/***********************************************************************/
/*                                                                     */
/*  FILE        :RLIN3.c                                               */
/*  DATE        :Mon, Oct 24, 2016                                     */
/*  DESCRIPTION :RLIN3 Program: UART Mode                              */
/*  CPU TYPE    :                                                      */
/*                                                                     */
/*  NOTE:THIS IS A TYPICAL EXAMPLE.                                    */
/*                                                                     */
/***********************************************************************/


/*****************************************************************************
 Includes   <System Includes> , "Project Includes"
 *****************************************************************************/
#include "global.h"


/*****************************************************************************
 Macro definitions
 *****************************************************************************/
 
 
/*****************************************************************************
 Typedef definitions
 *****************************************************************************/




/*****************************************************************************
 Imported global variables and functions (from other files)
 *****************************************************************************/

 
 
/*****************************************************************************
 Exported global variables and functions (to be accessed by other files)
 *****************************************************************************/
void RLIN30_Init(void);						// Configure RLIN module to enable the UART communication
void RLIN30_Transmit(unsigned char data);	// Sent one byte via UART



/*****************************************************************************
 * Outline				: RLIN30_Init program
 * Include				: 
 * Declaration			: 
 * Description			: RLIN30 Initialization program
 * Argument				: 
 * Return Value			: 
  * Calling Functions		: 
 *****************************************************************************/
void RLIN30_Init(void)
{
	//Port configuration (P5_13 in Alt 4th input ; P5_14 in Alt 3rd output)

	
	//Interrupt Configuration
	EIC115		= 0x0043;							// Enable the interrupt request for RLIN30 Rx with priority 3

	//LIN Wake-up Baud Rate Select Register 
	RLN30.LWBR	= 0xF0; 							// 16 Samplings; No pre-scaler

	//UART Baud Rate Prescaler 01 Register
	//P1M: RLIN3 Clock: High-speed peripheral clock, 80MHz
//	RLN30.LBRP01.UINT16= 42;   						// Baud rate pre-scaler = 42 => Baud rate = 80MHz/((42+1)*16) = 116279 Hz => 115200bps

	//P1M-C: RLIN3 Clock: Low-speed peripheral clock, 40MHz
	RLN30.LBRP01.UINT16= 21;   						// Baud rate pre-scaler = 21 => Baud rate = 40MHz/((21+1)*16) = 113636 Hz => 115200bps

	//UART Mode Register
	RLN30.LMD	= 0x21; 							// RX Noise filter disabled, UART mode                                                                                                                                                        

	//UART Configuration Register
	RLN30.LBFC	= 0x00; 							// 8bit; LSB first; 1 Stop bit; No Parity; Normal in-/output

	//UART Control Register
	RLN30.LCUC	= 0x01; 							// Software reset mode cancelled

	//UART Operation Enable Register
	RLN30.LUOER	= 0x03; 							// Enable Tx and Rx
	
}


/*****************************************************************************
 * Outline           : RLIN30 Transmit Module
 * Include           : none
 * Declaration       : void RLIN30_Transmit()
 * Description       : 
 * Argument          :
 * Return Value      : 
 *                   : 
 * Calling Functions : none
 *****************************************************************************/
void RLIN30_Transmit(unsigned char data)
	{
	volatile unsigned int timeout;
	timeout = 0xFFFFFFFF;
	
	while((RLN30.LST== 0x10))
		{
		timeout--;
		}
	
	if(timeout != 0x00)
		{
		RLN30.LUTDR.UINT16 = data;
		}
	
	while(((RLN30.LST & 0x10) == 0x10))
		{
		timeout--;
		}
	}


/*****************************************************************************
 * Outline           : Receive data
 * Include           : none
 * Declaration       : void getDebugChar()
 * Description       : 
 * Argument          :
 * Return Value      : receive data
 *                   : 
 * Calling Functions : none
 *****************************************************************************/
 char getDebugChar(void)
	{
/*
	char ch;
	
	//It is better to get the total status of SCI2 to avoid the error!
	if ((SCI30.SSR.UINT8 & 0x20)==0x20 |			//ORER: Overrun Error Flag
		(SCI30.SSR.UINT8 & 0x10)==0x10 |			//FER: Framing Error Flag
		(SCI30.SSR.UINT8 & 0x08)==0x08 )			//PER: Parity Error Flag
		SCI30_HandleError ();

	while((SCI30.SSR.UINT8 & 0x40) != 0x40);		//RDRF: Receive Buffer Register Full Flag

	SCI30.SSR.UINT8 = SCI30.SSR.UINT8 & (~0x40);	//RDRF: Clear Receive Buffer Register Full Flag
	ch=SCI30.RDR;									//RDR: Receive data

	return ch;
*/	
	}


/*****************************************************************************
 * Outline           : Transmit data
 * Include           : none
 * Declaration       : void putDebugChar()
 * Description       : 
 * Argument          :
 * Return Value      : none
 *                   : 
 * Calling Functions : none
 *****************************************************************************/
void putDebugChar (char ch)
	{
	RLIN30_Transmit(ch);
	}


/*****************************************************************************
 * Outline           : Transmit char
 * Include           : none
 * Declaration       : void putChar()
 * Description       : 
 * Argument          :
 * Return Value      : none
 *                   : 
 * Calling Functions : none
 *****************************************************************************/
int putChar(char c)
	{
	if (c == '\n')
		putDebugChar ('\r');
	putDebugChar (c);
	return c;
	}

/*****************************************************************************
 * Outline           : Transmit string
 * Include           : none
 * Declaration       : void putString()
 * Description       : 
 * Argument          :
 * Return Value      : none
 *                   : 
 * Calling Functions : none
 *****************************************************************************/
void putString (char *ptr, unsigned short code0, unsigned short code1, unsigned short code2)
	{
	char *p;
	char str[256];

	sprintf(str, ptr, code0, code1, code2);

	for (p = str; *p; p++)
		{
		if (*p == '\n')
			putDebugChar ('\r');
		putDebugChar (*p);
		}
	}
