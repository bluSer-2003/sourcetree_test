//============================================================================
// PROJECT = RH850/P1H-C
//============================================================================
//                                 C O P Y R I G H T                                    
//============================================================================
// Copyright (c) 2015 by RENESAS Electronics (Europe) GmbH. All rights reserved.
// Arcadiastr. 10
// D-40472 Duesseldorf
// Germany
//============================================================================
//Purpose: Header File for RCAN2NEXT SCIT SFR includes
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
//
// $Log$
//
//============================================================================

#ifndef _MAP_PORTS_H
#define _MAP_PORTS_H

//#include <ree_macros.h>
#include <standardports.h>

#ifndef DRIVER_LOCAL
#include <standardports_p.h>
#endif

/* ADDRESS DEFINITIONS */

#define N_PORT_BASE                   ( 0xffc10000 )
#define N_PORT_MODE_BASE              ( 0xffc10010 )
#define N_PORT_MODE_CONTROL_BASE      ( 0xffc10014 )
#define N_PORT_FUNCTION_CONTROL_BASE  ( 0xffc10018 )
#define N_PORT_FUNCTION_CONTROL2_BASE ( 0xffc1001c )

#define N_PORT_FUNCLEVELS             ( 3 )

/* #define A_PORT_BASE                  ( 0xfffff000 ) */
/* #define A_PORT_CONTROL_BASE          ( 0xfffff020 ) */
/* #define A_PORT_MODE_CONTROL_BASE     ( 0xfffff040 ) */
                                                                   
/* NON-EXISTING PORT AREAS */

#undef PORT_10
#undef PORT_11
#undef PORT_12
#undef PORT_13
#undef PORT_14
#undef PORT_15
#undef PORT_16
#undef PORT_17
#undef PORT_20
#undef PORT_24
#undef PORT_25
#undef PORT_29

#undef PORT_ALPHA

/* PORT STRUCTURE */

typedef struct port_numeric {
  
  volatile unsigned short  p0;
  volatile unsigned short  RESERVED0[ 0x1f ];
  volatile unsigned short  p1;
  volatile unsigned short  RESERVED1[ 0x1f ];
  volatile unsigned short  p2;
  volatile unsigned short  RESERVED2[ 0x1f ];
  volatile unsigned short  p3;
  volatile unsigned short  RESERVED3[ 0x1f ];
  volatile unsigned short  p4;
  volatile unsigned short  RESERVED4[ 0x1f ];
  volatile unsigned short  p5;
  volatile unsigned short  RESERVED5[ 0x1f ];
  volatile unsigned short  p6;
  volatile unsigned short  RESERVED6[ 0x1f ];
  volatile unsigned short  p7;
  volatile unsigned short  RESERVED7[ 0x1f ];
  volatile unsigned short  p8;
  volatile unsigned short  RESERVED8[ 0x1f ];
  volatile unsigned short  p9;
  volatile unsigned short  RESERVED9[ 0x1f ];
  
} port_numeric;


typedef struct port_mode_numeric {
  
  volatile unsigned short pm0;       
  volatile unsigned short RESERVED0[ 0x1f ];
  volatile unsigned short pm1;
  volatile unsigned short RESERVED1[ 0x1f ];
  volatile unsigned short pm2;
  volatile unsigned short RESERVED2[ 0x1f ];
  volatile unsigned short pm3;
  volatile unsigned short RESERVED3[ 0x1f ];
  volatile unsigned short pm4;
  volatile unsigned short RESERVED4[ 0x1f ];
  volatile unsigned short pm5;
  volatile unsigned short RESERVED5[ 0x1f ];
  volatile unsigned short pm6;
  volatile unsigned short RESERVED6[ 0x1f ];
  volatile unsigned short pm7;
  volatile unsigned short RESERVED7[ 0x1f ];
  volatile unsigned short pm8;
  volatile unsigned short RESERVED8[ 0x1f ];
  volatile unsigned short pm9;
  volatile unsigned short RESERVED9[ 0x1f ];
  
} port_mode_numeric;


typedef struct port_mode_control_numeric {
  
  volatile unsigned short pmc0;      
  volatile unsigned short RESERVED0[ 0x1f ];
  volatile unsigned short pmc1;
  volatile unsigned short RESERVED1[ 0x1f ];
  volatile unsigned short pmc2;
  volatile unsigned short RESERVED2[ 0x1f ];
  volatile unsigned short pmc3;
  volatile unsigned short RESERVED3[ 0x1f ];
  volatile unsigned short pmc4;
  volatile unsigned short RESERVED4[ 0x1f ];
  volatile unsigned short pmc5;
  volatile unsigned short RESERVED5[ 0x1f ];
  volatile unsigned short pmc6;
  volatile unsigned short RESERVED6[ 0x1f ];
  volatile unsigned short pmc7;
  volatile unsigned short RESERVED7[ 0x1f ];
  volatile unsigned short pmc8;
  volatile unsigned short RESERVED8[ 0x1f ];
  volatile unsigned short pmc9;
  volatile unsigned short RESERVED9[ 0x1f ];
  
} port_mode_control_numeric;

