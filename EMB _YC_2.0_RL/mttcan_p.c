/*****************************************************************************/
/* PROJECT = MTTCAN Type MTTCAN_R321, Lower level driver                     */
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

//#define DRIVER_LOCAL

#include <ree_types.h>
#include <stddef.h>

#include <map_mttcan.h>
#include <map_ports.h>
//#include <map_asmn_basic.h>
#include <standardports_p.h>

#define MTTCAN_MACROS 1

#if( MTTCAN_MACROS > 3 )
#error "NUMBER OF UNITS NOT SUPPORTED"
#endif

/*
 * CreateInterrupt() Jump Vector Table
 */

void MTTCAN_IRQDefault( );

#if( MTTCAN_MACROS == 1 )
static void ( *MTTCAN_CIVector [ ( MTTCAN_MACROS * MTTCAN_INT_LINES ) ] )( ) =
{
		MTTCAN_IRQDefault, MTTCAN_IRQDefault, MTTCAN_IRQDefault	
};
#endif

#if( MTTCAN_MACROS == 2 )
static void ( *MTTCAN_CIVector [ ( MTTCAN_MACROS * MTTCAN_INT_LINES ) ] )( ) =
{
		MTTCAN_IRQDefault, MTTCAN_IRQDefault, MTTCAN_IRQDefault,
		MTTCAN_IRQDefault, MTTCAN_IRQDefault, MTTCAN_IRQDefault
};
#endif

#if( MTTCAN_MACROS == 3 )
static void ( *MTTCAN_CIVector [ ( MTTCAN_MACROS * MTTCAN_INT_LINES ) ] )( ) =
{
		MTTCAN_IRQDefault, MTTCAN_IRQDefault, MTTCAN_IRQDefault,	
		MTTCAN_IRQDefault, MTTCAN_IRQDefault, MTTCAN_IRQDefault,	
		MTTCAN_IRQDefault, MTTCAN_IRQDefault, MTTCAN_IRQDefault
};
#endif

/*
 * Global Variables 
 */

/* Interrupt Flag Status */

u08 MTTCAN_InterruptFlag_Unit_u08 = MTTCAN_INVALID;
u08 MTTCAN_InterruptFlag_Line_u08 = MTTCAN_INT_NOINT;

/*
 * Internal Support Functions
 */

void MTTCAN_IRQDefault( )
{
}

u16 MTTCAN_GetObjectSize( u32 ObjectLengthCode_u32 )
{
  switch( ObjectLengthCode_u32 )
  {
    case MTTCAN_BUFDL_8:  return( MTTCAN_RAMSIZE_OBJECT_8 );
    case MTTCAN_BUFDL_12: return( MTTCAN_RAMSIZE_OBJECT_12 );
    case MTTCAN_BUFDL_16: return( MTTCAN_RAMSIZE_OBJECT_16 );
    case MTTCAN_BUFDL_20: return( MTTCAN_RAMSIZE_OBJECT_20 );
    case MTTCAN_BUFDL_24: return( MTTCAN_RAMSIZE_OBJECT_24 );
    case MTTCAN_BUFDL_32: return( MTTCAN_RAMSIZE_OBJECT_32 );
    case MTTCAN_BUFDL_48: return( MTTCAN_RAMSIZE_OBJECT_48 );
    case MTTCAN_BUFDL_64: return( MTTCAN_RAMSIZE_OBJECT_64 );
    default:            return( 0L );
  }
}

void MTTCAN_SetIDData( struct ee_mttcan_tx *Buffer,
                     struct ee_mttcan_tx *Message )
{
  u08 DataCount_u08;
  u08 DataCountMax_u08;
  
  if( Message->t1.dlc <= MTTCAN_DLC_CMAX )
  {
    DataCountMax_u08 = Message->t1.dlc;
    
    for( DataCount_u08 = 0;
         DataCount_u08 < DataCountMax_u08;
         DataCount_u08++ )
    {
      Buffer->d.b[ DataCount_u08 ] = Message->d.b[ DataCount_u08 ];
    }
  }
  else
  {
    switch( Message->t1.dlc )
    {
      case MTTCAN_DLC_FD_12: DataCountMax_u08 = 3; break;
      case MTTCAN_DLC_FD_16: DataCountMax_u08 = 4; break;
      case MTTCAN_DLC_FD_20: DataCountMax_u08 = 5; break;
      case MTTCAN_DLC_FD_24: DataCountMax_u08 = 6; break;
      case MTTCAN_DLC_FD_32: DataCountMax_u08 = 8; break;
      case MTTCAN_DLC_FD_48: DataCountMax_u08 = 12; break;
      case MTTCAN_DLC_FD_64: DataCountMax_u08 = 16; break;
      default:             DataCountMax_u08 = 0; break;
    }

    for( DataCount_u08 = 0;
         DataCount_u08 < DataCountMax_u08;
         DataCount_u08++ )
    {
      Buffer->d.lw[ DataCount_u08 ] = Message->d.lw[ DataCount_u08 ];
    }
  }
  
  if( Message->t0.xtd == MTTCAN_ID_STD )
  {
    //¡§¡§????a?????¡§C1???????????o??€?1????£¤¡§¡§???1??????????
    Buffer->t0.id = ( Message->t0.id << MTTCAN_ID_STD_SHIFT );
  }
  else
  {
    Buffer->t0.id = Message->t0.id;
  }

  Buffer->t0.rtr   = Message->t0.rtr;
  Buffer->t0.xtd   = Message->t0.xtd;
  Buffer->t0.esi   = Message->t0.esi;
  Buffer->t1.efc   = Message->t1.efc;
  Buffer->t1.dlc   = Message->t1.dlc;
  Buffer->t1.mm    = Message->t1.mm;
  Buffer->t1.brs   = Message->t1.brs;
  Buffer->t1.fdf   = Message->t1.fdf;
}

void MTTCAN_GetMessage( struct ee_mttcan_rx *Buffer,
                      struct ee_mttcan_rx *Message,
                      u08                MaxDataLength_u08 )
{
  u08 DataCount_u08;
  u08 DataCountMax_u08;
  
  Message->r1.rxts = Buffer->r1.rxts;
  Message->r1.fidx = Buffer->r1.fidx;
  Message->r1.dlc  = Buffer->r1.dlc;
  Message->r1.fdf  = Buffer->r1.fdf;
  Message->r1.brs  = Buffer->r1.brs;
  Message->r1.anmf = Buffer->r1.anmf;
  
  Message->r0.rtr  = Buffer->r0.rtr;
  Message->r0.xtd  = Buffer->r0.xtd;
  Message->r0.esi  = Buffer->r0.esi;
  
  if( Message->r0.xtd == MTTCAN_ID_STD )
  {
    Message->r0.id = ( Buffer->r0.id >> MTTCAN_ID_STD_SHIFT );
  }
  else
  {
    Message->r0.id = Buffer->r0.id;
  }  

  if( Message->r1.dlc <= MTTCAN_DLC_CMAX )
  {
    DataCountMax_u08 = Message->r1.dlc;
    //
    for( DataCount_u08 = 0;
         DataCount_u08 < 64;
         DataCount_u08++ )
    {
      Message->d.b[ DataCount_u08 ] = 0;
    }  
    //
    for( DataCount_u08 = 0;
         DataCount_u08 < DataCountMax_u08;
         DataCount_u08++ )
    {
      Message->d.b[ DataCount_u08 ] = ( u08 )( Buffer->d.b[ DataCount_u08 ] );
    }  
  }
  else
  {
    switch( Message->r1.dlc )
    {
      case MTTCAN_DLC_FD_12: DataCountMax_u08 = 12; break;
      case MTTCAN_DLC_FD_16: DataCountMax_u08 = 16; break;
      case MTTCAN_DLC_FD_20: DataCountMax_u08 = 20; break;
      case MTTCAN_DLC_FD_24: DataCountMax_u08 = 24; break;
      case MTTCAN_DLC_FD_32: DataCountMax_u08 = 32; break;
      case MTTCAN_DLC_FD_48: DataCountMax_u08 = 48; break;
      case MTTCAN_DLC_FD_64: DataCountMax_u08 = 64; break;
      default:             DataCountMax_u08 = 0; break;
    }

    for( DataCount_u08 = 0;
         DataCount_u08 < 64;
         DataCount_u08++ )
    {
      Message->d.b[ DataCount_u08 ] = 0;
    }  
    //
    for( DataCount_u08 = 0;
         DataCount_u08 < DataCountMax_u08;
         DataCount_u08++ )
    {
      Message->d.b[ DataCount_u08 ] = ( u08 )( Buffer->d.b[ DataCount_u08 ] );
    }  
    /*if( DataCountMax_u08 > MaxDataLength_u08 )
      DataCountMax_u08 = MaxDataLength_u08;

    for( DataCount_u08 = 0;
         DataCount_u08 < DataCountMax_u08;
         DataCount_u08++ )
    {
      Message->d.lw[ DataCount_u08 ] = ( u08 )( Buffer->d.lw[ DataCount_u08 ] );
    }  */
  }  
}

/*
 * The interrupt Functions
 */

//=============================================================================
// FunctionName: MTTCAN_Interrupt
// IN  :         -
// OUT :         -
// Description : Central Interrupt Entry, clears pending bits and stores status
// 
//=============================================================================

void MTTCAN_Interrupt( )
{
  u32 InterruptLineMask_u32;
  
  if( ( MTTCAN_InterruptFlag_Line_u08 != MTTCAN_INT_NOINT ) && 
      ( MTTCAN_InterruptFlag_Unit_u08 != MTTCAN_INVALID ) )
  {
    MTTCAN_CIVector[ MTTCAN_InterruptFlag_Unit_u08 * MTTCAN_INT_LINES + 
                   MTTCAN_InterruptFlag_Line_u08 ]( );

    if( MTTCAN_InterruptFlag_Line_u08 != MTTCAN_INT_LINE_FE )
    {
      InterruptLineMask_u32 = ee_mttcan_common_p[ MTTCAN_InterruptFlag_Unit_u08 ]->ils;
      
      if( MTTCAN_InterruptFlag_Line_u08 == MTTCAN_INT_LINE_0 )
      {
        InterruptLineMask_u32 = ~InterruptLineMask_u32;
      }
      
      ee_mttcan_common_p[ MTTCAN_InterruptFlag_Unit_u08 ]->ir = InterruptLineMask_u32;
    }

    MTTCAN_InterruptFlag_Line_u08 = MTTCAN_INT_NOINT;
    MTTCAN_InterruptFlag_Unit_u08 = MTTCAN_INVALID;
  }
}

/*
 * The peripheral Support Functions
 */

