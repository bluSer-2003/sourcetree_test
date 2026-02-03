#include <stdio.h>
#include <string.h>
#include <math.h>
#include "mttcan_a.h"
//#include "canfd.h"
#include "parameter.h"
#include "global_struct.h"

#define INVALID_CAN_ID 0

uint8 DEBUG1 = 0;
uint8 DEBUG2 = 0;
uint8 DEBUG3 = 0;
uint8 DEBUG4 = 0;

typedef enum {
    MSG_ID_Manuf_INQRY      = 0X0000,   // ?????? ID
    MSG_ID_Manuf_STATE      = 0X0200,   // ?????? ID
    MSG_ID_STATE_INQRY      = 0X0140,   // ?????? ID
    MSG_ID_FEEDBACK_STATE   = 0X0220,   // ?????? ID
    MSG_ID_GIVEN_CMD        = 0X0040,   // ?????? ID
    MSG_ID_GIVEN_STATE      = 0X0240,   // ?????? ID
    MSG_ID_REGULATOR_CMD    = 0X0060,   // ??????? ID
    MSG_ID_REGULATOR_STATE  = 0X0260,   // ??????? ID
    MSG_ID_PROTECT_CMD      = 0X0080,   // ?????? ID
    MSG_ID_PROTECT_STATE    = 0X0280,   // ?????? ID
    MSG_ID_FLASH_CMD        = 0X00C0,   // ?????? ID
    MSG_ID_FLASH_STATE      = 0X02C0    // ?????? ID
} CANFD_MessageID;

typedef enum {
    Manuf_Year      = 2025,  
    Manuf_Month     = 3,  
    Manuf_Day       = 29,   
    Manuf_Type      = 2,  
    Manuf_Version   = 12,  
    Manuf_SN        = 1234   
} Manufacture;

uint32_T CANfd_Password = 0x11223344;

CAN_FD_MESSAGE_BUS ReplyMSG;

// ??????
CAN_FD_MESSAGE_BUS ReplyMSG_Global;
real32_T Temp_real32;
real_T Temp_real;
uint16_T Temp_uint16;
uint32_T Temp_uint32;
int16_T Temp_int16;
int32_T Temp_int32;
uint8 rollcnt;

Given Given_Order;
Given Given_Complete;
Regulator Regulator_Order;
Regulator Regulator_Complete;
Protect Protect_Order;
Protect Protect_Complete;
Feedback FB_Inqury;

uint16_T CANfd_runMode = 0;
uint16_T CANfd_runState = 0;
uint16_T FB_Order_Flag = 0;
uint16_T FB_Complete_Flag = 0;
uint16_T FB_lianxu_Flag = 0;

uint16_T Flag_CAN_flash_Order = 0;
uint16_T Flag_CAN_flash_Complete = 0;
uint16_T Given_Order_Flag = 0;
uint16_T Given_Complete_Flag = 0;
uint16_T Protect_Order_Flag = 0;
uint16_T Protect_Complete_Flag = 0;
uint16_T Regulator_Order_Flag = 0;
uint16_T Regulator_Complete_Flag = 0;


uint16_T Password_Flag = 0;
uint16_T CANfd_Error = 0;

TX_PDU_0x6Ex BWC_FL_CAN1_FrP1;
TX_PDU_0x6Ex BWC_FR_CAN1_FrP1;
TX_PDU_0x6Ex BWC_RL_CAN1_FrP1;
TX_PDU_0x6Ex BWC_RR_CAN1_FrP1;

RX_PDU_0x6E0 BCU_M_CAN1_FrP1;
RX_PDU_0x6EF BCU_R_CAN1_FrP1;


const uint8 crc_table[256] =
{
	0x00, 0x1D, 0x3A, 0x27, 0x74, 0x69, 0x4E, 0x53,
	0xE8, 0xF5, 0xD2, 0xCF, 0x9C, 0x81, 0xA6, 0xBB,
	0xCD, 0xD0, 0xF7, 0xEA, 0xB9, 0xA4, 0x83, 0x9E,
	0x25, 0x38, 0x1F, 0x02, 0x51, 0x4C, 0x6B, 0x76,
	0x87, 0x9A, 0xBD, 0xA0, 0xF3, 0xEE, 0xC9, 0xD4,
	0x6F, 0x72, 0x55, 0x48, 0x1B, 0x06, 0x21, 0x3C,
	0x4A, 0x57, 0x70, 0x6D, 0x3E, 0x23, 0x04, 0x19,
	0xA2, 0xBF, 0x98, 0x85, 0xD6, 0xCB, 0xEC, 0xF1,
	0x13, 0x0E, 0x29, 0x34, 0x67, 0x7A, 0x5D, 0x40,
	0xFB, 0xE6, 0xC1, 0xDC, 0x8F, 0x92, 0xB5, 0xA8,
	0xDE, 0xC3, 0xE4, 0xF9, 0xAA, 0xB7, 0x90, 0x8D,
	0x36, 0x2B, 0x0C, 0x11, 0x42, 0x5F, 0x78, 0x65,
	0x94, 0x89, 0xAE, 0xB3, 0xE0, 0xFD, 0xDA, 0xC7,
	0x7C, 0x61, 0x46, 0x5B, 0x08, 0x15, 0x32, 0x2F,
	0x59, 0x44, 0x63, 0x7E, 0x2D, 0x30, 0x17, 0x0A,
	0xB1, 0xAC, 0x8B, 0x96, 0xC5, 0xD8, 0xFF, 0xE2,
	0x26, 0x3B, 0x1C, 0x01, 0x52, 0x4F, 0x68, 0x75,
	0xCE, 0xD3, 0xF4, 0xE9, 0xBA, 0xA7, 0x80, 0x9D,
	0xEB, 0xF6, 0xD1, 0xCC, 0x9F, 0x82, 0xA5, 0xB8,
	0x03, 0x1E, 0x39, 0x24, 0x77, 0x6A, 0x4D, 0x50,
	0xA1, 0xBC, 0x9B, 0x86, 0xD5, 0xC8, 0xEF, 0xF2,
	0x49, 0x54, 0x73, 0x6E, 0x3D, 0x20, 0x07, 0x1A,
	0x6C, 0x71, 0x56, 0x4B, 0x18, 0x05, 0x22, 0x3F,
	0x84, 0x99, 0xBE, 0xA3, 0xF0, 0xED, 0xCA, 0xD7,
	0x35, 0x28, 0x0F, 0x12, 0x41, 0x5C, 0x7B, 0x66,
	0xDD, 0xC0, 0xE7, 0xFA, 0xA9, 0xB4, 0x93, 0x8E,
	0xF8, 0xE5, 0xC2, 0xDF, 0x8C, 0x91, 0xB6, 0xAB,
	0x10, 0x0D, 0x2A, 0x37, 0x64, 0x79, 0x5E, 0x43,
	0xB2, 0xAF, 0x88, 0x95, 0xC6, 0xDB, 0xFC, 0xE1,
	0x5A, 0x47, 0x60, 0x7D, 0x2E, 0x33, 0x14, 0x09,
	0x7F, 0x62, 0x45, 0x58, 0x0B, 0x16, 0x31, 0x2C,
	0x97, 0x8A, 0xAD, 0xB0, 0xE3, 0xFE, 0xD9, 0xC4
};


extern int canTimer;
extern int canmissTimer;

void Send_Tx_0x6Ex(TX_PDU_0x6Ex Tx_PDU , uint16 PDU_ID);
void Recive_Signal_0x6E0(uint8 *Rx_data);
void Recive_Signal_0x6EF(uint8 *Rx_data);


void CAN_Tx_Fun(void)
{
    rollcnt++;
    if (rollcnt > 15)
    {
        rollcnt = 0;
    }  
    
#if(EMBActuator == FLEMB)
    if (canTimer % 100 > 10 && DEBUG1 == 0)
    {
        Send_Tx_0x6Ex(BWC_FL_CAN1_FrP1, 0x6E1);
	DEBUG1 = 1;
    }
    if (canTimer % 100 > 30 && DEBUG2 == 0)
    {
        FB_reply();
	DEBUG2 = 1;
    }
#endif
#if(EMBActuator == FREMB)
    if (canTimer % 100 > 10 && DEBUG1 == 0)
    {
        Send_Tx_0x6Ex(BWC_FR_CAN1_FrP1, 0x6E2);
	DEBUG1 = 1;
    }
    if (canTimer % 100 > 30 && DEBUG2 == 0)
    {
        FB_reply();
	DEBUG2 = 1;
    }
#endif
#if(EMBActuator == RLEMB)
    if (canTimer % 100 > 10 && DEBUG1 == 0)
    {
        Send_Tx_0x6Ex(BWC_RL_CAN1_FrP1, 0x6E3);
	DEBUG1 = 1;
    }
    if (canTimer % 100 > 30 && DEBUG2 == 0)
    {
        FB_reply();
	DEBUG2 = 1;
    }
#endif
#if(EMBActuator == RREMB)
    if (canTimer % 100 > 10 && DEBUG1 == 0)
    {
        Send_Tx_0x6Ex(BWC_RR_CAN1_FrP1, 0x6E4);
	DEBUG1 = 1;
    }
    if (canTimer % 100 > 30 && DEBUG2 == 0)
    {
        FB_reply();
	DEBUG2 = 1;
    }
#endif

    if (canTimer % 100 < 10)
    {
        DEBUG1 = 0;
	DEBUG2 = 0;
	DEBUG3 = 0;
	DEBUG4 = 0;
    }
}

uint8 crc_8find(uint8 *data, uint16 len)
{
    	uint8 crc8 = 0x00;

    	while( len-- ) 
    	{
        	crc8 = crc_table[crc8 ^ *data];
        	data++;
    	}
    	return crc8;
}