typedef struct port_function_control_numeric {
  
  volatile unsigned short pfc0;
  volatile unsigned short RESERVED0[ 0x1f ];
  volatile unsigned short pfc1;
  volatile unsigned short RESERVED1[ 0x1f ];
  volatile unsigned short pfc2;
  volatile unsigned short RESERVED2[ 0x1f ];
  volatile unsigned short pfc3;
  volatile unsigned short RESERVED3[ 0x1f ];
  volatile unsigned short pfc4;
  volatile unsigned short RESERVED4[ 0x1f ];
  volatile unsigned short pfc5;
  volatile unsigned short RESERVED5[ 0x1f ];
  volatile unsigned short pfc6;
  volatile unsigned short RESERVED6[ 0x1f ];
  volatile unsigned short pfc7;
  volatile unsigned short RESERVED7[ 0x1f ];
  volatile unsigned short pfc8;
  volatile unsigned short RESERVED8[ 0x1f ];
  volatile unsigned short pfc9;
  volatile unsigned short RESERVED9[ 0x1f ];
  
} port_function_control_numeric;

typedef struct port_function_control2_numeric {
  
  volatile unsigned short pfce0;
  volatile unsigned short RESERVED0[ 0x1f ];
  volatile unsigned short pfce1;
  volatile unsigned short RESERVED1[ 0x1f ];
  volatile unsigned short pfce2;
  volatile unsigned short RESERVED2[ 0x1f ];
  volatile unsigned short pfce3;
  volatile unsigned short RESERVED3[ 0x1f ];
  volatile unsigned short pfce4;
  volatile unsigned short RESERVED4[ 0x1f ];
  volatile unsigned short pfce5;
  volatile unsigned short RESERVED5[ 0x1f ];
  volatile unsigned short pfce6;
  volatile unsigned short RESERVED6[ 0x1f ];
  volatile unsigned short pfce7;
  volatile unsigned short RESERVED7[ 0x1f ];
  volatile unsigned short pfce8;
  volatile unsigned short RESERVED8[ 0x1f ];
  volatile unsigned short pfce9;
  volatile unsigned short RESERVED9[ 0x1f ];
  
} port_function_control2_numeric;

/* typedef struct port_alpha { */
  
/*   volatile unsigned short pal; */
/*   volatile unsigned char  pah; */
/*   volatile unsigned char  RESERVED0; */
/*   volatile unsigned short pdl; */
/*   volatile unsigned short pdh; */
/*   volatile unsigned char  pcs; */
/*   volatile unsigned char  RESERVED1; */
/*   volatile unsigned char  pct; */
/*   volatile unsigned char  RESERVED2; */
/*   volatile unsigned char  pcm; */
/*   volatile unsigned char  RESERVED3; */
/*   volatile unsigned char  pcd; */
  
/* } port_alpha; */


/* typedef struct port_mode_alpha { */
  
/*   volatile unsigned short pmal; */
/*   volatile unsigned char  pmah; */
/*   volatile unsigned char  RESERVED0; */
/*   volatile unsigned short pmdl; */
/*   volatile unsigned short pmdh; */
/*   volatile unsigned char  pmcs; */
/*   volatile unsigned char  RESERVED1; */
/*   volatile unsigned char  pmct; */
/*   volatile unsigned char  RESERVED2; */
/*   volatile unsigned char  pmcm; */
/*   volatile unsigned char  RESERVED3; */
/*   volatile unsigned char  pmcd; */
  
/* } port_mode_alpha; */


/* typedef struct port_mode_control_alpha { */
  
/*   volatile unsigned short pmcal; */
/*   volatile unsigned char  pmcah; */
/*   volatile unsigned char  RESERVED0; */
/*   volatile unsigned short pmcdl; */
/*   volatile unsigned short pmcdh; */
/*   volatile unsigned char  pmccs; */
/*   volatile unsigned char  RESERVED1; */
/*   volatile unsigned char  pmcct; */
/*   volatile unsigned char  RESERVED2; */
/*   volatile unsigned char  pmccm; */
/*   volatile unsigned char  RESERVED3; */
/*   volatile unsigned char  pmccd;  */
  
/* } port_mode_control_alpha; */


/* PORT DECLARATION */

static struct port_numeric              
             *port_numeric_p = 
                                 ( struct port_numeric * )
                                 ( N_PORT_BASE );

static struct port_mode_numeric         
             *port_mode_numeric_p = 
                                 ( struct port_mode_numeric * )
                                 ( N_PORT_MODE_BASE );

static struct port_mode_control_numeric 
             *port_mode_control_numeric_p = 
                                 ( struct port_mode_control_numeric * )
                                 ( N_PORT_MODE_CONTROL_BASE );

static struct port_function_control_numeric 
             *port_function_control_numeric_p = 
                                 ( struct port_function_control_numeric * )
                                 ( N_PORT_FUNCTION_CONTROL_BASE );

static struct port_function_control2_numeric 
             *port_function_control2_numeric_p = 
                                 ( struct port_function_control2_numeric * )
                                 ( N_PORT_FUNCTION_CONTROL2_BASE );

/* static struct port_alpha                */
/*              *port_alpha_p =  */
/*                                  ( struct port_alpha * )              */
/*                                  ( A_PORT_BASE ); */

/* static struct port_mode_alpha           */
/*              *port_mode_alpha_p =  */
/*                                  ( struct port_mode_alpha * )         */
/*                                  ( A_PORT_CONTROL_BASE ); */

/* static struct port_mode_control_alpha   */
/*              *port_mode_control_alpha_p =  */
/*                                  ( struct port_mode_control_alpha * ) */
/*                                  ( A_PORT_MODE_CONTROL_BASE ); */

#endif

