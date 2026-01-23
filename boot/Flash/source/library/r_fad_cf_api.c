/**********************************************************************************************************************
    Program Name    : Flash Access Driver (FAD)

    File Name       : r_fad_cf_api.c
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

#include "r_fad.h"
#include "r_fad_local.h"

/**********************************************************************************************************************
   Version number of the code flash functions
**********************************************************************************************************************/
#ifdef  __GHS__
#pragma ghs section rodata = "R_FAD_CONST"
#endif

const T_u1 pu1_versionCFStr[] = R_FAD_CF_VERSION;

/**********************************************************************************************************************
    Function Name   : R_FAD_CF_Init

    - Outline
        Makes the initial settings of the code flash
    - Format
        T_u4_FadErr
            R_FAD_CF_Init(void);
    - Input parameter
        non
    - Return
        R_FAD_OK            : Normal completion
        R_FAD_ERR_FCUTRNS   : Transfer to FCU firmware failed
        R_FAD_ERR_CLOCK     : The CPU clock frequency is incorrect.
**********************************************************************************************************************/
#ifdef  __GHS__
#pragma ghs section text = "R_FAD_CODE_ROM"
#endif

T_u4_FadErr
R_FAD_CF_Init(void)
{
    /* Defines local variables */
    T_u4_FadErr l_bu4_fadErr;
    T_u1        l_bu1_regFpmon;
    
    /* Initializes for Return value */
    l_bu4_fadErr = R_FAD_OK;
    
    /* Checks FLMD0 */
    /* When the transitions to the code flash program/erasure mode (FWE in FPMON) are disabled */
    l_bu1_regFpmon = R_FAD_REG_FACI0.FPMON;
    
    if (l_bu1_regFpmon != R_FAD_FPMON_FWE)
    {
        l_bu4_fadErr = R_FAD_ERR_FLMD0;
    }
    
    return l_bu4_fadErr;
}

/**********************************************************************************************************************
    Function Name   : R_FAD_CF_GetApiVersion

    - Outline
        Acquires version information of the code flash functions
    - Format
        T_p_FadApiVersion
            R_FAD_CF_GetApiVersion(void);
    - Input parameter
        non
    - Return
        versionCFStr    : Pointer to the string in which version information of the code flash functions are stored
**********************************************************************************************************************/

T_p_FadApiVersion
R_FAD_CF_GetApiVersion(void)
{
    return pu1_versionCFStr;
}

/**********************************************************************************************************************
    Function Name   : R_FAD_CF_Write

    - Outline
        Writes data to code flash memory
    - Format
        T_u4_FadErr
            R_FAD_CF_Write(
                T_u4_FadAddr    i_u4_FadAddr,
                T_p_DataBuff    i_p_DataBuff,
                T_u4            i_u4_TimeOutCount
            );
    - Input parameter
        i_u4_FadAddr        : Address of code flash memory from which programming starts
        i_p_DataBuff        : Pointer to the buffer where the data to be written is stored
        i_u4_TimeOutCount   : Count for Timeout when the value is set to FENTRYR
                              If you want to wait forever, set the "R_FAD_NO_TIMEOUT"
    - Return
        R_FAD_OK            : Normal completion
        R_FAD_ERR_CMDLK     : Command locked state
        R_FAD_ERR_BUSY      : Execution of this flash access API function is in progress
        R_FAD_ERR_PRGSPD    : Programming is suspended
        R_FAD_ERR_TIMEOUT   : Timeout before setting the value to FENTRYR
        R_FAD_ERR_INTERNAL  : An internal error has occurred
**********************************************************************************************************************/
#ifdef  __GHS__
#pragma ghs section text = "R_FAD_CODE_ROMRAM"
#endif

T_u4_FadErr
R_FAD_CF_Write(
    T_u4_FadAddr    i_u4_FadAddr,
    T_p_DataBuff    i_p_DataBuff,
    T_u4            i_u4_TimeOutCount
    )
{
    /* Defines local variables */
    T_u4_FadErr l_bu4_fadErr;
    
    /* Initializes for Return value */
    l_bu4_fadErr = R_FAD_OK;
    
    /* Writes to code flash */
    l_bu4_fadErr = fad_fu4_Write(R_FAD_CF_MODE, i_u4_FadAddr, i_p_DataBuff, i_u4_TimeOutCount);
    
    return l_bu4_fadErr;
}

