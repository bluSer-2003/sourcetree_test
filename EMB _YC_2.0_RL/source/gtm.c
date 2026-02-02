// -----------------------------------------------------------------------------
// Copyright (C) Australian Semiconductor Technology Company (ASTC). 2013.
// All Rights Reserved.
//
// This is unpublished proprietary source code of the Australian Semiconductor
// Technology Company (ASTC).  The copyright notice does not evidence any actual
// or intended publication of such source code.
// -----------------------------------------------------------------------------
#include <stdio.h>
#include <math.h>
#include <mttcan.h>
#include "gtm.h"
#include "global.h"
#include "tmr.h"
#include "tmr_macrodriver.h"
#include "global_struct.h"
#include "temperature.h"
#include "pi_controller.h"
#include "hv_svgen.h"
#include "transformation.h"
#include "parameter.h"
#include "r_adc.h"
#include "fliter.h"
#include "Alignment.h"
#include "Loop_Control.h"
#include "Gap_Control.h"
#include "Protection.h"

int canTimer = 0;
int canmissTimer = 0;

//热敏电阻
extern uint16_t High_temperature;
extern float temperature ;

//压力传感器变量
extern struct r_sentData_fast RSENT0_data_fast[8];
extern uint32_t fast_buffer;
extern volatile uint32_t no_com_flag;
volatile uint32_t SENT_err_flag;       //Flag for data error: 1:data error  2:sensor break
extern uint32_t pressure_data ;
uint32_t force_data = 0;	//保存夹紧力数据
uint32_t predicted_clamping = 0; // 预测夹紧力

//根据目标夹紧力计算目标位置
float  target_position = 0;

//外部引用
//SPI通信（tmr)
extern volatile	uint16_t send_data[4];
extern volatile	uint16_t rx_data[4];
volatile uint16_t rx_angle[4];
volatile uint16_t flag_angle;	//SPI转换标志位
//ADC数据
extern uint16_t Gu1ReadAdcValue[32];
extern uint16_t flag_adc;
//CAN通信
extern CAN_Info g_Can_Atrib;

//间隙控制标志位
extern int contectFlag;	//接触点识别
extern int reverseFlag; //反转标志位

//位置环频率控制
extern double omiga;
extern float beta;
float force_omiga = 0.0;

//超差保护计数
extern unsigned int outrangecount;
//变量定义	
unsigned long  IsrTicker = 0;	  //主中断初始化计数
unsigned long  VirtualTimer = 0;  //程序运行计时
unsigned int SpeedInit=0;	  //速度计算计数器

//初始定位数组、变量
extern double Alig_angle_e[POLES+1];	//电角度
extern double Ali_angle[POLES+1];       //电机角度     

//保护数组-电流、电压
float currentABuffer[4];
float currentBBuffer[4];
float currentCBuffer[4];
float voltageBuffer[4];
float fwvoltageBuffer[4];

//故障码
extern unsigned int error_state_code_0101;

//tmr角度
volatile double angle;

//电流采样偏置参数计算
float offsetA=0;
float offsetB=0;
float offsetC=0;
float K1= 0.998 ;	  //Offset filter coefficient K1: 0.05/(T+0.05);
float K2= 0.001999 ;	  //Offset filter coefficient K2: T/(T+0.05);

//数据存储数组
//数组大小在gtm.h中修改宏
float spdref[savedata_count];
float spdfbk[savedata_count];
//float spdui[savedata_count];
//float spdup[savedata_count];

//float forceout[savedata_count];
//float posref0[savedata_count];

float forceFbk[savedata_count];
float forceRef[savedata_count];
//float forceui[savedata_count];
//float forceup[savedata_count];
float posfbk[savedata_count];
float posref[savedata_count];

//float iqui[savedata_count];
//float iqup[savedata_count];
float iqfbk[savedata_count];
float iqref[savedata_count];

//float idref[savedata_count];
//float idfbk[savedata_count];

//float position_angle[savedata_count];
//float pos_angle[savedata_count];

//float current_A[savedata_count];
//float current_B[savedata_count];
//float current_C[savedata_count];

//float vdc[savedata_count];

//数据存储计数
unsigned int s=0;
unsigned int mask;

//For ABS:
int forcestage = 0;
int forcecount = 0;

//浮点角度-双精度
//更新角度值和角度差值
double agl1 = 0;
double angle_pre = 0;
double angle_delta = 0;
double angle_fli = 0;

//标志位
//int flagxb=0;

//控制调试模式存储数据的周期
int fyw=0;

//电流重构标志位
int RecsFlag = 4;   

//运行模式
//0:test    1:can
int TestFlag = TESTFLAG;     
int lswpre = LSW;

float TargetForce_pre = 0;

int init_int(){
   EIC159  = 0x000F;//INTGTM_ATOM0_7
   EIBD159 = 0x00000001;
   EIC145   = 0x0041;//INTGTM_TIM1_1 //GTM01I1 is connected to GTM0AT0O1
   EIBD145  = 0x00000001;
   return 0;
}

