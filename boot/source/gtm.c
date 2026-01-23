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
#include "gtm.h"
#include "global.h"
#include "tmr.h"
#include "tmr_macrodriver.h"
#include "global_struct.h"
#include "pi_controller.h"
#include "hv_svgen.h"
#include "transformation.h"
#include "parameter.h"
#include "r_adc.h"
#include "fliter.h"
#include "temperature.h"
#include <mttcan.h>

//yingchuang head file
#include "SWC_BasAsst.h"
#include "SWC_TAS.h"
#include "rtwtypes.h"
#include "RSENT_receive.h"

int init_int(void);
void gtm_start(void);
void choose(void);
//环路
inline void LoopCtrl(void);
inline void CurrentLoop(float IqRef,float Idref,float IqFbk,float IdFbk);
inline void SpeedLoop(float SpdRef,float SpdFbk) ;
inline void FWLoop(void);
inline void PosLoop(float PosRef,float PosFbk);

void MainISRInit(void);             //主中断初始化
inline void SaveData(void);         //测试数据存储
inline void MainISR(void);          //主中断运行函数
inline void SampleAndProtect(void); //采样与保护
inline void AngleProcess(void);     //角度处理判断

//处理函数
inline void  GetPosition(void);                       //位置计算
inline float ComputeSpeed(double angle,SpeedCal *v);  //转速计算
inline void  CurRecs(void);                           //电流处理
// 位置插补函数
inline float PosInterpolation(float target_pos);      //位置插补（传入目标位置，返回插补后位置）

//初始定位
void Alignment(void);
void Alignment_open(void) ;
void Aligment_rotate(void);
void Aligment_close(void);

inline void EPSYC(void);
inline void EPSLoop(void);

//外部引用
extern volatile	uint16_t send_data[4];
extern volatile	uint16_t rx_data[4];
extern uint16_t Gu1ReadAdcValue[32];
extern uint16_t flag_adc;
volatile uint16_t rx_angle[4];
volatile uint16_t flag_angle;
volatile double angle;
extern uint16_t High_temperature;
extern float temperature ;
extern int FlagCansend;
extern int cantime;
extern uint32_t Over_Time_TAS;
extern uint8_t TAS_Err_Flag;
extern struct r_sentdata SENT_DATA;
extern int32_t store1;
extern uint32_t period_range_error;
extern uint32_t duty_range_error;
extern uint8_t TAS_Err_Flag;
extern uint32_t wr_sort;
extern uint32_t TAS_Err_Count;
extern float Old_Angle ;
extern float old_difference ; 
extern float current_difference;

float testfywp = 0;
float testfywi = 0;

extern int Flag_CAN_flash;
extern int Flash_fix;

//变量定义
unsigned long  IsrTicker    = 0;
unsigned long  VirtualTimer = 0;  
unsigned int error_state_code_0101=0;
unsigned int SpeedInit=0;
unsigned int outrangecount=0;

//初始定位数组、变量
double Alig_angle_e[POLES+1];
double Ali_angle[POLES+1];         
int xb=0;

int fyw=0;                 //存数据跨度
int RecsFlag = 4;          //电流重构标志位
int TestFlag = TESTFLAG;   //0:test    1:can
extern int lsw = LSW;      //环路选择
int lswpre;                //储存给定环路
int FWFlag=1;             //弱磁标志位 1：启动弱磁

//保护数组-电流、电压
float currentABuffer[4];
float currentBBuffer[4];
float currentCBuffer[4];
float voltageBuffer[4];
float fwvoltageBuffer[4];

//电流采样偏置参数计算
float offsetA=0;
float offsetB=0;
float offsetC=0;
float K1= 0.998 ;	  //Offset filter coefficient K1: 0.05/(T+0.05);
float K2= 0.002 ;	  //Offset filter coefficient K2: T/(T+0.05);

//数据存储数组
float speedfbk[3000];
float iqref[3000];
float iqfbk[3000];
float idref[3000];
float idfbk[3000];

//float dif_cur[3000];
//float TAS_errcount[3000];
//float cont_angle[3000];
//float dif_old[3000];
//float TAS_errflag[3000];
//float angle_old[3000];
//float posref[3000];
float posfbk[3000];
//float fwout[3000];
//float fwspeed[3000];
//float speedout[3000];
float speedref[3000];
float Angle_last = 0;
extern float angle_out;    //extern TAS angle
double omiga=0;
float  beta;
unsigned int s=0;

//浮点角度-双精度
double agl1;
double angle_pre;
double angle_delta;
double angle_fli;

//标志位
int flagxb=0;
int flag_5060=0;
float steptest=0;
// Instance a few transform objects
CLARKE clarke1 = CLARKE_DEFAULTS;
CLARKE clarke2 = CLARKE_DEFAULTS;
PARK   park1   = PARK_DEFAULTS;
IPARK  ipark1  = IPARK_DEFAULTS;
int fwenterflag=0;

SVGEN svgen1    = SVGEN_DEFAULTS;
SVGEN svgentest = SVGEN_DEFAULTS;


int flag1,flag2;

int init_int()
{
   EIC159  = 0x000F;//INTGTM_ATOM0_7
   EIBD159 = 0x00000001;
   EIC145   = 0x0041;//INTGTM_TIM1_1 //GTM01I1 is connected to GTM0AT0O1
   EIBD145  = 0x00000001;
   return 0;
}

