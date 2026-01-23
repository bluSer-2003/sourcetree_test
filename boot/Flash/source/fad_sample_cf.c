/**********************************************************************************************************************
    File Name       : fad_sample_cf.c
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

#include "fad_sample.h"
#include "fad_range_r7f701374.h"

#ifdef  __GHS__
#pragma ghs section text="R_FAD_USER"
#endif

/**********************************************************************************************************************
    Function Name   : sample_CheckCF0

    - Outline
        Checks whether the address is in BankA of Code Flash
    - Format
        T_u4_FadErr
            sample_CheckCF0(
                T_u4_FadAddr    i_u4_FadAddr
            );
    - Input parameter
        i_u4_FadAddr        : To check address of code flash memory
    - Return
        R_FAD_OK            : Checking address is in BankA of Code Flash
        R_FAD_ERR_ILGADR    : Checking address is NOT in BankA of Code Flash
**********************************************************************************************************************/

T_u4_FadErr sample_CheckCF0(T_u4_FadAddr i_u4_FadAddr)
{
    /* Defines local variables */
    T_u4_FadErr fadErr;

    /* Initializes for local variables  */
    fadErr = R_FAD_ERR_ILGADR;

    if ((i_u4_FadAddr > R_FAD_CF_BANK0_BASE) && (i_u4_FadAddr < (R_FAD_CF_BANK0_BASE + R_FAD_CF_BANK0_SIZE)))
    {
        fadErr = R_FAD_OK;
    }

    return fadErr;
}

/**********************************************************************************************************************
    Function Name   : sample_CheckCF1

    - Outline
        Checks whether the address is in BankB of Code Flash
    - Format
        T_u4_FadErr
            sample_CheckCF1(
                T_u4_FadAddr    i_u4_FadAddr
            );
    - Input parameter
        i_u4_FadAddr        : To check address of code flash memory
    - Return
        R_FAD_OK            : Checking address is in BankB of Code Flash
        R_FAD_ERR_ILGADR    : Checking address is NOT in BankB of Code Flash
**********************************************************************************************************************/

T_u4_FadErr sample_CheckCF1(T_u4_FadAddr i_u4_FadAddr)
{
    /* Defines local variables */
    T_u4_FadErr fadErr;

    /* Initializes for local variables  */
    fadErr = R_FAD_ERR_ILGADR;

#ifndef	__R_FAD_DEVICE_R7F701337__
    if ((i_u4_FadAddr >= R_FAD_CF_BANK1_BASE) && (i_u4_FadAddr < (R_FAD_CF_BANK1_BASE + R_FAD_CF_BANK1_SIZE)))
    {
        fadErr = R_FAD_OK;
    }
#endif
    
    return fadErr;
}

/**********************************************************************************************************************
    Function Name   : sample_CheckBlockCF

    - Outline
        Checks the block size of Code Flash
    - Format
        T_u4_FadErr
            sample_CheckBlockCF(
                T_u4_FadAddr    i_u4_FadAddr
            );
    - Input parameter
        i_u4_FadAddr        : To check address of code flash memory
    - Return
        R_FAD_OK            : Normal completion
        R_FAD_ERR_BOUND     : Bound is not correct
**********************************************************************************************************************/

T_u4_FadErr sample_CheckBlockCF(T_u4_FadAddr i_u4_FadAddr)
{
    /* Defines local variables  */
    T_u2    bound;

    /* Initializes for local variables  */
    bound = 32768;  /* 32K Bytes    */

    /* Checks 8K Bytes block */
    if ((i_u4_FadAddr - R_FAD_CF_BANK0_BASE) < (R_FAD_8K_BLOCK_NUM * 8192))
    {
        bound = 8192;
    }

    return sample_CheckBound((T_u4)i_u4_FadAddr, bound);
}

/**********************************************************************************************************************
    Function Name   : sample_CheckBound

    - Outline
        Checks whether the address is correct bound
    - Format
        T_u4_FadErr
            sample_CheckBound(
                T_u4    i_u4_Addr
                T_u2    bound
            );
    - Input parameter
        i_u4_Addr           : To check address
        bound               : bound value
    - Return
        R_FAD_OK            : Address is correct bound
        R_FAD_ERR_BOUND     : Address is NOT correct bound
**********************************************************************************************************************/

T_u4_FadErr sample_CheckBound(T_u4 i_u4_Addr, T_u2 bound)
{
    /* Defines local variables */
    T_u4_FadErr fadErr;

    /* Initializes for local variables  */
    fadErr = R_FAD_ERR_BOUND;

    if ((i_u4_Addr % bound) == 0)
    {
        fadErr = R_FAD_OK;
    }

    return fadErr;
}