void GTM_Init(){
	
    unsigned int status=0; 
    
    // Configure INTC
    init_int();

    //printf ("Configure CMU\n");
    GTM0.CMUGCLKNUM  = 0x0FFFF; // global divider = *1
    GTM0.CMUGCLKDEN  = 0x0FFFF;    
    GTM0.CMUCLK3CTRL = 0x00000004; // sys_clk_period *5 = 62,5ns @ 80MH sys_clk
    GTM0.CMUCLKEN    = 0x00000080; // enable CMU clock 3
    status = GTM0.CMUCLKEN;
    if (status != 0x000000C0) {
        //printf("ERROR: CMU clock 3 cannot be enabled\n");
        while(1);//Stay here if clock could not be enabled
    }

     // printf ("Configure TIM\n");
    GTM0.TIM10CTRL   = 0x03002F01;//to measure GTM0AT0O0
    GTM0.TIM11CTRL   = 0x03002F01;//to measure GTM0AT0O1
    GTM0.TIM11IRQEN  = 0x00000001;//enable NEWVAL IRQ

    //printf("Configure DTM24 (connected to outputs of ATOM0 channel 0 to 3)\n");
    GTM0.DTM24CHCTRL2 = 0x88888800; // enable dead time channel 1,2,3
    //GTM0.DTM24CHCTRL2 = 0x22222200;
    GTM0.DTM241DTV    = 0x00500050; // RELRISE=100, RELFALL=100 @sys_clk = 1,25μs
    GTM0.DTM242DTV    = 0x00500050; // RELRISE=100, RELFALL=100
    GTM0.DTM243DTV    = 0x00500050; // RELRISE=100, RELFALL=100
  
    //printf("Channel 0 is master channel that defines period of PWM\n");
    GTM0.ATOM00CTRL = (mode_somp)+(sl_hi)+(trig_ccu0)+(cmu_clk3);
    //printf("Channel 1 to 6 are synchronized to channel 1 and middle symmetrical\n");
    GTM0.ATOM01CTRL = (mode_somp)+(aru_off)+(sl_hi)+(rst_on_trig)+(cmu_clk3);
    GTM0.ATOM02CTRL = (mode_somp)+(aru_off)+(sl_hi)+(rst_on_trig)+(cmu_clk3);
    GTM0.ATOM03CTRL = (mode_somp)+(aru_off)+(sl_hi)+(rst_on_trig)+(cmu_clk3);
    GTM0.ATOM04CTRL = (mode_somp)+(aru_off)+(sl_lo)+(rst_on_trig)+(cmu_clk3);
    GTM0.ATOM05CTRL = (mode_somp)+(aru_off)+(sl_hi)+(rst_on_trig)+(cmu_clk3);
    GTM0.ATOM06CTRL = (mode_somp)+(aru_off)+(sl_lo)+(rst_on_trig)+(cmu_clk3);
    //printf("Channel 7 triggers reload of SRx register\n");
    GTM0.ATOM07CTRL = (mode_somp)+(aru_off)+(sl_hi)+(cmu_clk3)+(trig_ccu0);

    // initial values for ATOM0 channel 0:
    GTM0.ATOM00CM0 = T0; // period = 1000*62,5ns = 16kHz
    GTM0.ATOM00CM1 = T0/2; // duty cycle = 500*62,5ns
    GTM0.ATOM00CN0 = 0x00000000; // initial delay = 0
    GTM0.ATOM00SR0 = T0;
    GTM0.ATOM00SR1 = T0/2;
    
  // initial value for ATOM0 channel 7:
    GTM0.ATOM07CM1 = CH7_Pulse_length; // falling edge if ATOM0_CH0_CN0=CH7_Pulse_length
    GTM0.ATOM07CM0 = T0; // rising edge if ATOM0_CH0_CN0=2*T0
    GTM0.ATOM07SR1 = CH7_Pulse_length;
    GTM0.ATOM07SR0 = T0;
 
    GTM0.ATOM07IRQEN     = 0x00000001;   // enable interrupt CCU0 of ATOM0_CH7
    GTM0.ATOM0AGCINTTRIG = 0x00008000;   // int. trig channel 7
    GTM0.ATOM0AGCGLBCTRL = 0x00020000;   // update enable of ch 0
    GTM0.ATOM0AGCOUTENCTRL = 0x0000AAAA; // enable output 0 to 7 (1 to 6)
    GTM0.ATOM0AGCENDISCTRL = 0x0000AAAA; // anable all channel
    GTM0.ATOM0AGCFUPDCTRL  = 0xAAAAAAAA; // force update on ch 0 to 7
    GTM0.ATOM0AGCGLBCTRL   = 0x00000001; // host trigger for start of ATOM0

    //after enable by host trigger set force update flags for next internal trigger
    GTM0.ATOM0AGCFUPDCTRL  = 0xAAA9AAA9; // force update on ch 1 to 7
}

void De_Mos(void){
	
    GTM0.DTM24CHCTRL2 = 0x22222200;    // disable dead time channel 1,2,3
    g_Control.iRunState  = 4444;
    g_Control.Dutycycle_A = 0;         //占空比置于50%
    g_Control.Dutycycle_B = 0;
    g_Control.Dutycycle_C = 0;
}

void On_Mos(void){
	
    GTM0.DTM24CHCTRL2 = 0x88888800;   // enable dead time channel 1,2,3
    
    //同时将pi调节器各部分都强行置0
    pi_id.Out = 0;       
    pi_id.i1  = 0;
    pi_iq.Out = 0;
    pi_iq.i1  = 0;
    pi_spd.Out= 0;
    pi_spd.i1 = 0;
    pi_fw.Out = 0;
    pi_fw.i1  =  0;
    pi_pos.Out = 0;
    pi_pos.i1 = 0;
    pi_force.Out = 0;
    pi_force.i1 = 0;
    
    outrangecount=0;    //重置超差计数
    omiga=0;            //重置位置环控制频率
    VirtualTimer=0;     //重置程序定时计数
    
    alarm.current_level1 = 0;	//重置保护参数
    alarm.current_level2 = 0;
    alarm.current_level3 = 0;
    error_state_code_0101 &= 0x0000;//清除故障码
    //g_Control.pos.PosOld = angle;//位置初始化
    //g_Control.pos.PosSum = 0; 
    g_Control.SpdRef = 0;
}

//调试程序定时
inline void TestStop(void){
	
    //调试模式且运行状态且非定位环
    if(TestFlag==0 && lsw!=0 && g_Control.iRunState==100){
    //if(TestFlag==0 && g_Control.iRunState==100 ){    
	//未达到计时    
        if(VirtualTimer<20000*stoptime) 
            VirtualTimer++;
	//达到计时
        else if(VirtualTimer>=20000*stoptime && VirtualTimer<20000*(stoptime+1)){
            VirtualTimer++;
            De_Mos();
	}
    }
}