/**********************************************************************************************************************
    Function Name   : R_FAD_CF_Erase

    - Outline
        Erases the contents of code flash memory for one block
    - Format
        T_u4_FadErr
            R_FAD_CF_Erase(
                T_u4_FadAddr    i_u4_FadAddr,
                T_u4            i_u4_TimeOutCount
            );
    - Input parameter
        i_u4_FadAddr        : Address of the code flash memory block to be erased
        i_u4_TimeOutCount   : Count for Timeout when the value is set to FENTRYR
                              If you want to wait forever, set the "R_FAD_NO_TIMEOUT"
    - Return
        R_FAD_OK            : Normal completion
        R_FAD_ERR_CMDLK     : Command locked state
        R_FAD_ERR_BUSY      : Execution of this flash access API function is in progress
        R_FAD_ERR_PRGSPD    : Programming is suspended
        R_FAD_ERR_ERSSPD    : Erasing is suspended
        R_FAD_ERR_TIMEOUT   : Timeout before setting the value to FENTRYR
        R_FAD_ERR_INTERNAL  : An internal error has occurred
**********************************************************************************************************************/

T_u4_FadErr
R_FAD_CF_Erase(
    T_u4_FadAddr    i_u4_FadAddr,
    T_u4            i_u4_TimeOutCount
    )
{
    /* Defines local variables */
    T_u4_FadErr l_bu4_fadErr;
    
    /* Initializes for Return value */
    l_bu4_fadErr = R_FAD_OK;
    
    /* Erases a code flash block */
    l_bu4_fadErr = fad_fu4_Erase(R_FAD_CF_MODE, i_u4_FadAddr, i_u4_TimeOutCount);
    
    return l_bu4_fadErr;
}

/**********************************************************************************************************************
    Function Name   : R_FAD_CF_SetConfig [For Security]

    - Outline
        Sets the data to configuration
    - Format
        T_u4_FadErr
            R_FAD_CF_SetConfig(
                T_u4_FadAddr    i_u4_FadAddr,
                T_p_DataBuff    i_p_DataBuff,
                T_u4            i_u4_TimeOutCount
            );
    - Input parameter
        i_u4_FadAddr        : Address for setting configuration
        i_p_DataBuff        : Address for writing data
        i_u4_TimeOutCount   : Count for Timeout when the value is set to FENTRYR
                              If you want to wait forever, set the "R_FAD_NO_TIMEOUT"
    - Return
        R_FAD_OK            : Normal completion
        R_FAD_ERR_CMDLK     : Command locked state
        R_FAD_ERR_BUSY      : Execution of this flash access API function is in progress
        R_FAD_ERR_PRGSPD    : Programming is suspended
        R_FAD_ERR_ERSSPD    : Erasing is suspended
        R_FAD_ERR_TIMEOUT   : Timeout before setting the value to FENTRYR
        R_FAD_ERR_INTERNAL  : An internal error has occurred
**********************************************************************************************************************/

T_u4_FadErr
R_FAD_CF_SetConfig(
    T_u4_FadAddr    i_u4_FadAddr,
    T_p_DataBuff    i_p_DataBuff,
    T_u4            i_u4_TimeOutCount
    )
{
    /* Defines local variables */
    T_u4_FadErr l_bu4_fadErr;
    
    /* Initializes for Return value */
    l_bu4_fadErr = R_FAD_OK;
    
    /* Sets configuration */
    l_bu4_fadErr = fad_fu4_SetConfig(R_FAD_CMDID_CONFIG, i_u4_FadAddr, i_p_DataBuff, i_u4_TimeOutCount);
    
    return l_bu4_fadErr;
}

/**********************************************************************************************************************
    Function Name   : R_FAD_CF_SetLockBit [For Security]

    - Outline
         Sets lock bits for a block of code flash memory
    - Format
        T_u4_FadErr
            R_FAD_CF_SetLockBit(
                T_u4_FadAddr    i_u4_FadAddr,
                T_u4            i_u4_TimeOutCount
            );
    - Input parameter
        i_u4_FadAddr        : Address of the code flash memory block for which lock bits are set
        i_u4_TimeOutCount   : Count for Timeout when the value is set to FENTRYR
                              If you want to wait forever, set the "R_FAD_NO_TIMEOUT"
    - Return
        R_FAD_OK            : Normal completion
        R_FAD_ERR_CMDLK     : Command locked state
        R_FAD_ERR_BUSY      : Execution of this flash access API function is in progress
        R_FAD_ERR_PRGSPD    : Programming is suspended
        R_FAD_ERR_ERSSPD    : Erasing is suspended
        R_FAD_ERR_TIMEOUT   : Timeout before setting the value to FENTRYR
        R_FAD_ERR_INTERNAL  : An internal error has occurred
**********************************************************************************************************************/