/**********************************************************************************************************************
    Function Name   : sample_CF_Write

    - Outline
        Writes data to Code Flash
    - Format
        T_u4_FadErr
            sample_CF_Write(
                T_u4_FadAddr    i_u4_FadAddr,
                T_p_DataBuff    i_p_DataBuff
            );
    - Input parameter
        i_u4_FadAddr        : Start address to write
        i_p_DataBuff        : To write data
    - Return
        R_FAD_OK            : Normal completion
        R_FAD_ERR_CMDLK     : Command locked
        R_FAD_ERR_BOUND     : Address is NOT correct bound
**********************************************************************************************************************/

T_u4_FadErr sample_CF_Write(T_u4_FadAddr i_u4_FadAddr, T_p_DataBuff i_p_DataBuff, T_u4 i_u4_TimeOutCount)
{
    /* Defines local variables */
    T_u4_FadErr         fadErr;
    T_bl                errFlag;
    T_u4_FadStatus      sts;
    T_u4_FadStsExInfo   stsinfo;

    /* Initializes error flag */
    errFlag = FALSE;

    /* Checks the range of memory */
    fadErr = sample_CheckCF0(i_u4_FadAddr);

    if (R_FAD_IS_ERROR(fadErr) == TRUE)
    {
        fadErr = sample_CheckCF1(i_u4_FadAddr);

        if (R_FAD_IS_ERROR(fadErr))
        {
            errFlag = TRUE;
        }
    }

    /* The flash status is OK   */
    if (errFlag != TRUE)
    {
        /* Checks border of start address of Code Flash */
        fadErr = sample_CheckBound((T_u4)i_u4_FadAddr, 256);

        if (R_FAD_IS_ERROR(fadErr))
        {
            errFlag = TRUE;
        }

    }

    /* The flash status is OK   */
    if (errFlag != TRUE)
    {
        /* Checks border of writing date    */
        fadErr = sample_CheckBound((T_u4)i_p_DataBuff, 4);

        if (R_FAD_IS_ERROR(fadErr))
        {
            errFlag = TRUE;
        }
    }

    /* The flash status is OK   */
    if (errFlag != TRUE)
    {
        /* Writes data  */
        fadErr = R_FAD_CF_Write(i_u4_FadAddr, i_p_DataBuff, R_FAD_NO_TIMEOUT);

        if (R_FAD_IS_ERROR(fadErr))
        {
            errFlag = TRUE;
        }
    }

    /* The flash status is OK   */
    if (errFlag != TRUE)
    {
        /* Waits the finish of command */
        do {
            sts = R_FAD_GetStatus(R_FAD_GET_FACI_NUMBER(fadErr), &stsinfo);
            if (sts == R_FAD_STS_CMDLK)
            {
                fadErr = R_FAD_ERR_CMDLK;
                break;
            }

        } while (sts != R_FAD_STS_IDLE);

    }

    return fadErr;
}

/**********************************************************************************************************************
    Function Name   : sample_CF_Erase

    - Outline
        Erases block of Code Flash
    - Format
        T_u4_FadErr
            sample_CF_Erase(
                T_u4_FadAddr    i_u4_FadAddr,
            );
    - Input parameter
        i_u4_FadAddr        : Start address of block to erase
    - Return
        R_FAD_OK            : Normal completion
        R_FAD_ERR_CMDLK     : Command locked
        R_FAD_ERR_BOUND     : Address is NOT correct bound
**********************************************************************************************************************/

T_u4_FadErr sample_CF_Erase(T_u4_FadAddr i_u4_FadAddr, T_u4 i_u4_TimeOutCount)
{
    /* Defines local variables */
    T_u4_FadErr         fadErr;
    T_bl                errFlag;
    T_u4_FadStatus      sts;
    T_u4_FadStsExInfo   stsinfo;

    /* Initializes error flag */
    errFlag = FALSE;

    /* Checks the range of memory */
    fadErr = sample_CheckCF0(i_u4_FadAddr);
    if (R_FAD_IS_ERROR(fadErr))
    {
        fadErr = sample_CheckCF1(i_u4_FadAddr);

        if (R_FAD_IS_ERROR(fadErr))
        {
            errFlag = TRUE;
        }
    }

    /* The flash status is OK   */
    if (errFlag != TRUE)
    {
        /* Checks the start block address */
        fadErr = sample_CheckBlockCF(i_u4_FadAddr);

        if (R_FAD_IS_ERROR(fadErr))
        {
            errFlag = TRUE;
        }
    }

    /* The flash status is OK   */
    if (errFlag != TRUE)
    {
        /* Erasures */
        fadErr = R_FAD_CF_Erase(i_u4_FadAddr, R_FAD_NO_TIMEOUT);

        if (R_FAD_IS_ERROR(fadErr))
        {
            errFlag = TRUE;
        }
    }
    
    /* The flash status is OK   */
    if (errFlag != TRUE)
    {
        /* Waits the finish of command */
        do {
            sts = R_FAD_GetStatus(R_FAD_GET_FACI_NUMBER(fadErr), &stsinfo);
            if (sts == R_FAD_STS_CMDLK)
            {
                fadErr = R_FAD_ERR_CMDLK;
                break;
            }

        } while (sts != R_FAD_STS_IDLE);

    }

    return fadErr;
}

