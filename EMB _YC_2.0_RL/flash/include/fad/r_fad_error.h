/**********************************************************************************************************************
    Program Name    : Flash Access Driver (FAD)

    File Name       : r_fad_error.h
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

#ifndef _R_FAD_API_ERROR_H_
#define _R_FAD_API_ERROR_H_

/**********************************************************************************************************************
    Error code
**********************************************************************************************************************/

#define R_FAD_OK            0x00000000
#define R_FAD_NOTSUS        0x00000001
#define R_FAD_ERR_CMDLK     0x00008000
#define R_FAD_ERR_BUSY      0x00008001
#define R_FAD_ERR_PRGSPD    0x00008002
#define R_FAD_ERR_ERSSPD    0x00008003
#define R_FAD_ERR_FCUTRNS   0x00008004
#define R_FAD_ERR_CLOCK     0x00008005
#define R_FAD_ERR_NOTSPD    0x00008006
#define R_FAD_ERR_CANNOTSPD 0x00008007
#define R_FAD_ERR_FLMD0     0x00008008
#define R_FAD_ERR_IDAUTH    0x00008009
#define R_FAD_ERR_TIMEOUT   0x00008010
#define R_FAD_ERR_INTERNAL  0x00008100

/**********************************************************************************************************************
    Status
**********************************************************************************************************************/

#define R_FAD_STS_IDLE      0x00000000
#define R_FAD_STS_BUSY      0x00000001
#define R_FAD_STS_CMDLK     0x00000002
#define R_FAD_STS_SUSRDY    0x00000003
#define R_FAD_STS_PRGSPD    0x00000004
#define R_FAD_STS_ERSSPD    0x00000005
#define R_FAD_STS_LKREAD0   0x00000010
#define R_FAD_STS_LKREAD1   0x00000011
#define R_FAD_STS_BLKCHK0   0x00000020
#define R_FAD_STS_BLKCHK1   0x00000021

/**********************************************************************************************************************
    Command
**********************************************************************************************************************/

#define R_FAD_CMD_UNDEF             0x00
#define R_FAD_CMD_PROGRAM           0x01
#define R_FAD_CMD_BLOCK_ERASE       0x02
#define R_FAD_CMD_BLANK_CHECK       0x03
#define R_FAD_CMD_CONFIG_PROGRAM    0x04
#define R_FAD_CMD_LOCK_BIT_PROGRAM  0x05
#define R_FAD_CMD_LOCK_BIT_READ     0x06
#define R_FAD_CMD_OTP_SET           0x07

/**********************************************************************************************************************
    Detail Error Information
**********************************************************************************************************************/

#define R_FAD_ERR_STS_CFAE          (1UL << 31)
#define R_FAD_ERR_STS_DFAE          (1UL << 30)
#define R_FAD_ERR_STS_OTPDTCT       (1UL << 17)
#define R_FAD_ERR_STS_ILGLERR       (1UL << 14)
#define R_FAD_ERR_STS_ERSERR        (1UL << 13)
#define R_FAD_ERR_STS_PRGERR        (1UL << 12)
#define R_FAD_ERR_STS_ERSERR_LOCK   (1UL << 29)
#define R_FAD_ERR_STS_PRGERR_LOCK   (1UL << 28)
#define R_FAD_ERR_STS_FCUERR        (1UL <<  7)
#define R_FAD_ERR_STS_FLWEERR       (1UL <<  6)
#define R_FAD_ERR_STS_CFGDTCT       (1UL <<  5)
#define R_FAD_ERR_STS_TBLDTCT       (1UL <<  3)
#define R_FAD_ERR_STS_FRDTCT        (1UL <<  1)

#endif    /* _R_FAD_API_ERROR_H_ */