T_u4_FadErr
R_FAD_CF_SetLockBit(
    T_u4_FadAddr    i_u4_FadAddr,
    T_u4            i_u4_TimeOutCount
    )
{
    /* Defines local variables */
    T_u4_FadErr l_bu4_fadErr;
    
    /* Initializes for Return value */
    l_bu4_fadErr = R_FAD_OK;
    
    /* Sets the lock bit */
    l_bu4_fadErr = fad_fu4_LockBit(R_FAD_CMDID_LOCK_SET, i_u4_FadAddr, i_u4_TimeOutCount);
    
    return l_bu4_fadErr;
}

/**********************************************************************************************************************
    Function Name   : R_FAD_CF_GetLockBit [For Security]

    - Outline
         Acquires lock bit information of a block of code flash memory
    - Format
        T_u4_FadErr
            R_FAD_CF_GetLockBit(
                T_u4_FadAddr i_u4_FadAddr,
                T_u4            i_u4_TimeOutCount
            );
    - Input parameter
        i_u4_FadAddr        : Address of the code flash memory block for which lock bit information is acquired
        i_u4_TimeOutCount   : Count for Timeout when the value is set to FENTRYR
                              If you want to wait forever, set the "R_FAD_NO_TIMEOUT"
    - Return
        R_FAD_OK            : Normal completion
        R_FAD_ERR_CMDLK     : Command locked state
        R_FAD_ERR_BUSY      : Execution of this flash access API function is in progress
        R_FAD_ERR_TIMEOUT   : Timeout before setting the value to FENTRYR
        R_FAD_ERR_INTERNAL  : An internal error has occurred
**********************************************************************************************************************/

T_u4_FadErr
R_FAD_CF_GetLockBit(
    T_u4_FadAddr    i_u4_FadAddr,
    T_u4            i_u4_TimeOutCount
    )
{
    /* Defines local variables */
    T_u4_FadErr l_bu4_fadErr;
    
    /* Initializes for Return value */
    l_bu4_fadErr = R_FAD_OK;
    
    /* Acquires the lock bit information */
    l_bu4_fadErr = fad_fu4_LockBit(R_FAD_CMDID_LOCK_GET, i_u4_FadAddr, i_u4_TimeOutCount);
    
    return l_bu4_fadErr;
}

/**********************************************************************************************************************
    Function Name   : R_FAD_CF_LockBitProtectControl [For Security]

    - Outline
        Controls the protection for lock bit
    - Format
        T_u4_FadErr
            R_FAD_CF_LockBitProtectControl(
                T_u4_FadAddr                i_u4_FadAddr,
                T_bl_LockBitProtectSwitch   i_bl_LockBitProtectSwitch
            );
    - Input parameter
        i_u4_FadAddr        : Address for controling the protection for lock bit
        i_bl_LbProtKind     : The kind of the protection (enable or disable)
    - Return
        R_FAD_OK            : Normal completion
        R_FAD_ERR_INTERNAL  : An internal error has occurred
**********************************************************************************************************************/

T_u4_FadErr
R_FAD_CF_LockBitProtectControl(
    T_u4_FadAddr                i_u4_FadAddr,
    T_bl_LockBitProtectSwitch   i_bl_LockBitProtectSwitch
    )
{
    /* Defines local variables */
    T_u4_FadErr l_bu4_fadErr;
    
    /* Initializes for Return value */
    l_bu4_fadErr = R_FAD_OK;
    
    /* Sets the protect bit */
    l_bu4_fadErr = fad_fu4_LockBitProtectControl(i_u4_FadAddr, i_bl_LockBitProtectSwitch);
    
    return l_bu4_fadErr;
}

/**********************************************************************************************************************
    Function Name   : R_FAD_CF_SetOTP [For Security]

    - Outline
        Sets the data to OTP
    - Format
        T_u4_FadErr
            R_FAD_CF_SetOTP(
                T_u4_FadAddr    i_u4_FadAddr,
                T_p_DataBuff    i_p_DataBuff,
                T_u4            i_u4_TimeOutCount
            );
    - Input parameter
        i_u4_FadAddr        : Address for setting OTP
        i_p_DataBuff        : Address for writing data
        i_u4_TimeOutCount   : Count for Timeout when the value is set to FENTRYR
                              If you want to wait forever, set the "R_FAD_NO_TIMEOUT"
    - Return
        R_FAD_OK            : Normal completion
        R_FAD_ERR_CMDLK     : Command locked state
        R_FAD_ERR_BUSY      : Execution of this flash access API function is in progress
        R_FAD_ERR_PRGSPD    : Programming is suspended
        R_FAD_ERR_ERSSPD    : Erasing is suspended
        R_FAD_ERR_TIMEOUT   : Timeout before setting the value to FENTRYR
        R_FAD_ERR_INTERNAL  : An internal error has occurred
**********************************************************************************************************************/

