/*
 * OBDII_Diag_Snapshot.c
 *
 *  
 *      Author: ZZZ
 */

#include "struct.h"
#include "OBDII_Diag_Snapshot.h"
#include "OBDII_DiagData_Detect.h"
#include "OBDII_Diag_CallBack.h"
#include "OBDII_DTC.h"
#include "OBDII_APP_IO.h"

//volatile uint8 OBD_fgResetRemember_MP __attribute__((section(".Resetflag"))) = 0;
extern ubyte Security_FAA_st;
uint32 EE_ValDTC_DSPR[DTC_SaveSnapshot_SIZEUsed];
ubyte  EE_ValDTCRecordNum_DSPR[DTC_SaveSnapshot_SIZEUsed];
ubyte  EE_ValSnapshot_DSPR[DTC_SaveSnapshot_SIZEUsed][A_DTC_SnapshotDID_MAXNumUsed];
ubyte  EE_ValExtended_DSPR[DTC_SaveSnapshot_SIZEUsed][A_DTC_Extended_MAXNumUsed];

uint32 EE_ValDTC_Temp_DSPR[DTC_SaveSnapshot_SIZEUsed];
ubyte  EE_ValSnapshot_Temp_DSPR[DTC_SaveSnapshot_SIZEUsed][A_DTC_SnapshotDID_MAXNumUsed];
ubyte  EE_ValExtended_Temp_DSPR[DTC_SaveSnapshot_SIZEUsed][A_DTC_Extended_MAXNumUsed];


ubyte  EE_numEntryfail;
uword  EE_TiSecDlay;
ubyte  EE_DTC_errNum[DTC_TABLE_SIZEUsed];
ubyte  EE_DTC_errNumCycle[DTC_TABLE_SIZEUsed];
ubyte  EE_DTC_statusStored[DTC_TABLE_SIZEUsed];

ubyte EE_numEntryfail_TiSecDlay[3];
ubyte  EE_DTC_numFaultOccurrence[DTC_TABLE_SIZEUsed];
ubyte  EE_DTC_numFaultPending[DTC_TABLE_SIZEUsed];
ubyte  EE_DTC_numAged[DTC_TABLE_SIZEUsed];
uint16 Fault_numRecord[DTC_TABLE_SIZEUsed]={0};
uint8 Fault_stRecord[DTC_TABLE_SIZEUsed]={Fault_init};
uint8 DTC_HistoryPos=0;
uint8 DTC_HistoryNum=0;
//*************************************************************************************************


//***************************variable Process snapshotdata and extdata*****************************
ubyte EE_ValSnapshot_TEMPDSPR[A_DTC_SnapshotDID_MAXNumUsed];
ubyte EE_ValExtended_TEMPDSPR[A_DTC_Extended_MAXNumUsed];
Dtcst_CSTR DTC_stAnderr[DTC_TABLE_SIZEUsed];
ubyte EE_numCurrentSnapPos=0;
ubyte EE_numCurrentSnaprecord=0;
WrEEprom_inf OBDII_EE_DATA =
{
	&EE_ValDTC_DSPR[0],
	&EE_ValDTCRecordNum_DSPR[0],
	&EE_ValSnapshot_DSPR[0][0],
	&EE_ValExtended_DSPR[0][0],
	&EE_ValDTC_Temp_DSPR[0],
	&EE_ValSnapshot_Temp_DSPR[0][0],
	&EE_ValExtended_Temp_DSPR[0][0],
	&EE_numEntryfail,
	&EE_TiSecDlay,
	&EE_ValSnapshot_TEMPDSPR[0],
	&EE_ValExtended_TEMPDSPR[0]
};

//*************************************************************************************************

