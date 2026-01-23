/**********************************************************************************************************************
    Program Name    : Flash Access Driver (FAD)

    File Name       : r_fad_common_api.c
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

extern T_u4 bu4_FCPSR;   /* Erase suspend mode */

T_u1    suspend_mode;       /* Suspend mode */

/**********************************************************************************************************************
    Function Name   : R_FAD_HW_Init

    - Outline
        Makes the initial settings of hardware
    - Format
        T_u4_FadErr
        R_FAD_HW_Init(
            T_st_HW_Init*   i_pst_HW_Init,
            T_u4            i_u4_TimeOutCount
        );
    - Input parameter
        i_pst_HW_Init       : Address for storing the initial setting parameter of hardware
        i_u4_TimeOutCount   : Count for Timeout when the value is set to FENTRYR
                              If you want to wait forever, set the "R_FAD_NO_TIMEOUT"
    - Return
        R_FAD_OK            : Normal completion
        R_FAD_ERR_FCUTRNS   : Transfer to FCU firmware failed
        R_FAD_ERR_CLOCK     : The CPU clock frequency is incorrect.
        R_FAD_ERR_TIMEOUT   : Timeout before setting the value to FENTRYR
**********************************************************************************************************************/
//#ifdef  __GHS__
//#pragma ghs section text = "R_FAD_CODE_ROM"
//#endif

T_u4_FadErr R_FAD_HW_Init(T_st_HW_Init* i_pst_HW_Init, T_u4 i_u4_TimeOutCount )
{
    /* Defines local variables */
    T_u4_FadErr l_bu4_fadErr;
    T_bl        l_bl1_errFlag;
    
    /* Initializes for Return value */
    l_bu4_fadErr = R_FAD_OK;
    
    /* Initializes error flag */
    l_bl1_errFlag = FALSE;
    
    /* Initial setting of registers */
    l_bu4_fadErr = fad_fu4_InitializeFlashSequencerSetupRegister();
    if (R_FAD_IS_ERROR(l_bu4_fadErr) == TRUE)
    {
        l_bl1_errFlag = TRUE;
    }
    
    if (l_bl1_errFlag != TRUE)
    {
        /* Sets the number of roop for time out */
        fad_fv0_SetLoopCnt();
        
        /* Sets of FCU clock */
        l_bu4_fadErr = fad_fu4_SetClock(i_pst_HW_Init->bu2_InClock,
                                        i_pst_HW_Init->bu2_CpuClock);
        if (R_FAD_IS_ERROR(l_bu4_fadErr) == TRUE)
        {
            l_bl1_errFlag = TRUE;
        }
        
        if (l_bl1_errFlag != TRUE)
        {
            /* Transfers to FCU firmware */
            l_bu4_fadErr = fad_fu4_TransferToFCU(i_u4_TimeOutCount);
            if (R_FAD_IS_ERROR(l_bu4_fadErr) == TRUE)
            {
                l_bl1_errFlag = TRUE;
            }
            
            if (l_bl1_errFlag != TRUE)
            {
                /* Stores setting value of FCPSR register */
                bu4_FCPSR = i_pst_HW_Init->bu1_EraseSuspendMode;
            }
        }
    }
    
    return l_bu4_fadErr;
}

/**********************************************************************************************************************
    Function Name   : R_FAD_StatusClear

    - Outline
        Clears the state of the specified flash access API function
    - Format
        T_u4_FadErr
        R_FAD_StatusClear(
            T_u2_FaciNumber i_u2_FaciNumber,
            T_u4            i_u4_TimeOutCount
        );
    - Input parameter
        i_u2_FaciNumber     : FACI number of the flash access API function whose state is cleared
        i_u4_TimeOutCount   : Count for Timeout when the value is set to FENTRYR
                              If you want to wait forever, set the "R_FAD_NO_TIMEOUT"
    - Return
        R_FAD_OK            : Normal completion
        R_FAD_ERR_BUSY      : Execution of this flash access API function is in progress
        R_FAD_ERR_TIMEOUT   : Timeout before setting the value to FENTRYR
        R_FAD_ERR_INTERNAL  : An internal error has occurred
**********************************************************************************************************************/

