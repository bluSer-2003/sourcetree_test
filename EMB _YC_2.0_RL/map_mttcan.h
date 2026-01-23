//============================================================================
// PROJECT = RH850/P1x-C
//============================================================================
//                                 C O P Y R I G H T                                    
//============================================================================
// Copyright (c) 2014 by RENESAS Electronics (Europe) GmbH. All rights reserved.
// Arcadiastrasse 10
// D-40472 Duesseldorf
// Germany
//============================================================================
//Purpose: MTTCAN Hardware Mapping Definition
//
//Warranty Disclaimer
//
//Because the Product(s) is licensed free of charge, there is no warranty 
//of any kind whatsoever and expressly disclaimed and excluded by RENESAS, 
//either expressed or implied, including but not limited to those for 
//non-infringement of intellectual property, merchantability and/or 
//fitness for the particular purpose. 
//RENESAS shall not have any obligation to maintain, service or provide bug 
//fixes for the supplied Product(s) and/or the Application.
//
//Each User is solely responsible for determining the appropriateness of 
//using the Product(s) and assumes all risks associated with its exercise 
//of rights under this Agreement, including, but not limited to the risks 
//and costs of program errors, compliance with applicable laws, damage to 
//or loss of data, programs or equipment, and unavailability or 
//interruption of operations.
//
//Limitation of Liability
//
//In no event shall RENESAS be liable to the User for any incidental, 
//consequential, indirect, or punitive damage (including but not limited 
//to lost profits) regardless of whether such liability is based on breach 
//of contract, tort, strict liability, breach of warranties, failure of 
//essential purpose or otherwise and even if advised of the possibility of 
//such damages. RENESAS shall not be liable for any services or products 
//provided by third party vendors, developers or consultants identified or
//referred to the User by RENESAS in connection with the Product(s) and/or the 
//Application.
//
//
//
//============================================================================
// Environment: Devices:          RH850/P1H-C
//              Assembler:        GHS MULTI 
//              C-Compiler:       GHS MULTI 
//              Linker:           GHS MULTI 
//              Debugger:         GHS MULTI 
//============================================================================

#ifndef _MAP_MTTCAN_H
#define _MAP_MTTCAN_H

#include <standardports.h>
#include <iodefine.h>

/* MAPPED MTTCAN: MTTCAN_R301/321 */
#define MTTCAN_TYPE MTTCAN_R321

#include <map_device.h>
#if(  MTTCAN_TYPE == MTTCAN_R321 )
#include <mttcan.h>
#ifndef DRIVER_LOCAL
#include <mttcan_p.h>
#include <mttcan_a.h>
#endif
#else
#include <mttcan\mttcan_r301\mttcan.h>
#ifndef DRIVER_LOCAL
#include <mttcan\mttcan_r301\mttcan_p.h>
#include <mttcan\mttcan_r301\mttcan_a.h>
#endif
#endif

#ifdef  APPLICATION_INTERFACE   /* optional UART settings */
#endif

/* FURTHER MTTCAN OPERATION PROPERTIES */

#define MTTCAN_BASE0              ( 0xFFEF0000 )

#define MTTCAN_BASE_RAM0          ( 0xFFEF8000)


//#define MTTCAN_BASE0              ( 0xFFD31000 )//can1

//#define MTTCAN_BASE_RAM0          ( 0xFFD3A000)//can1
#define MTTCAN_SIZE_RAM0          ( 0x00002000 )

#define MTTCAN_FREQFACTOR         ( 1.0 )

#define MTTCAN_MAXBAUDRATE        ( ( u32 )( OSCILLATOR_FREQUENCY * MTTCAN_FREQFACTOR )\
                                  / MTTCAN_CLKMINFACTOR )

#define MTTCAN_SHUTDOWNTIMEOUT    ( 1000000L )

#if ( defined( RH850_P1H_C_D4_RDRIVE ) || defined ( RH850_P1H_C_D5_RDRIVE )||defined ( RH850_P1M_C ) )
#define MTTCAN_VERBOSE            ( 0 )
#else
#define MTTCAN_VERBOSE            ( 1 )
#endif

/* PORT DEFINITIONS: ABG NETWORK BOARD NDB V1 */

#define MTTCAN_PORT_M0RX       PORT_5
#define MTTCAN_PORT_M0TX       PORT_5
//#define MTTCAN_PORT_M0RX       PORT_0
//#define MTTCAN_PORT_M0TX       PORT_0

#define MTTCAN_PORT_BIT_M0RX   BIT_0
 #define MTTCAN_PORT_BIT_M0TX   BIT_1
//#define MTTCAN_PORT_BIT_M0RX   BIT_7
//#define MTTCAN_PORT_BIT_M0TX   BIT_8

#define MTTCAN_PORT_FUNC_M0RX  PORT_FUNCTION_ALTLV2 
#define MTTCAN_PORT_FUNC_M0TX  PORT_FUNCTION_ALTLV2 

/* INTERRUPT REGISTER MAPPING */

#ifdef RH850_P1M_C

#define MTTCAN_INT_M0LINE0      ( EIC172 )
#define MTTCAN_INT_M0LINE1      ( EIC173 )
#define MTTCAN_INT_M0LINEFE     ( EIC174 )

#endif


#ifdef RH850_P1H_C_D4

#define MTTCAN_INT_M0LINE0      ( INTC2EIC172 )
#define MTTCAN_INT_M0LINE1      ( INTC2EIC173 )
#define MTTCAN_INT_M0LINEFE     ( INTC2EIC174 )

#endif

#ifdef RH850_P1H_C_D5ED

#define MTTCAN_INT_M0LINE0      ( EIC172 )
#define MTTCAN_INT_M0LINE1      ( EIC173 )
#define MTTCAN_INT_M0LINEFE     ( EIC174 )

#endif

#ifdef RH850_P1H_C_D5

#define MTTCAN_INT_M0LINE0      ( EIC172 )
#define MTTCAN_INT_M0LINE1      ( EIC173 )
#define MTTCAN_INT_M0LINEFE     ( EIC174 )

#endif

#define MTTCAN_INTCLEAR         ( 0x008F )       // Interrupt mask bit
#define MTTCAN_INTENABLEDEFAULT ( 0x0040 )


/* The MTTCAN Memory Mapping */  

static struct ee_mttcan_common *ee_mttcan_common_p[ MTTCAN_MACROS ] =
{
    ( ee_mttcan_common * )( MTTCAN_BASE0 )                             /* unit 0 */
};   

static u32 ee_mttcan_ram_p[ MTTCAN_MACROS ][ MTTCAN_RAMSECTIONS ] =
{
  {
    ( u32 )( MTTCAN_BASE_RAM0 ),                                     /* unit 0 */
    0L, 0L, 0L, 0L, 0L, 0L, 0L       /* Placeholder for sections as configured */
  } 
};   

static u32 ee_mttcan_ramsize_p[ MTTCAN_MACROS ] =
{
    ( u32 )( MTTCAN_SIZE_RAM0 )                                      /* unit 0 */
};   

#endif
