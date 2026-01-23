/*
 * File: SWC_TAS.c
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

#include "SWC_TAS.h"

/* Named constants for Chart: '<S20>/Chart' */
#define SWC_TAS_IN_INIT                ((uint8_T)1U)
#define SWC_TAS_IN_NO_ACTIVE_CHILD     ((uint8_T)0U)
#define SWC_TAS_IN_Run                 ((uint8_T)2U)

/* Named constants for Chart: '<S21>/Chart' */
#define SWC_TAS_IN_INIT_i              ((uint8_T)1U)
#define SWC_TAS_IN_NO_ACTIVE_CHILD_e   ((uint8_T)0U)
#define SWC_TAS_IN_Run_n               ((uint8_T)2U)

/* Named constants for Chart: '<S6>/StateSupervisor' */
#define SWC_TAS_IN_ASILB               ((uint8_T)1U)
#define SWC_TAS_IN_ERROR               ((uint8_T)2U)
#define SWC_TAS_IN_INIT_j              ((uint8_T)3U)
#define SWC_TAS_IN_Prewarning          ((uint8_T)4U)
#define SWC_TAS_IN_QM                  ((uint8_T)5U)
#define SWC_TAS_IN_du                  ((uint8_T)1U)
#define SWC_TAS_IN_during              ((uint8_T)1U)
#define SWC_TAS_IN_en                  ((uint8_T)2U)
#define SWC_TAS_IN_ex                  ((uint8_T)3U)

/* Named constants for Chart: '<S99>/Chart' */
#define SWC_TAS_IN_Abnormal            ((uint8_T)1U)
#define SWC_TAS_IN_Normal              ((uint8_T)2U)
#define SWC_TAS_IN_Waitt               ((uint8_T)3U)
#ifndef UCHAR_MAX
#include <limits.h>
#endif

#if ( UCHAR_MAX != (0xFFU) ) || ( SCHAR_MAX != (0x7F) )
#error Code was generated for compiler with different sized uchar/char. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

#if ( USHRT_MAX != (0xFFFFU) ) || ( SHRT_MAX != (0x7FFF) )
#error Code was generated for compiler with different sized ushort/short. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

#if ( UINT_MAX != (0xFFFFFFFFU) ) || ( INT_MAX != (0x7FFFFFFF) )
#error Code was generated for compiler with different sized uint/int. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

#if ( ULONG_MAX != (0xFFFFFFFFU) ) || ( LONG_MAX != (0x7FFFFFFF) )
#error Code was generated for compiler with different sized ulong/long. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

const TAS_AngResolutionFlt_Type SWC_TAS_rtZTAS_AngResolutionFlt_Type = {
  false,                               /* TAS_AngZeroNotCal */
  false                                /* TAS_AngAbnormal */
} ;                                    /* TAS_AngResolutionFlt_Type ground */

const TAS_TrqResolutionFlt_Type SWC_TAS_rtZTAS_TrqResolutionFlt_Type = {
  false                                /* TAS_TrqAbnormal */
} ;                                    /* TAS_TrqResolutionFlt_Type ground */

/* Exported block signals */
uint16_T TAS_SENT1A_NA_u16_Read;       /* '<Root>/TAS_SENT1A_NA_u16_Read' */
uint16_T TAS_SENT2A_NA_u16_Read;       /* '<Root>/TAS_SENT2A_NA_u16_Read' */
uint16_T TAS_SENT1B_NA_u16_Read;       /* '<Root>/TAS_SENT1B_NA_u16_Read' */
uint16_T TAS_SENT2B_NA_u16_Read;       /* '<Root>/TAS_SENT2B_NA_u16_Read' */
uint16_T TAS_SENT_ANG_NA_u16_Read;     /* '<Root>/TAS_SENT_ANG_NA_u16_Read' */
real32_T TAS_AngOffset_deg_f32_Read;   /* '<Root>/TAS_AngOffset_deg_f32_Read' */
boolean_T TAS_AngCalbra_NA_bl_Read;    /* '<Root>/TAS_AngCalbra_NA_bl_Read' */
boolean_T TAS_SENT1_LossOfSignal_NA_bl_Read;
                               /* '<Root>/TAS_SENT1_LossOfSignal_NA_bl_Read ' */
boolean_T TAS_SENT2_LossOfSignal_NA_bl_Read;
                                /* '<Root>/TAS_SENT2_LossOfSignal_NA_bl_Read' */
boolean_T TAS_SENT3_LossOfSignal_NA_bl_Read;
                               /* '<Root>/TAS_SENT3_LossOfSignal_NA_bl_Read ' */
TAS_TrqResolutionFlt_Type TAS_TrqResolutionFlt_write;/* '<S93>/Bus Creator' */
TAS_AngResolutionFlt_Type TAS_AngResolutionFlt_Write;/* '<S4>/Bus Creator' */
real32_T TAS_T1_NA_f32_Watch;          /* '<S94>/Divide' */
real32_T TAS_T2_NA_f32_Watch;          /* '<S94>/Divide1' */
real32_T TAS_TrqSC_Err_NA_f32_Watch;   /* '<S99>/Abs' */
real32_T TAS_StrTrq_Nm_f32_Write;      /* '<S94>/Merge' */
real32_T TAS_SENT1A_Follower_Deg_f32_Watch;/* '<S17>/Gain' */
real32_T TAS_SENT2A_Follower_Deg_f32_Watch;/* '<S18>/Gain' */
real32_T TAS_SENT_ANG_Follower_Deg_f32_Watch;/* '<S19>/Gain' */
real32_T TAS_Vernier_Angle_Deg_f32_Watch;/* '<S12>/Gain' */
real32_T TAS_ec_af_S1A_NA_f32_Watch;   /* '<S79>/Merge9' */
real32_T TAS_ec_af_S2A_NA_f32_Watch;   /* '<S79>/Merge10' */
real32_T TAS_ec_af_S3_NA_f32_Watch;    /* '<S79>/Merge11' */
real32_T TAS_ec_af_Vernier_NA_f32_Watch;/* '<S79>/Merge12' */
real32_T TAS_ec_diag_S1A_NA_f32_Watch; /* '<S79>/Merge14' */
real32_T TAS_ec_diag_S2A_NA_f32_Watch; /* '<S79>/Merge16' */
real32_T TAS_ec_diag_S3_NA_f32_Watch;  /* '<S79>/Merge13' */
real32_T TAS_StrAng_deg_f32_Write;     /* '<S72>/Multiport Switch' */
real32_T TAS_StrAngVel_degps_f32_Write;/* '<S8>/Unit Delay1' */
uint8_T TAS_SafetySts_NA_u8_Watch;     /* '<S6>/StateSupervisor' */
boolean_T TAS_TrqLossOfSignal_NA_bl_Watch;/* '<S2>/Logical Operator' */
boolean_T TAS_TrqAbnormal_NA_bl_Watch; /* '<S99>/Chart' */
boolean_T TAS_Vres_FD_NA_bl_Watch;     /* '<S67>/Relational Operator' */
boolean_T TAS_LossOfSignal_NA_bl_Watch;/* '<S6>/Relational Operator1' */
boolean_T TAS_AngCntOutLim_NA_bl_Watch;/* '<S4>/Relational Operator' */
boolean_T TAS_AngOutLim_NA_bl_Watch;   /* '<S4>/Logical Operator' */

/* Exported data definition */

/* Custom Memory Section */
#ifndef CAL_SEG
#define CAL_SEG                        __attribute__ ((section(".CalSection")))
#endif

/* Definition for custom storage class: CustomParameter */
volatile uint8_T TAS_AngOffset_Switch_NA_u8_Cal = 1U;/* Referenced by:
                                                      * '<S12>/Constant2'
                                                      * '<S17>/Constant2'
                                                      * '<S18>/Constant2'
                                                      * '<S19>/Constant2'
                                                      */
volatile real32_T TAS_AngOffset_deg_f32_Cal = 0.0F;/* Referenced by:
                                                    * '<S12>/Constant3'
                                                    * '<S17>/Constant3'
                                                    * '<S18>/Constant3'
                                                    * '<S19>/Constant3'
                                                    */
volatile real32_T TAS_CntUpLim_NA_f32_Cal = 100.0F;/* Referenced by:
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
volatile real32_T TAS_FaultCntLim_NA_f32_Cal = 50.0F;/* Referenced by: '<S6>/Constant1' */
volatile real32_T TAS_Kalman_Q_NA_f32_Cal = 0.01F;/* Referenced by: '<S7>/Constant1' */
volatile real32_T TAS_Kalman_R_NA_f32_Cal = 100.0F;/* Referenced by: '<S7>/Constant3' */
volatile real32_T TAS_SC_AngLim_deg_f32_Cal = 3.0F;/* Referenced by:
                                                    * '<S77>/Constant'
                                                    * '<S91>/Constant'
                                                    */
volatile real32_T TAS_TorsionBarStiff_NA_f32_Cal = 2.8F;/* Referenced by: '<S97>/Constant' */
volatile real32_T TAS_TrqFltTimeTh_Sec_f32_Cal = 0.02F;/* Referenced by: '<S99>/Constant2' */
volatile real32_T TAS_TrqOffset_Nm_f32_Cal = 0.0F;/* Referenced by: '<S97>/Constant4' */
volatile uint8_T TAS_TrqOffset_Switch_NA_u8_Cal = 0U;/* Referenced by: '<S97>/Constant2' */
volatile real32_T TAS_TrqSynchrCheckTh_Deg_f32_Cal = 1.0F;/* Referenced by: '<S99>/Thr' */

/* Constant parameters (default storage) */
const ConstP_SWC_TAS_T SWC_TAS_ConstP = {
  /* Expression: [0 22 7 29 14 36 21 6 28 13 35 20 5 27 12 34 19 4 26 11 33 18 3 25 10 32 17 2 24 9 31 16 1 23 8 30 15 0]
   * Referenced by: '<S57>/Interpolation Using Prelookup'
   */
  { 0.0, 22.0, 7.0, 29.0, 14.0, 36.0, 21.0, 6.0, 28.0, 13.0, 35.0, 20.0, 5.0,
    27.0, 12.0, 34.0, 19.0, 4.0, 26.0, 11.0, 33.0, 18.0, 3.0, 25.0, 10.0, 32.0,
    17.0, 2.0, 24.0, 9.0, 31.0, 16.0, 1.0, 23.0, 8.0, 30.0, 15.0, 0.0 },

  /* Computed Parameter: Prelookup_BreakpointsData
   * Referenced by: '<S57>/Prelookup'
   */
  { 0.0F, 1.0F, 2.0F, 3.0F, 4.0F, 5.0F, 6.0F, 7.0F, 8.0F, 9.0F, 10.0F, 11.0F,
    12.0F, 13.0F, 14.0F, 15.0F, 16.0F, 17.0F, 18.0F, 19.0F, 20.0F, 21.0F, 22.0F,
    23.0F, 24.0F, 25.0F, 26.0F, 27.0F, 28.0F, 29.0F, 30.0F, 31.0F, 32.0F, 33.0F,
    34.0F, 35.0F, 36.0F, 37.0F }
};

/* Block signals (default storage) */
B_SWC_TAS_T SWC_TAS_B;

/* Block states (default storage) */
DW_SWC_TAS_T SWC_TAS_DW;

/* Real-time model */
static RT_MODEL_SWC_TAS_T SWC_TAS_M_;
RT_MODEL_SWC_TAS_T *const SWC_TAS_M = &SWC_TAS_M_;
extern real32_T rt_modf(real32_T u0, real32_T u1);
int16_T plook_s16ff_binx(real32_T u, const real32_T bp[], uint32_T maxIndex,
  real32_T *fraction);
real_T intrp1d_s16dl_pw(int16_T bpIndex, real_T frac, const real_T table[]);
int16_T binsearch_s16f(real32_T u, const real32_T bp[], uint32_T startIndex,
  uint32_T maxIndex);
extern void SWC_TAS_IfActionSubsystem(real32_T rtu_RawAng, real32_T rtu_Error,
  real32_T *rty_StrAng_01Deg);
extern void SWC_TAS_IfActionSubsystem1(real32_T rtu_RawAng, real32_T rtu_Error,
  real32_T *rty_StrAng_Deg);
extern void SWC_TAS_Chart_Init(uint16_T *rty_SENT0, real32_T *rty_Vernier0,
  DW_Chart_SWC_TAS_T *localDW);
extern void SWC_TAS_Chart(uint16_T rtu_SENT, real32_T rtu_Vernier, boolean_T
  rtu_InitFlg, uint16_T *rty_SENT0, real32_T *rty_Vernier0, DW_Chart_SWC_TAS_T
  *localDW);
extern void SWC_TAS_Decrease(real32_T rtu_Idex_pre, real32_T *rty_Idex);
extern void SWC_TAS_Increase(real32_T rtu_Idex_pre, real32_T *rty_Idex);
extern void SWC_TAS_IfActionSubsystem_f(uint16_T rtu_SENT, uint16_T rtu_SENT_t_1,
  real32_T rtu_Idex_pre, real32_T *rty_Idex);
extern void SWC_TAS_IfActionSubsystem3(boolean_T *rty_SC_S1A, boolean_T
  *rty_SC_S2A, boolean_T *rty_SC_S3);

/* Forward declaration for local functions */
void SWC_TAS_enter_internal_during(void);
int16_T plook_s16ff_binx(real32_T u, const real32_T bp[], uint32_T maxIndex,
  real32_T *fraction)
{
  int16_T bpIndex;

  /* Prelookup - Index and Fraction
     Index Search method: 'binary'
     Extrapolation method: 'Linear'
     Use previous index: 'off'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
   */
  if (u <= bp[0U]) {
    bpIndex = 0;
    *fraction = (u - bp[0U]) / (bp[1U] - bp[0U]);
  } else if (u < bp[maxIndex]) {
    bpIndex = binsearch_s16f(u, bp, maxIndex >> 1U, maxIndex);
    *fraction = (u - bp[(uint32_T)bpIndex]) / (bp[bpIndex + 1U] - bp[(uint32_T)
      bpIndex]);
  } else {
    bpIndex = (int16_T)(maxIndex - 1U);
    *fraction = (u - bp[maxIndex - 1U]) / (bp[maxIndex] - bp[maxIndex - 1U]);
  }

  return bpIndex;
}

real_T intrp1d_s16dl_pw(int16_T bpIndex, real_T frac, const real_T table[])
{
  real_T yL_0d0;

  /* Column-major Interpolation 1-D
     Interpolation method: 'Linear point-slope'
     Use last breakpoint for index at or above upper limit: 'off'
     Overflow mode: 'portable wrapping'
   */
  yL_0d0 = table[(uint32_T)bpIndex];
  return ((table[bpIndex + 1U] - yL_0d0) * frac) + yL_0d0;
}

int16_T binsearch_s16f(real32_T u, const real32_T bp[], uint32_T startIndex,
  uint32_T maxIndex)
{
  uint32_T bpIdx;
  uint32_T iLeft;
  uint32_T iRght;

  /* Binary Search */
  bpIdx = startIndex;
  iLeft = 0U;
  iRght = maxIndex;
  while ((iRght - iLeft) > 1U) {
    if (u < bp[bpIdx]) {
      iRght = bpIdx;
    } else {
      iLeft = bpIdx;
    }

    bpIdx = ((iRght + iLeft) >> 1U);
  }

  return (int16_T)iLeft;
}

/*
 * Output and update for action system:
 *    '<S12>/If Action Subsystem'
 *    '<S17>/If Action Subsystem'
 *    '<S18>/If Action Subsystem'
 *    '<S19>/If Action Subsystem'
 */
void SWC_TAS_IfActionSubsystem(real32_T rtu_RawAng, real32_T rtu_Error, real32_T
  *rty_StrAng_01Deg)
{
  /* Switch: '<S15>/Switch' incorporates:
   *  Constant: '<S15>/Constant1'
   *  RelationalOperator: '<S15>/Relational Operator'
   *  Sum: '<S15>/Add'
   */
  if (rtu_RawAng <= rtu_Error) {
    *rty_StrAng_01Deg = rtu_RawAng + 1480.0F;
  } else {
    *rty_StrAng_01Deg = rtu_RawAng;
  }

  /* End of Switch: '<S15>/Switch' */
}