//测试数据存储
inline void SaveData(void){
    if(fyw==0){
       if((g_Can_Atrib.runState==255||TestFlag==0) && g_Control.iRunState == 100 && s < savedata_count){   // T = (fyw+1）*0.25S
//          if((g_Can_Atrib.runState==255||TestFlag==0)  && s<savedata_count){   // T = (fyw+1）*0.25S
	    forceRef[s] = g_Control.target_pressure;//g_Control.ForceRef;
            forceFbk[s] = force_data*0.001;//pi_pos.Out;//g_Control.m_Current.cur_A;//force_data;//force_data;
	    //forceui[s] = pi_force.ui;
	    //forceup[s] = pi_force.up*pi_force.Kp;
            posref[s] = pi_pos.Ref/20;// g_Control.m_Current.cur_B;//pi_pos.Ref/20;//g_Control.PosRef;
            posfbk[s] = -g_Control.pos.PosSum/(2*PI);//g_Control.m_Current.cur_C;//-g_Control.pos.PosSum/(2*PI);//g_Control.PosFbk;//g_Control.m_Current.cur_B;//g_Control.PosFbk;//angle;//
            
//	    forceout[s] = pi_preforce.Out;
	    //posref0[s] = (pi_pos.Ref - pi_force.Out) / 20;
//            position_angle[s] = angle;
//            pos_angle[s] = g_Control.angle_e;
	    
//            current_A[s] = g_Control.m_Current.cur_A;
//            current_B[s] = g_Control.m_Current.cur_B;
//            current_C[s] = g_Control.m_Current.cur_C;
	    
            spdref[s] = g_Control.SpdRef*SPEED_PU_RE;//-g_Control.SpdRef;//pi_iq.ui;//g_Control.m_Current.cur_C;//pi_force.Out;//
            spdfbk[s] = g_Control.m_speed.Speed;//pi_spd.Fbk;//pi_iq.up;//ipark1.Angle;//filter_2nd_order(g_Control.m_speed.Speed);
            //spdui[s] = pi_spd.ui*SPEED_PU_RE;
            //spdup[s] = pi_spd.Kp*pi_spd.up*SPEED_PU_RE;
	    
	    //idref[s] =  pi_id.Ref*CURRENT_PU_RE;;//pi_id.Ref*CURRENT_PU_RE;//filter_3nd_order(g_Control.m_speed.Speed);
            //idfbk[s] = pi_id.Fbk*CURRENT_PU_RE;;//pi_id.Fbk*CURRENT_PU_RE;//g_Control.m_Current.cur_A;//
	    
	    //iqup[s] = pi_iq.Kp*pi_iq.up*CURRENT_PU_RE;
	    //iqui[s] = pi_iq.ui*CURRENT_PU_RE;
            iqref[s] = pi_iq.Ref*CURRENT_PU_RE;//g_Control.m_Current.cur_C;//pi_pos.ui;//filter_3nd_order(g_Control.m_speed.Speed);
            iqfbk[s] = pi_iq.Fbk*CURRENT_PU_RE;//g_Control.m_Current.cur_B;//pi_pos.up;//
	    s++;
        }else if(g_Control.iRunState==100 && s>=savedata_count && TestFlag==1){
            s = 0;
            g_Can_Atrib.runState = 0;
        }
        fyw = Data_Interval - 1;
    }
    else
        fyw--;
}

#pragma interrupt INTGTM_ATOM0_7(enable=true, channel=159, fpu=true, callt=true)
 void INTGTM_ATOM0_7(void)//mainISR
{ 
    __EI();

    //CAN报文回复计时
    if(canTimer < 400){
    	canTimer++;
    }
    else{
    	canTimer = 0;

    }
    if(canmissTimer < 40000)
    {
	canmissTimer++;
    }
    else
    {
	canmissTimer = 40000;
    }
    
    //断线标志位no_com_flag,数据异常标志位data_err_flag
    SENT_err_flag = SENT_receive_start();
    force_data = pressure_data;
    //predicted_clamping = (int)smith_predictor_predict(&sp, clamping_feedback);

    R_ADC_ScanGroup_Start(1, 0);
    R_ADC_ScanGroup_Start(0, 0);
    //P1 |= _PORT_SET_BIT4;
    //P1 &= _PORT_CLEAR_BIT4;
     
    //tmr
    R_CSIH1_Master_Send((uint16_t*)send_data,  _CSIH_SELECT_CHIP_6,(uint16_t*)rx_data);  
    GTM0.ATOM07IRQNOTIFY = 0x00000003; // reset NOTIFY flags  

    //高温标志位：High_temperature
    temperature = ADC_Temperature();
   
    //速度计算
    g_Control.m_speed.Speed = ComputeSpeed(agl1,&Speed1); 
    //g_Control.m_speed.Speed = filter_2nd_order(g_Control.m_speed.Speed);  //速度二阶滤波
    //g_Control.m_speed.Speed = filter_3nd_order(g_Control.m_speed.Speed);  //速度三阶滤波
    
    //更新历史最大转速
    if(g_Control.m_speed.Speed>g_Control.m_speed.SpeedMax)
        g_Control.m_speed.SpeedMax=g_Control.m_speed.Speed;
    else if(g_Control.m_speed.Speed<-g_Control.m_speed.SpeedMax)
	    g_Control.m_speed.SpeedMax=-g_Control.m_speed.Speed;

    //ADC 转换标志位判断

    while(flag_adc==0);
        flag_adc = 0;

    //状态机选择
    switch(g_Control.iRunState){
        case 0:  //初始化
            AngleProcess();     //角度处理
            MainISRInit();      //主中断初始化	
        break;
        case 100://正常运行
            SampleAndProtect(); //电流采样与保护
            AngleProcess();     //角度处理
            MainISR();          //主中断运行
        break;
        case 4444: //停机
            GetPosition();
            SampleAndProtect(); //电流采样与保护
            AngleProcess();     //角度处理
        break;
        default:   
            GetPosition();
            SampleAndProtect(); //电流采样与保护
            AngleProcess();     //角度处理
    } 
   
    SaveData();  //数据存储 
    
    // 泄放功能
    // 如果直流母线电压过高，触发泄放动作
    Discharge();  
    
    //调试模式计时
    TestStop();
    
    //占空比控制
//    g_Control.Dutycycle_A = -1;
//    g_Control.Dutycycle_B = -1;
//    g_Control.Dutycycle_C = -1;

    //限制占空比0-95% dutycycle=A/2+0.5
    g_Control.Dutycycle_A = SATS(g_Control.Dutycycle_A,-1,MAXDUTY);
    g_Control.Dutycycle_B = SATS(g_Control.Dutycycle_B,-1,MAXDUTY);
    g_Control.Dutycycle_C = SATS(g_Control.Dutycycle_C,-1,MAXDUTY);
    
    //PWM值更新  
    GTM0.ATOM01SR0 = (T0/2)-(T0/4+(int)(g_Control.Dutycycle_A*((T0/4)-10)));
    GTM0.ATOM01SR1 = (T0/2)+(T0/4+(int)(g_Control.Dutycycle_A*((T0/4)-10)));
    GTM0.ATOM02SR0 = (T0/2)-(T0/4+(int)(g_Control.Dutycycle_B*((T0/4)-10)));
    GTM0.ATOM02SR1 = (T0/2)+(T0/4+(int)(g_Control.Dutycycle_B*((T0/4)-10)));
    GTM0.ATOM03SR0 = (T0/2)-(T0/4+(int)(g_Control.Dutycycle_C*((T0/4)-10)));
    GTM0.ATOM03SR1 = (T0/2)+(T0/4+(int)(g_Control.Dutycycle_C*((T0/4)-10)));

    //P1 |= _PORT_SET_BIT4;
    //P1 &= _PORT_CLEAR_BIT4;
}