/* For Security Part Begin */

/**********************************************************************************************************************
    Function Name   : sample_CheckCfg

    - Outline
        Checks whether the address is in Configuration Area
    - Format
        T_u4_FadErr
            sample_CheckCF1(
                T_u4_FadAddr    i_u4_FadAddr
            );
    - Input parameter
        i_u4_FadAddr        : To check address of code flash memory
    - Return
        R_FAD_OK            : Checking address is in BankB of Code Flash
        R_FAD_ERR_ILGADR    : Checking address is NOT in BankB of Code Flash
**********************************************************************************************************************/

T_u4_FadErr sample_CheckCfg(T_u4_FadAddr i_u4_FadAddr)
{
    /* Defines local variables */
    T_u4_FadErr fadErr;

    /* Initializes for local variables  */
    fadErr = R_FAD_ERR_ILGADR;

    if ((i_u4_FadAddr >= R_FAD_CONFIG_BASE) && (i_u4_FadAddr < (R_FAD_CONFIG_BASE + R_FAD_CONFIG_SIZE)))
    {
        fadErr = R_FAD_OK;
    }

    return fadErr;
}

/**********************************************************************************************************************
    Function Name   : sample_CheckOTP0

    - Outline
        Checks whether the address is in OTP Area of BankA
    - Format
        T_u4_FadErr
            sample_CheckCF1(
                T_u4_FadAddr    i_u4_FadAddr
            );
    - Input parameter
        i_u4_FadAddr        : To check address of code flash memory
    - Return
        R_FAD_OK            : Checking address is in BankB of Code Flash
        R_FAD_ERR_ILGADR    : Checking address is NOT in BankB of Code Flash
**********************************************************************************************************************/

T_u4_FadErr sample_CheckOTP0(T_u4_FadAddr i_u4_FadAddr)
{
    /* Defines local variables */
    T_u4_FadErr fadErr;

    /* Initializes for local variables  */
    fadErr = R_FAD_ERR_ILGADR;

    if ((i_u4_FadAddr >= R_FAD_OTP_BANK0_BASE) && (i_u4_FadAddr < (R_FAD_OTP_BANK0_BASE + R_FAD_OTP_BANK0_SIZE)))
    {
        fadErr = R_FAD_OK;
    }

    return fadErr;
}

/**********************************************************************************************************************
    Function Name   : sample_CheckOTP1

    - Outline
        Checks whether the address is in OTP Area of BankA
    - Format
        T_u4_FadErr
            sample_CheckCF1(
                T_u4_FadAddr    i_u4_FadAddr
            );
    - Input parameter
        i_u4_FadAddr        : To check address of code flash memory
    - Return
        R_FAD_OK            : Checking address is in BankB of Code Flash
        R_FAD_ERR_ILGADR    : Checking address is NOT in BankB of Code Flash
**********************************************************************************************************************/

T_u4_FadErr sample_CheckOTP1(T_u4_FadAddr i_u4_FadAddr)
{
    /* Defines local variables */
    T_u4_FadErr fadErr;

    /* Initializes for local variables  */
    fadErr = R_FAD_ERR_ILGADR;

#ifndef __R_FAD_DEVICE_R7F701337__
    if ((i_u4_FadAddr >= R_FAD_OTP_BANK1_BASE) && (i_u4_FadAddr < (R_FAD_OTP_BANK1_BASE + R_FAD_OTP_BANK1_SIZE)))
    {
        fadErr = R_FAD_OK;
    }
#endif
    
    return fadErr;
}

/**********************************************************************************************************************
    Function Name   : sample_CF_SetLockBit

    - Outline
        Sets lock bit
    - Format
        T_u4_FadErr
            sample_CF_SetLockBit(
                T_u4_FadAddr    i_u4_FadAddr,
            );
    - Input parameter
        i_u4_FadAddr        : Start address to set the lock bit
    - Return
        R_FAD_OK            : Normal completion
        R_FAD_ERR_CMDLK     : Command locked
        R_FAD_ERR_BOUND     : Address is NOT correct bound
**********************************************************************************************************************/

