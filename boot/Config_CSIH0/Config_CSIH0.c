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

#include "Config_CSIH0.h"
/* Start user code for include. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
Global variables and functions
***********************************************************************************************************************/
extern volatile uint32_t g_cg_sync_read;
volatile uint16_t  g_csih0_tx_num;                         /* csih0 transmit data number */
volatile uint16_t  g_csih0_rx_num;                        /* csih0 receive data number */
volatile uint16_t  g_csih0_rx_total_num;                  /* csih0 receive data total times */
volatile uint16_t * gp_csih0_tx_address;                   /* csih0 transmit buffer address */
volatile uint16_t * gp_csih0_rx_address; 

enum 
{
	CSI_TRANSMISSION = 0,
	CSI_RECEPTION,
	CSI_RECEPTION_FLAG,
	CSI_TYPE_MAX
};

#define CSI_DATA_MAX 7
#define CSI_RECEIVE_OK (1)
#define CSI_RECEIVE_NG (0)
volatile	uint16_t	uint16_master[CSI_TYPE_MAX][CSI_DATA_MAX];
volatile	uint16_t	uint16_slave[CSI_TYPE_MAX][CSI_DATA_MAX];

/* csih0 receive buffer address */
/* Start user code for global. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
* Function Name: R_Config_CSIH0_Create
* Description  : This function initializes the Config_CSIH0 module.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/



void R_Config_CSIH0_Create(void)
{
     uint32_t tmp_port;

    CSIH0.CTL0.UINT8 = _CSIH_OPERATION_CLOCK_STOP;
    /* Disable INTCSIH0IC operation and clear request */
    //EIC88 |= _INT_PROCESSING_MASK  ;
    //EIC88 &= ~_INT_REQUEST_OCCUR_MASK  ;
    /* Disable INTCSIH0IR operation and clear request */
    //EIC87 |= _INT_PROCESSING_MASK ;
    //EIC87 &= ~_INT_REQUEST_OCCUR_MASK  ;
    /* Set CSIH0 interrupt(INTCSIH0IC) setting */
    //EIC88 |= _INT_TABLE_VECTOR_MASK ;
    //EIC88 |= _INT_PRIORITY_LOWEST ;
   
    /* Set CSIH0 interrupt(INTCSIH0IR) setting */
    //EIC87 |= _INT_TABLE_VECTOR_MASK ;
    //EIC87 |= _INT_PRIORITY_LOWEST ;
    /* Set CSIH0 control setting */
    CSIH0.CTL1 = _CSIH_CLOCK_INVERTING_HIGH | _CSIH_INTERRUPT_TIMING_NORMAL | _CSIH_DATA_CONSISTENCY_CHECK_DISABLE | 
                 _CSIH_NO_DELAY | _CSIH_CHIPSELECT0_ACTIVE_LOW | _CSIH_HANDSHAKE_DISABLE | 
                 _CSIH_CHIPSELECT_SIGNAL_HOLD_INACTIVE | _CSIH_SLAVE_SELECT_DISABLE|_CSIH_SYNCHRONIZATION_FALLING_EDGE;
    CSIH0.CTL2 = _CSIH0_SELECT_BASIC_CLOCK;
    CSIH0.BRS0 = _CSIH0_BAUD_RATE_0;
    CSIH0.BRS1 = _CSIH0_BAUD_RATE_1;
    CSIH0.BRS2 = _CSIH0_BAUD_RATE_2;
    CSIH0.BRS3 = _CSIH0_BAUD_RATE_3;
    /* Set CSIH0 configuration setting */
    CSIH0.CFG0 = _CSIH_USED_BAUDRATE_0 | _CSIH_PARITY_NO | _CSIH_DATA_DIRECTION_MSB | _CSIH_PHASE_SELECTION_TYPE1 | 
                 _CSIH_IDLE_INSERTED_NOT_ALWAYS | _CSIH_IDLE_TIME_0 | _CSIH_HOLD_TIME_0 | 
                 _CSIH_INTER_DATA_DELAY_TIME_1 | _CSIH_SETUP_TIME_0;
    /* Synchronization processing */
    g_cg_sync_read = CSIH0.CTL1;
    __syncp();
    /* Set CSIH0SCO pin */
    PIBC5 &= _PORT_CLEAR_BIT6;
    PBDC5 &= _PORT_CLEAR_BIT6;
    PM5 |= _PORT_SET_BIT6;
    PMC5 &= _PORT_CLEAR_BIT6;
    PIPC5 &= _PORT_CLEAR_BIT6;
    //替代输出模式3
    tmp_port = PDSC5;
    PDSC5 = (tmp_port | _PORT_SET_BIT6);
    PFC5 |= _PORT_SET_BIT6;
    PFCE5 &= _PORT_CLEAR_BIT6;
    PIPC5 |= _PORT_SET_BIT6;
    PMC5 |= _PORT_SET_BIT6;
    /* Set CSIH0SO pin */
    PIBC5 &= _PORT_CLEAR_BIT5;
    PBDC5 &= _PORT_CLEAR_BIT5;
    PM5 |= _PORT_SET_BIT5;
    PMC5 &= _PORT_CLEAR_BIT5;
    PIPC5 &= _PORT_CLEAR_BIT5;
    tmp_port = PDSC5;
    PDSC5 = (tmp_port | _PORT_SET_BIT5);
    PFC5 |= _PORT_SET_BIT5;
    PFCE5 &= _PORT_CLEAR_BIT5;
    PIPC5 |= _PORT_SET_BIT5;
    PMC5 |= _PORT_SET_BIT5;
    /* Set CSIH0SI pin */
    PIBC2 &= _PORT_CLEAR_BIT11;
    PBDC2 &= _PORT_CLEAR_BIT11;
    PM2 |= _PORT_SET_BIT11;  
    PMC2 &= _PORT_CLEAR_BIT11;
    PFC2 &= _PORT_CLEAR_BIT11;
    PFCE2 |= _PORT_SET_BIT11;
    PMC2 |= _PORT_SET_BIT11; 
    /* Set CSIH2CSS0 pin */
    PIBC5 &= _PORT_CLEAR_BIT4;
    PBDC5 &= _PORT_CLEAR_BIT4;
    PM5 |= _PORT_SET_BIT4;
    PMC5 &= _PORT_CLEAR_BIT4;
    PFC5 |= _PORT_SET_BIT4;
    PFCE5 &= _PORT_CLEAR_BIT4;
    PMC5 |= _PORT_SET_BIT4;
    PM5 &= _PORT_CLEAR_BIT4;

    //R_Config_CSIH0_Create_UserInit();
}


