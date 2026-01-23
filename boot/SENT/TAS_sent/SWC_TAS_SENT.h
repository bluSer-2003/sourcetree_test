/*
 * File: SWC_TAS.h
 *
 * Code generated for Simulink model 'SWC_TAS'.
 *
 * Model version                  : 1.88
 * Simulink Coder version         : 9.5 (R2021a) 14-Nov-2020
 * C/C++ source code generated on : Sun Mar  2 23:21:50 2025
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Renesas->RH850
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_SWC_TAS_SENT_h_
#define RTW_HEADER_SWC_TAS_SENT_h_
#include "rtwtypes.h"
#include <float.h>
#include <math.h>
#include <stddef.h>
#include <string.h>
#ifndef SWC_TAS_COMMON_INCLUDES_
#define SWC_TAS_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* SWC_TAS_COMMON_INCLUDES_ */

/* Model Code Variants */

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

/* Forward declaration for rtModel */
typedef struct tag_RTM_SWC_TAS_T RT_MODEL_SWC_TAS_T;

#ifndef DEFINED_TYPEDEF_FOR_TAS_AngResolutionFlt_Type_
#define DEFINED_TYPEDEF_FOR_TAS_AngResolutionFlt_Type_

typedef struct {
  boolean_T TAS_AngZeroNotCal;
  boolean_T TAS_AngAbnormal;
} TAS_AngResolutionFlt_Type;

#endif

#ifndef DEFINED_TYPEDEF_FOR_TAS_TrqResolutionFlt_Type_
#define DEFINED_TYPEDEF_FOR_TAS_TrqResolutionFlt_Type_

typedef struct {
  boolean_T TAS_TrqAbnormal;
} TAS_TrqResolutionFlt_Type;

#endif

/* Block states (default storage) for system '<S20>/Chart' */
typedef struct {
  uint8_T is_active_c5_SWC_TAS;        /* '<S20>/Chart' */
  uint8_T is_c5_SWC_TAS;               /* '<S20>/Chart' */
} DW_Chart_SWC_TAS_T;