//=============================================================================
// FunctionName: MTTCAN_PortEnable
// IN  : UnitNumber: Selected Macro
// OUT : Error Flag
// Description : 
// Enable AFCAN I/O ports
//=============================================================================
bit MTTCAN_PortEnable( u08 UnitNumber_u08 )
{
  if( UnitNumber_u08 >= MTTCAN_MACROS ) return( MTTCAN_ERROR );

  switch( UnitNumber_u08 ) 
  {
    case MTTCAN_0:

#ifdef MTTCAN_PORT_M0RX
      PORT_Enable( MTTCAN_PORT_M0RX, MTTCAN_PORT_BIT_M0RX,
                   PORT_DIR_INPUT, PORT_MODE_PERIPHERAL, 
                   MTTCAN_PORT_FUNC_M0RX );
      PORT_Enable( MTTCAN_PORT_M0TX, MTTCAN_PORT_BIT_M0TX,
                   PORT_DIR_OUTPUT, PORT_MODE_PERIPHERAL, 
                   MTTCAN_PORT_FUNC_M0TX );
      break;
#endif

    case MTTCAN_1:

#ifdef MTTCAN_PORT_M1RX
      PORT_Enable( MTTCAN_PORT_M1RX, MTTCAN_PORT_BIT_M1RX,
                   PORT_DIR_INPUT, PORT_MODE_PERIPHERAL, 
                   MTTCAN_PORT_FUNC_M1RX );
      PORT_Enable( MTTCAN_PORT_M1TX, MTTCAN_PORT_BIT_M1TX,
                   PORT_DIR_OUTPUT, PORT_MODE_PERIPHERAL, 
                   MTTCAN_PORT_FUNC_M1TX );
      break;
#endif

    case MTTCAN_2:

#ifdef MTTCAN_PORT_M2RX
      PORT_Enable( MTTCAN_PORT_M2RX, MTTCAN_PORT_BIT_M2RX,
                   PORT_DIR_INPUT, PORT_MODE_PERIPHERAL, 
                   MTTCAN_PORT_FUNC_M2RX );
      PORT_Enable( MTTCAN_PORT_M2TX, MTTCAN_PORT_BIT_M2TX,
                   PORT_DIR_OUTPUT, PORT_MODE_PERIPHERAL, 
                   MTTCAN_PORT_FUNC_M2TX );
      break;
#endif

    default: 
      return( MTTCAN_ERROR );

  } // switch( UnitNumber )

    return( MTTCAN_OK );
}
    
//=============================================================================
// FunctionName: MTTCAN_PortDisable
// IN  : UnitNumber: Selected Macro
// OUT : Error Flag
// Description : 
// Release AFCAN I/O ports to normal port function
//=============================================================================
bit MTTCAN_PortDisable( u08 UnitNumber_u08 )
{
  if( UnitNumber_u08 >= MTTCAN_MACROS ) return( MTTCAN_ERROR );

  switch( UnitNumber_u08 ) 
  {
    case MTTCAN_0:
            
#ifdef MTTCAN_PORT_M0RX
      PORT_Disable( MTTCAN_PORT_M0RX, MTTCAN_PORT_BIT_M0RX );
      PORT_Disable( MTTCAN_PORT_M0TX, MTTCAN_PORT_BIT_M0TX );
      break;
#endif

    case MTTCAN_1:

#ifdef MTTCAN_PORT_M1RX
      PORT_Disable( MTTCAN_PORT_M1RX, MTTCAN_PORT_BIT_M1RX );
      PORT_Disable( MTTCAN_PORT_M1TX, MTTCAN_PORT_BIT_M1TX );
      break;
#endif

    case MTTCAN_2:

#ifdef MTTCAN_PORT_M2RX
      PORT_Disable( MTTCAN_PORT_M2RX, MTTCAN_PORT_BIT_M2RX );
      PORT_Disable( MTTCAN_PORT_M2TX, MTTCAN_PORT_BIT_M2TX );
      break;
#endif

    default: 
      return( MTTCAN_ERROR );

  } // switch( UnitNumber )
    
  return( MTTCAN_OK );
}

//=============================================================================
// FunctionName: MTTCAN_CreateInterrupt
// IN  :         Unit Number, Int Line Number, Int Level, 
//               Int Function Vector
// OUT :         Success Status
// Description : Enables and Sets Interrupt Vector to given Function
// 
//=============================================================================
bit MTTCAN_CreateInterrupt( u08  UnitNumber_u08,
                          u08  IntLineNumber_u08,
                          u16  SetIntLevel_u16,
                          void ( *FunctionVector )( ) )
{
  u16 IntLevel_u16 = SetIntLevel_u16;

  if( UnitNumber_u08 >= MTTCAN_MACROS ) return( MTTCAN_ERROR );
  if( FunctionVector == NULL ) 
  {
    IntLevel_u16 = MTTCAN_INTCLEAR;
    FunctionVector = MTTCAN_IRQDefault;
  }
  
  MTTCAN_CIVector[ UnitNumber_u08 * MTTCAN_INT_LINES + IntLineNumber_u08 ] = FunctionVector;

  switch( UnitNumber_u08 )
  {
  	case MTTCAN_0:
    	switch( IntLineNumber_u08 ) 
    	{

#if( defined( MTTCAN_INT_M0LINE0 ) )
    	  case MTTCAN_INT_LINE_0:
    	    MTTCAN_INT_M0LINE0 = IntLevel_u16;
    	    break;
#endif
#if( defined( MTTCAN_INT_M0LINE1 ) )
    	  case MTTCAN_INT_LINE_1:
    	    MTTCAN_INT_M0LINE1 = IntLevel_u16;
    	    break;
#endif
#if( defined( MTTCAN_INT_M0LINEFE ) )
    	  case MTTCAN_INT_LINE_FE:
    	    MTTCAN_INT_M0LINEFE = IntLevel_u16;
    	    break;
#endif
//¡§¡§????a?????¡§C1¡§¡§|????????????2?????¡§|?a?¡§|?¨¦?
  	    default:
  		    return( MTTCAN_ERROR );
      }
      break;

  	case MTTCAN_1:
    	switch( IntLineNumber_u08 ) 
    	{

#if( defined( MTTCAN_INT_M1LINE0 ) )
    	  case MTTCAN_INT_LINE_0:
    	    MTTCAN_INT_M1LINE0 = IntLevel_u16;
    	    break;
#endif
#if( defined( MTTCAN_INT_M1LINE1 ) )
    	  case MTTCAN_INT_LINE_1:
    	    MTTCAN_INT_M1LINE1 = IntLevel_u16;
    	    break;
#endif
#if( defined( MTTCAN_INT_M1LINEFE ) )
    	  case MTTCAN_INT_LINE_FE:
    	    MTTCAN_INT_M1LINEFE = IntLevel_u16;
    	    break;
#endif
  	    default:
  		    return( MTTCAN_ERROR );
      }
      break;

  	case MTTCAN_2:
    	switch( IntLineNumber_u08 ) 
    	{

#if( defined( MTTCAN_INT_M2LINE0 ) )
    	  case MTTCAN_INT_LINE_0:
    	    MTTCAN_INT_M2LINE0 = IntLevel_u16;
    	    break;
#endif
#if( defined( MTTCAN_INT_M2LINE1 ) )
    	  case MTTCAN_INT_LINE_1:
    	    MTTCAN_INT_M2LINE1 = IntLevel_u16;
    	    break;
#endif
#if( defined( MTTCAN_INT_M2LINEFE ) )
    	  case MTTCAN_INT_LINE_FE:
    	    MTTCAN_INT_M2LINEFE = IntLevel_u16;
    	    break;
#endif
  	    default:
  		    return( MTTCAN_ERROR );
      }
      break;

    default:
	    return( MTTCAN_ERROR );
  }
  return( MTTCAN_OK );
}

//=============================================================================
// FunctionName: MTTCAN_SetInterrupt
// IN  :         UnitNumber, Int Type, Int Line, Int Enable
// OUT :         Success Status
// Description : Enables or disables dedicated Interrupts
// 
//=============================================================================
bit MTTCAN_SetInterrupt( u08 UnitNumber_u08,
                           u32 InterruptType_u32,
                           u08 InterruptLineSelection_u08,
                           bit InterruptEnable_bit )
{
  u32 InterruptMask_u32;
  
  if( UnitNumber_u08 >= MTTCAN_MACROS ) return( MTTCAN_ERROR );

  InterruptMask_u32 = InterruptType_u32;
  if( !InterruptEnable_bit ) 
  {
    InterruptMask_u32 = ~InterruptMask_u32;
     ee_mttcan_common_p[ UnitNumber_u08 ]->ie &= InterruptMask_u32;
  }
  else
  {
    if( InterruptLineSelection_u08 == MTTCAN_INT_LINE_0 )
    {
      ee_mttcan_common_p[ UnitNumber_u08 ]->ils &= ( ~InterruptMask_u32 );
    }
    else
    {
      ee_mttcan_common_p[ UnitNumber_u08 ]->ils |= InterruptMask_u32;
    }
    ee_mttcan_common_p[ UnitNumber_u08 ]->ie |= InterruptMask_u32;
    ee_mttcan_common_p[ UnitNumber_u08 ]->ile.eint |= ( 1 << InterruptLineSelection_u08 );
  }
  return( MTTCAN_OK );
}

