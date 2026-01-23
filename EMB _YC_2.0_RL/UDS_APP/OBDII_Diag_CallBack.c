#include "struct.h"
#include "OBDII_APP_IO.h"
#include "OBDII_DTC.h"
#include "OBDII_Diag_CallBack.h"
#include "OBDII_DTC_Trans_Protocol.h"
#include "OBDII_Diag_Snapshot.h"
#include "global_struct.h"
#include "mttcan.h"
#include "iodefine.h"


#define StartRoutine_C   		1
#define StopRoutine_C    		2
#define RoutineResult_C  		3

#define Routine_Progressing     1
#define Routine_Finished_OK   	2
#define Routine_Finished_NOK  	3
#define Routine_Stopped       	4

ubyte Routine_cmdStRLightStar=0;
ubyte Rc_tiRLight=0;
ubyte Cancel_flag = 0;

ubyte OBD_fgRecPhyActive_MP = 0;
ubyte OBD_fgRecFunActive_MP = 0;
ubyte OBD_fgRecOBDActive_MP = 0;

ubyte OBD_flgRecUDSPhy_MP=0;
ubyte OBD_flgRecOBDPhy_MP=0;
ubyte OBD_flgFunctiopnReq_MP=0;//UDS Function Req=1

ubyte OBDII_lRecDataLength_MP;

RecCan_valSeverDataNew Rec_Diag_Physical1 ={0};
RecCan_valSeverDataNew  Rec_Diag_Function1 ={0};

uint32 IO_fgInputOutcControl_MP = 0;
uint8 OBD_ctrlEn_MP[22] = {0};
uint8 OBD_ctrlSt_MP[22] = {0};
ubyte ECU_stReset_Cmd = 0 ;
ubyte ClearOne_FLG = 0;
ubyte ClearALL_FLG = 0;

extern void can_send(const CAN_MSG *pCANMsg);

void OBDII_CallBack_SecurityAccess_Seed(void)
{
  	// This is a demo seed &key algorithm as follows:
 
	UDS_Valseed.seed_size = 4;
	rand_num ++;

	UDS_Valseed.seed[0] = (BYTE)(rand_num);
	UDS_Valseed.seed[1] = (BYTE)(rand_num1);
	UDS_Valseed.seed[2] = (BYTE)(rand_num2);
	UDS_Valseed.seed[3] = (BYTE)(rand_num3);

}


void OBDII_CallBack_SecurityAccess_Key(ubyte UDS_ValSecLev_LO)
{
	// This is a demo seed &key algorithm as follows:
	UDS_Valseed.key_size=4;

	UDS_Valseed.key[0]=12;
	UDS_Valseed.key[1]=34;
	UDS_Valseed.key[2]=56;
	UDS_Valseed.key[3]=78;
}

ubyte OBDII_CallBack_SessionCtl_Condition(ubyte cur_session,ubyte req_session)
{
	 return 1;
}

ubyte OBDII_CallBack_EcuReset_Condition(void)
{
	 ubyte OBD_stRequestResult=TRUE;

	 if(1)
	 {
		 OBD_stRequestResult = TRUE;
	 }
	 else
	 {
		 OBD_stRequestResult = FALSE;
	 }

	 return(OBD_stRequestResult);
}

ubyte OBDII_CallBack_ClearDTC_Condition(void)
{
	 ubyte OBD_stRequestResult=TRUE;
	 return(OBD_stRequestResult);
}

ubyte OBDII_CallBack_ReadDATAbyID_Condition(void)
{
	 ubyte OBD_stRequestResult=TRUE;
	 return(OBD_stRequestResult);
}

ubyte OBDII_CallBack_ReadMemory_Condition(void)
{
	ubyte OBD_stRequestResult=TRUE;
	return(OBD_stRequestResult);
}

ubyte OBDII_CallBack_Security_Condition(void)
{
	ubyte OBD_stRequestResult=TRUE;
	return(OBD_stRequestResult);
}

ubyte OBDII_CallBack_CheckComCtr_Condition(void)
{
	 ubyte OBD_stRequestResult=TRUE;

	 if(1)
	 {
		 OBD_stRequestResult = TRUE;
	 }
	 else
	 {
		 OBD_stRequestResult = FALSE;
	 }

	 return(OBD_stRequestResult);
}