void Send_Tx_0x6Ex(TX_PDU_0x6Ex Tx_PDU , uint16 PDU_ID)
{
	CAN_FD_MESSAGE_BUS Tx_Data = {0,0,0,0,0,0,0,0,0,0,0,{0}};
	
	Tx_Data.Data[1] += Tx_PDU.BrkForceVld;
	
	Tx_Data.Data[1] += Tx_PDU.BrkForceActive << 1;
	
	Tx_Data.Data[0] +=  Tx_PDU.BrkForceActual >> 6;
	Tx_Data.Data[1] += (Tx_PDU.BrkForceActual & 0x3F)<< 2;
	
	Tx_Data.Data[2] += Tx_PDU.BrkForceLmt;
	
	Tx_Data.Data[5] += Tx_PDU.BrkForceGrdActive << 7;
	
	Tx_Data.Data[3] += Tx_PDU.BrkForceGrdLmtMax;
	
	Tx_Data.Data[4] += Tx_PDU.BrkForceGrdLmtMin;
	
	Tx_Data.Data[6] += Tx_PDU.BrkForceRelPos << 6;
	
	Tx_Data.Data[5] += Tx_PDU.ParkBrkState;
	
	Tx_Data.Data[5] += Tx_PDU.ServiceBrkFailState << 5;
	
	Tx_Data.Data[5] += Tx_PDU.PrakBrkFailState << 3;
	
	Tx_Data.Data[6] += Tx_PDU.MotorControlState << 3;
	
	Tx_Data.Data[6] += Tx_PDU.ParkValveControlState;
	
	Tx_Data.Data[7] += Tx_PDU.WheelSpeed >> 7;
	Tx_Data.Data[8] += (Tx_PDU.WheelSpeed & 0x7F) << 1;
	
	Tx_Data.Data[10] += Tx_PDU.WheelSpeedDir << 3;
	
	Tx_Data.Data[8] += Tx_PDU.WheelSpeedVld;
	
	Tx_Data.Data[9] += Tx_PDU.WheelPulseCounter >> 2;
	Tx_Data.Data[10] += (Tx_PDU.WheelPulseCounter & 0x3) << 6;
	
	Tx_Data.Data[10] += Tx_PDU.WheelPulseReset << 5;
	
	Tx_Data.Data[11] += Tx_PDU.WheelTimestamp >> 8;
	Tx_Data.Data[12] += Tx_PDU.WheelTimestamp & 0xFF;
	
	Tx_Data.Data[10] += Tx_PDU.WheelTimestampRC << 1;
	
	Tx_Data.Data[13] += Tx_PDU.Comm_Avaliable_BCU_M << 7;
	
	Tx_Data.Data[13] += Tx_PDU.Comm_Avaliable_BCU_R << 6;
	
	Tx_Data.Data[13] += Tx_PDU.AliveRollingCount;
	
	Tx_PDU.Checksum = crc_8find(&Tx_Data , 14);
	
	Tx_Data.Data[14] += Tx_PDU.Checksum >>8;
	Tx_Data.Data[15] += Tx_PDU.Checksum & 0xFF;
	
	Tx_Data.ID = PDU_ID;
	Tx_Data.Length = 16U;
	Tx_Data.Extended = 0U;
	Tx_Data.Remote = 0;
	Tx_Data.BRS = 1;
	Tx_Data.ProtocolMode = 1;
	Tx_Data.DLC = 10U;
	
	Send_Test(&Tx_Data);
}


void Recive_Signal_0x6E0(rx_type *signal)
{
	BCU_M_CAN1_FrP1.BrkForceCmdActive_FL = (signal->Rx_data[1] >> 1) & 0x1;
	
	BCU_M_CAN1_FrP1.BrkForceCmd_FL = signal->Rx_data[0];
	BCU_M_CAN1_FrP1.BrkForceCmd_FL = BCU_M_CAN1_FrP1.BrkForceCmd_FL << 6;
	BCU_M_CAN1_FrP1.BrkForceCmd_FL += signal->Rx_data[1] >> 2;
	
	BCU_M_CAN1_FrP1.BrkForceCmdGrdMaxLmtA_FL = (signal->Rx_data[3] >> 4) & 0x1;
	
	BCU_M_CAN1_FrP1.BrkForceCmdGrdMinLmtA_FL = (signal->Rx_data[3] >> 3) & 0x1;
	
	BCU_M_CAN1_FrP1.BrkForceCmdGrdLmt_FL = signal->Rx_data[2];
	BCU_M_CAN1_FrP1.BrkForceCmdGrdLmt_FL = BCU_M_CAN1_FrP1.BrkForceCmdGrdLmt_FL << 3;
	BCU_M_CAN1_FrP1.BrkForceCmdGrdLmt_FL += signal->Rx_data[3] >> 5;
	
	BCU_M_CAN1_FrP1.BrkForceRelPosReq_FL = signal->Rx_data[3] & 0x3;
	
	BCU_M_CAN1_FrP1.BrkForceDiffAllow_FL = signal->Rx_data[1] & 0x1;
	
	BCU_M_CAN1_FrP1.ABSActive_FL = (signal->Rx_data[3] >> 2) & 0x1;
	
	BCU_M_CAN1_FrP1.ParkRequest_FL = (signal->Rx_data[4] >> 4) & 0xF;
	
	
	
	BCU_M_CAN1_FrP1.BrkForceCmdActive_FR = (signal->Rx_data[6] >> 1) & 0x1;
	
	BCU_M_CAN1_FrP1.BrkForceCmd_FR = signal->Rx_data[5];
	BCU_M_CAN1_FrP1.BrkForceCmd_FR = BCU_M_CAN1_FrP1.BrkForceCmd_FR << 6;
	BCU_M_CAN1_FrP1.BrkForceCmd_FR += signal->Rx_data[6] >> 2;
	
	BCU_M_CAN1_FrP1.BrkForceCmdGrdMaxLmtA_FR = (signal->Rx_data[8] >> 4) & 0x1;
	
	BCU_M_CAN1_FrP1.BrkForceCmdGrdMinLmtA_FR = (signal->Rx_data[8] >> 3) & 0x1;
	
	BCU_M_CAN1_FrP1.BrkForceCmdGrdLmt_FR = signal->Rx_data[7];
	BCU_M_CAN1_FrP1.BrkForceCmdGrdLmt_FR = BCU_M_CAN1_FrP1.BrkForceCmdGrdLmt_FR << 3;
	BCU_M_CAN1_FrP1.BrkForceCmdGrdLmt_FR += signal->Rx_data[8] >> 5;
	
	BCU_M_CAN1_FrP1.BrkForceRelPosReq_FR = signal->Rx_data[8] & 0x3;
	
	BCU_M_CAN1_FrP1.BrkForceDiffAllow_FR = signal->Rx_data[6] & 0x1;
	
	BCU_M_CAN1_FrP1.ABSActive_FR = (signal->Rx_data[8] >> 2) & 0x1;
	
	BCU_M_CAN1_FrP1.ParkRequest_FR = (signal->Rx_data[9] >> 4) & 0xF;
	
	
	BCU_M_CAN1_FrP1.BrkForceCmdActive_RL = (signal->Rx_data[11] >> 1) & 0x1;
	
	BCU_M_CAN1_FrP1.BrkForceCmd_RL = signal->Rx_data[10];
	BCU_M_CAN1_FrP1.BrkForceCmd_RL = BCU_M_CAN1_FrP1.BrkForceCmd_RL << 6;
	BCU_M_CAN1_FrP1.BrkForceCmd_RL += signal->Rx_data[11] >> 2;
	
	BCU_M_CAN1_FrP1.BrkForceCmdGrdMaxLmtA_RL = (signal->Rx_data[13] >> 4) & 0x1;
	
	BCU_M_CAN1_FrP1.BrkForceCmdGrdMinLmtA_RL = (signal->Rx_data[13] >> 3) & 0x1;
	
	BCU_M_CAN1_FrP1.BrkForceCmdGrdLmt_RL = signal->Rx_data[12];
	BCU_M_CAN1_FrP1.BrkForceCmdGrdLmt_RL = BCU_M_CAN1_FrP1.BrkForceCmdGrdLmt_RL << 3;
	BCU_M_CAN1_FrP1.BrkForceCmdGrdLmt_RL += signal->Rx_data[13] >> 5;
	
	BCU_M_CAN1_FrP1.BrkForceRelPosReq_RL = signal->Rx_data[13] & 0x3;
	
	BCU_M_CAN1_FrP1.BrkForceDiffAllow_RL = signal->Rx_data[11] & 0x1;
	
	BCU_M_CAN1_FrP1.ABSActive_RL = (signal->Rx_data[13] >> 2) & 0x1;
	
	BCU_M_CAN1_FrP1.ParkRequest_RL = (signal->Rx_data[14] >> 4) & 0xF;
	
	
	BCU_M_CAN1_FrP1.BrkForceCmdActive_RR = (signal->Rx_data[16] >> 1) & 0x1;
	
	BCU_M_CAN1_FrP1.BrkForceCmd_RR = signal->Rx_data[15];
	BCU_M_CAN1_FrP1.BrkForceCmd_RR = BCU_M_CAN1_FrP1.BrkForceCmd_RR << 6;
	BCU_M_CAN1_FrP1.BrkForceCmd_RR += signal->Rx_data[16] >> 2;
	
	BCU_M_CAN1_FrP1.BrkForceCmdGrdMaxLmtA_RR = (signal->Rx_data[18] >> 4) & 0x1;
	
	BCU_M_CAN1_FrP1.BrkForceCmdGrdMinLmtA_RR = (signal->Rx_data[18] >> 3) & 0x1;
	
	BCU_M_CAN1_FrP1.BrkForceCmdGrdLmt_RR = signal->Rx_data[17];
	BCU_M_CAN1_FrP1.BrkForceCmdGrdLmt_RR = BCU_M_CAN1_FrP1.BrkForceCmdGrdLmt_RR << 3;
	BCU_M_CAN1_FrP1.BrkForceCmdGrdLmt_RR += signal->Rx_data[18] >> 5;
	
	BCU_M_CAN1_FrP1.BrkForceRelPosReq_RR = signal->Rx_data[18] & 0x3;
	
	BCU_M_CAN1_FrP1.BrkForceDiffAllow_RR = signal->Rx_data[16] & 0x1;
	
	BCU_M_CAN1_FrP1.ABSActive_RR = (signal->Rx_data[18] >> 2) & 0x1;
	
	BCU_M_CAN1_FrP1.ParkRequest_RR = (signal->Rx_data[19] >> 4) & 0xF;
	
	
	BCU_M_CAN1_FrP1.R_Comm_Avaliable = (signal->Rx_data[22] >> 1) & 0x1;
	
	BCU_M_CAN1_FrP1.Control_Enable = (signal->Rx_data[22] >> 2) & 0x1;
	
	BCU_M_CAN1_FrP1.AvailableState = (signal->Rx_data[22] >> 3) & 0x1;
	
	BCU_M_CAN1_FrP1.BrkTakeoverRequest = (signal->Rx_data[22] >> 4) & 0x1;
	
	BCU_M_CAN1_FrP1.BrkPedalInputRodPosn = signal->Rx_data[20];
	
	BCU_M_CAN1_FrP1.BrkPedalInputRodPosnVld = (signal->Rx_data[22] >> 7) & 0x1;
	
	BCU_M_CAN1_FrP1.BrkPedalInputRodPosn = signal->Rx_data[21];
	
	BCU_M_CAN1_FrP1.BrkPedalInputRodForceVld = (signal->Rx_data[22] >> 6) & 0x1;
	
	BCU_M_CAN1_FrP1.LongAccel = signal->Rx_data[23];
	
	BCU_M_CAN1_FrP1.LongAccelVld = signal->Rx_data[22] & 0x1;
	
	BCU_M_CAN1_FrP1.RollerbenchActive = (signal->Rx_data[22] >> 5) & 0x1;
	
	BCU_M_CAN1_FrP1.WheelSpeed_FL = signal->Rx_data[24];
	BCU_M_CAN1_FrP1.WheelSpeed_FL = BCU_M_CAN1_FrP1.WheelSpeed_FL << 2;
	BCU_M_CAN1_FrP1.WheelSpeed_FL += signal->Rx_data[25] >> 6;
	
	BCU_M_CAN1_FrP1.WheelSpeedVld_FL = (signal->Rx_data[29] >> 7) & 0x1;
	
	BCU_M_CAN1_FrP1.WheelSpeed_FR = signal->Rx_data[25] & 0x3F;
	BCU_M_CAN1_FrP1.WheelSpeed_FR = BCU_M_CAN1_FrP1.WheelSpeed_FR << 4;
	BCU_M_CAN1_FrP1.WheelSpeed_FR += signal->Rx_data[26] >> 4;
	
	BCU_M_CAN1_FrP1.WheelSpeedVld_FR = (signal->Rx_data[29] >> 6) & 0x1;
	
	BCU_M_CAN1_FrP1.WheelSpeed_RL = signal->Rx_data[26] & 0xF;
	BCU_M_CAN1_FrP1.WheelSpeed_RL = BCU_M_CAN1_FrP1.WheelSpeed_RL << 6;
	BCU_M_CAN1_FrP1.WheelSpeed_RL += signal->Rx_data[27] >> 2;
	
	BCU_M_CAN1_FrP1.WheelSpeedVld_RL = (signal->Rx_data[29] >> 5) & 0x1;
	
	BCU_M_CAN1_FrP1.WheelSpeed_RR = signal->Rx_data[27] & 0x3;
	BCU_M_CAN1_FrP1.WheelSpeed_RR = BCU_M_CAN1_FrP1.WheelSpeed_RR << 8;
	BCU_M_CAN1_FrP1.WheelSpeed_RR += signal->Rx_data[28] ;
	
	BCU_M_CAN1_FrP1.WheelSpeedVld_RR = (signal->Rx_data[29] >> 4) & 0x1;
	
	BCU_M_CAN1_FrP1.AliveRollingCount = signal->Rx_data[29] & 0xF;
	
	BCU_M_CAN1_FrP1.Checksum = signal->Rx_data[30];
	BCU_M_CAN1_FrP1.Checksum = BCU_M_CAN1_FrP1.Checksum << 8;
	BCU_M_CAN1_FrP1.Checksum += signal->Rx_data[31];
	
	canmissTimer = 0;
}