//=============================================================================
// FunctionName: MTTCAN_GetStatus
// IN  :         UnitNumber
// OUT :         Success Status, Status Values
// Description : Returns status information flags
// 
//=============================================================================
bit MTTCAN_GetStatus( u08  UnitNumber_u08,
                 		u08  StatusNumber_u08,
                 		pu16 StatusValue_pu16 )
{
  u08 StatusLevel_u08;
  struct ee_mttcan_thl *TXEventPointer;

  if( UnitNumber_u08 >= MTTCAN_MACROS ) return( MTTCAN_ERROR );
    
  switch( StatusNumber_u08 )
  {
    case MTTCAN_STATUS_OPMODE:              /* Operation mode */
      if( ee_mttcan_common_p[ UnitNumber_u08 ]->cccr.init == MTTCAN_SET ) 
      {
        *StatusValue_pu16 = MTTCAN_OPMODE_INIT;
      }
      else 
      {
        if( ee_mttcan_common_p[ UnitNumber_u08 ]->cccr.fdoe == MTTCAN_SET )
        {
          *StatusValue_pu16 = MTTCAN_OPMODE_CANFD;
          if( ee_mttcan_common_p[ UnitNumber_u08 ]->cccr.brse == MTTCAN_SET )
          {
            *StatusValue_pu16 = MTTCAN_OPMODE_CANFDBRS;
          }
        }
        else
        {
          *StatusValue_pu16 = MTTCAN_OPMODE_CLASSIC;
        }
      }
      break;  
      
    case MTTCAN_STATUS_SPMODE:              /* Special mode */
      *StatusValue_pu16 = MTTCAN_SPMODE_NONE;
      if( ee_mttcan_common_p[ UnitNumber_u08 ]->cccr.test == MTTCAN_SET )
        *StatusValue_pu16 |= MTTCAN_SPMODE_STEST;
      if( ee_mttcan_common_p[ UnitNumber_u08 ]->cccr.dar == MTTCAN_SET )
        *StatusValue_pu16 |= MTTCAN_SPMODE_SSHOT;
      if( ee_mttcan_common_p[ UnitNumber_u08 ]->cccr.mon == MTTCAN_SET )
        *StatusValue_pu16 |= MTTCAN_SPMODE_RECONLY;
      break;

    case MTTCAN_STATUS_PSMODE:              /* Power mode */
      if( ee_mttcan_common_p[ UnitNumber_u08 ]->cccr.csa == MTTCAN_SET )
        *StatusValue_pu16 = MTTCAN_PSMODE_STOP;
      else
        *StatusValue_pu16 = MTTCAN_PSMODE_RUN;
      break;  
            
    case MTTCAN_STATUS_RECEIVE:        /* indicates channel is receiving */
		  if( ee_mttcan_common_p[ UnitNumber_u08 ]->psr.act == MTTCAN_ACT_RECEIVE )
  	  	*StatusValue_pu16 = MTTCAN_SET;
  	  else 
  	    *StatusValue_pu16 = MTTCAN_CLEAR;
      break;
            
    case MTTCAN_STATUS_TRANSMIT:        /* indicates channel is sending */
		  if( ee_mttcan_common_p[ UnitNumber_u08 ]->psr.act == MTTCAN_ACT_TRANSMIT )
  	  	*StatusValue_pu16 = MTTCAN_SET;
  	  else 
  	    *StatusValue_pu16 = MTTCAN_CLEAR;
      break;
            
    case MTTCAN_STATUS_BUSOFF:         /* indicates channel is bus off */
		  if( ee_mttcan_common_p[ UnitNumber_u08 ]->psr.bo == MTTCAN_SET )
  	  	*StatusValue_pu16 = MTTCAN_SET;
  	  else 
  	    *StatusValue_pu16 = MTTCAN_CLEAR;  	  	
      break;

    case MTTCAN_STATUS_ERRCNTLEV:                       /* error level */
      *StatusValue_pu16 = MTTCAN_ERROR_ACTIVE;
		  if( ee_mttcan_common_p[ UnitNumber_u08 ]->psr.ew == MTTCAN_SET )
		    *StatusValue_pu16 = MTTCAN_ERROR_WARNING;
		  if( ee_mttcan_common_p[ UnitNumber_u08 ]->psr.ep == MTTCAN_SET )
		    *StatusValue_pu16 = MTTCAN_ERROR_PASSIVE;
		  if( ee_mttcan_common_p[ UnitNumber_u08 ]->psr.bo == MTTCAN_SET )
		    *StatusValue_pu16 = MTTCAN_ERROR_BUSOFF;
      break;
            
    case MTTCAN_STATUS_TOVF:        /* send history overrun flag, clears overflow */
 	  	*StatusValue_pu16 = ( u08 )( ee_mttcan_common_p[ UnitNumber_u08 ]->txefs.tefl );
	    if( *StatusValue_pu16 == MTTCAN_SET )
	    {
	      StatusLevel_u08 = ( u08 )( ee_mttcan_common_p[ UnitNumber_u08 ]->txefs.efpi );
	      if( StatusLevel_u08 == 0 ) StatusLevel_u08 = MTTCAN_MAXTXEVENTS;
	      StatusLevel_u08--;
				ee_mttcan_common_p[ UnitNumber_u08 ]->txefa.efai = ( u32 )StatusLevel_u08;
	    }
	    break;

    case MTTCAN_STATUS_THPM:                 /* send history empty flag */
		  if( ee_mttcan_common_p[ UnitNumber_u08 ]->txefs.effl == 0L )
  	  	*StatusValue_pu16 = MTTCAN_SET;
  	  else
  	    *StatusValue_pu16 = MTTCAN_CLEAR; 
      break;

    case MTTCAN_STATUS_TGPT:                    /* send history pointer */
      StatusLevel_u08 = ( u08 )( ee_mttcan_common_p[ UnitNumber_u08 ]->txefs.efgi );
    	if( ee_mttcan_common_p[ UnitNumber_u08 ]->txefs.effl != 0L )
    	{
    	  TXEventPointer = ( struct ee_mttcan_thl* )
    	                   ( ee_mttcan_ram_p[ UnitNumber_u08 ][ MTTCAN_RAMSECTION_THL ] +
    	                   ( u32 )( StatusLevel_u08 * MTTCAN_RAMSIZE_THL ) );
    	  *StatusValue_pu16 = ( u16 )( TXEventPointer->e1.mm );
    	}
    	else
    	{
    	  return( MTTCAN_ERROR );
    	}
      break;
            
    case MTTCAN_STATUS_TXTS:                    /* send TX Timestamp */
      StatusLevel_u08 = ( u08 )( ee_mttcan_common_p[ UnitNumber_u08 ]->txefs.efgi );
    	if( ee_mttcan_common_p[ UnitNumber_u08 ]->txefs.effl != 0L )
    	{
    	  TXEventPointer = ( struct ee_mttcan_thl* )
    	                   ( ee_mttcan_ram_p[ UnitNumber_u08 ][ MTTCAN_RAMSECTION_THL ] +
    	                   ( u32 )( StatusLevel_u08 * MTTCAN_RAMSIZE_THL ) );
    	  *StatusValue_pu16 = ( u16 )( TXEventPointer->e1.txts );
    	}
    	else
    	{
    	  return( MTTCAN_ERROR );
    	}
      break;

    case MTTCAN_STATUS_NEWTXHISTORY:               /* get next THL entry */
      StatusLevel_u08 = ( u08 )( ee_mttcan_common_p[ UnitNumber_u08 ]->txefs.efgi );
      ee_mttcan_common_p[ UnitNumber_u08 ]->txefa.efai = ( u32 )StatusLevel_u08;
      break;

    case MTTCAN_STATUS_VALID:        /* channel has synchronized sucessfully */
      if( ee_mttcan_common_p[ UnitNumber_u08 ]->psr.act != 0L )
  	  	*StatusValue_pu16 = MTTCAN_SET;
  	  else
  	    *StatusValue_pu16 = MTTCAN_CLEAR; 
      break;
            
    case MTTCAN_STATUS_TRERRCOUNT:       /* transmit error counter value */
  	  	*StatusValue_pu16 = ( u16 )( ee_mttcan_common_p[ UnitNumber_u08 ]->ecr.tec );
      break;

    case MTTCAN_STATUS_RXERRCOUNT:       /* receive error counter value */
  	  	*StatusValue_pu16 = ( u16 )( ee_mttcan_common_p[ UnitNumber_u08 ]->ecr.rec );
      break;
            
    case MTTCAN_STATUS_ERRPLEV:                /* error counter passive */
  	  	*StatusValue_pu16 = ( u16 )( ee_mttcan_common_p[ UnitNumber_u08 ]->psr.ep );
      break;

    case MTTCAN_STATUS_MLT_RXFIFO0:
        *StatusValue_pu16 = ( u16 )( ee_mttcan_common_p[ UnitNumber_u08 ]->rxf0s.rfl );
        break;

    case MTTCAN_STATUS_MLT_RXFIFO1:
        *StatusValue_pu16 = ( u16 )( ee_mttcan_common_p[ UnitNumber_u08 ]->rxf1s.rfl );
        break;

    case MTTCAN_STATUS_ERRCODE_CLAR:     /* error detail classical/arbitration */
  	  	*StatusValue_pu16 = ( u16 )( ee_mttcan_common_p[ UnitNumber_u08 ]->psr.lec );
      break;

    case MTTCAN_STATUS_ERRCODE_FDAT:      /* error detail FD data phase */
  	  	*StatusValue_pu16 = ( u16 )( ee_mttcan_common_p[ UnitNumber_u08 ]->psr.dlec );
      break;

    default: return( MTTCAN_ERROR );

  } // end switch( StatusNumber_u08 )
    
  //__asm( "syncp" );
  return( MTTCAN_OK );
}    

