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
* File Name    : Config_CSIH2_user.c
* Version      : 1.2.0
* Device(s)    : R7F701649
* Description  : This file implements device driver for Config_CSIH2.
***********************************************************************************************************************/
/***********************************************************************************************************************
Pragma directive
***********************************************************************************************************************/
/* Start user code for pragma. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
Includes
***********************************************************************************************************************/
#include "r_cg_macrodriver.h"
#include "r_cg_userdefine.h"
#include "Config_CSIH2.h"
/* Start user code for include. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
Global variables and functions
***********************************************************************************************************************/
extern volatile uint16_t  g_csih2_tx_num;                         /* csih2 transmit data number */
extern volatile uint16_t  g_csih2_rx_num;                        /* csih2 receive data number */
extern volatile uint16_t  g_csih2_rx_total_num;                  /* csih2 receive data total times */
extern volatile uint16_t * gp_csih2_tx_address;                   /* csih2 transmit buffer address */
extern volatile uint16_t * gp_csih2_rx_address;                   /* csih2 receive buffer address */

enum 
{
	CSI_TRANSMISSION = 0,
	CSI_RECEPTION,
	CSI_RECEPTION_FLAG,
	CSI_TYPE_MAX
};
#define CSI_RECEIVE_OK (1)
#define CSI_RECEIVE_NG (0)
#define CSI_DATA_MAX 4
extern volatile	uint16_t	uint16_master[CSI_TYPE_MAX][CSI_DATA_MAX];
/* Start user code for global. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
* Function Name: R_Config_CSIH2_Create_UserInit
* Description  : This function adds user code after initializing CSIH module
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_Config_CSIH2_Create_UserInit(void)
{
    /* Start user code for user init. Do not edit comment generated here */
    /* End user code. Do not edit comment generated here */
}
/***********************************************************************************************************************
* Function Name: r_csih0_callback_error
* Description  : This function is a callback function when TCSS0 reception error occurs.
* Arguments    : err_type -
*                    error type value
* Return Value : None
***********************************************************************************************************************/
static void r_csih2_callback_error(uint32_t err_type)
{
    /* Start user code. Do not edit comment generated here */
    /* End user code. Do not edit comment generated here */
}
/***********************************************************************************************************************
* Function Name: r_csih0_callback_receiveend
* Description  : This function is a callback function when TCSS0 finishes reception.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
static void r_csih2_callback_receiveend(void)
{
    /* Start user code. Do not edit comment generated here */
    /* set reception complete flag */
     uint16_master[CSI_RECEPTION_FLAG][0] = CSI_RECEIVE_OK;
    /* End user code. Do not edit comment generated here */
}
/***********************************************************************************************************************
* Function Name: r_csih2_interrupt_receive
* Description  : None
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
#pragma interrupt r_csih2_interrupt_receive(enable=false, channel=96, fpu=true, callt=false)
void r_csih2_interrupt_receive(void)
{
    uint8_t err_type;
    uint16_t temp;
    err_type = (CSIH2.STR0 & (_CSIH_CONSISTENCY_ERROR_DETECTED | _CSIH_PARITY_ERROR_DETECTED | _CSIH_OVERRUN_ERROR_DETECTED));
    CSIH2.STCR0 |= (_CSIH_CONSISTENCY_ERROR_CLEAR | _CSIH_PARITY_ERROR_CLEAR | _CSIH_OVERRUN_ERROR_CLEAR);
    if (err_type != 0U)
    {
        r_csih2_callback_error(err_type);
    }
    else
    {
        temp = g_csih2_rx_total_num;
        if (temp > g_csih2_rx_num)
        {
            *gp_csih2_rx_address = CSIH2.RX0W;
            gp_csih2_rx_address++;
            g_csih2_rx_num++;
	    
        }
        temp = g_csih2_rx_total_num;
	if (temp > g_csih2_rx_num)
        {
     	    CSIH2.TX0W = 0U;
        }
        if (temp == g_csih2_rx_num)
        {
            r_csih2_callback_receiveend();
        }
    }
}
/***********************************************************************************************************************
* Function Name: r_Config_CSIH2_interrupt_send
* Description  : This function is CSIH2 send interrupt service routine
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
#pragma interrupt r_Config_CSIH2_interrupt_send(enable=false, channel=95, fpu=true, callt=false)
void r_Config_CSIH2_interrupt_send(void)
{
    if (g_csih2_tx_num > 0U)
    {
        CSIH2.TX0H = *gp_csih2_tx_address;
        gp_csih2_tx_address++;
        g_csih2_tx_num--;
    }
    else
    {
        r_Config_CSIH2_callback_sendend();
    }
}

/***********************************************************************************************************************
* Function Name: r_Config_CSIH2_callback_sendend
* Description  : This function is CSIH2 sendend callback service routine
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void r_Config_CSIH2_callback_sendend(void)
{
    /* Start user code for r_Config_CSIH2_callback_sendend. Do not edit comment generated here */
    /* End user code. Do not edit comment generated here */
    
}

/* Start user code for adding. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */

