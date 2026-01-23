/**********************************************************************************************************************
    File Name       : fad_sample.h
    File Revision   : $Rev$
    File Date       : $Date$
    Device(s)       : RV40 Flash based RH850 microcontroller
    Description     : Application sample for usage of Flash Access Driver (FAD)
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

#include "r_fad.h"

/**********************************************************************************************************************
    Prototype declaration
**********************************************************************************************************************/

/**********************************************************************************************************************
    Checks the range of memory
**********************************************************************************************************************/

T_u4_FadErr sample_CheckCF0(T_u4_FadAddr i_u4_FadAddr);
T_u4_FadErr sample_CheckCF1(T_u4_FadAddr i_u4_FadAddr);
T_u4_FadErr sample_CheckDF0(T_u4_FadAddr i_u4_FadAddr);
T_u4_FadErr sample_CheckDF1(T_u4_FadAddr i_u4_FadAddr);

/* For Security Part Begin */

T_u4_FadErr sample_CheckCfg(T_u4_FadAddr i_u4_FadAddr);
T_u4_FadErr sample_CheckOTP0(T_u4_FadAddr i_u4_FadAddr);
T_u4_FadErr sample_CheckOTP1(T_u4_FadAddr i_u4_FadAddr);

/* For Security Part End */

/**********************************************************************************************************************
    Checks the start block address
**********************************************************************************************************************/

T_u4_FadErr sample_CheckBlockCF(T_u4_FadAddr i_u4_FadAddr);
T_u4_FadErr sample_CheckBlockDF(T_u4_FadAddr i_u4_FadAddr);

/**********************************************************************************************************************
    Checks border
**********************************************************************************************************************/

T_u4_FadErr sample_CheckBound(T_u4 i_u4_Addr, T_u2 bound);

/**********************************************************************************************************************
    Checks the parameter of blank check
**********************************************************************************************************************/

T_u4_FadErr sample_BlankCheckParam(T_u4_FadAddr i_u4_FadStartAddr, T_u4_FadAddr i_u4_FadEndAddr, \
                                                                            T_u1_CheckDir i_u1_CheckDir);

/**********************************************************************************************************************
    For Code flash
**********************************************************************************************************************/

T_u4_FadErr sample_CF_Write(T_u4_FadAddr i_u4_FadAddr, T_p_DataBuff i_p_DataBuff, T_u4 i_u4_TimeOutCount);
T_u4_FadErr sample_CF_Erase(T_u4_FadAddr i_u4_FadAddr, T_u4 i_u4_TimeOutCount);

/* For Security Part Begin */

T_u4_FadErr sample_CF_SetLockBit(T_u4_FadAddr i_u4_FadAddr, T_u4 i_u4_TimeOutCount);
T_u4_FadErr sample_CF_GetLockBit(T_u4_FadAddr i_u4_FadAddr, T_u4 i_u4_TimeOutCount);

/* For Security Part End */

/**********************************************************************************************************************
    For Data flash
**********************************************************************************************************************/

T_u4_FadErr sample_DF_Write(T_u4_FadAddr i_u4_FadAddr, T_p_DataBuff i_p_DataBuff, T_u4 i_u4_TimeOutCount);
T_u4_FadErr sample_DF_Erase(T_u4_FadAddr i_u4_FadAddr, T_u4 i_u4_TimeOutCount);
T_u4_FadErr sample_DF_BlankCheck(T_u4_FadAddr i_u4_FadStartAddr, T_u4_FadAddr i_u4_FadEndAddr, \
                                                                T_u1_CheckDir i_u1_CheckDir, T_u4 i_u4_TimeOutCount);

#define FLMD0_PROTECTION_OFF    (0x01U)
#define FLMD0_PROTECTION_ON     (0x00U)

/**********************************************************************************************************************
    Error code
**********************************************************************************************************************/
#define R_FAD_LKREAD0       0x00000010
#define R_FAD_LKREAD1       0x00000011
#define R_FAD_BLKCHK0       0x00000020
#define R_FAD_BLKCHK1       0x00000021
#define R_FAD_ERR_PARAM     0x00009000
#define R_FAD_ERR_ILGADR    0x00009001
#define R_FAD_ERR_BOUND     0x00009002

/**********************************************************************************************************************
    Definition of logical value
**********************************************************************************************************************/

#define TRUE    1
#define FALSE   0