T_u4_FadErr R_FAD_StatusClear(T_u2_FaciNumber i_u2_FaciNumber,T_u4 i_u4_TimeOutCount)
{
    /* Defines local variables */
    T_u4_FadErr l_bu4_fadErr;
    T_bl        l_bl1_errFlag;
    T_u1        l_bu1_PEmode;
    T_u1        l_bu1_FASTAT;
    
    /* Initializes for Return value */
    l_bu4_fadErr = R_FAD_OK;
    
    /* Initializes error flag */
    l_bl1_errFlag = FALSE;
    
    /* Changes FACI */
    fad_fv0_SetFACI(i_u2_FaciNumber);
    
    /* Checks whether the command can be issued */
    l_bu4_fadErr = fad_fu4_IsValidToIssueCommand();
    if (R_FAD_IS_ERROR(l_bu4_fadErr) == TRUE)
    {
        l_bl1_errFlag = TRUE;
    }
    
    if (l_bl1_errFlag != TRUE)
    {
        /* Changes to P/E mode */
        l_bu1_PEmode = fad_fu4_GetPEModeOrReadMode();
        if (l_bu1_PEmode == R_FAD_RD_MODE)
        {
            l_bu4_fadErr = fad_fu4_SetPEModeOrReadMode(R_FAD_DF_MODE, i_u4_TimeOutCount);
            if (R_FAD_IS_ERROR(l_bu4_fadErr) == TRUE)
            {
                l_bl1_errFlag = TRUE;
            }
        }
        if (l_bl1_errFlag != TRUE)
        {
            /* Clears CFAE/DFAE bit */
            l_bu1_FASTAT = R_FAD_REG_FASTAT;
            if (l_bu1_FASTAT & (R_FAD_MASK_FASTAT_CFAE | R_FAD_MASK_FASTAT_DFAE))
            {
                R_FAD_REG_FASTAT &= ~(R_FAD_MASK_FASTAT_CFAE | R_FAD_MASK_FASTAT_DFAE);
            }
            
            /* Issues the command */
            l_bu4_fadErr = fad_fu4_IssueCommandTypeC(R_FAD_CMDID_STS_CLR);
        }
    }
    
    return l_bu4_fadErr;
}

/**********************************************************************************************************************
    Function Name   : R_FAD_ForcedStop

    - Outline
        Forcibly terminates the flash access API function being executed
    - Format
        T_u4_FadErr
        R_FAD_ForcedStop(
            T_u2_FaciNumber i_u2_FaciNumber,
            T_u4            i_u4_TimeOutCount
        );
    - Input parameter
        i_u2_FaciNumber     : FACI number of the flash access API function whose processing is forcibly terminated
        i_u4_TimeOutCount   : Count for Timeout when the value is set to FENTRYR
                              If you want to wait forever, set the "R_FAD_NO_TIMEOUT"
    - Return
        R_FAD_OK            : Normal completion
        R_FAD_ERR_TIMEOUT   : Timeout before setting the value to FENTRYR
        R_FAD_ERR_INTERNAL  : An internal error has occurred
**********************************************************************************************************************/

T_u4_FadErr R_FAD_ForcedStop(T_u2_FaciNumber i_u2_FaciNumber, T_u4 i_u4_TimeOutCount)
{
    /* Defines local variables */
    T_u4_FadErr l_bu4_fadErr;
    T_bl        l_bl1_errFlag;
    T_u1        l_bu1_PEmode;
    
    /* Initializes for Return value */
    l_bu4_fadErr = R_FAD_OK;
    
    /* Initializes error flag */
    l_bl1_errFlag = FALSE;
    
    /* Changes FACI */
    fad_fv0_SetFACI(i_u2_FaciNumber);
    
    /* Changes to P/E mode */
    l_bu1_PEmode = fad_fu4_GetPEModeOrReadMode();
    if (l_bu1_PEmode == R_FAD_RD_MODE)
    {
        l_bu4_fadErr = fad_fu4_SetPEModeOrReadMode(R_FAD_DF_MODE, i_u4_TimeOutCount);
        if (R_FAD_IS_ERROR(l_bu4_fadErr) == TRUE)
        {
            l_bl1_errFlag = TRUE;
        }
    }
    
    if (l_bl1_errFlag != TRUE)
    {
        /* Issues the command */
        l_bu4_fadErr = fad_fu4_IssueCommandTypeC(R_FAD_CMDID_STOP);
        if (R_FAD_IS_ERROR(l_bu4_fadErr) == TRUE)
        {
            l_bl1_errFlag = TRUE;
        }
        
        if (l_bl1_errFlag != TRUE)
        {
            /* Waiting for FRDY==1 */
            l_bu4_fadErr = fad_fu4_WaitForFRDYIsValid();
        }
    }
    
    return l_bu4_fadErr;
}

