/**********************************************************************************************************************
    Program Name    : Flash Access Driver (FAD)

    File Name       : r_fad_local.c
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
    Function Name   : fad_fu4_Write

    - Outline
        The body of writing function
    - Format
        T_u4_FadErr
            fad_fu4_Write(
                T_u1            i_u1_PEmode,
                T_u4_FadAddr    i_u4_FadAddr,
                T_p_DataBuff    i_p_DataBuff,
                T_u4            i_u4_TimeOutCount
            );
    - Input parameter
        i_u1_PEmode         : Address for storing the initial setting parameter of hardware
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
fad_fu4_Write(
    T_u1            i_u1_PEmode,
    T_u4_FadAddr    i_u4_FadAddr,
    T_p_DataBuff    i_p_DataBuff,
    T_u4            i_u4_TimeOutCount
    )
{
    /* Defines local variables */
    T_u4_FadErr     l_bu4_fadErr;
    T_bl            l_bl1_errFlag;
    T_u1            l_bu1_unitSize;     /* Size of Writing unit */
    T_u2_FaciNumber l_bu2_faciNumber;   /* Target FACI Number */
    
    /* Initializes for Return value */
    l_bu4_fadErr = R_FAD_OK;
    
    /* Initializes error flag */
    l_bl1_errFlag = FALSE;
    
    /* Acuires the current FACI Number and changes FACI area if necessary */
    l_bu2_faciNumber = fad_fu2_GetFACINumberFromAddress(i_u4_FadAddr);
    fad_fv0_SetFACI(l_bu2_faciNumber);
    
    /* Checks whether the flash status is OK    */
    l_bu4_fadErr = fad_fu4_CheckFlashStatus();
    
    /* Checks whether the flash status is not OK (not FRDY) */
    if (R_FAD_IS_ERROR(l_bu4_fadErr))
    {
        /* When the status is not Erase suspend */
        if (l_bu4_fadErr != R_FAD_ERR_ERSSPD)
        {
            /* Error Occured    */
            l_bl1_errFlag = TRUE;
            /* Add a FACI Number to Error code  */
            l_bu4_fadErr = R_FAD_SET_FACI_NUMBER(l_bu4_fadErr, l_bu2_faciNumber);
        }
    }
    
    /* The flash status is OK   */
    if (l_bl1_errFlag != TRUE)
    {
        /* Changes to P/E mode */
        l_bu4_fadErr = fad_fu4_SetPEModeOrReadMode(i_u1_PEmode, i_u4_TimeOutCount);
        
        if (R_FAD_IS_ERROR(l_bu4_fadErr))
        {
            /* Error Occured    */
            l_bl1_errFlag = TRUE;
            /* Add a FACI Number to Error code  */
            l_bu4_fadErr = R_FAD_SET_FACI_NUMBER(l_bu4_fadErr, l_bu2_faciNumber);
        }
    }
    
    /* Writing  */
    if (l_bl1_errFlag != TRUE)
    {
        /* Size of Writing unit or Erasing unit */
        l_bu1_unitSize  = (i_u1_PEmode == R_FAD_CF_MODE) ? R_FAD_CF_WR_UNIT : R_FAD_DF_WR_UNIT;
        /* Issues the writing command */
        l_bu4_fadErr    = fad_fu4_IssueCommandTypeA(R_FAD_CMDID_WRITE, i_u4_FadAddr, i_p_DataBuff,
                                                                            l_bu1_unitSize, i_u4_TimeOutCount);
        /* Add a FACI Number to Error code  */
        l_bu4_fadErr    = R_FAD_SET_FACI_NUMBER(l_bu4_fadErr, l_bu2_faciNumber);
    }
    
    return l_bu4_fadErr;
}

/**********************************************************************************************************************
    Function Name   : fad_fu4_Erase

    - Outline
        The body of erasing function
    - Format
        T_u4_FadErr
            fad_fu4_Erase(
                T_u1            i_u1_PEmode,
                T_u4_FadAddr    i_u4_FadAddr,
                T_u4            i_u4_TimeOutCount
            );
    - Input parameter
        i_u1_PEmode         : Address for storing the initial setting parameter of hardware
        i_u4_FadAddr        : Address of the code flash memory block to be erased
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

extern T_u4 bu4_FCPSR;        /* Erase suspend mode */

T_u4_FadErr
fad_fu4_Erase(
    T_u1            i_u1_PEmode,
    T_u4_FadAddr    i_u4_FadAddr,
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
    
    /* Changes FACI */
    l_bu2_faciNumber = fad_fu2_GetFACINumberFromAddress(i_u4_FadAddr);
    fad_fv0_SetFACI(l_bu2_faciNumber);
    
    /* Checks whether the command can be issued */
    l_bu4_fadErr = fad_fu4_CheckFlashStatus();
    
    /* Checks whether the flash status is not OK (not FRDY) */
    if (R_FAD_IS_ERROR(l_bu4_fadErr))
    {
        /* Error Occured    */
        l_bl1_errFlag = TRUE;
        /* Add a FACI Number to Error code  */
        l_bu4_fadErr = R_FAD_SET_FACI_NUMBER(l_bu4_fadErr, l_bu2_faciNumber);
    }
    
    /* The flash status is OK   */
    if (l_bl1_errFlag != TRUE)
    {
        /* Changes to P/E mode */
        l_bu4_fadErr = fad_fu4_SetPEModeOrReadMode(i_u1_PEmode, i_u4_TimeOutCount);
        if (R_FAD_IS_ERROR(l_bu4_fadErr))
        {
            /* Error Occured    */
            l_bl1_errFlag = TRUE;
            /* Add a FACI Number to Error code  */
            l_bu4_fadErr = R_FAD_SET_FACI_NUMBER(l_bu4_fadErr, l_bu2_faciNumber);
        }
    }
    
    /* Erasing  */
    if (l_bl1_errFlag != TRUE)
    {
        /* Setting the FCPSR register */
        /* Sets the Suspended-priority mode or Erasure-priority mode    */
        R_FAD_REG_FCPSR = bu4_FCPSR;
        /* Issues the erasing command */
        l_bu4_fadErr = fad_fu4_IssueCommandTypeB(R_FAD_CMDID_ERASE, i_u4_FadAddr);
        /* Add a FACI Number to Error code  */
        l_bu4_fadErr = R_FAD_SET_FACI_NUMBER(l_bu4_fadErr, l_bu2_faciNumber);
    }
    
    return  l_bu4_fadErr;
}

/**********************************************************************************************************************
    Function Name   : fad_fu4_LockBit

    - Outline
        The body of lock bit processing
    - Format
        T_u4_FadErr
            fad_fu4_GetConfig(
                T_u1            i_u1_commandID,
                T_u4_FadAddr    i_u4_FadAddr,
                T_u4            i_u4_TimeOutCount
            );
    - Input parameter
        i_u1_commandID      : Executing command
        i_u4_FadAddr        : Address of the code flash memory block to be acquired lock bit
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
fad_fu4_LockBit(
    T_u1            i_u1_commandID,
    T_u4_FadAddr    i_u4_FadAddr,
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
    
    /* Changes FACI */
    l_bu2_faciNumber = fad_fu2_GetFACINumberFromAddress(i_u4_FadAddr);
    fad_fv0_SetFACI(l_bu2_faciNumber);
    
    /* Checks whether the command can be issued */
    l_bu4_fadErr = fad_fu4_CheckFlashStatus();
    
    /* Checks whether the flash status is not OK (not FRDY) */
    if (R_FAD_IS_ERROR(l_bu4_fadErr))
    {
        if (i_u1_commandID == R_FAD_CMDID_LOCK_SET)
        {
            /* Error Occured    */
            l_bl1_errFlag = TRUE;
            /* Add a FACI Number to Error code  */
            l_bu4_fadErr = R_FAD_SET_FACI_NUMBER(l_bu4_fadErr, l_bu2_faciNumber);
        }
        else
        {
            /* Not ERSSPD or PRGSPD */
            if (!((l_bu4_fadErr == R_FAD_ERR_ERSSPD) || (l_bu4_fadErr == R_FAD_ERR_PRGSPD)))
            {
                /* Error Occured    */
                l_bl1_errFlag = TRUE;
                /* Add a FACI Number to Error code  */
                l_bu4_fadErr = R_FAD_SET_FACI_NUMBER(l_bu4_fadErr, l_bu2_faciNumber);
            }
        }
    }
    
    /* The flash status is OK   */
    if (l_bl1_errFlag != TRUE)
    {
        /* Changes to P/E mode for CF */
        l_bu4_fadErr = fad_fu4_SetPEModeOrReadMode(R_FAD_CF_MODE, i_u4_TimeOutCount);
        
        if (R_FAD_IS_ERROR(l_bu4_fadErr))
        {
            l_bl1_errFlag = TRUE;
            l_bu4_fadErr = R_FAD_SET_FACI_NUMBER(l_bu4_fadErr, l_bu2_faciNumber);
        }
    }
    
    if (l_bl1_errFlag != TRUE)
    {
        /* Issues the command */
        l_bu4_fadErr = fad_fu4_IssueCommandTypeB(i_u1_commandID, i_u4_FadAddr);
        l_bu4_fadErr = R_FAD_SET_FACI_NUMBER(l_bu4_fadErr, l_bu2_faciNumber);
    }
    
    return  l_bu4_fadErr;
    
}

/******************************************************************************
    [fad_fu4_LockBitProtectControl]  [For Security]

    - Outline
        The body of lock bit protect control
    - Format
        T_u4_FadErr
            fad_fu4_LockBitProtectControl(
                T_u4_FadAddr    i_u4_FadAddr,
                T_bl_LockBitProtectSwitch i_bl_LockBitProtectSwitch,
            );
    - Input parameter
        i_u4_FadAddr        : Address of the code flash memory block for which
                              lock bit protect control is acquired
        T_bl_LockBitProtectSwitch     : The kind of the protection (enable or disable)
    - Return
        R_FAD_OK            : Normal completion
        R_FAD_ERR_INTERNAL  : An internal error has occurred
******************************************************************************/

