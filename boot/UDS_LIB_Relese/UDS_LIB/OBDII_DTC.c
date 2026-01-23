//****************************************************************************
// @Module        OBD_II
// @Filename      OBD_II.c
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

#define Memory_start     0xa00000
#define Memory_end       0xb00000
ubyte Requestvehicleinfor_process(uword OBD_valPid_LO);
void ReportNumOfDTCbyStsMsk(void);
void ReportDTCbyStsMsk(void);
void ReportDtcSnapshotid(void);
void ReportDtcSnapshotByDTCnum(void);
void ReportDtcSnapshotByRecordNumber(void);
void ReportDtcExtendDataRecordByDTCnumber(void);
void ReportNumberOfDtcBySeverityMaskRecord(void);
void ReportDtcBySeverityMaskRecord(void);
void ReportSeverityInformOfDTC(void);
void ReportSuppedDTC(void);
void ReportFirstTestFailedDTC(void);
void ReportFirstCofirmedDTC(void);
void ReportDTCWithPermanentStatus(void);
//****************DTC条件变量*****************//
ubyte Dsg_flgInitDtcInfoFinish_MP = 0;
ubyte UDS_stCtlDTC = 1;
//**************************************************************/
ubyte UDS_stDiagSeon=1;
ubyte UDS_stDiagSeonLast = 1;
ubyte UDS_ValSecLev=0;
ubyte UDS_ValSecLev_last = 0;
uds_27_seedkey UDS_Valseed;
uword UDS_tiDiagSeon=0;
ubyte UDSVer_1;
ubyte UDSVer_2;
ubyte UDSVer_year;
ubyte UDSVer_month;
ubyte UDSVer_day;
ubyte Security_Timer_Flg=0;
ubyte Security_FAA_st=0;
ubyte CANRecForbid_st=0;
ubyte CANSendForbid_st=0;
ubyte OBDII_flgReqSeedNum=0;
ubyte TP_stSecurityState_MP = 0;
ubyte OBDII_DTC_AvailabilityMask=0xff;
DtcType_CSTR OBDII_DTC_FstTestFail;
DtcType_CSTR OBDII_DTC_FstConfirmed;
ubyte CI_flgDTCFunAddrVaild_MP = 0;
ubyte  Security_lib_Level1;
ubyte  Security_lib_Level2;

ubyte  OBDII_Support_Service_num=2;
ubyte  OBDII_PID_InOut_SIZE=2;
ubyte  OBDII_Routine_Data_SIZE=2;
ubyte  OBDII_Veh_Data_SIZE=2;
ubyte  OBDII_PID_TABLE_SIZE=2;
ubyte  OBD_PID_SIZE=2;
ubyte  OBD_VehData_SIZE=2;
ubyte OBDII_DTC_TABLE_SIZE=2;
ubyte OBDII_DTC_SupportSnapshot_SIZE=2;
ubyte OBDII_A_DTC_SnapshotDID_MAXNum=2;
ubyte OBDII_A_DTC_SnapshotExt_MAXNum=2;

ubyte OBDII_flgOperationstart=0;
ubyte OBDII_DTC_SaveSnapshot_SIZE=2;

const Snapshot_ofDTC *OBDII_DTC_SnapshotList=NULL;
const Service_CSTR *OBDII_Service_demondLst=NULL;
uds_InOut_Ctrl *OBDII_InOut_ParaLst=NULL;
const Routine_CSTR *OBDII_Routine_DATA=NULL;
const VehData_CSTR *OBD_Veh_InfLst=NULL;
const DiagData_CSTR *OBDII_DD_PidLst=NULL;
const OBD_DiagData_Inf *OBDII_PidLst=NULL;
const OBD_VehData_Inf *OBDII_VehPidLst=NULL;
const DtcType_CSTR *OBDII_DTC_Lst=NULL;
Dtcst_CSTR *DTC_st_errNum=NULL;
ubyte OBDII_num_DTCConfirm;
const ubyte *OBDII_DTC_TempSnapshotList=NULL;

uword P2Server;
uword P2_Server;
uword SessionTime;
uword TesterPresentTime;

Sec_ActTimer OBDII_TimeSec_Mp ={3,0,0,3,0,0,0};//赋初值;
uword OBDII_TiSec_Mp=0;
UDS_RcRecord OBDII_VauRcRecor={0,  0,  0, 0};
ubyte ReadZI_buff[56];
ubyte OBDII_ZI[50];
ubyte OBDII_ZA[22];
ubyte OBDII_flgZIReady=0;
ubyte OBDII_flgZAReady=0;
ubyte OBDII_ECUSerialNum[17];
ubyte OBD_stExeReturnValue[10]={0};
ubyte OBDII_ManufactureDate[4];
ubyte OBDII_InOut_CtlBuf[10]={0};
ubyte OBDII_InOut_ReturnBuf[10]={0};
ubyte OBDII_flgTestRecOp=0;
ubyte OBDII_valAgingAllow=40;

void StartDiagnosticSession_Process(void)  //10
{
  ubyte UDS_stDiagSeon_LO = 0;
  ubyte OBD_stRequestResult=0;
  OBDII_TP_stEffService.lSendCnt=0;
  OBDII_TP_stEffService.valWrongCode=0;
  UDS_stDiagSeon_LO = OBDII_TP_stEffService.TP_valRecBuf_MP[0];
  if(OBDII_TP_stEffService.lServiceR==0x02)
  {
    OBD_stRequestResult=TRUE;
  }
  else
  {
    OBDII_TP_stEffService.valWrongCode=Incorrect_Message_Length_Or_Invalid_Format;
    OBDII_Neg_Response();
  }
  if(OBD_stRequestResult==TRUE)
  {
    OBD_stRequestResult=FALSE;
    if((UDS_stDiagSeon_LO==0x01)||(UDS_stDiagSeon_LO==0x02)||(UDS_stDiagSeon_LO==0x03)
    	||(UDS_stDiagSeon_LO==0x81)||(UDS_stDiagSeon_LO==0x82)||(UDS_stDiagSeon_LO==0x83))
    {
      OBD_stRequestResult=TRUE;
    }
    else
    {
        OBDII_TP_stEffService.valWrongCode=Sub_Function_Not_Supported;
        OBDII_Neg_Response();
    }
  }
  if(OBD_stRequestResult==TRUE)
  {
    OBD_stRequestResult=FALSE;
    OBD_stRequestResult=OBDII_CallBack_SessionCtl_Condition(UDS_stDiagSeon,UDS_stDiagSeon_LO);
    if(OBD_stRequestResult==FALSE)
    {
       OBDII_TP_stEffService.valWrongCode=Conditions_Not_Correct;
       OBDII_Neg_Response();
    }
  }
  if(OBD_stRequestResult==TRUE)
  {
	  UDS_ValSecLev = 0;
	  UDS_ValSecLev_last= 0;
	  TP_stSecurityState_MP=0;
      UDS_stDiagSeon = UDS_stDiagSeon_LO&0x0F;
      UDS_tiDiagSeon = 0;
    if((UDS_stDiagSeon_LO==0x01)||(UDS_stDiagSeon_LO==0x02)||(UDS_stDiagSeon_LO==0x03))
      {
        OBDII_TP_stEffService.TP_valSendBuf_MP[OBDII_TP_stEffService.lSendCnt]= UDS_stDiagSeon;
		OBDII_TP_stEffService.lSendCnt++;
		OBDII_TP_stEffService.TP_valSendBuf_MP[OBDII_TP_stEffService.lSendCnt]=(P2Server>>8)&0xFF;
		OBDII_TP_stEffService.lSendCnt++;
		OBDII_TP_stEffService.TP_valSendBuf_MP[OBDII_TP_stEffService.lSendCnt]=P2Server&0xFF;
		OBDII_TP_stEffService.lSendCnt++;
		OBDII_TP_stEffService.TP_valSendBuf_MP[OBDII_TP_stEffService.lSendCnt]=(P2_Server>>8)&0xFF;
		OBDII_TP_stEffService.lSendCnt++;
		OBDII_TP_stEffService.TP_valSendBuf_MP[OBDII_TP_stEffService.lSendCnt]=P2_Server&0xFF;
		OBDII_TP_stEffService.lSendCnt++;
		OBDII_TP_stEffService.lServiceS=OBDII_TP_stEffService.lSendCnt;
        OBDII_Send_ResPonsReqdata();
        OBDII_CallBack_Current_DiagSession(UDS_stDiagSeon);
      }
      if((UDS_stDiagSeon_LO==0x01)||(UDS_stDiagSeon_LO==0x81))
      {
          UDS_stCtlDTC=0x01;
          CANSendForbid_st=0;
          CANRecForbid_st=0;
      }

      OBDII_CallBack_ResetRountine_Execute();
      OBDII_VauRcRecor.OBDII_numRecordRC_Mp=0xff;
      OBDII_VauRcRecor.OBDII_stExcRcSession=UDS_stDiagSeon;
      OBDII_VauRcRecor.OBDII_stExcReturnValue=0;
      OBDII_VauRcRecor.OBDII_flagExcStartRc=0;
  }
}
void EcuReset_Process(void) //11
{
	uword delay_i;
    ubyte UDS_stResetMode_LO=0;
    ubyte OBD_stRequestResult=0;
    UDS_stResetMode_LO=OBDII_TP_stEffService.TP_valRecBuf_MP[0];
    OBDII_TP_stEffService.lSendCnt=0;
    OBDII_TP_stEffService.valWrongCode=0;

    if((OBDII_Service_demondLst[OBDII_TP_stEffService.TP_posSevice].SupDiagSesnD_Or_Not==UDS_stDiagSeon)
 	 ||(OBDII_Service_demondLst[OBDII_TP_stEffService.TP_posSevice].SupDiagSesnP_Or_Not==UDS_stDiagSeon)
 	 ||(OBDII_Service_demondLst[OBDII_TP_stEffService.TP_posSevice].SupDiagSesnE_Or_Not==UDS_stDiagSeon))
    {
	   OBD_stRequestResult=TRUE;
    }
    else
    {
	   OBDII_TP_stEffService.valWrongCode=ServiceNotSupportedInActiveSession;
	   OBDII_Neg_Response();
    }
    if(OBD_stRequestResult==TRUE)
    {
	   OBD_stRequestResult=FALSE;
	    if(OBDII_TP_stEffService.lServiceR==0x02)
	    {
	    	OBD_stRequestResult=TRUE;
	    }
	    else
	    {
	    	 OBDII_TP_stEffService.valWrongCode=Incorrect_Message_Length_Or_Invalid_Format;
	    	 OBDII_Neg_Response();
	    }
    }
    if(OBD_stRequestResult==TRUE)
    {
    	 OBD_stRequestResult=FALSE;
    	 if((UDS_stResetMode_LO==0x01)||(UDS_stResetMode_LO==0x02)||(UDS_stResetMode_LO==0x03)
    		||(UDS_stResetMode_LO==0x81)||(UDS_stResetMode_LO==0x82)||(UDS_stResetMode_LO==0x83))
    	 {
    		 OBD_stRequestResult=TRUE;
    	 }
    	 else
    	 {
    		 OBDII_TP_stEffService.valWrongCode=Sub_Function_Not_Supported;
    		 OBDII_Neg_Response();
    	 }
    }
    if(OBD_stRequestResult==TRUE)
    {
    	OBD_stRequestResult=OBDII_CallBack_EcuReset_Condition();
    	if(OBD_stRequestResult==FALSE)
    	{
    		OBDII_TP_stEffService.valWrongCode=Conditions_Not_Correct;
    		OBDII_Neg_Response();
    	}
    }
   if(OBD_stRequestResult==TRUE)
   {
	   OBD_stRequestResult=FALSE;
	   if((OBDII_Service_demondLst[OBDII_TP_stEffService.TP_posSevice].Secu_Lev==Security_Level0)
		||(OBDII_Service_demondLst[OBDII_TP_stEffService.TP_posSevice].Secu_Lev==UDS_ValSecLev))
	   {
		  OBD_stRequestResult=TRUE;
	   }
	   else
	   {
		  OBDII_TP_stEffService.valWrongCode=Security_Access_Denied;
		  OBDII_Neg_Response();
	   }
   }
   if(OBD_stRequestResult==TRUE)
  {
	   UDS_ValSecLev=0;
	   UDS_ValSecLev_last = 0;
	   if((UDS_stResetMode_LO==0x81)||(UDS_stResetMode_LO==0x82)||(UDS_stResetMode_LO==0x83))
	   {
		   OBDII_CallBack_EcuReset_Execute(UDS_stResetMode_LO&0x0f);
	   }
	   if((UDS_stResetMode_LO==0x01)||(UDS_stResetMode_LO==0x02)||(UDS_stResetMode_LO==0x03))
	   {
		   OBDII_TP_stEffService.TP_valSendBuf_MP[OBDII_TP_stEffService.lSendCnt]=UDS_stResetMode_LO;
		   OBDII_TP_stEffService.lSendCnt++;
		   OBDII_TP_stEffService.lServiceS=OBDII_TP_stEffService.lSendCnt;
		   OBDII_Send_ResPonsReqdata();
		   for(delay_i=0;delay_i<35565;delay_i++)
		   {

		   }
		   OBDII_CallBack_EcuReset_Execute(UDS_stResetMode_LO&0x0f);
	   }
  }
}
void ClearDiagnosticInformation_Process(void)  //14
{
	ubyte OBD_stRequestResult=0;
	ubyte CDI_i;
	ubyte CDI_m,CDI_n,CDI_k,CDI_j;
	ubyte CDI_fgFbClrByTool=0;
	ubyte CDI_numPosClear=0xff;
	OBDII_TP_stEffService.lSendCnt=0;
	OBDII_TP_stEffService.valWrongCode=0;
	 if((OBDII_Service_demondLst[OBDII_TP_stEffService.TP_posSevice].SupDiagSesnD_Or_Not==UDS_stDiagSeon)
	  ||(OBDII_Service_demondLst[OBDII_TP_stEffService.TP_posSevice].SupDiagSesnP_Or_Not==UDS_stDiagSeon)
	  ||(OBDII_Service_demondLst[OBDII_TP_stEffService.TP_posSevice].SupDiagSesnE_Or_Not==UDS_stDiagSeon))
	 {
		OBD_stRequestResult=TRUE;
	 }
	 else
	 {
		OBDII_TP_stEffService.valWrongCode=ServiceNotSupportedInActiveSession;
		OBDII_Neg_Response();
	 }
	if(OBD_stRequestResult==TRUE)
	 {
		 OBD_stRequestResult=FALSE;
		 if(OBDII_TP_stEffService.lServiceR==4)
		 {
			 OBD_stRequestResult=TRUE;
		 }
		 else
		 {
			 OBDII_TP_stEffService.valWrongCode=Incorrect_Message_Length_Or_Invalid_Format;
			 OBDII_Neg_Response();
		 }
	 }
	if(OBD_stRequestResult==TRUE)
	{
		OBD_stRequestResult=FALSE;

		for(CDI_i = 0; CDI_i < (OBDII_DTC_TABLE_SIZE); CDI_i++)
		{
			if((OBDII_TP_stEffService.TP_valRecBuf_MP[0]==(ubyte)(OBDII_DTC_Lst[CDI_i].DTCVAL>>16))
				&&(OBDII_TP_stEffService.TP_valRecBuf_MP[1]==(ubyte)(OBDII_DTC_Lst[CDI_i].DTCVAL>>8))
				&&(OBDII_TP_stEffService.TP_valRecBuf_MP[2]==(ubyte)(OBDII_DTC_Lst[CDI_i].DTCVAL)))
			{

			  OBD_stRequestResult=TRUE;
			  CDI_numPosClear=CDI_i;
			}
		}
		if((OBDII_TP_stEffService.TP_valRecBuf_MP[0]==0xff)&&(OBDII_TP_stEffService.TP_valRecBuf_MP[1]==0xff)&&(OBDII_TP_stEffService.TP_valRecBuf_MP[2]==0xff))
		{
			OBD_stRequestResult=TRUE;
			CDI_numPosClear=0xff;
		}
		if(OBD_stRequestResult==FALSE)
		{
			OBDII_TP_stEffService.valWrongCode=Request_Out_Of_Range;
			OBDII_Neg_Response();
		}
	}
	if(OBD_stRequestResult==TRUE)
	{
		OBD_stRequestResult=OBDII_CallBack_ClearDTC_Condition();
    	if(OBD_stRequestResult==FALSE)
    	{
    		OBDII_TP_stEffService.valWrongCode=Conditions_Not_Correct;
    		OBDII_Neg_Response();
    	}
	}
	 if(OBD_stRequestResult==TRUE)
	 {
		 OBD_stRequestResult=FALSE;
		 if((OBDII_Service_demondLst[OBDII_TP_stEffService.TP_posSevice].Secu_Lev==Security_Level0)
			||(OBDII_Service_demondLst[OBDII_TP_stEffService.TP_posSevice].Secu_Lev==UDS_ValSecLev))
		 {
			OBD_stRequestResult=TRUE;
		 }
		 else
		 {
			OBDII_TP_stEffService.valWrongCode=Security_Access_Denied;
			OBDII_Neg_Response();
		 }
	 }
	if((OBD_stRequestResult==TRUE)&&(CDI_numPosClear==0xff)&&(DTC_st_errNum != ((Dtcst_CSTR*)0))&&(OBDII_DTC_SnapshotList != ((Snapshot_ofDTC*)0)))
	{
		for(CDI_i = 0; CDI_i < (OBDII_DTC_TABLE_SIZE); CDI_i++)
		{
		    CDI_fgFbClrByTool=FALSE;
            if(OBDII_DTC_Lst[CDI_i].ForbidClear==CanClearByTool)
            {
			  CDI_fgFbClrByTool=TRUE;
            }
			if((DTC_st_errNum != ((Dtcst_CSTR*)0))&&(CDI_fgFbClrByTool==TRUE))
			{
				DTC_st_errNum[CDI_i].Status=0;
				DTC_st_errNum[CDI_i].ErrNum=0;
				DTC_st_errNum[CDI_i].ErrOnce=0;
				DTC_st_errNum[CDI_i].ErrKeep=0;
				DTC_st_errNum[CDI_i].Status|=0x50;//set bit4 to 0 test not completed since last clear
				                                  //set bit6 to 0 test not completed this operation cycle
				DTC_st_errNum[CDI_i].ErrNumCycle=0;
				DTC_st_errNum[CDI_i].Operation_flgCycle=1;
			}
		}
		for(CDI_k = 0; CDI_k < (OBDII_DTC_SaveSnapshot_SIZE); CDI_k++)
		{
			for(CDI_m = 0; CDI_m < (OBDII_DTC_SupportSnapshot_SIZE); CDI_m++)
			{
	          if(OBDII_DTC_SnapshotList[CDI_m].DTC_SupportSnapshot.DTCVAL==OBDII_EE_DATA.DTCVAL[CDI_k])
	          {
				  if(OBDII_DTC_SnapshotList[CDI_m].DTC_SupportSnapshot.ForbidClear==CanClearByTool)
					{

						for(CDI_n = 0; CDI_n < OBDII_A_DTC_SnapshotDID_MAXNum; CDI_n++)
						{
							OBDII_EE_DATA.EE_ValSnapshot[CDI_k*OBDII_A_DTC_SnapshotDID_MAXNum+CDI_n]=0;
						}
						for(CDI_n = 0; CDI_n < OBDII_A_DTC_SnapshotExt_MAXNum; CDI_n++)
						{
							OBDII_EE_DATA.EE_ValExtended[CDI_k*OBDII_A_DTC_SnapshotExt_MAXNum+CDI_n]=0;
						}
					}
	          }
			}
		}

		OBDII_TP_stEffService.lServiceS=0;
		OBDII_Send_ResPonsReqdata();

		OBDII_CallBack_ClearAllDTC_Execute();

	}
	if((OBD_stRequestResult==TRUE)&&(CDI_numPosClear!=0xff)&&(DTC_st_errNum != ((Dtcst_CSTR*)0))&&((OBDII_DTC_SnapshotList != ((Snapshot_ofDTC*)0))))
	{
	    CDI_fgFbClrByTool=FALSE;
        if(OBDII_DTC_Lst[CDI_numPosClear].ForbidClear==CanClearByTool)
		{
        	CDI_fgFbClrByTool=TRUE;
		}
		if((DTC_st_errNum != ((Dtcst_CSTR*)0))&&(CDI_fgFbClrByTool==TRUE))
		{
			DTC_st_errNum[CDI_numPosClear].Status=0;
			DTC_st_errNum[CDI_numPosClear].ErrNum=0;
			DTC_st_errNum[CDI_numPosClear].ErrOnce=0;
			DTC_st_errNum[CDI_numPosClear].ErrKeep=0;
			DTC_st_errNum[CDI_numPosClear].Status|=0x50;
		}
        for(CDI_m = 0; CDI_m < (OBDII_DTC_SupportSnapshot_SIZE); CDI_m++)
		{
            if(((ubyte)(OBDII_DTC_SnapshotList[CDI_m].DTC_SupportSnapshot.DTCVAL>>16)==OBDII_TP_stEffService.TP_valRecBuf_MP[0])
				&&((ubyte)(OBDII_DTC_SnapshotList[CDI_m].DTC_SupportSnapshot.DTCVAL>>8)==OBDII_TP_stEffService.TP_valRecBuf_MP[1])
				&&((ubyte)(OBDII_DTC_SnapshotList[CDI_m].DTC_SupportSnapshot.DTCVAL)==OBDII_TP_stEffService.TP_valRecBuf_MP[2])
				&&(OBDII_DTC_SnapshotList[CDI_m].DTC_SupportSnapshot.ForbidClear==CanClearByTool))
            	{
            	   CDI_j=CDI_m;
            	}
		}
        for(CDI_k = 0; CDI_k < (OBDII_DTC_SaveSnapshot_SIZE); CDI_k++)
		{
		  if(OBDII_DTC_SnapshotList[CDI_j].DTC_SupportSnapshot.DTCVAL==OBDII_EE_DATA.DTCVAL[CDI_k])
		  {

			for(CDI_n = 0; CDI_n < OBDII_A_DTC_SnapshotDID_MAXNum; CDI_n++)
			{
				OBDII_EE_DATA.EE_ValSnapshot[CDI_k*OBDII_A_DTC_SnapshotDID_MAXNum+CDI_n]=0;
			}
			for(CDI_n = 0; CDI_n < OBDII_A_DTC_SnapshotExt_MAXNum; CDI_n++)
			{
				OBDII_EE_DATA.EE_ValExtended[CDI_k*OBDII_A_DTC_SnapshotExt_MAXNum+CDI_n]=0;
			}
		  }
		}
        OBDII_TP_stEffService.lServiceS=0;
        OBDII_Send_ResPonsReqdata();
     	OBDII_CallBack_ClearSpecialDTC_Execute(OBDII_DTC_Lst[CDI_numPosClear].DTCVAL,0);
	}

}
void OBDII_CallAutoClearSpecialDTC(uint32 DTC_Val)
{
	ubyte CDI_i=0;
	ubyte CDI_m=0;
	ubyte CDI_n=0;
	for(CDI_i = 0; CDI_i < (OBDII_DTC_TABLE_SIZE); CDI_i++)
	{
		if((OBDII_DTC_Lst[CDI_i].DTCVAL&0xffffff)==DTC_Val)
		{
		   DTC_st_errNum[CDI_i].Status&=0x53;//set bit3 to 0 confirmed dtc
		   DTC_st_errNum[CDI_i].ErrNum=0;
		}
	}
	if(OBDII_DTC_SnapshotList != ((Snapshot_ofDTC*)0))
	{
		for(CDI_m = 0; CDI_m < (OBDII_DTC_SupportSnapshot_SIZE); CDI_m++)
		{
			if(((OBDII_DTC_SnapshotList[CDI_m].DTC_SupportSnapshot.DTCVAL)==DTC_Val))
			{
			     CDI_i=CDI_m;
			}
		}
		for(CDI_m = 0; CDI_m < (OBDII_DTC_SaveSnapshot_SIZE); CDI_m++)
		{
			if(OBDII_DTC_SnapshotList[CDI_i].DTC_SupportSnapshot.DTCVAL==OBDII_EE_DATA.DTCVAL[CDI_m])
			{

			   for(CDI_n = 0; CDI_n < OBDII_A_DTC_SnapshotDID_MAXNum; CDI_n++)
			   {
				  OBDII_EE_DATA.EE_ValSnapshot[CDI_m*OBDII_A_DTC_SnapshotDID_MAXNum+CDI_n]=0;

			   }
			   for(CDI_n = 0; CDI_n < OBDII_A_DTC_SnapshotExt_MAXNum; CDI_n++)
				{
					OBDII_EE_DATA.EE_ValExtended[CDI_m*OBDII_A_DTC_SnapshotExt_MAXNum+CDI_n]=0;
				}
			   OBDII_CallBack_ClearSpecialDTC_Execute(DTC_Val,1);
			}
		}
	}

}
void ReadDTCInfor_Process(void)  //19
{
	ubyte OBD_stRequestResult=0;
	OBDII_TP_stEffService.lSendCnt=0;
	OBDII_TP_stEffService.valWrongCode=0;
	 if((OBDII_Service_demondLst[OBDII_TP_stEffService.TP_posSevice].SupDiagSesnD_Or_Not==UDS_stDiagSeon)
	  ||(OBDII_Service_demondLst[OBDII_TP_stEffService.TP_posSevice].SupDiagSesnP_Or_Not==UDS_stDiagSeon)
	  ||(OBDII_Service_demondLst[OBDII_TP_stEffService.TP_posSevice].SupDiagSesnE_Or_Not==UDS_stDiagSeon))
	 {
		OBD_stRequestResult=TRUE;
	 }
	 else
	 {
		OBDII_TP_stEffService.valWrongCode=ServiceNotSupportedInActiveSession;
		OBDII_Neg_Response();
	 }
	if(OBD_stRequestResult==TRUE)
	 {
		 OBD_stRequestResult=FALSE;
			if(OBDII_TP_stEffService.lServiceR>=2)
			{
				OBD_stRequestResult=TRUE;
			}
			else
			{
				OBDII_TP_stEffService.valWrongCode=Incorrect_Message_Length_Or_Invalid_Format;
				OBDII_Neg_Response();
			}
	 }
	 if(OBD_stRequestResult==TRUE)
	 {
		 OBD_stRequestResult=FALSE;
		 if((OBDII_Service_demondLst[OBDII_TP_stEffService.TP_posSevice].Secu_Lev==Security_Level0)
			||(OBDII_Service_demondLst[OBDII_TP_stEffService.TP_posSevice].Secu_Lev==UDS_ValSecLev))
		 {
			OBD_stRequestResult=TRUE;
		 }
		 else
		 {
			OBDII_TP_stEffService.valWrongCode=Security_Access_Denied;
			OBDII_Neg_Response();
		 }
	 }

	if((OBD_stRequestResult==TRUE)&&( OBDII_DTC_Lst!= ((DtcType_CSTR*)0))&&(DTC_st_errNum != ((Dtcst_CSTR*)0)))
	{

		 switch (OBDII_TP_stEffService.TP_valRecBuf_MP[0])
		 {
			case 0x01:
			{
				ReportNumOfDTCbyStsMsk();
				break;
			}
			case 0x02:
			{
				ReportDTCbyStsMsk();
				break;
			}
			case 0x03:
			{
				ReportDtcSnapshotid();
				break;
			}
			case 0x04:
			{
				ReportDtcSnapshotByDTCnum();
				break;
			}
			case 0x05:
			{
				ReportDtcSnapshotByRecordNumber();
				break;
			}
			case 0x06:
			{
				ReportDtcExtendDataRecordByDTCnumber();
				break;
			}
			case 0x07:
			{
				ReportNumberOfDtcBySeverityMaskRecord();
				break;
			}
			case 0x08:
			{
				ReportDtcBySeverityMaskRecord();
				break;
			}
			case 0x09:
			{
				ReportSeverityInformOfDTC();
				break;
			}
			case 0x0A:
			{
				ReportSuppedDTC();
				break;
			}
			case 0X0B:
			{
				ReportFirstTestFailedDTC();
				break;
			}
			case 0X0C:
			{
				ReportFirstCofirmedDTC();
				break;
			}
			case 0X15:
			{
				ReportDTCWithPermanentStatus();
				break;
			}
			default:
			{
				if(CI_flgDTCFunAddrVaild_MP == FALSE)
				{
					OBDII_TP_stEffService.valWrongCode=Sub_Function_Not_Supported;
					OBDII_Neg_Response();
				}
				break;
			}
		}
	}
}