/* Block signals (default storage) */
typedef struct {
  real32_T Vernier0;                   /* '<S22>/Chart' */
  real32_T SENT0;                      /* '<S21>/Chart' */
  real32_T Vernier0_m;                 /* '<S21>/Chart' */
  real32_T Vernier0_g;                 /* '<S20>/Chart' */
  uint16_T SENT0_i;                    /* '<S22>/Chart' */
  uint16_T SENT0_l;                    /* '<S20>/Chart' */
  uint8_T AngFollowerChoose;           /* '<S6>/StateSupervisor' */
  uint8_T reset;                       /* '<S6>/StateSupervisor' */
  uint8_T Vernier_Init;                /* '<S6>/StateSupervisor' */
  boolean_T LogicalOperator;           /* '<S77>/Logical Operator' */
} B_SWC_TAS_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real32_T UnitDelay1_DSTATE;          /* '<S7>/Unit Delay1' */
  real32_T UnitDelay5_DSTATE;          /* '<S32>/Unit Delay5' */
  real32_T UnitDelay1_DSTATE_a;        /* '<S20>/Unit Delay1' */
  real32_T UnitDelay5_DSTATE_l;        /* '<S41>/Unit Delay5' */
  real32_T UnitDelay1_DSTATE_k;        /* '<S21>/Unit Delay1' */
  real32_T UnitDelay3_DSTATE;          /* '<S21>/Unit Delay3' */
  real32_T UnitDelay5_DSTATE_k;        /* '<S50>/Unit Delay5' */
  real32_T UnitDelay1_DSTATE_h;        /* '<S22>/Unit Delay1' */
  real32_T Delay2_DSTATE;              /* '<S75>/Delay2' */
  real32_T Delay1_DSTATE;              /* '<S75>/Delay1' */
  real32_T UnitDelay_DSTATE_m;         /* '<S7>/Unit Delay' */
  real32_T UnitDelay_DSTATE_o;         /* '<S8>/Unit Delay' */
  real32_T UnitDelay1_DSTATE_o;        /* '<S8>/Unit Delay1' */
  real32_T OutCnt;                     /* '<S99>/Chart' */
  real32_T max_grad;                   /* '<S6>/StateSupervisor' */
  real32_T min_grad;                   /* '<S6>/StateSupervisor' */
  uint16_T UnitDelay3_DSTATE_i;        /* '<S20>/Unit Delay3' */
  uint16_T UnitDelay3_DSTATE_e;        /* '<S22>/Unit Delay3' */
  uint8_T UnitDelay3_DSTATE_ht;        /* '<S32>/Unit Delay3' */
  uint8_T UnitDelay4_DSTATE_j;         /* '<S32>/Unit Delay4' */
  uint8_T UnitDelay3_DSTATE_c;         /* '<S41>/Unit Delay3' */
  uint8_T UnitDelay4_DSTATE_g;         /* '<S41>/Unit Delay4' */
  uint8_T UnitDelay3_DSTATE_c1;        /* '<S50>/Unit Delay3' */
  uint8_T UnitDelay4_DSTATE_k;         /* '<S50>/Unit Delay4' */
  uint8_T UnitDelay_DSTATE_f;          /* '<S6>/Unit Delay' */
  boolean_T UnitDelay1_DSTATE_b;       /* '<S6>/Unit Delay1' */
  uint8_T is_active_c3_SWC_TAS;        /* '<S99>/Chart' */
  uint8_T is_c3_SWC_TAS;               /* '<S99>/Chart' */
  uint8_T is_active_c11_SWC_TAS;       /* '<S6>/StateSupervisor' */
  uint8_T is_c11_SWC_TAS;              /* '<S6>/StateSupervisor' */
  uint8_T is_INIT;                     /* '<S6>/StateSupervisor' */
  uint8_T is_QM;                       /* '<S6>/StateSupervisor' */
  uint8_T is_Prewarning;               /* '<S6>/StateSupervisor' */
  uint8_T ec_af_init;                  /* '<S6>/StateSupervisor' */
  uint8_T Cnt;                         /* '<S6>/StateSupervisor' */
  uint8_T ef_mg;                       /* '<S6>/StateSupervisor' */
  uint8_T is_active_c6_SWC_TAS;        /* '<S21>/Chart' */
  uint8_T is_c6_SWC_TAS;               /* '<S21>/Chart' */
  DW_Chart_SWC_TAS_T sf_Chart_h;       /* '<S22>/Chart' */
  DW_Chart_SWC_TAS_T sf_Chart;         /* '<S20>/Chart' */
} DW_SWC_TAS_T;

/* Constant parameters (default storage) */
typedef struct {
  /* Expression: [0 22 7 29 14 36 21 6 28 13 35 20 5 27 12 34 19 4 26 11 33 18 3 25 10 32 17 2 24 9 31 16 1 23 8 30 15 0]
   * Referenced by: '<S57>/Interpolation Using Prelookup'
   */
  real_T InterpolationUsingPrelookup_Tab[38];

  /* Computed Parameter: Prelookup_BreakpointsData
   * Referenced by: '<S57>/Prelookup'
   */
  real32_T Prelookup_BreakpointsData[38];
} ConstP_SWC_TAS_T;

/* Real-time Model Data Structure */
struct tag_RTM_SWC_TAS_T {
  const char_T * volatile errorStatus;
};

/* Block signals (default storage) */
extern B_SWC_TAS_T SWC_TAS_B;

/* Block states (default storage) */
extern DW_SWC_TAS_T SWC_TAS_DW;

/* External data declarations for dependent source files */
extern const TAS_AngResolutionFlt_Type SWC_TAS_rtZTAS_AngResolutionFlt_Type;/* TAS_AngResolutionFlt_Type ground */
extern const TAS_TrqResolutionFlt_Type SWC_TAS_rtZTAS_TrqResolutionFlt_Type;/* TAS_TrqResolutionFlt_Type ground */

/* Constant parameters (default storage) */
extern const ConstP_SWC_TAS_T SWC_TAS_ConstP;

/*
 * Exported Global Signals
 *
 * Note: Exported global signals are block signals with an exported global
 * storage class designation.  Code generation will declare the memory for
 * these signals and export their symbols.
 *
 */
