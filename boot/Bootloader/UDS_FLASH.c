/*
 * UDS_FLASH.c
 *
 *  Created on: 2021-12-11
 *      Author: xielijie
 */
#include "struct.h"
#include "CAN_LOADER.h"
#define CLIB_FLASH_P_BURST_LENGTH 4088
uint8 UFlash_fgCRCFinish_MP;
uint8 UFlash_fgCheckAppFinish_MP = 0;
uint8 UFlash_fgCheckCRCForJump_MP=1;
uint8 UFlash_fgCheckProgramSecond_MP;
uint8 UFlash_fgCheckCRCWrong_MP;
uint8 UFlash_fgProgramVerify_MP;
uint8 UFlash_fgWriteType_MP;
uint8 UFlash_fgWriteSize_MP;
uint8 UFlash_fgFirstCRC_MP;
uint8 UFlash_fgWriteSizeLast_MP;
uint8 UFlash_valRecDataForCheck_MP[MAX_NUMBEROFBLOCK_LENGTH - 2];
uint8 UFlash_valRecDataForCRC_MP[MAX_NUMBEROFBLOCK_LENGTH - 2];
uint8 UFlash_valWriteflashData_MP[MAX_NUMBEROFBLOCK_LENGTH - 2 + 0x80];
uint32 r1=0;
uint32 crccheck_last=0;
uint32 crccheck=0;
uint32 UFlash_valLastCRC_MP;
uint32 UFlash_numRecDataCount_MP;
uint32 UFlash_valSizeRecord_MP;
uint32 UFlash_valSizeResponse_MP;
uint32 UFlash_valSquceNum_MP;
uint32 UFlash_valRecDataLength_MP;
uint32 UFlash_valRMBASize_Remainder_MP;
uint32 UFlash_valRMBASize_Last_MP;
uint32 UFlash_valRMBAaddress_Record_MP;
uint32 UFlash_valRMBAaddress_Last_MP;
uint32 UFlash_valRMBAaddress_Remainder_MP;
typedef struct
{
	uint32 valProgramTopPtr;
	uint32 valProgramBottomPtr;
	uint32 valProgramDataSize;
}UFlash_ProgramStruct_TDSTR;
UFlash_ProgramStruct_TDSTR UFlash_valProgramStruct_TDSTR;
extern uint8 CL_fgCheckProgramFirst_MP;
extern uint8 CL_valBlockCheckSumRec_MP[4];
extern uint8 CL_valBlockCheckSumSelf_MP[4];
extern uint32 CL_valRecDataLength_MP;
extern uint32 CL_valCRCTable_MP[256];
extern uint32 UFlash_valRMBAaddress_MP;
extern uint32 UFlash_valRMBASize_MP;
void UDS_RequestDownload_Process()   //34
{
	uint32 valCounter_i_LO;
	uint32 RMBA_valaddressL_LO;
	uint32 RMBA_valaddressH_LO;
	uint32 RMBA_valsizeH_LO;
	uint32 RMBA_valsizeL_LO;
	UFlash_numRecDataCount_MP = 0;
	CL_valEffService_STR.lSendCnt=0;
	CL_valEffService_STR.valWrongCode=0;
	UFlash_valProgramStruct_TDSTR.valProgramBottomPtr = 0;
	UFlash_valProgramStruct_TDSTR.valProgramDataSize = 0;
	UFlash_valProgramStruct_TDSTR.valProgramTopPtr = 0;
	for(valCounter_i_LO=0;valCounter_i_LO<MAX_NUMBEROFBLOCK_LENGTH - 2 + 0x80;valCounter_i_LO++)
	{
		UFlash_valWriteflashData_MP[valCounter_i_LO] = 0;
	}
	RMBA_valaddressH_LO=CL_valEffService_STR.TP_valRecBuf_MP[2]*256+CL_valEffService_STR.TP_valRecBuf_MP[3];
	//RMBA_valaddressH_LO = RMBA_valaddressH_LO + 0x20;
	RMBA_valaddressL_LO=CL_valEffService_STR.TP_valRecBuf_MP[4]*256+CL_valEffService_STR.TP_valRecBuf_MP[5];
	UFlash_valRMBAaddress_MP=RMBA_valaddressH_LO * 65536 + RMBA_valaddressL_LO;
//	UFlash_valRMBAaddress_MP += 0x20000000;
	RMBA_valsizeH_LO=CL_valEffService_STR.TP_valRecBuf_MP[6] * 256 + CL_valEffService_STR.TP_valRecBuf_MP[7];
	RMBA_valsizeL_LO=CL_valEffService_STR.TP_valRecBuf_MP[8] * 256 + CL_valEffService_STR.TP_valRecBuf_MP[9];
	UFlash_valRMBASize_MP=RMBA_valsizeH_LO*65536+RMBA_valsizeL_LO;
	UFlash_valSizeRecord_MP=UFlash_valRMBASize_MP;

	UFlash_valRMBAaddress_Record_MP=UFlash_valRMBAaddress_MP;//���ʱ��record
//	if(CL_fgCheckProgramFirst_MP==1)
//	{
		if((UFlash_valRMBAaddress_MP>=0xFEF00000)&&(UFlash_valRMBAaddress_MP<0xFEF23FFF))
		{
			CL_fgCheckProgramFirst_MP=1;
			UFlash_fgCheckProgramSecond_MP=1;
			CL_valEffService_STR.TP_valSendBuf_MP[CL_valEffService_STR.lSendCnt]=0x20;//RMBA_lsize_LO;
			CL_valEffService_STR.lSendCnt++;
			CL_valEffService_STR.TP_valSendBuf_MP[CL_valEffService_STR.lSendCnt]=MAX_NUMBEROFBLOCK_LENGTH>>8;//((UFlash_valRMBASize_MP+0x02)>>8)&0xFF;
			CL_valEffService_STR.lSendCnt++;
			CL_valEffService_STR.TP_valSendBuf_MP[CL_valEffService_STR.lSendCnt]=MAX_NUMBEROFBLOCK_LENGTH;//(UFlash_valRMBASize_MP+0x02)&0xFF;
			CL_valEffService_STR.lSendCnt++;
			CL_valEffService_STR.lServiceS=CL_valEffService_STR.lSendCnt;
			OBDII_Send_ResPonsReqdata();
			UFlash_fgCRCFinish_MP=1;
			UFlash_valSquceNum_MP=1;
		}
		else
		{
			CL_valEffService_STR.valWrongCode=Request_Out_Of_Range;
			OBDII_Neg_Response();
		}
//	}
//	else
//	{
//		CL_valEffService_STR.valWrongCode=Conditions_Not_Correct;
//		OBDII_Neg_Response();
//	}

}