T_u4_FadErr sample_CF_SetLockBit(T_u4_FadAddr i_u4_FadAddr, T_u4 i_u4_TimeOutCount)
{
    /* Defines local variables */
    T_u4_FadErr         fadErr;
    T_bl                errFlag;
    T_u4_FadStatus      sts;
    T_u4_FadStsExInfo   stsinfo;

    /* Initializes error flag */
    errFlag = FALSE;

    /* Checks the range of memory */
    fadErr = sample_CheckCF0(i_u4_FadAddr);

    if (R_FAD_IS_ERROR(fadErr))
    {
        fadErr = sample_CheckCF1(i_u4_FadAddr);

        if (R_FAD_IS_ERROR(fadErr))
        {
            errFlag = TRUE;
        }
    }

    /* The flash status is OK   */
    if (errFlag != TRUE)
    {
        /* Checks the start address */
        fadErr = sample_CheckBlockCF(i_u4_FadAddr);

        if (R_FAD_IS_ERROR(fadErr))
        {
            errFlag = TRUE;
        }
    }

    /* The flash status is OK   */
    if (errFlag != TRUE)
    {
        /* Sets lock bit */
        fadErr = R_FAD_CF_SetLockBit(i_u4_FadAddr, R_FAD_NO_TIMEOUT);

        if (R_FAD_IS_ERROR(fadErr))
        {
            errFlag = TRUE;
        }
    }

    /* The flash status is OK   */
    if (errFlag != TRUE)
    {
        /* Waits the finish of command */
        do {
            sts = R_FAD_GetStatus(R_FAD_GET_FACI_NUMBER(fadErr), &stsinfo);
            if (sts == R_FAD_STS_CMDLK)
            {
                fadErr = R_FAD_ERR_CMDLK;
                break;
            }

        } while (sts != R_FAD_STS_IDLE);

    }

    return fadErr;
}

/**********************************************************************************************************************
    Function Name   : sample_CF_GetLockBit

    - Outline
        Acquires lock bit
    - Format
        T_u4_FadErr
            sample_CF_GetLockBit(
                T_u4_FadAddr    i_u4_FadAddr,
            );
    - Input parameter
        i_u4_FadAddr        : Start address to aquire the lock bit
    - Return
        R_FAD_OK            : Normal completion
        R_FAD_ERR_CMDLK     : Command locked
        R_FAD_ERR_BOUND     : Address is NOT correct bound
**********************************************************************************************************************/

T_u4_FadErr sample_CF_GetLockBit(T_u4_FadAddr i_u4_FadAddr, T_u4 i_u4_TimeOutCount)
{
    /* Defines local variables */
    T_u4_FadErr         fadErr;
    T_bl                errFlag;
    T_u4_FadStatus      sts;
    T_u4_FadStsExInfo   stsinfo;

    /* Initializes error flag */
    errFlag = FALSE;

    /* Checks the range of memory */
    fadErr = sample_CheckCF0(i_u4_FadAddr);
    if (R_FAD_IS_ERROR(fadErr))
    {
        fadErr = sample_CheckCF1(i_u4_FadAddr);

        if (R_FAD_IS_ERROR(fadErr))
        {
            errFlag = TRUE;
        }
    }

    /* The flash status is OK   */
    if (errFlag != TRUE)
    {
        /* Checks the start address */
        fadErr = sample_CheckBlockCF(i_u4_FadAddr);

        if (R_FAD_IS_ERROR(fadErr))
        {
            errFlag = TRUE;
        }
    }

    /* The flash status is OK   */
    if (errFlag != TRUE)
    {
        /* Acquires lock bit */
        fadErr = R_FAD_CF_GetLockBit(i_u4_FadAddr, R_FAD_NO_TIMEOUT);

        if (R_FAD_IS_ERROR(fadErr))
        {
            errFlag = TRUE;
        }
    }

    /* The flash status is OK   */
    if (errFlag != TRUE)
    {
        /* Waits the finish of command */
        do {
            sts = R_FAD_GetStatus(R_FAD_GET_FACI_NUMBER(fadErr), &stsinfo);
            if (sts == R_FAD_STS_CMDLK)
            {
                fadErr = R_FAD_ERR_CMDLK;
                break;
            }

        } while (!(sts == R_FAD_STS_LKREAD0 || sts == R_FAD_STS_LKREAD1));

        if (sts == R_FAD_STS_LKREAD0)
        {
            fadErr = R_FAD_LKREAD0;
        }
        else if (sts == R_FAD_STS_LKREAD1)
        {
            fadErr = R_FAD_LKREAD1;
        }
    }

    return fadErr;
}

/* For Security Part End */

