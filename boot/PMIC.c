/***********************************************************************************************************************
* DISCLAIMER
* This software is supplied by Renesas Electronics Corporation and is only intended for use with Renesas products.
* No other uses are authorized. This software is owned by Renesas Electronics Corporation and is protected under all
* applicable laws, including copyright laws. 
* THIS SOFTWARE IS PROVIDED "AS IS" AND RENESAS MAKES NO WARRANTIES REGARDING THIS SOFTWARE, WHETHER EXPRESS, IMPLIED
* OR STATUTORY, INCLUDING BUT NOT LIMITED TO WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
* NON-INFRINGEMENT.  ALL SUCH WARRANTIES ARE EXPRESSLY DISCLAIMED.TO THE MAXIMUM EXTENT PERMITTED NOT PROHIBITED BY
* LAW, NEITHER RENESAS ELECTRONICS CORPORATION NOR ANY OF ITS AFFILIATED COMPANIES SHALL BE LIABLE FOR ANY DIRECT,
* INDIRECT, SPECIAL, INCIDENTAL OR CONSEQUENTIAL DAMAGES FOR ANY REASON RELATED TO THIS SOFTWARE, EVEN IF RENESAS OR
* ITS AFFILIATES HAVE BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGES.
* Renesas reserves the right, without notice, to make changes to this software and to discontinue the availability 
* of this software. By using this software, you agree to the additional terms and conditions found by accessing the 
* following link:
* http://www.renesas.com/disclaimer
*
* Copyright (C) 2019 Renesas Electronics Corporation. All rights reserved.
***********************************************************************************************************************/

/***********************************************************************************************************************
* File Name    : Config_CSIH0.c
* Version      : 1.2.0
* Device(s)    : R7F701649
* Description  : This file implements device driver for Config_CSIH0.
***********************************************************************************************************************/
/***********************************************************************************************************************
Pragma directive
***********************************************************************************************************************/
/* Start user code for pragma. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
Includes
***********************************************************************************************************************/
#include "tmr_macrodriver.h"

#include "PMIC.h"
/* Start user code for include. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
Global variables and functions
***********************************************************************************************************************/
extern volatile uint32_t g_cg_sync_read;
volatile uint16_t  g_csih2_tx_num;                         /* csih0 transmit data number */
volatile uint16_t  g_csih2_rx_num;                        /* csih0 receive data number */
volatile uint16_t  g_csih2_rx_total_num;                  /* csih0 receive data total times */
volatile uint16_t * gp_csih2_tx_address;                   /* csih0 transmit buffer address */
volatile uint16_t * gp_csih2_rx_address; 

enum 
{
	CSI_TRANSMISSION = 0,
	CSI_RECEPTION,
	CSI_RECEPTION_FLAG,
	CSI_TYPE_MAX
};

#define CSI_DATA_MAX 10
#define CSI_RECEIVE_OK (1)
#define CSI_RECEIVE_NG (0)
extern volatile	uint16_t	uint16_master[CSI_TYPE_MAX][CSI_DATA_MAX];
extern volatile	uint16_t	uint16_slave[CSI_TYPE_MAX][CSI_DATA_MAX];