T_u4_FadErr
fad_fu4_LockBitProtectControl(
    T_u4_FadAddr                i_u4_FadAddr,
    T_bl_LockBitProtectSwitch   i_bl_LockBitProtectSwitch
    )
{

    /* Defines local variables */
    T_u4_FadErr                 l_bu4_fadErr;
    volatile T_u2_FaciNumber    l_bu2_faciNumber;
    T_u4                        l_bu4_bitPosition;
    
    /* Initializes for Return value */
    l_bu4_fadErr = R_FAD_OK;
    
    /* bit value initialization  */
    l_bu4_bitPosition = 0U;
    
    /* Changes FACI */
    l_bu2_faciNumber = fad_fu2_GetFACINumberFromAddress(i_u4_FadAddr);
    fad_fv0_SetFACI(l_bu2_faciNumber);
    
    /* Setting to the register FACI0FPROTCR0 (1) */
    if(i_u4_FadAddr <= R_FAD_CFBANK_A008)
    {
        /* Acquires the bit position */
        l_bu4_bitPosition = (0x1U << (i_u4_FadAddr / R_FAD_BLOCK_SIZE_8K));
        
        /* Specifies invalid of lock bit protection */
        if(i_bl_LockBitProtectSwitch == R_FAD_LB_DISABLE)
        {
            R_FAD_REG_FACI0FPROTCR0 |= l_bu4_bitPosition;
        }
        /* Specifies valid of lock bit protection */
        else
        {
            R_FAD_REG_FACI0FPROTCR0 &= ~l_bu4_bitPosition;
        }
    }
    /* Setting to the register FACI0FPROTCR0 (2) */
    else if( (R_FAD_CFBANK_A009 <=i_u4_FadAddr) && (i_u4_FadAddr <= R_FAD_CFBANK_A031) )
    {
        i_u4_FadAddr -= R_FAD_CFBANK_A009;
        
        /* Acquires the bit position */
        l_bu4_bitPosition = (0x200U << (i_u4_FadAddr / R_FAD_BLOCK_SIZE_32K));
        
        /* Specifies invalid of lock bit protection */
        if(i_bl_LockBitProtectSwitch == R_FAD_LB_DISABLE)
        {
            R_FAD_REG_FACI0FPROTCR0 |= l_bu4_bitPosition;
        }
        /* Specifies valid of lock bit protection */
        else
        {
            R_FAD_REG_FACI0FPROTCR0 &= ~l_bu4_bitPosition;
        }
    }
    
    /* Setting to the register FACI0FPROTCR1 */
    else if( (R_FAD_CFBANK_A032 <=i_u4_FadAddr) && (i_u4_FadAddr <= R_FAD_CFBANK_A063) )
    {
        i_u4_FadAddr -= R_FAD_CFBANK_A032;
        
        /* Acquires the bit position */
        l_bu4_bitPosition = (0x1U << (i_u4_FadAddr / R_FAD_BLOCK_SIZE_32K));
        
        /* Specifies invalid of lock bit protection */
        if(i_bl_LockBitProtectSwitch == R_FAD_LB_DISABLE)
        {
            R_FAD_REG_FACI0FPROTCR1 |= l_bu4_bitPosition;
        }
        /* Specifies valid of lock bit protection */
        else
        {
            R_FAD_REG_FACI0FPROTCR1 &= ~l_bu4_bitPosition;
        }    
    }
    
    /* Setting to the register FACI0FPROTCR2 */
    else if( (R_FAD_CFBANK_A064 <=i_u4_FadAddr) && (i_u4_FadAddr <= R_FAD_CFBANK_A095) )
    {
        i_u4_FadAddr -= R_FAD_CFBANK_A064;
        
        /* Acquires the bit position */
        l_bu4_bitPosition = (0x1U << (i_u4_FadAddr / R_FAD_BLOCK_SIZE_32K));
        
        /* Specifies invalid of lock bit protection */
        if(i_bl_LockBitProtectSwitch == R_FAD_LB_DISABLE)
        {
            R_FAD_REG_FACI0FPROTCR2 |= l_bu4_bitPosition;
        }
        /* Specifies valid of lock bit protection */
        else
        {
            R_FAD_REG_FACI0FPROTCR2 &= ~l_bu4_bitPosition;
        }    
    }
    
    /* Setting to the register FACI0FPROTCR3 */
    else if( (R_FAD_CFBANK_A096 <=i_u4_FadAddr) && (i_u4_FadAddr <= R_FAD_CFBANK_A127) )
    {
        i_u4_FadAddr -= R_FAD_CFBANK_A096;
        
        /* Acquires the bit position */
        l_bu4_bitPosition = (0x1U << (i_u4_FadAddr / R_FAD_BLOCK_SIZE_32K));
        
        /* Specifies invalid of lock bit protection */
        if(i_bl_LockBitProtectSwitch == R_FAD_LB_DISABLE)
        {
            R_FAD_REG_FACI0FPROTCR3 |= l_bu4_bitPosition;
        }
        /* Specifies valid of lock bit protection */
        else
        {
            R_FAD_REG_FACI0FPROTCR3 &= ~l_bu4_bitPosition;
        }
    }
    
    /* Setting to the register FACI0FPROTCR4 */
    else if( (R_FAD_CFBANK_A128 <=i_u4_FadAddr) && (i_u4_FadAddr <= R_FAD_CFBANK_A133) )
    {
        i_u4_FadAddr -= R_FAD_CFBANK_A128;
        
        /* Acquires the bit position */
        l_bu4_bitPosition = (0x1U << (i_u4_FadAddr / R_FAD_BLOCK_SIZE_32K));
        
        /* Specifies invalid of lock bit protection */
        if(i_bl_LockBitProtectSwitch == R_FAD_LB_DISABLE)
        {
            R_FAD_REG_FACI0FPROTCR4 |= l_bu4_bitPosition;
        }
        /* Specifies valid of lock bit protection */
        else
        {
            R_FAD_REG_FACI0FPROTCR4 &= ~l_bu4_bitPosition;
        }
    }

#ifndef    __RH850_P1L_C__
    /* Setting to the register FACI1FPROTCR0 */
    else if( (R_FAD_CFBANK_B000 <=i_u4_FadAddr) && (i_u4_FadAddr <= R_FAD_CFBANK_B001) )
    {    
        i_u4_FadAddr -= R_FAD_CFBANK_B000;
        
        /* Acquires the bit position */
        /* Bit position is irregular, adjusted by the formula*/
        l_bu4_bitPosition = (0x1U << (i_u4_FadAddr / (R_FAD_BLOCK_SIZE_32K/4)));
        
        /* Specifies invalid of lock bit protection */
        if(i_bl_LockBitProtectSwitch == R_FAD_LB_DISABLE)
        {
            R_FAD_REG_FACI1FPROTCR0 |= l_bu4_bitPosition;
        }
        /* Specifies valid of lock bit protection */
        else
        {
            R_FAD_REG_FACI1FPROTCR0 &= ~l_bu4_bitPosition;
        }
    }
    else if( (R_FAD_CFBANK_B002 <=i_u4_FadAddr) && (i_u4_FadAddr <= R_FAD_CFBANK_B025) )
    {
        i_u4_FadAddr -= R_FAD_CFBANK_B002;
        
        /* Acquires the bit position */
        l_bu4_bitPosition = (0x100U << (i_u4_FadAddr / R_FAD_BLOCK_SIZE_32K));
        
        /* Specifies invalid of lock bit protection */
        if(i_bl_LockBitProtectSwitch == R_FAD_LB_DISABLE)
        {
            R_FAD_REG_FACI1FPROTCR0 |= l_bu4_bitPosition;
        }
        /* Specifies valid of lock bit protection */
        else
        {
            R_FAD_REG_FACI1FPROTCR0 &= ~l_bu4_bitPosition;
        }
    }
    
    /* Setting to the register FACI1FPROTCR1 */
    else if( (R_FAD_CFBANK_B026 <=i_u4_FadAddr) && (i_u4_FadAddr <= R_FAD_CFBANK_B057) )
    {
        i_u4_FadAddr -= R_FAD_CFBANK_B026;
        
        /* Acquires the bit position */
        l_bu4_bitPosition =  (0x1U << (i_u4_FadAddr / R_FAD_BLOCK_SIZE_32K));
        
        /* Specifies invalid of lock bit protection */
        if(i_bl_LockBitProtectSwitch == R_FAD_LB_DISABLE)
        {
            R_FAD_REG_FACI1FPROTCR1 |= l_bu4_bitPosition;
        }
        /* Specifies valid of lock bit protection */
        else
        {
            R_FAD_REG_FACI1FPROTCR1 &= ~l_bu4_bitPosition;
        }
    }
    
    /* Setting to the register FACI1FPROTCR2 */
    else if( (R_FAD_CFBANK_B058 <=i_u4_FadAddr) && (i_u4_FadAddr <= R_FAD_CFBANK_B089) )
    {
        i_u4_FadAddr -= R_FAD_CFBANK_B058;
        
        /* Acquires the bit position */
        l_bu4_bitPosition =  (0x1U << (i_u4_FadAddr / R_FAD_BLOCK_SIZE_32K));
        
        /* Specifies invalid of lock bit protection */
        if(i_bl_LockBitProtectSwitch == R_FAD_LB_DISABLE)
        {
            R_FAD_REG_FACI1FPROTCR2 |= l_bu4_bitPosition;
        }
        /* Specifies valid of lock bit protection */
        else
        {
            R_FAD_REG_FACI1FPROTCR2 &= ~l_bu4_bitPosition;
        }
    }
    
    /* Setting to the register FACI1FPROTCR3 */
    else if( (R_FAD_CFBANK_B090 <=i_u4_FadAddr) && (i_u4_FadAddr <= R_FAD_CFBANK_B121) )
    {
        i_u4_FadAddr -= R_FAD_CFBANK_B090;
        
        /* Acquires the bit position */
        l_bu4_bitPosition =  (0x1U << (i_u4_FadAddr / R_FAD_BLOCK_SIZE_32K));
        
        /* Specifies invalid of lock bit protection */
        if(i_bl_LockBitProtectSwitch == R_FAD_LB_DISABLE)
        {
            R_FAD_REG_FACI1FPROTCR3 |= l_bu4_bitPosition;
        }
        /* Specifies valid of lock bit protection */
        else
        {
            R_FAD_REG_FACI1FPROTCR3 &= ~l_bu4_bitPosition;
        }
    }
    
    /* Setting to the register FACI1FPROTCR4 */
    else if( (R_FAD_CFBANK_B122 <=i_u4_FadAddr) && (i_u4_FadAddr <= R_FAD_CFBANK_B127) )
    {
        i_u4_FadAddr -= R_FAD_CFBANK_B122;
        
        /* Acquires the bit position */
        l_bu4_bitPosition =  (0x1U << (i_u4_FadAddr / R_FAD_BLOCK_SIZE_32K));
        
        /* Specifies invalid of lock bit protection */
        if(i_bl_LockBitProtectSwitch == R_FAD_LB_DISABLE)
        {
            R_FAD_REG_FACI1FPROTCR4 |= l_bu4_bitPosition;
        }
        /* Specifies valid of lock bit protection */
        else
        {
            R_FAD_REG_FACI1FPROTCR4 &= ~l_bu4_bitPosition;
        }
    }
#endif    /* #ifndef __RH850_P1L_C__ */
    /* other */
    else
    {
        l_bu4_fadErr = R_FAD_ERR_INTERNAL;
    }
    
    return l_bu4_fadErr;
}