//采样与保护
inline void SampleAndProtect(void){
    clarke2.As = -(float)(Gu1ReadAdcValue[2]-offsetA)*660/4095;       // Phase A curr.
    clarke2.Bs = -(float)(Gu1ReadAdcValue[3]-offsetB)*660/4095;       // Phase B curr.
    clarke2.Cs = -(float)(Gu1ReadAdcValue[0]-offsetC)*660/4095;       // Phase C curr.
    
    clarke1.As = 0*clarke1.As + 1*clarke2.As;
    clarke1.Bs = 0*clarke1.Bs + 1*clarke2.Bs;
    clarke1.Cs = 0*clarke1.Cs + 1*clarke2.Cs;
    
    // 如果电机类型是 EPS（电动助力转向）或 EMB（电动机械制动）
    if (motortype == EPS || motortype == EMB)                                                
        // 将 ADC 采样值 Gu1ReadAdcValue[9] 转换为实际总线电压 Vdc
        // 校准因子为 105.07（与硬件相关）
        g_Control.Vdc = Gu1ReadAdcValue[11] / (100.83);
    else
        // 如果电机类型是其他类型
        // 使用不同的校准因子 102.74
        g_Control.Vdc = Gu1ReadAdcValue[11] / (102.74);
	
     g_Control.FW.Vdcfbk=sqrt(pi_id.Out*pi_id.Out+pi_iq.Out*pi_iq.Out);//弱磁反馈电压
       
    //电流三相电流采样处理
    CurRecs();
    //保护（电流、转速）
    protection();
}

//角度处理
inline void AngleProcess(void){
    //SPI 转换标志位判断
    while(flag_angle==0);
        flag_angle=0;  
    
    //角度滤波
    angle = agl1;  //不滤波
    //angle = angle_precess_2order(angle_delta,angle_pre);   //对偏差滤波
    
    //电角度计算
    Angle_get_e(angle);
}

//主中断初始化
void MainISRInit(void){
    if(IsrTicker<10000)
	    IsrTicker++;                                    //0S~0.5S  上电稳定
    else if(IsrTicker<30000){                           //0.5s~1.5S计算直流偏置
        offsetA = K1*offsetA+K2*Gu1ReadAdcValue[2]; 	//Phase A offset
        offsetB = K1*offsetB+K2*Gu1ReadAdcValue[3]; 	//Phase B offset
        offsetC = K1*offsetC+K2*Gu1ReadAdcValue[0]; 	//Phase C offset
        g_Control.Dutycycle_A= -1;
        g_Control.Dutycycle_B= -1;
        g_Control.Dutycycle_C= -1;
        IsrTicker++;
        g_Control.pos.PosOld = angle;                   //位置初始化
        g_Control.pos.PosSum = 0;
    }else if(IsrTicker<30001){                          //测试模式跳过验证环节
    	SampleAndProtect();                             //电流采样与保护
        if(TestFlag==0)
	        IsrTicker = 100000;                         //下次跳到最后，测试模式
        else 
	        IsrTicker++;    
    }else if(IsrTicker<50001){                          //1.5s~2.5S定位到某一极
        g_Control.Dutycycle_A= -0.7; 
        g_Control.Dutycycle_B= -1;
        g_Control.Dutycycle_C= -1;
    	SampleAndProtect();    
        IsrTicker++;    
    }else if(IsrTicker<70001){                          //2.5s~3.5S定位到某一极
        g_Control.Dutycycle_A= -0.6; 
        g_Control.Dutycycle_B= -1;
        g_Control.Dutycycle_C= -1;
    	SampleAndProtect();    
        IsrTicker++;      
    }else if(IsrTicker<70002){                          //初始角度验证
    	SampleAndProtect();    
        //1:初始定位角度正常 0：初始定位角度异常
        flag.AliCheck = AliCheck(g_Control.angle_e,g_Control.Aligmenta.Ali_angle); 
        if(flag.AliCheck == 0 && lsw != 0){             //定位角度异常且当前不处于定位模式时
            lswpre = lsw;                               //储存环路信息
            lsw = 0;                                    //初始角度异常，进入定位模式，重新定位
            error_state_code_0101 |= _PORT_SET_BIT0;             //错误标志位:定位故障
        }
        g_Control.Dutycycle_A= -1;                      //封管
        g_Control.Dutycycle_B= -1;
        g_Control.Dutycycle_C= -1;
        IsrTicker++;    
    }
    // else if(IsrTicker<70003){
    //     if(lsw != 3){                                //非位置环
    //         if(TestFlag == 0)
    //             g_Control.iRunState  = 100;
    //         else
    //             g_Control.iRunState  = 4444;
    //     }
    //     IsrTicker++;
    // }
    else{
        SampleAndProtect();                             //电流采样与保护
        // CLARKE_MACRO(clarke1)
        // park1.Alpha = clarke1.Alpha;        
        // park1.Beta  = clarke1.Beta;  
        // park1.Angle = g_Control.angle_e;
        // park1.Sine  = sinf(park1.Angle);
        // park1.Cose  = cosf(park1.Angle);
        // PARK_MACRO(park1)			                //CLARKE和PARK变换
	
        if(lsw == 3){				                    //位置环进行接触点识别和间隙回退
            if(contectFlag == 0)
                EMB_ContactDetect();                    //计算接触点
            if((contectFlag == 1 ||contectFlag == 2) && reverseFlag == 0) {
                EMB_afterContactDetect();
            }
        }
	    //识别到接触点直接启动
	    if (((contectFlag == 1 ||contectFlag == 2) && reverseFlag == 1) || (lsw != 3))  
            g_Control.iRunState = 100;   
        
        clarke1.As = -(float)(Gu1ReadAdcValue[2]-offsetA)*660/4095;       // Phase A curr.
        clarke1.Bs = -(float)(Gu1ReadAdcValue[3]-offsetB)*660/4095;       // Phase B curr.
        clarke1.Cs = -(float)(Gu1ReadAdcValue[0]-offsetC)*660/4095;       // Phase C curr.
    }
}