void ReadDataByIdentifier_Process(void)  //22
{
	uword OBD_valPid_LO=0;
	ubyte check_NoPass = 0;
	ubyte check_num = 0;
	ubyte OBD_stRequestResult=0;
	uword RDBI_k = 0,RDBI_j=0;
	uword RDBI_m = 0,RDBI_n = 0,RDBI_q = 0;
	OBDII_TP_stEffService.lSendCnt=0;
	OBDII_TP_stEffService.valWrongCode=0;
	 if((OBDII_Service_demondLst[OBDII_TP_stEffService.TP_posSevice].SupDiagSesnD_Or_Not==UDS_stDiagSeon)
	  ||(OBDII_Service_demondLst[OBDII_TP_stEffService.TP_posSevice].SupDiagSesnP_Or_Not==UDS_stDiagSeon)
	  ||(OBDII_Service_demondLst[OBDII_TP_stEffService.TP_posSevice].SupDiagSesnE_Or_Not==UDS_stDiagSeon))
	 {
		OBD_stRequestResult=TRUE;
	 }
	 else
	 {
		OBDII_TP_stEffService.valWrongCode=ServiceNotSupportedInActiveSession;
		OBDII_Neg_Response();
	 }
	 if(OBD_stRequestResult==TRUE)
	 {
		 OBD_stRequestResult=FALSE;
		 if((OBDII_TP_stEffService.lServiceR>=3)&&(((OBDII_TP_stEffService.lServiceR-1)%2) == 0))
		 {
			 OBD_stRequestResult=TRUE;
		 }
		 else
		 {
			 OBDII_TP_stEffService.valWrongCode=Incorrect_Message_Length_Or_Invalid_Format;
			 OBDII_Neg_Response();
		 }
	 }
	 if(OBD_stRequestResult==TRUE)
	 {
		OBD_stRequestResult=OBDII_CallBack_ReadDATAbyID_Condition();
		if(OBD_stRequestResult==FALSE)
		{
			OBDII_TP_stEffService.valWrongCode=Conditions_Not_Correct;
			OBDII_Neg_Response();
		}
	 }

	 if(OBD_stRequestResult==TRUE)
	 {
		 OBD_stRequestResult=FALSE;
		 if((OBDII_Service_demondLst[OBDII_TP_stEffService.TP_posSevice].Secu_Lev==Security_Level0)
		  ||(OBDII_Service_demondLst[OBDII_TP_stEffService.TP_posSevice].Secu_Lev==UDS_ValSecLev))
		 {
			OBD_stRequestResult=TRUE;
		 }
		 else
		 {
			OBDII_TP_stEffService.valWrongCode=Security_Access_Denied;
			OBDII_Neg_Response();
		 }
	 }
	 if(OBD_stRequestResult==TRUE)
	 {
		OBD_stRequestResult=FALSE;
	    if(OBDII_DD_PidLst!= ((DiagData_CSTR*)0))
	    {
	    	OBD_stRequestResult=TRUE;
	    }
	 }
	 if(OBD_stRequestResult==TRUE)
	 {
		 OBD_stRequestResult=FALSE;
		 for(RDBI_m=1;RDBI_m<OBDII_TP_stEffService.lServiceR;)
		 {
			 OBD_valPid_LO=OBDII_TP_stEffService.TP_valRecBuf_MP[RDBI_m-1]*256+OBDII_TP_stEffService.TP_valRecBuf_MP[RDBI_m];
			 for(RDBI_n = 0; RDBI_n<OBDII_PID_TABLE_SIZE;RDBI_n++)
			 {
				 if((OBDII_DD_PidLst[RDBI_n].DiagFid == OBD_valPid_LO))
				 {
					  if(((UDS_stDiagSeon==Default_Session)&&(OBDII_DD_PidLst[RDBI_n].VehDataDSessionRW==SupRead))
						||((UDS_stDiagSeon==Program_Session)&&(OBDII_DD_PidLst[RDBI_n].VehDataPSessionRW==SupRead))
						||((UDS_stDiagSeon==Extended_Session)&&(OBDII_DD_PidLst[RDBI_n].VehDataESessionRW==SupRead)))
					  {
						OBD_stRequestResult=TRUE;
					  }
				 }
			 }
			 if(OBD_Veh_InfLst!= ((VehData_CSTR*)0))

			 {
				 for(RDBI_q = 0; RDBI_q<OBDII_Veh_Data_SIZE;RDBI_q++)
				 {
					 if(OBD_Veh_InfLst[RDBI_q].VehDataFid == OBD_valPid_LO)
					 {
						 OBD_stRequestResult=TRUE;
					 }
				 }
			 }
			 RDBI_m=RDBI_m+2;
		 }
		 if(OBD_stRequestResult==FALSE)
		 {
				OBDII_TP_stEffService.valWrongCode=Request_Out_Of_Range;
				OBDII_Neg_Response();
				check_NoPass=1;
		 }
	 }
	if((OBD_stRequestResult==TRUE)&&(check_NoPass==0))
	{
	   for(RDBI_k=1;RDBI_k<OBDII_TP_stEffService.lServiceR;)
	   {
		   OBD_valPid_LO=OBDII_TP_stEffService.TP_valRecBuf_MP[RDBI_k-1]*256+OBDII_TP_stEffService.TP_valRecBuf_MP[RDBI_k];
		   OBDII_DataService_Updata(OBD_valPid_LO);
		   OBD_stRequestResult=Requestvehicleinfor_process(OBD_valPid_LO);
		   if(OBD_stRequestResult==0)
		   {

				for (RDBI_j = 0; RDBI_j < (OBDII_PID_TABLE_SIZE); RDBI_j++)
				{
					   if(OBDII_DD_PidLst[RDBI_j].DiagFid==OBD_valPid_LO)
					   {
							 check_num+=1;
							 OBDII_TP_stEffService.TP_valSendBuf_MP[OBDII_TP_stEffService.lSendCnt]=OBD_valPid_LO/256;
							 OBDII_TP_stEffService.lSendCnt++;
							 OBDII_TP_stEffService.TP_valSendBuf_MP[OBDII_TP_stEffService.lSendCnt]=OBD_valPid_LO%256;
							 OBDII_TP_stEffService.lSendCnt++;
							 switch(OBDII_DD_PidLst[RDBI_j].DiagDatalen)
							 {
								   case 1:
								   OBDII_TP_stEffService.TP_valSendBuf_MP[OBDII_TP_stEffService.lSendCnt]=OBDII_DD_PidLst[RDBI_j].DiagVal1;
								   OBDII_TP_stEffService.lSendCnt++;
									   break;
								   case 2:
								   OBDII_TP_stEffService.TP_valSendBuf_MP[OBDII_TP_stEffService.lSendCnt]=OBDII_DD_PidLst[RDBI_j].DiagVal1;
								   OBDII_TP_stEffService.lSendCnt++;
								   OBDII_TP_stEffService.TP_valSendBuf_MP[OBDII_TP_stEffService.lSendCnt]=OBDII_DD_PidLst[RDBI_j].DiagVal2;
								   OBDII_TP_stEffService.lSendCnt++;
									   break;
							 }
					   }
				 }
		   }
		   else
		   {
			   check_num+=1;
		   }
		   RDBI_k=RDBI_k+2;
	   }
	   if(check_num>0)
	   {
		 OBDII_TP_stEffService.lServiceS=OBDII_TP_stEffService.lSendCnt;
		 OBDII_Send_ResPonsReqdata();
		 check_num=0;
	   }
		else
	     {
			   OBDII_TP_stEffService.valWrongCode=Request_Out_Of_Range;
			   OBDII_Neg_Response();
	     }
	 }
}
void ReadMemoryByAddress_Process(void) //23
{
	uword RMBA_valaddressH_LO;
	uword RMBA_valaddressL_LO;
	uword RMBA_valaddress_LO;
	ubyte RMBA_valsize_LO;
	ubyte RMBA_laddress_LO;
	ubyte RMBA_lsize_LO;
	ubyte OBD_stRequestResult;
	OBDII_TP_stEffService.lSendCnt=0;
	OBDII_TP_stEffService.valWrongCode=0;
	RMBA_laddress_LO=OBDII_TP_stEffService.TP_valRecBuf_MP[0]&0x0f;
	RMBA_lsize_LO=(OBDII_TP_stEffService.TP_valRecBuf_MP[0]&0xf0)>>4;

	RMBA_valaddressH_LO=OBDII_TP_stEffService.TP_valRecBuf_MP[2]*256+OBDII_TP_stEffService.TP_valRecBuf_MP[1];
	RMBA_valaddressL_LO=OBDII_TP_stEffService.TP_valRecBuf_MP[4]*256+OBDII_TP_stEffService.TP_valRecBuf_MP[3];
	RMBA_valaddress_LO=RMBA_valaddressH_LO*65536+RMBA_valaddressL_LO;
	RMBA_valsize_LO=OBDII_TP_stEffService.TP_valRecBuf_MP[6]*256+OBDII_TP_stEffService.TP_valRecBuf_MP[5];

	 if((UDS_stDiagSeon== OBDII_Service_demondLst[OBDII_TP_stEffService.TP_posSevice].SupDiagSesnD_Or_Not)
	  ||(UDS_stDiagSeon== OBDII_Service_demondLst[OBDII_TP_stEffService.TP_posSevice].SupDiagSesnP_Or_Not)
	 ||(UDS_stDiagSeon== OBDII_Service_demondLst[OBDII_TP_stEffService.TP_posSevice].SupDiagSesnE_Or_Not))
	 {
		OBD_stRequestResult=TRUE;
	 }
	 else
	 {
		OBDII_TP_stEffService.valWrongCode=ServiceNotSupportedInActiveSession;
		OBDII_Neg_Response();
	 }
	  if(OBD_stRequestResult==TRUE)
	 {
		 OBD_stRequestResult=FALSE;
			if((OBDII_TP_stEffService.lServiceR>=4)&&(OBDII_TP_stEffService.lServiceR == (2+RMBA_laddress_LO+RMBA_lsize_LO)))
			 {
				 OBD_stRequestResult=TRUE;
			 }
			 else
			 {
				 OBDII_TP_stEffService.valWrongCode=Incorrect_Message_Length_Or_Invalid_Format;
				 OBDII_Neg_Response();
			 }
	 }
		 if(OBD_stRequestResult==TRUE)
		 {
				OBD_stRequestResult=FALSE;
				if((RMBA_valaddress_LO>=Memory_start)&&(RMBA_valaddress_LO<=Memory_end))
				{
					OBD_stRequestResult=TRUE;
				}
				else
				{
					OBDII_TP_stEffService.valWrongCode=Request_Out_Of_Range;
					OBDII_Neg_Response();
				}
		 }
	 if(OBD_stRequestResult==TRUE)
	   {
		   OBD_stRequestResult=OBDII_CallBack_ReadMemory_Condition();
	    	if(OBD_stRequestResult==TRUE)
	    	{
	    		OBD_stRequestResult=TRUE;
	    	}
	    	else
	    	{
	    		OBDII_TP_stEffService.valWrongCode=Conditions_Not_Correct;
	    		OBDII_Neg_Response();
	    	}
	   }
	 if(OBD_stRequestResult==TRUE)
	 {
		 OBD_stRequestResult=FALSE;
		 if((OBDII_Service_demondLst[OBDII_TP_stEffService.TP_posSevice].Secu_Lev==Security_Level0)
			||(OBDII_Service_demondLst[OBDII_TP_stEffService.TP_posSevice].Secu_Lev==UDS_ValSecLev))
		 {
			OBD_stRequestResult=TRUE;
		 }
		 else
		 {
			OBDII_TP_stEffService.valWrongCode=Security_Access_Denied;
			OBDII_Neg_Response();
		 }
	 }
	 if(OBD_stRequestResult==TRUE)
	 {
		 OBDII_CallBack_ReadMemory_Execute(RMBA_valaddress_LO,RMBA_valsize_LO);
		 OBDII_TP_stEffService.lServiceS=OBDII_TP_stEffService.lSendCnt;
		 OBDII_Send_ResPonsReqdata();
	 }

}
void SecurityAccess_Process(void)  //27
{

  ubyte rec_key[4];
  ubyte Security_Level1_key;
  ubyte Security_Level2_key;
  ubyte UDS_ValSecLev_LO = 0;
  ubyte OBD_stRequestResult=0;
  ubyte SecurAcce_i =0,SecurAcce_j =0;
  UDS_ValSecLev_LO=OBDII_TP_stEffService.TP_valRecBuf_MP[0];
  OBDII_TP_stEffService.lSendCnt=0;
  OBDII_TP_stEffService.valWrongCode=0;

  if((OBDII_Service_demondLst[OBDII_TP_stEffService.TP_posSevice].SupDiagSesnD_Or_Not==UDS_stDiagSeon)
   ||(OBDII_Service_demondLst[OBDII_TP_stEffService.TP_posSevice].SupDiagSesnP_Or_Not==UDS_stDiagSeon)
   ||(OBDII_Service_demondLst[OBDII_TP_stEffService.TP_posSevice].SupDiagSesnE_Or_Not==UDS_stDiagSeon))
  {
	 OBD_stRequestResult=TRUE;
  }
  else
  {
	 OBDII_TP_stEffService.valWrongCode=ServiceNotSupportedInActiveSession;
	 OBDII_Neg_Response();
  }
  if(OBD_stRequestResult==TRUE)
  {
      OBD_stRequestResult=FALSE;
      if((OBDII_TP_stEffService.lServiceR==0x02)||(OBDII_TP_stEffService.lServiceR==(0x02+UDS_Valseed.key_size)))
    	{
    	   OBD_stRequestResult=TRUE;
    	}
    	else
    	{
    	   OBDII_TP_stEffService.valWrongCode=Incorrect_Message_Length_Or_Invalid_Format;
    	   OBDII_Neg_Response();
    	}
  }
  if(OBD_stRequestResult==TRUE)
   {
   	  OBD_stRequestResult=FALSE;
   	if((UDS_ValSecLev_LO==Security_lib_Level1)||(UDS_ValSecLev_LO==Security_lib_Level1+1)||(UDS_ValSecLev_LO==Security_lib_Level2)||(UDS_ValSecLev_LO==Security_lib_Level2+1))
  	  {
  		  OBD_stRequestResult=TRUE;
  	  }
  	  else
  	  {
  		  OBDII_TP_stEffService.valWrongCode=Sub_Function_Not_Supported;
  		  OBDII_Neg_Response();
  	  }
   }
  if(OBD_stRequestResult==TRUE)
    {
 	  OBD_stRequestResult=FALSE;
 	  if(((OBDII_TP_stEffService.lServiceR==0x02)&&(UDS_ValSecLev_LO%2==1))||((OBDII_TP_stEffService.lServiceR==(0x02+UDS_Valseed.key_size))&&(UDS_ValSecLev_LO%2==0)))
 	  {
 		  OBD_stRequestResult=TRUE;
 	  }
 	  else
 	  {
 		  OBDII_TP_stEffService.valWrongCode=Incorrect_Message_Length_Or_Invalid_Format;
 		  OBDII_Neg_Response();
 	  }
    }
  Security_Level1_key=Security_lib_Level1+1;
  Security_Level2_key=Security_lib_Level2+1;
//  if(OBD_stRequestResult==TRUE)
//   {
// 	  OBD_stRequestResult=FALSE;
// 	  if((((UDS_ValSecLev_LO==Security_Level1)||(UDS_ValSecLev_LO==Security_Level1_key))&&(UDS_stDiagSeon ==Security_Level_Session[0]))
// 	   ||(((UDS_ValSecLev_LO==Security_Level2)||(UDS_ValSecLev_LO==Security_Level2_key))&&(UDS_stDiagSeon ==Security_Level_Session[1])))
// 	   {
// 	         OBD_stRequestResult=TRUE;
// 	   }
// 	  else
// 	  {
// 		 OBDII_TP_stEffService.valWrongCode=SubFunctionNotSupportedInActiveSession;
// 	     OBDII_Neg_Response();
// 	  }
//   }
  if(OBD_stRequestResult==TRUE)
  {
	  OBD_stRequestResult=OBDII_CallBack_Security_Condition();
  	if(OBD_stRequestResult==FALSE)
  	{
  		OBDII_TP_stEffService.valWrongCode=Conditions_Not_Correct;
  		OBDII_Neg_Response();
  	}
  }
  if((OBD_stRequestResult==TRUE)&&(OBDII_flgReqSeedNum==OBDII_TimeSec_Mp.ConSeedRequestNum)&&(OBDII_TimeSec_Mp.ConSeedRequestNum!=0)&&(OBDII_TimeSec_Mp.ConSeedRequesEnable==1))
  {
	  OBD_stRequestResult=FALSE;
	  OBDII_TP_stEffService.valWrongCode=Exceed_N_Of_Attempts;
	  OBDII_Neg_Response();
//	  OBDII_EE_DATA.EE_numEntryfailPoint=OBDII_TimeSec_Mp.InvalidKeyNum;
	  OBDII_flgReqSeedNum=0;
  }
  if((OBD_stRequestResult==TRUE)&&(UDS_ValSecLev_LO%2==1)&&(Security_Timer_Flg==1))
  {
	  OBD_stRequestResult=FALSE;
	  OBDII_TP_stEffService.valWrongCode=Required_T_D_N_Expired;
	  OBDII_Neg_Response();
  }

    if((OBD_stRequestResult==TRUE)&&(UDS_ValSecLev_LO%2==1))
    {
         OBD_stRequestResult=FALSE;
		   if((OBDII_flgReqSeedNum<OBDII_TimeSec_Mp.ConSeedRequestNum)||(OBDII_TimeSec_Mp.ConSeedRequestNum==0))
		   {
			   OBDII_TP_stEffService.TP_valSendBuf_MP[OBDII_TP_stEffService.lSendCnt]=UDS_ValSecLev_LO;
			   OBDII_TP_stEffService.lSendCnt++;
				  if((UDS_ValSecLev_last == (UDS_ValSecLev_LO+1)))
				  {
					  for(SecurAcce_i = 0;SecurAcce_i < UDS_Valseed.seed_size;SecurAcce_i++)
					  {
							 OBDII_TP_stEffService.TP_valSendBuf_MP[OBDII_TP_stEffService.lSendCnt]=0;
							 UDS_Valseed.seed[SecurAcce_i] = 0;
							 OBDII_TP_stEffService.lSendCnt++;
					  }
				  }
				  else
				   {
				       //  if(OBDII_flgReqSeedNum==0)
				         {
				        	 OBDII_CallBack_SecurityAccess_Seed();
				         }
				         for(SecurAcce_i = 0;SecurAcce_i < UDS_Valseed.seed_size;SecurAcce_i++)
				         {
							  OBDII_TP_stEffService.TP_valSendBuf_MP[OBDII_TP_stEffService.lSendCnt]=UDS_Valseed.seed[SecurAcce_i];
							  OBDII_TP_stEffService.lSendCnt++;
				         }
				   }
				OBDII_TP_stEffService.lServiceS=OBDII_TP_stEffService.lSendCnt;
				OBDII_Send_ResPonsReqdata();
				OBDII_CallBack_SecurityAccess_Key(UDS_ValSecLev_LO);
				TP_stSecurityState_MP = 1;
				OBDII_flgReqSeedNum=OBDII_flgReqSeedNum+1;
		   }
    }

    if((OBD_stRequestResult==TRUE)&&(UDS_ValSecLev_LO%2==0))
    {
      OBD_stRequestResult=FALSE;
      OBDII_flgReqSeedNum=0;
	  if(TP_stSecurityState_MP == 1)
	  {
	    OBD_stRequestResult=TRUE;
	    TP_stSecurityState_MP = 0;
	  }
      else
      {
        OBDII_TP_stEffService.valWrongCode=requestSequenceError;
        OBDII_Neg_Response();
      }
      if(OBD_stRequestResult==TRUE)
      {

          for(SecurAcce_j = 0;SecurAcce_j < UDS_Valseed.key_size;SecurAcce_j++)
          {
              rec_key[SecurAcce_j]=OBDII_TP_stEffService.TP_valRecBuf_MP[SecurAcce_j+1];
              if((UDS_Valseed.key[SecurAcce_j])!=(rec_key[SecurAcce_j]))
            	  OBD_stRequestResult=FALSE;
          }
          if(OBD_stRequestResult==FALSE)
		  {

        	  if((*OBDII_EE_DATA.EE_numEntryfailPoint)<OBDII_TimeSec_Mp.InvalidKeyNum-1)
        	  {
    			  OBDII_TP_stEffService.valWrongCode=Invalid_Key;
    			  OBDII_Neg_Response();
            	  *OBDII_EE_DATA.EE_numEntryfailPoint = *OBDII_EE_DATA.EE_numEntryfailPoint + 1;
        	  }
        	  else
        	  {
    			  OBDII_TP_stEffService.valWrongCode=Exceed_N_Of_Attempts;
    			  *OBDII_EE_DATA.EE_numEntryfailPoint = OBDII_TimeSec_Mp.InvalidKeyNum;
    			  OBDII_Neg_Response();
        	  }
		  }
      }
      if(OBD_stRequestResult==TRUE)
      {
          *OBDII_EE_DATA.EE_numEntryfailPoint = 0;
		  OBDII_TP_stEffService.TP_valSendBuf_MP[OBDII_TP_stEffService.lSendCnt]=UDS_ValSecLev_LO;
		  OBDII_TP_stEffService.lSendCnt++;
		  OBDII_TP_stEffService.lServiceS=OBDII_TP_stEffService.lSendCnt;
		  OBDII_Send_ResPonsReqdata();
		  UDS_ValSecLev_last=UDS_ValSecLev_LO;
		  UDS_ValSecLev = UDS_ValSecLev_LO-1;
      }
    }
}
void CommunicationCtr_Process(void)//28
{
  ubyte ControlType_LO=0;
  ubyte CommuniType_LO=0;
  ubyte OBD_stRequestResult=0;
  OBDII_TP_stEffService.lSendCnt=0;
  OBDII_TP_stEffService.valWrongCode=0;
  ControlType_LO=OBDII_TP_stEffService.TP_valRecBuf_MP[0];
  CommuniType_LO=OBDII_TP_stEffService.TP_valRecBuf_MP[1];
  if((OBDII_Service_demondLst[OBDII_TP_stEffService.TP_posSevice].SupDiagSesnD_Or_Not==UDS_stDiagSeon)
   ||(OBDII_Service_demondLst[OBDII_TP_stEffService.TP_posSevice].SupDiagSesnP_Or_Not==UDS_stDiagSeon)
	 ||(OBDII_Service_demondLst[OBDII_TP_stEffService.TP_posSevice].SupDiagSesnE_Or_Not==UDS_stDiagSeon))
  {
     OBD_stRequestResult=TRUE;
  }
  else
  {
     OBDII_TP_stEffService.valWrongCode=ServiceNotSupportedInActiveSession;
     if(CI_flgDTCFunAddrVaild_MP==FALSE)
     OBDII_Neg_Response();
  }
  if(OBD_stRequestResult==TRUE)
  {
      OBD_stRequestResult=FALSE;
      if(OBDII_TP_stEffService.lServiceR==0x03)
    	{
    	   OBD_stRequestResult=TRUE;
    	}
    	else
    	{
    	   OBDII_TP_stEffService.valWrongCode=Incorrect_Message_Length_Or_Invalid_Format;
    	   OBDII_Neg_Response();
    	}
  }
  if(OBD_stRequestResult==TRUE)
    {
       OBD_stRequestResult=FALSE;
       if((ControlType_LO==0x80)||(ControlType_LO==0x81)||(ControlType_LO==0x82)||(ControlType_LO==0x83)
    	||(ControlType_LO==0x00)||(ControlType_LO==0x01)||(ControlType_LO==0x02)||(ControlType_LO==0x03))
       {
    	   OBD_stRequestResult=TRUE;
       }
       else
       {
    	   OBDII_TP_stEffService.valWrongCode=Sub_Function_Not_Supported;
    	   OBDII_Neg_Response();
       }
    }
  if(OBD_stRequestResult==TRUE)
     {
        OBD_stRequestResult=OBDII_CallBack_CheckComCtr_Condition();
    	if(OBD_stRequestResult==FALSE)
    	{
    		OBDII_TP_stEffService.valWrongCode=Conditions_Not_Correct;
    		OBDII_Neg_Response();
    	}
     }
  if(OBD_stRequestResult==TRUE)
  {
          OBD_stRequestResult=FALSE;
          if((CommuniType_LO==CommunicatinType)||(CommuniType_LO==NMCommunicatinType)||(CommuniType_LO==NM_CommunicatinType))
          {
          	OBD_stRequestResult=TRUE;
          }
          else
          {
          	OBDII_TP_stEffService.valWrongCode=Request_Out_Of_Range;
          	OBDII_Neg_Response();
          }
  }
    if(OBD_stRequestResult==TRUE)
    {
        OBD_stRequestResult=FALSE;
        if((OBDII_Service_demondLst[OBDII_TP_stEffService.TP_posSevice].Secu_Lev==Security_Level0)
        	||(OBDII_Service_demondLst[OBDII_TP_stEffService.TP_posSevice].Secu_Lev==UDS_ValSecLev))
        {
           OBD_stRequestResult=TRUE;
        }
        else
        {
           OBDII_TP_stEffService.valWrongCode=Security_Access_Denied;
           OBDII_Neg_Response();
        }
    }

    if(OBD_stRequestResult==TRUE)
    {
    	OBDII_CallBack_CommunicationCtl_Execute(ControlType_LO&0x0F,CommuniType_LO);
    	if((ControlType_LO==0x00)||(ControlType_LO==0x01)||(ControlType_LO==0x02)||(ControlType_LO==0x03))
    	{
            OBDII_TP_stEffService.TP_valSendBuf_MP[OBDII_TP_stEffService.lSendCnt]=ControlType_LO;
            OBDII_TP_stEffService.lSendCnt++;
            OBDII_TP_stEffService.lServiceS=OBDII_TP_stEffService.lSendCnt;
            OBDII_Send_ResPonsReqdata();

    	}
    	else if((ControlType_LO==0x80)||(ControlType_LO==0x81)||(ControlType_LO==0x82)||(ControlType_LO==0x83))
		{

		}

    }
}
void WriteDataByIdentifier_Process(void)  //2E
{
  uword OBD_valPid_LO=0;
  ubyte WDFidValid = 0;
  ubyte OBD_stRequestResult=0;
  uword WDBI_i = 0,WDBI_j = 0,WDBI_k = 0;
  OBDII_TP_stEffService.lSendCnt=0;
  OBDII_TP_stEffService.valWrongCode=0;
  OBD_valPid_LO=OBDII_TP_stEffService.TP_valRecBuf_MP[0]*256+OBDII_TP_stEffService.TP_valRecBuf_MP[1];
  if((OBDII_Service_demondLst[OBDII_TP_stEffService.TP_posSevice].SupDiagSesnD_Or_Not==UDS_stDiagSeon)
   ||(OBDII_Service_demondLst[OBDII_TP_stEffService.TP_posSevice].SupDiagSesnP_Or_Not==UDS_stDiagSeon)
	 ||(OBDII_Service_demondLst[OBDII_TP_stEffService.TP_posSevice].SupDiagSesnE_Or_Not==UDS_stDiagSeon))
  {
     OBD_stRequestResult=TRUE;
  }
  else
  {
     OBDII_TP_stEffService.valWrongCode=ServiceNotSupportedInActiveSession;
     OBDII_Neg_Response();
  }
  if(OBD_stRequestResult==TRUE)
  {
	OBD_stRequestResult=FALSE;
	  if(OBDII_TP_stEffService.lServiceR>3)
	  {
		  OBD_stRequestResult=TRUE;
	  }
	  else
	  {
	  	  OBDII_TP_stEffService.valWrongCode=Incorrect_Message_Length_Or_Invalid_Format;
	  	  OBDII_Neg_Response();
	  }
  }
  if(OBD_stRequestResult==TRUE)
    {
	  OBD_stRequestResult=FALSE;
	  if(OBD_Veh_InfLst!= ((VehData_CSTR*)0))
	  {
		  OBD_stRequestResult=TRUE;
	  }
    }
  if(OBD_stRequestResult==TRUE)
  {
	OBD_stRequestResult=FALSE;
	for(WDBI_i = 0; WDBI_i < (OBDII_Veh_Data_SIZE); WDBI_i++)
	{
	  if(OBD_valPid_LO==OBD_Veh_InfLst[WDBI_i].VehDataFid)
	   {
		 OBD_stRequestResult=TRUE;
		 WDFidValid = 1;
		 WDBI_j=WDBI_i;
	   }
	}
	  if(WDFidValid == 0)
	  {
		   OBDII_TP_stEffService.valWrongCode=Request_Out_Of_Range;
		   OBDII_Neg_Response();
	  }
  }
  if(OBD_stRequestResult==TRUE)
  {
	  OBD_stRequestResult=FALSE;
      if((OBDII_TP_stEffService.lServiceR-3)==OBD_Veh_InfLst[WDBI_j].VehDatalen)
      {
    	  OBD_stRequestResult=TRUE;
      }
      else
      {
    	  OBDII_TP_stEffService.valWrongCode=Incorrect_Message_Length_Or_Invalid_Format;
    	  OBDII_Neg_Response();
      }
  }
  if(OBD_stRequestResult==TRUE)
  {
	  OBD_stRequestResult=FALSE;
	  if(((UDS_stDiagSeon==Default_Session)&&(OBD_Veh_InfLst[WDBI_j].VehDataDSessionRW==SupRW))
		||((UDS_stDiagSeon==Program_Session)&&(OBD_Veh_InfLst[WDBI_j].VehDataPSessionRW==SupRW))
		||((UDS_stDiagSeon==Extended_Session)&&(OBD_Veh_InfLst[WDBI_j].VehDataESessionRW==SupRW)))
	  {
		OBD_stRequestResult=TRUE;
	  }
	  else
	  {
		OBDII_TP_stEffService.valWrongCode=Request_Out_Of_Range;
		OBDII_Neg_Response();
	  }
  }
  if(OBD_stRequestResult==TRUE)
  {
	  OBD_stRequestResult=OBDII_CallBack_WriteDATAbyID_Condition();
  	if(OBD_stRequestResult==TRUE)
  	{
  		OBD_stRequestResult=TRUE;
  	}
  	else
  	{
  		OBDII_TP_stEffService.valWrongCode=Conditions_Not_Correct;
  		OBDII_Neg_Response();
  	}
  }
  if(OBD_stRequestResult==TRUE)
	{
	  OBD_stRequestResult=FALSE;
	  if((OBDII_Service_demondLst[OBDII_TP_stEffService.TP_posSevice].Secu_Lev==Security_Level0)
	   ||(OBDII_Service_demondLst[OBDII_TP_stEffService.TP_posSevice].Secu_Lev==UDS_ValSecLev))
	  {
		OBD_stRequestResult=TRUE;
	  }
	  else
	  {
		OBDII_TP_stEffService.valWrongCode=Security_Access_Denied;
		OBDII_Neg_Response();
	  }
	}

  if(OBD_stRequestResult==TRUE)
  	{
	  OBD_stRequestResult=FALSE;
	 if((OBD_Veh_InfLst[WDBI_j].VehDataSupSecLevel==Security_Level0)
	  ||(OBD_Veh_InfLst[WDBI_j].VehDataSupSecLevel==UDS_ValSecLev))
	  {
		 OBD_stRequestResult=TRUE;
	  }
	 else
	  {
		OBDII_TP_stEffService.valWrongCode=Security_Access_Denied;
		OBDII_Neg_Response();
	  }
  	}
  if(OBD_stRequestResult==TRUE)
	{
		OBDII_TP_stEffService.TP_valSendBuf_MP[OBDII_TP_stEffService.lSendCnt]=OBD_valPid_LO/256;
		OBDII_TP_stEffService.lSendCnt++;
		OBDII_TP_stEffService.TP_valSendBuf_MP[OBDII_TP_stEffService.lSendCnt]=OBD_valPid_LO%256;
		OBDII_TP_stEffService.lSendCnt++;
		for(WDBI_k = 0; WDBI_k <(OBD_Veh_InfLst[WDBI_j].VehDatalen); WDBI_k++)
		{
		  OBD_Veh_InfLst[WDBI_j].VehDatainf[WDBI_k]=OBDII_TP_stEffService.TP_valRecBuf_MP[WDBI_k+2];
		}
		OBDII_TP_stEffService.lServiceS=OBDII_TP_stEffService.lSendCnt;
		OBDII_Send_ResPonsReqdata();
		OBDII_CallBack_WriteDataByIdentifier_Execute(OBD_valPid_LO);
	}
}
void InputOutputControlByIdentifier_Process(void)//2F
{
	uword OBD_valPid_LO=0;
	ubyte OBD_stRequestResult=0;
	ubyte IOCBD_j,IOCBD_k,IOCBD_m;
	ubyte CheckPass_LO=0;
	ubyte OBDII_dataSizeReturn=0;
	OBDII_TP_stEffService.lSendCnt=0;
	OBDII_TP_stEffService.valWrongCode=0;
	 if((OBDII_Service_demondLst[OBDII_TP_stEffService.TP_posSevice].SupDiagSesnD_Or_Not==UDS_stDiagSeon)
	  ||(OBDII_Service_demondLst[OBDII_TP_stEffService.TP_posSevice].SupDiagSesnP_Or_Not==UDS_stDiagSeon)
	  ||(OBDII_Service_demondLst[OBDII_TP_stEffService.TP_posSevice].SupDiagSesnE_Or_Not==UDS_stDiagSeon))
	 {
		OBD_stRequestResult=TRUE;
	 }
	 else
	 {
		OBDII_TP_stEffService.valWrongCode=ServiceNotSupportedInActiveSession;
		OBDII_Neg_Response();
	 }
	if(OBD_stRequestResult==TRUE)
	 {
		 OBD_stRequestResult=FALSE;
		if((OBDII_TP_stEffService.lServiceR==5)||(OBDII_TP_stEffService.lServiceR==4))
		{
			OBD_stRequestResult=TRUE;
		}
		else
		{
			OBDII_TP_stEffService.valWrongCode=Incorrect_Message_Length_Or_Invalid_Format;
			OBDII_Neg_Response();
		}
	 }
	if(OBD_stRequestResult==TRUE)
	{
		OBD_stRequestResult=OBDII_CallBack_InputOutputCtl_Condition();
    	if(OBD_stRequestResult==FALSE)
    	{
    		OBDII_TP_stEffService.valWrongCode=Conditions_Not_Correct;
    		OBDII_Neg_Response();
    	}
	}
	 if(OBD_stRequestResult==TRUE)
	 {
		 OBD_stRequestResult=FALSE;
		 if((OBDII_Service_demondLst[OBDII_TP_stEffService.TP_posSevice].Secu_Lev==Security_Level0)
		  ||(OBDII_Service_demondLst[OBDII_TP_stEffService.TP_posSevice].Secu_Lev==UDS_ValSecLev))
		 {
			OBD_stRequestResult=TRUE;
		 }
		 else
		 {
			OBDII_TP_stEffService.valWrongCode=Security_Access_Denied;
			OBDII_Neg_Response();
		 }
	 }
	 if(OBD_stRequestResult==TRUE)
	 {
		 OBD_stRequestResult=FALSE;
		 OBD_valPid_LO=OBDII_TP_stEffService.TP_valRecBuf_MP[0]*256+OBDII_TP_stEffService.TP_valRecBuf_MP[1];
		 for(IOCBD_k = 0; IOCBD_k < (OBDII_PID_InOut_SIZE); IOCBD_k++)
		  {
			 if(OBD_valPid_LO==OBDII_InOut_ParaLst[IOCBD_k].InOutID)
			 {
				 OBD_stRequestResult=TRUE;
				 IOCBD_j=IOCBD_k;
				 CheckPass_LO=1;
			 }
		  }
		 if(CheckPass_LO==0)
		 {
			 OBDII_TP_stEffService.valWrongCode=Request_Out_Of_Range;
			  OBDII_Neg_Response();
		 }
     }
	if(OBD_stRequestResult==TRUE)
	{
		if((OBDII_InOut_ParaLst[IOCBD_j].ctrlStSize<=10)&&(OBDII_InOut_ParaLst != ((uds_InOut_Ctrl*)0)))
		{
			for(IOCBD_m=0;IOCBD_m<OBDII_InOut_ParaLst[IOCBD_j].ctrlStSize;IOCBD_m++)
				OBDII_InOut_CtlBuf[IOCBD_m]=OBDII_TP_stEffService.TP_valRecBuf_MP[2+IOCBD_m];

		}
		OBDII_dataSizeReturn=OBDII_CallBack_InputOutputCtl_Execute(OBD_valPid_LO,OBDII_InOut_CtlBuf,OBDII_InOut_ReturnBuf);
		OBDII_TP_stEffService.TP_valSendBuf_MP[OBDII_TP_stEffService.lSendCnt]=OBD_valPid_LO/256;
		OBDII_TP_stEffService.lSendCnt++;
		OBDII_TP_stEffService.TP_valSendBuf_MP[OBDII_TP_stEffService.lSendCnt]=OBD_valPid_LO%256;
		OBDII_TP_stEffService.lSendCnt++;

		if((OBDII_dataSizeReturn<=10)&&(OBDII_dataSizeReturn!=0))
		{
			for(IOCBD_m=0;IOCBD_m<OBDII_InOut_ParaLst[IOCBD_j].ctrlStSize;IOCBD_m++)
			{
			  OBDII_TP_stEffService.TP_valSendBuf_MP[OBDII_TP_stEffService.lSendCnt]=OBDII_InOut_ReturnBuf[IOCBD_m];
			  OBDII_TP_stEffService.lSendCnt++;
			}
		}
		OBDII_TP_stEffService.lServiceS=OBDII_TP_stEffService.lSendCnt;
		OBDII_Send_ResPonsReqdata();
	 }
}
void Routine_Control_Process(void)//31
{
	uword OBD_valPid_LO;
	ubyte OBD_stRequestResult=0;
	ubyte RoutCtr_i,RoutCtr_j;
	ubyte CheckPass_LO=0;
	OBDII_TP_stEffService.lSendCnt=0;
	OBDII_TP_stEffService.valWrongCode=0;
	OBD_valPid_LO=OBDII_TP_stEffService.TP_valRecBuf_MP[1]*256+OBDII_TP_stEffService.TP_valRecBuf_MP[2];
	 if((OBDII_Service_demondLst[OBDII_TP_stEffService.TP_posSevice].SupDiagSesnD_Or_Not==UDS_stDiagSeon)
	  ||(OBDII_Service_demondLst[OBDII_TP_stEffService.TP_posSevice].SupDiagSesnP_Or_Not==UDS_stDiagSeon)
	  ||(OBDII_Service_demondLst[OBDII_TP_stEffService.TP_posSevice].SupDiagSesnE_Or_Not==UDS_stDiagSeon))
	 {
		OBD_stRequestResult=TRUE;
	 }
	 else
	 {
		OBDII_TP_stEffService.valWrongCode=ServiceNotSupportedInActiveSession;
		OBDII_Neg_Response();
	 }
	if(OBD_stRequestResult==TRUE)
	{
		OBD_stRequestResult=FALSE;
		if(OBDII_TP_stEffService.lServiceR>=0x04)
		{
			OBD_stRequestResult=TRUE;
		}
		else
		{
			OBDII_TP_stEffService.valWrongCode=Incorrect_Message_Length_Or_Invalid_Format;
			OBDII_Neg_Response();
		}
	}
	if(OBD_stRequestResult==TRUE)
	 {
		 OBD_stRequestResult=FALSE;
		if((OBDII_TP_stEffService.TP_valRecBuf_MP[0]==0x01)||(OBDII_TP_stEffService.TP_valRecBuf_MP[0]==0x03))
		{
		  OBD_stRequestResult=TRUE;
		}
		else
		{
		  OBDII_TP_stEffService.valWrongCode=Sub_Function_Not_Supported;
		  OBDII_Neg_Response();
		}
	 }

	if((OBD_stRequestResult==TRUE)&&(OBDII_Routine_DATA!= ((Routine_CSTR*)0)))
	{
		OBD_stRequestResult=FALSE;
		for(RoutCtr_i = 0;RoutCtr_i < OBDII_Routine_Data_SIZE;RoutCtr_i++)
		{
			if(OBD_valPid_LO == OBDII_Routine_DATA[RoutCtr_i].RoutineFid)
			{
				OBD_stRequestResult=TRUE;
				RoutCtr_j=RoutCtr_i;
				CheckPass_LO=1;
			}
		}
		if(CheckPass_LO==0)
		{
			OBDII_TP_stEffService.valWrongCode=Request_Out_Of_Range;
			OBDII_Neg_Response();
		}
	}
	if(OBD_stRequestResult==TRUE)
	{
		OBD_stRequestResult=OBDII_CallBack_RoutineCtl_Condition(RoutCtr_j);
    	if(OBD_stRequestResult==TRUE)
    	{
    		OBD_stRequestResult=TRUE;
    	}
    	else
    	{
    		OBDII_TP_stEffService.valWrongCode=Conditions_Not_Correct;
    		OBDII_Neg_Response();
    	}
	}
	 if(OBD_stRequestResult==TRUE)
	 {
		 OBD_stRequestResult=FALSE;
		 if((OBDII_Service_demondLst[OBDII_TP_stEffService.TP_posSevice].Secu_Lev==Security_Level0)
		  ||(OBDII_Service_demondLst[OBDII_TP_stEffService.TP_posSevice].Secu_Lev==UDS_ValSecLev))
		 {
			OBD_stRequestResult=TRUE;
		 }
		 else
		 {
			OBDII_TP_stEffService.valWrongCode=Security_Access_Denied;
			OBDII_Neg_Response();
		 }
	 }
	if((OBD_stRequestResult==TRUE)&&(OBDII_Routine_DATA!= ((Routine_CSTR*)0)))
	{
		OBD_stRequestResult=FALSE;
		if(((UDS_stDiagSeon==Default_Session)&&(OBDII_Routine_DATA[RoutCtr_j].SupDSessionOrNot==SuppDiagSesnD))
		||((UDS_stDiagSeon==Program_Session)&&(OBDII_Routine_DATA[RoutCtr_j].SupPSessionOrNot==SuppDiagSesnP))
		||((UDS_stDiagSeon==Extended_Session)&&(OBDII_Routine_DATA[RoutCtr_j].SupESessionOrNot==SuppDiagSesnE)))
	   {
		  OBD_stRequestResult=TRUE;
	   }
	   else
	   {
		  OBDII_TP_stEffService.valWrongCode=ServiceNotSupportedInActiveSession;
		  OBDII_Neg_Response();
	   }
	}
	if((OBD_stRequestResult==TRUE)&&(OBDII_Routine_DATA!= ((Routine_CSTR*)0)))
	{
		 OBD_stRequestResult=FALSE;
		 if((OBDII_Routine_DATA[RoutCtr_j].RoutineSupSecLevel==Security_Level0)
		  ||(OBDII_Routine_DATA[RoutCtr_j].RoutineSupSecLevel==UDS_ValSecLev))
		 {
			 OBD_stRequestResult=TRUE;
		 }
		 else
		 {
			OBDII_TP_stEffService.valWrongCode=Security_Access_Denied;
			OBDII_Neg_Response();
		 }
	}
	if(OBD_stRequestResult==TRUE)
	{
	    OBD_stRequestResult=FALSE;
	    if(OBDII_TP_stEffService.TP_valRecBuf_MP[0]==1)//start routine
	    {
	      OBDII_VauRcRecor.OBDII_numRecordRC_Mp=RoutCtr_j;
	      OBDII_VauRcRecor.OBDII_stExcReturnValue=OBDII_CallBack_RoutineCtl_Execute(RoutCtr_j,OBDII_TP_stEffService.TP_valRecBuf_MP[0],&OBD_stExeReturnValue[0]);
	      OBDII_VauRcRecor.OBDII_stExcRcSession=UDS_stDiagSeon;
	      OBDII_VauRcRecor.OBDII_flagExcStartRc=1;

	      OBD_stRequestResult=TRUE;
	    }
	    else if(OBDII_TP_stEffService.TP_valRecBuf_MP[0]==2)//stop routine
	    {
	      if((OBDII_VauRcRecor.OBDII_numRecordRC_Mp==RoutCtr_j)&&(OBDII_VauRcRecor.OBDII_flagExcStartRc==1)&&(OBDII_VauRcRecor.OBDII_stExcRcSession==UDS_stDiagSeon))
	        {
	          OBDII_VauRcRecor.OBDII_stExcReturnValue=OBDII_CallBack_RoutineCtl_Execute(RoutCtr_j,OBDII_TP_stEffService.TP_valRecBuf_MP[0],&OBD_stExeReturnValue[0]);
	        OBDII_VauRcRecor.OBDII_flagExcStartRc=0;

	        OBD_stRequestResult=TRUE;
	        }
	    }
	    else if(OBDII_TP_stEffService.TP_valRecBuf_MP[0]==3)//request result
	    {
	      if((OBDII_VauRcRecor.OBDII_numRecordRC_Mp==RoutCtr_j)&&(OBDII_VauRcRecor.OBDII_stExcRcSession==UDS_stDiagSeon))
	        {
	          OBDII_VauRcRecor.OBDII_stExcReturnValue=OBDII_CallBack_RoutineCtl_Execute(RoutCtr_j,OBDII_TP_stEffService.TP_valRecBuf_MP[0],&OBD_stExeReturnValue[0]);
	          if((OBDII_VauRcRecor.OBDII_stExcReturnValue>=1)&&(OBDII_VauRcRecor.OBDII_stExcReturnValue<=4))
	          OBD_stRequestResult=TRUE;
	        }
	    }
	    if(OBD_stRequestResult==FALSE)
	    {
	            OBDII_TP_stEffService.valWrongCode=requestSequenceError;
	            OBDII_Neg_Response();

	    }
	}
	if(OBD_stRequestResult==TRUE)
	{
		OBD_stRequestResult=FALSE;

		if((OBDII_TP_stEffService.TP_valRecBuf_MP[0]&(0x80))!=0x80)
		{
			OBD_stRequestResult=TRUE;
		}
	}
	if(OBD_stRequestResult==TRUE)
	{
	  OBDII_TP_stEffService.TP_valSendBuf_MP[OBDII_TP_stEffService.lSendCnt]=OBDII_TP_stEffService.TP_valRecBuf_MP[0];
	  OBDII_TP_stEffService.lSendCnt++;
	  OBDII_TP_stEffService.TP_valSendBuf_MP[OBDII_TP_stEffService.lSendCnt]=OBDII_TP_stEffService.TP_valRecBuf_MP[1];
	  OBDII_TP_stEffService.lSendCnt++;
	  OBDII_TP_stEffService.TP_valSendBuf_MP[OBDII_TP_stEffService.lSendCnt]=OBDII_TP_stEffService.TP_valRecBuf_MP[2];
	  OBDII_TP_stEffService.lSendCnt++;
	  if(OBDII_VauRcRecor.OBDII_stExcReturnValue>0)
	  {
		  for(RoutCtr_i=0;RoutCtr_i<OBDII_VauRcRecor.OBDII_stExcReturnValue;RoutCtr_i++)
		  {
			OBDII_TP_stEffService.TP_valSendBuf_MP[OBDII_TP_stEffService.lSendCnt]=OBD_stExeReturnValue[RoutCtr_i];
			OBDII_TP_stEffService.lSendCnt++;
		  }
	  }
	  OBDII_TP_stEffService.lServiceS=OBDII_TP_stEffService.lSendCnt;
	  OBDII_Send_ResPonsReqdata();
	}
}
void WriteMemoryByAddress_Process(void)  //3D
{
	uword RMBA_valaddressH_LO;
	uword RMBA_valaddressL_LO;
	uword RMBA_valaddress_LO;
	ubyte RMBA_valsize_LO;
	ubyte RMBA_laddress_LO;
	ubyte RMBA_lsize_LO;
	ubyte OBD_stRequestResult=0;
	OBDII_TP_stEffService.lSendCnt=0;
	OBDII_TP_stEffService.valWrongCode=0;
	RMBA_laddress_LO=OBDII_TP_stEffService.TP_valRecBuf_MP[0]&0x0f;
	RMBA_lsize_LO=(OBDII_TP_stEffService.TP_valRecBuf_MP[0]&0xf0)>>4;

	RMBA_valaddressH_LO=OBDII_TP_stEffService.TP_valRecBuf_MP[2]*256+OBDII_TP_stEffService.TP_valRecBuf_MP[1];
	RMBA_valaddressL_LO=OBDII_TP_stEffService.TP_valRecBuf_MP[4]*256+OBDII_TP_stEffService.TP_valRecBuf_MP[3];
	RMBA_valaddress_LO=RMBA_valaddressH_LO*65536+RMBA_valaddressL_LO;
	RMBA_valsize_LO=OBDII_TP_stEffService.TP_valRecBuf_MP[6]*256+OBDII_TP_stEffService.TP_valRecBuf_MP[5];

	 if((UDS_stDiagSeon== OBDII_Service_demondLst[OBDII_TP_stEffService.TP_posSevice].SupDiagSesnD_Or_Not)
	  ||(UDS_stDiagSeon== OBDII_Service_demondLst[OBDII_TP_stEffService.TP_posSevice].SupDiagSesnP_Or_Not)
	 ||(UDS_stDiagSeon== OBDII_Service_demondLst[OBDII_TP_stEffService.TP_posSevice].SupDiagSesnE_Or_Not))
	 {
		OBD_stRequestResult=TRUE;
	 }
	 else
	 {
		OBDII_TP_stEffService.valWrongCode=ServiceNotSupportedInActiveSession;
		OBDII_Neg_Response();
	 }
	 if(OBD_stRequestResult==TRUE)
	 {
		 OBD_stRequestResult=FALSE;
		if((OBDII_TP_stEffService.lServiceR>=5)&&(OBDII_TP_stEffService.lServiceR == (2+RMBA_laddress_LO+RMBA_lsize_LO)))
		 {
			 OBD_stRequestResult=TRUE;
		 }
		 else
		 {
			 OBDII_TP_stEffService.valWrongCode=Incorrect_Message_Length_Or_Invalid_Format;
			 OBDII_Neg_Response();
		 }
	 }
	 if(OBD_stRequestResult==TRUE)
	 {
		 OBD_stRequestResult=FALSE;
		 if((OBDII_Service_demondLst[OBDII_TP_stEffService.TP_posSevice].Secu_Lev==Security_Level0)||(UDS_ValSecLev==OBDII_Service_demondLst[OBDII_TP_stEffService.TP_posSevice].Secu_Lev))
		 {
			OBD_stRequestResult=TRUE;
		 }
		 else
		 {
			OBDII_TP_stEffService.valWrongCode=Security_Access_Denied;
			OBDII_Neg_Response();
		 }
	 }
	 if(OBD_stRequestResult==TRUE)
	   {
		   OBD_stRequestResult=OBDII_CallBack_WriteMemory_Condition();
	    	if(OBD_stRequestResult==TRUE)
	    	{
	    		OBD_stRequestResult=TRUE;
	    	}
	    	else
	    	{
	    		OBDII_TP_stEffService.valWrongCode=Conditions_Not_Correct;
	    		OBDII_Neg_Response();
	    	}
	   }
	 if(OBD_stRequestResult==TRUE)
	 {
			OBD_stRequestResult=FALSE;
			if((RMBA_valaddress_LO>=Memory_start)&&(RMBA_valaddress_LO<=Memory_end))
			{
				OBD_stRequestResult=TRUE;
			}
			else
			{
				OBDII_TP_stEffService.valWrongCode=Request_Out_Of_Range;
				OBDII_Neg_Response();
			}
	 }
	 if(OBD_stRequestResult==TRUE)
	 {
		 OBDII_TP_stEffService.TP_valSendBuf_MP[OBDII_TP_stEffService.lSendCnt]=OBDII_TP_stEffService.TP_valRecBuf_MP[0];
		 OBDII_TP_stEffService.lSendCnt++;
		 OBDII_TP_stEffService.TP_valSendBuf_MP[OBDII_TP_stEffService.lSendCnt]=OBDII_TP_stEffService.TP_valRecBuf_MP[1];
		 OBDII_TP_stEffService.lSendCnt++;
		 OBDII_TP_stEffService.TP_valSendBuf_MP[OBDII_TP_stEffService.lSendCnt]=OBDII_TP_stEffService.TP_valRecBuf_MP[2];
		 OBDII_TP_stEffService.lSendCnt++;
		 OBDII_TP_stEffService.TP_valSendBuf_MP[OBDII_TP_stEffService.lSendCnt]=OBDII_TP_stEffService.TP_valRecBuf_MP[3];
		 OBDII_TP_stEffService.lSendCnt++;
		 OBDII_TP_stEffService.TP_valSendBuf_MP[OBDII_TP_stEffService.lSendCnt]=OBDII_TP_stEffService.TP_valRecBuf_MP[4];
		 OBDII_TP_stEffService.lSendCnt++;
		 OBDII_TP_stEffService.TP_valSendBuf_MP[OBDII_TP_stEffService.lSendCnt]=OBDII_TP_stEffService.TP_valRecBuf_MP[5];
		 OBDII_TP_stEffService.lSendCnt++;
		 OBDII_TP_stEffService.TP_valSendBuf_MP[OBDII_TP_stEffService.lSendCnt]=OBDII_TP_stEffService.TP_valRecBuf_MP[6];
		 OBDII_TP_stEffService.lSendCnt++;
		 OBDII_TP_stEffService.TP_valSendBuf_MP[OBDII_TP_stEffService.lSendCnt]=OBDII_TP_stEffService.TP_valRecBuf_MP[7];
		 OBDII_TP_stEffService.lSendCnt++;
		 OBDII_TP_stEffService.TP_valSendBuf_MP[OBDII_TP_stEffService.lSendCnt]=OBDII_TP_stEffService.TP_valRecBuf_MP[8];
		 OBDII_TP_stEffService.lSendCnt++;
		 OBDII_CallBack_WriteMemory_Execute(RMBA_valaddress_LO,RMBA_valsize_LO);
		 OBDII_TP_stEffService.lServiceS=OBDII_TP_stEffService.lSendCnt;
		 OBDII_Send_ResPonsReqdata();
	 }
}
void TesterPresent_Process(void)//3E
{
  ubyte UDS_st3E=0;
  ubyte OBD_stRequestResult=0;
  UDS_st3E=OBDII_TP_stEffService.TP_valRecBuf_MP[0];
  OBDII_TP_stEffService.lSendCnt=0;
  OBDII_TP_stEffService.valWrongCode=0;

  if(OBDII_TP_stEffService.lServiceR==0x02)
   {
	  OBD_stRequestResult=TRUE;
   }
   else
   {
     OBDII_TP_stEffService.valWrongCode=Incorrect_Message_Length_Or_Invalid_Format;
     OBDII_Neg_Response();
   }
  if(OBD_stRequestResult==TRUE)
   {
	  OBD_stRequestResult=FALSE;
	  if((UDS_st3E==0x80)||(UDS_st3E==0x0))
		{
			   UDS_tiDiagSeon=0;
			   OBD_stRequestResult=TRUE;
		}
		else
		{
			OBDII_TP_stEffService.valWrongCode=Sub_Function_Not_Supported;
			OBDII_Neg_Response();
		}
  }
  if(OBD_stRequestResult==TRUE)
  {
	  OBD_stRequestResult=FALSE;
	  if(UDS_st3E==0x0) OBD_stRequestResult=TRUE;
  }
  if(OBD_stRequestResult==TRUE)
    {
        OBDII_TP_stEffService.TP_valSendBuf_MP[OBDII_TP_stEffService.lSendCnt]=UDS_st3E;
        OBDII_TP_stEffService.lSendCnt++;
        OBDII_TP_stEffService.lServiceS=OBDII_TP_stEffService.lSendCnt;
        OBDII_Send_ResPonsReqdata();

    }
}

