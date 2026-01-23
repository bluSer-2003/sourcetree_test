/*
 * 		Can_Loader.c
 *
 * 	 	Created on: 2018年3月9日
 *  	Author: think
 *  	Function: Parse the CAN Message for UDS Diagnostic Services
 */
/*******************************************************************************
 **                      Includes                                              **
 *******************************************************************************/
#include "struct.h"
#include "CAN_LOADER.h"
#include "global_struct.h"
#include "mttcan.h"
#include "iodefine.h"
/*******************************************************************************
 **                       variable                                             **
 *******************************************************************************/
uint8 Security_Level_Session[2] = {Extended_Session,Program_Session};
uint8 CL_valMaskKey_MP[4];
uint8 CL_valMaskKeySecond_MP[4];
uint8 CL_fgSendCF_MP = 0;
uint8 CL_fgForbidWrite_MP = 0;
uint8 CL_fgDTCFunAddrVaild_MP = 0;
uint8 CL_fgCheckProgramFirst_MP = 0;
uint8 CL_stDiagSeon_MP = 1;
uint8 CL_stFrameControl_MP = 0;  //0--未在流控阵及后续帧状态，1-开启流控帧状态，2-流控帧已发出，处于接收后续帧状态，3--后续帧接收完成，4--后续帧接收超时
uint8 CL_stContinueFrameState_MP = 0;  //0--未在流控阵及后续帧状态，1-开启流控帧状态，2-流控帧已发出，处于接收后续帧状态，3--后续帧接收完成
uint8 CL_valBS_MP = 8;
uint8 CL_valSid_MP = 0;
uint8 CL_valCFnum_MP = 0;
uint8 CL_valSnLast_MP = 0;
uint8 CL_valSecLev_MP = 0;
uint8 CL_valSendFS_MP = 0;
uint8 CL_valFrameType_MP = 0;
uint8 CL_valRecDataLength_MP;
uint8 CL_valSecLev_last_MP = 0;
uint8 CL_valSecurityAcesseErrNumCount_MP = 0;
uint8 CL_valContinueServiceValid_MP = 0;

uint8 CL_valBlockCheckSumRec_MP[4];
uint8 CL_valBlockCheckSumSelf_MP[4];
uint8 CL_valFingerBuffArray_MP[152];
uint8 CL_fgCheckEraseErr_MP = 0;
uint32 UFlash_valRMBASize_MP;
uint32 UFlash_valRMBAaddress_MP;
uint32 CL_valRandNumForSeed_MP = 0;
CL_RCF_TDSTR  CL_valRecCF_STR;
CL_SerRAndS_TDSTR CL_valEffService_STR;
CL_SeedAndKey_TDSTR CL_valSeedAndKey_STR;
extern uint8 BM_valBootType_MP;
extern uint8 BM_fgRecCANChannel_MP;
extern uint8 UFlash_fgCheckAppFinish_MP;
extern uint8 UFlash_fgCheckCRCForJump_MP;
extern uint8 UFlash_fgCheckCRCWrong_MP;
extern uint8 UFlash_fgProgramVerify_MP;
extern uint8 UFlash_fgCRCFinish_MP;
extern uint8 UFlash_fgFirstCRC_MP;
extern uint8 UFlash_valRecDataForCRC_MP[1000];
extern uint32 r1;
extern uint32 UFlash_valLastCRC_MP;
extern uint32 CL_valRecordDiag5msS3Counter_MP;
extern uint32 BM_numSecurityAccessResetCount_MP;
uint32 CFlash_valWriteAddressStartLast_MP;
union
{
	unsigned int uData;
	unsigned char cArray[4];
}UN_INTBYTE;
const uint32 nc_uds_keymul[32] = {
		0x7678,0x9130,0xd753,0x750f,0x72cb,0x55f7,0x13da,0x786b,0x372a,0x4932,0x0e7c,0x3687,0x3261,0xa82c,0x8935,0xd00c,
		0x1995,0x4311,0xb854,0x0d8d,0x9863,0x1a21,0xf753,0xd6d3,0xb15d,0x7f3d,0x6821,0x791c,0x26c5,0x2e37,0x0e69,0x64a0 };

const uint32 CL_valCRCTable_MP[256] = {
		0, 			1996959894, 3993919788, 2567524794, 124634137,	1886057615,	3915621685, 2657392035, 249268274, 	2044508324,
		3772115230, 2547177864, 162941995, 	2125561021, 3887607047,	2428444049, 498536548,	1789927666, 4089016648, 2227061214,
		450548861, 	1843258603, 4107580753, 2211677639, 325883990,	1684777152, 4251122042, 2321926636, 335633487, 	1661365465,
		4195302755, 2366115317, 997073096, 	1281953886, 3579855332,	2724688242, 1006888145, 1258607687, 3524101629, 2768942443,
		901097722, 	1119000684, 3686517206, 2898065728, 853044451,	1172266101, 3705015759, 2882616665, 651767980, 	1373503546,
		3369554304, 3218104598, 565507253, 	1454621731, 3485111705,	3099436303, 671266974, 	1594198024, 3322730930, 2970347812,
		795835527, 	1483230225, 3244367275, 3060149565, 1994146192,	31158534, 	2563907772, 4023717930, 1907459465, 112637215,
		2680153253, 3904427059, 2013776290, 251722036, 	2517215374,	3775830040, 2137656763, 141376813, 	2439277719, 3865271297,
		1802195444, 476864866, 	2238001368, 4066508878, 1812370925,	453092731, 	2181625025, 4111451223, 1706088902, 314042704,
		2344532202, 4240017532, 1658658271, 366619977, 	2362670323,	4224994405, 1303535960, 984961486, 	2747007092, 3569037538,
		1256170817, 1037604311, 2765210733, 3554079995, 1131014506,	879679996, 	2909243462, 3663771856, 1141124467, 855842277,
		2852801631, 3708648649, 1342533948, 654459306, 	3188396048,	3373015174, 1466479909, 544179635, 	3110523913, 3462522015,
		1591671054, 702138776, 	2966460450, 3352799412, 1504918807,	783551873, 	3082640443, 3233442989, 3988292384, 2596254646,
		62317068, 	1957810842, 3939845945, 2647816111, 81470997,	1943803523, 3814918930, 2489596804, 225274430, 	2053790376,
		3826175755, 2466906013, 167816743, 	2097651377, 4027552580,	2265490386, 503444072, 	1762050814, 4150417245, 2154129355,
		426522225, 	1852507879, 4275313526, 2312317920, 282753626,	1742555852, 4189708143, 2394877945, 397917763, 	1622183637,
		3604390888, 2714866558, 953729732, 	1340076626, 3518719985,	2797360999, 1068828381, 1219638859, 3624741850, 2936675148,
		906185462, 	1090812512, 3747672003, 2825379669, 829329135,	1181335161, 3412177804, 3160834842, 628085408, 	1382605366,
		3423369109, 3138078467, 570562233, 	1426400815, 3317316542,	2998733608, 733239954, 	1555261956, 3268935591, 3050360625,
		752459403, 	1541320221, 2607071920, 3965973030, 1969922972,	40735498, 	2617837225, 3943577151, 1913087877, 83908371,
		2512341634, 3803740692, 2075208622, 213261112, 	2463272603,	3855990285, 2094854071, 198958881, 	2262029012, 4057260610,
		1759359992, 534414190, 	2176718541, 4139329115, 1873836001,	414664567, 	2282248934, 4279200368, 1711684554, 285281116,
		2405801727, 4167216745, 1634467795, 376229701, 	2685067896,	3608007406, 1308918612, 956543938, 	2808555105, 3495958263,
		1231636301, 1047427035, 2932959818, 3654703836, 1088359270,	936918000, 	2847714899, 3736837829, 1202900863, 817233897,
		3183342108, 3401237130, 1404277552, 615818150, 	3134207493,	3453421203, 1423857449, 601450431, 	3009837614, 3294710456,
		1567103746, 711928724, 	3020668471, 3272380065, 1510334235,	755167117
};

CL_Service_TDSTR OBDII_Service_demondLst[Support_Service_num]=
{
		{TP_StartDiagnosticSession,Support_Service,SuppDiagSesnD,SuppDiagSesnP,SuppDiagSesnE,Security_Level0},
		{TP_SecurityAccess,Support_Service,Not_SupDiagSesnD,SuppDiagSesnP,SuppDiagSesnE,Security_Level0},
		{TP_TesterPresent,Support_Service,SuppDiagSesnD,SuppDiagSesnP,SuppDiagSesnE,Security_Level0},
		{TP_EcuReset,Support_Service,SuppDiagSesnD,SuppDiagSesnP,SuppDiagSesnE,Security_Level0},
		{TP_CommunicationControl,Support_Service,Not_SupDiagSesnD,Not_SupDiagSesnP,SuppDiagSesnE,Security_Level0},
		{TP_ControlDTCSetting,Support_Service,Not_SupDiagSesnD,Not_SupDiagSesnP,SuppDiagSesnE,Security_Level0},
		{TP_ReadDataByIdentifier,Support_Service,SuppDiagSesnD,SuppDiagSesnP,SuppDiagSesnE,Security_Level0},
		{TP_WriteDataByIdentifier,Support_Service,SuppDiagSesnD,SuppDiagSesnP,SuppDiagSesnE,Security_Level0},
		{TP_RoutineCtlByIdentifier,Support_Service,Not_SupDiagSesnD,SuppDiagSesnP,SuppDiagSesnE,Security_Level0},
		{TP_RequestDownload,Support_Service,SuppDiagSesnD,SuppDiagSesnP,SuppDiagSesnE,Security_Level0},
		{TP_TransferData,Support_Service,SuppDiagSesnD,SuppDiagSesnP,SuppDiagSesnE,Security_Level0},
		{TP_RequestTransferExit,Support_Service,SuppDiagSesnD,SuppDiagSesnP,SuppDiagSesnE,Security_Level0},
};

