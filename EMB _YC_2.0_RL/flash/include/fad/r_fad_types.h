/**********************************************************************************************************************
    Program Name    : Flash Access Driver (FAD)

    File Name       : r_fad_types.h
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

#ifndef _R_FAD_TYPES_H_
#define _R_FAD_TYPES_H_

/**********************************************************************************************************************
    Data types
**********************************************************************************************************************/
typedef signed char     T_s1;
typedef unsigned char   T_u1;
typedef signed short    T_s2;
typedef unsigned short  T_u2;
typedef signed long     T_s4;
typedef unsigned long   T_u4;
typedef unsigned char   T_bl;

/**********************************************************************************************************************
    Parameter for Hardware Initialization
**********************************************************************************************************************/
typedef struct {
    T_u2 bu2_InClock;
    T_u2 bu2_CpuClock;
    T_u1 bu1_EraseSuspendMode;
} T_st_HW_Init;

/**********************************************************************************************************************
    Parameter for Data Flash Initialization
**********************************************************************************************************************/
typedef T_u4        T_u4_FadErr;
typedef T_u2        T_u2_FaciNumber;
typedef T_u4        T_u4_FadAddr;
typedef T_u4*       T_p_DataBuff;
typedef T_u4        T_u4_FadStatus;
typedef T_u1        T_u1_CheckDir;
typedef T_u4        T_u4_FadStsExInfo;
typedef const T_u1* T_p_FadApiVersion;


/* For Security Part Begin */

/**********************************************************************************************************************
    Data types for Security
**********************************************************************************************************************/
typedef T_bl        T_bl_LockBitProtectSwitch;

/* For Security Part End */

#endif    /* _R_FAD_TYPES_H_ */
