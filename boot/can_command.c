#include <ree_types.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include "global_struct.h"
#include "parameter.h"
//#define  DRIVER_LOCAL
#define  APPLICATION_INTERFACE

#include <mttcan.h>
#include <gtm.h>
//#include "mttcan_p.h"
//#include "mttcan_s.h"

#include <can_command.h>

// 外部变量声明 - 用于获取系统状态数据
extern float temperature;        // 温度数据
extern ControlManage_t g_Control; // 控制管理结构体

/*
 * DBC兼容的数据处理函数
 * 按照标准DBC定义进行小端序数据打包和解包
 */

// 小端序打包16位有符号数据
void pack_int16_le(unsigned short *data, int offset, int16 value) {
    data[offset] = value & 0xFF;
    data[offset + 1] = (value >> 8) & 0xFF;
}

// 小端序打包32位有符号数据  
void pack_int32_le(unsigned short *data, int offset, int32 value) {
    data[offset] = value & 0xFF;
    data[offset + 1] = (value >> 8) & 0xFF;
    data[offset + 2] = (value >> 16) & 0xFF;
    data[offset + 3] = (value >> 24) & 0xFF;
}

// 小端序解包16位有符号数据
int16 unpack_int16_le(const unsigned short *data, int offset) {
    return (int16)(data[offset] | (data[offset + 1] << 8));
}

// 小端序解包32位有符号数据
int32 unpack_int32_le(const unsigned short *data, int offset) {
    return (int32)(data[offset] | (data[offset + 1] << 8) | 
                   (data[offset + 2] << 16) | (data[offset + 3] << 24));
}

void can_send(const CAN_MSG *pCANMsg,u08 Unit1_u08);
Uint32 hCAN_Pack(Uint16 NodeID,Uint16 CmdCode);
void Obj_Read(Uint16 ObjID,Uint16 AttriID,CAN_MSG *pCANMsg);
void Obj_Write(Uint16 ObjID,Uint16 AttriID,const Uint16 *pWriteData,Uint16 writeSize,CAN_MSG *pCANMsg);
void ObjAttri_Read(Uint16 ObjID,Uint16 AttriID,const char *pData,Uint16 dataSize,CAN_MSG *pCANMsg);
void ObjAttri_Write(Uint16 ObjID,Uint16 AttriID,char *pData,Uint16 dataSize,const Uint16 *pWriteData,Uint16 writeSize,CAN_MSG *pCANMsg);
void CANPack_ValveStatus(CAN_MSG *pCANMsg);


/*
 * Global Variables
 */
Object_t g_CANObject;


//extern Uint32 error_state_code_0101;//错误标志位

#define INITIAL_SETTING_DEFAULTS {   \
                           0xF100,   \
                           1,        \
                           300,      \
                           1200,     \
                           3,        \
                           2500     \
                          }
typedef struct
{
    Uint16 SoftVersion;/*版本号*/
    int16 Nodeid;/*节点号*/
    Uint16 TimeOutSet;//超时时间 ms
    Uint16 MaxSpeed_Initial;//最大转速
    int16 SpeedStep_Initial;//速度阶跃幅度选择,1~5->100~500
    int32 StepTimecount;//2500*50us对应每125ms速度给定加速


}MainSet_t;//初始值
MainSet_t g_Initial = INITIAL_SETTING_DEFAULTS;

 
 /*
 * Application Test Functions
 */
 int flag_hyxx;

 int Flag_CAN_flash = 0;
 int Flag_Cansend = 0;
 
 int flashcode = 0;
 int sendcode = 0;

 // CAN发送轮询状态变量
 static int send_state = 0;          // 发送状态机：0=电流，1=速度，2=三相电流，3=母线电压，4=位置，5=温度
 static int last_2ms_time = 0;       // 上次2ms数据（电流）发送时间
 static int last_10ms_time = 0;      // 上次10ms数据发送时间（用于速度和三相电流的周期控制）
 static int last_20ms_time = 0;      // 上次20ms数据发送时间（用于电压、位置、温度的周期控制）
 static int speed_sent = 0;          // 本周期10ms数据中速度是否已发送
 static int current3_sent = 0;       // 本周期10ms数据中三相电流是否已发送
 static int voltage_sent = 0;        // 本周期20ms数据中电压是否已发送
 static int position_sent = 0;       // 本周期20ms数据中位置是否已发送
 static int temperature_sent = 0;    // 本周期20ms数据中温度是否已发送

 int Canref_O = 0;
 int Canref_M = 0;
 int Flash_fix = 0;
 int vehspd = 0;
 int Canref = 0;
 unsigned int error_a = 0;
 extern unsigned int error_state_code_0101;
 extern int sleepflag;

 extern unsigned int  rx_angle[4];
 int cantime = 0;

//=============================================================================
// FunctionName: MTTCAN_Reset
// IN  :         Unit Number
// OUT :         Success Status
// Description : Resets M_CAN unit and releases Port
// 
//=============================================================================