CL_VehData_TDSTR OBD_Veh_InfLst[Veh_Data_SIZE]=
{
		/* F180*/	{BootSoftwareIdentification,    10, &CL_valFingerBuffArray_MP[0],	0,	SupRead,SupRead,SupRead,	Security_Level0},
		/* F18A*/	{OBDII_SupplierNum, 			7,	&CL_valFingerBuffArray_MP[10], 	0, 	SupRead,SupRead,SupRead,	Security_Level0},
		/* F192*/	{OBDII_EVPTECUHwNum, 			11,	&CL_valFingerBuffArray_MP[17], 	0, 	SupRead,SupRead,SupRead,  	Security_Level0},
		/* F194*/	{OBDII_EVPTECUSWNum,           	14, &CL_valFingerBuffArray_MP[28], 	0, 	SupRead,SupRead,SupRead,	Security_Level0},
		/* F195*/	{OBDII_SSECUSWVerNum,           12, &CL_valFingerBuffArray_MP[42], 	0, 	SupRead,SupRead,SupRead,	Security_Level0},
		/* F1CB*/	{OBDII_EndModePart,            	4,  &CL_valFingerBuffArray_MP[54], 	0, 	SupRead,SupRead,SupRead,	Security_Level0},
		/* F1C1*/	{OBDII_SGMWECUAppSwVer,         18, &CL_valFingerBuffArray_MP[58], 	0, 	SupRead,SupRead,SupRead,  	Security_Level0},
		/* F193*/	{OBDII_SupplierHWVerNum,        10, &CL_valFingerBuffArray_MP[76], 	0, 	SupRead,SupRead,SupRead,  	Security_Level0},
		/* F1C2*/	{OBDII_SGMWECUCalSwVerNum,      18, &CL_valFingerBuffArray_MP[86], 	0, 	SupRead,SupRead,SupRead,  	Security_Level0},
		/* F190*/	{VehicleIdentificationCode,     17, &CL_valFingerBuffArray_MP[104], 0, 	SupRead,SupRead,SupRead,  	Security_Level0},
};

CL_RoutineDID_TDSTR CL_vaRoutineDID_STR[Routine_Data_SIZE]=
{
		{CheckFlashDri,Not_SupDiagSesnD,SuppDiagSesnP,Not_SupDiagSesnE,Security_Level2},
		{CheckProPrecondition,Not_SupDiagSesnD,Not_SupDiagSesnP,SuppDiagSesnE,Security_Level2},
		{EraseMemory,Not_SupDiagSesnD,SuppDiagSesnP,Not_SupDiagSesnE,Security_Level2},
		{CheckAppSoft,Not_SupDiagSesnD,SuppDiagSesnP,Not_SupDiagSesnE,Security_Level2},
		{TestSwapA,Not_SupDiagSesnD,SuppDiagSesnP,Not_SupDiagSesnE,Security_Level2},
		{TestSwapB,Not_SupDiagSesnD,SuppDiagSesnP,Not_SupDiagSesnE,Security_Level2},
		{Readval,Not_SupDiagSesnD,SuppDiagSesnP,Not_SupDiagSesnE,Security_Level2},
};
/*******************************************************************************
 **                     function                                               **
 *******************************************************************************/
void OBDII_CmdHandler_Rec(ubyte *cmd)
{
	uint8 valServiceValid_LO = 0;
	uint8 numCounter_i_LO = 0,numCounter_j_LO = 0;
	uint8 valSidValid_LO = 0;
	uint8 valFrameType_LO=0;
	uint8 valSn_LO=0;
	uint8 valEffSid_LO;
	valFrameType_LO = cmd[0] & 0xF0;
	if((((valFrameType_LO) == TP_ControlFrame_C)&&(CL_stFrameControl_MP == stRecCFOK))
			||(CL_valContinueServiceValid_MP == 1)||(((CL_stContinueFrameState_MP!=0))&&(cmd[1]==0x3e)&&(cmd[0]==0x2)))
	{
		valServiceValid_LO = 0;
	}
	else if(((valFrameType_LO) == TP_SingleFrame_C)
			||((valFrameType_LO) == TP_FirstFrame_C)
			||((valFrameType_LO) == TP_ControlFrame_C)
			||((valFrameType_LO) == TP_ContinueFrame_C))
	{
		CL_valFrameType_MP = valFrameType_LO;
		valServiceValid_LO = 1;
	}

	if(valServiceValid_LO == 1)
	{
		if (CL_valFrameType_MP == TP_SingleFrame_C)
		{
			CL_valEffService_STR.lServiceR=cmd[0] & 0x0F;
			CL_valSid_MP = cmd[1];

			if((CL_valEffService_STR.lServiceR == 0x02) && (CL_valSid_MP == 0x00)
				&& ((cmd[2] == 0x00) || (cmd[2] == 0x80)) && (CL_fgDTCFunAddrVaild_MP == 0))
			{
				CL_valEffService_STR.valActSid = CL_valSid_MP;
				CL_valEffService_STR.valWrongCode = Service_Not_Supported;
				OBDII_Neg_Response();
			}
			else
			{
				;
			}
		}
		else if (CL_valFrameType_MP == TP_FirstFrame_C)
		{
			CL_valEffService_STR.lServiceR=((uword)((cmd[0]&0x0F)*256) + cmd[1]);
			if(CL_valEffService_STR.lServiceR>6)
			{
				CL_valSid_MP = cmd[2];
				CL_stFrameControl_MP=1;
				CL_stContinueFrameState_MP = 1;
			}
		}
		else if(CL_valFrameType_MP == TP_ControlFrame_C)
		{
			if(CL_valRecDataLength_MP >= 3)
			{
				CL_valRecCF_STR.valRecFS    = cmd[0]&0x0F;
				CL_valRecCF_STR.valRecBS    = cmd[1];
				CL_valRecCF_STR.valRecStmin = cmd[2];

				if((CL_valRecCF_STR.valRecFS==0)&&(CL_fgDTCFunAddrVaild_MP==FALSE))
					CL_valRecCF_STR.stRecCF=stRecCFOK;
			}
		}
		else if(CL_valFrameType_MP == TP_ContinueFrame_C)
		{
			valSn_LO = cmd[0]&0x0F;
		}
		for(numCounter_j_LO = 0;numCounter_j_LO < Support_Service_num;numCounter_j_LO++)
		{
			if(CL_valSid_MP == OBDII_Service_demondLst[numCounter_j_LO].valSid)
			{
				valSidValid_LO = 1;
				CL_valEffService_STR.TP_posSevice = numCounter_j_LO;
			}
		}
		if((valSidValid_LO == 0) && (CL_valSid_MP != 0) && (CL_valFrameType_MP != TP_ControlFrame_C) && (CL_valFrameType_MP != TP_ContinueFrame_C))
		{
			CL_valEffService_STR.valActSid = CL_valSid_MP;
			CL_valEffService_STR.valWrongCode=Service_Not_Supported;
			if(CL_fgDTCFunAddrVaild_MP == FALSE)
			{
				OBDII_Neg_Response();
			}
			CL_valSid_MP = 0;
		}
		else if((CL_valEffService_STR.stSeviceAct == stSendDoing)&&(CL_valFrameType_MP == TP_ContinueFrame_C))
		{
			CL_valEffService_STR.valActSid = CL_valSid_MP;
			CL_valEffService_STR.valWrongCode=Request_Out_Of_Range;
			OBDII_Neg_Response();

			CL_valSid_MP = 0;
		}
		valEffSid_LO=OBDII_Unexpect_Frame_Process(CL_valFrameType_MP,valSn_LO);
		if(valEffSid_LO!=0)
			CL_valSid_MP = 0;
		if(((CL_valFrameType_MP == TP_SingleFrame_C)&&(((CL_valEffService_STR.lServiceR>=7)&&(CL_valRecDataLength_MP==8))||((CL_valEffService_STR.lServiceR<7)&&(CL_valRecDataLength_MP>=(CL_valEffService_STR.lServiceR+1)))))
				||((CL_valFrameType_MP == TP_FirstFrame_C)&&(CL_valRecDataLength_MP == 8))
				||((CL_valFrameType_MP == TP_ControlFrame_C)&&(CL_valRecDataLength_MP >= 3))
				||((CL_valFrameType_MP == TP_ContinueFrame_C)&&((((CL_valEffService_STR.lServiceR-CL_valEffService_STR.lRecCnt)>7)&&(CL_valRecDataLength_MP == 8))||(((CL_valEffService_STR.lServiceR-CL_valEffService_STR.lRecCnt)<=7)&&(CL_valRecDataLength_MP >=((CL_valEffService_STR.lServiceR-CL_valEffService_STR.lRecCnt)+1))))))
		{
		}
		else
			CL_valSid_MP = 0;

		if(valEffSid_LO == 0)
		{
			CL_valEffService_STR.valActSid=CL_valSid_MP;
			if((valFrameType_LO == TP_SingleFrame_C)||(valFrameType_LO == TP_FirstFrame_C)||((CL_fgDTCFunAddrVaild_MP == FALSE)&&(valFrameType_LO == TP_ContinueFrame_C)))
			{
				if(CL_valSid_MP!=0)
				{
					CL_valEffService_STR.stSeviceAct=OBDII_Rec_Diagdata(valFrameType_LO,cmd,CL_valEffService_STR.lServiceR);
				}
				else
				{
					CL_valEffService_STR.stSeviceAct=0;
					CL_valEffService_STR.lServiceR=0;
					for(numCounter_i_LO = 0; numCounter_i_LO < 100; numCounter_i_LO++)
					{
						CL_valEffService_STR.TP_valRecBuf_MP[numCounter_i_LO]=0;
					}
				}
				if(CL_valEffService_STR.stSeviceAct==1)
				{
					CL_RecDiagService_Process();
				}
			}
		}
		else
		{
			CL_stFrameControl_MP = 0;
			CL_stContinueFrameState_MP = 0;
		}
	}
}

