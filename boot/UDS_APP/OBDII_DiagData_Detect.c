/*
 * OBDII_DiagData_Detect.c
 *
 *  
 *      Author: think
 */
#include "OBDII_DiagData_Detect.h"
#include "struct.h"
#include "OBDII_Diag_CallBack.h"
#include "OBDII_Diag_Snapshot.h"
#include "OBDII_DTC.h"
#include "OBDII_DTC_Trans_Protocol.h"
#include "OBDII_APP_IO.h"
#include "iodefine.h"
//********************************UDS Parameters ******************************************//
const Sec_ActTimer OBDII_TimeSecInit={0,0,0,3,1,18000,0};//

#define P2Server_value          		50  //P2Server
#define P2_Server_value         		500//P2*Server
#define KeepSessionTime_value   		500 //Time to hold the current session mode.unit 10ms
#define TesterPresentTime_value 		499 //tester present.unit 10ms
#define DemRecSamOp 		            TRUE
//******************************************************************************************//
ubyte DTC_numConfirm = 1 ; //
ubyte DTC_numAging =40 ;
//****************************************Supported Services*************************************************
const Service_CSTR OBDII_Service_demondLst_DSPR[Support_Service_numUsed]=
{
/*10*/	{TP_StartDiagnosticSession,  		 Support_Service,    SuppDiagSesnD,	  SuppDiagSesnP,	SuppDiagSesnE,Security_Level0},
/*11*/	{TP_EcuReset,               	     Support_Service,    SuppDiagSesnD,	  SuppDiagSesnP,	SuppDiagSesnE,Security_Level0},
/*14*/	{TP_ClearDiagnosticInformation, 	 Support_Service,    SuppDiagSesnD,	  SuppDiagSesnP,	SuppDiagSesnE,Security_Level0},
/*19*/	{TP_ReadDTCInfor, 				 	 Support_Service,    SuppDiagSesnD,	  SuppDiagSesnP,	SuppDiagSesnE,Security_Level0},
/*22*/	{TP_ReadDataByIdentifier, 			 Support_Service,    SuppDiagSesnD,	  SuppDiagSesnP,	SuppDiagSesnE,Security_Level0},
/*23*/	{TP_ReadMemoryByAddress, 			 Not_Support_Service,SuppDiagSesnD,	  SuppDiagSesnP,	SuppDiagSesnE,Security_Level0},
/*27*/	{TP_SecurityAccess, 				 Support_Service,	 Not_SupDiagSesnD,SuppDiagSesnP,    SuppDiagSesnE,Security_Level0},
/*28*/	{TP_CommunicationControl, 			 Support_Service,	 Not_SupDiagSesnD,Not_SupDiagSesnP, SuppDiagSesnE,Security_Level0},
/*2e*/	{TP_WriteDataByIdentifier, 		 	 Support_Service,	 Not_SupDiagSesnD,SuppDiagSesnP,	SuppDiagSesnE,Security_Level2},
/*2f*/	{TP_InputOutputControlByIdentifier,  Not_Support_Service,	 Not_SupDiagSesnD,SuppDiagSesnP,	SuppDiagSesnE,Security_Level0},
/*31*/	{TP_RoutineCtlByIdentifier,          Support_Service,	 Not_SupDiagSesnD,SuppDiagSesnP,	SuppDiagSesnE,Security_Level2},
/*3d*/	{TP_WriteMemoryByAddress,            Not_Support_Service,SuppDiagSesnD,	  SuppDiagSesnP,	SuppDiagSesnE,Security_Level0},
/*3e*/	{TP_TesterPresent,  				 Support_Service,	 SuppDiagSesnD,	  SuppDiagSesnP,	SuppDiagSesnE,Security_Level0},
/*85*/	{TP_ControlDTCSetting,  			 Support_Service,	 Not_SupDiagSesnD,Not_SupDiagSesnP, SuppDiagSesnE,Security_Level0},
/*01*/	{TP_ReadPowerSysInf,  			     Not_Support_Service,	 SuppDiagSesnD,SuppDiagSesnP, SuppDiagSesnE,Security_Level0},
/*09*/	{TP_ReadVehInf,  			        Not_Support_Service,	 SuppDiagSesnD,SuppDiagSesnP, SuppDiagSesnE,Security_Level0},
};

