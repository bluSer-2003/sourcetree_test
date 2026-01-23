/*
 * OBDII_DiagData_Detect.h
 *
 *  Created on: 2018年12月27日
 *      Author: think
 */

#ifndef OBDII_DIAGDATA_DETECT_H_
#define OBDII_DIAGDATA_DETECT_H_
#include  "OBDII_DTC.h"
//**********************************SID19  subfunctions supported**********************************************//
#define Sup_ReportNumOfDTCbyStsMsk                         ON
#define Sup_ReportDTCbyStsMsk                              ON
#define Sup_ReportDtcSnapshotid                            OFF
#define Sup_ReportDtcSnapshotByDTCnum                      OFF
#define Sup_ReportDtcSnapshotByRecordNumber                OFF
#define Sup_ReportDtcExtendDataRecordByDTCnumber           OFF
#define Sup_ReportNumberOfDtcBySeverityMaskRecord          OFF
#define Sup_ReportDtcBySeverityMaskRecord                  OFF
#define Sup_ReportSeverityInformOfDTC                      OFF
#define Sup_ReportSuppedDTC                                ON
#define Sup_ReportFirstTestFailedDTC                       OFF
#define Sup_ReportFirstCofirmedDTC                         OFF
#define Sup_ReportDTCWithPermanentStatus                   OFF
//***************************whether services and sessions are supported****************//
#define Support_Service       1
#define Not_Support_Service   0
#define SuppDiagSesnD         1
#define Not_SupDiagSesnD      0
#define SuppDiagSesnP         2
#define Not_SupDiagSesnP      0
#define SuppDiagSesnE         3
#define Not_SupDiagSesnE      0
//*************************************whether DTC Can Clear By Tool************************************//
#define CanClearByTool        0
#define CanNotClearByTool     1

//****************************************************************************************************//
//***********************whether reading and writing are supported*****************************//
#define SupRead      1
#define SupWrite     2
#define SupRW        3
#define NotSupRW     4



//********************************************************************************************************//
typedef struct
{
	const ubyte valSid;   //服务ID
	const ubyte Support_Or_Not;   //服务ID
	const ubyte SupDiagSesnD_Or_Not;   //支持默认诊断模式
	const ubyte SupDiagSesnP_Or_Not;   //编程会话
	const ubyte SupDiagSesnE_Or_Not;   //扩展会话
	const ubyte Secu_Lev;       //安全级别
}Service_CSTR;

typedef struct
{
	const uword InOutID;
	ubyte ctrlStSize;
} uds_InOut_Ctrl;
typedef struct
{
	uword RoutineFid;
	ubyte SupDSessionOrNot;
	ubyte SupPSessionOrNot;
	ubyte SupESessionOrNot;
	ubyte RoutineSupSecLevel;
} Routine_CSTR;
typedef struct
{
	uword VehDataFid;
	ubyte VehDatalen;
	ubyte *VehDatainf;
	ubyte VehDataWriteFinsh;
	ubyte VehDataDSessionRW;
	ubyte VehDataPSessionRW;
	ubyte VehDataESessionRW;
	ubyte VehDataSupSecLevel;
} VehData_CSTR;
typedef struct
{
	const uword DiagFid;
	ubyte DiagVal1;
	ubyte DiagVal2;
	ubyte DiagDatalen;
	ubyte VehDataDSessionRW;
	ubyte VehDataPSessionRW;
	ubyte VehDataESessionRW;
} DiagData_CSTR;

typedef struct
{
	uint32 DTCVAL;
	ubyte ForbidClear;
	ubyte WaringIndicator;
} DtcType_CSTR;
typedef struct
{
	ubyte Status;
	ubyte ErrNum;
	ubyte ErrKeep;
	ubyte ErrOnce;
	ubyte ErrNumCycle;
	ubyte Operation_flgCycle;
} Dtcst_CSTR;
typedef struct
{
	ubyte valFreData1;
	ubyte valFreData2;
}Freezedata_CSTR;

