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
* File Name    : Config_CSIH1.c
* Version      : 1.2.0
* Device(s)    : R7F701649
* Description  : This file implements device driver for Config_CSIH1.
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

#include "tmr.h"
/* Start user code for include. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
Global variables and functions
***********************************************************************************************************************/
extern volatile uint32_t g_cg_sync_read;
volatile uint16_t  g_csih1_tx_num;                         /* CSIH1 transmit data number */
volatile uint8_t  g_csih1_tx_num8;
volatile uint16_t  g_csih1_rx_num;                        /* CSIH1 receive data number */
volatile uint16_t  g_csih1_rx_total_num=4;                  /* CSIH1 receive data total times */
volatile uint16_t * gp_csih1_tx_address;                   /* CSIH1 transmit buffer address */
volatile uint32_t g_cg_sync_read;
volatile uint16_t * gp_csih1_rx_address;                   /* CSIH1 receive buffer address */
volatile	uint16_t  send_data[4];
volatile	uint16_t  rx_data[4];

/* Start user code for global. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
* Function Name: R_Config_CSIH1_Create
* Description  : This function initializes the Config_CSIH1 module.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_Config_CSIH1_Create(void)
{
 

    CSIH1.CTL0.UINT8 = _CSIH_OPERATION_CLOCK_STOP;
    /* Disable INTCSIH1IC operation and clear request */
    EIC92 |= _INT_PROCESSING_MASK  ;   //0080
    EIC92 &= ~_INT_REQUEST_OCCUR_MASK  ;   //1000
    /* Disable INTCSIH1IR operation and clear request */
    EIC91 |= _INT_PROCESSING_MASK ;
    EIC91 &= ~_INT_REQUEST_OCCUR_MASK  ;
    /* Set CSIH1 interrupt(INTCSIH1IC) setting */
    EIC92 |= _INT_TABLE_VECTOR_MASK ;    //0040
    EIC92 |= _INT_PRIORITY_LOWEST ;      //00CF
   
    /* Set CSIH1 interrupt(INTCSIH1IR) setting */
    EIC91 |= _INT_TABLE_VECTOR_MASK ;
    EIC91 |= _INT_PRIORITY_LOWEST ;
    /* Set CSIH1 control setting */
    CSIH1.CTL1 = _CSIH_CLOCK_INVERTING_LOW | _CSIH_INTERRUPT_TIMING_NORMAL | _CSIH_DATA_CONSISTENCY_CHECK_DISABLE | 
                 _CSIH_NO_DELAY | _CSIH_CHIPSELECT6_ACTIVE_LOW | _CSIH_HANDSHAKE_DISABLE | 
                 _CSIH_CHIPSELECT_SIGNAL_HOLD_INACTIVE | _CSIH_SLAVE_SELECT_DISABLE | _CSIH_SYNCHRONIZATION_FALLING_EDGE|0x00000080;
   
    //CSIH1.CTL1 =0x01020010;
    //CSIH1.CTL2 = _CSIH1_SELECT_BASIC_CLOCK;
    CSIH1.CTL2 =0x0000;
    //CSIH1.BRS0 = _CSIH1_BAUD_RATE_0;
    CSIH1.BRS0 =0x0008;
    CSIH1.BRS1 = _CSIH1_BAUD_RATE_1;
    CSIH1.BRS2 = _CSIH1_BAUD_RATE_2;
    CSIH1.BRS3 = _CSIH1_BAUD_RATE_3;
    /* Set CSIH1 configuration setting */
    CSIH1.CFG6 = _CSIH_USED_BAUDRATE_0 | _CSIH_PARITY_NO | _CSIH_DATA_DIRECTION_MSB | _CSIH_PHASE_SELECTION_TYPE3 | 
                 _CSIH_IDLE_INSERTED_NOT_ALWAYS | _CSIH_IDLE_TIME_0 | _CSIH_HOLD_TIME_0 | 
                 _CSIH_INTER_DATA_DELAY_TIME_0 | _CSIH_SETUP_TIME_0| _CSIH_DATA_LENGTH_8|0x10000000;
    //CSIH1.CFG0=0x08010010;
    /* Synchronization processing */
    CSIH1.MCTL1=0x0003007D;
    
    g_cg_sync_read = CSIH1.CTL1;
    __syncp();
    /* Set CSIH1SCO pin */
    PIBC4 &= _PORT_CLEAR_BIT3;
    PBDC4 &= _PORT_CLEAR_BIT3;
    PM4 &= _PORT_CLEAR_BIT3;
    PFC4 &= _PORT_CLEAR_BIT3;
    PFCE4 |= _PORT_SET_BIT3;
    PMC4 |= _PORT_SET_BIT3;
    /* Set CSIH1SO pin */
    PIBC4 &= _PORT_CLEAR_BIT2;
    PBDC4 &= _PORT_CLEAR_BIT2;
    PFC4 &= _PORT_CLEAR_BIT2;
    PFCE4 |= _PORT_SET_BIT2;
    PIPC4 |= _PORT_SET_BIT2;
    PMC4 |= _PORT_SET_BIT2;
    /* Set CSIH1SI pin */
    PIBC4 &= _PORT_CLEAR_BIT4;
    PBDC4 &= _PORT_CLEAR_BIT4;
    PM4 |= _PORT_SET_BIT4;  
    PFC4 &= _PORT_CLEAR_BIT4;
    PFCE4 |= _PORT_SET_BIT4;
    PMC4 |= _PORT_SET_BIT4; 
    PD4 |= _PORT_SET_BIT4;
    /* Set csih1CSS0 pin */
    PIBC6 &= _PORT_CLEAR_BIT0;
    PBDC6 &= _PORT_CLEAR_BIT0;
    PFC6 |= _PORT_SET_BIT0;
    PFCE6 |= _PORT_SET_BIT0;
    PMC6 |= _PORT_SET_BIT0;
    PM6 &= _PORT_CLEAR_BIT0;
   

    //R_Config_CSIH1_Create_UserInit();
}


