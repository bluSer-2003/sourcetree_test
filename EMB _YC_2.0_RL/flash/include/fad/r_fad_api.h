/**********************************************************************************************************************
    Program Name    : Flash Access Driver (FAD)

    File Name       : r_fad_api.h
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

#ifndef _R_FAD_API_H_
#define _R_FAD_API_H_

#include    "r_fad_types.h"

/**********************************************************************************************************************
    Prototype declaration
**********************************************************************************************************************/

/**********************************************************************************************************************
    Common API
**********************************************************************************************************************/

T_u4_FadErr         R_FAD_HW_Init(T_st_HW_Init* i_pst_HW_Init, T_u4 i_u4_TimeOutCount);
T_u4_FadErr         R_FAD_Suspend(T_u2_FaciNumber i_u2_FaciNumber);
T_u4_FadErr         R_FAD_Resume(T_u2_FaciNumber i_u2_FaciNumber, T_u4 i_u4_TimeOutCount);
T_u4_FadErr         R_FAD_StatusClear(T_u2_FaciNumber i_u2_FaciNumber, T_u4 i_u4_TimeOutCount);
T_u4_FadErr         R_FAD_ForcedStop(T_u2_FaciNumber i_u2_FaciNumber, T_u4 i_u4_TimeOutCount);
T_u4_FadStatus      R_FAD_GetStatus(T_u2_FaciNumber i_u2_FaciNumber, T_u4_FadStsExInfo* o_pu4_FadStsExInfo);
T_u4_FadErr         R_FAD_ShiftToReadMode(T_u2_FaciNumber i_u2_FaciNumber, T_u4 i_u4_TimeOutCount);
T_u4_FadErr         R_FAD_IDAuth(T_u4* i_p_AuthIDAddr, T_u1* i_p_CheckData,\
                                    T_u4 i_u4_IDLength, T_u4 i_u4_StatusBitValue);

/**********************************************************************************************************************
    Code flash API
**********************************************************************************************************************/

T_u4_FadErr         R_FAD_CF_Init(void);
T_u4_FadErr         R_FAD_CF_Write(T_u4_FadAddr i_u4_FadAddr, T_p_DataBuff i_p_DataBuff, T_u4 i_u4_TimeOutCount);
T_u4_FadErr         R_FAD_CF_Erase(T_u4_FadAddr i_u4_FadAddr, T_u4 i_u4_TimeOutCount);
T_p_FadApiVersion   R_FAD_CF_GetApiVersion(void);

/**********************************************************************************************************************
    Data flash API
**********************************************************************************************************************/

T_u4_FadErr         R_FAD_DF_Write(T_u4_FadAddr i_u4_FadAddr, T_p_DataBuff i_p_DataBuff, T_u4 i_u4_TimeOutCount);
T_u4_FadErr         R_FAD_DF_Erase(T_u4_FadAddr i_u4_FadAddr, T_u4 i_u4_TimeOutCount);
T_u4_FadErr         R_FAD_DF_BlankCheck(T_u4_FadAddr i_u4_FadStartAddr,T_u4_FadAddr i_u4_FadEndAddr,\
                                           T_u1_CheckDir i_u1_CheckDir, T_u4 i_u4_TimeOutCount);
T_p_FadApiVersion   R_FAD_DF_GetApiVersion(void);


/* For Security Part Begin */

/**********************************************************************************************************************
    APIs for Security
**********************************************************************************************************************/

T_u4_FadErr         R_FAD_CF_SetLockBit(T_u4_FadAddr i_u4_FadAddr, T_u4 i_u4_TimeOutCount);
T_u4_FadErr         R_FAD_CF_GetLockBit(T_u4_FadAddr i_u4_FadAddr, T_u4 i_u4_TimeOutCount);
T_u4_FadErr         R_FAD_CF_LockBitProtectControl(T_u4_FadAddr i_u4_FadAddr,\
                                                         T_bl_LockBitProtectSwitch i_bl_LbProtKind);
T_u4_FadErr         R_FAD_CF_SetConfig(T_u4_FadAddr i_u4_FadAddr, T_p_DataBuff i_p_DataBuff, T_u4 i_u4_TimeOutCount);
T_u4_FadErr         R_FAD_CF_GetConfig(T_u4_FadAddr i_u4_FadAddr, T_p_DataBuff o_p_DataBuff, T_u4 i_u4_TimeOutCount);
T_u4_FadErr         R_FAD_CF_SetOTP(T_u4_FadAddr i_u4_FadAddr, T_p_DataBuff i_p_DataBuff, T_u4 i_u4_TimeOutCount);
T_u4_FadErr         R_FAD_CF_GetOTP(T_u4_FadAddr i_u4_FadAddr,T_p_DataBuff o_p_DataBuff, T_u4 i_u4_TimeOutCount);

/* For Security Part End */

T_u4_FadErr         fad_fu4_DFPEId(T_u1* dfpeid);

#endif    /* _R_FAD_API_H_ */
