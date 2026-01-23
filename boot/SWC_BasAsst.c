/*
 * File: SWC_BasAsst.c
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

#include "SWC_BasAsst.h"

/* Exported block signals */
real32_T BA_StrTrq_Nm_f32_Read;        /* '<Root>/BA_StrTrq_Nm_f32_Read' */
real32_T BA_VehSpd_kph_f32_Read;       /* '<Root>/BA_VehSpd_kph_f32_Read' */
real32_T BA_StrVel_degps_f32_Read;     /* '<Root>/BA_StrVel_degps_f32_Read' */
real32_T BA_HPFTrqFilter_Nm_f32_Irv;   /* '<S1>/Add' */
real32_T BA_LPFTrqFilter_Nm_f32_Irv;   /* '<S1>/Switch' */
real32_T BA_HFGAsstTrq_Nm_f32_Irv;     /* '<S3>/Switch' */
real32_T BA_Zn_warch;               /* '<S22>/Interpolation Using Prelookup3' */
real32_T BA_BaTrq_Nm_f32_Write;        /* '<S4>/Saturation2' */
real32_T BA_AsstTrqSum_Nm_f32_Irv;     /* '<S5>/Add' */
real32_T BA_BoostTrq_Nm_f32_Irv;       /* '<S2>/Switch' */

/* Exported data definition */

/* Custom Memory Section */
#ifndef CAL_SEG
#define CAL_SEG                        __attribute__ ((section(".CalSection")))
#endif

/* Definition for custom storage class: CustomParameter */
volatile real32_T BA_BC_VehSpd_kph_f32_a12_Cal[12] = { 0.0F, 5.0F, 10.0F, 15.0F,
  25.0F, 35.0F, 50.0F, 70.0F, 90.0F, 120.0F, 150.0F, 190.0F } ;/* Referenced by:
                                                                * '<S22>/Prelookup2'
                                                                * '<S12>/Boost_Curve_P0_Interpolation'
                                                                * '<S12>/Boost_Curve_P1_Interpolation'
                                                                * '<S12>/Boost_Curve_P2_Interpolation'
                                                                * '<S12>/Boost_Curve_P3_Interpolation'
                                                                * '<S12>/Boost_Curve_P4_Interpolation'
                                                                * '<S12>/Boost_Curve_P5_Interpolation'
                                                                * '<S12>/Boost_Curve_PD_Interpolation'
                                                                */

volatile real32_T BA_BF_CutoffFreq_Hz_f32_a11_Cal[12] = { 15.0F, 13.4F, 13.4F,
  13.5F, 13.7F, 13.9F, 14.0F, 16.0F, 16.8F, 17.0F, 18.0F, 18.0F } ;
                       /* Referenced by: '<S6>/Interpolation Using Prelookup' */

volatile real32_T BA_BF_VehSpd_kph_f32_a11_Cal[12] = { 0.0F, 5.0F, 10.0F, 15.0F,
  25.0F, 35.0F, 50.0F, 70.0F, 90.0F, 120.0F, 150.0F, 190.0F } ;/* Referenced by: '<S6>/Prelookup' */

volatile real32_T BA_BoostFac_f32_a12_Cal = 0.1F;/* Referenced by: '<S10>/Constant1' */
volatile real32_T BA_HFGFac_f32_a1_Cal = 1.0F;/* Referenced by: '<S3>/Gain' */
volatile real32_T BA_HFG_StrTrq_Nm_f32_a10_Cal[10] = { 0.0F, 0.9F, 1.4F, 2.0F,
  2.5F, 3.0F, 3.6F, 4.4F, 5.0F, 5.9F } ;/* Referenced by: '<S20>/Prelookup' */

volatile real32_T BA_HFG_TableData_NA_f32_a10a12_Cal[120] = { 1.9F, 1.9F, 1.9F,
  1.9F, 2.0F, 2.1F, 2.2F, 2.2F, 2.2F, 2.2F, 1.8F, 1.8F, 1.8F, 1.8F, 1.9F, 2.0F,
  2.1F, 2.1F, 2.1F, 2.1F, 1.75F, 1.75F, 1.75F, 1.75F, 1.85F, 1.95F, 2.05F, 2.05F,
  2.05F, 2.05F, 1.6F, 1.6F, 1.6F, 1.6F, 1.7F, 1.8F, 1.9F, 1.9F, 1.9F, 1.9F, 1.5F,
  1.5F, 1.5F, 1.5F, 1.6F, 1.7F, 1.8F, 1.8F, 1.8F, 1.8F, 1.4F, 1.4F, 1.4F, 1.4F,
  1.5F, 1.6F, 1.7F, 1.7F, 1.7F, 1.7F, 1.0F, 1.0F, 1.0F, 1.0F, 1.1F, 1.2F, 1.3F,
  1.3F, 1.3F, 1.3F, 0.569884F, 0.61558F, 0.640966F, 0.67143F, 0.696816F,
  0.808142F, 0.941734F, 1.119856F, 1.14803398F, 1.19030094F, 0.524903F,
  0.568986F, 0.593476F, 0.622864F, 0.647354F, 0.761093F, 0.897579F, 1.07956F,
  1.10837698F, 1.15160203F, 0.457432F, 0.499095F, 0.522241F, 0.550016F,
  0.573162F, 0.690518F, 0.831346F, 1.01911604F, 1.04889095F, 1.09355402F,
  0.389961F, 0.429204F, 0.451006F, 0.477168F, 0.498969F, 0.619944F, 0.765113F,
  0.958673F, 0.989406F, 1.03550601F, 0.3F, 0.336016F, 0.356026F, 0.380037F,
  0.400046F, 0.525845F, 0.676803F, 0.878081F, 0.910092F, 0.958109F } ;
                      /* Referenced by: '<S20>/Interpolation Using Prelookup' */

volatile real32_T BA_HFlim_f32_a1_Cal = 100.0F;/* Referenced by: '<S3>/Saturation' */
volatile real32_T BA_HPG_VehSpd_kph_f32_a12_Cal[12] = { 0.0F, 5.0F, 10.0F, 15.0F,
  25.0F, 35.0F, 50.0F, 70.0F, 90.0F, 120.0F, 150.0F, 190.0F } ;/* Referenced by: '<S20>/Prelookup1' */

volatile real32_T BA_LinearAsstGain_NA_f32_Cal = 0.0F;/* Referenced by: '<S11>/Constant' */
volatile real32_T BA_NF_Fd_a5b12_f32_Cal[60] = { 15.0F, 15.0F, 15.0F, 15.0F,
  15.0F, 15.0F, 15.0F, 15.0F, 15.0F, 15.0F, 15.0F, 15.0F, 15.0F, 15.0F, 15.0F,
  15.0F, 15.0F, 15.0F, 15.0F, 15.0F, 15.0F, 15.0F, 15.0F, 15.0F, 15.0F, 15.0F,
  15.0F, 15.0F, 15.0F, 15.0F, 15.0F, 15.0F, 15.0F, 15.0F, 15.0F, 15.0F, 15.0F,
  15.0F, 15.0F, 15.0F, 15.0F, 15.0F, 15.0F, 15.0F, 15.0F, 15.0F, 15.0F, 15.0F,
  15.0F, 15.0F, 15.0F, 15.0F, 15.0F, 15.0F, 15.0F, 15.0F, 15.0F, 15.0F, 15.0F,
  15.0F } ;          /* Referenced by: '<S22>/Interpolation Using Prelookup2' */

volatile real32_T BA_NF_Fn_a5b12_f32_Cal[60] = { 13.0F, 13.0F, 13.0F, 13.0F,
  13.0F, 13.0F, 13.0F, 13.0F, 13.0F, 13.0F, 13.0F, 13.0F, 13.0F, 13.0F, 13.0F,
  13.0F, 13.0F, 13.0F, 13.0F, 13.0F, 13.0F, 13.0F, 13.0F, 13.0F, 13.0F, 13.0F,
  13.0F, 13.0F, 13.0F, 13.0F, 13.0F, 13.0F, 13.0F, 13.0F, 13.0F, 13.0F, 13.0F,
  13.0F, 13.0F, 13.0F, 13.0F, 13.0F, 13.0F, 13.0F, 13.0F, 13.0F, 13.0F, 13.0F,
  13.0F, 13.0F, 13.0F, 13.0F, 13.0F, 13.0F, 13.0F, 13.0F, 13.0F, 13.0F, 13.0F,
  13.0F } ;          /* Referenced by: '<S22>/Interpolation Using Prelookup1' */