void can_command_process(CAN_MSG *pmsg,u08 Unit1_u08)
{
    Uint16 NodeID;//节点号
    Uint16 CmdCode;//命令码

    CAN_MSG CANMsgSend;



    //g_CANflash.cur.kp = 1;
    NodeID = (Uint16)(pmsg->id & 0x0F);//节点ID
    CmdCode = (Uint16)((pmsg->id >> 5) & 0x001F);
    
    flashcode = (Uint16)(pmsg->data8[0]);

    

/* 正常模式和故障模式下均需要响应的命令 */
    switch(CmdCode)
    {
   
	memset(&CANMsgSend,0,sizeof(CAN_MSG) );
	   
    case 0x01://flash do
	Flag_CAN_flash = 1;
	break;
	
    case 0x02://flash adjust

	CANMsgSend.id = 0x240;
	switch(flashcode)
	{
      	case 0xA1://current kp
		if(pmsg->data8[1] == 0x01){
			Canref = (Uint16)(pmsg->data8[2]) |  ((Uint16)(pmsg->data8[3]) << 8); // 小端序解析
			// DBC边界检查：ParamValue1范围[0|65535]，换算后KP最大值65.535
			if(Canref <= 65535) {
				g_CANflash.cur.kp = Canref * 0.001;
				g_CANflash.flag |= _PORT_SET_BIT0;
			}
        }

		if(pmsg->data8[1] == 0x00){
			Canref = (pi_iq.Kp)*1000;
			CANMsgSend.data8[2] = Canref & 0xFF;        // 低字节在前(小端序)
			CANMsgSend.data8[3] = (Canref >> 8) & 0xFF; // 高字节在后(小端序)
			CANMsgSend.data8[0] = 0xA1;
			CANMsgSend.data8[1] = 00;
			CANMsgSend.len = 8;	
		}
	    break;
		
	case 0xA2://current ki
        if(pmsg->data8[1] == 0x01){
			Canref = (Uint16)(pmsg->data8[2]) |  ((Uint16)(pmsg->data8[3]) << 8); // 小端序解析
			g_CANflash.cur.ki = Canref * 0.0001;
			g_CANflash.flag |= _PORT_SET_BIT1;
	    }
	    if(pmsg->data8[1] == 0x00){
			Canref = (pi_iq.Ki)*10000;
			CANMsgSend.data8[2] = Canref & 0xFF;        // 低字节在前(小端序)
			CANMsgSend.data8[3] = (Canref >> 8) & 0xFF; // 高字节在后(小端序)
			CANMsgSend.data8[0] = 0xA2;
			CANMsgSend.data8[1] = 00;
			CANMsgSend.len = 8;	
		}
	    break;
		
	case 0xA3://current iq id
	    if(pmsg->data8[1] == 0x01){//iq
		g_CANflash.qRef = (Uint16)((pmsg->data8[4] & 0x7F) << 8 |  pmsg->data8[5]);
		if((pmsg->data8[2] & 0x80) == 0x80){
		    g_CANflash.qRef_float = g_CANflash.qRef * -0.01;
		}else{
		    g_CANflash.qRef_float = g_CANflash.qRef * 0.01;
		}
		
		g_CANflash.dRef = (Uint16)((pmsg->data8[6]) << 8 |  pmsg->data8[7]);//id
		g_CANflash.dRef_float = g_CANflash.dRef * -0.01;
		g_CANflash.flag |= _PORT_SET_BIT2;
	    }
		
	    if(pmsg->data8[1] == 0x00){
		Canref = ABS(g_Control.IqRef)*100*CURRENT_PU_RE;//iq
		if(g_Control.IqRef >= 0){
		    CANMsgSend.data8[4] = Canref & 0xFF;        // 低字节在前(小端序)
		    CANMsgSend.data8[5] = (Canref >> 8) & 0xFF; // 高字节在后(小端序)
		}
		else{
		    CANMsgSend.data8[4] = Canref & 0xFF;        // 低字节在前(小端序)
		    CANMsgSend.data8[5] = ((Canref >> 8) & 0xFF) | 0x80; // 高字节在后+符号位(小端序)
		}

		Canref = ABS(g_Control.IdRef)*100*CURRENT_PU_RE;//id
		CANMsgSend.data8[6] = Canref & 0xFF;        // 低字节在前(小端序)
		CANMsgSend.data8[7] = (Canref >> 8) & 0xFF; // 高字节在后(小端序)
		CANMsgSend.data8[0] = 0xA3;
		CANMsgSend.data8[1] = 00;
		CANMsgSend.len = 8;	
		}
	    break;
		
	case 0xB1://speed kp
	    if(pmsg->data8[1] == 0x01){
			Canref = (Uint16)(pmsg->data8[2]) |  ((Uint16)(pmsg->data8[3]) << 8); // 小端序解析
			g_CANflash.spd.kp = Canref * 0.001;
			g_CANflash.flag |= _PORT_SET_BIT3;//
	    }
		
	    if(pmsg->data8[1] == 0x00){
			Canref = (pi_spd.Kp)*1000;
			CANMsgSend.data8[2] = Canref & 0xFF;        // 低字节在前(小端序)
			CANMsgSend.data8[3] = (Canref >> 8) & 0xFF; // 高字节在后(小端序)
			CANMsgSend.data8[0] = 0xB1;
			CANMsgSend.data8[1] = 00;
			CANMsgSend.len = 8;	
	    }
	    break;
		
	case 0xB2://speed ki
	    if(pmsg->data8[1] == 0x01){
			Canref = (Uint16)(pmsg->data8[2]) |  ((Uint16)(pmsg->data8[3]) << 8); // 小端序解析
			g_CANflash.spd.ki = Canref * 0.0001;
			g_CANflash.flag |= _PORT_SET_BIT4;//
	    }
		
	    if(pmsg->data8[1] == 0x00){
			Canref = (pi_spd.Ki)*10000;
			CANMsgSend.data8[2] = Canref & 0xFF;        // 低字节在前(小端序)
			CANMsgSend.data8[3] = (Canref >> 8) & 0xFF; // 高字节在后(小端序)
			CANMsgSend.data8[0] = 0xB2;
			CANMsgSend.data8[1] = 00;
			CANMsgSend.len = 8;	
	    }
	    break;
		
	case 0xB3://speedref & current max
	    if(pmsg->data8[1] == 0x01){//spdref
			g_CANflash.spdRef = (Uint16)((pmsg->data8[4]) << 8 |  pmsg->data8[5]);
	        if((pmsg->data8[4] & 0x80) == 0x80){
                    g_CANflash.spdRef_float = (g_CANflash.spdRef & 0x7FFF) * -1.0;
            }
			else{
                    g_CANflash.spdRef_float = (g_CANflash.spdRef & 0x7FFF) * 1.0;
                }
		    Canref = (Uint16)((pmsg->data8[6]) << 8 |  pmsg->data8[7]);//curmax
		    g_CANflash.CurMax = Canref * 0.01;
		    g_CANflash.flag |= _PORT_SET_BIT5;
		}
	    if(pmsg->data8[1] == 0x00){
			Canref = ABS(g_Control.SpdRef)*SPEED_PU_RE;
			if(g_Control.SpdRef >= 0){
				CANMsgSend.data8[4] = Canref & 0xFF;        // 低字节在前(小端序)
				CANMsgSend.data8[5] = (Canref >> 8) & 0xFF; // 高字节在后(小端序)
			}
			else{
				CANMsgSend.data8[4] = Canref & 0xFF;        // 低字节在前(小端序)
				CANMsgSend.data8[5] = ((Canref >> 8) & 0xFF) | 0x80; // 高字节在后+符号位(小端序)
			}
				
			Canref = pi_spd.Umax * 100 * CURRENT_PU_RE;
			CANMsgSend.data8[6] = Canref & 0xFF;        // 低字节在前(小端序)
			CANMsgSend.data8[7] = (Canref >> 8) & 0xFF; // 高字节在后(小端序)
			CANMsgSend.data8[0] = 0xB3;
			CANMsgSend.data8[1] = 00;
			CANMsgSend.len = 8;	
		}
		break;
		
	case 0xC1://pos kp
	    if(pmsg->data8[1] == 0x01){
			Canref = (Uint16)(pmsg->data8[2]) |  ((Uint16)(pmsg->data8[3]) << 8); // 小端序解析
			g_CANflash.pos.kp = Canref * 0.001;
			g_CANflash.flag |= _PORT_SET_BIT6;
	    }
	    if(pmsg->data8[1] == 0x00){
			Canref = (pi_pos.Kp)*1000;
			CANMsgSend.data8[2] = Canref & 0xFF;        // 低字节在前(小端序)
			CANMsgSend.data8[3] = (Canref >> 8) & 0xFF; // 高字节在后(小端序)
			CANMsgSend.data8[0] = 0xC1;
			CANMsgSend.data8[1] = 00;
			CANMsgSend.len = 8;	
	    }
	    break;
		
	case 0xC2://pos ki
	    if(pmsg->data8[1] == 0x01){
			Canref = (Uint16)(pmsg->data8[2]) |  ((Uint16)(pmsg->data8[3]) << 8); // 小端序解析
			g_CANflash.pos.ki = Canref * 0.0001;
			g_CANflash.flag |= _PORT_SET_BIT7;
	    }
	    if(pmsg->data8[1] == 0x00){
			Canref = (pi_pos.Ki)*10000;
			CANMsgSend.data8[2] = Canref & 0xFF;        // 低字节在前(小端序)
			CANMsgSend.data8[3] = (Canref >> 8) & 0xFF; // 高字节在后(小端序)
			CANMsgSend.data8[0] = 0xC2;
			CANMsgSend.data8[1] = 00;
			CANMsgSend.len = 8;	
	    }
	    break;
		
	case 0xC3://posref quan & speedmax & Curmax
	    if(pmsg->data8[1] == 0x01){//posref
			g_CANflash.posRef = (Uint16)(pmsg->data8[2]) |  ((Uint16)(pmsg->data8[3]) << 8); // 小端序解析
	        if((pmsg->data8[3] & 0x80) == 0x80){
                    g_CANflash.posRef_float = (g_CANflash.posRef & 0x7FFF) * -0.001;
            }
			else{
                    g_CANflash.posRef_float = (g_CANflash.posRef & 0x7FFF) * 0.001;
            }
		
	        Canref = (Uint16)((pmsg->data8[4]) << 8 |  pmsg->data8[5]);//spdmax
	        g_CANflash.SpeedMax = Canref * 1.0 ;
		
            Canref = (Uint16)((pmsg->data8[6]) << 8 |  pmsg->data8[7]);//curmax
	        g_CANflash.CurMax = Canref * 0.01 ;
	        g_CANflash.flag |= _PORT_SET_BIT8;
	    }
	    if(pmsg->data8[1] == 0x00){
			Canref = ABS(g_Control.PosRef)*1000*POSITION_PU_RE;//posref
			if(g_Control.PosRef >= 0){
				CANMsgSend.data8[2] = Canref & 0xFF;        // 低字节在前(小端序)
				CANMsgSend.data8[3] = (Canref >> 8) & 0xFF; // 高字节在后(小端序)
			}
			else{
				CANMsgSend.data8[2] = Canref & 0xFF;        // 低字节在前(小端序)
				CANMsgSend.data8[3] = ((Canref >> 8) & 0xFF) | 0x80; // 高字节在后+符号位(小端序)
			}
				
			Canref = pi_pos.Umax * SPEED_PU_RE;//spdmax
			CANMsgSend.data8[4] = Canref & 0xFF;        // 低字节在前(小端序)
			CANMsgSend.data8[5] = (Canref >> 8) & 0xFF; // 高字节在后(小端序)
			
			Canref = pi_spd.Umax * CURRENT_PU_RE;//curmax
			CANMsgSend.data8[6] = Canref & 0xFF;        // 低字节在前(小端序)
			CANMsgSend.data8[7] = (Canref >> 8) & 0xFF; // 高字节在后(小端序)
			CANMsgSend.data8[0] = 0xC3;
			CANMsgSend.data8[1] = 00;
			CANMsgSend.len = 8;	
		}
	    break;
		
	case 0xD1://weak kp
	    if(pmsg->data8[1] == 0x01){
			Canref = (Uint16)(pmsg->data8[2]) |  ((Uint16)(pmsg->data8[3]) << 8); // 小端序解析
			g_CANflash.weak.kp = Canref * 0.001;
			g_CANflash.flag |= _PORT_SET_BIT9;
	    }
		
	    if(pmsg->data8[1] == 0x00){
			Canref = (pi_fw.Kp)*1000;
			CANMsgSend.data8[2] = Canref & 0xFF;        // 低字节在前(小端序)
			CANMsgSend.data8[3] = (Canref >> 8) & 0xFF; // 高字节在后(小端序)
			CANMsgSend.data8[0] = 0xD1;
			CANMsgSend.data8[1] = 00;
			CANMsgSend.len = 8;	
	    }
	    break;
		
	case 0xD2://weak ki
	    if(pmsg->data8[1] == 0x01){
			Canref = (Uint16)(pmsg->data8[2]) |  ((Uint16)(pmsg->data8[3]) << 8); // 小端序解析
			g_CANflash.weak.ki = Canref * 0.0001;
			g_CANflash.flag |= _PORT_SET_BIT10;
	    }
		
	    if(pmsg->data8[1] == 0x00){
			Canref = (pi_fw.Ki)*10000;
			CANMsgSend.data8[2] = Canref & 0xFF;        // 低字节在前(小端序)
			CANMsgSend.data8[3] = (Canref >> 8) & 0xFF; // 高字节在后(小端序)
			CANMsgSend.data8[0] = 0xD2;
			CANMsgSend.data8[1] = 00;
			CANMsgSend.len = 8;	
	    }
	    break;
		
	case 0xD3://weak Curmax 
		if(pmsg->data8[1] == 0x01){
			Canref = (Uint16)(pmsg->data8[2]) |  ((Uint16)(pmsg->data8[3]) << 8); // 小端序解析
			g_CANflash.fwCurMax = Canref * 0.01;
			g_CANflash.flag |= _PORT_SET_BIT11;
		}

		if(pmsg->data8[1] == 0x00){
		    Canref = (pi_fw.Umin)*100*CURRENT_PU_RE;
		    CANMsgSend.data8[2] = Canref & 0xFF;        // 低字节在前(小端序)
			CANMsgSend.data8[3] = (Canref >> 8) & 0xFF; // 高字节在后(小端序)
			CANMsgSend.data8[0] = 0xD3;
			CANMsgSend.data8[1] = 00;
			CANMsgSend.len = 8;	
		}
	    break;
		  
	case 0x01:   //overVoltage
	    if(pmsg->data8[1] == 0x01){
			g_CANflash.flag |= _PORT_SET_BIT12;
			g_CANflash.Ov = (Uint16)(pmsg->data8[2]) |  ((Uint16)(pmsg->data8[3]) << 8); // 小端序解析
	    }
		
	    if(pmsg->data8[1] == 0x00){
			Canref = g_Control.prot.VoltLevel1* 10;

			CANMsgSend.data8[2] = Canref & 0xFF;        // 低字节在前(小端序)
			CANMsgSend.data8[3] = (Canref >> 8) & 0xFF; // 高字节在后(小端序)
			CANMsgSend.data8[0] = 0x01;
			CANMsgSend.data8[1] = 00;
			CANMsgSend.len = 8;	
	    }
	break;
		
	case 0x02:  //overCurrent
	    if(pmsg->data8[1] == 0x01){
			g_CANflash.flag |= _PORT_SET_BIT13;
			g_CANflash.Oi = (Uint16)(pmsg->data8[2]) |  ((Uint16)(pmsg->data8[3]) << 8); // 小端序解析
	    }
		
	    if(pmsg->data8[1] == 0x00){
			Canref = g_Control.prot.CurLevel1*10;
			CANMsgSend.data8[2] = Canref & 0xFF;        // 低字节在前(小端序)
			CANMsgSend.data8[3] = (Canref >> 8) & 0xFF; // 高字节在后(小端序)
			CANMsgSend.data8[0] = 0x02;
			CANMsgSend.data8[1] = 00;
			CANMsgSend.len = 8;	
	    }	
		break;
		
	
		//default:
	    //CANMsgSend.data8[0] = 0xFF;
        //CANMsgSend.data8[1] = 0xFF;
		
    }
	can_send(&CANMsgSend,Unit1_u08);
	break;
	
    case 0x03://send fbk 
    	if(pmsg->data8[0] == 0x01){
    	    sendcode = pmsg->data8[1];
	    Flag_Cansend = 1;
		}
	
		if(pmsg->data8[0] == 0x00)
			Flag_Cansend = 0;

			CANMsgSend.data8[0] = 0x12;
			CANMsgSend.data8[1] = 0x34; 
			CANMsgSend.len = 2;
			CANMsgSend.id = 0x222;
		can_send(&CANMsgSend,Unit1_u08);
		break;
    
    case 0x04://send errorcode 
    	error_a = error_state_code_0101;
        CANMsgSend.data8[0] = (error_a) & 0xFF;        // 最低字节 (小端序)
        CANMsgSend.data8[1] = (error_a >> 8) & 0xFF;   // 次低字节
		CANMsgSend.data8[2] = (error_a >> 16) & 0xFF;  // 次高字节
        CANMsgSend.data8[3] = (error_a >> 24) & 0xFF;  // 最高字节
		CANMsgSend.data8[4] = 0x00;  // 保留字节
		CANMsgSend.data8[5] = 0x00;  // 保留字节
		CANMsgSend.data8[6] = 0x00;  // 保留字节
		CANMsgSend.data8[7] = 0x00;  // 保留字节
	
        CANMsgSend.len = 8;
        CANMsgSend.id = 0x280;
		can_send(&CANMsgSend,Unit1_u08);
		break;

    case 0x05://send version info (新增独立版本信息帧)
        CANMsgSend.data8[0] = (VERSION >> 16) & 0xFF;     // 主版本号
        CANMsgSend.data8[1] = (VERSION >> 8) & 0xFF;      // 次版本号
        CANMsgSend.data8[2] = VERSION & 0xFF;             // 修订版本号
        CANMsgSend.data8[3] = 0x00;                       // 保留字节
        CANMsgSend.data8[4] = (BUILD_DATE >> 16) & 0xFF;  // 年份(YY)
        CANMsgSend.data8[5] = (BUILD_DATE >> 8) & 0xFF;   // 月份(MM)
        CANMsgSend.data8[6] = BUILD_DATE & 0xFF;          // 日期(DD)
        CANMsgSend.data8[7] = 0x00;                       // 保留字节
        
        CANMsgSend.len = 8;
        CANMsgSend.id = 0x2A0;  
        can_send(&CANMsgSend,Unit1_u08);
        break;
	
    case 0x0D://YC Vehspd   
        vehspd = pmsg->data8[3]  & 0xFE;	
		vehspd |= (pmsg->data8[2] << 8);
		g_CANflash.vehspd = (vehspd >> 1) * 0.05625;
		break;	
	
    case 0x0F://start/ stop 
		if(pmsg->data8[0] == 0x00){		//aligment
    	    g_CANflash.runState = 1;
			g_CANflash.statusSym = 0;
			CANMsgSend.data8[0] = 0x00;
	    
		}
	
		if(pmsg->data8[0] == 0x01){		//open loop
    	    g_CANflash.runState = 1;
	    	g_CANflash.statusSym = -1;
            CANMsgSend.data8[0] = 0x01;
	    
		}

		if(pmsg->data8[0] == 0x08){		//personal mode #1
    	    //g_CANflash.runState = 1;
	    	//g_CANflash.statusSym = -1;
            CANMsgSend.data8[0] = 0x08;
	    
		}

		if(pmsg->data8[0] == 0x09){		//personal mode #2
    	    g_CANflash.runState = 1;
	    	g_CANflash.statusSym = -1;
            CANMsgSend.data8[0] = 0x09;
	    
		}
	
		if(pmsg->data8[0] == 0x0A){		//current loop
    	    g_CANflash.runState = 1;
	    	g_CANflash.statusSym = 1;
            CANMsgSend.data8[0] = 0x0A;
	    
		}
	
		if(pmsg->data8[0] == 0x0B){//spd loop
    	    g_CANflash.runState = 1;
	    	g_CANflash.statusSym = 2;
            CANMsgSend.data8[0] = 0x0B;
	    
		}
	
		if(pmsg->data8[0] == 0x0C){//pos loop
    	    g_CANflash.runState = 1;
	   	 	g_CANflash.statusSym = 3;
            CANMsgSend.data8[0] = 0x0C;
	    
		}
	
		if(pmsg->data8[0] == 0x0D){//JWD loop
    	    
	   
	    	g_CANflash.runState = 1;
	    	g_CANflash.statusSym = 5;
            CANMsgSend.data8[0] = 0x0D;
	    
		}
	
		if(pmsg->data8[0] == 0x0F){//stop
    	    g_CANflash.runState = 9;
	    sleepflag = 1;
	    	g_CANflash.statusSym = pmsg->data8[0];
            CANMsgSend.data8[0] = 0x0F;
	    
		}
	
        CANMsgSend.len = 1;
        CANMsgSend.id = 0x3E0;
		can_send(&CANMsgSend,Unit1_u08);
		break;	
	
    	default:
        break;

    }
}



