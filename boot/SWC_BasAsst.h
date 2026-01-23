/*
 * File: SWC_BasAsst.h
 *
 * Code generated for Simulink model 'SWC_BasAsst'.
 *
 * Model version                  : 3.94
 * Simulink Coder version         : 9.5 (R2021a) 14-Nov-2020
 * C/C++ source code generated on : Fri Nov 29 16:06:53 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Renesas->RH850
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_SWC_BasAsst_h_
#define RTW_HEADER_SWC_BasAsst_h_
#include <math.h>
#include <stddef.h>
#include <string.h>
#ifndef SWC_BasAsst_COMMON_INCLUDES_
#define SWC_BasAsst_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* SWC_BasAsst_COMMON_INCLUDES_ */

/* Model Code Variants */

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

/* Forward declaration for rtModel */
typedef struct tag_RTM_SWC_BasAsst_T RT_MODEL_SWC_BasAsst_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real32_T UnitDelay2_DSTATE;          /* '<S8>/Unit Delay2' */
  real32_T UnitDelay1_DSTATE;          /* '<S8>/Unit Delay1' */
  real32_T UnitDelay_DSTATE;           /* '<S21>/Unit Delay' */
  real32_T UnitDelay1_DSTATE_a;        /* '<S21>/Unit Delay1' */
} DW_SWC_BasAsst_T;

/* Invariant block signals (default storage) */
typedef struct {
  const real32_T MathFunction2;        /* '<S23>/Math Function2' */
  const real32_T MathFunction3;        /* '<S23>/Math Function3' */
  const real32_T MathFunction2_n;      /* '<S24>/Math Function2' */
  const real32_T MathFunction3_n;      /* '<S24>/Math Function3' */
  const real32_T MathFunction2_g;      /* '<S25>/Math Function2' */
  const real32_T MathFunction3_m;      /* '<S25>/Math Function3' */
  const real32_T MathFunction2_m;      /* '<S26>/Math Function2' */
  const real32_T MathFunction3_k;      /* '<S26>/Math Function3' */
  const real32_T MathFunction2_l;      /* '<S27>/Math Function2' */
  const real32_T MathFunction3_p;      /* '<S27>/Math Function3' */
  const real32_T MathFunction2_p;      /* '<S28>/Math Function2' */
  const real32_T MathFunction3_o;      /* '<S28>/Math Function3' */
} ConstB_SWC_BasAsst_T;

/* Real-time Model Data Structure */
struct tag_RTM_SWC_BasAsst_T {
  const char_T * volatile errorStatus;
};

/* Block states (default storage) */
extern DW_SWC_BasAsst_T SWC_BasAsst_DW;
extern const ConstB_SWC_BasAsst_T SWC_BasAsst_ConstB;/* constant block i/o */

/*
 * Exported Global Signals
 *
 * Note: Exported global signals are block signals with an exported global
 * storage class designation.  Code generation will declare the memory for
 * these signals and export their symbols.
 *
 */
extern real32_T BA_StrTrq_Nm_f32_Read; /* '<Root>/BA_StrTrq_Nm_f32_Read' */
extern real32_T BA_VehSpd_kph_f32_Read;/* '<Root>/BA_VehSpd_kph_f32_Read' */
extern real32_T BA_StrVel_degps_f32_Read;/* '<Root>/BA_StrVel_degps_f32_Read' */
extern real32_T BA_HPFTrqFilter_Nm_f32_Irv;/* '<S1>/Add' */
extern real32_T BA_LPFTrqFilter_Nm_f32_Irv;/* '<S1>/Switch' */
extern real32_T BA_HFGAsstTrq_Nm_f32_Irv;/* '<S3>/Switch' */
extern real32_T BA_Zn_warch;        /* '<S22>/Interpolation Using Prelookup3' */
extern real32_T BA_BaTrq_Nm_f32_Write; /* '<S4>/Saturation2' */
extern real32_T BA_AsstTrqSum_Nm_f32_Irv;/* '<S5>/Add' */
extern real32_T BA_BoostTrq_Nm_f32_Irv;/* '<S2>/Switch' */

/* Model entry point functions */
extern void SWC_BasAsst_initialize(void);

/* Exported entry point function */
extern void TMT_Rnbl_BA_BlendFilter(void);

/* Exported entry point function */
extern void TMT_Rnbl_BA_BoostCurve(void);

/* Exported entry point function */
extern void TMT_Rnbl_BA_TrqMonitor(void);

/* Exported entry point function */
extern void TMT_Rnbl_BA_NotchFilter(void);

/* Exported entry point function */
extern void TMT_Rnbl_BA_HighFreqAsst(void);

/* Exported data declaration */