volatile real32_T BA_NF_Zd_a5b12_f32_Cal[60] = { 5.0F, 5.0F, 6.0F, 6.0F, 6.0F,
  6.0F, 6.0F, 5.0F, 5.0F, 5.0F, 6.0F, 6.0F, 5.0F, 5.0F, 5.0F, 6.0F, 6.0F, 6.0F,
  6.0F, 6.0F, 6.0F, 6.0F, 6.0F, 6.0F, 6.0F, 6.0F, 6.0F, 6.0F, 6.0F, 6.0F, 6.0F,
  6.0F, 6.0F, 6.0F, 6.0F, 6.0F, 6.0F, 6.0F, 6.0F, 6.0F, 6.0F, 6.0F, 6.0F, 6.0F,
  6.0F, 6.0F, 6.0F, 6.0F, 6.0F, 6.0F, 6.0F, 6.0F, 6.0F, 6.0F, 6.0F, 6.0F, 6.0F,
  6.0F, 6.0F, 6.0F } ;
                     /* Referenced by: '<S22>/Interpolation Using Prelookup4' */

volatile real32_T BA_NF_Zn_a5b12_f32_Cal[60] = { 1.0F, 1.0F, 0.930769F,
  0.792308F, 0.7F, 1.0F, 1.0F, 0.4F, 0.4F, 0.4F, 1.0F, 1.0F, 0.4F, 0.4F, 0.4F,
  1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.06666696F, 1.06666696F, 1.06666696F,
  1.06666696F, 1.06666696F, 1.1F, 1.1F, 1.1F, 1.1F, 1.1F, 1.2F, 1.2F, 1.2F, 1.2F,
  1.2F, 1.3F, 1.3F, 1.3F, 1.3F, 1.3F, 1.4F, 1.4F, 1.4F, 1.4F, 1.4F, 1.5F, 1.5F,
  1.5F, 1.5F, 1.5F, 1.5F, 1.5F, 1.5F, 1.5F, 1.5F, 1.5F, 1.5F, 1.5F, 1.5F, 1.5F }
;                    /* Referenced by: '<S22>/Interpolation Using Prelookup3' */

volatile real32_T BA_P0_f32_a12_Cal[12] = { 0.1F, 0.13F, 0.15F, 0.17F, 0.18F,
  0.19F, 0.2F, 0.23F, 0.25F, 0.28F, 0.30F, 0.35F } ;
                       /* Referenced by: '<S12>/Boost_Curve_P0_Interpolation' */

volatile real32_T BA_P1_f32_a12_Cal[12] = { 0.4F, 0.5F, 0.55F, 0.6F, 0.65F,
  0.7F, 0.75F, 0.8F, 0.85F, 0.9F, 0.95F, 0.95F } ;
                       /* Referenced by: '<S12>/Boost_Curve_P1_Interpolation' */

volatile real32_T BA_P2_f32_a12_Cal[12] = { 13.0F, 10.0F, 9.0F, 8.5F, 8.0F, 7.5F,
  7.0F, 6.2F, 5.5F, 5.0F, 4.8F, 4.5F } ;
                       /* Referenced by: '<S12>/Boost_Curve_P2_Interpolation' */

volatile real32_T BA_P3_f32_a12_Cal[12] = { 0.6F, 0.65F, 0.7F, 0.85F, 1.0F,
  1.1F, 1.12F, 1.16F, 1.20F, 1.23F, 1.28F, 1.36F } ;
                       /* Referenced by: '<S12>/Boost_Curve_P3_Interpolation' */

volatile real32_T BA_P4_f32_a12_Cal[12] = { 0.8F, 1.25F, 1.28F, 1.3F, 1.32F,
  1.34F, 1.36F, 1.4F, 1.45F, 1.5F, 1.55F, 1.6F } ;
                       /* Referenced by: '<S12>/Boost_Curve_P4_Interpolation' */

volatile real32_T BA_P5_f32_a12_Cal[12] = { 28.0F, 26.0F, 24.0F, 23.0F,
  21.0F, 19.0F, 17.0F, 15.0F, 13.0F, 11.0F, 10.0F,
  8.0F } ;            /* Referenced by: '<S12>/Boost_Curve_P5_Interpolation' */

volatile real32_T BA_PD_f32_a12_Cal[12] = { 1.0F, 0.8F,
  0.7F, 0.65F, 0.6F, 0.45F, 0.4F, 0.3F,
  0.25F, 0.2F, 0.1F, 0.1F } ;
                       /* Referenced by: '<S12>/Boost_Curve_PD_Interpolation' */

volatile real32_T BA_StrVel_degps_BPK_f32_a4_Cal[5] = { 0.0F, 150.0F, 300.0F,
  600.0F, 800.0F } ;                   /* Referenced by: '<S22>/Prelookup1' */

volatile boolean_T BA_Switch_HFG_NA_bl_Cal = 1;/* Referenced by: '<S3>/Constant' */
volatile boolean_T BA_Switch_LinearAsst_NA_bl_Cal = 0;/* Referenced by: '<S2>/Constant' */
volatile boolean_T BA_Switch_NFOut_NA_bl_Cal = 1;/* Referenced by: '<S4>/Constant2' */
volatile boolean_T BA_Switch_StrLPF_bl_Cal = 1;/* Referenced by: '<S1>/Constant' */

/* Invariant block signals (default storage) */
const ConstB_SWC_BasAsst_T SWC_BasAsst_ConstB = {
  1.00000011E-6F,                      /* '<S23>/Math Function2' */
  9.86960506F,                         /* '<S23>/Math Function3' */
  1.00000011E-6F,                      /* '<S24>/Math Function2' */
  9.86960506F,                         /* '<S24>/Math Function3' */
  1.00000011E-6F,                      /* '<S25>/Math Function2' */
  9.86960506F,                         /* '<S25>/Math Function3' */
  1.00000011E-6F,                      /* '<S26>/Math Function2' */
  9.86960506F,                         /* '<S26>/Math Function3' */
  1.00000011E-6F,                      /* '<S27>/Math Function2' */
  9.86960506F,                         /* '<S27>/Math Function3' */
  1.00000011E-6F,                      /* '<S28>/Math Function2' */
  9.86960506F                          /* '<S28>/Math Function3' */
};

/* Block states (default storage) */
DW_SWC_BasAsst_T SWC_BasAsst_DW;

/* Real-time model */
static RT_MODEL_SWC_BasAsst_T SWC_BasAsst_M_;
RT_MODEL_SWC_BasAsst_T *const SWC_BasAsst_M = &SWC_BasAsst_M_;
void SWC_BasAsst_BINARYSEAR_Dda9nu0m(uint32_T *piLeft, uint32_T *piRght,
  real32_T u, const real32_T *pData, uint32_T iHi);
void SWC_BasAsst_LookUp_rea_uF5G4H1O(real32_T *pY, const real32_T *pYData,
  real32_T u, const real32_T *pUData, uint32_T iHi);
uint32_T SWC_BasAsst_plook_u32ff_binc(real32_T u, const real32_T bp[], uint32_T
  maxIndex, real32_T *fraction);
real32_T SWC_BasAsst_intrp2d_fu32fl_pw(const uint32_T bpIndex[], const real32_T
  frac[], const real32_T table[], const uint32_T stride);
uint32_T SWC_BasAsst_binsearch_u32f(real32_T u, const real32_T bp[], uint32_T
  startIndex, uint32_T maxIndex);
uint16_T SWC_BasAsst_plook_u16ff_binc(real32_T u, const real32_T bp[], uint32_T
  maxIndex, real32_T *fraction);
real32_T SWC_BasAsst_intrp1d_fu16fl_pw(uint16_T bpIndex, real32_T frac, const
  real32_T table[]);