/*
 * Output and update for action system:
 *    '<S12>/If Action Subsystem1'
 *    '<S17>/If Action Subsystem1'
 *    '<S18>/If Action Subsystem1'
 *    '<S19>/If Action Subsystem1'
 */
void SWC_TAS_IfActionSubsystem1(real32_T rtu_RawAng, real32_T rtu_Error,
  real32_T *rty_StrAng_Deg)
{
  /* Switch: '<S16>/Switch' incorporates:
   *  Constant: '<S16>/Constant1'
   *  RelationalOperator: '<S16>/Relational Operator'
   *  Sum: '<S16>/Add'
   *  Sum: '<S16>/Add1'
   */
  if (rtu_RawAng > (rtu_Error + 1480.0F)) {
    *rty_StrAng_Deg = rtu_RawAng - 1480.0F;
  } else {
    *rty_StrAng_Deg = rtu_RawAng;
  }

  /* End of Switch: '<S16>/Switch' */
}

/*
 * System initialize for atomic system:
 *    '<S20>/Chart'
 *    '<S22>/Chart'
 */
void SWC_TAS_Chart_Init(uint16_T *rty_SENT0, real32_T *rty_Vernier0,
  DW_Chart_SWC_TAS_T *localDW)
{
  localDW->is_active_c5_SWC_TAS = 0U;
  localDW->is_c5_SWC_TAS = SWC_TAS_IN_NO_ACTIVE_CHILD;
  *rty_SENT0 = 0U;
  *rty_Vernier0 = 0.0F;
}

/*
 * Output and update for atomic system:
 *    '<S20>/Chart'
 *    '<S22>/Chart'
 */
void SWC_TAS_Chart(uint16_T rtu_SENT, real32_T rtu_Vernier, boolean_T
                   rtu_InitFlg, uint16_T *rty_SENT0, real32_T *rty_Vernier0,
                   DW_Chart_SWC_TAS_T *localDW)
{
  /* Chart: '<S20>/Chart' */
  if (localDW->is_active_c5_SWC_TAS == 0U) {
    localDW->is_active_c5_SWC_TAS = 1U;
    localDW->is_c5_SWC_TAS = SWC_TAS_IN_INIT;
    *rty_SENT0 = rtu_SENT;
    *rty_Vernier0 = rtu_Vernier;
  } else if (localDW->is_c5_SWC_TAS == SWC_TAS_IN_INIT) {
    localDW->is_c5_SWC_TAS = SWC_TAS_IN_Run;

    /* case IN_Run: */
  } else if (!rtu_InitFlg) {
    localDW->is_c5_SWC_TAS = SWC_TAS_IN_INIT;
    *rty_SENT0 = rtu_SENT;
    *rty_Vernier0 = rtu_Vernier;
  }

  /* End of Chart: '<S20>/Chart' */
}

/*
 * Output and update for action system:
 *    '<S30>/Decrease'
 *    '<S39>/Decrease'
 *    '<S48>/Decrease'
 */
void SWC_TAS_Decrease(real32_T rtu_Idex_pre, real32_T *rty_Idex)
{
  /* Sum: '<S35>/Add3' incorporates:
   *  Constant: '<S35>/Constant2'
   */
  *rty_Idex = rtu_Idex_pre - 1.0F;
}

/*
 * Output and update for action system:
 *    '<S30>/Increase'
 *    '<S39>/Increase'
 *    '<S48>/Increase'
 */
void SWC_TAS_Increase(real32_T rtu_Idex_pre, real32_T *rty_Idex)
{
  /* Sum: '<S36>/Add2' incorporates:
   *  Constant: '<S36>/Constant3'
   */
  *rty_Idex = rtu_Idex_pre + 1.0F;
}

/*
 * Output and update for action system:
 *    '<S20>/If Action Subsystem'
 *    '<S22>/If Action Subsystem'
 */
void SWC_TAS_IfActionSubsystem_f(uint16_T rtu_SENT, uint16_T rtu_SENT_t_1,
  real32_T rtu_Idex_pre, real32_T *rty_Idex)
{
  /* If: '<S30>/If' incorporates:
   *  Sum: '<S30>/Add2'
   */
  if ((rtu_SENT - rtu_SENT_t_1) > 0) {
    /* Outputs for IfAction SubSystem: '<S30>/Decrease' incorporates:
     *  ActionPort: '<S35>/Action Port'
     */
    SWC_TAS_Decrease(rtu_Idex_pre, rty_Idex);

    /* End of Outputs for SubSystem: '<S30>/Decrease' */
  } else {
    /* Outputs for IfAction SubSystem: '<S30>/Increase' incorporates:
     *  ActionPort: '<S36>/Action Port'
     */
    SWC_TAS_Increase(rtu_Idex_pre, rty_Idex);

    /* End of Outputs for SubSystem: '<S30>/Increase' */
  }

  /* End of If: '<S30>/If' */
}

/*
 * Output and update for action system:
 *    '<S80>/If Action Subsystem3'
 *    '<S80>/If Action Subsystem5'
 */
void SWC_TAS_IfActionSubsystem3(boolean_T *rty_SC_S1A, boolean_T *rty_SC_S2A,
  boolean_T *rty_SC_S3)
{
  /* SignalConversion generated from: '<S88>/SC_S1A' incorporates:
   *  Constant: '<S88>/Constant'
   */
  *rty_SC_S1A = false;

  /* SignalConversion generated from: '<S88>/SC_S2A' incorporates:
   *  Constant: '<S88>/Constant1'
   */
  *rty_SC_S2A = false;

  /* SignalConversion generated from: '<S88>/SC_S3' incorporates:
   *  Constant: '<S88>/Constant2'
   */
  *rty_SC_S3 = false;
}

real32_T rt_modf(real32_T u0, real32_T u1)
{
  real32_T q;
  real32_T y;
  boolean_T yEq;
  y = u0;
  if (u1 == 0.0F) {
    if (u0 == 0.0F) {
      y = u1;
    }
  } else if (u0 == 0.0F) {
    y = 0.0F / u1;
  } else {
    y = fmodf(u0, u1);
    yEq = (y == 0.0F);
    if ((!yEq) && (u1 > floorf(u1))) {
      q = fabsf(u0 / u1);
      yEq = (fabsf(q - floorf(q + 0.5F)) <= (FLT_EPSILON * q));
    }

    if (yEq) {
      y = 0.0F;
    } else if ((u0 < 0.0F) != (u1 < 0.0F)) {
      y += u1;
    }
  }

  return y;
}

/* Function for Chart: '<S6>/StateSupervisor' */
void SWC_TAS_enter_internal_during(void)
{
  if (!TAS_Vres_FD_NA_bl_Watch) {
    if (SWC_TAS_B.LogicalOperator) {
      SWC_TAS_DW.ec_af_init++;
      SWC_TAS_DW.Cnt = 0U;
      SWC_TAS_B.Vernier_Init = 1U;
      SWC_TAS_B.AngFollowerChoose = 0U;
    } else {
      SWC_TAS_DW.Cnt = 1U;
      SWC_TAS_B.Vernier_Init = 1U;
      SWC_TAS_B.AngFollowerChoose = 4U;
    }
  } else {
    SWC_TAS_DW.ec_af_init++;
    SWC_TAS_DW.Cnt = 0U;
    SWC_TAS_B.Vernier_Init = 0U;
    SWC_TAS_B.AngFollowerChoose = 0U;
  }
}