ubyte OBDII_CallBack_WriteDATAbyID_Condition(void)
{
	 ubyte OBD_stRequestResult=TRUE;
	 return(OBD_stRequestResult);
}

ubyte OBDII_CallBack_InputOutputCtl_Condition(void)
{
	 ubyte OBD_stRequestResult=TRUE;

	 if(0)
	 {
		 OBD_stRequestResult = TRUE;
	 }
	 else
	 {
		 OBD_stRequestResult = FALSE;
	 }

	 return(OBD_stRequestResult);
}

ubyte OBDII_CallBack_RoutineCtl_Condition(ubyte Routine_num)
{
	 ubyte OBD_stRequestResult=TRUE;

	 if(1)
	 {
		 OBD_stRequestResult = TRUE;
	 }
	 else
	 {
		 OBD_stRequestResult = FALSE;
	 }

	 return(OBD_stRequestResult);
}

ubyte OBDII_CallBack_WriteMemory_Condition(void)
{
	ubyte OBD_stRequestResult=TRUE;
	return(OBD_stRequestResult);
}

ubyte OBDII_CallBack_CtlDTC_Condition(void)
{
	 ubyte OBD_stRequestResult=TRUE;
	 return(OBD_stRequestResult);
}

void OBDII_CallBack_Current_DiagSession(ubyte OBDII_stSession)
{
//	uint8 i=0;
//	 = OBDII_stSession;
//	if(==0x01)
//	{
//		for(i=0;i<22;i++)
//		  =0;
//	}
}

void OBDII_CallBack_EcuReset_Execute(ubyte ECU_stResetMode)
{
	 switch (ECU_stResetMode)
	  {
		case 0x01://hardware reset
			ECU_stReset_Cmd = 1;
			//sleepflag = 1;
			break;
		case 0x02://ig off on reset
			break;
		case 0x03: //software reset
			SWSRESA0 = 0x00000001;

			break;
	  }
}

void OBDII_CallBack_ReadMemory_Execute(uword read_address,uword read_size)
{

}

void OBDII_CallBack_CommunicationCtl_Execute(ubyte ControlType,ubyte CommuniType)
{
	  switch(ControlType)
	  {
		case 0x0://enableRxAndTx
			CANRecForbid_st = 0;
			CANSendForbid_st = 0;
			break;
//		case 0x01: //enbleRxAndDisableTx
//			Btm_cmdCANRecForbid_MP=0;
//			Btm_cmdCANSendForbid_MP=1;
//			break;
//		case 0x02: //disableRxAndEnbleTx
//			Btm_cmdCANRecForbid_MP=1;
//			Btm_cmdCANSendForbid_MP=0;
//			break;
		case 0x03://disableRxAndTx
			CANRecForbid_st = 1;
			CANSendForbid_st=1;
			break;
	  }
}



ubyte OBDII_CallBack_InputOutputCtl_Execute(uword OBD_valPid_LO,ubyte *ctrlSt,ubyte *realSt)
{
   	uint8 OBDII_paraInOut_LO=0;
   	OBDII_paraInOut_LO=*ctrlSt;  //1:�ָ�Ĭ�ϺͿ���3:UDS���� ����״̬Ϊ*ctrlSt+1 *ctrlSt+2 ...(�Ϊ8)
//	switch (OBD_valPid_LO)
//	{
//	  	default:
//		break;
//	}
	return 0;
}