/***********************************************************************************************************************
* Function Name: R_Config_CSIH1_Start
* Description  : This function starts the Config_CSIH1 module operation.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_Config_CSIH1_Start(void)
{
    /* Enable CSIH1 operation */
    CSIH1.CTL0.UINT8 = _CSIH_OPERATION_CLOCK_PROVIDE | _CSIH_TRANSMISSION_PERMIT | _CSIH_RECEPTION_PERMIT ;
    
    
                //| _CSIH_DIRECTACCESS;
    /* Clear CSIH1 interrupt request and enable operation */
    //EIC91 &= ~_INT_REQUEST_OCCUR_MASK  ;  //0x1000
    //EIC92 &= ~_INT_REQUEST_OCCUR_MASK  ;
    
    EIC91 &= ~_INT_PROCESSING_MASK  ;   //0x0080
    EIC91 &=0x0001;
    //EIC92 &= ~_INT_PROCESSING_MASK  ;
    
}
/***********************************************************************************************************************
* Function Name: R_Config_csih1_Start
* Description  : This function starts the Config_csih1 module operation.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void TMR_Init(void)
{
	R_Config_CSIH1_Create();
	R_Config_CSIH1_Start();
	send_data[0]=0x0500;
	send_data[1]=0x0000;
	send_data[2]=0x0000;
	send_data[3]=0x0000;
	
	rx_data[0]=0x0000;
	rx_data[1]=0x0000;
	rx_data[2]=0x0000;
	rx_data[3]=0x0000;
}

void R_CSIH1_Master_Send(uint16_t* const tx_buf, uint32_t chip_id,uint16_t* const rx_buf)
{ 
    //uint32_t regValue;
    //gp_csih1_tx_address = tx_buf;
    //gp_csih1_rx_address = rx_buf;
    
    /* Disable CSIH1 interrupt receive operation */
        //EIC91 |= _INT_PROCESSING_MASK  ;

        
	//while(!(CSIH1.STR0==0x00000010));
	

	//regValue=0x20FF0000;
	CSIH1.TX0W =0x20BF0000|tx_buf[0];
	CSIH1.TX0W =0x20BF0000|tx_buf[1];
	CSIH1.TX0W =0x00BF0000|tx_buf[2];
	//while(((CSIH1.STR0 &  0xFF000000)>>24)<126 );
	//while(!(CSIH1.STR0==0x00000010));
	//regValue &= ~(chip_id);
        /* Set transmit data */
        //regValue |= *gp_csih1_tx_address;
        

	//CSIH1.TX0W = regValue;
	//*gp_csih1_rx_address = CSIH1.RX0W;
        //while(!(CSIH1.STR0==0x00000010));
	//*gp_csih1_rx_address = CSIH1.RX0W;
	
	//datacount--;
	/* Enable CSIH1 interrupt receive operation */
        //EIC91 &= ~_INT_PROCESSING_MASK  ;
	
	
    

  
}

