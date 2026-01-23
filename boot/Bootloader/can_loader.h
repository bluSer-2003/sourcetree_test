/*
 * CAN_LOADER.h
 *
 *  Created on: 2021-12-7
 *      Author: xielijie
 */

#ifndef CAN_LOADER_H_
#define CAN_LOADER_H_

#include  "struct.h"

#define  RUN_Z7_0_flag_ADDR  	0x4009fe08
#define NC_DEFAULT_SEED 		0xa548fd85
#define NC_UDS_KEYMASK 			0x22cd54a1
#define CANLOADER_Start_Addr	0x40050000

#define Session_defult 1
#define Session_program 2
#define Session_extension 3

#define TP_SingleFrame_C                            0x00
#define TP_FirstFrame_C                             0x10
#define TP_ContinueFrame_C                          0x20
#define TP_ControlFrame_C                           0x30

#define Support_Service_num 						13

#define TP_StartDiagnosticSession                   0x10
#define TP_SecurityAccess                           0x27
#define TP_TesterPresent                            0x3E
#define TP_EcuReset                                 0x11
#define TP_CommunicationControl                     0x28
#define TP_ControlDTCSetting                        0x85
#define TP_ReadDataByIdentifier                     0x22
#define TP_WriteDataByIdentifier                    0x2E
#define TP_RoutineCtlByIdentifier                   0x31
#define TP_RequestDownload                          0x34
#define TP_TransferData                             0x36
#define TP_RequestTransferExit                      0x37

//****************************************消极响应代码 *****************************************************************//
#define  General_Reject                             0x10                 //general error
#define  Service_Not_Supported                      0x11                 //服务器不支持客户端请求的诊断服务
#define  Sub_Function_Not_Supported                 0x12                 //服务器不支持客户端请求诊断服务的子功能
#define  Incorrect_Message_Length_Or_Invalid_Format 0x13                 //请求报文数据长度（或者格式）不符合标准
#define  Response_Too_Long                          0x14                 //the response to be generated exceeds the maximum number of bytes available by the underlying network layer.
#define  Busy_Repeat_Request                        0x21                 //the server is temporarily too busy to perform the requested operation
#define  Conditions_Not_Correct                     0x22                 //Prerequisites not fulfilled or a expected request sequence was not kept
#define  requestSequenceError                       0x24                 //server expects a different sequence of request messages or message to that sent bythe clien.
#define  Request_Out_Of_Range                       0x31                 //请求超出范围
#define  Security_Access_Denied                     0x33                 //Access to protected functions denied
#define  Invalid_Key                                0x35                 //The keyword (key) transmitted after a security access (securityAccess) was incorrect
#define  Exceed_N_Of_Attempts                       0x36                 //The number of allowed failed access attempts to protected functions (securityAccess) was exceeded
#define  Required_T_D_N_Expired                     0x37                 //requiredTimeDelayNotExpired
#define  generalProgrammingFailure                  0x72                 //This response code indicates that the server detected an error when erasing or programming a memory location in the permanent memory device
#define  Response_Pending                           0x78                 //服务器正忙，暂时无法处理客户端发出的请求
#define  SNS_In_Active_dtc                          0X81                 //service Not Supported In Active Diagnostic Mode                                       //The requested diagnosis service cannot be accessed in the present diagnosis mode
#define  effective_code                             0x81                 //有效码,只第一位和第七位有效
#define  ServiceNotSupportedInActiveSession         0x7F                 //
#define  SubFunctionNotSupportedInActiveSession     0x7E                 //
#define  Upordown_Operation_Denied                  0x70                 //上传下载拒绝
#define  Transfer_Data_Break                        0x71                 //传输数据暂停
#define  Block_Sequence_Counter_Error               0x73                 //块序列计数器错误
#define  Voltage_Over                               0x92                 //电压过高
#define  Voltage_Below                              0x93                 //电压过低


#define Support_Service      		1
#define Not_Support_Service  		0
#define SuppDiagSesnD         		1
#define Not_SupDiagSesnD     		0
#define SuppDiagSesnP         		2
#define Not_SupDiagSesnP     		0
#define SuppDiagSesnE         		3
#define Not_SupDiagSesnE     		0