void ControlDTCSetting_Process(void)  //85
{
  ubyte UDS_stCtlDTC_LO = 0;
  ubyte OBD_stRequestResult=0;
  OBDII_TP_stEffService.lSendCnt=0;
  OBDII_TP_stEffService.valWrongCode=0;
  if((UDS_stDiagSeon== OBDII_Service_demondLst[OBDII_TP_stEffService.TP_posSevice].SupDiagSesnD_Or_Not)
   ||(UDS_stDiagSeon== OBDII_Service_demondLst[OBDII_TP_stEffService.TP_posSevice].SupDiagSesnP_Or_Not)
	 ||(UDS_stDiagSeon== OBDII_Service_demondLst[OBDII_TP_stEffService.TP_posSevice].SupDiagSesnE_Or_Not))
  {
     OBD_stRequestResult=TRUE;
  }
  else
  {
     OBDII_TP_stEffService.valWrongCode=ServiceNotSupportedInActiveSession;
     if(CI_flgDTCFunAddrVaild_MP==FALSE)
     OBDII_Neg_Response();
  }
  if(OBD_stRequestResult==TRUE)
     {
         OBD_stRequestResult=FALSE;
         if(OBDII_TP_stEffService.lServiceR==0x02)
       	{
       	  OBD_stRequestResult=TRUE;
       	  UDS_stCtlDTC_LO=OBDII_TP_stEffService.TP_valRecBuf_MP[0];
       	}
       	else
       	{
       	  OBDII_TP_stEffService.valWrongCode=Incorrect_Message_Length_Or_Invalid_Format;
       	  OBDII_Neg_Response();
       	}
     }
   if(OBD_stRequestResult==TRUE)
      {
        OBD_stRequestResult=FALSE;
        if((UDS_stCtlDTC_LO==0x01)||(UDS_stCtlDTC_LO==0x02)||(UDS_stCtlDTC_LO==0x81)||(UDS_stCtlDTC_LO==0x82))
        {
          OBD_stRequestResult=TRUE;
        }
        else
        {
            OBDII_TP_stEffService.valWrongCode=Sub_Function_Not_Supported;
            OBDII_Neg_Response();
        }
      }
     if(OBD_stRequestResult==TRUE)
     {
	    OBD_stRequestResult=OBDII_CallBack_CtlDTC_Condition();
		if(OBD_stRequestResult==FALSE)
		{
			OBDII_TP_stEffService.valWrongCode=Conditions_Not_Correct;
			OBDII_Neg_Response();
		}
     }
     if(OBD_stRequestResult==TRUE)
     {
         OBD_stRequestResult=FALSE;
         if((OBDII_Service_demondLst[OBDII_TP_stEffService.TP_posSevice].Secu_Lev==Security_Level0)
          ||(OBDII_Service_demondLst[OBDII_TP_stEffService.TP_posSevice].Secu_Lev==UDS_ValSecLev))
         {
            OBD_stRequestResult=TRUE;
         }
         else
         {
            OBDII_TP_stEffService.valWrongCode=Security_Access_Denied;
            OBDII_Neg_Response();
         }
     }
     if(OBD_stRequestResult==TRUE)
     {
          OBD_stRequestResult=FALSE;
          OBDII_CallBack_CtlDTC_Execute(UDS_stCtlDTC_LO&0x0f);
          if((UDS_stCtlDTC_LO==0x01)||(UDS_stCtlDTC_LO==0x02))
          {
        	  OBD_stRequestResult=TRUE;
          }
     }
    if(OBD_stRequestResult==TRUE)
    {
        OBDII_TP_stEffService.TP_valSendBuf_MP[OBDII_TP_stEffService.lSendCnt]=UDS_stCtlDTC_LO;
        OBDII_TP_stEffService.lSendCnt++;
        OBDII_TP_stEffService.lServiceS=OBDII_TP_stEffService.lSendCnt;
        OBDII_Send_ResPonsReqdata();

    }
}