uint16_T SWC_BasAsst_binsearch_u16f(real32_T u, const real32_T bp[], uint32_T
  startIndex, uint32_T maxIndex);
extern void Rnbl_BA_BoostCurve(void);
extern void Rnbl_BA_TrqMonitor(void);
extern void Rnbl_BA_NotchFilter(void);
extern void Rnbl_BA_HighFreqAsst(void);
extern void Rnbl_BA_TrqFilter_Init(void);
extern void Rnbl_BA_TrqFilter(void);

/* Lookup Binary Search Utility SWC_BasAsst_BINARYSEAR_Dda9nu0m */
void SWC_BasAsst_BINARYSEAR_Dda9nu0m(uint32_T *piLeft, uint32_T *piRght,
  real32_T u, const real32_T *pData, uint32_T iHi)
{
  /* Find the location of current input value in the data table. */
  *piLeft = 0U;
  *piRght = iHi;
  if (u <= pData[0] ) {
    /* Less than or equal to the smallest point in the table. */
    *piRght = 0U;
  } else if (u >= pData[iHi] ) {
    /* Greater than or equal to the largest point in the table. */
    *piLeft = iHi;
  } else {
    uint32_T i;

    /* Do a binary search. */
    while (( *piRght - *piLeft ) > 1U ) {
      /* Get the average of the left and right indices using to Floor rounding. */
      i = (*piLeft + *piRght) >> 1;

      /* Move either the right index or the left index so that */
      /*  LeftDataPoint <= CurrentValue < RightDataPoint */
      if (u < pData[i] ) {
        *piRght = i;
      } else {
        *piLeft = i;
      }
    }
  }
}

/* Lookup Utility SWC_BasAsst_LookUp_rea_uF5G4H1O */
void SWC_BasAsst_LookUp_rea_uF5G4H1O(real32_T *pY, const real32_T *pYData,
  real32_T u, const real32_T *pUData, uint32_T iHi)
{
  uint32_T iLeft;
  uint32_T iRght;
  SWC_BasAsst_BINARYSEAR_Dda9nu0m( &(iLeft), &(iRght), u, pUData, iHi);

  {
    real32_T lambda;
    if (pUData[iRght] > pUData[iLeft] ) {
      real32_T num;
      real32_T den;
      den = pUData[iRght];
      den -= pUData[iLeft];
      num = u;
      num -= pUData[iLeft];
      lambda = num / den;
    } else {
      lambda = 0.0F;
    }

    {
      real32_T yLeftCast;
      real32_T yRghtCast;
      yLeftCast = pYData[iLeft];
      yRghtCast = pYData[iRght];
      yLeftCast += lambda * ( yRghtCast - yLeftCast );
      (*pY) = yLeftCast;
    }
  }
}

uint32_T SWC_BasAsst_plook_u32ff_binc(real32_T u, const real32_T bp[], uint32_T
  maxIndex, real32_T *fraction)
{
  uint32_T bpIndex;

  /* Prelookup - Index and Fraction
     Index Search method: 'binary'
     Extrapolation method: 'Clip'
     Use previous index: 'off'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
   */
  if (u <= bp[0U]) {
    bpIndex = 0U;
    *fraction = 0.0F;
  } else if (u < bp[maxIndex]) {
    bpIndex = SWC_BasAsst_binsearch_u32f(u, bp, maxIndex >> 1U, maxIndex);
    *fraction = (u - bp[bpIndex]) / (bp[bpIndex + 1U] - bp[bpIndex]);
  } else {
    bpIndex = maxIndex - 1U;
    *fraction = 1.0F;
  }

  return bpIndex;
}

real32_T SWC_BasAsst_intrp2d_fu32fl_pw(const uint32_T bpIndex[], const real32_T
  frac[], const real32_T table[], const uint32_T stride)
{
  real32_T yL_0d0;
  real32_T yL_0d1;
  uint32_T offset_1d;

  /* Column-major Interpolation 2-D
     Canonical function name: intrp2d_fu32fl_pw
     Interpolation method: 'Linear point-slope'
     Use last breakpoint for index at or above upper limit: 'off'
     Overflow mode: 'portable wrapping'
   */
  offset_1d = (bpIndex[1U] * stride) + bpIndex[0U];
  yL_0d0 = table[offset_1d];
  yL_0d0 += (table[offset_1d + 1U] - yL_0d0) * frac[0U];
  offset_1d += stride;
  yL_0d1 = table[offset_1d];
  return (((((table[offset_1d + 1U] - yL_0d1) * frac[0U]) + yL_0d1) - yL_0d0) *
          frac[1U]) + yL_0d0;
}

uint32_T SWC_BasAsst_binsearch_u32f(real32_T u, const real32_T bp[], uint32_T
  startIndex, uint32_T maxIndex)
{
  uint32_T bpIdx;
  uint32_T bpIndex;
  uint32_T iRght;

  /* Binary Search */
  bpIdx = startIndex;
  bpIndex = 0U;
  iRght = maxIndex;
  while ((iRght - bpIndex) > 1U) {
    if (u < bp[bpIdx]) {
      iRght = bpIdx;
    } else {
      bpIndex = bpIdx;
    }

    bpIdx = ((iRght + bpIndex) >> 1U);
  }

  return bpIndex;
}

uint16_T SWC_BasAsst_plook_u16ff_binc(real32_T u, const real32_T bp[], uint32_T
  maxIndex, real32_T *fraction)
{
  uint16_T bpIndex;

  /* Prelookup - Index and Fraction
     Index Search method: 'binary'
     Extrapolation method: 'Clip'
     Use previous index: 'off'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
   */
  if (u <= bp[0U]) {
    bpIndex = 0U;
    *fraction = 0.0F;
  } else if (u < bp[maxIndex]) {
    bpIndex = SWC_BasAsst_binsearch_u16f(u, bp, maxIndex >> 1U, maxIndex);
    *fraction = (u - bp[(uint32_T)bpIndex]) / (bp[bpIndex + 1U] - bp[(uint32_T)
      bpIndex]);
  } else {
    bpIndex = (uint16_T)(maxIndex - 1U);
    *fraction = 1.0F;
  }

  return bpIndex;
}

real32_T SWC_BasAsst_intrp1d_fu16fl_pw(uint16_T bpIndex, real32_T frac, const
  real32_T table[])
{
  real32_T yL_0d0;

  /* Column-major Interpolation 1-D
     Canonical function name: intrp1d_fu16fl_pw
     Interpolation method: 'Linear point-slope'
     Use last breakpoint for index at or above upper limit: 'off'
     Overflow mode: 'portable wrapping'
   */
  yL_0d0 = table[(uint32_T)bpIndex];
  return ((table[bpIndex + 1U] - yL_0d0) * frac) + yL_0d0;
}

uint16_T SWC_BasAsst_binsearch_u16f(real32_T u, const real32_T bp[], uint32_T
  startIndex, uint32_T maxIndex)
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

  return (uint16_T)iLeft;
}

