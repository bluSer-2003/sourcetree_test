#include "global_struct.h"
#include "canfd.h"
#include "parameter.h"
#include "global_struct.h"
#include "gtm.h"
#include "global.h"

extern unsigned int error_state_code_0101;
extern uint32_t force_data;
extern float temperature ;
extern uint8 rollcnt;
extern int canmissTimer;

//反馈参数更新
void UpdateFbkPara()
{
    //if(FB_Order_Flag){
        FB_Inqury.curIa = clarke1.As;
        FB_Inqury.curIb = clarke1.Bs;
        FB_Inqury.curIc = clarke1.Cs;
        FB_Inqury.curId = pi_id.Fbk*CURRENT_PU_RE;
        FB_Inqury.curIq = pi_iq.Fbk*CURRENT_PU_RE; 
        FB_Inqury.curIdRef = g_Control.IdRef*CURRENT_PU_RE;
        FB_Inqury.curIqRef = g_Control.IqRef*CURRENT_PU_RE;
        FB_Inqury.spd = g_Control.m_speed.Speed;
        FB_Inqury.spdRef = g_Control.SpdRef * SPEED_PU_RE;
        FB_Inqury.pre  = (float)force_data * 0.001;          //EMB pressure
        FB_Inqury.preRef = g_Control.target_pressure;
        FB_Inqury.pos = pi_pos.Fbk/20;
        FB_Inqury.posRef = pi_pos.Ref/20;//g_Control.PosRef/20;
        FB_Inqury.errCode = error_state_code_0101;
        FB_Inqury.temp1 = temperature;
	    FB_Inqury.vol = g_Control.Vdc; // ????
        //FB_Inqury.temp2
        //FB_Inqury.version
    
        //FB_Order_Flag = 0;
        //FB_Complete_Flag = 1;
    //}
}

//更新调节器参数
void UpdateRegulatorParam(void)
{
    //CAN给定赋值给控制参数
    if(Regulator_Order_Flag==1 && g_Control.iRunState==4444){
        if(Regulator_Order.regFlag&0x0001)
            pi_pos.Kp = Regulator_Order.posKp;
        if(Regulator_Order.regFlag&0x0002)
            pi_pos.Ki = Regulator_Order.posKi;
        if(Regulator_Order.regFlag&0x0004)
            pi_spd.Kp = Regulator_Order.spdKp;
        if(Regulator_Order.regFlag&0x0008)
            pi_spd.Ki = Regulator_Order.spdKi;
        if(Regulator_Order.regFlag&0x0010){
            pi_iq.Kp = Regulator_Order.curKp;
    	    pi_id.Kp = Regulator_Order.curKp;
        }
        if(Regulator_Order.regFlag&0x0020){
            pi_iq.Ki = Regulator_Order.curKi;
	    pi_id.Ki = Regulator_Order.curKi;
        }
        if(Regulator_Order.regFlag&0x0040)
            pi_fw.Kp = Regulator_Order.fwKp;
        if(Regulator_Order.regFlag&0x0080)
            pi_fw.Ki = Regulator_Order.fwKi;
	    //if(Regulator_Order.regFlag&&0x2000==1)
            //Regulator_Order.fwCurMax
        //if(Regulator_Order.regFlag&&0x2000==1)
            //Regulator_Order.interFreq

	//控制PI参数赋值给CAN结构体
        Regulator_Complete.posKp = pi_pos.Kp;
        Regulator_Complete.posKi = pi_pos.Ki;
        Regulator_Complete.spdKp = pi_spd.Kp;
        Regulator_Complete.spdKi = pi_spd.Ki;
        Regulator_Complete.curKp = pi_iq.Kp;
        Regulator_Complete.curKi = pi_iq.Ki;
        Regulator_Complete.fwKp = pi_fw.Kp;
        Regulator_Complete.fwKi  = pi_fw.Ki;
        Regulator_Order_Flag = 0;
        Regulator_Complete_Flag = 1;

        //if(Regulator_Order.regFlag&&0x2000==1)
            //Regulator_Order.interFreq;
	
    }
}
    