ubyte  Requestvehicleinfor_process(uword OBD_valPid_LO)
{
   ubyte Request_result_LO=0;
   ubyte RVIP_i,RVIP_j;

   if(OBD_Veh_InfLst!= ((VehData_CSTR*)0))
   {
	   for(RVIP_i = 0; RVIP_i <(OBDII_Veh_Data_SIZE); RVIP_i++)
	   {
		   if(OBD_valPid_LO==OBD_Veh_InfLst[RVIP_i].VehDataFid)
		   {
				   OBDII_TP_stEffService.TP_valSendBuf_MP[OBDII_TP_stEffService.lSendCnt]=OBD_valPid_LO/256;
				   OBDII_TP_stEffService.lSendCnt++;
				   OBDII_TP_stEffService.TP_valSendBuf_MP[OBDII_TP_stEffService.lSendCnt]=OBD_valPid_LO%256;
				   OBDII_TP_stEffService.lSendCnt++;
				   for(RVIP_j = 0; RVIP_j <(OBD_Veh_InfLst[RVIP_i].VehDatalen); RVIP_j++)
				   {
					   OBDII_TP_stEffService.TP_valSendBuf_MP[OBDII_TP_stEffService.lSendCnt]=OBD_Veh_InfLst[RVIP_i].VehDatainf[RVIP_j];
					   OBDII_TP_stEffService.lSendCnt++;
				   }
				   Request_result_LO=1;
		   }
	   }
   	}
   return Request_result_LO;
}
void ReportNumOfDTCbyStsMsk(void)
{
	uword DTC_NumCurrent_LO=0;
	ubyte DTC_Mask=0;
	ubyte OBD_stRequestResult=0;
	uword RNDTCBS_i = 0;
	OBDII_TP_stEffService.lSendCnt=0;
	OBDII_TP_stEffService.valWrongCode=0;
	DTC_Mask=OBDII_TP_stEffService.TP_valRecBuf_MP[1]&OBDII_DTC_AvailabilityMask;
	OBDII_TP_stEffService.TP_valSendBuf_MP[0]=0x01;
	OBDII_TP_stEffService.lSendCnt++;
	OBDII_TP_stEffService.TP_valSendBuf_MP[1]=OBDII_DTC_AvailabilityMask;
	OBDII_TP_stEffService.lSendCnt++;
	OBDII_TP_stEffService.TP_valSendBuf_MP[2]=0x00;//15031-6
	OBDII_TP_stEffService.lSendCnt++;
	if(Sup_ReportNumOfDTCbyStsMsk==ON)
	{
		OBD_stRequestResult=TRUE;
	}
	else
	{
		OBDII_TP_stEffService.valWrongCode=Sub_Function_Not_Supported;
		OBDII_Neg_Response();
	}
	if(OBD_stRequestResult==TRUE)
	{
		OBD_stRequestResult=FALSE;
		if(OBDII_TP_stEffService.lServiceR==3)
		{
			OBD_stRequestResult=TRUE;
		}
		else
		{
			OBDII_TP_stEffService.valWrongCode=Incorrect_Message_Length_Or_Invalid_Format;
			OBDII_Neg_Response();
		}
	}
	if(OBD_stRequestResult==TRUE)
	{
		for (RNDTCBS_i = 0; RNDTCBS_i <(OBDII_DTC_TABLE_SIZE); RNDTCBS_i++)
		{
			if(DTC_st_errNum != ((Dtcst_CSTR*)0))
			{
				if(DTC_st_errNum[RNDTCBS_i].Status&DTC_Mask)
				{
					DTC_NumCurrent_LO++;
				}
			}
		}
		OBDII_TP_stEffService.TP_valSendBuf_MP[3]=(DTC_NumCurrent_LO>>8)&0xFF;
		OBDII_TP_stEffService.lSendCnt++;
		OBDII_TP_stEffService.TP_valSendBuf_MP[4]=DTC_NumCurrent_LO&0xFF;
		OBDII_TP_stEffService.lSendCnt++;
		OBDII_TP_stEffService.lServiceS=OBDII_TP_stEffService.lSendCnt;
		OBDII_Send_ResPonsReqdata();
	}
}
void ReportDTCbyStsMsk(void)
{
	ubyte DTC_Mask=0;
	ubyte OBD_stRequestResult=0;
	uword RDTCBSM_i = 0;
	OBDII_TP_stEffService.lSendCnt=0;
	OBDII_TP_stEffService.valWrongCode=0;
	DTC_Mask=OBDII_TP_stEffService.TP_valRecBuf_MP[1]&OBDII_DTC_AvailabilityMask;
	OBDII_TP_stEffService.TP_valSendBuf_MP[0]=0x02;
	OBDII_TP_stEffService.lSendCnt++;
	OBDII_TP_stEffService.TP_valSendBuf_MP[1]=OBDII_DTC_AvailabilityMask;
	OBDII_TP_stEffService.lSendCnt++;
	if(Sup_ReportDTCbyStsMsk==ON)
	{
		OBD_stRequestResult=TRUE;
	}
	else
	{
		OBDII_TP_stEffService.valWrongCode=Sub_Function_Not_Supported;
		OBDII_Neg_Response();
	}
	if(OBD_stRequestResult==TRUE)
	{
		OBD_stRequestResult=FALSE;
		if(OBDII_TP_stEffService.lServiceR==3)
		{
			OBD_stRequestResult=TRUE;
		}
		else
		{
			OBDII_TP_stEffService.valWrongCode=Incorrect_Message_Length_Or_Invalid_Format;
			OBDII_Neg_Response();
		}
	}
	if(OBD_stRequestResult==TRUE)
	{
		for (RDTCBSM_i = 0; RDTCBSM_i <(OBDII_DTC_TABLE_SIZE); RDTCBSM_i++)
		{
			if(DTC_st_errNum != ((Dtcst_CSTR*)0))
			{
				if(DTC_st_errNum[RDTCBSM_i].Status&DTC_Mask)
				{
					OBDII_TP_stEffService.TP_valSendBuf_MP[OBDII_TP_stEffService.lSendCnt]=(ubyte)(OBDII_DTC_Lst[RDTCBSM_i].DTCVAL>>16);
					OBDII_TP_stEffService.lSendCnt++;
					OBDII_TP_stEffService.TP_valSendBuf_MP[OBDII_TP_stEffService.lSendCnt]=(ubyte)(OBDII_DTC_Lst[RDTCBSM_i].DTCVAL>>8);
					OBDII_TP_stEffService.lSendCnt++;
					OBDII_TP_stEffService.TP_valSendBuf_MP[OBDII_TP_stEffService.lSendCnt]=(ubyte)(OBDII_DTC_Lst[RDTCBSM_i].DTCVAL);
					OBDII_TP_stEffService.lSendCnt++;
					OBDII_TP_stEffService.TP_valSendBuf_MP[OBDII_TP_stEffService.lSendCnt]=DTC_st_errNum[RDTCBSM_i].Status&OBDII_DTC_AvailabilityMask;
					OBDII_TP_stEffService.lSendCnt++;
				}
			}
		}
		OBDII_TP_stEffService.lServiceS=OBDII_TP_stEffService.lSendCnt;
		OBDII_Send_ResPonsReqdata();
	}
}
void ReportDtcSnapshotid(void)
{
	uword OBD_stDTCValid_LO=0;
	ubyte OBD_stRequestResult=0;
	ubyte OBD_statusDTC=0;
	uword RDTCSSBD_m = 0;
	uword RDTCSSBRN_j=0;
	uword RDTCSSBRN_i=0;
	uword RDTCSSBD_n=0;
	uword RDTCSSBD_p=0;
	ubyte OBD_SSRecord_Num_LO=0;
	OBDII_TP_stEffService.lSendCnt=0;
	OBDII_TP_stEffService.valWrongCode=0;
	OBDII_TP_stEffService.TP_valSendBuf_MP[0]=0x03;
	OBDII_TP_stEffService.lSendCnt++;
	if(Sup_ReportDtcSnapshotid==ON)
	{
		OBD_stRequestResult=TRUE;
	}
	else
	{
		OBDII_TP_stEffService.valWrongCode=Sub_Function_Not_Supported;
		OBDII_Neg_Response();
	}
	if(OBD_stRequestResult==TRUE)
	{
		OBD_stRequestResult=FALSE;
		if(OBDII_TP_stEffService.lServiceR==2)
		{
			OBD_stRequestResult=TRUE;
		}
		else
		{
			OBDII_TP_stEffService.valWrongCode=Incorrect_Message_Length_Or_Invalid_Format;
			OBDII_Neg_Response();
		}
	}
	if((OBD_stRequestResult==TRUE)&&(OBDII_DTC_SnapshotList != ((Snapshot_ofDTC*)0)))
		{
			OBD_stRequestResult=FALSE;
			for(RDTCSSBD_m = 0; RDTCSSBD_m<OBDII_DTC_SaveSnapshot_SIZE; RDTCSSBD_m++)
			{
				if(OBDII_EE_DATA.RecordNum[RDTCSSBD_m]!=0)
				{
					OBDII_TP_stEffService.TP_valSendBuf_MP[OBDII_TP_stEffService.lSendCnt]=(ubyte)((*OBDII_EE_DATA.DTCVAL)>>16);
					OBDII_TP_stEffService.lSendCnt++;
					OBDII_TP_stEffService.TP_valSendBuf_MP[OBDII_TP_stEffService.lSendCnt]=(ubyte)((*OBDII_EE_DATA.DTCVAL)>>8);
					OBDII_TP_stEffService.lSendCnt++;
					OBDII_TP_stEffService.TP_valSendBuf_MP[OBDII_TP_stEffService.lSendCnt]=(ubyte)((*OBDII_EE_DATA.DTCVAL));
					OBDII_TP_stEffService.lSendCnt++;
					OBDII_TP_stEffService.TP_valSendBuf_MP[OBDII_TP_stEffService.lSendCnt]=*OBDII_EE_DATA.RecordNum;
					OBDII_TP_stEffService.lSendCnt++;
					OBD_stDTCValid_LO=1;
				}
			}
			OBDII_TP_stEffService.lServiceS=OBDII_TP_stEffService.lSendCnt;
			OBDII_Send_ResPonsReqdata();

		}
}
void ReportDtcSnapshotByDTCnum(void)
{
	uword OBD_valPid_LO=0;
	ubyte OBD_stDTCValid_LO=0;
	ubyte OBD_stRequestResult=0;
	ubyte OBD_SSRecord_Num_LO=0;
	ubyte OBD_CheckPass=0;
	//***********xlj add
	ubyte OBD_statusDTC=0;
	ubyte OBD_CheckDtcListPass=0;
	//*******xlj add end
	ubyte RDTCSSBRN_j,RDTCSSBRN_i,RDTCSSBRN_k,RDTCSSBD_m,RDTCSSBD_n,RDTCSSBD_l,RDTCSSBD_p;
//	static ubyte OBD_stRecordDTC=0;
	ubyte OBD_stRecordDTC=0;
	ubyte sendbuf[8]={0};
	OBD_SSRecord_Num_LO=OBDII_TP_stEffService.TP_valRecBuf_MP[4];
	OBDII_TP_stEffService.lSendCnt=0;
	OBDII_TP_stEffService.valWrongCode=0;
	OBDII_TP_stEffService.TP_valSendBuf_MP[0]=0x04;
	OBDII_TP_stEffService.lSendCnt++;
	if(Sup_ReportDtcSnapshotByDTCnum==ON)
	{
		OBD_stRequestResult=TRUE;
	}
	else
	{
		OBDII_TP_stEffService.valWrongCode=Sub_Function_Not_Supported;
		OBDII_Neg_Response();
	}
	if(OBD_stRequestResult==TRUE)
	{
		OBD_stRequestResult=FALSE;
		if(OBDII_TP_stEffService.lServiceR==6)
		{
			OBD_stRequestResult=TRUE;
		}
		else
		{
			OBDII_TP_stEffService.valWrongCode=Incorrect_Message_Length_Or_Invalid_Format;
			OBDII_Neg_Response();
		}
	}

	//*********xlj add
	if(OBD_stRequestResult==TRUE)
	{
		OBD_stRequestResult=FALSE;
		for(RDTCSSBD_m = 0; RDTCSSBD_m<OBDII_DTC_TABLE_SIZE; RDTCSSBD_m++)
		{
			if((ubyte)(OBDII_DTC_Lst[RDTCSSBD_m].DTCVAL>>16) == OBDII_TP_stEffService.TP_valRecBuf_MP[1])
			{
				OBD_stRequestResult=TRUE;
			}
			if(OBD_stRequestResult==TRUE)
			{
				OBD_stRequestResult=FALSE;
				if((ubyte)(OBDII_DTC_Lst[RDTCSSBD_m].DTCVAL>>8) == OBDII_TP_stEffService.TP_valRecBuf_MP[2])
				{
					OBD_stRequestResult=TRUE;
				}
			}
			if(OBD_stRequestResult==TRUE)
			{
				OBD_stRequestResult=FALSE;
				if((ubyte)(OBDII_DTC_Lst[RDTCSSBD_m].DTCVAL) == OBDII_TP_stEffService.TP_valRecBuf_MP[3])
				{
					OBD_stRequestResult=TRUE;
//					if((DTC_st_errNum != ((Dtcst_CSTR*)0)))
//					{
	                  OBD_statusDTC=DTC_st_errNum[RDTCSSBD_m].Status&OBDII_DTC_AvailabilityMask;
	                  OBD_CheckDtcListPass=1;
//					}

					break;
				}
			}
		}
		if(OBD_CheckDtcListPass==0)
		{
			sendbuf[0] = 0x06;
			sendbuf[1] = 0x59;
			sendbuf[2] = 0X04;
			sendbuf[3] = OBDII_TP_stEffService.TP_valRecBuf_MP[1];
			sendbuf[4] = OBDII_TP_stEffService.TP_valRecBuf_MP[2];
			sendbuf[5] = OBDII_TP_stEffService.TP_valRecBuf_MP[3];
			sendbuf[6] = 0x00;
			sendbuf[7] = 0xCC;
			OBDII_CallBack_SendAck(sendbuf,7);
//			OBDII_TP_stEffService.valWrongCode=Request_Out_Of_Range;
//			OBDII_Neg_Response();
		}
	}
	//*********xlj add end
	if(OBD_stRequestResult==TRUE)
	{
		OBD_CheckDtcListPass=0;
		OBD_stRequestResult=FALSE;
		for(RDTCSSBD_m = 0; RDTCSSBD_m<OBDII_DTC_SupportSnapshot_SIZE; RDTCSSBD_m++)
		{

			if((ubyte)(OBDII_DTC_SnapshotList[RDTCSSBD_m].DTC_SupportSnapshot.DTCVAL>>16) == OBDII_TP_stEffService.TP_valRecBuf_MP[1])
			{
				OBD_stRequestResult=TRUE;
			}
			if(OBD_stRequestResult==TRUE)
			{
				OBD_stRequestResult=FALSE;
				if((ubyte)(OBDII_DTC_SnapshotList[RDTCSSBD_m].DTC_SupportSnapshot.DTCVAL>>8) == OBDII_TP_stEffService.TP_valRecBuf_MP[2])
				{
					OBD_stRequestResult=TRUE;
				}
			}
			if(OBD_stRequestResult==TRUE)
			{
				OBD_stRequestResult=FALSE;
				if((ubyte)(OBDII_DTC_SnapshotList[RDTCSSBD_m].DTC_SupportSnapshot.DTCVAL) == OBDII_TP_stEffService.TP_valRecBuf_MP[3])
				{
					OBD_stRequestResult=TRUE;
//					if((DTC_st_errNum != ((Dtcst_CSTR*)0)))
//					{
					  OBD_CheckDtcListPass=1;
					  RDTCSSBRN_k=RDTCSSBD_m;
//					}

					break;
				}
			}
	    }
		if(OBD_CheckDtcListPass==0)
		{
			sendbuf[0] = 0x06;
			sendbuf[1] = 0x59;
			sendbuf[2] = 0X04;
			sendbuf[3] = OBDII_TP_stEffService.TP_valRecBuf_MP[1];
			sendbuf[4] = OBDII_TP_stEffService.TP_valRecBuf_MP[2];
			sendbuf[5] = OBDII_TP_stEffService.TP_valRecBuf_MP[3];
			sendbuf[6] = 0x00;
			sendbuf[7] = 0xCC;
			OBDII_CallBack_SendAck(sendbuf,7);
//			OBDII_TP_stEffService.valWrongCode=Request_Out_Of_Range;
//			OBDII_Neg_Response();
		}
   }
	if((OBD_stRequestResult==TRUE)&&(OBDII_EE_DATA.EE_ValSnapshot != ((Snapshot_ofDTC*)0)))
	{

		for(RDTCSSBD_m = 0; RDTCSSBD_m<OBDII_DTC_SaveSnapshot_SIZE; RDTCSSBD_m++)
		{
			OBD_stRequestResult=FALSE;
			if((ubyte)(OBDII_EE_DATA.DTCVAL_Current[RDTCSSBD_m]>>16)== OBDII_TP_stEffService.TP_valRecBuf_MP[1])
			{
				OBD_stRequestResult=TRUE;
			}
			if(OBD_stRequestResult==TRUE)
			{
				OBD_stRequestResult=FALSE;
				if((ubyte)(OBDII_EE_DATA.DTCVAL_Current[RDTCSSBD_m]>>8) == OBDII_TP_stEffService.TP_valRecBuf_MP[2])
				{
					OBD_stRequestResult=TRUE;
				}
			}
			if(OBD_stRequestResult==TRUE)
			{
				OBD_stRequestResult=FALSE;
				if(((ubyte)(OBDII_EE_DATA.DTCVAL_Current[RDTCSSBD_m])) == OBDII_TP_stEffService.TP_valRecBuf_MP[3])
				{
					OBD_stRequestResult=TRUE;
				}
			}
			if(OBD_stRequestResult==TRUE)
			{
				OBD_stRequestResult=FALSE;
				if((OBDII_EE_DATA.RecordNum[RDTCSSBD_m] == OBD_SSRecord_Num_LO)||((OBD_SSRecord_Num_LO==0xff)&&(OBDII_EE_DATA.RecordNum[RDTCSSBD_m]!=0)))
				{
					OBD_CheckPass=2;
					OBD_stRequestResult=TRUE;
				}
				else
				{
					OBD_stRequestResult=FALSE;
				}
			}
			if(OBD_stRequestResult==TRUE)
			{
				if(OBD_stRecordDTC==0)
				{
//					OBD_stRecordDTC=1;
					OBDII_TP_stEffService.TP_valSendBuf_MP[OBDII_TP_stEffService.lSendCnt]=(ubyte)(OBDII_EE_DATA.DTCVAL_Current[RDTCSSBD_m]>>16);
					OBDII_TP_stEffService.lSendCnt++;
					OBDII_TP_stEffService.TP_valSendBuf_MP[OBDII_TP_stEffService.lSendCnt]=(ubyte)(OBDII_EE_DATA.DTCVAL_Current[RDTCSSBD_m]>>8);
					OBDII_TP_stEffService.lSendCnt++;
					OBDII_TP_stEffService.TP_valSendBuf_MP[OBDII_TP_stEffService.lSendCnt]=(ubyte)(OBDII_EE_DATA.DTCVAL_Current[RDTCSSBD_m]);
					OBDII_TP_stEffService.lSendCnt++;
					OBDII_TP_stEffService.TP_valSendBuf_MP[OBDII_TP_stEffService.lSendCnt]=OBD_statusDTC;
					OBDII_TP_stEffService.lSendCnt++;
				}

				OBDII_TP_stEffService.TP_valSendBuf_MP[OBDII_TP_stEffService.lSendCnt]=(ubyte)(OBDII_EE_DATA.RecordNum[RDTCSSBD_m]);
				OBDII_TP_stEffService.lSendCnt++;

				for(RDTCSSBRN_j=0;RDTCSSBRN_j<OBDII_A_DTC_SnapshotDID_MAXNum;RDTCSSBRN_j++)
				{
					OBDII_EE_DATA.EE_ValTempSnapshot[RDTCSSBRN_j]=OBDII_EE_DATA.EE_ValCurrentSnapshot[RDTCSSBD_m*OBDII_A_DTC_SnapshotDID_MAXNum+RDTCSSBRN_j];
				}


				OBDII_TP_stEffService.TP_valSendBuf_MP[OBDII_TP_stEffService.lSendCnt]=OBDII_DTC_SnapshotList[RDTCSSBRN_k].DTC_SnapshotDID_num;
				OBDII_TP_stEffService.lSendCnt++;
				for (RDTCSSBRN_i = 0;RDTCSSBRN_i < (OBDII_DTC_SnapshotList[RDTCSSBRN_k].DTC_SnapshotDID_num); RDTCSSBRN_i++)
				{
				   OBD_valPid_LO=OBDII_DTC_SnapshotList[RDTCSSBRN_k].DTC_Snapshot_Infor[RDTCSSBRN_i].DID;
				   OBDII_TP_stEffService.TP_valSendBuf_MP[OBDII_TP_stEffService.lSendCnt]=OBD_valPid_LO/256;
				   OBDII_TP_stEffService.lSendCnt++;
				   OBDII_TP_stEffService.TP_valSendBuf_MP[OBDII_TP_stEffService.lSendCnt]=OBD_valPid_LO%256;
				   OBDII_TP_stEffService.lSendCnt++;
				   for(RDTCSSBD_p=0;RDTCSSBD_p<OBDII_DTC_SnapshotList[RDTCSSBRN_k].DTC_Snapshot_Infor[RDTCSSBRN_i].DataLength;RDTCSSBD_p++)
				   {
					 OBDII_TP_stEffService.TP_valSendBuf_MP[OBDII_TP_stEffService.lSendCnt]=*((OBDII_DTC_SnapshotList[RDTCSSBRN_k].DTC_Snapshot_Infor[RDTCSSBRN_i].DataBuff)+RDTCSSBD_p);
					 OBDII_TP_stEffService.lSendCnt++;

				   }
				}
			}
		}
	}
	if((OBD_CheckPass==0)&&(OBDII_EE_DATA.EE_ValSnapshot != ((Snapshot_ofDTC*)0)))
	{

		for(RDTCSSBD_m = 0; RDTCSSBD_m<OBDII_DTC_SaveSnapshot_SIZE; RDTCSSBD_m++)
		{
			OBD_stRequestResult=FALSE;
			if((ubyte)(OBDII_EE_DATA.DTCVAL[RDTCSSBD_m]>>16)== OBDII_TP_stEffService.TP_valRecBuf_MP[1])
			{
				OBD_stRequestResult=TRUE;
			}
			if(OBD_stRequestResult==TRUE)
			{
				OBD_stRequestResult=FALSE;
				if((ubyte)(OBDII_EE_DATA.DTCVAL[RDTCSSBD_m]>>8) == OBDII_TP_stEffService.TP_valRecBuf_MP[2])
				{
					OBD_stRequestResult=TRUE;
				}
			}
			if(OBD_stRequestResult==TRUE)
			{
				OBD_stRequestResult=FALSE;
				if(((ubyte)(OBDII_EE_DATA.DTCVAL[RDTCSSBD_m])) == OBDII_TP_stEffService.TP_valRecBuf_MP[3])
				{
					OBD_stRequestResult=TRUE;
				}
			}
			if(OBD_stRequestResult==TRUE)
			{
				OBD_stRequestResult=FALSE;
				if((OBDII_EE_DATA.RecordNum[RDTCSSBD_m] == OBD_SSRecord_Num_LO)||((OBD_SSRecord_Num_LO==0xff)))
				{
					OBD_CheckPass=1;
					OBD_stRequestResult=TRUE;
				}
				else
				{
					OBD_stRequestResult=FALSE;
				}
			}
            if(OBD_stRequestResult==TRUE)
            {
            	if(OBD_stRecordDTC==0)
            	{
//            		OBD_stRecordDTC=1;
            		OBDII_TP_stEffService.TP_valSendBuf_MP[OBDII_TP_stEffService.lSendCnt]=(ubyte)(OBDII_EE_DATA.DTCVAL[RDTCSSBD_m]>>16);
					OBDII_TP_stEffService.lSendCnt++;
					OBDII_TP_stEffService.TP_valSendBuf_MP[OBDII_TP_stEffService.lSendCnt]=(ubyte)(OBDII_EE_DATA.DTCVAL[RDTCSSBD_m]>>8);
					OBDII_TP_stEffService.lSendCnt++;
					OBDII_TP_stEffService.TP_valSendBuf_MP[OBDII_TP_stEffService.lSendCnt]=(ubyte)(OBDII_EE_DATA.DTCVAL[RDTCSSBD_m]);
					OBDII_TP_stEffService.lSendCnt++;
					OBDII_TP_stEffService.TP_valSendBuf_MP[OBDII_TP_stEffService.lSendCnt]=OBD_statusDTC;
					OBDII_TP_stEffService.lSendCnt++;
            	}

            	OBDII_TP_stEffService.TP_valSendBuf_MP[OBDII_TP_stEffService.lSendCnt]=(ubyte)(OBDII_EE_DATA.RecordNum[RDTCSSBD_m]);
				OBDII_TP_stEffService.lSendCnt++;

                for(RDTCSSBRN_j=0;RDTCSSBRN_j<OBDII_A_DTC_SnapshotDID_MAXNum;RDTCSSBRN_j++)
                {
                	OBDII_EE_DATA.EE_ValTempSnapshot[RDTCSSBRN_j]=OBDII_EE_DATA.EE_ValSnapshot[RDTCSSBD_m*OBDII_A_DTC_SnapshotDID_MAXNum+RDTCSSBRN_j];
                }


				OBDII_TP_stEffService.TP_valSendBuf_MP[OBDII_TP_stEffService.lSendCnt]=OBDII_DTC_SnapshotList[RDTCSSBRN_k].DTC_SnapshotDID_num;
				OBDII_TP_stEffService.lSendCnt++;
				for (RDTCSSBRN_i = 0;RDTCSSBRN_i < (OBDII_DTC_SnapshotList[RDTCSSBRN_k].DTC_SnapshotDID_num); RDTCSSBRN_i++)
			    {
				   OBD_valPid_LO=OBDII_DTC_SnapshotList[RDTCSSBRN_k].DTC_Snapshot_Infor[RDTCSSBRN_i].DID;
				   OBDII_TP_stEffService.TP_valSendBuf_MP[OBDII_TP_stEffService.lSendCnt]=OBD_valPid_LO/256;
				   OBDII_TP_stEffService.lSendCnt++;
				   OBDII_TP_stEffService.TP_valSendBuf_MP[OBDII_TP_stEffService.lSendCnt]=OBD_valPid_LO%256;
				   OBDII_TP_stEffService.lSendCnt++;
				   for(RDTCSSBD_p=0;RDTCSSBD_p<OBDII_DTC_SnapshotList[RDTCSSBRN_k].DTC_Snapshot_Infor[RDTCSSBRN_i].DataLength;RDTCSSBD_p++)
				   {
					 OBDII_TP_stEffService.TP_valSendBuf_MP[OBDII_TP_stEffService.lSendCnt]=*((OBDII_DTC_SnapshotList[RDTCSSBRN_k].DTC_Snapshot_Infor[RDTCSSBRN_i].DataBuff)+RDTCSSBD_p);
					 OBDII_TP_stEffService.lSendCnt++;

				   }
			    }
            }
		}
	}
	if(OBD_CheckPass==0)
	{
		if((OBD_SSRecord_Num_LO==0x01)||(OBD_SSRecord_Num_LO==0xFF))
		{
		sendbuf[0] = 0x06;
		sendbuf[1] = 0x59;
		sendbuf[2] = 0X04;
		sendbuf[3] = OBDII_TP_stEffService.TP_valRecBuf_MP[1];
		sendbuf[4] = OBDII_TP_stEffService.TP_valRecBuf_MP[2];
		sendbuf[5] = OBDII_TP_stEffService.TP_valRecBuf_MP[3];
		sendbuf[6] = 0x00;
		sendbuf[7] = 0xCC;
		OBDII_CallBack_SendAck(sendbuf,7);
		}
		else
		{
		OBDII_TP_stEffService.valWrongCode=Request_Out_Of_Range;
		OBDII_Neg_Response();
		}
	}
	else
	{
		OBDII_TP_stEffService.lServiceS=OBDII_TP_stEffService.lSendCnt;
		OBDII_Send_ResPonsReqdata();
	}

}