//主中断运行函数
inline void MainISR(void){
    //CLARKE变换和PARK变换
    CLARKE_MACRO(clarke1)
    park1.Alpha = clarke1.Alpha;        
    park1.Beta  = clarke1.Beta;  
    park1.Angle = g_Control.angle_e;
    park1.Sine  = sinf(park1.Angle);
    park1.Cose  = cosf(park1.Angle);
    PARK_MACRO(park1)
    
    //环路选择
    LoopCtrl();
}

inline void Position_Cal(float Target_Force){
    if(Target_Force <= 200.0f){   // 压力太小，直接回零
        target_position = -1.50f;
	    pi_preforce.Out=0;
    }else{
        target_position = -5.055f + sqrtf(2348000000.0f + 389728.0f * Target_Force) * 0.000103f;
    }
}

inline void ABSTestRefSet(){
    if(forcestage % 4 == 0){
        g_Control.target_pressure = 4.5;
        if(force_data >= 4500)
            forcecount++;
        if(forcecount >= 600){
	        forcecount = 0;
            forcestage++;
	    }
    }
    else if(forcestage % 4 == 1){
	    g_Control.target_pressure = 3;
        if(force_data <= 3000)
            forcecount++;
	    if(forcecount >= 600){
	        forcecount = 0;
	        forcestage++;
	    }
    }
    else if(forcestage % 4 == 2){
	    g_Control.target_pressure = 4.5;
	    if(force_data >= 4500)
	        forcecount++;
	    if(forcecount >= 600){
            forcecount = 0;
            forcestage++;
	    }
    }
    else if(forcestage % 4 == 3){
        g_Control.target_pressure = 0;
        if(force_data <= 200)
            forcecount++;
        if(forcecount >= 600){
	        forcecount = 0;
            forcestage++;
        }
    }
    Position_Cal(g_Control.target_pressure*FORCE_PU_RE);
    TargetForce_pre = g_Control.target_pressure*FORCE_PU_RE;
    g_Control.PosRef = target_position;
    g_Control.PosRef = g_Control.PosRef * POSITION_PU * 2 * PI;
}

uint8_t FORCE_PERIOD = 1;
inline float sineRef(){
    float force_sineRef = 0.0f;
    force_sineRef = FORCE_REF * sinf(force_omiga - PI/2)+5000;
    force_omiga += 2*PI / (FORCE_PERIOD*20000);   //T=12 0.00057119866  T=6  0.001047197 T=3 0.002094394 T=5 0.001256637
    if(force_omiga>2*PI) 
        force_omiga -= 2*PI;
    return force_sineRef*0.001;
}

//设置斜坡给定
uint8_t SlopeSetPeriod = 2;
uint32_t Set_count = 0;
static uint8_t Set_Step = 0;
static float SlopeRef = 0;
inline void SlopeSet(float Ref){
    //第一阶段：以设定周期上升斜率
    if(Set_Step % 2 == 0)
        SlopeRef = (float)Ref * (Set_count - Set_Step*SlopeSetPeriod*20000)/ (SlopeSetPeriod*20000);
    else if(Set_Step % 2 == 1){
	    SlopeRef = (float)Ref * (Set_count - Set_Step*SlopeSetPeriod*20000) / (SlopeSetPeriod*20000);
        SlopeRef = (float)Ref - SlopeRef;
    }
    Set_count++;
    //当计数值达到周期的整数倍时，切换上升/下降
    if(Set_count % (SlopeSetPeriod*20000) == 0)
        Set_Step ++;
}

