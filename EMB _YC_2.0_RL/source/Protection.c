#include "Protection.h"
#include "gtm.h"
#include "iodefine.h"
#include "global_struct.h"
#include "parameter.h"
#include "global.h"
#include "tmr_macrodriver.h"
#include "r_adc.h"


unsigned int outrangecount=0;
unsigned int error_state_code_0101=0;
extern uint16_t High_temperature;
extern uint16_t Low_temperature ;
extern int temperature ;
extern uint32_t force_data ;
extern uint16_t Gu1ReadAdcValue[32];
extern volatile uint32_t SENT_err_flag;
extern  volatile uint32_t SENT_nocom_flag;
extern int contectFlag;

/****************************************
故障码列表
15      14       13     12     
    温度检测失效         
11      10       9       8      
超差    超速  控制器过压  控制器欠压
7        6          5       4
过温 接触点识别超时  过压    欠压
3                 2       1       0
压力传感器故障  压力超限   过流     定位错误
*******************************/
// 保护功能实现
void protection(void)
{
    static unsigned int VolLowCount;
    static unsigned int VolHighCount;
    
    // 电流保护滑动滤波
    Read_ADC_Current();

    //转速最大值
    if(g_Control.m_speed.Speed>g_Control.m_speed.SpeedMax)
        g_Control.m_speed.SpeedMax=g_Control.m_speed.Speed;
    else if(g_Control.m_speed.Speed<-g_Control.m_speed.SpeedMax)
	    g_Control.m_speed.SpeedMax=-g_Control.m_speed.Speed;
	
    // 计算电流的绝对值
    g_Control.r_Current.I_A = ABS(g_Control.m_Current.cur_A);
    g_Control.r_Current.I_B = ABS(g_Control.m_Current.cur_B);
    g_Control.r_Current.I_C = ABS(g_Control.m_Current.cur_C);

    // 获取最大电流值
    g_Control.r_Current.I_Max = MAX_THREE(g_Control.r_Current.I_A, g_Control.r_Current.I_B, g_Control.r_Current.I_C);
    
    // 更新电流历史最大值
    g_Control.r_Current.I_Max_Keep = MAX(g_Control.r_Current.I_Max_Keep, g_Control.r_Current.I_Max);

    // 初始化Vdc最小值（如果Vdcmin为0）
    if (g_Control.Vdcmin == 0)
        g_Control.Vdcmin = g_Control.Vdc;
    
    // 更新电压的历史最大值与最小值
    g_Control.Vdcmax = MAX(g_Control.Vdcmax, g_Control.Vdc);
    g_Control.Vdcmin = MIN(g_Control.Vdcmin, g_Control.Vdc);

    // 超差保护计数（基于速度误差）
    if (ABS(pi_spd.up) > 10)
        outrangecount++;
    else if (ABS(pi_spd.up) < 10 && outrangecount > 0)
        outrangecount--;
    else
        outrangecount = 0;

    // 电流保护三级计数
    // 1级电流报警
    if (g_Control.r_Current.I_Max > CURRENT_WARN_LEVEL1)    
        alarm.current_level1++;
    else if (alarm.current_level1>0&&
	    (g_Control.r_Current.I_Max < CURRENT_WARN_LEVEL1))
        alarm.current_level1--;
    else
        alarm.current_level1 = 0;
    // 2级电流报警
    if (g_Control.r_Current.I_Max > CURRENT_WARN_LEVEL2)    
        alarm.current_level2++;
    else if (alarm.current_level2>0&&
	     (g_Control.r_Current.I_Max < CURRENT_WARN_LEVEL2))
        alarm.current_level2--;
    else
        alarm.current_level2 = 0;
    // 3级电流报警
    if (g_Control.r_Current.I_Max > CURRENT_WARN_LEVEL3)    
        alarm.current_level3++;
    else if (alarm.current_level3>0&&
	     (g_Control.r_Current.I_Max < CURRENT_WARN_LEVEL3))
        alarm.current_level3--;
    else
        alarm.current_level3 = 0;
    
    // 过流保故障设立
    if (alarm.current_level1 > 20) {    
        error_state_code_0101 |= _PORT_SET_BIT1;  // 设置电流报警标志
        alarm.current_errcount++;
        De_Mos();  // 断开MOS管
        alarm.current_level1 = 20;  //防止溢出
    }
    if (alarm.current_level2 > 10) {    
        error_state_code_0101 |= _PORT_SET_BIT1;  // 设置电流报警标志
        alarm.current_errcount++;
        De_Mos();  // 断开MOS管
        alarm.current_level2 = 10;
    }
    if (alarm.current_level3 > 1) {    
        error_state_code_0101 |= _PORT_SET_BIT1;  // 设置电流报警标志
        alarm.current_errcount++;
        De_Mos();  // 断开MOS管
        alarm.current_level3 = 1;
    }
    // 过流故障限时恢复，夹紧力指令为0且故障未超过限定次数
//    if((error_state_code_0101>>1)&0x01 == 1 && (lsw == 3 && g_Control.target_pressure <= 0.2f) 
//    						&& alarm.current_errcount <= CURRENT_ERR_limit){
//        error_state_code_0101 &= _PORT_CLEAR_BIT1;
//        g_Control.iRunState = 100;
//        alarm.current_level1 = 0;
//        alarm.current_level2 = 0;
//        alarm.current_level3 = 0;
//    }
    
    // 压力超限保护
    if (force_data > FORCE_HIGH && alarm.force_outrange < FORCE_OUTLIMIT)    
        alarm.force_outrange++;
    else if (force_data < FORCE_HIGH && alarm.force_outrange > 0)
        alarm.force_outrange--;
    if(alarm.force_outrange > FORCE_OUTLIMIT){
        error_state_code_0101 |= _PORT_SET_BIT2;  // 设置压力过大报警标志
        De_Mos();                                 // 断开MOS管
        alarm.force_outrange = FORCE_OUTLIMIT;
    }
    // 压力超限故障恢复:夹紧力指令为0
//    if(((error_state_code_0101 >> 2) & 0x01) == 1 && (lsw == 3 && g_Control.target_pressure <= 0.2f)){
//        error_state_code_0101 &= _PORT_CLEAR_BIT2;
//        On_Mos();
//        g_Control.iRunState = 100;
//        alarm.force_outrange = 0;
//    }

    //压力传感器故障设立：接收不到数据（可能断线）/反馈数据错乱/数据异常偏低
    if(SENT_nocom_flag == 1 || SENT_err_flag == 1 || (SENT_err_flag == 2 && g_Control.target_pressure > 0.2f)){
        error_state_code_0101 |= _PORT_SET_BIT3;  // 设置压力过大报警标志
        De_Mos();                                 // 断开MOS管
    }
    // 压力传感器故障恢复
//    if(SENT_nocom_flag == 0 && (SENT_err_flag == 0 ||  (SENT_err_flag == 2 && g_Control.target_pressure <= 0.2f)) 
//        && (((error_state_code_0101 >> 3) &0x01) == 1)){
//            error_state_code_0101 &= _PORT_CLEAR_BIT3;
//            On_Mos();
//            g_Control.iRunState = 100;
//    }
    
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
    }
    //母线欠压故障恢复