/*
//保护参数更新
void UpdateProctectParam(void)
{
	
    if(Protect_Order_Flag==1&&g_Control.iRunState==4444){
        if(Regulator_Order.protFlag&0x0001)
	    Regulator_Order.volProtOV;
	if(Regulator_Order.protFlag&0x0002)
	    Regulator_Order.volProtUV;
	if(Regulator_Order.protFlag&0x0003)
	    Regulator_Order.curProt;
	if(Regulator_Order.protFlag&0x0010)
	    Regulator_Order.spdProt;
	if(Regulator_Order.protFlag&0x0020)
	    Regulator_Order.curOpProt;
	if(Regulator_Order.protFlag&0x0040)
	    Regulator_Order.spdOpProt;
	if(Regulator_Order.protFlag&0x0100)
	    Regulator_Order.posOpProt;
	if(Regulator_Order.protFlag&0x0200)
	    Regulator_Order.powProt;
    }
    
    if(Protect_Order_Flag==1){
	Regulator_Order.volProtOV;
	Regulator_Order.volProtUV;
	Regulator_Order.curProt;
	Regulator_Order.spdProt;
	Regulator_Order.curOpProt;
	Regulator_Order.spdOpProt;
	Regulator_Order.posOpProt;
	Regulator_Order.powProt;
	Protect_Complete_Flag = 1;
    }
}
*/

//给定参数更新
void UpdateGivenParam(void){
    if(Given_Order_Flag == 1){
	
	if(Given_Order.givenFlag&0x0001)
            //g_Control.target_pressure = Given_Order.pre;	//夹紧力给定
	    
	if(Given_Order.givenFlag&0x0002)
            g_Control.PosRefStep = Given_Order.pos;		//位置圈数给定
    	if(Given_Order.givenFlag&0x0004){
            pi_pos.Umax = Given_Order.spdMax * SPEED_PU;
	    pi_pos.Umin = -pi_pos.Umax;
	}
	
	if(Given_Order.givenFlag&0x0008)
            g_Control.SpdRef = Given_Order.spd * SPEED_PU;	//转速给定
    	if(Given_Order.givenFlag&0x0010){
            pi_spd.Umax = Given_Order.curMax * CURRENT_PU;
	    pi_spd.Umin = -pi_spd.Umax;
	}
	
	if(Given_Order.givenFlag&0x0020)
            g_Control.IdRef = Given_Order.curId;		//d轴电流给定
	if(Given_Order.givenFlag&0x0040)
            g_Control.IqRef = Given_Order.curIq;		//q轴电流给定
    	if(Given_Order.givenFlag&0x0080)
            CANfd_Password = Given_Order.password;
	    
        //Given_Order.volDisUp;
        //Given_Order.volDisDown;
	Given_Order_Flag = 0;

	Given_Complete.pre = g_Control.target_pressure;
        Given_Complete.pos = g_Control.PosRefStep;
        Given_Complete.spd = g_Control.SpdRef * SPEED_PU_RE;//*3300/20;
        Given_Complete.spdMax = pi_pos.Umax * SPEED_PU_RE;
	Given_Complete.curMax = pi_spd.Umax * CURRENT_PU_RE;
        Given_Complete.curIq = g_Control.IqRef;
	Given_Complete.curId = g_Control.IdRef;
        Given_Complete.password = CANfd_Password;
	//Given_Complete.volDisUp;
        //Given_Complete.volDisDown;	
        Given_Complete_Flag = 1;


    }
  
}


