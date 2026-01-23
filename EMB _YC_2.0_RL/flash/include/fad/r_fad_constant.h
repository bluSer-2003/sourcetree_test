/**********************************************************************************************************************
    Program Name    : Flash Access Driver (FAD)

    File Name       : r_fad_constant.h
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

#ifndef _R_FAD_CONSTANT_H_
#define _R_FAD_CONSTANT_H_

/**********************************************************************************************************************
    Constants definition
**********************************************************************************************************************/

#define R_FAD_SUSPRI_MODE   0       /* Suspended priority mode                  */
#define R_FAD_ERSPRI_MODE   1       /* Erasure priority mode                    */
#define R_FAD_INC_MODE      0       /* Increment mode                           */
#define R_FAD_DEC_MODE      1       /* Decrement mode                           */
#define R_FAD_FACI0         0       /* Specifies FACI0                          */
#define R_FAD_FACI1         1       /* Specifies FACI1                          */
#define R_FAD_NO_TIMEOUT    0       /* No Timeout Mode for waiting the FENTRYR  */

/**********************************************************************************************************************
    ID Status for Authentication ID
**********************************************************************************************************************/

#define R_FAD_IDSTATUS_SELFIDST     0x01    /* Authentication status SELFID */

/**********************************************************************************************************************
    Length of Autentication ID
**********************************************************************************************************************/

#define R_FAD_IDLENGTH_SELFID       256     /* SELFID Authentication length */


/* For Security Part Begin */

/**********************************************************************************************************************
    Constants definition for Security
**********************************************************************************************************************/

#define R_FAD_LB_ENABLE     0       /* Protection for writing and erasing is enabled */
#define R_FAD_LB_DISABLE    1       /* Protection for writing and erasing is dnabled */

/**********************************************************************************************************************
    ID Status for Authentication ID for Security
**********************************************************************************************************************/

#define R_FAD_IDSTATUS_CFRDIDST     0x02    /* Authentication status CFRDID */
#define R_FAD_IDSTATUS_DFRDIDST     0x04    /* Authentication status DFRDID */
#define R_FAD_IDSTATUS_CFPEIDST     0x08    /* Authentication status CFPEID */
#define R_FAD_IDSTATUS_DFPEIDST     0x10    /* Authentication status DFPEID */

/**********************************************************************************************************************
    Length of Autentication ID for Security
**********************************************************************************************************************/

#define R_FAD_IDLENGTH_CFRDID       256     /* CFRDID Authentication length */
#define R_FAD_IDLENGTH_DFRDID       256     /* DFRDID Authentication length */
#define R_FAD_IDLENGTH_CFPEID       256     /* CFPEID Authentication length */
#define R_FAD_IDLENGTH_DFPEID       256     /* DFPEID Authentication length */

/* For Security Part End */

#endif    /* _R_FAD_CONSTANT_H_ */