ubyte OBDII_CallBack_RoutineCtl_Execute(ubyte Routine_num,ubyte Routine_state,ubyte *ReturnResult_Buff)
{
	ubyte OBD_stRoutineCtl1_LO = 0, OBD_stRoutineCtl2_LO = 0,OBD_stRoutineResultSize_LO = 0;
	//The return value is the status of the routine execution
	switch (Routine_num)
	{
		case 0x00://Angle_Calibration
			if(Routine_state == StartRoutine_C)//Perform routine
			{
				//Start_TAS_Calibration = 1;
				*ReturnResult_Buff= 0;
			}
			else if(Routine_state == StopRoutine_C)
			{
				//Start_TAS_Calibration = 0;
				*ReturnResult_Buff = 0;
			}
			else if(Routine_state== RoutineResult_C)
			{
				//It could be other variables in the program
				/*if(Finished_TAS_Calibration == 1)
				{
					*ReturnResult_Buff = 1;
				}
				else if(Finished_TAS_Calibration == 0)
				{
					*ReturnResult_Buff = 0;
				}*/

			}
			OBD_stRoutineResultSize_LO=1;
			return OBD_stRoutineResultSize_LO;
			break;
			
		case 0x01://Cancel_Angle_Calibration
	    		if(Routine_state== StartRoutine_C)
	    		{
				Cancel_flag = 1;
	    			*ReturnResult_Buff= 0;
	    		}
			else if(Routine_state== StopRoutine_C)
	    		{
				Cancel_flag = 2;
	    			*ReturnResult_Buff= 2;
	    		}
	    		else if(Routine_state== RoutineResult_C)
	    		{
				if(Cancel_flag == 1)
				{
					Cancel_flag = 3;
					*ReturnResult_Buff= 3;
				}
				else if(Cancel_flag == 2)
				{
					Cancel_flag = 4;
					*ReturnResult_Buff = 4;
				}
	    		}
	  
	    		OBD_stRoutineResultSize_LO=1;
	    		return OBD_stRoutineResultSize_LO;
	    		break;
			
		default:
    			return 0;
    			break;
	}
}

void OBDII_CallBack_WriteDataByIdentifier_Execute(uword wr_id)
{
	switch(wr_id)
	{
	   	case OBDII_VehId:
			//I2C_BufferWrite(&OBDII_VehIdData[0],3392,17 );
			break;
	   	default:
			 break;
	}
}

void OBDII_CallBack_ResetRountine_Execute(void)
{
    	if(Routine_cmdStRLightStar==1)   //if allow routine to control Rl or not
    	{
         	Routine_cmdStRLightStar=0;
         	Rc_tiRLight=0;
    	}
}

void OBDII_CallBack_WriteMemory_Execute(uword wr_address,uword wr_size)
{

}

void OBDII_CallBack_CtlDTC_Execute(ubyte UDS_stCtlDTC_LO)
{
	UDS_stCtlDTC = UDS_stCtlDTC_LO;
}


void OBDII_CallBack_ClearSpecialDTC_Execute(uint32 DTC_Val,uint8 DTC_flgClearByAge)
{
	uint8 CDI_i;
	ClearOne_FLG = 1;
	Get_CurrentRecordnum_CurrentPosAfterClear(DTC_Val);

}


void OBDII_CallBack_ClearAllDTC_Execute(void)
{
	uint8 CDI_i;
	ClearALL_FLG = 1;
	Get_CurrentRecordnum_CurrentPosAfterClear(0xffffff);
	
	for(CDI_i = 0; CDI_i < (DTC_TABLE_SIZEUsed); CDI_i++)
	{
		EE_DTC_numAged[CDI_i]=0;
		EE_DTC_numFaultOccurrence[CDI_i]=0;
		EE_DTC_numFaultPending[CDI_i]=0;
		Fault_stRecord[CDI_i]=Fault_init;
		Fault_numRecord[CDI_i]=0;
	}
	//Clear_Faultflag();
}


//******************************Routine Task**************//
void Routine_Task(void)
{
	if(Routine_cmdStRLightStar==1)  //Routine Start
	{
		if(Rc_tiRLight<200)
			Rc_tiRLight++;
			
		if(Rc_tiRLight==100)
		{
			//Add code :Open the right light

		}
		else if(Rc_tiRLight==200)
		{
			//Add code :Close the right light

			Rc_tiRLight=0;
			Routine_cmdStRLightStar=2;    //Routine Finish  (200 cycles finish this routine)
		}
	}
	else if (Rc_tiRLight != 0)
	{
	   	//Add code : abnormal interrupt routine
	   	Rc_tiRLight=0;
	}
}