//*****************************************DTC List********************************************************
DtcType_CSTR const OBDII_DTC_Lst_DSPR[DTC_TABLE_SIZEUsed]=
{
/* 0*/  {DTC_valBatteryVL,CanClearByTool,WaringIndicator_Disable },
/* 1*/	{DTC_valBatteryVH ,CanClearByTool,WaringIndicator_Disable},
/* 2*/	{DTC_valCANbusoff,CanClearByTool,WaringIndicator_Disable},
/* 3*/	{DTC_valVCUNodeErr,CanClearByTool,WaringIndicator_Disable},
/* 4*/	{DTC_valVCUNodeSignalErr,CanClearByTool,WaringIndicator_Disable},
/* 5*/	{DTC_valToranglePowErr ,CanClearByTool,WaringIndicator_Disable},
/* 6*/	{DTC_valEPSTorAngleErr,CanClearByTool,WaringIndicator_Disable},
/* 7*/	{DTC_valEPSPowerErr ,CanClearByTool,WaringIndicator_Disable},
/* 8*/	{DTC_valEPSHardWareErr,CanClearByTool,WaringIndicator_Disable},
/* 9*/  {DTC_valEPSMotorErr,CanClearByTool,WaringIndicator_Disable },
/* 10*/	{DTC_valTempSignalErr ,CanClearByTool,WaringIndicator_Disable},
/* 11*/	{DTC_valECUTempSignalErr,CanClearByTool,WaringIndicator_Disable},
/* 12*/	{DTC_valRelayBreakErr,CanClearByTool,WaringIndicator_Disable},
/* 13*/	{DTC_valRelayStickErr,CanClearByTool,WaringIndicator_Disable},
/* 14*/	{DTC_valMoterLoationErr ,CanClearByTool,WaringIndicator_Disable},
/* 15*/	{DTC_valTurnStickErr,CanClearByTool,WaringIndicator_Disable},
/* 16*/	{DTC_valAutoModeInterErr ,CanClearByTool,WaringIndicator_Disable},
/* 17*/	{DTC_valAngleZeroErr,CanClearByTool,WaringIndicator_Disable},
};

//****************************************Dtc1 snapshot*************************//

ubyte data_0x1234[2] = {0x32,0x14};
ubyte data_0x4432[3] = {0x56,0x78,0x12};

Snapshot_data OBDII_DTC_DID_List1[30]=
{
	{0x1234,2,&data_0x1234[0]},
	{0x4432,3,&data_0x4432[0]}
};

//********************************** List for Snapshot information of DTCs******************************************************************//

const Snapshot_ofDTC OBDII_DTC_SnapshotList_DSPR[DTC_SupportSnapshot_SIZEUsed]=
{
	{{DTC_valBatteryVL,CanClearByTool,WaringIndicator_Disable},2,&OBDII_DTC_DID_List1[0],0,0,1},
};
//*************************************************************************************************************************//

uint32 OBDII_ValTest_Lo=0;
void OBDII_ConfigDTCSnapshot_In(ubyte OBDII_posDtc)
{
	uint32 val_did = 0;
	
}

uint8 OBDII_FZ_EE_POS = 0;
Snapshot_ofCurrentDTC DTC_Current= {0};//ʵʱ����
Snapshot_ofCurrentDTC DTC_SnapshotCurrent[10] = {0};//��Ҫ�µ�洢�Ĺ���?
extern uint8 DTC_CurrentNum;
uint8 DTC_Test1=0;
void OBDII_FreezeData_Updata(ubyte OBDII_posDtc)
{

}
void Freeze_deal_Before_PowerOff(void)
{


}

