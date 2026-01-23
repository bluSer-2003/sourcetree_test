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
 * File Name    : R_ADC.c
 * Device       : RH850P1x_C
 * OS           : none
 * H/W Platform : RH850P1x_C Controller Board 1.0
 * Description  : 
 * Limitation   : This file can be only used as internal code.
 ******************************************************************************
 * History      : 
 * <Version>    <Date>      <Author>          <Modification>
 ******************************************************************************/

/*****************************************************************************
 Includes   <System Includes> , "Project Includes"
 *****************************************************************************/
#include "r_adc.h"
#include "r_adc_reg.h"
#include "iodefine.h"

/*****************************************************************************
 Macro definitions
 *****************************************************************************/

/*****************************************************************************
 Typedef definitions
 *****************************************************************************/
#define ADC_NUM                        2UL
/*****************************************************************************
 Global variables
 *****************************************************************************/

/*****************************************************************************
 Global static variables
 *****************************************************************************/
static uint32 Gsu4Adcc[ADC_NUM] = {
    ADC0_base,
    ADC1_base,
};
/*****************************************************************************
 Static functions
 *****************************************************************************/
extern uint16 Gu1ReadAdcValue[32] = {0};
extern uint16 flag_adc=0;

/*****************************************************************************
--------------------- Globle functions --------------------------------------
 *****************************************************************************/
 static int init_adc_int()
{
   EIC80  = 0x0041;//INTGTM_ATOM0_7
   EIBD80 = 0x00000001;
   EIC81   = 0x0000;//INTGTM_TIM1_1 //GTM01I1 is connected to GTM0AT0O1
   EIBD81  = 0x00000001;
   EIC167   = 0x0000;//INTGTM_TIM1_1 //GTM01I1 is connected to GTM0AT0O1
   EIBD167  = 0x00000001;
   return 0;
}


static void R_ADC_ScanGroupInit(uint8 Pu1Adc,uint8 trigger_mode)
{
    /* 1.1.1 Disable SGx triggers */
    /* Disable A/D conversion start trigger input to scan group */
    SGCR(Gsu4Adcc[Pu1Adc], 0) = trigger_mode;
    SGCR(Gsu4Adcc[Pu1Adc], 1) = trigger_mode;
    SGCR(Gsu4Adcc[Pu1Adc], 2) = trigger_mode;
    SGCR(Gsu4Adcc[Pu1Adc], 3) = trigger_mode;

    /* 1.1.2 Halt all the scan groups, A/D conversions, and A/D timers */
    ADHALTR(Gsu4Adcc[Pu1Adc]) = 0x01;
}
static void R_ADC_ScanGroupInit_Hardwaretrigger(uint8 PulAdc)
{
   //ADCFnSGSRx.SGACT = 1;
}

static inline void R_ADC_VRChannel_Bind(uint8 Pu1Adc, uint8 Pu1VrCh, uint32 Pu1HwCh)
{
    VCR(Gsu4Adcc[Pu1Adc], Pu1VrCh) = 0x00000000 | Pu1HwCh;
}

static void R_ADC_SCanGroup_Bind(uint8 Pu1Adc, uint8 Pu1SG, uint8 Pu1VrChStart, uint8 Pu1VrChEnd)
{
    SGVCSP(Gsu4Adcc[Pu1Adc], Pu1SG) = Pu1VrChStart;
    SGVCEP(Gsu4Adcc[Pu1Adc], Pu1SG) = Pu1VrChEnd;
    SGMCYCR(Gsu4Adcc[Pu1Adc], Pu1SG) = 0x00U;
    ULLMSR(Gsu4Adcc[Pu1Adc], Pu1SG) = 0x00U;
}

