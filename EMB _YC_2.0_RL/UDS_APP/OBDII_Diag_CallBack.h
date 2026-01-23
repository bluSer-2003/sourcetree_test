#ifndef UPPERHFILE_OBDII_DIAG_CALLBACK_H_
#define UPPERHFILE_OBDII_DIAG_CALLBACK_H_

#include "OBDII_DiagData_Detect.h"

#define TRUE  1
#define FALSE 0

extern const Sec_ActTimer OBDII_TimeSecInit;
extern ubyte OBDII_CallBack_SessionCtl_Condition(ubyte cur_session,ubyte req_session);
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
extern void OBDII_CallBack_WriteDataByIdentifier_Execute(uword wr_id);

extern void OBDII_CallBack_WriteMemory_Execute(uword wr_address,uword wr_size);
extern void OBDII_CallBack_CtlDTC_Execute(ubyte UDS_stCtlDTC_LO);
extern void OBDII_CallBack_ClearSpecialDTC_Execute(uint32 DTC_Val,uint8 DTC_flgClearByAge);
extern void OBDII_CallBack_ClearAllDTC_Execute(void);
extern void Rec_BootLoader_UDS(RecCan_valSeverDataNew Boot_stRecBootLoader_UDS);
extern void CallBack_RefalshCondition(ubyte Reflash_Condition_Allow_orNot);
extern void OBDII_ASW_ClearDtc(void);
extern ubyte CI_flgDTCFunAddrVaild_MP;


ulong croleft(ulong c, uint32 b);
unsigned short int croshortright(unsigned short int c, unsigned short int b);
ulong mulu32(ulong val1,ulong val2);
unsigned long uds_calc_key(unsigned long seed);

extern ubyte OBD_fgRecPhyActive_MP;
extern ubyte OBD_fgRecFunActive_MP;
extern ubyte OBD_fgRecOBDActive_MP;
extern ubyte CANRecForbid_st;
extern ubyte CANSendForbid_st;

#endif /* UPPERHFILE_OBDII_DIAG_CALLBACK_H_ */