//给定设置
inline void SetLoopRef(){

    if(TestFlag==0){ //定时测试给定
        switch(lsw)
        {
            case force:
	            g_Control.ForceRef = sineRef();
        	    //g_Control.ForceRef = FORCE_REF * FORCE_PU;      //压力给定，标定为KN 
            break;
            case position:
                //For step input reference:
                g_Control.target_pressure = FORCE_REF * FORCE_PU;
                //Position_Cal(g_Control.target_pressure*FORCE_PU_RE);
        	//TargetForce_pre = g_Control.target_pressure*FORCE_PU_RE;
                //g_Control.PosRef = target_position;
                //g_Control.PosRef = g_Control.PosRef * POSITION_PU * 2 * PI;
		
		//For position loop:
                //g_Control.PosRef = POS_REF*POSITION_PU;         //位置给定

                //For ABS test:
                //ABSTestRefSet();

                //For sine reference:
                //g_Control.target_pressure = sineRef();
                
                //For Slope reference:
                //SlopeSet(FORCE_REF);
                //g_Control.target_pressure = SlopeRef * FORCE_PU; 

        	Position_Cal(g_Control.target_pressure*FORCE_PU_RE);
        	//TargetForce_pre = g_Control.target_pressure*FORCE_PU_RE;
                g_Control.PosRef = target_position;
                g_Control.PosRef = g_Control.PosRef * POSITION_PU * 2 * PI;
            break;
            case speed:
                //YC参数设置：15KN对应圈数大致为2.6圈  17KN：2.86r   21KN：3.28r
                //给定转速100rpm：3/3.5r需要时长为1.8s/2.1s 来回时长设计为4s/4.5s
                //给定转速500rpm: 3/3.5r需要时长为0.36s/0.42s 来回时长设计为1s/1s
                //给定转速1000rpm：3/3.5r需要时长为0.18s/0.21s 来回时长设计为0.5s/0.5s
                //给定转速2000rpm：3/3.5r需要时长为0.09s/0.105s 来回时长设计为0.2s/0.3s
//                if(force_data <= 16000 && VirtualTimer <= 0.4*20000)
//                    g_Control.SpdRef = -Speed_Ref*SPEED_PU;
//                else if( force_data > 0 && VirtualTimer > 0.4*20000 && VirtualTimer < 0.8*20000)
//                    g_Control.SpdRef = Speed_Ref*SPEED_PU;
//                else if(force_data == 0)
//                    g_Control.SpdRef = 0*SPEED_PU;
                //正常给定
	    	    g_Control.SpdRef = Speed_Ref*SPEED_PU;          //测试固定转速给定
            break;
            case current:
	            //SlopeSet(IQ_REF);
	            //g_Control.IqRef = SlopeRef*CURRENT_PU;
                g_Control.IqRef = IQ_REF*CURRENT_PU;            //q轴电流给定
                g_Control.IdRef = ID_REF*CURRENT_PU;            //d轴电流给定
            break;
        }
    }
    
    if(TestFlag==1){  //CAN给定
        switch(lsw)
        {
            case position:
                 g_Control.target_pressure = SATS(g_Control.target_pressure,0,FORCE_HIGH);	        //CAN给定压力值
                 Position_Cal(g_Control.target_pressure*FORCE_PU_RE);
                // TargetForce_pre = g_Control.target_pressure*FORCE_PU_RE;
                 g_Control.PosRef = target_position;
                 g_Control.PosRef = g_Control.PosRef * POSITION_PU * 2 * PI;
               // g_Control.PosRef = g_Control.PosRefStep*2*PI*POSITION_PU;       //位置给定（根据压力计算）
            break;
            case speed:
                g_Control.SpdRef = 0.999*g_Control.SpdRef+0.001*g_Control.SpdRef;
                //g_Control.SpdRef = g_Can_Atrib.spdRef_float*SPEED_PU;        //转速给定通过CAN通讯更新
            break;
            case current:
                g_Control.IqRef = SATS(g_Can_Atrib.spdRef_float,-108,108)*CURRENT_PU;
                g_Control.IdRef = ID_REF*CURRENT_PU;                            //d轴电流给定
            break;
        }
    }
}

//环路选择
inline void LoopCtrl(void){
    SetLoopRef();         //给定设置
    //EMB_Retreat();	  //如果给定设置为0，回退0.2mm;
    GetPosition();   
    switch(lsw)
    {
        case force:
            g_Control.ForceFbk = force_data * FORCE_PU;     //反馈为N,标幺为KN
            ForceLoop(g_Control.ForceRef,g_Control.ForceFbk);   //环路控制以KN为单位
            break;
        case position:                                              //获取位置
            g_Control.pressure_Fbk = force_data * FORCE_PU;
            g_Control.PosFbk = -g_Control.pos.PosSum*POSITION_PU;  //改正负号         //位置反馈
            PosLoop(g_Control.PosRef,g_Control.PosFbk);
        break;

        case speed:
            //GetPosition();   
            g_Control.SpdFbk = -g_Control.m_speed.Speed*SPEED_PU;    //改正负号        //转速反馈
            SpeedLoop(g_Control.SpdRef,g_Control.SpdFbk); 
        break;
            
        case current:
            CurrentLoop(g_Control.IqRef,g_Control.IdRef,park1.Qs,park1.Ds);
        break;
        
        case Aligement:
            Alignment();    //初始定位 
        break;
        
        case openloop:
            Openloop();     //开环
        break;
        
        default:
            g_Control.Dutycycle_A = -1;
            g_Control.Dutycycle_B = -1;
            g_Control.Dutycycle_C = -1;
        break;    
    }
}


// 电流处理函数
inline void CurRecs(void)
{
    float Duty_threshold = 0.7;//采不到的最大占空比门槛
    static float prevA = 0.0f, prevB = 0.0f, prevC = 0.0f;//记录先值
    
    unsigned int missA;
    unsigned int missB;
    unsigned int missC;
   
    float usedA = clarke2.As;
    float usedB = clarke2.Bs;
    float usedC = clarke2.Cs;
    missA = (g_Control.Dutycycle_A >= Duty_threshold );// 4 5 2 6
    missB = (g_Control.Dutycycle_B >= Duty_threshold );// 2 6  1  3
    missC = (g_Control.Dutycycle_C >= Duty_threshold);//1 3  4  5 svgen1.Sector
   //const unsigned int mask  = (missA ? 0x01 : 0) | (missB ? 0x02 : 0) | (missC ? 0x04 : 0);
    mask  = (missA ? 0x01 : 0) | (missB ? 0x02 : 0) | (missC ? 0x04 : 0);

    switch (mask) {
        case 0x00: //都采的到
            break;
        case 0x01: // A采不到
            usedA = -(usedB + usedC);
            break;
        case 0x02: // B采不到 
            usedB = -(usedA + usedC);
            break;
        case 0x04: // C采不到 
            usedC = -(usedA + usedB);
            break;
        case 0x03: //AB采不到 C采的到
            usedC = clarke2.Cs;
            usedA = prevA;
            usedB = -(usedA + usedC);
            break;
        case 0x05: //AC采不到 B采的到
            usedB = clarke2.Bs;
            usedA = prevA;
            usedC = -(usedA + usedB);
            break;
        case 0x06: //BC采不到 A采的到
            usedA = clarke2.As;
            usedB = prevB;
            usedC = -(usedA + usedB);
            break;
        case 0x07: //全都采不到
            usedA = prevA;
            usedB = prevB;
            usedC = prevC;
            break;
        default:
            break;
    }

    prevA = usedA;
    prevB = usedB;
    prevC = usedC;
    //更新三相
    clarke2.As = usedA;
    clarke2.Bs = usedB;
    clarke2.Cs = usedC;
}

