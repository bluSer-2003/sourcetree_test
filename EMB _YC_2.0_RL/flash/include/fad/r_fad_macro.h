/**********************************************************************************************************************
    Program Name    : Flash Access Driver (FAD)

    File Name       : r_fad_macro.h
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

#ifndef _R_FAD_MACRO_H_
#define _R_FAD_MACRO_H_

/**********************************************************************************************************************
    For writing to FACI Command
**********************************************************************************************************************/

#define R_FAD_MASK_ERROR        0x00008000
#define R_FAD_MASK_FACI         0x00030000  /* 16-17 bit  0:FACI0 1:FACI1 2,3:Reservation */

#define R_FAD_SHIFT_FACI        16

#define R_FAD_IS_ERROR(error)               ((error & R_FAD_MASK_ERROR) != 0)
#define R_FAD_GET_FACI_NUMBER(error)        ((error & ~R_FAD_MASK_ERROR) >> R_FAD_SHIFT_FACI)
#define R_FAD_GET_ERRCD(error)              (error & ~R_FAD_MASK_FACI)
#define R_FAD_SET_FACI_NUMBER(error, faci)  (error | (faci << R_FAD_SHIFT_FACI))

#endif  /* _R_FAD_MACRO_H_ */