//=============================================================================
// FunctionName: MTTCAN_Start
// IN  :         UnitNumber, Operation Mode, Timer Settings
// OUT :         Success Status
// Description : Activates CAN Unit from any stop/sleep mode
// 
//=============================================================================
bit MTTCAN_Start( u08 UnitNumber_u08,
                u08 OperationMode_u08,
                u16 TimeStampSetting_u16,
                u16 TimeOutSetting_u16 )
{
  u32 AccessTimeout_u32 = MTTCAN_SHUTDOWNTIMEOUT; 

  if( UnitNumber_u08 >= MTTCAN_MACROS ) return( MTTCAN_ERROR );
    
  /* Must be in INIT mode to set operation mode and start  */
  
  if( ee_mttcan_common_p[ UnitNumber_u08 ]->cccr.init == MTTCAN_CLEAR )
    return( MTTCAN_ERROR );

  /* Timestamp counter setting, optionally just this and no more */
   
  if( TimeStampSetting_u16 )
  {
  	ee_mttcan_common_p[ UnitNumber_u08 ]->tscv.tsc = MTTCAN_CLEAR;
  	if( OperationMode_u08 == MTTCAN_OPMODE_KEEP )
  	{
  	  return( MTTCAN_OK );
  	}
  }
  
  /* activate the unit from stop */
    
  if( ee_mttcan_common_p[ UnitNumber_u08 ]->cccr.csa )
  {
    AccessTimeout_u32 = MTTCAN_SHUTDOWNTIMEOUT;
    ee_mttcan_common_p[ UnitNumber_u08 ]->cccr.csr = MTTCAN_PSMODE_RUN;
    //__asm( "syncp" );
    while( ( ee_mttcan_common_p[ UnitNumber_u08 ]->cccr.csa != MTTCAN_PSMODE_RUN )
             && ( --AccessTimeout_u32 > 0 ) );
    if( AccessTimeout_u32 == 0L ) return( MTTCAN_ERROR );
  }

  /* Timeout Counter Setting */
   
  if( TimeOutSetting_u16 )
  {
    AccessTimeout_u32 = MTTCAN_SHUTDOWNTIMEOUT;
    ee_mttcan_common_p[ UnitNumber_u08 ]->tocc.top = ( u32 )TimeOutSetting_u16;
    ee_mttcan_common_p[ UnitNumber_u08 ]->cccr.cce = MTTCAN_SET;
    //__asm( "syncp" );
    while( ( ee_mttcan_common_p[ UnitNumber_u08 ]->cccr.cce != MTTCAN_SET )
             && ( --AccessTimeout_u32 > 0 ) );
    if( AccessTimeout_u32 == 0L ) return( MTTCAN_ERROR );

    AccessTimeout_u32 = MTTCAN_SHUTDOWNTIMEOUT;
    ee_mttcan_common_p[ UnitNumber_u08 ]->cccr.cce = MTTCAN_CLEAR;
    //__asm( "syncp" );
    while( ( ee_mttcan_common_p[ UnitNumber_u08 ]->cccr.cce != MTTCAN_CLEAR )
             && ( --AccessTimeout_u32 > 0 ) );
    if( AccessTimeout_u32 == 0L ) return( MTTCAN_ERROR );
  }
 
  
  /* Special Operation Mode Options */

  if( ( OperationMode_u08 & MTTCAN_SPMODE ) != MTTCAN_SPMODE_NONE )
  {
    if( ( OperationMode_u08 & MTTCAN_SPMODE_RECONLY ) == MTTCAN_SPMODE_RECONLY )
    {
      ee_mttcan_common_p[ UnitNumber_u08 ]->cccr.cce = MTTCAN_SET;
      ee_mttcan_common_p[ UnitNumber_u08 ]->cccr.mon = MTTCAN_SET;
    }
    if( ( OperationMode_u08 & MTTCAN_SPMODE_STEST ) == MTTCAN_SPMODE_STEST )
    {
      ee_mttcan_common_p[ UnitNumber_u08 ]->cccr.test = MTTCAN_SET;
      ee_mttcan_common_p[ UnitNumber_u08 ]->test.lbck = MTTCAN_SET;
    }
    if( ( OperationMode_u08 & MTTCAN_SPMODE_SSHOT ) == MTTCAN_SPMODE_SSHOT )
    {
      ee_mttcan_common_p[ UnitNumber_u08 ]->cccr.dar = MTTCAN_SET;
    }
    if( ( OperationMode_u08 & MTTCAN_SPMODE_RESTRICT ) == MTTCAN_SPMODE_RESTRICT )
    {
      ee_mttcan_common_p[ UnitNumber_u08 ]->cccr.cce = MTTCAN_SET;
      ee_mttcan_common_p[ UnitNumber_u08 ]->cccr.rom = MTTCAN_SET;
    }
  }
  else
  {
    ee_mttcan_common_p[ UnitNumber_u08 ]->cccr.cce  = MTTCAN_SET;
    ee_mttcan_common_p[ UnitNumber_u08 ]->cccr.mon  = MTTCAN_CLEAR;
    ee_mttcan_common_p[ UnitNumber_u08 ]->cccr.test = MTTCAN_CLEAR;
    ee_mttcan_common_p[ UnitNumber_u08 ]->cccr.dar  = MTTCAN_CLEAR;
    ee_mttcan_common_p[ UnitNumber_u08 ]->cccr.rom  = MTTCAN_CLEAR;
  } 
  
  
  switch( ( OperationMode_u08 & MTTCAN_OPMODE ) )
  {
    case MTTCAN_OPMODE_INIT:
    case MTTCAN_OPMODE_KEEP:
      break;
      
    case MTTCAN_OPMODE_CLASSIC:
      ee_mttcan_common_p[ UnitNumber_u08 ]->cccr.fdoe = MTTCAN_CLEAR;
      ee_mttcan_common_p[ UnitNumber_u08 ]->cccr.brse = MTTCAN_CLEAR;
      break;

    case MTTCAN_OPMODE_CANFD:
      ee_mttcan_common_p[ UnitNumber_u08 ]->cccr.fdoe = MTTCAN_SET;
      ee_mttcan_common_p[ UnitNumber_u08 ]->cccr.brse = MTTCAN_CLEAR;
      break;

    case MTTCAN_OPMODE_CANFDBRS:
      ee_mttcan_common_p[ UnitNumber_u08 ]->cccr.fdoe = MTTCAN_SET;
      ee_mttcan_common_p[ UnitNumber_u08 ]->cccr.brse = MTTCAN_SET;
      break;

    default: return( MTTCAN_ERROR );
  } 
  
  
  
  /* Clear INIT mode - Start Operation */

  AccessTimeout_u32 = MTTCAN_SHUTDOWNTIMEOUT;                                            
  ee_mttcan_common_p[ UnitNumber_u08 ]->cccr.cce  = MTTCAN_CLEAR;
  //__asm( "syncp" );
	ee_mttcan_common_p[ UnitNumber_u08 ]->cccr.init = MTTCAN_CLEAR;
  //__asm( "syncp" );
  while( ( ee_mttcan_common_p[ UnitNumber_u08 ]->cccr.init != MTTCAN_CLEAR )
           && ( --AccessTimeout_u32 > 0 ) );
  if( AccessTimeout_u32 == 0L ) return( MTTCAN_ERROR );
  //__asm( "syncp" );

  if( AccessTimeout_u32 == 0L ) return( MTTCAN_ERROR );
  else return( MTTCAN_OK );    
}

//=============================================================================
// FunctionName: MTTCAN_Stop
// IN  :         UnitNumber, Stop Mode
// OUT :         Success Status
// Description : Sets CAN Channel into any init/stop mode
// 
//=============================================================================
bit MTTCAN_Stop( u08 UnitNumber_u08,
               u08 StopMode_u08 )
{
  u32 AccessTimeout_u32 = MTTCAN_SHUTDOWNTIMEOUT; 

  if( UnitNumber_u08 >= MTTCAN_MACROS ) return( MTTCAN_ERROR );

  switch( StopMode_u08 & MTTCAN_PSMODE )
  {
    case MTTCAN_PSMODE_RUN:
      break;
      
    case MTTCAN_PSMODE_INIT:
      
      /* workaround on m_(tt)can V3.0.1 issues #7, 10(#8, 11) */
      
      ee_mttcan_common_p[ UnitNumber_u08 ]->txbcr     = MTTCAN_TX_ABORTALL;
      ee_mttcan_common_p[ UnitNumber_u08 ]->cccr.csr  = MTTCAN_SET;
      //__asm( "syncp" );
      while( ( ee_mttcan_common_p[ UnitNumber_u08 ]->cccr.csa != MTTCAN_SET )
             && ( --AccessTimeout_u32 > 0 ) );
      ee_mttcan_common_p[ UnitNumber_u08 ]->cccr.csr  = MTTCAN_CLEAR;
      //__asm( "syncp" );
      ee_mttcan_common_p[ UnitNumber_u08 ]->cccr.init = MTTCAN_CLEAR;
      //__asm( "syncp" );
      //¡§¡§????a?????¡§C1??????????¡§|?a?¡§|?¨¦?
      while( ( ee_mttcan_common_p[ UnitNumber_u08 ]->cccr.init != MTTCAN_SET )
             && ( --AccessTimeout_u32 > 0 ) );
      ee_mttcan_common_p[ UnitNumber_u08 ]->cccr.csr  = MTTCAN_SET;
     // __asm( "syncp" );
      while( ( ee_mttcan_common_p[ UnitNumber_u08 ]->cccr.csa != MTTCAN_SET )
             && ( --AccessTimeout_u32 > 0 ) );
      ee_mttcan_common_p[ UnitNumber_u08 ]->cccr.csr  = MTTCAN_CLEAR;
      
      /* end of workaround */
      
      ee_mttcan_common_p[ UnitNumber_u08 ]->cccr.init = MTTCAN_SET;
     // __asm( "syncp" );
      while( ( ee_mttcan_common_p[ UnitNumber_u08 ]->cccr.init != MTTCAN_SET )
             && ( --AccessTimeout_u32 > 0 ) );
      break;
      
    case MTTCAN_PSMODE_STOP:
      ee_mttcan_common_p[ UnitNumber_u08 ]->cccr.csr = MTTCAN_SET;
     //__asm( "syncp" );
      while( ( ee_mttcan_common_p[ UnitNumber_u08 ]->cccr.csa != MTTCAN_SET )
             && ( --AccessTimeout_u32 > 0 ) );
      break;
      
    default:
      return( MTTCAN_ERROR );
  }

  if( AccessTimeout_u32 == 0L ) return( MTTCAN_ERROR );
  else return( MTTCAN_OK );
}    

//=============================================================================
// FunctionName: MTTCAN_SetBittiming
// IN  :         InputFrequency, Bitrate, TQ per Bit, Sampling Point, SJW
// OUT :         Bit Rate Prescaler Setting, Bit Timing
// Description : Calculates Settings from Clock Supply and Parameters
// 
//=============================================================================