//速度计算
inline float ComputeSpeed(double angle, SpeedCal *v){
    // 定义静态数组，用于存储历史角度和历史速度
    static double angle_pre[6];  // 存储最近 6 次的角度值
    static float speed_pre[5];   // 存储最近 5 次的速度值
    float output;                // 输出速度变量

    // 初始化历史数据，仅在 SpeedInit < 2 的情况下执行一次
    if (SpeedInit < 2) {
        // 初始化角度数组为当前角度值
        angle_pre[0] = angle;
        angle_pre[1] = angle;
        angle_pre[2] = angle;
        angle_pre[3] = angle;
        angle_pre[4] = angle;
        angle_pre[5] = angle;

        // 初始化速度数组为 0
        speed_pre[0] = 0;
        speed_pre[1] = 0;
        speed_pre[2] = 0;
        speed_pre[3] = 0;
        speed_pre[4] = 0;

        // 增加初始化计数器
        SpeedInit++;
    }

    // 更新角度数组，依次向前移动，保留最近 6 次的角度值
    angle_pre[0] = angle_pre[1];
    angle_pre[1] = angle_pre[2];
    angle_pre[2] = angle_pre[3];
    angle_pre[3] = angle_pre[4];
    angle_pre[4] = angle_pre[5];
    angle_pre[5] = angle; // 存储当前角度

    // 更新速度结构体中的当前角度和之前角度
    v->angle_now = angle_pre[5]; // 最新角度
    v->angle_pre = angle_pre[0]; // 最早角度

    // 计算角度差
    v->dif_angle = v->angle_now - v->angle_pre;

    // 处理角度差超出范围的情况，将其归一化到 [-PI, PI] 范围内
    if (v->dif_angle < -PI)
        v->dif_angle = v->dif_angle + 2 * PI; // 小于 -PI，补偿 2PI
    else if (v->dif_angle > PI)
        v->dif_angle = v->dif_angle - 2 * PI; // 大于 PI，减去 2PI

    // 如果角度偏差过大，认为数据异常，使用上一次的角度差
    if (v->dif_angle > 0.1 * PI)
        v->dif_angle = v->dif_angle_pre; // 使用之前的差值
    else if (v->dif_angle < -0.1 * PI)
        v->dif_angle = v->dif_angle_pre; // 使用之前的差值

    // 存储当前角度差值为历史角度差
    v->dif_angle_pre = v->dif_angle;

    // 计算实际机械速度
    // 转速计算公式：角度差 * 600000 / (PI * 时间间隔)
    v->realspeed = v->dif_angle * 600000 / (PI * 5);

    // 更新速度数组，依次向前移动，保留最近 5 次的速度值
    speed_pre[0] = speed_pre[1];
    speed_pre[1] = speed_pre[2];
    speed_pre[2] = speed_pre[3];
    speed_pre[3] = speed_pre[4];
    speed_pre[4] = v->realspeed; // 存储当前速度

    // 滤波处理（此处未使用滤波）
    output = v->realspeed; // 输出当前计算的速度（未滤波）

    return output; // 返回速度值
}

// 电角度计算函数
inline void Angle_get_e(double agl){
	
    // 计算电角度：机械角度乘以电机极对数
    g_Control.angle_e = agl * POLES;

    // 限制电角度范围在 [0, 2π) 内
    while (g_Control.angle_e >= 2 * PI)
        g_Control.angle_e -= 2 * PI;

    // 如果电机类型是 Booster，需要对电角度取反（电角度反向）
    // if (motortype == Booster)
    g_Control.angle_e = 2 * PI - g_Control.angle_e;

    // 初始定位角度补偿
    if (lsw != 0){ 
        if (g_Control.angle_e >= g_Control.Aligmenta.Ali_angle)
            g_Control.angle_e = g_Control.angle_e - g_Control.Aligmenta.Ali_angle;
        else if (g_Control.angle_e < g_Control.Aligmenta.Ali_angle)
            g_Control.angle_e = g_Control.angle_e + 2 * PI - g_Control.Aligmenta.Ali_angle;
    }
}

// 开环控制功能实现
void Openloop(void)
{
    // 设置d轴参考电压和q轴参考电压
    ipark1.Ds = VD_REF;  // d轴参考电压
    ipark1.Qs = VQ_REF;  // q轴参考电压
    
    // 更新电机角度，每次增加一个步进量
    ipark1.Angle = ipark1.Angle + OPEN_STEP;  // 角度更新，每步增加OPEN_STEP（如：0.0005*PI）
    
    // 确保电机角度在0到2PI范围内
    if (ipark1.Angle > (2 * PI)) {
        ipark1.Angle = ipark1.Angle - 2 * PI;  // 超过2PI时减去2PI
    }
    if (ipark1.Angle < 0) {
        ipark1.Angle = ipark1.Angle + 2 * PI;  // 超过2PI时减去2PI
    }
    // 计算当前角度的正弦值和余弦值
    ipark1.Sine = sin(ipark1.Angle);  // 电机角度的正弦值
    ipark1.Cose = cos(ipark1.Angle);  // 电机角度的余弦值
    
    // 调用逆Park变换宏，得到α、β坐标系中的电压分量
    IPARK_MACRO(ipark1)

    // 设置SVGEN_DQ模块的输入，调用空间矢量生成宏
    svgen1.Ualpha = ipark1.Alpha;  // α轴电压
    svgen1.Ubeta  = ipark1.Beta;   // β轴电压
    svgentest.Ualpha = ipark1.Alpha;  // 测试用的α轴电压
    svgentest.Ubeta  = ipark1.Beta;   // 测试用的β轴电压
    
    // 调用空间矢量脉宽调制（SVPWM）生成电压的占空比
    svpwm(&svgen1);

    // 更新三相电流占空比
    g_Control.Dutycycle_A = svgen1.Tc;  // A相电流占空比
    g_Control.Dutycycle_B = svgen1.Tb;  // B相电流占空比
    g_Control.Dutycycle_C = svgen1.Ta;  // C相电流占空比
}