/* csih0 receive buffer address */
/* Start user code for global. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
* Function Name: R_Config_CSIH0_Create
* Description  : This function initializes the Config_CSIH0 module.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/



void R_Config_CSIH2_Create(void)
{
    
    CSIH2.CTL0.UINT8 = _CSIH_OPERATION_CLOCK_STOP;

    CSIH2.CTL1 = _CSIH_CLOCK_INVERTING_LOW | _CSIH_INTERRUPT_TIMING_NORMAL | _CSIH_DATA_CONSISTENCY_CHECK_DISABLE | 
                 _CSIH_NO_DELAY | _CSIH_CHIPSELECT0_ACTIVE_LOW | _CSIH_HANDSHAKE_DISABLE | 
                 _CSIH_CHIPSELECT_SIGNAL_HOLD_INACTIVE | _CSIH_SLAVE_SELECT_DISABLE|_CSIH_SYNCHRONIZATION_RISING_EDGE;
    CSIH2.CTL2 = 0x0008;
    CSIH2.BRS0 = 0x0023;
    CSIH2.BRS1 = _CSIH0_BAUD_RATE_1;
    CSIH2.BRS2 = _CSIH0_BAUD_RATE_2;
    CSIH2.BRS3 = _CSIH0_BAUD_RATE_3;
    /* Set CSIH0 configuration setting */
    CSIH2.CFG1 = _CSIH_USED_BAUDRATE_0 | _CSIH_PARITY_NO | _CSIH_DATA_DIRECTION_MSB | _CSIH_PHASE_SELECTION_TYPE3 | 
                 _CSIH_IDLE_INSERTED_NOT_ALWAYS | _CSIH_IDLE_TIME_0 | _CSIH_HOLD_TIME_0 | 
                 _CSIH_INTER_DATA_DELAY_TIME_1 | _CSIH_SETUP_TIME_0;
    /* Synchronization processing */
     /* Set CSIH1SCO pin */
    PIBC5 &= _PORT_CLEAR_BIT7;
    PBDC5 &= _PORT_CLEAR_BIT7;
    PM5 &= _PORT_CLEAR_BIT7;
    PFC5 |= _PORT_SET_BIT7;
    PFCE5 |= _PORT_SET_BIT7;
    PMC5 |= _PORT_SET_BIT7;
    /* Set CSIH1SO pin */
    PIBC2 &= _PORT_CLEAR_BIT1;
    PBDC2 &= _PORT_CLEAR_BIT1;
    PFC2 &= _PORT_CLEAR_BIT1;
    PFCE2 |= _PORT_SET_BIT1;
    PIPC2 |= _PORT_SET_BIT1;
    PMC2 |= _PORT_SET_BIT1;
    /* Set CSIH1SI pin */
    PIBC2 &= _PORT_CLEAR_BIT3;
    PBDC2 &= _PORT_CLEAR_BIT3;
    PM2 |= _PORT_SET_BIT3;  
    PFC2 &= _PORT_CLEAR_BIT3;
    PFCE2 |= _PORT_SET_BIT3;
    PMC2 |= _PORT_SET_BIT3; 
    PD2 |= _PORT_SET_BIT3;
    /* Set csih1CSS0 pin */
    PIBC2 &= _PORT_CLEAR_BIT2;
    PBDC2 &= _PORT_CLEAR_BIT2;
    PFC2 |= _PORT_SET_BIT2;
    PFCE2 &= _PORT_CLEAR_BIT2;
    PMC2 |= _PORT_SET_BIT2;
    PM2 &= _PORT_CLEAR_BIT2;

    //R_Config_CSIH0_Create_UserInit();
}


/***********************************************************************************************************************
* Function Name: R_Config_CSIH0_Start
* Description  : This function starts the Config_CSIH0 module operation.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_Config_CSIH2_Start(void)
{
    /* Enable CSIH0 operation */
    
    CSIH2.CTL0.UINT8 = _CSIH_OPERATION_CLOCK_PROVIDE | _CSIH_TRANSMISSION_PERMIT | _CSIH_RECEPTION_PERMIT | 
                 _CSIH_DIRECTACCESS;
    
    
}


/***********************************************************************************************************************
* Function Name: R_Config_CSIH0_Stop
* Description  : This function stops the CSIH0 module operation.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_Config_CSIH2_Stop(void)
{
  /* Disable CSIH0 interrupt operation */
   // //EIC88 |= _INT_PROCESSING_MASK  ;
    /* Disable CSIH0 operation */
    CSIH2.CTL0.UINT8 &= (uint8_t) ~_CSIH_TRANSMISSION_PERMIT;
    CSIH2.CTL0.UINT8 &= (uint8_t) ~_CSIH_OPERATION_CLOCK_PROVIDE;
    /* Synchronization processing */
    //g_cg_sync_read = CSIH2.CTL0.UINT8;
    __syncp();
    /* Clear CSIH0 interrupt operation */
   // //EIC88 &= ~_INT_REQUEST_OCCUR_MASK  ;
    /* Synchronization processing */
   // g_cg_sync_read = //EIC88;
    __syncp();
}


MD_STATUS R_CSIH2_Master_Send(uint16_t* const tx_buf, uint16_t tx_num, uint32_t chip_id,uint16_t* const rx_buf)
{
//	int i,j;
    MD_STATUS status = MD_OK;
    uint32_t regValue = _CSIH0_SETTING_INIT;
    if ((tx_num < 1U) )
    {
        status = MD_ARGERROR;
    }
    else
    {
        /* Set select chip id */
        regValue &= ~(chip_id);
        /* Set transmit setting */
        gp_csih2_tx_address = tx_buf;
        g_csih2_tx_num = tx_num;
        regValue |= *gp_csih2_tx_address;
	//EIC88 |= _INT_PROCESSING_MASK  ;
        /* Disable CSIH2 interrupt operation */
        //EIC88 |= _INT_PROCESSING_MASK  ;
        /* Synchronization processing */
        //g_cg_sync_read = //EIC88;
        __syncp();
        /* Set transmit data */
        CSIH2.TX0W = regValue;
	gp_csih2_rx_address = rx_buf;
	*gp_csih2_rx_address = CSIH2.RX0W;
	__syncp();
	*gp_csih2_rx_address = CSIH2.RX0W;
	while(!(CSIH2.STR0==0x00000010));
    }

    return status;
}