void ReportDtcSnapshotByRecordNumber(void)
{
	uword OBD_valPid_LO=0;
	ubyte OBD_stDTCValid_LO=0;
	ubyte OBD_stRequestResult=0;
	ubyte OBD_SSRecord_Num_LO=0;
	ubyte OBD_CheckPass=0;
	ubyte OBD_statusDTC=0;
	ubyte OBD_CheckDtcListPass=0;
	ubyte RDTCSSBRN_j,RDTCSSBRN_i,RDTCSSBRN_k,RDTCSSBD_m,RDTCSSBD_n,RDTCSSBD_l,RDTCSSBD_p;
	OBD_SSRecord_Num_LO=OBDII_TP_stEffService.TP_valRecBuf_MP[1];
	OBDII_TP_stEffService.lSendCnt=0;
	OBDII_TP_stEffService.valWrongCode=0;
	OBDII_TP_stEffService.TP_valSendBuf_MP[0]=0x05;
	OBDII_TP_stEffService.lSendCnt++;
	if(Sup_ReportDtcSnapshotByRecordNumber==ON)
	{
		OBD_stRequestResult=TRUE;
	}
	else
	{
		OBDII_TP_stEffService.valWrongCode=Sub_Function_Not_Supported;
		OBDII_Neg_Response();
	}
	if(OBD_stRequestResult==TRUE)
	{
		OBD_stRequestResult=FALSE;
		if(OBDII_TP_stEffService.lServiceR==3)
		{
			OBD_stRequestResult=TRUE;
		}
		else
		{
			OBDII_TP_stEffService.valWrongCode=Incorrect_Message_Length_Or_Invalid_Format;
			OBDII_Neg_Response();
		}
	}
	if((OBD_stRequestResult==TRUE)&&(OBDII_DTC_SnapshotList != ((Snapshot_ofDTC*)0)))
	{
		OBD_stRequestResult=FALSE;
		for(RDTCSSBD_m = 0; RDTCSSBD_m<OBDII_DTC_SaveSnapshot_SIZE; RDTCSSBD_m++)
		{
			if((OBD_SSRecord_Num_LO==OBDII_EE_DATA.RecordNum[RDTCSSBD_m])||((OBD_SSRecord_Num_LO==0xff))&&(OBDII_EE_DATA.RecordNum[RDTCSSBD_m]!=0))
			{
				OBDII_TP_stEffService.TP_valSendBuf_MP[OBDII_TP_stEffService.lSendCnt]=OBDII_EE_DATA.RecordNum[RDTCSSBD_m];
				OBDII_TP_stEffService.lSendCnt++;
				OBDII_TP_stEffService.TP_valSendBuf_MP[OBDII_TP_stEffService.lSendCnt]=(ubyte)(OBDII_EE_DATA.DTCVAL[RDTCSSBD_m]>>16);
				OBDII_TP_stEffService.lSendCnt++;
				OBDII_TP_stEffService.TP_valSendBuf_MP[OBDII_TP_stEffService.lSendCnt]=(ubyte)(OBDII_EE_DATA.DTCVAL[RDTCSSBD_m]>>8);
				OBDII_TP_stEffService.lSendCnt++;
				OBDII_TP_stEffService.TP_valSendBuf_MP[OBDII_TP_stEffService.lSendCnt]=(ubyte)(OBDII_EE_DATA.DTCVAL[RDTCSSBD_m]);
				OBDII_TP_stEffService.lSendCnt++;

				//*********xlj add end
				for(RDTCSSBRN_j = 0; RDTCSSBRN_j<OBDII_DTC_TABLE_SIZE; RDTCSSBRN_j++)
				{
					if(OBDII_DTC_Lst[RDTCSSBRN_j].DTCVAL== OBDII_EE_DATA.DTCVAL[RDTCSSBD_m])
					{
						if((DTC_st_errNum != ((Dtcst_CSTR*)0)))
						{
						  OBD_statusDTC=DTC_st_errNum[RDTCSSBRN_j].Status&OBDII_DTC_AvailabilityMask;
						}
					}
				}

				for(RDTCSSBRN_j = 0; RDTCSSBRN_j<OBDII_DTC_SupportSnapshot_SIZE; RDTCSSBRN_j++)
				{
					if(OBDII_DTC_SnapshotList[RDTCSSBRN_j].DTC_SupportSnapshot.DTCVAL== OBDII_EE_DATA.DTCVAL[RDTCSSBD_m])
					{
						if((DTC_st_errNum != ((Dtcst_CSTR*)0)))
						{
						  RDTCSSBRN_k=RDTCSSBRN_j;
						}
					}
				}
				for(RDTCSSBD_l=0;RDTCSSBD_l<OBDII_A_DTC_SnapshotDID_MAXNum;RDTCSSBD_l++)
				{
					OBDII_EE_DATA.EE_ValTempSnapshot[RDTCSSBD_l]=OBDII_EE_DATA.EE_ValSnapshot[RDTCSSBD_m*OBDII_A_DTC_SnapshotDID_MAXNum+RDTCSSBD_l];
				}

				OBDII_TP_stEffService.TP_valSendBuf_MP[OBDII_TP_stEffService.lSendCnt]=OBD_statusDTC;
				OBDII_TP_stEffService.lSendCnt++;
				OBDII_TP_stEffService.TP_valSendBuf_MP[OBDII_TP_stEffService.lSendCnt]=OBDII_DTC_SnapshotList[RDTCSSBRN_k].DTC_SnapshotDID_num;
				OBDII_TP_stEffService.lSendCnt++;
				for (RDTCSSBRN_i = 0;RDTCSSBRN_i < (OBDII_DTC_SnapshotList[RDTCSSBRN_k].DTC_SnapshotDID_num); RDTCSSBRN_i++)
				{
				   OBD_valPid_LO=OBDII_DTC_SnapshotList[RDTCSSBRN_k].DTC_Snapshot_Infor[RDTCSSBRN_i].DID;
				   OBDII_TP_stEffService.TP_valSendBuf_MP[OBDII_TP_stEffService.lSendCnt]=OBD_valPid_LO/256;
				   OBDII_TP_stEffService.lSendCnt++;
				   OBDII_TP_stEffService.TP_valSendBuf_MP[OBDII_TP_stEffService.lSendCnt]=OBD_valPid_LO%256;
				   OBDII_TP_stEffService.lSendCnt++;
				   for(RDTCSSBD_p=0;RDTCSSBD_p<OBDII_DTC_SnapshotList[RDTCSSBRN_k].DTC_Snapshot_Infor[RDTCSSBRN_i].DataLength;RDTCSSBD_p++)
				   {
						OBDII_TP_stEffService.TP_valSendBuf_MP[OBDII_TP_stEffService.lSendCnt]=*((OBDII_DTC_SnapshotList[RDTCSSBRN_k].DTC_Snapshot_Infor[RDTCSSBRN_i].DataBuff)+RDTCSSBD_p);
						OBDII_TP_stEffService.lSendCnt++;
				   }
				}
				OBD_CheckPass=1;
			}

		}
		if(OBD_CheckPass==0)
		{
			OBDII_TP_stEffService.valWrongCode=Request_Out_Of_Range;
			OBDII_Neg_Response();
		}
		else
		{
			OBDII_TP_stEffService.lServiceS=OBDII_TP_stEffService.lSendCnt;
			OBDII_Send_ResPonsReqdata();
		}
	}
}
void ReportDtcExtendDataRecordByDTCnumber(void)
{
	ubyte OBD_stRecordDTC=0;
	uword OBD_valPid_LO=0;
	ubyte OBD_stDTCValid_LO=0;
	ubyte OBD_stRequestResult=0;
	ubyte OBD_ExRecordNum=0;
	ubyte OBD_CheckPass=0;
	ubyte OBD_statusDTC=0;
	ubyte OBD_CheckDtcListPass=0;
	ubyte RDTCSSBRN_j,RDTCSSBRN_i,RDTCSSBRN_k,RDTCSSBD_m,RDTCSSBD_n,RDTCSSBD_l,RDTCSSBD_p;


	OBD_ExRecordNum=OBDII_TP_stEffService.TP_valRecBuf_MP[4];
	OBDII_TP_stEffService.lSendCnt=0;
	OBDII_TP_stEffService.valWrongCode=0;
	OBDII_TP_stEffService.TP_valSendBuf_MP[0]=0x06;
	OBDII_TP_stEffService.lSendCnt++;
	if(Sup_ReportDtcExtendDataRecordByDTCnumber==ON)
	{
		OBD_stRequestResult=TRUE;
	}
	else
	{
		OBDII_TP_stEffService.valWrongCode=Sub_Function_Not_Supported;
		OBDII_Neg_Response();
	}
	if(OBD_stRequestResult==TRUE)
	{
		OBD_stRequestResult=FALSE;
		if(OBDII_TP_stEffService.lServiceR==6)
		{
			OBD_stRequestResult=TRUE;
		}
		else
		{
			OBDII_TP_stEffService.valWrongCode=Incorrect_Message_Length_Or_Invalid_Format;
			OBDII_Neg_Response();
		}
	}

	//*********xlj add
	if(OBD_stRequestResult==TRUE)
	{
		OBD_stRequestResult=FALSE;
		for(RDTCSSBD_m = 0; RDTCSSBD_m<OBDII_DTC_TABLE_SIZE; RDTCSSBD_m++)
		{
			if((ubyte)(OBDII_DTC_Lst[RDTCSSBD_m].DTCVAL>>16) == OBDII_TP_stEffService.TP_valRecBuf_MP[1])
			{
				OBD_stRequestResult=TRUE;
			}
			if(OBD_stRequestResult==TRUE)
			{
				OBD_stRequestResult=FALSE;
				if((ubyte)(OBDII_DTC_Lst[RDTCSSBD_m].DTCVAL>>8) == OBDII_TP_stEffService.TP_valRecBuf_MP[2])
				{
					OBD_stRequestResult=TRUE;
				}
			}
			if(OBD_stRequestResult==TRUE)
			{
				OBD_stRequestResult=FALSE;
				if((ubyte)(OBDII_DTC_Lst[RDTCSSBD_m].DTCVAL) == OBDII_TP_stEffService.TP_valRecBuf_MP[3])
				{
					OBD_stRequestResult=TRUE;
					if((DTC_st_errNum != ((Dtcst_CSTR*)0)))
					{
					  OBD_statusDTC=DTC_st_errNum[RDTCSSBD_m].Status&OBDII_DTC_AvailabilityMask;
					  OBD_CheckDtcListPass=1;
					}

					break;
				}
			}
		}
		if(OBD_CheckDtcListPass==0)
		{
			OBDII_TP_stEffService.valWrongCode=Request_Out_Of_Range;
			OBDII_Neg_Response();
		}

	}
	//*********xlj add end

	if((OBD_stRequestResult==TRUE)&&(OBDII_DTC_SnapshotList != ((Snapshot_ofDTC*)0)))
	{
		OBD_stRequestResult=FALSE;
		for(RDTCSSBD_m = 0; RDTCSSBD_m<OBDII_DTC_SupportSnapshot_SIZE; RDTCSSBD_m++)
		{
			if((ubyte)(OBDII_DTC_SnapshotList[RDTCSSBD_m].DTC_SupportSnapshot.DTCVAL>>16)== OBDII_TP_stEffService.TP_valRecBuf_MP[1])
			{
				OBD_stRequestResult=TRUE;
			}
			if(OBD_stRequestResult==TRUE)
			{
				OBD_stRequestResult=FALSE;
				if((ubyte)(OBDII_DTC_SnapshotList[RDTCSSBD_m].DTC_SupportSnapshot.DTCVAL>>8) == OBDII_TP_stEffService.TP_valRecBuf_MP[2])
				{
					OBD_stRequestResult=TRUE;
				}
			}
			if(OBD_stRequestResult==TRUE)
			{
				OBD_stRequestResult=FALSE;
				if(((ubyte)(OBDII_DTC_SnapshotList[RDTCSSBD_m].DTC_SupportSnapshot.DTCVAL)) == OBDII_TP_stEffService.TP_valRecBuf_MP[3])
				{
					OBD_stRequestResult=TRUE;
					OBD_CheckPass=1;
					RDTCSSBRN_k=RDTCSSBD_m;
					break;
				}
			}
		}
		if(OBD_CheckPass==0)
		{
			OBDII_TP_stEffService.valWrongCode=Request_Out_Of_Range;
			OBDII_Neg_Response();
		}
	}
	if((OBD_stRequestResult==TRUE)&&(OBDII_DTC_SnapshotList != ((Snapshot_ofDTC*)0)))
		{
			OBD_stRequestResult=FALSE;
			for(RDTCSSBD_m = 0; RDTCSSBD_m<OBDII_DTC_SaveSnapshot_SIZE; RDTCSSBD_m++)
			{
				if((ubyte)(OBDII_EE_DATA.DTCVAL_Current[RDTCSSBD_m]>>16)== OBDII_TP_stEffService.TP_valRecBuf_MP[1])
				{
					OBD_stRequestResult=TRUE;
				}
				if(OBD_stRequestResult==TRUE)
				{
					OBD_stRequestResult=FALSE;
					if((ubyte)(OBDII_EE_DATA.DTCVAL_Current[RDTCSSBD_m]>>8) == OBDII_TP_stEffService.TP_valRecBuf_MP[2])
					{
						OBD_stRequestResult=TRUE;
					}
				}
				if(OBD_stRequestResult==TRUE)
				{
					OBD_stRequestResult=FALSE;
					if(((ubyte)(OBDII_EE_DATA.DTCVAL_Current[RDTCSSBD_m])) == OBDII_TP_stEffService.TP_valRecBuf_MP[3])
					{
						OBD_stRequestResult=TRUE;
					}
				}
				if(OBD_stRequestResult==TRUE)
				{
					OBD_stRequestResult=FALSE;
					if((((ubyte)(OBDII_EE_DATA.RecordNum[RDTCSSBD_m])) == OBD_ExRecordNum)||(OBD_ExRecordNum==0xff))
					{

						OBD_stRequestResult=TRUE;

					}
				}
				if(OBD_stRequestResult==TRUE)
				{
					if(OBD_stRecordDTC==0)
					{
						OBD_stRecordDTC=1;
						OBDII_TP_stEffService.TP_valSendBuf_MP[OBDII_TP_stEffService.lSendCnt]=(ubyte)(OBDII_EE_DATA.DTCVAL_Current[RDTCSSBD_m]>>16);
						OBDII_TP_stEffService.lSendCnt++;
						OBDII_TP_stEffService.TP_valSendBuf_MP[OBDII_TP_stEffService.lSendCnt]=(ubyte)(OBDII_EE_DATA.DTCVAL_Current[RDTCSSBD_m]>>8);
						OBDII_TP_stEffService.lSendCnt++;
						OBDII_TP_stEffService.TP_valSendBuf_MP[OBDII_TP_stEffService.lSendCnt]=(ubyte)(OBDII_EE_DATA.DTCVAL_Current[RDTCSSBD_m]);
						OBDII_TP_stEffService.lSendCnt++;
						OBDII_TP_stEffService.TP_valSendBuf_MP[OBDII_TP_stEffService.lSendCnt]=OBD_statusDTC;
						OBDII_TP_stEffService.lSendCnt++;
					}

					OBDII_TP_stEffService.TP_valSendBuf_MP[OBDII_TP_stEffService.lSendCnt]=(ubyte)(OBDII_EE_DATA.RecordNum[RDTCSSBD_m]);
					OBDII_TP_stEffService.lSendCnt++;

					for(RDTCSSBRN_j=0;RDTCSSBRN_j<OBDII_A_DTC_SnapshotExt_MAXNum;RDTCSSBRN_j++)
					{
						OBDII_EE_DATA.EE_ValTempExtended[RDTCSSBRN_j]=OBDII_EE_DATA.EE_ValCurrentExtended[RDTCSSBD_m*OBDII_A_DTC_SnapshotExt_MAXNum+RDTCSSBRN_j];
					}

					for (RDTCSSBRN_i = 0;RDTCSSBRN_i < (OBDII_DTC_SnapshotList[RDTCSSBRN_k].DTC_ExtDataLen); RDTCSSBRN_i++)
					{
						 OBDII_TP_stEffService.TP_valSendBuf_MP[OBDII_TP_stEffService.lSendCnt]=*((OBDII_DTC_SnapshotList[RDTCSSBRN_k].DTC_Ext_Infor+RDTCSSBRN_i));
						 OBDII_TP_stEffService.lSendCnt++;
					}

					OBD_stDTCValid_LO=2;
				}
			}
		}
	if((OBD_stRequestResult==TRUE)&&(OBD_stDTCValid_LO==0)&&(OBDII_DTC_SnapshotList != ((Snapshot_ofDTC*)0)))
	{
		OBD_stRequestResult=FALSE;
		for(RDTCSSBD_m = 0; RDTCSSBD_m<OBDII_DTC_SaveSnapshot_SIZE; RDTCSSBD_m++)
	    {
			if((ubyte)(OBDII_EE_DATA.DTCVAL[RDTCSSBD_m]>>16)== OBDII_TP_stEffService.TP_valRecBuf_MP[1])
			{
				OBD_stRequestResult=TRUE;
			}
			if(OBD_stRequestResult==TRUE)
			{
				OBD_stRequestResult=FALSE;
				if((ubyte)(OBDII_EE_DATA.DTCVAL[RDTCSSBD_m]>>8) == OBDII_TP_stEffService.TP_valRecBuf_MP[2])
				{
					OBD_stRequestResult=TRUE;
				}
			}
			if(OBD_stRequestResult==TRUE)
			{
				OBD_stRequestResult=FALSE;
				if(((ubyte)(OBDII_EE_DATA.DTCVAL[RDTCSSBD_m])) == OBDII_TP_stEffService.TP_valRecBuf_MP[3])
				{
					OBD_stRequestResult=TRUE;
				}
			}
			if(OBD_stRequestResult==TRUE)
			{
				OBD_stRequestResult=FALSE;
				if((((ubyte)(OBDII_EE_DATA.RecordNum[RDTCSSBD_m])) == OBD_ExRecordNum)||(OBD_ExRecordNum==0xff))
				{

					OBD_stRequestResult=TRUE;

				}
			}
			if(OBD_stRequestResult==TRUE)
			{
				if(OBD_stRecordDTC==0)
				{
					OBD_stRecordDTC=1;
					OBDII_TP_stEffService.TP_valSendBuf_MP[OBDII_TP_stEffService.lSendCnt]=(ubyte)(OBDII_EE_DATA.DTCVAL[RDTCSSBD_m]>>16);
					OBDII_TP_stEffService.lSendCnt++;
					OBDII_TP_stEffService.TP_valSendBuf_MP[OBDII_TP_stEffService.lSendCnt]=(ubyte)(OBDII_EE_DATA.DTCVAL[RDTCSSBD_m]>>8);
					OBDII_TP_stEffService.lSendCnt++;
					OBDII_TP_stEffService.TP_valSendBuf_MP[OBDII_TP_stEffService.lSendCnt]=(ubyte)(OBDII_EE_DATA.DTCVAL[RDTCSSBD_m]);
					OBDII_TP_stEffService.lSendCnt++;
					OBDII_TP_stEffService.TP_valSendBuf_MP[OBDII_TP_stEffService.lSendCnt]=OBD_statusDTC;
					OBDII_TP_stEffService.lSendCnt++;
				}

				OBDII_TP_stEffService.TP_valSendBuf_MP[OBDII_TP_stEffService.lSendCnt]=(ubyte)(OBDII_EE_DATA.RecordNum[RDTCSSBD_m]);
				OBDII_TP_stEffService.lSendCnt++;

				for(RDTCSSBRN_j=0;RDTCSSBRN_j<OBDII_A_DTC_SnapshotExt_MAXNum;RDTCSSBRN_j++)
				{
					OBDII_EE_DATA.EE_ValTempExtended[RDTCSSBRN_j]=OBDII_EE_DATA.EE_ValExtended[RDTCSSBD_m*OBDII_A_DTC_SnapshotExt_MAXNum+RDTCSSBRN_j];
				}

				for (RDTCSSBRN_i = 0;RDTCSSBRN_i < (OBDII_DTC_SnapshotList[RDTCSSBRN_k].DTC_ExtDataLen); RDTCSSBRN_i++)
				{
					 OBDII_TP_stEffService.TP_valSendBuf_MP[OBDII_TP_stEffService.lSendCnt]=*((OBDII_DTC_SnapshotList[RDTCSSBRN_k].DTC_Ext_Infor+RDTCSSBRN_i));
					 OBDII_TP_stEffService.lSendCnt++;
				}

				OBD_stDTCValid_LO=1;
		    }
	    }
	}

	if(OBD_stDTCValid_LO != 0)
	{
		OBDII_TP_stEffService.lServiceS=OBDII_TP_stEffService.lSendCnt;
		OBDII_Send_ResPonsReqdata();
	}
	else if(OBD_stRequestResult==TRUE)
	{
		OBDII_TP_stEffService.valWrongCode=Request_Out_Of_Range;
		OBDII_Neg_Response();
	}
}
void ReportNumberOfDtcBySeverityMaskRecord(void)
{
	ubyte DTC_NumCurrent_LO=0;
	ubyte DTC_Mask=0;
	ubyte OBD_stRequestResult=0;
	ubyte RNDTCBSMR_i;
	DTC_Mask=OBDII_TP_stEffService.TP_valRecBuf_MP[1];
	OBDII_TP_stEffService.TP_valSendBuf_MP[0]=0x07;
	OBDII_TP_stEffService.lSendCnt++;
	OBDII_TP_stEffService.TP_valSendBuf_MP[1]=OBDII_DTC_AvailabilityMask;
	OBDII_TP_stEffService.lSendCnt++;
	OBDII_TP_stEffService.lSendCnt=0;
	OBDII_TP_stEffService.valWrongCode=0;
	if(Sup_ReportNumberOfDtcBySeverityMaskRecord==ON)
	{
		OBD_stRequestResult=TRUE;
	}
	else
	{
		OBDII_TP_stEffService.valWrongCode=Sub_Function_Not_Supported;
		OBDII_Neg_Response();
	}
	if(OBD_stRequestResult==TRUE)
	{
		OBD_stRequestResult=FALSE;
		if(OBDII_TP_stEffService.lServiceR==4)
		{
			OBD_stRequestResult=TRUE;
		}
		else
		{
			OBDII_TP_stEffService.valWrongCode=Incorrect_Message_Length_Or_Invalid_Format;
			OBDII_Neg_Response();
		}
    }
	if((OBD_stRequestResult==TRUE)&&(DTC_st_errNum != ((Dtcst_CSTR*)0)))
	{
		for(RNDTCBSMR_i = 0; RNDTCBSMR_i< (OBDII_DTC_TABLE_SIZE); RNDTCBSMR_i++)
		{
			if(DTC_st_errNum[RNDTCBSMR_i].Status&DTC_Mask)
			{
				DTC_NumCurrent_LO++;
			}
		}
		OBDII_TP_stEffService.TP_valSendBuf_MP[1]=DTC_NumCurrent_LO;
		OBDII_TP_stEffService.lSendCnt++;
		OBDII_TP_stEffService.lServiceS=OBDII_TP_stEffService.lSendCnt;
		OBDII_Send_ResPonsReqdata();
	}
}
void ReportDtcBySeverityMaskRecord(void)
{
	ubyte DTC_Mask=0;
	ubyte OBD_stRequestResult=0;
	ubyte RDBSMR_i;
	OBDII_TP_stEffService.lSendCnt=0;
	OBDII_TP_stEffService.valWrongCode=0;
	DTC_Mask=OBDII_TP_stEffService.TP_valRecBuf_MP[1];
	OBDII_TP_stEffService.TP_valSendBuf_MP[0]=0x08;
	OBDII_TP_stEffService.lSendCnt++;
	OBDII_TP_stEffService.TP_valSendBuf_MP[1]=OBDII_DTC_AvailabilityMask;
	OBDII_TP_stEffService.lSendCnt++;
	if(Sup_ReportDtcBySeverityMaskRecord==ON)
	{
		OBD_stRequestResult=TRUE;
	}
	else
	{
		OBDII_TP_stEffService.valWrongCode=Sub_Function_Not_Supported;
		OBDII_Neg_Response();
	}
	if(OBD_stRequestResult==TRUE)
	{
		OBD_stRequestResult=FALSE;
		if(OBDII_TP_stEffService.lServiceR==4)
		{
			OBD_stRequestResult=TRUE;
		}
		else
		{
			OBDII_TP_stEffService.valWrongCode=Incorrect_Message_Length_Or_Invalid_Format;
			OBDII_Neg_Response();
		}
	}
	if((OBD_stRequestResult==TRUE)&&(DTC_st_errNum != ((Dtcst_CSTR*)0)))
	{
		for (RDBSMR_i = 0; RDBSMR_i < (OBDII_DTC_TABLE_SIZE); RDBSMR_i++)
		{
			if(DTC_st_errNum[RDBSMR_i].Status&DTC_Mask)
			{
				OBDII_TP_stEffService.TP_valSendBuf_MP[OBDII_TP_stEffService.lSendCnt]=(ubyte)(OBDII_DTC_Lst[RDBSMR_i].DTCVAL>>16);
				OBDII_TP_stEffService.lSendCnt++;
				OBDII_TP_stEffService.TP_valSendBuf_MP[OBDII_TP_stEffService.lSendCnt]=(ubyte)(OBDII_DTC_Lst[RDBSMR_i].DTCVAL>>8);
				OBDII_TP_stEffService.lSendCnt++;
				OBDII_TP_stEffService.TP_valSendBuf_MP[OBDII_TP_stEffService.lSendCnt]=(ubyte)(OBDII_DTC_Lst[RDBSMR_i].DTCVAL);
				OBDII_TP_stEffService.lSendCnt++;
				OBDII_TP_stEffService.TP_valSendBuf_MP[OBDII_TP_stEffService.lSendCnt]=DTC_st_errNum[RDBSMR_i].Status&OBDII_DTC_AvailabilityMask;
				OBDII_TP_stEffService.lSendCnt++;
			}
		}
		OBDII_TP_stEffService.lServiceS=OBDII_TP_stEffService.lSendCnt;
		OBDII_Send_ResPonsReqdata();
	}
}
void ReportSeverityInformOfDTC(void)
{
	ubyte OBD_stRequestResult=0;
	if(Sup_ReportSeverityInformOfDTC==ON)
	{
		OBD_stRequestResult=TRUE;
	}
	else
	{
		OBDII_TP_stEffService.valWrongCode=Sub_Function_Not_Supported;
		OBDII_Neg_Response();
	}
	if(OBD_stRequestResult==TRUE)
	{
		OBD_stRequestResult=FALSE;
		if(OBDII_TP_stEffService.lServiceR==4)
		{
			OBD_stRequestResult=TRUE;
		}
		else
		{
			OBDII_TP_stEffService.valWrongCode=Incorrect_Message_Length_Or_Invalid_Format;
			OBDII_Neg_Response();
		}
	}
}
void ReportSuppedDTC(void)
{
	ubyte DTC_Mask=0;
	ubyte OBD_stRequestResult=0;
	uword RSDTC_i = 0;
	OBDII_TP_stEffService.lSendCnt = 0;
	OBDII_TP_stEffService.valWrongCode = 0;
	DTC_Mask=OBDII_TP_stEffService.TP_valRecBuf_MP[0];
	OBDII_TP_stEffService.TP_valSendBuf_MP[0]=0x0A;
	OBDII_TP_stEffService.lSendCnt++;
	OBDII_TP_stEffService.TP_valSendBuf_MP[1]=OBDII_DTC_AvailabilityMask;
	OBDII_TP_stEffService.lSendCnt++;
	if(Sup_ReportSuppedDTC==ON)
	{
		OBD_stRequestResult=TRUE;
	}
	else
	{
		OBDII_TP_stEffService.valWrongCode=Sub_Function_Not_Supported;
		OBDII_Neg_Response();
	}
	if(OBD_stRequestResult==TRUE)
	{
		OBD_stRequestResult=FALSE;
		if(OBDII_TP_stEffService.lServiceR==2)
		{
			OBD_stRequestResult=TRUE;
		}
		else
		{
			OBDII_TP_stEffService.valWrongCode=Incorrect_Message_Length_Or_Invalid_Format;
			OBDII_Neg_Response();
		}
	}
	if((OBD_stRequestResult==TRUE)&&(DTC_st_errNum != ((Dtcst_CSTR*)0)))
	{
		OBD_stRequestResult=FALSE;
		for (RSDTC_i = 0; RSDTC_i < (OBDII_DTC_TABLE_SIZE); RSDTC_i++)
		{
			OBDII_TP_stEffService.TP_valSendBuf_MP[OBDII_TP_stEffService.lSendCnt]=(ubyte)(OBDII_DTC_Lst[RSDTC_i].DTCVAL>>16);
			OBDII_TP_stEffService.lSendCnt++;
			OBDII_TP_stEffService.TP_valSendBuf_MP[OBDII_TP_stEffService.lSendCnt]=(ubyte)(OBDII_DTC_Lst[RSDTC_i].DTCVAL>>8);
			OBDII_TP_stEffService.lSendCnt++;
			OBDII_TP_stEffService.TP_valSendBuf_MP[OBDII_TP_stEffService.lSendCnt]=(ubyte)(OBDII_DTC_Lst[RSDTC_i].DTCVAL);
			OBDII_TP_stEffService.lSendCnt++;
			OBDII_TP_stEffService.TP_valSendBuf_MP[OBDII_TP_stEffService.lSendCnt]=DTC_st_errNum[RSDTC_i].Status&OBDII_DTC_AvailabilityMask;
			OBDII_TP_stEffService.lSendCnt++;
		}
		OBDII_TP_stEffService.lServiceS=OBDII_TP_stEffService.lSendCnt;
		OBDII_Send_ResPonsReqdata();
	}
}
void ReportFirstTestFailedDTC(void)
{
	 ubyte DTC_Mask=0;
	 ubyte OBD_stRequestResult=0;
	 OBDII_TP_stEffService.lSendCnt = 0;
	 OBDII_TP_stEffService.valWrongCode = 0;
	 DTC_Mask=OBDII_TP_stEffService.TP_valRecBuf_MP[0];
	 OBDII_TP_stEffService.TP_valSendBuf_MP[0]=0x0B;
	 OBDII_TP_stEffService.lSendCnt++;
	 OBDII_TP_stEffService.TP_valSendBuf_MP[1]=OBDII_DTC_AvailabilityMask;
	 OBDII_TP_stEffService.lSendCnt++;
	 if(Sup_ReportFirstTestFailedDTC==ON)
	 {
		OBD_stRequestResult=TRUE;
	 }
	 else
	 {
		OBDII_TP_stEffService.valWrongCode=Sub_Function_Not_Supported;
		OBDII_Neg_Response();
	 }
	 if(OBD_stRequestResult==TRUE)
	 {
		OBD_stRequestResult=FALSE;
		 if(OBDII_TP_stEffService.lServiceR==2)
		 {
			OBD_stRequestResult=TRUE;
		 }
		 else
		 {
			OBDII_TP_stEffService.valWrongCode=Incorrect_Message_Length_Or_Invalid_Format;
			OBDII_Neg_Response();
		 }
	 }
	 if(OBD_stRequestResult==TRUE)
	 {
	   OBDII_TP_stEffService.TP_valSendBuf_MP[OBDII_TP_stEffService.lSendCnt]=(ubyte)(OBDII_DTC_FstTestFail.DTCVAL>>16);
	   OBDII_TP_stEffService.lSendCnt++;
	   OBDII_TP_stEffService.TP_valSendBuf_MP[OBDII_TP_stEffService.lSendCnt]=(ubyte)(OBDII_DTC_FstTestFail.DTCVAL>>8);
	   OBDII_TP_stEffService.lSendCnt++;
	   OBDII_TP_stEffService.TP_valSendBuf_MP[OBDII_TP_stEffService.lSendCnt]=(ubyte)(OBDII_DTC_FstTestFail.DTCVAL);
	   OBDII_TP_stEffService.lSendCnt++;
	   OBDII_TP_stEffService.lServiceS=OBDII_TP_stEffService.lSendCnt;
	   OBDII_Send_ResPonsReqdata();
	 }
}
void ReportFirstCofirmedDTC(void)
{
	 ubyte DTC_Mask=0;
	 ubyte OBD_stRequestResult=0;
	 OBDII_TP_stEffService.lSendCnt = 0;
	 OBDII_TP_stEffService.valWrongCode = 0;
	 DTC_Mask=OBDII_TP_stEffService.TP_valRecBuf_MP[0];
	 OBDII_TP_stEffService.TP_valSendBuf_MP[0]=0x0C;
	 OBDII_TP_stEffService.lSendCnt++;
	 OBDII_TP_stEffService.TP_valSendBuf_MP[1]=OBDII_DTC_AvailabilityMask;
	 OBDII_TP_stEffService.lSendCnt++;
	 if(Sup_ReportFirstCofirmedDTC==ON)
	{
	   OBD_stRequestResult=TRUE;
	}
	else
	{
	   OBDII_TP_stEffService.valWrongCode=Sub_Function_Not_Supported;
	   OBDII_Neg_Response();
	}
	if(OBD_stRequestResult==TRUE)
	{
		 if(OBDII_TP_stEffService.lServiceR==2)
		 {
			OBD_stRequestResult=TRUE;
		 }
		 else
		 {
			OBDII_TP_stEffService.valWrongCode=Incorrect_Message_Length_Or_Invalid_Format;
			OBDII_Neg_Response();
		 }
	 }
	 if(OBD_stRequestResult==TRUE)
	 {

	   OBDII_TP_stEffService.TP_valSendBuf_MP[OBDII_TP_stEffService.lSendCnt]=(ubyte)(OBDII_DTC_FstConfirmed.DTCVAL>>16);
	   OBDII_TP_stEffService.lSendCnt++;
	   OBDII_TP_stEffService.TP_valSendBuf_MP[OBDII_TP_stEffService.lSendCnt]=(ubyte)(OBDII_DTC_FstConfirmed.DTCVAL>>8);
	   OBDII_TP_stEffService.lSendCnt++;
	   OBDII_TP_stEffService.TP_valSendBuf_MP[OBDII_TP_stEffService.lSendCnt]=(ubyte)(OBDII_DTC_FstConfirmed.DTCVAL);
	   OBDII_TP_stEffService.lSendCnt++;
	   OBDII_TP_stEffService.lServiceS=OBDII_TP_stEffService.lSendCnt;
	   OBDII_Send_ResPonsReqdata();
	 }
}
void ReportDTCWithPermanentStatus(void)
{
	ubyte DTC_Mask=0;
	ubyte OBD_stRequestResult=0;
	uword RSDTC_i = 0;
	OBDII_TP_stEffService.lSendCnt = 0;
	OBDII_TP_stEffService.valWrongCode = 0;
	DTC_Mask=OBDII_TP_stEffService.TP_valRecBuf_MP[0];
	OBDII_TP_stEffService.TP_valSendBuf_MP[0]=0x15;
	OBDII_TP_stEffService.lSendCnt++;
	OBDII_TP_stEffService.TP_valSendBuf_MP[1]=OBDII_DTC_AvailabilityMask;
	OBDII_TP_stEffService.lSendCnt++;
	if(Sup_ReportDTCWithPermanentStatus==ON)
	{
		OBD_stRequestResult=TRUE;
	}
	else
	{
		OBDII_TP_stEffService.valWrongCode=Sub_Function_Not_Supported;
		OBDII_Neg_Response();
	}
	if(OBD_stRequestResult==TRUE)
	{
		OBD_stRequestResult=FALSE;
		if(OBDII_TP_stEffService.lServiceR==2)
		{
			OBD_stRequestResult=TRUE;
		}
		else
		{
			OBDII_TP_stEffService.valWrongCode=Incorrect_Message_Length_Or_Invalid_Format;
			OBDII_Neg_Response();
		}
	}
	if((OBD_stRequestResult==TRUE)&&(DTC_st_errNum != ((Dtcst_CSTR*)0)))
	{
//		for (RSDTC_i = 0; RSDTC_i < (OBDII_DTC_TABLE_SIZE); RSDTC_i++)
//		{
//		  if(OBDII_EE_DATA.EE_stDtc[RSDTC_i].OBDII_DTC_PermanentStatus)
//		  {
//			OBDII_TP_stEffService.TP_valSendBuf_MP[OBDII_TP_stEffService.lSendCnt]=(ubyte)(OBDII_DTC_Lst[RSDTC_i].DTCVAL);
//			OBDII_TP_stEffService.lSendCnt++;
//			OBDII_TP_stEffService.TP_valSendBuf_MP[OBDII_TP_stEffService.lSendCnt]=(ubyte)(OBDII_DTC_Lst[RSDTC_i].DTCVAL);
//			OBDII_TP_stEffService.lSendCnt++;
//			OBDII_TP_stEffService.TP_valSendBuf_MP[OBDII_TP_stEffService.lSendCnt]=(ubyte)(OBDII_DTC_Lst[RSDTC_i].DTCVAL);
//			OBDII_TP_stEffService.lSendCnt++;
//			OBDII_TP_stEffService.TP_valSendBuf_MP[OBDII_TP_stEffService.lSendCnt]=DTC_st_errNum[RSDTC_i].Status&OBDII_DTC_AvailabilityMask;
//			OBDII_TP_stEffService.lSendCnt++;
//		  }
//		}
//		OBDII_TP_stEffService.lServiceS=OBDII_TP_stEffService.lSendCnt;
//		OBDII_Send_ResPonsReqdata();
	}
}
void DiagSeon_Timer(void)
{
	static ubyte DT_numCrOverTime_LO = 0;
	if((UDS_stDiagSeon==2)||(UDS_stDiagSeon==3))
	{
		if(UDS_tiDiagSeon>SessionTime)
		{
			UDS_stDiagSeon=1;
			OBDII_CallBack_Current_DiagSession(UDS_stDiagSeon);
			UDS_tiDiagSeon=0;
			UDS_ValSecLev=0;
			UDS_ValSecLev_last = 0;
			OBDII_flgReqSeedNum=0;
			UDS_stCtlDTC=0x01;

			OBDII_CallBack_ResetRountine_Execute();
			OBDII_VauRcRecor.OBDII_numRecordRC_Mp=0xff;
			OBDII_VauRcRecor.OBDII_stExcRcSession=UDS_stDiagSeon;
			OBDII_VauRcRecor.OBDII_stExcReturnValue=0;
			OBDII_VauRcRecor.OBDII_flagExcStartRc=0;
		}
		else
		{
			if(UDS_tiDiagSeon==TesterPresentTime)
			{
				CANSendForbid_st=0;
				CANRecForbid_st=0;
			}
			UDS_tiDiagSeon++;
		}
	}

	if(UDS_stDiagSeonLast != UDS_stDiagSeon)
	{
		UDS_ValSecLev=0;
		UDS_ValSecLev_last = 0;
		OBDII_flgReqSeedNum=0;
		UDS_tiDiagSeon = 0;
		UDS_stDiagSeonLast = UDS_stDiagSeon;
	}

	if(OBDII_TP_FrameControl == 2)
	{
		if(DT_numCrOverTime_LO<25)
			DT_numCrOverTime_LO++;
		else
			OBDII_TP_FrameControl = 0;
	}
	else
	{
		DT_numCrOverTime_LO = 0;
	}
}