void Recive_Signal_0x6EF(rx_type *signal)
{
	BCU_R_CAN1_FrP1.BrkForceCmdActive_FL = (signal->Rx_data[1] >> 1) && 0x1;
	
	BCU_R_CAN1_FrP1.BrkForceCmd_FL = signal->Rx_data[0];
	BCU_R_CAN1_FrP1.BrkForceCmd_FL = BCU_R_CAN1_FrP1.BrkForceCmd_FL << 6;
	BCU_R_CAN1_FrP1.BrkForceCmd_FL += signal->Rx_data[1] >> 2;
	
	BCU_R_CAN1_FrP1.BrkForceCmdGrdMaxLmtA_FL = (signal->Rx_data[3] >> 4) && 0x1;
	
	BCU_R_CAN1_FrP1.BrkForceCmdGrdMinLmtA_FL = (signal->Rx_data[3] >> 3) && 0x1;
	
	BCU_R_CAN1_FrP1.BrkForceCmdGrdLmt_FL = signal->Rx_data[2];
	BCU_R_CAN1_FrP1.BrkForceCmdGrdLmt_FL = BCU_R_CAN1_FrP1.BrkForceCmdGrdLmt_FL << 3;
	BCU_R_CAN1_FrP1.BrkForceCmdGrdLmt_FL += signal->Rx_data[3] >> 5;
	
	BCU_R_CAN1_FrP1.BrkForceRelPosReq_FL = signal->Rx_data[3] && 0x3;
	
	BCU_R_CAN1_FrP1.BrkForceDiffAllow_FL = signal->Rx_data[1] && 0x1;
	
	BCU_R_CAN1_FrP1.ABSActive_FL = (signal->Rx_data[3] >> 2) && 0x1;
	
	BCU_R_CAN1_FrP1.ParkRequest_FL = (signal->Rx_data[4] >> 4) && 0xF;
	
	
	BCU_R_CAN1_FrP1.BrkForceCmdActive_FR = (signal->Rx_data[6] >> 1) && 0x1;
	
	BCU_R_CAN1_FrP1.BrkForceCmd_FR = signal->Rx_data[5];
	BCU_R_CAN1_FrP1.BrkForceCmd_FR = BCU_R_CAN1_FrP1.BrkForceCmd_FR << 6;
	BCU_R_CAN1_FrP1.BrkForceCmd_FR += signal->Rx_data[6] >> 2;
	
	BCU_R_CAN1_FrP1.BrkForceCmdGrdMaxLmtA_FR = (signal->Rx_data[8] >> 4) && 0x1;
	
	BCU_R_CAN1_FrP1.BrkForceCmdGrdMinLmtA_FR = (signal->Rx_data[8] >> 3) && 0x1;
	
	BCU_R_CAN1_FrP1.BrkForceCmdGrdLmt_FR = signal->Rx_data[7];
	BCU_R_CAN1_FrP1.BrkForceCmdGrdLmt_FR = BCU_R_CAN1_FrP1.BrkForceCmdGrdLmt_FR << 3;
	BCU_R_CAN1_FrP1.BrkForceCmdGrdLmt_FR += signal->Rx_data[8] >> 5;
	
	BCU_R_CAN1_FrP1.BrkForceRelPosReq_FR = signal->Rx_data[8] && 0x3;
	
	BCU_R_CAN1_FrP1.BrkForceDiffAllow_FR = signal->Rx_data[6] && 0x1;
	
	BCU_R_CAN1_FrP1.ABSActive_FR = (signal->Rx_data[8] >> 2) && 0x1;
	
	BCU_R_CAN1_FrP1.ParkRequest_FR = (signal->Rx_data[9] >> 4) && 0xF;
	
	
	BCU_R_CAN1_FrP1.BrkForceCmdActive_RL = (signal->Rx_data[11] >> 1) && 0x1;
	
	BCU_R_CAN1_FrP1.BrkForceCmd_RL = signal->Rx_data[10];
	BCU_R_CAN1_FrP1.BrkForceCmd_RL = BCU_R_CAN1_FrP1.BrkForceCmd_RL << 6;
	BCU_R_CAN1_FrP1.BrkForceCmd_RL += signal->Rx_data[11] >> 2;
	
	BCU_R_CAN1_FrP1.BrkForceCmdGrdMaxLmtA_RL = (signal->Rx_data[13] >> 4) && 0x1;
	
	BCU_R_CAN1_FrP1.BrkForceCmdGrdMinLmtA_RL = (signal->Rx_data[13] >> 3) && 0x1;
	
	BCU_R_CAN1_FrP1.BrkForceCmdGrdLmt_RL = signal->Rx_data[12];
	BCU_R_CAN1_FrP1.BrkForceCmdGrdLmt_RL = BCU_R_CAN1_FrP1.BrkForceCmdGrdLmt_RL << 3;
	BCU_R_CAN1_FrP1.BrkForceCmdGrdLmt_RL += signal->Rx_data[13] >> 5;
	
	BCU_R_CAN1_FrP1.BrkForceRelPosReq_RL = signal->Rx_data[13] && 0x3;
	
	BCU_R_CAN1_FrP1.BrkForceDiffAllow_RL = signal->Rx_data[11] && 0x1;
	
	BCU_R_CAN1_FrP1.ABSActive_RL = (signal->Rx_data[13] >> 2) && 0x1;
	
	BCU_R_CAN1_FrP1.ParkRequest_RL = (signal->Rx_data[14] >> 4) && 0xF;
	
	
	BCU_R_CAN1_FrP1.BrkForceCmdActive_RR = (signal->Rx_data[16] >> 1) && 0x1;
	
	BCU_R_CAN1_FrP1.BrkForceCmd_RR = signal->Rx_data[15];
	BCU_R_CAN1_FrP1.BrkForceCmd_RR = BCU_R_CAN1_FrP1.BrkForceCmd_RR << 6;
	BCU_R_CAN1_FrP1.BrkForceCmd_RR += signal->Rx_data[16] >> 2;
	
	BCU_R_CAN1_FrP1.BrkForceCmdGrdMaxLmtA_RR = (signal->Rx_data[18] >> 4) && 0x1;
	
	BCU_R_CAN1_FrP1.BrkForceCmdGrdMinLmtA_RR = (signal->Rx_data[18] >> 3) && 0x1;
	
	BCU_R_CAN1_FrP1.BrkForceCmdGrdLmt_RR = signal->Rx_data[17];
	BCU_R_CAN1_FrP1.BrkForceCmdGrdLmt_RR = BCU_R_CAN1_FrP1.BrkForceCmdGrdLmt_RR << 3;
	BCU_R_CAN1_FrP1.BrkForceCmdGrdLmt_RR += signal->Rx_data[18] >> 5;
	
	BCU_R_CAN1_FrP1.BrkForceRelPosReq_RR = signal->Rx_data[18] && 0x3;
	
	BCU_R_CAN1_FrP1.BrkForceDiffAllow_RR = signal->Rx_data[16] && 0x1;
	
	BCU_R_CAN1_FrP1.ABSActive_RR = (signal->Rx_data[18] >> 2) && 0x1;
	
	BCU_R_CAN1_FrP1.ParkRequest_RR = (signal->Rx_data[19] >> 4) && 0xF;
	
	
	BCU_R_CAN1_FrP1.M_Comm_Avaliable = (signal->Rx_data[22] >> 1) && 0x1;
	
	BCU_R_CAN1_FrP1.Control_Enable = (signal->Rx_data[22] >> 2) && 0x1;
	
	BCU_R_CAN1_FrP1.BrkTakeoverResp = (signal->Rx_data[22] >> 3) && 0x3;
	
	BCU_R_CAN1_FrP1.BrkPedalInputRodPosn = signal->Rx_data[20];
	
	BCU_R_CAN1_FrP1.BrkPedalInputRodPosnVld = (signal->Rx_data[22] >> 7) && 0x1;
	
	BCU_R_CAN1_FrP1.BrkPedalInputRodPosn = signal->Rx_data[21];
	
	BCU_R_CAN1_FrP1.BrkPedalInputRodForceVld = (signal->Rx_data[22] >> 6) && 0x1;
	
	BCU_R_CAN1_FrP1.LongAccel = signal->Rx_data[23];
	
	BCU_R_CAN1_FrP1.LongAccelVld = signal->Rx_data[22] && 0x1;
	
	BCU_R_CAN1_FrP1.RollerbenchActive = (signal->Rx_data[22] >> 5) && 0x1;
	
	BCU_R_CAN1_FrP1.WheelSpeed_FL = signal->Rx_data[24];
	BCU_R_CAN1_FrP1.WheelSpeed_FL = BCU_R_CAN1_FrP1.WheelSpeed_FL << 2;
	BCU_R_CAN1_FrP1.WheelSpeed_FL += signal->Rx_data[25] >> 6;
	
	BCU_R_CAN1_FrP1.WheelSpeedVld_FL = (signal->Rx_data[29] >> 7) && 0x1;
	
	BCU_R_CAN1_FrP1.WheelSpeed_FR = signal->Rx_data[25] && 0x3F;
	BCU_R_CAN1_FrP1.WheelSpeed_FR = BCU_R_CAN1_FrP1.WheelSpeed_FR << 4;
	BCU_R_CAN1_FrP1.WheelSpeed_FR += signal->Rx_data[26] >> 4;
	
	BCU_R_CAN1_FrP1.WheelSpeedVld_FR = (signal->Rx_data[29] >> 6) && 0x1;
	
	BCU_R_CAN1_FrP1.WheelSpeed_RL = signal->Rx_data[26] && 0xF;
	BCU_R_CAN1_FrP1.WheelSpeed_RL = BCU_R_CAN1_FrP1.WheelSpeed_RL << 6;
	BCU_R_CAN1_FrP1.WheelSpeed_RL += signal->Rx_data[27] >> 2;
	
	BCU_R_CAN1_FrP1.WheelSpeedVld_RL = (signal->Rx_data[29] >> 5) && 0x1;
	
	BCU_R_CAN1_FrP1.WheelSpeed_RR = signal->Rx_data[27] && 0x3;
	BCU_R_CAN1_FrP1.WheelSpeed_RR = BCU_R_CAN1_FrP1.WheelSpeed_RR << 8;
	BCU_R_CAN1_FrP1.WheelSpeed_RR += signal->Rx_data[28] ;
	
	BCU_R_CAN1_FrP1.WheelSpeedVld_RR = (signal->Rx_data[29] >> 4) && 0x1;
	
	BCU_R_CAN1_FrP1.AliveRollingCount = signal->Rx_data[29] && 0xF;
	
	BCU_R_CAN1_FrP1.Checksum = signal->Rx_data[30];
	BCU_R_CAN1_FrP1.Checksum = BCU_R_CAN1_FrP1.Checksum << 8;
	BCU_R_CAN1_FrP1.Checksum += signal->Rx_data[31];
}

