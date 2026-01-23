/**********************************************************************************************************************
    Program Name    : Flash Access Driver (FAD)

    File Name       : r_fad_local.h
    Program Version : V2.00
    File Revision   : $Rev$
    File Date       : $Date$
    Device(s)       : RV40 Flash based RH850 microcontroller
    Description     : 
**********************************************************************************************************************/

/**********************************************************************************************************************
    DISCLAIMER
    This software is supplied by Renesas Electronics Corporation and is only  intended for use with
    Renesas products. No other uses are authorized. This software is owned by Renesas Electronics
    Corporation and is protected under all applicable laws, including copyright laws.
    THIS SOFTWARE IS PROVIDED "AS IS" AND RENESAS MAKES NO WARRANTIES REGARDING THIS SOFTWARE,
    WHETHER EXPRESS, IMPLIED OR STATUTORY, INCLUDING BUT NOT LIMITED TO WARRANTIES OF MERCHANTABILITY,
    FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT. ALL SUCH WARRANTIES ARE EXPRESSLY DISCLAIMED.
    TO THE MAXIMUM EXTENT PERMITTED NOT PROHIBITED BY LAW, NEITHER RENESAS ELECTRONICS CORPORATION NOR
    ANY OF ITS AFFILIATED COMPANIES SHALL BE LIABLE FOR ANY DIRECT, INDIRECT, SPECIAL, INCIDENTAL OR
    CONSEQUENTIAL DAMAGES FOR ANY REASON RELATED TO THIS SOFTWARE, EVEN IF RENESAS OR ITS AFFILIATES HAVE
    BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGES.
    Renesas reserves the right, without notice, to make changes to this software and to discontinue the
    availability of this software. By using this software, you agree to the additional terms and conditions
    found by accessing the  following link:
    http://www.renesas.com/disclaimer

    Copyright (C) 2017 Renesas Electronics Corporation. All rights reserved.
**********************************************************************************************************************/

#ifndef _R_FAD_LOCAL_H_
#define _R_FAD_LOCAL_H_

#include "r_fad_local_macro.h"
#include "r_fad_version.h"

/**********************************************************************************************************************
    Command ID of FACI
**********************************************************************************************************************/

#define R_FAD_CMDID_CONFIG      0x40
#define R_FAD_CMDID_OTP         0x45
#define R_FAD_CMDID_LOCK_SET    0x77
#define R_FAD_CMDID_LOCK_GET    0x71
#define R_FAD_CMDID_WRITE       0xE8
#define R_FAD_CMDID_ERASE       0x20
#define R_FAD_CMDID_SUSPEND     0xB0
#define R_FAD_CMDID_RESUME      0xD0
#define R_FAD_CMDID_STS_CLR     0x50
#define R_FAD_CMDID_STOP        0xB3
#define R_FAD_CMDID_BLK_CHK     0x71
#define R_FAD_CMDID_RUN         0xD0

/**********************************************************************************************************************
    For writing area of FACI Command
**********************************************************************************************************************/

extern T_u4 bu4_CommandArea;

#define R_FAD_CMD_AREA_FOR_1BYTE    *((T_u1 *)bu4_CommandArea)     /* For 1 byte control   */
#define R_FAD_CMD_AREA_FOR_2BYTES   *((T_u2 *)bu4_CommandArea)     /* For 2 bytes control  */
#define R_FAD_CMD_AREA_FOR_4BYTES   *((T_u4 *)bu4_CommandArea)     /* For 4 bytes control  */

/**********************************************************************************************************************
    Definition of Register related to FACI Control
**********************************************************************************************************************/

extern T_u4 bu4_FaciBase;

#define FACI                (*(volatile struct __faci *)bu4_FaciBase)