//    if(g_Control.Vdc > VOLTAGE_WARN_LOW && ((error_state_code_0101 >> 4) & 0x01) == 1 
//        && alarm.voltage_low < 20000*2)
//        alarm.voltlow_recovery++;
//    else if(alarm.voltlow_recovery >= 20000*2){
//        error_state_code_0101 &= _PORT_CLEAR_BIT4;
//        On_Mos();
//        g_Control.iRunState = 100;
//        alarm.voltlow_recovery = 0;
//        alarm.voltage_low = 0;
//    }


    //母线过压保护
    if (g_Control.ControlBoardPowerDC > VOLTAGE_WARN_LEVEL1 || g_Control.Vdc > VOLTAGE_WARN_LEVEL2) {    
        error_state_code_0101 |= _PORT_SET_BIT5;  // 设置过压报警标志
        De_Mos();  // 断开MOS管
    }
    //母线过压故障恢复
//    if(g_Control.ControlBoardPowerDC <= VOLTAGE_WARN_LEVEL1 && g_Control.Vdc <=  VOLTAGE_WARN_LEVEL2 
//        && ((error_state_code_0101 >> 4) & 0x01) == 1 && alarm.boardvolt_high_recovery < 20000*2)
//        alarm.boardvolt_high_recovery++;
//    else if(alarm.boardvolt_high_recovery >= 20000*2){
//        error_state_code_0101 &= _PORT_CLEAR_BIT5;
//        On_Mos();
//        g_Control.iRunState = 100;
//        alarm.boardvolt_high_recovery = 0;
//    }

    //接触点识别超时故障设立
    if(contectFlag == 2)
        error_state_code_0101 |= _PORT_SET_BIT6;
    //接触点识别故障恢复
    if(contectFlag != 2 && ((error_state_code_0101 >> 6) & 0x01) == 1)
        error_state_code_0101 &= _PORT_CLEAR_BIT6;
    
    // 过温保护（在转速环和电流环之间）
    if(High_temperature == 1){
        error_state_code_0101 |= _PORT_SET_BIT7;  // 设置过温报警标志
        De_Mos();  // 断开MOS管
    }
    //过温故障处理
//    if(temperature <= 80 && ((error_state_code_0101 >> 7) & 0x01) == 1 && alarm.temp_High_recovery <= 20000*3)
//        alarm.temp_High_recovery++;
//    else if(alarm.temp_High_recovery >= 20000*3){
//        error_state_code_0101 &= _PORT_CLEAR_BIT7;
//        On_Mos();
//        g_Control.iRunState = 100;
//        alarm.temp_High_recovery = 0;
//    }

    //控制器长期欠压
    if(g_Control.Vdc < 8.5)	
        VolLowCount++;
    else if(g_Control.Vdc > 8.5 && VolLowCount > 0)
        VolLowCount--;
    if(VolLowCount >= 20000*5){
        error_state_code_0101 |=_PORT_SET_BIT8;
        VolLowCount = 20000*5;
        De_Mos();
    }
    //控制器长期欠压恢复