ubyte OBDII_Rec_Diagdata(ubyte valFrameType_LO,ubyte *cmd,uword valFrameData_LO)//BMS接收后续帧工作在此完成
{
	uint8 numCounter_i_LO = 0,numCounter_j_LO = 0;
	uint8 valSn_LO = 0;
	uint8 fgRecReqFinish_LO = 0;
	if (valFrameType_LO == TP_SingleFrame_C)
	{
		for(numCounter_i_LO = 0; numCounter_i_LO < 100; numCounter_i_LO++)
		{
			CL_valEffService_STR.TP_valRecBuf_MP[numCounter_i_LO]=0;
		}
		memcpy(&CL_valEffService_STR.TP_valRecBuf_MP[0],&(cmd[2]),6);

		fgRecReqFinish_LO=stRecFinish;
		CL_valEffService_STR.lRecCnt=CL_valEffService_STR.lServiceR-1;
	}
	else if (valFrameType_LO == TP_FirstFrame_C)
	{
		for(numCounter_j_LO = 0; numCounter_j_LO <100; numCounter_j_LO++)
		{
			CL_valEffService_STR.TP_valRecBuf_MP[numCounter_j_LO]=0;
		}
		memcpy(&CL_valEffService_STR.TP_valRecBuf_MP[0],&(cmd[3]),5);
		CL_valEffService_STR.lRecCnt = 5;
	}
	else if (valFrameType_LO == TP_ContinueFrame_C)
	{
		valSn_LO=(cmd[0] & 0x0F);
		if(CL_stFrameControl_MP == 2)
		{
			if((valFrameData_LO-1-CL_valEffService_STR.lRecCnt)>7)
			{
				memcpy(&CL_valEffService_STR.TP_valRecBuf_MP[CL_valEffService_STR.lRecCnt],&(cmd[1]),7);
				CL_valEffService_STR.lRecCnt += 7;
				fgRecReqFinish_LO = stRecDoing;
				if((CL_valSendFS_MP != 0)&&((valSn_LO%CL_valSendFS_MP)==0))
					OBDII_SendControlFrame();
				CL_stContinueFrameState_MP = 2;
			}
			else
			{
				memcpy(&CL_valEffService_STR.TP_valRecBuf_MP[CL_valEffService_STR.lRecCnt],&(cmd[1]),(valFrameData_LO-CL_valEffService_STR.lRecCnt));
				fgRecReqFinish_LO=stRecFinish;
				CL_stContinueFrameState_MP = 3;
				CL_stFrameControl_MP = 3;
			}
		}
	}
	return fgRecReqFinish_LO;
}
ubyte OBDII_Unexpect_Frame_Process(ubyte valFrameType_LO,ubyte valSn_LO)
{
	ubyte valResult_LO=0;
	if(valFrameType_LO == TP_FirstFrame_C)
	{
		CL_valSnLast_MP = 0;
		CL_valCFnum_MP = 0;
	}
	else if(valFrameType_LO == TP_SingleFrame_C)
	{
		CL_valSnLast_MP = 0;
		CL_valCFnum_MP = 0;
	}
	else if(valFrameType_LO == TP_ContinueFrame_C)
	{
		CL_valCFnum_MP = 0;
	}
	else if(valFrameType_LO == TP_ControlFrame_C)
	{
		CL_valCFnum_MP++;
	}
	if((valFrameType_LO == TP_SingleFrame_C)&&((CL_valEffService_STR.lServiceR>7)||(CL_valEffService_STR.lServiceR==0)))
		valResult_LO = 1;
	if((valFrameType_LO == TP_FirstFrame_C)&&((CL_valEffService_STR.lServiceR>4095)||(CL_valEffService_STR.lServiceR<7)))
		valResult_LO = 2;
	if(valFrameType_LO == TP_ContinueFrame_C)
	{
		if(((valSn_LO-CL_valSnLast_MP)==1)||((CL_valSnLast_MP==0x0f)&&(valSn_LO)==0))
		{
			CL_valSnLast_MP=valSn_LO;
		}
		else
			valResult_LO=3;
	}
	if((valFrameType_LO == TP_ControlFrame_C)&&(CL_valRecCF_STR.valRecFS==2))
		valResult_LO=4;
	if((valFrameType_LO == TP_ControlFrame_C)&&(CL_valCFnum_MP>OBDII_TP_valWFTmax))
		valResult_LO=5;
	if((CL_fgDTCFunAddrVaild_MP == TRUE)&&(valFrameType_LO == TP_FirstFrame_C))
	{
		valResult_LO=6;
	}
	return valResult_LO;
}

void CL_RecDiagService_Process(void)
{
	switch(CL_valEffService_STR.valActSid)
	{
	case TP_StartDiagnosticSession:  //10
	{
		CL_StartDiagnosticSession_Process();
		break;
	}
	case TP_SecurityAccess:  		//27
	{
		CL_SecurityAccess_Process();
		break;
	}
	case TP_TesterPresent:  		//3E
	{
		CL_TesterPresent_Process();
		break;
	}
	case TP_EcuReset:  				//11
	{
		CL_EcuReset_Process();
		break;
	}
	case TP_CommunicationControl: 	//28
	{
		CL_CommunicationControl_Process();
		break;
	}
	case TP_ControlDTCSetting:  	//85
	{
		CL_ControlDTCSetting_Process();
		break;
	}
	case TP_ReadDataByIdentifier:  //22
	{
		CL_ReadDataByIdentifier_Process();
		break;
	}
	case TP_WriteDataByIdentifier:  //2E
	{
		CL_WriteDataByIdentifier_Process();
		break;
	}

	case TP_RoutineCtlByIdentifier:  //31
	{
		CL_RoutineControl_Process();
		break;
	}
	case TP_RequestDownload:		//34
	{
		UDS_RequestDownload_Process();
		break;
	}
	case TP_TransferData:  			//36
	{
		UDS_TransferData_Process();
		break;
	}
	case TP_RequestTransferExit:   //37
	{
		UDS_RequestTransferExit_Process();
		break;
	}
	default :
	{
		if(CL_fgDTCFunAddrVaild_MP == FALSE)
		{
			CL_valEffService_STR.valWrongCode=Service_Not_Supported;
			OBDII_Neg_Response();
		}
		break;
	}
	}
}
void CL_StartDiagnosticSession_Process()//10
{
	ubyte stDiagSeon_LO = 0;
	ubyte stDiagSeonNotResponse_LO = 0;
	ubyte stRequestResult_LO;
	unsigned int DelayForReset = 0x9000;
	CL_valEffService_STR.lSendCnt=0;
	CL_valEffService_STR.valWrongCode=0;
	CL_valEffService_STR.valActSid=0x10;
	stDiagSeon_LO = CL_valEffService_STR.TP_valRecBuf_MP[0];
	stDiagSeonNotResponse_LO = stDiagSeon_LO&0xF0;
	if(CL_valEffService_STR.lServiceR==0x02)
	{
		stRequestResult_LO=TRUE;
	}
	else
	{
		CL_valEffService_STR.valWrongCode=Incorrect_Message_Length_Or_Invalid_Format;
		OBDII_Neg_Response();
	}
	if(stRequestResult_LO==TRUE)
	{
		stRequestResult_LO=FALSE;
		if((stDiagSeon_LO==0x01)||(stDiagSeon_LO==0x02)||(stDiagSeon_LO==0x03)
				||(stDiagSeon_LO==0x81)||(stDiagSeon_LO==0x82)||(stDiagSeon_LO==0x83))
		{
			stRequestResult_LO=TRUE;
		}
		else
		{
			CL_valEffService_STR.valWrongCode=Sub_Function_Not_Supported;
			OBDII_Neg_Response();
		}
	}
	if(stRequestResult_LO==TRUE)
	{
		stDiagSeon_LO = stDiagSeon_LO & 0x0F;
		if((stDiagSeon_LO == 0x01)||(stDiagSeon_LO == 0x02))
		{
			CL_valSecLev_MP = 0;
			CL_valSecLev_last_MP= 0;
			//CL_valRecordDiag5msS3Counter_MP = BM_val5MSCalCounter;
			CL_stDiagSeon_MP = stDiagSeon_LO&0x0F;
			CL_valEffService_STR.TP_valSendBuf_MP[CL_valEffService_STR.lSendCnt]= stDiagSeon_LO;
			CL_valEffService_STR.lSendCnt++;
			CL_valEffService_STR.TP_valSendBuf_MP[CL_valEffService_STR.lSendCnt]=0x00;
			CL_valEffService_STR.lSendCnt++;
			CL_valEffService_STR.TP_valSendBuf_MP[CL_valEffService_STR.lSendCnt]=0x32;
			CL_valEffService_STR.lSendCnt++;
			CL_valEffService_STR.TP_valSendBuf_MP[CL_valEffService_STR.lSendCnt]=0x01;
			CL_valEffService_STR.lSendCnt++;
			CL_valEffService_STR.TP_valSendBuf_MP[CL_valEffService_STR.lSendCnt]=0xF4;
			CL_valEffService_STR.lSendCnt++;
			CL_valEffService_STR.lServiceS=CL_valEffService_STR.lSendCnt;
			if(stDiagSeonNotResponse_LO!=0x80)
			OBDII_Send_ResPonsReqdata();
			if((stDiagSeon_LO==0x01))
			{
				while(DelayForReset--);
				SWSRESA0 = 1;
			}
		}
		else
		{
			if(CL_stDiagSeon_MP != 0x02)
			{
				CL_valSecLev_MP = 0;
				CL_valSecLev_last_MP= 0;
				CL_stDiagSeon_MP = stDiagSeon_LO&0x0F;
//				CL_valRecordDiag5msS3Counter_MP = BM_val5MSCalCounter;
				CL_valEffService_STR.TP_valSendBuf_MP[CL_valEffService_STR.lSendCnt]= stDiagSeon_LO;
				CL_valEffService_STR.lSendCnt++;
				CL_valEffService_STR.TP_valSendBuf_MP[CL_valEffService_STR.lSendCnt]=0x00;
				CL_valEffService_STR.lSendCnt++;
				CL_valEffService_STR.TP_valSendBuf_MP[CL_valEffService_STR.lSendCnt]=0x32;
				CL_valEffService_STR.lSendCnt++;
				CL_valEffService_STR.TP_valSendBuf_MP[CL_valEffService_STR.lSendCnt]=0x01;
				CL_valEffService_STR.lSendCnt++;
				CL_valEffService_STR.TP_valSendBuf_MP[CL_valEffService_STR.lSendCnt]=0xF4;
				CL_valEffService_STR.lSendCnt++;
				CL_valEffService_STR.lServiceS=CL_valEffService_STR.lSendCnt;
				if(stDiagSeonNotResponse_LO!=0x80)
				OBDII_Send_ResPonsReqdata();
			}
			else
			{
				BM_valBootType_MP = 3;
				CL_valEffService_STR.valWrongCode=SubFunctionNotSupportedInActiveSession;
				OBDII_Neg_Response();
			}
		}
	}
}