/***********************************************************************************************************************
* Function Name: R_Config_CSIH0_Start
* Description  : This function starts the Config_CSIH0 module operation.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_Config_CSIH0_Start(void)
{
    /* Enable CSIH0 operation */
    
    CSIH0.CTL0.UINT8 = _CSIH_OPERATION_CLOCK_PROVIDE | _CSIH_TRANSMISSION_PERMIT | _CSIH_RECEPTION_PERMIT | 
                 _CSIH_DIRECTACCESS;
    
    /* Clear CSIH0 interrupt request and enable operation */
    ////EIC87 &= ~_INT_REQUEST_OCCUR_MASK  ;
    ////EIC88 &= ~_INT_REQUEST_OCCUR_MASK  ;
    
    ////EIC87 &= ~_INT_PROCESSING_MASK  ;
   // //EIC88 &= ~_INT_PROCESSING_MASK  ;
    
}
/***********************************************************************************************************************
* Function Name: R_Config_CSIH2_Start
* Description  : This function starts the Config_CSIH2 module operation.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_Config_CSIH0_TransmissionStart(void)
{
    /* Enable CSIH0 operation */
    CSIH0.CTL0.UINT8 = _CSIH_OPERATION_CLOCK_PROVIDE | _CSIH_TRANSMISSION_PERMIT | _CSIH_RECEPTION_PROHIBIT | 
                 _CSIH_DIRECTACCESS;
    /* Clear CSIH0 interrupt request and enable operation */
    ////EIC87 &= ~_INT_REQUEST_OCCUR_MASK  ;
   // //EIC88 &= ~_INT_REQUEST_OCCUR_MASK  ;
    
    ////EIC87 |= _INT_PROCESSING_MASK  ;
    ////EIC88 &= ~_INT_PROCESSING_MASK  ;
  

}
/***********************************************************************************************************************
* Function Name: R_Config_CSIH2_Start
* Description  : This function starts the Config_CSIH2 module operation.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_Config_CSIH0_ReceptionStart(void)
{
    /* Enable CSIH0 operation */
    CSIH0.CTL0.UINT8 = _CSIH_OPERATION_CLOCK_PROVIDE | _CSIH_TRANSMISSION_PROHIBIT | _CSIH_RECEPTION_PERMIT | 
                 _CSIH_DIRECTACCESS;
    /* Clear CSIH0 interrupt request and enable operation */
    ////EIC87 &= ~_INT_REQUEST_OCCUR_MASK  ;
    ////EIC88 &= ~_INT_REQUEST_OCCUR_MASK  ;
   
    /* Disable INTCSIH0IR operation and clear request */
   // //EIC87 &= ~_INT_PROCESSING_MASK  ;
   // //EIC88 |= _INT_PROCESSING_MASK  ;

}
/***********************************************************************************************************************
* Function Name: R_Config_CSIH0_Stop
* Description  : This function stops the CSIH0 module operation.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_Config_CSIH0_Stop(void)
{
    /* Disable CSIH0 interrupt operation */
   // //EIC88 |= _INT_PROCESSING_MASK  ;
    /* Disable CSIH0 operation */
    CSIH0.CTL0.UINT8 &= (uint8_t) ~_CSIH_TRANSMISSION_PERMIT;
    CSIH0.CTL0.UINT8 &= (uint8_t) ~_CSIH_OPERATION_CLOCK_PROVIDE;
    /* Synchronization processing */
    g_cg_sync_read = CSIH0.CTL0.UINT8;
    __syncp();
    /* Clear CSIH0 interrupt operation */
   // //EIC88 &= ~_INT_REQUEST_OCCUR_MASK  ;
    /* Synchronization processing */
   // g_cg_sync_read = //EIC88;
    __syncp();
}
/***********************************************************************************************************************
* Function Name: R_CSIH0_Slave_Receive
* Description  : This function receives CSIH0 data.
* Arguments    : rx_buf -
*                    receive buffer pointer
*                rx_num -
*                    buffer size
* Return Value : status -
*                    MD_OK or MD_ARGERROR
***********************************************************************************************************************/
MD_STATUS R_CSIH0_Slave_Receive(uint16_t* rx_buf, uint16_t rx_num)
{
    MD_STATUS status = MD_OK;
    if (rx_num < 1U)
    {
        status = MD_ARGERROR;
    }
    else
    {
        g_csih0_rx_total_num = rx_num;
        gp_csih0_rx_address = rx_buf;
        g_csih0_tx_num = 0U; 
    }

    return (status);
}
/***********************************************************************************************************************
* Function Name: R_Config_CSIH0_Send
* Description  : This function sends CSIH0 data.
* Arguments    : tx_buf -
*                    send buffer pointer
*                tx_num -
*                    buffer size
* Return Value : status -
***********************************************************************************************************************/
MD_STATUS R_CSIH0_Slave_Send(uint16_t* const tx_buf, uint16_t tx_num)
{
    MD_STATUS status = MD_OK;
    uint32_t regValue = _CSIH0_SETTING_INIT;

    if (tx_num < 1U)
    {
        status = MD_ARGERROR;
    }
    else
    {
        /* Set transmit setting */
        gp_csih0_tx_address = tx_buf;
        g_csih0_tx_num = tx_num;
        regValue |= *gp_csih0_tx_address;
        /* Disable CSIH0 interrupt operation */
	////EIC88 |= _INT_PROCESSING_MASK  ;
        /* Synchronization processing */
       // g_cg_sync_read = //EIC88;
        __syncp();
        /* Set transmit data */
        CSIH0.TX0W = regValue;
        gp_csih0_tx_address++;
        g_csih0_tx_num--;
        /* Synchronization processing */
        g_cg_sync_read = CSIH0.CTL1;
        __syncp();
        /* Enable CSIH0 interrupt operation */
       // //EIC88 &= ~_INT_PROCESSING_MASK  ;
        /* Synchronization processing */
       // g_cg_sync_read =  //EIC88 ;
        __syncp();
    }

    return status;
}

