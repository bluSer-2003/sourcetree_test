/**********************************************************************************************************************
    File Name       : fad_range.h
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

/******************************************************************************
    Define the macros of the device to be used
        R7F701337   RH850/P1L-C
        R7F701371   RH850/P1H-C(8MB)
        R7F701372   RH850/P1H-C(4MB)
        R7F701373   RH850/P1M-C(BGA292)
        R7F701374   RH850/P1M-C(QFP144)
******************************************************************************/

#if defined(__R_FAD_DEVICE_R7F701371__)
#include "device/fad_range_r7f701371.h"

#elif defined(__R_FAD_DEVICE_R7F701372__)
#include "device/fad_range_r7f701372.h"

#elif defined(__R_FAD_DEVICE_R7F701373__)
#include "device/fad_range_r7f701373.h"

#elif defined(__R_FAD_DEVICE_R7F701374__)
#include "device/fad_range_r7f701374.h"

#elif defined(__R_FAD_DEVICE_R7F701337__)
#include "device/fad_range_r7f701337.h"

#endif