void CL_SecurityAccess_Process()//27
{
	static ubyte TP_stSecurityState_LO = 0;
	ubyte valRec_Key_LO[16] = {0};
	ubyte valSecurity_Level1_key_LO;
	ubyte valSecurity_Level2_key_LO;
	ubyte stRequestResult_LO = 0;
	ubyte numCounter_i_LO = 0,numCounter_j_LO = 0;
	ubyte valSecLev_LO = 0;
	valSecLev_LO = CL_valEffService_STR.TP_valRecBuf_MP[0];
	CL_valEffService_STR.lSendCnt = 0;
	CL_valEffService_STR.valWrongCode = 0;
	if((OBDII_Service_demondLst[1].SupDiagSesnD_Or_Not==CL_stDiagSeon_MP)
			||(OBDII_Service_demondLst[1].SupDiagSesnP_Or_Not==CL_stDiagSeon_MP)
			||(OBDII_Service_demondLst[1].SupDiagSesnE_Or_Not==CL_stDiagSeon_MP))
	{
		stRequestResult_LO=TRUE;
	}
	else
	{
		CL_valEffService_STR.valWrongCode=ServiceNotSupportedInActiveSession;
		OBDII_Neg_Response();
	}
	if(stRequestResult_LO==TRUE)
	{
		stRequestResult_LO=FALSE;
		if(((CL_valEffService_STR.lServiceR==0x02)&&(valSecLev_LO%2==1))||((CL_valEffService_STR.lServiceR==(CL_valSeedAndKey_STR.key_size+2))&&(valSecLev_LO%2==0)))
		{
			stRequestResult_LO=TRUE;
		}
		else
		{
			CL_valEffService_STR.valWrongCode=Incorrect_Message_Length_Or_Invalid_Format;
			OBDII_Neg_Response();
		}
	}
	if(stRequestResult_LO==TRUE)
	{
		stRequestResult_LO=FALSE;
		if((valSecLev_LO==Security_Level2)||(valSecLev_LO==Security_Level2+1)
		/*||(valSecLev_LO==Security_Level1)||(valSecLev_LO==Security_Level1+1)*/)
		{
			stRequestResult_LO=TRUE;
		}
		else
		{
			CL_valEffService_STR.valWrongCode=Sub_Function_Not_Supported;
			OBDII_Neg_Response();
		}
	}
	if(stRequestResult_LO==TRUE)
	{
		stRequestResult_LO=OBDII_CallBack_Security_Condition();
		if(stRequestResult_LO==FALSE)
		{
			CL_valEffService_STR.valWrongCode=Conditions_Not_Correct;
			OBDII_Neg_Response();
		}
	}
	valSecurity_Level1_key_LO=Security_Level1+1;
	valSecurity_Level2_key_LO=Security_Level2+1;
	if(stRequestResult_LO==TRUE)
	{
		stRequestResult_LO=FALSE;
		if(/*(((valSecLev_LO==Security_Level1)||(valSecLev_LO==valSecurity_Level1_key_LO))&&(CL_stDiagSeon_MP == Security_Level_Session[0]))
	   ||*/(((valSecLev_LO==Security_Level2)||(valSecLev_LO==valSecurity_Level2_key_LO))&&((CL_stDiagSeon_MP == Program_Session)||(CL_stDiagSeon_MP == Extended_Session))))
		{
			stRequestResult_LO=TRUE;
		}
		else
		{
			CL_valEffService_STR.valWrongCode=SubFunctionNotSupportedInActiveSession;
			OBDII_Neg_Response();
		}
	}
	if((stRequestResult_LO==TRUE)&&(valSecLev_LO%2==1))
	{
		stRequestResult_LO=FALSE;
		if(CL_valSecurityAcesseErrNumCount_MP < 3)
		{
			CL_SecurityAccess_Seed();
			CL_valEffService_STR.TP_valSendBuf_MP[CL_valEffService_STR.lSendCnt]=valSecLev_LO;
			CL_valEffService_STR.lSendCnt++;
			for(numCounter_i_LO = 0;numCounter_i_LO < CL_valSeedAndKey_STR.seed_size;numCounter_i_LO++)
			{
				if((CL_valSecLev_last_MP == (valSecLev_LO+1)))
				{
					CL_valEffService_STR.TP_valSendBuf_MP[CL_valEffService_STR.lSendCnt]=0;
					CL_valSeedAndKey_STR.seed[numCounter_i_LO] = 0;
					CL_valEffService_STR.lSendCnt++;
				}
				else
				{
					CL_valEffService_STR.TP_valSendBuf_MP[CL_valEffService_STR.lSendCnt]=CL_valSeedAndKey_STR.seed[numCounter_i_LO];
					CL_valEffService_STR.lSendCnt++;
				}
			}
			CL_valEffService_STR.lServiceS=CL_valEffService_STR.lSendCnt;
			OBDII_Send_ResPonsReqdata();
			CL_SecurityAccess_Key();
			TP_stSecurityState_LO = 1;
		}
		else
		{
			CL_valEffService_STR.valWrongCode=Required_T_D_N_Expired;
			OBDII_Neg_Response();
		}
	}
	if((stRequestResult_LO==TRUE)&&(valSecLev_LO%2==0))
	{
		stRequestResult_LO=FALSE;
		if(TP_stSecurityState_LO == 1)
		{
			stRequestResult_LO=TRUE;
			TP_stSecurityState_LO = 0;
			if(stRequestResult_LO==TRUE)
			{
				for(numCounter_j_LO = 0;numCounter_j_LO < CL_valSeedAndKey_STR.key_size;numCounter_j_LO++)
				{
					valRec_Key_LO[numCounter_j_LO]=CL_valEffService_STR.TP_valRecBuf_MP[numCounter_j_LO+1];
					if(((CL_valSeedAndKey_STR.key[numCounter_j_LO])!=(valRec_Key_LO[numCounter_j_LO]))&&((CL_valMaskKey_MP[numCounter_j_LO])!=(valRec_Key_LO[numCounter_j_LO]))&&((CL_valMaskKeySecond_MP[numCounter_j_LO])!=(valRec_Key_LO[numCounter_j_LO])))
						//stRequestResult_LO=FALSE;
						stRequestResult_LO=TRUE;
				}
			}
			if(stRequestResult_LO==TRUE)
			{
				CL_valEffService_STR.TP_valSendBuf_MP[CL_valEffService_STR.lSendCnt]=valSecLev_LO;
				CL_valEffService_STR.lSendCnt++;
				CL_valEffService_STR.lServiceS=CL_valEffService_STR.lSendCnt;
				OBDII_Send_ResPonsReqdata();
				CL_valSecLev_last_MP=valSecLev_LO;
				CL_valSecLev_MP = valSecLev_LO-1;
				CL_valSecurityAcesseErrNumCount_MP = 0;
				//BM_WriteSecurityAcesseErrNumIntoFee();
				BM_numSecurityAccessResetCount_MP = 0;
			}
			else
			{
				CL_valSecurityAcesseErrNumCount_MP++;
				//BM_WriteSecurityAcesseErrNumIntoFee();
				if((CL_valSecurityAcesseErrNumCount_MP == 1)||(CL_valSecurityAcesseErrNumCount_MP == 2))
				{
					CL_valEffService_STR.valWrongCode=Invalid_Key;
					OBDII_Neg_Response();
				}
				else if(CL_valSecurityAcesseErrNumCount_MP == 3)
				{
					CL_valEffService_STR.valWrongCode=Exceed_N_Of_Attempts;
					OBDII_Neg_Response();
				}
				else
				{

				}
			}
		}
		else
		{
			CL_valEffService_STR.valWrongCode=requestSequenceError;
			OBDII_Neg_Response();
		}
	}
}
void CL_TesterPresent_Process(void)//3E
{
	ubyte valSubFunction_LO = 0;
	ubyte stRequestResult_LO = 0;
	valSubFunction_LO = CL_valEffService_STR.TP_valRecBuf_MP[0];
	CL_valEffService_STR.lSendCnt = 0;
	CL_valEffService_STR.valWrongCode = 0;
	if(CL_valEffService_STR.lServiceR==0x02)
	{
		stRequestResult_LO=TRUE;
	}
	else
	{
		CL_valEffService_STR.valWrongCode=Incorrect_Message_Length_Or_Invalid_Format;
		OBDII_Neg_Response();
	}
	if(stRequestResult_LO==TRUE)
	{
		stRequestResult_LO=FALSE;
		if((valSubFunction_LO==0x80)||(valSubFunction_LO==0x0))
		{
			stRequestResult_LO=TRUE;
		}
		else
		{
			CL_valEffService_STR.valWrongCode=Sub_Function_Not_Supported;
			OBDII_Neg_Response();
		}
	}
	if(stRequestResult_LO==TRUE)
	{
//		CL_valRecordDiag5msS3Counter_MP = BM_val5MSCalCounter;
		stRequestResult_LO=FALSE;
		if(valSubFunction_LO==0x0)
			stRequestResult_LO=TRUE;
	}
	if(stRequestResult_LO==TRUE)
	{
		CL_valEffService_STR.TP_valSendBuf_MP[CL_valEffService_STR.lSendCnt]=valSubFunction_LO;
		CL_valEffService_STR.lSendCnt++;
		CL_valEffService_STR.lServiceS=CL_valEffService_STR.lSendCnt;
		OBDII_Send_ResPonsReqdata();
	}
}