/* Output and update for function-call system: '<Root>/Rnbl_BA_BoostCurve' */
void Rnbl_BA_BoostCurve(void)
{
  /* local block i/o variables */
  real32_T rtb_Boost_Curve_P2_Interpolatio;
  real32_T rtb_Boost_Curve_PD_Interpolatio;
  real32_T rtb_Boost_Curve_P5_Interpolatio;
  real32_T rtb_Boost_Curve_P0_Interpolatio;
  real32_T rtb_Boost_Curve_P1_Interpolatio;
  real32_T rtb_Boost_Curve_P4_Interpolatio;
  real32_T rtb_Boost_Curve_P3_Interpolatio;
  real32_T rtb_Abs;
  real32_T rtb_Product5;
  real32_T rtb_Product6_m;
  real32_T rtb_abs_bc_input;
  int16_T rtb_Gain3;
  int16_T rtb_Gain4;
  int16_T u1;
  int16_T u1_0;

  /* Abs: '<S12>/Abs' incorporates:
   *  Inport: '<Root>/BA_VehSpd_kph_f32_Read'
   */
  rtb_Abs = fabsf(BA_VehSpd_kph_f32_Read);

  /* Lookup: '<S12>/Boost_Curve_P2_Interpolation' */
  /*
   * About '<S12>/Boost_Curve_P2_Interpolation':
   * Input0  Data Type:  Floating Point real32_T
   * Output0 Data Type:  Floating Point real32_T
   * Saturation Mode: Saturate
   * Lookup Method: Linear_Endpoint
   *
   * XData parameter uses the same data type and scaling as Input0
   * YData parameter uses the same data type and scaling as Output0
   */
  SWC_BasAsst_LookUp_rea_uF5G4H1O( &(rtb_Boost_Curve_P2_Interpolatio),
    ((real32_T *)&(BA_P2_f32_a12_Cal[0])), rtb_Abs, ((real32_T *)
    &(BA_BC_VehSpd_kph_f32_a12_Cal[0])), 11U);

  /* Lookup: '<S12>/Boost_Curve_PD_Interpolation' */
  /*
   * About '<S12>/Boost_Curve_PD_Interpolation':
   * Input0  Data Type:  Floating Point real32_T
   * Output0 Data Type:  Floating Point real32_T
   * Saturation Mode: Saturate
   * Lookup Method: Linear_Endpoint
   *
   * XData parameter uses the same data type and scaling as Input0
   * YData parameter uses the same data type and scaling as Output0
   */
  SWC_BasAsst_LookUp_rea_uF5G4H1O( &(rtb_Boost_Curve_PD_Interpolatio),
    ((real32_T *)&(BA_PD_f32_a12_Cal[0])), rtb_Abs, ((real32_T *)
    &(BA_BC_VehSpd_kph_f32_a12_Cal[0])), 11U);

  /* Lookup: '<S12>/Boost_Curve_P5_Interpolation' */
  /*
   * About '<S12>/Boost_Curve_P5_Interpolation':
   * Input0  Data Type:  Floating Point real32_T
   * Output0 Data Type:  Floating Point real32_T
   * Saturation Mode: Saturate
   * Lookup Method: Linear_Endpoint
   *
   * XData parameter uses the same data type and scaling as Input0
   * YData parameter uses the same data type and scaling as Output0
   */
  SWC_BasAsst_LookUp_rea_uF5G4H1O( &(rtb_Boost_Curve_P5_Interpolatio),
    ((real32_T *)&(BA_P5_f32_a12_Cal[0])), rtb_Abs, ((real32_T *)
    &(BA_BC_VehSpd_kph_f32_a12_Cal[0])), 11U);

  /* Switch: '<S2>/Switch' incorporates:
   *  Constant: '<S2>/Constant'
   */
  if (BA_Switch_LinearAsst_NA_bl_Cal) {
    /* Product: '<S10>/Product' incorporates:
     *  Constant: '<S11>/Constant'
     *  Product: '<S11>/Product'
     *  Switch: '<S2>/Switch'
     */
    BA_BoostTrq_Nm_f32_Irv = BA_LPFTrqFilter_Nm_f32_Irv *
      BA_LinearAsstGain_NA_f32_Cal;
  } else {
    /* Lookup: '<S12>/Boost_Curve_P0_Interpolation' */
    /*
     * About '<S12>/Boost_Curve_P0_Interpolation':
     * Input0  Data Type:  Floating Point real32_T
     * Output0 Data Type:  Floating Point real32_T
     * Saturation Mode: Saturate
     * Lookup Method: Linear_Endpoint
     *
     * XData parameter uses the same data type and scaling as Input0
     * YData parameter uses the same data type and scaling as Output0
     */
    SWC_BasAsst_LookUp_rea_uF5G4H1O( &(rtb_Boost_Curve_P0_Interpolatio),
      ((real32_T *)&(BA_P0_f32_a12_Cal[0])), rtb_Abs, ((real32_T *)
      &(BA_BC_VehSpd_kph_f32_a12_Cal[0])), 11U);

    /* Abs: '<S13>/Abs' */
    rtb_abs_bc_input = fabsf(BA_LPFTrqFilter_Nm_f32_Irv);

    /* Lookup: '<S12>/Boost_Curve_P1_Interpolation' */
    /*
     * About '<S12>/Boost_Curve_P1_Interpolation':
     * Input0  Data Type:  Floating Point real32_T
     * Output0 Data Type:  Floating Point real32_T
     * Saturation Mode: Saturate
     * Lookup Method: Linear_Endpoint
     *
     * XData parameter uses the same data type and scaling as Input0
     * YData parameter uses the same data type and scaling as Output0
     */
    SWC_BasAsst_LookUp_rea_uF5G4H1O( &(rtb_Boost_Curve_P1_Interpolatio),
      ((real32_T *)&(BA_P1_f32_a12_Cal[0])), rtb_Abs, ((real32_T *)
      &(BA_BC_VehSpd_kph_f32_a12_Cal[0])), 11U);

    /* Lookup: '<S12>/Boost_Curve_P4_Interpolation' */
    /*
     * About '<S12>/Boost_Curve_P4_Interpolation':
     * Input0  Data Type:  Floating Point real32_T
     * Output0 Data Type:  Floating Point real32_T
     * Saturation Mode: Saturate
     * Lookup Method: Linear_Endpoint
     *
     * XData parameter uses the same data type and scaling as Input0
     * YData parameter uses the same data type and scaling as Output0
     */
    SWC_BasAsst_LookUp_rea_uF5G4H1O( &(rtb_Boost_Curve_P4_Interpolatio),
      ((real32_T *)&(BA_P4_f32_a12_Cal[0])), rtb_Abs, ((real32_T *)
      &(BA_BC_VehSpd_kph_f32_a12_Cal[0])), 11U);

    /* Lookup: '<S12>/Boost_Curve_P3_Interpolation' */
    /*
     * About '<S12>/Boost_Curve_P3_Interpolation':
     * Input0  Data Type:  Floating Point real32_T
     * Output0 Data Type:  Floating Point real32_T
     * Saturation Mode: Saturate
     * Lookup Method: Linear_Endpoint
     *
     * XData parameter uses the same data type and scaling as Input0
     * YData parameter uses the same data type and scaling as Output0
     */
    SWC_BasAsst_LookUp_rea_uF5G4H1O( &(rtb_Boost_Curve_P3_Interpolatio),
      ((real32_T *)&(BA_P3_f32_a12_Cal[0])), rtb_Abs, ((real32_T *)
      &(BA_BC_VehSpd_kph_f32_a12_Cal[0])), 11U);

    /* Sum: '<S19>/Sum1' */
    rtb_Abs = rtb_Boost_Curve_P3_Interpolatio + rtb_Boost_Curve_P4_Interpolatio;

    /* Gain: '<S19>/Gain4' incorporates:
     *  RelationalOperator: '<S19>/Relational Operator7'
     */
    rtb_Gain4 = (int16_T)((rtb_abs_bc_input >= rtb_Abs) * 5);

    /* Gain: '<S19>/Gain3' incorporates:
     *  Logic: '<S19>/Logical Operator2'
     *  RelationalOperator: '<S19>/Relational Operator5'
     *  RelationalOperator: '<S19>/Relational Operator6'
     */
    rtb_Gain3 = (int16_T)(((rtb_abs_bc_input >= rtb_Boost_Curve_P3_Interpolatio)
      && (rtb_abs_bc_input < rtb_Abs)) << 2);

    /* Sum: '<S19>/Sum' */
    rtb_Abs = rtb_Boost_Curve_P0_Interpolatio + rtb_Boost_Curve_P1_Interpolatio;

    /* MinMax: '<S19>/MinMax' incorporates:
     *  Gain: '<S19>/Gain1'
     *  Gain: '<S19>/Gain2'
     *  Logic: '<S19>/Logical Operator'
     *  Logic: '<S19>/Logical Operator1'
     *  RelationalOperator: '<S19>/Relational Operator'
     *  RelationalOperator: '<S19>/Relational Operator1'
     *  RelationalOperator: '<S19>/Relational Operator2'
     *  RelationalOperator: '<S19>/Relational Operator3'
     *  RelationalOperator: '<S19>/Relational Operator4'
     */
    u1 = (int16_T)(((rtb_abs_bc_input >= rtb_Boost_Curve_P0_Interpolatio) &&
                    (rtb_abs_bc_input < rtb_Abs)) << 1);
    if ((rtb_abs_bc_input < rtb_Boost_Curve_P0_Interpolatio) > u1) {
      u1 = 1;
    }

    u1_0 = (int16_T)(((rtb_abs_bc_input >= rtb_Abs) && (rtb_abs_bc_input <
      rtb_Boost_Curve_P3_Interpolatio)) * 3);
    if (u1 > u1_0) {
      u1_0 = u1;
    }

    if (u1_0 > rtb_Gain3) {
      rtb_Gain3 = u1_0;
    }

    if (rtb_Gain3 > rtb_Gain4) {
      rtb_Gain4 = rtb_Gain3;
    }

    /* End of MinMax: '<S19>/MinMax' */

    /* MultiPortSwitch: '<S13>/Multiport Switch' incorporates:
     *  Constant: '<S15>/Constant'
     *  Constant: '<S17>/Constant'
     *  Math: '<S15>/Math Function'
     *  Math: '<S15>/Math Function1'
     *  Math: '<S17>/Math Function1'
     *  Math: '<S17>/Math Function3'
     *  Product: '<S14>/Product'
     *  Product: '<S15>/Product'
     *  Product: '<S15>/Product1'
     *  Product: '<S15>/Product2'
     *  Product: '<S15>/Product3'
     *  Product: '<S16>/Product'
     *  Product: '<S16>/Product1'
     *  Product: '<S16>/Product2'
     *  Product: '<S16>/Product3'
     *  Product: '<S16>/Product4'
     *  Product: '<S17>/Product1'
     *  Product: '<S17>/Product3'
     *  Product: '<S17>/Product4'
     *  Product: '<S18>/Product2'
     *  Product: '<S18>/Product3'
     *  Product: '<S18>/Product4'
     *  Sum: '<S15>/Sum1'
     *  Sum: '<S15>/Sum2'
     *  Sum: '<S16>/Sum'
     *  Sum: '<S16>/Sum1'
     *  Sum: '<S16>/Sum2'
     *  Sum: '<S17>/Sum2'
     *  Sum: '<S17>/Sum3'
     *  Sum: '<S18>/Sum1'
     *  Sum: '<S18>/Sum2'
     *  Sum: '<S18>/Sum3'
     *  Sum: '<S18>/Sum4'
     *
     * About '<S15>/Math Function1':
     *  Operator: reciprocal
     *
     * About '<S17>/Math Function3':
     *  Operator: reciprocal
     */
    switch (rtb_Gain4) {
     case 1:
      rtb_Abs = rtb_abs_bc_input * rtb_Boost_Curve_PD_Interpolatio;
      break;

     case 2:
      /* Sum: '<S15>/Sum' */
      rtb_Abs = rtb_abs_bc_input - rtb_Boost_Curve_P0_Interpolatio;
      rtb_Abs = (((rtb_Abs * rtb_Abs) * (rtb_Boost_Curve_P2_Interpolatio -
        rtb_Boost_Curve_PD_Interpolatio)) * (1.0F /
                  (rtb_Boost_Curve_P1_Interpolatio * 2.0F))) + (rtb_abs_bc_input
        * rtb_Boost_Curve_PD_Interpolatio);
      break;

     case 3:
      rtb_Abs = ((((rtb_abs_bc_input - rtb_Boost_Curve_P0_Interpolatio) -
                   rtb_Boost_Curve_P1_Interpolatio) *
                  rtb_Boost_Curve_P2_Interpolatio) +
                 ((rtb_Boost_Curve_P1_Interpolatio *
                   rtb_Boost_Curve_P2_Interpolatio) * 0.5F)) +
        (((rtb_Boost_Curve_P1_Interpolatio * 0.5F) +
          rtb_Boost_Curve_P0_Interpolatio) * rtb_Boost_Curve_PD_Interpolatio);
      break;

     case 4:
      /* Product: '<S17>/Product' incorporates:
       *  Constant: '<S17>/Constant'
       *  Math: '<S17>/Math Function2'
       *
       * About '<S17>/Math Function2':
       *  Operator: reciprocal
       */
      rtb_Abs = rtb_Boost_Curve_P1_Interpolatio * 0.5F;

      /* Product: '<S17>/Product6' incorporates:
       *  Sum: '<S17>/Sum4'
       */
      rtb_Product6_m = (rtb_Abs + rtb_Boost_Curve_P0_Interpolatio) *
        rtb_Boost_Curve_PD_Interpolatio;

      /* Product: '<S17>/Product5' incorporates:
       *  Sum: '<S17>/Sum1'
       */
      rtb_Product5 = ((rtb_abs_bc_input - rtb_Boost_Curve_P0_Interpolatio) -
                      rtb_Abs) * rtb_Boost_Curve_P2_Interpolatio;

      /* Sum: '<S17>/Sum' */
      rtb_Abs = rtb_abs_bc_input - rtb_Boost_Curve_P3_Interpolatio;
      rtb_Abs = ((((rtb_Abs * rtb_Abs) * (rtb_Boost_Curve_P5_Interpolatio -
        rtb_Boost_Curve_P2_Interpolatio)) * (1.0F / (2.0F *
        rtb_Boost_Curve_P4_Interpolatio))) + rtb_Product5) + rtb_Product6_m;
      break;

     default:
      /* Product: '<S18>/Product1' */
      rtb_Abs = rtb_Boost_Curve_P4_Interpolatio * 0.5F;

      /* Product: '<S18>/Product6' */
      rtb_Product6_m = 0.5F * rtb_Boost_Curve_P1_Interpolatio;
      rtb_Abs = (((((rtb_Boost_Curve_P3_Interpolatio + rtb_Abs) - rtb_Product6_m)
                   - rtb_Boost_Curve_P0_Interpolatio) *
                  rtb_Boost_Curve_P2_Interpolatio) + (((rtb_abs_bc_input -
        rtb_Boost_Curve_P3_Interpolatio) - rtb_Abs) *
                  rtb_Boost_Curve_P5_Interpolatio)) + ((rtb_Product6_m +
        rtb_Boost_Curve_P0_Interpolatio) * rtb_Boost_Curve_PD_Interpolatio);
      break;
    }

    /* End of MultiPortSwitch: '<S13>/Multiport Switch' */

    /* Signum: '<S13>/Sign' */
    if (BA_LPFTrqFilter_Nm_f32_Irv < 0.0F) {
      rtb_abs_bc_input = -1.0F;
    } else if (BA_LPFTrqFilter_Nm_f32_Irv > 0.0F) {
      rtb_abs_bc_input = 1.0F;
    } else {
      rtb_abs_bc_input = BA_LPFTrqFilter_Nm_f32_Irv;
    }

    /* End of Signum: '<S13>/Sign' */

    /* Product: '<S10>/Product' incorporates:
     *  Constant: '<S10>/Constant1'
     *  Product: '<S13>/Product1'
     */
    BA_BoostTrq_Nm_f32_Irv = (rtb_Abs * rtb_abs_bc_input) *
      BA_BoostFac_f32_a12_Cal;

    /* Saturate: '<S10>/Saturation' */
    if (BA_BoostTrq_Nm_f32_Irv > 4.15F) {
      /* Product: '<S10>/Product' incorporates:
       *  Switch: '<S2>/Switch'
       */
      BA_BoostTrq_Nm_f32_Irv = 4.15F;
    } else if (BA_BoostTrq_Nm_f32_Irv < -4.15F) {
      /* Product: '<S10>/Product' incorporates:
       *  Switch: '<S2>/Switch'
       */
      BA_BoostTrq_Nm_f32_Irv = -4.15F;
    }

    /* End of Saturate: '<S10>/Saturation' */
  }

  /* End of Switch: '<S2>/Switch' */
}

