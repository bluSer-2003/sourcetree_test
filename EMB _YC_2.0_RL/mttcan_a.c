/*****************************************************************************/
/* PROJECT = MTTCAN Type MTTCAN_R321, Applications                           */
/*****************************************************************************/
/*                                  COPYRIGHT                                */
/*===========================================================================*/
/* Copyright (c) 2015 by Renesas Electronics Europe GmbH,                    */
/*               a company of the Renesas Electronics Corporation            */
/*===========================================================================*/
/*===========================================================================*/
/* In case of any question please do not hesitate to contact:                */
/*                                                                           */
/*        ABG.Support                                                        */
/*                                                                           */
/*        Renesas Electronics Europe GmbH                                    */
/*        Arcadiastrasse 10                                                  */
/*        D-40472 Duesseldorf, Germany                                       */
/*                                                                           */
/*        e-mail: device_support.rl78-eu@lm.renesas.com                      */
/*        FAX:   +49 - (0)211 / 65 03 - 12 79                                */
/*                                                                           */
/*===========================================================================*/
/* Warranty Disclaimer                                                       */
/*                                                                           */
/* Because the Product(s) is licensed free of charge, there is no warranty   */
/* of any kind whatsoever and expressly disclaimed and excluded by Renesas,  */
/* either expressed or implied, including but not limited to those for       */
/* non-infringement of intellectual property, merchantability and/or         */
/* fitness for the particular purpose.                                       */
/* Renesas shall not have any obligation to maintain, service or provide bug */
/* fixes for the supplied Product(s) and/or the Application.                 */
/*                                                                           */
/* Each User is solely responsible for determining the appropriateness of    */
/* using the Product(s) and assumes all risks associated with its exercise   */
/* of rights under this Agreement, including, but not limited to the risks   */
/* and costs of program errors, compliance with applicable laws, damage to   */
/* or loss of data, programs or equipment, and unavailability or             */
/* interruption of operations.                                               */
/*                                                                           */
/* Limitation of Liability                                                   */
/*                                                                           */
/* In no event shall Renesas be liable to the User for any incidental,       */
/* consequential, indirect, or punitive damage (including but not limited    */
/* to lost profits) regardless of whether such liability is based on breach  */
/* of contract, tort, strict liability, breach of warranties, failure of     */
/* essential purpose or otherwise and even if advised of the possibility of  */
/* such damages. Renesas shall not be liable for any services or products    */
/* provided by third party vendors, developers or consultants identified or  */
/* referred to the User by Renesas in connection with the Product(s) and/or  */
/* the Application.                                                          */
/*                                                                           */
/*===========================================================================*/

#include <ree_types.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include "tmr_macrodriver.h"

//#define  DRIVER_LOCAL
#define  APPLICATION_INTERFACE

#include <map_mttcan.h>
//#include <map_asmn.h>
//#include <map_asmn_basic.h>

#include "mttcan_p.h"
#include "mttcan_s.h"

//#include "canfd.h"

/* ASMN Modules: Main Communication Port */
#if( ASMN_UARTINTERFACE == RLIN3_STANDARD )
#if( defined RLIN3_MACROS )
//#include <map_rlin3.h>
#else
#error "MTTCAN_A: RLIN3 Communication Interface Missing"
#endif

#elif( ASMN_UARTINTERFACE == DEBUG_INTERNAL )

#else
#error "MTTCAN_A: No Communication Interface Defined"
#endif

/*
 * Global Settings
 */

#ifndef MTTCAN_A_TIMEOUT_LIMIT
    #define MTTCAN_A_TIMEOUT_LIMIT ( 100L )
#endif

#ifdef  MTTCAN_VERBOSE
#if( MTTCAN_VERBOSE == 1 )
#define printf( String ) \
              ( ASMN_UARTSENDSTRING( ASMN_MENUCOM, String, ASMN_UARTMODECRLF ) )
#endif

#if( MTTCAN_VERBOSE == 2 )
#endif

#if( MTTCAN_VERBOSE == 0 )
#define printf( String ) ( MTTCAN_A_DoNothing( String ) )
#endif

#else
#define printf( String ) ( MTTCAN_A_DoNothing( String ) )
#endif

/*
 * Global Variables
 */
 
extern u08 MTTCAN_InterruptFlag_Unit_u08;

static u08 MTTCAN_A_IRQ_REC_1 = 0;
static u08 MTTCAN_A_IRQ_TRX_0 = 0;