/**********************************************************************************************************************
    Function Name   : R_FAD_GetStatus

    - Outline
        Acquires the state of the specified flash access API function
    - Format
        T_u4_FadErr
        R_FAD_GetStatus(
            T_u2_FaciNumber     i_u2_FaciNumber
            T_u4_FadStsExInfo*  o_pu4_FadStsExInfo
        );
    - Input parameter
        i_u2_FaciNumber     : FACI number of the flash access API function whose processing is forcibly terminated
        o_pu4_FadStsExInfo  : Address of the area for storing the extended state information of the flash access API
                              function
    - Return
        R_FAD_STS_IDLE      : Normal completion
        R_FAD_ERR_BUSY      : Execution of this flash access API function is in progress
        R_FAD_ERR_CMDLK     : Command locked state
        R_FAD_STS_SUSRDY    : State in which processing can be suspended
        R_FAD_ERR_PRGSPD    : Programming is suspended
        R_FAD_ERR_ERSSPD    : Erasing is suspended
        R_FAD_STS_LKREAD0   : State in which acquisition of lock bit information has completed (protected state)
        R_FAD_STS_LKREAD1   : State in which acquisition of lock bit information has completed (unprotected state)
        R_FAD_STS_BLKCHK0   : State in which searching for an empty area in data flash memory has completed.
                              The result of searching for an empty area is "All areas are empty"
        R_FAD_STS_BLKCHK1   : State in which searching for an empty area in data flash memory has completed.
                              The result of searching for an empty area is "There is a programmed area"
**********************************************************************************************************************/

T_u4_FadStatus R_FAD_GetStatus(T_u2_FaciNumber  i_u2_FaciNumber,T_u4_FadStsExInfo*  o_pu4_FadStsExInfo)
{
    /* Defines local variables */
    T_bl    l_bl1_errFlag;
    T_bl    l_bl1_stsExInfoNullFlag;
    T_u4    l_bu4_status;
    T_u2    l_bu2_FCMDR;
    T_u4    l_bu4_FENTRYR;
    T_u4    l_bu4_FLKSTAT;
    T_u4    l_bu4_FBCSTAT;
    
   /* Status value for initialization */
    l_bu4_status = R_FAD_STS_IDLE;
    
    /* Initializes error flag */
    l_bl1_errFlag = FALSE;
    l_bl1_stsExInfoNullFlag = TRUE;

    /* Changes FACI */
    fad_fv0_SetFACI(i_u2_FaciNumber);
    
    /* Initial setting for extended state information */
    if (o_pu4_FadStsExInfo != NULL)
    {
        *o_pu4_FadStsExInfo = 0;
        l_bl1_stsExInfoNullFlag = FALSE; /* Not NULL */
    }
    
    /* Checks FRDY */
    if (fad_fbl_IsFRDY() == FALSE)
    {
        if (fad_fbl_IsSUSRDY() == TRUE)
        {
            l_bu4_status = R_FAD_STS_SUSRDY;
        }
        else
        {
            l_bu4_status = R_FAD_STS_BUSY;
            /* Not NULL */
            if (l_bl1_stsExInfoNullFlag == FALSE)
            {
                *o_pu4_FadStsExInfo = fad_fu1_GetAcceptedFACICommand();
            }
        }
    }
    /* fad_fbl_IsFRDY() == TRUE */
    else
    {
        /* ISCMDLK */
        /* Checks command lock */
        if (fad_fbl_IsCMDLK() == TRUE)
        {
            /* Not NULL */
            if (l_bl1_stsExInfoNullFlag == FALSE)
            {
                *o_pu4_FadStsExInfo = fad_fu4_GetDetailErrorInformation();
            }
            l_bu4_status = R_FAD_STS_CMDLK;
            l_bl1_errFlag = TRUE;
        }
        
        if (l_bl1_errFlag != TRUE)
        {
            if (fad_fbl_IsERSSPD() == TRUE)
            {
                l_bu4_status = R_FAD_STS_ERSSPD;
            }
            else if (fad_fbl_IsPRGSPD() == TRUE)
            {
                l_bu4_status = R_FAD_STS_PRGSPD;
            }
            else
            {
                l_bu2_FCMDR = R_FAD_REG_FCMDR;
                if (l_bu2_FCMDR == ((R_FAD_CMDID_RUN << 8) | R_FAD_CMDID_LOCK_GET))
                {
                    l_bu4_FENTRYR = R_FAD_REG_FENTRYR;

                    /* Code flash mode */
                    if (l_bu4_FENTRYR == R_FAD_CF_MODE)
                    {
                        l_bu4_FLKSTAT = R_FAD_REG_FLKSTAT;
                        if (l_bu4_FLKSTAT == 0)
                        {
                            l_bu4_status = R_FAD_STS_LKREAD0;
                        }
                        else
                        {
                            l_bu4_status = R_FAD_STS_LKREAD1;
                        }
                    }
                    /* Data flash mode */
                    else if (l_bu4_FENTRYR == R_FAD_DF_MODE)
                    {
                        l_bu4_FBCSTAT = R_FAD_REG_FBCSTAT;
                        if (l_bu4_FBCSTAT == 0)
                        {
                            l_bu4_status = R_FAD_STS_BLKCHK0;
                        }
                        else
                        {
                            l_bu4_status = R_FAD_STS_BLKCHK1;
                            if (l_bl1_stsExInfoNullFlag == FALSE)
                            {
                                *o_pu4_FadStsExInfo = R_FAD_REG_FPSADDR + R_FAD_DF0_BASE;
                            }
                        }
                    }
                    else
                    {
                        ;
                    }
                }
            }
        }
    }
    
    return l_bu4_status;
}

