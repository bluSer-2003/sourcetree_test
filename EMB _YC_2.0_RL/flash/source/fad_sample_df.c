/**********************************************************************************************************************
    File Name       : fad_sample_df.c
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
    Function Name   : sample_CheckDF0

    - Outline
        Checks whether the address is in BankA of Data Flash
    - Format
        T_u4_FadErr
            sample_CheckCF0(
                T_u4_FadAddr    i_u4_FadAddr
            );
    - Input parameter
        i_u4_FadAddr        : To check address of data flash memory
    - Return
        R_FAD_OK            : Checking address is in BankA of Data Flash
        R_FAD_ERR_ILGADR    : Checking address is NOT in BankA of Data Flash
**********************************************************************************************************************/

T_u4_FadErr sample_CheckDF0(T_u4_FadAddr i_u4_FadAddr)
{
    /* Defines local variables */
    T_u4_FadErr fadErr;

    /* Initializes for local variables  */
    fadErr = R_FAD_ERR_ILGADR;

    if (i_u4_FadAddr >= (R_FAD_DF_BANK0_BASE + R_FAD_ERASE_CNT_SIZE) &&
        i_u4_FadAddr < (R_FAD_DF_BANK0_BASE + R_FAD_DF_BANK0_SIZE))
    {
        fadErr = R_FAD_OK;
    }

    return fadErr;
}

/**********************************************************************************************************************
    Function Name   : sample_CheckDF1

    - Outline
        Checks whether the address is in BankB of Data Flash
    - Format
        T_u4_FadErr
            sample_CheckDF1(
                T_u4_FadAddr    i_u4_FadAddr
            );
    - Input parameter
        i_u4_FadAddr        : To check address of data flash memory
    - Return
        R_FAD_OK            : Checking address is in BankB of Data Flash
        R_FAD_ERR_ILGADR    : Checking address is NOT in BankB of Data Flash
**********************************************************************************************************************/

T_u4_FadErr sample_CheckDF1(T_u4_FadAddr i_u4_FadAddr)
{
    /* Defines local variables */
    T_u4_FadErr fadErr;

    /* Initializes for local variables  */
    fadErr = R_FAD_ERR_ILGADR;

#ifndef	__R_FAD_DEVICE_R7F701337__
    if ((i_u4_FadAddr >= R_FAD_DF_BANK1_BASE) && (i_u4_FadAddr < (R_FAD_DF_BANK1_BASE + R_FAD_DF_BANK1_SIZE)))
    {
        fadErr = R_FAD_OK;
    }
#endif

    return fadErr;
}

/**********************************************************************************************************************
    Function Name   : sample_CheckBlockDF

    - Outline
        Checks the block size of Data Flash
    - Format
        T_u4_FadErr
            sample_CheckBlockDF(
                T_u4_FadAddr    i_u4_FadAddr
            );
    - Input parameter
        i_u4_FadAddr        : To check address of data flash memory
    - Return
        R_FAD_OK            : Normal completion
        R_FAD_ERR_BOUND     : Bound is not correct
**********************************************************************************************************************/

