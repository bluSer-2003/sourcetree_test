/*
 * File: can.h
 *
 * Code generated for Simulink model 'can'.
 *
 * Model version                  : 9.21
 * Simulink Coder version         : 24.1 (R2024a) 19-Nov-2023
 * C/C++ source code generated on : Thu Jul 18 17:08:23 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Texas Instruments->C2000
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef canfd_h_
#define canfd_h_
//#ifndef can_COMMON_INCLUDES_
//#define can_COMMON_INCLUDES_

#include "canfd_types.h"
#include <stddef.h>
#include <string.h>
#include "r_compiler.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif






/* Block signals (default storage) */
typedef struct {
  real_T u_o2;                         /* '<S10>/?????????4' */
  real_T u_o5;                         /* '<S10>/?????????4' */
  real_T u_o8;                         /* '<S10>/?????????4' */
  real_T u_o11;                        /* '<S10>/?????????4' */
  real_T u_o7;                         /* '<S6>/?????????2' */
  real_T _o1;                          /* '<S5>/?????????' */
  uint16_T u_o1;                         /* '<S4>/?????????1' */
  uint32_T u_o3;                       /* '<S6>/?????????2' */
  real32_T u_o1_d;                     /* '<S10>/?????????4' */
  real32_T u_o3_j;                     /* '<S10>/?????????4' */
  real32_T u_o4;                       /* '<S10>/?????????4' */
  real32_T u_o7_h;                     /* '<S10>/?????????4' */
  real32_T u_o10;                      /* '<S10>/?????????4' */
  real32_T u_o1_g;                     /* '<S6>/?????????2' */
  real32_T u_o4_i;                     /* '<S6>/?????????2' */
  real32_T u_o5_j;                     /* '<S6>/?????????2' */
  real32_T u_o8_i;                     /* '<S6>/?????????2' */
  real32_T u_o9;                       /* '<S6>/?????????2' */
  real32_T u_o3_i;                     /* '<S8>/?????????3' */
  real32_T u_o9_n;                     /* '<S8>/?????????3' */
  real32_T u_o10_b;                    /* '<S8>/?????????3' */
  uint16_T u_o6;                       /* '<S10>/?????????4' */
  uint16_T u_o9_o;                     /* '<S10>/?????????4' */
  uint16_T u_o12;                      /* '<S10>/?????????4' */
  uint16_T u_o2_g;                     /* '<S6>/?????????2' */
  uint16_T u_o6_o;                     /* '<S6>/?????????2' */
  uint16_T u_o1_f;                     /* '<S8>/?????????3' */
  uint16_T u_o2_gk;                    /* '<S8>/?????????3' */
  uint16_T u_o4_m;                     /* '<S8>/?????????3' */
  uint16_T u_o5_c;                     /* '<S8>/?????????3' */
  uint16_T u_o6_b;                     /* '<S8>/?????????3' */
  uint16_T u_o7_g;                     /* '<S8>/?????????3' */
  uint16_T u_o8_j;                     /* '<S8>/?????????3' */
  uint16_T u_o13;                      /* '<S10>/?????????4' */
  uint16_T u_o10_e;                    /* '<S6>/?????????2' */
  uint16_T u_o11_l;                    /* '<S8>/?????????3' */
  uint16_T _o2;                        /* '<S5>/?????????' */
  uint16_T u_o2_o;                     /* '<S4>/?????????1' */
} B_canFD_P_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  int_T u_ModeSignalID;                /* '<S10>/?????????4' */
  int_T u_StatusPortID;                /* '<S10>/?????????4' */
  int_T u_ModeSignalID_m;              /* '<S6>/?????????2' */
  int_T u_StatusPortID_n;              /* '<S6>/?????????2' */
  int_T u_ModeSignalID_n;              /* '<S8>/?????????3' */
  int_T u_StatusPortID_e;              /* '<S8>/?????????3' */
  int_T _ModeSignalID;                 /* '<S5>/?????????' */
  int_T _StatusPortID;                 /* '<S5>/?????????' */
  int_T u_ModeSignalID_h;              /* '<S4>/?????????1' */
  int_T u_StatusPortID_p;              /* '<S4>/?????????1' */
  int_T CANFDPack_ModeSignalID;        /* '<S17>/CAN FD Pack' */
  int_T CANFDPack1_ModeSignalID;       /* '<S15>/CAN FD Pack1' */
  int_T CANFDPack_ModeSignalID_p;      /* '<S16>/CAN FD Pack' */
  int_T CANFDPack_ModeSignalID_i;      /* '<S14>/CAN FD Pack' */
  int_T CANFDPack_ModeSignalID_pg;     /* '<S13>/CAN FD Pack' */
  int_T CANFDPack_ModeSignalID_il;     /* '<S11>/CAN FD Pack' */
  int_T CANFDPack_ModeSignalID_b;      /* '<S9>/CAN FD Pack' */
  int_T CANFDPack_ModeSignalID_o;      /* '<S7>/CAN FD Pack' */
} DW_canFD_P_T;