/**********************************************************************************************************************
    Function Name   : R_FAD_ShiftToReadMode

    - Outline
       Shifts the mode for accessing a flash access API function to read mode
    - Format
        T_u4_FadErr
        R_FAD_ShiftToReadMode(
            T_u2_FaciNumber i_u2_FaciNumber,
            T_u4            i_u4_TimeOutCount
        );
    - Input parameter
        i_u2_FaciNumber     : FACI number of the flash access API function shifted to read mode
        i_u4_TimeOutCount   : Count for Timeout when the value is set to FENTRYR
                              If you want to wait forever, set the "R_FAD_NO_TIMEOUT"
    - Return
        R_FAD_OK            : Normal completion
        R_FAD_ERR_TIMEOUT   : Timeout before setting the value to FENTRYR
        R_FAD_ERR_INTERNAL  : An internal error has occurred
**********************************************************************************************************************/

T_u4_FadErr R_FAD_ShiftToReadMode( T_u2_FaciNumber i_u2_FaciNumber,T_u4 i_u4_TimeOutCount )
{
    /* Defines local variables */
    T_u4_FadErr l_bu4_fadErr;
    
    /* Initializes for Return value */
    l_bu4_fadErr = R_FAD_OK;
    
    /* Changes FACI */
    fad_fv0_SetFACI(i_u2_FaciNumber);
    
    /* Shifts to read mode */
    l_bu4_fadErr = fad_fu4_SetPEModeOrReadMode(R_FAD_RD_MODE, i_u4_TimeOutCount);
    
    return l_bu4_fadErr;
}

/**********************************************************************************************************************
    Function Name   : R_FAD_IDAuth

    - Outline
        Authentication of ID
    - Format
        T_u4_FadErr
        R_FAD_IDAuth(
            T_u4*   i_p_AuthIDAddr,
            T_u1*   i_p_CheckData,
            T_u4    i_u4_IDLength,
            T_u4    i_u4_StatusBitValue
        );
    - Input parameter
        i_p_AuthIDAddr      : Address of the authentication ID
                              Specifies as following:
                                Self-programing authentication          : R_FAD_REG_SELFID
                                Password authentication for Code Flash  : R_FAD_REG_CFPEID
                                Password authentication for Data Flash  : R_FAD_REG_DFPEID
        i_p_CheckData       : Address of the Checking data (Checking ID)
        i_u4_IDLength       : Length of ID (bit)
                              Specifies as following:
                                Self-programing authentication          : R_FAD_IDLENGTH_SELFID
                                Password authentication for Code Flash  : R_FAD_IDLENGTH_CFPEID
                                Password authentication for Data Flash  : R_FAD_IDLENGTH_DFPEID
        i_u4_StatusBitValue : Value of IDST(ID Status) for IDSTATUS register
                              It must match the ID to be checked.Sets the corresponding bit to 1.
                              Specifies as following:
                                Self-programing authentication          : R_FAD_IDSTATUS_SELFIDST
                                Password authentication for Code Flash  : R_FAD_IDSTATUS_CFPEIDST
                                Password authentication for Data Flash  : R_FAD_IDSTATUS_DFPEIDST
    - Return
        R_FAD_OK            : Normal completion
        R_FAD_ERR_IDAUTH    : The authentication ID did not match
**********************************************************************************************************************/
//#ifdef  __GHS__
//#pragma ghs section text = "R_FAD_CODE_ROMRAM"
//#endif