/* Output and update for function-call system: '<Root>/Rnbl_BA_TrqMonitor' */
void Rnbl_BA_TrqMonitor(void)
{
  /* Sum: '<S5>/Add' */
  BA_AsstTrqSum_Nm_f32_Irv = BA_BoostTrq_Nm_f32_Irv + BA_HFGAsstTrq_Nm_f32_Irv;
}

/* Output and update for function-call system: '<Root>/Rnbl_BA_NotchFilter' */
void Rnbl_BA_NotchFilter(void)
{
  real_T rtb_Max;
  real_T rtb_Max_tmp;
  real32_T frac[2];
  real32_T frac_0[2];
  real32_T frac_1[2];
  real32_T frac_2[2];
  real32_T rtb_InterpolationUsingPrelook_f;
  real32_T rtb_InterpolationUsingPrelookup;
  real32_T rtb_MathFunction1_ot;
  real32_T rtb_Prelookup2_o2;
  real32_T rtb_Product1_c_tmp;
  real32_T rtb_Switch_tmp;
  uint32_T bpIndex[2];
  uint32_T bpIndex_0[2];
  uint32_T bpIndex_1[2];
  uint32_T bpIndex_2[2];
  uint32_T rtb_Prelookup1_o1;
  uint32_T rtb_Prelookup2_o1;

  /* Abs: '<S22>/Abs' incorporates:
   *  Inport: '<Root>/BA_StrVel_degps_f32_Read'
   */
  rtb_InterpolationUsingPrelook_f = fabsf(BA_StrVel_degps_f32_Read);

  /* Saturate: '<S22>/Saturation' */
  if (rtb_InterpolationUsingPrelook_f > 800.0F) {
    rtb_InterpolationUsingPrelook_f = 800.0F;
  }

  /* End of Saturate: '<S22>/Saturation' */

  /* PreLookup: '<S22>/Prelookup1' */
  rtb_Prelookup1_o1 = SWC_BasAsst_plook_u32ff_binc
    (rtb_InterpolationUsingPrelook_f, ((real32_T *)
      &(BA_StrVel_degps_BPK_f32_a4_Cal[0])), 4U,
     &rtb_InterpolationUsingPrelook_f);

  /* PreLookup: '<S22>/Prelookup2' incorporates:
   *  Inport: '<Root>/BA_VehSpd_kph_f32_Read'
   */
  rtb_Prelookup2_o1 = SWC_BasAsst_plook_u32ff_binc(BA_VehSpd_kph_f32_Read,
    ((real32_T *)&(BA_BC_VehSpd_kph_f32_a12_Cal[0])), 11U, &rtb_Prelookup2_o2);

  /* Interpolation_n-D: '<S22>/Interpolation Using Prelookup1' */
  frac[0] = rtb_InterpolationUsingPrelook_f;
  frac[1] = rtb_Prelookup2_o2;
  bpIndex[0] = rtb_Prelookup1_o1;
  bpIndex[1] = rtb_Prelookup2_o1;
  rtb_InterpolationUsingPrelookup = SWC_BasAsst_intrp2d_fu32fl_pw(bpIndex, frac,
    ((real32_T *)&(BA_NF_Fn_a5b12_f32_Cal[0])), 5U);

  /* Interpolation_n-D: '<S22>/Interpolation Using Prelookup2' */
  frac_0[0] = rtb_InterpolationUsingPrelook_f;
  frac_0[1] = rtb_Prelookup2_o2;
  bpIndex_0[0] = rtb_Prelookup1_o1;
  bpIndex_0[1] = rtb_Prelookup2_o1;
  rtb_MathFunction1_ot = SWC_BasAsst_intrp2d_fu32fl_pw(bpIndex_0, frac_0,
    ((real32_T *)&(BA_NF_Fd_a5b12_f32_Cal[0])), 5U);

  /* Math: '<S26>/Math Function1' incorporates:
   *  Math: '<S23>/Math Function1'
   *  Math: '<S24>/Math Function1'
   *  Math: '<S25>/Math Function1'
   *  Math: '<S27>/Math Function1'
   *  Math: '<S28>/Math Function1'
   */
  rtb_Product1_c_tmp = rtb_MathFunction1_ot * rtb_MathFunction1_ot;

  /* Interpolation_n-D: '<S22>/Interpolation Using Prelookup3' */
  frac_1[0] = rtb_InterpolationUsingPrelook_f;
  frac_1[1] = rtb_Prelookup2_o2;
  bpIndex_1[0] = rtb_Prelookup1_o1;
  bpIndex_1[1] = rtb_Prelookup2_o1;

  /* Interpolation_n-D: '<S22>/Interpolation Using Prelookup3' */
  BA_Zn_warch = SWC_BasAsst_intrp2d_fu32fl_pw(bpIndex_1, frac_1, ((real32_T *)
    &(BA_NF_Zn_a5b12_f32_Cal[0])), 5U);

  /* Math: '<S23>/Math Function' incorporates:
   *  Math: '<S24>/Math Function'
   *  Math: '<S25>/Math Function'
   *  Math: '<S27>/Math Function'
   *  Math: '<S28>/Math Function'
   */
  rtb_Switch_tmp = rtb_InterpolationUsingPrelookup *
    rtb_InterpolationUsingPrelookup;

  /* Interpolation_n-D: '<S22>/Interpolation Using Prelookup4' */
  frac_2[0] = rtb_InterpolationUsingPrelook_f;
  frac_2[1] = rtb_Prelookup2_o2;
  bpIndex_2[0] = rtb_Prelookup1_o1;
  bpIndex_2[1] = rtb_Prelookup2_o1;

  /* Product: '<S23>/Product1' incorporates:
   *  Constant: '<S23>/Constant'
   *  Interpolation_n-D: '<S22>/Interpolation Using Prelookup4'
   *  Product: '<S25>/Product1'
   */
  rtb_Max_tmp = 2.0 * SWC_BasAsst_intrp2d_fu32fl_pw(bpIndex_2, frac_2,
    ((real32_T *)&(BA_NF_Zd_a5b12_f32_Cal[0])), 5U);

  /* Product: '<S23>/Product' incorporates:
   *  Math: '<S23>/Math Function'
   *  Product: '<S24>/Product'
   *  Product: '<S25>/Product'
   *  Product: '<S27>/Product'
   *  Product: '<S28>/Product'
   */
  rtb_Prelookup2_o2 = rtb_Product1_c_tmp * rtb_Switch_tmp;

  /* MinMax: '<S21>/Max' incorporates:
   *  Constant: '<S21>/Constant'
   *  Math: '<S23>/Math Function'
   *  Product: '<S23>/Product'
   *  Product: '<S23>/Product1'
   *  Sum: '<S23>/Add'
   */
  rtb_Max = fmax((((((rtb_Max_tmp * rtb_MathFunction1_ot) * rtb_Switch_tmp) *
                    0.0010000000474974513) * 3.1415927410125732) +
                  ((rtb_Prelookup2_o2 * SWC_BasAsst_ConstB.MathFunction2) *
                   SWC_BasAsst_ConstB.MathFunction3)) + rtb_Switch_tmp, 1.0E-6);

  /* Sum: '<S21>/Add' incorporates:
   *  Constant: '<S21>/Ts'
   *  Constant: '<S21>/pi'
   *  Gain: '<S26>/Gain'
   *  Math: '<S26>/Math Function'
   *  Math: '<S26>/Math Function1'
   *  Product: '<S21>/Divide'
   *  Product: '<S21>/Product'
   *  Product: '<S26>/Product'
   *  Product: '<S26>/Product1'
   *  Sum: '<S26>/Add'
   *  UnitDelay: '<S21>/Unit Delay'
   */
  rtb_InterpolationUsingPrelook_f = ((real32_T)(((((((((2.0F * BA_Zn_warch) *
    rtb_Product1_c_tmp) * rtb_InterpolationUsingPrelookup) * 0.001F) *
    3.14159274F) + ((((rtb_InterpolationUsingPrelookup *
                       rtb_InterpolationUsingPrelookup) * rtb_Product1_c_tmp) *
                     SWC_BasAsst_ConstB.MathFunction2_m) *
                    SWC_BasAsst_ConstB.MathFunction3_k)) + rtb_Product1_c_tmp) /
    rtb_Max) * BA_AsstTrqSum_Nm_f32_Irv)) + SWC_BasAsst_DW.UnitDelay_DSTATE;

  /* Switch: '<S4>/Switch' incorporates:
   *  Constant: '<S4>/Constant2'
   *  Saturate: '<S4>/Saturation1'
   */
  if (BA_Switch_NFOut_NA_bl_Cal) {
    /* Saturate: '<S4>/Saturation' */
    if (rtb_InterpolationUsingPrelook_f > 4.5F) {
      /* Switch: '<S4>/Switch' */
      BA_BaTrq_Nm_f32_Write = 4.5F;
    } else if (rtb_InterpolationUsingPrelook_f < -4.5F) {
      /* Switch: '<S4>/Switch' */
      BA_BaTrq_Nm_f32_Write = -4.5F;
    } else {
      /* Switch: '<S4>/Switch' */
      BA_BaTrq_Nm_f32_Write = rtb_InterpolationUsingPrelook_f;
    }

    /* End of Saturate: '<S4>/Saturation' */
  } else if (BA_AsstTrqSum_Nm_f32_Irv > 4.5F) {
    /* Switch: '<S4>/Switch' incorporates:
     *  Saturate: '<S4>/Saturation1'
     */
    BA_BaTrq_Nm_f32_Write = 4.5F;
  } else if (BA_AsstTrqSum_Nm_f32_Irv < -4.5F) {
    /* Switch: '<S4>/Switch' incorporates:
     *  Saturate: '<S4>/Saturation1'
     */
    BA_BaTrq_Nm_f32_Write = -4.5F;
  } else {
    /* Switch: '<S4>/Switch' incorporates:
     *  Saturate: '<S4>/Saturation1'
     */
    BA_BaTrq_Nm_f32_Write = BA_AsstTrqSum_Nm_f32_Irv;
  }

  /* End of Switch: '<S4>/Switch' */

  /* Saturate: '<S4>/Saturation2' */
  if (BA_BaTrq_Nm_f32_Write > 4.23F) {
    /* Switch: '<S4>/Switch' incorporates:
     *  Saturate: '<S4>/Saturation2'
     */
    BA_BaTrq_Nm_f32_Write = 4.23F;
  } else if (BA_BaTrq_Nm_f32_Write < -4.23F) {
    /* Switch: '<S4>/Switch' incorporates:
     *  Saturate: '<S4>/Saturation2'
     */
    BA_BaTrq_Nm_f32_Write = -4.23F;
  }

  /* End of Saturate: '<S4>/Saturation2' */

  /* Update for UnitDelay: '<S21>/Unit Delay' incorporates:
   *  Gain: '<S24>/Gain'
   *  Gain: '<S24>/Gain1'
   *  Gain: '<S27>/Gain'
   *  Gain: '<S27>/Gain1'
   *  Product: '<S21>/Divide1'
   *  Product: '<S21>/Divide3'
   *  Product: '<S21>/Product2'
   *  Product: '<S21>/Product4'
   *  Product: '<S24>/Product'
   *  Product: '<S27>/Product'
   *  Sum: '<S21>/Add1'
   *  Sum: '<S21>/Subtract1'
   *  Sum: '<S24>/Add'
   *  Sum: '<S27>/Add'
   *  UnitDelay: '<S21>/Unit Delay1'
   */
  SWC_BasAsst_DW.UnitDelay_DSTATE = (((real32_T)((((((rtb_Prelookup2_o2 *
    SWC_BasAsst_ConstB.MathFunction2_l) * SWC_BasAsst_ConstB.MathFunction3_p) *
    2.0F) - (2.0F * rtb_Product1_c_tmp)) / rtb_Max) * BA_AsstTrqSum_Nm_f32_Irv))
    - ((real32_T)((((((rtb_Prelookup2_o2 * SWC_BasAsst_ConstB.MathFunction2_n) *
                      SWC_BasAsst_ConstB.MathFunction3_n) * 2.0F) - (2.0F *
    rtb_Switch_tmp)) / rtb_Max) * rtb_InterpolationUsingPrelook_f))) +
    SWC_BasAsst_DW.UnitDelay1_DSTATE_a;

  /* Update for UnitDelay: '<S21>/Unit Delay1' incorporates:
   *  Constant: '<S28>/Constant'
   *  Product: '<S21>/Divide2'
   *  Product: '<S21>/Divide4'
   *  Product: '<S21>/Product1'
   *  Product: '<S21>/Product3'
   *  Product: '<S25>/Product'
   *  Product: '<S25>/Product1'
   *  Product: '<S28>/Product'
   *  Product: '<S28>/Product1'
   *  Sum: '<S21>/Subtract'
   *  Sum: '<S25>/Add'
   *  Sum: '<S28>/Add'
   */
  SWC_BasAsst_DW.UnitDelay1_DSTATE_a = ((real32_T)((((((rtb_Prelookup2_o2 *
    SWC_BasAsst_ConstB.MathFunction2_p) * SWC_BasAsst_ConstB.MathFunction3_o) -
    (((((2.0 * BA_Zn_warch) * 3.1415927410125732) * rtb_Product1_c_tmp) *
      rtb_InterpolationUsingPrelookup) * 0.0010000000474974513)) +
    rtb_Product1_c_tmp) / rtb_Max) * BA_AsstTrqSum_Nm_f32_Irv)) - ((real32_T)
    ((((((rtb_Prelookup2_o2 * SWC_BasAsst_ConstB.MathFunction2_g) *
         SWC_BasAsst_ConstB.MathFunction3_m) - ((((rtb_Max_tmp *
    3.1415927410125732) * rtb_MathFunction1_ot) * rtb_Switch_tmp) *
    0.0010000000474974513)) + rtb_Switch_tmp) / rtb_Max) *
     rtb_InterpolationUsingPrelook_f));
}