void can_send(const CAN_MSG *pCANMsg,u08 Unit1_u08)
{
       // Sending Message Set Up //
       
    struct ee_mttcan_tx          SendMessage;
    u08 SendStatus_u08;
    u32 TimeoutLimit_u32 = 100000L;
    u08 DataCounter_u08;
    bit MTTCAN_Status_bit   = MTTCAN_OK;
    //u08 Unit1_u08 = 0;

    SendMessage.t0.id      = pCANMsg->id;
    SendMessage.t1.efc     = MTTCAN_CLEAR;            // No entry in THL 
    SendMessage.t0.rtr     = 0;                     // Data Frame 
    SendMessage.t0.xtd     = 0;                     // Standard Frame 
        SendMessage.t0.esi     = 0;                     // ESI reflects own status 
        SendMessage.t1.mm      = 0x23;                  // HTH value 
        SendMessage.t1.dlc     = pCANMsg->len;
        SendMessage.t1.fdf     = 0;                     // classical message 
        SendMessage.t1.brs     = 0;
        SendMessage.path       = MTTCAN_PATH_MSGBOX;      // Send via Message Box 
        SendMessage.pathdetail = MTTCAN_PATHDETAIL_ANY;   // use any box... 
        SendMessage.irq_enable = MTTCAN_SET;              // Cause interrupt 
  
  for( DataCounter_u08 = 0;
       DataCounter_u08 < SendMessage.t1.dlc;
       DataCounter_u08++ )
  {
    SendMessage.d.b[ DataCounter_u08 ] = pCANMsg->data8[ DataCounter_u08 ];
  }

  do
  {
    MTTCAN_Status_bit &= MTTCAN_SendMessage( Unit1_u08,
                                         &SendStatus_u08,
                                         &SendMessage );
   // if( MTTCAN_Status_bit == MTTCAN_ERROR ) return( MTTCAN_ERROR );
    
  } while( ( SendStatus_u08 == MTTCAN_FAULT_BUSY ) &&
           ( --TimeoutLimit_u32 > 0 ) );
	   flag_hyxx=1;
}