void Password_Verify(CAN_FD_MESSAGE_BUS *msg)
{
    if(msg->ID == 0x1C0){
        if (msg->Length == 4 && !msg->Extended) {
            uint32_T word = 0x00000000;
            word |= (uint32_T)(msg->Data[3]);
            word |= (uint32_T)((uint32_T)(msg->Data[2]) << 8);
            word |= (uint32_T)((uint32_T)(msg->Data[1]) << 16);
            word |= (uint32_T)((uint32_T)(msg->Data[0]) << 24);
            
            if(word == CANfd_Password)
                Password_Flag = 1;
	        if(word == 0)
                Password_Flag = 0;		

        }
        Password_reply();
        
    }

}


void Password_reply(void)
{
    memset(&ReplyMSG_Global, 0, sizeof(CAN_FD_MESSAGE_BUS));
    ReplyMSG_Global.ID = 0x3C0;
    ReplyMSG_Global.Length = 1U;
    ReplyMSG_Global.Extended = 0U;
    ReplyMSG_Global.Remote = 0;
    ReplyMSG_Global.BRS = 1;
    ReplyMSG_Global.ProtocolMode = 1;
    ReplyMSG_Global.DLC = 1U;

    ReplyMSG_Global.Data[0] = Password_Flag;
    Send_Test(&ReplyMSG_Global);
}