T_u4_FadErr
R_FAD_CF_SetOTP(
    T_u4_FadAddr    i_u4_FadAddr,
    T_p_DataBuff    i_p_DataBuff,
    T_u4            i_u4_TimeOutCount
    )
{
    /* Defines local variables */
    T_u4_FadErr l_bu4_fadErr;
    
    /* Initializes for Return value */
    l_bu4_fadErr = R_FAD_OK;
    
    /* Sets OTP data */
    l_bu4_fadErr = fad_fu4_SetConfig(R_FAD_CMDID_OTP, i_u4_FadAddr, i_p_DataBuff, i_u4_TimeOutCount);
    
    return l_bu4_fadErr;
}

/**********************************************************************************************************************
    Function Name   : R_FAD_CF_GetConfig [For Security]

    - Outline
        Acquires the data from configuration
    - Format
        T_u4_FadErr
            R_FAD_CF_GetConfig(
                T_u4_FadAddr    i_u4_FadAddr,
                T_p_DataBuff    o_p_DataBuff,
                T_u4            i_u4_TimeOutCount
            );
    - Input parameter
        i_u4_FadAddr        : Address for acquiring configuration
        i_p_DataBuff        : Address for storing data
        i_u4_TimeOutCount   : Count for Timeout when the value is set to FENTRYR
                              If you want to wait forever, set the "R_FAD_NO_TIMEOUT"
    - Return
        R_FAD_OK            : Normal completion
        R_FAD_ERR_CLOCK     : The CPU clock frequency is incorrect.
        R_FAD_ERR_NOTSPD    : The flash access API which is specified is not suspended
        R_FAD_ERR_CANNOTSPD : A processing that cannot be suspended is
        R_FAD_ERR_FLMD0     : The FLMD0 pin is not high
        R_FAD_ERR_IDAUTH    : The authentication ID did not match
        R_FAD_ERR_TIMEOUT   : Timeout before setting the value to CCTRL
        R_FAD_ERR_INTERNAL  : An internal error has occurred being executed
**********************************************************************************************************************/
#ifdef  __GHS__
#pragma ghs section text = "R_FAD_CODE_RAM"
#endif

T_u4_FadErr
R_FAD_CF_GetConfig(
    T_u4_FadAddr    i_u4_FadAddr,
    T_p_DataBuff    o_p_DataBuff,
    T_u4            i_u4_TimeOutCount
    )
{
    /* Defines local variables */
    T_u4_FadErr l_bu4_fadErr;
    
    /* Initializes for Return value */
    l_bu4_fadErr = R_FAD_OK;
    
    /* Acquires the data from configuration */
    l_bu4_fadErr = fad_fu4_GetConfig(R_FAD_CMDID_CONFIG, i_u4_FadAddr, o_p_DataBuff, i_u4_TimeOutCount);
    
    return l_bu4_fadErr;
}

/**********************************************************************************************************************
    Function Name   : R_FAD_CF_GetOTP [For Security]

    - Outline
        Acquires the data from OTP
    - Format
        T_u4_FadErr
            R_FAD_CF_GetOTP(
                T_u4_FadAddr    i_u4_FadAddr,
                T_p_DataBuff    o_p_DataBuff,
                T_u4            i_u4_TimeOutCount
            );
    - Input parameter
        i_u4_FadAddr        : Address for getting configuration
        i_p_DataBuff        : Address for storing data
        i_u4_TimeOutCount   : Count for Timeout when the value is set to FENTRYR
                              If you want to wait forever, set the "R_FAD_NO_TIMEOUT"
    - Return
        R_FAD_OK            : Normal completion
        R_FAD_ERR_TIMEOUT   : Timeout before setting the value to CCTRL
        R_FAD_ERR_INTERNAL  : An internal error has occurred
**********************************************************************************************************************/

T_u4_FadErr
R_FAD_CF_GetOTP(
    T_u4_FadAddr    i_u4_FadAddr,
    T_p_DataBuff    o_p_DataBuff,
    T_u4            i_u4_TimeOutCount
    )
{
    /* Defines local variables */
    T_u4_FadErr l_bu4_fadErr;
    
    /* Initializes for Return value */
    l_bu4_fadErr = R_FAD_OK;
    
    /* Acquires OTP data */
    l_bu4_fadErr = fad_fu4_GetConfig(R_FAD_CMDID_OTP, i_u4_FadAddr, o_p_DataBuff, i_u4_TimeOutCount);
    
    return l_bu4_fadErr;
}
