#include <ree_types.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>

//#define  DRIVER_LOCAL
#define  APPLICATION_INTERFACE

#include <mttcan.h>

//#include "mttcan_p.h"
//#include "mttcan_s.h"
#include "OBDII_APP_IO.h"
#include <OBDII_Diag_CallBack.h>
#include <OBDII_Diag_Snapshot.h>
#include <can_command.h>

void can_send(const CAN_MSG *pCANMsg);
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
CAN_Info g_Can_Atrib; 

volatile Uint16 SlaveNodeID3[40];
Uint16 SlaveNodeID4[40];

extern RecCan_valSeverDataNew Rec_Diag_Physical1;
extern RecCan_valSeverDataNew  Rec_Diag_Function1;
extern ubyte CANRecForbid_st;
//extern Uint32 error_state_code_0101;//错误标志位

//extern CAN_Info g_Can_Atrib; 
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

//=============================================================================
// FunctionName: MTTCAN_Reset
// IN  :         Unit Number
// OUT :         Success Status
// Description : Resets M_CAN unit and releases Port
// 
//=============================================================================

void can_command_process(CAN_MSG *pmsg)
{
    Uint16 NodeID;//节点号
    Uint16 CmdCode;//命令码
    Uint16 MasterSlaveFlag;//主从标识
    CAN_MSG CANMsgSend;
    Uint16 OperCode;
    Uint16 ObjID;
    Uint16 AttriID;
	unsigned char Rec_CANnumCount = 0;

    memset(&CANMsgSend,0,sizeof(CAN_MSG));  // for what?
    NodeID = (Uint16)(pmsg->id & 0x0F);//节点ID
    CmdCode = (Uint16)((pmsg->id >> 5) & 0x001F);
    MasterSlaveFlag = (Uint16)((pmsg->id)& 0x410);//0100 0001 0000

	if(pmsg->id  == 0x7E3)
	{
		Rec_Diag_Physical1.CanBus_flgRecActive =1;
		for(Rec_CANnumCount = 0;Rec_CANnumCount<8;Rec_CANnumCount++)
		{
			Rec_Diag_Physical1.CanBus_valRecCanData8.b[Rec_CANnumCount] = pmsg->data8[Rec_CANnumCount];
		}
		Rec_Diag_Physical1.CanBus_valDataLength =8;
	}
	
	if(pmsg->id  == 0x7DF)
	{
		
		Rec_Diag_Function1.CanBus_flgRecActive =1;
		for(Rec_CANnumCount = 0;Rec_CANnumCount<8;Rec_CANnumCount++)
		{
			Rec_Diag_Function1.CanBus_valRecCanData8.b[Rec_CANnumCount] = pmsg->data8[Rec_CANnumCount];
		}
		Rec_Diag_Function1.CanBus_valDataLength =8;
	}
	
    if(MasterSlaveFlag != 0x00)//非主机发送
    {
        return ;
    }

    //if((NodeID != 0)&&//不是发送给所有节点
    //   (NodeID != g_CANObject.m_Obj_0x00A0.NodeID))//不是发送给本机
   // {
    //    return ;
   // }

    g_Can_Atrib.onlineFlag = 1;
    g_Can_Atrib.offline_timeCount = 0;

/* 正常模式和故障模式下均需要响应的命令 */
    switch(CmdCode)
    {
    case 0x11://节点检测命令
        CANMsgSend.data8[0] = 0x20;
        CANMsgSend.data8[1] = 0x24;
        CANMsgSend.data8[2] = 0x03;
        CANMsgSend.data8[3] = 0x26;//出厂日期：2024.3.26
        CANMsgSend.data8[4] = 0x00;
        CANMsgSend.data8[5] = 0x01;//设备类型0001
        CANMsgSend.data8[6] = 0x00;
        CANMsgSend.data8[7] = 0x01;//出厂编号0001
        CANMsgSend.len = 8;

        CANMsgSend.id = hCAN_Pack(g_CANObject.m_Obj_0x00A0.NodeID, 0x11);
        
	can_send(&CANMsgSend);
        
	break;
    case 0x15://节点状态命令
        if(pmsg->data8[0]==0x00)//网络管理命令码，00代表获取节点当前状态
        {
            CANMsgSend.data8[0] = 0x00;
            CANMsgSend.data8[1] = (Uint16)( g_Can_Atrib.statusSym & 0XFF);
            CANMsgSend.len = 2;

            CANMsgSend.id = hCAN_Pack(g_CANObject.m_Obj_0x00A0.NodeID, 0x15);
            can_send(&CANMsgSend);
        }else if(pmsg->data8[0]==0x05)//网络管理命令码，05代表更改节点当前状态
        {
            CANMsgSend.data8[0] = 0x05;
            switch(pmsg->data8[1])
            {
            case 0x01://初始定位
                g_Can_Atrib.statusSym = pmsg->data8[1];
                CANMsgSend.data8[1] = (Uint16)( g_Can_Atrib.statusSym & 0XFF);break;
            case 0x0A://电流环
                g_Can_Atrib.statusSym = pmsg->data8[1];
                CANMsgSend.data8[1] = (Uint16)( g_Can_Atrib.statusSym & 0XFF);break;
            case 0x0B://转速环
                g_Can_Atrib.statusSym = pmsg->data8[1];
                CANMsgSend.data8[1] = (Uint16)( g_Can_Atrib.statusSym & 0XFF);break;
            case 0x99://程序更新
                g_Can_Atrib.statusSym = pmsg->data8[1];
                CANMsgSend.data8[1] = (Uint16)( g_Can_Atrib.statusSym & 0XFF);break;
            default://无效命令码
                CANMsgSend.data8[1] = 0XFF;break;
            }
            g_CANObject.m_Obj_0x00A0.NodeStatus = g_Can_Atrib.statusSym;
            CANMsgSend.len = 2;
            CANMsgSend.id = hCAN_Pack(g_CANObject.m_Obj_0x00A0.NodeID, 0x15);
            can_send(&CANMsgSend);
        }else{//无效命令码
            CANMsgSend.data8[0] = 0xFF;
            CANMsgSend.len = 1;

            CANMsgSend.id = hCAN_Pack(g_CANObject.m_Obj_0x00A0.NodeID, 0x15);
            can_send(&CANMsgSend);
        }
        break;
    default:
        break;
    }

    if(0xFF == g_CANObject.m_Obj_0x00A0.NodeID)//本机为故障模式
    {
        return ;
    }

    /* 仅正常模式下响应的命令 */
    switch(CmdCode)
    {
    case 0x18://阀门控制命令
        if(pmsg->data8[0] == 0x0A || pmsg->data8[0] == 0x0B)
        {
            if(pmsg->data8[1] == 0x01)
            {
//                g_Control.iRunState = 0;
                g_Can_Atrib.runState = pmsg->data8[1];
                g_Can_Atrib.runTime = 0;
            }else if(pmsg->data8[1] == 0x02)
            {
//                g_Constrol.iRunState = 0;
                g_Can_Atrib.runState = pmsg->data8[1];
                g_Can_Atrib.runTime = pmsg->data8[2];
            }else if(pmsg->data8[1] == 0x09)
            {
//                g_Control.iRunState = 404;
                g_Can_Atrib.runState = pmsg->data8[1];
                g_Can_Atrib.runTime = 0;
            }else{
                g_Can_Atrib.runState = 0xFF;
                g_Can_Atrib.runTime = 0;
            }

            if(g_Can_Atrib.statusSym == 0x0A && g_Can_Atrib.statusSym == pmsg->data8[0])
            {
                g_Can_Atrib.dRef = pmsg->data8[3] << 4 | pmsg->data8[4] >> 4;
                g_Can_Atrib.qRef = (pmsg->data8[4] & 0x0F) << 8 | pmsg->data8[5];
                g_Can_Atrib.dRef_float = g_Can_Atrib.dRef * (-0.1);
                g_Can_Atrib.qRef_float = g_Can_Atrib.qRef * (0.1);
            }else if(g_Can_Atrib.statusSym == 0x0B && g_Can_Atrib.statusSym == pmsg->data8[0])
            {
                g_Can_Atrib.spdRef = ((((Uint32)pmsg->data8[3] << 8) | pmsg->data8[4])<<8 | pmsg->data8[5]);
                if((pmsg->data8[3] & 0xF0) == 0x10){
                    g_Can_Atrib.spdRef_float = (g_Can_Atrib.spdRef & 0x0FFFFF) * -0.01;
                }else{
                    g_Can_Atrib.spdRef_float = (g_Can_Atrib.spdRef & 0x0FFFFF) * 0.01;
                }
            }else{
                g_Can_Atrib.runState = 0xF1;
            }

        }

//        if(0x55 == pmsg->data8[2])//正转
//        {
//            g_Can_Atrib.CyclesNum = pmsg->data8[1] + (pmsg->data8[0] * 0.01);
//        }else if(0xAA == pmsg->data8[2])//反转
//        {
//            g_Can_Atrib.CyclesNum = -(pmsg->data8[1] + (pmsg->data8[0] * 0.01));
//        }
//        g_Can_Atrib.CyclesNum *= 0.1;
//        g_CANObject.m_Obj_0x00A0.NodeStatus = pmsg->data8[3] & 0x00FF;
//        g_CANObject.m_Obj_0x00B0.HostStatus = g_CANObject.m_Obj_0x00A0.NodeStatus;
//        g_CANObject.m_Obj_0x00B0.HostSwitchCmd = pmsg->data8[3] & 0x00FF;

        CANPack_ValveStatus(&CANMsgSend);
        can_send(&CANMsgSend);//发送
        break;
    case 0x1A://状态查询命令
        if(0x01 == pmsg->data8[0])
        {
            CANPack_ValveStatus(&CANMsgSend);
            can_send(&CANMsgSend);//发送
        }
        break;
    case 0x001C://对象属性操作命令
        OperCode = pmsg->data8[0];
        ObjID = 0;
        ObjID |= (pmsg->data8[1]);
        ObjID <<= 8;
        ObjID |= (pmsg->data8[2]);
        AttriID = pmsg->data8[3];

        switch(OperCode)
        {
        case 0x10://读
            Obj_Read(ObjID, AttriID, &CANMsgSend);
            can_send(&CANMsgSend);//发送
            break;
        case 0x21://写
        case 0x22:
        case 0x23:
        case 0x24:
            Obj_Write(ObjID,AttriID,&pmsg->data8[4],OperCode-0x20,&CANMsgSend);
            can_send(&CANMsgSend);//发送
            break;
        default:
            break;
        }
        break;

        /*case 0x1D://FlashProg命令-发送指令
            if((pmsg->data8[0] == 0xAA) && (pmsg->data8[1] == 0xFF))// AA FF
            {
                APPBOOT_Select=0;
                erase_flag=0;//全部烧写
            }else if((pmsg->data8[0] == 0x01) && (pmsg->data8[1] == 0xFF)){
                APPBOOT_Select=0;
                erase_flag=1;//部分烧写
            }else if((pmsg->data8[0] == 0xDD) && (pmsg->data8[1] == 0xFF)){
                BOOT_Status2_flag = 2;//数据传输结束

            }else if((pmsg->data8[0] == 0xBB) && (pmsg->data8[1] == 0xFF)){

                Prog_Start_Addr[AddrDat_Ptr] = (Uint32)(pmsg->data8[2]);//更改数据为2 3 4 5 6
                Prog_Start_Addr[AddrDat_Ptr] = (Uint32)(((Prog_Start_Addr[AddrDat_Ptr])<<8) | pmsg->data8[3]);
                Prog_Start_Addr[AddrDat_Ptr] = (Uint32)(((Prog_Start_Addr[AddrDat_Ptr])<<8) | pmsg->data8[4]);

                Dat_CNT[AddrDat_Ptr+1] = pmsg->data8[5];
                Dat_CNT[AddrDat_Ptr+1] = (Uint16)(((Dat_CNT[AddrDat_Ptr+1])<<8) | pmsg->data8[6]);

                //                    for(i_cnt = 1; i_cnt < Array_Size+1; i_cnt++)
                //                    {
                //                        if(i_cnt == 1)
                //                        {
                //                            Dat_CNT[0] = Dat_CNT[i_cnt];
                //                        }else{
                //                            Dat_CNT[0] += Dat_CNT[i_cnt];
                //                        }
                //                    }
                Dat_CNT[0] = Dat_CNT[1]+Dat_CNT[2]+Dat_CNT[3]+Dat_CNT[4]+Dat_CNT[5];

                AddrDat_Ptr++;
                //                    CANPack_ValveStatus(&CANMsgSend);
                //                    can_send(&CANMsgSend);

            }

            CANMsgSend.data8[0] = pmsg->data8[1];
            CANMsgSend.len = 1;
            CANMsgSend.id = hCAN_Pack(g_CANObject.m_Obj_0x00A0.NodeID, 0x1D);
            can_send(&CANMsgSend);

            break;
        case 0x1E://FlashProg命令-发送数据
            if(BOOT_Status == 1)
            {
                if(Dat_CNT[0] > 0)
                {
                    if(TextFull_Flag % 2 == 0)
                    {
                        for(ptr=0 ; ptr<8 ; ptr++ , text_Ptr++)
                        {
                            text1[text_Ptr] = pmsg->data8[ptr++];
                            text1[text_Ptr] = ((text1[text_Ptr])<<8) | pmsg->data8[ptr];
                        }
                        if(text_Ptr == Prog_Word_Len)
                        {
                            text_Ptr = 0;
                            TextFull_Flag++;
                        }
                    }else if(TextFull_Flag % 2 == 1)
                    {
                        for(ptr=0 ; ptr<8 ; ptr++ , text_Ptr++)
                        {
                            text2[text_Ptr] = pmsg->data8[ptr++];
                            text2[text_Ptr] = ((text2[text_Ptr])<<8) | pmsg->data8[ptr];
                        }
                        if(text_Ptr == Prog_Word_Len)
                        {
                            text_Ptr = 0;
                            TextFull_Flag++;
                        }
                    }
                    RXDAT_Count+=4;//字节计数

                }
            }
            break;

        default:
            break;*/
    }

}