extern uint16_T TAS_SENT1A_NA_u16_Read;/* '<Root>/TAS_SENT1A_NA_u16_Read' */
extern uint16_T TAS_SENT2A_NA_u16_Read;/* '<Root>/TAS_SENT2A_NA_u16_Read' */
extern uint16_T TAS_SENT1B_NA_u16_Read;/* '<Root>/TAS_SENT1B_NA_u16_Read' */
extern uint16_T TAS_SENT2B_NA_u16_Read;/* '<Root>/TAS_SENT2B_NA_u16_Read' */
extern uint16_T TAS_SENT_ANG_NA_u16_Read;/* '<Root>/TAS_SENT_ANG_NA_u16_Read' */
extern real32_T TAS_AngOffset_deg_f32_Read;/* '<Root>/TAS_AngOffset_deg_f32_Read' */
extern boolean_T TAS_AngCalbra_NA_bl_Read;/* '<Root>/TAS_AngCalbra_NA_bl_Read' */
extern boolean_T TAS_SENT1_LossOfSignal_NA_bl_Read;
                               /* '<Root>/TAS_SENT1_LossOfSignal_NA_bl_Read ' */
extern boolean_T TAS_SENT2_LossOfSignal_NA_bl_Read;
                                /* '<Root>/TAS_SENT2_LossOfSignal_NA_bl_Read' */
extern boolean_T TAS_SENT3_LossOfSignal_NA_bl_Read;
                               /* '<Root>/TAS_SENT3_LossOfSignal_NA_bl_Read ' */
extern TAS_TrqResolutionFlt_Type TAS_TrqResolutionFlt_write;/* '<S93>/Bus Creator' */
extern TAS_AngResolutionFlt_Type TAS_AngResolutionFlt_Write;/* '<S4>/Bus Creator' */
extern real32_T TAS_T1_NA_f32_Watch;   /* '<S94>/Divide' */
extern real32_T TAS_T2_NA_f32_Watch;   /* '<S94>/Divide1' */
extern real32_T TAS_TrqSC_Err_NA_f32_Watch;/* '<S99>/Abs' */
extern real32_T TAS_StrTrq_Nm_f32_Write;/* '<S94>/Merge' */
extern real32_T TAS_SENT1A_Follower_Deg_f32_Watch;/* '<S17>/Gain' */
extern real32_T TAS_SENT2A_Follower_Deg_f32_Watch;/* '<S18>/Gain' */
extern real32_T TAS_SENT_ANG_Follower_Deg_f32_Watch;/* '<S19>/Gain' */
extern real32_T TAS_Vernier_Angle_Deg_f32_Watch;/* '<S12>/Gain' */
extern real32_T TAS_ec_af_S1A_NA_f32_Watch;/* '<S79>/Merge9' */
extern real32_T TAS_ec_af_S2A_NA_f32_Watch;/* '<S79>/Merge10' */
extern real32_T TAS_ec_af_S3_NA_f32_Watch;/* '<S79>/Merge11' */
extern real32_T TAS_ec_af_Vernier_NA_f32_Watch;/* '<S79>/Merge12' */
extern real32_T TAS_ec_diag_S1A_NA_f32_Watch;/* '<S79>/Merge14' */
extern real32_T TAS_ec_diag_S2A_NA_f32_Watch;/* '<S79>/Merge16' */
extern real32_T TAS_ec_diag_S3_NA_f32_Watch;/* '<S79>/Merge13' */
extern real32_T TAS_StrAng_deg_f32_Write;/* '<S72>/Multiport Switch' */
extern real32_T TAS_StrAngVel_degps_f32_Write;/* '<S8>/Unit Delay1' */
extern uint8_T TAS_SafetySts_NA_u8_Watch;/* '<S6>/StateSupervisor' */
extern boolean_T TAS_TrqLossOfSignal_NA_bl_Watch;/* '<S2>/Logical Operator' */
extern boolean_T TAS_TrqAbnormal_NA_bl_Watch;/* '<S99>/Chart' */
extern boolean_T TAS_Vres_FD_NA_bl_Watch;/* '<S67>/Relational Operator' */
extern boolean_T TAS_LossOfSignal_NA_bl_Watch;/* '<S6>/Relational Operator1' */
extern boolean_T TAS_AngCntOutLim_NA_bl_Watch;/* '<S4>/Relational Operator' */
extern boolean_T TAS_AngOutLim_NA_bl_Watch;/* '<S4>/Logical Operator' */

