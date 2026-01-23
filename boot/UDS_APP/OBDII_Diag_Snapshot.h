/*
 * OBDII_Diag_Snapshot.h
 *
 *  
 *      Author: ZZZ
 */

#ifndef UPPERHFILE_OBDII_DIAG_SNAPSHOT_H_
#define UPPERHFILE_OBDII_DIAG_SNAPSHOT_H_

#include "OBDII_DiagData_Detect.h"

//************************************DID List. Snapshot data*****************************************

#define Frez_stECUVolDatId                                  			0xF011//ECU Voltage DataIdentifier
#define Frez_stMotoSpeedDatId                 			                0xF012//Motor Speed DataIdentifier
#define Frez_stVehSpeedDatId                                			0xF013//Vehicle Speed DataIdentifier
#define Frez_stVehOdoDatId                            				    0xF014//Vehicle Odometer DataIdentifier
#define Frez_stVehActGearStDatId                     					0xD053//Vehicle Actual Gear StatusDataIdentifier
#define Frez_stMotoTrqReqDatId                         				    0xD030//Motor Torque Request DataIdentifier
#define Frez_stAccPosDataId              					            0xD006//Accelerator Position DataIdentifier
#define Frez_stBSOF_bAcvHndbrkDatId      		                        0xD10C//BSOF_bAcvHndbrk DataIdentifier
#define Frez_stDriSbeltAttachDatId                    				    0xD080//Driver Seatbelt Attached DataIdentifier
#define Frez_stHmi_AcvBrkSnsr1DatId                            	  	    0xD102//Hmi_AcvBrkSnsr1 DataIdentifier
#define Frez_stVehOperModeDatId                        					0xD051//Vehicle Operation Mode DataIdentifier
#define Frez_stVATCDId              									0xD04E//VehicleActualTotalCurrentDataIdentifier
#define Frez_stVATVDId                   								0xD04F//VehicleActualTotal VoltageDataIdentifier
#define Frez_stMAWSDId                    								0xD03D//Motor ActualWorkingStatusDataIdentifier
#define Frez_stMASDId                            						0xD034//Motor Actual Speed DataIdentifier
#define Frez_stMATDId                         						    0xD05A//Motor Actual Torque DataIdentifier
#define Frez_stMIVDId              							            0xD038//Motor Inverter Voltage DataIdentifier
#define Frez_stMotoActTempDatId              					        0xD036//Motor Actual Temperature DataIdentifier
#define Frez_stBatSOCDatId                            					0xD062//Battery SOC DataIdentifier
#define Frez_stBFLDId                      								0xD01B//Battery Fault Level DataIdentifier
#define Frez_stBatInsRDataId								            0xD01C//BatteryInsulationResistanceDataIdentifier
#define Frez_stBatExtVolDatId               						    0xD01E//Battery External Voltage DataIdentifier
#define Frez_stBatAveTemDID      				                   	    0xD02B//Battery Average Temperature DID
#define Frez_stBHVI_LStDID              							    0xD026//Battery High VoltageInt-lockingStatusDID
#define Frez_stOBCTempDatId					                      		0xD016//OBC Temperature DataIdentifier
#define Frez_stBatTotalCurDatId                  				        0xD027//Battery Total Current DataIdentifier
#define Frez_stOBCInVolDatId					                      	0xD013//OBC Input Voltage DataIdentifier
#define Frez_stOBCOutVolDatId            				     			0xD014//OBC Output Voltage DataIdentifier
#define Frez_stOBCOutCurDatId                     				        0xD015//OBC Output Current DataIdentifier
#define Frez_stGlobalRTDatId           				                    0xF010//Global Real Time DataIdentifier

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

//extern uint8 FRM_RealTime_UDS[7];

extern uint8 OBDII_RelatedDtc_WriteToEEprom(ubyte* Wr_tiEEprom);
void Get_CurrentRecordnum_CurrentPos(void);
void Get_CurrentRecordnum_CurrentPosAfterClear(uint32 DTC_Val);
#endif /* UPPERHFILE_OBDII_DIAG_SNAPSHOT_H_ */