T_u4_FadErr R_FAD_IDAuth(
    T_u4*   i_p_AuthIDAddr,
    T_u1*   i_p_CheckData,
    T_u4    i_u4_IDLength,
    T_u4    i_u4_StatusBitValue
    )
{
    /* Defines local variables */
    T_u4_FadErr l_bu4_fadErr;
    T_u4*       l_p_checkData;
    T_u4        l_bu4_IDstatus;
    T_u4        l_bu4_roop;
    T_u4        l_bu4_work[16];     /* Max 512 bit  */
    
    /* Initializes for Return value */
    l_bu4_fadErr = R_FAD_OK;
    
    if (((T_u4)i_p_CheckData & 0x3) == 0)
    {
        l_p_checkData = (T_u4 *)i_p_CheckData;
    }
    else
    {
        fad_fv0_Memcpy1((T_u1 *)l_bu4_work, (T_u1 *)i_p_CheckData, 32);
        l_p_checkData = l_bu4_work;
    }
    
    /* Stores the ID */
    for (l_bu4_roop = 0; l_bu4_roop < i_u4_IDLength/32; l_bu4_roop++)
    {
        *i_p_AuthIDAddr = *l_p_checkData;
        i_p_AuthIDAddr++;
        l_p_checkData++;
    }
    l_bu4_IDstatus = R_FAD_REG_IDSTATUS;    /* ID Status */
    
    /* Checks the Authentication */
    if (l_bu4_IDstatus & i_u4_StatusBitValue)
    {
        l_bu4_fadErr = R_FAD_ERR_IDAUTH;
    }
    else
    {
        l_bu4_fadErr = R_FAD_OK;
    }
    
    return l_bu4_fadErr;
}

/**********************************************************************************************************************
    Function Name   : R_FAD_Suspend

    - Outline
        Suspends the flash access API function whose processing is in progress
    - Format
        T_u4_FadErr
        R_FAD_Suspend(
            T_u2_FaciNumber     i_u2_FaciNumber
        );
    - Input parameter
        i_u2_FaciNumber         : FACI number of the flash access API function whose processing is suspended
    - Return
        R_FAD_OK            : Normal completion
        R_FAD_NOTSUS        : Suspending was not performed
        R_FAD_ERR_CMDLK     : Command locked state
        R_FAD_ERR_CANNOTSPD : A processing that cannot be suspended is being executed
        R_FAD_ERR_INTERNAL  : An internal error has occurred
**********************************************************************************************************************/

T_u4_FadErr R_FAD_Suspend(T_u2_FaciNumber i_u2_FaciNumber)
{
    /* Defines local variables */
    T_u4_FadErr l_bu4_fadErr;
    T_bl        l_bl1_errFlag;
    
    /* Initializes for Return value */
    l_bu4_fadErr = R_FAD_OK;
    
    /* Initializes error flag */
    l_bl1_errFlag = FALSE;
    
    /* Changes FACI */
    fad_fv0_SetFACI(i_u2_FaciNumber);
    
    /* Checks whether the command can be issued */
    l_bu4_fadErr = fad_fu4_CheckFlashStatusSuspendable();
    if (R_FAD_IS_ERROR(l_bu4_fadErr) == TRUE)
    {
        l_bl1_errFlag = TRUE;
    }
    
    /* Checks command completion before the suspend execution */
    if (l_bl1_errFlag != TRUE)
    {
        if (fad_fbl_IsFRDY() == TRUE)
        {
            /* FRDY is available */
            l_bl1_errFlag = TRUE;
            l_bu4_fadErr = R_FAD_NOTSUS;    /* Cannot suspend   */
        }
    }
    
    if (l_bl1_errFlag != TRUE)
    {
        /* Saves P/E mode */
        suspend_mode = fad_fu4_GetPEModeOrReadMode();
        
        /* Issues command */
        l_bu4_fadErr = fad_fu4_IssueCommandTypeC(R_FAD_CMDID_SUSPEND);
        if (R_FAD_IS_ERROR(l_bu4_fadErr) == TRUE)
        {
            l_bl1_errFlag = TRUE;
        }
    }
    
    if (l_bl1_errFlag != TRUE)
    {
        /* Checks FRDY */
        l_bu4_fadErr = fad_fu4_WaitForFRDYIsValid();
        if (R_FAD_IS_ERROR(l_bu4_fadErr) == TRUE)
        {
            l_bl1_errFlag = TRUE;
        }
    }
    
    /* Checks command locked state */
    if (l_bl1_errFlag != TRUE)
    {
        if (fad_fbl_IsCMDLK() == TRUE)
        {
            l_bl1_errFlag = TRUE;
            l_bu4_fadErr = R_FAD_ERR_CMDLK;
        }
    }
    
    /* Checks suspend completion */
    if (l_bl1_errFlag != TRUE)
    {
        /* When both ERSSPD and PRGSPD is 0, executes if statement */
        /* When ERSSPD or PRGSPD is 1, not executes if statement and go to return */
        if (!(fad_fbl_IsERSSPD()||fad_fbl_IsPRGSPD()))
        {
            /* When both ERSSPD and PRGSPD is 0 */
            if (fad_fbl_IsFRDY() == TRUE)
            {
                /* When the processing to be suspended finishes                 */
                /* after checking FRDY and before issuing the suspend command   */
                l_bu4_fadErr = R_FAD_NOTSUS;
            }
            else
            {
                l_bl1_errFlag = TRUE;
                l_bu4_fadErr = R_FAD_ERR_INTERNAL;
            }
        }
    }
    
    return l_bu4_fadErr;
}