bit MTTCAN_SetBittiming( u08  UnitNumber_u08,
                       u32  InputFrequency_u32,
                       u32  Bitrate_u32,
                       bit  Timingspec_bit,
                       pu16 BRPSetting_pu16,
                       pu08 TSEG1Setting_pu08,
                       pu08 TSEG2Setting_pu08,
                       pu08 SJWSetting_pu08,
                       flt  SamplingPointPos_flt ) // optional Parameter, can be 0.0
{
  u16 TQPerBitUsed_u16;
  u16 TQPerBitMinDeviation_u16;
  u16 BRPSettingUsed_u16;
  u08 TSEG1SettingUsed_u16;
  u08 TSEG2SettingUsed_u16;
  flt SamplingPointPosUsed_flt = SamplingPointPos_flt;
  u32 BitrateAchieved_u32;
  s32 MinBitrateDeviation_s32;
  s32 BitrateDeviation_s32;

  /* Automatic settings generation */
 //??a?¡§|?a??¡§|????¡§C????-????£¤???¡ì??¡ãa???????
  TQPerBitUsed_u16 = ( u16 )( InputFrequency_u32 / 
                            ( Bitrate_u32 * MTTCAN_TRLAYERFACTOR ) );

//??€??a????¡ì????????¡¥-??¨¨????????a??a?¡§|?a??¡§|???-?
  if( Timingspec_bit == MTTCAN_BT_SPEC )
  {
    if( TQPerBitUsed_u16 > MTTCAN_BT_MAXTQ ) TQPerBitUsed_u16 = MTTCAN_BT_MAXTQ;
    if( TQPerBitUsed_u16 < MTTCAN_BT_MINTQ ) return( MTTCAN_ERROR );

    /* Minimum Bitrate check */
  
    if( ( InputFrequency_u32 / 
          ( ( u32 )TQPerBitUsed_u16 * MTTCAN_TRLAYERFACTOR * Bitrate_u32 ) ) >
          MTTCAN_BT_MAXBRP )
      return( MTTCAN_ERROR );
  }
  else
  {
    if( TQPerBitUsed_u16 > MTTCAN_BTD_MAXTQ ) TQPerBitUsed_u16 = MTTCAN_BTD_MAXTQ;
    if( TQPerBitUsed_u16 < MTTCAN_BTD_MINTQ ) return( MTTCAN_ERROR );

    /* Minimum Bitrate check */
  
    if( ( InputFrequency_u32 / 
          ( ( u32 )TQPerBitUsed_u16 * MTTCAN_TRLAYERFACTOR * Bitrate_u32 ) ) >
          MTTCAN_BTD_MAXBRP )
      return( MTTCAN_ERROR );
  }

  if( SamplingPointPos_flt == 0.0 ) SamplingPointPosUsed_flt = MTTCAN_BT_SPTOPTIMUM;

  /* Other plausibility checks */
  
  if( ( InputFrequency_u32 / Bitrate_u32 ) < MTTCAN_CLKMINFACTOR )
    return( MTTCAN_ERROR );
  
  /* Maximum Bitrate check */

  if( ( InputFrequency_u32 / 
        ( ( u32 )TQPerBitUsed_u16 * MTTCAN_TRLAYERFACTOR ) ) < Bitrate_u32 )
    return( MTTCAN_ERROR );

  /* Maximum Prescaler check */

  BRPSettingUsed_u16 = ( u16 )( InputFrequency_u32 / 
                              ( Bitrate_u32 *
                              ( u32 )TQPerBitUsed_u16 * 
                                MTTCAN_TRLAYERFACTOR ) );

  /* Frequency rounding optimization */
  
  BitrateAchieved_u32 = ( u32 )InputFrequency_u32 / 
    ( ( u32 ) ( ( u32 )BRPSettingUsed_u16 *
                ( u32 )TQPerBitUsed_u16 *
                ( u32 )MTTCAN_TRLAYERFACTOR ) );

  MinBitrateDeviation_s32 = ( s32 )( BitrateAchieved_u32 - Bitrate_u32 );
  if( MinBitrateDeviation_s32 < 0L ) 
    MinBitrateDeviation_s32 = -MinBitrateDeviation_s32;
  BitrateDeviation_s32    = MinBitrateDeviation_s32;

  while( BitrateAchieved_u32 != Bitrate_u32 )
    {
      TQPerBitUsed_u16--;
      if( Timingspec_bit == MTTCAN_BT_SPEC )
      {
        if( TQPerBitUsed_u16 < MTTCAN_BT_MINTQ ) break;
      }
      else
      {
        if( TQPerBitUsed_u16 < MTTCAN_BTD_MINTQ ) break;
      }
       
      BRPSettingUsed_u16 = ( u16 )( InputFrequency_u32 / 
                                  ( Bitrate_u32 *
                                  ( u32 )TQPerBitUsed_u16 * 
                                    MTTCAN_TRLAYERFACTOR ) );

      if( Timingspec_bit == MTTCAN_BT_SPEC )
      {
        if( BRPSettingUsed_u16 > MTTCAN_BT_MAXBRP )
          return( MTTCAN_ERROR );
      }          
      else
      {
        if( BRPSettingUsed_u16 > MTTCAN_BTD_MAXBRP )
          return( MTTCAN_ERROR );
      }
      
      BitrateAchieved_u32 = ( u32 )InputFrequency_u32 / 
                ( ( u32 ) ( ( u32 )BRPSettingUsed_u16 *
                            ( u32 )TQPerBitUsed_u16 *
                            ( u32 )MTTCAN_TRLAYERFACTOR ) );

      BitrateDeviation_s32 = ( s32 )( BitrateAchieved_u32 - Bitrate_u32 );
      if( BitrateDeviation_s32 < 0L ) BitrateDeviation_s32 = -BitrateDeviation_s32;
      if( BitrateDeviation_s32 < MinBitrateDeviation_s32 )
        {
          MinBitrateDeviation_s32  = BitrateDeviation_s32;
          TQPerBitMinDeviation_u16 = TQPerBitUsed_u16;
        }
    }
    
  if( BitrateAchieved_u32 != Bitrate_u32 )  /* Optimum Bitrate was not found */
    {
      TQPerBitUsed_u16 = TQPerBitMinDeviation_u16;   /* use the best value instead */
      BRPSettingUsed_u16 = ( u16 )( InputFrequency_u32 / 
                                  ( Bitrate_u32 *
                           ( u32 )TQPerBitUsed_u16 * 
                                  MTTCAN_TRLAYERFACTOR ) );
    }

  /* Sampling Point setting and segment splitting */
  /* Synchronisation Jump Width setting */
  
  if( Timingspec_bit == MTTCAN_BT_SPEC )
  {
    TSEG1SettingUsed_u16 = ( u16 )( ( flt )( TQPerBitUsed_u16 - MTTCAN_BT_SYNCSEGLEN ) 
                                    * SamplingPointPosUsed_flt );
    if( TSEG1SettingUsed_u16 < MTTCAN_BT_MINTSEG1 ) TSEG1SettingUsed_u16 = MTTCAN_BT_MINTSEG1;
    if( TSEG1SettingUsed_u16 > MTTCAN_BT_MAXTSEG1 ) TSEG1SettingUsed_u16 = MTTCAN_BT_MAXTSEG1;
  
    TSEG2SettingUsed_u16 = TQPerBitUsed_u16 - TSEG1SettingUsed_u16 - MTTCAN_BT_SYNCSEGLEN;
    if( TSEG2SettingUsed_u16 > MTTCAN_BT_MAXTSEG2 ) TSEG2SettingUsed_u16 = MTTCAN_BT_MAXTSEG2;
    if( TSEG2SettingUsed_u16 < MTTCAN_BT_MINTSEG2 ) TSEG2SettingUsed_u16 = MTTCAN_BT_MINTSEG2;
  
    TSEG1SettingUsed_u16 = TQPerBitUsed_u16 - TSEG2SettingUsed_u16 - MTTCAN_BT_SYNCSEGLEN;
    if( ( TSEG1SettingUsed_u16 < MTTCAN_BT_MINTSEG1 ) ||
        ( TSEG1SettingUsed_u16 > MTTCAN_BT_MAXTSEG1 ) ) return( MTTCAN_ERROR );
    
    /* Workaround for M_(TT)CAN issue #4(#5): 
     * BRP and TSEG2 shall not be zero at the same time
     */
    
    if( ( TSEG2SettingUsed_u16 == MTTCAN_BT_MINTSEG2 ) &&
        ( BRPSettingUsed_u16   == MTTCAN_BT_MINBRP ) ) return( MTTCAN_ERROR );
     
    /* end of workaround */
    
    *SJWSetting_pu08 = ( u08 )TSEG2SettingUsed_u16 - 1;
    if( *SJWSetting_pu08 >= MTTCAN_BT_MAXSJW )
  		*SJWSetting_pu08 = MTTCAN_BT_MAXSJW - 1;
  }
  else
  {
    TSEG1SettingUsed_u16 = ( u16 )( ( flt )( TQPerBitUsed_u16 - MTTCAN_BTD_SYNCSEGLEN ) 
                                    * SamplingPointPosUsed_flt );
    if( TSEG1SettingUsed_u16 < MTTCAN_BTD_MINTSEG1 ) TSEG1SettingUsed_u16 = MTTCAN_BTD_MINTSEG1;
    if( TSEG1SettingUsed_u16 > MTTCAN_BTD_MAXTSEG1 ) TSEG1SettingUsed_u16 = MTTCAN_BTD_MAXTSEG1;
  
    TSEG2SettingUsed_u16 = TQPerBitUsed_u16 - TSEG1SettingUsed_u16 - MTTCAN_BTD_SYNCSEGLEN;
    if( TSEG2SettingUsed_u16 > MTTCAN_BTD_MAXTSEG2 ) TSEG2SettingUsed_u16 = MTTCAN_BTD_MAXTSEG2;
    if( TSEG2SettingUsed_u16 < MTTCAN_BTD_MINTSEG2 ) TSEG2SettingUsed_u16 = MTTCAN_BTD_MINTSEG2;
  
    TSEG1SettingUsed_u16 = TQPerBitUsed_u16 - TSEG2SettingUsed_u16 - MTTCAN_BTD_SYNCSEGLEN;
    if( ( TSEG1SettingUsed_u16 < MTTCAN_BTD_MINTSEG1 ) ||
        ( TSEG1SettingUsed_u16 > MTTCAN_BTD_MAXTSEG1 ) ) return( MTTCAN_ERROR );
  
    *SJWSetting_pu08 = ( u08 )TSEG2SettingUsed_u16 - 1;
    if( *SJWSetting_pu08 >= MTTCAN_BTD_MAXSJW )
  		*SJWSetting_pu08 = MTTCAN_BTD_MAXSJW - 1;
  }
  
  /* Definition of Register Values */

  *BRPSetting_pu16   = ( u16 )( BRPSettingUsed_u16 - 1 );
  *TSEG1Setting_pu08 = ( u08 )( TSEG1SettingUsed_u16 - 1 );
  *TSEG2Setting_pu08 = ( u08 )( TSEG2SettingUsed_u16 - 1 );

  return( MTTCAN_OK );
}

//=============================================================================
// FunctionName: MTTCAN_SetConfiguration
// IN  :         UnitNumber, Configuration set
// OUT :         Error State Return: Bit timing failures, 
//                                   Not in INIT mode,
//                                   Not defined unit number,
//                                   Out of RAM bounds
// Description : Performs Configuration
// 
//=============================================================================