static u08 MTTCAN_A_IRQ_REC_GW[ MTTCAN_MACROS ];
static u08 MTTCAN_A_IRQ_TRX_GW[ MTTCAN_MACROS ];

int flag_CAN;
int test_CAN;

extern int flag_hyxx;

//extern float ywx[8];

CAN_MSG canrx;
CAN_FD_MESSAGE_BUS canfdrx;

#if( MTTCAN_VERBOSE == 1 )
static u32 MTTCAN_A_TXIDTRACE[ 1 << ( sizeof( u08 ) ) ];
#endif

/*
 * Local Support Functions
 */

void MTTCAN_A_DoNothing( char *String )  /* Suppress printing action */
{
}

void MTTCAN_A_Unit2ReceiveIRQ( void )  /* Receive Interrupt Basic Test */
{
  MTTCAN_A_IRQ_REC_1++;
  return;
}

void MTTCAN_A_Unit1TransmitIRQ( void )  /* Receive Interrupt Basic Test */
{
  MTTCAN_A_IRQ_TRX_0++;
  return;
}

void MTTCAN_A_GatewayTransmitIRQ( void ) /* Transmit Interrupt Gateway */
{
  MTTCAN_A_IRQ_TRX_GW[ MTTCAN_InterruptFlag_Unit_u08 ] += 1;
}

void MTTCAN_A_GatewayReceiveIRQ( void )  /* Receive Interrupt Gateway */
{
  MTTCAN_A_IRQ_REC_GW[ MTTCAN_InterruptFlag_Unit_u08 ] += 1;
}

/* Transfer a Classical CAN Message with Event Recording */

void MTTCAN_A_GatewayCopy( struct ee_mttcan_tx *OutputMessage,
                         struct ee_mttcan_rx *InputMessage )
{
  static u08 CopyCounter_u08 = 0;
  
  OutputMessage->t0.id  = InputMessage->r0.id;
  OutputMessage->t0.rtr = InputMessage->r0.rtr;
  OutputMessage->t0.xtd = InputMessage->r0.xtd;
  //OutputMessage->t0.esi = InputMessage->r0.esi;
  OutputMessage->t1.dlc = InputMessage->r1.dlc;
//  OutputMessage->t1.fdf = InputMessage->r1.fdf;
  //OutputMessage->t1.brs = InputMessage->r1.brs;
  OutputMessage->t1.efc = MTTCAN_SET;

  /* Transmit tracing */
  OutputMessage->t1.mm  = ( u32 )CopyCounter_u08;
#if( MTTCAN_VERBOSE == 1 )
  MTTCAN_A_TXIDTRACE[ CopyCounter_u08 ] = OutputMessage->t0.id;
#endif
  CopyCounter_u08++;
  
  OutputMessage->d.lw[ 0 ] = InputMessage->d.lw[ 0 ];
  OutputMessage->d.lw[ 1 ] = InputMessage->d.lw[ 1 ];
  
  OutputMessage->path = MTTCAN_PATH_FIFOQUEUE;
  OutputMessage->irq_enable = 1;
  
  return;
}

/*
 * Application Test Functions
 */

//=============================================================================
// FunctionName: MTTCAN_Reset
// IN  :         Unit Number
// OUT :         Success Status
// Description : Resets M_CAN unit and releases Port
// 
//=============================================================================

bit MTTCAN_Reset( u08 Unit_u08 )
{
  bit MTTCAN_Status_bit;
  
  MTTCAN_Status_bit =  MTTCAN_Stop( Unit_u08, MTTCAN_PSMODE_INIT );
  MTTCAN_Status_bit &= MTTCAN_PortDisable( Unit_u08 );
  
  return( MTTCAN_Status_bit );
}





//=============================================================================
// FunctionName: MTTCAN_Loopback Test
// IN  :         Unit Numbers
// OUT :         Success Status
// Description : Performs elementary sending and receiving of one standard
//               message with default settings between external CAN transciver
//				 and on board CAN transciver
//
//=============================================================================