MD_STATUS R_CSIH0_Master_Send(uint16_t* const tx_buf, uint16_t tx_num, uint32_t chip_id,uint16_t* const rx_buf)
{
	int i,j;
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
        gp_csih0_tx_address = tx_buf;
        g_csih0_tx_num = tx_num;
        regValue |= *gp_csih0_tx_address;
	EIC88 |= _INT_PROCESSING_MASK  ;
        /* Disable CSIH2 interrupt operation */
        //EIC88 |= _INT_PROCESSING_MASK  ;
        /* Synchronization processing */
        //g_cg_sync_read = //EIC88;
        __syncp();
        /* Set transmit data */
        CSIH0.TX0W = regValue;
	//PPR5 = 0x2000;
	//while(!(EIC88&(_PORT_SET_BIT12)==_PORT_SET_BIT12));
	//EIC88 &=_PORT_CLEAR_BIT12;
	for(i=0;i<3000;i++)
	{
		for(j=0;j<10;j++);
	}
	//while(!(EIC87&(_PORT_SET_BIT12)==_PORT_SET_BIT12));
	gp_csih0_rx_address = rx_buf;
	*gp_csih0_rx_address = CSIH0.RX0W;
	EIC87 &=_PORT_CLEAR_BIT12;
        //gp_csih0_tx_address++;
       // g_csih0_tx_num--;
        /* Synchronization processing */
        //g_cg_sync_read = CSIH0.CTL1;
       // __syncp();
        /* Enable CSIH2 interrupt operation */
        //EIC88 &= ~_INT_PROCESSING_MASK  ;
        /* Synchronization processing */
       // g_cg_sync_read = //EIC88;
      // while(!(EIC88&(_PORT_SET_BIT12)==_PORT_SET_BIT12));
      // EIC88 &=_PORT_CLEAR_BIT12;
       // __syncp();
      // while(!(EIC88&(_PORT_SET_BIT12)==_PORT_SET_BIT12));
       // EIC88 &=_PORT_CLEAR_BIT12;
	//while(!(EIC87&(_PORT_SET_BIT12)==_PORT_SET_BIT12));
      //  EIC87 &=_PORT_CLEAR_BIT12;
    }

    return status;
}

