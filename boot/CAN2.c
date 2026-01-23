#include <ree_types.h>
#include <stddef.h>

#include <mttcan.h>
#include <gtm.h>
#include "can_loader.h"
//#include "mttcan_p.h"
//#include "mttcan_s.h"

#include <can_command.h>

#include <stdio.h>
#include <string.h>
#include "global_struct.h"
#include "parameter.h"
#define _PORT_CLEAR_BIT0                    (0xFFFEU)  /* clear bit 0 */
#define _PORT_CLEAR_BIT1                    (0xFFFDU)  /* clear bit 1 */
#define _PORT_CLEAR_BIT2                    (0xFFFBU)  /* clear bit 2 */
#define _PORT_CLEAR_BIT3                    (0xFFF7U)  /* clear bit 3 */
#define _PORT_CLEAR_BIT4                    (0xFFEFU)  /* clear bit 4 */
#define _PORT_CLEAR_BIT5                    (0xFFDFU)  /* clear bit 5 */
#define _PORT_CLEAR_BIT6                    (0xFFBFU)  /* clear bit 6 */
#define _PORT_CLEAR_BIT7                    (0xFF7FU)  /* clear bit 7 */
#define _PORT_CLEAR_BIT8                    (0xFEFFU)  /* clear bit 8 */
#define _PORT_CLEAR_BIT9                    (0xFDFFU)  /* clear bit 9 */
#define _PORT_CLEAR_BIT10                   (0xFBFFU)  /* clear bit 10 */
#define _PORT_CLEAR_BIT11                   (0xF7FFU)  /* clear bit 11 */
#define _PORT_CLEAR_BIT12                   (0xEFFFU)  /* clear bit 12 */
#define _PORT_CLEAR_BIT13                   (0xDFFFU)  /* clear bit 13 */
#define _PORT_CLEAR_BIT14                   (0xBFFFU)  /* clear bit 14 */
#define _PORT_CLEAR_BIT15                   (0x7FFFU)  /* clear bit 15 */
/* Specify PORT initialize set bits */
#define _PORT_SET_BIT0                      (0x0001U)  /* set bit 0 */
#define _PORT_SET_BIT1                      (0x0002U)  /* set bit 1 */
#define _PORT_SET_BIT2                      (0x0004U)  /* set bit 2 */
#define _PORT_SET_BIT3                      (0x0008U)  /* set bit 3 */
#define _PORT_SET_BIT4                      (0x0010U)  /* set bit 4 */
#define _PORT_SET_BIT5                      (0x0020U)  /* set bit 5 */
#define _PORT_SET_BIT6                      (0x0040U)  /* set bit 6 */
#define _PORT_SET_BIT7                      (0x0080U)  /* set bit 7 */
#define _PORT_SET_BIT8                      (0x0100U)  /* set bit 8 */
#define _PORT_SET_BIT9                      (0x0200U)  /* set bit 9 */
#define _PORT_SET_BIT10                     (0x0400U)  /* set bit 10 */
#define _PORT_SET_BIT11                     (0x0800U)  /* set bit 11 */
#define _PORT_SET_BIT12                     (0x1000U)  /* set bit 12 */
#define _PORT_SET_BIT13                     (0x2000U)  /* set bit 13 */
#define _PORT_SET_BIT14                     (0x4000U)  /* set bit 14 */
#define _PORT_SET_BIT15                     (0x8000U)  /* set bit 15 */

#include <mttcan.h>



#define SATS(x, lower, upper) ((x) < (lower) ? (lower) : ((x) > (upper) ? (upper) : (x)))
#define ABS(x) ((x) < 0 ? -(x) : (x))
extern unsigned int error_state_code_0101;
int FlagCansend = 0;
unsigned int CAN_temp = 0;
unsigned int CAN_count=0;
extern int sleepflag;
extern RecCan_valSeverDataNew BM_valRecSeverData_PHY_MP;
extern RecCan_valSeverDataNew  BM_valRecSeverData_FUN_MP;
volatile uint8 RecCANCount = 0;
void CAN0_UDSSend(u08 Unit1_u08)
{
		RecCANCount++;
		exmsg.data[0] = 0;
        	exmsg.data[1] = 1;
		exmsg.data[2] = 2;
        	exmsg.data[3] = 3;
		exmsg.data[4] = 4;
		
		exmsg.data[5] = 6;
		exmsg.data[6] = 7;
		exmsg.data[7] = 8;
		exmsg.len = 8;
        	exmsg.id = 0x7eb;
		
		Exsend(&exmsg,Unit1_u08);
		
		
	
}/**/	