/**********************************************************************************************************************
    Function Name   : fad_fu4_IssueCommandTypeA

    - Outline
        Issues the command (Type A)
        For as follwing:
            - Write
            - SetConfig
    - Format
        T_u4_FadErr
            fad_fu4_IssueCommandTypeA(
                T_u1            i_u1_commandID,
                T_u4_FadAddr    i_u4_FadAddr,
                T_p_DataBuff    i_p_DataBuff,
                T_u1            i_bu1_unitSize,
                T_u4            i_bu4_timeOutCount
            );
    - Input parameter
        i_u1_commandID      : Executing command
        i_u4_FadAddr        : Address of issuance target
        i_p_DataBuff        : Address of the data buffer
        i_bu1_unitSize      : Unit size
        i_bu4_timeOutCount  : Count for timeout
                              When set to FSTATR(DBFULL), prevent to wait forever.
                              If this value is 0, waits forever
    - Return
        R_FAD_OK            : Normal completion
    - Remark
        When corresponding to the DMA program command, it is necessary to set the size to 2 bytes.
**********************************************************************************************************************/

T_u4_FadErr
fad_fu4_IssueCommandTypeA(
    T_u1            i_u1_commandID,
    T_u4_FadAddr    i_u4_FadAddr,
    T_p_DataBuff    i_p_DataBuff,
    T_u1            i_bu1_unitSize,
    T_u4            i_bu4_timeOutCount
    )
{
    /* Defines local variables */
    T_u4_FadErr l_bu4_fadErr;
    T_bl        l_bl1_errFlag;
    T_u1        l_bu1_roopCnt;
    T_u2*       l_p_buff;
    T_bl        l_bl1_codeFlashMode;
    T_u4        l_bu4_FENTRYR;
    
    /* Initializes for Return value */
    l_bu4_fadErr = R_FAD_OK;
    
    /* Initializes error flag */
    l_bl1_errFlag = FALSE;
    
    l_p_buff            = (T_u2 *)i_p_DataBuff;
    l_bu4_FENTRYR       = R_FAD_REG_FENTRYR;
    l_bl1_codeFlashMode = (l_bu4_FENTRYR == R_FAD_CF_MODE);
    
    /* Sets to target address   */
    R_FAD_REG_FSADDR  = i_u4_FadAddr;
    
    /* The device specification flow for Program Command Issue   */
    R_FAD_CMD_AREA_FOR_1BYTE  = i_u1_commandID;
    R_FAD_CMD_AREA_FOR_1BYTE  = i_bu1_unitSize;
    R_FAD_CMD_AREA_FOR_2BYTES = *l_p_buff++;
    
    for (l_bu1_roopCnt = 0; l_bu1_roopCnt < i_bu1_unitSize-1; l_bu1_roopCnt++)
    {
        R_FAD_CMD_AREA_FOR_2BYTES = *l_p_buff++;
        
        /* If the mode is Code Flash P/E Mode       */
        if (l_bl1_codeFlashMode)
        {
            /* To avoid the P-Bus waiting               */
            /* The case of Data Flash is not related    */
            l_bu4_fadErr = fad_fu4_WaitForDBFULLIsInvalid(i_bu4_timeOutCount);
            
            if (R_FAD_IS_ERROR(l_bu4_fadErr))
            {
                l_bl1_errFlag = TRUE;
            }
        }
    }
    
    if (l_bl1_errFlag != TRUE)
    {
        R_FAD_CMD_AREA_FOR_1BYTE = R_FAD_CMDID_RUN;
    }
    
    return l_bu4_fadErr;
}

/**********************************************************************************************************************
    Function Name   : fad_fu4_IssueCommandTypeB

    - Outline
        Issues the command (Type B)
        For as follwing:
            - Erase
            - SetLockBit/GetLockBit
            - Blank Check
    - Format
        T_u4_FadErr
            fad_fu4_IssueCommandTypeB(
                T_u1            i_u1_commandID,
                T_u4_FadAddr    i_u4_FadAddr
            );
    - Input parameter
        i_u1_commandID      : Executing command
        i_u4_FadAddr        : Address of issuance target
    - Return
        R_FAD_OK            : Normal completion
**********************************************************************************************************************/

T_u4_FadErr
fad_fu4_IssueCommandTypeB(
    T_u1            i_u1_commandID,
    T_u4_FadAddr    i_u4_FadAddr
    )
{
    R_FAD_REG_FSADDR            = i_u4_FadAddr;
    R_FAD_CMD_AREA_FOR_1BYTE    = i_u1_commandID;
    R_FAD_CMD_AREA_FOR_1BYTE    = R_FAD_CMDID_RUN;
    
    return R_FAD_OK;
}

/**********************************************************************************************************************
    Function Name   : fad_fu4_IssueCommandTypeC

    - Outline
        Issues the command (Type C)
        For as follwing:
            - Status Clear
            - Forced Stop
            - Suspend
            - Resume
    - Format
        T_u4_FadErr
            fad_fu4_IssueCommandTypeC(
                T_u1            i_u1_commandID
            );
    - Input parameter
        i_u1_commandID      : Executing command
    - Return
        R_FAD_OK            : Normal completion
**********************************************************************************************************************/

T_u4_FadErr
fad_fu4_IssueCommandTypeC(
    T_u1    i_u1_commandID
    )
{
    R_FAD_CMD_AREA_FOR_1BYTE = i_u1_commandID;
    
    return R_FAD_OK;
}

/**********************************************************************************************************************
    Function Name   : fad_fu4_InitializeFlashSequencerSetupRegister

    - Outline
        Initializes registers
    - Format
        T_u4_FadErr
            fad_fu4_InitializeFlashSequencerSetupRegister(void);
    - Input parameter
        non
    - Return
        R_FAD_OK            : Normal completion
**********************************************************************************************************************/

T_u4_FadErr
fad_fu4_InitializeFlashSequencerSetupRegister(void)
{
    /* Initializes registers */
    R_FAD_REG_FACI0.FSUINITR = R_FAD_FSUINITR_SUINIT;

#ifndef    __RH850_P1L_C__
    R_FAD_REG_FACI1.FSUINITR = R_FAD_FSUINITR_SUINIT;
#endif    /* #ifndef __RH850_P1L_C__ */
    
    /* Changes FACI */
    fad_fv0_SetFACI(R_FAD_FACI0);
    
    return R_FAD_OK;
}

/**********************************************************************************************************************
    Function Name   : fad_fu4_SetRerutnOfFcuTransition (STUB for test)

    - Outline
        FCU firmware transfer
    - Format
        void
            fad_fu4_SetRerutnOfFcuTransition(
                T_u4    rt
            );
    - Input parameter
        T_u4    rt          : Information for stub
    - Return
        non
**********************************************************************************************************************/

#ifdef __R_FAD_USE_STUB__   /* For internal test */
extern T_u4 bu4_ReturnFcutrans;

void
fad_fu4_SetRerutnOfFcuTransition(
    T_u4   rt
    )
{
    bu4_ReturnFcutrans = rt;
}
#endif    /* __R_FAD_USE_STUB__ */


/**********************************************************************************************************************
    Function Name   : fad_fu4_TransferToFCU

    - Outline
        FCU firmware transfer
    - Format
        T_u4_FadErr
            fad_fu4_TransferToFCU(
                T_u4            i_u4_TimeOutCount
            );
            
    - Input parameter
         i_u4_TimeOutCount   : Count for Timeout when the value is set to FENTRYR
                               If you want to wait forever, set the "R_FAD_NO_TIMEOUT"
    - Return
        R_FAD_OK            : Normal completion
        R_FAD_ERR_TIMEOUT   : Timeout before setting the value to FENTRYR
**********************************************************************************************************************/