uint32 UFlash_MakeCRC(uint32 crc, uint32 size,ubyte*dest_ptr_CHECK)
{
	//	make_CL_valCRCTable_MP();
	while(size--)
	{
		crc = (crc >> 8)^(CL_valCRCTable_MP[(crc ^ *dest_ptr_CHECK++)&0xff]);
	}
	return crc;
}

uint32 getThreeBytesValue(const uint8 *address) {
    return (uint32)address[2] | ((uint32)address[1] << 8) | ((uint32)address[0] << 16);
}

uint8 compareThreeBytes(const uint32 NewSW_StartAdress, const uint32 OldSW_StartAdress) {
	uint32 value1 = getThreeBytesValue(NewSW_StartAdress+3);
	uint32 value2 = getThreeBytesValue(OldSW_StartAdress+3);
	if(value2==0xFFFFFF)
	{
		return 2;
	}
    if (value1 < value2) {
        return 3;
    } else if (value1 > value2) {
        return 2;
    } else {
        return 1;
    }
}



void UDS_TransferData_Process()//36
{
	uint8 stRequestResult_LO;
	uint32 numCounter_i_LO = 0,numCounter_j_LO = 0,numCounter_k_LO = 0;
	uint32 UFlash_valRec36DataLength_MP;
	UFlash_valRec36DataLength_MP=CL_valEffService_STR.lServiceR-2;
	if(stRequestResult_LO==1)
	{
		stRequestResult_LO=0;
		if((UFlash_valRec36DataLength_MP>0)&&(UFlash_valRec36DataLength_MP <= (MAX_NUMBEROFBLOCK_LENGTH - 2)))
		{
			stRequestResult_LO=1;
		}
		else
		{
			CL_valEffService_STR.valWrongCode=Incorrect_Message_Length_Or_Invalid_Format;
			OBDII_Neg_Response();
		}
	}
	if(stRequestResult_LO==1)
	{
		stRequestResult_LO=0;
		if(UFlash_valSizeRecord_MP >= UFlash_valRec36DataLength_MP)
		{
			stRequestResult_LO=1;
			UFlash_valSizeRecord_MP = UFlash_valSizeRecord_MP - UFlash_valRec36DataLength_MP;
		}
		else
		{
			CL_valEffService_STR.valWrongCode=Incorrect_Message_Length_Or_Invalid_Format;
			OBDII_Neg_Response();
		}
	}

	  if(stRequestResult_LO=1)
	  {
		  if(UFlash_valSquceNum_MP==CL_valEffService_STR.TP_valRecBuf_MP[0])
		  {
			  stRequestResult_LO=1;
			  if(UFlash_valSquceNum_MP<0xFF)
			  {
				  UFlash_valSquceNum_MP=UFlash_valSquceNum_MP+1;
			  }
			  else
			  {
				  UFlash_valSquceNum_MP=0;
			  }
		  }
		  else
		  {
			  stRequestResult_LO=0;
			  if(UFlash_valSquceNum_MP==CL_valEffService_STR.TP_valRecBuf_MP[0] + 1)
			  {
				  for(numCounter_k_LO=0;numCounter_k_LO<UFlash_valRec36DataLength_MP;numCounter_k_LO++)
				  {
					  UFlash_valRecDataForCheck_MP[numCounter_k_LO]=CL_valEffService_STR.TP_valRecBuf_MP[numCounter_k_LO+1];
				  }
				  crccheck = UFlash_MakeCRC(0xeeeeffff,UFlash_valRec36DataLength_MP,UFlash_valRecDataForCheck_MP);
				  if(crccheck==crccheck_last)
				  {
						CL_valEffService_STR.TP_valSendBuf_MP[CL_valEffService_STR.lSendCnt]=CL_valEffService_STR.TP_valRecBuf_MP[0];
						CL_valEffService_STR.lSendCnt++;
						CL_valEffService_STR.lServiceS=CL_valEffService_STR.lSendCnt;
						OBDII_Send_ResPonsReqdata();

				  }
				  else
				  {

						CL_valEffService_STR.valWrongCode=0x73;
						OBDII_Neg_Response();
				  }

			  }
			  else
			  {
				   CL_valEffService_STR.valWrongCode=0x73;
				   OBDII_Neg_Response();
			  }
		  }

	  }

	if(stRequestResult_LO==1)
	{
		for(numCounter_k_LO=0;numCounter_k_LO<UFlash_valRec36DataLength_MP;numCounter_k_LO++)
		{
			UFlash_valRecDataForCRC_MP[numCounter_k_LO]=CL_valEffService_STR.TP_valRecBuf_MP[numCounter_k_LO+1];
		}
		UFlash_numRecDataCount_MP=UFlash_numRecDataCount_MP+1;
		for(numCounter_i_LO=0;numCounter_i_LO<UFlash_valRec36DataLength_MP;numCounter_i_LO++)
		{
			UFlash_valWriteflashData_MP[numCounter_i_LO + UFlash_valProgramStruct_TDSTR.valProgramBottomPtr]=CL_valEffService_STR.TP_valRecBuf_MP[numCounter_i_LO+1];
		}
		UFlash_valProgramStruct_TDSTR.valProgramBottomPtr += UFlash_valRec36DataLength_MP;
		UFlash_valProgramStruct_TDSTR.valProgramDataSize = UFlash_valProgramStruct_TDSTR.valProgramBottomPtr - UFlash_valProgramStruct_TDSTR.valProgramTopPtr;
		while(UFlash_valProgramStruct_TDSTR.valProgramDataSize >= 0x80)
		{
			//flash_operation(UFlash_valRMBAaddress_MP,0x80,&UFlash_valWriteflashData_MP[UFlash_valProgramStruct_TDSTR.valProgramTopPtr]);
			memcpy(UFlash_valRMBAaddress_MP,&UFlash_valWriteflashData_MP[UFlash_valProgramStruct_TDSTR.valProgramTopPtr],0x80);
			UFlash_valRMBAaddress_MP += 0x80;
			UFlash_valProgramStruct_TDSTR.valProgramDataSize = UFlash_valProgramStruct_TDSTR.valProgramDataSize - 0x80;
			UFlash_valProgramStruct_TDSTR.valProgramTopPtr = UFlash_valProgramStruct_TDSTR.valProgramTopPtr + 0x80;
			UFlash_valProgramStruct_TDSTR.valProgramBottomPtr = UFlash_valProgramStruct_TDSTR.valProgramBottomPtr - 0x80;
		}
		for(numCounter_i_LO=0;numCounter_i_LO<UFlash_valProgramStruct_TDSTR.valProgramDataSize;numCounter_i_LO++)
		{
			UFlash_valWriteflashData_MP[numCounter_i_LO]=UFlash_valWriteflashData_MP[numCounter_i_LO + UFlash_valProgramStruct_TDSTR.valProgramTopPtr];
		}
		UFlash_valProgramStruct_TDSTR.valProgramTopPtr = 0;


		if(UFlash_fgCRCFinish_MP == 1)
		{
			if(UFlash_fgFirstCRC_MP == 0)
			{
				UFlash_fgFirstCRC_MP = 1;
				r1= UFlash_MakeCRC(0xffffffff,UFlash_valRec36DataLength_MP,UFlash_valRecDataForCRC_MP);
			}
			else
			{
				r1= UFlash_MakeCRC(UFlash_valLastCRC_MP,UFlash_valRec36DataLength_MP,UFlash_valRecDataForCRC_MP);
			}
			UFlash_valLastCRC_MP=r1;
			 crccheck_last=UFlash_MakeCRC(0xeeeeffff,UFlash_valRec36DataLength_MP,UFlash_valRecDataForCRC_MP);
			for(numCounter_k_LO=0;numCounter_k_LO<UFlash_valRec36DataLength_MP;numCounter_k_LO++)
			{
				UFlash_valRecDataForCRC_MP[numCounter_k_LO]=0;
				UFlash_valRecDataForCheck_MP[numCounter_k_LO]=0;
			}
		}
		CL_valEffService_STR.TP_valSendBuf_MP[CL_valEffService_STR.lSendCnt]=CL_valEffService_STR.TP_valRecBuf_MP[0];
		CL_valEffService_STR.lSendCnt++;
		CL_valEffService_STR.lServiceS=CL_valEffService_STR.lSendCnt;
		OBDII_Send_ResPonsReqdata();
	}
}
void UDS_RequestTransferExit_Process()//37
{
	if(UFlash_valProgramStruct_TDSTR.valProgramDataSize % 4 == 0)
	{
		memcpy(UFlash_valRMBAaddress_MP,&UFlash_valWriteflashData_MP[UFlash_valProgramStruct_TDSTR.valProgramTopPtr],UFlash_valProgramStruct_TDSTR.valProgramDataSize);
	}
	else
	{
		memcpy(UFlash_valRMBAaddress_MP,&UFlash_valWriteflashData_MP[UFlash_valProgramStruct_TDSTR.valProgramTopPtr],UFlash_valProgramStruct_TDSTR.valProgramDataSize + 4 - (UFlash_valProgramStruct_TDSTR.valProgramDataSize % 4));
	}
	
		CL_valEffService_STR.lServiceS=CL_valEffService_STR.lSendCnt;
		OBDII_Send_ResPonsReqdata();
}