volatile uint8 OBDII_stWriteSuccess[32];
uint8 DTC_eeprom_test = 0;
uint8 DTC_CurrentNum = 0;
uint8 OBDII_RelatedDtc_WriteToEEprom(ubyte* Wr_tiEEprom)
{
//	static uint8 OBDII_numWr_Lo = 0;
//	uint8  HisDTC_i;
//	uint8 EE_fgWriteFinish_LO = 0;
//	uint8 i=0,j=0,k=0,m;
////	uint8 DTC_CurrentNum = 0;
//	EE_numEntryfail_TiSecDlay[0]=EE_numEntryfail;
//	EE_numEntryfail_TiSecDlay[1]=EE_TiSecDlay;
//	EE_numEntryfail_TiSecDlay[2]=EE_TiSecDlay>>8;
//	switch(*Wr_tiEEprom)
//	{
//	   case 0:

//			Stop_Operation_Cycle();
//			Freeze_deal_Before_PowerOff();
//			for(HisDTC_i=0;HisDTC_i<DTC_TABLE_SIZEUsed;HisDTC_i++)
//			{
//				EE_DTC_errNum[HisDTC_i]=DTC_stAnderr[HisDTC_i].ErrNum;
//				EE_DTC_errNumCycle[HisDTC_i]=DTC_stAnderr[HisDTC_i].ErrNumCycle;
//				EE_DTC_statusStored[HisDTC_i]=DTC_stAnderr[HisDTC_i].Status;
//			}
//			(*Wr_tiEEprom)++;
//			break;
//	   case 1:
//		   OBDII_numWr_Lo++;
//		   if((OBDII_numWr_Lo>2))
//		   {
//			   (*Wr_tiEEprom)++;
//			   OBDII_numWr_Lo = 0;
//		   }
//	   case 2:
//		   OBDII_numWr_Lo++;
//		   OBDII_stWriteSuccess[0]=I2C_BufferWrite(EE_DTC_errNum, 256, 64);   //EE_DTC_errNum �ӿ�1
//           if((OBDII_stWriteSuccess[0]==0)||(OBDII_numWr_Lo>3))
//           {
//			   (*Wr_tiEEprom)++;
//			   OBDII_numWr_Lo=0;
//           }
//		   break;
//	   case 7:
//		   OBDII_numWr_Lo++;
//		   if((OBDII_numWr_Lo>2))
//		   {
//			   (*Wr_tiEEprom)++;
//			   OBDII_numWr_Lo = 0;
//		   }
//	   case 8:
//		   OBDII_numWr_Lo++;
//		   OBDII_stWriteSuccess[3]=I2C_BufferWrite(EE_DTC_statusStored,448, 64);//EE_DTC_statusStored �ӿ�1 
//		   if((OBDII_stWriteSuccess[3]==0)||(OBDII_numWr_Lo>3))
//		   {
//			   (*Wr_tiEEprom)++;
//			   OBDII_numWr_Lo=0;
//		   }
//		   break;
//		   OBDII_numWr_Lo++;
//		   OBDII_stWriteSuccess[15]= I2C_BufferWrite(EE_DTC_errNumCycle,1216, 64);//EE_DTC_errNumCycle �ӿ�1
//		   if((OBDII_stWriteSuccess[15]==0)||(OBDII_numWr_Lo>3))
//		   {
//			   (*Wr_tiEEprom)++;
//			   OBDII_numWr_Lo=0;
//		   }
//		   break;
//	   case 44:
//		   OBDII_numWr_Lo++;
//		   OBDII_stWriteSuccess[21]= I2C_BufferWrite(EE_numEntryfail_TiSecDlay,1600, 3);//EE_numEntryfail_TiSecDlay �ӿ�1
//		   if((OBDII_stWriteSuccess[21]==0)||(OBDII_numWr_Lo>3))
//		   {
//			   (*Wr_tiEEprom)++;
//			   OBDII_numWr_Lo=0;
//		   }
//		   break;
//	   case 66:

//		   EE_fgWriteFinish_LO = 1;
//	   default:
//		   break;
//	}

	return 0;//EE_fgWriteFinish_LO;

}