void CL_EcuReset_Process()//11
{
	ubyte stResetMode_LO = 0;
	ubyte stRequestResult_LO = 0;
	unsigned int DelayForReset = 0x8000;
	stResetMode_LO = CL_valEffService_STR.TP_valRecBuf_MP[0];
	CL_valEffService_STR.lSendCnt = 0;
	CL_valEffService_STR.valWrongCode = 0;
	if(CL_valEffService_STR.lServiceR == 0x02)
	{
		stRequestResult_LO=TRUE;
	}
	else
	{
		CL_valEffService_STR.valWrongCode=Incorrect_Message_Length_Or_Invalid_Format;
		OBDII_Neg_Response();
	}

	if(stRequestResult_LO==TRUE)
	{
		stRequestResult_LO=FALSE;
		if((stResetMode_LO==0x01)||(stResetMode_LO==0x02)||(stResetMode_LO==0x03)
				||(stResetMode_LO==0x81)||(stResetMode_LO==0x82)||(stResetMode_LO==0x83))
		{
			stRequestResult_LO=TRUE;
		}
		else
		{
			CL_valEffService_STR.valWrongCode=Sub_Function_Not_Supported;
			OBDII_Neg_Response();
		}
	}
	if(stRequestResult_LO==TRUE)
	{
		stRequestResult_LO=FALSE;
		if((CL_stDiagSeon_MP== OBDII_Service_demondLst[CL_valEffService_STR.TP_posSevice].SupDiagSesnD_Or_Not)
				||(CL_stDiagSeon_MP== OBDII_Service_demondLst[CL_valEffService_STR.TP_posSevice].SupDiagSesnP_Or_Not)
				||(CL_stDiagSeon_MP== OBDII_Service_demondLst[CL_valEffService_STR.TP_posSevice].SupDiagSesnE_Or_Not))
		{
			stRequestResult_LO=TRUE;
		}
		else
		{
			CL_valEffService_STR.valWrongCode=ServiceNotSupportedInActiveSession;
			OBDII_Neg_Response();
		}
	}
	else
	{
		CL_valEffService_STR.valWrongCode=Conditions_Not_Correct;
		OBDII_Neg_Response();
	}
	if(stRequestResult_LO==TRUE)
	{
		stRequestResult_LO=FALSE;
		if((OBDII_Service_demondLst[CL_valEffService_STR.TP_posSevice].Secu_Lev==Security_Level0)||(CL_valSecLev_MP=OBDII_Service_demondLst[CL_valEffService_STR.TP_posSevice].Secu_Lev))
		{
			stRequestResult_LO=TRUE;
		}
		else
		{
			CL_valEffService_STR.valWrongCode=Security_Access_Denied;
			OBDII_Neg_Response();
		}
	}
	if(stRequestResult_LO==TRUE)
	{
		stRequestResult_LO=FALSE;
		OBDII_CallBack_EcuReset_Execute(stResetMode_LO&0x0f);
		if((stResetMode_LO==0x01)||(stResetMode_LO==0x02)||(stResetMode_LO==0x03))
		{
			stRequestResult_LO=TRUE;
		}
	}
	if(stRequestResult_LO==TRUE)
	{
		CL_valEffService_STR.TP_valSendBuf_MP[CL_valEffService_STR.lSendCnt]=stResetMode_LO;
		CL_valEffService_STR.lSendCnt++;
		CL_valEffService_STR.lServiceS=CL_valEffService_STR.lSendCnt;
		OBDII_Send_ResPonsReqdata();
		while(DelayForReset--);
		CL_valSecLev_MP=0;
		CL_valSecLev_last_MP = 0;
		// if(UFlash_fgCheckCRCForJump_MP==0)
		// {
			//((void(*)(void))0x20000)();
			SWSRESA0 = 1;	
		// }
	}
}

void CL_ReadDataByIdentifier_Process(void)//22
{
	uint8 numCheckInfo_LO = 0;
	uint8 stRequestResult_LO = 0;
	uint16 valPid_LO = 0;
	uint32 numCounter_i_LO = 0,numCounter_j_LO = 0,numCounter_k_LO = 0;
	CL_valEffService_STR.lSendCnt = 0;
	CL_valEffService_STR.valWrongCode = 0;
	if((CL_valEffService_STR.lServiceR>=3)&&(((CL_valEffService_STR.lServiceR-1)%2) == 0))
	{
		stRequestResult_LO=TRUE;
	}
	else
	{
		CL_valEffService_STR.valWrongCode=Incorrect_Message_Length_Or_Invalid_Format;
		OBDII_Neg_Response();
	}
	if(stRequestResult_LO==TRUE)
	{
		stRequestResult_LO=FALSE;
		if((CL_stDiagSeon_MP == OBDII_Service_demondLst[CL_valEffService_STR.TP_posSevice].SupDiagSesnD_Or_Not)
				||(CL_stDiagSeon_MP == OBDII_Service_demondLst[CL_valEffService_STR.TP_posSevice].SupDiagSesnP_Or_Not)
				||(CL_stDiagSeon_MP == OBDII_Service_demondLst[CL_valEffService_STR.TP_posSevice].SupDiagSesnE_Or_Not))
		{
			stRequestResult_LO=TRUE;
		}
		else
		{
			CL_valEffService_STR.valWrongCode=ServiceNotSupportedInActiveSession ;
			OBDII_Neg_Response();
		}
	}
	if(stRequestResult_LO==TRUE)
	{
		stRequestResult_LO=FALSE;
		if((OBDII_Service_demondLst[CL_valEffService_STR.TP_posSevice].Secu_Lev==Security_Level0)||(CL_valSecLev_MP=OBDII_Service_demondLst[CL_valEffService_STR.TP_posSevice].Secu_Lev))
		{
			stRequestResult_LO=TRUE;
		}
		else
		{
			CL_valEffService_STR.valWrongCode=Security_Access_Denied;
			OBDII_Neg_Response();
		}
	}
	if(stRequestResult_LO==TRUE)
	{
		stRequestResult_LO=FALSE;
		for(numCounter_j_LO=1;numCounter_j_LO<CL_valEffService_STR.lServiceR;)
		{
			valPid_LO=CL_valEffService_STR.TP_valRecBuf_MP[numCounter_j_LO-1]*256+CL_valEffService_STR.TP_valRecBuf_MP[numCounter_j_LO];
			for(numCounter_k_LO = 0; numCounter_k_LO<Veh_Data_SIZE;numCounter_k_LO++)
			{
				if(OBD_Veh_InfLst[numCounter_k_LO].VehDataFid == valPid_LO)
				{
					stRequestResult_LO=TRUE;
				}
			}
			numCounter_j_LO=numCounter_j_LO+2;
		}
	}
	if(stRequestResult_LO==TRUE)
	{
		for(numCounter_i_LO=1;numCounter_i_LO<CL_valEffService_STR.lServiceR;)
		{
			valPid_LO=CL_valEffService_STR.TP_valRecBuf_MP[numCounter_i_LO-1]*256+CL_valEffService_STR.TP_valRecBuf_MP[numCounter_i_LO];

			stRequestResult_LO=Requestvehicleinfor_process(valPid_LO);
			if(stRequestResult_LO==1)
			{
				numCheckInfo_LO+=1;
			}
			numCounter_i_LO=numCounter_i_LO+2;
		}
		if(numCheckInfo_LO>0)
		{
			CL_valEffService_STR.lServiceS=CL_valEffService_STR.lSendCnt;
			OBDII_Send_ResPonsReqdata();
			numCheckInfo_LO=0;
		}
	}
	else
	{
		CL_valEffService_STR.valWrongCode=Request_Out_Of_Range;
		OBDII_Neg_Response();
	}
}
ubyte Requestvehicleinfor_process(uint16 valPid_LO)
{
	ubyte numCounter_i_LO = 0,numCounter_j_LO = 0,stRequestResult_LO = 0;
	for(numCounter_i_LO = 0; numCounter_i_LO <(Veh_Data_SIZE); numCounter_i_LO++)
	{
		if(valPid_LO==OBD_Veh_InfLst[numCounter_i_LO].VehDataFid)
		{
			CL_valEffService_STR.TP_valSendBuf_MP[CL_valEffService_STR.lSendCnt]=valPid_LO/256;
			CL_valEffService_STR.lSendCnt++;
			CL_valEffService_STR.TP_valSendBuf_MP[CL_valEffService_STR.lSendCnt]=valPid_LO%256;
			CL_valEffService_STR.lSendCnt++;
			for(numCounter_j_LO = 0; numCounter_j_LO <(OBD_Veh_InfLst[numCounter_i_LO].VehDatalen); numCounter_j_LO++)
			{
				CL_valEffService_STR.TP_valSendBuf_MP[CL_valEffService_STR.lSendCnt]=OBD_Veh_InfLst[numCounter_i_LO].VehDatainf[numCounter_j_LO];
				CL_valEffService_STR.lSendCnt++;
			}
			stRequestResult_LO=1;
		}
	}
	return stRequestResult_LO;
}

