#include <stdio.h>
#include <string.h>
#include <math.h>
#include "mttcan_a.h"
//#include "canfd.h"
#include "rtwtypes.h"
#define INVALID_CAN_ID 0

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
    if(Password_Flag){
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
            
            default:
            CANfd_Error = 2;
              
        }

    }
    if(!Password_Flag){
        CANfd_Error = 1;
    }

    if(CANfd_Error != 0 && msg->ID != 0x1C0){
        Error_reply();
    }
}


void FB_reply(void)
{
    FB_Order_Flag = 0;
    FB_Complete_Flag = 0;
    memset(&ReplyMSG_Global, 0, sizeof(CAN_FD_MESSAGE_BUS));
    ReplyMSG_Global.ID = 0x220;
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
    Temp_real32 = roundf(FB_Inqury.preRef * 1000);
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