bit MTTCAN_LoopbackTest(u08 Unit1_u08)
{
  bit MTTCAN_Status_bit   = MTTCAN_OK;
  u08 DataCounter_u08;
  u08 SendStatus_u08;
  u08 ReceiveStatus_u08;
  u32 TimeoutLimit_u32;
  
  //int maincnt = 100;
  
  //u16 NodeID_FlashRead;//?flash??????
  //u32 CANIDFlag;
  
  struct ee_mttcan_tx          SendMessage;
  struct ee_mttcan_rx          ReceiveMessage;
  
  /* Filter example to receive  in FIFO0 
  
  const struct ee_mttcan_filter_std *FilterEntry0 = &MTTCAN_A_FILTER_EXAMPLE_test0;
  
  const struct ee_mttcan_filter_std *FilterEntry1 = &MTTCAN_A_FILTER_EXAMPLE_test1;
  
  const struct ee_mttcan_filter_std *FilterEntry2 = &MTTCAN_A_FILTER_EXAMPLE_test2;
  
  const struct ee_mttcan_filter_std *FilterEntry3 = &MTTCAN_A_FILTER_EXAMPLE_test3;
  
  const struct ee_mttcan_filter_std *FilterEntry4 = &MTTCAN_A_FILTER_EXAMPLE_test4;
  
  const struct ee_mttcan_filter_std *FilterEntry5 = &MTTCAN_A_FILTER_EXAMPLE_test5;
  
  const struct ee_mttcan_filter_std *FilterEntry6 = &MTTCAN_A_FILTER_EXAMPLE_test6;
  
  const struct ee_mttcan_filter_std *FilterEntry7 = &MTTCAN_A_FILTER_EXAMPLE_test7;*/
  
  //NodeID_FlashRead = FilterEntry->sfid1;//0001
  
  //CANIDFlag = (NodeID_FlashRead | (0x00000011 << 5));// 0 10001 0 0001
  
  
  
  /* Receive Message algorithm specification */

  ReceiveMessage.path       = MTTCAN_PATH_ANY;        /* Search all resources */
  ReceiveMessage.pathdetail = MTTCAN_PATHDETAIL_ANY;  /* Check in any location */
  
  /* Port activation */
  
  //MTTCAN_Status_bit =  MTTCAN_PortEnable( Unit1_u08 );
  //if( MTTCAN_Status_bit == MTTCAN_ERROR ) return( MTTCAN_ERROR );
    
    /*PM0 |= _PORT_SET_BIT7;
    PFC0 |= _PORT_SET_BIT7;
    PFCE0 &= _PORT_CLEAR_BIT7;
    PMC0 |= _PORT_SET_BIT7;
    
    PM0 &= _PORT_CLEAR_BIT8;
    PFC0 |= _PORT_SET_BIT8;
    PFCE0 &= _PORT_CLEAR_BIT8;
    PMC0 |= _PORT_SET_BIT8;*/
    
    
    PM5 |= _PORT_SET_BIT0;
    PFC5 &= _PORT_CLEAR_BIT0;
    PFCE5 |= _PORT_SET_BIT0;
    PMC5 |= _PORT_SET_BIT0;
    
    PM5 &= _PORT_CLEAR_BIT1;
    PFC5 &= _PORT_CLEAR_BIT1;
    PFCE5 |= _PORT_SET_BIT1;
    PMC5 |= _PORT_SET_BIT1;

                                            
  /* Interrupts: Line 0: Transmission Completion, Line 1: Any FIFO 0 Reception */
                                                          
  MTTCAN_Status_bit &= MTTCAN_CreateInterrupt( Unit1_u08,
                                           MTTCAN_INT_LINE_0,
                                           MTTCAN_INTENABLEDEFAULT,
                                           MTTCAN_A_Unit1TransmitIRQ );
  
  MTTCAN_Status_bit &= MTTCAN_CreateInterrupt( Unit1_u08,
                                           MTTCAN_INT_LINE_1,
                                           MTTCAN_INTENABLEDEFAULT,
                                           MTTCAN_A_Unit2ReceiveIRQ );

  MTTCAN_Status_bit &= MTTCAN_SetInterrupt( Unit1_u08,
                                        MTTCAN_CINT_TC,
                                        MTTCAN_INT_LINE_0,
                                        MTTCAN_IRQ );

  MTTCAN_Status_bit &= MTTCAN_SetInterrupt( Unit1_u08,
                                        MTTCAN_CINT_RF0N,
                                        MTTCAN_INT_LINE_1,
                                        MTTCAN_IRQ );

  					     

					     
if( MTTCAN_Status_bit == MTTCAN_ERROR ) return( MTTCAN_ERROR );
    
  /* Activate Units and Channels */

  MTTCAN_Status_bit &= MTTCAN_Start( Unit1_u08,
                                 MTTCAN_OPMODE_CANFDBRS,   /* operation mode */
                                 0,                  /* timestamp not set */
                                 0 );                  /* timeout not set */


  /* Ready to detect interrupts */

  MTTCAN_A_IRQ_TRX_0 = 0;
  MTTCAN_A_IRQ_REC_1 = 0;
  
  /* Send Message to be received by other unit/channel */
  
  TimeoutLimit_u32 = MTTCAN_A_TIMEOUT_LIMIT;

  
  /* Receive the message */

//while(flag_CAN==0)
  
  {  
    MTTCAN_Status_bit &= MTTCAN_ReceiveMessage( Unit1_u08,
                                            &ReceiveStatus_u08,
                                            &ReceiveMessage );
    //if( MTTCAN_Status_bit == MTTCAN_ERROR ) return( MTTCAN_ERROR );
  if(ReceiveStatus_u08 == MTTCAN_FAULT_NONE)
   
      {flag_CAN=1;}
      
//      if(maincnt--<0)
//      {break;}
  } //while( ( ReceiveStatus_u08 == MTTCAN_FAULT_NODATA ) &&
           //( --TimeoutLimit_u32 > 0 ) );
      
	   
      //while(flag_CAN==0);
      
      
//data process
 	/*canrx.id = ReceiveMessage.r0.id;
	canrx.format = ReceiveMessage.r0.xtd; 
	canrx.type = ReceiveMessage.r0.rtr;
	canrx.len = ReceiveMessage.r1.dlc;
	
	//TEST
	for( DataCounter_u08 = 0;
       DataCounter_u08 < 8;
       DataCounter_u08++ )
  {
    canrx.data8[ DataCounter_u08 ] = 0;
  }
	
	for( DataCounter_u08 = 0;
       DataCounter_u08 < ReceiveMessage.r1.dlc;
       DataCounter_u08++ )
  {
    canrx.data8[ DataCounter_u08 ] = ReceiveMessage.d.b[ DataCounter_u08 ];
  }*/
      
	//if(ReceiveMessage.r1.dlc>0)
      //{flag_CAN=1;}   
      	
//

  //if( TimeoutLimit_u32 == 0L ) MTTCAN_Status_bit = MTTCAN_ERROR;

/*if(test_CAN == 1)
{
	test_CAN = 0;
     //Sending Message Set Up 
  
  SendMessage.t0.id      = ReceiveMessage.r0.id;
  SendMessage.t1.efc     = MTTCAN_CLEAR;            // No entry in THL 
  SendMessage.t0.rtr     = 0;                     // Data Frame 
  SendMessage.t0.xtd     = 0;                     // Standard Frame 
  SendMessage.t0.esi     = 0;                     // ESI reflects own status 
  SendMessage.t1.mm      = 0x23;                  // HTH value 
  SendMessage.t1.dlc     = 8;
  SendMessage.t1.fdf     = 0;                     // classical message 
  SendMessage.t1.brs     = 0;
  SendMessage.path       = MTTCAN_PATH_MSGBOX;      // Send via Message Box 
  SendMessage.pathdetail = MTTCAN_PATHDETAIL_ANY;   // use any box... 
  SendMessage.irq_enable = MTTCAN_SET;              // Cause interrupt 
  
  for( DataCounter_u08 = 0;
       DataCounter_u08 < SendMessage.t1.dlc;
       DataCounter_u08++ )
  {
    SendMessage.d.b[ DataCounter_u08 ] = DataCounter_u08 ;
  }

  do
  {
    MTTCAN_Status_bit &= MTTCAN_SendMessage( Unit1_u08,
                                         &SendStatus_u08,
                                         &SendMessage );
    if( MTTCAN_Status_bit == MTTCAN_ERROR ) return( MTTCAN_ERROR );
    
  } while( ( SendStatus_u08 == MTTCAN_FAULT_BUSY ) &&
           ( --TimeoutLimit_u32 > 0 ) );
}*/
	   //ReceiveMessage.r1.dlc=0; 

  // Check that interrupts have happened 
  if(flag_CAN==1)
	{
		
 	if(ReceiveMessage.r1.fdf == 0)
	{
		
	
		
	
		//classic can data process
		canrx.id = ReceiveMessage.r0.id;
		canrx.format = ReceiveMessage.r0.xtd; 
		canrx.type = ReceiveMessage.r0.rtr;
		canrx.len = ReceiveMessage.r1.dlc;
	
		for( DataCounter_u08 = 0;DataCounter_u08 < 8;DataCounter_u08++ )
  		{
    			canrx.data8[ DataCounter_u08 ] = 0;
  		}
	
		for( DataCounter_u08 = 0;DataCounter_u08 < ReceiveMessage.r1.dlc;DataCounter_u08++ )
  		{
    			canrx.data8[ DataCounter_u08 ] = ReceiveMessage.d.b[ DataCounter_u08 ];
  		}
	
		flag_CAN=0;
		//CAN???1?????3???D????
		
		can_command_process(&canrx);
		
	}
	
	
	else
	{
	
	
		//canfd data process
	canfdrx.ID = ReceiveMessage.r0.id;
	canfdrx.Extended = ReceiveMessage.r0.xtd; 
	canfdrx.Remote = ReceiveMessage.r0.rtr;
	canfdrx.ESI = ReceiveMessage.r0.esi; 
	switch( ReceiveMessage.r1.dlc )
    {
      case 9: canfdrx.Length = 12; break;
      case 10: canfdrx.Length = 16; break;
      case 11: canfdrx.Length = 20; break;
      case 12: canfdrx.Length = 24; break;
      case 13: canfdrx.Length = 32; break;
      case 14: canfdrx.Length = 48; break;
      case 15: canfdrx.Length = 64; break;
      default:             canfdrx.Length = ReceiveMessage.r1.dlc; break;
    }

	
	canfdrx.BRS = ReceiveMessage.r1.brs;
	canfdrx.ProtocolMode = ReceiveMessage.r1.fdf;


	
	
	//TEST
	for( DataCounter_u08 = 0;DataCounter_u08 < 64;DataCounter_u08++ )
  		{
    			canfdrx.Data[ DataCounter_u08 ] = 0;
  		}
	
	for( DataCounter_u08 = 0;DataCounter_u08 < 64;DataCounter_u08++ )
  		{
    			canfdrx.Data[ DataCounter_u08 ] = ReceiveMessage.d.b[ DataCounter_u08 ];
  		}
	
		flag_CAN=0;
		//CAN???1?????3???D????
		Password_Verify(&canfdrx);
		CAN_FD_P_ANA(&canfdrx);
		
	}
	}
	
	//while(flag_hyxx==0);
	flag_hyxx=0;
	//Send_Test();
    
 while( ( --TimeoutLimit_u32 > 0 ) && ( MTTCAN_A_IRQ_TRX_0 == 0 ) );
  if( MTTCAN_A_IRQ_TRX_0 == 0 ) return( MTTCAN_ERROR );
  while( ( --TimeoutLimit_u32 > 0 ) && ( MTTCAN_A_IRQ_REC_1 == 0 ) );
  if( MTTCAN_A_IRQ_REC_1 == 0 ) return( MTTCAN_ERROR );   


  MTTCAN_Reset(MTTCAN_0);
  // Shutdown 
  
  //MTTCAN_Status_bit &= MTTCAN_Stop( Unit1_u08,
    //                            MTTCAN_OPMODE_INIT );
				
  
   
  return( MTTCAN_Status_bit );
  
  
  
}