/* Output and update for function-call system: '<Root>/Rnbl_BA_HighFreqAsst' */
void Rnbl_BA_HighFreqAsst(void)
{
  real32_T frac[2];
  real32_T rtb_Product_e;
  uint32_T bpIndex[2];

  /* Switch: '<S3>/Switch' incorporates:
   *  Constant: '<S3>/Constant'
   */
  if (BA_Switch_HFG_NA_bl_Cal) {
    /* Interpolation_n-D: '<S20>/Interpolation Using Prelookup' incorporates:
     *  Inport: '<Root>/BA_VehSpd_kph_f32_Read'
     *  PreLookup: '<S20>/Prelookup1'
     */
    bpIndex[1] = SWC_BasAsst_plook_u32ff_binc(BA_VehSpd_kph_f32_Read, ((real32_T
      *)&(BA_HPG_VehSpd_kph_f32_a12_Cal[0])), 11U, &frac[1]);

    /* Abs: '<S20>/Abs' */
    rtb_Product_e = fabsf(BA_LPFTrqFilter_Nm_f32_Irv);

    /* Saturate: '<S20>/Saturation' */
    if (rtb_Product_e > 5.9F) {
      rtb_Product_e = 5.9F;
    }

    /* End of Saturate: '<S20>/Saturation' */

    /* Interpolation_n-D: '<S20>/Interpolation Using Prelookup' incorporates:
     *  PreLookup: '<S20>/Prelookup'
     */
    bpIndex[0] = SWC_BasAsst_plook_u32ff_binc(rtb_Product_e, ((real32_T *)
      &(BA_HFG_StrTrq_Nm_f32_a10_Cal[0])), 9U, &rtb_Product_e);
    frac[0] = rtb_Product_e;

    /* Product: '<S3>/Product' incorporates:
     *  Gain: '<S3>/Gain'
     *  Interpolation_n-D: '<S20>/Interpolation Using Prelookup'
     */
    BA_HFGAsstTrq_Nm_f32_Irv = (BA_HFGFac_f32_a1_Cal *
      SWC_BasAsst_intrp2d_fu32fl_pw(bpIndex, frac, ((real32_T *)
      &(BA_HFG_TableData_NA_f32_a10a12_Cal[0])), 10U)) *
      BA_HPFTrqFilter_Nm_f32_Irv;

    /* Saturate: '<S3>/Saturation' */
    if (BA_HFGAsstTrq_Nm_f32_Irv > BA_HFlim_f32_a1_Cal) {
      /* Product: '<S3>/Product' */
      BA_HFGAsstTrq_Nm_f32_Irv = BA_HFlim_f32_a1_Cal;
    } else if (BA_HFGAsstTrq_Nm_f32_Irv < (-BA_HFlim_f32_a1_Cal)) {
      /* Product: '<S3>/Product' */
      BA_HFGAsstTrq_Nm_f32_Irv = -BA_HFlim_f32_a1_Cal;
    }

    /* End of Saturate: '<S3>/Saturation' */
  } else {
    /* Product: '<S3>/Product' incorporates:
     *  Constant: '<S3>/Constant1'
     */
    BA_HFGAsstTrq_Nm_f32_Irv = 0.0F;
  }

  /* End of Switch: '<S3>/Switch' */
}