void OBDII_RelatedDtc_ReadFromEEprom(void)
{
	ubyte ReadDTC_i,ReadDTC_j,ReadDTC_m;

//	GT_I2C_Buffer_read(256, EE_DTC_errNum, sizeof(ubyte)*DTC_TABLE_SIZEUsed);
//	GT_I2C_Buffer_read(448, EE_DTC_statusStored, sizeof(ubyte)*DTC_TABLE_SIZEUsed );
//	GT_I2C_Buffer_read(1216, EE_DTC_errNumCycle, sizeof(ubyte)*DTC_TABLE_SIZEUsed);
//	GT_I2C_Buffer_read(1601, &EE_TiSecDlay, 2);

	if((OBDII_VehIdData[0]==0xFF)
		&&(OBDII_VehIdData[1]==0xFF)
		&&(OBDII_VehIdData[2]==0xFF)
		&&(OBDII_VehIdData[3]==0xFF)
		&&(OBDII_VehIdData[4]==0xFF)
		&&(OBDII_VehIdData[5]==0xFF)
		&&(OBDII_VehIdData[6]==0xFF)
		&&(OBDII_VehIdData[7]==0xFF)
		&&(OBDII_VehIdData[8]==0xFF)
		&&(OBDII_VehIdData[9]==0xFF)
		&&(OBDII_VehIdData[10]==0xFF)
		&&(OBDII_VehIdData[11]==0xFF)
		&&(OBDII_VehIdData[12]==0xFF)
		&&(OBDII_VehIdData[13]==0xFF)
		&&(OBDII_VehIdData[14]==0xFF)
		&&(OBDII_VehIdData[15]==0xFF)
		&&(OBDII_VehIdData[16]==0xFF))
	{
		OBDII_VehIdData[0] = 0;
		OBDII_VehIdData[1] = 0;
		OBDII_VehIdData[2] = 0;
		OBDII_VehIdData[3] = 0;
		OBDII_VehIdData[4] = 0;
		OBDII_VehIdData[5] = 0;
		OBDII_VehIdData[6] = 0;
		OBDII_VehIdData[7] = 0;
		OBDII_VehIdData[8] = 0;
		OBDII_VehIdData[9] = 0;
		OBDII_VehIdData[10] = 0;
		OBDII_VehIdData[11] = 0;
		OBDII_VehIdData[12] = 0;
		OBDII_VehIdData[13] = 0;
		OBDII_VehIdData[14] = 0;
		OBDII_VehIdData[15] = 0;
		OBDII_VehIdData[16] = 0;
	}


    if(EE_numEntryfail==0xff)
       EE_numEntryfail=0;
     else if(EE_numEntryfail==OBDII_TimeSecInit.InvalidKeyNum)
     {
       Security_FAA_st=1;
     }

	for(ReadDTC_i=0;ReadDTC_i<DTC_TABLE_SIZEUsed;ReadDTC_i++)
	{
		if(EE_DTC_errNum[ReadDTC_i]> DTC_numConfirm)
			DTC_stAnderr[ReadDTC_i].ErrNum = DTC_numConfirm;
		else
			DTC_stAnderr[ReadDTC_i].ErrNum = EE_DTC_errNum[ReadDTC_i];

		if(EE_DTC_errNumCycle[ReadDTC_i] > 40)
			DTC_stAnderr[ReadDTC_i].ErrNumCycle = 0;
		else
			DTC_stAnderr[ReadDTC_i].ErrNumCycle = EE_DTC_errNumCycle[ReadDTC_i];
	}

	for(ReadDTC_i=0;ReadDTC_i<DTC_TABLE_SIZEUsed;ReadDTC_i++)
	{
		DTC_stAnderr[ReadDTC_i].Status=EE_DTC_statusStored[ReadDTC_i];
	}
	Get_CurrentRecordnum_CurrentPos();
	Start_Operation_Cycle();

}

