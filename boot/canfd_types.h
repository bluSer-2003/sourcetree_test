/*
 * File: can_types.h
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

#ifndef canfd_types_h_
#define cafdn_types_h_
#include "rtwtypes.h"

typedef struct {
  uint16_T ProtocolMode;
  uint16_T Extended;
  uint16_T Length;
  uint16_T Remote;
  uint16_T Error;
  uint16_T BRS;
  uint16_T ESI;
  uint16_T DLC;
  uint32_T ID;
  uint32_T Reserved;
  real_T Timestamp;
  uint8_T Data[64];
} CAN_FD_MESSAGE_BUS;


typedef struct {
  real32_T pre;
  real32_T pos;
  uint16_T spdMax;
  real32_T spd;
  real32_T curMax;
  real32_T curId;
  real32_T curIq;
  //uint16_T runMode;
  uint32_T password;
  real32_T volDisUp;
  real32_T volDisDown;
  uint16_T givenFlag;
} Given;

typedef struct {
  real32_T volProtOV;
  real32_T volProtUV;
  uint16_T curProt;
  uint16_T spdProt;
  uint16_T curOpProt;
  uint16_T spdOpProt;
  real32_T posOpProt;
  uint16_T powProt;
  uint16_T protFlag;
  uint16_T protEn;
} Protect;


typedef struct {
  real_T posKp;
  real32_T posKi;
  real_T spdKp;
  real32_T spdKi;
  real_T curKp;
  real32_T curKi;
  real_T fwKp;
  real32_T fwKi;
  real32_T fwCurMax;
  //uint16_T spdMax;
  //real32_T curMax;
  uint16_T interFreq;
  uint16_T regFlag;
} Regulator;

typedef struct {
  uint16_T maunfYear;
  uint16_T maunfMonth;
  uint16_T maunfDay;
  uint16_T maunfType;
  uint16_T maunfVersion;
  uint16_T maunfSN;
} Maunfactory;


typedef struct {
  real32_T vol;
  real32_T curIa;
  real32_T curIb;
  real32_T curIc;
  real32_T curId;
  real32_T curIq;
  real32_T curIdRef;
  real32_T curIqRef;
  real32_T spd;
  real32_T spdRef;
  real32_T pre;
  real32_T preRef;
  real32_T pos;
  real32_T posRef;
  uint32_T errCode;
  int16_T temp1;
  int16_T temp2;
  uint32_T version;
} Feedback;

#endif


/* Forward declaration for rtModel */
typedef struct tag_RTM_canFD_P_V2_T RT_MODEL_canFD_P_V2_T;

//#endif                                   /* can_types_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