/* Model entry point functions */
extern void SWC_TAS_initialize(void);

/* Exported entry point function */
extern void TMT_Rnbl_TAS_StrAng(void);

/* Exported entry point function */
extern void TMT_Rnbl_TAS_StrTrq(void);

/* Exported data declaration */

/* Custom Memory Section */
#ifndef CAL_SEG
#define CAL_SEG                        __attribute__ ((section(".CalSection")))
#endif

/* Declaration for custom storage class: CustomParameter */
extern volatile uint8_T TAS_AngOffset_Switch_NA_u8_Cal;/* Referenced by:
                                                        * '<S12>/Constant2'
                                                        * '<S17>/Constant2'
                                                        * '<S18>/Constant2'
                                                        * '<S19>/Constant2'
                                                        */
extern volatile real32_T TAS_AngOffset_deg_f32_Cal;/* Referenced by:
                                                    * '<S12>/Constant3'
                                                    * '<S17>/Constant3'
                                                    * '<S18>/Constant3'
                                                    * '<S19>/Constant3'
                                                    */
extern volatile real32_T TAS_CntUpLim_NA_f32_Cal;/* Referenced by:
                                                  * '<S81>/Saturation'
                                                  * '<S81>/Saturation1'
                                                  * '<S81>/Saturation2'
                                                  * '<S81>/Saturation3'
                                                  * '<S81>/Saturation4'
                                                  * '<S81>/Saturation5'
                                                  * '<S81>/Saturation7'
                                                  * '<S82>/Saturation'
                                                  * '<S82>/Saturation1'
                                                  * '<S82>/Saturation2'
                                                  * '<S82>/Saturation3'
                                                  * '<S82>/Saturation4'
                                                  * '<S82>/Saturation5'
                                                  * '<S82>/Saturation6'
                                                  */
extern volatile real32_T TAS_FaultCntLim_NA_f32_Cal;/* Referenced by: '<S6>/Constant1' */
extern volatile real32_T TAS_Kalman_Q_NA_f32_Cal;/* Referenced by: '<S7>/Constant1' */
extern volatile real32_T TAS_Kalman_R_NA_f32_Cal;/* Referenced by: '<S7>/Constant3' */
extern volatile real32_T TAS_SC_AngLim_deg_f32_Cal;/* Referenced by:
                                                    * '<S77>/Constant'
                                                    * '<S91>/Constant'
                                                    */
extern volatile real32_T TAS_TorsionBarStiff_NA_f32_Cal;/* Referenced by: '<S97>/Constant' */
extern volatile real32_T TAS_TrqFltTimeTh_Sec_f32_Cal;/* Referenced by: '<S99>/Constant2' */
extern volatile real32_T TAS_TrqOffset_Nm_f32_Cal;/* Referenced by: '<S97>/Constant4' */
extern volatile uint8_T TAS_TrqOffset_Switch_NA_u8_Cal;/* Referenced by: '<S97>/Constant2' */
extern volatile real32_T TAS_TrqSynchrCheckTh_Deg_f32_Cal;/* Referenced by: '<S99>/Thr' */

