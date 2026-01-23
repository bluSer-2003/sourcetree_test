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

/******************************************************************************
   PLL and Clock devider setting
   It has to set each device.
******************************************************************************/

#ifdef  __GHS__
#pragma ghs section rodata = "R_FAD_CONST"
#endif

#ifdef  __RH850_P1L_C__
const T_st_ClockFreqTable   cst_clockFreqTable[] = {
    { 16, 0xC00009D9 },        /* P1L-C No.1 */
    { 20, 0xC0000979 },        /* P1L-C No.2 */
    { 24, 0xC00011D9 },        /* P1L-C No.3 */
    { 16, 0x80000938 },        /* P1L-C No.4 */
    { 20, 0x800008F8 },        /* P1L-C No.5 */
    { 24, 0x80001138 },        /* P1L-C No.6 */
};

const T_st_PClockFreqTable  cst_pClockFreqTable[] = {
    { 24, 24, 24, 24, 15, 12,  6 },
    { 32, 32, 32, 32, 20, 16,  8 },
    { 40, 40, 40, 32, 20, 16,  8 },
    { 40, 40, 40, 30, 40, 20, 20 }
};

#else   /* for RH850/P1H-C, RH850/P1M-C */
const T_st_ClockFreqTable   cst_clockFreqTable[] = {
    { 16, 0x000009D8 },        /* P1H-C/P1M-C No.1 */
    { 16, 0x800009D8 },        /* P1H-C/P1M-C No.2 */
    { 20, 0x00000978 },        /* P1H-C/P1M-C No.3 */
    { 20, 0x80000978 },        /* P1H-C/P1M-C No.4 */
    { 24, 0x000011D8 },        /* P1H-C/P1M-C No.5 */
    { 24, 0x800011D8 },        /* P1H-C/P1M-C No.6 */
    { 16, 0x40000938 },        /* P1H-C/P1M-C No.7 */
    { 20, 0x400008F8 },        /* P1H-C/P1M-C No.8 */
    { 24, 0x40001138 },        /* P1H-C/P1M-C No.9 */
};

const T_st_PClockFreqTable  cst_pClockFreqTable[] = {
    { 30, 30, 40, 30, 40, 20, 20 },
    { 40, 40, 40, 40, 40, 20, 20 },
    { 40, 40, 40, 40, 40, 20, 20 }
};

#endif  /* __RH850_P1L_C__ */

/******************************************************************************
    [fad_fu4_SetClock]

    - Outline
        Sets the clock
    - Format
        T_u4_FadErr
        fad_fu4_SetClock(
            T_u2    i_bu2_clockIn,
            T_u2    i_bu2_clockCpu
        );
    - Input parameter
        i_bu2_clockIn       : Input clock frequency
        i_bu2_clockCpu      : CPU clock frequency
    - Return
        R_FAD_OK            : Normal completion
******************************************************************************/
#ifdef  __GHS__
#pragma ghs section text = "R_FAD_CODE_ROMRAM"
#endif

T_u4_FadErr
fad_fu4_SetClock(
    T_u2    i_bu2_clockIn,
    T_u2    i_bu2_clockCpu
    )
{
    /* Defines local variables */
    T_u4_FadErr l_bu4_fadErr;       /* Return Value                     */
    T_bl        l_bl1_errFlag;
    T_bl        l_bl1_foundFlag;    /* Flag for searching               */
    T_u4        l_bu4_opbt1;        /* Option Byte 1                    */
    T_u4        l_bu4_clkd0div;     /* Clock divider 0 divisor register */
    T_u4        l_bu4_pll0freq;     /* PLL0FREQ in the option byte 1    */
    T_u1        l_bu1_readCycle;    /* Data Flash Memory Read Cycle     */
    T_u1        l_bu1_clkLsb;
    T_u1        l_bu1_tableSearchNum;
    T_u4        l_bu4_clockFreqTableNum;
    
    /* Initializes for Return value */
    l_bu4_fadErr = R_FAD_OK;
    
    /* Initializes for error flag */
    l_bl1_errFlag = FALSE;
    
    /* Checks Input Clock Frequency */
    if ( !(i_bu2_clockIn == 16
        || i_bu2_clockIn == 20
        || i_bu2_clockIn == 24) )
    {
        l_bl1_errFlag = TRUE;
        l_bu4_fadErr = R_FAD_ERR_CLOCK;
    }
    
    /* Checks clock CPU frequency */
    if ( !(i_bu2_clockCpu == 120
        || i_bu2_clockCpu == 160
        || i_bu2_clockCpu == 240) )
    {
        l_bl1_errFlag = TRUE;
        l_bu4_fadErr = R_FAD_ERR_CLOCK;
    }
    
    
    if (l_bl1_errFlag != TRUE)
    {
        l_bu4_opbt1 = R_FAD_REG_OPBT1;
        l_bu4_opbt1 &= MASK_RESERVED_BIT_FOR_OPBT1;
        
        /* Searches the value from the table */
        l_bl1_foundFlag = FALSE;
        /* Acquires the size of cst_clockTable */
        l_bu4_clockFreqTableNum
                = (sizeof cst_clockFreqTable)/(sizeof cst_clockFreqTable[0]);
        
        for (l_bu1_tableSearchNum = 0;
                l_bu1_tableSearchNum < l_bu4_clockFreqTableNum;
                l_bu1_tableSearchNum++)
        {
            if (cst_clockFreqTable[l_bu1_tableSearchNum].cu2_InClockFreq == i_bu2_clockIn)
            {
                if (cst_clockFreqTable[l_bu1_tableSearchNum].cu4_OptionByte1 == l_bu4_opbt1)
                {
                    l_bl1_foundFlag = TRUE;
                    break;
                }
            }
        }
        
        /* No value in the table */
        if (l_bl1_foundFlag == FALSE)
        {
            l_bl1_errFlag = TRUE;
            l_bu4_fadErr = R_FAD_ERR_CLOCK;
        }
    }
    
    if (l_bl1_errFlag != TRUE)
    {
        /* Acquires FCU clock frequency */
        l_bu4_clkd0div = R_FAD_REG_CLKD0DIV;
        l_bu4_pll0freq = l_bu4_opbt1 >> 30;
        l_bu1_clkLsb   = cst_pClockFreqTable[l_bu4_pll0freq].cu1_pClockFreq[l_bu4_clkd0div-1];
        
        /* Sets FPCKAR register */
        R_FAD_REG_FACI0.FPCKAR = R_FAD_KEY_FPCKAR | l_bu1_clkLsb;
    #ifndef __RH850_P1L_C__
        R_FAD_REG_FACI1.FPCKAR = R_FAD_KEY_FPCKAR | l_bu1_clkLsb;
    #endif  /* #ifndef __RH850_P1L_C__ */
        
        /* Sets EEPRDCYCLx register */
        l_bu1_readCycle = l_bu1_clkLsb/10-1;
        R_FAD_REG_EEPRDCYCL0 = l_bu1_readCycle;
        R_FAD_REG_EEPRDCYCL1 = l_bu1_readCycle;
    }

    return l_bu4_fadErr;
}