/* Model step function */
void TMT_Rnbl_TAS_StrAng(void)
{
  int32_T rtb_MatrixMultiply;
  real32_T rtb_Add1_h;
  real32_T rtb_Add_co;
  real32_T rtb_Divide_l;
  real32_T rtb_Divide_mc;
  real32_T rtb_Product_n;
  real32_T rtb_Sum3;
  real32_T rtb_Switch_j;
  real32_T rtb_vd_pos;
  real32_T tmp;
  int16_T rtb_Prelookup_o1;
  uint16_T tmp_0;
  boolean_T guard1 = false;
  boolean_T guard2 = false;
  boolean_T rtb_LogicalOperator_m;
  boolean_T rtb_Merge1_d;
  boolean_T rtb_Merge2_j;
  boolean_T rtb_RelationalOperator1_n;
  boolean_T rtb_RelationalOperator2;
  boolean_T rtb_RelationalOperator_j;
  boolean_T tmp_1;
  boolean_T tmp_2;

  /* RootInportFunctionCallGenerator generated from: '<Root>/TMT_Rnbl_TAS_StrAng' incorporates:
   *  SubSystem: '<Root>/Rnbl_TAS_StrAng'
   */
  /* Constant: '<S7>/Constant1' */
  rtb_Product_n = TAS_Kalman_Q_NA_f32_Cal * 1024.0F;
  rtb_Divide_l = fabsf(rtb_Product_n);
  if (rtb_Divide_l < 8.388608E+6F) {
    if (rtb_Divide_l >= 0.5F) {
      rtb_Product_n = floorf(rtb_Product_n + 0.5F);
    } else {
      rtb_Product_n = 0.0F;
    }
  }

  if (rtb_Product_n < 65536.0F) {
    if (rtb_Product_n >= 0.0F) {
      tmp_0 = (uint16_T)rtb_Product_n;
    } else {
      tmp_0 = 0U;
    }
  } else {
    tmp_0 = MAX_uint16_T;
  }

  /* End of Constant: '<S7>/Constant1' */

  /* Sum: '<S7>/Sum3' incorporates:
   *  UnitDelay: '<S7>/Unit Delay1'
   */
  rtb_Sum3 = (((real32_T)tmp_0) * 0.0009765625F) + SWC_TAS_DW.UnitDelay1_DSTATE;

  /* Constant: '<S7>/Constant3' */
  rtb_Product_n = TAS_Kalman_R_NA_f32_Cal * 128.0F;
  rtb_Divide_l = fabsf(rtb_Product_n);
  if (rtb_Divide_l < 8.388608E+6F) {
    if (rtb_Divide_l >= 0.5F) {
      rtb_Product_n = floorf(rtb_Product_n + 0.5F);
    } else {
      rtb_Product_n = 0.0F;
    }
  }

  if (rtb_Product_n < 65536.0F) {
    if (rtb_Product_n >= 0.0F) {
      tmp_0 = (uint16_T)rtb_Product_n;
    } else {
      tmp_0 = 0U;
    }
  } else {
    tmp_0 = MAX_uint16_T;
  }

  /* End of Constant: '<S7>/Constant3' */

  /* Product: '<S7>/Divide' incorporates:
   *  Sum: '<S7>/Sum5'
   */
  rtb_Divide_l = rtb_Sum3 / ((((real32_T)tmp_0) * 0.0078125F) + rtb_Sum3);

  /* Switch: '<S17>/Switch' incorporates:
   *  Constant: '<S17>/Constant2'
   *  Constant: '<S17>/Constant3'
   *  Inport: '<Root>/TAS_AngOffset_deg_f32_Read'
   *
   * Block description for '<S17>/Constant3':
   *  ???ии??и░?ив?
   */
  if (TAS_AngOffset_Switch_NA_u8_Cal > 0) {
    tmp = TAS_AngOffset_deg_f32_Read;
  } else {
    tmp = TAS_AngOffset_deg_f32_Cal;
  }

  /* End of Switch: '<S17>/Switch' */

  /* Product: '<S33>/Product' incorporates:
   *  Constant: '<S33>/Constant1'
   *  Constant: '<S33>/Constant4'
   *  Constant: '<S33>/Constant5'
   *  Inport: '<Root>/TAS_SENT1A_NA_u16_Read'
   *  Product: '<S33>/Divide'
   *  Sum: '<S33>/Add'
   */
  rtb_Product_n = ((((real32_T)TAS_SENT1A_NA_u16_Read) - 1.0F) / 4092.0F) *
    40.0F;

  /* Product: '<S69>/Product' incorporates:
   *  Constant: '<S69>/Constant'
   *  Constant: '<S69>/Constant1'
   *  Inport: '<Root>/TAS_SENT1A_NA_u16_Read'
   *  Sum: '<S69>/Add'
   */
  rtb_vd_pos = (((real32_T)TAS_SENT1A_NA_u16_Read) - 1.0F) * 2.0F;

  /* UnaryMinus: '<S70>/Unary Minus' incorporates:
   *  Constant: '<S70>/Constant'
   *  Constant: '<S70>/Constant1'
   *  Inport: '<Root>/TAS_SENT2A_NA_u16_Read'
   *  Product: '<S70>/Product'
   *  Sum: '<S70>/Add'
   */
  rtb_Switch_j = -((((real32_T)TAS_SENT2A_NA_u16_Read) - 4093.0F) * 2.0F);

  /* Sum: '<S56>/Add' */
  rtb_Add_co = rtb_vd_pos - rtb_Switch_j;

  /* If: '<S56>/If' incorporates:
   *  Constant: '<S59>/Constant'
   *  Constant: '<S60>/Constant'
   *  Sum: '<S59>/Add'
   *  Sum: '<S60>/Add'
   *  UnaryMinus: '<S70>/Unary Minus'
   */
  if (rtb_Add_co < -4092.0F) {
    /* Outputs for IfAction SubSystem: '<S56>/If Action Subsystem' incorporates:
     *  ActionPort: '<S59>/Action Port'
     */
    rtb_Switch_j += 8184.0F;

    /* End of Outputs for SubSystem: '<S56>/If Action Subsystem' */
  } else if (rtb_Add_co > 4092.0F) {
    /* Outputs for IfAction SubSystem: '<S56>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S60>/Action Port'
     */
    rtb_Switch_j -= 8184.0F;

    /* End of Outputs for SubSystem: '<S56>/If Action Subsystem1' */
  }

  /* End of If: '<S56>/If' */

  /* Sum: '<S56>/Add1' */
  rtb_Add1_h = rtb_vd_pos + rtb_Switch_j;

  /* If: '<S56>/If1' */
  if (rtb_Add1_h < 0.0F) {
    /* Outputs for IfAction SubSystem: '<S56>/If Action Subsystem3' incorporates:
     *  ActionPort: '<S62>/Action Port'
     */
    /* Sum: '<S62>/Add' incorporates:
     *  Constant: '<S62>/Constant'
     */
    rtb_Add1_h += 16368.0F;

    /* End of Outputs for SubSystem: '<S56>/If Action Subsystem3' */
  } else if (rtb_Add1_h > 16368.0F) {
    /* Outputs for IfAction SubSystem: '<S56>/If Action Subsystem4' incorporates:
     *  ActionPort: '<S63>/Action Port'
     */
    /* Sum: '<S63>/Add' incorporates:
     *  Constant: '<S63>/Constant'
     */
    rtb_Add1_h -= 16368.0F;

    /* End of Outputs for SubSystem: '<S56>/If Action Subsystem4' */
  }

  /* End of If: '<S56>/If1' */

  /* Sum: '<S57>/Add2' incorporates:
   *  Constant: '<S58>/Constant'
   *  Constant: '<S71>/Constant'
   *  Inport: '<Root>/TAS_SENT_ANG_NA_u16_Read'
   *  Product: '<S58>/Product'
   *  Sum: '<S71>/Add'
   */
  rtb_Add_co = rtb_Add1_h - ((((real32_T)TAS_SENT_ANG_NA_u16_Read) - 1.0F) *
    29.6289062F);

  /* If: '<S57>/If' incorporates:
   *  Constant: '<S65>/Constant'
   *  Sum: '<S65>/Add2'
   */
  if (rtb_Add_co < 0.0F) {
    /* Outputs for IfAction SubSystem: '<S57>/If Action Subsystem' incorporates:
     *  ActionPort: '<S65>/Action Port'
     */
    rtb_Add_co += 121122.0F;

    /* End of Outputs for SubSystem: '<S57>/If Action Subsystem' */
  }

  /* End of If: '<S57>/If' */

  /* Rounding: '<S57>/Floor' incorporates:
   *  Constant: '<S57>/Constant1'
   *  Constant: '<S57>/Constant2'
   *  Product: '<S57>/Product1'
   *  Sum: '<S57>/vd_pos'
   */
  rtb_MatrixMultiply = (int32_T)floorf((rtb_Add_co + 1637.0F) * 0.000305473804F);

  /* PreLookup: '<S57>/Prelookup' */
  rtb_Prelookup_o1 = plook_s16ff_binx((real32_T)rtb_MatrixMultiply,
    SWC_TAS_ConstP.Prelookup_BreakpointsData, 37U, &rtb_vd_pos);

  /* Interpolation_n-D: '<S57>/Interpolation Using Prelookup' */
  if (rtb_vd_pos < 0.0F) {
    rtb_vd_pos = 0.0F;
  } else if (rtb_vd_pos > 1.0F) {
    rtb_vd_pos = 1.0F;
  }

  /* Product: '<S57>/Divide' incorporates:
   *  Constant: '<S57>/Constant4'
   *  Constant: '<S57>/Constant5'
   *  Interpolation_n-D: '<S57>/Interpolation Using Prelookup'
   *  Product: '<S57>/Product2'
   *  Sum: '<S57>/Add1'
   *  Sum: '<S57>/Add3'
   */
  rtb_Divide_mc = ((((real32_T)(intrp1d_s16dl_pw(rtb_Prelookup_o1, rtb_vd_pos,
    SWC_TAS_ConstP.InterpolationUsingPrelookup_Tab) * 16368.0)) + rtb_Add1_h) -
                   302808.0F) / 409.2F;

  /* Switch: '<S32>/Switch1' incorporates:
   *  UnitDelay: '<S32>/Unit Delay3'
   */
  if (SWC_TAS_DW.UnitDelay3_DSTATE_ht > 0) {
    rtb_Add1_h = rtb_Product_n;
  } else {
    rtb_Add1_h = rtb_Divide_mc;
  }

  /* End of Switch: '<S32>/Switch1' */

  /* Switch: '<S32>/Switch2' incorporates:
   *  UnitDelay: '<S32>/Unit Delay4'
   */
  if (SWC_TAS_DW.UnitDelay4_DSTATE_j <= 0) {
    SWC_TAS_DW.UnitDelay5_DSTATE = rtb_Divide_mc;
  }

  /* End of Switch: '<S32>/Switch2' */

  /* If: '<S20>/If' incorporates:
   *  Abs: '<S20>/Abs'
   *  Constant: '<S20>/Constant7'
   *  Inport: '<Root>/TAS_SENT1A_NA_u16_Read'
   *  Inport: '<S31>/Idex_pre'
   *  Sum: '<S20>/Add1'
   *  Switch: '<S20>/Switch'
   *  UnitDelay: '<S20>/Unit Delay1'
   *  UnitDelay: '<S20>/Unit Delay3'
   *  UnitDelay: '<S6>/Unit Delay1'
   */
  if (fabsf(rtb_Add1_h - SWC_TAS_DW.UnitDelay5_DSTATE) > 20.0F) {
    /* Switch: '<S20>/Switch' incorporates:
     *  Constant: '<S20>/Constant7'
     *  UnitDelay: '<S20>/Unit Delay1'
     *  UnitDelay: '<S6>/Unit Delay1'
     */
    if (SWC_TAS_DW.UnitDelay1_DSTATE_b) {
      rtb_Add1_h = SWC_TAS_DW.UnitDelay1_DSTATE_a;
    } else {
      rtb_Add1_h = 0.0F;
    }

    /* Outputs for IfAction SubSystem: '<S20>/If Action Subsystem' incorporates:
     *  ActionPort: '<S30>/Action Port'
     */
    SWC_TAS_IfActionSubsystem_f(TAS_SENT1A_NA_u16_Read,
      SWC_TAS_DW.UnitDelay3_DSTATE_i, rtb_Add1_h,
      &SWC_TAS_DW.UnitDelay1_DSTATE_a);

    /* End of Outputs for SubSystem: '<S20>/If Action Subsystem' */
  } else if (!SWC_TAS_DW.UnitDelay1_DSTATE_b) {
    /* Outputs for IfAction SubSystem: '<S20>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S31>/Action Port'
     */
    SWC_TAS_DW.UnitDelay1_DSTATE_a = 0.0F;

    /* End of Outputs for SubSystem: '<S20>/If Action Subsystem1' */
  }

  /* End of If: '<S20>/If' */

  /* Chart: '<S20>/Chart' incorporates:
   *  Inport: '<Root>/TAS_SENT1A_NA_u16_Read'
   *  UnitDelay: '<S6>/Unit Delay1'
   */
  SWC_TAS_Chart(TAS_SENT1A_NA_u16_Read, rtb_Divide_mc,
                SWC_TAS_DW.UnitDelay1_DSTATE_b, &SWC_TAS_B.SENT0_l,
                &SWC_TAS_B.Vernier0_g, &SWC_TAS_DW.sf_Chart);

  /* Math: '<S37>/Mod' incorporates:
   *  Constant: '<S34>/Constant3'
   *  Constant: '<S34>/Constant6'
   *  Constant: '<S34>/Constant8'
   *  Constant: '<S37>/Constant'
   *  Constant: '<S37>/Constant1'
   *  Inport: '<Root>/TAS_SENT1A_NA_u16_Read'
   *  Product: '<S34>/Divide1'
   *  Product: '<S34>/Product1'
   *  Product: '<S34>/Product2'
   *  Sum: '<S34>/Add2'
   *  Sum: '<S34>/Add3'
   *  Sum: '<S34>/Add4'
   *  Sum: '<S37>/Add'
   *  UnitDelay: '<S20>/Unit Delay1'
   */
  rtb_vd_pos = rt_modf(((((((SWC_TAS_DW.UnitDelay1_DSTATE_a * 4092.0F) +
    ((real32_T)TAS_SENT1A_NA_u16_Read)) - ((real32_T)SWC_TAS_B.SENT0_l)) /
    4092.0F) * 40.0F) + SWC_TAS_B.Vernier0_g) + 740.0F, 1480.0F);

  /* If: '<S17>/If' incorporates:
   *  Constant: '<S17>/Constant1'
   *  Constant: '<S37>/Constant'
   *  RelationalOperator: '<S17>/Relational Operator'
   *  Sum: '<S17>/Add'
   *  Sum: '<S17>/Add1'
   *  Sum: '<S17>/Subtract'
   *  Sum: '<S37>/Add1'
   */
  if ((tmp + 740.0F) > 740.0F) {
    /* Outputs for IfAction SubSystem: '<S17>/If Action Subsystem' incorporates:
     *  ActionPort: '<S23>/Action Port'
     */
    SWC_TAS_IfActionSubsystem((rtb_vd_pos - 740.0F) + 740.0F, (tmp + 740.0F) -
      740.0F, &rtb_vd_pos);

    /* End of Outputs for SubSystem: '<S17>/If Action Subsystem' */
  } else {
    /* Outputs for IfAction SubSystem: '<S17>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S24>/Action Port'
     */
    SWC_TAS_IfActionSubsystem1((rtb_vd_pos - 740.0F) + 740.0F, (tmp + 740.0F) -
      740.0F, &rtb_vd_pos);

    /* End of Outputs for SubSystem: '<S17>/If Action Subsystem1' */
  }

  /* End of If: '<S17>/If' */

  /* Gain: '<S17>/Gain' incorporates:
   *  Constant: '<S17>/Constant1'
   *  Sum: '<S17>/Add1'
   *  Sum: '<S17>/Add2'
   */
  TAS_SENT1A_Follower_Deg_f32_Watch = -(rtb_vd_pos - (tmp + 740.0F));

  /* Switch: '<S18>/Switch' incorporates:
   *  Constant: '<S18>/Constant2'
   *  Constant: '<S18>/Constant3'
   *  Inport: '<Root>/TAS_AngOffset_deg_f32_Read'
   *
   * Block description for '<S18>/Constant3':
   *  ???ии??и░?ив?
   */
  if (TAS_AngOffset_Switch_NA_u8_Cal > 0) {
    tmp = TAS_AngOffset_deg_f32_Read;
  } else {
    tmp = TAS_AngOffset_deg_f32_Cal;
  }

  /* End of Switch: '<S18>/Switch' */

  /* Product: '<S42>/Product' incorporates:
   *  Constant: '<S21>/Constant'
   *  Constant: '<S42>/Constant1'
   *  Constant: '<S42>/Constant4'
   *  Constant: '<S42>/Constant5'
   *  Inport: '<Root>/TAS_SENT2A_NA_u16_Read'
   *  Product: '<S42>/Divide'
   *  Sum: '<S21>/Add'
   *  Sum: '<S42>/Add'
   */
  rtb_vd_pos = (((4094.0F - ((real32_T)TAS_SENT2A_NA_u16_Read)) - 1.0F) /
                4092.0F) * 40.0F;

  /* Switch: '<S21>/Switch' incorporates:
   *  Constant: '<S21>/Constant7'
   *  UnitDelay: '<S21>/Unit Delay1'
   *  UnitDelay: '<S6>/Unit Delay1'
   */
  if (SWC_TAS_DW.UnitDelay1_DSTATE_b) {
    rtb_Switch_j = SWC_TAS_DW.UnitDelay1_DSTATE_k;
  } else {
    rtb_Switch_j = 0.0F;
  }

  /* End of Switch: '<S21>/Switch' */

  /* Switch: '<S41>/Switch1' incorporates:
   *  UnitDelay: '<S41>/Unit Delay3'
   */
  if (SWC_TAS_DW.UnitDelay3_DSTATE_c > 0) {
    rtb_Add1_h = rtb_vd_pos;
  } else {
    rtb_Add1_h = rtb_Divide_mc;
  }

  /* End of Switch: '<S41>/Switch1' */

  /* Switch: '<S41>/Switch2' incorporates:
   *  UnitDelay: '<S41>/Unit Delay4'
   */
  if (SWC_TAS_DW.UnitDelay4_DSTATE_g <= 0) {
    SWC_TAS_DW.UnitDelay5_DSTATE_l = rtb_Divide_mc;
  }

  /* End of Switch: '<S41>/Switch2' */

  /* If: '<S21>/If' incorporates:
   *  Abs: '<S21>/Abs'
   *  Inport: '<S40>/Idex_pre'
   *  Sum: '<S21>/Add1'
   *  UnitDelay: '<S21>/Unit Delay1'
   */
  if (fabsf(rtb_Add1_h - SWC_TAS_DW.UnitDelay5_DSTATE_l) > 20.0F) {
    /* Outputs for IfAction SubSystem: '<S21>/If Action Subsystem' incorporates:
     *  ActionPort: '<S39>/Action Port'
     */
    /* If: '<S39>/If' incorporates:
     *  Constant: '<S21>/Constant'
     *  Inport: '<Root>/TAS_SENT2A_NA_u16_Read'
     *  Sum: '<S21>/Add'
     *  Sum: '<S39>/Add2'
     *  UnitDelay: '<S21>/Unit Delay1'
     *  UnitDelay: '<S21>/Unit Delay3'
     */
    if (((4094.0F - ((real32_T)TAS_SENT2A_NA_u16_Read)) -
         SWC_TAS_DW.UnitDelay3_DSTATE) > 0.0F) {
      /* Outputs for IfAction SubSystem: '<S39>/Decrease' incorporates:
       *  ActionPort: '<S44>/Action Port'
       */
      SWC_TAS_Decrease(rtb_Switch_j, &SWC_TAS_DW.UnitDelay1_DSTATE_k);

      /* End of Outputs for SubSystem: '<S39>/Decrease' */
    } else {
      /* Outputs for IfAction SubSystem: '<S39>/Increase' incorporates:
       *  ActionPort: '<S45>/Action Port'
       */
      SWC_TAS_Increase(rtb_Switch_j, &SWC_TAS_DW.UnitDelay1_DSTATE_k);

      /* End of Outputs for SubSystem: '<S39>/Increase' */
    }

    /* End of If: '<S39>/If' */
    /* End of Outputs for SubSystem: '<S21>/If Action Subsystem' */
  } else {
    /* Outputs for IfAction SubSystem: '<S21>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S40>/Action Port'
     */
    SWC_TAS_DW.UnitDelay1_DSTATE_k = rtb_Switch_j;

    /* End of Outputs for SubSystem: '<S21>/If Action Subsystem1' */
  }

  /* End of If: '<S21>/If' */

  /* Chart: '<S21>/Chart' incorporates:
   *  Constant: '<S21>/Constant'
   *  Inport: '<Root>/TAS_SENT2A_NA_u16_Read'
   *  Sum: '<S21>/Add'
   *  UnitDelay: '<S6>/Unit Delay1'
   */
  if (SWC_TAS_DW.is_active_c6_SWC_TAS == 0U) {
    SWC_TAS_DW.is_active_c6_SWC_TAS = 1U;
    SWC_TAS_DW.is_c6_SWC_TAS = SWC_TAS_IN_INIT_i;
    SWC_TAS_B.SENT0 = 4094.0F - ((real32_T)TAS_SENT2A_NA_u16_Read);
    SWC_TAS_B.Vernier0_m = rtb_Divide_mc;
  } else if (SWC_TAS_DW.is_c6_SWC_TAS == 1) {
    SWC_TAS_DW.is_c6_SWC_TAS = SWC_TAS_IN_Run_n;

    /* case IN_Run: */
  } else if (!SWC_TAS_DW.UnitDelay1_DSTATE_b) {
    SWC_TAS_DW.is_c6_SWC_TAS = SWC_TAS_IN_INIT_i;
    SWC_TAS_B.SENT0 = 4094.0F - ((real32_T)TAS_SENT2A_NA_u16_Read);
    SWC_TAS_B.Vernier0_m = rtb_Divide_mc;
  }

  /* End of Chart: '<S21>/Chart' */

  /* Math: '<S46>/Mod' incorporates:
   *  Constant: '<S21>/Constant'
   *  Constant: '<S43>/Constant3'
   *  Constant: '<S43>/Constant6'
   *  Constant: '<S43>/Constant8'
   *  Constant: '<S46>/Constant'
   *  Constant: '<S46>/Constant1'
   *  Inport: '<Root>/TAS_SENT2A_NA_u16_Read'
   *  Product: '<S43>/Divide1'
   *  Product: '<S43>/Product1'
   *  Product: '<S43>/Product2'
   *  Sum: '<S21>/Add'
   *  Sum: '<S43>/Add2'
   *  Sum: '<S43>/Add3'
   *  Sum: '<S43>/Add4'
   *  Sum: '<S46>/Add'
   *  UnitDelay: '<S21>/Unit Delay1'
   */
  rtb_Add1_h = rt_modf(((((((SWC_TAS_DW.UnitDelay1_DSTATE_k * 4092.0F) +
    (4094.0F - ((real32_T)TAS_SENT2A_NA_u16_Read))) - SWC_TAS_B.SENT0) / 4092.0F)
    * 40.0F) + SWC_TAS_B.Vernier0_m) + 740.0F, 1480.0F);

  /* If: '<S18>/If' incorporates:
   *  Constant: '<S18>/Constant1'
   *  Constant: '<S46>/Constant'
   *  RelationalOperator: '<S18>/Relational Operator'
   *  Sum: '<S18>/Add'
   *  Sum: '<S18>/Add1'
   *  Sum: '<S18>/Subtract'
   *  Sum: '<S46>/Add1'
   */
  if ((tmp + 740.0F) > 740.0F) {
    /* Outputs for IfAction SubSystem: '<S18>/If Action Subsystem' incorporates:
     *  ActionPort: '<S25>/Action Port'
     */
    SWC_TAS_IfActionSubsystem((rtb_Add1_h - 740.0F) + 740.0F, (tmp + 740.0F) -
      740.0F, &rtb_Add1_h);

    /* End of Outputs for SubSystem: '<S18>/If Action Subsystem' */
  } else {
    /* Outputs for IfAction SubSystem: '<S18>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S26>/Action Port'
     */
    SWC_TAS_IfActionSubsystem1((rtb_Add1_h - 740.0F) + 740.0F, (tmp + 740.0F) -
      740.0F, &rtb_Add1_h);

    /* End of Outputs for SubSystem: '<S18>/If Action Subsystem1' */
  }

  /* End of If: '<S18>/If' */

  /* Gain: '<S18>/Gain' incorporates:
   *  Constant: '<S18>/Constant1'
   *  Sum: '<S18>/Add1'
   *  Sum: '<S18>/Add2'
   */
  TAS_SENT2A_Follower_Deg_f32_Watch = -(rtb_Add1_h - (tmp + 740.0F));

  /* Switch: '<S19>/Switch' incorporates:
   *  Constant: '<S19>/Constant2'
   *  Constant: '<S19>/Constant3'
   *  Inport: '<Root>/TAS_AngOffset_deg_f32_Read'
   *
   * Block description for '<S19>/Constant3':
   *  ???ии??и░?ив?
   */
  if (TAS_AngOffset_Switch_NA_u8_Cal > 0) {
    tmp = TAS_AngOffset_deg_f32_Read;
  } else {
    tmp = TAS_AngOffset_deg_f32_Cal;
  }

  /* End of Switch: '<S19>/Switch' */

  /* Product: '<S51>/Product' incorporates:
   *  Constant: '<S51>/Constant1'
   *  Constant: '<S51>/Constant4'
   *  Constant: '<S51>/Constant5'
   *  Inport: '<Root>/TAS_SENT_ANG_NA_u16_Read'
   *  Product: '<S51>/Divide'
   *  Sum: '<S51>/Add'
   */
  rtb_Switch_j = ((((real32_T)TAS_SENT_ANG_NA_u16_Read) - 1.0F) / 4086.0F) *
    296.0F;

  /* Switch: '<S50>/Switch1' incorporates:
   *  UnitDelay: '<S50>/Unit Delay3'
   */
  if (SWC_TAS_DW.UnitDelay3_DSTATE_c1 > 0) {
    rtb_Add1_h = rtb_Switch_j;
  } else {
    rtb_Add1_h = rtb_Divide_mc;
  }

  /* End of Switch: '<S50>/Switch1' */

  /* Switch: '<S50>/Switch2' incorporates:
   *  UnitDelay: '<S50>/Unit Delay4'
   */
  if (SWC_TAS_DW.UnitDelay4_DSTATE_k <= 0) {
    SWC_TAS_DW.UnitDelay5_DSTATE_k = rtb_Divide_mc;
  }

  /* End of Switch: '<S50>/Switch2' */

  /* If: '<S22>/If' incorporates:
   *  Abs: '<S22>/Abs'
   *  Constant: '<S22>/Constant7'
   *  Inport: '<Root>/TAS_SENT_ANG_NA_u16_Read'
   *  Inport: '<S49>/Idex_pre'
   *  Sum: '<S22>/Add1'
   *  Switch: '<S22>/Switch'
   *  UnitDelay: '<S22>/Unit Delay1'
   *  UnitDelay: '<S22>/Unit Delay3'
   *  UnitDelay: '<S6>/Unit Delay1'
   */
  if (fabsf(rtb_Add1_h - SWC_TAS_DW.UnitDelay5_DSTATE_k) > 148.0F) {
    /* Switch: '<S22>/Switch' incorporates:
     *  Constant: '<S22>/Constant7'
     *  UnitDelay: '<S22>/Unit Delay1'
     *  UnitDelay: '<S6>/Unit Delay1'
     */
    if (SWC_TAS_DW.UnitDelay1_DSTATE_b) {
      rtb_Add1_h = SWC_TAS_DW.UnitDelay1_DSTATE_h;
    } else {
      rtb_Add1_h = 0.0F;
    }

    /* Outputs for IfAction SubSystem: '<S22>/If Action Subsystem' incorporates:
     *  ActionPort: '<S48>/Action Port'
     */
    SWC_TAS_IfActionSubsystem_f(TAS_SENT_ANG_NA_u16_Read,
      SWC_TAS_DW.UnitDelay3_DSTATE_e, rtb_Add1_h,
      &SWC_TAS_DW.UnitDelay1_DSTATE_h);

    /* End of Outputs for SubSystem: '<S22>/If Action Subsystem' */
  } else if (!SWC_TAS_DW.UnitDelay1_DSTATE_b) {
    /* Outputs for IfAction SubSystem: '<S22>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S49>/Action Port'
     */
    SWC_TAS_DW.UnitDelay1_DSTATE_h = 0.0F;

    /* End of Outputs for SubSystem: '<S22>/If Action Subsystem1' */
  }

  /* End of If: '<S22>/If' */

  /* Chart: '<S22>/Chart' incorporates:
   *  Inport: '<Root>/TAS_SENT_ANG_NA_u16_Read'
   *  UnitDelay: '<S6>/Unit Delay1'
   */
  SWC_TAS_Chart(TAS_SENT_ANG_NA_u16_Read, rtb_Divide_mc,
                SWC_TAS_DW.UnitDelay1_DSTATE_b, &SWC_TAS_B.SENT0_i,
                &SWC_TAS_B.Vernier0, &SWC_TAS_DW.sf_Chart_h);

  /* Math: '<S55>/Mod' incorporates:
   *  Constant: '<S52>/Constant3'
   *  Constant: '<S52>/Constant6'
   *  Constant: '<S52>/Constant8'
   *  Constant: '<S55>/Constant'
   *  Constant: '<S55>/Constant1'
   *  Inport: '<Root>/TAS_SENT_ANG_NA_u16_Read'
   *  Product: '<S52>/Divide1'
   *  Product: '<S52>/Product1'
   *  Product: '<S52>/Product2'
   *  Sum: '<S52>/Add2'
   *  Sum: '<S52>/Add3'
   *  Sum: '<S52>/Add4'
   *  Sum: '<S55>/Add'
   *  UnitDelay: '<S22>/Unit Delay1'
   */
  rtb_Add1_h = rt_modf(((((((SWC_TAS_DW.UnitDelay1_DSTATE_h * 4087.0F) +
    ((real32_T)TAS_SENT_ANG_NA_u16_Read)) - ((real32_T)SWC_TAS_B.SENT0_i)) /
    4087.0F) * 296.0F) + SWC_TAS_B.Vernier0) + 740.0F, 1480.0F);

  /* If: '<S19>/If' incorporates:
   *  Constant: '<S19>/Constant1'
   *  Constant: '<S55>/Constant'
   *  RelationalOperator: '<S19>/Relational Operator'
   *  Sum: '<S19>/Add'
   *  Sum: '<S19>/Add1'
   *  Sum: '<S19>/Subtract'
   *  Sum: '<S55>/Add1'
   */
  if ((tmp + 740.0F) > 740.0F) {
    /* Outputs for IfAction SubSystem: '<S19>/If Action Subsystem' incorporates:
     *  ActionPort: '<S27>/Action Port'
     */
    SWC_TAS_IfActionSubsystem((rtb_Add1_h - 740.0F) + 740.0F, (tmp + 740.0F) -
      740.0F, &rtb_Add1_h);

    /* End of Outputs for SubSystem: '<S19>/If Action Subsystem' */
  } else {
    /* Outputs for IfAction SubSystem: '<S19>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S28>/Action Port'
     */
    SWC_TAS_IfActionSubsystem1((rtb_Add1_h - 740.0F) + 740.0F, (tmp + 740.0F) -
      740.0F, &rtb_Add1_h);

    /* End of Outputs for SubSystem: '<S19>/If Action Subsystem1' */
  }

  /* End of If: '<S19>/If' */

  /* Gain: '<S19>/Gain' incorporates:
   *  Constant: '<S19>/Constant1'
   *  Sum: '<S19>/Add1'
   *  Sum: '<S19>/Add2'
   */
  TAS_SENT_ANG_Follower_Deg_f32_Watch = -(rtb_Add1_h - (tmp + 740.0F));

  /* Switch: '<S12>/Switch' incorporates:
   *  Constant: '<S12>/Constant2'
   *  Constant: '<S12>/Constant3'
   *  Inport: '<Root>/TAS_AngOffset_deg_f32_Read'
   *
   * Block description for '<S12>/Constant3':
   *  ???ии??и░?ив?
   */
  if (TAS_AngOffset_Switch_NA_u8_Cal > 0) {
    tmp = TAS_AngOffset_deg_f32_Read;
  } else {
    tmp = TAS_AngOffset_deg_f32_Cal;
  }

  /* End of Switch: '<S12>/Switch' */

  /* If: '<S12>/If' incorporates:
   *  Constant: '<S12>/Constant1'
   *  RelationalOperator: '<S12>/Relational Operator'
   *  Sum: '<S12>/Add'
   *  Sum: '<S12>/Add1'
   *  Sum: '<S12>/Subtract'
   */
  if ((tmp + 740.0F) > 740.0F) {
    /* Outputs for IfAction SubSystem: '<S12>/If Action Subsystem' incorporates:
     *  ActionPort: '<S15>/Action Port'
     */
    SWC_TAS_IfActionSubsystem(rtb_Divide_mc + 740.0F, (tmp + 740.0F) - 740.0F,
      &rtb_Add1_h);

    /* End of Outputs for SubSystem: '<S12>/If Action Subsystem' */
  } else {
    /* Outputs for IfAction SubSystem: '<S12>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S16>/Action Port'
     */
    SWC_TAS_IfActionSubsystem1(rtb_Divide_mc + 740.0F, (tmp + 740.0F) - 740.0F,
      &rtb_Add1_h);

    /* End of Outputs for SubSystem: '<S12>/If Action Subsystem1' */
  }

  /* End of If: '<S12>/If' */

  /* Gain: '<S12>/Gain' incorporates:
   *  Constant: '<S12>/Constant1'
   *  Sum: '<S12>/Add1'
   *  Sum: '<S12>/Add2'
   */
  TAS_Vernier_Angle_Deg_f32_Watch = -(rtb_Add1_h - (tmp + 740.0F));

  /* RelationalOperator: '<S67>/Relational Operator' incorporates:
   *  Abs: '<S67>/Abs'
   *  Constant: '<S57>/Constant1'
   *  Constant: '<S67>/Constant6'
   *  Constant: '<S67>/Constant7'
   *  Constant: '<S67>/Constant8'
   *  Constant: '<S67>/Constant9'
   *  Product: '<S67>/Product3'
   *  Product: '<S67>/Product4'
   *  Sum: '<S57>/vd_pos'
   *  Sum: '<S67>/Add4'
   *  Sum: '<S67>/vd_nom'
   */
  TAS_Vres_FD_NA_bl_Watch = (fabsf(((((real32_T)rtb_MatrixMultiply) * 32736.0F)
    + 16368.0F) - ((rtb_Add_co + 1637.0F) * 10.0F)) > 12276.0F);

  /* Switch: '<S75>/Switch' incorporates:
   *  Constant: '<S75>/Constant3'
   *  Delay: '<S75>/Delay1'
   *  Delay: '<S75>/Delay2'
   *  Sum: '<S75>/Add'
   */
  if (SWC_TAS_DW.Delay1_DSTATE > 0.0F) {
    tmp = TAS_SENT_ANG_Follower_Deg_f32_Watch - SWC_TAS_DW.Delay2_DSTATE;
  } else {
    tmp = 1.0F;
  }

  /* End of Switch: '<S75>/Switch' */

  /* Chart: '<S6>/StateSupervisor' incorporates:
   *  RelationalOperator: '<S75>/Relational Operator'
   */
  tmp_2 = !TAS_Vres_FD_NA_bl_Watch;

  /* Outputs for Enabled SubSystem: '<S74>/VernierSynchronicityCheck' incorporates:
   *  EnablePort: '<S77>/Enable'
   */
  /* Logic: '<S75>/Logical Operator' incorporates:
   *  Abs: '<S75>/Abs'
   *  Constant: '<S75>/Constant1'
   *  RelationalOperator: '<S75>/Relational Operator1'
   */
  if (tmp_2 && (fabsf(tmp) < 0.5F)) {
    /* Logic: '<S77>/Logical Operator' incorporates:
     *  Abs: '<S77>/Abs'
     *  Abs: '<S77>/Abs1'
     *  Abs: '<S77>/Abs2'
     *  Constant: '<S77>/Constant'
     *  RelationalOperator: '<S77>/Relational Operator'
     *  RelationalOperator: '<S77>/Relational Operator1'
     *  RelationalOperator: '<S77>/Relational Operator2'
     *  Sum: '<S77>/Add'
     *  Sum: '<S77>/Add1'
     *  Sum: '<S77>/Add2'
     */
    SWC_TAS_B.LogicalOperator = (((fabsf(TAS_Vernier_Angle_Deg_f32_Watch -
      TAS_SENT_ANG_Follower_Deg_f32_Watch) > TAS_SC_AngLim_deg_f32_Cal) ||
      (fabsf(TAS_SENT1A_Follower_Deg_f32_Watch - TAS_Vernier_Angle_Deg_f32_Watch)
       > TAS_SC_AngLim_deg_f32_Cal)) || (fabsf(TAS_SENT2A_Follower_Deg_f32_Watch
      - TAS_Vernier_Angle_Deg_f32_Watch) > TAS_SC_AngLim_deg_f32_Cal));
  }

  /* End of Logic: '<S75>/Logical Operator' */
  /* End of Outputs for SubSystem: '<S74>/VernierSynchronicityCheck' */

  /* RelationalOperator: '<S91>/Relational Operator' incorporates:
   *  Abs: '<S91>/Abs'
   *  Constant: '<S91>/Constant'
   *  Sum: '<S91>/Add'
   */
  rtb_RelationalOperator_j = (fabsf(TAS_SENT1A_Follower_Deg_f32_Watch -
    TAS_SENT2A_Follower_Deg_f32_Watch) > TAS_SC_AngLim_deg_f32_Cal);

  /* RelationalOperator: '<S91>/Relational Operator1' incorporates:
   *  Abs: '<S91>/Abs1'
   *  Constant: '<S91>/Constant'
   *  Sum: '<S91>/Add1'
   */
  rtb_RelationalOperator1_n = (fabsf(TAS_SENT2A_Follower_Deg_f32_Watch -
    TAS_SENT_ANG_Follower_Deg_f32_Watch) > TAS_SC_AngLim_deg_f32_Cal);

  /* RelationalOperator: '<S91>/Relational Operator2' incorporates:
   *  Abs: '<S91>/Abs2'
   *  Constant: '<S91>/Constant'
   *  Sum: '<S91>/Add2'
   */
  rtb_RelationalOperator2 = (fabsf(TAS_SENT1A_Follower_Deg_f32_Watch -
    TAS_SENT_ANG_Follower_Deg_f32_Watch) > TAS_SC_AngLim_deg_f32_Cal);

  /* If: '<S80>/If' */
  tmp_1 = !rtb_RelationalOperator_j;
  if ((tmp_1 && rtb_RelationalOperator1_n) && rtb_RelationalOperator2) {
    /* Outputs for IfAction SubSystem: '<S80>/If Action Subsystem' incorporates:
     *  ActionPort: '<S85>/Action Port'
     */
    /* SignalConversion generated from: '<S85>/SC_S1A' incorporates:
     *  Constant: '<S85>/Constant'
     */
    rtb_RelationalOperator2 = false;

    /* SignalConversion generated from: '<S85>/SC_S2A' incorporates:
     *  Constant: '<S85>/Constant1'
     */
    rtb_Merge1_d = false;

    /* SignalConversion generated from: '<S85>/SC_S3' incorporates:
     *  Constant: '<S85>/Constant2'
     */
    rtb_Merge2_j = true;

    /* End of Outputs for SubSystem: '<S80>/If Action Subsystem' */
  } else {
    rtb_Merge1_d = !rtb_RelationalOperator1_n;
    if ((rtb_RelationalOperator_j && rtb_Merge1_d) && rtb_RelationalOperator2) {
      /* Outputs for IfAction SubSystem: '<S80>/If Action Subsystem1' incorporates:
       *  ActionPort: '<S86>/Action Port'
       */
      /* SignalConversion generated from: '<S86>/SC_S1A' incorporates:
       *  Constant: '<S86>/Constant'
       */
      rtb_RelationalOperator2 = true;

      /* SignalConversion generated from: '<S86>/SC_S2A' incorporates:
       *  Constant: '<S86>/Constant1'
       */
      rtb_Merge1_d = false;

      /* SignalConversion generated from: '<S86>/SC_S3' incorporates:
       *  Constant: '<S86>/Constant2'
       */
      rtb_Merge2_j = false;

      /* End of Outputs for SubSystem: '<S80>/If Action Subsystem1' */
    } else {
      rtb_Merge2_j = !rtb_RelationalOperator2;
      rtb_RelationalOperator_j = (rtb_RelationalOperator_j &&
        rtb_RelationalOperator1_n);
      if (rtb_RelationalOperator_j && rtb_Merge2_j) {
        /* Outputs for IfAction SubSystem: '<S80>/If Action Subsystem2' incorporates:
         *  ActionPort: '<S87>/Action Port'
         */
        /* SignalConversion generated from: '<S87>/SC_S1A' incorporates:
         *  Constant: '<S87>/Constant'
         */
        rtb_RelationalOperator2 = false;

        /* SignalConversion generated from: '<S87>/SC_S2A' incorporates:
         *  Constant: '<S87>/Constant1'
         */
        rtb_Merge1_d = true;

        /* SignalConversion generated from: '<S87>/SC_S3' incorporates:
         *  Constant: '<S87>/Constant2'
         */
        rtb_Merge2_j = false;

        /* End of Outputs for SubSystem: '<S80>/If Action Subsystem2' */
      } else if ((tmp_1 && rtb_Merge1_d) && rtb_Merge2_j) {
        /* Outputs for IfAction SubSystem: '<S80>/If Action Subsystem3' incorporates:
         *  ActionPort: '<S88>/Action Port'
         */
        SWC_TAS_IfActionSubsystem3(&rtb_RelationalOperator2, &rtb_Merge1_d,
          &rtb_Merge2_j);

        /* End of Outputs for SubSystem: '<S80>/If Action Subsystem3' */
      } else if (rtb_RelationalOperator_j && rtb_RelationalOperator2) {
        /* Outputs for IfAction SubSystem: '<S80>/If Action Subsystem4' incorporates:
         *  ActionPort: '<S89>/Action Port'
         */
        /* SignalConversion generated from: '<S89>/SC_S1A' incorporates:
         *  Constant: '<S89>/Constant'
         */
        rtb_RelationalOperator2 = true;

        /* SignalConversion generated from: '<S89>/SC_S2A' incorporates:
         *  Constant: '<S89>/Constant1'
         */
        rtb_Merge1_d = true;

        /* SignalConversion generated from: '<S89>/SC_S3' incorporates:
         *  Constant: '<S89>/Constant2'
         */
        rtb_Merge2_j = true;

        /* End of Outputs for SubSystem: '<S80>/If Action Subsystem4' */
      } else {
        /* Outputs for IfAction SubSystem: '<S80>/If Action Subsystem5' incorporates:
         *  ActionPort: '<S90>/Action Port'
         */
        SWC_TAS_IfActionSubsystem3(&rtb_RelationalOperator2, &rtb_Merge1_d,
          &rtb_Merge2_j);

        /* End of Outputs for SubSystem: '<S80>/If Action Subsystem5' */
      }
    }
  }

  /* End of If: '<S80>/If' */

  /* Logic: '<S71>/Logical Operator' incorporates:
   *  Inport: '<Root>/TAS_SENT_ANG_NA_u16_Read'
   *  RelationalOperator: '<S71>/Relational Operator'
   *  RelationalOperator: '<S71>/Relational Operator1'
   */
  rtb_RelationalOperator_j = ((TAS_SENT_ANG_NA_u16_Read < 1) ||
    (TAS_SENT_ANG_NA_u16_Read > 4088));

  /* Logic: '<S69>/Logical Operator' incorporates:
   *  Inport: '<Root>/TAS_SENT1A_NA_u16_Read'
   *  RelationalOperator: '<S69>/Relational Operator'
   *  RelationalOperator: '<S69>/Relational Operator1'
   */
  rtb_RelationalOperator1_n = ((TAS_SENT1A_NA_u16_Read < 1) ||
    (TAS_SENT1A_NA_u16_Read > 4093));

  /* Logic: '<S70>/Logical Operator' incorporates:
   *  Inport: '<Root>/TAS_SENT2A_NA_u16_Read'
   *  RelationalOperator: '<S70>/Relational Operator'
   *  RelationalOperator: '<S70>/Relational Operator1'
   */
  rtb_LogicalOperator_m = ((TAS_SENT2A_NA_u16_Read < 1) ||
    (TAS_SENT2A_NA_u16_Read > 4093));

  /* Logic: '<S76>/Logical Operator' incorporates:
   *  Chart: '<S6>/StateSupervisor'
   */
  tmp_1 = !SWC_TAS_B.LogicalOperator;

  /* If: '<S78>/If' incorporates:
   *  Logic: '<S76>/Logical Operator'
   *  Logic: '<S76>/Logical Operator1'
   */
  if (((((((!rtb_RelationalOperator2) && (!rtb_Merge1_d)) && (!rtb_Merge2_j)) &&
         tmp_1) && (!rtb_RelationalOperator_j)) && (!rtb_RelationalOperator1_n))
      && (!rtb_LogicalOperator_m)) {
    /* Outputs for IfAction SubSystem: '<S78>/decrease' incorporates:
     *  ActionPort: '<S81>/Action Port'
     */
    /* Saturate: '<S81>/Saturation' incorporates:
     *  Constant: '<S81>/Constant1'
     *  Sum: '<S81>/Add5'
     */
    if ((TAS_ec_af_S1A_NA_f32_Watch - 1.0F) > TAS_CntUpLim_NA_f32_Cal) {
      /* Merge: '<S78>/Merge' */
      TAS_ec_af_S1A_NA_f32_Watch = TAS_CntUpLim_NA_f32_Cal;
    } else if ((TAS_ec_af_S1A_NA_f32_Watch - 1.0F) < 0.0F) {
      /* Merge: '<S78>/Merge' */
      TAS_ec_af_S1A_NA_f32_Watch = 0.0F;
    } else {
      /* Merge: '<S78>/Merge' */
      TAS_ec_af_S1A_NA_f32_Watch--;
    }

    /* End of Saturate: '<S81>/Saturation' */

    /* Saturate: '<S81>/Saturation1' incorporates:
     *  Constant: '<S81>/Constant'
     *  Sum: '<S81>/Add9'
     */
    if ((TAS_ec_af_S2A_NA_f32_Watch - 1.0F) > TAS_CntUpLim_NA_f32_Cal) {
      /* Merge: '<S78>/Merge1' */
      TAS_ec_af_S2A_NA_f32_Watch = TAS_CntUpLim_NA_f32_Cal;
    } else if ((TAS_ec_af_S2A_NA_f32_Watch - 1.0F) < 0.0F) {
      /* Merge: '<S78>/Merge1' */
      TAS_ec_af_S2A_NA_f32_Watch = 0.0F;
    } else {
      /* Merge: '<S78>/Merge1' */
      TAS_ec_af_S2A_NA_f32_Watch--;
    }

    /* End of Saturate: '<S81>/Saturation1' */

    /* Saturate: '<S81>/Saturation2' incorporates:
     *  Constant: '<S81>/Constant2'
     *  Sum: '<S81>/Add6'
     */
    if ((TAS_ec_af_S3_NA_f32_Watch - 1.0F) > TAS_CntUpLim_NA_f32_Cal) {
      /* Merge: '<S78>/Merge2' */
      TAS_ec_af_S3_NA_f32_Watch = TAS_CntUpLim_NA_f32_Cal;
    } else if ((TAS_ec_af_S3_NA_f32_Watch - 1.0F) < 0.0F) {
      /* Merge: '<S78>/Merge2' */
      TAS_ec_af_S3_NA_f32_Watch = 0.0F;
    } else {
      /* Merge: '<S78>/Merge2' */
      TAS_ec_af_S3_NA_f32_Watch--;
    }

    /* End of Saturate: '<S81>/Saturation2' */

    /* Saturate: '<S81>/Saturation3' incorporates:
     *  Constant: '<S81>/Constant3'
     *  Sum: '<S81>/Add10'
     */
    if ((TAS_ec_af_Vernier_NA_f32_Watch - 1.0F) > TAS_CntUpLim_NA_f32_Cal) {
      /* Merge: '<S78>/Merge3' */
      TAS_ec_af_Vernier_NA_f32_Watch = TAS_CntUpLim_NA_f32_Cal;
    } else if ((TAS_ec_af_Vernier_NA_f32_Watch - 1.0F) < 0.0F) {
      /* Merge: '<S78>/Merge3' */
      TAS_ec_af_Vernier_NA_f32_Watch = 0.0F;
    } else {
      /* Merge: '<S78>/Merge3' */
      TAS_ec_af_Vernier_NA_f32_Watch--;
    }

    /* End of Saturate: '<S81>/Saturation3' */

    /* Saturate: '<S81>/Saturation4' incorporates:
     *  Constant: '<S81>/Constant4'
     *  Sum: '<S81>/Add11'
     */
    if ((TAS_ec_diag_S3_NA_f32_Watch - 1.0F) > TAS_CntUpLim_NA_f32_Cal) {
      /* Merge: '<S78>/Merge4' */
      TAS_ec_diag_S3_NA_f32_Watch = TAS_CntUpLim_NA_f32_Cal;
    } else if ((TAS_ec_diag_S3_NA_f32_Watch - 1.0F) < 0.0F) {
      /* Merge: '<S78>/Merge4' */
      TAS_ec_diag_S3_NA_f32_Watch = 0.0F;
    } else {
      /* Merge: '<S78>/Merge4' */
      TAS_ec_diag_S3_NA_f32_Watch--;
    }

    /* End of Saturate: '<S81>/Saturation4' */

    /* Saturate: '<S81>/Saturation5' incorporates:
     *  Constant: '<S81>/Constant5'
     *  Sum: '<S81>/Add12'
     */
    if ((TAS_ec_diag_S1A_NA_f32_Watch - 1.0F) > TAS_CntUpLim_NA_f32_Cal) {
      /* Merge: '<S78>/Merge5' */
      TAS_ec_diag_S1A_NA_f32_Watch = TAS_CntUpLim_NA_f32_Cal;
    } else if ((TAS_ec_diag_S1A_NA_f32_Watch - 1.0F) < 0.0F) {
      /* Merge: '<S78>/Merge5' */
      TAS_ec_diag_S1A_NA_f32_Watch = 0.0F;
    } else {
      /* Merge: '<S78>/Merge5' */
      TAS_ec_diag_S1A_NA_f32_Watch--;
    }

    /* End of Saturate: '<S81>/Saturation5' */

    /* Saturate: '<S81>/Saturation7' incorporates:
     *  Constant: '<S81>/Constant7'
     *  Sum: '<S81>/Add14'
     */
    if ((TAS_ec_diag_S2A_NA_f32_Watch - 1.0F) > TAS_CntUpLim_NA_f32_Cal) {
      /* Merge: '<S78>/Merge7' */
      TAS_ec_diag_S2A_NA_f32_Watch = TAS_CntUpLim_NA_f32_Cal;
    } else if ((TAS_ec_diag_S2A_NA_f32_Watch - 1.0F) < 0.0F) {
      /* Merge: '<S78>/Merge7' */
      TAS_ec_diag_S2A_NA_f32_Watch = 0.0F;
    } else {
      /* Merge: '<S78>/Merge7' */
      TAS_ec_diag_S2A_NA_f32_Watch--;
    }

    /* End of Saturate: '<S81>/Saturation7' */
    /* End of Outputs for SubSystem: '<S78>/decrease' */
  } else {
    /* Outputs for IfAction SubSystem: '<S78>/increase' incorporates:
     *  ActionPort: '<S82>/Action Port'
     */
    /* Merge: '<S78>/Merge' incorporates:
     *  Sum: '<S82>/Add5'
     */
    TAS_ec_af_S1A_NA_f32_Watch += (real32_T)rtb_RelationalOperator2;

    /* Saturate: '<S82>/Saturation' */
    if (TAS_ec_af_S1A_NA_f32_Watch > TAS_CntUpLim_NA_f32_Cal) {
      /* Merge: '<S78>/Merge' */
      TAS_ec_af_S1A_NA_f32_Watch = TAS_CntUpLim_NA_f32_Cal;
    } else if (TAS_ec_af_S1A_NA_f32_Watch < 0.0F) {
      /* Merge: '<S78>/Merge' */
      TAS_ec_af_S1A_NA_f32_Watch = 0.0F;
    }

    /* End of Saturate: '<S82>/Saturation' */

    /* Merge: '<S78>/Merge1' incorporates:
     *  Sum: '<S82>/Add9'
     */
    TAS_ec_af_S2A_NA_f32_Watch += (real32_T)rtb_Merge1_d;

    /* Saturate: '<S82>/Saturation1' */
    if (TAS_ec_af_S2A_NA_f32_Watch > TAS_CntUpLim_NA_f32_Cal) {
      /* Merge: '<S78>/Merge1' */
      TAS_ec_af_S2A_NA_f32_Watch = TAS_CntUpLim_NA_f32_Cal;
    } else if (TAS_ec_af_S2A_NA_f32_Watch < 0.0F) {
      /* Merge: '<S78>/Merge1' */
      TAS_ec_af_S2A_NA_f32_Watch = 0.0F;
    }

    /* End of Saturate: '<S82>/Saturation1' */

    /* Merge: '<S78>/Merge2' incorporates:
     *  Sum: '<S82>/Add6'
     */
    TAS_ec_af_S3_NA_f32_Watch += (real32_T)rtb_Merge2_j;

    /* Saturate: '<S82>/Saturation2' */
    if (TAS_ec_af_S3_NA_f32_Watch > TAS_CntUpLim_NA_f32_Cal) {
      /* Merge: '<S78>/Merge2' */
      TAS_ec_af_S3_NA_f32_Watch = TAS_CntUpLim_NA_f32_Cal;
    } else if (TAS_ec_af_S3_NA_f32_Watch < 0.0F) {
      /* Merge: '<S78>/Merge2' */
      TAS_ec_af_S3_NA_f32_Watch = 0.0F;
    }

    /* End of Saturate: '<S82>/Saturation2' */

    /* Merge: '<S78>/Merge3' incorporates:
     *  Sum: '<S82>/Add10'
     */
    TAS_ec_af_Vernier_NA_f32_Watch += (real32_T)SWC_TAS_B.LogicalOperator;

    /* Saturate: '<S82>/Saturation3' */
    if (TAS_ec_af_Vernier_NA_f32_Watch > TAS_CntUpLim_NA_f32_Cal) {
      /* Merge: '<S78>/Merge3' */
      TAS_ec_af_Vernier_NA_f32_Watch = TAS_CntUpLim_NA_f32_Cal;
    } else if (TAS_ec_af_Vernier_NA_f32_Watch < 0.0F) {
      /* Merge: '<S78>/Merge3' */
      TAS_ec_af_Vernier_NA_f32_Watch = 0.0F;
    }

    /* End of Saturate: '<S82>/Saturation3' */

    /* Merge: '<S78>/Merge4' incorporates:
     *  Sum: '<S82>/Add11'
     */
    TAS_ec_diag_S3_NA_f32_Watch += (real32_T)rtb_RelationalOperator_j;

    /* Saturate: '<S82>/Saturation4' */
    if (TAS_ec_diag_S3_NA_f32_Watch > TAS_CntUpLim_NA_f32_Cal) {
      /* Merge: '<S78>/Merge4' */
      TAS_ec_diag_S3_NA_f32_Watch = TAS_CntUpLim_NA_f32_Cal;
    } else if (TAS_ec_diag_S3_NA_f32_Watch < 0.0F) {
      /* Merge: '<S78>/Merge4' */
      TAS_ec_diag_S3_NA_f32_Watch = 0.0F;
    }

    /* End of Saturate: '<S82>/Saturation4' */

    /* Merge: '<S78>/Merge5' incorporates:
     *  Sum: '<S82>/Add12'
     */
    TAS_ec_diag_S1A_NA_f32_Watch += (real32_T)rtb_RelationalOperator1_n;

    /* Saturate: '<S82>/Saturation5' */
    if (TAS_ec_diag_S1A_NA_f32_Watch > TAS_CntUpLim_NA_f32_Cal) {
      /* Merge: '<S78>/Merge5' */
      TAS_ec_diag_S1A_NA_f32_Watch = TAS_CntUpLim_NA_f32_Cal;
    } else if (TAS_ec_diag_S1A_NA_f32_Watch < 0.0F) {
      /* Merge: '<S78>/Merge5' */
      TAS_ec_diag_S1A_NA_f32_Watch = 0.0F;
    }

    /* End of Saturate: '<S82>/Saturation5' */

    /* Merge: '<S78>/Merge7' incorporates:
     *  Sum: '<S82>/Add14'
     */
    TAS_ec_diag_S2A_NA_f32_Watch += (real32_T)rtb_LogicalOperator_m;

    /* Saturate: '<S82>/Saturation6' */
    if (TAS_ec_diag_S2A_NA_f32_Watch > TAS_CntUpLim_NA_f32_Cal) {
      /* Merge: '<S78>/Merge7' */
      TAS_ec_diag_S2A_NA_f32_Watch = TAS_CntUpLim_NA_f32_Cal;
    } else if (TAS_ec_diag_S2A_NA_f32_Watch < 0.0F) {
      /* Merge: '<S78>/Merge7' */
      TAS_ec_diag_S2A_NA_f32_Watch = 0.0F;
    }

    /* End of Saturate: '<S82>/Saturation6' */
    /* End of Outputs for SubSystem: '<S78>/increase' */
  }

  /* End of If: '<S78>/If' */

  /* If: '<S79>/If1' incorporates:
   *  UnitDelay: '<S6>/Unit Delay'
   */
  if (SWC_TAS_DW.UnitDelay_DSTATE_f == 1) {
    /* Outputs for IfAction SubSystem: '<S79>/If Action Subsystem' incorporates:
     *  ActionPort: '<S83>/Action Port'
     */
    /* Merge: '<S78>/Merge3' incorporates:
     *  Constant: '<S83>/Constant'
     *  Merge: '<S79>/Merge12'
     *  SignalConversion generated from: '<S83>/  ec_af_Vernier'
     */
    TAS_ec_af_Vernier_NA_f32_Watch = 0.0F;

    /* Merge: '<S78>/Merge' incorporates:
     *  Constant: '<S83>/Constant'
     *  Merge: '<S79>/Merge9'
     *  SignalConversion generated from: '<S83>/ ec_af_S1A'
     */
    TAS_ec_af_S1A_NA_f32_Watch = 0.0F;

    /* Merge: '<S78>/Merge1' incorporates:
     *  Constant: '<S83>/Constant'
     *  Merge: '<S79>/Merge10'
     *  SignalConversion generated from: '<S83>/ ec_af_S2A'
     */
    TAS_ec_af_S2A_NA_f32_Watch = 0.0F;

    /* Merge: '<S78>/Merge2' incorporates:
     *  Constant: '<S83>/Constant'
     *  Merge: '<S79>/Merge11'
     *  SignalConversion generated from: '<S83>/ ec_af_S3'
     */
    TAS_ec_af_S3_NA_f32_Watch = 0.0F;

    /* Merge: '<S78>/Merge7' incorporates:
     *  Constant: '<S83>/Constant'
     *  Merge: '<S79>/Merge16'
     *  SignalConversion generated from: '<S83>/ ec_diag_S2A'
     */
    TAS_ec_diag_S2A_NA_f32_Watch = 0.0F;

    /* Merge: '<S78>/Merge5' incorporates:
     *  Constant: '<S83>/Constant'
     *  Merge: '<S79>/Merge14'
     *  SignalConversion generated from: '<S83>/ec_diag_S1A'
     */
    TAS_ec_diag_S1A_NA_f32_Watch = 0.0F;

    /* Merge: '<S78>/Merge4' incorporates:
     *  Constant: '<S83>/Constant'
     *  Merge: '<S79>/Merge13'
     *  SignalConversion generated from: '<S83>/ec_diag_S3'
     */
    TAS_ec_diag_S3_NA_f32_Watch = 0.0F;

    /* End of Outputs for SubSystem: '<S79>/If Action Subsystem' */
  }

  /* End of If: '<S79>/If1' */

  /* RelationalOperator: '<S6>/Relational Operator1' incorporates:
   *  Constant: '<S6>/Constant2'
   *  Inport: '<Root>/TAS_SENT1_LossOfSignal_NA_bl_Read '
   *  Inport: '<Root>/TAS_SENT2_LossOfSignal_NA_bl_Read'
   *  Inport: '<Root>/TAS_SENT3_LossOfSignal_NA_bl_Read '
   *  Sum: '<S6>/Add'
   */
  TAS_LossOfSignal_NA_bl_Watch = (((int32_T)((((uint32_T)
    TAS_SENT1_LossOfSignal_NA_bl_Read) + TAS_SENT2_LossOfSignal_NA_bl_Read) +
    TAS_SENT3_LossOfSignal_NA_bl_Read)) >= 2);

  /* Chart: '<S6>/StateSupervisor' incorporates:
   *  Constant: '<S6>/Constant1'
   */
  if (SWC_TAS_DW.is_active_c11_SWC_TAS == 0U) {
    SWC_TAS_DW.is_active_c11_SWC_TAS = 1U;
    SWC_TAS_DW.is_c11_SWC_TAS = SWC_TAS_IN_INIT_j;
    TAS_SafetySts_NA_u8_Watch = 0U;
    SWC_TAS_DW.is_INIT = SWC_TAS_IN_en;
    SWC_TAS_DW.Cnt = 0U;
    SWC_TAS_DW.min_grad = 0.0F;
    SWC_TAS_DW.max_grad = 0.0F;
    SWC_TAS_DW.ef_mg = 0U;
    SWC_TAS_DW.ec_af_init = 0U;
    SWC_TAS_B.Vernier_Init = 1U;
    SWC_TAS_B.reset = 1U;
    SWC_TAS_B.AngFollowerChoose = 4U;
  } else {
    guard1 = false;
    guard2 = false;
    switch (SWC_TAS_DW.is_c11_SWC_TAS) {
     case SWC_TAS_IN_ASILB:
      if ((((((((TAS_ec_af_S1A_NA_f32_Watch > TAS_FaultCntLim_NA_f32_Cal) &&
                (TAS_ec_af_S2A_NA_f32_Watch > TAS_FaultCntLim_NA_f32_Cal)) ||
               ((TAS_ec_af_S2A_NA_f32_Watch > TAS_FaultCntLim_NA_f32_Cal) &&
                (TAS_ec_af_S3_NA_f32_Watch > TAS_FaultCntLim_NA_f32_Cal))) ||
              ((TAS_ec_af_S1A_NA_f32_Watch > TAS_FaultCntLim_NA_f32_Cal) &&
               (TAS_ec_af_S3_NA_f32_Watch > TAS_FaultCntLim_NA_f32_Cal))) ||
             ((TAS_ec_diag_S1A_NA_f32_Watch > TAS_FaultCntLim_NA_f32_Cal) &&
              (TAS_ec_diag_S2A_NA_f32_Watch > TAS_FaultCntLim_NA_f32_Cal))) ||
            ((TAS_ec_diag_S2A_NA_f32_Watch > TAS_FaultCntLim_NA_f32_Cal) &&
             (TAS_ec_diag_S3_NA_f32_Watch > TAS_FaultCntLim_NA_f32_Cal))) ||
           ((TAS_ec_diag_S1A_NA_f32_Watch > TAS_FaultCntLim_NA_f32_Cal) &&
            (TAS_ec_diag_S3_NA_f32_Watch > TAS_FaultCntLim_NA_f32_Cal))) ||
          TAS_LossOfSignal_NA_bl_Watch) {
        SWC_TAS_DW.is_c11_SWC_TAS = SWC_TAS_IN_ERROR;
        TAS_SafetySts_NA_u8_Watch = 4U;
        if (((((((TAS_ec_af_Vernier_NA_f32_Watch > TAS_FaultCntLim_NA_f32_Cal) &&
                 (TAS_ec_af_S3_NA_f32_Watch > TAS_FaultCntLim_NA_f32_Cal)) &&
                (TAS_ec_diag_S1A_NA_f32_Watch < TAS_FaultCntLim_NA_f32_Cal)) &&
               (TAS_ec_diag_S2A_NA_f32_Watch < TAS_FaultCntLim_NA_f32_Cal)) &&
              (TAS_ec_diag_S3_NA_f32_Watch < TAS_FaultCntLim_NA_f32_Cal)) &&
             (TAS_ec_af_S1A_NA_f32_Watch < TAS_FaultCntLim_NA_f32_Cal)) &&
            (TAS_ec_af_S2A_NA_f32_Watch < TAS_FaultCntLim_NA_f32_Cal)) {
          SWC_TAS_DW.ef_mg = 1U;
        }

        SWC_TAS_B.AngFollowerChoose = 0U;
      } else if ((TAS_ec_af_S1A_NA_f32_Watch > 0.0F) &&
                 (TAS_ec_af_S2A_NA_f32_Watch == 0.0F)) {
        SWC_TAS_B.AngFollowerChoose = 3U;
        guard1 = true;
      } else if ((TAS_ec_af_S1A_NA_f32_Watch == 0.0F) &&
                 (TAS_ec_af_S2A_NA_f32_Watch > 0.0F)) {
        SWC_TAS_B.AngFollowerChoose = 2U;
        guard1 = true;
      } else {
        TAS_SafetySts_NA_u8_Watch = 2U;
        SWC_TAS_B.AngFollowerChoose = 1U;
      }
      break;

     case SWC_TAS_IN_ERROR:
      if ((((((((((TAS_ec_diag_S1A_NA_f32_Watch == 0.0F) &&
                  (TAS_ec_diag_S2A_NA_f32_Watch == 0.0F)) &&
                 (TAS_ec_diag_S3_NA_f32_Watch == 0.0F)) &&
                (TAS_ec_af_S1A_NA_f32_Watch == 0.0F)) &&
               (TAS_ec_af_S2A_NA_f32_Watch == 0.0F)) &&
              (TAS_ec_af_S3_NA_f32_Watch == 0.0F)) &&
             (TAS_ec_af_Vernier_NA_f32_Watch == 0.0F)) && (SWC_TAS_DW.ef_mg == 0))
           && (SWC_TAS_DW.ec_af_init == 0)) && (!TAS_LossOfSignal_NA_bl_Watch))
      {
        SWC_TAS_DW.is_c11_SWC_TAS = SWC_TAS_IN_INIT_j;
        TAS_SafetySts_NA_u8_Watch = 0U;
        SWC_TAS_DW.is_INIT = SWC_TAS_IN_en;
        SWC_TAS_DW.Cnt = 0U;
        SWC_TAS_DW.min_grad = 0.0F;
        SWC_TAS_DW.max_grad = 0.0F;
        SWC_TAS_DW.ef_mg = 0U;
        SWC_TAS_DW.ec_af_init = 0U;
        SWC_TAS_B.Vernier_Init = 1U;
        SWC_TAS_B.reset = 1U;
        SWC_TAS_B.AngFollowerChoose = 4U;
      } else {
        SWC_TAS_DW.is_c11_SWC_TAS = SWC_TAS_IN_ERROR;
        TAS_SafetySts_NA_u8_Watch = 4U;
        if (((((((TAS_ec_af_Vernier_NA_f32_Watch > TAS_FaultCntLim_NA_f32_Cal) &&
                 (TAS_ec_af_S3_NA_f32_Watch > TAS_FaultCntLim_NA_f32_Cal)) &&
                (TAS_ec_diag_S1A_NA_f32_Watch < TAS_FaultCntLim_NA_f32_Cal)) &&
               (TAS_ec_diag_S2A_NA_f32_Watch < TAS_FaultCntLim_NA_f32_Cal)) &&
              (TAS_ec_diag_S3_NA_f32_Watch < TAS_FaultCntLim_NA_f32_Cal)) &&
             (TAS_ec_af_S1A_NA_f32_Watch < TAS_FaultCntLim_NA_f32_Cal)) &&
            (TAS_ec_af_S2A_NA_f32_Watch < TAS_FaultCntLim_NA_f32_Cal)) {
          SWC_TAS_DW.ef_mg = 1U;
        }

        SWC_TAS_B.AngFollowerChoose = 0U;
      }
      break;

     case SWC_TAS_IN_INIT_j:
      if (((TAS_ec_diag_S1A_NA_f32_Watch > TAS_FaultCntLim_NA_f32_Cal) ||
           (TAS_ec_diag_S2A_NA_f32_Watch > TAS_FaultCntLim_NA_f32_Cal)) ||
          (TAS_ec_diag_S3_NA_f32_Watch > TAS_FaultCntLim_NA_f32_Cal)) {
        SWC_TAS_DW.ec_af_init = 0U;
        guard2 = true;
      } else if (SWC_TAS_DW.ec_af_init > TAS_FaultCntLim_NA_f32_Cal) {
        guard2 = true;
      } else if ((((((((SWC_TAS_DW.Cnt >= 2) && (TAS_ec_diag_S1A_NA_f32_Watch ==
        0.0F)) && (TAS_ec_diag_S2A_NA_f32_Watch == 0.0F)) &&
                     (TAS_ec_diag_S3_NA_f32_Watch == 0.0F)) &&
                    (TAS_ec_af_S1A_NA_f32_Watch == 0.0F)) &&
                   (TAS_ec_af_S2A_NA_f32_Watch == 0.0F)) &&
                  (TAS_ec_af_S3_NA_f32_Watch == 0.0F)) &&
                 (TAS_ec_af_Vernier_NA_f32_Watch == 0.0F)) {
        SWC_TAS_DW.ec_af_init = 0U;
        SWC_TAS_B.Vernier_Init = 0U;
        SWC_TAS_DW.is_INIT = SWC_TAS_IN_NO_ACTIVE_CHILD_e;
        SWC_TAS_DW.is_c11_SWC_TAS = SWC_TAS_IN_QM;
        TAS_SafetySts_NA_u8_Watch = 1U;
        SWC_TAS_B.AngFollowerChoose = 1U;
        SWC_TAS_DW.is_QM = SWC_TAS_IN_en;
        SWC_TAS_DW.min_grad = TAS_Vernier_Angle_Deg_f32_Watch;
        SWC_TAS_DW.max_grad = TAS_Vernier_Angle_Deg_f32_Watch;
      } else {
        TAS_SafetySts_NA_u8_Watch = 0U;
        switch (SWC_TAS_DW.is_INIT) {
         case SWC_TAS_IN_during:
          if ((tmp_2 && tmp_1) && (SWC_TAS_DW.Cnt == 1)) {
            SWC_TAS_DW.is_INIT = SWC_TAS_IN_ex;
            SWC_TAS_DW.Cnt = 2U;
            SWC_TAS_B.Vernier_Init = 0U;
          } else {
            SWC_TAS_DW.is_INIT = SWC_TAS_IN_during;
            SWC_TAS_enter_internal_during();
          }
          break;

         case SWC_TAS_IN_en:
          SWC_TAS_B.reset = 0U;
          SWC_TAS_DW.is_INIT = SWC_TAS_IN_during;
          SWC_TAS_enter_internal_during();
          break;

         default:
          /* case IN_ex: */
          if (TAS_Vres_FD_NA_bl_Watch || (SWC_TAS_B.LogicalOperator)) {
            SWC_TAS_DW.is_INIT = SWC_TAS_IN_during;
            SWC_TAS_enter_internal_during();
          } else {
            SWC_TAS_DW.Cnt = 2U;
            SWC_TAS_B.Vernier_Init = 0U;
          }
          break;
        }
      }
      break;

     case SWC_TAS_IN_Prewarning:
      if ((((((((TAS_ec_af_S1A_NA_f32_Watch > TAS_FaultCntLim_NA_f32_Cal) &&
                (TAS_ec_af_S2A_NA_f32_Watch > TAS_FaultCntLim_NA_f32_Cal)) ||
               ((TAS_ec_af_S2A_NA_f32_Watch > TAS_FaultCntLim_NA_f32_Cal) &&
                (TAS_ec_af_S3_NA_f32_Watch > TAS_FaultCntLim_NA_f32_Cal))) ||
              ((TAS_ec_af_S1A_NA_f32_Watch > TAS_FaultCntLim_NA_f32_Cal) &&
               (TAS_ec_af_S3_NA_f32_Watch > TAS_FaultCntLim_NA_f32_Cal))) ||
             ((TAS_ec_diag_S1A_NA_f32_Watch > TAS_FaultCntLim_NA_f32_Cal) &&
              (TAS_ec_diag_S2A_NA_f32_Watch > TAS_FaultCntLim_NA_f32_Cal))) ||
            ((TAS_ec_diag_S2A_NA_f32_Watch > TAS_FaultCntLim_NA_f32_Cal) &&
             (TAS_ec_diag_S3_NA_f32_Watch > TAS_FaultCntLim_NA_f32_Cal))) ||
           ((TAS_ec_diag_S1A_NA_f32_Watch > TAS_FaultCntLim_NA_f32_Cal) &&
            (TAS_ec_diag_S3_NA_f32_Watch > TAS_FaultCntLim_NA_f32_Cal))) ||
          TAS_LossOfSignal_NA_bl_Watch) {
        SWC_TAS_DW.is_Prewarning = SWC_TAS_IN_NO_ACTIVE_CHILD_e;
        SWC_TAS_DW.is_c11_SWC_TAS = SWC_TAS_IN_ERROR;
        TAS_SafetySts_NA_u8_Watch = 4U;
        if (((((((TAS_ec_af_Vernier_NA_f32_Watch > TAS_FaultCntLim_NA_f32_Cal) &&
                 (TAS_ec_af_S3_NA_f32_Watch > TAS_FaultCntLim_NA_f32_Cal)) &&
                (TAS_ec_diag_S1A_NA_f32_Watch < TAS_FaultCntLim_NA_f32_Cal)) &&
               (TAS_ec_diag_S2A_NA_f32_Watch < TAS_FaultCntLim_NA_f32_Cal)) &&
              (TAS_ec_diag_S3_NA_f32_Watch < TAS_FaultCntLim_NA_f32_Cal)) &&
             (TAS_ec_af_S1A_NA_f32_Watch < TAS_FaultCntLim_NA_f32_Cal)) &&
            (TAS_ec_af_S2A_NA_f32_Watch < TAS_FaultCntLim_NA_f32_Cal)) {
          SWC_TAS_DW.ef_mg = 1U;
        }

        SWC_TAS_B.AngFollowerChoose = 0U;
      } else if ((((((((TAS_ec_diag_S1A_NA_f32_Watch == 0.0F) &&
                       (TAS_ec_diag_S2A_NA_f32_Watch == 0.0F)) &&
                      (TAS_ec_diag_S3_NA_f32_Watch == 0.0F)) &&
                     (TAS_ec_af_S1A_NA_f32_Watch == 0.0F)) &&
                    (TAS_ec_af_S2A_NA_f32_Watch == 0.0F)) &&
                   (TAS_ec_af_S3_NA_f32_Watch == 0.0F)) &&
                  (TAS_ec_af_Vernier_NA_f32_Watch == 0.0F)) &&
                 ((SWC_TAS_DW.max_grad - SWC_TAS_DW.min_grad) > 3.0F)) {
        SWC_TAS_DW.is_Prewarning = SWC_TAS_IN_NO_ACTIVE_CHILD_e;
        SWC_TAS_DW.is_c11_SWC_TAS = SWC_TAS_IN_ASILB;
        TAS_SafetySts_NA_u8_Watch = 2U;
        SWC_TAS_B.AngFollowerChoose = 1U;
      } else {
        TAS_SafetySts_NA_u8_Watch = 3U;
        if (SWC_TAS_DW.is_Prewarning == 1) {
          SWC_TAS_DW.is_Prewarning = SWC_TAS_IN_du;
          if (tmp_1 && tmp_2) {
            if (TAS_Vernier_Angle_Deg_f32_Watch > SWC_TAS_DW.max_grad) {
              SWC_TAS_DW.max_grad = TAS_Vernier_Angle_Deg_f32_Watch;
            } else if (TAS_Vernier_Angle_Deg_f32_Watch < SWC_TAS_DW.min_grad) {
              SWC_TAS_DW.min_grad = TAS_Vernier_Angle_Deg_f32_Watch;
            }
          } else {
            SWC_TAS_DW.min_grad = TAS_Vernier_Angle_Deg_f32_Watch;
            SWC_TAS_DW.max_grad = TAS_Vernier_Angle_Deg_f32_Watch;
          }
        } else {
          /* case IN_en: */
          SWC_TAS_DW.is_Prewarning = SWC_TAS_IN_du;
          if (tmp_1 && tmp_2) {
            if (TAS_Vernier_Angle_Deg_f32_Watch > SWC_TAS_DW.max_grad) {
              SWC_TAS_DW.max_grad = TAS_Vernier_Angle_Deg_f32_Watch;
            } else if (TAS_Vernier_Angle_Deg_f32_Watch < SWC_TAS_DW.min_grad) {
              SWC_TAS_DW.min_grad = TAS_Vernier_Angle_Deg_f32_Watch;
            }
          } else {
            SWC_TAS_DW.min_grad = TAS_Vernier_Angle_Deg_f32_Watch;
            SWC_TAS_DW.max_grad = TAS_Vernier_Angle_Deg_f32_Watch;
          }
        }
      }
      break;

     default:
      /* case IN_QM: */
      if ((((((((TAS_ec_diag_S2A_NA_f32_Watch > TAS_FaultCntLim_NA_f32_Cal) ||
                (TAS_ec_af_S2A_NA_f32_Watch > TAS_FaultCntLim_NA_f32_Cal)) ||
               (TAS_ec_diag_S3_NA_f32_Watch > TAS_FaultCntLim_NA_f32_Cal)) ||
              (TAS_ec_af_S3_NA_f32_Watch > TAS_FaultCntLim_NA_f32_Cal)) ||
             (TAS_ec_diag_S1A_NA_f32_Watch > TAS_FaultCntLim_NA_f32_Cal)) ||
            (TAS_ec_af_S1A_NA_f32_Watch > TAS_FaultCntLim_NA_f32_Cal)) ||
           (TAS_ec_af_Vernier_NA_f32_Watch > TAS_FaultCntLim_NA_f32_Cal)) ||
          TAS_LossOfSignal_NA_bl_Watch) {
        SWC_TAS_DW.is_QM = SWC_TAS_IN_NO_ACTIVE_CHILD_e;
        SWC_TAS_DW.is_c11_SWC_TAS = SWC_TAS_IN_ERROR;
        TAS_SafetySts_NA_u8_Watch = 4U;
        if (((((((TAS_ec_af_Vernier_NA_f32_Watch > TAS_FaultCntLim_NA_f32_Cal) &&
                 (TAS_ec_af_S3_NA_f32_Watch > TAS_FaultCntLim_NA_f32_Cal)) &&
                (TAS_ec_diag_S1A_NA_f32_Watch < TAS_FaultCntLim_NA_f32_Cal)) &&
               (TAS_ec_diag_S2A_NA_f32_Watch < TAS_FaultCntLim_NA_f32_Cal)) &&
              (TAS_ec_diag_S3_NA_f32_Watch < TAS_FaultCntLim_NA_f32_Cal)) &&
             (TAS_ec_af_S1A_NA_f32_Watch < TAS_FaultCntLim_NA_f32_Cal)) &&
            (TAS_ec_af_S2A_NA_f32_Watch < TAS_FaultCntLim_NA_f32_Cal)) {
          SWC_TAS_DW.ef_mg = 1U;
        }

        SWC_TAS_B.AngFollowerChoose = 0U;
      } else if ((SWC_TAS_DW.max_grad - SWC_TAS_DW.min_grad) > 7.0F) {
        SWC_TAS_DW.is_QM = SWC_TAS_IN_NO_ACTIVE_CHILD_e;
        SWC_TAS_DW.is_c11_SWC_TAS = SWC_TAS_IN_ASILB;
        TAS_SafetySts_NA_u8_Watch = 2U;
        SWC_TAS_B.AngFollowerChoose = 1U;
      } else {
        TAS_SafetySts_NA_u8_Watch = 1U;
        SWC_TAS_B.AngFollowerChoose = 1U;
        if (SWC_TAS_DW.is_QM == 1) {
          SWC_TAS_DW.is_QM = SWC_TAS_IN_du;
          if (TAS_Vernier_Angle_Deg_f32_Watch > SWC_TAS_DW.max_grad) {
            SWC_TAS_DW.max_grad = TAS_Vernier_Angle_Deg_f32_Watch;
          } else if (TAS_Vernier_Angle_Deg_f32_Watch < SWC_TAS_DW.min_grad) {
            SWC_TAS_DW.min_grad = TAS_Vernier_Angle_Deg_f32_Watch;
          }
        } else {
          /* case IN_en: */
          SWC_TAS_DW.is_QM = SWC_TAS_IN_du;
          if (TAS_Vernier_Angle_Deg_f32_Watch > SWC_TAS_DW.max_grad) {
            SWC_TAS_DW.max_grad = TAS_Vernier_Angle_Deg_f32_Watch;
          } else if (TAS_Vernier_Angle_Deg_f32_Watch < SWC_TAS_DW.min_grad) {
            SWC_TAS_DW.min_grad = TAS_Vernier_Angle_Deg_f32_Watch;
          }
        }
      }
      break;
    }

    if (guard2) {
      SWC_TAS_DW.is_INIT = SWC_TAS_IN_NO_ACTIVE_CHILD_e;
      SWC_TAS_DW.is_c11_SWC_TAS = SWC_TAS_IN_ERROR;
      TAS_SafetySts_NA_u8_Watch = 4U;
      if (((((((TAS_ec_af_Vernier_NA_f32_Watch > TAS_FaultCntLim_NA_f32_Cal) &&
               (TAS_ec_af_S3_NA_f32_Watch > TAS_FaultCntLim_NA_f32_Cal)) &&
              (TAS_ec_diag_S1A_NA_f32_Watch < TAS_FaultCntLim_NA_f32_Cal)) &&
             (TAS_ec_diag_S2A_NA_f32_Watch < TAS_FaultCntLim_NA_f32_Cal)) &&
            (TAS_ec_diag_S3_NA_f32_Watch < TAS_FaultCntLim_NA_f32_Cal)) &&
           (TAS_ec_af_S1A_NA_f32_Watch < TAS_FaultCntLim_NA_f32_Cal)) &&
          (TAS_ec_af_S2A_NA_f32_Watch < TAS_FaultCntLim_NA_f32_Cal)) {
        SWC_TAS_DW.ef_mg = 1U;
      }

      SWC_TAS_B.AngFollowerChoose = 0U;
    }

    if (guard1) {
      SWC_TAS_DW.is_c11_SWC_TAS = SWC_TAS_IN_Prewarning;
      TAS_SafetySts_NA_u8_Watch = 3U;
      SWC_TAS_DW.is_Prewarning = SWC_TAS_IN_en;
      SWC_TAS_DW.min_grad = TAS_Vernier_Angle_Deg_f32_Watch;
      SWC_TAS_DW.max_grad = TAS_Vernier_Angle_Deg_f32_Watch;
    }
  }

  /* MultiPortSwitch: '<S72>/Multiport Switch' */
  switch (SWC_TAS_B.AngFollowerChoose) {
   case 0:
    /* MultiPortSwitch: '<S72>/Multiport Switch' incorporates:
     *  Constant: '<S72>/Constant1'
     */
    TAS_StrAng_deg_f32_Write = 0.0F;
    break;

   case 1:
    /* MultiPortSwitch: '<S72>/Multiport Switch' incorporates:
     *  Constant: '<S72>/Constant'
     *  Product: '<S72>/Divide'
     *  Sum: '<S72>/Add'
     */
    TAS_StrAng_deg_f32_Write = (TAS_SENT1A_Follower_Deg_f32_Watch +
      TAS_SENT2A_Follower_Deg_f32_Watch) * 0.5F;
    break;

   case 2:
    /* MultiPortSwitch: '<S72>/Multiport Switch' */
    TAS_StrAng_deg_f32_Write = TAS_SENT1A_Follower_Deg_f32_Watch;
    break;

   case 3:
    /* MultiPortSwitch: '<S72>/Multiport Switch' */
    TAS_StrAng_deg_f32_Write = TAS_SENT2A_Follower_Deg_f32_Watch;
    break;

   default:
    /* MultiPortSwitch: '<S72>/Multiport Switch' */
    TAS_StrAng_deg_f32_Write = TAS_Vernier_Angle_Deg_f32_Watch;
    break;
  }

  /* End of MultiPortSwitch: '<S72>/Multiport Switch' */

  /* Sum: '<S7>/Sum1' incorporates:
   *  Sum: '<S7>/Sum'
   *  UnitDelay: '<S7>/Unit Delay'
   */
  tmp = fmodf(floorf(TAS_StrAng_deg_f32_Write * 1.048576E+6F), 4.2949673E+9F);
  rtb_Add1_h = fmodf(floorf(SWC_TAS_DW.UnitDelay_DSTATE_m * 1.048576E+6F),
                     4.2949673E+9F);

  /* Sum: '<S7>/Sum2' incorporates:
   *  Product: '<S7>/Matrix Multiply'
   *  Sum: '<S7>/Sum'
   *  Sum: '<S7>/Sum1'
   *  UnitDelay: '<S7>/Unit Delay'
   */
  SWC_TAS_DW.UnitDelay_DSTATE_m += (((real32_T)(((tmp < 0.0F) ? (-((int32_T)
    ((uint32_T)(-tmp)))) : ((int32_T)((uint32_T)tmp))) - ((rtb_Add1_h < 0.0F) ?
    (-((int32_T)((uint32_T)(-rtb_Add1_h)))) : ((int32_T)((uint32_T)rtb_Add1_h)))))
    * 9.53674316E-7F) * rtb_Divide_l;

  /* Sum: '<S7>/Sum4' incorporates:
   *  Product: '<S7>/Matrix Multiply1'
   *  UnitDelay: '<S7>/Unit Delay1'
   */
  SWC_TAS_DW.UnitDelay1_DSTATE = rtb_Sum3 - (rtb_Sum3 * rtb_Divide_l);

  /* UnitDelay: '<S8>/Unit Delay' */
  rtb_Sum3 = SWC_TAS_DW.UnitDelay_DSTATE_o;

  /* UnitDelay: '<S8>/Unit Delay1' */
  TAS_StrAngVel_degps_f32_Write = SWC_TAS_DW.UnitDelay1_DSTATE_o;

  /* Sum: '<S8>/Add' incorporates:
   *  Gain: '<S8>/Gain'
   *  UnitDelay: '<S8>/Unit Delay'
   */
  SWC_TAS_DW.UnitDelay_DSTATE_o += 0.001F * TAS_StrAngVel_degps_f32_Write;

  /* Sum: '<S8>/Subtract' incorporates:
   *  Gain: '<S8>/Gain1'
   *  Gain: '<S8>/Gain2'
   *  Gain: '<S8>/Gain3'
   *  Sum: '<S8>/Sum'
   *  Sum: '<S8>/Sum1'
   *  UnitDelay: '<S7>/Unit Delay'
   *  UnitDelay: '<S8>/Unit Delay1'
   */
  SWC_TAS_DW.UnitDelay1_DSTATE_o = TAS_StrAngVel_degps_f32_Write - ((((rtb_Sum3
    - SWC_TAS_DW.UnitDelay_DSTATE_m) * 160000.0F) + (800.0F *
    TAS_StrAngVel_degps_f32_Write)) * 0.001F);

  /* RelationalOperator: '<S4>/Relational Operator' incorporates:
   *  Constant: '<S4>/Constant'
   */
  TAS_AngCntOutLim_NA_bl_Watch = (TAS_SafetySts_NA_u8_Watch == 4);

  /* Logic: '<S4>/Logical Operator' incorporates:
   *  Constant: '<S9>/Lower Limit'
   *  Constant: '<S9>/Upper Limit'
   *  Logic: '<S9>/AND'
   *  RelationalOperator: '<S9>/Lower Test'
   *  RelationalOperator: '<S9>/Upper Test'
   */
  TAS_AngOutLim_NA_bl_Watch = ((-740.0F > TAS_StrAng_deg_f32_Write) ||
    (TAS_StrAng_deg_f32_Write > 740.0F));

  /* Logic: '<S4>/Logical Operator1' */
  TAS_AngResolutionFlt_Write.TAS_AngAbnormal = (TAS_AngCntOutLim_NA_bl_Watch ||
    TAS_AngOutLim_NA_bl_Watch);

  /* BusCreator: '<S4>/Bus Creator' incorporates:
   *  Inport: '<Root>/TAS_AngCalbra_NA_bl_Read'
   */
  TAS_AngResolutionFlt_Write.TAS_AngZeroNotCal = TAS_AngCalbra_NA_bl_Read;

  /* Logic: '<S6>/Logical Operator' incorporates:
   *  UnitDelay: '<S6>/Unit Delay1'
   */
  SWC_TAS_DW.UnitDelay1_DSTATE_b = (SWC_TAS_B.Vernier_Init == 0);

  /* Update for UnitDelay: '<S32>/Unit Delay3' incorporates:
   *  Constant: '<S32>/Constant5'
   */
  SWC_TAS_DW.UnitDelay3_DSTATE_ht = 1U;

  /* Update for Switch: '<S32>/Switch2' incorporates:
   *  UnitDelay: '<S32>/Unit Delay5'
   */
  SWC_TAS_DW.UnitDelay5_DSTATE = rtb_Product_n;

  /* Update for UnitDelay: '<S32>/Unit Delay4' incorporates:
   *  Constant: '<S32>/Constant6'
   */
  SWC_TAS_DW.UnitDelay4_DSTATE_j = 1U;

  /* Update for UnitDelay: '<S20>/Unit Delay3' incorporates:
   *  Inport: '<Root>/TAS_SENT1A_NA_u16_Read'
   */
  SWC_TAS_DW.UnitDelay3_DSTATE_i = TAS_SENT1A_NA_u16_Read;

  /* Update for UnitDelay: '<S41>/Unit Delay3' incorporates:
   *  Constant: '<S41>/Constant5'
   */
  SWC_TAS_DW.UnitDelay3_DSTATE_c = 1U;

  /* Update for Switch: '<S41>/Switch2' incorporates:
   *  UnitDelay: '<S41>/Unit Delay5'
   */
  SWC_TAS_DW.UnitDelay5_DSTATE_l = rtb_vd_pos;

  /* Update for UnitDelay: '<S41>/Unit Delay4' incorporates:
   *  Constant: '<S41>/Constant6'
   */
  SWC_TAS_DW.UnitDelay4_DSTATE_g = 1U;

  /* Update for UnitDelay: '<S21>/Unit Delay3' incorporates:
   *  Constant: '<S21>/Constant'
   *  Inport: '<Root>/TAS_SENT2A_NA_u16_Read'
   *  Sum: '<S21>/Add'
   */
  SWC_TAS_DW.UnitDelay3_DSTATE = 4094.0F - ((real32_T)TAS_SENT2A_NA_u16_Read);

  /* Update for UnitDelay: '<S50>/Unit Delay3' incorporates:
   *  Constant: '<S50>/Constant5'
   */
  SWC_TAS_DW.UnitDelay3_DSTATE_c1 = 1U;

  /* Update for Switch: '<S50>/Switch2' incorporates:
   *  UnitDelay: '<S50>/Unit Delay5'
   */
  SWC_TAS_DW.UnitDelay5_DSTATE_k = rtb_Switch_j;

  /* Update for UnitDelay: '<S50>/Unit Delay4' incorporates:
   *  Constant: '<S50>/Constant6'
   */
  SWC_TAS_DW.UnitDelay4_DSTATE_k = 1U;

  /* Update for UnitDelay: '<S22>/Unit Delay3' incorporates:
   *  Inport: '<Root>/TAS_SENT_ANG_NA_u16_Read'
   */
  SWC_TAS_DW.UnitDelay3_DSTATE_e = TAS_SENT_ANG_NA_u16_Read;

  /* Update for Delay: '<S75>/Delay2' */
  SWC_TAS_DW.Delay2_DSTATE = TAS_SENT_ANG_Follower_Deg_f32_Watch;

  /* Update for Delay: '<S75>/Delay1' incorporates:
   *  Constant: '<S75>/Constant2'
   */
  SWC_TAS_DW.Delay1_DSTATE = 1.0F;

  /* Update for UnitDelay: '<S6>/Unit Delay' */
  SWC_TAS_DW.UnitDelay_DSTATE_f = SWC_TAS_B.reset;

  /* End of Outputs for RootInportFunctionCallGenerator generated from: '<Root>/TMT_Rnbl_TAS_StrAng' */
}