void UpdateParam_fromBCU(void) 
{
    #if(EMBActuator == FLEMB)
        if(canmissTimer > 10000)
	{
		fromBCU_YC_FL.BrkForceCmd = 0;
	}
        fromBCU_YC_FL.BrkForceCmd = BCU_M_CAN1_FrP1.BrkForceCmd_FL * 10;    //N
	g_Control.target_pressure = (float)fromBCU_YC_FL.BrkForceCmd*0.001; 
    fromBCU_YC_FL.BrkForceCmdGrdMaxLmtA = BCU_M_CAN1_FrP1.BrkForceCmdGrdMaxLmtA_FL;
    fromBCU_YC_FL.BrkForceCmdGrdMinLmtA = BCU_M_CAN1_FrP1.BrkForceCmdGrdMinLmtA_FL;
    fromBCU_YC_FL.BrkForceCmdGrdLmt = BCU_M_CAN1_FrP1.BrkForceCmdGrdLmt_FL;
    fromBCU_YC_FL.BrkForceRelPosReq = BCU_M_CAN1_FrP1.BrkForceRelPosReq_FL;
    fromBCU_YC_FL.BrkForceDiffAllow = BCU_M_CAN1_FrP1.BrkForceDiffAllow_FL;
    fromBCU_YC_FL.ABSActive = BCU_M_CAN1_FrP1.ABSActive_FL;
    fromBCU_YC_FL.ParkRequest = BCU_M_CAN1_FrP1.ParkRequest_FL;
    BCU_M_CAN1_FrP1.BrkForceCmdActive_FL = 0;
    #endif
    #if(EMBActuator == FREMB)
        if(canmissTimer > 10000)
	{
		fromBCU_YC_FR.BrkForceCmd = 0;
	}
        fromBCU_YC_FR.BrkForceCmd = BCU_M_CAN1_FrP1.BrkForceCmd_FR * 10;    //N
	g_Control.target_pressure = (float)fromBCU_YC_FR.BrkForceCmd*0.001; 
    fromBCU_YC_FR.BrkForceCmdGrdMaxLmtA = BCU_M_CAN1_FrP1.BrkForceCmdGrdMaxLmtA_FR;
    fromBCU_YC_FR.BrkForceCmdGrdMinLmtA = BCU_M_CAN1_FrP1.BrkForceCmdGrdMinLmtA_FR;
    fromBCU_YC_FR.BrkForceCmdGrdLmt = BCU_M_CAN1_FrP1.BrkForceCmdGrdLmt_FR;
    fromBCU_YC_FR.BrkForceRelPosReq = BCU_M_CAN1_FrP1.BrkForceRelPosReq_FR;
    fromBCU_YC_FR.BrkForceDiffAllow = BCU_M_CAN1_FrP1.BrkForceDiffAllow_FR;
    fromBCU_YC_FR.ABSActive = BCU_M_CAN1_FrP1.ABSActive_FR;
    fromBCU_YC_FR.ParkRequest = BCU_M_CAN1_FrP1.ParkRequest_FR;
    BCU_M_CAN1_FrP1.BrkForceCmdActive_FR = 0;
    #endif
    #if(EMBActuator == RLEMB)
        if(canmissTimer > 10000)
	{
		fromBCU_YC_RL.BrkForceCmd = 0;
	}
        fromBCU_YC_RL.BrkForceCmd = BCU_M_CAN1_FrP1.BrkForceCmd_RL * 10;    //N
	g_Control.target_pressure = (float)fromBCU_YC_RL.BrkForceCmd*0.001; 
    fromBCU_YC_RL.BrkForceCmdGrdMaxLmtA = BCU_M_CAN1_FrP1.BrkForceCmdGrdMaxLmtA_RL;
    fromBCU_YC_RL.BrkForceCmdGrdMinLmtA = BCU_M_CAN1_FrP1.BrkForceCmdGrdMinLmtA_RL;
    fromBCU_YC_RL.BrkForceCmdGrdLmt = BCU_M_CAN1_FrP1.BrkForceCmdGrdLmt_RL;
    fromBCU_YC_RL.BrkForceRelPosReq = BCU_M_CAN1_FrP1.BrkForceRelPosReq_RL;
    fromBCU_YC_RL.BrkForceDiffAllow = BCU_M_CAN1_FrP1.BrkForceDiffAllow_RL;
    fromBCU_YC_RL.ABSActive = BCU_M_CAN1_FrP1.ABSActive_RL;
    fromBCU_YC_RL.ParkRequest = BCU_M_CAN1_FrP1.ParkRequest_RL;
    BCU_M_CAN1_FrP1.BrkForceCmdActive_RL = 0;
    #endif
    #if(EMBActuator == RREMB)
        if(canmissTimer > 10000)
	{
		fromBCU_YC_RR.BrkForceCmd = 0;
	}
        fromBCU_YC_RR.BrkForceCmd = BCU_M_CAN1_FrP1.BrkForceCmd_RR * 10;    //N
	g_Control.target_pressure = (float)fromBCU_YC_RR.BrkForceCmd*0.001; 
    fromBCU_YC_RR.BrkForceCmdGrdMaxLmtA = BCU_M_CAN1_FrP1.BrkForceCmdGrdMaxLmtA_RR;
    fromBCU_YC_RR.BrkForceCmdGrdMinLmtA = BCU_M_CAN1_FrP1.BrkForceCmdGrdMinLmtA_RR;
    fromBCU_YC_RR.BrkForceCmdGrdLmt = BCU_M_CAN1_FrP1.BrkForceCmdGrdLmt_RR;
    fromBCU_YC_RR.BrkForceRelPosReq = BCU_M_CAN1_FrP1.BrkForceRelPosReq_RR;
    fromBCU_YC_RR.BrkForceDiffAllow = BCU_M_CAN1_FrP1.BrkForceDiffAllow_RR;
    fromBCU_YC_RR.ABSActive = BCU_M_CAN1_FrP1.ABSActive_RR;
    fromBCU_YC_RR.ParkRequest = BCU_M_CAN1_FrP1.ParkRequest_RR;
    BCU_M_CAN1_FrP1.BrkForceCmdActive_RR = 0;
    #endif
    
//    if(fromBCU_YC_FL.BrkForceCmd > g_Control.target_pressure || fromBCU_YC_FL.BrkForceCmd == 0)
//    {
//	    g_Control.target_pressure = (float)fromBCU_YC_FL.BrkForceCmd*0.001;    
//    }


}