MD_STATUS R_CSIH0_Master_Receive(uint16_t* rx_buf, uint16_t rx_num, uint32_t chip_id)
{
    MD_STATUS status = MD_OK;
    uint32_t regValue = _CSIH_RECEIVE_SETTING_INIT;
    //CSIH0.STCR0 |= (_CSIH_CONSISTENCY_ERROR_CLEAR | _CSIH_PARITY_ERROR_CLEAR | _CSIH_OVERRUN_ERROR_CLEAR | _CSIH_FIFO_ERROR_CLEAR);
    {
        /* Set select chip id */
        regValue &= ~(chip_id);
        CSIH0.TX0W = regValue; 
        /* Set receive setting */
        gp_csih0_rx_address = rx_buf;
        g_csih0_rx_total_num = rx_num; 
        g_csih0_rx_num = 0U;
	*gp_csih0_rx_address = CSIH0.RX0W;
	
	//while(!(EIC87&(_PORT_SET_BIT12)==_PORT_SET_BIT12));
       //EIC87 &=_PORT_CLEAR_BIT12;
    }

    return (status);
}

void A4911_Config(void)
{
	uint8_t i,j;
	R_Config_CSIH0_Create();
	
	for(i=0;i<CSI_TYPE_MAX;i++)
	{
		for(j=0;j<CSI_DATA_MAX;j++)
		{
			uint16_master[i][j] = 0;
			uint16_slave[i][j] = 0;
		}
	}
	
	R_Config_CSIH0_Start();
	
	uint16_master[CSI_TRANSMISSION][0] = 0x3D65;
	R_CSIH0_Master_Send((uint16_t*)&uint16_master[CSI_TRANSMISSION][0], CSI_DATA_MAX, _CSIH_SELECT_CHIP_0,(uint16_t*)&uint16_master[CSI_RECEPTION][0]);
	uint16_master[CSI_TRANSMISSION][0] = 0x3D65;
	R_CSIH0_Master_Send((uint16_t*)&uint16_master[CSI_TRANSMISSION][0], CSI_DATA_MAX, _CSIH_SELECT_CHIP_0,(uint16_t*)&uint16_master[CSI_RECEPTION][0]);
	uint16_master[CSI_TRANSMISSION][0] = 0x3D65;
	R_CSIH0_Master_Send((uint16_t*)&uint16_master[CSI_TRANSMISSION][0], CSI_DATA_MAX, _CSIH_SELECT_CHIP_0,(uint16_t*)&uint16_master[CSI_RECEPTION][0]);
	//uint16_master[CSI_TRANSMISSION][0] = 0x3D65; 
	uint16_master[CSI_TRANSMISSION][1] = 0x3964;
	R_CSIH0_Master_Send((uint16_t*)&uint16_master[CSI_TRANSMISSION][1], CSI_DATA_MAX, _CSIH_SELECT_CHIP_0,(uint16_t*)&uint16_master[CSI_RECEPTION][1]);
	//uint16_master[CSI_TRANSMISSION][0] = 0x3D65; 
	uint16_master[CSI_TRANSMISSION][2] = 0xE000;
	R_CSIH0_Master_Send((uint16_t*)&uint16_master[CSI_TRANSMISSION][2], CSI_DATA_MAX, _CSIH_SELECT_CHIP_0,(uint16_t*)&uint16_master[CSI_RECEPTION][2]);
	//uint16_master[CSI_TRANSMISSION][0] = 0x3D65; 
	uint16_master[CSI_TRANSMISSION][3] = 0xE801;
	R_CSIH0_Master_Send((uint16_t*)&uint16_master[CSI_TRANSMISSION][3], CSI_DATA_MAX, _CSIH_SELECT_CHIP_0,(uint16_t*)&uint16_master[CSI_RECEPTION][3]);
	//uint16_master[CSI_TRANSMISSION][0] = 0x3D65; 
	uint16_master[CSI_TRANSMISSION][4] = 0xF001;
	R_CSIH0_Master_Send((uint16_t*)&uint16_master[CSI_TRANSMISSION][4], CSI_DATA_MAX, _CSIH_SELECT_CHIP_0,(uint16_t*)&uint16_master[CSI_RECEPTION][4]);
	//uint16_master[CSI_TRANSMISSION][0] = 0x3D65; 
	R_Config_CSIH0_Stop();
	 
}

/* Start user code for adding. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
