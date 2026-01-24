#ifndef _MAIN_H_
#define _MAIN_H_


#include "global.h"
//#include "declare.h"
#include "r_adc.h"
#include "tmr.h"
#include "tmr_macrodriver.h"
#include "Config_CSIH0.h"
#include <mttcan.h>
#include "gtm.h"
#include "CAN_SPI.h"
#include "PMIC.h"
#include "parameter.h"
#include "global_struct.h"
#include "fad_flash.h"
#include "para_update.h"
#include "UDS_Main.h"

#define PrintEnable 1	//Enable output internal information via RLIN30


/*****************************************************************************
 Private variables and functions
 *****************************************************************************/


extern unsigned int SpeedLoopCount;
extern Object_t g_CANObject;
extern int fdtest;
extern CAN_Info g_Can_Atrib;
extern T_u4 Data_Flash_Read[16];
extern T_u4 Flash_Data[16];
//extern int Flag_CAN_flash;
extern unsigned int FB_Order_Flag;
extern unsigned int FB_Complete_Flag;
extern unsigned int FB_lianxu_Flag;

extern unsigned int Given_Complete_Flag;
extern unsigned int Protect_Complete_Flag;
extern unsigned int Regulator_Complete_Flag;
extern unsigned int Flag_CAN_flash_Order;
extern unsigned int Flag_CAN_flash_Complete;
extern unsigned int Run_Complete_Flag;

extern unsigned int CANfd_runState;
extern unsigned int CANfd_runMode;
//extern unsigned int Run_Order_Flag;


void main(void);
void Clock_Init(void);
void FlashRead(void);
void FlashWrite(void);

void Port_Init(void);

#endif