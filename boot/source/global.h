/*************************************************************************/
/*																		 */
/*  FILE        	:global.h						  					 */
/*  DATE       	 	:Feb 20, 2017        			                     */
/*  DESCRIPTION :														 */
/*  CPU TYPE		:													 */
/*																				*/
/*  NOTE			:This is a common head program.									*/
/*				  It is developed by ZhouZhenQi.									*/
/*																				*/
/*************************************************************************/
#ifndef GLOBAL_H_
#define GLOBAL_H_

/*****************************************************************************
 Includes   <System Includes> , "Project Includes"
 *****************************************************************************/
#include "iodefine.h"

//====================================================================
//LEDs define
//------------------------
/*
#define	LED1		12V	
#define	LED2		Track1(5V)	
#define	LED3		Track2(5V)	
#define	LED4		VOUT1(5V)	
#define	LED5		VOUT2(3.3V)	
#define	LED6		AVCC(5V)	
#define	LED7		VOUT0(3.3V)	
#define	LED8		FT232RL TXLED#	
#define	LED9		FT232RL RXLED#	
#define	LED10		FT232RL PWREN#	

#define	LED11		PORT.P3.BIT.P3_5
#define	LED12		PORT.P3.BIT.P3_4
#define	LED13		PORT.P3.BIT.P3_2
#define	LED14		PORT.P3.BIT.P3_1
#define	LED15		PORT.P3.BIT.P3_0
#define	LED16		PORT.P2.BIT.P2_15

#define	LED17		CVMOUT	
#define	LED18		ERROROUT	
*/
//====================================================================




//====================================================================
//motor status
#define IDLE						0x00
#define STATUS_START_MOTOR		0x10
#define STATUS_ASC_START_MOTOR	0x11
#define STATUS_RUN_MOTOR			0x20
#define STATUS_STOP_MOTOR			0x30
#define STATUS_STOP_MOTOR_WAIT	0x31
#define STATUS_BRAKE_MOTOR		0x32
#define STATUS_STOP_FLEXPWM		0x33
//motor status

//FOC
#define FOC_offset 10922
//====================================================================
#ifndef __TYPEDEF__
    typedef signed char           int8_t;
    typedef unsigned char         uint8_t;
    typedef signed short          int16_t;
    typedef unsigned short        uint16_t;
    typedef signed long           int32_t;
    typedef unsigned long         uint32_t;
    typedef signed long long      int64_t;
    typedef unsigned long long    uint64_t;
    typedef unsigned short        MD_STATUS;
    #define __TYPEDEF__
#endif


//====================================================================
#define True	0
#define Wrong	1
//====================================================================


//====================================================================




#endif /* GLOBAL_H_ */