#define stRecFinish  				1
#define stRecDoing   				2
#define stRecWrong   				3
#define stSendDoing  				4
#define stSendFinish 				5
#define stSendWrong  				6

#define stNoNeedCF   0
#define stWatingCF   1
#define stRecCFOK    2

#define OBDII_TP_valWFTmax 			6
//****************************************诊断模式*****************************************************************//
#define Default_Session               0x01
#define Program_Session               0x02
#define Extended_Session              0x03
//****************************************诊断相关 *****************************************************************//
#define Routine_Data_SIZE 7

#define CheckFlashDri           0xF001
#define CheckProPrecondition    0x0203
#define EraseMemory             0xFF00
#define CheckAppSoft            0xDFFF
#define TestSwapA				0xDD0A
#define TestSwapB				0xDD0B
#define Readval					0xDD0C
//****************************************安全进入相关 *****************************************************************//
#define Security_Level0               0x00
#define Security_Level1               0x01
#define Security_Level2               0x09

#define SupRead      1
#define SupWrite     2
#define SupRW        3
#define NotSupRW     4
//******************************************DID定义 ******************************************************************//
#define Veh_Data_SIZE 10

#define	BootSoftwareIdentification          				(0xF180)
#define	OBDII_SupplierNum	        				    	(0xF18A)
#define	OBDII_EVPTECUHwNum         		                    (0xF192)
#define OBDII_EVPTECUSWNum 			                        (0xF194)
#define OBDII_SSECUSWVerNum 		                    	(0xF195)
#define OBDII_EndModePart 			                        (0xF1CB)
#define OBDII_SGMWECUAppSwVer 			                    (0xF1C1)
#define OBDII_SupplierHWVerNum 			                    (0xF193)
#define OBDII_SGMWECUCalSwVerNum 			                (0xF1C2)
#define VehicleIdentificationCode							(0xF190)
#define	BootSoftwareIdAddr          						(0xFFFF40)

#define MAX_NUMBEROFBLOCK_LENGTH	0xFFF
 struct stCanObj
 {
   uword  uwMOFCRL;    // Function Control Register Low
   uword  uwMOFCRH;    // Function Control Register High
   uword  uwMOFGPRL;   // FIFO/Gateway Pointer Register Low
   uword  uwMOFGPRH;   // FIFO/Gateway Pointer Register High
   uword  uwMOIPRL;    // Interrupt Pointer Register Low
   uword  uwMOIPRH;    // Interrupt Pointer Register High
   uword  uwMOAMRL;    // Acceptance Mask Register Low
   uword  uwMOAMRH;    // Acceptance Mask Register High
   //ubyte  ubData[8];   // Message Data 0..7
  union
  {
    ubyte   ubData[8];  // Message Data 0..7
    uword  uwData[4];  // Message Data 0..7
    struct
    {
      uword uwDataLow;
      uword uwDataHigh;
    } stData;
  } MODATAn32bit;
   uword  uwMOARL;     // Arbitration Register Low
   uword  uwMOARH;     // Arbitration Register High
   uword  uwMOCTRL;    // Control Register Low
   uword  uwMOCTRH;    // Control Register High
 };

 typedef struct
{
	volatile union UBYTE8 CanBus_valRecCanData8;//  Rec_CanData8
	uint8 CanBus_valDataLength;//CanBus_DataLength

	ubyte  CanBus_flgRecActive  :1;//    Rec_flgReceiveActive
	ubyte                        :0;   //?????????????????,??h?????

}RecCan_valSeverDataNew;      //CAN??????????????L???   RecCan_SeverDataNew
 
 typedef struct
 {
    ubyte   valActSid;        //服务标识符
    ubyte   stSeviceAct;      //服务有效标示--激活服务
    uword   lServiceR;        //接收的服务整体字节长度
    uword   lServiceS;        //VCU发送的返回帧数据长度
    ubyte   valWrongCode;     //错误代码
    uword   lRecCnt;          //接收计数
    uword   lSendCnt;         //发送计数
    ubyte   numSendSN;        //连续帧发送计数
    ubyte   TP_valRecBuf_MP[4200];   //接收BUF
    ubyte   TP_valSendBuf_MP[100];  //发送BUF
    ubyte   TP_posSevice;
 }CL_SerRAndS_TDSTR;

 typedef struct
  {
      ubyte seed_size;
      ubyte seed[16];
      ubyte key_size;
      ubyte key[16];
  } CL_SeedAndKey_TDSTR;