Uint32 hCAN_Pack(Uint16 NodeID,Uint16 CmdCode)
{
    Uint32 CANID;
    Uint32 Temp;

    CANID = 0;
    Temp = NodeID;
    Temp &= 0x0F;
    CANID |= Temp;

    Temp = CmdCode;
    Temp &= 0x1F;
    Temp <<= 5;
    CANID |= Temp;

    return (CANID);
}

void can_send(const CAN_MSG *pCANMsg)
{
       // Sending Message Set Up //
       
         struct ee_mttcan_tx          SendMessage;
	 u08 SendStatus_u08;
	 u32 TimeoutLimit_u32 = 100000L;
	 u08 DataCounter_u08;
	 bit MTTCAN_Status_bit   = MTTCAN_OK;
	 u08 Unit1_u08 = 0;

  
  SendMessage.t0.id      = pCANMsg->id;
  SendMessage.t1.efc     = MTTCAN_CLEAR;            // No entry in THL 
  SendMessage.t0.rtr     = pCANMsg->type;                     // Data Frame 
  SendMessage.t0.xtd     = pCANMsg->format;                     // Standard Frame 
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

void Obj_Read(Uint16 ObjID,Uint16 AttriID,CAN_MSG *pCANMsg)
{
    memset(pCANMsg,0,sizeof(CAN_MSG));
    pCANMsg->id = hCAN_Pack(g_CANObject.m_Obj_0x00A0.NodeID, 0x1C);
    pCANMsg->data8[1] = (Uint16)((ObjID>>8) & 0x00FF);
    pCANMsg->data8[2] = (Uint16)(ObjID & 0x00FF);
    pCANMsg->data8[3] = AttriID;
    pCANMsg->len = 8;

    g_CANObject.m_Obj_0x00A0.NodeStatus = g_Can_Atrib.statusSym;
    g_CANObject.m_Obj_0x00A0.ErrorReg = 0;
    if(0x00A0 == ObjID)
    {
        switch(AttriID)
        {
        case 0x01://节点ID
            ObjAttri_Read(ObjID,AttriID,(char*)&g_CANObject.m_Obj_0x00A0.NodeID,1,pCANMsg);
            break;
        case 0x02://节点状态
            ObjAttri_Read(ObjID,AttriID,(char*)&g_CANObject.m_Obj_0x00A0.NodeStatus,1,pCANMsg);
            break;
        case 0x03://故障码
            ObjAttri_Read(ObjID,AttriID,(char*)&g_CANObject.m_Obj_0x00A0.ErrorReg,2,pCANMsg);
            break;
        default:
            pCANMsg->data8[0] = 0xF1;//属性ID不存在
            break;
        }
    }else if(0x00B0 == ObjID)
    {
        switch(AttriID)
        {
        case 0x01:
            ObjAttri_Read(ObjID,AttriID,(char*)&g_CANObject.m_Obj_0x00B0.poleNum,1,pCANMsg);
            break;
        case 0x02:
            ObjAttri_Read(ObjID,AttriID,(char*)&g_CANObject.m_Obj_0x00B0.ratedVol,1,pCANMsg);
            break;
        case 0x03:
            ObjAttri_Read(ObjID,AttriID,(char*)&g_CANObject.m_Obj_0x00B0.ratedCur,1,pCANMsg);
            break;
        case 0x04:
            ObjAttri_Read(ObjID,AttriID,(char*)&g_CANObject.m_Obj_0x00B0.ratedSpd,2,pCANMsg);
            break;
        default:
            pCANMsg->data8[0] = 0xF1;//属性ID不存在
            break;
        }
    }else if(0x00C0 == ObjID)
    {
        switch(AttriID)
        {
        case 0x01:
            ObjAttri_Read(ObjID,AttriID,(char*)&g_CANObject.m_Obj_0x00C0.cur_Kp,2,pCANMsg);
            break;
        case 0x02:
            ObjAttri_Read(ObjID,AttriID,(char*)&g_CANObject.m_Obj_0x00C0.cur_Ki,2,pCANMsg);
            break;
        case 0x03:
            ObjAttri_Read(ObjID,AttriID,(char*)&g_CANObject.m_Obj_0x00C0.spd_Kp,2,pCANMsg);
            break;
        case 0x04:
            ObjAttri_Read(ObjID,AttriID,(char*)&g_CANObject.m_Obj_0x00C0.spd_Ki,2,pCANMsg);
            break;
        case 0x05:
            ObjAttri_Read(ObjID,AttriID,(char*)&g_CANObject.m_Obj_0x00C0.fluxWk_Kp,2,pCANMsg);
            break;
        case 0x06:
            ObjAttri_Read(ObjID,AttriID,(char*)&g_CANObject.m_Obj_0x00C0.fluxWk_Ki,2,pCANMsg);
            break;
        default:
            pCANMsg->data8[0] = 0xF1;//属性ID不存在
            break;
        }
    }else if(0x00D0 == ObjID)
    {
        switch(AttriID)
        {
        case 0x01:
            ObjAttri_Read(ObjID,AttriID,(char*)&g_CANObject.m_Obj_0x00D0.overVol_set,1,pCANMsg);
            break;
        case 0x02:
            ObjAttri_Read(ObjID,AttriID,(char*)&g_CANObject.m_Obj_0x00D0.overCul_set,1,pCANMsg);
            break;
        case 0x03:
            ObjAttri_Read(ObjID,AttriID,(char*)&g_CANObject.m_Obj_0x00D0.overSpd_set,2,pCANMsg);
            break;
        default:
            pCANMsg->data8[0] = 0xF1;//属性ID不存在
            break;
        }
    }else{//对象ID不存在
        pCANMsg->data8[0] = 0xF0;
    }
}

void Obj_Write(Uint16 ObjID,Uint16 AttriID,const Uint16 *pWriteData,Uint16 writeSize,CAN_MSG *pCANMsg)
{
    int c = 0;
    memset(pCANMsg,0,sizeof(CAN_MSG));
    pCANMsg->id = hCAN_Pack(g_CANObject.m_Obj_0x00A0.NodeID, 0x1C);
    pCANMsg->data8[1] = (Uint16)((ObjID>>8) & 0x00FF);
    pCANMsg->data8[2] = (Uint16)(ObjID & 0x00FF);
    pCANMsg->data8[3] = AttriID;
    pCANMsg->len = 8;

    for (c = 0; c < 40; c++)   SlaveNodeID4[c] = SlaveNodeID3[c];
    if(0x00A0 == ObjID)
    {
        switch(AttriID)
        {
        case 0x01://节点ID
            ObjAttri_Write(ObjID,AttriID,(char*)&g_CANObject.m_Obj_0x00A0.NodeID,1,pWriteData,writeSize,pCANMsg);
            SlaveNodeID4[0]=g_CANObject.m_Obj_0x00A0.NodeID;
            break;
        case 0x02://节点状态
            pCANMsg->data8[0] = 0xF2;//只读属性
            break;
        case 0x03://故障码
            pCANMsg->data8[0] = 0xF2;//只读属性
            break;
        default:
            pCANMsg->data8[0] = 0xF1;//属性ID不存在
            break;
        }
    }else if(0x00B0 == ObjID)
    {
        switch(AttriID)
        {
        case 0x01:
            ObjAttri_Write(ObjID,AttriID,(char*)&g_CANObject.m_Obj_0x00B0.poleNum,1,pWriteData,writeSize,pCANMsg);
            SlaveNodeID4[10]=g_CANObject.m_Obj_0x00B0.poleNum;
            break;
        case 0x02:
            ObjAttri_Write(ObjID,AttriID,(char*)&g_CANObject.m_Obj_0x00B0.ratedVol,1,pWriteData,writeSize,pCANMsg);
            SlaveNodeID4[11]=g_CANObject.m_Obj_0x00B0.ratedVol;
            break;
        case 0x03:
            ObjAttri_Write(ObjID,AttriID,(char*)&g_CANObject.m_Obj_0x00B0.ratedCur,1,pWriteData,writeSize,pCANMsg);
            SlaveNodeID4[12]=g_CANObject.m_Obj_0x00B0.ratedCur;
            break;
        case 0x04:
            ObjAttri_Write(ObjID,AttriID,(char*)&g_CANObject.m_Obj_0x00B0.ratedSpd,2,pWriteData,writeSize,pCANMsg);
            SlaveNodeID4[13]=g_CANObject.m_Obj_0x00B0.ratedSpd;
            break;
        default:
            pCANMsg->data8[0] = 0xF1;//属性ID不存在
            break;
        }
    }else if(0x00C0 == ObjID)
    {
        switch(AttriID)
        {
        case 0x01:
            ObjAttri_Write(ObjID,AttriID,(char*)&g_CANObject.m_Obj_0x00C0.cur_Kp,2,pWriteData,writeSize,pCANMsg);
            SlaveNodeID4[20]=g_CANObject.m_Obj_0x00C0.cur_Kp;
            break;
        case 0x02:
            ObjAttri_Write(ObjID,AttriID,(char*)&g_CANObject.m_Obj_0x00C0.cur_Ki,2,pWriteData,writeSize,pCANMsg);
            SlaveNodeID4[21]=g_CANObject.m_Obj_0x00C0.cur_Ki;
            break;
        case 0x03:
            ObjAttri_Write(ObjID,AttriID,(char*)&g_CANObject.m_Obj_0x00C0.spd_Kp,2,pWriteData,writeSize,pCANMsg);
            SlaveNodeID4[22]=g_CANObject.m_Obj_0x00C0.spd_Kp;
            break;
        case 0x04:
            ObjAttri_Write(ObjID,AttriID,(char*)&g_CANObject.m_Obj_0x00C0.spd_Ki,2,pWriteData,writeSize,pCANMsg);
            SlaveNodeID4[23]=g_CANObject.m_Obj_0x00C0.spd_Ki;
            break;
        case 0x05:
            ObjAttri_Write(ObjID,AttriID,(char*)&g_CANObject.m_Obj_0x00C0.fluxWk_Kp,2,pWriteData,writeSize,pCANMsg);
            SlaveNodeID4[24]=g_CANObject.m_Obj_0x00C0.fluxWk_Kp;
            break;
        case 0x06:
            ObjAttri_Write(ObjID,AttriID,(char*)&g_CANObject.m_Obj_0x00C0.fluxWk_Ki,2,pWriteData,writeSize,pCANMsg);
            SlaveNodeID4[25]=g_CANObject.m_Obj_0x00C0.fluxWk_Ki;
            break;
        default:
            pCANMsg->data8[0] = 0xF1;//属性ID不存在
            break;
        }
    }else if(0x00D0 == ObjID)
    {
        switch(AttriID)
        {
        case 0x01:
            ObjAttri_Write(ObjID,AttriID,(char*)&g_CANObject.m_Obj_0x00D0.overVol_set,1,pWriteData,writeSize,pCANMsg);
            SlaveNodeID4[30]=g_CANObject.m_Obj_0x00D0.overVol_set;
            break;
        case 0x02:
            ObjAttri_Write(ObjID,AttriID,(char*)&g_CANObject.m_Obj_0x00D0.overCul_set,1,pWriteData,writeSize,pCANMsg);
            SlaveNodeID4[31]=g_CANObject.m_Obj_0x00D0.overCul_set;
            break;
        case 0x03:
            ObjAttri_Write(ObjID,AttriID,(char*)&g_CANObject.m_Obj_0x00D0.overSpd_set,2,pWriteData,writeSize,pCANMsg);
            SlaveNodeID4[32]=g_CANObject.m_Obj_0x00D0.overSpd_set;
            break;
        default:
            pCANMsg->data8[0] = 0xF1;//属性ID不存在
            break;
        }

    }else{//对象ID不存在
        pCANMsg->data8[0] = 0xF0;
    }
}

void ObjAttri_Read(Uint16 ObjID,Uint16 AttriID,const char *pData,Uint16 dataSize,CAN_MSG *pCANMsg)
{
    //封装回复报文
    Uint16 index;
    Uint16 *p16Data;
    Uint16 temp;
    Uint16 data[8];

//    memset(pCANMsg,0,sizeof(CAN_MSG));
//    pCANMsg->id = hCAN_Pack(g_CANObject.m_Obj_0x00A0.NodeID, 0x1F);
//    pCANMsg->data8[1] = (Uint16)(ObjID & 0x00FF);
//    pCANMsg->data8[2] = (Uint16)((ObjID>>8)&0x00FF);
//    pCANMsg->data8[3] = AttriID & 0x00FF;
//    pCANMsg->len = 8;
    if(dataSize > 4)
    {
        pCANMsg->data8[0] = 0xF2;
    }else{
        pCANMsg->data8[0] = 0x10 + dataSize;
        p16Data = (Uint16*)pData;

        temp = p16Data[0];
        data[0] = temp & 0x00FF;
        data[1] = (temp >> 8) & 0x00FF;
        if(dataSize > 2)
        {
            temp = p16Data[1];
            data[2] = temp & 0x00FF;
            data[3] = (temp >> 8) & 0x00FF;
        }
        for(index = 0;index < dataSize;index++)
        {
            pCANMsg->data8[4 + index] = data[dataSize-index-1];
        }
    }
}

void ObjAttri_Write(Uint16 ObjID,Uint16 AttriID,char *pData,Uint16 dataSize,const Uint16 *pWriteData,Uint16 writeSize,CAN_MSG *pCANMsg)
{
    Uint16 index;
    Uint32 writeData;
    Uint32 temp;

//    memset(pCANMsg,0,sizeof(CAN_MSG));
//
//    pCANMsg->id = hCAN_Pack(g_CANObject.m_Obj_0x00A0.NodeID, 0x1F);
//    pCANMsg->data8[1] = (Uint16)(ObjID & 0x00FF);
//    pCANMsg->data8[2] = (Uint16)((ObjID>>8)&0x00FF);
//    pCANMsg->data8[3] = AttriID;
//    pCANMsg->len = 8;

    if((dataSize != writeSize)||
       (writeSize > 4))
    {
        pCANMsg->data8[0] = 0xF2;//封装写异常报文
    }else{
        writeData = 0;
        for(index = 0;index < writeSize;index++)
        {
            temp = pWriteData[index] & 0x00FF;
            temp = temp << ((writeSize-index-1) << 3);
            writeData |= temp;
        }

        if(dataSize <= 2)
        {
            *(Uint16*)pData = writeData & 0x0000FFFF;
        }else{
            *(Uint32*)pData = writeData;
        }
        pCANMsg->data8[0] = 0x20;
    }
}

void CANPack_ValveStatus(CAN_MSG *pCANMsg)
{
    memset(pCANMsg,0,sizeof(CAN_MSG));

    pCANMsg->id = hCAN_Pack(g_CANObject.m_Obj_0x00A0.NodeID,0x19);
    g_CANObject.m_Obj_0x00A0.ErrorReg = 0;

    pCANMsg->data8[0] = g_Can_Atrib.statusSym;
    pCANMsg->data8[1] = g_Can_Atrib.runState;
    pCANMsg->data8[2] = g_Can_Atrib.runTime;

    if(g_Can_Atrib.statusSym == 0x0A)
    {
        pCANMsg->data8[3] = (Uint16)((g_Can_Atrib.dRef >> 4) & 0XFF);
        pCANMsg->data8[4] = (Uint16)(((g_Can_Atrib.dRef & 0X0F) << 4) | (g_Can_Atrib.qRef >> 8));
        pCANMsg->data8[5] = (Uint16)(g_Can_Atrib.qRef & 0XFF);
        pCANMsg->data8[6] = (Uint16)((g_CANObject.m_Obj_0x00A0.ErrorReg >>8) & 0XFF);
        pCANMsg->data8[7] = (Uint16)( g_CANObject.m_Obj_0x00A0.ErrorReg & 0XFF);
        pCANMsg->len = 8;
    }else if(g_Can_Atrib.statusSym == 0x0B){
        pCANMsg->data8[3] = (Uint16)((g_Can_Atrib.spdRef >> 16) & 0XFF);
        pCANMsg->data8[4] = (Uint16)((g_Can_Atrib.spdRef >> 8) & 0XFF);
        pCANMsg->data8[5] = (Uint16)( g_Can_Atrib.spdRef & 0XFF);
        pCANMsg->data8[6] = (Uint16)((g_CANObject.m_Obj_0x00A0.ErrorReg >>8) & 0XFF);
        pCANMsg->data8[7] = (Uint16)( g_CANObject.m_Obj_0x00A0.ErrorReg & 0XFF);
        pCANMsg->len = 8;
    }else{
        pCANMsg->len = 3;
    }
}