void PMIC_normalConfig(void)
{
	R_Config_CSIH2_Start();
	//normal
	uint16_master[CSI_TRANSMISSION][2] = 0xABD5;
	R_CSIH2_Master_Send((uint16_t*)&uint16_master[CSI_TRANSMISSION][2], CSI_DATA_MAX, _CSIH_SELECT_CHIP_1,(uint16_t*)&uint16_master[CSI_RECEPTION][2]);
	uint16_master[CSI_TRANSMISSION][2] = 0xAC2B;
	R_CSIH2_Master_Send((uint16_t*)&uint16_master[CSI_TRANSMISSION][2], CSI_DATA_MAX, _CSIH_SELECT_CHIP_1,(uint16_t*)&uint16_master[CSI_RECEPTION][2]);
	R_Config_CSIH2_Stop();
	
}

void PMIC_sleepConfig(void)
{
	R_Config_CSIH2_Start();
	//sleep
	uint16_master[CSI_TRANSMISSION][2] = 0xAA05;
	R_CSIH2_Master_Send((uint16_t*)&uint16_master[CSI_TRANSMISSION][2], CSI_DATA_MAX, _CSIH_SELECT_CHIP_1,(uint16_t*)&uint16_master[CSI_RECEPTION][2]);
	uint16_master[CSI_TRANSMISSION][2] = 0xADFB;
	R_CSIH2_Master_Send((uint16_t*)&uint16_master[CSI_TRANSMISSION][2], CSI_DATA_MAX, _CSIH_SELECT_CHIP_1,(uint16_t*)&uint16_master[CSI_RECEPTION][2]);
	
	
	
	uint16_master[CSI_TRANSMISSION][2] = 0xAA06;
	R_CSIH2_Master_Send((uint16_t*)&uint16_master[CSI_TRANSMISSION][2], CSI_DATA_MAX, _CSIH_SELECT_CHIP_1,(uint16_t*)&uint16_master[CSI_RECEPTION][2]);
	uint16_master[CSI_TRANSMISSION][2] = 0xADF8;
	R_CSIH2_Master_Send((uint16_t*)&uint16_master[CSI_TRANSMISSION][2], CSI_DATA_MAX, _CSIH_SELECT_CHIP_1,(uint16_t*)&uint16_master[CSI_RECEPTION][2]);
	R_Config_CSIH2_Stop();
}

void PMIC_standbyConfig(void)
{
	uint8_t i,j;
	uint8_t m,n;
	R_Config_CSIH2_Start();
	for(i=0;i<CSI_TYPE_MAX;i++)
	{
		for(j=0;j<CSI_DATA_MAX;j++)
		{
			uint16_master[i][j] = 0;
			uint16_slave[i][j] = 0;
		}
	}
	//stanby
	
	uint16_master[CSI_TRANSMISSION][2] = 0xAA05;
	R_CSIH2_Master_Send((uint16_t*)&uint16_master[CSI_TRANSMISSION][2], CSI_DATA_MAX, _CSIH_SELECT_CHIP_1,(uint16_t*)&uint16_master[CSI_RECEPTION][2]);
	uint16_master[CSI_TRANSMISSION][2] = 0xADFB;
	R_CSIH2_Master_Send((uint16_t*)&uint16_master[CSI_TRANSMISSION][2], CSI_DATA_MAX, _CSIH_SELECT_CHIP_1,(uint16_t*)&uint16_master[CSI_RECEPTION][2]);
	
		//delay
	for(m=0;m<20;m++)
	{
	for(n=0;n<55;n++)
	{
	;
	}
	}
	
	uint16_master[CSI_TRANSMISSION][2] = 0xAA09;
	R_CSIH2_Master_Send((uint16_t*)&uint16_master[CSI_TRANSMISSION][2], CSI_DATA_MAX, _CSIH_SELECT_CHIP_1,(uint16_t*)&uint16_master[CSI_RECEPTION][2]);
	uint16_master[CSI_TRANSMISSION][2] = 0xADF7;
	R_CSIH2_Master_Send((uint16_t*)&uint16_master[CSI_TRANSMISSION][2], CSI_DATA_MAX, _CSIH_SELECT_CHIP_1,(uint16_t*)&uint16_master[CSI_RECEPTION][2]);
	
	R_Config_CSIH2_Stop();
}