void R_ADC_ScanGroup_Start(uint8 Pu1Adc, uint8 Pu1SG)
{
    SGSTCR(Gsu4Adcc[Pu1Adc], Pu1SG) = 0x01U;
}
static void R_ADC_diagnostic_Init(uint32 Pul1_mode)
{
    /* 1 A/D conversion stop settings */
    R_ADC_ScanGroupInit(0,SOFEWARE_Trigger);
    R_ADC_ScanGroupInit(1,SOFEWARE_Trigger);

    /* 2 Bind Vr/Hw Channel */
    R_ADC_VRChannel_Bind(0, 0, 0|Pul1_mode);
    R_ADC_VRChannel_Bind(0, 1, 1|Pul1_mode);
    R_ADC_VRChannel_Bind(0, 2, 3|Pul1_mode);
    R_ADC_VRChannel_Bind(0, 3, 2|Pul1_mode);

    /* 3 Bind SG and Vr Channel */
    R_ADC_SCanGroup_Bind(0, 0, 0, 3);

    /* 4 Set the read and clear enable */
    SFTCR(Gsu4Adcc[0]) = 0x10U;

    /* 5 Enable the output of the scan group x end interrupt signal ADInx */
    SGCR(Gsu4Adcc[0], 0) = 0x10U;

    /* 6 Start SCAN GROUP Control */
    R_ADC_ScanGroup_Start(0, 0);
   
}
void R_ADC_Init(void)
{
    /* 1 A/D conversion stop settings */
    R_ADC_ScanGroupInit(0,HARDWARE_Trigger);
    R_ADC_ScanGroupInit(1,HARDWARE_Trigger);
    
   // ADCF0.SGCR0 = 0x0040;
   // ADCF1.SGCR0 = 0x0040;
   // ADCF0.ADSYNSTCR = 1;
    

    /* 2 Bind Vr/Hw Channel */
    R_ADC_VRChannel_Bind(0, 0, 5|Pull_upDown_disable);
    R_ADC_VRChannel_Bind(0, 1, 6|Pull_upDown_disable);
    R_ADC_VRChannel_Bind(0, 2, 7|Pull_upDown_disable);
    R_ADC_VRChannel_Bind(0, 3, 8|Pull_upDown_disable);
    R_ADC_VRChannel_Bind(0, 4, 9|Pull_upDown_disable);

    R_ADC_VRChannel_Bind(1, 4, 0|Pull_upDown_disable);
    R_ADC_VRChannel_Bind(1, 5, 2|Pull_upDown_disable);
    R_ADC_VRChannel_Bind(1, 2, 3|Pull_upDown_disable);
    R_ADC_VRChannel_Bind(1, 3, 4|Pull_upDown_disable);
    R_ADC_VRChannel_Bind(1, 0, 5|Pull_upDown_disable);
    R_ADC_VRChannel_Bind(1, 1, 6|Pull_upDown_disable);
    R_ADC_VRChannel_Bind(1, 6, 7|Pull_upDown_disable);
    R_ADC_VRChannel_Bind(1, 7, 8|Pull_upDown_disable);

    /* 3 Bind SG and Vr Channel */
    R_ADC_SCanGroup_Bind(0, 0, 0, 4);
    R_ADC_SCanGroup_Bind(1, 0, 0, 7);
    //R_ADC_SCanGroup_Bind(1, 1, 2, 3);

    /* 4 Set the read and clear enable */
    SFTCR(Gsu4Adcc[0]) = 0x10U;
    SFTCR(Gsu4Adcc[1]) = 0x10U;

    /* 5 Enable the output of the scan group x end interrupt signal ADInx */
    SGCR(Gsu4Adcc[1], 0) |= 0x10U;
   // SGCR(Gsu4Adcc[1], 0) = 0x10U;
    //SGCR(Gsu4Adcc[1], 1) = 0x10U;

    /* 6 Start SCAN GROUP Control */
   // R_ADC_ScanGroup_Start(0, 0);
    
   // R_ADC_ScanGroup_Start(1, 0);
    //R_ADC_ScanGroup_Start(1, 1);
	init_adc_int();
}

void R_Drv_ADC_ScanGroup_OperationOn(uint8 Pu1ADC, uint8 Pu1SGNum)
{
    R_ADC_ScanGroup_Start(Pu1ADC, Pu1SGNum);
}



