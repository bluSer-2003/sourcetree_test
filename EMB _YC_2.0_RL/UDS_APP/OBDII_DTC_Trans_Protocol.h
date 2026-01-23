#ifndef TRANS_PROTOCOL_H_
#define TRANS_PROTOCOL_H_

//********************************Supported services***************//
#define TP_StartDiagnosticSession                      0x10
#define TP_EcuReset                                    0x11
#define TP_ClearDiagnosticInformation                  0x14
#define TP_ReadDTCInfor                                0x19
#define TP_ReadDataByIdentifier                        0x22
#define TP_ReadMemoryByAddress                         0x23
#define TP_SecurityAccess                              0x27
#define TP_CommunicationControl                        0x28
#define TP_WriteDataByIdentifier                       0x2E
#define TP_InputOutputControlByIdentifier              0x2F
#define TP_RoutineCtlByIdentifier                      0x31
#define TP_RequestDownload                             0x34
#define TP_TransferData                                0x36
#define TP_RequestTransferExit                         0x37
#define TP_WriteMemoryByAddress                        0x3D
#define TP_TesterPresent                               0x3E
#define TP_ControlDTCSetting                           0x85
#define TP_ReadPowerSysInf                             0x01
#define TP_ReadVehInf                                  0x09
//**************************frame type***************************//
#define TP_SingleFrame_C                            0x00
#define TP_FirstFrame_C                             0x10
#define TP_ContinueFrame_C                          0x20
#define TP_ControlFrame_C                           0x30

#define OBDII_TP_valWFTmax 6  //

//*************************************Communication type  SID28***********************************//
#define  CommunicatinType     1
#define  NMCommunicatinType   2
#define  NM_CommunicatinType  3

//**************************************control frame`s parameters*************************************//
#define  OBDII_TP_valSendFS     0x00
#define  OBDII_TP_valSendBS     0x08
#define  OBDII_TP_valSendST     0x14

#define  OBD_BSvalue       		15	//When sending continue frames,SN`s maximum
#define  OBDII_tiSendCF_Max       	15  	//Maximum interval between receiving continue frames.  unit 10ms

typedef struct
{
	ubyte   valActSid;        		//SID
	ubyte   stSeviceAct;      		//sever active
	uword   lServiceR;        		//Valid byte length received
	uword   lServiceS;        		//Valid byte length sent
	ubyte   valWrongCode;     		//NRC
	uword   lRecCnt;          		//A count of received bytes
	uword   lSendCnt;         		//A count of sent bytes
	ubyte   numSendSN;        		//send continue frame`s SN
	ubyte   TP_valRecBuf_MP[500];   	//Received data
	ubyte   TP_valSendBuf_MP[500];  	//Sent data
	ubyte   TP_posSevice;
}stSerRAndS;

typedef struct
{
	ubyte   valRecFS;
	ubyte   valRecBS;
	ubyte   valRecSN;
	ubyte   valRecStmin;
	ubyte   stRecCF;
}stRCF; //control frame information

extern stSerRAndS OBDII_TP_stEffService;
extern stRCF      OBDII_TP_stRecCF;

extern ubyte OBDII_TP_FrameControl;//0-Not in control frame or continue frame status£¬
                                   //1-The first frame has been received and no control frame has been sent£¬
                                   //2-The control frame has been sent and is in the state of receiving continue frames£¬
                                   //3-continue frames are received£¬4-continue frames receive timeout.
				   
void OBDII_CmdHandler_Rec(ubyte *cmd,ubyte OBDII_lRecDataLength_LO);
void OBDII_Neg_Response(void);
void OBDII_SendControlFrame(void);
void OBDII_Send_ResPonsReqdata(void);
void OBDII_Send_ResPonsCondata(void);
void OBDII_TpLayer_Timer(void);

#endif /* TRANS_PROTOCOL_H_ */