/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  CAN_FD_MESSAGE_BUS MaunfStateMessage;/* '<Root>/Maunf State Message_I' */
  CAN_FD_MESSAGE_BUS FeedbackStateMessage;/* '<Root>/Feedback State Message_I' */
  CAN_FD_MESSAGE_BUS GivenStateMessage;/* '<Root>/Given State Message_I' */
  CAN_FD_MESSAGE_BUS RegulatorStateMessage;/* '<Root>/Regulator State Message_I' */
  CAN_FD_MESSAGE_BUS ProtectStateMessage;/* '<Root>/Protect State Message_I' */
  CAN_FD_MESSAGE_BUS FlashStateMessage;
} output;

/* Real-time Model Data Structure */
//struct tag_RTM_canFD_P_T {
  //const char_T * volatile errorStatus;
//};

/* Block signals (default storage) */
extern B_canFD_P_T canFD_P_B;

/* Block states (default storage) */
//extern DW_canFD_P_T canFD_P_DW;

/* External outputs (root outports fed by signals with default storage) */
extern output out;


extern Given Given_Order;
extern Given Given_Complete;

extern Regulator Regulator_Order;
extern Regulator Regulator_Complete;

extern Protect Protect_Order;
extern Protect Protect_Complete;

extern Feedback FB_Inqury;

extern uint16_T Flag_CAN_flash_Order;
extern uint16_T Flag_CAN_flash_Complete;

extern uint16_T FB_Order_Flag;
extern uint16_T FB_Complete_Flag;
extern uint16_T FB_lianxu_Flag;

extern uint16_T Given_Order_Flag;
extern uint16_T Given_Complete_Flag;

extern uint16_T Protect_Order_Flag;
extern uint16_T Protect_Complete_Flag;

extern uint16_T Regulator_Order_Flag;
extern uint16_T Regulator_Complete_Flag;


extern uint16_T CANfd_runState;
extern uint16_T CANfd_Password;
extern uint16_T CANfd_runMode;


//extern void canFD_P_initialize(void);
extern void CAN_FD_P_ANA(CAN_FD_MESSAGE_BUS *msg);
extern void FB_reply(void);
extern void Given_reply(void);
extern void Regulator_reply(void);
//extern void Protect_reply(void);
extern void Flash_reply(void);
//extern void Run_reply(void);
void Error_reply(void);
void Password_reply(void);
extern void Password_Verify(CAN_FD_MESSAGE_BUS *msg);

typedef struct 
{
	uint8  BrkForceVld		:1	;
	uint8  BrkForceActive		:1	;
	uint32 BrkForceActual		:14	;
	uint8  BrkForceLmt		:8	;
	uint8  BrkForceGrdActive	:1	;
	uint8  BrkForceGrdLmtMax	:8	;
	uint8  BrkForceGrdLmtMin	:8	;
	uint8  BrkForceRelPos		:2	;
	uint8  ParkBrkState		:3	;
	uint8  ServiceBrkFailState	:2	;
	uint8  PrakBrkFailState		:2	;
	uint8  MotorControlState	:3	;
	uint8  ParkValveControlState	:3	;
	uint16 WheelSpeed		:15	;
	uint8  WheelSpeedDir		:2	;
	uint8  WheelSpeedVld		:1	;
	uint16 WheelPulseCounter	:10	;
	uint8  WheelPulseReset		:1	;
	uint16 WheelTimestamp		:16	;
	uint8  WheelTimestampRC		:2	;
	uint8  Comm_Avaliable_BCU_M	:1	;
	uint8  Comm_Avaliable_BCU_R	:1	;
	uint8  AliveRollingCount	:4	;
	uint16 Checksum			:16	;
}TX_PDU_0x6Ex;