ubyte ReadDTC_storminrecord,ReadDTC_storeminprior,ReadDTC_storeminpriorRecord;
ubyte RecordMinNum_Lo=DTC_SaveSnapshot_SIZEUsed;
ubyte RecordMaxNum_Lo=0;
ubyte DTCMinPrior_Lo=DTC_MAXPRIOR;
void Get_CurrentRecordnum_CurrentPos(void)
{
	ubyte ReadDTC_i,ReadDTC_j;


	for(ReadDTC_i=0;ReadDTC_i<DTC_SaveSnapshot_SIZEUsed;ReadDTC_i++)
	{
	      EE_ValDTCRecordNum_DSPR[ReadDTC_i]=0x01;
	}


}
ubyte test1,test2,test3;
uint32 test4;
void Get_CurrentRecordnum_CurrentPosAfterClear(uint32 DTC_Val)
{
	ubyte ReadDTC_i,ReadDTC_j,ReadDTC_m,ReadDTC_n,j;
	ubyte RecordMinNum_Lo=DTC_SaveSnapshot_SIZEUsed;
	ubyte RecordMaxNum_Lo=0;
	for(ReadDTC_i=0;ReadDTC_i<DTC_SaveSnapshot_SIZEUsed;ReadDTC_i++)
	{
      if(DTC_Val==EE_ValDTC_DSPR[ReadDTC_i])
      {

		  EE_ValDTC_DSPR[ReadDTC_i]=0;
		  for(j=0;j<A_DTC_SnapshotDID_MAXNumUsed;j++)
	      {
			  OBDII_EE_DATA.EE_ValCurrentSnapshot[ReadDTC_i*A_DTC_SnapshotDID_MAXNumUsed+j]=0;
	      }
	      for(j=0;j<A_DTC_Extended_MAXNumUsed;j++)
	      {
	    	  OBDII_EE_DATA.EE_ValCurrentExtended[ReadDTC_i*A_DTC_SnapshotDID_MAXNumUsed+j]=0;
	      }

      }
      if(DTC_Val==EE_ValDTC_Temp_DSPR[ReadDTC_i])
      {
    	  EE_ValDTC_Temp_DSPR[ReadDTC_i]=0;
		  DTC_SnapshotCurrent[ReadDTC_i].DTC_Priority=0;
		  DTC_SnapshotCurrent[ReadDTC_i].DTC_SupportSnapshot.DTCVAL=0;
		  for(j=0;j<A_DTC_SnapshotDID_MAXNumUsed;j++)
		  {
			  OBDII_EE_DATA.EE_ValCurrentSnapshot[ReadDTC_i*A_DTC_SnapshotDID_MAXNumUsed+j]=0;
		  }
		  for(j=0;j<A_DTC_Extended_MAXNumUsed;j++)
		  {
			  OBDII_EE_DATA.EE_ValCurrentExtended[ReadDTC_i*A_DTC_SnapshotDID_MAXNumUsed+j]=0;
		  }

      }
      if(DTC_Val==0xffffff)
      {
    	  EE_numCurrentSnapPos=0;
    	//  EE_ValDTCRecordNum_DSPR[ReadDTC_i]=0;
    	  EE_ValDTC_DSPR[ReadDTC_i]=0;
    	  EE_numCurrentSnaprecord=0;

    	  for(ReadDTC_n=0;ReadDTC_n<DTC_SaveSnapshot_SIZEUsed;ReadDTC_n++)
    	  {
    	    EE_ValDTC_Temp_DSPR[ReadDTC_n]=0;
    	    DTC_SnapshotCurrent[ReadDTC_n].DTC_Priority=0;
    	    DTC_SnapshotCurrent[ReadDTC_n].DTC_SupportSnapshot.DTCVAL=0;
		   for(j=0;j<A_DTC_SnapshotDID_MAXNumUsed;j++)
		   {
			   OBDII_EE_DATA.EE_ValCurrentSnapshot[ReadDTC_n*A_DTC_SnapshotDID_MAXNumUsed+j]=0;
		   }
		   for(j=0;j<A_DTC_Extended_MAXNumUsed;j++)
		   {
			   OBDII_EE_DATA.EE_ValCurrentExtended[ReadDTC_n*A_DTC_SnapshotDID_MAXNumUsed+j]=0;
		   }
    	  }

      }
	}




}