void CL_WriteDataByIdentifier_Process(void)//2E
{
	uint8 valWDFidValid_LO = 0;
	uint8 stRequestResult_LO = 0;
	uint8 numCounter_i_LO = 0,numCounter_j_LO = 0,numCounter_k_LO = 0;
	uint16 valPid_LO = 0;
	CL_valEffService_STR.lSendCnt = 0;
	CL_valEffService_STR.valWrongCode = 0;
	valPid_LO = CL_valEffService_STR.TP_valRecBuf_MP[0]*256 + CL_valEffService_STR.TP_valRecBuf_MP[1];
	if(CL_valEffService_STR.lServiceR>3)
	{
		stRequestResult_LO=TRUE;
	}
	else
	{
		CL_valEffService_STR.valWrongCode=Incorrect_Message_Length_Or_Invalid_Format;
		OBDII_Neg_Response();
	}
	if(stRequestResult_LO==TRUE)
	{
		stRequestResult_LO=FALSE;
		for(numCounter_i_LO = 0; numCounter_i_LO < (Veh_Data_SIZE); numCounter_i_LO++)
		{
			if(valPid_LO==OBD_Veh_InfLst[numCounter_i_LO].VehDataFid)
			{
				stRequestResult_LO=TRUE;
				valWDFidValid_LO = 1;
				numCounter_j_LO=numCounter_i_LO;
			}
		}
	}
	if(valWDFidValid_LO == 0)
	{
		CL_valEffService_STR.valWrongCode=Request_Out_Of_Range;
		OBDII_Neg_Response();
	}
	else
	{
		stRequestResult_LO=TRUE;
	}
	if(stRequestResult_LO==TRUE)
	{
		stRequestResult_LO=FALSE;
		if((CL_valEffService_STR.lServiceR-3)==OBD_Veh_InfLst[numCounter_j_LO].VehDatalen)
		{
			stRequestResult_LO=TRUE;
		}
		else
		{
			CL_valEffService_STR.valWrongCode=Incorrect_Message_Length_Or_Invalid_Format;
			OBDII_Neg_Response();
		}
	}
	if(stRequestResult_LO==TRUE)
	{
		stRequestResult_LO=FALSE;
		if(((CL_stDiagSeon_MP==Default_Session)&&(OBD_Veh_InfLst[numCounter_j_LO].VehDataDSessionRW==SupRW))
				||((CL_stDiagSeon_MP==Program_Session)&&(OBD_Veh_InfLst[numCounter_j_LO].VehDataPSessionRW==SupRW))
				||((CL_stDiagSeon_MP==Extended_Session)&&(OBD_Veh_InfLst[numCounter_j_LO].VehDataESessionRW==SupRW)))
		{
			stRequestResult_LO=TRUE;
		}
		else
		{
			CL_valEffService_STR.valWrongCode=ServiceNotSupportedInActiveSession;
			OBDII_Neg_Response();
		}
	}
	if(stRequestResult_LO==TRUE)
	{
		stRequestResult_LO=FALSE;
		if((OBDII_Service_demondLst[CL_valEffService_STR.TP_posSevice].Secu_Lev==Security_Level0)||(CL_valSecLev_MP=OBDII_Service_demondLst[CL_valEffService_STR.TP_posSevice].Secu_Lev))
		{
			stRequestResult_LO=TRUE;
		}
		else
		{
			CL_valEffService_STR.valWrongCode=Security_Access_Denied;
			OBDII_Neg_Response();
		}
	}
	if(stRequestResult_LO==TRUE)
	{
		stRequestResult_LO=FALSE;
		if((OBD_Veh_InfLst[numCounter_j_LO].VehDataSupSecLevel==Security_Level0)||(CL_valSecLev_MP== OBD_Veh_InfLst[numCounter_j_LO].VehDataSupSecLevel))
		{
			stRequestResult_LO=TRUE;
		}
		else
		{
			CL_valEffService_STR.valWrongCode=Security_Access_Denied;
			OBDII_Neg_Response();
		}
	}
	if(stRequestResult_LO==TRUE)
	{
		for(numCounter_k_LO = 0; numCounter_k_LO <(OBD_Veh_InfLst[numCounter_j_LO].VehDatalen); numCounter_k_LO++)
		{
			OBD_Veh_InfLst[numCounter_j_LO].VehDatainf[numCounter_k_LO]=CL_valEffService_STR.TP_valRecBuf_MP[numCounter_k_LO+2];
		}
		CL_valEffService_STR.TP_valSendBuf_MP[CL_valEffService_STR.lSendCnt]=valPid_LO/256;
		CL_valEffService_STR.lSendCnt++;
		CL_valEffService_STR.TP_valSendBuf_MP[CL_valEffService_STR.lSendCnt]=valPid_LO%256;
		CL_valEffService_STR.lSendCnt++;
		CL_valEffService_STR.lServiceS=CL_valEffService_STR.lSendCnt;
		OBDII_Send_ResPonsReqdata();
	}
}
uint8 genRand[4];
void CL_SecurityAccess_Seed(void)  //CL_SecurityAccess_Process调用
{
	CL_valSeedAndKey_STR.seed_size = 4;
	genRand[1]=(1>>4)^0x12;
	genRand[2]=(1>>12)^0x34;
	genRand[3]=(1>>8)^0x56;
	genRand[0]=(1)^0x78;
	
	memcpy(CL_valSeedAndKey_STR.seed,genRand,CL_valSeedAndKey_STR.seed_size);
}
uint8  App_au8CmacResult[4];
void CL_SecurityAccess_Key(void) //CL_SecurityAccess_Process调用
{
	CL_valSeedAndKey_STR.key_size=4;
	App_au8CmacResult[0]=00;
	App_au8CmacResult[1]=00;
	App_au8CmacResult[2]=00;
	App_au8CmacResult[3]=00;
	
	memcpy(CL_valSeedAndKey_STR.key,App_au8CmacResult,CL_valSeedAndKey_STR.key_size);
}

void Write_30_Flash(void)
{
	uint8 FlashDataBuffer[1024] = {0xFF};
	unsigned int i;
	FlashDataBuffer[0]=30;
	for(i = 0;i < 152;i++)
	{
		FlashDataBuffer[i+4]=CL_valFingerBuffArray_MP[i];
	}

	//	FlashInit();
//	FLASH_EraseSector(0xB000);
	//	FlashInit();
//	fls_ctx_data_t flash_write;
//	flash_write.dest = (0x1000000);
//	flash_write.mode = FLS_OP_SYNC;
//	flash_write.size = 0x400U;
//	flash_write.src = FlashDataBuffer;
//	FLASH_Write(&flash_write);
	//	delay_ms(1);
}

/**
 * CL_ControlDTCSetting_Process()
 * 描述  UDS的85服务内容。
 * 输入
 * 返回
 */
void CL_ControlDTCSetting_Process() //85DTC设置
{
	CL_valEffService_STR.lSendCnt = 0;
	CL_valEffService_STR.TP_valSendBuf_MP[CL_valEffService_STR.lSendCnt] = CL_valEffService_STR.TP_valRecBuf_MP[0];
	CL_valEffService_STR.lSendCnt++;
	CL_valEffService_STR.lServiceS = CL_valEffService_STR.lSendCnt;
	OBDII_Send_ResPonsReqdata();
}

/**
 * CL_CommunicationControl_Process()
 * 描述  UDS的28服务内容。
 * 输入
 * 返回
 */
void CL_CommunicationControl_Process() //28通讯控制
{
	CL_valEffService_STR.lSendCnt = 0;
	CL_valEffService_STR.TP_valSendBuf_MP[CL_valEffService_STR.lSendCnt] = CL_valEffService_STR.TP_valRecBuf_MP[0];
	CL_valEffService_STR.lSendCnt++;
	CL_valEffService_STR.lServiceS = CL_valEffService_STR.lSendCnt;
	OBDII_Send_ResPonsReqdata();
}

