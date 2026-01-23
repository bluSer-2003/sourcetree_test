//****************************************************************************
// @Module        OBD_II allocation
// @Filename      OBD_II.H
// @Project       XC2000_EV
//----------------------------------------------------------------------------
// @Controller    Infineon XC2765X
//
// @Compiler      tasking
//
// @Codegenerator 2.0
//
// @Description   This file contains all function prototypes and macros for
//                the task module.
//
//----------------------------------------------------------------------------
// @Date          2007-12-9 15:15:32
//
//****************************************************************************

#ifndef OBD_II_H_
#define OBD_II_H_
#include  "OBDII_DiagData_Detect.h"
#include  "struct.h"
 //****************************************NRC -Negative Response Code**************************************************//
 #define  General_Reject                             0x10  //General Reject
 #define  Service_Not_Supported                      0x11  //Service Not Supported
 #define  Sub_Function_Not_Supported                 0x12  //SubFunction Not Supported
 #define  Incorrect_Message_Length_Or_Invalid_Format 0x13  //Incorrect Message Length Or Invalid Format
 #define  Response_Too_Long                          0x14  //Response Too Long
 #define  Busy_Repeat_Request                        0x21  //Busy Repeat Request
 #define  Conditions_Not_Correct                     0x22  //Conditions Not Correct
 #define  requestSequenceError                       0x24  //Request Sequence Error
 #define  Request_Out_Of_Range                       0x31  //Request Out Of Range
 #define  Security_Access_Denied                     0x33  //Security Access Denied
 #define  Invalid_Key                                0x35  //Invalid Key
 #define  Exceed_N_Of_Attempts                       0x36  //Exceed Number Of Attempts
 #define  Required_T_D_N_Expired                     0x37  //Required Time Delay Not Expired
 #define  generalProgrammingFailure                  0x72  //General Programming Failure
 #define  Response_Pending                           0x78  //Request Correctly Received-Response Pending
 #define  SubFunctionNotSupportedInActiveSession     0x7E  //SubFunction Not Supported In Active Session
 #define  ServiceNotSupportedInActiveSession         0x7F  //Service Not Supported In Active Session
//****************************************Session Mode*****************************************************************//
#define Default_Session               0x01
#define Program_Session               0x02
#define Extended_Session              0x03
//****************************************Security Level *****************************************************************//
#define Security_Level0 0
extern ubyte  Security_lib_Level1;
extern ubyte  Security_lib_Level2;
//extern ubyte   Security_Level_Session[2];
 //********************************************************************************************************************//
extern ubyte Dsg_flgInitDtcInfoFinish_MP;//Whether initialization is complete
extern ubyte UDS_stCtlDTC;//control DTC setting 1:on 2:off
extern uword UDS_tiDiagSeon;//counter for S2server/S3client

extern ubyte Security_FAA_st;//The count for error security access is not 0 when ig on
extern ubyte CANRecForbid_st;//1:Forbidden to receive CAN data 0:allow
extern ubyte CANSendForbid_st;//1:Forbidden to send CAN data 0:allow
extern ubyte CI_flgDTCFunAddrVaild_MP;//whether to address for functionality
//********************************************************************************************************************//
extern ubyte OBDII_flgReqSeedNum;
extern ubyte  OBDII_Support_Service_num;
//****************************************************************************************//
extern const Service_CSTR *OBDII_Service_demondLst;

typedef struct
 {
     ubyte seed_size;
     ubyte seed[4];
     ubyte key_size;
     ubyte key[4];
 } uds_27_seedkey;
 typedef struct
 {
   	ubyte UDS_Version1;
   	ubyte UDS_Version2;
   	ubyte UDS_Version_Year;
   	ubyte UDS_Version_Month;
   	ubyte UDS_Version_Day;
 } UDS_Version;

 typedef struct
  {
      ubyte OBDII_numRecordRC_Mp;
      ubyte OBDII_stExcReturnValue;
      ubyte OBDII_stExcRcSession;
      ubyte OBDII_flagExcStartRc;
  } UDS_RcRecord;

 extern uds_27_seedkey UDS_Valseed;

 extern void StartDiagnosticSession_Process(void);
 extern void EcuReset_Process(void);
 extern void ClearDiagnosticInformation_Process(void);
 extern void ReadDTCInfor_Process(void);
 extern void ReadDataByIdentifier_Process(void);
 extern void ReadMemoryByAddress_Process(void);
 extern void SecurityAccess_Process(void);
 extern void CommunicationCtr_Process(void );
 extern void WriteDataByIdentifier_Process(void);
 extern void InputOutputControlByIdentifier_Process(void);
 extern void Routine_Control_Process(void);
 extern void WriteMemoryByAddress_Process(void);
 extern void TesterPresent_Process(void);
 extern void ControlDTCSetting_Process(void);

 extern void DiagSeon_Timer(void);
 extern void Securiry_Timer(void);
 extern UDS_Version Gets_UDS_Version(void);


#endif /* OBD_II_H_ */