typedef struct
{
  uint32              *DTCVAL;
  ubyte               *RecordNum;
  ubyte               *EE_ValSnapshot;
  ubyte               *EE_ValExtended;
  uint32              *DTCVAL_Current;
  ubyte               *EE_ValCurrentSnapshot;
  ubyte               *EE_ValCurrentExtended;
  ubyte               *EE_numEntryfailPoint;
  uword               *EE_TiSec;
  ubyte               *EE_ValTempSnapshot;
  ubyte               *EE_ValTempExtended;
} WrEEprom_inf;

typedef struct
{
  DtcType_CSTR  DTC_SupportSnapshot;
  ubyte               DTC_Priority;
}Snapshot_ofCurrentDTC;
typedef struct
{
	uword        DID;
	ubyte        DataLength;
	ubyte        *DataBuff;
}Snapshot_data;


typedef struct
{
	DtcType_CSTR        DTC_SupportSnapshot;
	ubyte               DTC_SnapshotDID_num;
	Snapshot_data     *DTC_Snapshot_Infor;
	ubyte               DTC_ExtDataLen;
	ubyte     *DTC_Ext_Infor;
	ubyte               DTC_Priority;
}Snapshot_ofDTC;

typedef struct
{
	ubyte        ConSeedRequestNum;
	ubyte        ConSeedRequesEnable;
	uword        ConSeedRequesTime;
	ubyte        InvalidKeyNum;//The number of Record number
	ubyte        InvalidKeyEnable;
	uword        InvalidKeyTime;
    ubyte        IgOnRestTimeEnable;

}Sec_ActTimer;

typedef struct
{
	const ubyte DiagPid;
	ubyte DiagDatalen;
	ubyte *DiagDatainf;
} OBD_DiagData_Inf;

typedef struct
{
	ubyte VehInfType;
	ubyte VehInflen;
	ubyte VehInfItemNum;
	ubyte *VehInfData;
} OBD_VehData_Inf;

extern WrEEprom_inf OBDII_EE_DATA;

extern ubyte Boot_flgReflash_UDS;

//********************************************************************************************************//
extern void OBDII_DataService_Updata(uword OBDII_valReqdid);
extern void OBDII_FreezeData_Updata(ubyte OBDII_posDtc);
extern void OBDII_Each_DTCstatus_Update(ubyte FC_flgFault_LO,ubyte FC_numDTCline_LO);
extern void OBD_EEPROM_Write(void);
extern void OBD_stDtcReadFromEEPROM(void);
extern void OBD_Service(void);
extern void OBDII_TSKUpper_Ex(void);
extern void OBDII_cmd_RecUDS(RecCan_valSeverDataNew Rec_Diag_Physical,RecCan_valSeverDataNew Rec_Diag_Function);
extern void OBDII_CallBack_RecUDS(void);
//modify 20200227
extern void OBDII_CallBack_SendAck(ubyte *pcandata,ubyte SendLength);
//modify 20200227 end
extern void OBDII_CallBack_Init(void);
extern void OBDII_CallBack_SecurityAccess_Seed(void);
extern void OBDII_CallBack_SecurityAccess_Key(ubyte UDS_ValSecLev_LO);