// 保护电流滑动滤波函数
void Read_ADC_Current(void){
    // 更新电流A的滑动窗口
    currentABuffer[0] = currentABuffer[1];
    currentABuffer[1] = currentABuffer[2];
    currentABuffer[2] = currentABuffer[3];
    currentABuffer[3] = clarke1.As; // 当前采样值

    // 更新电流B的滑动窗口
    currentBBuffer[0] = currentBBuffer[1];
    currentBBuffer[1] = currentBBuffer[2];
    currentBBuffer[2] = currentBBuffer[3];
    currentBBuffer[3] = clarke1.Bs;

    // 更新电流C的滑动窗口
    currentCBuffer[0] = currentCBuffer[1];
    currentCBuffer[1] = currentCBuffer[2];
    currentCBuffer[2] = currentCBuffer[3];
    currentCBuffer[3] = clarke1.Cs;

    // 更新母线电压的滑动窗口
    voltageBuffer[0] = voltageBuffer[1];
    voltageBuffer[1] = voltageBuffer[2];
    voltageBuffer[2] = voltageBuffer[3];
    voltageBuffer[3] = g_Control.Vdc; // 当前母线电压

    // 更新磁链电压反馈的滑动窗口
    fwvoltageBuffer[0] = fwvoltageBuffer[1];
    fwvoltageBuffer[1] = fwvoltageBuffer[2];
    fwvoltageBuffer[2] = fwvoltageBuffer[3];
    fwvoltageBuffer[3] = g_Control.FW.Vdcfbk; // 当前磁链反馈电压

    // 计算母线电压的滑动平均值
    g_Control.ControlBoardPowerDC = (voltageBuffer[0] + voltageBuffer[1]
                                    + voltageBuffer[2] + voltageBuffer[3]) / 4;

    // 计算磁链反馈电压的加权滑动平均值
    g_Control.FW.Vdcfbkfli = (1.8 * fwvoltageBuffer[0] + 1.5 * fwvoltageBuffer[1]
                              + 0.5 * fwvoltageBuffer[2] + 0.2 * fwvoltageBuffer[3]) / 4;

    // 计算相电流A的滑动平均值
    g_Control.m_Current.cur_A = (currentABuffer[0] + currentABuffer[1]
                                + currentABuffer[2] + currentABuffer[3]) / 4;

    // 计算相电流B的滑动平均值
    g_Control.m_Current.cur_B = (currentBBuffer[0] + currentBBuffer[1]
                                + currentBBuffer[2] + currentBBuffer[3]) / 4;

    // 计算相电流C的滑动平均值
    g_Control.m_Current.cur_C = (currentCBuffer[0] + currentCBuffer[1]
                                + currentCBuffer[2] + currentCBuffer[3]) / 4;
}

#pragma interrupt INTGTM_TIM1_1(enable=false, channel=145, fpu=true, callt=false)
void INTGTM_TIM1_1(void)
{
    printf("INTGTM_TIM1_1 Interrupt Raised\n");
    printf("Measured ATOM0O0 PWM duty is equal to %i, and PWM period to %i\n",GTM0.TIM10GPR0&0x0000FFFF, GTM0.TIM10GPR1&0x0000FFFF);
    printf("Measured ATOM0O1 PWM duty is equal to %i, and PWM period to %i\n",GTM0.TIM11GPR0&0x0000FFFF, GTM0.TIM11GPR1&0x0000FFFF);
    GTM0.TIM11IRQNOTIFY = 0x00000001;//clear the NEWVAL flag
}

void GTM_PIC_ADC_Init(void)
{
    PIC2C.TRGPREMUX0 = 0x00000010; // GTM ATOM0_OUT trigger source selected for ADCF SG0;
    PIC2C.TRGMUX0 = 0x00000001;  //Selects ADCnTRG or GTM trigger for ADCFn scan group 0;
    //PIC2C.EDGSEL0 = 0x00000002; //Select active edge on ADCFn scan group 0;
    PIC2C.EDGSEL0 = 0x00000000;
	
    PIC2C.TRGPREMUX1 = 0x00000010; // GTM ATOM0_OUT trigger source selected for ADCF SG0;
    PIC2C.TRGMUX1 = 0x00000001;  //Selects ADCnTRG or GTM trigger for ADCFn scan group 0;
    //PIC2C.EDGSEL0 = 0x00000002; //Select active edge on ADCFn scan group 0;
    PIC2C.EDGSEL1 = 0x00000000;
}

#pragma interrupt r_csih0_interrupt_receive(enable=false, channel=91, fpu=true, callt=false)
void r_csih0_interrupt_receive(void)
{
    //P5 |= _PORT_SET_BIT4;
    //P5 &= _PORT_CLEAR_BIT4;
    // Set receive setting */

    rx_data[0]=CSIH1.RX0H;
    rx_data[1]=CSIH1.RX0H;
    rx_data[2]=CSIH1.RX0H;

    rx_angle[0]=(rx_data[0]<<8 | (rx_data[1]&0xFF00)>>8);
    rx_angle[angle_status]=rx_data[1]&0x00FF;
	
    flag_angle=1;
	
    agl1=PI*2*(double)rx_angle[0]/65535;
    
//    if(flagxb==0){
//        angle_pre=agl1;
//	flagxb=1;
//    }
    angle_delta = agl1 - angle_pre;
    angle_pre   = agl1;
    
    if(angle_delta>PI)
        angle_delta -= TWO_PI;
    if(angle_delta<-PI)
        angle_delta += TWO_PI;
    //while(!(EIC91&(_PORT_SET_BIT12)==_PORT_SET_BIT12));
    EIC91 &=_PORT_CLEAR_BIT12;
    
    //P1 |= _PORT_SET_BIT4;
    //P1 &= _PORT_CLEAR_BIT4;	
}