#define R_FAD_REG_FPMON         (FACI.FPMON)
#define R_FAD_REG_FASTAT        (FACI.FASTAT)
#define R_FAD_REG_FAEINT        (FACI.FAEINT)
#define R_FAD_REG_FSADDR        (FACI.FSADDR)
#define R_FAD_REG_FEADDR        (FACI.FEADDR)
#define R_FAD_REG_FCURAME       (FACI.FCURAME)
#define R_FAD_REG_FRAMMCR       (FACI.FRAMMCR)
#define R_FAD_REG_FSTATR        (FACI.FSTATR)
#define R_FAD_REG_FENTRYR       (FACI.FENTRYR)
#define R_FAD_REG_FSUINITR      (FACI.FSUINITR)
#define R_FAD_REG_FLKSTAT       (FACI.FLKSTAT)
#define R_FAD_REG_FRFSTEADR     (FACI.FRFSTEADR)
#define R_FAD_REG_FRTSTAT       (FACI.FRTSTAT)
#define R_FAD_REG_FRTEINT       (FACI.FRTEINT)
#define R_FAD_REG_FCMDR         (FACI.FCMDR)
#define R_FAD_REG_FRAMECCR      (FACI.FRAMECCR)
#define R_FAD_REG_FPESTAT       (FACI.FPESTAT)
#define R_FAD_REG_FCNFPRGCNT    (FACI.FCNFPRGCNT)
#define R_FAD_REG_FBCCNT        (FACI.FBCCNT)
#define R_FAD_REG_FBCSTAT       (FACI.FBCSTAT)
#define R_FAD_REG_FPSADDR       (FACI.FPSADDR)
#define R_FAD_REG_FCPSR         (FACI.FCPSR)
#define R_FAD_REG_FPCKAR        (FACI.FPCKAR)
#define R_FAD_REG_FECCEMON      (FACI.FECCEMON)
#define R_FAD_REG_FECCTMD       (FACI.FECCTMD)
#define R_FAD_REG_FDMYECC       (FACI.FDMYECC)

#ifdef __R_FAD_USE_STUB__   /* For Internal Test */
extern struct __faci bst_Faci0;
extern struct __faci bst_Faci1;
#define R_FAD_FACI0_BASE        (T_u4)(&bst_Faci0)  /* Base address for FACI0 (for internal test)  */
#define R_FAD_FACI1_BASE        (T_u4)(&bst_Faci1)  /* Base address for FACI1 (for internal test)  */
#else   /* For Formal Code */
#define R_FAD_FACI0_BASE        0xFFA10000U         /* Base address for FACI0   */
#define R_FAD_FACI1_BASE        0xFFA18000U         /* Base address for FACI1   */
#endif  /* __R_FAD_USE_STUB__ */

#define R_FAD_CMDAREA0          0xFFA20000U         /* FACI0 command-issuing area   */
#define R_FAD_CMDAREA1          0xFFA30000U         /* FACI1 command-issuing area   */

/**********************************************************************************************************************
    For the initializing value related to flash register
**********************************************************************************************************************/

#define R_FAD_FSUINITR_SUINIT   0x0001

/**********************************************************************************************************************
    KEY value for writing to register
**********************************************************************************************************************/

#define R_FAD_KEY_FENTRYR       0xAA00      /* For FENTRYR  */
#define R_FAD_KEY_FCURAME       0xC400      /* For FCURAME  */
#define R_FAD_KEY_FRAMMCR       0xB900      /* For FRAMMCR  */
#define R_FAD_KEY_FPCKAR        0x1E00      /* For FPCKAR   */

/**********************************************************************************************************************
    Related to FCU
**********************************************************************************************************************/

#define R_FAD_FCUFIRM_BASE      0x0100B000U     /* Base address of FCU firmware */
#define R_FAD_FCURAM0_BASE      0xFFA12000U     /* Base address of FCURAM0      */
#define R_FAD_FCURAM1_BASE      0xFFA1A000U     /* Base address of FCURAM1      */

/**********************************************************************************************************************
    Memory address
**********************************************************************************************************************/

#define R_FAD_CF1_BASE          0x00800000U     /* Start address of Code Flash BankA    */
#define R_FAD_CF_END            0x0100A000U     /* End address of Code Flash            */
#define R_FAD_DF0_BASE          0xFF200000U     /* Start address of Data Flash BankA    */
#define R_FAD_DF1_BASE          0xFF300000U     /* Start address of Data Flash BankB    */
#define R_FAD_DF_END            0xFF400000U     /* End address of Data Flash            */

/**********************************************************************************************************************
    Masking value for FASTAT register
**********************************************************************************************************************/