typedef struct 
{
	uint8 BrkForceCmdActive_FL	:1	;
	uint16 BrkForceCmd_FL		:14	;
	uint8 BrkForceCmdGrdMaxLmtA_FL	:1	;
	uint8 BrkForceCmdGrdMinLmtA_FL	:1	;
	uint16 BrkForceCmdGrdLmt_FL	:11	;
	uint8 BrkForceRelPosReq_FL	:2	;
	uint8 BrkForceDiffAllow_FL	:1	;
	uint8 ABSActive_FL		:1	;
	uint8 ParkRequest_FL		:4	;
	
	uint8 BrkForceCmdActive_FR	:1	;
	uint16 BrkForceCmd_FR		:14	;
	uint8 BrkForceCmdGrdMaxLmtA_FR	:1	;
	uint8 BrkForceCmdGrdMinLmtA_FR	:1	;
	uint16 BrkForceCmdGrdLmt_FR	:11	;
	uint8 BrkForceRelPosReq_FR	:2	;
	uint8 BrkForceDiffAllow_FR	:1	;
	uint8 ABSActive_FR		:1	;
	uint8 ParkRequest_FR		:4	;
	
	uint8 BrkForceCmdActive_RL	:1	;
	uint16 BrkForceCmd_RL		:14	;
	uint8 BrkForceCmdGrdMaxLmtA_RL	:1	;
	uint8 BrkForceCmdGrdMinLmtA_RL	:1	;
	uint16 BrkForceCmdGrdLmt_RL	:11	;
	uint8 BrkForceRelPosReq_RL	:2	;
	uint8 BrkForceDiffAllow_RL	:1	;
	uint8 ABSActive_RL		:1	;
	uint8 ParkRequest_RL		:4	;
	
	uint8 BrkForceCmdActive_RR	:1	;
	uint16 BrkForceCmd_RR		:14	;
	uint8 BrkForceCmdGrdMaxLmtA_RR	:1	;
	uint8 BrkForceCmdGrdMinLmtA_RR	:1	;
	uint16 BrkForceCmdGrdLmt_RR	:11	;
	uint8 BrkForceRelPosReq_RR	:2	;
	uint8 BrkForceDiffAllow_RR	:1	;
	uint8 ABSActive_RR		:1	;
	uint8 ParkRequest_RR		:4	;
	
	uint8 R_Comm_Avaliable		:1	;
	uint8 Control_Enable		:1	;
	uint8 AvailableState		:1	;
	uint8 BrkTakeoverRequest	:1	;
	
	uint8 BrkPedalInputRodPosn	:8	;
	uint8 BrkPedalInputRodPosnVld	:1	;
	uint8 BrkPedalInputRodForce	:8	;
	uint8 BrkPedalInputRodForceVld	:1	;
	
	uint8 LongAccel			:8	;
	uint8 LongAccelVld		:1	;
	uint8 RollerbenchActive		:1	;
	uint16 WheelSpeed_FL		:10	;
	uint8 WheelSpeedVld_FL		:1	;
	uint16 WheelSpeed_FR		:10	;
	uint8 WheelSpeedVld_FR		:1	;
	uint16 WheelSpeed_RL		:10	;
	uint8 WheelSpeedVld_RL		:1	;
	uint16 WheelSpeed_RR		:10	;
	uint8 WheelSpeedVld_RR		:1	;
	uint8 AliveRollingCount		:4	;
	uint16 Checksum			:16	;
	
}RX_PDU_0x6E0;