bit MTTCAN_SetConfiguration( u08  UnitNumber_u08,
                           const struct ee_mttcan_config *Config,
                           pu08 ErrorStatus_pu08 )
{    
  bit Status_bit;
  u32 RAMPointer_u32;
  u32 RAMPointer_Access_u32;
  u32 ClockFrequency_u32;
  u16 BRPSetting_u16;
  u08 TSEG1Setting_u08;
  u08 TSEG2Setting_u08;
  u08 SJWSetting_u08;
  u32 AccessTimeout_u32 = MTTCAN_SHUTDOWNTIMEOUT; 

  *ErrorStatus_pu08 = MTTCAN_CONFIG_ERROR_UNITNOTEXIST;
  if( UnitNumber_u08 >= MTTCAN_MACROS ) return( MTTCAN_ERROR );

  /* Must be in INIT mode to set the configuration! */
  
  //?|¨¬?¡§¡§?£¤??????a??€?¡§¡§????a?????¡§C1?????£¤??-????¡ì¡§¡§|???¨º€??¡ê¡è??€???
//  *ErrorStatus_pu08 = MTTCAN_CONFIG_ERROR_NOTININIT;
//  if( ee_mttcan_common_p[ UnitNumber_u08 ]->cccr.init == MTTCAN_CLEAR )
//    return( MTTCAN_ERROR );
    
//  /* Set Configuration Enable to access configuration settings */
  
//  *ErrorStatus_pu08 = MTTCAN_CONFIG_ERROR_HWTIMEOUT;
//  ee_mttcan_common_p[ UnitNumber_u08 ]->cccr.cce = MTTCAN_SET;
//  //__asm( "syncp" );
//  while( ( ee_mttcan_common_p[ UnitNumber_u08 ]->cccr.cce != MTTCAN_SET )
//         && ( --AccessTimeout_u32 > 0 ) );
//  if( AccessTimeout_u32 == 0L ) return( MTTCAN_ERROR ); //CANINIT IN Bootloader block this check
    
  /* Check configuration border conditions */
  
  *ErrorStatus_pu08 = MTTCAN_CONFIG_ERROR_BITTIMING;
  ClockFrequency_u32 = ( u32 )( OSCILLATOR_FREQUENCY * MTTCAN_FREQFACTOR );  //??a?¡§|?¡¥??????¨º€??¡ê¡è?????a?¡§|?¡¥????£¤??|???????¡§|?¨¦??
  if( Config->arb_bitrate > MTTCAN_MAXBAUDRATE ) return( MTTCAN_ERROR ); // ¡§¡§??????????????£¤?????¡ãa??¡ê¡è???
  if( Config->data_bitrate > MTTCAN_MAXBAUDRATE ) return( MTTCAN_ERROR );
    
  /* Configure bit rates */
  
  if( Config->arb_bitrate != 0L )
  {
    Status_bit = MTTCAN_SetBittiming( UnitNumber_u08,
                                    ClockFrequency_u32,
                                    Config->arb_bitrate,
                                    MTTCAN_BT_SPEC,
                                    &BRPSetting_u16,
                                    &TSEG1Setting_u08,
                                    &TSEG2Setting_u08,
                                    &SJWSetting_u08,
                                    Config->arb_samplingpointpos );
    if( Status_bit != MTTCAN_OK ) return( MTTCAN_ERROR );

    ee_mttcan_common_p[ UnitNumber_u08 ]->nbtp.nbrp   = ( u32 )BRPSetting_u16;
    ee_mttcan_common_p[ UnitNumber_u08 ]->nbtp.ntseg1 = ( u32 )TSEG1Setting_u08;
    ee_mttcan_common_p[ UnitNumber_u08 ]->nbtp.ntseg2 = ( u32 )TSEG2Setting_u08;
    ee_mttcan_common_p[ UnitNumber_u08 ]->nbtp.nsjw   = ( u32 )SJWSetting_u08;
  }
  else
  {
    ee_mttcan_common_p[ UnitNumber_u08 ]->nbtp.nbrp   = Config->nbtp.nbrp;
    ee_mttcan_common_p[ UnitNumber_u08 ]->nbtp.ntseg1 = Config->nbtp.ntseg1;
    ee_mttcan_common_p[ UnitNumber_u08 ]->nbtp.ntseg2 = Config->nbtp.ntseg2;
    ee_mttcan_common_p[ UnitNumber_u08 ]->nbtp.nsjw   = Config->nbtp.nsjw;
  }
    
  if( Config->data_bitrate != 0L )
  {
    Status_bit = MTTCAN_SetBittiming( UnitNumber_u08,
                                    ClockFrequency_u32,
                                    Config->data_bitrate,
                                    MTTCAN_BTD_SPEC,
                                    &BRPSetting_u16,
                                    &TSEG1Setting_u08,
                                    &TSEG2Setting_u08,
                                    &SJWSetting_u08,
                                    Config->data_samplingpointpos );
    if( Status_bit != MTTCAN_OK ) return( MTTCAN_ERROR );
      
    ee_mttcan_common_p[ UnitNumber_u08 ]->dbtp.dbrp   = ( u32 )BRPSetting_u16;
    ee_mttcan_common_p[ UnitNumber_u08 ]->dbtp.dtseg1 = ( u32 )TSEG1Setting_u08;
    ee_mttcan_common_p[ UnitNumber_u08 ]->dbtp.dtseg2 = ( u32 )TSEG2Setting_u08;
    ee_mttcan_common_p[ UnitNumber_u08 ]->dbtp.dsjw   = ( u32 )SJWSetting_u08;
  }
  else
  {
    ee_mttcan_common_p[ UnitNumber_u08 ]->dbtp.dbrp   = Config->dbtp.dbrp;
    ee_mttcan_common_p[ UnitNumber_u08 ]->dbtp.dtseg1 = Config->dbtp.dtseg1;
    ee_mttcan_common_p[ UnitNumber_u08 ]->dbtp.dtseg2 = Config->dbtp.dtseg2;
    ee_mttcan_common_p[ UnitNumber_u08 ]->dbtp.dsjw   = Config->dbtp.dsjw;
  }
  
  ee_mttcan_common_p[ UnitNumber_u08 ]->dbtp.tdc     = Config->dbtp.tdc;
  ee_mttcan_common_p[ UnitNumber_u08 ]->tdcr.tdcf    = Config->tdcr.tdcf;
  ee_mttcan_common_p[ UnitNumber_u08 ]->tdcr.tdco    = Config->tdcr.tdco;
  
  /* Copy other configuration settings into CAN controller register set */
  
  ee_mttcan_common_p[ UnitNumber_u08 ]->tscc.tss     = Config->tscc.tss;
  ee_mttcan_common_p[ UnitNumber_u08 ]->tscc.tcp     = Config->tscc.tcp;
  
  ee_mttcan_common_p[ UnitNumber_u08 ]->gfc.rrfe     = Config->gfc.rrfe;
  ee_mttcan_common_p[ UnitNumber_u08 ]->gfc.rrfs     = Config->gfc.rrfs;
  ee_mttcan_common_p[ UnitNumber_u08 ]->gfc.anfe     = Config->gfc.anfe;
  ee_mttcan_common_p[ UnitNumber_u08 ]->gfc.anfs     = Config->gfc.anfs;

  ee_mttcan_common_p[ UnitNumber_u08 ]->xidam.eidm   = Config->xidam.eidm;
  
  //¡§¡§???????a??£¤??-????¡ì?1??2?????¡§|?-???????????
  ee_mttcan_common_p[ UnitNumber_u08 ]->rxf0c.fwm    = Config->rxf0c.fwm;
  ee_mttcan_common_p[ UnitNumber_u08 ]->rxf0c.fom    = Config->rxf0c.fom;
  ee_mttcan_common_p[ UnitNumber_u08 ]->rxf1c.fwm    = Config->rxf1c.fwm;
  ee_mttcan_common_p[ UnitNumber_u08 ]->rxf1c.fom    = Config->rxf1c.fom;
  ee_mttcan_common_p[ UnitNumber_u08 ]->rxesc.f0ds   = Config->rxesc.f0ds;
  ee_mttcan_common_p[ UnitNumber_u08 ]->rxesc.f1ds   = Config->rxesc.f1ds;
  ee_mttcan_common_p[ UnitNumber_u08 ]->rxesc.rbds   = Config->rxesc.rbds;
  
  ee_mttcan_common_p[ UnitNumber_u08 ]->txbc.tfqm    = Config->txbc.tfqm;
  ee_mttcan_common_p[ UnitNumber_u08 ]->txesc.tbds   = Config->txesc.tbds;
  ee_mttcan_common_p[ UnitNumber_u08 ]->txefc.efwm   = Config->txefc.efwm;

  /* RAM Configuration */
  
  *ErrorStatus_pu08     = MTTCAN_CONFIG_ERROR_OUTOFRAM;
  RAMPointer_u32        = 0L;  /* the addressing from MTTCAN side is relative */
  RAMPointer_Access_u32 = ee_mttcan_ram_p[ UnitNumber_u08 ][ MTTCAN_RAMSECTION_BASE ];
  
  ee_mttcan_common_p[ UnitNumber_u08 ]->sidfc.flssa  = RAMPointer_u32;
  ee_mttcan_common_p[ UnitNumber_u08 ]->sidfc.lss    = ( u32 )Config->ram.mttcan_a_stdfilters_count;
  
  RAMPointer_u32 += ( u32 )( Config->ram.mttcan_a_stdfilters_count * 
                             MTTCAN_RAMSIZE_STDFILTER / 4 );
  if( RAMPointer_u32 >= ( ee_mttcan_ramsize_p[ UnitNumber_u08 ] / 4 ) ) 
    return( MTTCAN_ERROR );
  
  ee_mttcan_ram_p[ UnitNumber_u08 ][ MTTCAN_RAMSECTION_STDFILTER ] = RAMPointer_Access_u32;
  RAMPointer_Access_u32 += ( u32 )( Config->ram.mttcan_a_stdfilters_count * 
                                    MTTCAN_RAMSIZE_STDFILTER );
    
  ee_mttcan_common_p[ UnitNumber_u08 ]->xidfc.flesa  = RAMPointer_u32;
  ee_mttcan_common_p[ UnitNumber_u08 ]->xidfc.lse    = ( u32 )Config->ram.mttcan_a_extfilters_count;

  RAMPointer_u32 += ( u32 )( Config->ram.mttcan_a_extfilters_count * 
                             MTTCAN_RAMSIZE_EXTFILTER / 4 );
  if( RAMPointer_u32 >= ( ee_mttcan_ramsize_p[ UnitNumber_u08 ] / 4 ) ) 
    return( MTTCAN_ERROR );
    
  ee_mttcan_ram_p[ UnitNumber_u08 ][ MTTCAN_RAMSECTION_EXTFILTER ] = RAMPointer_Access_u32;
  RAMPointer_Access_u32 += ( u32 )( Config->ram.mttcan_a_extfilters_count * 
                                    MTTCAN_RAMSIZE_EXTFILTER );

  ee_mttcan_common_p[ UnitNumber_u08 ]->rxf0c.fsa    = RAMPointer_u32;
  ee_mttcan_common_p[ UnitNumber_u08 ]->rxf0c.fs     = ( u32 )Config->ram.mttcan_a_fifo0_size;

  RAMPointer_u32 += ( u32 )( Config->ram.mttcan_a_fifo0_size *  
                             MTTCAN_GetObjectSize( Config->rxesc.f0ds ) / 4 );
  if( RAMPointer_u32 >= ( ee_mttcan_ramsize_p[ UnitNumber_u08 ] / 4 ) ) 
    return( MTTCAN_ERROR );
    
  ee_mttcan_ram_p[ UnitNumber_u08 ][ MTTCAN_RAMSECTION_RXFIFO0 ] = RAMPointer_Access_u32;
  RAMPointer_Access_u32 += ( u32 )( Config->ram.mttcan_a_fifo0_size * 
                                    MTTCAN_GetObjectSize( Config->rxesc.f0ds ) );

  ee_mttcan_common_p[ UnitNumber_u08 ]->rxf1c.fsa    = RAMPointer_u32;
  ee_mttcan_common_p[ UnitNumber_u08 ]->rxf1c.fs     = ( u32 )Config->ram.mttcan_a_fifo1_size;

  RAMPointer_u32 += ( u32 )( Config->ram.mttcan_a_fifo1_size *  
                             MTTCAN_GetObjectSize( Config->rxesc.f1ds ) / 4 );
  if( RAMPointer_u32 >= ( ee_mttcan_ramsize_p[ UnitNumber_u08 ] / 4 ) ) 
    return( MTTCAN_ERROR );
    
  ee_mttcan_ram_p[ UnitNumber_u08 ][ MTTCAN_RAMSECTION_RXFIFO1 ] = RAMPointer_Access_u32;
  RAMPointer_Access_u32 += ( u32 )( Config->ram.mttcan_a_fifo1_size * 
                                    MTTCAN_GetObjectSize( Config->rxesc.f1ds ) );

  ee_mttcan_common_p[ UnitNumber_u08 ]->rxbc.rbsa    = RAMPointer_u32;

  RAMPointer_u32 += ( u32 )( Config->ram.mttcan_a_rxbuffers_count *  
                             MTTCAN_GetObjectSize( Config->rxesc.rbds ) / 4 );
  if( RAMPointer_u32 >= ( ee_mttcan_ramsize_p[ UnitNumber_u08 ] / 4 ) ) 
    return( MTTCAN_ERROR );
    
  ee_mttcan_ram_p[ UnitNumber_u08 ][ MTTCAN_RAMSECTION_RXBUFFERS ] = RAMPointer_Access_u32;
  RAMPointer_Access_u32 += ( u32 )( Config->ram.mttcan_a_rxbuffers_count * 
                                    MTTCAN_GetObjectSize( Config->rxesc.rbds ) );

  ee_mttcan_common_p[ UnitNumber_u08 ]->txefc.efsa   = RAMPointer_u32;
  ee_mttcan_common_p[ UnitNumber_u08 ]->txefc.efs    = ( u32 )Config->ram.mttcan_a_thl_size;

  RAMPointer_u32 += ( u32 )( Config->ram.mttcan_a_thl_size *  
                             MTTCAN_RAMSIZE_THL / 4 );
  if( RAMPointer_u32 >= ( ee_mttcan_ramsize_p[ UnitNumber_u08 ] / 4 ) ) 
    return( MTTCAN_ERROR );

  ee_mttcan_ram_p[ UnitNumber_u08 ][ MTTCAN_RAMSECTION_THL ] = RAMPointer_Access_u32;
  RAMPointer_Access_u32 += ( u32 )( Config->ram.mttcan_a_thl_size * 
                                    MTTCAN_RAMSIZE_THL );

  ee_mttcan_common_p[ UnitNumber_u08 ]->txbc.tbsa    = RAMPointer_u32;
  ee_mttcan_common_p[ UnitNumber_u08 ]->txbc.ndtb    = ( u32 )Config->ram.mttcan_a_txbuffers_count;
  ee_mttcan_common_p[ UnitNumber_u08 ]->txbc.tfqs    = ( u32 )Config->ram.mttcan_a_txqueue_size;

  RAMPointer_u32 += ( u32 )( Config->ram.mttcan_a_txbuffers_count *  
                             MTTCAN_GetObjectSize( Config->txesc.tbds ) / 4 );
  RAMPointer_u32 += ( u32 )( Config->ram.mttcan_a_txqueue_size *  
                             MTTCAN_GetObjectSize( Config->txesc.tbds ) / 4 );
  if( RAMPointer_u32 >= ( ee_mttcan_ramsize_p[ UnitNumber_u08 ] / 4 ) ) 
    return( MTTCAN_ERROR );

  ee_mttcan_ram_p[ UnitNumber_u08 ][ MTTCAN_RAMSECTION_TXBUFFERS ] = RAMPointer_Access_u32;

  /* Clear Configuration Enable to protect configuration settings */
  
  AccessTimeout_u32 = MTTCAN_SHUTDOWNTIMEOUT;
  *ErrorStatus_pu08 = MTTCAN_CONFIG_ERROR_HWTIMEOUT;
  ee_mttcan_common_p[ UnitNumber_u08 ]->cccr.cce = MTTCAN_CLEAR;
  //__asm( "syncp" );
  while( ( ee_mttcan_common_p[ UnitNumber_u08 ]->cccr.cce != MTTCAN_CLEAR )
         && ( --AccessTimeout_u32 > 0 ) );

  if( AccessTimeout_u32 == 0L ) return( MTTCAN_ERROR );
  
  *ErrorStatus_pu08 = MTTCAN_CONFIG_OK;
  return( MTTCAN_OK );
}