#define R_FAD_MASK_FASTAT_CFAE      0x80U
#define R_FAD_MASK_FASTAT_DFAE      0x08U
#define R_FAD_MASK_FASTAT_CMDLK     0x10U

/**********************************************************************************************************************
    Masking value for FSTATR register
**********************************************************************************************************************/

#define R_FAD_MASK_FSTATR_FRDY      0x00008000U
#define R_FAD_MASK_FSTATR_ERSERR    0x00002000U
#define R_FAD_MASK_FSTATR_PRGERR    0x00001000U
#define R_FAD_MASK_FSTATR_SUSRDY    0x00000800U
#define R_FAD_MASK_FSTATR_DBFULL    0x00000400U
#define R_FAD_MASK_FSTATR_ERSSPD    0x00000200U
#define R_FAD_MASK_FSTATR_PRGSPD    0x00000100U

/**********************************************************************************************************************
    Masking value for FPESTAT register
**********************************************************************************************************************/

#define R_FAD_MASK_FPESTAT_NO_ERR       0x00U
#define R_FAD_MASK_FPESTAT_WR_ERR_LOCK  0x01U
#define R_FAD_MASK_FPESTAT_WR_ERR_OTHER 0x02U
#define R_FAD_MASK_FPESTAT_ER_ERR_LOCK  0x11U
#define R_FAD_MASK_FPESTAT_ER_ERR_OTHER 0x12U

/**********************************************************************************************************************
    Masking value for detail error information
**********************************************************************************************************************/

#define R_FAD_MASK_ERROR_INFO           0xF00270EA

/**********************************************************************************************************************
    Masking value for Option Byte 1
**********************************************************************************************************************/

#define MASK_RESERVED_BIT_FOR_OPBT1     0xC0003FFF

/**********************************************************************************************************************
    Masking value for FPMON
**********************************************************************************************************************/

#define R_FAD_FPMON_FWE         0x80    /* Bit of Flash Write Enable in FPMON   */

/**********************************************************************************************************************
    For argument of internal writing API
**********************************************************************************************************************/

#define R_FAD_CF_MODE           0x01    /* For writing to Code Flash                */
#define R_FAD_DF_MODE           0x80    /* For writing to Data Flash                */
#define R_FAD_RD_MODE           0x00    /* For reading of Code Flash or Data Flash  */

/**********************************************************************************************************************
    Writing Unit
**********************************************************************************************************************/

#define R_FAD_CF_WR_UNIT        128     /* Writing unit for Code Flash : 128 bytes  */
#define R_FAD_DF_WR_UNIT        2       /* Writing unit for Data Flash : 2 bytes    */

/**********************************************************************************************************************
    Loop count for waiting
**********************************************************************************************************************/

#define R_FAD_FRDY_LOOP         800000
#define R_FAD_WAIT_LOOP         1000

/**********************************************************************************************************************
    Definition of logical value
**********************************************************************************************************************/

#define TRUE    1
#define FALSE   0

/**********************************************************************************************************************
    Definition of NULL
**********************************************************************************************************************/

#define NULL    0

/**********************************************************************************************************************
    Table of clock frequency
**********************************************************************************************************************/

typedef struct {   
    T_u2    cu2_InClockFreq;    /* Input clock frequency    */
    T_u4    cu4_OptionByte1;    /* Option byte 1            */
} T_st_ClockFreqTable;

/**********************************************************************************************************************
    Table of FCU clock frequency
**********************************************************************************************************************/

typedef struct {
    T_u1    cu1_pClockFreq[7];  /* FCU clock frequency(CLK_LSB) */
} T_st_PClockFreqTable;

/**********************************************************************************************************************
    Prototype declaration for internal function
**********************************************************************************************************************/

T_u4_FadErr fad_fu4_Write(T_u1 i_u1_Mode, T_u4_FadAddr i_u4_FadAddr,\
                            T_p_DataBuff i_p_DataBuff, T_u4 i_u4_TimeOutCount);
T_u4_FadErr fad_fu4_Erase(T_u1 i_u1_Mode, T_u4_FadAddr i_u4_FadAddr, T_u4 i_u4_TimeOutCount);

T_u4_FadErr fad_fu4_IssueCommandTypeA(T_u1 i_u1_Command, T_u4_FadAddr i_u4_FadAddr, \
                                        T_p_DataBuff i_p_DataBuff, T_u1 i_u1_Size, T_u4 i_bu4_timeOutCount);