void Securiry_Timer(void)
{
    static uword Security_Delay=0;

//    static ubyte OBDII_flgSecDelay_Mp=0;
	static ubyte OBDII_flgStartDelay_Mp=0;
    if((*OBDII_EE_DATA.EE_numEntryfailPoint==OBDII_TimeSec_Mp.InvalidKeyNum)&&(OBDII_TimeSec_Mp.InvalidKeyEnable==TRUE))
    {
       OBDII_TiSec_Mp=OBDII_TimeSec_Mp.InvalidKeyTime;
	   OBDII_flgStartDelay_Mp=1;
    }
	else if((OBDII_flgReqSeedNum==OBDII_TimeSec_Mp.ConSeedRequestNum)&&(OBDII_TimeSec_Mp.ConSeedRequestNum!=0)&&(OBDII_TimeSec_Mp.ConSeedRequesEnable==TRUE))
    {
       OBDII_TiSec_Mp=OBDII_TimeSec_Mp.InvalidKeyTime;
	   OBDII_flgStartDelay_Mp=1;
    }
	else
	{
		OBDII_TiSec_Mp=0;
	}
	if((Security_FAA_st==1)&&(OBDII_TimeSec_Mp.IgOnRestTimeEnable==TRUE))
	{
	   Security_Delay=0;
	   Security_FAA_st=0;
	}
	else if((Security_FAA_st==1)&&(OBDII_TimeSec_Mp.IgOnRestTimeEnable==FALSE))
	{
	   Security_Delay=*OBDII_EE_DATA.EE_TiSec;
	   Security_FAA_st=0;
	}
	if(OBDII_flgStartDelay_Mp==1)
	{
		if(Security_Delay<OBDII_TiSec_Mp)
		{
			Security_Delay++;
			Security_Timer_Flg=1;
		}
		else
		{
		    OBDII_flgStartDelay_Mp=0;
			Security_Delay=0;
			Security_Timer_Flg=0;
			Security_FAA_st=0;
			OBDII_flgReqSeedNum=0;
//			if(*OBDII_EE_DATA.EE_numEntryfailPoint==3)
//			{
////			*OBDII_EE_DATA.EE_numEntryfailPoint = *OBDII_EE_DATA.EE_numEntryfailPoint - 1;
//				*OBDII_EE_DATA.EE_numEntryfailPoint = 0;
//			}
			*OBDII_EE_DATA.EE_numEntryfailPoint = 0;
		}
	}

}
UDS_Version OBDII_UDS_Version;
UDS_Version Gets_UDS_Version(void)
{
	OBDII_UDS_Version.UDS_Version1=0;
	OBDII_UDS_Version.UDS_Version2=3;
	OBDII_UDS_Version.UDS_Version_Year=20;
	OBDII_UDS_Version.UDS_Version_Month=2;
	OBDII_UDS_Version.UDS_Version_Day=13;
	return OBDII_UDS_Version;
}
extern void Config_TimeParameter(uword P2Server_LO,uword P2_Server_LO,uword SessionTime_LO,uword TesterPresentTime_LO)
{
	P2Server=P2Server_LO;
	P2_Server=P2_Server_LO;
	SessionTime=SessionTime_LO;
	TesterPresentTime=TesterPresentTime_LO;
}