void CAN_FD_P_ANA(CAN_FD_MESSAGE_BUS *msg)
{
//    if(Password_Flag){
        switch (msg->ID)
        {
            case 0x00: // ????
                if (msg->Length == 1 && !msg->Extended) {
		    CANfd_Error = 0;
                    memset(&ReplyMSG_Global, 0, sizeof(CAN_FD_MESSAGE_BUS));
                    ReplyMSG_Global.ID = 0x200;
                    ReplyMSG_Global.Length = 12;
                    ReplyMSG_Global.Extended = 0;
                    ReplyMSG_Global.Remote = 0;
                    ReplyMSG_Global.BRS = 1;
                    ReplyMSG_Global.ProtocolMode = 1;
                    ReplyMSG_Global.DLC = 9;

                    Temp_uint16 = Manuf_Year;
                    ReplyMSG_Global.Data[1] |= (uint8_T)(Temp_uint16);
                    ReplyMSG_Global.Data[0] |= (uint8_T)((Temp_uint16 >> 8) & 0xFF);

                    Temp_uint16 = Manuf_Month;
                    ReplyMSG_Global.Data[3] |= (uint8_T)(Temp_uint16);
                    ReplyMSG_Global.Data[2] |= (uint8_T)((Temp_uint16 >> 8) & 0xFF);

                    Temp_uint16 = Manuf_Day;
                    ReplyMSG_Global.Data[5] |= (uint8_T)(Temp_uint16);
                    ReplyMSG_Global.Data[4] |= (uint8_T)((Temp_uint16 >> 8) & 0xFF);

                    Temp_uint16 = Manuf_Type;
                    ReplyMSG_Global.Data[7] |= (uint8_T)(Temp_uint16);
                    ReplyMSG_Global.Data[6] |= (uint8_T)((Temp_uint16 >> 8) & 0xFF);

                    Temp_uint16 = Manuf_Version;
                    ReplyMSG_Global.Data[9] |= (uint8_T)(Temp_uint16);
                    ReplyMSG_Global.Data[8] |= (uint8_T)((Temp_uint16 >> 8) & 0xFF);

                    Temp_uint16 = Manuf_SN;
                    ReplyMSG_Global.Data[11] |= (uint8_T)(Temp_uint16);
                    ReplyMSG_Global.Data[10] |= (uint8_T)((Temp_uint16 >> 8) & 0xFF);

                    Send_Test(&ReplyMSG_Global);
                }
                break;

            case 0x140: // ????
                if (msg->Length == 1 && !msg->Extended) {
		            CANfd_Error = 0;
                    switch (msg->Data[0]) {
                        case 1:
                            FB_Order_Flag = 1;
			    FB_lianxu_Flag = 0;
                            FB_Complete_Flag = 0;
                            break;
			    
			case 17:
                            FB_Order_Flag = 1;
                            FB_lianxu_Flag = 1;
                            FB_Complete_Flag = 0;
                            break;
			    
			case 255:
                            FB_Order_Flag = 0;
                            FB_lianxu_Flag = 0;
                            FB_Complete_Flag = 1;
                            break;
			    
                        case 2L:
                            Given_Order_Flag = 1;
                            Given_Complete_Flag = 0;
                            break;
                        case 3L:
                            Regulator_Order_Flag = 1;
                            Regulator_Complete_Flag = 0;
                            break;
                        case 4L:
                            Protect_Order_Flag = 1;
                            Protect_Complete_Flag = 0;
                            break;
                    }
                }
                break;

            case 0x40: // ????
                if (msg->Length == 32 && !msg->Extended) {
		    CANfd_Error = 0;
                    Given_Order_Flag = 1;
                    Given_Complete_Flag = 0;

                    Temp_uint16 = 0;
                    Temp_uint16 |= (uint16_T)(msg->Data[1]);
                    Temp_uint16 |= (uint16_T)((uint16_T)(msg->Data[0]) << 8);
                    Given_Order.pre = (real32_T)Temp_uint16 * 0.001F;

                    Temp_int16 = 0;
                    Temp_int16 |= (int16_T)(msg->Data[3]);
                    Temp_int16 |= (int16_T)((uint16_T)(msg->Data[2]) << 8);
                    Given_Order.pos = (real32_T)Temp_int16 * 0.01F;
		    
                    Temp_uint16 = 0;
                    Temp_uint16 |= (uint16_T)(msg->Data[5]);
                    Temp_uint16 |= (uint16_T)((uint16_T)(msg->Data[4]) << 8);
                    Given_Order.spdMax = (uint32_T)Temp_uint16;               

                    Temp_int32 = 0;
                    Temp_int32 |= (int32_T)(msg->Data[9]);
                    Temp_int32 |= (int32_T)((uint32_T)(msg->Data[8]) << 8);
                    Temp_int32 |= (int32_T)((uint32_T)(msg->Data[7]) << 16);
                    Temp_int32 |= (int32_T)((uint32_T)(msg->Data[6]) << 24);
		    Given_Order.spd = (real32_T)Temp_int32 * 0.1;
		    
		    
                    Temp_uint16 = 0;
                    Temp_uint16 |= (uint16_T)(msg->Data[11]);
                    Temp_uint16 |= (uint16_T)((uint16_T)(msg->Data[10]) << 8);
                    Given_Order.curMax = (real32_T)Temp_uint16 * 0.01F;

		    Temp_uint16 = 0;
                    Temp_int16 = 0;
                    Temp_uint16 |= (uint16_T)(msg->Data[13]);
                    Temp_uint16 |= (uint16_T)((uint16_T)(msg->Data[12]) << 8);
                    Temp_int16 = (int16_T)Temp_uint16;
                    Given_Order.curId = (real32_T)Temp_int16 * 0.01F;
		    
		    Temp_uint16 = 0;
                    Temp_int16 = 0;
                    Temp_uint16 |= (uint16_T)(msg->Data[15]);
                    Temp_uint16 |= (uint16_T)((uint16_T)(msg->Data[14]) << 8);
                    Temp_int16 = (int16_T)Temp_uint16;
                    Given_Order.curIq = (real32_T)Temp_int16 * 0.01F;

                    Temp_uint32 = 0;
                    Temp_uint32 |= (uint32_T)(msg->Data[19]);
                    Temp_uint32 |= (uint32_T)((uint32_T)(msg->Data[18]) << 8);
                    Temp_uint32 |= (uint32_T)((uint32_T)(msg->Data[17]) << 16);
                    Temp_uint32 |= (uint32_T)((uint32_T)(msg->Data[16]) << 24);
                    Given_Order.password = (uint32_T)Temp_uint32;

                    Temp_uint16 = 0;
                    Temp_uint16 |= (uint16_T)(msg->Data[21]);
                    Temp_uint16 |= (uint16_T)((uint16_T)(msg->Data[20]) << 8);
                    Given_Order.volDisDown = (real32_T)Temp_uint16 * 0.01F;

                    Temp_uint16 = 0;
                    Temp_uint16 |= (uint16_T)(msg->Data[23]);
                    Temp_uint16 |= (uint16_T)((uint16_T)(msg->Data[22]) << 8);
                    Given_Order.volDisUp = (real32_T)Temp_uint16 * 0.01F;

                    Temp_uint16 = 0;
                    Temp_uint16 |= (uint16_T)(msg->Data[25]);
                    Temp_uint16 |= (uint16_T)((uint16_T)(msg->Data[24]) << 8);
                    Given_Order.givenFlag = Temp_uint16;

                    //Given_Order.runState = Given_Order.givenFlag & 0x8000;
                }
                break;

            case 0x60: // ?????
                if (msg->Length == 32 && !msg->Extended) {
		            CANfd_Error = 0;
                    Regulator_Order_Flag = 1;
                    Regulator_Complete_Flag = 0;

                    Temp_uint32 = 0;
                    Temp_uint32 |= (uint32_T)(msg->Data[3]);
                    Temp_uint32 |= (uint32_T)((uint32_T)(msg->Data[2]) << 8);
                    Temp_uint32 |= (uint32_T)((uint32_T)(msg->Data[1]) << 16);
                    Temp_uint32 |= (uint32_T)((uint32_T)(msg->Data[0]) << 24);
                    Regulator_Order.posKp = (real_T)Temp_uint32 * 0.0001;

                    Temp_uint16 = 0;
                    Temp_uint16 |= (uint16_T)(msg->Data[5]);
                    Temp_uint16 |= (uint16_T)((uint16_T)(msg->Data[4]) << 8);
                    Regulator_Order.posKi = (real32_T)Temp_uint16 * 0.0001F;

                    Temp_uint32 = 0;
                    Temp_uint32 |= (uint32_T)(msg->Data[9]);
                    Temp_uint32 |= (uint32_T)((uint32_T)(msg->Data[8]) << 8);
                    Temp_uint32 |= (uint32_T)((uint32_T)(msg->Data[7]) << 16);
                    Temp_uint32 |= (uint32_T)((uint32_T)(msg->Data[6]) << 24);
                    Regulator_Order.spdKp = (real_T)Temp_uint32 * 0.0001;

                    Temp_uint16 = 0;
                    Temp_uint16 |= (uint16_T)(msg->Data[11]);
                    Temp_uint16 |= (uint16_T)((uint16_T)(msg->Data[10]) << 8);
                    Regulator_Order.spdKi = (real32_T)Temp_uint16 * 0.0001F;

                    Temp_uint32 = 0;
                    Temp_uint32 |= (uint32_T)(msg->Data[15]);
                    Temp_uint32 |= (uint32_T)((uint32_T)(msg->Data[14]) << 8);
                    Temp_uint32 |= (uint32_T)((uint32_T)(msg->Data[13]) << 16);
                    Temp_uint32 |= (uint32_T)((uint32_T)(msg->Data[12]) << 24);
                    Regulator_Order.curKp = (real_T)Temp_uint32 * 0.0001;

                    Temp_uint16 = 0;
                    Temp_uint16 |= (uint16_T)(msg->Data[17]);
                    Temp_uint16 |= (uint16_T)((uint16_T)(msg->Data[16]) << 8);
                    Regulator_Order.curKi = (real32_T)Temp_uint16 * 0.0001F;

                    Temp_uint32 = 0;
                    Temp_uint32 |= (uint32_T)(msg->Data[21]);
                    Temp_uint32 |= (uint32_T)((uint32_T)(msg->Data[20]) << 8);
                    Temp_uint32 |= (uint32_T)((uint32_T)(msg->Data[19]) << 16);
                    Temp_uint32 |= (uint32_T)((uint32_T)(msg->Data[18]) << 24);
                    Regulator_Order.fwKp = (real_T)Temp_uint32 * 0.0001;

                    Temp_uint16 = 0;
                    Temp_uint16 |= (uint16_T)(msg->Data[23]);
                    Temp_uint16 |= (uint16_T)((uint16_T)(msg->Data[22]) << 8);
                    Regulator_Order.fwKi = (real32_T)Temp_uint16 * 0.0001F;

                    Temp_uint16 = 0;
                    Temp_uint16 |= (uint16_T)(msg->Data[25]);
                    Temp_uint16 |= (uint16_T)((uint16_T)(msg->Data[24]) << 8);
                    Regulator_Order.fwCurMax = (real32_T)Temp_uint16 * 0.01F;


                    Temp_uint16 = 0;
                    Temp_uint16 |= (uint16_T)(msg->Data[27]);
                    Temp_uint16 |= (uint16_T)((uint16_T)(msg->Data[26]) << 8);
                    Regulator_Order.interFreq = Temp_uint16;

                    Temp_uint16 = 0;
                    Temp_uint16 |= (uint16_T)(msg->Data[29]);
                    Temp_uint16 |= (uint16_T)((uint16_T)(msg->Data[28]) << 8);
                    Regulator_Order.regFlag = Temp_uint16;
                }
                break;

            case 0x80: // ????
                if (msg->Length == 20 && !msg->Extended) {
		    CANfd_Error = 0;
                    Protect_Order_Flag = 1;
                    Protect_Complete_Flag = 0;

                    Temp_uint16 = 0;
                    Temp_uint16 = (uint16_T)(msg->Data[1]) | (uint16_T)((uint16_T)(msg->Data[0]) << 8);
                    Protect_Order.volProtOV = (real32_T)Temp_uint16 * 0.1F;

                    Temp_uint16 = 0;
                    Temp_uint16 = (uint16_T)(msg->Data[3]) | (uint16_T)((uint16_T)(msg->Data[2]) << 8);
                    Protect_Order.volProtUV = (real32_T)Temp_uint16 * 0.1F;

                    Temp_uint16 = 0;
                    Temp_uint16 = (uint16_T)(msg->Data[7]) | (uint16_T)((uint16_T)(msg->Data[6]) << 8);
                    Protect_Order.curProt = Temp_uint16;

                    Temp_uint16 = 0;
                    Temp_uint16 = (uint16_T)(msg->Data[11]) | (uint16_T)((uint16_T)(msg->Data[10]) << 8);
                    Protect_Order.spdProt = Temp_uint16;

                    Temp_uint16 = 0;
                    Temp_uint16 = (uint16_T)(msg->Data[17]) | (uint16_T)((uint16_T)(msg->Data[16]) << 8);
                    Protect_Order.curOpProt = Temp_uint16;

                    Temp_uint16 = 0;
                    Temp_uint16 = (uint16_T)(msg->Data[19]) | (uint16_T)((uint16_T)(msg->Data[18]) << 8);
                    Protect_Order.spdOpProt = Temp_uint16;

                    Temp_uint16 = 0;
                    Temp_uint16 = (uint16_T)(msg->Data[15]) | (uint16_T)((uint16_T)(msg->Data[14]) << 8);
                    Protect_Order.posOpProt = Temp_uint16;

                    Temp_uint16 = 0;
                    Temp_uint16 = (uint16_T)(msg->Data[13]) | (uint16_T)((uint16_T)(msg->Data[12]) << 8);
                    Protect_Order.powProt = (real32_T)Temp_uint16 * 0.01F;

                    Temp_uint16 = 0;
                    Temp_uint16 = (uint16_T)(msg->Data[5]) | (uint16_T)((uint16_T)(msg->Data[4]) << 8);
                    Protect_Order.protFlag = Temp_uint16;

                    Temp_uint16 = 0;
                    Temp_uint16 = (uint16_T)(msg->Data[9]) | (uint16_T)((uint16_T)(msg->Data[8]) << 8);
                    Protect_Order.protEn = Temp_uint16;
                }
                break;

            case 0xC0: // Flash??
                if (msg->Length <= 1 && !msg->Extended) {
		    CANfd_Error = 0;
                    Flag_CAN_flash_Order = 1;
		    Flag_CAN_flash_Complete = 0;

                }
                break;

            case 0x1E0: //????
                if (msg->Length == 1 && !msg->Extended) {
		    CANfd_Error = 0;
                    switch(msg->Data[0]){
			    
			    case 0:		//aligment
			    CANfd_runState = 1;
			    CANfd_runMode = 0;
			    break;
			    
			    case 0x01:		//open loop
			    CANfd_runState = 1;
			    CANfd_runMode = -1;
			    break;
			    
			    case 0x08:		//personal mode #1
			    CANfd_runState = 1;
			    CANfd_runMode = 0;
			    break;
			    
			    case 0x09:		//personal mode #2
			    CANfd_runState = 1;
			    CANfd_runMode = 0;
			    break;
			    
			    case 0x0A:		//current loop
			    CANfd_runState = 1;
			    CANfd_runMode = 1;
			    break;
			    
			    case 0x0B:		//spd loop
			    CANfd_runState = 1;
			    CANfd_runMode = 2;
			    break;
			    
			    case 0x0C:		//pos loop
			    CANfd_runState = 1;
			    CANfd_runMode = 3;
			    break;
			    
			    case 0x0F:		//stop
			    CANfd_runState = 9;
			    CANfd_runMode = 0x0F;
			    break;
		    }
		    
		    
		    memset(&ReplyMSG_Global, 0, sizeof(CAN_FD_MESSAGE_BUS));
		    ReplyMSG_Global.ID = 0x3E0;
		    ReplyMSG_Global.Length = 1U;
		    ReplyMSG_Global.Extended = 0U;
		    ReplyMSG_Global.Remote = 0;
		    ReplyMSG_Global.BRS = 1;
		    ReplyMSG_Global.ProtocolMode = 1;
		    ReplyMSG_Global.DLC = 1U;

		    ReplyMSG_Global.Data[0] = msg->Data[0];
		    Send_Test(&ReplyMSG_Global);
                }
                break;	
		
    		case 0x6E0:
			{
				Recive_Signal_0x6E0(msg->Data);
			}
		    break;
		    
		case 0x6EF:
			{
				Recive_Signal_0x6E0(msg->Data);
			}
		    break;
            default:
            CANfd_Error = 2;
              
      //  }

    }
}