/* Model step function */
void TMT_Rnbl_TAS_StrTrq(void)
{
  real32_T tmp;
  boolean_T rtb_RelationalOperator_d;

  /* RootInportFunctionCallGenerator generated from: '<Root>/TMT_Rnbl_TAS_StrTrq' incorporates:
   *  SubSystem: '<Root>/Rnbl_TAS_StrTrq'
   */
  /* Logic: '<S2>/Logical Operator' incorporates:
   *  Inport: '<Root>/TAS_SENT1_LossOfSignal_NA_bl_Read '
   *  Inport: '<Root>/TAS_SENT2_LossOfSignal_NA_bl_Read'
   */
  TAS_TrqLossOfSignal_NA_bl_Watch = (TAS_SENT1_LossOfSignal_NA_bl_Read ||
    TAS_SENT2_LossOfSignal_NA_bl_Read);

  /* Product: '<S94>/Divide' incorporates:
   *  Constant: '<S94>/Constant7'
   *  Constant: '<S95>/Constant2'
   *  Constant: '<S95>/Constant3'
   *  Inport: '<Root>/TAS_SENT1B_NA_u16_Read'
   *  Product: '<S95>/Product1'
   *  Sum: '<S95>/Add1'
   */
  TAS_T1_NA_f32_Watch = ((((real32_T)TAS_SENT1B_NA_u16_Read) * 2.0F) - 4095.0F) /
    679.833313F;

  /* Product: '<S94>/Divide1' incorporates:
   *  Constant: '<S94>/Constant2'
   *  Constant: '<S96>/Constant6'
   *  Constant: '<S96>/Constant7'
   *  Inport: '<Root>/TAS_SENT2B_NA_u16_Read'
   *  Product: '<S96>/Product1'
   *  Sum: '<S96>/Add1'
   */
  TAS_T2_NA_f32_Watch = (4095.0F - (((real32_T)TAS_SENT2B_NA_u16_Read) * 2.0F)) /
    679.833313F;

  /* Abs: '<S99>/Abs' incorporates:
   *  Sum: '<S99>/Add'
   */
  TAS_TrqSC_Err_NA_f32_Watch = fabsf(TAS_T1_NA_f32_Watch - TAS_T2_NA_f32_Watch);

  /* RelationalOperator: '<S99>/Relational Operator' incorporates:
   *  Constant: '<S99>/Thr'
   */
  rtb_RelationalOperator_d = (TAS_TrqSC_Err_NA_f32_Watch >
    TAS_TrqSynchrCheckTh_Deg_f32_Cal);

  /* Chart: '<S99>/Chart' incorporates:
   *  Constant: '<S99>/Constant2'
   */
  if (SWC_TAS_DW.is_active_c3_SWC_TAS == 0U) {
    SWC_TAS_DW.is_active_c3_SWC_TAS = 1U;
    SWC_TAS_DW.is_c3_SWC_TAS = SWC_TAS_IN_Normal;
    TAS_TrqAbnormal_NA_bl_Watch = false;
  } else {
    switch (SWC_TAS_DW.is_c3_SWC_TAS) {
     case SWC_TAS_IN_Abnormal:
      if (!rtb_RelationalOperator_d) {
        SWC_TAS_DW.is_c3_SWC_TAS = SWC_TAS_IN_Waitt;
        SWC_TAS_DW.OutCnt += 0.001F;
      } else {
        TAS_TrqAbnormal_NA_bl_Watch = true;
        SWC_TAS_DW.OutCnt = 0.0F;
      }
      break;

     case SWC_TAS_IN_Normal:
      if (rtb_RelationalOperator_d) {
        SWC_TAS_DW.is_c3_SWC_TAS = SWC_TAS_IN_Abnormal;
        TAS_TrqAbnormal_NA_bl_Watch = true;
        SWC_TAS_DW.OutCnt = 0.0F;
      } else {
        TAS_TrqAbnormal_NA_bl_Watch = false;
      }
      break;

     default:
      /* case IN_Waitt: */
      if (SWC_TAS_DW.OutCnt > TAS_TrqFltTimeTh_Sec_f32_Cal) {
        SWC_TAS_DW.is_c3_SWC_TAS = SWC_TAS_IN_Normal;
        TAS_TrqAbnormal_NA_bl_Watch = false;
      } else if (rtb_RelationalOperator_d) {
        SWC_TAS_DW.is_c3_SWC_TAS = SWC_TAS_IN_Abnormal;
        TAS_TrqAbnormal_NA_bl_Watch = true;
        SWC_TAS_DW.OutCnt = 0.0F;
      } else {
        SWC_TAS_DW.OutCnt += 0.001F;
      }
      break;
    }
  }

  /* End of Chart: '<S99>/Chart' */

  /* Logic: '<S93>/Logical Operator' */
  TAS_TrqResolutionFlt_write.TAS_TrqAbnormal = (TAS_TrqAbnormal_NA_bl_Watch ||
    TAS_TrqLossOfSignal_NA_bl_Watch);

  /* If: '<S94>/If' */
  if (!TAS_TrqAbnormal_NA_bl_Watch) {
    /* Outputs for IfAction SubSystem: '<S94>/If Action Subsystem' incorporates:
     *  ActionPort: '<S97>/Action Port'
     */
    /* Switch: '<S97>/Switch' incorporates:
     *  Constant: '<S97>/Constant2'
     *  Constant: '<S97>/Constant4'
     */
    if (TAS_TrqOffset_Switch_NA_u8_Cal > 0) {
      tmp = 0.0F;
    } else {
      tmp = TAS_TrqOffset_Nm_f32_Cal;
    }

    /* End of Switch: '<S97>/Switch' */

    /* Merge: '<S94>/Merge' incorporates:
     *  Constant: '<S97>/Constant'
     *  Constant: '<S97>/Constant1'
     *  Product: '<S97>/Product'
     *  Product: '<S97>/Product1'
     *  Sum: '<S97>/Add'
     *  Sum: '<S97>/Add1'
     */
    TAS_StrTrq_Nm_f32_Write = tmp - (((TAS_T1_NA_f32_Watch + TAS_T2_NA_f32_Watch)
      * 0.5F) * TAS_TorsionBarStiff_NA_f32_Cal);

    /* End of Outputs for SubSystem: '<S94>/If Action Subsystem' */
  } else {
    /* Outputs for IfAction SubSystem: '<S94>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S98>/Action Port'
     */
    /* Merge: '<S94>/Merge' incorporates:
     *  Constant: '<S98>/Constant1'
     *  SignalConversion generated from: '<S98>/StrTrq'
     */
    TAS_StrTrq_Nm_f32_Write = 0.0F;

    /* End of Outputs for SubSystem: '<S94>/If Action Subsystem1' */
  }

  /* End of If: '<S94>/If' */
  /* End of Outputs for RootInportFunctionCallGenerator generated from: '<Root>/TMT_Rnbl_TAS_StrTrq' */
}