//=============================================================================
// FunctionName: MTTCAN_SetStdFilterEntry
// IN  :         UnitNumber, Rule Number, Filter Entry object
// OUT :         Success Status
// Description : Enters a new entry into the AFL
//=============================================================================
bit MTTCAN_SetStdFilterEntry( u08          UnitNumber_u08,
								      			u16          RuleNumber_u16,
                            const struct ee_mttcan_filter_std *FilterEntry )
{
  struct ee_mttcan_filter_std *RAMPointer;

  if( UnitNumber_u08 >= MTTCAN_MACROS ) return( MTTCAN_ERROR );
  
  RAMPointer = ( struct ee_mttcan_filter_std* )
               ( ee_mttcan_ram_p[ UnitNumber_u08 ]
                              [ MTTCAN_RAMSECTION_STDFILTER ] +
                 RuleNumber_u16 * MTTCAN_RAMSIZE_STDFILTER );
  
  if( ( u32 )RAMPointer >= ee_mttcan_ram_p[ UnitNumber_u08 ]
                                        [ MTTCAN_RAMSECTION_EXTFILTER ] )
    return( MTTCAN_ERROR );
  
  RAMPointer->sfid2 = FilterEntry->sfid2;
  RAMPointer->sfid1 = FilterEntry->sfid1;
  RAMPointer->sfec  = FilterEntry->sfec;
  RAMPointer->sft   = FilterEntry->sft;
  
  return( MTTCAN_OK );
}

//=============================================================================
// FunctionName: MTTCAN_SetExtFilterEntry
// IN  :         UnitNumber, Rule Number, Filter Entry object
// OUT :         Success Status
// Description : Enters a new entry into the AFL
//=============================================================================
bit MTTCAN_SetExtFilterEntry( u08          UnitNumber_u08,
								      			u16          RuleNumber_u16,
                            const struct ee_mttcan_filter_ext *FilterEntry )
{
  struct ee_mttcan_filter_ext *RAMPointer;

  if( UnitNumber_u08 >= MTTCAN_MACROS ) return( MTTCAN_ERROR );
  
  RAMPointer = ( struct ee_mttcan_filter_ext* )
               ( ee_mttcan_ram_p[ UnitNumber_u08 ]
                              [ MTTCAN_RAMSECTION_EXTFILTER ] +
                 RuleNumber_u16 * MTTCAN_RAMSIZE_EXTFILTER );
  
  if( ( u32 )RAMPointer >= ee_mttcan_ram_p[ UnitNumber_u08 ]
                                        [ MTTCAN_RAMSECTION_RXFIFO0 ] )
    return( MTTCAN_ERROR );
  
  RAMPointer->f0.efid1 = FilterEntry->f0.efid1;
  RAMPointer->f0.efec  = FilterEntry->f0.efec;
  RAMPointer->f1.efid2 = FilterEntry->f1.efid2;
  RAMPointer->f1.eft   = FilterEntry->f1.eft;
  
  return( MTTCAN_OK );
}

//=============================================================================
// FunctionName: MTTCAN_SendMessage
// IN  :         UnitNumber, Channel Number, Message
// OUT :         Success Status
// Description : Performs Message Sending
//=============================================================================
bit MTTCAN_SendMessage( u08                UnitNumber_u08,
                      pu08               Status_pu08,
                      struct ee_mttcan_tx *Message )
{
  u08 SendBox_u08;
  u08 FirstBox_u08;
  u08 LastBox_u08;
  u16 ObjectSize_u16;
  
  struct ee_mttcan_tx *RAMPointer;
  
  *Status_pu08 = MTTCAN_FAULT_PARAMETER;
  
  if( UnitNumber_u08 >= MTTCAN_MACROS ) return( MTTCAN_ERROR );
  
  if( ee_mttcan_common_p[ UnitNumber_u08 ]->cccr.init != MTTCAN_CLEAR )
    return( MTTCAN_ERROR );
    
  *Status_pu08 = MTTCAN_FAULT_NONE;
  
  ObjectSize_u16 = MTTCAN_GetObjectSize( ee_mttcan_common_p[ UnitNumber_u08 ]->txesc.tbds );
  
  switch( Message->path )
  {
    case MTTCAN_PATH_MSGBOX:      /* search a free SendBox, if required */
    {
      if( Message->pathdetail != MTTCAN_PATHDETAIL_ANY )
      {
        FirstBox_u08 = Message->pathdetail;
        LastBox_u08  = FirstBox_u08;
        if( ( ee_mttcan_ram_p[ UnitNumber_u08 ][ MTTCAN_RAMSECTION_TXBUFFERS ] +
            ( u32 )LastBox_u08 * ( u32 )ObjectSize_u16 ) >= 
            ee_mttcan_ramsize_p[ UnitNumber_u08 ] )
        {
          *Status_pu08 = MTTCAN_FAULT_PARAMETER;
          return( MTTCAN_ERROR );
        }
      }
      else
      {
        FirstBox_u08 = 0;
        LastBox_u08  = ( u08 )
                       ( ( ee_mttcan_ramsize_p[ UnitNumber_u08 ] -
                           ee_mttcan_ram_p[ UnitNumber_u08 ][ MTTCAN_RAMSECTION_TXBUFFERS ] )
                           / ( u32 )ObjectSize_u16 );
        if( LastBox_u08 >= MTTCAN_MAXTXBUFFERS ) LastBox_u08 = MTTCAN_MAXTXBUFFERS - 1;
      }

      *Status_pu08 = MTTCAN_FAULT_BUSY;

      for( SendBox_u08 =  FirstBox_u08;
           SendBox_u08 <= LastBox_u08; )
      {
        //¡§¡§????1?2??????¨¨a???
        RAMPointer = ( struct ee_mttcan_tx* )
                     ( ee_mttcan_ram_p[ UnitNumber_u08 ]
                                    [ MTTCAN_RAMSECTION_TXBUFFERS ] +
                      ( u32 )( SendBox_u08 * ObjectSize_u16 ) );
                                                        /* check pending TRQ */
        if( !( ee_mttcan_common_p[ UnitNumber_u08 ]->txbrp & ( 1 << SendBox_u08 ) ) )
        {
          MTTCAN_SetIDData( RAMPointer, Message ); 
          if( Message->irq_enable == MTTCAN_SET )
            ee_mttcan_common_p[ UnitNumber_u08 ]->txbtie |= ( u32 )( 1 <<  SendBox_u08 );
          else
            ee_mttcan_common_p[ UnitNumber_u08 ]->txbtie &= ~( ( u32 )( 1 <<  SendBox_u08 ) );
          ee_mttcan_common_p[ UnitNumber_u08 ]->txbar |= ( u32 )( 1 <<  SendBox_u08 );
          *Status_pu08 = MTTCAN_FAULT_NONE;
          break;
        }
        else
        {
          SendBox_u08++;
        }
      }
      break;
    }
    
    case MTTCAN_PATH_FIFOQUEUE:
    {
      if( ee_mttcan_common_p[ UnitNumber_u08 ]->txfqs.tfqf == MTTCAN_SET )
      {
        *Status_pu08 = MTTCAN_FAULT_BUSY;
      }
      else
      {
        SendBox_u08 = ( u08 )ee_mttcan_common_p[ UnitNumber_u08 ]->txfqs.tfqpi;
        RAMPointer = ( struct ee_mttcan_tx* )
                     ( ee_mttcan_ram_p[ UnitNumber_u08 ]
                                    [ MTTCAN_RAMSECTION_TXBUFFERS ] +
                      ( u32 )( SendBox_u08 * ObjectSize_u16 ) );
        MTTCAN_SetIDData( RAMPointer, Message );
        if( Message->irq_enable == MTTCAN_SET )
          ee_mttcan_common_p[ UnitNumber_u08 ]->txbtie |= ( u32 )( 1 <<  SendBox_u08 );
        else
          ee_mttcan_common_p[ UnitNumber_u08 ]->txbtie &= ~( ( u32 )( 1 <<  SendBox_u08 ) );
        ee_mttcan_common_p[ UnitNumber_u08 ]->txbar |= ( u32 )( 1 <<  SendBox_u08 );
        *Status_pu08 = MTTCAN_FAULT_NONE;
      }
      break;
    }
    
    default:
    {
      *Status_pu08 = MTTCAN_FAULT_PARAMETER;
      return( MTTCAN_ERROR );
    }
  }
  return( MTTCAN_OK );
}

//=============================================================================
// FunctionName: MTTCAN_ReceiveMessage
// IN  :         UnitNumber, (preferred) Reception path within message
// OUT :         Success Status
//               Message with content and information
// Description : Performs Message Reception
// 
//=============================================================================
bit MTTCAN_ReceiveMessage( u08                UnitNumber_u08,
                         pu08               Status_pu08,
                         struct ee_mttcan_rx *Message )
{
  u08 ReceiveBox_u08;
  u08 SearchBegin_u08;
  u08 SearchEnd_u08;
  u16 ObjectSize_u16;
  