void FB_reply(void)
{
    FB_Order_Flag = 0;
    FB_Complete_Flag = 0;
    memset(&ReplyMSG_Global, 0, sizeof(CAN_FD_MESSAGE_BUS));
#if(EMBActuator == FLEMB)
    ReplyMSG_Global.ID = 0x220;
#endif
#if(EMBActuator == FREMB)
    ReplyMSG_Global.ID = 0x221;
#endif
#if(EMBActuator == RLEMB)
    ReplyMSG_Global.ID = 0x222;
#endif
#if(EMBActuator == RREMB)
    ReplyMSG_Global.ID = 0x223;
#endif
    
    ReplyMSG_Global.Length = 48U;
    ReplyMSG_Global.Extended = 0U;
    ReplyMSG_Global.Remote = 0;
    ReplyMSG_Global.BRS = 1;
    ReplyMSG_Global.ProtocolMode = 1;
    ReplyMSG_Global.DLC = 14U;

    // vol
    Temp_real32 = roundf(FB_Inqury.vol * 100);
    if (Temp_real32 > 65535.0) Temp_real32 = 65535;
    else if (Temp_real32 < 0.0) Temp_real32 = 0;
    ReplyMSG_Global.Data[1] |= (uint16_T)(Temp_real32);
    ReplyMSG_Global.Data[0] |= (uint16_T)(((uint16_T)Temp_real32 & 0xFF00U) >> 8);

    // curIa
    Temp_real32 = roundf(FB_Inqury.curIa * 100);
    if (Temp_real32 > 32767.0) Temp_real32 = 32767;
    else if (Temp_real32 < -32768.0) Temp_real32 = -32768;
    Temp_int16 = (int16_T)Temp_real32;
    ReplyMSG_Global.Data[3] |= (uint16_T)(Temp_int16 & 0xFFU);
    ReplyMSG_Global.Data[2] |= (uint16_T)((Temp_int16 >> 8) & 0xFFU);

    // curIb
    Temp_real32 = roundf(FB_Inqury.curIb * 100);
    if (Temp_real32 > 32767.0) Temp_real32 = 32767;
    else if (Temp_real32 < -32768.0) Temp_real32 = -32768;
    Temp_int16 = (int16_T)Temp_real32;
    ReplyMSG_Global.Data[5] |= (uint16_T)(Temp_int16 & 0xFFU);
    ReplyMSG_Global.Data[4] |= (uint16_T)((Temp_int16 >> 8) & 0xFFU);

    // curIc
    Temp_real32 = roundf(FB_Inqury.curIc * 100);
    if (Temp_real32 > 32767.0) Temp_real32 = 32767;
    else if (Temp_real32 < -32768.0) Temp_real32 = -32768;
    Temp_int16 = (int16_T)Temp_real32;
    ReplyMSG_Global.Data[7] |= (uint16_T)(Temp_int16 & 0xFFU);
    ReplyMSG_Global.Data[6] |= (uint16_T)((Temp_int16 >> 8) & 0xFFU);

    // curId
    Temp_real32 = roundf(FB_Inqury.curId * 100);
    if (Temp_real32 > 32767.0) Temp_real32 = 32767;
    else if (Temp_real32 < -32768.0) Temp_real32 = -32768;
    Temp_int16 = (int16_T)Temp_real32;
    ReplyMSG_Global.Data[9] |= (uint16_T)(Temp_int16 & 0xFFU);
    ReplyMSG_Global.Data[8] |= (uint16_T)((Temp_int16 >> 8) & 0xFFU);

    // curIq
    Temp_real32 = roundf(FB_Inqury.curIq * 100);
    if (Temp_real32 > 32767.0) Temp_real32 = 32767;
    else if (Temp_real32 < -32768.0) Temp_real32 = -32768;
    Temp_int16 = (int16_T)Temp_real32;
    ReplyMSG_Global.Data[11] |= (uint16_T)(Temp_int16 & 0xFFU);
    ReplyMSG_Global.Data[10] |= (uint16_T)((Temp_int16 >> 8) & 0xFFU);


    // curIdRef
    Temp_real32 = roundf(FB_Inqury.curIdRef * 100);
    if (Temp_real32 > 32767.0) Temp_real32 = 32767;
    else if (Temp_real32 < -32768.0) Temp_real32 = -32768;
    Temp_int16 = (int16_T)Temp_real32;
    ReplyMSG_Global.Data[13] |= (uint16_T)(Temp_int16 & 0xFFU);
    ReplyMSG_Global.Data[12] |= (uint16_T)((Temp_int16 >> 8) & 0xFFU);
    
    
    // curIqRef
    Temp_real32 = roundf(FB_Inqury.curIqRef * 100);
    if (Temp_real32 > 32767.0) Temp_real32 = 32767;
    else if (Temp_real32 < -32768.0) Temp_real32 = -32768;
    Temp_int16 = (int16_T)Temp_real32;
    ReplyMSG_Global.Data[15] |= (uint16_T)(Temp_int16 & 0xFFU);
    ReplyMSG_Global.Data[14] |= (uint16_T)((Temp_int16 >> 8) & 0xFFU);

    // spd
    Temp_real32 = roundf(FB_Inqury.spd * 10);
    if (Temp_real32 > 2147483647.0) Temp_real32 = 2147483647;
    else if (Temp_real32 < -2147483648.0) Temp_real32 = -2147483648;
    Temp_int32 = (int32_T)Temp_real32;
    ReplyMSG_Global.Data[19] |= (uint16_T)(Temp_int32 & 0xFFU);
    ReplyMSG_Global.Data[18] |= (uint16_T)((Temp_int32 & 0xFF00U) >> 8);
    ReplyMSG_Global.Data[17] |= (uint16_T)((Temp_int32 & 0xFF0000U) >> 16);
    ReplyMSG_Global.Data[16] |= (uint16_T)((Temp_int32 & 0xFF000000U) >> 24);

    // spdRef
    Temp_real32 = roundf(FB_Inqury.spdRef * 10);
    if (Temp_real32 > 2147483647.0) Temp_real32 = 2147483647;
    else if (Temp_real32 < -2147483648.0) Temp_real32 = -2147483648;
    Temp_int32 = (int32_T)Temp_real32;
    ReplyMSG_Global.Data[23] |= (uint16_T)(Temp_int32 & 0xFFU);
    ReplyMSG_Global.Data[22] |= (uint16_T)((Temp_int32 & 0xFF00U) >> 8);
    ReplyMSG_Global.Data[21] |= (uint16_T)((Temp_int32 & 0xFF0000U) >> 16);
    ReplyMSG_Global.Data[20] |= (uint16_T)((Temp_int32 & 0xFF000000U) >> 24);


    // pre
    Temp_real32 = roundf(FB_Inqury.pre * 1000);
    if (Temp_real32 > 65535.0) Temp_real32 = 65535;
    else if (Temp_real32 < 0.0) Temp_real32 = 0;
    ReplyMSG_Global.Data[25] |= (uint16_T)(Temp_real32);
    ReplyMSG_Global.Data[24] |= (uint16_T)(((uint16_T)Temp_real32 & 0xFF00U) >> 8);

    // preRef
    Temp_real32 = roundf(fromBCU_YC_FL.BrkForceCmd);
    
    //Temp_real32 = roundf(FB_Inqury.preRef * 1000);
    if (Temp_real32 > 65535.0) Temp_real32 = 65535;
    else if (Temp_real32 < 0.0) Temp_real32 = 0;
    ReplyMSG_Global.Data[27] |= (uint16_T)(Temp_real32);
    ReplyMSG_Global.Data[26] |= (uint16_T)(((uint16_T)Temp_real32 & 0xFF00U) >> 8);

    // pos
    Temp_real32 = roundf(FB_Inqury.pos * 100);
    if (Temp_real32 > 32767.0) Temp_real32 = 32767;
    else if (Temp_real32 < -32768.0) Temp_real32 = -32768;
    Temp_int16 = (int16_T)Temp_real32;
    ReplyMSG_Global.Data[29] |= (uint16_T)(Temp_int16 & 0xFFU);
    ReplyMSG_Global.Data[28] |= (uint16_T)((Temp_int16 >> 8) & 0xFFU);

    // posRef
    Temp_real32 = roundf(FB_Inqury.posRef * 100);
    if (Temp_real32 > 32767.0) Temp_real32 = 32767;
    else if (Temp_real32 < -32768.0) Temp_real32 = -32768;
    Temp_int16 = (int16_T)Temp_real32;
    ReplyMSG_Global.Data[31] |= (uint16_T)(Temp_int16 & 0xFFU);
    ReplyMSG_Global.Data[30] |= (uint16_T)((Temp_int16 >> 8) & 0xFFU);

    // errCode
    Temp_uint32 = (uint32_T)(FB_Inqury.errCode);
    ReplyMSG_Global.Data[35] |= (uint16_T)(Temp_uint32 & 0xFFU);
    ReplyMSG_Global.Data[34] |= (uint16_T)((Temp_uint32 & 0xFF00U) >> 8);
    ReplyMSG_Global.Data[33] |= (uint16_T)((Temp_uint32 & 0xFF0000U) >> 16);
    ReplyMSG_Global.Data[32] |= (uint16_T)((Temp_uint32 & 0xFF000000U) >> 24);

    // temp1
    Temp_uint16 = (int16_T)(FB_Inqury.temp1 + 55);
    if (Temp_uint16 < 0) Temp_uint16 = 0;
    if (Temp_uint16 > 65535) Temp_uint16 = 65535;
    ReplyMSG_Global.Data[37] |= (uint16_T)(Temp_uint16);
    ReplyMSG_Global.Data[36] |= (uint16_T)((Temp_uint16 & 0xFF00U) >> 8);

    // temp2
    Temp_uint16 = (int16_T)(FB_Inqury.temp2 + 55);
    if (Temp_uint16 < 0) Temp_uint16 = 0;
    if (Temp_uint16 > 65535) Temp_uint16 = 65535;
    ReplyMSG_Global.Data[39] |= (uint16_T)(Temp_uint16);
    ReplyMSG_Global.Data[38] |= (uint16_T)((Temp_uint16 & 0xFF00U) >> 8);

    // version
    Temp_uint32 = (uint32_T)(FB_Inqury.version);
    ReplyMSG_Global.Data[43] |= (uint16_T)(Temp_uint32 & 0xFFU);
    ReplyMSG_Global.Data[42] |= (uint16_T)((Temp_uint32 & 0xFF00U) >> 8);
    ReplyMSG_Global.Data[41] |= (uint16_T)((Temp_uint32 & 0xFF0000U) >> 16);
    ReplyMSG_Global.Data[40] |= (uint16_T)((Temp_uint32 & 0xFF000000U) >> 24);

    Send_Test(&ReplyMSG_Global);
}