void GTM_Init()
{
    unsigned int status=0; 
    // Configure INTC
    init_int();

    //printf ("Configure CMU\n");
    GTM0.CMUGCLKNUM  = 0x0FFFF; // global divider = *1
    GTM0.CMUGCLKDEN  = 0x0FFFF;    
    GTM0.CMUCLK3CTRL = 0x00000004; // sys_clk_period *5 = 62,5ns @ 80MH sys_clk
    GTM0.CMUCLKEN    = 0x00000080; // enable CMU clock 3
    status = GTM0.CMUCLKEN & 0x00C0;
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

void De_Mos(void)  
{
    GTM0.DTM24CHCTRL2 = 0x22222200;    // disable dead time channel 1,2,3
    g_Control.Dutycycle_A = 0;         //占空比置于50%
    g_Control.Dutycycle_B = 0;
    g_Control.Dutycycle_C = 0;

}

void On_Mos(void)  
{
   
    GTM0.DTM24CHCTRL2 = 0x88888800;   // enable dead time channel 1,2,3
    pi_id.Out = 0;       //同时将pi调节器各部分都强行置0
    pi_id.i1  = 0;
    pi_iq.Out = 0;
    pi_iq.i1  = 0;
    pi_spd.Out= 0;
    pi_spd.i1 = 0;
    pi_fw.Out = 0;
    pi_fw.i1  =  0;
    
    g_Control.SpdRef = 0;
    g_CANflash.spdRef_float = 0;
    
    outrangecount=0;    //超差计数清除
    omiga=0;            //转速s曲线清除
    VirtualTimer=0;     //程序定时计数清除
    alarm.current_level1 = 0;
    alarm.current_level2 = 0;
    alarm.current_level3 = 0;
    alarm.Lock_rotor = 0;
    alarm.temp_High = 0;
    alarm.TAS_break = 0;
    alarm.TAS_signal_abnormal = 0;
    alarm.voltage_low = 0;
    alarm.ADC12_outrange = 0;
    alarm.spd_outrange = 0;
    alarm_recover.temp_norm = 0;
    alarm_recover.speed_norm = 0;
    alarm_recover.posRef_norm = 0;
    alarm_recover.Lock_rotor_norm = 0;
    error_state_code_0101 &= 0x0000;//清除故障码
    g_Control.pos.PosOld = angle;//位置初始化
    if(lsw==5){
    	g_Control.pos.PosSum = g_Control.TAS.TAS_angle*0.28798;
	    g_Control.PosRef = g_Control.TAS.TAS_angle*2.2917;
    }
    else
        g_Control.pos.PosSum = 0;
}

//调试程序定时
inline void TestStop(void){
    if(TestFlag==0&&lsw!=0&&g_Control.iRunState==100){
        if(VirtualTimer<20000*stoptime)  
            VirtualTimer++;
        else if(VirtualTimer>=20000*stoptime&&VirtualTimer<20000*(stoptime+1)){
            VirtualTimer++;
            g_Control.iRunState = 404;
            De_Mos();
	}
    }
}

//测试数据存储
inline void SaveData(void){
    if(fyw==0){
        if((g_CANflash.runState==255||TestFlag==0)&&g_Control.iRunState==100&&s<3000){   // T = (fyw+1）*0.25S
        	//dif_cur[s] = current_difference;//clarke1.As;//filter_2nd_order(Speed1.realspeed);
	    	//TAS_errcount[s] = TAS_Err_Count;
           
	    	//cont_angle[s] = g_Control.TAS.TAS_angle;//filter_2nd_order(g_Control.m_speed.Speed);
        	//dif_old[s] = old_difference;//filter_3nd_order(g_Control.m_speed.Speed);
	    
	    	//TAS_errflag[s] = TAS_Err_Flag;
        	//angle_old[s] = Old_Angle - g_Control.TAS.TAS_angle_comp;//pi_spd.Ref;//g_Control.TAS.TAS_angle;//g_Control.pos.PosSum;//angle_out;//pi_spd.Out;
	    	//fwout[s] = pi_fw.Out;
	    	//fwspeed[s] = g_Control.FW.Speed;
		
		
		iqref[s]=pi_iq.Ref;
		iqfbk[s]=pi_iq.Fbk;
		idref[s]=pi_id.Ref;
		idfbk[s]=pi_id.Fbk;
	   
	    	//posref[s] = angle_out;
	    	posfbk[s] = angle_out;
	    
	    
	    	speedref[s] = pi_spd.Ref* SPEED_PU_RE;
	    	//speedout[s] = pi_spd.Out;
            	speedfbk[s] = pi_spd.Fbk * SPEED_PU_RE;//g_Control.pos.PosSum;//g_Control.TAS.TAS_angle;//angle_out;//-g_Control.m_speed.Speed;//
	    	s++;
        }else if(flag1==1&&g_Control.iRunState==100&&s>=5000&&TestFlag==1){
            s = 0;
	    g_CANflash.runState = 0;
	    flag1=0;
        }
        fyw=0;
     }
    else
        fyw--;
}

#pragma interrupt INTGTM_ATOM0_7(enable=1, channel=159, fpu=1, callt=1)
 void INTGTM_ATOM0_7(void)//mainISR
{ 
//    __EI();
//    R_ADC_ScanGroup_Start(1, 0);
//    R_ADC_ScanGroup_Start(0, 0);
//    if(PPR4 & 0x0080)
//    {flag_5060 = 1;}
    
    FlagCansend++;
    cantime++;
//    R_CSIH1_Master_Send((uint16_t*)send_data,  _CSIH_SELECT_CHIP_6,(uint16_t*)rx_data);  //tmr
//    GTM0.ATOM07IRQNOTIFY = 0x00000003; // reset NOTIFY flags  
   
//    TestStop();//调试程序定时
    
//    //高温标志位：High_temperature
//    temperature = ADC_Temperature();

//    //角度获取 angle_out
//    Get_Angle_Data();
//    g_Control.TAS.TAS_angle = angle_out - g_Control.TAS.TAS_angle_comp;
    
//    if(TAS_Err_Flag == 0 ){
//        Angle_last = angle_out;
//    }
//    //速度计算
//    g_Control.m_speed.Speed = ComputeSpeed(agl1,&Speed1); 
//    //g_Control.m_speed.Speed = filter_2nd_order(g_Control.m_speed.Speed);  //速度二阶滤波
//    g_Control.m_speed.Speed = filter_3nd_order(g_Control.m_speed.Speed);  //速度三阶滤波
    
//    //ADC 转换标志位判断
//    while(flag_adc==0);
//        flag_adc = 0;

//    //状态机选择
//    switch(g_Control.iRunState){
//        case 0:  //初始化
//            AngleProcess();     //角度处理
//            MainISRInit();      //主中断初始化	
//        break;
//        case 100://正常运行
//            SampleAndProtect(); //电流采样与保护
//            AngleProcess();     //角度处理
//            MainISR();          //主中断运行
//        break;
//        case 4444: //停机
//            SampleAndProtect(); //电流采样与保护
//            AngleProcess();     //角度处理
//        break;
//        default:   
//            SampleAndProtect(); //电流采样与保护
//            AngleProcess();     //角度处理
//    } 
    
//    SaveData();  //数据存储
//    //占空比控制
//    //g_Control.Dutycycle_A = -1;
//    //g_Control.Dutycycle_B = -1;
//    //g_Control.Dutycycle_C = -1;

//    //限制占空比0-95% dutycycle=A/2+0.5
//    g_Control.Dutycycle_A = SATS(g_Control.Dutycycle_A,-1,MAXDUTY);
//    g_Control.Dutycycle_B = SATS(g_Control.Dutycycle_B,-1,MAXDUTY);
//    g_Control.Dutycycle_C = SATS(g_Control.Dutycycle_C,-1,MAXDUTY);
    
//    //PWM值更新  
//    GTM0.ATOM01SR0 = (T0/2)-(T0/4+(int)(g_Control.Dutycycle_A*((T0/4)-10)));
//    GTM0.ATOM01SR1 = (T0/2)+(T0/4+(int)(g_Control.Dutycycle_A*((T0/4)-10)));
//    GTM0.ATOM02SR0 = (T0/2)-(T0/4+(int)(g_Control.Dutycycle_B*((T0/4)-10)));
//    GTM0.ATOM02SR1 = (T0/2)+(T0/4+(int)(g_Control.Dutycycle_B*((T0/4)-10)));
//    GTM0.ATOM03SR0 = (T0/2)-(T0/4+(int)(g_Control.Dutycycle_C*((T0/4)-10)));
//    GTM0.ATOM03SR1 = (T0/2)+(T0/4+(int)(g_Control.Dutycycle_C*((T0/4)-10)));
}


//采样与保护
inline void SampleAndProtect(void)
{
    clarke2.As = -(float)(Gu1ReadAdcValue[2]-offsetA)*330/4095;       // Phase A curr.
    clarke2.Bs = -(float)(Gu1ReadAdcValue[3]-offsetB)*330/4095;       // Phase B curr.
    clarke2.Cs = -(float)(Gu1ReadAdcValue[0]-offsetC)*330/4095;       // Phase C curr.
    
    clarke1.As = 0*clarke1.As + 1*clarke2.As;
    clarke1.Bs = 0*clarke1.Bs + 1*clarke2.Bs;
    clarke1.Cs = 0*clarke1.Cs + 1*clarke2.Cs;
    
    //clarke1.As = 0.515*clarke1.As + 0.485*clarke2.As;
    //clarke1.Bs = 0.515*clarke1.Bs + 0.485*clarke2.Bs;
    //clarke1.Cs = 0.515*clarke1.Cs + 0.485*clarke2.Cs;
    
    if(motortype==EPS||motortype==EMB)                                                // Vbus voltage
        g_Control.Vdc = Gu1ReadAdcValue[9]/(105.07);
    else
        g_Control.Vdc = Gu1ReadAdcValue[9]/(59.583*2);
    g_Control.FW.Vdcfbk=sqrt(pi_id.Out*pi_id.Out+pi_iq.Out*pi_iq.Out);//弱磁反馈电压
       
    //电流三相电流采样处理
    CurRecs();
    //保护（电流、转速）
    protection();
}

//角度处理
inline void AngleProcess(void)
{
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
	    IsrTicker++;              //0S~0.5S  上电稳定
    else if(IsrTicker<30000){     //0.5s~1.5S计算直流偏置
        offsetA = K1*offsetA+K2*Gu1ReadAdcValue[2]; 	//Phase A offset
        offsetB = K1*offsetB+K2*Gu1ReadAdcValue[3]; 	//Phase B offset
        offsetC = K1*offsetC+K2*Gu1ReadAdcValue[0]; 	//Phase C offset
        g_Control.Dutycycle_A= -1;
        g_Control.Dutycycle_B= -1;
        g_Control.Dutycycle_C= -1;
	    IsrTicker++;
    }else if(IsrTicker<30001){     //测试模式跳过验证环节
    	SampleAndProtect();        //电流采样与保护
        if(TestFlag==0)
	        IsrTicker = 100000;    //下次跳到最后，测试模式
        else 
	        IsrTicker++;    
	    IsrTicker = 100000;
    }else if(IsrTicker<50001){     //1.5s~2.5S定位到某一极
        g_Control.Dutycycle_A= -0.7; 
        g_Control.Dutycycle_B= -1;
        g_Control.Dutycycle_C= -1;
    	SampleAndProtect();    
        IsrTicker++;    
    }else if(IsrTicker<70001){     //2.5s~3.5S定位到某一极
        g_Control.Dutycycle_A= -0.6; 
        g_Control.Dutycycle_B= -1;
        g_Control.Dutycycle_C= -1;
    	SampleAndProtect();    
        IsrTicker++;      
    }else if(IsrTicker<70002){     //初始角度验证
	flag.AliCheck = AliCheck(g_Control.angle_e,g_Control.Aligmenta.Ali_angle);  //1:初始定位角度正常 0：异常
	if(flag.AliCheck==0&&lsw!=0){  //定位角度异常且当前不处于定位模式时
	    lswpre = lsw;         //储存环路信息
	    lsw = 0;              //初始角度异常，进入定位模式，重新定位
	   // error_state_code_0101 = 0x0001;  //错误标志位:定位故障
	}
	g_Control.Dutycycle_A= -1; //关管
        g_Control.Dutycycle_B= -1;
        g_Control.Dutycycle_C= -1;
        IsrTicker++;    
    }
    else{
        if((TestFlag==0)||(TestFlag==1&&lsw==5))
            g_Control.iRunState  = 100;//4444;//
        else
            g_Control.iRunState  = 4444;//100;//
        
        g_Control.pos.PosOld = angle;//位置初始化
        if(lsw==5){
                g_Control.pos.PosSum = g_Control.TAS.TAS_angle*0.28798;
                g_Control.PosRef = g_Control.TAS.TAS_angle*2.2917;
            }
            else
                g_Control.pos.PosSum = 0;
        
        // 初始化位置插补器
        g_PosInterp.current_pos = g_Control.PosRef;
        g_PosInterp.target_pos = g_Control.PosRef;
        g_PosInterp.start_pos = g_Control.PosRef;
        g_PosInterp.interpolation_count = POS_INTERP_STEPS;
        
        flag1=0;
        flag2=0;
        clarke1.As = -(float)(Gu1ReadAdcValue[2]-offsetA)*330/4095;       // Phase A curr.
        clarke1.Bs = -(float)(Gu1ReadAdcValue[3]-offsetB)*330/4095;       // Phase B curr.
        clarke1.Cs = -(float)(Gu1ReadAdcValue[0]-offsetC)*330/4095;       // Phase C curr.
    }
}

//主中断运行函数
inline void MainISR(void){
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

unsigned long counts1 = 0;
//给定设置
inline void SetLoopRef(){
    if(TestFlag==0){ //定时测试给定
    
        /*
        if (counts1<=20000*5){
            g_Control.PosRef = POS_REF*POSITION_PU;
        counts1++;
        }
        else if (counts1<20000*10&&counts1>20000*5){
        g_Control.PosRef = -POS_REF*POSITION_PU;
        counts1++;
        }
        else 
            counts1=0;
        */
        switch(lsw)
        {
            case JWDL:   
                g_Control.POSRefDeg = JWD_REF;
                g_Control.PosRef = g_Control.POSRefDeg*2.2917;                           //位置给定
                g_Control.PosRef = SATS(g_Control.PosRef,-500*2.2917,500*2.2917);
                
                break;
            case position:
                g_Control.PosRef = POS_REF*POSITION_PU;         //位置给定
                break;
            case speed:
                g_Control.SpdRef = Speed_Ref*SPEED_PU;          //测试固定转速给定
                break;
            case current:
                g_Control.IqRef = IQ_REF*CURRENT_PU;            //q轴电流给定
                g_Control.IdRef = ID_REF*CURRENT_PU;            //d轴电流给定
                break;
        }
    }
    
    if(TestFlag==1){  //CAN给定
        switch(lsw)
        {	
            case JWDL:
                if(CAN2.flag&_PORT_SET_BIT0){   
                    g_Control.POSRefDeg = CAN2.Angle;
                    g_Control.PosRef = g_Control.POSRefDeg*2.2917;
                    pi_pos.Umax = SATS(CAN2.AngleSpd*2.75,2000,2000)*SPEED_PU;   //16.5*60/360   传动比*60秒/360°  将角速度deg/s换算为Rpm
                    pi_pos.Umin =-pi_pos.Umax;
                    CAN2.flag &= _PORT_CLEAR_BIT0;
                }
            
                break;
                
            case position:
                if(g_CANflash.flag&_PORT_SET_BIT8){        
                    if(g_CANflash.SpeedMax!=0){                                     //速度限幅
                        g_Control.PosRef = g_CANflash.posRef_float*POSITION_PU;
                        pi_pos.Umax = g_CANflash.SpeedMax*SPEED_PU;
                        pi_pos.Umin =-pi_pos.Umax;
                    }
                    if(g_CANflash.CurMax!=0){                                       //电流限幅
                        pi_spd.Umax = g_CANflash.CurMax*CURRENT_PU;
                        pi_spd.Umin =-pi_spd.Umax;
                    }
                    g_CANflash.flag &=_PORT_CLEAR_BIT8;
                }
                break;
            case speed:
                if(g_CANflash.flag&_PORT_SET_BIT5){          
                        //g_Control.SpdRef = 0.999*g_Control.SpdRef + 0.001*g_CANflash.spdRef_float*SPEED_PU;
                //g_Control.SpdRef = g_CANflash.spdRef_float*SPEED_PU;
                //g_Control.SpdRef = g_Can_Atrib.spdRef_float*SPEED_PU;        //转速给定通过CAN通讯更新
                if(g_CANflash.CurMax!=0){                                      //电流限幅
                        pi_spd.Umax = g_CANflash.CurMax;
                    pi_spd.Umin =-pi_spd.Umax;
                    //g_CANflash.CurMax = 0;
                }
                    g_CANflash.flag &=_PORT_CLEAR_BIT5;
                    }
                g_Control.SpdRef = 0.999*g_Control.SpdRef + 0.001*g_CANflash.spdRef_float*SPEED_PU;
                break;
            case current:
                if(g_CANflash.flag&_PORT_SET_BIT2){              //2:IdRef&IqRef
                    g_Control.IqRef = SATS(g_CANflash.qRef_float,-108,108)*CURRENT_PU;
                        g_Control.IdRef = SATS(g_CANflash.dRef_float,-108,  0)*CURRENT_PU;
                    g_CANflash.flag &=_PORT_CLEAR_BIT2;
                }
                break;
        }
    }
}

//环路选择
inline void LoopCtrl(void)
{
    SetLoopRef();                                                       //给定设置
    
    switch(lsw)
    {
        case JWDL:
            GetPosition();                                                  //获取位置-TMR绝对位置
            g_Control.PosFbk = g_Control.pos.PosSum*POSITION_PU;            //位置反馈
            //g_Control.PosFbk = g_Control.TAS.TAS_angle*0.28798;
            PosLoop(g_Control.PosRef,g_Control.PosFbk);
        break;
        
        case position:
            GetPosition();                                                 //获取位置-电机相对位置
            g_Control.PosFbk = -g_Control.pos.PosSum*POSITION_PU;          //位置反馈
            PosLoop(g_Control.PosRef,g_Control.PosFbk);
        break;

        case EPSL:
            EPSLoop();
        break;
        
        case speed:
            g_Control.SpdFbk = g_Control.m_speed.Speed*SPEED_PU;            //转速反馈
            SpeedLoop(g_Control.SpdRef,g_Control.SpdFbk); 
        break;
            
        case current:
            CurrentLoop(g_Control.IqRef,g_Control.IdRef,park1.Qs,park1.Ds);
        break;
        
        case Aligement:
            Alignment();                                                   //初始定位 
        break;
        
        case openloop:
            Openloop();                                                    //开环
        break;
        
        default:
            g_Control.Dutycycle_A = -1;
            g_Control.Dutycycle_B = -1;
            g_Control.Dutycycle_C = -1;
        break;    
    }
}
//电流环
inline void CurrentLoop(float IqRef,float Idref,float IqFbk,float IdFbk)
{

    pi_iq.Ref = IqRef;
    pi_id.Ref = Idref;
    pi_iq.Fbk = park1.Qs*CURRENT_PU ;
    pi_id.Fbk = park1.Ds*CURRENT_PU ;
    PI_CUR(&pi_iq);
    PI_CUR(&pi_id);
    //PI_MACRO(pi_iq)
    //PI_MACRO(pi_id)
    
    ipark1.Ds   = pi_id.Out;
    ipark1.Qs   = pi_iq.Out;
    ipark1.Sine = park1.Sine;
    ipark1.Cose = park1.Cose;
    IPARK_MACRO(ipark1)

    svgen1.Ualpha = ipark1.Alpha/IQ_MAX;
    svgen1.Ubeta  = ipark1.Beta/IQ_MAX ;
    
    svpwm(&svgen1);
    //SVGENDQ_MACRO(svgen1)
	    
    g_Control.Dutycycle_A = svgen1.Ta;
    g_Control.Dutycycle_B = svgen1.Tb;
    g_Control.Dutycycle_C = svgen1.Tc;
}

int SIGN(float x){
	if(x > 0){
		return 1;
	}else if(x < 0){
		return -1;
	}else 
	return 0;
}

//转速环
inline void SpeedLoop(float SpdRef,float SpdFbk)
{
	

    g_Control.FW.Speed = 0.99*g_Control.FW.Speed+0.01*g_Control.m_speed.Speed;  //0.97
    //计算弱磁限度
    if(g_Control.count.SatCount==1){
        if(ABS(g_Control.FW.Speed)>1000 && FWFlag==1){
	    pi_spd.Umax = POWER/ABS(g_Control.FW.Speed);
	    pi_spd.Umin =-pi_spd.Umax;
	    pi_fw.Umin  =-sqrt(IS_SQU-pi_spd.Umax*pi_spd.Umax);
	    //if(pi_fw.Umin<-200)
	    	//pi_fw.Umin = -200;
	}else{
	    pi_spd.Umax = SPEED_MAX;
	    pi_spd.Umin = SPEED_MIN;
	    pi_fw.Umin  = 0;
	}
	g_Control.count.SatCount = SAT_LOOP;
    }else
        g_Control.count.SatCount--;
    
    //转速环计算
    if(g_Control.count.SpeedLoopCount==1){ //转速环分频
        pi_spd.Ref = SpdRef;
        pi_spd.Fbk = SpdFbk*SPEEDDIR;
        //PI_SPD(&pi_spd);
        PI_1(&pi_spd);     //动态限幅
        g_Control.count.SpeedLoopCount = SPEED_LOOP;
    }else
        g_Control.count.SpeedLoopCount--;
  
    //弱磁
    if(FWFlag==1)
        FWLoop(); 
    else{
        g_Control.IqRef = pi_spd.Out;
	    g_Control.IdRef = 0;
    }

    //过温警告，将电流要求设置为原来的50%实现降载
    if((((error_state_code_0101>>7) & 0x01) == 1) && (alarm.temp_High < 2000))
    { 
         g_Control.IqRef = SIGN(g_Control.IqRef) * 10;
    }
	
    //电流环
    CurrentLoop(g_Control.IqRef,g_Control.IdRef,park1.Qs,park1.Ds);
    
}

inline void EPSLoop(void)
{
    //int  FWFlag=1;   //弱磁标志：0-不弱磁
   // BA_StrTrq_Nm_f32_Read;//传感器手力矩；
   // BA_VehSpd_kph_f32_Read;//整车车速；
    BA_StrVel_degps_f32_Read=0;//角速度-给固定值0；
    EPSYC();
   
    pi_spd.Out = 83.143350*BA_BaTrq_Nm_f32_Write-4.859172;//BA_BaTrq_Nm_f32_Write：电机助力输出值；
    g_Control.FW.Speed = 0.99*g_Control.FW.Speed+0.01*g_Control.m_speed.Speed;  //0.97
    //计算弱磁限度
    if(g_Control.count.EPSTasLoopCount==6){
        if(ABS(g_Control.FW.Speed)>1000&&FWFlag==1){
	    pi_spd.Umax = POWER/ABS(g_Control.FW.Speed);
	    pi_spd.Umin =-pi_spd.Umax;
	    pi_fw.Umin  =-sqrt(IS_SQU-pi_spd.Umax*pi_spd.Umax);
	    //if(pi_fw.Umin<-200)
	    	//pi_fw.Umin = -200;
	}else{
	    pi_spd.Umax = SPEED_MAX;
	    pi_spd.Umin = SPEED_MIN;
	    pi_fw.Umin  = 0;
	}
    }
  
    //弱磁
    if(FWFlag==1)
        FWLoop(); 
    else{
        g_Control.IqRef = pi_spd.Out;
	    g_Control.IdRef = 0;
    }
	
    //电流环
    CurrentLoop(g_Control.IqRef,g_Control.IdRef,park1.Qs,park1.Ds);
}

//英创上层程序
inline void EPSYC(void)
{
    if (++g_Control.count.EPSTasLoopCount >= 20)
        g_Control.count.EPSTasLoopCount = 0;

    // BA_StrTrq_Nm_f32_Read;//传感器手力矩；TAS_StrAng_deg_f32_Write
    BA_VehSpd_kph_f32_Read = 0;        //整车车速；TAS_AngResolutionFlt_Write
    BA_StrVel_degps_f32_Read = 0;      //角速度-给固定值0；
    switch (g_Control.count.EPSTasLoopCount)
    {
	case 0:
	    SENT_receive_start();          //SENT通讯得到转矩
	    break;
        case 1:
	    //输入赋值
	    TAS_SENT1A_NA_u16_Read = SENT_DATA.SENT1A;    //传感器SENT信号-SENT1A
	    TAS_SENT2A_NA_u16_Read = SENT_DATA.SENT2A;    //传感器SENT信号-SENT2A
	    TAS_SENT_ANG_NA_u16_Read = SENT_DATA.SENT3A;  //传感器SENT信号-SENT3A
	    TAS_AngOffset_deg_f32_Read = 0;               //TAS角度偏移量:标定量
	    
	    //TAS_TrqOffset_Switch_NA_u8_Cal= 0;
	    TAS_AngOffset_deg_f32_Cal = -375;//TAS_StrAng_deg_f32_Write //TAS_AngOffset_deg_f32_Cal
	    TAS_AngCalbra_NA_bl_Read   = 0;
	    TAS_SENT1_LossOfSignal_NA_bl_Read = 0;
	    TAS_SENT2_LossOfSignal_NA_bl_Read = 0;
	    TAS_SENT3_LossOfSignal_NA_bl_Read = 0;
	    TMT_Rnbl_TAS_StrAng();         // 执行转向角度处理
            break;
	case 2:
	    TAS_SENT1_LossOfSignal_NA_bl_Read = 0;
	    TAS_SENT2_LossOfSignal_NA_bl_Read = 0;
	    TAS_SENT1B_NA_u16_Read = SENT_DATA.SENT1B;    //传感器SENT信号-SENT1B
	    TAS_SENT2B_NA_u16_Read = SENT_DATA.SENT2B;    //传感器SENT信号-SENT2B
            TMT_Rnbl_TAS_StrTrq();         // 转向扭矩计算
            break;
        case 3:
	    BA_StrTrq_Nm_f32_Read = TAS_StrTrq_Nm_f32_Write;
            TMT_Rnbl_BA_BlendFilter();     // 力矩滤波分离
            break;
        case 4:
            TMT_Rnbl_BA_BoostCurve();      // 助力曲线
            break;
        case 5:
            TMT_Rnbl_BA_HighFreqAsst();    // 高频助力
            break;
        case 6:
            TMT_Rnbl_BA_TrqMonitor();      // 力矩限幅
            break;
        case 7:
            TMT_Rnbl_BA_NotchFilter();     // 陷波器
            break;
        default:
            break;
    }
}

//弱磁
inline void FWLoop(void)
{
	fwenterflag=1;
	if(g_Control.count.FWLoopCount==1){    //弱磁环分频
        	pi_fw.Ref = FW_REF ;
        	pi_fw.Fbk = g_Control.FW.Vdcfbkfli;
        	PI_MACRO(pi_fw)
        	g_Control.IqRef = pi_spd.Out;
        	g_Control.IdRef = pi_fw.Out;
	    	g_Control.count.FWLoopCount = FW_LOOP;
   	}else
       	g_Control.count.FWLoopCount--;
}

//double omiga;
//位置环
inline void PosLoop(float PosRef,float PosFbk)
{
    //static int timecount = 0;
    if(g_Control.count.PosLoopCount==1){
        
        // 使用插补算法平滑位置给定
        pi_pos.Ref = PosInterpolation(PosRef);
        pi_pos.Fbk = PosFbk;
        PI_1(&pi_pos);
        g_Control.count.PosLoopCount = POS_LOOP;
        


        // 不使用插补算法控制
        //pi_pos.Ref = PosRef*sinf(omiga);//*omiga;//
        //omiga +=0.001256637;   //T=12 0.00057119866  T=6  0.001047197 T=3 0.002094394
	//T=5 0.001256637
        //if(omiga>TWO_PI) omiga-=TWO_PI;
        //pi_pos.Fbk = PosFbk;
       // PI_1(&pi_pos);
        //g_Control.count.PosLoopCount = POS_LOOP;
        
        
        
        //定时校准部分
        //timecount++;
        // if(timecount==200000&&lsw==5&&ABS(pi_pos.up<0.001)
        // &&ABS(g_Control.POSRefDeg-g_Control.TAS.TAS_angle)>0.1){
        //     g_Control.pos.PosSum = g_Control.TAS.TAS_angle*0.28798; 
        //     timeflag ++;
        // }
        //if(timecount>=200000)
            //timecount = 0;
    }
    else
        g_Control.count.PosLoopCount--;
	
    //转速环  
    g_Control.SpdRef = pi_pos.Out;                         //位置环输出作为转速环给定
    g_Control.SpdFbk = g_Control.m_speed.Speed*SPEED_PU;
    SpeedLoop(g_Control.SpdRef,g_Control.SpdFbk);
}

//开环
inline void Openloop(void)
{
    ipark1.Ds = VD_REF;
    ipark1.Qs = VQ_REF;
    ipark1.Angle = g_Control.angle_e;//ipark1.Angle+OPENSTEP;//0.0005*PI;//
    if(ipark1.Angle>(2*PI)){
	ipark1.Angle=ipark1.Angle-2*PI;
    }
    ipark1.Sine = sin(ipark1.Angle);//or ipark1.Angle
    ipark1.Cose = cos(ipark1.Angle);
    IPARK_MACRO(ipark1)
// ------------------------------------------------------------------------------
//  Connect inputs of the SVGEN_DQ module and call the space-vector gen. macro
// ------------------------------------------------------------------------------
    svgen1.Ualpha = ipark1.Alpha;
    svgen1.Ubeta  = ipark1.Beta ;
    svgentest.Ualpha = ipark1.Alpha;
    svgentest.Ubeta  = ipark1.Beta ;
    svpwm(&svgen1);
    //SVGENDQ_MACRO(svgen1)
    
    g_Control.Dutycycle_A = svgen1.Ta;
    g_Control.Dutycycle_B = svgen1.Tb;
    g_Control.Dutycycle_C = svgen1.Tc;
}

//初始角度定位
void Alignment(void)
{
    float aglsum=0;
    float delta;
    int xbs=0;
    if(Aligment.Flag==1&&xb!=(POLES+1)){       //1:定位
        if(ALIG_LOOP==0)    //0:开环
            Alignment_open();
        else if(ALIG_LOOP==1)//1:闭环
            Aligment_close(); 
        else
            De_Mos();         //错误封管
    }
    else if(Aligment.Flag==2&&xb!=(POLES+1)){   //2:转动
        Aligment_rotate();
    }
    else{
        De_Mos();             //结束封管
	// 计算极对数方向的平均电角度
        for (xbs = 1; xbs < (POLES+1); xbs++) {
	    delta = Alig_angle_e[xbs]-Alig_angle_e[1];
	    // wrap 到 [-π, π)
            if (delta > PI) delta -= 2*PI;
            if (delta < -PI) delta += 2*PI;
	    aglsum+=delta;
        }
	
	// 计算平均电角度并保存到控制结构体
        g_Control.Aligmenta.Ali_angle = Alig_angle_e[1]+aglsum / POLES;

        while(g_Control.Aligmenta.Ali_angle >= 2 * PI)
            g_Control.Aligmenta.Ali_angle -= 2 * PI;
        while(g_Control.Aligmenta.Ali_angle <=-2 * PI)
            g_Control.Aligmenta.Ali_angle += 2 * PI;
        
        if(TestFlag==1){  //不处于调试模式时
            flag.AliCheck = 1;                //初始角度定位完成标志 需要烧写到FLAH中
            g_Control.iRunState = 4444;       //电机恢复停止状态
            g_CANflash.runState= 0;          //避免上次CAN启动，需重新发CAN指令才可以启动
            error_state_code_0101 &= 0xFFFE;  //将定位错误标志位复位
            lsw = lswpre; //恢复环路设置
            Flag_CAN_flash = 1;
            //FAD_FlashOperation((int)(g_Control.Aligmenta.Ali_angle*1000),flag.AliCheck);
        }
    }
}

//初始角度定位-旋转
void Aligment_rotate(void)
{
    double agldelta;
    ipark1.Ds = 0;
    ipark1.Qs = 0.2;
    ipark1.Angle = ipark1.Angle+0.001;
    if(ipark1.Angle>(2*PI)){
	ipark1.Angle=ipark1.Angle-2*PI;
    }
    ipark1.Sine = sin(ipark1.Angle);//or ipark1.Angle
    ipark1.Cose = cos(ipark1.Angle);
    IPARK_MACRO(ipark1)
// ------------------------------------------------------------------------------
//  Connect inputs of the SVGEN_DQ module and call the space-vector gen. macro
// ------------------------------------------------------------------------------
    svgen1.Ualpha = ipark1.Alpha;
    svgen1.Ubeta  = ipark1.Beta ;
    svgentest.Ualpha = ipark1.Alpha;
    svgentest.Ubeta  = ipark1.Beta ;
    svpwm(&svgen1);
    
    g_Control.Dutycycle_A = svgen1.Ta;
    g_Control.Dutycycle_B = svgen1.Tb;
    g_Control.Dutycycle_C = svgen1.Tc;
    
    agldelta = Aligment.anglepre-angle;
    if(agldelta>PI)
        agldelta = agldelta-2*PI;
    if(agldelta<-PI)
        agldelta = agldelta+2*PI;
    if(ABS(agldelta)>1){
	Aligment.Flag = 1; //进入定位状态
	ipark1.Angle  = 0; //清除角度
    }
}
//初始角度定位-开环定位
void Alignment_open(void) 
{
    g_Control.Dutycycle_A = -0.6;
    g_Control.Dutycycle_B = -1;
    g_Control.Dutycycle_C = -1;
    if(Aligment.count<30000)  //定位稳定阶段
        Aligment.count++;
    else if(Aligment.count==30000){
        Aligment.angle = g_Control.angle_e;
	Aligment.count++;
    }
    else if(Aligment.count>30000&&Aligment.count<60000){
        Aligment.angle = 0.001*g_Control.angle_e+0.999*Aligment.angle; 
	Aligment.count++;
    }
    else{
	Alig_angle_e[xb] = Aligment.angle;
	Ali_angle[xb++]  = angle;          //将电角度和角度数据记录在数组中
	Aligment.anglepre= angle;
	Aligment.Flag = 2;    //一次定位结束，开始旋转
	Aligment.count= 0;    //清除计数
    }
    g_Control.Aligmenta.Ali_angle = g_Control.angle_e;
}
//初始角度定位-闭环定位
void Aligment_close(void)
{
    clarke1.As = -clarke1.As;// Phase A curr.
    clarke1.Bs = -clarke1.Bs;// Phase B curr.
    CLARKE_MACRO(clarke1)

    park1.Sine = 0 ;       //a to alpha
    park1.Cose = 1;
    PARK_MACRO(park1)

    g_Control.Aligmenta.Ali_count++;
    g_Control.Aligmenta.Id_count = g_Control.Aligmenta.Ali_count/100;
    if(g_Control.Aligmenta.Id_count > 0 && g_Control.Aligmenta.Id_Cal < 1)
    {
        g_Control.Aligmenta.Ali_count = 0;
        g_Control.Aligmenta.Id_Cal = g_Control.Aligmenta.Id_Cal+0.05;
    }
	 
    pi_iq.Ref = 0 ;      //g_Control.Aligmenta.Id_Cal;
    pi_iq.Fbk = park1.Qs ;
    pi_id.Ref = 2;//g_Control.Aligmenta.Id_Cal ;     //PI_id_ref;
    pi_id.Fbk = park1.Ds ;
    PI_MACRO(pi_iq)
    PI_MACRO(pi_id)
    
    ipark1.Ds   = pi_id.Out;
    ipark1.Qs   = pi_iq.Out;
    ipark1.Sine = park1.Sine;
    ipark1.Cose = park1.Cose;
    IPARK_MACRO(ipark1)

    svgen1.Ualpha = ipark1.Alpha;
    svgen1.Ubeta  = ipark1.Beta ;
    SVGENDQ_MACRO(svgen1)
    
    g_Control.Dutycycle_A= svgen1.Ta/IQ_MAX;// -1;//
    g_Control.Dutycycle_B= svgen1.Tb/IQ_MAX;
    g_Control.Dutycycle_C= svgen1.Tc/IQ_MAX;
}

// ==================== 位置插补函数实现 ====================

// 位置插补函数
inline float PosInterpolation(float target_pos)
{
    // 如果目标位置改变，重新开始插补
    if (target_pos != g_PosInterp.target_pos) {
        g_PosInterp.target_pos = target_pos;
        g_PosInterp.start_pos = g_PosInterp.current_pos;
        g_PosInterp.interpolation_count = 0;
    }
    
    // 执行插补（POS_INTERP_STEPS 内完成）
    if (g_PosInterp.interpolation_count < POS_INTERP_STEPS) {
        g_PosInterp.interpolation_count++;
        g_PosInterp.current_pos = g_PosInterp.start_pos + 
            (g_PosInterp.target_pos - g_PosInterp.start_pos) * g_PosInterp.interpolation_count / (float)POS_INTERP_STEPS;
    } else {
        g_PosInterp.current_pos = g_PosInterp.target_pos;
    }
    
    return g_PosInterp.current_pos;
}

//位置环位置计算
inline void GetPosition(void)
{
    int flag = 1;
    if(lsw == 5)
        flag =-1;
    if(g_Control.count.PosLoopCount == 1){
        g_Control.pos.PosNew = angle;
        g_Control.pos.PosDif = g_Control.pos.PosNew - g_Control.pos.PosOld;
        //角度处理
        if(g_Control.pos.PosDif>PI)
           g_Control.pos.PosDif = g_Control.pos.PosDif-2*PI;
        else if(g_Control.pos.PosDif<-PI)
	   g_Control.pos.PosDif = g_Control.pos.PosDif+2*PI;
	    
        g_Control.pos.PosSum+= flag*g_Control.pos.PosDif ;
        g_Control.pos.PosOld = g_Control.pos.PosNew;
    }
}    

//电流处理
inline void CurRecs(void)
{  
    // 两个及以上的占空比大于85%，检查正电流情况
    if (clarke1.As < 0 && g_Control.Dutycycle_A > 0.7)
        RecsFlag = 1; // A相电流正，重构A相
    else if (clarke1.Bs < 0 && g_Control.Dutycycle_B > 0.7)
        RecsFlag = 2; // B相电流正，重构B相
    else if (clarke1.Cs < 0 && g_Control.Dutycycle_C > 0.7)
        RecsFlag = 3; // C相电流正，重构C相
       
    // 执行电流重构或更新
    switch (RecsFlag){
    case 1:
        clarke1.As = -(clarke1.Bs + clarke1.Cs);
        break;
    case 2:
        clarke1.Bs = -(clarke1.As + clarke1.Cs);
        break;
    case 3:
        clarke1.Cs = -(clarke1.As + clarke1.Bs);
        break;
    }
}

//速度计算
inline float ComputeSpeed(double angle,SpeedCal *v)
{
    static double angle_pre[6];
    static float  speed_pre[5];
    float output;
    
    //初始化
    if(SpeedInit<2){
        angle_pre[0] = angle;
        angle_pre[1] = angle;
        angle_pre[2] = angle;
        angle_pre[3] = angle;
        angle_pre[4] = angle;
        angle_pre[5] = angle;
        speed_pre[0] = 0;
        speed_pre[1] = 0;
        speed_pre[2] = 0;
        speed_pre[3] = 0;
        speed_pre[4] = 0;
        SpeedInit++;
    }
    
    //角度位置更新
    angle_pre[0] = angle_pre[1];
    angle_pre[1] = angle_pre[2];
    angle_pre[2] = angle_pre[3];
    angle_pre[3] = angle_pre[4];
    angle_pre[4] = angle_pre[5];
    angle_pre[5] = angle ;
    
    
    //角度差计算
    v->angle_now = angle_pre[5];
    v->angle_pre = angle_pre[0];   
    v->dif_angle = v->angle_now - v->angle_pre;
	
    //角度突变处理
    if(v->dif_angle<-PI)
        v->dif_angle = v->dif_angle+2*PI;
    else if(v->dif_angle>PI)
	v->dif_angle = v->dif_angle-2*PI;
    
    //角度偏差过大，采用上一次的
    if(v->dif_angle>0.1*PI)
	v->dif_angle = v->dif_angle_pre;
    else if(v->dif_angle<-0.1*PI)
        v->dif_angle = v->dif_angle_pre;
    
    v->dif_angle_pre = v->dif_angle;             //角度差更新
    v->realspeed = v->dif_angle*600000/(PI*5);   //实际机械速度

    speed_pre[0] = speed_pre[1];
    speed_pre[1] = speed_pre[2];
    speed_pre[2] = speed_pre[3];
    speed_pre[3] = speed_pre[4];
    speed_pre[4] = v->realspeed;
    
    //转速滤波处理
    output = v->realspeed;                             //速度不滤波
    return output;
}


//电角度计算
inline void Angle_get_e(double agl)
{
    g_Control.angle_e=agl*POLES; 
    while (g_Control.angle_e >= 2 * PI)
        g_Control.angle_e -= 2 * PI;
	
//    if(motortype==Booster)
    g_Control.angle_e = 2 * PI-g_Control.angle_e;
	
   //对初始定位角补偿 
    if(lsw!=0&&g_Control.iRunState!=0){
        if(g_Control.angle_e>=g_Control.Aligmenta.Ali_angle)
            g_Control.angle_e=g_Control.angle_e-g_Control.Aligmenta.Ali_angle;
        else if(g_Control.angle_e < g_Control.Aligmenta.Ali_angle)
            g_Control.angle_e=g_Control.angle_e + 2*PI- g_Control.Aligmenta.Ali_angle;
    }
}


//保护电流滑动滤波
inline void Read_ADC_Current(void)
{
    currentABuffer[0]=currentABuffer[1];
    currentABuffer[1]=currentABuffer[2];
    currentABuffer[2]=currentABuffer[3];
    currentABuffer[3]=clarke1.As;

    currentBBuffer[0]=currentBBuffer[1];
    currentBBuffer[1]=currentBBuffer[2];
    currentBBuffer[2]=currentBBuffer[3];
    currentBBuffer[3]=clarke1.Bs;

    currentCBuffer[0]=currentCBuffer[1];
    currentCBuffer[1]=currentCBuffer[2];
    currentCBuffer[2]=currentCBuffer[3];
    currentCBuffer[3]=clarke1.Cs;
    
    voltageBuffer[0] =voltageBuffer[1];
    voltageBuffer[1] =voltageBuffer[2];
    voltageBuffer[2] =voltageBuffer[3];
    voltageBuffer[3] =g_Control.Vdc ;
    
    fwvoltageBuffer[0] =fwvoltageBuffer[1];
    fwvoltageBuffer[1] =fwvoltageBuffer[2];
    fwvoltageBuffer[2] =fwvoltageBuffer[3];
    fwvoltageBuffer[3] =g_Control.FW.Vdcfbk ;

    g_Control.ControlBoardPowerDC= (voltageBuffer[0]+voltageBuffer[1]
                                    +voltageBuffer[2]+voltageBuffer[3])/4;
    g_Control.FW.Vdcfbkfli       = (1.8*fwvoltageBuffer[0]+1.5*fwvoltageBuffer[1]
                                    +0.5*fwvoltageBuffer[2]+0.2*fwvoltageBuffer[3])/4;
    g_Control.m_Current.cur_A    = (currentABuffer[0]+currentABuffer[1]
                                    +currentABuffer[2]+currentABuffer[3])/4;
    g_Control.m_Current.cur_B    = (currentBBuffer[0]+currentBBuffer[1]
				    +currentBBuffer[2]+currentBBuffer[3])/4;
    g_Control.m_Current.cur_C    = (currentCBuffer[0]+currentCBuffer[1]
				    +currentCBuffer[2]+currentCBuffer[3])/4;
}


/****************************************
故障码列表
15          14          13          12     
         温度检测失效 角度异常波动 TAS超时（断线）
11      10       9       8      
超差    超速  控制器过压  控制器欠压
7        6       5       4
过温   电机未定位 过压    欠压
3        2       1       0
转向卡滞 5060    过流     定位错误
*******************************/

//保护
inline void protection(void)
{
    static unsigned int VolLowCount;
    static unsigned int VolHighCount;
    static unsigned int err_5060_count;

    //电流保护滑动滤波
    Read_ADC_Current();
    
    //转速最大值
    if(g_Control.m_speed.Speed>g_Control.m_speed.SpeedMax)
        g_Control.m_speed.SpeedMax=g_Control.m_speed.Speed;
    else if(g_Control.m_speed.Speed<-g_Control.m_speed.SpeedMax)
	g_Control.m_speed.SpeedMax=-g_Control.m_speed.Speed;
	
    //电流取绝对值
    g_Control.r_Current.I_A = ABS(g_Control.m_Current.cur_A);
    g_Control.r_Current.I_B = ABS(g_Control.m_Current.cur_B);
    g_Control.r_Current.I_C = ABS(g_Control.m_Current.cur_C);
    
    //电流最大值
    g_Control.r_Current.I_Max = MAX_THREE(g_Control.r_Current.I_A, g_Control.r_Current.I_B, g_Control.r_Current.I_C);
     
    //电流历史最大值  
    g_Control.r_Current.I_Max_Keep = MAX(g_Control.r_Current.I_Max_Keep,g_Control.r_Current.I_Max);
    
    if(g_Control.Vdcmin==0)
        g_Control.Vdcmin = g_Control.Vdc;
    //电压历史最大值、最小值
    g_Control.Vdcmax = MAX(g_Control.Vdcmax,g_Control.Vdc);
    g_Control.Vdcmin = MIN(g_Control.Vdcmin,g_Control.Vdc);
	
    //超差保护计数
    if(ABS(pi_spd.up)>10)
        outrangecount++;
    else if(ABS(pi_spd.up)<10&&outrangecount>0)
        outrangecount--;
    else
        outrangecount=0;

    //电流保护三级计数
     // 1级电流报警
    if (g_Control.r_Current.I_Max > g_Control.prot.CurLevel1)    
        alarm.current_level1++;
    else if (alarm.current_level1>0&&
	    (g_Control.r_Current.I_Max < g_Control.prot.CurLevel1))
        alarm.current_level1--;
    else
        alarm.current_level1 = 0;
    // 2级电流报警
    if (g_Control.r_Current.I_Max > g_Control.prot.CurLevel2)    
        alarm.current_level2++;
    else if (alarm.current_level2>0&&
	     (g_Control.r_Current.I_Max < g_Control.prot.CurLevel2))
        alarm.current_level2--;
    else
        alarm.current_level2 = 0;
    // 3级电流报警
    if (g_Control.r_Current.I_Max > g_Control.prot.CurLevel3)    
        alarm.current_level3++;
    else if (alarm.current_level3>0&&
	     (g_Control.r_Current.I_Max < g_Control.prot.CurLevel3))
        alarm.current_level3--;
    else
        alarm.current_level3 = 0;
	
    // 判断电流报警级别是否达到临界值，触发保护
    if(alarm.current_level1>20){    
        error_state_code_0101 |= _PORT_SET_BIT1;
	    De_Mos();
        g_Control.iRunState = 404;
        alarm.current_level1 = 20;  //防止溢出
    }
    if(alarm.current_level2>10){    
        error_state_code_0101 |= _PORT_SET_BIT1;
	    De_Mos();
        g_Control.iRunState = 404;
        alarm.current_level2 = 10;
    }   
    if(alarm.current_level3>1){    
        error_state_code_0101 |= _PORT_SET_BIT1;
	    De_Mos();
        g_Control.iRunState = 404;
        alarm.current_level3 = 1;
    }
    

    //5060保护 封管
    if(flag_5060==1){
        if(++err_5060_count > 200){     //10ms
        error_state_code_0101 |= _PORT_SET_BIT2;
            //De_Mos();
            //g_Control.iRunState = 404;
        }
        else{
            error_state_code_0101 &= _PORT_CLEAR_BIT2;
            flag_5060 = 0;
        }
    } 


    //转向卡滞故障(输出最大扭矩且但速度很小),设立标志位
    if((ABS(pi_iq.Ref) >= CURRENT_IS) && (ABS(pi_spd.Fbk) <= 25*SPEED_PU) && (alarm.Lock_rotor < 200))
        alarm.Lock_rotor++;
    else if(alarm.Lock_rotor > 0)
        alarm.Lock_rotor--;
    if(alarm.Lock_rotor >= 200 ){
        error_state_code_0101 |=  _PORT_SET_BIT3;
        alarm.Lock_rotor = 200;
       // De_Mos();
       // g_Control.iRunState = 404;
    }

    //母线欠压保护(未进入弱磁区)
    if((g_Control.Vdc < VOLTAGE_WARN_LOW) && (ABS(g_Control.FW.Speed) <= 1000) 
        && (alarm.voltage_low < 20000*2)){  
        alarm.voltage_low++;
    }
    else if((g_Control.Vdc > VOLTAGE_WARN_LOW) && (alarm.voltage_low > 0)){
        alarm.voltage_low--;
    }
    if(alarm.voltage_low >= 20000*2){
        error_state_code_0101 |= _PORT_SET_BIT4;
        alarm.voltage_low = 20000*2;
	    De_Mos();
        g_Control.iRunState = 404;
    }


    //母线过压保护
    if(g_Control.ControlBoardPowerDC >g_Control.prot.VoltLevel1||g_Control.Vdc>g_Control.prot.VoltLevel1){    
        error_state_code_0101 |= _PORT_SET_BIT5;
	    De_Mos();
        g_Control.iRunState = 404;
    }


    //角度零位未标定 封管
    if((g_Control.Aligmenta.Ali_angle == 0xffffffff / 1000) || (g_Control.Aligmenta.Ali_angle == 0)){
        error_state_code_0101 |= _PORT_SET_BIT6;
        De_Mos();
        g_Control.iRunState = 404;
    }


    // 过温保护（在转速环和电流环之间）
    if(High_temperature==1){
        error_state_code_0101 |= _PORT_SET_BIT7;  // 设置过温报警标志
	    alarm.temp_High++;
    }
    //过温故障处理
    if(alarm.temp_High >= 2000){
        De_Mos();  // 断开MOS管
        g_Control.iRunState = 404;  // 设置运行状态为错误
        alarm.temp_High = 2000;
    }
    //过温标志位清除
    if((temperature < 85) && (((error_state_code_0101>>7) & 0x01) == 1) && (alarm_recover.temp_norm < 2000)){
        alarm_recover.temp_norm++;
    }
    else if(alarm_recover.temp_norm == 2000){
        High_temperature = 0;
        error_state_code_0101 &= _PORT_CLEAR_BIT7;
        alarm_recover.temp_norm = 2000;
    }
    

    //控制器长期欠压
    if(g_Control.Vdc<8.5)	
        VolLowCount++;
    else if(g_Control.Vdc>8.5&&VolLowCount>0)
        VolLowCount--;
    if(VolLowCount>=20000*5){
        error_state_code_0101 |=_PORT_SET_BIT8;
        VolLowCount = 20000*5;
        De_Mos();
        g_Control.iRunState = 404;
    }


    //控制器长期过压
    if(g_Control.Vdc>18)
        VolHighCount++;
    else if(g_Control.Vdc<18&&VolHighCount>0)
        VolHighCount--;
    if(VolHighCount>=20000*5){   //持续5s设立故障码
        error_state_code_0101 |=_PORT_SET_BIT9;
        VolHighCount = 20000*5;
        De_Mos();
        g_Control.iRunState = 404;
    }


    //超速保护
    if((ABS(g_Control.m_speed.Speed) > SPEED_WARN) && alarm.spd_outrange < 200){
        alarm.spd_outrange++;
    }else if(alarm.spd_outrange >= 200){
        error_state_code_0101 |= _PORT_SET_BIT10;
        De_Mos();
        g_Control.iRunState = 404; 
        alarm.spd_outrange = 200;
    }  


    //超差保护	
    if(outrangecount>20000*5){
        error_state_code_0101 |= (0x0800);
        //De_Mos();
       // g_Control.iRunState = 404;
    }else if((outrangecount == 0) && (((error_state_code_0101 >> 11) & 0x01) == 1)){
        error_state_code_0101 &= _PORT_CLEAR_BIT11;
    }


    //TAS传感器断线,设立标志位
    if(ABS(g_Control.m_speed.Speed) <= 1200){
        if(((Over_Time_TAS >> 2) == 1) && ((Over_Time_TAS >> 3) == 1) ){  // 检查P和S信号的超时标志
            error_state_code_0101 |= _PORT_SET_BIT12;
        }
        //故障处理
        if((((error_state_code_0101 >> 12) & 0x01) == 1) && (alarm.TAS_break < 1000)){
            alarm.TAS_break++;
            angle_out = Angle_last;     //维持原数据
            g_Control.TAS.TAS_angle = angle_out - g_Control.TAS.TAS_angle_comp;
        }else if(alarm.TAS_break >= 1000){
            alarm.TAS_break = 1000;
            De_Mos();
            g_Control.iRunState = 404;
        }
    }
    //故障标志位消除
    if((((error_state_code_0101 >> 12) & 0x01) == 1) && (alarm.TAS_break > 0) &&
       (((Over_Time_TAS >>2) == 0) || ((Over_Time_TAS >>3) == 0))){
        alarm.TAS_break--;
    }else if((alarm.TAS_break == 0) && (((error_state_code_0101 >> 12) & 0x01) == 1)){
        error_state_code_0101 &= _PORT_CLEAR_BIT12;
    }
  

    //先报错后处理故障
    //TAS传感器异常（包括P、S信号占空比异常以及数据异常波动）
    if(ABS(g_Control.m_speed.Speed) <= 1200){
        if(((TAS_Err_Flag == 1) || ((duty_range_error >> 2) == 1) || ((duty_range_error >> 3) == 1)) && ((alarm.TAS_signal_abnormal < 1000))){
            alarm.TAS_signal_abnormal++;
            angle_out = Angle_last;     //维持原数据
            g_Control.TAS.TAS_angle = angle_out - g_Control.TAS.TAS_angle_comp;
        }else if(alarm.TAS_signal_abnormal >= 1000){
            alarm.TAS_signal_abnormal = 1000;    
	    error_state_code_0101 |= _PORT_SET_BIT13;
        }
    }
    //故障信号清除
    if((((error_state_code_0101 >> 13) & 0x01) == 1) && (alarm.TAS_signal_abnormal > 0) && 
    (TAS_Err_Flag == 0) && (duty_range_error == 0)){
        alarm.TAS_signal_abnormal--;
    }else if(alarm.TAS_signal_abnormal == 0){
        error_state_code_0101 &= _PORT_CLEAR_BIT13;
    }    
	

    //温度检测信号无效
    if((Gu1ReadAdcValue[12] > 3800) && (alarm.ADC12_outrange < 2000)){
        alarm.ADC12_outrange++;
    }
    else if((Gu1ReadAdcValue[12] <= 3800) && (alarm.ADC12_outrange > 0)){
        alarm.ADC12_outrange--;
    }
    if(alarm.ADC12_outrange > 2000){
        error_state_code_0101 |= _PORT_SET_BIT14;
        alarm.ADC12_outrange = 2000;
        De_Mos();
        g_Control.iRunState = 404;
    }

}

//初始定位检查
int AliCheck(double angle,double Aliangle)
{
    double error = Aliangle - angle;
    
    if(error<0)
        error = -error;
    if(error>PI)
        error = 2*PI - error;
	
    if(error>=0.5)
        return 0;  //偏差过大，定位有问题
    else
        return 1;  //定位正常
}

#pragma interrupt INTGTM_TIM1_1(enable=0, channel=145, fpu=1, callt=0)
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

#pragma interrupt r_csih0_interrupt_receive(enable=0, channel=91, fpu=1, callt=0)
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
    
    if(flagxb==0){
        angle_pre=agl1;
	flagxb=1;
    }
    
   
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