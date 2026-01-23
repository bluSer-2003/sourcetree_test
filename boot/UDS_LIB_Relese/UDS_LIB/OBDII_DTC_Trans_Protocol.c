//****************************************************************************
// @Module        Trans_Protocol
// @Filename      Trans_Protocol.c
// @Project       XC2000_EV
//----------------------------------------------------------------------------
// @Controller    Infineon XC2765X-104F80
//
// @Compiler      Tasking Viper
//
//
// @Description   This file contains can dtc.
//
//----------------------------------------------------------------------------

//
//****************************************************************************

//****************************************************************************
// @Project Includes
//****************************************************************************
#include "MAIN.h"

#define stRecFinish  1
#define stRecDoing   2
#define stRecWrong   3
#define stSendDoing  4
#define stSendFinish 5
#define stSendWrong  6
#define stNoNeedCF   0
#define stWatingCF   1
#define stRecCFOK    2
ubyte OBDII_Unexpect_Frame_Process(ubyte TP_valFrameType_LO,ubyte TP_valSn_LO);
ubyte OBDII_Rec_Diagdata(ubyte TP_valFrameType_LO,ubyte *cmd,uword TP_lFrameData_LO);
void OBDII_Rec_DiagService_Process(void);

stSerRAndS OBDII_TP_stEffService;
stRCF  OBDII_TP_stRecCF;
ubyte TP_valFrameType_MP = 0;
ubyte OBDII_TP_valSid_MP = 0;
ubyte OBDII_TP_FrameControl = 0;  //0--未在流控阵及后续帧状态，1-开启流控帧状态，2-流控帧已发出，处于接收后续帧状态，3--后续帧接收完成，4--后续帧接收超时
ubyte OBDII_TP_ContinueFrameState = 0;  //0--未在流控阵及后续帧状态，1-开启流控帧状态，2-流控帧已发出，处于接收后续帧状态，3--后续帧接收完成
ubyte TP_valContinueServiceValid_MP = 0;
ubyte OBDII_TP_KeepRecCF = 0;
ubyte OBDII_flgSendCF_MP = 0;
ubyte OBDII_tiSendCF_MP = 0;
uint8 test_uds=0;
ubyte OBDII_flgSendFirst=0;
extern ubyte OBD_flgFunctiopnReq_MP;
void OBDII_CmdHandler_Rec(ubyte *cmd,ubyte OBDII_lRecDataLength_LO)
{
	ubyte TP_valServiceValid_LO = 0;
	ubyte TP_valSidValid_LO = 0;
	ubyte TP_valFrameType_LO=0;
	ubyte TP_valSn_LO=0;
	ubyte TP_valEffSid_LO;
	uword OBDCHR_i = 0,OBDCHR_j = 0;
	TP_valFrameType_LO=cmd[0] & 0xF0;
	if(((OBDII_TP_stEffService.stSeviceAct==stSendDoing)&&(OBDII_TP_stRecCF.stRecCF==stRecCFOK)&&((TP_valFrameType_LO == TP_ContinueFrame_C)||(TP_valFrameType_LO == TP_FirstFrame_C)||(TP_valFrameType_LO == TP_SingleFrame_C)))
			||(((TP_valFrameType_LO) == TP_ControlFrame_C)&&(OBDII_TP_FrameControl == stRecCFOK))
				||((TP_valContinueServiceValid_MP == 1)&&(OBDII_TP_KeepRecCF ==0))||((OBDII_TP_ContinueFrameState!=0)&&(cmd[1]==0x3e)&&(cmd[0]==0x2)))
	{
		TP_valServiceValid_LO = 0;
	}
	else if(((TP_valFrameType_LO) == TP_SingleFrame_C)
		||((TP_valFrameType_LO) == TP_FirstFrame_C)
		||(((TP_valFrameType_LO) == TP_ControlFrame_C)||(((TP_valFrameType_LO) == TP_ControlFrame_C)&&(TP_valContinueServiceValid_MP == 1)&&(OBDII_TP_KeepRecCF ==1)))
		||((TP_valFrameType_LO) == TP_ContinueFrame_C))
	{
		TP_valFrameType_MP = TP_valFrameType_LO;
		TP_valServiceValid_LO = 1;
	}

	if(TP_valServiceValid_LO == 1)
	{
		if (TP_valFrameType_MP == TP_SingleFrame_C)
		{
			  OBDII_TP_stEffService.lServiceR=cmd[0] & 0x0F;
			  OBDII_TP_valSid_MP = cmd[1];
			  OBDII_tiSendCF_MP=0;
		}
		else if (TP_valFrameType_MP == TP_FirstFrame_C)
		{
			OBDII_TP_stEffService.lServiceR=((uword)((cmd[0]&0x0F)*256) + cmd[1]);
			if(OBDII_TP_stEffService.lServiceR>6)
			{
			  OBDII_TP_valSid_MP = cmd[2];
			  OBDII_TP_FrameControl=1;
			  OBDII_TP_ContinueFrameState = 1;
			  OBDII_tiSendCF_MP=0;
			}
			else
			{
				OBDII_TP_valSid_MP=0;
			}
		}
		else if(TP_valFrameType_MP == TP_ControlFrame_C)
		{
			if(OBDII_lRecDataLength_LO >= 3)
			{
				OBDII_TP_stRecCF.valRecFS    = cmd[0]&0x0F;
				OBDII_TP_stRecCF.valRecBS    = cmd[1];
				OBDII_TP_stRecCF.valRecStmin = cmd[2];
//				if(OBDII_TP_stRecCF.valRecStmin<20)
//					OBDII_TP_stRecCF.valRecStmin=20;
				if((OBDII_TP_stRecCF.valRecFS==1)&&(CI_flgDTCFunAddrVaild_MP==FALSE))
				{
					OBDII_TP_stRecCF.stRecCF=stWatingCF;
					if(OBDII_TP_KeepRecCF ==1)
					{
						OBDII_TP_KeepRecCF =0;
					}
				}

				if((OBDII_TP_stRecCF.valRecFS==0)&&(CI_flgDTCFunAddrVaild_MP==FALSE))
				{
					OBDII_TP_stRecCF.stRecCF=stRecCFOK;
					if(OBDII_TP_KeepRecCF ==1)
					{
						OBDII_TP_KeepRecCF =0;
					}
				}
			}
		}
		else if(TP_valFrameType_MP == TP_ContinueFrame_C)
		{
			TP_valSn_LO = cmd[0]&0x0F;
			if((OBDII_tiSendCF_MP<OBDII_tiSendCF_Max)&&(OBDII_flgSendCF_MP==1))
			{
				OBDII_tiSendCF_MP=0;
				OBDII_flgSendCF_MP=0;
			}
		}

		for(OBDCHR_j = 0;OBDCHR_j<OBDII_Support_Service_num;OBDCHR_j++)
		{
			test_uds=OBDII_TP_valSid_MP;
			if(OBDII_TP_valSid_MP == OBDII_Service_demondLst[OBDCHR_j].valSid)
			{
				test_uds=1;
				if(OBDII_Service_demondLst[OBDCHR_j].Support_Or_Not==Support_Service)
				{
				  TP_valSidValid_LO = 1;
				  OBDII_TP_stEffService.TP_posSevice=OBDCHR_j;
				  test_uds=2;
				}
			}
		}
		if((TP_valSidValid_LO == 0)&&(OBDII_TP_valSid_MP!=0)&&(TP_valFrameType_MP != TP_ControlFrame_C)&&(TP_valFrameType_MP != TP_ContinueFrame_C))
		{

			OBDII_TP_stEffService.valActSid = OBDII_TP_valSid_MP;
			OBDII_TP_stEffService.valWrongCode=Service_Not_Supported;
			OBDII_Neg_Response();

			OBDII_TP_valSid_MP = 0;
		}
		else if((OBDII_TP_stEffService.stSeviceAct == stSendDoing)&&(TP_valFrameType_MP == TP_ContinueFrame_C))
		{
			OBDII_TP_stEffService.valActSid = OBDII_TP_valSid_MP;
			OBDII_TP_stEffService.valWrongCode=Request_Out_Of_Range;
			OBDII_Neg_Response();

			OBDII_TP_valSid_MP = 0;
		}

		TP_valEffSid_LO=OBDII_Unexpect_Frame_Process(TP_valFrameType_MP,TP_valSn_LO);

		if(TP_valEffSid_LO!=0)
			OBDII_TP_valSid_MP = 0;


		if(((TP_valFrameType_MP == TP_SingleFrame_C)&&(((OBDII_TP_stEffService.lServiceR>=7)&&(OBDII_lRecDataLength_LO==8))||((OBDII_TP_stEffService.lServiceR<7)&&(OBDII_lRecDataLength_LO>=(OBDII_TP_stEffService.lServiceR+1)))))
				||((TP_valFrameType_MP == TP_FirstFrame_C)&&(OBDII_lRecDataLength_LO == 8))
				||((TP_valFrameType_MP == TP_ControlFrame_C)&&(OBDII_lRecDataLength_LO >= 3))
				||((TP_valFrameType_MP == TP_ContinueFrame_C)&&((((OBDII_TP_stEffService.lServiceR-OBDII_TP_stEffService.lRecCnt)>7)&&(OBDII_lRecDataLength_LO == 8))||(((OBDII_TP_stEffService.lServiceR-OBDII_TP_stEffService.lRecCnt)<=7)&&(OBDII_lRecDataLength_LO >=((OBDII_TP_stEffService.lServiceR-OBDII_TP_stEffService.lRecCnt)+1))))))
		{

		}
		else
			OBDII_TP_valSid_MP = 0;

		if(TP_valEffSid_LO == 0)
		{
			OBDII_TP_stEffService.valActSid=OBDII_TP_valSid_MP;

			if((TP_valFrameType_LO == TP_SingleFrame_C)||(TP_valFrameType_LO == TP_FirstFrame_C)||((CI_flgDTCFunAddrVaild_MP == FALSE)&&(TP_valFrameType_LO == TP_ContinueFrame_C)))
			{
				if((OBDII_TP_valSid_MP!=0)&&(OBDII_tiSendCF_MP<OBDII_tiSendCF_Max))
				{
					OBDII_TP_stEffService.stSeviceAct=OBDII_Rec_Diagdata(TP_valFrameType_LO,cmd,OBDII_TP_stEffService.lServiceR);
				}
				else
				{
					OBDII_TP_stEffService.stSeviceAct=0;
					OBDII_TP_stEffService.lServiceR=0;
					for(OBDCHR_i = 0; OBDCHR_i < 100; OBDCHR_i++)
					{
						OBDII_TP_stEffService.TP_valRecBuf_MP[OBDCHR_i]=0;
					}
				}
				if((OBDII_TP_stEffService.stSeviceAct==1)&&( OBDII_Service_demondLst!= ((Service_CSTR*)0)))
				{
					OBDII_Rec_DiagService_Process();
				}
			}
		}
		else
		{
			OBDII_TP_FrameControl = 0;
			OBDII_TP_ContinueFrameState = 0;
		}
	}
}
ubyte OBDII_Unexpect_Frame_Process(ubyte TP_valFrameType_LO,ubyte TP_valSn_LO)
{
	static ubyte TP_valSnLast_LO = 0;
	static ubyte TP_valCfnum_LO = 0;
	ubyte TP_valResult_LO=0;
	if(TP_valFrameType_LO == TP_FirstFrame_C)
	{
		TP_valSnLast_LO=0;
		TP_valCfnum_LO=0;
	}
	else if(TP_valFrameType_LO == TP_SingleFrame_C)
	{
	   TP_valSnLast_LO = 0;
	   TP_valCfnum_LO=0;
	}
	else if(TP_valFrameType_LO == TP_ContinueFrame_C)
	{
	   TP_valCfnum_LO=0;
	}
	else if(TP_valFrameType_LO == TP_ControlFrame_C)
	{
	   TP_valCfnum_LO++;
	}
	if((TP_valFrameType_LO == TP_SingleFrame_C)&&((OBDII_TP_stEffService.lServiceR>7)||(OBDII_TP_stEffService.lServiceR==0)))
	   TP_valResult_LO=1;
	if((TP_valFrameType_LO == TP_FirstFrame_C)&&((OBDII_TP_stEffService.lServiceR>4095)||(OBDII_TP_stEffService.lServiceR<7)))
	   TP_valResult_LO=2;
	if(TP_valFrameType_LO == TP_ContinueFrame_C)
	{
	   if(((TP_valSn_LO-TP_valSnLast_LO)==1)||((TP_valSnLast_LO==0x0f)&&(TP_valSn_LO)==0))
	   {
		   TP_valSnLast_LO=TP_valSn_LO;
	   }
	   else
		 TP_valResult_LO=3;
	}
	if((TP_valFrameType_LO == TP_ControlFrame_C)&&(OBDII_TP_stRecCF.valRecFS==2))
	   TP_valResult_LO=4;
	if((TP_valFrameType_LO == TP_ControlFrame_C)&&(TP_valCfnum_LO>OBDII_TP_valWFTmax))
	   TP_valResult_LO=5;
	if((CI_flgDTCFunAddrVaild_MP == TRUE)&&(TP_valFrameType_LO == TP_FirstFrame_C))
	{
	   TP_valResult_LO=6;
	}
	return TP_valResult_LO;
}