void Given_reply(void)
{
    Given_Complete_Flag = 0;
    Given_Order_Flag = 0;
    memset(&ReplyMSG_Global, 0, sizeof(CAN_FD_MESSAGE_BUS));
    ReplyMSG_Global.ID = 0x240;
    ReplyMSG_Global.Length = 32U;
    ReplyMSG_Global.Extended = 0U;
    ReplyMSG_Global.Remote = 0;
    ReplyMSG_Global.BRS = 1;
    ReplyMSG_Global.ProtocolMode = 1;
    ReplyMSG_Global.DLC = 13U;

    // pre
    Temp_real32 = roundf(Given_Complete.pre * 1000);
    if (Temp_real32 > 65535.0) Temp_real32 = 65535;
    else if (Temp_real32 < 0.0) Temp_real32 = 0;
    ReplyMSG_Global.Data[1] |= (uint16_T)(Temp_real32);
    ReplyMSG_Global.Data[0] |= (uint16_T)(((uint16_T)Temp_real32 & 0xFF00U) >> 8);

    // pos
    Temp_real32 = roundf(Given_Complete.pos * 100);
    if (Temp_real32 > 32767.0) Temp_real32 = 32767;
    else if (Temp_real32 < -32768.0) Temp_real32 = -32768;
    Temp_int16 = (int16_T)Temp_real32;
    ReplyMSG_Global.Data[3] |= (uint16_T)(Temp_int16 & 0xFFU);
    ReplyMSG_Global.Data[2] |= (uint16_T)((Temp_int16 >> 8) & 0xFFU);

   // spdMax
   Temp_real32 = roundf(Given_Complete.spdMax);
   if (Temp_real32 > 65535.0) Temp_real32 = 65535;
   else if (Temp_real32 < 0.0) Temp_real32 = 0;
   ReplyMSG_Global.Data[5] |= (uint16_T)(Temp_real32);
   ReplyMSG_Global.Data[4] |= (uint16_T)(((uint16_T)Temp_real32 & 0xFF00U) >> 8);


    // spd
    Temp_real32 = roundf(Given_Complete.spd * 10);
    if (Temp_real32 > 2147483647.0) Temp_real32 = 2147483647;
    else if (Temp_real32 < -2147483648.0) Temp_real32 = -2147483648;
    
    //Temp_int32 = (int32_T)Temp_real32;
    if(Temp_real32 >= 0){    
    	Temp_uint32 = (uint32_T)Temp_real32;
    }
    else{
	Temp_uint32 = abs(Temp_real32);
	Temp_uint32 = ~Temp_uint32 + 1;
    }
    
    ReplyMSG_Global.Data[9] |= (uint16_T)(Temp_uint32 & 0xFFU);
    ReplyMSG_Global.Data[8] |= (uint16_T)((Temp_uint32 & 0xFF00U) >> 8);
    ReplyMSG_Global.Data[7] |= (uint16_T)((Temp_uint32 & 0xFF0000U) >> 16);
    ReplyMSG_Global.Data[6] |= (uint16_T)((Temp_uint32 & 0xFF000000U) >> 24);

    // curMax
    Temp_real32 = roundf(Given_Complete.curMax * 100);
    if (Temp_real32 > 32767.0) Temp_real32 = 32767;
    else if (Temp_real32 < -32768.0) Temp_real32 = -32768;
    Temp_int16 = (int16_T)Temp_real32;
    ReplyMSG_Global.Data[11] |= (uint16_T)(Temp_int16 & 0xFFU);
    ReplyMSG_Global.Data[10] |= (uint16_T)((Temp_int16 >> 8) & 0xFFU);

    // cur
    Temp_real32 = roundf(Given_Complete.curId * 100);
    if (Temp_real32 > 32767.0) Temp_real32 = 32767;
    else if (Temp_real32 < -32768.0) Temp_real32 = -32768;
    Temp_int16 = (int16_T)Temp_real32;
    ReplyMSG_Global.Data[13] |= (uint16_T)(Temp_int16 & 0xFFU);
    ReplyMSG_Global.Data[12] |= (uint16_T)((Temp_int16 >> 8) & 0xFFU);
    
    // cur
    Temp_real32 = roundf(Given_Complete.curIq * 100);
    if (Temp_real32 > 32767.0) Temp_real32 = 32767;
    else if (Temp_real32 < -32768.0) Temp_real32 = -32768;
    Temp_int16 = (int16_T)Temp_real32;
    ReplyMSG_Global.Data[15] |= (uint16_T)(Temp_int16 & 0xFFU);
    ReplyMSG_Global.Data[14] |= (uint16_T)((Temp_int16 >> 8) & 0xFFU);

    // password
    Temp_uint32 = (uint32_T)(Given_Complete.password);
    ReplyMSG_Global.Data[19] |= (uint16_T)(Temp_uint32 & 0xFFU);
    ReplyMSG_Global.Data[18] |= (uint16_T)((Temp_uint32 & 0xFF00U) >> 8);
    ReplyMSG_Global.Data[17] |= (uint16_T)((Temp_uint32 & 0xFF0000U) >> 16);
    ReplyMSG_Global.Data[16] |= (uint16_T)((Temp_uint32 & 0xFF000000U) >> 24);

    // volDisDown
    Temp_real32 = roundf(Given_Complete.volDisDown *100);
    if (Temp_real32 > 65535.0) Temp_real32 = 65535;
    else if (Temp_real32 < 0.0) Temp_real32 = 0;
    ReplyMSG_Global.Data[21] |= (uint16_T)(Temp_real32);
    ReplyMSG_Global.Data[20] |= (uint16_T)(((uint16_T)Temp_real32 & 0xFF00U) >> 8);

    // volDisUp
    Temp_real32 = roundf(Given_Complete.volDisUp * 100);
    if (Temp_real32 > 65535.0) Temp_real32 = 65535;
    else if (Temp_real32 < 0.0) Temp_real32 = 0;
    ReplyMSG_Global.Data[23] |= (uint16_T)(Temp_real32);
    ReplyMSG_Global.Data[22] |= (uint16_T)(((uint16_T)Temp_real32 & 0xFF00U) >> 8);

    // givenFlag
    Temp_real32 = roundf(Given_Complete.givenFlag);
    if (Temp_real32 > 65535.0) Temp_real32 = 65535;
    else if (Temp_real32 < 0.0) Temp_real32 = 0;
    ReplyMSG_Global.Data[25] |= (uint16_T)(Temp_real32);
    ReplyMSG_Global.Data[24] |= (uint16_T)(((uint16_T)Temp_real32 & 0xFF00U) >> 8);

    Send_Test(&ReplyMSG_Global);
}