T_u4_FadErr fad_fu4_IssueCommandTypeB(T_u1 i_u1_Command, T_u4_FadAddr i_u4_FadAddr);
T_u4_FadErr fad_fu4_IssueCommandTypeC(T_u1 i_u1_Command);

T_u4_FadErr fad_fu4_InitializeFlashSequencerSetupRegister(void);
T_u4_FadErr fad_fu4_TransferToFCU(T_u4 i_u4_TimeOutCount);
T_u4_FadErr fad_fu4_SetClock(T_u2 i_u2_ClockIn, T_u2 i_u2_ClockCpu);
T_u4_FadErr fad_fu4_AuthId(T_u1* i_u1_Authid);

T_u4_FadErr fad_fu4_CheckFlashStatus(void);
T_u4_FadErr fad_fu4_IsValidToIssueCommand(void);
T_u4_FadErr fad_fu4_CheckFlashStatusSuspendable(void);

T_u4        fad_fu4_GetPEModeOrReadMode(void);
T_u4_FadErr fad_fu4_SetPEModeOrReadMode(T_u1 i_u1_Mode, T_u4 i_u4_TimeOutCount);

T_bl        fad_fbl_IsFRDY(void);
T_bl        fad_fbl_IsSUSRDY(void);
T_bl        fad_fbl_IsERSSPD(void);
T_bl        fad_fbl_IsPRGSPD(void);
T_bl        fad_fbl_IsCMDLK(void);

T_u4_FadErr fad_fu4_WaitForDBFULLIsInvalid(T_u4 i_bu4_timeOutCount);
T_u4_FadErr fad_fu4_WaitForFRDYIsValid(void);
T_u4_FadErr fad_fu4_SelectFCUFirmArea(T_u1 i_u1_Area, T_u4 i_bu4_timeOutCount);
T_u4_FadErr fad_fu4_ClearIcache(T_u4 i_bu4_timeOutCount);

void        fad_fv0_Memcpy4(T_u4* i_p_Destination, T_u4* i_p_Source, T_u4 i_p_Size);
void        fad_fv0_Memcpy1(T_u1* i_p_Destination, T_u1* i_p_Source, T_u4 i_p_Size);

T_u4        fad_fu4_GetCheckSum(T_u4* i_p_Fcuram, T_u4 i_u4_Size, T_u4 i_u4_AddUnit);
T_u4        fad_fu4_GetDetailErrorInformation(void);

T_u1        fad_fu1_GetAcceptedFACICommand(void);

T_u2_FaciNumber fad_fu2_GetFACINumberFromAddress(T_u4_FadAddr i_u4_fadAddr);
void        fad_fv0_SetFACI(T_u2_FaciNumber i_u2_FaciNumber);
void        fad_fv0_SetLoopCnt(void);

void        __SYNCI(void);  /* Used in the macro R_FAD_SYNCI()  */
void        __SYNCP(void);  /* Used in the macro R_FAD_SYNCP()  */
int         R_FAD_STSR(int, int);
int         R_FAD_LDSR(int, int, int);

T_u4_FadErr fad_fu4_SetConfig(T_u1 i_u1_Command, T_u4_FadAddr i_u4_FadAddr,\
                                T_p_DataBuff i_p_DataBuff, T_u4 i_u4_TimeOutCount);
T_u4_FadErr fad_fu4_GetConfig(T_u1 i_u1_Command, T_u4_FadAddr i_u4_FadAddr,
                                T_p_DataBuff i_p_DataBuff, T_u4 i_bu4_timeOutCount);
T_u4_FadErr fad_fu4_LockBitProtectControl(T_u4_FadAddr i_u4_FadAddr,\
                                              T_bl_LockBitProtectSwitch i_bl_LockBitProtectSwitch);
T_u4_FadErr fad_fu4_LockBit(T_u1 i_u1_Command, T_u4_FadAddr i_u4_FadAddr, T_u4 i_u4_TimeOutCount);



T_u4        fad_fu4_CheckSum(T_u4 *p_fcuram, T_u4 size);

#endif /* _R_FAD_LOCAL_H_ */