ubyte OBDII_Rec_Diagdata(ubyte TP_valFrameType_LO,ubyte *cmd,uword TP_lFrameData_LO)//BMS接收后续帧工作在此完成
{
	ubyte TP_valSn_LO = 0;
	ubyte TP_flgRecReqFinish_LO = 0;
	uword OBDRD_i = 0,OBDRD_j = 0;
	if (TP_valFrameType_LO == TP_SingleFrame_C)
	{
		for(OBDRD_i = 0; OBDRD_i < 100; OBDRD_i++)
		{
			OBDII_TP_stEffService.TP_valRecBuf_MP[OBDRD_i]=0;
		}
		memcpy(&OBDII_TP_stEffService.TP_valRecBuf_MP[0],&(cmd[2]),6);

		TP_flgRecReqFinish_LO=stRecFinish;
		OBDII_TP_stEffService.lRecCnt=OBDII_TP_stEffService.lServiceR-1;
	}
	else if (TP_valFrameType_LO == TP_FirstFrame_C)
	{
		for(OBDRD_j = 0; OBDRD_j <100; OBDRD_j++)
		{
			OBDII_TP_stEffService.TP_valRecBuf_MP[OBDRD_j]=0;
		}
		memcpy(&OBDII_TP_stEffService.TP_valRecBuf_MP[0],&(cmd[3]),5);
		OBDII_TP_stEffService.lRecCnt = 5;
	}
	else if (TP_valFrameType_LO == TP_ContinueFrame_C)
	{
		TP_valSn_LO=(cmd[0]&0x0F);
		if(OBDII_TP_FrameControl == 2)
		{
			if((TP_lFrameData_LO-1-OBDII_TP_stEffService.lRecCnt)>7)
			{
				memcpy(&OBDII_TP_stEffService.TP_valRecBuf_MP[OBDII_TP_stEffService.lRecCnt],&(cmd[1]),7);
				OBDII_TP_stEffService.lRecCnt += 7;
				TP_flgRecReqFinish_LO = stRecDoing;
				if((OBDII_TP_valSendFS != 0)&&((TP_valSn_LO%OBDII_TP_valSendFS)==0))
					OBDII_SendControlFrame();

				OBDII_TP_ContinueFrameState = 2;
			}
			else
			{
				memcpy(&OBDII_TP_stEffService.TP_valRecBuf_MP[OBDII_TP_stEffService.lRecCnt],&(cmd[1]),(TP_lFrameData_LO-OBDII_TP_stEffService.lRecCnt));
				TP_flgRecReqFinish_LO=stRecFinish;
				OBDII_TP_ContinueFrameState = 3;
				OBDII_TP_FrameControl = 3;
			}
		}
	}
	return TP_flgRecReqFinish_LO;
}