  struct ee_mttcan_rx *RAMPointer;
  
  *Status_pu08 = MTTCAN_FAULT_NODATA;
  
  if( UnitNumber_u08 >= MTTCAN_MACROS ) return( MTTCAN_ERROR );
  
  if( ee_mttcan_common_p[ UnitNumber_u08 ]->cccr.init != MTTCAN_CLEAR )
    return( MTTCAN_ERROR );

  if( ( Message->path == MTTCAN_PATH_MSGBOX ) ||
      ( Message->path == MTTCAN_PATH_ANY ) )      /* check within message boxes */
  {
    ObjectSize_u16 = MTTCAN_GetObjectSize( ee_mttcan_common_p[ UnitNumber_u08 ]->rxesc.rbds );

    if( Message->pathdetail != MTTCAN_PATHDETAIL_ANY )    /* read dedicated box */
    {
      SearchBegin_u08 = Message->pathdetail;
      SearchEnd_u08   = Message->pathdetail;
      
      //fix
      if( ( ee_mttcan_ram_p[ UnitNumber_u08 ][ MTTCAN_RAMSECTION_RXBUFFERS ] +
          ( u32 )SearchEnd_u08 * ( u32 )ObjectSize_u16 ) >= 
          ee_mttcan_ram_p[ UnitNumber_u08 ][ MTTCAN_RAMSECTION_THL ] )
      {
        *Status_pu08 = MTTCAN_FAULT_PARAMETER;
        return( MTTCAN_ERROR );
      }
    }
    else
    {
      SearchBegin_u08 = 0;
      SearchEnd_u08  = ( u08 )
                     ( ( ee_mttcan_ram_p[ UnitNumber_u08 ][ MTTCAN_RAMSECTION_THL ] -
                         ee_mttcan_ram_p[ UnitNumber_u08 ][ MTTCAN_RAMSECTION_RXBUFFERS ] )
                         / ( u32 )ObjectSize_u16 );
      if( SearchEnd_u08 >= MTTCAN_MAXRXBUFFERS ) SearchEnd_u08 = MTTCAN_MAXRXBUFFERS - 1;
    }

    for( ReceiveBox_u08 =  SearchBegin_u08;
         ReceiveBox_u08 <= SearchEnd_u08;
         ReceiveBox_u08++ )
    {
      if( ReceiveBox_u08 < ( MTTCAN_MAXRXBUFFERS / 2 ) )
      {
        while( ( ee_mttcan_common_p[ UnitNumber_u08 ]->ndat1 >> ReceiveBox_u08 ) &
                 MTTCAN_SET )
        {
          *Status_pu08 = MTTCAN_FAULT_NONE;
                                                        /* Clear new data flag */
          ee_mttcan_common_p[ UnitNumber_u08 ]->ndat1 = ( u32 )
                                                      ( 1 << ReceiveBox_u08 );
          RAMPointer = ( struct ee_mttcan_rx* )
                       ( ee_mttcan_ram_p[ UnitNumber_u08 ]
                                      [ MTTCAN_RAMSECTION_RXBUFFERS ] +
                       ( u32 )( ReceiveBox_u08 * ObjectSize_u16 ) );
                      
          MTTCAN_GetMessage( RAMPointer, Message, 
                         ( u08 )( ObjectSize_u16 - MTTCAN_RAMSIZE_OBJECT_0 ) );
        }
      }
      else
      {
        while( ( ee_mttcan_common_p[ UnitNumber_u08 ]->ndat2 >> 
               ( ReceiveBox_u08 - ( MTTCAN_MAXRXBUFFERS / 2 ) ) ) &
                 MTTCAN_SET )
        {
          *Status_pu08 = MTTCAN_FAULT_NONE;
                                                        /* Clear new data flag */
          ee_mttcan_common_p[ UnitNumber_u08 ]->ndat2 = ( u32 )
                                                      ( 1 << ( ReceiveBox_u08 - 
                                                      ( MTTCAN_MAXRXBUFFERS / 2 ) ) );
          RAMPointer = ( struct ee_mttcan_rx* )
                       ( ee_mttcan_ram_p[ UnitNumber_u08 ]
                                      [ MTTCAN_RAMSECTION_RXBUFFERS ] +
                       ( u32 )( ReceiveBox_u08 * ObjectSize_u16 ) );
                      
          MTTCAN_GetMessage( RAMPointer, Message, 
                         ( u08 )( ObjectSize_u16 - MTTCAN_RAMSIZE_OBJECT_0 ) );
        }
      }
    }  
  }
  

  if( ( Message->path == MTTCAN_PATH_FIFOQUEUE ) ||
      ( ( Message->path == MTTCAN_PATH_ANY ) &&
        ( *Status_pu08 == MTTCAN_FAULT_NODATA ) ) ) /* check within RX FIFO */
  {
    if( ( Message->pathdetail == MTTCAN_PATHDETAIL_ANY ) ||
        ( Message->pathdetail == 0 ) )                       /* RX FIFO 0 */
    {
      ObjectSize_u16 = MTTCAN_GetObjectSize( ee_mttcan_common_p[ UnitNumber_u08 ]->rxesc.f0ds );
      
      if( ee_mttcan_common_p[ UnitNumber_u08 ]->rxf0s.ffl > 0 )
      {
        *Status_pu08   = MTTCAN_FAULT_NONE;
        ReceiveBox_u08 = ( u08 )( ee_mttcan_common_p[ UnitNumber_u08 ]->rxf0s.fgi );
        RAMPointer     = ( struct ee_mttcan_rx* )
                         ( ee_mttcan_ram_p[ UnitNumber_u08 ]
                                        [ MTTCAN_RAMSECTION_RXFIFO0 ] +
                         ( u32 )( ReceiveBox_u08 * ObjectSize_u16 ) );

        if( ( u32 )RAMPointer >= ee_mttcan_ram_p[ UnitNumber_u08 ]
                                              [ MTTCAN_RAMSECTION_RXFIFO1 ] )
        {
          *Status_pu08 = MTTCAN_FAULT_PARAMETER;
          return( MTTCAN_ERROR );
        }

        MTTCAN_GetMessage( RAMPointer, Message, 
                       ( u08 )( ObjectSize_u16 - MTTCAN_RAMSIZE_OBJECT_0 ) );

        ee_mttcan_common_p[ UnitNumber_u08 ]->rxf0a.fai = ( u32 )ReceiveBox_u08;
      }
    }
    else if( *Status_pu08 == MTTCAN_FAULT_NODATA )             /* RX FIFO 1 */
    {
      ObjectSize_u16 = MTTCAN_GetObjectSize( ee_mttcan_common_p[ UnitNumber_u08 ]->rxesc.f1ds );
      
      if( ee_mttcan_common_p[ UnitNumber_u08 ]->rxf1s.ffl > 0 )
      {
        *Status_pu08   = MTTCAN_FAULT_NONE;
        ReceiveBox_u08 = ( u08 )( ee_mttcan_common_p[ UnitNumber_u08 ]->rxf1s.fgi );
        RAMPointer     = ( struct ee_mttcan_rx* )
                         ( ee_mttcan_ram_p[ UnitNumber_u08 ]
                                        [ MTTCAN_RAMSECTION_RXFIFO1 ] +
                         ( u32 )( ReceiveBox_u08 * ObjectSize_u16 ) );

        if( ( u32 )RAMPointer >= ee_mttcan_ram_p[ UnitNumber_u08 ]
                                              [ MTTCAN_RAMSECTION_RXBUFFERS ] )
        {
          *Status_pu08 = MTTCAN_FAULT_PARAMETER;
          return( MTTCAN_ERROR );
        }

        MTTCAN_GetMessage( RAMPointer, Message, 
                       ( u08 )( ObjectSize_u16 - MTTCAN_RAMSIZE_OBJECT_0 ) );

        ee_mttcan_common_p[ UnitNumber_u08 ]->rxf1a.fai = ( u32 )ReceiveBox_u08;
      }      
    }
  }
  return( MTTCAN_OK );
}

//=============================================================================
// FunctionName: MTTCAN_TxAbort
// IN  :         UnitNumber, Channel Number, Message
// OUT :         Success Status
// Description : Performs Message Sending
//=============================================================================
bit MTTCAN_TxAbort( u08                UnitNumber_u08,
                  struct ee_mttcan_tx *Message )
{
  u08 SendBox_u08;
  u08 FirstBox_u08;
  u08 LastBox_u08;
  u16 ObjectSize_u16;

  if( UnitNumber_u08 >= MTTCAN_MACROS ) return( MTTCAN_ERROR );
  if( ee_mttcan_common_p[ UnitNumber_u08 ]->cccr.init != MTTCAN_CLEAR )
    return( MTTCAN_ERROR );

  ObjectSize_u16 = MTTCAN_GetObjectSize( ee_mttcan_common_p[ UnitNumber_u08 ]->txesc.tbds );

  switch( Message->path )
  {
    case MTTCAN_PATH_MSGBOX:         /* direct abortion of message box */
      if( Message->pathdetail == MTTCAN_PATHDETAIL_ANY )  /* abort all */
      {             /* procedure also to be used to abort a TX Queue */
        FirstBox_u08 = 0;
        LastBox_u08  = ( u08 )
                       ( ( ee_mttcan_ramsize_p[ UnitNumber_u08 ] -
                           ee_mttcan_ram_p[ UnitNumber_u08 ][ MTTCAN_RAMSECTION_TXBUFFERS ] )
                           / ( u32 )ObjectSize_u16 );
        if( LastBox_u08 >= MTTCAN_MAXTXBUFFERS ) LastBox_u08 = MTTCAN_MAXTXBUFFERS - 1;
      }
      else
      {
        FirstBox_u08 = Message->pathdetail;
        LastBox_u08  = FirstBox_u08;
        
        if( ( ee_mttcan_ram_p[ UnitNumber_u08 ][ MTTCAN_RAMSECTION_TXBUFFERS ] +
            ( u32 )LastBox_u08 * ( u32 )ObjectSize_u16 ) >= 
            ee_mttcan_ramsize_p[ UnitNumber_u08 ] )
        {
          return( MTTCAN_ERROR );
        }
      }    
      break;
      
    case MTTCAN_PATH_FIFOQUEUE:      /* abortion of frontmost FIFO entry */
      if( ee_mttcan_common_p[ UnitNumber_u08 ]->txbc.tfqm == MTTCAN_TXB_QUEUEMODE )
        return( MTTCAN_ERROR );
      else
      {
        FirstBox_u08 = ( u08 )ee_mttcan_common_p[ UnitNumber_u08 ]->txfqs.tfgi;
        LastBox_u08  = FirstBox_u08;
      }
      break;
  }
  
  for( SendBox_u08 =  FirstBox_u08;
       SendBox_u08 <= LastBox_u08;
       SendBox_u08++ )
  {
    ee_mttcan_common_p[ UnitNumber_u08 ]->txbcr = ( u32 )( 1 << SendBox_u08 );
  }  
  
  return( MTTCAN_OK );
}
