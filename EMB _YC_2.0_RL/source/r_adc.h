/******************************************************************************* 
* DISCLAIMER 
* This software is supplied by Renesas Electronics Corporation and is only  
* intended for use with Renesas products. No other uses are authorized. This  
* software is owned by Renesas Electronics Corporation and is protected under 
* all applicable laws, including copyright laws. 
* THIS SOFTWARE IS PROVIDED "AS IS" AND RENESAS MAKES NO WARRANTIES REGARDING 
* THIS SOFTWARE, WHETHER EXPRESS, IMPLIED OR STATUTORY, INCLUDING BUT NOT 
* LIMITED TO WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE  
* AND NON-INFRINGEMENT. ALL SUCH WARRANTIES ARE EXPRESSLY DISCLAIMED. 
* TO THE MAXIMUM EXTENT PERMITTED NOT PROHIBITED BY LAW, NEITHER RENESAS  
* ELECTRONICS CORPORATION NOR ANY OF ITS AFFILIATED COMPANIES SHALL BE LIABLE  
* FOR ANY DIRECT, INDIRECT, SPECIAL, INCIDENTAL OR CONSEQUENTIAL DAMAGES FOR 
* ANY REASON RELATED TO THIS SOFTWARE, EVEN IF RENESAS OR ITS AFFILIATES HAVE 
* BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGES. 
* Renesas reserves the right, without notice, to make changes to this software 
* and to discontinue the availability of this software. By using this software, 
* you agree to the additional terms and conditions found by accessing the  
* following link: 
* http://www.renesas.com/disclaimer 
* 
* Copyright (C) 2012, 2014 Renesas Electronics Corporation. All rights reserved.     
*******************************************************************************/
/******************************************************************************
 * System Name  : Renesas eps motor control by RH850P1x_C
 * File Name    : R_ADC.h
 * Device       : RH850P1x_C
 * OS           : none
 * H/W Platform : RH850P1x_C Controller Board 1.0
 * Description  : 
 * Limitation   : This file can be only used as internal code.
 ******************************************************************************
 * History      : 
 * <Version>    <Date>      <Author>          <Modification>
 ******************************************************************************/
#ifndef __R_ADC_H__
#define __R_ADC_H__

/*****************************************************************************
 Includes   <System Includes> , "Project Includes"
 *****************************************************************************/
#include "r_compiler.h"
/*****************************************************************************
 Macro definitions
 *****************************************************************************/
 #define Pull_upDown_disable (0x0)
#define Pull_Up  (1<<17)
#define Pull_Down (1<<16)
/*****************************************************************************
 Typedef definitions
 *****************************************************************************/
enum ADC_Trigger_MODE
{
   SOFEWARE_Trigger,
   HARDWARE_Trigger
};
/*****************************************************************************
 Global variables
 *****************************************************************************/
/*****************************************************************************
 Global functions
 *****************************************************************************/
void R_ADC_Init(void);
void R_Drv_ADC_ScanGroup_OperationOn(uint8 Pu1ADC, uint8 Pu1SGNum);
void R_Drv_ADC_UpdateValue(uint8 Pu1ADC, uint8 Pu1SGNum);
void R_Drv_ADC_diagnostic_test(void);
void R_ADC_ScanGroup_Start(uint8 Pu1Adc, uint8 Pu1SG);
#endif