T_u4_FadErr sample_CheckBlockDF(T_u4_FadAddr i_u4_FadAddr)
{
    return sample_CheckBound(i_u4_FadAddr, 64);
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
    Function Name   : sample_CheckBound

    - Outline
        Checks the parameter for blank check function
    - Format
        T_u4_FadErr
            sample_BlankCheckParam(
                T_u4_FadAddr    i_u4_FadStartAddr
                T_u4_FadAddr    i_u4_FadEndAddr
                T_u1_CheckDir   i_u1_CheckDir
            );
    - Input parameter
        i_u4_FadStartAddr   : Start address for searching range
        i_u4_FadEndAddr     : End address for searching range
        i_u1_CheckDir       : Direction for search
    - Return
        R_FAD_OK            : Parameter is correct
        R_FAD_ERR_PARAM     : Parameter is NOT correct
**********************************************************************************************************************/

T_u4_FadErr sample_BlankCheckParam(
    T_u4_FadAddr    i_u4_FadStartAddr,
    T_u4_FadAddr    i_u4_FadEndAddr,
    T_u1_CheckDir   i_u1_CheckDirection
    )
{
    /* Defines local variables */
    T_u4_FadErr fadErr;
    T_u4        range;

    /* Initializes for Return value */
    fadErr = R_FAD_ERR_PARAM;

    if (i_u1_CheckDirection == 0)
    {
        if (i_u4_FadStartAddr <= i_u4_FadEndAddr)
        {
            range = i_u4_FadEndAddr - i_u4_FadStartAddr;
            if (range <= 65536)
            {
                fadErr = R_FAD_OK;
            }
        }
    }
    else
    {
        if (i_u4_FadStartAddr >= i_u4_FadEndAddr)
        {
            range = i_u4_FadStartAddr - i_u4_FadEndAddr;
            if (range <= 65536)
            {
                fadErr = R_FAD_OK;
            }
        }
    }

    return fadErr;
}

/**********************************************************************************************************************
    Function Name   : sample_DF_Write

    - Outline
        Writes data to Data Flash
    - Format
        T_u4_FadErr
            sample_DF_Write(
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

T_u4_FadErr sample_DF_Write(T_u4_FadAddr i_u4_FadAddr, T_p_DataBuff i_p_DataBuff, T_u4 i_u4_TimeOutCount)
{
    /* Defines local variables */
    T_u4_FadErr         fadErr;
    T_bl                errFlag;
    T_u4_FadStatus      sts;
    T_u4_FadStsExInfo   stsinfo;

    /* Initializes error flag */
    errFlag = FALSE;

    /* Checks the range of memory */
    fadErr = sample_CheckDF0(i_u4_FadAddr);
    
    if (R_FAD_IS_ERROR(fadErr))
    {
        fadErr = sample_CheckDF1(i_u4_FadAddr);

        if (R_FAD_IS_ERROR(fadErr))
        {
            errFlag = TRUE;
        }
    }
    
    /* The flash status is OK   */
    if (errFlag != TRUE)
    {
        /* Checks border of start address of Code Flash */
        fadErr = sample_CheckBound((T_u4)i_u4_FadAddr, 4);

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
        fadErr = R_FAD_DF_Write(i_u4_FadAddr, i_p_DataBuff, R_FAD_NO_TIMEOUT);

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
    Function Name   : sample_DF_Erase

    - Outline
        Erases block of Code Flash
    - Format
        T_u4_FadErr
            sample_DF_Erase(
                T_u4_FadAddr    i_u4_FadAddr,
            );
    - Input parameter
        i_u4_FadAddr        : Start address of block to erase
    - Return
        R_FAD_OK            : Normal completion
        R_FAD_ERR_CMDLK     : Command locked
        R_FAD_ERR_BOUND     : Address is NOT correct bound
**********************************************************************************************************************/

T_u4_FadErr sample_DF_Erase(T_u4_FadAddr i_u4_FadAddr, T_u4 i_u4_TimeOutCount)
{
    T_u4_FadErr         fadErr;
    T_bl                errFlag;
    T_u4_FadStatus      sts;
    T_u4_FadStsExInfo   stsinfo;

    /* Initializes error flag */
    errFlag = FALSE;

    /* Checks the range of memory */
    fadErr = sample_CheckDF0(i_u4_FadAddr);

    if (R_FAD_IS_ERROR(fadErr))
    {
        fadErr = sample_CheckDF1(i_u4_FadAddr);

        if (R_FAD_IS_ERROR(fadErr))
        {
            errFlag = TRUE;
        }
    }

    /* The flash status is OK   */
    if (errFlag != TRUE)
    {
        /* Checks the start block address */
        fadErr = sample_CheckBlockDF(i_u4_FadAddr);

        if (R_FAD_IS_ERROR(fadErr))
        {
            errFlag = TRUE;
        }
    }

    /* The flash status is OK   */
    if (errFlag != TRUE)
    {
        /* Erasures */
        fadErr = R_FAD_DF_Erase(i_u4_FadAddr, R_FAD_NO_TIMEOUT);

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
    Function Name   : sample_DF_BlankCheck

    - Outline
        Erases block of Code Flash
    - Format
        T_u4_FadErr
            sample_DF_BlankCheck(
                T_u4_FadAddr    i_u4_FadAddr,
            );
    - Input parameter
        i_u4_FadAddr        : Start address of block to erase
    - Return
        R_FAD_OK            : Normal completion
        R_FAD_ERR_CMDLK     : Command locked
        R_FAD_ERR_BOUND     : Address is NOT correct bound
**********************************************************************************************************************/

T_u4_FadErr sample_DF_BlankCheck(
    T_u4_FadAddr    i_u4_FadStartAddr,
    T_u4_FadAddr    i_u4_FadEndAddr,
    T_u1_CheckDir   i_u1_CheckDirection,
    T_u4            i_u4_TimeOutCount
    )
{
    /* Defines local variables */
    T_u4_FadErr         fadErr;
    T_bl                errFlag;
    T_u4_FadStatus      sts;
    T_u4_FadStsExInfo   stsinfo;
    T_u2                faci_no_s;
    T_u2                faci_no_e;
    T_u2                faci_no;

    /* Initializes error flag */
    errFlag = FALSE;

    /* Checks the range of memory */
    faci_no_s = 0;

    fadErr = sample_CheckDF0(i_u4_FadStartAddr);

    if (R_FAD_IS_ERROR(fadErr))
    {
        fadErr = sample_CheckDF1(i_u4_FadStartAddr);

        if (R_FAD_IS_ERROR(fadErr))
        {
            errFlag = TRUE;
        }
        else
        {
            faci_no_s = 1;
        }
    }

    /* The flash status is OK   */
    if (errFlag != TRUE)
    {
        faci_no_e = 0;

        fadErr = sample_CheckDF0(i_u4_FadEndAddr);

        if (R_FAD_IS_ERROR(fadErr))
        {
            fadErr = sample_CheckDF1(i_u4_FadEndAddr);

            if (R_FAD_IS_ERROR(fadErr))
            {
                errFlag = TRUE;
            }
            else
            {
                faci_no_e = 1;
            }
        }
    }

    /* The flash status is OK   */
    if (errFlag != TRUE)
    {
        /* Checks extend the bank */
        if (faci_no_s != faci_no_e)
        {
            errFlag = TRUE;
            fadErr = R_FAD_ERR_ILGADR;
        }
    }

    /* The flash status is OK   */
    if (errFlag != TRUE)
    {
        /* Checks the parameter of blank check */
        fadErr = sample_BlankCheckParam(i_u4_FadStartAddr, i_u4_FadEndAddr, i_u1_CheckDirection);

        if (R_FAD_IS_ERROR(fadErr))
        {
            errFlag = TRUE;
        }
    }

    /* The flash status is OK   */
    if (errFlag != TRUE)
    {
        /* Blank check */
        fadErr = R_FAD_DF_BlankCheck(i_u4_FadStartAddr, i_u4_FadEndAddr, i_u1_CheckDirection, R_FAD_NO_TIMEOUT);

        if (R_FAD_IS_ERROR(fadErr))
        {
            errFlag = TRUE;
        }
    }

    /* The flash status is OK   */
    if (errFlag != TRUE)
    {
        faci_no = R_FAD_GET_FACI_NUMBER(fadErr);

        /* Waits the finish of command */
        do {
            sts = R_FAD_GetStatus(faci_no, &stsinfo);
            if (sts == R_FAD_STS_CMDLK) break;
        } while (!(sts == R_FAD_STS_BLKCHK0 || sts == R_FAD_STS_BLKCHK1));
        if (sts == R_FAD_STS_BLKCHK0)
        {
            fadErr = R_FAD_BLKCHK0;
        }
        else if (sts == R_FAD_STS_BLKCHK1)
        {
            fadErr = R_FAD_BLKCHK1;
        }
    }

    return R_FAD_SET_FACI_NUMBER(fadErr, faci_no);
    
}