void CL_RoutineControl_Process()//31
{
	uint16 valPid_LO;
	uint8 stRequestResult_LO=0;
	uint32 numCounter_i_LO,numCounter_j_LO;
	uint8 valSendBuffer_LO[8];
	CL_valEffService_STR.lSendCnt=0;
	CL_valEffService_STR.valWrongCode=0;
	valPid_LO=CL_valEffService_STR.TP_valRecBuf_MP[1]*256+CL_valEffService_STR.TP_valRecBuf_MP[2];

	if((OBDII_Service_demondLst[CL_valEffService_STR.TP_posSevice].SupDiagSesnD_Or_Not==CL_stDiagSeon_MP)
			||(OBDII_Service_demondLst[CL_valEffService_STR.TP_posSevice].SupDiagSesnP_Or_Not==CL_stDiagSeon_MP)
			||(OBDII_Service_demondLst[CL_valEffService_STR.TP_posSevice].SupDiagSesnE_Or_Not==CL_stDiagSeon_MP))
	{
		stRequestResult_LO=TRUE;

	}
	else
	{
		CL_valEffService_STR.valWrongCode=ServiceNotSupportedInActiveSession;
		OBDII_Neg_Response();
	}

	if(stRequestResult_LO==TRUE)
	{
		stRequestResult_LO=FALSE;
		if((CL_valEffService_STR.TP_valRecBuf_MP[0]==0x01)||(CL_valEffService_STR.TP_valRecBuf_MP[0]==0x02)||(CL_valEffService_STR.TP_valRecBuf_MP[0]==0x03))
		{
			stRequestResult_LO=TRUE;
		}
		else
		{
			CL_valEffService_STR.valWrongCode=Sub_Function_Not_Supported;
			OBDII_Neg_Response();
		}
	}
	if(stRequestResult_LO==TRUE)
	{
		stRequestResult_LO=FALSE;
		if(CL_valEffService_STR.lServiceR>=0x04)
		{
			stRequestResult_LO=TRUE;
		}
		else
		{
			CL_valEffService_STR.valWrongCode=Incorrect_Message_Length_Or_Invalid_Format;
			OBDII_Neg_Response();
		}
	}
	if(stRequestResult_LO==TRUE)
	{
		stRequestResult_LO=FALSE;
		for(numCounter_i_LO = 0;numCounter_i_LO < Routine_Data_SIZE;numCounter_i_LO++)
		{
			if(valPid_LO == CL_vaRoutineDID_STR[numCounter_i_LO].RoutineFid)
			{
				stRequestResult_LO=TRUE;
				numCounter_j_LO=numCounter_i_LO;
			}
		}
		if(stRequestResult_LO==TRUE)
		{
			stRequestResult_LO=TRUE;
		}
		else
		{
			CL_valEffService_STR.valWrongCode=Request_Out_Of_Range;
			OBDII_Neg_Response();
		}
	}
	if(stRequestResult_LO==TRUE)
	{
		stRequestResult_LO=OBDII_CallBack_RoutineCtl_Condition(numCounter_j_LO);
		if(stRequestResult_LO==TRUE)
		{
			stRequestResult_LO=TRUE;
		}
		else
		{
			CL_valEffService_STR.valWrongCode=Conditions_Not_Correct;
			OBDII_Neg_Response();
		}
	}
	if(stRequestResult_LO==TRUE)
	{
		stRequestResult_LO=FALSE;
		if((OBDII_Service_demondLst[CL_valEffService_STR.TP_posSevice].Secu_Lev==Security_Level0)
				||(OBDII_Service_demondLst[CL_valEffService_STR.TP_posSevice].Secu_Lev==CL_valSecLev_MP))
		{
			stRequestResult_LO=TRUE;
		}
		else
		{
			CL_valEffService_STR.valWrongCode=Security_Access_Denied;
			OBDII_Neg_Response();
		}
	}

	if(stRequestResult_LO==TRUE)
	{
		stRequestResult_LO=FALSE;
		if(((CL_stDiagSeon_MP==Default_Session)&&(CL_vaRoutineDID_STR[numCounter_j_LO].SupDSessionOrNot==SuppDiagSesnD))
				||((CL_stDiagSeon_MP==Program_Session)&&(CL_vaRoutineDID_STR[numCounter_j_LO].SupPSessionOrNot==SuppDiagSesnP))
				||((CL_stDiagSeon_MP==Extended_Session)&&(CL_vaRoutineDID_STR[numCounter_j_LO].SupESessionOrNot==SuppDiagSesnE)))
		{
			stRequestResult_LO=TRUE;
		}
		else
		{
			CL_valEffService_STR.valWrongCode=ServiceNotSupportedInActiveSession;
			OBDII_Neg_Response();
		}
	}
	if(stRequestResult_LO==TRUE)
	{
		 if(CL_vaRoutineDID_STR[numCounter_j_LO].RoutineFid==EraseMemory)
		{
			if(CL_valSecLev_MP == Security_Level2)
			{
				valSendBuffer_LO[0] = 0x03;
				valSendBuffer_LO[1] = 0x7f;
				valSendBuffer_LO[2] = 0x31;
				valSendBuffer_LO[3] = 0x78;
				valSendBuffer_LO[4] = 0xAA;
				valSendBuffer_LO[5] = 0xAA;
				valSendBuffer_LO[6] = 0xAA;
				valSendBuffer_LO[7] = 0xAA;
				OBDII_SendAck(valSendBuffer_LO);
				if(CL_valEffService_STR.TP_valRecBuf_MP[3] == 0x44)
				{
					//CL_EraseBlock(4);
				}
				else
				{
					//CL_EraseBlock(3);
				}
				for(numCounter_i_LO = 0;numCounter_i_LO < MAX_NUMBEROFBLOCK_LENGTH - 2;numCounter_i_LO++)
				{
					UFlash_valRecDataForCRC_MP[numCounter_i_LO]=0;
				}
				r1=0;
				BM_valBootType_MP = 5;
				CL_fgCheckProgramFirst_MP=1;
				UFlash_fgProgramVerify_MP=0;
				UFlash_valLastCRC_MP=0;
				UFlash_fgCRCFinish_MP=0;
				UFlash_fgFirstCRC_MP=0;
				UFlash_fgCheckAppFinish_MP = 0;
				CFlash_valWriteAddressStartLast_MP=0x01200000;
				if(CL_fgCheckEraseErr_MP==0)
				{
					CL_valEffService_STR.TP_valSendBuf_MP[CL_valEffService_STR.lSendCnt]=CL_valEffService_STR.TP_valRecBuf_MP[0];
					CL_valEffService_STR.lSendCnt++;
					CL_valEffService_STR.TP_valSendBuf_MP[CL_valEffService_STR.lSendCnt]=CL_valEffService_STR.TP_valRecBuf_MP[1];
					CL_valEffService_STR.lSendCnt++;
					CL_valEffService_STR.TP_valSendBuf_MP[CL_valEffService_STR.lSendCnt]=CL_valEffService_STR.TP_valRecBuf_MP[2];
					CL_valEffService_STR.lSendCnt++;
					CL_valEffService_STR.lServiceS=CL_valEffService_STR.lSendCnt;
					OBDII_Send_ResPonsReqdata();
				}
				else
				{
					valSendBuffer_LO[0] = 0x03;
					valSendBuffer_LO[1] = 0x7f;
					valSendBuffer_LO[2] = 0x31;
					valSendBuffer_LO[3] = 0x22;
					valSendBuffer_LO[4] = 0xAA;
					valSendBuffer_LO[5] = 0xAA;
					valSendBuffer_LO[6] = 0xAA;
					valSendBuffer_LO[7] = 0xAA;
					OBDII_SendAck(valSendBuffer_LO);
				}
			}
			else
			{
				CL_valEffService_STR.valWrongCode=Security_Access_Denied;
				OBDII_Neg_Response();
			}
		}
		else if(CL_vaRoutineDID_STR[numCounter_j_LO].RoutineFid==CheckProPrecondition)
		{
			CL_valEffService_STR.TP_valSendBuf_MP[CL_valEffService_STR.lSendCnt]=CL_valEffService_STR.TP_valRecBuf_MP[0];
			CL_valEffService_STR.lSendCnt++;
			CL_valEffService_STR.TP_valSendBuf_MP[CL_valEffService_STR.lSendCnt]=CL_valEffService_STR.TP_valRecBuf_MP[1];
			CL_valEffService_STR.lSendCnt++;
			CL_valEffService_STR.TP_valSendBuf_MP[CL_valEffService_STR.lSendCnt]=CL_valEffService_STR.TP_valRecBuf_MP[2];
			CL_valEffService_STR.lSendCnt++;
			CL_valEffService_STR.TP_valSendBuf_MP[CL_valEffService_STR.lSendCnt]=0;
			CL_valEffService_STR.lSendCnt++;
			CL_valEffService_STR.lServiceS=CL_valEffService_STR.lSendCnt;
			OBDII_Send_ResPonsReqdata();
		}

		else if(CL_vaRoutineDID_STR[numCounter_j_LO].RoutineFid==CheckAppSoft)
		{
			//UDS_CheckAppSoft();
			CL_valEffService_STR.TP_valSendBuf_MP[CL_valEffService_STR.lSendCnt]=CL_valEffService_STR.TP_valRecBuf_MP[0];
			CL_valEffService_STR.lSendCnt++;
			CL_valEffService_STR.TP_valSendBuf_MP[CL_valEffService_STR.lSendCnt]=CL_valEffService_STR.TP_valRecBuf_MP[1];
			CL_valEffService_STR.lSendCnt++;
			CL_valEffService_STR.TP_valSendBuf_MP[CL_valEffService_STR.lSendCnt]=CL_valEffService_STR.TP_valRecBuf_MP[2];
			CL_valEffService_STR.lSendCnt++;
			CL_valEffService_STR.TP_valSendBuf_MP[CL_valEffService_STR.lSendCnt]=0;
			CL_valEffService_STR.lSendCnt++;
			CL_valEffService_STR.lServiceS=CL_valEffService_STR.lSendCnt;
			OBDII_Send_ResPonsReqdata();
		}

		else if(CL_vaRoutineDID_STR[numCounter_j_LO].RoutineFid==CheckFlashDri)
		{
			CL_valBlockCheckSumRec_MP[0]=CL_valEffService_STR.TP_valRecBuf_MP[3];
			CL_valBlockCheckSumRec_MP[1]=CL_valEffService_STR.TP_valRecBuf_MP[4];
			CL_valBlockCheckSumRec_MP[2]=CL_valEffService_STR.TP_valRecBuf_MP[5];
			CL_valBlockCheckSumRec_MP[3]=CL_valEffService_STR.TP_valRecBuf_MP[6];
			UFlash_fgCRCFinish_MP=0;
			UFlash_fgFirstCRC_MP=0;
			UN_INTBYTE.uData=r1 ^ 0xffffffff;
			CL_valBlockCheckSumSelf_MP[0]=UN_INTBYTE.cArray[0];
			CL_valBlockCheckSumSelf_MP[1]=UN_INTBYTE.cArray[1];
			CL_valBlockCheckSumSelf_MP[2]=UN_INTBYTE.cArray[2];
			CL_valBlockCheckSumSelf_MP[3]=UN_INTBYTE.cArray[3];
			if((CL_valBlockCheckSumRec_MP[0]!=CL_valBlockCheckSumSelf_MP[0])||(CL_valBlockCheckSumRec_MP[1]!=CL_valBlockCheckSumSelf_MP[1])
					||(CL_valBlockCheckSumRec_MP[2]!=CL_valBlockCheckSumSelf_MP[2])||(CL_valBlockCheckSumRec_MP[3]!=CL_valBlockCheckSumSelf_MP[3]))
			{
				UFlash_fgCheckCRCWrong_MP=1;
//				FLASH_EraseSector(App_au8Rsa4096Signature_FlashSBLStartAdr);
			}
			else
			{
				UFlash_fgCheckCRCWrong_MP=0;
			}
			//MTTCAN_Stop(0);
			((void(*)(void))0xFEF00000)();
			UDS_CheckAppSoft();
		}
		else
		{
			CL_valEffService_STR.valWrongCode=Sub_Function_Not_Supported;
			OBDII_Neg_Response();
		}
	}
}