//****************************************Input_Output DID List*************************************************
uds_InOut_Ctrl OBDII_InOut_ParaLst_DSPR[PID_InOut_SIZEUsed]=
{
	0
};

//****************************************Routine Ctl DID List*************************************************
Routine_CSTR OBDII_Routine_DATA_DSPR[Routine_Data_SIZEUsed]=
{
/* 0*/  {Angle_Calibration,Not_SupDiagSesnD,SuppDiagSesnP,SuppDiagSesnE,Security_Level2},
/* 1*/  {Cancel_Angle_Calibration,Not_SupDiagSesnD,Not_SupDiagSesnP,SuppDiagSesnE,Security_Level2},
};

//****************************************Dynamic data DID List*************************************************
DiagData_CSTR OBDII_DD_PidLst_DSPR[PID_TABLE_SIZEUsed]=
{
	0
}; 

//*****************************************Other Variable definitions********************************************

VehData_CSTR OBD_Veh_InfLst_DSPR[Veh_Data_SIZEUsed]=
{
/* F18C*/	{OBDII_ECUSerial, 			14,	&OBDII_ECUSerialData[0], 			0, 	SupRead,NotSupRW,SupRead,Security_Level0},
/* F18A*/	{OBDII_SuppIdInf, 			10,	&OBDII_System_Supplier_Identifier[0], 	        0, 	SupRead,NotSupRW,SupRead,Security_Level0},
/* F187*/	{OBDII_ManufacturerPartNumber,		12,	&OBDII_Vehicle_Manufacturer_Part_Number[0], 	0, 	SupRead,NotSupRW,SupRead,Security_Level0},
/* F190*/	{OBDII_VehId, 				17,	&OBDII_VehIdData[0], 				0, 	SupRead,NotSupRW,SupRW,Security_Level0},
/* F197*/	{OBDII_ECUSysName, 			10,	&OBDII_System_Num[0],	  	 		0,	SupRead,NotSupRW,SupRead,Security_Level0},
/* F193*/	{OBDII_ECUHwVerNum,			2,	&OBDII_SysSupplier_ECUHWVer_Number[0],	  	0,	SupRead,NotSupRW,SupRead,Security_Level0},
/* F195*/	{OBDII_SSECUSWVerNum,			2,	&OBDII_SysSupplier_ECUSWVer_Number[0],	        0,	SupRead,NotSupRW,SupRead,Security_Level0},
/* F15B*/	{OBDII_FingerprintDataIdentifier, 	10,	&OBDII_FingerprintDataIdentifier_DATA[0],	  	0,	SupRead,NotSupRW,SupRead,Security_Level0},
};

//***********************Dynamic data Updata *****//
void OBDII_DataService_Updata(uword OBDII_valReqdid)//Dynamic data
{

    switch(OBDII_valReqdid)

    {
      default:


    	  break;

    }
}
uint8 rand_num =0;
uint8 rand_num1 =0;
uint8 rand_num2 =0;
uint8 rand_num3 =0;
void delay_ms(volatile uint32 nms)
{
	volatile uint32 i,j;
	for(i=0;i<nms;i++)
	{
		j=7000;
		while(j--);
	}
}
extern uint8 OBDII_stWriteSuccess[61];
extern ubyte EE_numEntryfail_TiSecDlay[3];
void OBDII_TSKUpper_Ex(void)
{
	static ubyte ECU_stReset_Cnt;
	rand_num++;
	rand_num1 = rand_num1+3;
	rand_num2 = rand_num2+7;
	rand_num3 = rand_num3+11;

	OBD_Service();
	OBDII_CallBack_RecUDS();
	OBDII_DiagData_Update();
	if(ECU_stReset_Cmd == 1)
	{
		ECU_stReset_Cnt++;
		if(ECU_stReset_Cnt == 2)
		{
			EE_numEntryfail_TiSecDlay[0]=EE_numEntryfail;
			EE_numEntryfail_TiSecDlay[1]=EE_TiSecDlay;
			EE_numEntryfail_TiSecDlay[2]=EE_TiSecDlay>>8;

//			OBDII_stWriteSuccess[21]= I2C_BufferWrite(EE_numEntryfail_TiSecDlay,1600, 3);
		    	delay_ms(100);

			ECU_stReset_Cnt = 0;
			ECU_stReset_Cmd = 0;
//			asm("NOP");
//			asm("RESET");//���Ը�λ--��λ���Զ�����BootLoader
//			asm("NOP");
		}
		else
		{

		}
	}
	else
	{

	}

}