/**********************************************************************************************************************
    Function Name   : R_FAD_Resume

    - Outline
        Resumes processing of the flash access API function that was suspended
    - Format
        T_u4_FadErr
        R_FAD_Suspend(
            T_u2_FaciNumber i_u2_FaciNumber,
            T_u4            i_u4_TimeOutCount
        );
    - Input parameter
        i_u2_FaciNumber     : FACI number of the flash access API function whose processing is suspended
        i_u4_TimeOutCount   : Count for Timeout when the value is set to FENTRYR
                              If you want to wait forever, set the "R_FAD_NO_TIMEOUT"
    - Return
        R_FAD_OK            : Normal completion
        R_FAD_ERR_CMDLK     : Command locked state
        R_FAD_ERR_BUSY      : Execution of this flash access API function is in progress
        R_FAD_ERR_NOTSPD    : The flash access API which is specified is not suspended
        R_FAD_ERR_TIMEOUT   : Timeout before setting the value to FENTRYR
        R_FAD_ERR_INTERNAL  : An internal error has occurred
**********************************************************************************************************************/

T_u4_FadErr R_FAD_Resume( T_u2_FaciNumber i_u2_FaciNumber,T_u4 i_u4_TimeOutCount)
{
    /* Defines local variables */
    T_u4_FadErr l_bu4_fadErr;
    T_bl        l_bl1_errFlag;
    
    /* Initializes for Return value */
    l_bu4_fadErr = R_FAD_OK;
    
    /* Changes FACI */
    fad_fv0_SetFACI(i_u2_FaciNumber);
    
    /* Checks whether the command can be issued */
    l_bu4_fadErr = fad_fu4_CheckFlashStatus();
    if (R_FAD_IS_ERROR(l_bu4_fadErr) == TRUE)
    {
        if ((l_bu4_fadErr != R_FAD_ERR_ERSSPD)&&(l_bu4_fadErr != R_FAD_ERR_PRGSPD))
        {
            l_bl1_errFlag = TRUE;
        }
    }
    else
    {
        l_bl1_errFlag = TRUE;
        l_bu4_fadErr = R_FAD_ERR_NOTSPD;
    }
    
    /* Changes P/E mode */
    if (l_bl1_errFlag != TRUE)
    {
        l_bu4_fadErr = fad_fu4_SetPEModeOrReadMode(suspend_mode, i_u4_TimeOutCount);
        if (R_FAD_IS_ERROR(l_bu4_fadErr) == TRUE)
        {
        l_bl1_errFlag = TRUE;
        }
    }
    
    if (l_bl1_errFlag != TRUE)
    {
        /* Issues command */
        l_bu4_fadErr = fad_fu4_IssueCommandTypeC(R_FAD_CMDID_RESUME);
        if (R_FAD_IS_ERROR(l_bu4_fadErr) == TRUE)
        {
            l_bl1_errFlag = TRUE;
        }
    }
    
    return l_bu4_fadErr;
}