T_u4_FadErr
fad_fu4_TransferToFCU(
    T_u4    i_u4_TimeOutCount
)
{

    /* Defines local variables */
#ifdef __R_FAD_USE_STUB__
    return bu4_ReturnFcutrans;
#else
    T_u4_FadErr l_bu4_fadErr;
    T_bl        l_bl1_errFlag;
    T_u4*       l_p_fadFCURAM_FACI0;
    T_u4*       l_p_fadFCUFIRM;
    T_u4        l_bu4_FCURAMCodeSizeDevidedBy4;
    T_u4        l_bu4_checkSum;
    T_u4        l_bu4_checkSumResult;
    T_u1        l_bu1_FAEINT;
    T_u1        l_bu1_FAEINT_FACI0;
#ifndef __RH850_P1L_C__
    T_u1        l_bu1_FAEINT_FACI1;
#endif  /* __RH850_P1L_C__ */
    
    /* Initializes for Return value */
    l_bu4_fadErr = R_FAD_OK;
    
    /* Initializes error flag */
    l_bl1_errFlag = FALSE;
    
    /* Shifts to read mode [FACI0] */
    fad_fv0_SetFACI(R_FAD_FACI0);
    l_bu4_fadErr = fad_fu4_SetPEModeOrReadMode(R_FAD_RD_MODE, i_u4_TimeOutCount);
    
    if (R_FAD_IS_ERROR(l_bu4_fadErr))
    {
        l_bl1_errFlag = TRUE;
    }
    
#ifndef __RH850_P1L_C__
    if (l_bl1_errFlag != TRUE)
    {
        /* Shifts to read mode [FACI1] */
        fad_fv0_SetFACI(R_FAD_FACI1);
        l_bu4_fadErr = fad_fu4_SetPEModeOrReadMode(R_FAD_RD_MODE, i_u4_TimeOutCount);
        
        if (R_FAD_IS_ERROR(l_bu4_fadErr))
        {
            l_bl1_errFlag = TRUE;
        }
    }
#endif  /* __RH850_P1L_C__ */
    
    if (l_bl1_errFlag != TRUE)
    {
        /***************************************************************
         *  Sets the FRAMMCR and FCURAME
         **************************************************************/
        /* Both FCURAMs are written at the same by writing to FCURAM in FACI0 */
        R_FAD_REG_FACI0.FRAMMCR = R_FAD_KEY_FRAMMCR | 0x01;
        
        /* Enables access to the FCURAM                  */
        /* FCURAM Transfer Mode is High-speed write mode */
        R_FAD_REG_FACI0.FCURAME = R_FAD_KEY_FCURAME | 0x03;
        
    #ifndef __RH850_P1L_C__
        /* Both FCURAMs are written at the same by writing to FCURAM in FACI0 */
        R_FAD_REG_FACI1.FRAMMCR = R_FAD_KEY_FRAMMCR | 0x01;
        
        /* Enables access to the FCURAM                  */
        /* FCURAM Transfer Mode is High-speed write mode */
        R_FAD_REG_FACI1.FCURAME = R_FAD_KEY_FCURAME | 0x03;
    #endif  /* __RH850_P1L_C__ */
        
        /***************************************************************
         *  Sets the FCURAM [FACI0] and FCUFIRM
         **************************************************************/
        
        /* Sets the start address of FCURAM [FACI0] */
        l_p_fadFCURAM_FACI0 = (T_u4 *)R_FAD_FCURAM0_BASE;
        
        /* For the reading of the FCURAM size and checksum, */
        /* sets the start address of FCUFIRM                */
        l_p_fadFCUFIRM                  = (T_u4 *)R_FAD_FCUFIRM_BASE;
        l_bu4_FCURAMCodeSizeDevidedBy4  = l_p_fadFCUFIRM[1022];
        l_bu4_checkSum                  = l_p_fadFCUFIRM[1023];
        
        /***************************************************************
         *  Disables interrupt
         **************************************************************/
        
        /* Disables interrupt for FACI0 */
        fad_fv0_SetFACI(R_FAD_FACI0);
        
        l_bu1_FAEINT           = R_FAD_REG_FACI0.FAEINT;
        l_bu1_FAEINT_FACI0     = l_bu1_FAEINT;
        l_bu1_FAEINT          &= ~0x11;
        R_FAD_REG_FACI0.FAEINT = l_bu1_FAEINT;
        
    #ifndef __RH850_P1L_C__
        /* Disables interrupt for FACI1 */
        fad_fv0_SetFACI(R_FAD_FACI1);
        
        l_bu1_FAEINT           = R_FAD_REG_FACI1.FAEINT;
        l_bu1_FAEINT_FACI1     = l_bu1_FAEINT;
        l_bu1_FAEINT          &= ~0x11;
        R_FAD_REG_FACI1.FAEINT = l_bu1_FAEINT;
    #endif  /* __RH850_P1L_C__ */
        
        /***************************************************************
         *  Copy to FCURAM
         *  According to setting for FRAMMCR,
         *  it is OK to control the FACI0 only
         **************************************************************/
        
        /* FCU firmware transfer */
        fad_fv0_Memcpy4(l_p_fadFCURAM_FACI0, l_p_fadFCUFIRM, R_FAD_FCURAM_WHOLE_SIZE/R_FAD_FCURAM_COPY_UNIT);
        
        /* Enables interrupt for FACI0 */
        R_FAD_REG_FACI0.FAEINT  = l_bu1_FAEINT_FACI0;
        /* FCURAM Transfer Mode is Normal transfer mode */
        /* to read and write access to FCURAM           */
        R_FAD_REG_FACI0.FCURAME = R_FAD_KEY_FCURAME | 0x01;
    #ifndef __RH850_P1L_C__
        /* Enables interrupt for FACI1 */
        R_FAD_REG_FACI1.FAEINT  = l_bu1_FAEINT_FACI1;
        /* FCURAM Transfer Mode is Normal transfer mode */
        /* to read and write access to FCURAM           */
        R_FAD_REG_FACI1.FCURAME = R_FAD_KEY_FCURAME | 0x01;
    #endif  /* __RH850_P1L_C__ */
        
        /* Checks the checksum */
        l_bu4_checkSumResult = fad_fu4_GetCheckSum(l_p_fadFCURAM_FACI0,
                                                   l_bu4_FCURAMCodeSizeDevidedBy4,
                                                   R_FAD_FCURAM_CHECKSUM_ADDING_UNIT);

        if (l_bu4_checkSum != l_bu4_checkSumResult)
        {
            l_bl1_errFlag = TRUE;
            l_bu4_fadErr = R_FAD_ERR_FCUTRNS;
        }
    }
    
    if (l_bl1_errFlag != TRUE)
    {
        /* Disables access to the FCURAM                */
        /* FCURAM Transfer Mode is Normal transfer mode */
        /* to read and write access to FCURAM           */
        R_FAD_REG_FACI0.FCURAME = R_FAD_KEY_FCURAME | 0x00;
        
    #ifndef __RH850_P1L_C__
        /* Disables access to the FCURAM                */
        /* FCURAM Transfer Mode is Normal transfer mode */
        /* to read and write access to FCURAM           */
        R_FAD_REG_FACI1.FCURAME = R_FAD_KEY_FCURAME | 0x00;
    #endif  /* __RH850_P1L_C__ */
        
        /***************************************************************
         *  Issues Forced Stop command
         *  for clearing the ECC error flag in FCURAM
         **************************************************************/
        
        l_bu4_fadErr = R_FAD_ForcedStop(R_FAD_FACI0, i_u4_TimeOutCount);
        if (R_FAD_IS_ERROR(l_bu4_fadErr))
        {
            l_bl1_errFlag = TRUE;
        }
        
    #ifndef __RH850_P1L_C__
        l_bu4_fadErr = R_FAD_ForcedStop(R_FAD_FACI1, i_u4_TimeOutCount);
        if (R_FAD_IS_ERROR(l_bu4_fadErr))
        {
           l_bl1_errFlag = TRUE;
        }
    #endif  /* __RH850_P1L_C__ */
        
    }

    /***************************************************************
     *  Shifts to read mode
     **************************************************************/
    
    if (l_bl1_errFlag != TRUE)
    {
        fad_fv0_SetFACI(R_FAD_FACI0);
        l_bu4_fadErr = fad_fu4_SetPEModeOrReadMode(R_FAD_RD_MODE, i_u4_TimeOutCount);
    
    #ifndef __RH850_P1L_C__
        /* Shifts to read mode */
        fad_fv0_SetFACI(R_FAD_FACI1);
        l_bu4_fadErr = fad_fu4_SetPEModeOrReadMode(R_FAD_RD_MODE, i_u4_TimeOutCount);
    #endif  /* __RH850_P1L_C__ */
    }
    
    return l_bu4_fadErr;
    
#endif  /* __R_FAD_USE_STUB__ */
}

/**********************************************************************************************************************
    Function Name   : fad_fu4_CheckFlashStatus

    - Outline
        Checks whether the command can be issued.
        Checks as following :
            - FRDY
            - CMDLK
            - ERSSPD
            - PRGSPD
        If the FRDY is TRUE, returns to R_FAD_OK.
            
    - Format
        T_u4_FadErr
            fad_fu4_CheckFlashStatus(void);
    - Input parameter
        non
    - Return
        R_FAD_OK            : Normal completion
        R_FAD_ERR_CMDLK     : Command locked state
        R_FAD_ERR_BUSY      : Execution of this flash access API function is
                              in progress
        R_FAD_ERR_ERSSPD    : Erasing is suspended
        R_FAD_ERR_PRGSPD    : Programming is suspended
**********************************************************************************************************************/