void Config_SecurityLevel_Variant(ubyte OBDII_Level_LO)
{
	Security_lib_Level1=OBDII_Level_LO;
}
void Config_SecurityLevel_Control(ubyte OBDII_Level_LO)
{
	Security_lib_Level2=OBDII_Level_LO;
}
void Config_Support_Service_num(ubyte OBDII_configsize_LO,const Service_CSTR *SrcBufferPtr_LO)
{
	OBDII_Support_Service_num=OBDII_configsize_LO;
	if(SrcBufferPtr_LO != ((Service_CSTR*)0))
	{
		OBDII_Service_demondLst=SrcBufferPtr_LO;
	}
}
void Config_PID_InOut_SIZE(ubyte OBDII_configsize_LO,const uds_InOut_Ctrl *SrcBufferPtr_LO)
{
	OBDII_PID_InOut_SIZE=OBDII_configsize_LO;
	if(SrcBufferPtr_LO != ((uds_InOut_Ctrl*)0))
	{
		OBDII_InOut_ParaLst=SrcBufferPtr_LO;
	}
}
void Config_Routine_Data_SIZE(ubyte OBDII_configsize_LO,const Routine_CSTR *SrcBufferPtr_LO)
{
	OBDII_Routine_Data_SIZE=OBDII_configsize_LO;
	if(SrcBufferPtr_LO != ((Routine_CSTR*)0))
	{
		OBDII_Routine_DATA=SrcBufferPtr_LO;
	}
}
void Config_Veh_Data_SIZE(ubyte OBDII_configsize_LO,const VehData_CSTR *SrcBufferPtr_LO)
{
	OBDII_Veh_Data_SIZE=OBDII_configsize_LO;
	if(SrcBufferPtr_LO != ((VehData_CSTR*)0))
	{
		OBD_Veh_InfLst=SrcBufferPtr_LO;
	}
}
void Config_PID_TABLE_SIZE(ubyte OBDII_configsize_LO, DiagData_CSTR *SrcBufferPtr_LO)
{
	OBDII_PID_TABLE_SIZE=OBDII_configsize_LO;
	if(SrcBufferPtr_LO != ((DiagData_CSTR*)0))
	{
		OBDII_DD_PidLst=SrcBufferPtr_LO;
	}
}
void Config_OBDPID_TABLE_SIZE(ubyte OBDII_configsize_LO,const OBD_DiagData_Inf *SrcBufferPtr_LO)
{

	OBD_PID_SIZE=OBDII_configsize_LO;
	if(SrcBufferPtr_LO != ((DiagData_CSTR*)0))
	{
		OBDII_PidLst=SrcBufferPtr_LO;
	}

}