void OBDII_Rec_DiagService_Process(void)
{
	switch(OBDII_TP_stEffService.valActSid)
	{
		case TP_StartDiagnosticSession://开始诊断会话服务
		{
			UDS_tiDiagSeon = 0;
			OBDII_flgReqSeedNum=0;
			StartDiagnosticSession_Process();
			break;
		}
		case TP_EcuReset://ECU复位服务
		{
			UDS_tiDiagSeon = 0;
			OBDII_flgReqSeedNum=0;
			EcuReset_Process();
			break;
		}
		case TP_ClearDiagnosticInformation://清除诊断数据服务
		{
			UDS_tiDiagSeon = 0;
			OBDII_flgReqSeedNum=0;
			ClearDiagnosticInformation_Process();
			break;
		}
		case TP_ReadDTCInfor://读DTC诊断数据服务
		{
			UDS_tiDiagSeon = 0;
			OBDII_flgReqSeedNum=0;
			ReadDTCInfor_Process();
			break;
		}
		case TP_ReadDataByIdentifier://读取数据服务
		{
			UDS_tiDiagSeon = 0;
			OBDII_flgReqSeedNum=0;
			ReadDataByIdentifier_Process();
			break;
		}
		case TP_ReadMemoryByAddress://读取内存数据服务
		{
			UDS_tiDiagSeon = 0;
			OBDII_flgReqSeedNum=0;
			ReadMemoryByAddress_Process();
			break;
		}
		case TP_SecurityAccess://安全进入服务
		{
			UDS_tiDiagSeon = 0;
			SecurityAccess_Process();
			break;
		}
		case TP_CommunicationControl://通信控制
		{
			UDS_tiDiagSeon = 0;
			OBDII_flgReqSeedNum=0;
			CommunicationCtr_Process();
			break;
		}
		case TP_WriteDataByIdentifier://写数据服务
		{
			UDS_tiDiagSeon = 0;
			OBDII_flgReqSeedNum=0;
			WriteDataByIdentifier_Process();
			break;
		}
		case TP_InputOutputControlByIdentifier://控制输入输出服务
		{
			UDS_tiDiagSeon = 0;
			OBDII_flgReqSeedNum=0;
			InputOutputControlByIdentifier_Process();
			break;
		}
		case TP_RoutineCtlByIdentifier://历程控制
		{
			UDS_tiDiagSeon = 0;
			OBDII_flgReqSeedNum=0;
			Routine_Control_Process();
			break;
		}
		case TP_WriteMemoryByAddress://写内存数据服务
		{
			UDS_tiDiagSeon = 0;
			OBDII_flgReqSeedNum=0;
			WriteMemoryByAddress_Process();
			break;
		}
		case TP_TesterPresent://诊断在线服务
		{
			UDS_tiDiagSeon = 0;
			OBDII_flgReqSeedNum=0;
			TesterPresent_Process();
			break;
		}
		case TP_ControlDTCSetting://控制DTC服务
		{
			UDS_tiDiagSeon = 0;
			OBDII_flgReqSeedNum=0;
			ControlDTCSetting_Process();
			break;
		}
		case OBD_ReqCurrDiagData_15031://01
		{
			OBD_flgFunctiopnReq_MP=1;
			OBD_RequestDiagData_15031();
			break;
		}

		case OBD_ReqVehInf_15031://09
		{
			OBD_flgFunctiopnReq_MP=1;
			OBD_RequestVehInfor_15031();
			break;
		}

		default :
		{
			if(CI_flgDTCFunAddrVaild_MP == FALSE)
			{
				OBDII_TP_stEffService.valWrongCode=Service_Not_Supported;
				OBDII_Neg_Response();
			}
			break;
		}
	}
}
void OBDII_TpLayer_Timer(void)
{
	 if(OBDII_flgSendCF_MP==1)
	 {
		 OBDII_tiSendCF_MP=OBDII_tiSendCF_MP+1;
	 }
	 else
	 {
		 OBDII_tiSendCF_MP=0;
	 }
}

