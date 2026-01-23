/***********************************************************************************************************************
Includes
***********************************************************************************************************************/
#include "tmr_macrodriver.h"
#include "tmr.h"
#include "CAN_SPI.h"

/***********************************************************************************************************************
Global variables and functions
***********************************************************************************************************************/
int CAN_SYC[20];
int SYCi;
/***********************************************************************************************************************
* Function Name: R_Config_CSIH3_Create
* Description  : This function initializes the Config_CSIH3 module.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_Config_CSIH3_Create(void)
{
 

    CSIH3.CTL0.UINT8 = _CSIH_OPERATION_CLOCK_STOP;
    // Disable INTCSIH3IC operation and clear request 
    EIC100 |= _INT_PROCESSING_MASK  ;   //0080
    EIC100 &= ~_INT_REQUEST_OCCUR_MASK  ;   //1000
    // Disable INTCSIH3IR operation and clear request 
    EIC99 |= _INT_PROCESSING_MASK ;
    EIC99 &= ~_INT_REQUEST_OCCUR_MASK  ;
    // Set CSIH3 interrupt(INTCSIH1IC) setting 
    EIC100 |= _INT_TABLE_VECTOR_MASK ;    //0040
    EIC100 |= _INT_PRIORITY_LOWEST ;      //00CF
   
    // Set CSIH3 interrupt(INTCSIH1IR) setting 
    EIC99 |= _INT_TABLE_VECTOR_MASK ;
    EIC99 |= _INT_PRIORITY_LOWEST ;
    // Set CSIH3 control setting 
    CSIH3.CTL1 = _CSIH_CLOCK_INVERTING_LOW | _CSIH_INTERRUPT_TIMING_NORMAL | _CSIH_DATA_CONSISTENCY_CHECK_DISABLE | 
                 _CSIH_NO_DELAY | _CSIH_CHIPSELECT0_ACTIVE_LOW | _CSIH_HANDSHAKE_DISABLE | 
                 _CSIH_CHIPSELECT_SIGNAL_HOLD_INACTIVE | _CSIH_SLAVE_SELECT_DISABLE | _CSIH_SYNCHRONIZATION_FALLING_EDGE;//|0x00000080;
   
    //CSIH3.CTL1 =0x01020010;
    //CSIH3.CTL2 = _CSIH1_SELECT_BASIC_CLOCK;
    CSIH3.CTL2 =0x0000;
    //CSIH3.BRS0 = _CSIH1_BAUD_RATE_0;
    CSIH3.BRS0 =0x0008;
    CSIH3.BRS1 = _CSIH1_BAUD_RATE_1;
    CSIH3.BRS2 = _CSIH1_BAUD_RATE_2;
    CSIH3.BRS3 = _CSIH1_BAUD_RATE_3;
    // Set CSIH3 configuration setting CAN0:CFG0,CAN1:CFG2
    CSIH3.CFG0 = _CSIH_USED_BAUDRATE_0 | _CSIH_PARITY_NO | _CSIH_DATA_DIRECTION_MSB | _CSIH_PHASE_SELECTION_TYPE1 | 
                 _CSIH_IDLE_INSERTED_NOT_ALWAYS | _CSIH_IDLE_TIME_0 | _CSIH_HOLD_TIME_0 | 
                 _CSIH_INTER_DATA_DELAY_TIME_0 | _CSIH_SETUP_TIME_0| _CSIH_DATA_LENGTH_16;//|0x10000000;//
    
    CSIH3.CFG2 = _CSIH_USED_BAUDRATE_0 | _CSIH_PARITY_NO | _CSIH_DATA_DIRECTION_MSB | _CSIH_PHASE_SELECTION_TYPE1 | 
                 _CSIH_IDLE_INSERTED_NOT_ALWAYS | _CSIH_IDLE_TIME_0 | _CSIH_HOLD_TIME_0 | 
                 _CSIH_INTER_DATA_DELAY_TIME_0 | _CSIH_SETUP_TIME_0| _CSIH_DATA_LENGTH_16;//|0x10000000;//
    
    // Synchronization processing 
    //CSIH3.MCTL1=0x0003007D;
    
//    g_cg_sync_read = CSIH1.CTL1;
    __syncp();
    // Set CSIH3SCO pin 2nd out
    PIBC1 &= _PORT_CLEAR_BIT2;
    PBDC1 &= _PORT_CLEAR_BIT2;
    PM1 &= _PORT_CLEAR_BIT2;
    PFC1 |= _PORT_SET_BIT2;
    PFCE1 &= _PORT_CLEAR_BIT2;
    PMC1 |= _PORT_SET_BIT2;
    // Set CSIH3SO pin 2nd out 
    PIBC1 &= _PORT_CLEAR_BIT4;
    PBDC1 &= _PORT_CLEAR_BIT4;
    PM1 &= _PORT_CLEAR_BIT4;
    PFC1 |= _PORT_SET_BIT4;
    PFCE1 &= _PORT_CLEAR_BIT4;
    PMC1 |= _PORT_SET_BIT4;
    // Set CSIH3SI pin 2nd in 
    PIBC1 &= _PORT_CLEAR_BIT3;
    PBDC1 &= _PORT_CLEAR_BIT3;
    PM1 |= _PORT_SET_BIT3;  
    PFC1 |= _PORT_SET_BIT3;
    PFCE1 &= _PORT_CLEAR_BIT3;
    PMC1 |= _PORT_SET_BIT3; 
    //PD1 |= _PORT_SET_BIT3;
    // Set csih3CSS0 pin 2nd out
    PIBC1 &= _PORT_CLEAR_BIT1;//can0
    PBDC1 &= _PORT_CLEAR_BIT1;
    PM1 &= _PORT_CLEAR_BIT1;
    PFC1 |= _PORT_SET_BIT1;
    PFCE1 &= _PORT_CLEAR_BIT1;
    PMC1 |= _PORT_SET_BIT1;/**/
    
    PIBC3 &= _PORT_CLEAR_BIT3;//can1
    PBDC3 &= _PORT_CLEAR_BIT3;
    PM3 &= _PORT_CLEAR_BIT3;
    PFC3 &= _PORT_CLEAR_BIT3;
    PFCE3 |= _PORT_SET_BIT3;
    PMC3 |= _PORT_SET_BIT3;
    

}