uint16 DemDebCountFailThreshold=2;             //Failure threshold
uint16 DemDebCountPassThreshold=2;             //Pass threshold
uint16 DemDebonceCountJumpUpVal=1;;             //Increment value of the first pre-failure
uint16 DemDebounceCountIncremStepSize=1;       //Increment value for each pre-failure
uint16 DemDebounceCountJumpDownValue=1;        //Decrement value at the first pre-pass
uint16 DemDebTimeIncrementStepSize=1;          //Decrement value for each pre-failure
uint16 err_flag_record = 0;                  //Record the number of incoming faults


uint8 Fault_flgTrig[DTC_TABLE_SIZEUsed]={0};
void Fault_Filter_Fun(ubyte FC_numDTCline_LO)
{
	if(Fault_flgTrig[FC_numDTCline_LO]==1)
	  {
	  if((Fault_stRecord[FC_numDTCline_LO] == Fault_pass)||(Fault_stRecord[FC_numDTCline_LO] == Fault_init))
	  {
	     Fault_stRecord[FC_numDTCline_LO]=Fault_fail;
	     OBDII_Each_DTCstatus_Update(1,FC_numDTCline_LO);
	  }
	  }
	  else if(Fault_flgTrig[FC_numDTCline_LO]==0)
	  {
	  if((Fault_stRecord[FC_numDTCline_LO] == Fault_fail)||(Fault_stRecord[FC_numDTCline_LO] == Fault_init))
	  {
	    Fault_stRecord[FC_numDTCline_LO]=Fault_pass;
	    OBDII_Each_DTCstatus_Update(0,FC_numDTCline_LO);
	  }
	  }

}
//***********************Fault Detect Update *************//
ubyte DTC0_FaultTrigger_LO = 0;
ubyte DTC1_FaultTrigger_LO = 0;
ubyte DTC2_FaultTrigger_LO = 0;
ubyte DTC_FaultTrigger_LO=0 ;

uint16 OBD_numTimes_MP = 0;
void OBDII_DiagData_Update(void)
{
	ubyte i=0;

	if(UDS_stCtlDTC==1)
	{

		//void OBDII_Each_DTCstatus_Update(ubyte FC_flgFault_LO,ubyte FC_numDTCline_LO);
		//Param1: 0 - not test fail;  1 - test fail
		//Param2: DTC List Index

		Fault_flgTrig[0]=DTC_flgBatteryVL;
		Fault_flgTrig[1]=DTC_flgBatteryVH;
		Fault_flgTrig[2]=DTC_flgCANbusoff;
		Fault_flgTrig[3]=DTC_flgVCUNodeErr;
		Fault_flgTrig[4]=DTC_flgVCUNodeSignalErr;//
		Fault_flgTrig[5]=DTC_flgToranglePowErr;//
		Fault_flgTrig[6]=DTC_flgEPSTorAngleErr;//
		Fault_flgTrig[7]=DTC_flgEPSPowerErr;//
		Fault_flgTrig[8]=DTC_flgEPSHardWareErr;//
		Fault_flgTrig[9]=DTC_flgEPSMotorErr;//

		Fault_flgTrig[10]=DTC_flgTempSignalErr;//
		Fault_flgTrig[11]=DTC_flgECUTempSignalErr;//
		Fault_flgTrig[12]=DTC_flgRelayBreakErr;//
		Fault_flgTrig[13]=DTC_flgRelayStickErr;//
		Fault_flgTrig[14]=DTC_flgMoterLoationErr;//
		Fault_flgTrig[15]=DTC_flgTurnStickErr;//
		Fault_flgTrig[16]=DTC_flgAutoModeInterErr;
		Fault_flgTrig[17]=DTC_flgAngleZeroErr;//
		
		for(i=0;i<17;i++)
		{
			Fault_Filter_Fun(i);
		}

	}
}