/* Custom Memory Section */
#ifndef CAL_SEG
#define CAL_SEG                        __attribute__ ((section(".CalSection")))
#endif

/* Declaration for custom storage class: CustomParameter */
extern volatile real32_T BA_BC_VehSpd_kph_f32_a12_Cal[12];/* Referenced by:
                                                           * '<S22>/Prelookup2'
                                                           * '<S12>/Boost_Curve_P0_Interpolation'
                                                           * '<S12>/Boost_Curve_P1_Interpolation'
                                                           * '<S12>/Boost_Curve_P2_Interpolation'
                                                           * '<S12>/Boost_Curve_P3_Interpolation'
                                                           * '<S12>/Boost_Curve_P4_Interpolation'
                                                           * '<S12>/Boost_Curve_P5_Interpolation'
                                                           * '<S12>/Boost_Curve_PD_Interpolation'
                                                           */
extern volatile real32_T BA_BF_CutoffFreq_Hz_f32_a11_Cal[12];
                       /* Referenced by: '<S6>/Interpolation Using Prelookup' */
extern volatile real32_T BA_BF_VehSpd_kph_f32_a11_Cal[12];/* Referenced by: '<S6>/Prelookup' */
extern volatile real32_T BA_BoostFac_f32_a12_Cal;/* Referenced by: '<S10>/Constant1' */
extern volatile real32_T BA_HFGFac_f32_a1_Cal;/* Referenced by: '<S3>/Gain' */
extern volatile real32_T BA_HFG_StrTrq_Nm_f32_a10_Cal[10];/* Referenced by: '<S20>/Prelookup' */
extern volatile real32_T BA_HFG_TableData_NA_f32_a10a12_Cal[120];
                      /* Referenced by: '<S20>/Interpolation Using Prelookup' */
extern volatile real32_T BA_HFlim_f32_a1_Cal;/* Referenced by: '<S3>/Saturation' */
extern volatile real32_T BA_HPG_VehSpd_kph_f32_a12_Cal[12];/* Referenced by: '<S20>/Prelookup1' */
extern volatile real32_T BA_LinearAsstGain_NA_f32_Cal;/* Referenced by: '<S11>/Constant' */
extern volatile real32_T BA_NF_Fd_a5b12_f32_Cal[60];
                     /* Referenced by: '<S22>/Interpolation Using Prelookup2' */
extern volatile real32_T BA_NF_Fn_a5b12_f32_Cal[60];
                     /* Referenced by: '<S22>/Interpolation Using Prelookup1' */
extern volatile real32_T BA_NF_Zd_a5b12_f32_Cal[60];
                     /* Referenced by: '<S22>/Interpolation Using Prelookup4' */
extern volatile real32_T BA_NF_Zn_a5b12_f32_Cal[60];
                     /* Referenced by: '<S22>/Interpolation Using Prelookup3' */
extern volatile real32_T BA_P0_f32_a12_Cal[12];
                       /* Referenced by: '<S12>/Boost_Curve_P0_Interpolation' */
extern volatile real32_T BA_P1_f32_a12_Cal[12];
                       /* Referenced by: '<S12>/Boost_Curve_P1_Interpolation' */
extern volatile real32_T BA_P2_f32_a12_Cal[12];
                       /* Referenced by: '<S12>/Boost_Curve_P2_Interpolation' */
extern volatile real32_T BA_P3_f32_a12_Cal[12];
                       /* Referenced by: '<S12>/Boost_Curve_P3_Interpolation' */
extern volatile real32_T BA_P4_f32_a12_Cal[12];
                       /* Referenced by: '<S12>/Boost_Curve_P4_Interpolation' */
extern volatile real32_T BA_P5_f32_a12_Cal[12];
                       /* Referenced by: '<S12>/Boost_Curve_P5_Interpolation' */
extern volatile real32_T BA_PD_f32_a12_Cal[12];
                       /* Referenced by: '<S12>/Boost_Curve_PD_Interpolation' */
extern volatile real32_T BA_StrVel_degps_BPK_f32_a4_Cal[5];/* Referenced by: '<S22>/Prelookup1' */
extern volatile boolean_T BA_Switch_HFG_NA_bl_Cal;/* Referenced by: '<S3>/Constant' */
extern volatile boolean_T BA_Switch_LinearAsst_NA_bl_Cal;/* Referenced by: '<S2>/Constant' */
extern volatile boolean_T BA_Switch_NFOut_NA_bl_Cal;/* Referenced by: '<S4>/Constant2' */
extern volatile boolean_T BA_Switch_StrLPF_bl_Cal;/* Referenced by: '<S1>/Constant' */

