/***********************************************************************/
/*                                                                     */
/*  FILE        :Main.c                                                */
/*  DATE        :Mon, Oct 24, 2016                                     */
/*  DESCRIPTION :Main Program                                          */
/*  CPU TYPE    :                                                      */
/*                                                                     */
/*  NOTE:THIS IS A TYPICAL EXAMPLE.                                    */
/*                                                                     */
/***********************************************************************/


/*****************************************************************************
 Includes   <System Includes> , "Project Includes"
 *****************************************************************************/
#include "global.h"
#include "gtm.h"

/*****************************************************************************
 Macro definitions
 *****************************************************************************/
#define PrintEnable 1								//Enable output internal information via RLIN30

 
/*****************************************************************************
 Typedef definitions
 *****************************************************************************/



/*****************************************************************************
 Private variables and functions
 *****************************************************************************/
void main(void);
void Clock_Init(void);



/*****************************************************************************
 Imported global variables and functions (from other files)
 *****************************************************************************/
void Port_Init(void);

#pragma section text "fst"
void Test_Addr_Parity_Code_Flash(void)
{
	unsigned char retval = 0;
	unsigned int loopcnt = 300;
	CFAPCTL = 0X4000;
	CFAPCTL |= 0X0002; //Address Parity check test bit; test mode;
	
	CFAPCTL |= 0X0001;  //Enable address parity check;
	if(CFAPCTL & 0x0002 == 0)
	{
		retval += 1;
	}
	
	do{
	
	}while((loopcnt>0) && ((UCFDERSTR & 0X04)==0));
}
 
/*****************************************************************************
 Exported global variables and functions (to be accessed by other files)
 *****************************************************************************/


/*****************************************************************************
 * Outline				: Main program
 * Include				: 
 * Declaration			: 
 * Description			: 
 * Argument				: 
 * Return Value			: 
  * Calling Functions		: 
 *****************************************************************************/
void main(void)
{
	//Initialize clocks
	Test_Addr_Parity_Code_Flash();
	Clock_Init();

	//Initialize ports
	Port_Init();
	
		
	  printf("Start\n");
	  
	  __EI();
	  
	  gtm_test();
	while(1){
		
		};

}


/*****************************************************************************
 * Outline				: Clock_Init program
 * Include				: 
 * Declaration			: 
 * Description			: 
 * Argument				: 
 * Return Value			: 
  * Calling Functions		: 
 *****************************************************************************/
void Clock_Init(void)
{
	//Canceling Module standby mode
	MSR_LM3	=0x0000;		//Enable MCAN clock
	MSR_LM4	=0x0000;		//Enable FlexRay clock
	MSR_LM5	=0x0000;		//Enable GTM clock
	MSR_LM6	=0x0000;		//Enable Ethernet clock
	MSR_LM7	=0x0000;		//Enable SENT clock
	MSR_LM8	=0x0000;		//Enable HS-USRT clock
	MSR_LM10=0x0000;		//Enable CSIH clock
	MSR_LM11=0x0000;		//Enable RLIN3 clock
	MSR_LM12=0x0000;		//Enable ADC clock
}