void Regulator_reply(void)
{
    Regulator_Complete_Flag = 0;
    Regulator_Order_Flag = 0;
    memset(&ReplyMSG_Global, 0, sizeof(CAN_FD_MESSAGE_BUS));
    ReplyMSG_Global.ID = 608;
    ReplyMSG_Global.Length = 32U;
    ReplyMSG_Global.Extended = 0U;
    ReplyMSG_Global.Remote = 0;
    ReplyMSG_Global.BRS = 1;
    ReplyMSG_Global.ProtocolMode = 1;
    ReplyMSG_Global.DLC = 13U;

    // posKp
    Temp_real32 = roundf(Regulator_Complete.posKp * 10000);
    if (Temp_real32 < 0.0) Temp_real32 = 0;
    Temp_uint32 = (uint32_T)Temp_real32;
    ReplyMSG_Global.Data[3] |= (uint16_T)(Temp_uint32 & 0xFFU);
    ReplyMSG_Global.Data[2] |= (uint16_T)((Temp_uint32 >> 8) & 0xFFU);
    ReplyMSG_Global.Data[1] |= (uint16_T)((Temp_uint32 >> 16) & 0xFFU);
    ReplyMSG_Global.Data[0] |= (uint16_T)((Temp_uint32 >> 24) & 0xFFU);

    // posKi
    Temp_real32 = roundf(Regulator_Complete.posKi * 10000);
    if (Temp_real32 > 65535.0) Temp_real32 = 65535;
    else if (Temp_real32 < 0.0) Temp_real32 = 0;
    Temp_uint16 = (uint16_T)Temp_real32;
    ReplyMSG_Global.Data[5] |= (uint16_T)(Temp_uint16 & 0xFFU);
    ReplyMSG_Global.Data[4] |= (uint16_T)((Temp_uint16 >> 8) & 0xFFU);

    // spdKp
    Temp_real32 = roundf(Regulator_Complete.spdKp * 10000);
    if (Temp_real32 < 0.0) Temp_real32 = 0;
    Temp_uint32 = (uint32_T)Temp_real32;
    ReplyMSG_Global.Data[9] |= (uint16_T)(Temp_uint32 & 0xFFU);
    ReplyMSG_Global.Data[8] |= (uint16_T)((Temp_uint32 >> 8) & 0xFFU);
    ReplyMSG_Global.Data[7] |= (uint16_T)((Temp_uint32 >> 16) & 0xFFU);
    ReplyMSG_Global.Data[6] |= (uint16_T)((Temp_uint32 >> 24) & 0xFFU);

    // spdKi
    Temp_real32 = roundf(Regulator_Complete.spdKi * 10000);
    if (Temp_real32 > 65535.0) Temp_real32 = 65535;
    else if (Temp_real32 < 0.0) Temp_real32 = 0;
    Temp_uint16 = (uint16_T)Temp_real32;
    ReplyMSG_Global.Data[11] |= (uint16_T)(Temp_uint16 & 0xFFU);
    ReplyMSG_Global.Data[10] |= (uint16_T)((Temp_uint16 >> 8) & 0xFFU);

    // curKp
    Temp_real32 = roundf(Regulator_Complete.curKp * 10000);
    if (Temp_real32 < 0.0) Temp_real32 = 0;
    Temp_uint32 = (uint32_T)Temp_real32;
    ReplyMSG_Global.Data[15] |= (uint16_T)(Temp_uint32 & 0xFFU);
    ReplyMSG_Global.Data[14] |= (uint16_T)((Temp_uint32 >> 8) & 0xFFU);
    ReplyMSG_Global.Data[13] |= (uint16_T)((Temp_uint32 >> 16) & 0xFFU);
    ReplyMSG_Global.Data[12] |= (uint16_T)((Temp_uint32 >> 24) & 0xFFU);

    // curKi
    Temp_real32 = roundf(Regulator_Complete.curKi * 10000);
    if (Temp_real32 > 65535.0) Temp_real32 = 65535;
    else if (Temp_real32 < 0.0) Temp_real32 = 0;
    Temp_uint16 = (uint16_T)Temp_real32;
    ReplyMSG_Global.Data[17] |= (uint16_T)(Temp_uint16 & 0xFFU);
    ReplyMSG_Global.Data[16] |= (uint16_T)((Temp_uint16 >> 8) & 0xFFU);

    // fwKp
    Temp_real32 = roundf(Regulator_Complete.fwKp * 10000);
    if (Temp_real32 < 0.0) Temp_real32 = 0;
    Temp_uint32 = (uint32_T)Temp_real32;
    ReplyMSG_Global.Data[21] |= (uint16_T)(Temp_uint32 & 0xFFU);
    ReplyMSG_Global.Data[20] |= (uint16_T)((Temp_uint32 >> 8) & 0xFFU);
    ReplyMSG_Global.Data[19] |= (uint16_T)((Temp_uint32 >> 16) & 0xFFU);
    ReplyMSG_Global.Data[18] |= (uint16_T)((Temp_uint32 >> 24) & 0xFFU);

    // fwKi
    Temp_real32 = roundf(Regulator_Complete.fwKi * 10000);
    if (Temp_real32 > 65535.0) Temp_real32 = 65535;
    else if (Temp_real32 < 0.0) Temp_real32 = 0;
    Temp_uint16 = (uint16_T)Temp_real32;
    ReplyMSG_Global.Data[23] |= (uint16_T)(Temp_uint16 & 0xFFU);
    ReplyMSG_Global.Data[22] |= (uint16_T)((Temp_uint16 >> 8) & 0xFFU);

    // fwCurMax
    Temp_real32 = roundf(Regulator_Complete.fwKi * 100);
    if (Temp_real32 > 65535.0) Temp_real32 = 65535;
    else if (Temp_real32 < 0.0) Temp_real32 = 0;
    Temp_uint16 = (uint16_T)Temp_real32;
    ReplyMSG_Global.Data[25] |= (uint16_T)(Temp_uint16 & 0xFFU);
    ReplyMSG_Global.Data[24] |= (uint16_T)((Temp_uint16 >> 8) & 0xFFU);

    // interFreq
    Temp_uint16 = (uint16_T)Regulator_Complete.interFreq;
    ReplyMSG_Global.Data[27] |= (uint16_T)(Temp_uint16 & 0xFFU);
    ReplyMSG_Global.Data[26] |= (uint16_T)((Temp_uint16 >> 8) & 0xFFU);

    // regFlag
    Temp_uint16 = (uint16_T)Regulator_Complete.regFlag;
    ReplyMSG_Global.Data[29] |= (uint16_T)(Temp_uint16 & 0xFFU);
    ReplyMSG_Global.Data[28] |= (uint16_T)((Temp_uint16 >> 8) & 0xFFU);

    Send_Test(&ReplyMSG_Global);
}


void Protect_reply(void)
{
    Protect_Order_Flag = 0;
    Protect_Complete_Flag = 0;
    memset(&ReplyMSG_Global, 0, sizeof(CAN_FD_MESSAGE_BUS));
    ReplyMSG_Global.ID = 640;
    ReplyMSG_Global.Length = 20U;
    ReplyMSG_Global.Extended = 0U;
    ReplyMSG_Global.Remote = 0;
    ReplyMSG_Global.BRS = 1;
    ReplyMSG_Global.ProtocolMode = 1;
    ReplyMSG_Global.DLC = 11U;

    // volProtOV
    Temp_real32 = roundf(Protect_Complete.volProtOV * 10);
    if (Temp_real32 > 65535.0) Temp_real32 = 65535;
    else if (Temp_real32 < 0.0) Temp_real32 = 0;
    Temp_uint16 = (uint16_T)Temp_real32;
    ReplyMSG_Global.Data[1] |= (uint16_T)(Temp_uint16 & 0xFFU);
    ReplyMSG_Global.Data[0] |= (uint16_T)((Temp_uint16 >> 8) & 0xFFU);

    // volProtUV
    Temp_real32 = roundf(Protect_Complete.volProtUV * 10);
    if (Temp_real32 > 65535.0) Temp_real32 = 65535;
    else if (Temp_real32 < 0.0) Temp_real32 = 0;
    Temp_uint16 = (uint16_T)Temp_real32;
    ReplyMSG_Global.Data[3] |= (uint16_T)(Temp_uint16 & 0xFFU);
    ReplyMSG_Global.Data[2] |= (uint16_T)((Temp_uint16 >> 8) & 0xFFU);

    // curProt
    Temp_uint16 = (uint16_T)Protect_Complete.curProt;
    ReplyMSG_Global.Data[5] |= (uint16_T)(Temp_uint16 & 0xFFU);
    ReplyMSG_Global.Data[4] |= (uint16_T)((Temp_uint16 >> 8) & 0xFFU);

    // spdProt
    Temp_uint16 = (uint16_T)Protect_Complete.spdProt;
    ReplyMSG_Global.Data[7] |= (uint16_T)(Temp_uint16 & 0xFFU);
    ReplyMSG_Global.Data[6] |= (uint16_T)((Temp_uint16 >> 8) & 0xFFU);

    // curOpProt
    Temp_uint16 = (uint16_T)Protect_Complete.curOpProt;
    ReplyMSG_Global.Data[9] |= (uint16_T)(Temp_uint16 & 0xFFU);
    ReplyMSG_Global.Data[8] |= (uint16_T)((Temp_uint16 >> 8) & 0xFFU);

    // spdOpProt
    Temp_uint16 = (uint16_T)Protect_Complete.spdOpProt;
    ReplyMSG_Global.Data[11] |= (uint16_T)(Temp_uint16 & 0xFFU);
    ReplyMSG_Global.Data[10] |= (uint16_T)((Temp_uint16 >> 8) & 0xFFU);

    // posOpProt
    Temp_real32 = roundf(Protect_Complete.posOpProt * 100);
    if (Temp_real32 > 65535.0) Temp_real32 = 65535;
    else if (Temp_real32 < 0.0) Temp_real32 = 0;
    Temp_uint16 = (uint16_T)Temp_real32;
    ReplyMSG_Global.Data[13] |= (uint16_T)(Temp_uint16 & 0xFFU);
    ReplyMSG_Global.Data[12] |= (uint16_T)((Temp_uint16 >> 8) & 0xFFU);

    // powProt
    Temp_uint16 = (uint16_T)Protect_Complete.powProt;
    ReplyMSG_Global.Data[15] |= (uint16_T)(Temp_uint16 & 0xFFU);
    ReplyMSG_Global.Data[14] |= (uint16_T)((Temp_uint16 >> 8) & 0xFFU);

    // protFlag
    Temp_uint16 = (uint16_T)Protect_Complete.protFlag;
    ReplyMSG_Global.Data[17] |= (uint16_T)(Temp_uint16 & 0xFFU);
    ReplyMSG_Global.Data[16] |= (uint16_T)((Temp_uint16 >> 8) & 0xFFU);

    // protEn
    Temp_uint16 = (uint16_T)Protect_Complete.protEn;
    ReplyMSG_Global.Data[19] |= (uint16_T)(Temp_uint16 & 0xFFU);
    ReplyMSG_Global.Data[18] |= (uint16_T)((Temp_uint16 >> 8) & 0xFFU);

    Send_Test(&ReplyMSG_Global);
}


void Flash_reply(void)
{


    memset(&ReplyMSG_Global, 0, sizeof(CAN_FD_MESSAGE_BUS));
    ReplyMSG_Global.ID = 0x2C0;
    ReplyMSG_Global.Length = 1U;
    ReplyMSG_Global.Extended = 0U;
    ReplyMSG_Global.Remote = 0;
    ReplyMSG_Global.BRS = 1;
    ReplyMSG_Global.ProtocolMode = 1;
    ReplyMSG_Global.DLC = 1U;

    Send_Test(&ReplyMSG_Global);
}

void Error_reply(void)
{
    memset(&ReplyMSG_Global, 0, sizeof(CAN_FD_MESSAGE_BUS));
    ReplyMSG_Global.ID = 0x7FF;
    ReplyMSG_Global.Length = 1U;
    ReplyMSG_Global.Extended = 0U;
    ReplyMSG_Global.Remote = 0;
    ReplyMSG_Global.BRS = 1;
    ReplyMSG_Global.ProtocolMode = 1;
    ReplyMSG_Global.DLC = 1U;

    ReplyMSG_Global.Data[0] = CANfd_Error;
    Send_Test(&ReplyMSG_Global);
}