void can2_command_process(CAN_MSG *pmsg,u08 Unit1_u08)
{
	unsigned int CANID = 0;
	unsigned char Rec_CANnumCount = 0;
	CAN_count++;
	CANID = (Uint16)(pmsg->id);
	if(CANID == 0x7E3)
	{
		BM_valRecSeverData_PHY_MP.CanBus_flgRecActive =1;
		for(Rec_CANnumCount = 0;Rec_CANnumCount<8;Rec_CANnumCount++)
		{
		BM_valRecSeverData_PHY_MP.CanBus_valRecCanData8.b[Rec_CANnumCount] = pmsg->data8[Rec_CANnumCount];
		}
		BM_valRecSeverData_PHY_MP.CanBus_valDataLength =8;
		//memcpy(&Rec_Diag_Physical1.CanBus_valRecCanData8.b[0],pmsg->[0],8);
		//CAN0_UDSSend(0);
	}
	
	if(CANID == 0x7DF)
	{
		
		BM_valRecSeverData_FUN_MP.CanBus_flgRecActive =1;
		for(Rec_CANnumCount = 0;Rec_CANnumCount<8;Rec_CANnumCount++)
		{
		BM_valRecSeverData_FUN_MP.CanBus_valRecCanData8.b[Rec_CANnumCount] = pmsg->data8[Rec_CANnumCount];
		}
		BM_valRecSeverData_FUN_MP.CanBus_valDataLength =8;
	}
}



void CAN2_ExternSend(u08 Unit1_u08)
{
	if(FlagCansend >= 400){
		
		//CAN2.Angle = g_Control.TAS.TAS_angle;
		CAN2.AngleSpd = ABS(g_Control.m_speed.Speed*360/(16.5*60));


		CAN_temp = (g_Control.TAS.TAS_angle + 2048)*16;
		exmsg.data[1] = (unsigned short)CAN_temp  & 0xFF;
        	exmsg.data[0] = (unsigned short)(CAN_temp >> 8) & 0xFF;
		CAN_temp = CAN2.AngleSpd * 0.05;
		exmsg.data[2] = (unsigned short)CAN2.AngleSpd & 0xFF;
        	exmsg.data[3] = (unsigned short)CAN2.Status << 1 & CAN2.AngleFault & 0xFF;
		exmsg.data[4] = (unsigned short)CAN2.FaultRank & 0x0F;
		exmsg.data[5] = (unsigned short)CAN2.StateFlow & 0xFF;
		CAN2.RollCount = CAN2.RollCount + 1;
		if(CAN2.RollCount > 15){
			CAN2.RollCount = 0;
		}
		exmsg.data[6] = (unsigned short)CAN2.RollCount & 0x0F;
		CAN2.SumCheck = exmsg.data[0]^exmsg.data[1]^exmsg.data[2]^
						exmsg.data[3]^exmsg.data[4]^exmsg.data[5]^exmsg.data[6];
		exmsg.data[7] = (unsigned short)CAN2.SumCheck & 0xFF;
		
		exmsg.len = 8;
        	exmsg.id = 0x322;
		
		Exsend(&exmsg,Unit1_u08);
		FlagCansend = 0;
		FlagCansend = 0;
	
	
	//if(FlagCansend == 400){
		
		CAN_temp = error_state_code_0101;
		if(error_state_code_0101 & _PORT_SET_BIT1)
		{CAN2.error2 |= _PORT_SET_BIT2;}
		
		if(error_state_code_0101 & _PORT_SET_BIT5)
		{CAN2.error2 |= _PORT_SET_BIT3;}
		
		if(error_state_code_0101 & _PORT_SET_BIT7)
		{CAN2.error2 |= _PORT_SET_BIT4;}
		
		if(error_state_code_0101 & _PORT_SET_BIT8)
		{CAN2.error1 |= _PORT_SET_BIT0;}
		
		if(error_state_code_0101 & _PORT_SET_BIT9)
		{CAN2.error1 |= _PORT_SET_BIT1;}
		
		
		
		exmsg.data[0] = (unsigned short)CAN2.error1 & 0xFF;
        	exmsg.data[1] = (unsigned short)CAN2.error2 & 0xFF;
		exmsg.data[2] = (unsigned short)CAN2.error3 & 0x03;
        	exmsg.data[3] = 0;
		exmsg.data[4] = 0;
		
		exmsg.data[5] = (unsigned short)CAN2.supply & 0x03;
		exmsg.data[6] = (unsigned short)CAN2.SoftVersion & 0xFF;
		exmsg.data[7] = (unsigned short)CAN2.HardVersion & 0xFF;
		exmsg.len = 8;
        	exmsg.id = 0x607;
		
		//Exsend(&exmsg,Unit1_u08);
	}/**/
		
		
	
}/**/	