void flash()
{
	u16 NodeID_FlashRead;//′óflash?áè?μ??úμ?o?

	memset(&g_CANObject,0,sizeof(Object_t));

		

	NodeID_FlashRead = *((Uint16 *) 0x3EA000);
	
	if(0xFFFF == NodeID_FlashRead)
	{
	    g_CANObject.m_Obj_0x00A0.NodeID = g_Initial.Nodeid;//??è??úμ?o??a1
	}else if((NodeID_FlashRead >= 1)&&(NodeID_FlashRead <= 14))
	{
	    g_CANObject.m_Obj_0x00A0.NodeID = NodeID_FlashRead;
	}else{
	    g_CANObject.m_Obj_0x00A0.NodeID = 15;//1ê??×′ì?μ??úμ?o?
	}

}




void ExternSend(u08 Unit1_u08)
{
	// 外部变量声明 - 必须在函数开头
	extern PI_CONTROLLER pi_iq, pi_id, pi_spd, pi_pos;
	extern unsigned short High_temperature;

	// CAN发送状态机 - 每次只发送一帧
	// cantime每50us递增1，所以0.5ms = 10个cantime单位，2ms = 20个cantime单位
	// 10ms = 200个cantime单位，20ms = 400个cantime单位
	
	// 检查是否允许发送
	if(Flag_Cansend != 1 ) {
		return;  // 不满足发送条件，直接返回
	}
	
	// 防止cantime溢出，每到一定值时重置相关时间变量
	if(cantime > 30000) {  // 约1.5秒后重置，避免溢出
		cantime = 0;
		last_2ms_time = 0;
		last_10ms_time = 0;
		last_20ms_time = 0;
		// 重置发送标志
		speed_sent = 0;
		current3_sent = 0;
		voltage_sent = 0;
		position_sent = 0;
		temperature_sent = 0;
	}
	
	// 检查10ms周期是否到达，重置10ms数据发送标志
	if((cantime - last_10ms_time) >= 200) {
		speed_sent = 0;      // 重置速度发送标志
		current3_sent = 0;   // 重置三相电流发送标志
		last_10ms_time = cantime;
	}
	
	// 检查20ms周期是否到达，重置20ms数据发送标志
	if((cantime - last_20ms_time) >= 400) {
		voltage_sent = 0;     // 重置电压发送标志
		position_sent = 0;    // 重置位置发送标志
		temperature_sent = 0; // 重置温度发送标志
		last_20ms_time = cantime;
	}
	
	// 状态机逻辑：按序发送不同类型数据帧，同频率数据分散在周期内发送
	switch(send_state) {
	case 0: // 发送电流数据 (2ms频率，每2ms发送)
		if((cantime - last_2ms_time) >= 40) {  // 每2ms发送一次(40个cantime单位)
			// 变量声明必须在代码块开头
			int16 iq_ref_raw, iq_fbk_raw, id_ref_raw, id_fbk_raw;
			
			// 电流数据按照DBC定义：小端序，有符号16位，分辨率0.01
			// DBC边界检查：电流范围[-327.67|327.67]A，防止数据溢出
			float iq_ref_val = pi_iq.Ref * 100 * CURRENT_PU_RE;
			float iq_fbk_val = pi_iq.Fbk * 100 * CURRENT_PU_RE;
			float id_ref_val = pi_id.Ref * 100 * CURRENT_PU_RE;
			float id_fbk_val = pi_id.Fbk * 100 * CURRENT_PU_RE;
			
			// 边界限制以防止溢出
			if(iq_ref_val > 32767) iq_ref_val = 32767;
			if(iq_ref_val < -32768) iq_ref_val = -32768;
			if(iq_fbk_val > 32767) iq_fbk_val = 32767;
			if(iq_fbk_val < -32768) iq_fbk_val = -32768;
			if(id_ref_val > 32767) id_ref_val = 32767;
			if(id_ref_val < -32768) id_ref_val = -32768;
			if(id_fbk_val > 32767) id_fbk_val = 32767;
			if(id_fbk_val < -32768) id_fbk_val = -32768;
			
			iq_ref_raw = (int16)iq_ref_val;
			iq_fbk_raw = (int16)iq_fbk_val;
			id_ref_raw = (int16)id_ref_val;
			id_fbk_raw = (int16)id_fbk_val;
			
			// 使用标准DBC兼容的小端序打包
			pack_int16_le(exmsg.data, 0, iq_ref_raw);  // Iq_Set
			pack_int16_le(exmsg.data, 2, iq_fbk_raw);  // Iq_Fb
			pack_int16_le(exmsg.data, 4, id_ref_raw);  // Id_Set
			pack_int16_le(exmsg.data, 6, id_fbk_raw);  // Id_Fb
			
			exmsg.len = 8;
			exmsg.id = 0x340;
			
			Exsend(&exmsg, Unit1_u08);
			last_2ms_time = cantime;   // 记录2ms数据发送时间
		}
		
		// 下个状态：转速
		send_state = 1;
		break;
		
	case 1: // 发送转速数据 (10ms频率，在10ms周期开始时发送)
		if(speed_sent == 0 && (cantime - last_10ms_time) >= 0) {  // 10ms周期开始就可以发送
			// 变量声明必须在代码块开头
			int32 spd_ref_raw, spd_fbk_raw;
			
			// 转速数据按照DBC定义：小端序，有符号32位，分辨率0.1
			spd_ref_raw = (int32)(g_Control.SpdRef * 10 * SPEED_PU_RE);
			spd_fbk_raw = (int32)(g_Control.SpdFbk * 10 * SPEED_PU_RE);
			
			// 使用标准DBC兼容的小端序打包
			pack_int32_le(exmsg.data, 0, spd_ref_raw);  // Speed_Set
			pack_int32_le(exmsg.data, 4, spd_fbk_raw);  // Speed_Fb
			
			exmsg.len = 8;
			exmsg.id = 0x360;
			
			Exsend(&exmsg, Unit1_u08);
			speed_sent = 1;  // 标记速度已发送
		}
		
		// 下个状态：三相电流
		send_state = 2;
		break;
		
	case 2: // 发送三相电流数据 (10ms频率，在10ms周期中间发送，约5ms偏移)
		if(current3_sent == 0 && (cantime - last_10ms_time) >= 100) {  // 5ms偏移(100个cantime单位)
			// 变量声明必须在代码块开头
			int16 ia_raw, ib_raw, ic_raw, imax_raw;
			
			// 三相电流数据按照DBC定义：小端序，有符号16位，分辨率0.01A
			ia_raw = (int16)(g_Control.m_Current.cur_A * 100);  // A相电流
			ib_raw = (int16)(g_Control.m_Current.cur_B * 100);  // B相电流
			ic_raw = (int16)(g_Control.m_Current.cur_C * 100);  // C相电流
			imax_raw = (int16)(g_Control.r_Current.I_Max * 100); // 最大电流
			
			// 使用标准DBC兼容的小端序打包
			pack_int16_le(exmsg.data, 0, ia_raw);    // A相电流
			pack_int16_le(exmsg.data, 2, ib_raw);    // B相电流  
			pack_int16_le(exmsg.data, 4, ic_raw);    // C相电流
			pack_int16_le(exmsg.data, 6, imax_raw);  // 最大电流
			
			exmsg.len = 8;
			exmsg.id = 0x3C0;
			
			Exsend(&exmsg, Unit1_u08);
			current3_sent = 1;  // 标记三相电流已发送
		}
		
		// 下个状态：母线电压
		send_state = 3;
		break;
		
	case 3: // 发送母线电压数据 (20ms频率，在20ms周期开始时发送)
		if(voltage_sent == 0 && (cantime - last_20ms_time) >= 0) {  // 20ms周期开始就可以发送
			// 变量声明必须在代码块开头
			int16 vdc_raw, vdc_max_raw, vdc_min_raw, vdc_board_raw;
			
			// 母线电压数据按照DBC定义：小端序，有符号16位，分辨率0.1V
			vdc_raw = (int16)(g_Control.Vdc * 10);           // 主母线电压
			vdc_max_raw = (int16)(g_Control.Vdcmax * 10);    // 最大电压
			vdc_min_raw = (int16)(g_Control.Vdcmin * 10);    // 最小电压  
			vdc_board_raw = (int16)(g_Control.ControlBoardPowerDC * 10); // 控制板电压
			
			// 使用标准DBC兼容的小端序打包
			pack_int16_le(exmsg.data, 0, vdc_raw);         // 主母线电压
			pack_int16_le(exmsg.data, 2, vdc_max_raw);     // 最大电压
			pack_int16_le(exmsg.data, 4, vdc_min_raw);     // 最小电压
			pack_int16_le(exmsg.data, 6, vdc_board_raw);   // 控制板电压
			
			exmsg.len = 8;
			exmsg.id = 0x3A0;
			
			Exsend(&exmsg, Unit1_u08);
			voltage_sent = 1;  // 标记电压已发送
		}
		
		// 下个状态：位置
		send_state = 4;
		break;
		
	case 4:		// 发送位置反馈数据 (20ms频率，约7ms偏移)
		if(position_sent == 0 && (cantime - last_20ms_time) >= 140) {  // 7ms偏移(140个cantime单位)
			// 变量声明必须在代码块开头
			int32 pos_ref_raw, pos_fbk_raw;
			
			// 位置数据按照DBC定义：小端序，有符号32位，分辨率0.1rad
			// 使用标幺化缩放因子进行单位转换：
			// PosRef需要考虑系统设定值的标幺化
			// PosSum需要考虑编码器反馈的标幺化和机械传动比
			pos_ref_raw = (int32)(g_Control.PosRef * 10 / 2.2917);       // 设定值标幺缩放
			pos_fbk_raw = (int32)(g_Control.pos.PosSum * 10 / 0.28798);  // 反馈值标幺缩放
			
			// 使用标准DBC兼容的小端序打包
			pack_int32_le(exmsg.data, 0, pos_ref_raw);  // Pos_Set
			pack_int32_le(exmsg.data, 4, pos_fbk_raw);  // Pos_Fb
			
			exmsg.len = 8;
			exmsg.id = 0x380;
			
			Exsend(&exmsg, Unit1_u08);
			position_sent = 1;  // 标记位置已发送
		}
		
		// 下个状态：温度
		send_state = 5;
		break;
		
	case 5: // 发送温度反馈数据 (20ms频率，约14ms偏移)
		if(temperature_sent == 0 && (cantime - last_20ms_time) >= 280) {  // 14ms偏移(280个cantime单位)
			// 变量声明必须在代码块开头
			int16 temp_raw, temp_status;
			
			// 温度数据按照DBC定义：小端序，有符号16位，分辨率0.1℃
			temp_raw = (int16)(temperature * 10);           // 系统温度
			temp_status = 0;                                // 温度状态
			
			// 温度状态位定义:
			// bit0: 高温报警 (>=95℃)
			// bit1: 温度传感器故障
			// bit2-15: 保留
			if(High_temperature == 1) {
			    temp_status |= 0x01;  // 设置高温报警位
			}
			
			// 使用标准DBC兼容的小端序打包
			pack_int16_le(exmsg.data, 0, temp_raw);      // 温度值
			pack_int16_le(exmsg.data, 2, temp_status);   // 温度状态
			exmsg.data[4] = 0;  // 保留字节
			exmsg.data[5] = 0;  // 保留字节
			exmsg.data[6] = 0;  // 保留字节
			exmsg.data[7] = 0;  // 保留字节
			
			exmsg.len = 8;
			exmsg.id = 0x3F0;
			
			Exsend(&exmsg, Unit1_u08);
			temperature_sent = 1;  // 标记温度已发送
		}
		
		// 回到初始状态：电流数据
		send_state = 0;
		break;
		
	default:
		// 异常情况，重置状态机
		send_state = 0;
		break;
	}
	
	// 保留原有的CAN闪烁处理逻辑
	if(g_CANflash.flag & 0x8000){
		g_CANflash.flag &= 0x7FFFU;
		exmsg.data[0] = 0xAA;
        	
		exmsg.len = 1;
        	exmsg.id = 0x220;
		
		Exsend(&exmsg, Unit1_u08);
	}
}