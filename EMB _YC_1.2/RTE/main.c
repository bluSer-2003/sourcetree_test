/*****************************************************************************
 Includes   <System Includes> , "Project Includes"
 *****************************************************************************/
#include "main.h"

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
	RTE_Main_Init();

	unsigned int i,j;
	unsigned int Ali_flash = 8643;
	unsigned int Ali_flag = 0;
	//Initialize clocks
	//   '      ? ?   
	initGlobalVariables();
	Clock_Init();
	PM2&= _PORT_CLEAR_BIT10;
	PM2&= _PORT_CLEAR_BIT11;

	//Initialize ports
	Port_Init();
	PMIC_Config();
	A4911_Config();
	SENT_receive_init();
	GTM0.DTM24CHCTRL2 = 0x22222200;
	for(i=0;i<30000;i++)
	{
		for(j=0;j<100;j++);
	}
	//A4911_Config();
	R_ADC_Init();
	//GTM_PIC_ADC_Init();	
	CAN_Init();
	CAN_SPI_Init();
	CAN1145_ModeControl(CAN_normal);
	TMR_Init();
	//printf("Start\n");
	para_Init();       
	OBDII_CallBack_Init();
	OBD_stDtcReadFromEEPROM();
	FAD_DFlashWriteBootFLG(20);
	__EI();
	GTM_Init();
	//FAD_FlashOperation(Ali_flash,Ali_flag);
	for(;;) 
    	{
		//CAN1145_ModeControl(CAN_normal);
		MCAN();
		/********CANFD     *********/
		UpdateFbkPara();
	        UpdateRegulatorParam();
	        //UpdateProctectParam();
	        UpdateGivenParam();
		UDS_MainFun();
		
	        if(FB_Complete_Flag)
	            	FB_reply();
			
	        if(FB_lianxu_Flag)
		{
	            	FB_Order_Flag = 1;
	            	FB_Complete_Flag = 0;
	        }
		
	        if(Given_Complete_Flag)
			Given_reply();
			
	        if(Regulator_Complete_Flag)
	            	Regulator_reply();
			
	        //if(Protect_Complete_Flag)
	            //Protect_reply();

	        //if(Run_Order_Flag)
	            //Run_reply();	

	        if(g_Control.iRunState==4444 && Flag_CAN_flash_Order==1)
		{  	//only stop motor can op flash
	            	FlashWrite();
	            	Flag_CAN_flash_Order = 0;
	            	Flag_CAN_flash_Complete = 1;
	            	//g_CANflash.flag |=0x8000;
	        }
	        if(Flag_CAN_flash_Complete)
		{
	            	Flag_CAN_flash_Order = 0;
	            	Flag_CAN_flash_Complete = 0;
	            	Flash_reply();	
	        }
	        if(CANfd_runState==1&&g_Control.iRunState==4444)
		{  	//??off=9
	            	g_Control.iRunState = 1;
	            	lsw = CANfd_runMode;
	            	CANfd_runState = 0;
		}
	        if(CANfd_runState==9&&g_Control.iRunState==100)
		{   	//??off=9
	            	g_Control.iRunState = 404;
	            	CANfd_runState = 0;
	        }
		
		switch(g_Control.iRunState)
		{
		        case 0:   
		            break;

		        case 1:   
		                On_Mos();
		                g_Control.iRunState = 100;
		            break;
		            
		        case 100: 
			
		            break;

		        case 404: 
		                De_Mos();
		                g_Control.iRunState = 4444;
		            break;

		        case 4444: 
		            break;

		        default:
		                g_Control.iRunState = 404;
		            break;
	        }
    	}
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