void Init_PMIC_Config(void)
{
	uint8_t i,j;
	uint8_t m,n;
	R_Config_CSIH2_Create();
	
	for(i=0;i<CSI_TYPE_MAX;i++)
	{
		for(j=0;j<CSI_DATA_MAX;j++)
		{
			uint16_master[i][j] = 0;
			uint16_slave[i][j] = 0;
		}
	}
	
	R_Config_CSIH2_Start();
	
	//unlock and wrtie to protected register
	{
	uint16_master[CSI_TRANSMISSION][0] = 0x8756;
	R_CSIH2_Master_Send((uint16_t*)&uint16_master[CSI_TRANSMISSION][0], CSI_DATA_MAX, _CSIH_SELECT_CHIP_1,(uint16_t*)&uint16_master[CSI_RECEPTION][0]);
	uint16_master[CSI_TRANSMISSION][1] = 0x87DE;
	R_CSIH2_Master_Send((uint16_t*)&uint16_master[CSI_TRANSMISSION][1], CSI_DATA_MAX, _CSIH_SELECT_CHIP_1,(uint16_t*)&uint16_master[CSI_RECEPTION][1]);
	uint16_master[CSI_TRANSMISSION][2] = 0x86AD;
	R_CSIH2_Master_Send((uint16_t*)&uint16_master[CSI_TRANSMISSION][2], CSI_DATA_MAX, _CSIH_SELECT_CHIP_1,(uint16_t*)&uint16_master[CSI_RECEPTION][2]);
	uint16_master[CSI_TRANSMISSION][2] = 0x8625;
	R_CSIH2_Master_Send((uint16_t*)&uint16_master[CSI_TRANSMISSION][2], CSI_DATA_MAX, _CSIH_SELECT_CHIP_1,(uint16_t*)&uint16_master[CSI_RECEPTION][2]);
	
	uint16_master[CSI_TRANSMISSION][0] = 0x8D27;
	R_CSIH2_Master_Send((uint16_t*)&uint16_master[CSI_TRANSMISSION][0], CSI_DATA_MAX, _CSIH_SELECT_CHIP_1,(uint16_t*)&uint16_master[CSI_RECEPTION][0]);
	uint16_master[CSI_TRANSMISSION][1] = 0x8A01;
	R_CSIH2_Master_Send((uint16_t*)&uint16_master[CSI_TRANSMISSION][1], CSI_DATA_MAX, _CSIH_SELECT_CHIP_1,(uint16_t*)&uint16_master[CSI_RECEPTION][1]);

	uint16_master[CSI_TRANSMISSION][0] = 0x87BE;
	R_CSIH2_Master_Send((uint16_t*)&uint16_master[CSI_TRANSMISSION][0], CSI_DATA_MAX, _CSIH_SELECT_CHIP_1,(uint16_t*)&uint16_master[CSI_RECEPTION][0]);
	uint16_master[CSI_TRANSMISSION][1] = 0x8668;
	R_CSIH2_Master_Send((uint16_t*)&uint16_master[CSI_TRANSMISSION][1], CSI_DATA_MAX, _CSIH_SELECT_CHIP_1,(uint16_t*)&uint16_master[CSI_RECEPTION][1]);
	uint16_master[CSI_TRANSMISSION][2] = 0x877D;
	R_CSIH2_Master_Send((uint16_t*)&uint16_master[CSI_TRANSMISSION][2], CSI_DATA_MAX, _CSIH_SELECT_CHIP_1,(uint16_t*)&uint16_master[CSI_RECEPTION][2]);
	uint16_master[CSI_TRANSMISSION][2] = 0x8795;
	R_CSIH2_Master_Send((uint16_t*)&uint16_master[CSI_TRANSMISSION][2], CSI_DATA_MAX, _CSIH_SELECT_CHIP_1,(uint16_t*)&uint16_master[CSI_RECEPTION][2]);
		
	uint16_master[CSI_TRANSMISSION][2] = 0xBA7F;
	R_CSIH2_Master_Send((uint16_t*)&uint16_master[CSI_TRANSMISSION][2], CSI_DATA_MAX, _CSIH_SELECT_CHIP_1,(uint16_t*)&uint16_master[CSI_RECEPTION][2]);
	
	//delay
	for(m=0;m<20;m++)
	{
	for(n=0;n<55;n++)
	{
	;
	}
	}
	
	//normal		
	
	}
	
	 R_Config_CSIH2_Stop();
	 
}



/* Start user code for adding. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
