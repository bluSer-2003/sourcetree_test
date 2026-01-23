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

#endif                                 /* can_COMMON_INCLUDES_ */

#include "canfd_types.h"
#include <stddef.h>
#include <string.h>


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
extern uint32_T CANfd_Password;
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