typedef struct
{
	uint16 VehDataFid;
	uint8 VehDatalen;
	ubyte *VehDatainf;
	uint8 VehDataWriteFinsh;
	uint8 VehDataDSessionRW;
	uint8 VehDataPSessionRW;
	uint8 VehDataESessionRW;
	uint8 VehDataSupSecLevel;
} CL_VehData_TDSTR;

typedef struct
{
	ubyte   valRecFS;
	ubyte   valRecBS;
	ubyte   valRecSN;
	ubyte   valRecStmin;
	ubyte   stRecCF;
}CL_RCF_TDSTR;

typedef struct
{
	uword RoutineFid;
	uint8 SupDSessionOrNot;
	uint8 SupPSessionOrNot;
	uint8 SupESessionOrNot;
	uint8 RoutineSupSecLevel;
} CL_RoutineDID_TDSTR;

typedef struct
{
	const uint8 valSid;   //服务ID
	const uint8 Support_Or_Not;   //服务ID
	const uint8 SupDiagSesnD_Or_Not;   //支持默认诊断模式
	const uint8 SupDiagSesnP_Or_Not;   //编程会话
	const uint8 SupDiagSesnE_Or_Not;   //扩展会话
	const uint8 Secu_Lev;       //安全级别
}CL_Service_TDSTR;

extern uint8 CL_stFrameControl_MP;
extern uint8 Security_Level_Session[2];
extern uint8 CL_stDiagSeon_MP;
extern uint8 CL_valSecLev_MP;
extern uint8 CL_valSecLev_last_MP;
extern uint8 CL_fgForbidWrite_MP;
extern CL_VehData_TDSTR OBD_Veh_InfLst[Veh_Data_SIZE];
extern CL_Service_TDSTR OBDII_Service_demondLst[Support_Service_num];
extern CL_SerRAndS_TDSTR CL_valEffService_STR;

ubyte OBDII_CallBack_Security_Condition(void);
ubyte Requestvehicleinfor_process(uint16 valPid_LO);
ubyte OBDII_CallBack_RoutineCtl_Condition(ubyte Routine_num);
ubyte OBDII_Unexpect_Frame_Process(ubyte valFrameType_LO,ubyte valSn_LO);
ubyte OBDII_Rec_Diagdata(ubyte valFrameType_LO,ubyte *cmd,uword valFrameData_LO);

void CL_RecDiagService_Process(void);
void CL_StartDiagnosticSession_Process(void);
void CL_SecurityAccess_Process();
void CL_TesterPresent_Process(void);
void CL_EcuReset_Process();
void CL_ReadDataByIdentifier_Process(void);
void CL_WriteDataByIdentifier_Process(void);
void CL_SecurityAccess_Seed(void);
void CL_SecurityAccess_Key(void);
void CL_RoutineControl_Process();
void CL_CommunicationControl_Process(void);
void CL_ControlDTCSetting_Process(void);
void CL_EraseBlock(ubyte valByte_LO);
void OBDII_Neg_Response(void);
void OBDII_CmdHandler_Rec(ubyte *cmd);
void OBDII_SendControlFrame(void);
void OBDII_Send_ResPonsReqdata(void);
void OBDII_Send_ResPonsCondata(void);
void OBDII_SendAck(ubyte sendbuf[8]);
void OBDII_CallBack_EcuReset_Execute(ubyte ECU_stResetMode);
extern void UDS_RequestDownload_Process(void);
extern void UDS_TransferData_Process(void);
extern void UDS_RequestTransferExit_Process();
#endif /* CAN_LOADER_H_ */
