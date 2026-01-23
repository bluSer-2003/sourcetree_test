#include "global_struct.h"

// ?????????????????
ControlManage_t g_Control;
SpeedCal Speed1;
Aligment_d Aligment;
alarmcount alarm;
alarmrecovercount alarm_recover;
FLAG flag;
CANflash g_CANflash;
exCAN_MSG exmsg;
JWDcan CAN2;
PosInterpolation_t g_PosInterp = POS_INTERPOLATION_DEFAULTS;  // 位置插补全局变量初始化
// Instance PI regulators to regulate the d and q  axis currents, and speed
PI_CONTROLLER pi_pos = PI_CONTROLLER_DEFAULTS;
PI_CONTROLLER pi_fw  = PI_CONTROLLER_DEFAULTS;
PI_CONTROLLER pi_spd = PI_CONTROLLER_DEFAULTS;
PI_CONTROLLER pi_id  = PI_CONTROLLER_DEFAULTS;
PI_CONTROLLER pi_iq  = PI_CONTROLLER_DEFAULTS;
// ??????o????y?D3??????????????????
void initGlobalVariables() {
    // 3??????? g_Control_t
    g_Control.iRunState = 0;
    g_Control.ControlBoardPowerDC = 0.0f;
    g_Control.Vdc = 0.0f;
    g_Control.Vdcmax = 0.0f;
    g_Control.Vdcmin = 0.0f;

    // 3??????? Aligmenta
    g_Control.Aligmenta.Ali_count = 0;
    g_Control.Aligmenta.Ali_angle = 0.0f;
    g_Control.Aligmenta.Id_count = 0;
    g_Control.Aligmenta.Id_Cal = 0.0f;
    g_Control.Aligmenta.Id_Ref = 0.0f;
    
    // 3??????? m_Current
    g_Control.m_Current.cur_A = 0.0f;
    g_Control.m_Current.cur_B = 0.0f;
    g_Control.m_Current.cur_C = 0.0f;

    // 3??????? FW
    g_Control.FW.Flag = 0;
    g_Control.FW.Speedmax = 0.0f;
    g_Control.FW.Speedmin = 0.0f;
    g_Control.FW.Speed = 0.0f;
    g_Control.FW.Vdcfbk = 0.0f;
    g_Control.FW.Vdcfbkfli = 0.0f;
    
    // 3??????? r_Current
    g_Control.r_Current.I_A = 0.0f;
    g_Control.r_Current.I_B = 0.0f;
    g_Control.r_Current.I_C = 0.0f;
    g_Control.r_Current.I_Max = 0.0f;
    g_Control.r_Current.I_Max_Keep = 0.0f;

    // 3??????? count
    g_Control.count.SpeedLoopCount = 0;
    g_Control.count.FWLoopCount = 0;
    g_Control.count.PosLoopCount = 0;
    g_Control.count.SatCount = 0;

    // 3??????? m_speed
    g_Control.m_speed.oldtime_angle_e = 0.0;
    g_Control.m_speed.newtime_angle_e = 0.0;
    g_Control.m_speed.differ_angle_e = 0.0;
    g_Control.m_speed.differ_angle_e_pre = 0.0;
    g_Control.m_speed.Speed = 0.0f;
    g_Control.m_speed.SpeedPre = 0.0f;
    g_Control.m_speed.Speed_ctl = 0.0f;
    g_Control.m_speed.SpeedMax = 0.0f;
    g_Control.m_speed.Speed_ref = 0.0f;
    
    // 3??????? pos
    g_Control.pos.PosOld = 0.0f;
    g_Control.pos.PosNew = 0.0f;
    g_Control.pos.PosDif = 0.0f;
    g_Control.pos.PosSum = 0.0f;
    
    g_Control.angle_e = 0.0;
    g_Control.Dutycycle_A = 0.0f;
    g_Control.Dutycycle_B = 0.0f;
    g_Control.Dutycycle_C = 0.0f;
    g_Control.IqRef = 0.0f;
    g_Control.IdRef = 0.0f;
    g_Control.IqFbk = 0.0f;
    g_Control.IdFbk = 0.0f;
    g_Control.SpdRef = 0.0f;
    g_Control.SpdFbk = 0.0f;
    g_Control.PosRef = 0.0f;
    g_Control.PosFbk = 0.0f;

    // 3??????? SpeedCal
    Speed1.dif_angle = 0.0f;
    Speed1.angle_now = 0.0f;
    Speed1.angle_pre = 0.0f;
    Speed1.realspeed = 0.0f;
    Speed1.dif_angle_pre = 0.0f;

    // 3??????? Aligment_d
    Aligment.anglepre = 0.0;
    Aligment.angle = 0.0;
    Aligment.Id_Ref = 0.0f;
    Aligment.Duty = 0.0f;
    Aligment.Flag = 0;
    Aligment.count = 0;

    // 3??????? alarmCount
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
    alarm_recover.speed_norm = 0;
    alarm_recover.posRef_norm = 0;
    flag.AliCheck = 0;
}

// ????????????????????????