T_u4_FadErr
fad_fu4_CheckFlashStatus(void)
{
    /* Defines local variables */
    T_u4_FadErr l_bu4_fadErr;
    T_bl        l_bl1_errFlag;
    T_bl        l_bl1_CMDLK_FASTAT;
    T_bl        l_bl1_FRDY_FSTATR;
    T_bl        l_bl1_ERSSPD_FSTATR;
    T_bl        l_bl1_PRGSPD_FSTATR;
    
    /* Initializes for Return value */
    l_bu4_fadErr = R_FAD_OK;
    
    /* Initializes error flag */
    l_bl1_errFlag = FALSE;
    
    /* Checks FRDY */
    l_bl1_FRDY_FSTATR = fad_fbl_IsFRDY();
    if (l_bl1_FRDY_FSTATR == TRUE)
    {
        /* Checks Command Locked state */
        l_bl1_CMDLK_FASTAT = fad_fbl_IsCMDLK();
        
        /* If the status is Command Lock */
        if (l_bl1_CMDLK_FASTAT == TRUE)
        {
            /* Error Occured    */
            l_bl1_errFlag = TRUE;
            l_bu4_fadErr = R_FAD_ERR_CMDLK;
        }
        
        /* If the status is not Command Lock */
        if (l_bl1_errFlag != TRUE)
        {
            /* Checks ERSSPD and PRGSPD */
            l_bl1_ERSSPD_FSTATR = fad_fbl_IsERSSPD();
            l_bl1_PRGSPD_FSTATR = fad_fbl_IsPRGSPD();
            
            if (l_bl1_ERSSPD_FSTATR == TRUE)
            {
                l_bu4_fadErr = R_FAD_ERR_ERSSPD;
            }
            else if (l_bl1_PRGSPD_FSTATR == TRUE)
            {
                l_bu4_fadErr = R_FAD_ERR_PRGSPD;
            }
            else
            {
                l_bu4_fadErr = R_FAD_OK;
            }
        }
    }
    else
    {
        l_bu4_fadErr = R_FAD_ERR_BUSY;
    }
    
    return l_bu4_fadErr;
}

/**********************************************************************************************************************
    Function Name   : fad_fu4_IsValidToIssueCommand

    - Outline
        Checks whether the command can be issued (Status Clear)
    - Format
        T_u4_FadErr
            fad_fu4_IsValidToIssueCommand(void);
    - Input parameter
        non
    - Return
        R_FAD_OK            : Normal completion
        R_FAD_ERR_BUSY      : Execution of this flash access API function is in progress
**********************************************************************************************************************/

T_u4_FadErr
fad_fu4_IsValidToIssueCommand(void)
{
    /* Defines local variables */
    T_u4_FadErr l_bu4_fadErr;
    
    /* Initializes for Return value */
    l_bu4_fadErr = R_FAD_OK;
    
    if (fad_fbl_IsFRDY() == TRUE)
    {
        l_bu4_fadErr = R_FAD_OK;
    }
    else
    {
        l_bu4_fadErr = R_FAD_ERR_BUSY;
    }
    
    return l_bu4_fadErr;
}

/**********************************************************************************************************************
    Function Name   : fad_fu4_CheckFlashStatusSuspendable

    - Outline
        Checks whether the command can be issued (Suspend)
    - Format
        T_u4_FadErr
            fad_fu4_CheckFlashStatusSuspendable(void);
    - Input parameter
        non
    - Return
        R_FAD_OK            : Normal completion
        R_FAD_ERR_CMDLK     : Command locked state
        R_FAD_ERR_CANNOTSPD : A processing that cannot be suspended is being executed
**********************************************************************************************************************/

T_u4_FadErr
fad_fu4_CheckFlashStatusSuspendable(void)
{
    /* Defines local variables */
    T_u4_FadErr l_bu4_fadErr;
    T_bl        l_bl1_errFlag;
    
    /* Initializes for Return value */
    l_bu4_fadErr = R_FAD_OK;
    
    /* Initializes error flag */
    l_bl1_errFlag = FALSE;
    
    if (fad_fbl_IsCMDLK() == TRUE)
    {
        l_bl1_errFlag = TRUE;
        l_bu4_fadErr = R_FAD_ERR_CMDLK;
    }
    
    if (l_bl1_errFlag != TRUE)
    {
        /* Checks SUSRDY */
        if (fad_fbl_IsSUSRDY() == TRUE)
        {
            l_bu4_fadErr = R_FAD_OK;
        }
        else
        {
            l_bu4_fadErr = R_FAD_ERR_CANNOTSPD;
        }
    }
    
    return l_bu4_fadErr;
}

/**********************************************************************************************************************
    Function Name   : fad_fu1_GetPEModeOrReadMode

    - Outline
        Acquires the P/E mode
    - Format
        T_u4
            fad_fu4_GetPEModeOrReadMode(void);
    - Input parameter
        non
    - Return
        R_FAD_REG_FENTRYR   : P/E mode
**********************************************************************************************************************/

T_u4
fad_fu4_GetPEModeOrReadMode(void)
{
    /* Defines local variables */
    T_u4    l_bu4_FENTRYR;
    
    l_bu4_FENTRYR = R_FAD_REG_FENTRYR;
    
    return l_bu4_FENTRYR;
}

/**********************************************************************************************************************
    Function Name   : fad_fu4_SetPEModeOrReadMode

    - Outline
        Changes to P/E mode
    - Format
        T_u1
            fad_fu4_SetPEModeOrReadMode(
                T_u1    i_bu1_setMode,
                T_u4    i_bu4_timeOutCount
            );
    - Input parameter
        i_bu1_setMode       : The mode to set
        i_bu4_timeOutCount  : Count for timeout
                              When set to FENTRYR, prevent to wait forever.
                              If this value is 0, waits forever
    - Return
        R_FAD_REG_FENTRYR   : P/E mode
        R_FAD_ERR_TIMEOUT   : Timeout before setting the value to FENTRYR
        R_FAD_ERR_INTERNAL  : Internal error
**********************************************************************************************************************/

T_u4_FadErr
fad_fu4_SetPEModeOrReadMode(
    T_u1    i_bu1_setMode,
    T_u4    i_bu4_timeOutCount
    )
{
    /* Defines local variables */
    T_u4_FadErr l_bu4_fadErr;
    T_bl        l_bl1_errFlag;
    T_u4        l_bu4_FENTRYR;
    
    /* Initializes for Return value */
    l_bu4_fadErr = R_FAD_OK;
    
    /* Initializes error flag */
    l_bl1_errFlag = FALSE;
    
    l_bu4_FENTRYR = R_FAD_REG_FENTRYR;
    
    /* If the mode have already been same   */
    if (l_bu4_FENTRYR == i_bu1_setMode)
    {
        /* Finish the function as R_FAD_OK  */
        l_bl1_errFlag = TRUE;
    }
    
    /* Changes the mode */
    if (l_bl1_errFlag != TRUE)
    {
        /* If FENTRYR is not RD mode and set mode is not RD mode   */
        if ((l_bu4_FENTRYR != R_FAD_RD_MODE) && (i_bu1_setMode != R_FAD_RD_MODE))
        {
            /* Sets RD mode to FENTRYR  */
            R_FAD_REG_FENTRYR = R_FAD_KEY_FENTRYR | R_FAD_RD_MODE;
        }
        
        /* If FENTRYR is WR mode or set mode is WR mode */
        R_FAD_REG_FENTRYR = R_FAD_KEY_FENTRYR | i_bu1_setMode;
        
        /* Waits to set to FENTRYR or timeout */
        /* Read the FENTRYR */
        l_bu4_FENTRYR = R_FAD_REG_FENTRYR;

        /* When timeout value is set */
        if (i_bu4_timeOutCount != 0)
        {
            while (l_bu4_FENTRYR != i_bu1_setMode)
            {
                i_bu4_timeOutCount--;
                
                if (i_bu4_timeOutCount == 0)
                {
                    l_bu4_fadErr = R_FAD_ERR_TIMEOUT;
                    break;
                }
                l_bu4_FENTRYR = R_FAD_REG_FENTRYR;
            }
        }
        /* When timeout value is not set */
        else
        {
            while (l_bu4_FENTRYR != i_bu1_setMode)
            {
                l_bu4_FENTRYR = R_FAD_REG_FENTRYR;
            }
        }
        
        /* Return value is not R_FAD_OK or R_FAD_ERR_TIMEOUT */
        if ((l_bu4_fadErr != R_FAD_OK)&&(l_bu4_fadErr != R_FAD_ERR_TIMEOUT))
        {
            l_bu4_fadErr = R_FAD_ERR_INTERNAL;
        }
    }
    return l_bu4_fadErr;
}

/**********************************************************************************************************************
    Function Name   : fad_fbl_IsFRDY

    - Outline
        Checks the FRDY is available
    - Format
        T_bl
            fad_fbl_IsFRDY(void);
    - Input parameter
        non
    - Return
        TRUE(1)     : FRDY==1
        FALSE(0)    : FRDY==0
**********************************************************************************************************************/

T_bl
fad_fbl_IsFRDY(void)
{
    /* Defines local variables */
    T_bl    l_bl1_fadErr;
    T_u4    l_bu4_FSTATR;
    
    l_bu4_FSTATR = R_FAD_REG_FSTATR;
    
    /* Checks FRDY bit is available */
    if ((l_bu4_FSTATR & R_FAD_MASK_FSTATR_FRDY) != 0)
    {
        l_bl1_fadErr = TRUE;    /* FRDY is availavle */
    }
    else {
        
        l_bl1_fadErr = FALSE;   /* FRDY is not availavle */
    }
    
    return  l_bl1_fadErr;
}

/**********************************************************************************************************************
    Function Name   : fad_fbl_IsSUSRDY

    - Outline
        Checks the SUSRDY is available
    - Format
        T_bl
            fad_fbl_IsSUSRDY(void);
    - Input parameter
        non
    - Return
        TRUE(1)     : SUSRDY==1
        FALSE(0)    : SUSRDY==0
**********************************************************************************************************************/

T_bl
fad_fbl_IsSUSRDY(void)
{
    /* Defines local variables */
    T_bl    l_bl1_fadErr;
    T_u4    l_bu4_FSTATR;
    
    l_bu4_FSTATR = R_FAD_REG_FSTATR;
    
    /* Checks SUSRDY bit is available */
    if ((l_bu4_FSTATR & R_FAD_MASK_FSTATR_SUSRDY) != 0)
    {
        l_bl1_fadErr = TRUE;    /* SUSRDY is availavle */
    }
    else {
        
        l_bl1_fadErr = FALSE;   /* SUSRDY is not availavle */
    }
    
    return  l_bl1_fadErr;
}

