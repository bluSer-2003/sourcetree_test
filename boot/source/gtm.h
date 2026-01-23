/*===========================================================================*/
/* Module      = gtm.h                                                       */
/* Version     = 0.01                                                        */
/*===========================================================================*/
/*                                  COPYRIGHT                                */
/*===========================================================================*/
/* Copyright (c) 2013 by Renesas Electronics Europe GmbH,                    */
/*               a company of the Renesas Electronics Corporation            */
/*===========================================================================*/
/* Purpose:      Declarations of I/O Registers                               */
/*                                                                           */
/*===========================================================================*/
/*                                                                           */
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
/* Environment:                                                              */
/*              Device:         RH850                                */
/*              IDE:            GHS Multi for V800  V6.xx or later           */
/*===========================================================================*/


#ifndef __GTM_H__
#define __GTM_H__


/* ---------------------------------------------------
 * Function prototype
 * --------------------------------------------------- */
void GTM_Init(void);
void GTM_PIC_ADC_Init(void);
void para_Init(void);
inline void get_speed(void);
inline void Angle_get_e(double agl);
void De_Mos(void);
void choose(void);
inline void Read_ADC_Current(void);
inline void protection(void) ;
inline void Openloop(void)   ;  

/*******************************************************
 *                   Registers bit masks               *
 *******************************************************/
// ATOM_CH_CTRL register definitions:
#define mode_somi (0<<0)
#define mode_somc (1<<0)
#define mode_somp (2<<0)
#define mode_soms (3<<0)
#define aru_off (0<<3)
#define aru_on (1<<3)
#define sl_lo (0<<11)
#define sl_hi (1<<11)
#define osm_cont (0<<26)
#define osm_one (1<<26)
#define cmu_clk0 (0<<12)
#define cmu_clk1 (1<<12)
#define cmu_clk2 (2<<12)
#define cmu_clk3 (3<<12)
#define cmu_clk4 (4<<12)
#define cmu_clk5 (5<<12)
#define cmu_clk6 (6<<12)
#define cmu_clk7 (7<<12)
#define trig_chx (0<<24)
#define trig_ccu0 (1<<24)
#define rst_on_cm0 (0<<20)
#define rst_on_trig (1<<20)
#define T0 800 // period on channel 0: 1000*62,5ns = 16kHz
#define CH7_Pulse_length 100 // high pulse length ch7: 100*62,5ns = 6250 ns
#define PI 3.14159265
#define ARU_ACB 0x0C000000 // ACB=C transferred via ARU
#define angle_status 1
//useful marco
#define SATS(x, lower, upper) ((x) < (lower) ? (lower) : ((x) > (upper) ? (upper) : (x)))
#define MAX_THREE(a, b, c) ((a) > (b) ? ((a) > (c) ? (a) : (c)) : ((b) > (c) ? (b) : (c)))
#define ABS(x) ((x) < 0 ? -(x) : (x))
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))
extern int TestFlag;
extern int lsw;

#endif //__GTM_H__