void Program_Sesion_software_reset(void)
{
	uint32 *dest_application = 0;
	dest_application = 0xFEF20000;  //FES
	*dest_application = 0x0101;
	 __DI();
	 FAD_DFlashWriteBootFLG(10);
	 SWSRESA0 = 1;		  
}

//***********  UDS_Receive_Request  *****************//
void OBDII_CallBack_RecUDS(void)
{
  	ubyte	TP_valCandata[8] = {0};
  	ubyte	TP_valAckdata[8] = {0};
  	ubyte TP_valIndex = 0;
  	if(Rec_Diag_Physical1.CanBus_flgRecActive)
  	{
	  	Rec_Diag_Physical1.CanBus_flgRecActive = 0;
		
	  	if((Rec_Diag_Physical1.CanBus_valRecCanData8.b[0] == 0x02)
			  &&(Rec_Diag_Physical1.CanBus_valRecCanData8.b[1] == 0x10)
			  &&(Rec_Diag_Physical1.CanBus_valRecCanData8.b[2] == 0x02))
	  	{
		  	if(1)
		  	{
			  	TP_valAckdata[0] = 0x03;
			  	TP_valAckdata[1] = 0x7F;
			  	TP_valAckdata[2] = 0x10;
			  	TP_valAckdata[3] = 0x78;
			  	OBD_flgRecOBDPhy_MP=0;
			  	OBD_flgFunctiopnReq_MP=0;
			  	OBDII_CallBack_SendAck(TP_valAckdata,4);
			  	Program_Sesion_software_reset();
		  	}
	  	}
		
    		CI_flgDTCFunAddrVaild_MP = 0;
		
      		for(TP_valIndex=0;TP_valIndex<8;TP_valIndex++)
      		{
       			TP_valCandata[TP_valIndex]=Rec_Diag_Physical1.CanBus_valRecCanData8.b[TP_valIndex];
      		}
     	 	OBDII_lRecDataLength_MP = Rec_Diag_Physical1.CanBus_valDataLength;
      		OBD_flgRecUDSPhy_MP=1;
      		OBD_flgFunctiopnReq_MP=0;
      		OBDII_CmdHandler_Rec(TP_valCandata,OBDII_lRecDataLength_MP);
  	}
  	else if(Rec_Diag_Function1.CanBus_flgRecActive==1)
  	{
    		Rec_Diag_Function1.CanBus_flgRecActive=0;
    		CI_flgDTCFunAddrVaild_MP = 1;
    		OBD_flgRecUDSPhy_MP=0;
      		for(TP_valIndex=0;TP_valIndex<8;TP_valIndex++)
      		{
        		TP_valCandata[TP_valIndex]=Rec_Diag_Function1.CanBus_valRecCanData8.b[TP_valIndex];
      		}
      		OBDII_lRecDataLength_MP = Rec_Diag_Function1.CanBus_valDataLength;
      		OBDII_CmdHandler_Rec(TP_valCandata,OBDII_lRecDataLength_MP);
  	}
  	else
  	{
    		CI_flgDTCFunAddrVaild_MP = 0;
		
    		if(OBDII_TP_FrameControl == 1)
    		{
      			OBDII_SendControlFrame();
    		}
  	}
}


//**************************UDS_Send_Respond****************************//
void OBDII_CallBack_SendAck(ubyte *pcandata,ubyte SendLength)
{
	CAN_MSG send_msg;
   	uint8 i;
	send_msg.id = 0x7EB;
	send_msg.len = 8;
	
        for(i=0;i<SendLength;i++)
        {
    	    send_msg.data8[i] = pcandata[i];
        }
        for(i=SendLength;i<8;i++)
        {
    	    send_msg.data8[i] =0xAA;
        }
	can_send(&send_msg);
}

void OBDII_CallBack_DTCOccurence(ubyte OBDII_DTC_Line)
{
	if(DTC_stAnderr[OBDII_DTC_Line].ErrOnce==1)
	{
		DTC_stAnderr[OBDII_DTC_Line].ErrOnce=2;
	}
}
void OBDII_CallBack_DTCStatusChange(ubyte OBDII_DTC_Line,ubyte OBDII_DTC_LastStatus,ubyte OBDII_DTC_CurrentStatus)
{

}