/* Real-time Model object */
extern RT_MODEL_SWC_BasAsst_T *const SWC_BasAsst_M;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S9>/Display' : Unused code path elimination
 * Block '<S19>/Gain' : Eliminated nontunable gain of 1
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
 * '<Root>' : 'SWC_BasAsst'
 * '<S1>'   : 'SWC_BasAsst/Rnbl_BA_BlendFilter'
 * '<S2>'   : 'SWC_BasAsst/Rnbl_BA_BoostCurve'
 * '<S3>'   : 'SWC_BasAsst/Rnbl_BA_HighFreqAsst'
 * '<S4>'   : 'SWC_BasAsst/Rnbl_BA_NotchFilter'
 * '<S5>'   : 'SWC_BasAsst/Rnbl_BA_TrqMonitor'
 * '<S6>'   : 'SWC_BasAsst/Rnbl_BA_BlendFilter/BF_Map'
 * '<S7>'   : 'SWC_BasAsst/Rnbl_BA_BlendFilter/LowPassFilter'
 * '<S8>'   : 'SWC_BasAsst/Rnbl_BA_BlendFilter/LowPassFilter/1stDigitalFilter_IIRLOOKUP_single'
 * '<S9>'   : 'SWC_BasAsst/Rnbl_BA_BlendFilter/LowPassFilter/1stDigitalFilter_IIRLOOKUP_single/Subsystem2'
 * '<S10>'  : 'SWC_BasAsst/Rnbl_BA_BoostCurve/BoostCurve'
 * '<S11>'  : 'SWC_BasAsst/Rnbl_BA_BoostCurve/LinearAsstGain'
 * '<S12>'  : 'SWC_BasAsst/Rnbl_BA_BoostCurve/BoostCurve/CALCULATION_OF_BOOST_CURVE_VARIABLES '
 * '<S13>'  : 'SWC_BasAsst/Rnbl_BA_BoostCurve/BoostCurve/LOW-FREQUENCY_ASSISTANCE_TORQUE_CALCULATION'
 * '<S14>'  : 'SWC_BasAsst/Rnbl_BA_BoostCurve/BoostCurve/LOW-FREQUENCY_ASSISTANCE_TORQUE_CALCULATION/Boost_Curve_Section_1'
 * '<S15>'  : 'SWC_BasAsst/Rnbl_BA_BoostCurve/BoostCurve/LOW-FREQUENCY_ASSISTANCE_TORQUE_CALCULATION/Boost_Curve_Section_2'
 * '<S16>'  : 'SWC_BasAsst/Rnbl_BA_BoostCurve/BoostCurve/LOW-FREQUENCY_ASSISTANCE_TORQUE_CALCULATION/Boost_Curve_Section_3'
 * '<S17>'  : 'SWC_BasAsst/Rnbl_BA_BoostCurve/BoostCurve/LOW-FREQUENCY_ASSISTANCE_TORQUE_CALCULATION/Boost_Curve_Section_4'
 * '<S18>'  : 'SWC_BasAsst/Rnbl_BA_BoostCurve/BoostCurve/LOW-FREQUENCY_ASSISTANCE_TORQUE_CALCULATION/Boost_Curve_Section_5'
 * '<S19>'  : 'SWC_BasAsst/Rnbl_BA_BoostCurve/BoostCurve/LOW-FREQUENCY_ASSISTANCE_TORQUE_CALCULATION/Boost_Curve_Section_Selection'
 * '<S20>'  : 'SWC_BasAsst/Rnbl_BA_HighFreqAsst/HighFreqGain'
 * '<S21>'  : 'SWC_BasAsst/Rnbl_BA_NotchFilter/2ndDigitalNotchFilter_Static'
 * '<S22>'  : 'SWC_BasAsst/Rnbl_BA_NotchFilter/Subsystem'
 * '<S23>'  : 'SWC_BasAsst/Rnbl_BA_NotchFilter/2ndDigitalNotchFilter_Static/A0'
 * '<S24>'  : 'SWC_BasAsst/Rnbl_BA_NotchFilter/2ndDigitalNotchFilter_Static/A1'
 * '<S25>'  : 'SWC_BasAsst/Rnbl_BA_NotchFilter/2ndDigitalNotchFilter_Static/A2'
 * '<S26>'  : 'SWC_BasAsst/Rnbl_BA_NotchFilter/2ndDigitalNotchFilter_Static/B0'
 * '<S27>'  : 'SWC_BasAsst/Rnbl_BA_NotchFilter/2ndDigitalNotchFilter_Static/B1'
 * '<S28>'  : 'SWC_BasAsst/Rnbl_BA_NotchFilter/2ndDigitalNotchFilter_Static/B2'
 */
#endif                                 /* RTW_HEADER_SWC_BasAsst_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