void CAN_Init(void)
{
	
	bit MTTCAN_Status_bit   = MTTCAN_OK;
	u08 ErrorStatus_u08;
	u08 Unit1_u08=0;
	
	  /* Filter example to receive  in FIFO0 */
  
  const struct ee_mttcan_filter_std *FilterEntry0 = &MTTCAN_A_FILTER_EXAMPLE_test0;
  
  const struct ee_mttcan_filter_std *FilterEntry1 = &MTTCAN_A_FILTER_EXAMPLE_test1;
  
  const struct ee_mttcan_filter_std *FilterEntry2 = &MTTCAN_A_FILTER_EXAMPLE_test2;
  
  const struct ee_mttcan_filter_std *FilterEntry3 = &MTTCAN_A_FILTER_EXAMPLE_test3;
  
  const struct ee_mttcan_filter_std *FilterEntry4 = &MTTCAN_A_FILTER_EXAMPLE_test4;
  
  const struct ee_mttcan_filter_std *FilterEntry5 = &MTTCAN_A_FILTER_EXAMPLE_test5;
  
  const struct ee_mttcan_filter_std *FilterEntry6 = &MTTCAN_A_FILTER_EXAMPLE_test6;
  
  const struct ee_mttcan_filter_std *FilterEntry7 = &MTTCAN_A_FILTER_EXAMPLE_test7;
  
  const struct ee_mttcan_filter_std *FilterEntry8 = &MTTCAN_A_FILTER_EXAMPLE_1;
  
  
    /* Configuration */
  
  MTTCAN_Status_bit &= MTTCAN_SetConfiguration( Unit1_u08,
                                            &MTTCAN_A_CFG_EXAMPLE_1,
                                            &ErrorStatus_u08 );
					    
 /* Set the Filter 
  * (due to equal configuration, the TX Unit also should set the filter) 
  

  MTTCAN_Status_bit &= MTTCAN_SetStdFilterEntry( Unit1_u08,
					      0,
                                             FilterEntry0 );
					     
  MTTCAN_Status_bit &= MTTCAN_SetStdFilterEntry( Unit1_u08,
					      1,
                                             FilterEntry1 );
					     
    MTTCAN_Status_bit &= MTTCAN_SetStdFilterEntry( Unit1_u08,
					      2,
                                             FilterEntry2 );
					     
  MTTCAN_Status_bit &= MTTCAN_SetStdFilterEntry( Unit1_u08,
					      3,
                                             FilterEntry3 );
					     
  MTTCAN_Status_bit &= MTTCAN_SetStdFilterEntry( Unit1_u08,
					      4,
                                             FilterEntry4 );
					     
  MTTCAN_Status_bit &= MTTCAN_SetStdFilterEntry( Unit1_u08,
					      5,
                                             FilterEntry5 );					     

  MTTCAN_Status_bit &= MTTCAN_SetStdFilterEntry( Unit1_u08,
					      6,
                                             FilterEntry6 );					     

  MTTCAN_Status_bit &= MTTCAN_SetStdFilterEntry( Unit1_u08,
					      7,
                                             FilterEntry7  );*/
	MTTCAN_Status_bit &= MTTCAN_SetStdFilterEntry( Unit1_u08,
					      0,
                                             FilterEntry8  );
	
	// configure P2_7 and P2_8 as port output for test
	PMSR2	= 0x01800000;


	
	PSR2	= 0x01800180;
	


	
	
	
	
	
	
	
	
}