/* System initialize for function-call system: '<Root>/Rnbl_BA_BlendFilter' */
void Rnbl_BA_TrqFilter_Init(void)
{
  /* InitializeConditions for UnitDelay: '<S8>/Unit Delay2' */
  SWC_BasAsst_DW.UnitDelay2_DSTATE = 1.0F;
}

/* Output and update for function-call system: '<Root>/Rnbl_BA_BlendFilter' */
void Rnbl_BA_TrqFilter(void)
{
  real32_T rtb_Divide;
  uint16_T rtb_Prelookup_o1_c;

  /* Switch: '<S8>/Switch' incorporates:
   *  UnitDelay: '<S8>/Unit Delay2'
   */
  if (SWC_BasAsst_DW.UnitDelay2_DSTATE > 0.0F) {
    /* Switch: '<S8>/Switch' incorporates:
     *  Inport: '<Root>/BA_StrTrq_Nm_f32_Read'
     */
    SWC_BasAsst_DW.UnitDelay1_DSTATE = BA_StrTrq_Nm_f32_Read;
  }

  /* End of Switch: '<S8>/Switch' */

  /* Sum: '<S1>/Add' incorporates:
   *  Inport: '<Root>/BA_StrTrq_Nm_f32_Read'
   */
  BA_HPFTrqFilter_Nm_f32_Irv = BA_StrTrq_Nm_f32_Read -
    SWC_BasAsst_DW.UnitDelay1_DSTATE;

  /* Switch: '<S1>/Switch' incorporates:
   *  Constant: '<S1>/Constant'
   *  Inport: '<Root>/BA_StrTrq_Nm_f32_Read'
   */
  if (BA_Switch_StrLPF_bl_Cal) {
    BA_LPFTrqFilter_Nm_f32_Irv = SWC_BasAsst_DW.UnitDelay1_DSTATE;
  } else {
    BA_LPFTrqFilter_Nm_f32_Irv = BA_StrTrq_Nm_f32_Read;
  }

  /* End of Switch: '<S1>/Switch' */

  /* PreLookup: '<S6>/Prelookup' incorporates:
   *  Inport: '<Root>/BA_VehSpd_kph_f32_Read'
   */
  rtb_Prelookup_o1_c = SWC_BasAsst_plook_u16ff_binc(BA_VehSpd_kph_f32_Read,
    ((real32_T *)&(BA_BF_VehSpd_kph_f32_a11_Cal[0])), 11U, &rtb_Divide);

  /* Gain: '<S9>/Gain' incorporates:
   *  Interpolation_n-D: '<S6>/Interpolation Using Prelookup'
   */
  rtb_Divide = 6.28318548F * SWC_BasAsst_intrp1d_fu16fl_pw(rtb_Prelookup_o1_c,
    rtb_Divide, ((real32_T *)&(BA_BF_CutoffFreq_Hz_f32_a11_Cal[0])));

  /* Product: '<S9>/Divide' incorporates:
   *  Constant: '<S9>/Constant'
   *  Sum: '<S9>/Add'
   */
  rtb_Divide /= rtb_Divide + 1000.0F;

  /* Update for UnitDelay: '<S8>/Unit Delay2' incorporates:
   *  Constant: '<S8>/Constant5'
   */
  SWC_BasAsst_DW.UnitDelay2_DSTATE = 0.0F;

  /* Update for Switch: '<S8>/Switch' incorporates:
   *  Constant: '<S8>/Constant1'
   *  Inport: '<Root>/BA_StrTrq_Nm_f32_Read'
   *  Product: '<S8>/Product2'
   *  Product: '<S8>/Product3'
   *  Sum: '<S8>/Add1'
   *  Sum: '<S8>/Subtract1'
   *  UnitDelay: '<S8>/Unit Delay1'
   */
  SWC_BasAsst_DW.UnitDelay1_DSTATE = ((1.0F - rtb_Divide) *
    SWC_BasAsst_DW.UnitDelay1_DSTATE) + (rtb_Divide * BA_StrTrq_Nm_f32_Read);
}