//英创项目外发给整车参数更新
void UpdateParam_toBCU(void)
{
#if(EMBActuator == FLEMB)
    BWC_FL_CAN1_FrP1.BrkForceVld = 1;                                            //与压力传感器对应，暂时恒定给有效
    BWC_FL_CAN1_FrP1.BrkForceActive = BCU_M_CAN1_FrP1.BrkForceCmdActive_FL;      //与电机实际动作相关，暂时直接与给定关联
    BWC_FL_CAN1_FrP1.BrkForceActual = (float)(0.1 * force_data);                //N→kN，0.01的分辨率
    BWC_FL_CAN1_FrP1.BrkForceLmt = 2 * 15;                                       //kN，0.5的分辨率
    BWC_FL_CAN1_FrP1.BrkForceGrdActive = 0;                                      //变化率响应激活，暂时反馈0
    BWC_FL_CAN1_FrP1.BrkForceGrdLmtMax = 0;                                      //变化率最大值，暂时反馈0
    BWC_FL_CAN1_FrP1.BrkForceGrdLmtMin = 0;                                      //变化率最小值，暂时反馈0
    BWC_FL_CAN1_FrP1.BrkForceRelPos = 1;                                         //暂时先写回到初始位置
    BWC_FL_CAN1_FrP1.ParkBrkState = 2;                                           //驻车状态，现阶段不用，暂时发已释放
    BWC_FL_CAN1_FrP1.ServiceBrkFailState = 1;                                    //行车制动失效状态，与功能降级关联，暂时给normal
    BWC_FL_CAN1_FrP1.PrakBrkFailState = 0;                                       //驻车制动失效状态，驻车功能暂时不用，暂时给init
    BWC_FL_CAN1_FrP1.MotorControlState = 0;                                       //电机控制状态
    BWC_FL_CAN1_FrP1.ParkValveControlState = 0;                                  //驻车电磁阀状态，无
    BWC_FL_CAN1_FrP1.WheelSpeed = 0;                                             //轮速，无
    BWC_FL_CAN1_FrP1.WheelSpeedDir = 0;                                          //轮速方向，无
    BWC_FL_CAN1_FrP1.WheelSpeedVld = 0;                                          //轮速有效性，无
    BWC_FL_CAN1_FrP1.WheelPulseCounter = 0;                                      //轮速脉冲，无
    BWC_FL_CAN1_FrP1.WheelPulseReset = 0;                                        //轮速脉冲异常重置，无
    BWC_FL_CAN1_FrP1.WheelTimestamp = 0;                                         //轮速时间戳，无
    BWC_FL_CAN1_FrP1.WheelTimestampRC = 0;                                       //轮速时间戳计数器，无
    BWC_FL_CAN1_FrP1.Comm_Avaliable_BCU_M = 1;                                   //与BCU_M通讯有效
    BWC_FL_CAN1_FrP1.Comm_Avaliable_BCU_R = 1;                                   //与BCU_R通讯有效
    BWC_FL_CAN1_FrP1.AliveRollingCount = rollcnt;                                       //心跳信号
    BWC_FL_CAN1_FrP1.Checksum = 0;                                               //CRC校验暂时先不发
#endif
#if(EMBActuator == FREMB)
    BWC_FR_CAN1_FrP1.BrkForceVld = 1;                                            //与压力传感器对应，暂时恒定给有效
    BWC_FR_CAN1_FrP1.BrkForceActive = BCU_M_CAN1_FrP1.BrkForceCmdActive_FR;      //与电机实际动作相关，暂时直接与给定关联
    BWC_FR_CAN1_FrP1.BrkForceActual = (float)(0.1 * force_data);                //N→kN，0.01的分辨率
    BWC_FR_CAN1_FrP1.BrkForceLmt = 2 * 15;                                       //kN，0.5的分辨率
    BWC_FR_CAN1_FrP1.BrkForceGrdActive = 0;                                      //变化率响应激活，暂时反馈0
    BWC_FR_CAN1_FrP1.BrkForceGrdLmtMax = 0;                                      //变化率最大值，暂时反馈0
    BWC_FR_CAN1_FrP1.BrkForceGrdLmtMin = 0;                                      //变化率最小值，暂时反馈0
    BWC_FR_CAN1_FrP1.BrkForceRelPos = 1;                                         //暂时先写回到初始位置
    BWC_FR_CAN1_FrP1.ParkBrkState = 2;                                           //驻车状态，现阶段不用，暂时发已释放
    BWC_FR_CAN1_FrP1.ServiceBrkFailState = 1;                                    //行车制动失效状态，与功能降级关联，暂时给normal
    BWC_FR_CAN1_FrP1.PrakBrkFailState = 0;                                       //驻车制动失效状态，驻车功能暂时不用，暂时给init
    BWC_FR_CAN1_FrP1.MotorControlState = 0;                                       //电机控制状态
    BWC_FR_CAN1_FrP1.ParkValveControlState = 0;                                  //驻车电磁阀状态，无
    BWC_FR_CAN1_FrP1.WheelSpeed = 0;                                             //轮速，无
    BWC_FR_CAN1_FrP1.WheelSpeedDir = 0;                                          //轮速方向，无
    BWC_FR_CAN1_FrP1.WheelSpeedVld = 0;                                          //轮速有效性，无
    BWC_FR_CAN1_FrP1.WheelPulseCounter = 0;                                      //轮速脉冲，无
    BWC_FR_CAN1_FrP1.WheelPulseReset = 0;                                        //轮速脉冲异常重置，无
    BWC_FR_CAN1_FrP1.WheelTimestamp = 0;                                         //轮速时间戳，无
    BWC_FR_CAN1_FrP1.WheelTimestampRC = 0;                                       //轮速时间戳计数器，无
    BWC_FR_CAN1_FrP1.Comm_Avaliable_BCU_M = 1;                                   //与BCU_M通讯有效
    BWC_FR_CAN1_FrP1.Comm_Avaliable_BCU_R = 1;                                   //与BCU_R通讯有效
    BWC_FR_CAN1_FrP1.AliveRollingCount = rollcnt;                                       //心跳信号
    BWC_FR_CAN1_FrP1.Checksum = 0;                                               //CRC校验暂时先不发
#endif
#if(EMBActuator == RLEMB)
    BWC_RL_CAN1_FrP1.BrkForceVld = 1;                                            //与压力传感器对应，暂时恒定给有效
    BWC_RL_CAN1_FrP1.BrkForceActive = BCU_M_CAN1_FrP1.BrkForceCmdActive_RL;      //与电机实际动作相关，暂时直接与给定关联
    BWC_RL_CAN1_FrP1.BrkForceActual = (float)(0.1 * force_data);                //N→kN，0.01的分辨率
    BWC_RL_CAN1_FrP1.BrkForceLmt = 2 * 15;                                       //kN，0.5的分辨率
    BWC_RL_CAN1_FrP1.BrkForceGrdActive = 0;                                      //变化率响应激活，暂时反馈0
    BWC_RL_CAN1_FrP1.BrkForceGrdLmtMax = 0;                                      //变化率最大值，暂时反馈0
    BWC_RL_CAN1_FrP1.BrkForceGrdLmtMin = 0;                                      //变化率最小值，暂时反馈0
    BWC_RL_CAN1_FrP1.BrkForceRelPos = 1;                                         //暂时先写回到初始位置
    BWC_RL_CAN1_FrP1.ParkBrkState = 2;                                           //驻车状态，现阶段不用，暂时发已释放
    BWC_RL_CAN1_FrP1.ServiceBrkFailState = 1;                                    //行车制动失效状态，与功能降级关联，暂时给normal
    BWC_RL_CAN1_FrP1.PrakBrkFailState = 0;                                       //驻车制动失效状态，驻车功能暂时不用，暂时给init
    BWC_RL_CAN1_FrP1.MotorControlState = 0;                                       //电机控制状态
    BWC_RL_CAN1_FrP1.ParkValveControlState = 0;                                  //驻车电磁阀状态，无
    BWC_RL_CAN1_FrP1.WheelSpeed = 0;                                             //轮速，无
    BWC_RL_CAN1_FrP1.WheelSpeedDir = 0;                                          //轮速方向，无
    BWC_RL_CAN1_FrP1.WheelSpeedVld = 0;                                          //轮速有效性，无
    BWC_RL_CAN1_FrP1.WheelPulseCounter = 0;                                      //轮速脉冲，无
    BWC_RL_CAN1_FrP1.WheelPulseReset = 0;                                        //轮速脉冲异常重置，无
    BWC_RL_CAN1_FrP1.WheelTimestamp = 0;                                         //轮速时间戳，无
    BWC_RL_CAN1_FrP1.WheelTimestampRC = 0;                                       //轮速时间戳计数器，无
    BWC_RL_CAN1_FrP1.Comm_Avaliable_BCU_M = 1;                                   //与BCU_M通讯有效
    BWC_RL_CAN1_FrP1.Comm_Avaliable_BCU_R = 1;                                   //与BCU_R通讯有效
    BWC_RL_CAN1_FrP1.AliveRollingCount = rollcnt;                                       //心跳信号
    BWC_RL_CAN1_FrP1.Checksum = 0;                                               //CRC校验暂时先不发
#endif
#if(EMBActuator == RREMB)
    BWC_RR_CAN1_FrP1.BrkForceVld = 1;                                            //与压力传感器对应，暂时恒定给有效
    BWC_RR_CAN1_FrP1.BrkForceActive = BCU_M_CAN1_FrP1.BrkForceCmdActive_RR;      //与电机实际动作相关，暂时直接与给定关联
    BWC_RR_CAN1_FrP1.BrkForceActual = (float)(0.1 * force_data);                //N→kN，0.01的分辨率
    BWC_RR_CAN1_FrP1.BrkForceLmt = 2 * 15;                                       //kN，0.5的分辨率
    BWC_RR_CAN1_FrP1.BrkForceGrdActive = 0;                                      //变化率响应激活，暂时反馈0
    BWC_RR_CAN1_FrP1.BrkForceGrdLmtMax = 0;                                      //变化率最大值，暂时反馈0
    BWC_RR_CAN1_FrP1.BrkForceGrdLmtMin = 0;                                      //变化率最小值，暂时反馈0
    BWC_RR_CAN1_FrP1.BrkForceRelPos = 1;                                         //暂时先写回到初始位置
    BWC_RR_CAN1_FrP1.ParkBrkState = 2;                                           //驻车状态，现阶段不用，暂时发已释放
    BWC_RR_CAN1_FrP1.ServiceBrkFailState = 1;                                    //行车制动失效状态，与功能降级关联，暂时给normal
    BWC_RR_CAN1_FrP1.PrakBrkFailState = 0;                                       //驻车制动失效状态，驻车功能暂时不用，暂时给init
    BWC_RR_CAN1_FrP1.MotorControlState = 0;                                       //电机控制状态
    BWC_RR_CAN1_FrP1.ParkValveControlState = 0;                                  //驻车电磁阀状态，无
    BWC_RR_CAN1_FrP1.WheelSpeed = 0;                                             //轮速，无
    BWC_RR_CAN1_FrP1.WheelSpeedDir = 0;                                          //轮速方向，无
    BWC_RR_CAN1_FrP1.WheelSpeedVld = 0;                                          //轮速有效性，无
    BWC_RR_CAN1_FrP1.WheelPulseCounter = 0;                                      //轮速脉冲，无
    BWC_RR_CAN1_FrP1.WheelPulseReset = 0;                                        //轮速脉冲异常重置，无
    BWC_RR_CAN1_FrP1.WheelTimestamp = 0;                                         //轮速时间戳，无
    BWC_RR_CAN1_FrP1.WheelTimestampRC = 0;                                       //轮速时间戳计数器，无
    BWC_RR_CAN1_FrP1.Comm_Avaliable_BCU_M = 1;                                   //与BCU_M通讯有效
    BWC_RR_CAN1_FrP1.Comm_Avaliable_BCU_R = 1;                                   //与BCU_R通讯有效
    BWC_RR_CAN1_FrP1.AliveRollingCount = rollcnt;                                       //心跳信号
    BWC_RR_CAN1_FrP1.Checksum = 0;                                               //CRC校验暂时先不发
#endif


}   