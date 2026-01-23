/*************************************************************************/
/*  									 */
/*  FILE			:port.c					 */
/*  DATE			:July 15, 2015				 */
/*  DESCRIPTION	:port Program						 */
/*  CPU TYPE		:RH850/P1M				 */
/*									 */
/*  NOTE			:This is a port configuration program.   */
/*				 It is developed by ZhouZhenQi. 	 */
/*									 */
/*********************************************************************/

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
void Port_Init(void);

 
/*****************************************************************************
 Private variables and functions
 *****************************************************************************/

 
 
/*---------------------------------------------------------------------------*
 *  Function Implementation                                                  *
 *---------------------------------------------------------------------------*/
/*****************************************************************************
 * Outline			: port initialization program
 * Include			: 
 * Declaration		: void Port_Init()
 * Description		: 
 * Argument			: 
 * Return Value		: 
  * Calling Functions: 
 *****************************************************************************/
void Port_Init(void)
{
  
	 //GTM0AT0O0 P4_0
  //GTM0AT0O2 P4_1
  //GTM0AT0O1 P4_2 GTM1I1
  PMC4  = PMC4  |  0x0007;// set PMC4_0,1,2 for alternative function
  PIPC4 = PIPC4 & ~0x0007;// clear PIPC4_0,1,2 for software mode
  PFCE4 = PFCE4 & ~0x0007;// clear PFCE4_0,1,2
  PFC4  = PFC4  & ~0x0007;// clear PFC4_0,1,2, so together with PFCE you get Alternative function 1
  PM4   = PM4   & ~0x0007;// clear PM4_0,1,2 for output
  PBDC4 = PBDC4 |  0x0007;// set PBDC4_0,1,2 for bi-directional mode
  
  //GTM0AT0O3  P5_0
  //GTM0AT0O3N P5_9
  //GTM0AT0O2N P5_15
  PMC5  = PMC5  |  0x8201;// set PMC5_0,9,15 for alternative function
  PIPC5 = PIPC5 & ~0x8201;// clear PIPC5_0,9,15 for software mode
  PFCE5 = PFCE5 & ~0x8201;// clear PFCE5_0,9,15
  PFC5  = PFC5  & ~0x8201;// clear PFC5_0,9,15, so together with PFCE you get Alternative function 1
  PM5   = PM5   & ~0x8201;// clear PM5_0,9,15 for output

  //GTM0AT0O7 P6_3
  PMC6  = PMC6  |  0x0008;// set PMC6_3 for alternative function
  PIPC6 = PIPC6 & ~0x0008;// clear PIPC6_3 for software mode
  PFCE6 = PFCE6 & ~0x0008;// clear PFCE6_3
  PFC6  = PFC6  & ~0x0008;// clear PFC6_3, so together with PFCE you get Alternative function 1
  PM6   = PM6   & ~0x0008;// clear PM6_3 for output

  //GTM0AT0O1N P2_0
  PMC2  = PMC2  |  0x0001;// set PMC2_0 for alternative function
  PIPC2 = PIPC2 & ~0x0001;// clear PIPC2_0 for software mode
  PFCE2 = PFCE2 & ~0x0001;// clear PFCE2_0
  PFC2  = PFC2  & ~0x0001;// clear PFC2_0, so together with PFCE you get Alternative function 1
  PM2   = PM2   & ~0x0001;// clear PM2_0 for output
}

