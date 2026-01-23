#ifndef UPPERHFILE_OBDII_DIAG_SNAPSHOT_H_
#define UPPERHFILE_OBDII_DIAG_SNAPSHOT_H_

#include "OBDII_DiagData_Detect.h"

//************************************DID List. Snapshot data*****************************************

#define Fault_pass       0
#define Fault_prepass    1
#define Fault_fail       2
#define Fault_prefail    3
#define Fault_init       4

extern uint16 Fault_numRecord[DTC_TABLE_SIZEUsed];
extern uint8 Fault_stRecord[DTC_TABLE_SIZEUsed];

extern const Snapshot_ofDTC OBDII_DTC_SnapshotList_DSPR[DTC_SupportSnapshot_SIZEUsed];
extern ubyte EE_ValSnapshot_TEMPDSPR[A_DTC_SnapshotDID_MAXNumUsed];
extern ubyte EE_ValExtended_TEMPDSPR[A_DTC_Extended_MAXNumUsed];


extern ubyte  EE_DTC_numFaultOccurrence[DTC_TABLE_SIZEUsed];
extern ubyte  EE_DTC_numFaultPending[DTC_TABLE_SIZEUsed];
extern ubyte  EE_DTC_numAged[DTC_TABLE_SIZEUsed];

extern uint8 OBDII_RelatedDtc_WriteToEEprom(ubyte* Wr_tiEEprom);
extern uint8 Set_DTC_busoff;
extern uint8 Set_DTC_CheckSumerr;

void Get_CurrentRecordnum_CurrentPos(void);
void Get_CurrentRecordnum_CurrentPosAfterClear(uint32 DTC_Val);

#endif /* UPPERHFILE_OBDII_DIAG_SNAPSHOT_H_ */