void UDS_CheckAppSoft(void)
{
	uint16 numCounter_j_LO;
	UFlash_fgCheckAppFinish_MP = 1;

	CL_valEffService_STR.TP_valSendBuf_MP[CL_valEffService_STR.lSendCnt]=CL_valEffService_STR.TP_valRecBuf_MP[0];
	CL_valEffService_STR.lSendCnt++;
	CL_valEffService_STR.TP_valSendBuf_MP[CL_valEffService_STR.lSendCnt]=CL_valEffService_STR.TP_valRecBuf_MP[1];
	CL_valEffService_STR.lSendCnt++;
	CL_valEffService_STR.TP_valSendBuf_MP[CL_valEffService_STR.lSendCnt]=CL_valEffService_STR.TP_valRecBuf_MP[2];
	CL_valEffService_STR.lSendCnt++;
	if((UFlash_fgCheckCRCWrong_MP==1)||(UFlash_fgProgramVerify_MP==1))//((UFlash_fgCheckCRCWrong_MP==1)||(UFlash_fgProgramVerify_MP==1))
	{
		CL_valEffService_STR.TP_valSendBuf_MP[CL_valEffService_STR.lSendCnt]=1;
		CL_valEffService_STR.lSendCnt++;
		UFlash_fgCheckCRCForJump_MP=1;
	}
	else if((CL_fgCheckProgramFirst_MP==1)&&(UFlash_fgCheckProgramSecond_MP==1))
	{
		CL_valEffService_STR.TP_valSendBuf_MP[CL_valEffService_STR.lSendCnt]=0;
		CL_valEffService_STR.lSendCnt++;
		UFlash_fgCheckCRCForJump_MP=0;
	}
	CL_valEffService_STR.lServiceS=CL_valEffService_STR.lSendCnt;
	OBDII_Send_ResPonsReqdata();
}