/* Model initialize function */
void SWC_TAS_initialize(void)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatus(SWC_TAS_M, (NULL));

  /* block I/O */
  (void) memset(((void *) &SWC_TAS_B), 0,
                sizeof(B_SWC_TAS_T));

  /* exported global signals */
  TAS_TrqResolutionFlt_write = SWC_TAS_rtZTAS_TrqResolutionFlt_Type;
  TAS_AngResolutionFlt_Write = SWC_TAS_rtZTAS_AngResolutionFlt_Type;
  TAS_T1_NA_f32_Watch = 0.0F;
  TAS_T2_NA_f32_Watch = 0.0F;
  TAS_TrqSC_Err_NA_f32_Watch = 0.0F;
  TAS_StrTrq_Nm_f32_Write = 0.0F;
  TAS_SENT1A_Follower_Deg_f32_Watch = 0.0F;
  TAS_SENT2A_Follower_Deg_f32_Watch = 0.0F;
  TAS_SENT_ANG_Follower_Deg_f32_Watch = 0.0F;
  TAS_Vernier_Angle_Deg_f32_Watch = 0.0F;
  TAS_ec_af_S1A_NA_f32_Watch = 0.0F;
  TAS_ec_af_S2A_NA_f32_Watch = 0.0F;
  TAS_ec_af_S3_NA_f32_Watch = 0.0F;
  TAS_ec_af_Vernier_NA_f32_Watch = 0.0F;
  TAS_ec_diag_S1A_NA_f32_Watch = 0.0F;
  TAS_ec_diag_S2A_NA_f32_Watch = 0.0F;
  TAS_ec_diag_S3_NA_f32_Watch = 0.0F;
  TAS_StrAng_deg_f32_Write = 0.0F;
  TAS_StrAngVel_degps_f32_Write = 0.0F;
  TAS_SafetySts_NA_u8_Watch = 0U;
  TAS_TrqLossOfSignal_NA_bl_Watch = false;
  TAS_TrqAbnormal_NA_bl_Watch = false;
  TAS_Vres_FD_NA_bl_Watch = false;
  TAS_LossOfSignal_NA_bl_Watch = false;
  TAS_AngCntOutLim_NA_bl_Watch = false;
  TAS_AngOutLim_NA_bl_Watch = false;

  /* states (dwork) */
  (void) memset((void *)&SWC_TAS_DW, 0,
                sizeof(DW_SWC_TAS_T));

  /* external inputs */
  TAS_SENT1A_NA_u16_Read = 0U;
  TAS_SENT2A_NA_u16_Read = 0U;
  TAS_SENT1B_NA_u16_Read = 0U;
  TAS_SENT2B_NA_u16_Read = 0U;
  TAS_SENT_ANG_NA_u16_Read = 0U;
  TAS_AngOffset_deg_f32_Read = 0.0F;
  TAS_AngCalbra_NA_bl_Read = false;
  TAS_SENT1_LossOfSignal_NA_bl_Read = false;
  TAS_SENT2_LossOfSignal_NA_bl_Read = false;
  TAS_SENT3_LossOfSignal_NA_bl_Read = false;

  /* SystemInitialize for RootInportFunctionCallGenerator generated from: '<Root>/TMT_Rnbl_TAS_StrTrq' incorporates:
   *  SubSystem: '<Root>/Rnbl_TAS_StrTrq'
   */
  /* SystemInitialize for Merge: '<S94>/Merge' */
  TAS_StrTrq_Nm_f32_Write = 0.0F;

  /* SystemInitialize for Chart: '<S99>/Chart' */
  SWC_TAS_DW.is_active_c3_SWC_TAS = 0U;
  SWC_TAS_DW.is_c3_SWC_TAS = SWC_TAS_IN_NO_ACTIVE_CHILD_e;
  SWC_TAS_DW.OutCnt = 0.0F;
  TAS_TrqAbnormal_NA_bl_Watch = false;

  /* End of SystemInitialize for RootInportFunctionCallGenerator generated from: '<Root>/TMT_Rnbl_TAS_StrTrq' */

  /* SystemInitialize for RootInportFunctionCallGenerator generated from: '<Root>/TMT_Rnbl_TAS_StrAng' incorporates:
   *  SubSystem: '<Root>/Rnbl_TAS_StrAng'
   */
  /* SystemInitialize for Chart: '<S20>/Chart' */
  SWC_TAS_Chart_Init(&SWC_TAS_B.SENT0_l, &SWC_TAS_B.Vernier0_g,
                     &SWC_TAS_DW.sf_Chart);

  /* SystemInitialize for Chart: '<S21>/Chart' */
  SWC_TAS_DW.is_active_c6_SWC_TAS = 0U;
  SWC_TAS_DW.is_c6_SWC_TAS = SWC_TAS_IN_NO_ACTIVE_CHILD_e;
  SWC_TAS_B.SENT0 = 0.0F;
  SWC_TAS_B.Vernier0_m = 0.0F;

  /* SystemInitialize for Chart: '<S22>/Chart' */
  SWC_TAS_Chart_Init(&SWC_TAS_B.SENT0_i, &SWC_TAS_B.Vernier0,
                     &SWC_TAS_DW.sf_Chart_h);

  /* SystemInitialize for Chart: '<S6>/StateSupervisor' */
  SWC_TAS_DW.is_INIT = SWC_TAS_IN_NO_ACTIVE_CHILD_e;
  SWC_TAS_DW.is_Prewarning = SWC_TAS_IN_NO_ACTIVE_CHILD_e;
  SWC_TAS_DW.is_QM = SWC_TAS_IN_NO_ACTIVE_CHILD_e;
  SWC_TAS_DW.is_active_c11_SWC_TAS = 0U;
  SWC_TAS_DW.is_c11_SWC_TAS = SWC_TAS_IN_NO_ACTIVE_CHILD_e;
  SWC_TAS_DW.ec_af_init = 0U;
  SWC_TAS_DW.Cnt = 0U;
  SWC_TAS_DW.ef_mg = 0U;
  SWC_TAS_DW.max_grad = 0.0F;
  SWC_TAS_DW.min_grad = 0.0F;
  TAS_SafetySts_NA_u8_Watch = 0U;
  SWC_TAS_B.AngFollowerChoose = 0U;
  SWC_TAS_B.reset = 0U;
  SWC_TAS_B.Vernier_Init = 0U;

  /* End of SystemInitialize for RootInportFunctionCallGenerator generated from: '<Root>/TMT_Rnbl_TAS_StrAng' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