/**********************************************************************************************************************
    Function Name   : fad_fbl_IsERSSPD

    - Outline
        Checks the ERSSPD is available
    - Format
        T_bl
            fad_fbl_IsERSSPD(void);
    - Input parameter
        non
    - Return
        TRUE(1)     : ERSSPD==1
        FALSE(0)    : ERSSPD==0
**********************************************************************************************************************/

T_bl
fad_fbl_IsERSSPD(void)
{
    /* Defines local variables */
    T_bl    l_bl1_fadErr;
    T_u4    l_bu4_FSTATR;
    
    l_bu4_FSTATR = R_FAD_REG_FSTATR;
    
    /* Checks ERSSPD bit is available */
    if ((l_bu4_FSTATR & R_FAD_MASK_FSTATR_ERSSPD) != 0)
    {
        l_bl1_fadErr = TRUE;    /* ERSSPD is availavle */
    }
    else
    {
        l_bl1_fadErr = FALSE;   /* ERSSPD is not availavle */
    }
    
    return  l_bl1_fadErr;
}

/**********************************************************************************************************************
    Function Name   : fad_fbl_IsPRGSPD

    - Outline
        Checks the PRGSPD is available
    - Format
        T_bl
            fad_fbl_IsPRGSPD(void);
    - Input parameter
        non
    - Return
        TRUE(1)     : PRGSPD==1
        FALSE(0)    : PRGSPD==0
**********************************************************************************************************************/

T_bl
fad_fbl_IsPRGSPD(void)
{
    /* Defines local variables */
    T_bl    l_bl1_fadErr;
    T_u4    l_bu4_FSTATR;
    
    l_bu4_FSTATR = R_FAD_REG_FSTATR;
    
    /* Checks PRGSPD bit is available */
    if ((l_bu4_FSTATR & R_FAD_MASK_FSTATR_PRGSPD) != 0)
    {
        l_bl1_fadErr = TRUE;    /* PRGSPD is availavle */
    }
    else
    {
        l_bl1_fadErr = FALSE;   /* PRGSPD is not availavle */
    }
    
    return  l_bl1_fadErr;
    
}

/**********************************************************************************************************************
    Function Name   : fad_fbl_IsCMDLK

    - Outline
        Checks the CMDLK is available
    - Format
        T_bl
            fad_fbl_IsCMDLK(void);
    - Input parameter
        non
    - Return
        TRUE(1)     : CMDLK==1
        FALSE(0)    : CMDLK==0
**********************************************************************************************************************/

T_bl
fad_fbl_IsCMDLK(void)
{
    /* Defines local variables */
    T_bl    l_bl1_fadErr;
    T_u1    l_bu4_FSTATR;
    
    l_bu4_FSTATR = R_FAD_REG_FASTAT;
    
    /* Checks CMDLK bit is available */
    if ((l_bu4_FSTATR & R_FAD_MASK_FASTAT_CMDLK) != 0)
    {
        l_bl1_fadErr = TRUE;    /* CMDLK is availavle */
    }
    else
    {
        l_bl1_fadErr = FALSE;   /* CMDLK is not availavle */
    }
    
    return  l_bl1_fadErr;
}

/**********************************************************************************************************************
    Function Name   : fad_fv0_SetLoopCnt

    - Outline
        Sets the number of the roop for time out
    - Format
        void
            fad_fv0_SetLoopCnt(void);
    - Input parameter
        non
    - Return
        non
**********************************************************************************************************************/

extern T_u4 bu4_FRDY1Loop;      /* The number of the roop for waiting the FRDY1             */
extern T_u4 bu4_DBFULL0Loop;    /* The number of the roop for waiting the DBFULL0           */
extern T_u4 bu4_27uWaitLoop;    /* The number of the roop for waiting the during 2.7us      */
extern T_u4 bu4_IcacheLoop;     /* The number of the roop for clearing instruction cache    */

void
fad_fv0_SetLoopCnt(void)
{
    bu4_FRDY1Loop = R_FAD_FRDY_LOOP;
    bu4_27uWaitLoop = R_FAD_WAIT_LOOP;
}

/**********************************************************************************************************************
    Function Name   : fad_fu4_WaitForDBFULLIsInvalid

    - Outline
        Waits for setting 0 to the DBFULL0 (Waits for empty of data buffer)
    - Format
        void
            fad_fu4_WaitForDBFULLIsInvalid(
                T_u4    i_bu4_timeOutCount
                );
    - Input parameter
        i_bu4_timeOutCount  : Count for timeout
                              When set to FENTRYR, prevent to wait forever.
                              If this value is 0, waits forever
    - Return
        R_FAD_OK            : Normal completion
        R_FAD_ERR_TIMEOUT   : Timeout before setting the value to FSTATR
        R_FAD_ERR_INTERNAL  : An internal error has occurred
**********************************************************************************************************************/

T_u4_FadErr
fad_fu4_WaitForDBFULLIsInvalid(
    T_u4    i_bu4_timeOutCount
)
{
    /* Defines local variables */
    T_u4_FadErr l_bu4_fadErr;
    T_u4        l_bu4_FSTATR;
    
    /* Initializes for Return value */
    l_bu4_fadErr = R_FAD_OK;
    
    l_bu4_FSTATR = R_FAD_REG_FSTATR;
    
    /* When timeout value is set */
    if (i_bu4_timeOutCount != 0)
    {
        while (l_bu4_FSTATR & R_FAD_MASK_FSTATR_DBFULL)
        {
            i_bu4_timeOutCount--;

            if (i_bu4_timeOutCount == 0)
            {
                l_bu4_fadErr = R_FAD_ERR_TIMEOUT;
                break;
            }
            l_bu4_FSTATR = R_FAD_REG_FSTATR;
        }
    }
    else
    {
        while (l_bu4_FSTATR & R_FAD_MASK_FSTATR_DBFULL)
        {
            l_bu4_FSTATR = R_FAD_REG_FSTATR;
        }
    }
    
    return l_bu4_fadErr;
}

/**********************************************************************************************************************
    Function Name   : fad_fu4_WaitForFRDYIsValid

    - Outline
        Waits for setting to the FRDY1
    - Format
        void
            fad_fu4_WaitForFRDYIsValid(void);
    - Input parameter
        non
    - Return
        R_FAD_OK            : Normal completion
        R_FAD_ERR_INTERNAL  : An internal error has occurred
**********************************************************************************************************************/

T_u4_FadErr
fad_fu4_WaitForFRDYIsValid(void)
{
    /* Defines local variables */
    T_u4_FadErr l_bu4_fadErr;
    T_u4        l_bu4_FSTATR;
    T_u4        l_bu4_roopCnt;
    
    /* Initializes for Return value */
    l_bu4_fadErr = R_FAD_OK;
    
    l_bu4_roopCnt = bu4_FRDY1Loop;
    
    do
    {
        l_bu4_FSTATR = R_FAD_REG_FSTATR;
        l_bu4_roopCnt--;
        if (l_bu4_roopCnt == 0) break;
        
    } while (!(l_bu4_FSTATR & R_FAD_MASK_FSTATR_FRDY));
    
    if (l_bu4_roopCnt == 0)
    {
        l_bu4_fadErr = R_FAD_ERR_INTERNAL;
    }
    
    return l_bu4_fadErr;
}

/**********************************************************************************************************************
    Function Name   : fad_fv0_Memcpy4

    - Outline
        Copies the memory to the memory(4 byte unit)
    - Format
        void
            fad_fv0_memcpy4(
                T_u4*   l_p_dest,
                T_u4*   l_p_src,
                T_u4    l_bu4_size
            );
    - Input parameter
        l_p_dest      : Distination address
        l_p_src       : Source address
        l_bu4_size    : Copy size
    - Return
        R_FAD_OK            : Normal completion
        R_FAD_ERR_INTERNAL  : An internal error has occurred
**********************************************************************************************************************/

void
fad_fv0_Memcpy4(
    T_u4*   l_p_destination,
    T_u4*   l_p_source,
    T_u4    l_bu4_size
    )
{
    while (l_bu4_size--)
    {
        *l_p_destination++ = *l_p_source++;
    }
}

/**********************************************************************************************************************
    Function Name   : fad_fv0_Memcpy1

    - Outline
        Copies the memory to the memory(1 byte unit)
    - Format
        void
            fad_fv0_Memcpy1(
                T_u4*   l_p_dest,
                T_u4*   l_p_src,
                T_u4    l_bu4_size
                );
    - Input parameter
        l_p_dest    : Distination address
        l_p_src     : Source address
        l_bu4_size  : Copy size
    - Return
        R_FAD_OK            : Normal completion
        R_FAD_ERR_INTERNAL  : An internal error has occurred
**********************************************************************************************************************/

void
fad_fv0_Memcpy1(
    T_u1*   l_p_destination,
    T_u1*   l_p_source,
    T_u4    l_bu4_size
    )
{
    while (l_bu4_size--)
    {
        *l_p_destination++ = *l_p_source++;
    }
}

/**********************************************************************************************************************
    Function Name   : fad_fu4_GetCheckSum

    - Outline
        Calculates the checksum
    - Format
        void
            fad_fu4_GetCheckSum(
                T_u4*   l_p_FCURAMAddr,
                T_u4    l_bu4_theNumberOf4ByteUnit,
                T_u4    l_bu4_addingUnit
                );
    - Input parameter
        l_p_FCURAM                  : Start address of FCURAM
        l_bu4_theNumberOf4ByteUnit  : The number of 4 bytes Unit
        l_bu4_addingUnit            : Size of the adding unit
    - Return
        R_FAD_OK        : Value of the checksum
**********************************************************************************************************************/