void R_Drv_ADC_UpdateValue(uint8 Pu1ADC, uint8 Pu1SGNum)
{
	
    switch (Pu1SGNum)
    {
    case 0:
        {
            uint32 Lu4ADC_DR0 = DR(Gsu4Adcc[0], 0);
	    uint32 Lu4ADC_DR2 = DR(Gsu4Adcc[0], 1);
	    uint32 Lu4ADC_DR3 = DR(Gsu4Adcc[0], 2);
	    
            Gu1ReadAdcValue[0] = (uint16)Lu4ADC_DR0>>3;
            Gu1ReadAdcValue[1] = (uint16)(Lu4ADC_DR0>>16)>>3;
	    Gu1ReadAdcValue[4] = (uint16)Lu4ADC_DR2>>3;
            Gu1ReadAdcValue[5] = (uint16)(Lu4ADC_DR2>>16)>>3;
	    Gu1ReadAdcValue[6] = (uint16)(Lu4ADC_DR3>>3);
          
        }
        break;
       case 1:
        {
	     uint32 Lu4ADC_DR1 = DR(Gsu4Adcc[1], 0);
	     uint32 Lu4ADC_DR4 = DR(Gsu4Adcc[1], 1);
	     uint32 Lu4ADC_DR5 = DR(Gsu4Adcc[1], 2);
	     uint32 Lu4ADC_DR6 = DR(Gsu4Adcc[1], 3);
	     Gu1ReadAdcValue[2] = (uint16)Lu4ADC_DR1>>3;
            Gu1ReadAdcValue[3] = (uint16)(Lu4ADC_DR1>>16)>>3;
	     Gu1ReadAdcValue[7] = (uint16)Lu4ADC_DR4>>3;
            Gu1ReadAdcValue[8] = (uint16)(Lu4ADC_DR4>>16)>>3;
	     Gu1ReadAdcValue[9] = (uint16)Lu4ADC_DR5>>3;
            Gu1ReadAdcValue[10] = (uint16)(Lu4ADC_DR5>>16)>>3;
	     Gu1ReadAdcValue[11] = (uint16)Lu4ADC_DR6>>3;
            Gu1ReadAdcValue[12] = (uint16)(Lu4ADC_DR6>>16)>>3;
	    
          
        }
        break;
	
	
    
    default:
        break;
    }
}

void R_Drv_ADC_diagnostic_test(void)
{
	R_ADC_diagnostic_Init(Pull_Up);
	R_Drv_ADC_ScanGroup_OperationOn(0, 0);
	while(ADCF0.SGSR0)
	{
	  ;
	}
        R_Drv_ADC_UpdateValue(0, 0);
	R_ADC_diagnostic_Init(Pull_Down);
	R_Drv_ADC_ScanGroup_OperationOn(0, 0);
        while(ADCF0.SGSR0)
	{
	  ;
	}
        R_Drv_ADC_UpdateValue(0, 0);
}

void R_ADC_test(void)
{
	//R_Drv_ADC_ScanGroup_OperationOn(0, 0);
        while( ADCF0.SGSR0 & flag_adc)
	{
	  ;
	}
        R_Drv_ADC_UpdateValue(0, 0);
	//R_ADC_ScanGroup_Start(1, 0);
	R_Drv_ADC_UpdateValue(0, 1);
	flag_adc = 1;
	 // P1 |= 0x0010;
         //P1 &= 0xEF;
}

#pragma interrupt R_ADCA0_error_interrupt(enable=false, channel=80, fpu=true, callt=false)
void R_ADCA0_error_interrupt(void)
{
    /* Start user code for r_Config_ADCA1_error_interrupt. Do not edit comment generated here */
    /* End user code. Do not edit comment generated here */
}

#pragma interrupt R_ADCA0_Group0_interrupt(enable=false, channel=167, fpu=true, callt=false)
void R_ADCA0_Group0_interrupt(void)
{
    /* Start user code for r_Config_ADCA1_error_interrupt. Do not edit comment generated here */
    R_ADC_test();
    /* End user code. Do not edit comment generated here */
}
/*****************************************************************************
--------------------- Static functions --------------------------------------
 *****************************************************************************/