/* Real-time Model object */
extern RT_MODEL_SWC_TAS_T *const SWC_TAS_M;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S9>/FixPt Data Type Duplicate' : Unused code path elimination
 * Block '<S95>/Constant6' : Unused code path elimination
 * Block '<S95>/Constant7' : Unused code path elimination
 * Block '<S95>/Logical Operator1' : Unused code path elimination
 * Block '<S95>/Relational Operator2' : Unused code path elimination
 * Block '<S95>/Relational Operator3' : Unused code path elimination
 * Block '<S96>/Constant8' : Unused code path elimination
 * Block '<S96>/Constant9' : Unused code path elimination
 * Block '<S96>/Logical Operator1' : Unused code path elimination
 * Block '<S96>/Relational Operator2' : Unused code path elimination
 * Block '<S96>/Relational Operator3' : Unused code path elimination
 */

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'SWC_TAS'
 * '<S1>'   : 'SWC_TAS/Rnbl_TAS_StrAng'
 * '<S2>'   : 'SWC_TAS/Rnbl_TAS_StrTrq'
 * '<S3>'   : 'SWC_TAS/Rnbl_TAS_StrAng/AngVelCal'
 * '<S4>'   : 'SWC_TAS/Rnbl_TAS_StrAng/FaultDiag'
 * '<S5>'   : 'SWC_TAS/Rnbl_TAS_StrAng/Subsystem1'
 * '<S6>'   : 'SWC_TAS/Rnbl_TAS_StrAng/Supervisor'
 * '<S7>'   : 'SWC_TAS/Rnbl_TAS_StrAng/AngVelCal/Subsystem4'
 * '<S8>'   : 'SWC_TAS/Rnbl_TAS_StrAng/AngVelCal/Subsystem5'
 * '<S9>'   : 'SWC_TAS/Rnbl_TAS_StrAng/FaultDiag/Interval Test'
 * '<S10>'  : 'SWC_TAS/Rnbl_TAS_StrAng/Subsystem1/AngleCal'
 * '<S11>'  : 'SWC_TAS/Rnbl_TAS_StrAng/Subsystem1/Preprocessing'
 * '<S12>'  : 'SWC_TAS/Rnbl_TAS_StrAng/Subsystem1/AngleCal/AngOffset'
 * '<S13>'  : 'SWC_TAS/Rnbl_TAS_StrAng/Subsystem1/AngleCal/AngleFollower'
 * '<S14>'  : 'SWC_TAS/Rnbl_TAS_StrAng/Subsystem1/AngleCal/VernierCal'
 * '<S15>'  : 'SWC_TAS/Rnbl_TAS_StrAng/Subsystem1/AngleCal/AngOffset/If Action Subsystem'
 * '<S16>'  : 'SWC_TAS/Rnbl_TAS_StrAng/Subsystem1/AngleCal/AngOffset/If Action Subsystem1'
 * '<S17>'  : 'SWC_TAS/Rnbl_TAS_StrAng/Subsystem1/AngleCal/AngleFollower/AngOffset'
 * '<S18>'  : 'SWC_TAS/Rnbl_TAS_StrAng/Subsystem1/AngleCal/AngleFollower/AngOffset1'
 * '<S19>'  : 'SWC_TAS/Rnbl_TAS_StrAng/Subsystem1/AngleCal/AngleFollower/AngOffset2'
 * '<S20>'  : 'SWC_TAS/Rnbl_TAS_StrAng/Subsystem1/AngleCal/AngleFollower/SENT1_ANGFollower'
 * '<S21>'  : 'SWC_TAS/Rnbl_TAS_StrAng/Subsystem1/AngleCal/AngleFollower/SENT2_ANGFollower'
 * '<S22>'  : 'SWC_TAS/Rnbl_TAS_StrAng/Subsystem1/AngleCal/AngleFollower/SENT3_ANGFollower'
 * '<S23>'  : 'SWC_TAS/Rnbl_TAS_StrAng/Subsystem1/AngleCal/AngleFollower/AngOffset/If Action Subsystem'
 * '<S24>'  : 'SWC_TAS/Rnbl_TAS_StrAng/Subsystem1/AngleCal/AngleFollower/AngOffset/If Action Subsystem1'
 * '<S25>'  : 'SWC_TAS/Rnbl_TAS_StrAng/Subsystem1/AngleCal/AngleFollower/AngOffset1/If Action Subsystem'
 * '<S26>'  : 'SWC_TAS/Rnbl_TAS_StrAng/Subsystem1/AngleCal/AngleFollower/AngOffset1/If Action Subsystem1'
 * '<S27>'  : 'SWC_TAS/Rnbl_TAS_StrAng/Subsystem1/AngleCal/AngleFollower/AngOffset2/If Action Subsystem'
 * '<S28>'  : 'SWC_TAS/Rnbl_TAS_StrAng/Subsystem1/AngleCal/AngleFollower/AngOffset2/If Action Subsystem1'
 * '<S29>'  : 'SWC_TAS/Rnbl_TAS_StrAng/Subsystem1/AngleCal/AngleFollower/SENT1_ANGFollower/Chart'
 * '<S30>'  : 'SWC_TAS/Rnbl_TAS_StrAng/Subsystem1/AngleCal/AngleFollower/SENT1_ANGFollower/If Action Subsystem'
 * '<S31>'  : 'SWC_TAS/Rnbl_TAS_StrAng/Subsystem1/AngleCal/AngleFollower/SENT1_ANGFollower/If Action Subsystem1'
 * '<S32>'  : 'SWC_TAS/Rnbl_TAS_StrAng/Subsystem1/AngleCal/AngleFollower/SENT1_ANGFollower/Subsystem'
 * '<S33>'  : 'SWC_TAS/Rnbl_TAS_StrAng/Subsystem1/AngleCal/AngleFollower/SENT1_ANGFollower/Subsystem1'
 * '<S34>'  : 'SWC_TAS/Rnbl_TAS_StrAng/Subsystem1/AngleCal/AngleFollower/SENT1_ANGFollower/Subsystem2'
 * '<S35>'  : 'SWC_TAS/Rnbl_TAS_StrAng/Subsystem1/AngleCal/AngleFollower/SENT1_ANGFollower/If Action Subsystem/Decrease'
 * '<S36>'  : 'SWC_TAS/Rnbl_TAS_StrAng/Subsystem1/AngleCal/AngleFollower/SENT1_ANGFollower/If Action Subsystem/Increase'
 * '<S37>'  : 'SWC_TAS/Rnbl_TAS_StrAng/Subsystem1/AngleCal/AngleFollower/SENT1_ANGFollower/Subsystem2/Subsystem1'
 * '<S38>'  : 'SWC_TAS/Rnbl_TAS_StrAng/Subsystem1/AngleCal/AngleFollower/SENT2_ANGFollower/Chart'
 * '<S39>'  : 'SWC_TAS/Rnbl_TAS_StrAng/Subsystem1/AngleCal/AngleFollower/SENT2_ANGFollower/If Action Subsystem'
 * '<S40>'  : 'SWC_TAS/Rnbl_TAS_StrAng/Subsystem1/AngleCal/AngleFollower/SENT2_ANGFollower/If Action Subsystem1'
 * '<S41>'  : 'SWC_TAS/Rnbl_TAS_StrAng/Subsystem1/AngleCal/AngleFollower/SENT2_ANGFollower/Subsystem'
 * '<S42>'  : 'SWC_TAS/Rnbl_TAS_StrAng/Subsystem1/AngleCal/AngleFollower/SENT2_ANGFollower/Subsystem1'
 * '<S43>'  : 'SWC_TAS/Rnbl_TAS_StrAng/Subsystem1/AngleCal/AngleFollower/SENT2_ANGFollower/Subsystem2'
 * '<S44>'  : 'SWC_TAS/Rnbl_TAS_StrAng/Subsystem1/AngleCal/AngleFollower/SENT2_ANGFollower/If Action Subsystem/Decrease'
 * '<S45>'  : 'SWC_TAS/Rnbl_TAS_StrAng/Subsystem1/AngleCal/AngleFollower/SENT2_ANGFollower/If Action Subsystem/Increase'
 * '<S46>'  : 'SWC_TAS/Rnbl_TAS_StrAng/Subsystem1/AngleCal/AngleFollower/SENT2_ANGFollower/Subsystem2/Subsystem1'
 * '<S47>'  : 'SWC_TAS/Rnbl_TAS_StrAng/Subsystem1/AngleCal/AngleFollower/SENT3_ANGFollower/Chart'
 * '<S48>'  : 'SWC_TAS/Rnbl_TAS_StrAng/Subsystem1/AngleCal/AngleFollower/SENT3_ANGFollower/If Action Subsystem'
 * '<S49>'  : 'SWC_TAS/Rnbl_TAS_StrAng/Subsystem1/AngleCal/AngleFollower/SENT3_ANGFollower/If Action Subsystem1'
 * '<S50>'  : 'SWC_TAS/Rnbl_TAS_StrAng/Subsystem1/AngleCal/AngleFollower/SENT3_ANGFollower/Subsystem'
 * '<S51>'  : 'SWC_TAS/Rnbl_TAS_StrAng/Subsystem1/AngleCal/AngleFollower/SENT3_ANGFollower/Subsystem1'
 * '<S52>'  : 'SWC_TAS/Rnbl_TAS_StrAng/Subsystem1/AngleCal/AngleFollower/SENT3_ANGFollower/Subsystem2'
 * '<S53>'  : 'SWC_TAS/Rnbl_TAS_StrAng/Subsystem1/AngleCal/AngleFollower/SENT3_ANGFollower/If Action Subsystem/Decrease'
 * '<S54>'  : 'SWC_TAS/Rnbl_TAS_StrAng/Subsystem1/AngleCal/AngleFollower/SENT3_ANGFollower/If Action Subsystem/Increase'
 * '<S55>'  : 'SWC_TAS/Rnbl_TAS_StrAng/Subsystem1/AngleCal/AngleFollower/SENT3_ANGFollower/Subsystem2/Subsystem1'
 * '<S56>'  : 'SWC_TAS/Rnbl_TAS_StrAng/Subsystem1/AngleCal/VernierCal/Subsystem'
 * '<S57>'  : 'SWC_TAS/Rnbl_TAS_StrAng/Subsystem1/AngleCal/VernierCal/Subsystem1'
 * '<S58>'  : 'SWC_TAS/Rnbl_TAS_StrAng/Subsystem1/AngleCal/VernierCal/Subsystem2'
 * '<S59>'  : 'SWC_TAS/Rnbl_TAS_StrAng/Subsystem1/AngleCal/VernierCal/Subsystem/If Action Subsystem'
 * '<S60>'  : 'SWC_TAS/Rnbl_TAS_StrAng/Subsystem1/AngleCal/VernierCal/Subsystem/If Action Subsystem1'
 * '<S61>'  : 'SWC_TAS/Rnbl_TAS_StrAng/Subsystem1/AngleCal/VernierCal/Subsystem/If Action Subsystem2'
 * '<S62>'  : 'SWC_TAS/Rnbl_TAS_StrAng/Subsystem1/AngleCal/VernierCal/Subsystem/If Action Subsystem3'
 * '<S63>'  : 'SWC_TAS/Rnbl_TAS_StrAng/Subsystem1/AngleCal/VernierCal/Subsystem/If Action Subsystem4'
 * '<S64>'  : 'SWC_TAS/Rnbl_TAS_StrAng/Subsystem1/AngleCal/VernierCal/Subsystem/If Action Subsystem5'
 * '<S65>'  : 'SWC_TAS/Rnbl_TAS_StrAng/Subsystem1/AngleCal/VernierCal/Subsystem1/If Action Subsystem'
 * '<S66>'  : 'SWC_TAS/Rnbl_TAS_StrAng/Subsystem1/AngleCal/VernierCal/Subsystem1/If Action Subsystem1'
 * '<S67>'  : 'SWC_TAS/Rnbl_TAS_StrAng/Subsystem1/AngleCal/VernierCal/Subsystem1/Subsystem'
 * '<S68>'  : 'SWC_TAS/Rnbl_TAS_StrAng/Subsystem1/Preprocessing/Preprocessing'
 * '<S69>'  : 'SWC_TAS/Rnbl_TAS_StrAng/Subsystem1/Preprocessing/Preprocessing/Subsystem'
 * '<S70>'  : 'SWC_TAS/Rnbl_TAS_StrAng/Subsystem1/Preprocessing/Preprocessing/Subsystem2'
 * '<S71>'  : 'SWC_TAS/Rnbl_TAS_StrAng/Subsystem1/Preprocessing/Preprocessing/Subsystem4'
 * '<S72>'  : 'SWC_TAS/Rnbl_TAS_StrAng/Supervisor/ANG_OUT'
 * '<S73>'  : 'SWC_TAS/Rnbl_TAS_StrAng/Supervisor/StateSupervisor'
 * '<S74>'  : 'SWC_TAS/Rnbl_TAS_StrAng/Supervisor/SynchronicityCheck'
 * '<S75>'  : 'SWC_TAS/Rnbl_TAS_StrAng/Supervisor/Timing'
 * '<S76>'  : 'SWC_TAS/Rnbl_TAS_StrAng/Supervisor/SynchronicityCheck/ErrorCnt'
 * '<S77>'  : 'SWC_TAS/Rnbl_TAS_StrAng/Supervisor/SynchronicityCheck/VernierSynchronicityCheck'
 * '<S78>'  : 'SWC_TAS/Rnbl_TAS_StrAng/Supervisor/SynchronicityCheck/ErrorCnt/ErrCnt'
 * '<S79>'  : 'SWC_TAS/Rnbl_TAS_StrAng/Supervisor/SynchronicityCheck/ErrorCnt/IF_RESET'
 * '<S80>'  : 'SWC_TAS/Rnbl_TAS_StrAng/Supervisor/SynchronicityCheck/ErrorCnt/SENT_SynchronicityCheck'
 * '<S81>'  : 'SWC_TAS/Rnbl_TAS_StrAng/Supervisor/SynchronicityCheck/ErrorCnt/ErrCnt/decrease'
 * '<S82>'  : 'SWC_TAS/Rnbl_TAS_StrAng/Supervisor/SynchronicityCheck/ErrorCnt/ErrCnt/increase'
 * '<S83>'  : 'SWC_TAS/Rnbl_TAS_StrAng/Supervisor/SynchronicityCheck/ErrorCnt/IF_RESET/If Action Subsystem'
 * '<S84>'  : 'SWC_TAS/Rnbl_TAS_StrAng/Supervisor/SynchronicityCheck/ErrorCnt/IF_RESET/If Action Subsystem1'
 * '<S85>'  : 'SWC_TAS/Rnbl_TAS_StrAng/Supervisor/SynchronicityCheck/ErrorCnt/SENT_SynchronicityCheck/If Action Subsystem'
 * '<S86>'  : 'SWC_TAS/Rnbl_TAS_StrAng/Supervisor/SynchronicityCheck/ErrorCnt/SENT_SynchronicityCheck/If Action Subsystem1'
 * '<S87>'  : 'SWC_TAS/Rnbl_TAS_StrAng/Supervisor/SynchronicityCheck/ErrorCnt/SENT_SynchronicityCheck/If Action Subsystem2'
 * '<S88>'  : 'SWC_TAS/Rnbl_TAS_StrAng/Supervisor/SynchronicityCheck/ErrorCnt/SENT_SynchronicityCheck/If Action Subsystem3'
 * '<S89>'  : 'SWC_TAS/Rnbl_TAS_StrAng/Supervisor/SynchronicityCheck/ErrorCnt/SENT_SynchronicityCheck/If Action Subsystem4'
 * '<S90>'  : 'SWC_TAS/Rnbl_TAS_StrAng/Supervisor/SynchronicityCheck/ErrorCnt/SENT_SynchronicityCheck/If Action Subsystem5'
 * '<S91>'  : 'SWC_TAS/Rnbl_TAS_StrAng/Supervisor/SynchronicityCheck/ErrorCnt/SENT_SynchronicityCheck/Subsystem'
 * '<S92>'  : 'SWC_TAS/Rnbl_TAS_StrTrq/Preprocessing1'
 * '<S93>'  : 'SWC_TAS/Rnbl_TAS_StrTrq/Subsystem'
 * '<S94>'  : 'SWC_TAS/Rnbl_TAS_StrTrq/Subsystem2'
 * '<S95>'  : 'SWC_TAS/Rnbl_TAS_StrTrq/Preprocessing1/Subsystem1'
 * '<S96>'  : 'SWC_TAS/Rnbl_TAS_StrTrq/Preprocessing1/Subsystem3'
 * '<S97>'  : 'SWC_TAS/Rnbl_TAS_StrTrq/Subsystem2/If Action Subsystem'
 * '<S98>'  : 'SWC_TAS/Rnbl_TAS_StrTrq/Subsystem2/If Action Subsystem1'
 * '<S99>'  : 'SWC_TAS/Rnbl_TAS_StrTrq/Subsystem2/Synchronicity_Check'
 * '<S100>' : 'SWC_TAS/Rnbl_TAS_StrTrq/Subsystem2/Synchronicity_Check/Chart'
 */
#endif                                 /* RTW_HEADER_SWC_TAS_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