void OBDII_SendControlFrame(void)
{
	uint8 valSendBuffer_LO[8];
	valSendBuffer_LO[0] = 0x30;
	valSendBuffer_LO[1] = 0x00;
	valSendBuffer_LO[2] = 0x01;
	valSendBuffer_LO[3] = 0xAA;
	valSendBuffer_LO[4] = 0xAA;
	valSendBuffer_LO[5] = 0xAA;
	valSendBuffer_LO[6] = 0xAA;
	valSendBuffer_LO[7] = 0xAA;
	OBDII_SendAck(valSendBuffer_LO);
	if(CL_valEffService_STR.valWrongCode != 0)
	{
		CL_stFrameControl_MP = 0;
		CL_stContinueFrameState_MP = 0;
	}
	else
		CL_stFrameControl_MP = 2;
}

void OBDII_Send_ResPonsReqdata(void)
{
	uint8 valSendBuffer_LO[8] = {0};
	uint16 numCounter_i_LO = 0,numCounter_j_LO = 0;
	CL_stFrameControl_MP = 0;
	if(CL_valEffService_STR.valWrongCode!=0)
		OBDII_Neg_Response();
	else
	{
		if(CL_valEffService_STR.lServiceS<=6)
		{
			valSendBuffer_LO[0]=CL_valEffService_STR.lServiceS+1;
			valSendBuffer_LO[1]=CL_valEffService_STR.valActSid+0x40;
			for(numCounter_i_LO=0; numCounter_i_LO < CL_valEffService_STR.lServiceS; numCounter_i_LO++)
				valSendBuffer_LO[numCounter_i_LO+2]=CL_valEffService_STR.TP_valSendBuf_MP[numCounter_i_LO];
			for(numCounter_i_LO=CL_valEffService_STR.lServiceS+2; numCounter_i_LO < 8; numCounter_i_LO++)
				valSendBuffer_LO[numCounter_i_LO]=0xAA;
			OBDII_SendAck(valSendBuffer_LO);
			CL_valEffService_STR.lSendCnt=0;
		}
		else
		{
			valSendBuffer_LO[0]=0x10+(CL_valEffService_STR.lServiceS+1)/256;
			valSendBuffer_LO[1]=(CL_valEffService_STR.lServiceS+1)%256;
			valSendBuffer_LO[2]=CL_valEffService_STR.valActSid+0x40;
			for( numCounter_j_LO = 0; numCounter_j_LO < 5; numCounter_j_LO++)
				valSendBuffer_LO[numCounter_j_LO+3]=CL_valEffService_STR.TP_valSendBuf_MP[numCounter_j_LO];
			OBDII_SendAck(valSendBuffer_LO);
			CL_valRecCF_STR.stRecCF=stWatingCF;
			CL_valEffService_STR.numSendSN=0;
			CL_valEffService_STR.lSendCnt=5;
			CL_valEffService_STR.stSeviceAct=stSendDoing;
		}
	}
	CL_stContinueFrameState_MP = 0;
}


void OBDII_Send_ResPonsCondata(void)
{
	uint8 valSendBuffer_LO[8]={0};
	uint16 numCounter_i_LO = 0,numCounter_j_LO = 0;
	if(CL_valEffService_STR.stSeviceAct==stSendDoing)
	{
		if(CL_valRecCF_STR.stRecCF==stRecCFOK)
		{
			CL_valContinueServiceValid_MP = 1;
			CL_valEffService_STR.numSendSN =CL_valEffService_STR.numSendSN+1;
			if(CL_valEffService_STR.numSendSN==(CL_valBS_MP+1))
				CL_valEffService_STR.numSendSN=0;

			valSendBuffer_LO[0]=CL_valEffService_STR.numSendSN+0x20;

			if(CL_valEffService_STR.lServiceS>(CL_valEffService_STR.lSendCnt+7))
			{
				for(numCounter_i_LO = 0; numCounter_i_LO < 7; numCounter_i_LO++)
					valSendBuffer_LO[numCounter_i_LO+1]=CL_valEffService_STR.TP_valSendBuf_MP[CL_valEffService_STR.lSendCnt+numCounter_i_LO];
				OBDII_SendAck(valSendBuffer_LO);
//				delay_ms(3);
				CL_valEffService_STR.lSendCnt+=7;
				CL_valEffService_STR.stSeviceAct=stSendDoing;
				/////////////////////////没找到为什么SN为1的那帧后续帧没发出来
				if(CL_fgSendCF_MP==0)
				{
					CL_fgSendCF_MP=1;
				}
				else if(CL_fgSendCF_MP==1)
				{
					CL_fgSendCF_MP=0;
				}
			}
			else
			{
				for(numCounter_j_LO = 0; numCounter_j_LO < (CL_valEffService_STR.lServiceS-CL_valEffService_STR.lSendCnt); numCounter_j_LO++)
					valSendBuffer_LO[numCounter_j_LO+1]=CL_valEffService_STR.TP_valSendBuf_MP[CL_valEffService_STR.lSendCnt+numCounter_j_LO];
				for(numCounter_j_LO = (CL_valEffService_STR.lServiceS-CL_valEffService_STR.lSendCnt); numCounter_j_LO < 7; numCounter_j_LO++)
					valSendBuffer_LO[numCounter_j_LO+1]=0xAA;
				OBDII_SendAck(valSendBuffer_LO);
				CL_valEffService_STR.lSendCnt=0;
				CL_valEffService_STR.stSeviceAct=stSendFinish;
				CL_valRecCF_STR.stRecCF = stWatingCF;
			}
			if(CL_valRecCF_STR.valRecBS!=0)
			{
				if(((CL_valEffService_STR.numSendSN%CL_valRecCF_STR.valRecBS) == 0)&&(CL_valEffService_STR.numSendSN != 0))
					CL_valRecCF_STR.stRecCF=stWatingCF;
			}
		}
		else
		{
			CL_valContinueServiceValid_MP = 0;
		}
	}
	else
	{
		CL_valContinueServiceValid_MP = 0;
	}
}
void OBDII_Neg_Response(void)
{
	uint8 valsendbuf_LO[8];
	if((CL_valEffService_STR.valWrongCode != Incorrect_Message_Length_Or_Invalid_Format) && (CL_fgDTCFunAddrVaild_MP == TRUE))
	{

	}
	else
	{
		valsendbuf_LO[0] = 0x03;
		valsendbuf_LO[1] = 0x7f;
		valsendbuf_LO[2] = CL_valEffService_STR.valActSid;
		valsendbuf_LO[3] = CL_valEffService_STR.valWrongCode;
		valsendbuf_LO[4] = 0xAA;
		valsendbuf_LO[5] = 0xAA;
		valsendbuf_LO[6] = 0xAA;
		valsendbuf_LO[7] = 0xAA;
		OBDII_SendAck(valsendbuf_LO);
	}

	CL_valEffService_STR.valWrongCode = 0;

}
void OBDII_Neg_78Response(void)
{
	uint8 valsendbuf_LO[8];
	valsendbuf_LO[0] = 0x03;
	valsendbuf_LO[1] = 0x7f;
	valsendbuf_LO[2] = 0x36;
	valsendbuf_LO[3] = 0x78;
	valsendbuf_LO[4] = 0xAA;
	valsendbuf_LO[5] = 0xAA;
	valsendbuf_LO[6] = 0xAA;
	valsendbuf_LO[7] = 0xAA;
	OBDII_SendAck(valsendbuf_LO);
}
void OBDII_SendAck(ubyte sendbuf[8])//
{
	
	exCAN_MSG send_msg;
   	uint8 i;
	send_msg.id    = 0x7EB;
	send_msg.len = 8;
	 for(i=0;i<8;i++)
        {
    	    send_msg.data[i] = sendbuf[i];
        }

	can_send(&send_msg,0);
}


uint8 OBDII_CallBack_Security_Condition(void)
{
	uint8 stRequestResult_LO = TRUE;
	return(stRequestResult_LO);
}

uint8 OBDII_CallBack_RoutineCtl_Condition(uint8 Routine_num)
{
	uint8 stRequestResult_LO = TRUE;

	return(stRequestResult_LO);
}
void OBDII_CallBack_EcuReset_Execute(uint8 ECU_stResetMode)
{
	switch (ECU_stResetMode)
	{
	case 0x01:		//hardReset
		break;
	case 0x02:		//keyOffOnReset
		break;
	case 0x03:		//softReset
		break;
	}
}

void CL_EraseBlock(uint8 valByte_LO)
{
	uint8 numCounter_i_LO;
//	if(CL_valEffService_STR.TP_valRecBuf_MP[valByte_LO] == 0x09)
//	{
//		for(numCounter_i_LO = 0;numCounter_i_LO < 4;numCounter_i_LO++)//OBD_valSize_block
//		{
//			FLASH_EraseSector(0x1300000 + (numCounter_i_LO * 0x40000));
//		}
//	}
//	else
//	{
//		for(numCounter_i_LO = 0;numCounter_i_LO < 8;numCounter_i_LO++)//OBD_valSize_block
//		{
//			FLASH_EraseSector(0x1200000 + (numCounter_i_LO * 0x40000));
//		}
//	}
}