typedef struct 
{
	uint8 BrkForceCmdActive_FL	:1	;
	uint16 BrkForceCmd_FL		:14	;
	uint8 BrkForceCmdGrdMaxLmtA_FL	:1	;
	uint8 BrkForceCmdGrdMinLmtA_FL	:1	;
	uint16 BrkForceCmdGrdLmt_FL	:11	;
	uint8 BrkForceRelPosReq_FL	:2	;
	uint8 BrkForceDiffAllow_FL	:1	;
	uint8 ABSActive_FL		:1	;
	uint8 ParkRequest_FL		:4	;
	
	uint8 BrkForceCmdActive_FR	:1	;
	uint16 BrkForceCmd_FR		:14	;
	uint8 BrkForceCmdGrdMaxLmtA_FR	:1	;
	uint8 BrkForceCmdGrdMinLmtA_FR	:1	;
	uint16 BrkForceCmdGrdLmt_FR	:11	;
	uint8 BrkForceRelPosReq_FR	:2	;
	uint8 BrkForceDiffAllow_FR	:1	;
	uint8 ABSActive_FR		:1	;
	uint8 ParkRequest_FR		:4	;
	
	uint8 BrkForceCmdActive_RL	:1	;
	uint16 BrkForceCmd_RL		:14	;
	uint8 BrkForceCmdGrdMaxLmtA_RL	:1	;
	uint8 BrkForceCmdGrdMinLmtA_RL	:1	;
	uint16 BrkForceCmdGrdLmt_RL	:11	;
	uint8 BrkForceRelPosReq_RL	:2	;
	uint8 BrkForceDiffAllow_RL	:1	;
	uint8 ABSActive_RL		:1	;
	uint8 ParkRequest_RL		:4	;
	
	uint8 BrkForceCmdActive_RR	:1	;
	uint16 BrkForceCmd_RR		:14	;
	uint8 BrkForceCmdGrdMaxLmtA_RR	:1	;
	uint8 BrkForceCmdGrdMinLmtA_RR	:1	;
	uint16 BrkForceCmdGrdLmt_RR	:11	;
	uint8 BrkForceRelPosReq_RR	:2	;
	uint8 BrkForceDiffAllow_RR	:1	;
	uint8 ABSActive_RR		:1	;
	uint8 ParkRequest_RR		:4	;
	
	uint8 M_Comm_Avaliable		:1	;
	uint8 Control_Enable		:1	;
	uint8 BrkTakeoverResp		:2	;

	
	uint8 BrkPedalInputRodPosn	:8	;
	uint8 BrkPedalInputRodPosnVld	:1	;
	uint8 BrkPedalInputRodForce	:8	;
	uint8 BrkPedalInputRodForceVld	:1	;
	
	uint8 LongAccel			:8	;
	uint8 LongAccelVld		:1	;
	uint8 RollerbenchActive		:1	;
	uint16 WheelSpeed_FL		:10	;
	uint8 WheelSpeedVld_FL		:1	;
	uint16 WheelSpeed_FR		:10	;
	uint8 WheelSpeedVld_FR		:1	;
	uint16 WheelSpeed_RL		:10	;
	uint8 WheelSpeedVld_RL		:1	;
	uint16 WheelSpeed_RR		:10	;
	uint8 WheelSpeedVld_RR		:1	;
	uint8 AliveRollingCount		:4	;
	uint16 Checksum			:16	;
	
}RX_PDU_0x6EF;

typedef struct 
{
	uint8_T Rx_data[64];
}rx_type;

void CAN_Tx_Fun(void);


extern TX_PDU_0x6Ex BWC_FL_CAN1_FrP1;
extern TX_PDU_0x6Ex BWC_FR_CAN1_FrP1;
extern TX_PDU_0x6Ex BWC_RL_CAN1_FrP1;
extern TX_PDU_0x6Ex BWC_RR_CAN1_FrP1;

extern RX_PDU_0x6E0 BCU_M_CAN1_FrP1;
extern RX_PDU_0x6EF BCU_R_CAN1_FrP1;

#endif