extern void Config_TimeParameter(uword P2Server_LO,uword P2_Server_LO,uword SessionTime_LO,uword TesterPresentTime_LO);
extern void Config_SecurityLevel_Variant(ubyte OBDII_Level_LO);
extern void Config_SecurityLevel_Control(ubyte OBDII_Level_LO);
extern void Config_Support_Service_num(ubyte OBDII_configsize_LO,const Service_CSTR *SrcBufferPtr_LO);
extern void Config_PID_InOut_SIZE(ubyte OBDII_configsize_LO,const uds_InOut_Ctrl *SrcBufferPtr_LO);
extern void Config_Routine_Data_SIZE(ubyte OBDII_configsize_LO,const Routine_CSTR *SrcBufferPtr_LO);
extern void Config_Veh_Data_SIZE(ubyte OBDII_configsize_LO,const VehData_CSTR *SrcBufferPtr_LO);
extern void Config_DTCAvailabilityMask_Ex(ubyte OBDII_valMask_LO);
extern void Config_PID_TABLE_SIZE(ubyte OBDII_configsize_LO, DiagData_CSTR *SrcBufferPtr_LO);
extern void Config_DTC_TABLE_SIZE(ubyte OBDII_configsize_LO,const DtcType_CSTR *SrcDtcListBufferPtr_LO,Dtcst_CSTR *SrcDtcStBufferPtr_LO);
extern void Config_DTC_SupportSnapshot_SIZE(ubyte OBDII_configsize_LO,const Snapshot_ofDTC *SrcBufferPtr_LO,ubyte OBDII_SuppEEconfigsize_LO,const ubyte *SrcTempBufferPtr_LO);
extern void Config_A_DTC_SnapshotDID_MAXNum(ubyte OBDII_configsize_LO,ubyte OBDII_Extconfigsize_LO);
extern void Config_DTC_ConfirmNum(ubyte OBDII_confignum_LO);
extern void Config_Security_NumAndTimer(Sec_ActTimer OBDII_TimeSec_LO);
extern void Config_DTC_RecovSameOp(ubyte DemRecSamOp);
extern void Config_DTC_AgingAllow(ubyte Dem_valAging);


extern ubyte OBDII_CallBack_EcuReset_Condition(void);
extern ubyte OBDII_CallBack_ClearDTC_Condition(void);
extern ubyte OBDII_CallBack_ReadDATAbyID_Condition(void);//
extern ubyte OBDII_CallBack_ReadMemory_Condition(void);
extern ubyte OBDII_CallBack_Security_Condition(void);
extern ubyte OBDII_CallBack_CheckComCtr_Condition(void);
extern ubyte OBDII_CallBack_WriteDATAbyID_Condition(void);
extern ubyte OBDII_CallBack_InputOutputCtl_Condition(void);
extern ubyte OBDII_CallBack_RoutineCtl_Condition(ubyte Routine_num);
extern ubyte OBDII_CallBack_WriteMemory_Condition(void);
extern ubyte OBDII_CallBack_CtlDTC_Condition(void);

extern void OBDII_CallBack_EcuReset_Execute(ubyte ECU_stResetMode);
extern void OBDII_CallBack_ReadMemory_Execute(uword read_address,uword read_size);
extern void OBDII_CallBack_CommunicationCtl_Execute(ubyte ControlType,ubyte CommuniType);
extern ubyte OBDII_CallBack_InputOutputCtl_Execute(uword OBD_valPid_LO,ubyte *ctrlSt,ubyte *realSt);
extern ubyte OBDII_CallBack_RoutineCtl_Execute(ubyte Routine_num,ubyte Routine_state,ubyte *ReturnResult_Buff);
extern void OBDII_CallBack_ResetRountine_Execute(void);
extern void OBDII_CallBack_WriteMemory_Execute(uword wr_address,uword wr_size);
extern void OBDII_CallBack_CtlDTC_Execute(ubyte UDS_stCtlDTC_LO);
extern void OBDII_CallBack_ClearSpecialDTC_Execute(uint32 DTC_Val,uint8 DTC_flgClearByAge);
extern void OBDII_CallBack_ClearAllDTC_Execute(void);
extern void OBDII_CallBack_WriteDataByIdentifier_Execute(uword wr_id);
extern void Get_Date_Manufacture(ubyte *Mdate_Buffer,ubyte Mdate_Size);
extern void OBDII_CallAutoClearSpecialDTC(uint32 DTC_Val);
extern void OBDII_CallBack_DTCOccurence(ubyte OBDII_DTC_Line);
extern ubyte Stop_Operation_Cycle(void);
extern ubyte Start_Operation_Cycle(void);
//void OBDII_CallBack_Current_DiagSession(ubyte OBDII_stSession);

#endif /* OBDII_DIAGDATA_DETECT_H_ */