T_u4
fad_fu4_GetCheckSum(
    T_u4*   l_p_FCURAMAddr,
    T_u4    l_bu4_theNumberOf4ByteUnit,
    T_u4    l_bu4_addingUnit
    )
{
    /* Defines local variables */
    T_u2*   l_p_buff;
    T_u4    l_bu4_size;
    T_u4    l_bu4_checkSum;
    
    /* Check devided number */
    if(l_bu4_addingUnit == 0)
    {
        l_bu4_checkSum = 0;
    }
    else
    {
        l_p_buff    = (T_u2 *)l_p_FCURAMAddr;
        /* Adding count */
        l_bu4_size  = l_bu4_theNumberOf4ByteUnit * (4/l_bu4_addingUnit);
        l_bu4_checkSum = 0;
        
        while (l_bu4_size--)
        {
            l_bu4_checkSum += *l_p_buff;
            l_p_buff++;
        }
    }
    
    return l_bu4_checkSum;
}

/**********************************************************************************************************************
    Function Name   : fad_fu4_GetDetailErrorInformation

    - Outline
        Acquires the detail information of the error
        Decided the bit 31,30,29,28 of detail error information of R_FAD_GetStatus
        Detects as following:
            - Code Flash Access Error (CFAE in FASTAT)
            - Data Flash Access Error (DFAE in FASTAT)
            - An erase attempt made to an area protected by the lock bits (in FPESTAT)
            - A write attempt made to an area protected by the lock bits (in FPESTAT)
    - Format
        T_u4
            fad_fu4_GetDetailErrorInformation(void);
    - Input parameter
        non
    - Return
        l_bu4_status & R_FAD_MASK_ERROR_INFO    : Detail error information
**********************************************************************************************************************/

T_u4
fad_fu4_GetDetailErrorInformation(void)
{
    /* Defines local variables */
    T_u4 l_bu4_status;
    T_u4 l_bu4_FSTATR;
    T_u1 l_bu1_FASTAT;
    T_u2 l_bu2_FPESTAT;
    
    l_bu4_FSTATR = R_FAD_REG_FSTATR;
    
    /* Base is the value of FSTATR  */
    l_bu4_status = l_bu4_FSTATR;
    
    l_bu1_FASTAT = R_FAD_REG_FASTAT;
    
    /* Checks CFAE in FASTAT    */
    if (l_bu1_FASTAT & R_FAD_MASK_FASTAT_CFAE)
    {
        l_bu4_status |= R_FAD_ERR_STS_CFAE;
    }
    
    /* Checks DFAE in FASTAT    */
    if (l_bu1_FASTAT & R_FAD_MASK_FASTAT_DFAE)
    {
        l_bu4_status |= R_FAD_ERR_STS_DFAE;
    }
    
    /* Checks ERSERR in FSTATR  */
    if (l_bu4_FSTATR & R_FAD_MASK_FSTATR_ERSERR)
    {
        l_bu2_FPESTAT = R_FAD_REG_FPESTAT;
        /* Checks PEERRST in FPESTAT  */
        if (l_bu2_FPESTAT == R_FAD_MASK_FPESTAT_ER_ERR_LOCK)
        {
            l_bu4_status |= R_FAD_ERR_STS_ERSERR_LOCK;
        }
    }
    
    /* Checks PRGERR in FSTATR  */
    if (l_bu4_FSTATR & R_FAD_MASK_FSTATR_PRGERR)
    {
        l_bu2_FPESTAT = R_FAD_REG_FPESTAT;
        /* Checks PEERRST in FPESTAT  */
        if (l_bu2_FPESTAT == R_FAD_MASK_FPESTAT_WR_ERR_LOCK)
        {
            l_bu4_status |= R_FAD_ERR_STS_PRGERR_LOCK;
        }
    }
    
    return (l_bu4_status & R_FAD_MASK_ERROR_INFO);
}

/**********************************************************************************************************************
    Function Name   : fad_fu1_GetAcceptedFACICommand

    - Outline
        Acquires the executed command
    - Format
        T_u1
            fad_fu1_GetAcceptedFACICommand(void);
    - Input parameter
        non
    - Return
        l_bu1_acceptedCommand   : Executed command
**********************************************************************************************************************/

T_u1
fad_fu1_GetAcceptedFACICommand(void)
{
    /* Defines local variables */
    T_u2 l_bu2_FCMDR;
    T_u4 l_bu4_FENTRYR;
    T_u1 l_bu1_CMDR_FCMDR;
    T_u1 l_bu1_PCMDR_FCMDR;
    T_u1 l_bu1_acceptedCommand;
    
    l_bu2_FCMDR = R_FAD_REG_FCMDR;
    l_bu1_CMDR_FCMDR  = l_bu2_FCMDR >> 8;
    l_bu1_PCMDR_FCMDR = l_bu2_FCMDR & 0x00FF;
    
    /* If the command is Running (CMDR == 0xD0) */
    if (l_bu1_CMDR_FCMDR == R_FAD_CMDID_RUN)
    {
        /* If the privious command is Block Erase       */
        if (l_bu1_PCMDR_FCMDR == R_FAD_CMDID_ERASE)
        {
            l_bu1_acceptedCommand = R_FAD_CMD_BLOCK_ERASE;
        }
        /* If the privious command is Lock Bit Program  */
        else if (l_bu1_PCMDR_FCMDR == R_FAD_CMDID_LOCK_SET)
        {
            l_bu1_acceptedCommand = R_FAD_CMD_LOCK_BIT_PROGRAM;
        }
        /* If the privious command is Lock Bit Read     */
        else if (l_bu1_PCMDR_FCMDR == R_FAD_CMDID_LOCK_GET)
        {
            l_bu4_FENTRYR = R_FAD_REG_FENTRYR;
            /* If the Flash entry register is CF mode   */
            if (l_bu4_FENTRYR == R_FAD_CF_MODE)
            {
                l_bu1_acceptedCommand = R_FAD_CMD_LOCK_BIT_READ;
            }
            /* If the Flash entry register is DF mode   */
            else if (l_bu4_FENTRYR == R_FAD_DF_MODE)
            {
                l_bu1_acceptedCommand = R_FAD_CMD_BLANK_CHECK;
            }
        }
    }
    /* If the command is not Running (CMDR != 0xD0) */
    else
    {
        switch (l_bu1_CMDR_FCMDR)
        {
            case R_FAD_CMDID_WRITE:
                l_bu1_acceptedCommand = R_FAD_CMD_PROGRAM;
                break;
            case R_FAD_CMDID_OTP:
                l_bu1_acceptedCommand = R_FAD_CMD_OTP_SET;
                break;
            case R_FAD_CMDID_CONFIG:
                l_bu1_acceptedCommand = R_FAD_CMD_CONFIG_PROGRAM;
                break;
        }
    }
    
    return l_bu1_acceptedCommand;
}

/**********************************************************************************************************************
    Function Name   : fad_fu2_GetFACINumberFromAddress

    - Outline
        Judge of the number of the FACI
    - Format
        T_u2_FaciNumber
            fad_fu2_GetFACINumberFromAddress(
                T_u4_FadAddr    i_bu4_fadAddr
                );
    - Input parameter
        i_bu4_fadAddr   : Address of the Flash memory
    - Return
        R_FAD_FACI0 : FACI0
        R_FAD_FACI1 : FACI1
**********************************************************************************************************************/

T_u2_FaciNumber
fad_fu2_GetFACINumberFromAddress(T_u4_FadAddr i_bu4_fadAddr)
{
    /* Defines local variables */
    T_u2_FaciNumber l_bu2_faciNumber;
    
    l_bu2_faciNumber = R_FAD_FACI0;
    
    /* Checks the area of Data Flash */
    if ((i_bu4_fadAddr >= R_FAD_DF0_BASE) && (i_bu4_fadAddr < R_FAD_DF_END))
    {
        if (i_bu4_fadAddr >= R_FAD_DF1_BASE)
        {
            l_bu2_faciNumber = R_FAD_FACI1;
        }
    }
    
    /* Checks the area of Code Flash */
    else if (i_bu4_fadAddr < R_FAD_CF_END)
    {
        if (i_bu4_fadAddr >= R_FAD_CF1_BASE)
        {
            l_bu2_faciNumber = R_FAD_FACI1;
        }
    }
    
    return l_bu2_faciNumber;
}

/**********************************************************************************************************************
    Function Name   : fad_fv0_SetFACI

    - Outline
        Changes the FACI register
    - Format
        void
            fad_fv0_SetFACI(
                T_u2_FaciNumber     i_bu2_faciNo
            );
    - Input parameter
        i_bu2_faciNo    : Address of the Flash memory
    - Return
        R_FAD_FACI0 : FACI0
        R_FAD_FACI1 : FACI1
**********************************************************************************************************************/

extern T_u4 bu4_FaciBase;
extern T_u4 bu4_CommandArea;

void
fad_fv0_SetFACI(T_u2_FaciNumber i_bu2_faciNo)
{
    if (i_bu2_faciNo == R_FAD_FACI1)
    {
        bu4_FaciBase = R_FAD_FACI1_BASE;
        bu4_CommandArea = R_FAD_CMDAREA1;   /* FACI1 command-issuing area   */
    }
    else
    {
        bu4_FaciBase = R_FAD_FACI0_BASE;
        bu4_CommandArea = R_FAD_CMDAREA0;   /* FACI0 command-issuing area   */
    }
    
    return;
}