void OBDII_Neg_Response(void)
{
	ubyte sendbuf[8];
	ubyte OBD_stNegNoResponseResult=FALSE;
    if((OBDII_TP_stEffService.valActSid<0x10)&&(CI_flgDTCFunAddrVaild_MP == TRUE))
    {
            OBD_stNegNoResponseResult=FALSE;
    }
    else if( (OBDII_TP_stEffService.valWrongCode!=Incorrect_Message_Length_Or_Invalid_Format)&&
	(CI_flgDTCFunAddrVaild_MP == TRUE))
    {
    		OBD_stNegNoResponseResult=TRUE;
    }
	if(OBD_stNegNoResponseResult==FALSE)
	{
		sendbuf[0] = 0x03;
		sendbuf[1] = 0x7f;
		sendbuf[2] = OBDII_TP_stEffService.valActSid;
		sendbuf[3] = OBDII_TP_stEffService.valWrongCode;
		sendbuf[4] = 0xCC;
		sendbuf[5] = 0xCC;
		sendbuf[6] = 0xCC;
		sendbuf[7] = 0xCC;
		//*************modify 20200227
		OBDII_CallBack_SendAck(sendbuf,4);
		//*************modify 20200227 end
		OBDII_TP_ContinueFrameState = 0;

	}
	OBDII_TP_stEffService.valWrongCode = 0;

}
void OBDII_SendControlFrame(void)
{
	ubyte sendbuf[8];
	sendbuf[0] = 0x30+OBDII_TP_valSendFS;
	sendbuf[1] = OBDII_TP_valSendBS;
	sendbuf[2] = OBDII_TP_valSendST;
	sendbuf[3] = 0xAA;
	sendbuf[4] = 0xAA;
	sendbuf[5] = 0xAA;
	sendbuf[6] = 0xAA;
	sendbuf[7] = 0xAA;
	//***********modify  20200227
	OBDII_CallBack_SendAck(sendbuf,3);
	//***********modify  20200227 end
	if(OBDII_TP_stEffService.valWrongCode != 0)
	{
		OBDII_TP_FrameControl = 0;
		OBDII_TP_ContinueFrameState = 0;
	}
	else
	{
		OBDII_TP_ContinueFrameState = 0;
		OBDII_TP_FrameControl = 2;
	}
	OBDII_tiSendCF_MP=0;
	OBDII_flgSendCF_MP=1;

}
void OBDII_Send_ResPonsReqdata(void)
{
	 ubyte TP_valSendData[8]={0};
	 uword OBDSRPR_i = 0,OBDSRPR_j = 0;
	 OBDII_TP_FrameControl = 0;
	 if(OBDII_TP_stEffService.valWrongCode!=0)
	 {
		 OBDII_Neg_Response();
	 }
	 else
	 {
		 if(OBDII_TP_stEffService.lServiceS<=6)
		 {
			 TP_valSendData[0]=OBDII_TP_stEffService.lServiceS+1;
			 TP_valSendData[1]=OBDII_TP_stEffService.valActSid+0x40;
			 for(OBDSRPR_i=0; OBDSRPR_i < OBDII_TP_stEffService.lServiceS; OBDSRPR_i++)
				 TP_valSendData[OBDSRPR_i+2]=OBDII_TP_stEffService.TP_valSendBuf_MP[OBDSRPR_i];
			 if((OBDII_TP_stEffService.lServiceS+2)<8)
			 {
				 for(OBDSRPR_i=0; OBDSRPR_i < (8-(OBDII_TP_stEffService.lServiceS+2)); OBDSRPR_i++)
				 {
					 TP_valSendData[OBDSRPR_i+2+OBDII_TP_stEffService.lServiceS]=0xCC;
				 }
			 }
			 //modify 20200227
			 OBDII_CallBack_SendAck(TP_valSendData,(OBDII_TP_stEffService.lServiceS+2));
			 //modify 20200227 end
			 OBDII_TP_stEffService.lSendCnt=0;
		 }
		 else
		 {
			 TP_valSendData[0]=0x10+(OBDII_TP_stEffService.lServiceS+1)/256;
			 TP_valSendData[1]=(OBDII_TP_stEffService.lServiceS+1)%256;
			 TP_valSendData[2]=OBDII_TP_stEffService.valActSid+0x40;
			 for( OBDSRPR_j = 0; OBDSRPR_j < 5; OBDSRPR_j++)
				 TP_valSendData[OBDSRPR_j+3]=OBDII_TP_stEffService.TP_valSendBuf_MP[OBDSRPR_j];
			 //modify 20200227
			 OBDII_CallBack_SendAck(TP_valSendData,8);
			 //modify 20200227
			 OBDII_TP_stRecCF.stRecCF=stWatingCF;
			 OBDII_TP_stEffService.numSendSN=0;
			 OBDII_TP_stEffService.lSendCnt=5;
			 OBDII_TP_stEffService.stSeviceAct=stSendDoing;
			 OBDII_flgSendFirst=1;
		 }
	 }
	 OBDII_TP_ContinueFrameState = 0;
}
ubyte TP_tiSendCF_LO = 0;
ubyte TP_SendCount_MP = 0;
void OBDII_Send_ResPonsCondata(void)
{
	static ubyte Keep_RecCF_flg=0;
	static uword TP_numFCDelay_LO = 0;
	ubyte TP_valSendData[8]={0};
	uword OBDSRPC_i = 0,OBDSRPC_j = 0;

	if((OBDII_TP_stRecCF.stRecCF == stWatingCF)&&(OBDII_TP_stEffService.stSeviceAct==stSendDoing))//&&(TP_numFCDelay_LO == 0))
	{
		if(OBDII_TP_stRecCF.valRecFS==1)
		{
			TP_numFCDelay_LO=0;
			OBDII_TP_stRecCF.valRecFS=0;
		}
		else
		{
			if(TP_numFCDelay_LO<14)
				TP_numFCDelay_LO++;
			else
			{
				OBDII_TP_stEffService.stSeviceAct = stSendFinish;
				TP_numFCDelay_LO = 0;
			}
		}
	}
	else
	{
		TP_numFCDelay_LO = 0;
	}

	if(OBDII_TP_stEffService.stSeviceAct==stSendDoing)
	{
		TP_tiSendCF_LO=TP_tiSendCF_LO+10;
		if((OBDII_TP_stRecCF.stRecCF==stRecCFOK)&&(((TP_tiSendCF_LO>=((ubyte)(OBDII_TP_stRecCF.valRecStmin))))||(OBDII_TP_stRecCF.valRecStmin<10)))
//		if(OBDII_TP_stRecCF.stRecCF==stRecCFOK)
		{
			TP_tiSendCF_LO=0;
			TP_valContinueServiceValid_MP = 1;//////////////////////

			OBDII_flgSendFirst+=1;
			if(OBDII_TP_stEffService.lServiceS-OBDII_TP_stEffService.lSendCnt>(OBDII_TP_stRecCF.valRecBS*7))
			{
				OBDII_TP_KeepRecCF=1;
			}
			else
			{
				Keep_RecCF_flg=Keep_RecCF_flg+1;
			}
			TP_SendCount_MP = TP_SendCount_MP+1;
			OBDII_TP_stEffService.numSendSN += 1;

			if(OBDII_TP_stEffService.numSendSN==(OBD_BSvalue+1))
				OBDII_TP_stEffService.numSendSN=0;

			TP_valSendData[0]=OBDII_TP_stEffService.numSendSN+0x20;

			if(OBDII_TP_stEffService.lServiceS>(OBDII_TP_stEffService.lSendCnt+7))
			{
			   for(OBDSRPC_i = 0; OBDSRPC_i < 7; OBDSRPC_i++)
				  TP_valSendData[OBDSRPC_i+1]=OBDII_TP_stEffService.TP_valSendBuf_MP[OBDII_TP_stEffService.lSendCnt+OBDSRPC_i];
			   //modify 20200227
			   OBDII_CallBack_SendAck(TP_valSendData,8);
			   //modify 20200227 end
			   OBDII_TP_stEffService.lSendCnt+=7;

			   OBDII_TP_stEffService.stSeviceAct=stSendDoing;
			}
			else
			{
				for(OBDSRPC_j = 0; OBDSRPC_j < (OBDII_TP_stEffService.lServiceS-OBDII_TP_stEffService.lSendCnt); OBDSRPC_j++)
					TP_valSendData[OBDSRPC_j+1]=OBDII_TP_stEffService.TP_valSendBuf_MP[OBDII_TP_stEffService.lSendCnt+OBDSRPC_j];
				if((OBDII_TP_stEffService.lServiceS-OBDII_TP_stEffService.lSendCnt)<7)
				{
					for(OBDSRPC_j = 0; OBDSRPC_j < 7-(OBDII_TP_stEffService.lServiceS-OBDII_TP_stEffService.lSendCnt); OBDSRPC_j++)
					{
						TP_valSendData[OBDSRPC_j+1+(OBDII_TP_stEffService.lServiceS-OBDII_TP_stEffService.lSendCnt)]=0xCC;
					}
				}
				// modify 20200227
				OBDII_CallBack_SendAck(TP_valSendData,(1+(OBDII_TP_stEffService.lServiceS-OBDII_TP_stEffService.lSendCnt)));
				// modify 20200227 end
				OBDII_TP_stEffService.lSendCnt=0;

				TP_SendCount_MP=0;
				OBDII_TP_KeepRecCF=0;
				OBDII_TP_stEffService.stSeviceAct=stSendFinish;
				OBDII_TP_stRecCF.stRecCF = stWatingCF;
				TP_tiSendCF_LO=0;
			}
			if(OBDII_TP_stRecCF.valRecBS!=0)
			{
			   if(((TP_SendCount_MP%OBDII_TP_stRecCF.valRecBS) == 0))
			   {
				   OBDII_TP_stRecCF.stRecCF=stWatingCF;
			   }
			}
		}
		else
		{
			TP_valContinueServiceValid_MP = 0;
		}

		if((OBDII_TP_stRecCF.stRecCF==stRecCFOK)&&((OBDII_flgSendFirst==1)||(OBDII_flgSendFirst==3)))
		{
			if(TP_tiSendCF_LO<6)
			{
				TP_tiSendCF_LO++;

			}
			if((TP_tiSendCF_LO==2)||(TP_tiSendCF_LO==6))
			{
				OBDII_flgSendFirst+=1;
			}

		}

	}
	else
	{
		TP_tiSendCF_LO=0;
		TP_valContinueServiceValid_MP = 0;
	}
}

