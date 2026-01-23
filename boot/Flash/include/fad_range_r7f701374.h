/**********************************************************************************************************************
    File Name       : fad_range_r7f701374.h
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

/**********************************************************************************************************************
    Device Information
      - R7F701374(P1M-C QFP144)
**********************************************************************************************************************/

/**********************************************************************************************************************
    Base Address
**********************************************************************************************************************/

#define R_FAD_CF_BANK0_BASE     (0x00000000)
#define R_FAD_CF_BANK1_BASE     (0x00800000)
#define R_FAD_DF_BANK0_BASE     (0xFF200000)
#define R_FAD_DF_BANK1_BASE     (0xFF300000)
#define R_FAD_LOCAL_RAM_BASE    (0xFEDE0000)
#define R_FAD_GLOBAL_RAM_BASE   (0xFEED8000)

/* For Security Part Begin */

#define R_FAD_CONFIG_BASE       (0xFF280040)
#define R_FAD_OTP_BANK0_BASE    (0xFF2C0040)
#define R_FAD_OTP_BANK1_BASE    (0xFF3C0040)

/* For Security Part End */

/**********************************************************************************************************************
    Size
**********************************************************************************************************************/

#define R_FAD_CF_BANK0_SIZE     (0x00200000)    /* 2M Bytes                         */
#define R_FAD_CF_BANK1_SIZE     (0x00200000)    /* 2M Bytes                         */
#define R_FAD_DF_BANK0_SIZE     (0x00010000)    /* 64K Bytes                        */
#define R_FAD_DF_BANK1_SIZE     (0x00000000)    /* non                              */
#define R_FAD_LOCAL_RAM_SIZE    (0x00020000)    /* 128K Bytes                       */
#define R_FAD_GLOBAL_RAM_SIZE   (0x00050000)    /* 320K Bytes                       */
#define R_FAD_8K_BLOCK_NUM      (8)             /* The number of blocks of 8K Bytes */
#define R_FAD_ERASE_CNT_SIZE    (704)           /* The size of erasure counter      */

/* For Security Part Begin */

#define R_FAD_CONFIG_SIZE       (192)
#define R_FAD_OTP_BANK0_SIZE    (80)
#define R_FAD_OTP_BANK1_SIZE    (80)

/* For Security Part End */