/**********************************************************************************************************************
    Function Name   : fad_fu4_SetConfig

    - Outline
        The body of setting configuration
    - Format
        T_u4_FadErr
            fad_fu4_SetConfig(
                T_u1            i_u1_faciCommandID,
                T_u4_FadAddr    i_u4_FadAddr,
                T_p_DataBuff    i_p_DataBuff,
                T_u4            i_u4_TimeOutCount
            );
    - Input parameter
        i_u1_faciCommandID  : Executing command
        i_u4_FadAddr        : Address of the code flash memory block to be set configuration
        i_p_DataBuff        : Pointer to the buffer where the data to be written is stored
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
fad_fu4_SetConfig(
    T_u1            i_u1_faciCommandID,
    T_u4_FadAddr    i_u4_FadAddr,
    T_p_DataBuff    i_p_DataBuff,
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
    
    /* Changes FACI */
    l_bu2_faciNumber = fad_fu2_GetFACINumberFromAddress(i_u4_FadAddr);
    fad_fv0_SetFACI(l_bu2_faciNumber);
    
    /* Checks whether the command can be issued */
    /* Checks flash status                      */
    l_bu4_fadErr = fad_fu4_CheckFlashStatus();
    if (R_FAD_IS_ERROR(l_bu4_fadErr))
    {
        l_bl1_errFlag = TRUE;
    }
    
    if (l_bl1_errFlag != TRUE)
    {
        /* Changes to P/E mode for DF */
        l_bu4_fadErr = fad_fu4_SetPEModeOrReadMode(R_FAD_DF_MODE, i_u4_TimeOutCount);
        if (R_FAD_IS_ERROR(l_bu4_fadErr))
        {
            l_bl1_errFlag = TRUE;
        }
    }
    
    if (l_bl1_errFlag != TRUE)
    {
        /* Issues the command */
        l_bu4_fadErr = fad_fu4_IssueCommandTypeA(i_u1_faciCommandID, i_u4_FadAddr, i_p_DataBuff, 8, i_u4_TimeOutCount);
    }
    
    return l_bu4_fadErr;
}

/**********************************************************************************************************************
    Function Name   : fad_fu4_GetConfig

    - Outline
        The body of acquiering configuration
    - Format
        T_u4_FadErr
            fad_fu4_GetConfig(
                T_u1            i_u1_faciCommandID,
                T_u4_FadAddr    i_u4_FadAddr,
                T_p_DataBuff    i_p_DataBuff,
                T_u4            i_bu4_timeOutCount
            );
    - Input parameter
        i_u1_faciCommandID  : Executing command
        i_u4_FadAddr        : Address of the code flash memory block to be acquired configuration
        i_p_DataBuff        : Pointer to the buffer where the data to be read is stored
        i_bu4_timeOutCount  : Count for timeout
                              When set to FENTRYR, prevent to wait forever.
                              If this value is 0, waits forever
    - Return
        R_FAD_OK            : Normal completion
        R_FAD_ERR_CLOCK     : The CPU clock frequency is incorrect.
        R_FAD_ERR_NOTSPD    : The flash access API which is specified is not suspended
        R_FAD_ERR_CANNOTSPD : A processing that cannot be suspended is
        R_FAD_ERR_FLMD0     : The FLMD0 pin is not high
        R_FAD_ERR_AUTHID    : The authentication ID did not match
        R_FAD_ERR_TIMEOUT   : Timeout before setting the value to ICCTRL
        R_FAD_ERR_INTERNAL  : An internal error has occurred being executed
**********************************************************************************************************************/
#ifdef  __GHS__
#pragma ghs section text = "R_FAD_CODE_RAM"
#endif

T_u4_FadErr
fad_fu4_GetConfig(
    T_u1            i_u1_faciCommandID,
    T_u4_FadAddr    i_u4_FadAddr,
    T_p_DataBuff    o_p_DataBuff,
    T_u4            i_bu4_timeOutCount
    )
{
    /* Defines local variables */
    T_u4_FadErr l_bu4_fadErr;
    T_bl        l_bl1_errFlag;
    T_u4        l_bu4_dataSize;
    T_u4*       l_p_fadAddr;
    
    /* Initializes for Return value */
    l_bu4_fadErr = R_FAD_OK;
    
    /* Initializes error flag */
    l_bl1_errFlag = FALSE;
    
    /* Changes the area */
    /* When the configuration area and OTP setting area are read,   */
    /* the FCUFSEL bit must be set to "1"."                         */
    l_bu4_fadErr = fad_fu4_SelectFCUFirmArea(1, i_bu4_timeOutCount);
    
    if (R_FAD_IS_ERROR(l_bu4_fadErr))
    {
        l_bl1_errFlag = TRUE;
    }
    
    if (l_bl1_errFlag != TRUE)
    {
        /* Data copy */
        l_bu4_dataSize = 4;
        l_p_fadAddr = (T_u4 *)i_u4_FadAddr;
        while (l_bu4_dataSize--)
        {
            *o_p_DataBuff++ = *l_p_fadAddr++;
        }
        
        /* Changes the area */
        l_bu4_fadErr = fad_fu4_SelectFCUFirmArea(0, i_bu4_timeOutCount);
    }
    
    return l_bu4_fadErr;
}

/**********************************************************************************************************************
    Function Name   : fad_fu4_SelectFCUFirmArea

    - Outline
        Changes the area of configuration
    - Format
        T_u4_FadErr
            fad_fu4_SelectFCUFirmArea(
                T_u1    l_bu1_FCUfirmAreaSelect,
                T_u4    i_bu4_timeOutCount
            );
    - Input parameter
        l_bu1_fcuFirmAreaSelect : Firmware Storage Area Select
                                  0 : The user area is assigned to 0x17000 to 0x17FFF
                                  1 : The firmware storage area is assigned to 0x17000 to 0x17FFF
        i_bu4_timeOutCount      : Count for timeout
                                  When set to FENTRYR, prevent to wait forever.
                                  If this value is 0, waits forever
    - Return
        R_FAD_OK                : Normal completion
        R_FAD_ERR_TIMEOUT       : Timeout before setting the value to ICCTRL
**********************************************************************************************************************/

void __SYNCI(void) {
    
}

void __SYNCP(void) {
    
}

T_u4_FadErr
fad_fu4_SelectFCUFirmArea(
    T_u1 l_bu1_FCUfirmAreaSelect,
    T_u4 i_bu4_timeOutCount
    )
{
    /* Defines local variables */
    T_u4_FadErr l_bu4_fadErr;
    
    /* Initializes for Return value */
    l_bu4_fadErr = R_FAD_OK;
    
    /* Changes the area of configuration */
    R_FAD_REG_FCUFAREA = l_bu1_FCUfirmAreaSelect;
    
    R_FAD_SYNCP();  /* This is for device specification */
    R_FAD_SYNCI();  /* This is for device specification */
    
    /* Clears the instruction cache     */
    /* This is for device specification */
    l_bu4_fadErr = fad_fu4_ClearIcache(i_bu4_timeOutCount);
    
    return l_bu4_fadErr;
}

/**********************************************************************************************************************
    Function Name   : fad_fu4_ClearIcache

    - Outline
        Clears the instruction cache
    - Format
        T_u4_FadErr
            fad_fu4_ClearIcache(
                T_u4    i_bu4_timeOutCount
                );
    - Input parameter
        i_bu4_timeOutCount  : Count for timeout
                              When set to FENTRYR, prevent to wait forever.
                              If this value is 0, waits forever
    - Return
        R_FAD_OK            : Normal completion
        R_FAD_ERR_TIMEOUT   : Timeout before setting the value to ICCTRL
**********************************************************************************************************************/

extern T_u4 bu4_IcacheLoop;

T_u4_FadErr
fad_fu4_ClearIcache(
    T_u4    i_bu4_timeOutCount
)
{
    /* Defines local variables */
    T_u4_FadErr l_bu4_fadErr;
   // T_u4        l_bu4_ICCTRL;   /* Instruction cache control register       */
   // T_u4        l_bu4_CDBCR;    /* Data Buffer Operation Function Register  */
    
    /* Initializes for Return value */
    l_bu4_fadErr = R_FAD_OK;
    
    /* regID:SR24, selID:4 : Control instruction cache (ICCTRL) */
   // l_bu4_ICCTRL = R_FAD_STSR(24,4);    /* Reads the ICCTRL     */
   // l_bu4_ICCTRL |= 0x00000100;         /* Sets 1 to ICHCLR     */
   // R_FAD_LDSR(24,4,l_bu4_ICCTRL);      /* Stores to the ICCTRL */
    
    /* Clears the instruction cache */
    /* After ICHCLR bit is set to 1, it is read as 1 until clearing is completed.   */
    /* The bit is cleared to 0 once clearing is completed                           */
    
   // l_bu4_ICCTRL = R_FAD_STSR(24,4);

    /* When timeout value is set */
   /* if (i_bu4_timeOutCount != 0)
    {
        while (l_bu4_ICCTRL & 0x00000100)
        {
            i_bu4_timeOutCount--;

            if (i_bu4_timeOutCount == 0)
            {
                l_bu4_fadErr = R_FAD_ERR_TIMEOUT;
                break;
            }
            l_bu4_ICCTRL = R_FAD_STSR(24,4);
        }
    }
    else
    {
        while (l_bu4_ICCTRL & 0x00000100)
        {
            l_bu4_ICCTRL = R_FAD_STSR(24,4);
        }
    }*/

    /* Clears the data buffer */
    /* regID:SR24, selID:13 : Control the data buffer(CDBCR)        */
    /* When CDBCLR bit is set to 1, data buffer is all cleared.     */
    /* This bit is always read as 0.                                */
    
    //l_bu4_CDBCR = R_FAD_STSR(24,13);    /* Reads the CDBCR          */
    //l_bu4_CDBCR |= 0x00000002;          /* Sets 1 to CDBCLR         */
    //R_FAD_LDSR(24,13,l_bu4_CDBCR);      /* Stores to the CDBCR      */
    //l_bu4_CDBCR = R_FAD_STSR(24,13);    /* Reads the CDBCR again    */
    
    R_FAD_SYNCP();  /* This is for device specification */
    R_FAD_SYNCI();  /* This is for device specification */
    
    return l_bu4_fadErr;
}