void Config_OBDVeh_TABLE_SIZE(ubyte OBDII_configsize_LO,const OBD_VehData_Inf *SrcBufferPtr_LO)
{
	OBD_VehData_SIZE=OBDII_configsize_LO;
	if(SrcBufferPtr_LO != ((DiagData_CSTR*)0))
	{
		OBDII_VehPidLst=SrcBufferPtr_LO;
	}

}


void Config_DTCAvailabilityMask_Ex(ubyte OBDII_valMask_LO)
{
	OBDII_DTC_AvailabilityMask=OBDII_valMask_LO;
}
void Config_DTC_TABLE_SIZE(ubyte OBDII_configsize_LO,const DtcType_CSTR *SrcDtcListBufferPtr_LO,Dtcst_CSTR *SrcDtcStBufferPtr_LO)
{
	OBDII_DTC_TABLE_SIZE=OBDII_configsize_LO;
	if(SrcDtcListBufferPtr_LO != ((DtcType_CSTR*)0))
	{
		OBDII_DTC_Lst=SrcDtcListBufferPtr_LO;
	}
	if(SrcDtcStBufferPtr_LO != ((Dtcst_CSTR*)0))
	{
		DTC_st_errNum=SrcDtcStBufferPtr_LO;
	}
}
void Config_DTC_SupportSnapshot_SIZE(ubyte OBDII_configsize_LO,const Snapshot_ofDTC *SrcBufferPtr_LO,ubyte OBDII_SuppEEconfigsize_LO,const ubyte  *SrcTempBufferPtr_LO)
{
	OBDII_DTC_SupportSnapshot_SIZE=OBDII_configsize_LO;
	if(SrcBufferPtr_LO != ((Snapshot_ofDTC*)0))
	{
		OBDII_DTC_SnapshotList=SrcBufferPtr_LO;
	}
	OBDII_DTC_SaveSnapshot_SIZE=OBDII_SuppEEconfigsize_LO;
    if(SrcTempBufferPtr_LO!=((ubyte*)0))
    {
    	OBDII_DTC_TempSnapshotList=SrcTempBufferPtr_LO;
    }

}
void Config_A_DTC_SnapshotDID_MAXNum(ubyte OBDII_configsize_LO,ubyte OBDII_Extconfigsize_LO)
{
	OBDII_A_DTC_SnapshotDID_MAXNum=OBDII_configsize_LO;
	OBDII_A_DTC_SnapshotExt_MAXNum=OBDII_Extconfigsize_LO;
}
void Config_DTC_ConfirmNum(ubyte OBDII_confignum_LO)
{
	OBDII_num_DTCConfirm=OBDII_confignum_LO;
}
void Config_Security_NumAndTimer(Sec_ActTimer OBDII_TimeSec_LO)
{

    OBDII_TimeSec_Mp=OBDII_TimeSec_LO;
//	if(OBDII_TimeSec_Mp.ConSeedRequestNum==0)
//	{
//		  OBDII_TimeSec_Mp.ConSeedRequestNum=3;
//	}
//	if(OBDII_TimeSec_Mp.InvalidKeyNum==0)
//	{
//	  OBDII_TimeSec_Mp.InvalidKeyNum=3;
//	}

}
//void OBDII_Each_DTCstatus_Update(ubyte FC_flgFault_LO, ubyte FC_flgwarn_LO, ubyte FC_numDTCline_LO,ubyte Fc_flagSafityCon_LO)
void OBDII_Each_DTCstatus_Update(ubyte FC_flgFault_LO,ubyte FC_numDTCline_LO)
{
	static ubyte OBDII_DTC_flgFstConfirmed=0;
	static ubyte OBDII_DTC_flgFstTestFail=0;
	static ubyte OBDII_DTC_LastStatus=0;

	if(DTC_st_errNum != ((Dtcst_CSTR*)0))
	{
	   DTC_st_errNum[FC_numDTCline_LO].Status &=0xFF;
	   OBDII_DTC_LastStatus=DTC_st_errNum[FC_numDTCline_LO].Status;
	}
	if(FC_flgFault_LO==TRUE)                               //
	{
		if(OBDII_DTC_flgFstTestFail==0)
		{
			OBDII_DTC_FstTestFail=OBDII_DTC_Lst[FC_numDTCline_LO];
			OBDII_DTC_flgFstTestFail=1;
		}
		if(DTC_st_errNum != ((Dtcst_CSTR*)0))
		{
			DTC_st_errNum[FC_numDTCline_LO].Status |= 0x01;//set bit0 to 1 test failed
			DTC_st_errNum[FC_numDTCline_LO].Status |= 0x20;//set bit5 to 1 test failed lastclear
			DTC_st_errNum[FC_numDTCline_LO].Status |= 0x04;//set bit2 to 1 pending dtc
			DTC_st_errNum[FC_numDTCline_LO].Status |= 0x02;//set bit1 to 1 testfailed this operation cycle
			if(DTC_st_errNum[FC_numDTCline_LO].ErrOnce==0)
				DTC_st_errNum[FC_numDTCline_LO].ErrOnce=1;
			OBDII_CallBack_DTCOccurence(FC_numDTCline_LO);



			if((DTC_st_errNum[FC_numDTCline_LO].ErrNumCycle==0)&&(DTC_st_errNum[FC_numDTCline_LO].ErrOnce==2))
             { 
			   DTC_st_errNum[FC_numDTCline_LO].ErrNumCycle=OBDII_valAgingAllow;
               OBDII_FreezeData_Updata(FC_numDTCline_LO);
			 }


			//DTC_st_errNum[FC_numDTCline_LO].ErrNumCycle=OBDII_valAgingAllow;

			if((DTC_st_errNum[FC_numDTCline_LO].ErrNum<OBDII_num_DTCConfirm)&&(DTC_st_errNum[FC_numDTCline_LO].Operation_flgCycle==1))
			{
				DTC_st_errNum[FC_numDTCline_LO].Operation_flgCycle=0;
			    DTC_st_errNum[FC_numDTCline_LO].ErrNum++;
			}
			//if ((DTC_st_errNum[FC_numDTCline_LO].ErrNum == OBDII_num_DTCConfirm)&&(DTC_st_errNum[FC_numDTCline_LO].ErrNumCycle==OBDII_valAgingAllow)) //
			if (DTC_st_errNum[FC_numDTCline_LO].ErrNumCycle==OBDII_valAgingAllow) //
			{

				  DTC_st_errNum[FC_numDTCline_LO].Status|= 0x08;// set bit3 to 1 confirmed DTC

				  DTC_st_errNum[FC_numDTCline_LO].ErrKeep= 1;
				  if(OBDII_DTC_Lst[FC_numDTCline_LO].WaringIndicator==TRUE)
				  {
					  DTC_st_errNum[FC_numDTCline_LO].Status|=0x80;// set bit7 to 1 WaringIndicatorRequest
				  }

				  if(OBDII_DTC_flgFstConfirmed==0)
				  {
					OBDII_DTC_FstConfirmed=OBDII_DTC_Lst[FC_numDTCline_LO];
					OBDII_DTC_flgFstConfirmed=1;
				  }

			}
		}
	}
	else
	{
		if(DTC_st_errNum != ((Dtcst_CSTR*)0))
		{
		    if(OBDII_flgTestRecOp==TRUE)
		    {
			  DTC_st_errNum[FC_numDTCline_LO].Status &= 0xFe;//set bit0  to zero
		    }
			    //DTC_st_errNum[FC_numDTCline_LO].ErrNum=0;
		}


	}
	if(DTC_st_errNum != ((Dtcst_CSTR*)0))
	{

	   DTC_st_errNum[FC_numDTCline_LO].Status&= 0xAf;//set bit4 to 0 test not completed since last clear
	                                              //set bit6 to 0 test not completed this operation cycle
	}
	if(OBDII_DTC_LastStatus==DTC_st_errNum[FC_numDTCline_LO].Status)
	{
		OBDII_CallBack_DTCStatusChange(FC_numDTCline_LO,OBDII_DTC_LastStatus,DTC_st_errNum[FC_numDTCline_LO].Status);
	}
}

ubyte Start_Operation_Cycle(void)
{
	ubyte Stoc_i=0;
	ubyte SO_status=0;
	if(OBDII_flgOperationstart==0)
	{
	   OBDII_flgOperationstart=1;
	    for(Stoc_i = 0; Stoc_i < (OBDII_DTC_TABLE_SIZE); Stoc_i++)
		{
		   if(DTC_st_errNum[Stoc_i].ErrNumCycle>OBDII_valAgingAllow)
			   DTC_st_errNum[Stoc_i].ErrNumCycle=OBDII_valAgingAllow;

		   DTC_st_errNum[Stoc_i].Status=DTC_st_errNum[Stoc_i].Status&0xbc;
		   DTC_st_errNum[Stoc_i].Status|=0x40;//initial bit6 to 1
		   if(DTC_st_errNum[Stoc_i].ErrNumCycle==0)
		   {
			  if((DTC_st_errNum[Stoc_i].Status&0x08)!=0)
			  OBDII_CallAutoClearSpecialDTC(OBDII_DTC_Lst[Stoc_i].DTCVAL);
		   }
		   DTC_st_errNum[Stoc_i].Operation_flgCycle=1;
		}
		SO_status=1;
	}
	return  SO_status;
}
ubyte Stop_Operation_Cycle(void)
{
	ubyte Stoc_i=0;
	ubyte SO_status=0;
	if(OBDII_flgOperationstart==1)
	{
	   OBDII_flgOperationstart=0;
	   for(Stoc_i = 0; Stoc_i < (OBDII_DTC_TABLE_SIZE); Stoc_i++)
		{
		   if((DTC_st_errNum[Stoc_i].ErrOnce==0)&&(DTC_st_errNum[Stoc_i].ErrNum<OBDII_num_DTCConfirm)&&(DTC_st_errNum[Stoc_i].Operation_flgCycle==1))
		   {
			   DTC_st_errNum[Stoc_i].ErrNum=0;
			   DTC_st_errNum[Stoc_i].ErrNumCycle=0;
		   }
		   if(DTC_st_errNum[Stoc_i].ErrOnce>0)
		   {
			   DTC_st_errNum[Stoc_i].ErrNumCycle=OBDII_valAgingAllow;
		   }

		   else if((DTC_st_errNum[Stoc_i].ErrOnce==0)&&(DTC_st_errNum[Stoc_i].ErrNumCycle!=0)&&((DTC_st_errNum[Stoc_i].Status&0x40)==0))
		   {
			   DTC_st_errNum[Stoc_i].ErrNumCycle-=1;
		   }
		   if(DTC_st_errNum[Stoc_i].ErrOnce==0)
		   {
			   DTC_st_errNum[Stoc_i].Status=DTC_st_errNum[Stoc_i].Status&0xfb;//set bit2  to zero
		   }
		   DTC_st_errNum[Stoc_i].Status=DTC_st_errNum[Stoc_i].Status&0xbc;
		   DTC_st_errNum[Stoc_i].Operation_flgCycle=0;
		   DTC_st_errNum[Stoc_i].ErrOnce=0;
		   DTC_st_errNum[Stoc_i].ErrKeep=0;

		}
	   SO_status=1;
	}
   return  SO_status;
}
void Config_DTC_RecovSameOp(ubyte DemRecSamOp)
{
	OBDII_flgTestRecOp=DemRecSamOp;
}
void Config_DTC_AgingAllow(ubyte Dem_valAging)
{
	OBDII_valAgingAllow=Dem_valAging;
}
//*******************************************************OBD************************************************************//
void OBD_RequestDiagData_15031(void)  //01
{
	ubyte OBD_valPid_LO=0;
	ubyte OBD_stRequestResult;
	ubyte RDD_k,RDD_m,RDD_n,RDD_q;
	ubyte OBD_flgSuppPID_LO,OBD_flgValuePID_LO;
	OBDII_TP_stEffService.lSendCnt=0;
	OBDII_TP_stEffService.valWrongCode=0;

	if(OBDII_TP_stEffService.lServiceR<=7)
	{
		OBD_stRequestResult=TRUE;
	}
	if(OBD_stRequestResult==TRUE)
	{
		OBD_stRequestResult=FALSE;
		 for(RDD_m=0;RDD_m<(OBDII_TP_stEffService.lServiceR-1);RDD_m++)
		 {
			 OBD_valPid_LO=OBDII_TP_stEffService.TP_valRecBuf_MP[RDD_m];
			 for(RDD_k=0;RDD_k<6;RDD_k++)
			 {
				if(OBDII_PidLst[RDD_k].DiagPid==OBD_valPid_LO)
				{
					OBD_stRequestResult=TRUE;
					OBD_flgSuppPID_LO=1;
					OBDII_TP_stEffService.TP_valSendBuf_MP[OBDII_TP_stEffService.lSendCnt]=OBD_valPid_LO;
					OBDII_TP_stEffService.lSendCnt++;
						for(RDD_q=0;RDD_q<OBDII_PidLst[RDD_k].DiagDatalen;RDD_q++)
						{
							OBDII_TP_stEffService.TP_valSendBuf_MP[OBDII_TP_stEffService.lSendCnt]=OBDII_PidLst[RDD_k].DiagDatainf[RDD_q];
							OBDII_TP_stEffService.lSendCnt++;
						}

				}
			 }
			 for(RDD_n=6;RDD_n<OBD_PID_SIZE;RDD_n++)
			 {
				if(OBDII_PidLst[RDD_n].DiagPid==OBD_valPid_LO)
				{
					OBD_stRequestResult=TRUE;
					OBD_flgValuePID_LO=1;
					OBDII_TP_stEffService.TP_valSendBuf_MP[OBDII_TP_stEffService.lSendCnt]=OBD_valPid_LO;
					OBDII_TP_stEffService.lSendCnt++;
					if(OBDII_PidLst[RDD_n].DiagDatalen==1)
					{
						OBDII_TP_stEffService.TP_valSendBuf_MP[OBDII_TP_stEffService.lSendCnt]=OBDII_PidLst[RDD_n].DiagDatainf[0];
						OBDII_TP_stEffService.lSendCnt++;
					}
					else
					{
						for(RDD_q=0;RDD_q<OBDII_PidLst[RDD_n].DiagDatalen;RDD_q++)
						{
							OBDII_TP_stEffService.TP_valSendBuf_MP[OBDII_TP_stEffService.lSendCnt]=OBDII_PidLst[RDD_n].DiagDatainf[RDD_q];
							OBDII_TP_stEffService.lSendCnt++;
						}
					}
				}
			 }
		 }
	}
	if(OBD_stRequestResult==TRUE)
	{
		if(((OBD_flgSuppPID_LO==1)&&(OBD_flgValuePID_LO==1))||((OBD_flgSuppPID_LO==0)&&(OBD_flgValuePID_LO==0)))
		{
			OBD_stRequestResult=FALSE;
		}
		else
		{
			 OBDII_TP_stEffService.lServiceS=OBDII_TP_stEffService.lSendCnt;
			 OBDII_Send_ResPonsReqdata();
		}
	}
}

//void OBD_RequestVehInfor_15031(void)  //09
//{
//	ubyte OBD_valTyp_LO=0;
//	ubyte RVI_i,RVI_k,RVI_m,RVI_n,RVI_q;
//	ubyte OBD_flgSuppTyp_LO,OBD_flgValueTyp_LO;
//	OBDII_TP_stEffService.lSendCnt=0;
//	OBDII_TP_stEffService.valWrongCode=0;
//
//
//	 for(RVI_i=0;RVI_i<(OBDII_TP_stEffService.lServiceR-1);RVI_i++)
//	 {
//		 OBD_valTyp_LO=OBDII_TP_stEffService.TP_valRecBuf_MP[RVI_i];
//		 for(RVI_k=0;RVI_k<2;RVI_k++)
//		 {
//			if(OBDII_VehPidLst[RVI_k].VehInfType==OBD_valTyp_LO)
//			{
//				OBD_flgSuppTyp_LO=1;
//				OBDII_TP_stEffService.TP_valSendBuf_MP[OBDII_TP_stEffService.lSendCnt]=OBD_valTyp_LO;
//				OBDII_TP_stEffService.lSendCnt++;
////				for(RVI_q=0;RVI_q<OBD_PidLst[RVI_k].DiagDatalen;RVI_q++)//lc
//					for(RVI_q=0;RVI_q<OBDII_VehPidLst[RVI_k].VehInflen;RVI_q++)//lc
//				{
//					OBDII_TP_stEffService.TP_valSendBuf_MP[OBDII_TP_stEffService.lSendCnt]=OBDII_VehPidLst[RVI_k].VehInfData[RVI_q];
//					OBDII_TP_stEffService.lSendCnt++;
//				}
//			}
//		 }
//		 for(RVI_n=2;RVI_n<OBD_VehData_SIZE;RVI_n++)
//		 {
//			if(OBDII_VehPidLst[RVI_n].VehInfType==OBD_valTyp_LO)
//			{
//				OBD_flgValueTyp_LO=1;
//				OBDII_TP_stEffService.TP_valSendBuf_MP[OBDII_TP_stEffService.lSendCnt]=OBD_valTyp_LO;
//				OBDII_TP_stEffService.lSendCnt++;
//				if(OBDII_VehPidLst[RVI_n].VehInfItemNum==1)
//				{
//					OBDII_TP_stEffService.TP_valSendBuf_MP[OBDII_TP_stEffService.lSendCnt]=1;
//					OBDII_TP_stEffService.lSendCnt++;
////					for(RVI_q=0;RVI_q<OBD_PidLst[RVI_n].DiagDatalen;RVI_q++)
//					for(RVI_q=0;RVI_q<OBDII_VehPidLst[RVI_n].VehInflen;RVI_q++)
//					{
//						OBDII_TP_stEffService.TP_valSendBuf_MP[OBDII_TP_stEffService.lSendCnt]=OBDII_VehPidLst[RVI_n].VehInfData[RVI_q];
//						OBDII_TP_stEffService.lSendCnt++;
//					}
//				}
//			}
//		 }
//	 }
//
//	if(((OBD_flgSuppTyp_LO==1)&&(OBD_flgValueTyp_LO==1))||((OBD_flgSuppTyp_LO==0)&&(OBD_flgValueTyp_LO==0)))
//	{
//	}
//	else if(((OBD_flgSuppTyp_LO==1)&&(OBDII_TP_stEffService.lServiceR<=7))||((OBD_flgValueTyp_LO==1)&&(OBDII_TP_stEffService.lServiceR==2)))
//	{
//		 OBDII_TP_stEffService.lServiceS=OBDII_TP_stEffService.lSendCnt;
//		 OBDII_Send_ResPonsReqdata();
//	}
//}
void OBD_RequestVehInfor_15031(void)  //09
{
  ubyte OBD_valTyp_LO=0;
  ubyte RVI_i,RVI_k,RVI_m,RVI_n,RVI_q;
  ubyte OBD_flgSuppTyp_LO=0,OBD_flgValueTyp_LO=0;
  OBDII_TP_stEffService.lSendCnt=0;
  OBDII_TP_stEffService.valWrongCode=0;


   for(RVI_i=0;RVI_i<(OBDII_TP_stEffService.lServiceR-1);RVI_i++)
   {
     OBD_valTyp_LO=OBDII_TP_stEffService.TP_valRecBuf_MP[RVI_i];

     for(RVI_n=0;RVI_n<OBD_VehData_SIZE;RVI_n++)
     {
      if(OBDII_VehPidLst[RVI_n].VehInfType==OBD_valTyp_LO)
      {
        OBDII_TP_stEffService.TP_valSendBuf_MP[OBDII_TP_stEffService.lSendCnt]=OBD_valTyp_LO;
        OBDII_TP_stEffService.lSendCnt++;
//        if(OBDII_VehPidLst[RVI_n].VehInfItemNum==1)
//        {
          if((RVI_n!=0))//&&(RVI_n!=1))
          {
              if(OBDII_VehPidLst[RVI_n].VehInfItemNum!=0)
              {
                OBDII_TP_stEffService.TP_valSendBuf_MP[OBDII_TP_stEffService.lSendCnt]=OBDII_VehPidLst[RVI_n].VehInfItemNum;
                OBDII_TP_stEffService.lSendCnt++;
              }
            OBD_flgValueTyp_LO=1;
            OBD_flgSuppTyp_LO=0;
          }
          else
          {
            OBD_flgSuppTyp_LO=1;
            OBD_flgValueTyp_LO=0;
          }
          for(RVI_q=0;RVI_q<OBDII_VehPidLst[RVI_n].VehInflen;RVI_q++)
          {
            OBDII_TP_stEffService.TP_valSendBuf_MP[OBDII_TP_stEffService.lSendCnt]=OBDII_VehPidLst[RVI_n].VehInfData[RVI_q];
            OBDII_TP_stEffService.lSendCnt++;
          }
 //       }
      }
     }
   }

  if(((OBD_flgSuppTyp_LO==1)&&(OBDII_TP_stEffService.lServiceR<=7))||((OBD_flgValueTyp_LO==1)&&(OBDII_TP_stEffService.lServiceR==2)))
  {
     OBDII_TP_stEffService.lServiceS=OBDII_TP_stEffService.lSendCnt;
     OBDII_Send_ResPonsReqdata();
  }
}



