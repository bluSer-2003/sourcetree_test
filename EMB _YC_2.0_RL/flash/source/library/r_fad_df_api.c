/**********************************************************************************************************************
    Program Name    : Flash Access Driver (FAD)

    File Name       : r_fad_df_api.c
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
   Version Number
**********************************************************************************************************************/
//#ifdef  __GHS__
//#pragma ghs section rodata = "R_FAD_CONST"
//#endif

const T_u1 pu1_versionDFStr[] = R_FAD_DF_VERSION;

/**********************************************************************************************************************
    Function Name   : R_FAD_DF_GetApiVersion

    - Outline
        Acquires version information of the data flash functions
    - Format
        T_p_FadApiVersion
            R_FAD_DF_GetApiVersion(void);
    - Input parameter
        non
    - Return
        versionDFStr    : Pointer to the string in which version information of the data flash functions are stored
**********************************************************************************************************************/
//#ifdef  __GHS__
//#pragma ghs section text = "R_FAD_CODE_ROM"
//#endif

T_p_FadApiVersion
R_FAD_DF_GetApiVersion(void)
{
    return pu1_versionDFStr;
}

/**********************************************************************************************************************
    Function Name   : R_FAD_DF_Write

    - Outline
        Writes data to code flash memory
    - Format
        T_u4_FadErr
            R_FAD_DF_Write(
                T_u4_FadAddr    i_u4_FadAddr
                T_p_DataBuff    i_p_DataBuff,
                T_u4            i_u4_TimeOutCount
            );
    - Input parameter
        i_u4_FadAddr        : Address of data flash memory from which programming starts
        i_p_DataBuff        : Pointer to the buffer where the data to be written is stored
        i_u4_TimeOutCount   : Count for Timeout when the value is set to FENTRYR
                              If you want to wait forever, set the "R_FAD_NO_TIMEOUT"
    - Return
        R_FAD_OK            : Normal completion
        R_FAD_ERR_TIMEOUT   : Timeout before setting the value to FENTRYR
**********************************************************************************************************************/

T_u4_FadErr
R_FAD_DF_Write(
    T_u4_FadAddr    i_u4_FadAddr,
    T_p_DataBuff    i_p_DataBuff,
    T_u4            i_u4_TimeOutCount
    )
{
    /* Defines local variables */
    T_u4_FadErr l_bu4_fadErr;
    
    /* Initializes for Return value */
    l_bu4_fadErr = R_FAD_OK;
    
    /* Writes to data flash */
    l_bu4_fadErr = fad_fu4_Write(R_FAD_DF_MODE, i_u4_FadAddr, i_p_DataBuff, i_u4_TimeOutCount);
    
    return l_bu4_fadErr;
}

/**********************************************************************************************************************
    Function Name   : R_FAD_DF_Erase

    - Outline
        Erases the contents of data flash memory for one block
    - Format
        T_u4_FadErr
            R_FAD_DF_Erase(
                T_u4_FadAddr    i_u4_FadAddr,
                T_u4            i_u4_TimeOutCount
            );
    - Input parameter
        i_u4_FadAddr        : Address of the data flash memory block to be erased
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
R_FAD_DF_Erase(
    T_u4_FadAddr    i_u4_FadAddr,
    T_u4            i_u4_TimeOutCount
    )
{
    /* Defines local variables */
    T_u4_FadErr l_bu4_fadErr;
    
    /* Initializes for Return value */
    l_bu4_fadErr = R_FAD_OK;
    
    /* Erases a data flash block */
    l_bu4_fadErr = fad_fu4_Erase(R_FAD_DF_MODE, i_u4_FadAddr, i_u4_TimeOutCount);
    
    return l_bu4_fadErr;
}

/**********************************************************************************************************************
    Function Name   : R_FAD_DF_BlankCheck

    - Outline
        Checks data flash memory for an empty area
    - Format
        T_u4_FadErr
            R_FAD_DF_BlankCheck(
                T_u4_FadAddr    i_u4_FadStartAddr,
                T_u4_FadAddr    i_u4_FadEndAddr,
                T_u1_CheckDir   i_u1_CheckDir,
                T_u4            i_u4_TimeOutCount
            );
    - Input parameter
        i_u4_FadStartAddr   : Start address of data flash memory to be searched for an empty area
        i_u4_FadEndAddr     : End address of data flash memory to be searched for an empty area
        i_u1_CheckDir       : Flag determining whether to start searching from the start address or end address
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
R_FAD_DF_BlankCheck(
    T_u4_FadAddr    i_u4_FadStartAddr,
    T_u4_FadAddr    i_u4_FadEndAddr,
    T_u1_CheckDir   i_u1_CheckDir,
    T_u4            i_u4_TimeOutCount
    )
{
    /* Defines local variables */
    T_u4_FadErr     l_bu4_fadErr;
    T_bl            l_bl1_errFlag;
    T_u2_FaciNumber l_bu2_faciNumber;
    
    /* Initializes for Return value */
    l_bu4_fadErr = R_FAD_OK;
    
    /* Initializes error flag */
    l_bl1_errFlag = FALSE;
    
    /* Acuires the current FACI Number and changes FACI area if necessary */
    l_bu2_faciNumber = fad_fu2_GetFACINumberFromAddress(i_u4_FadStartAddr);
    fad_fv0_SetFACI(l_bu2_faciNumber);
    
    /* Checks whether the command can be issued */
    l_bu4_fadErr = fad_fu4_CheckFlashStatus();
    if (R_FAD_IS_ERROR(l_bu4_fadErr))
    {
        /* When the status is not Erase Suspend or not Program Suspend  */
        if (!((l_bu4_fadErr == R_FAD_ERR_ERSSPD) || (l_bu4_fadErr == R_FAD_ERR_PRGSPD)))
        {
            l_bl1_errFlag = TRUE;
            l_bu4_fadErr = R_FAD_SET_FACI_NUMBER(l_bu4_fadErr, l_bu2_faciNumber);
        }
    }
    
    if (l_bl1_errFlag != TRUE)
    {
        /* Changes P/E mode of Data flash */
        l_bu4_fadErr = fad_fu4_SetPEModeOrReadMode(R_FAD_DF_MODE, i_u4_TimeOutCount);
        
        if (R_FAD_IS_ERROR(l_bu4_fadErr))
        {
            l_bl1_errFlag = TRUE;
            l_bu4_fadErr = R_FAD_SET_FACI_NUMBER(l_bu4_fadErr, l_bu2_faciNumber);
        }
    }
    
    if (l_bl1_errFlag != TRUE)
    {
        /* Issues command */
        R_FAD_REG_FBCCNT = i_u1_CheckDir;           /* FBCCNT register */
        R_FAD_REG_FEADDR = i_u4_FadEndAddr;         /* FEADDR register */
        l_bu4_fadErr = fad_fu4_IssueCommandTypeB(R_FAD_CMDID_BLK_CHK, i_u4_FadStartAddr);
        l_bu4_fadErr = R_FAD_SET_FACI_NUMBER(l_bu4_fadErr, l_bu2_faciNumber);
    }
    
    return l_bu4_fadErr;
}