void OBD_Service(void)
{
	OBDII_Send_ResPonsCondata();
//	OBDII_CallBack_RecUDS();
	DiagSeon_Timer();
	Securiry_Timer();
	OBDII_TpLayer_Timer();

}
void OBDII_cmd_RecUDS(RecCan_valSeverDataNew Rec_Diag_Physical,RecCan_valSeverDataNew Rec_Diag_Function)
{
	ubyte TP_valCandata[8];
	ubyte TP_valIndex;
	ubyte OBDII_lRecDataLength_LO;


		if((Rec_Diag_Physical.CanBus_flgRecActive==1)||(Rec_Diag_Physical.CanBus_flgRecActive==1))
		{
			CI_flgDTCFunAddrVaild_MP = FALSE;
			for(TP_valIndex=0;TP_valIndex<8;TP_valIndex++)
			{
				TP_valCandata[TP_valIndex]=Rec_Diag_Physical.CanBus_valRecCanData8.b[TP_valIndex];
			}
			OBDII_lRecDataLength_LO = Rec_Diag_Physical.CanBus_valDataLength;
			OBDII_CmdHandler_Rec(TP_valCandata,OBDII_lRecDataLength_LO);
		}
		else if(Rec_Diag_Function.CanBus_flgRecActive==1)
		{
			CI_flgDTCFunAddrVaild_MP = TRUE;
			for(TP_valIndex=0;TP_valIndex<8;TP_valIndex++)
			{
				TP_valCandata[TP_valIndex]=Rec_Diag_Function.CanBus_valRecCanData8.b[TP_valIndex];
			}
			OBDII_lRecDataLength_LO = Rec_Diag_Function.CanBus_valDataLength;
			OBDII_CmdHandler_Rec(TP_valCandata,OBDII_lRecDataLength_LO);
		}
		else
		{
			CI_flgDTCFunAddrVaild_MP = FALSE;
			if(OBDII_TP_FrameControl == 1)
			{
				OBDII_SendControlFrame();
			}
		}
}