void MCAN(void)
{
	MTTCAN_LoopbackTest(MTTCAN_0);
	
	//if(flag_CAN==1)
	//{
	//	flag_CAN=0;
		//CAN???1?????3???D????
	//	can_command_process(&canrx);
		
	//}
	//MTTCAN_Reset(MTTCAN_0);	
}

void Send_Test(CAN_FD_MESSAGE_BUS *msg)
{
	//u32 TimeoutLimit_u32 = 100000L;
	//Sending Message Set Up 
	struct ee_mttcan_tx          SendMessage;
	 u08 SendStatus_u08;
	 //u32 TimeoutLimit_u32 = 100000L;
	 u08 DataCounter_u08;
	 bit MTTCAN_Status_bit   = MTTCAN_OK;
	 u08 Unit1_u08 = 0;
  
  SendMessage.t0.id      = msg->ID;
  SendMessage.t1.efc     = MTTCAN_CLEAR;            // No entry in THL 
  SendMessage.t0.rtr     = 0;                     // Data Frame 
  SendMessage.t0.xtd     = 0;                     // Standard Frame 
  SendMessage.t0.esi     = 0;                     // ESI reflects own status 
  SendMessage.t1.mm      = 0x23;                  // HTH value 
  SendMessage.t1.dlc     = msg->DLC;
  SendMessage.t1.fdf     = 1;                     // classical message 
  SendMessage.t1.brs     = 0;
  SendMessage.path       = MTTCAN_PATH_MSGBOX;      // Send via Message Box 
  SendMessage.pathdetail = MTTCAN_PATHDETAIL_ANY;   // use any box... 
  SendMessage.irq_enable = MTTCAN_SET;              // Cause interrupt 
  
  for( DataCounter_u08 = 0;
       DataCounter_u08 < msg->Length;
       DataCounter_u08++ )
  {
    SendMessage.d.b[ DataCounter_u08 ] = msg->Data[DataCounter_u08] ;
  }

  
    MTTCAN_Status_bit &= MTTCAN_SendMessage( Unit1_u08,
                                         &SendStatus_u08,
                                         &SendMessage );
    //if( MTTCAN_Status_bit == MTTCAN_ERROR ) return( MTTCAN_ERROR );
    
 
}