//    if(g_Control.Vdc >= 8.5 && ((error_state_code_0101 >> 8) & 0x01) == 1 && alarm.voltlow_recovery2 < 20000*5)
//        alarm.voltlow_recovery2++;
//    else if(alarm.voltlow_recovery2 >= 20000*5){
//        error_state_code_0101 &= _PORT_CLEAR_BIT8;
//        On_Mos();
//        g_Control.iRunState = 100;
//        alarm.voltlow_recovery2 = 0;
//        VolLowCount = 0;
//    }

    //控制器长期过压
    if(g_Control.Vdc > 18)
        VolHighCount++;
    else if(g_Control.Vdc < 18 && VolHighCount > 0)
        VolHighCount--;
    if(VolHighCount >= 20000*5){   //持续5s设立故障码
        error_state_code_0101 |=_PORT_SET_BIT9;
        VolHighCount = 20000*5;
        De_Mos();
    }
    //控制器长期过压恢复
//    if(g_Control.Vdc < 18 && ((error_state_code_0101 >> 9) & 0x01) == 1 && alarm.boardvolt_high_recovery2 < 20000*5)
//        alarm.boardvolt_high_recovery2++;
//    else if(alarm.boardvolt_high_recovery2 >= 20000*5){
//        error_state_code_0101 &= _PORT_CLEAR_BIT9;
//        On_Mos();
//        g_Control.iRunState = 100;
//        alarm.boardvolt_high_recovery2 = 0;
//        VolHighCount = 0;
//    }

    //超速保护
    if((ABS(g_Control.m_speed.Speed) > SPEED_WARN) && alarm.spd_outrange < 200){
        alarm.spd_outrange++;
    }else if(alarm.spd_outrange >= 200){
        error_state_code_0101 |= _PORT_SET_BIT10;
        De_Mos();
        alarm.spd_outrange = 200;
    }  

    // 超差保护
    if (outrangecount > 20000 *1) {
        // 超过计数阈值时执行保护逻辑
        //error_state_code_0101 |= (0x0800);  // 可以添加更多报警标志
        //De_Mos();  // 断开MOS管
	    //P2 |= _PORT_SET_BIT11;     //turn on
    }     
    
        //P2 |= _PORT_SET_BIT11;     //turn on
        //if(error_state_code_0101==0)
        //P2 &= _PORT_CLEAR_BIT11;   //turn off	
    
    // 低温保护
    if(Low_temperature == 1){
        error_state_code_0101 |= _PORT_SET_BIT12;  // 设置过温报警标志
    }
    // 低温故障清除
    if(temperature >= -40 && ((error_state_code_0101 >> 12) & 0x01) == 1 && alarm.temp_low_recovery <= 20000*3)
        alarm.temp_low_recovery++;
    else if(alarm.temp_low_recovery >= 20000*3){
        error_state_code_0101 &= _PORT_CLEAR_BIT12;
        alarm.temp_low_recovery = 0;
    }
    
    //温度检测信号无效
    if((Gu1ReadAdcValue[12] > 3800) && (alarm.ADC12_outrange < 200)){
        alarm.ADC12_outrange++;
    }
    else if((Gu1ReadAdcValue[12] <= 3800) && (alarm.ADC12_outrange > 0)){
        alarm.ADC12_outrange--;
    }
    if(alarm.ADC12_outrange > 200){
        error_state_code_0101 |= _PORT_SET_BIT14;
        alarm.ADC12_outrange = 200;
        De_Mos();
    }
    //温度检测故障恢复
    if((Gu1ReadAdcValue[12] <= 3800) && (alarm.ADC12_recovery < 200) && ((error_state_code_0101 >> 14) & 0x01) == 1)
        alarm.ADC12_recovery++;
    else if(alarm.ADC12_recovery >= 200){
        error_state_code_0101 &= _PORT_CLEAR_BIT14;
        On_Mos();
        g_Control.iRunState = 100;
        alarm.ADC12_recovery = 0;
        alarm.ADC12_outrange = 0;
    }
}

// 泄放功能实现
void Discharge()
{
    // 如果母线电压大于泄放阈值，设置端口P2的第10位为高电平，启动泄放
    if (g_Control.Vdc > LEAK_H)
    {
        P2 |= _PORT_SET_BIT10;  // 设置P2的第10位为1，表示启用泄放功能
    }
    
    // 如果母线电压小于泄放的最低阈值，清除端口P2的第10位，停止泄放
    if (g_Control.Vdc < LEAK_L)
    {
        P2 &= _PORT_CLEAR_BIT10;  // 清除P2的第10位为0，表示停止泄放功能
    }
}