uint8 OBD_fgEEpromWriteOperation = 0;
void OBD_EERPOM_WritePrepare(void)
{
	OBD_fgEEpromWriteOperation =0;
}

uint8 OBD_EEPROM_Write(void)
{
	return 0;
}

void OBD_stDtcReadFromEEPROM(void)
{

}


//**********************UDS Parameter Initial**********//
void OBDII_CallBack_Init(void)
{
	ubyte DTCStatus_i;
	Config_DTCAvailabilityMask_Ex(0x09);
	Config_SecurityLevel_Variant(Security_Level2);
	Config_SecurityLevel_Control(Security_Level3);
	Config_Security_NumAndTimer(OBDII_TimeSecInit);

	Config_Support_Service_num(Support_Service_numUsed,OBDII_Service_demondLst_DSPR);
	Config_PID_InOut_SIZE(PID_InOut_SIZEUsed,OBDII_InOut_ParaLst_DSPR);
	Config_Routine_Data_SIZE(Routine_Data_SIZEUsed,OBDII_Routine_DATA_DSPR);
	Config_Veh_Data_SIZE(Veh_Data_SIZEUsed,OBD_Veh_InfLst_DSPR);
	Config_PID_TABLE_SIZE(PID_TABLE_SIZEUsed,OBDII_DD_PidLst_DSPR);
	Config_DTC_TABLE_SIZE(DTC_TABLE_SIZEUsed,OBDII_DTC_Lst_DSPR,DTC_stAnderr);

//	Config_OBDPID_TABLE_SIZE(OBD_PID_SIZE_USED,OBD_PidLst);
//	Config_OBDVeh_TABLE_SIZE(OBD_VehData_SIZE_USED,OBD_VehInfLst);


    	Config_DTC_SupportSnapshot_SIZE(DTC_SupportSnapshot_SIZEUsed,OBDII_DTC_SnapshotList_DSPR,DTC_SaveSnapshot_SIZEUsed,EE_ValSnapshot_TEMPDSPR);
	Config_A_DTC_SnapshotDID_MAXNum(A_DTC_SnapshotDID_MAXNumUsed,A_DTC_Extended_MAXNumUsed);
	Config_DTC_ConfirmNum(DTC_numConfirm);
	Config_DTC_AgingAllow(DTC_numAging);
	Config_DTC_RecovSameOp(DemRecSamOp);
	Config_TimeParameter(P2Server_value, P2_Server_value, KeepSessionTime_value, TesterPresentTime_value);
	for(DTCStatus_i=0;DTCStatus_i<DTC_TABLE_SIZEUsed;DTCStatus_i++)
	{
		DTC_stAnderr[DTCStatus_i].Status|=0x50;
	}




	Dsg_flgInitDtcInfoFinish_MP = 1;


}

ubyte DTC_OpCycle ;
ubyte DTC_OpCycle_record; //1-write eeprom, 2-read eeprom
void SaveAndReadObdData_Opcycle(void)
{
	static ubyte start_flgCycle=0;
	if((DTC_OpCycle==1)||(DTC_OpCycle==2))
	{
		DTC_OpCycle_record=DTC_OpCycle;
		DTC_OpCycle=0;
	}
	if(DTC_OpCycle_record==1)
	{
		if(start_flgCycle==1)
		{
	      Stop_Operation_Cycle();

	      start_flgCycle=0;
		}
		DTC_OpCycle_record=3;
	}
	else if(DTC_OpCycle_record==2)
	{
		if(start_flgCycle==0)
		{

		  Start_Operation_Cycle();

		  start_flgCycle=1;
		}
		DTC_OpCycle_record=4;
	}
}