/***********************************************************************************************************************
* Function Name: R_Config_CSIH3_Start
* Description  : This function starts the Config_CSIH3 module operation.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_Config_CSIH3_Start(void)
{
    // Enable CSIH3 operation 
    CSIH3.CTL0.UINT8 = _CSIH_OPERATION_CLOCK_PROVIDE | _CSIH_TRANSMISSION_PERMIT | _CSIH_RECEPTION_PERMIT | _CSIH_DIRECTACCESS;
    // Clear CSIH3 interrupt request and enable operation 
    //EIC91 &= ~_INT_REQUEST_OCCUR_MASK  ;  //0x1000
    //EIC92 &= ~_INT_REQUEST_OCCUR_MASK  ;
    
    EIC91 &= ~_INT_PROCESSING_MASK  ;   //0x0080
    EIC91 &=0x0001;
    //EIC92 &= ~_INT_PROCESSING_MASK  ;
    
}

/***********************************************************************************************************************
* Function Name: CAN_SPI_Init
* Description  : This function init spi.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void CAN_SPI_Init(void)
{
	R_Config_CSIH3_Create();
	R_Config_CSIH3_Start();
}

/***********************************************************************************************************************
* Function Name: CAN1145_ModeControl
* Description  : This function switch can mode.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void CAN1145_ModeControl(int CAN_Mode)
	{
		int cani;
		switch(CAN_Mode)
		{
			case CAN_normal:
			CSIH3.TX0W =0x00FE0247;//MC  CAN0:FE,CAN1:FB
			for(cani = 0;cani<5000;cani++)
			{}
			CAN_SYC[0] = CSIH3.RX0W;
			CAN_SYC[0] = CSIH3.RX0W;
			while(!(CSIH3.STR0==0x00000010));
			
			for(cani = 0;cani<500;cani++)
			{}/**/
			
			CSIH3.TX0W =0x00FE4001;//CMC
			for(cani = 0;cani<5000;cani++)
			{}
			CAN_SYC[1] = CSIH3.RX0W;
			CAN_SYC[1] = CSIH3.RX0W;
			while(!(CSIH3.STR0==0x00000010));
			
			for(cani = 0;cani<500;cani++)
			{}/**/
			
			CSIH3.TX0W =0x00FEC600;//
			for(cani = 0;cani<5000;cani++)
			{}
			CAN_SYC[4] = CSIH3.RX0W;
			CAN_SYC[4] = CSIH3.RX0W;
			while(!(CSIH3.STR0==0x00000010));
			
			for(cani = 0;cani<500;cani++)
			{}/**/
			
			CSIH3.TX0W =0x00FE0700;//STATUS
			for(cani = 0;cani<5000;cani++)
			{}
			CAN_SYC[2] = CSIH3.RX0W;
			CAN_SYC[2] = CSIH3.RX0W;
			while(!(CSIH3.STR0==0x00000010));
			
			for(cani = 0;cani<500;cani++)
			{}/**/
			
			CSIH3.TX0W =0x00FE4500;//TX STATUS
			for(cani = 0;cani<5000;cani++)
			{}
			CAN_SYC[3] = CSIH3.RX0W;
			CAN_SYC[3] = CSIH3.RX0W;
			while(!(CSIH3.STR0==0x00000010));
			
			
			break;
			
			case CAN_sleep:
						
			CSIH3.TX0W =0x00FA0000 | 0x0A << 9 | 0x00;// no lock  
			for(cani = 0;cani<5000;cani++)
			{}
			CAN_SYC[15] = CSIH3.RX0W | 0x0A << 24;
			CAN_SYC[15] = CSIH3.RX0W | 0x0A << 24;
			while(!(CSIH3.STR0==0x00000010));
						
			for(cani = 0;cani<500;cani++)
			{}

				
			CSIH3.TX0W =0x00FA0000 | 0x23 << 9 | 0x01;// wake up enable CWE
			for(cani = 0;cani<5000;cani++)
			{}
			CAN_SYC[0] = CSIH3.RX0W;
			CAN_SYC[0] = CSIH3.RX0W;
			while(!(CSIH3.STR0==0x00000010));
						
			for(cani = 0;cani<500;cani++)
			{}
					
			CSIH3.TX0W =0x00FA0000 | 0x4C << 9 | 0x02;//WPRE WPFE
			for(cani = 0;cani<5000;cani++)
			{}
			CAN_SYC[1] = CSIH3.RX0W;
			CAN_SYC[1] = CSIH3.RX0W;
			while(!(CSIH3.STR0==0x00000010));
			
			for(cani = 0;cani<500;cani++)
			{}
					
			CSIH3.TX0W =0x00FA0000 | 0x26 << 9 | 0x05;//CDR data rate 500k
			for(cani = 0;cani<5000;cani++)
			{}
			CAN_SYC[2] = CSIH3.RX0W;
			CAN_SYC[2] = CSIH3.RX0W;
			while(!(CSIH3.STR0==0x00000010));
			
		
				
			for(cani = 0;cani<500;cani++)
			{}		
			
			CSIH3.TX0W =0x00FA0000 | 0x2F << 9 | 0x00;//PNDM DLC  dont care data ,just ID
			for(cani = 0;cani<5000;cani++)
			{}
			CAN_SYC[3] = CSIH3.RX0W;
			CAN_SYC[3] = CSIH3.RX0W;
			while(!(CSIH3.STR0==0x00000010));
			
						
			for(cani = 0;cani<500;cani++)
			{}		
			
			CSIH3.TX0W =0x00FA0000 | 0x27 << 9 | 0x00;//extern ID
			for(cani = 0;cani<5000;cani++)
			{}
			CAN_SYC[4] = CSIH3.RX0W;
			CAN_SYC[4] = CSIH3.RX0W;
			while(!(CSIH3.STR0==0x00000010));
			
						
			for(cani = 0;cani<500;cani++)
			{}		
			
			CSIH3.TX0W =0x00FA0000 | 0x28 << 9 | 0x00;//extern ID
			for(cani = 0;cani<5000;cani++)
			{}
			CAN_SYC[5] = CSIH3.RX0W;
			CAN_SYC[5] = CSIH3.RX0W;
			while(!(CSIH3.STR0==0x00000010));
			
			for(cani = 0;cani<500;cani++)
			{}		
			
			CSIH3.TX0W =0x00FA0000 | 0x29 << 9 | 0x00;// HSB6 stand ID 5-0 
			for(cani = 0;cani<5000;cani++)
			{}
			CAN_SYC[6] = CSIH3.RX0W;
			CAN_SYC[6] = CSIH3.RX0W;
			while(!(CSIH3.STR0==0x00000010));
			
			for(cani = 0;cani<500;cani++)
			{}		
			
			CSIH3.TX0W =0x00FA0000 | 0x2A << 9 | 0x10;//LSB5 stand ID 10-6
			for(cani = 0;cani<5000;cani++)
			{}
			CAN_SYC[7] = CSIH3.RX0W;
			CAN_SYC[7] = CSIH3.RX0W;
			while(!(CSIH3.STR0==0x00000010));
			
			for(cani = 0;cani<500;cani++)
			{}		
			
			CSIH3.TX0W =0x00FA0000 | 0x2B << 9 | 0x00;//extern ID mask 7-0
			for(cani = 0;cani<5000;cani++)
			{}
			CAN_SYC[8] = CSIH3.RX0W;
			CAN_SYC[8] = CSIH3.RX0W;
			while(!(CSIH3.STR0==0x00000010));
			
			for(cani = 0;cani<500;cani++)
			{}		
			
			CSIH3.TX0W =0x00FA0000 | 0x2C << 9 | 0x00;//extern ID mask 15-8
			for(cani = 0;cani<5000;cani++)
			{}
			CAN_SYC[9] = CSIH3.RX0W;
			CAN_SYC[9] = CSIH3.RX0W;
			while(!(CSIH3.STR0==0x00000010));
			
			for(cani = 0;cani<500;cani++)
			{}		
			
			CSIH3.TX0W =0x00FA0000 | 0x2D << 9 | 0x00;//stand ID mask 5-0
			for(cani = 0;cani<5000;cani++)
			{}
			CAN_SYC[10] = CSIH3.RX0W;
			CAN_SYC[10] = CSIH3.RX0W;
			while(!(CSIH3.STR0==0x00000010));
			
			for(cani = 0;cani<500;cani++)
			{}		
			
			CSIH3.TX0W =0x00FA0000 | 0x2E << 9 | 0x00;//stand ID mask 10-6
			for(cani = 0;cani<5000;cani++)
			{}
			CAN_SYC[11] = CSIH3.RX0W;
			CAN_SYC[11] = CSIH3.RX0W;
			while(!(CSIH3.STR0==0x00000010));
						
			for(cani = 0;cani<500;cani++)
			{}		
			
			CSIH3.TX0W =0x00FA0000 | 0x20 << 9 | 0x31;//CAN control CFDC PNCOK CPNC CMC
			for(cani = 0;cani<5000;cani++)
			{}
			CAN_SYC[12] = CSIH3.RX0W;
			CAN_SYC[12] = CSIH3.RX0W;
			while(!(CSIH3.STR0==0x00000010));
					
			/*for(cani = 0;cani<500;cani++)
			{}	
			
			CSIH3.TX0W =0x00FB0000 | 0x01 << 9 | 0x01;//MC standby
			for(cani = 0;cani<5000;cani++)
			{}
			CAN_SYC[9] = CSIH3.RX0W;
			CAN_SYC[9] = CSIH3.RX0W;
			while(!(CSIH3.STR0==0x00000010));*/
			
						
						
			for(cani = 0;cani<500;cani++)
			{}	
			
			CSIH3.TX0W =0x00FA0000 | 0x60 << 9 | 0xFF;//global event
			for(cani = 0;cani<5000;cani++)
			{}
			CAN_SYC[13] = CSIH3.RX0W;
			CAN_SYC[13] = CSIH3.RX0W;
			while(!(CSIH3.STR0==0x00000010));
			
						
			for(cani = 0;cani<500;cani++)
			{}	
			
			CSIH3.TX0W =0x00FA0000 | 0x61 << 9 | 0xFF;//System event
			for(cani = 0;cani<5000;cani++)
			{}
			CAN_SYC[14] = CSIH3.RX0W;
			CAN_SYC[14] = CSIH3.RX0W;
			while(!(CSIH3.STR0==0x00000010));
			
						
		
			
			for(cani = 0;cani<500;cani++)
			{}	
			
			CSIH3.TX0W =0x00FA0000 | 0x63 << 9 | 0xFF;//Tx event PNFDE CBS CF CW
			for(cani = 0;cani<5000;cani++)
			{}
			CAN_SYC[15] = CSIH3.RX0W;
			CAN_SYC[15] = CSIH3.RX0W;
			while(!(CSIH3.STR0==0x00000010));
			

						
			for(cani = 0;cani<500;cani++)
			{}	
			
			CSIH3.TX0W =0x00FA0000 | 0x64 << 9 | 0xFF;//WAKE event WPR WPF
			for(cani = 0;cani<5000;cani++)
			{}
			CAN_SYC[16] = CSIH3.RX0W;
			CAN_SYC[16] = CSIH3.RX0W;
			while(!(CSIH3.STR0==0x00000010));
			
						
			for(cani = 0;cani<500;cani++)
			{}	
			
			CSIH3.TX0W =0x00FA0000 | 0x01 << 9 | 0x01;//MC sleep
			for(cani = 0;cani<5000;cani++)
			{}
			CAN_SYC[17] = CSIH3.RX0W;
			CAN_SYC[17] = CSIH3.RX0W;
			while(!(CSIH3.STR0==0x00000010));
			
			for(cani = 0;cani<500;cani++)
			{}
			CSIH3.TX0W =0x00FA0000 | 0x0A << 9 | 0xFF;// lock
			for(cani = 0;cani<5000;cani++)
			{}
			CAN_SYC[18] = CSIH3.RX0W;
			CAN_SYC[18 ] = CSIH3.RX0W;
			while(!(CSIH3.STR0==0x00000010));
			
			
			
			
			
			break;
			
			case CAN_standby:
			CSIH3.TX0W =0x01040000;
			while(!(CSIH3.STR0==0x00000010));
			CAN_SYC[0] = CSIH3.RX0H;
			
			break;
		}
	}
	
/*void CAN1145_SpiSend(int ChipSelectID,int WR,int CAN_adress,int cData )
{
	
		CSIH3.TX0W = ChipSelectID | WR << 8 | CAN_adress << 9 | cData;
		for(cani = 0;cani<500;cani++)
			{}
		CAN_SYC[SYCi] = CSIH3.RX0W;
		CAN_SYC[SYCi] = CSIH3.RX0W;
		while(!(CSIH3.STR0==0x00000010));
		SYCi++;
		for(cani = 0;cani<500;cani++)
			{}
}*/