/* Model step function */
void TMT_Rnbl_BA_BlendFilter(void)
{
  /* RootInportFunctionCallGenerator generated from: '<Root>/Inport' incorporates:
   *  SubSystem: '<Root>/Rnbl_BA_BlendFilter'
   */
  Rnbl_BA_TrqFilter();

  /* End of Outputs for RootInportFunctionCallGenerator generated from: '<Root>/Inport' */
}

/* Model step function */
void TMT_Rnbl_BA_BoostCurve(void)
{
  /* RootInportFunctionCallGenerator generated from: '<Root>/Inport1' incorporates:
   *  SubSystem: '<Root>/Rnbl_BA_BoostCurve'
   */
  Rnbl_BA_BoostCurve();

  /* End of Outputs for RootInportFunctionCallGenerator generated from: '<Root>/Inport1' */
}

/* Model step function */
void TMT_Rnbl_BA_TrqMonitor(void)
{
  /* RootInportFunctionCallGenerator generated from: '<Root>/Inport2' incorporates:
   *  SubSystem: '<Root>/Rnbl_BA_TrqMonitor'
   */
  Rnbl_BA_TrqMonitor();

  /* End of Outputs for RootInportFunctionCallGenerator generated from: '<Root>/Inport2' */
}

/* Model step function */
void TMT_Rnbl_BA_NotchFilter(void)
{
  /* RootInportFunctionCallGenerator generated from: '<Root>/Inport3' incorporates:
   *  SubSystem: '<Root>/Rnbl_BA_NotchFilter'
   */
  Rnbl_BA_NotchFilter();

  /* End of Outputs for RootInportFunctionCallGenerator generated from: '<Root>/Inport3' */
}

/* Model step function */
void TMT_Rnbl_BA_HighFreqAsst(void)
{
  /* RootInportFunctionCallGenerator generated from: '<Root>/Inport4' incorporates:
   *  SubSystem: '<Root>/Rnbl_BA_HighFreqAsst'
   */
  Rnbl_BA_HighFreqAsst();

  /* End of Outputs for RootInportFunctionCallGenerator generated from: '<Root>/Inport4' */
}

/* Model initialize function */
void SWC_BasAsst_initialize(void)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatus(SWC_BasAsst_M, (NULL));

  /* block I/O */

  /* exported global signals */
  BA_HPFTrqFilter_Nm_f32_Irv = 0.0F;
  BA_LPFTrqFilter_Nm_f32_Irv = 0.0F;
  BA_HFGAsstTrq_Nm_f32_Irv = 0.0F;
  BA_Zn_warch = 0.0F;
  BA_BaTrq_Nm_f32_Write = 0.0F;
  BA_AsstTrqSum_Nm_f32_Irv = 0.0F;
  BA_BoostTrq_Nm_f32_Irv = 0.0F;

  /* states (dwork) */
  (void) memset((void *)&SWC_BasAsst_DW, 0,
                sizeof(DW_SWC_BasAsst_T));

  /* external inputs */
  BA_StrTrq_Nm_f32_Read = 0.0F;
  BA_VehSpd_kph_f32_Read = 0.0F;
  BA_StrVel_degps_f32_Read = 0.0F;

  /* SystemInitialize for RootInportFunctionCallGenerator generated from: '<Root>/Inport' incorporates:
   *  SubSystem: '<Root>/Rnbl_BA_BlendFilter'
   */
  Rnbl_BA_TrqFilter_Init();

  /* End of SystemInitialize for RootInportFunctionCallGenerator generated from: '<Root>/Inport' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
