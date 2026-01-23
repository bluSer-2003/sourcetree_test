/***********************************************************************/
/*                                                                     */
/*  FILE        :Main.c                                                */
/*  DATE        :Mon, Oct 24, 2016                                     */
/*  DESCRIPTION :Main Program                                          */
/*  CPU TYPE    :                                                      */
/*                                                                     */
/*  NOTE:THIS IS A TYPICAL EXAMPLE.                                    */
/*                                                                     */
/***********************************************************************/


/*****************************************************************************
 Includes   <System Includes> , "Project Includes"
 *****************************************************************************/
#include "global.h"
#include "declare.h"
#include "r_adc.h"
#include "tmr.h"
#include "tmr_macrodriver.h"
#include "Config_CSIH0.h"
#include <mttcan.h>
#include "gtm.h"
#include "PMIC.h"
#include "global_struct.h"
#include "parameter.h"
#include "fad_flash.h"
//#include "can_command.h"
#include "can_loader.h"
//yingchuang head file
#include "SWC_BasAsst.h"
#include "SWC_TAS.h"
#include "r_fad_types.h"
//#include "rtwtypes.h"
/*****************************************************************************
 Macro definitions
 *****************************************************************************/
#define PrintEnable 1								//Enable output internal information via RLIN30
#define CAN0 0
#define CAN1 1
#define BM_FROM_APP_ADDR_DFLASH_C 0xFF20FF00
#define BM_FROM_APP_ADDR_RAM_C 0xFEF20000
#define BM_FROM_APP_ADDR_CFLASH_C 0x2000
#define APP_ADDR_START_C 0x20000
/*****************************************************************************
 Typedef definitions
 *****************************************************************************/



/*****************************************************************************
 Private variables and functions
 *****************************************************************************/
void main(void);
void Clock_Init(void);
void FlashRead(void);
void FlashWrite(void);
void ChangePara(void);
void EPSsleep(void);
/*****************************************************************************
 Imported global variables and functions (from other files)
 *****************************************************************************/
void Port_Init(void);
extern Object_t g_CANObject;
extern CAN_Info g_Can_Atrib;
extern T_u4 Data_Flash_Read[16];
extern T_u4 Flash_Data[16];
extern int Flag_CAN_flash;
extern float angle_out;    //extern TAS angle
extern int FlagCansend;
int sleepflag = 0;
#pragma section const   "boot_flg"
uint8 const     Bootloader_FLG[8] = {0x14,0x00,0x00,0x01};
uint8 const     FingerPrint[10] = {0};
#pragma section default

 unsigned char flash_test[1024]={1,2,3,4,5.6};
RecCan_valSeverDataNew BM_valRecSeverData_PHY_MP = {{0},0,0};
RecCan_valSeverDataNew BM_valRecSeverData_FUN_MP = {{0},0,0};
uint32 BM_numExitBoot_MP = 0;
uint8 BM_fgCheckSumWrong_MP = 1;
uint8 BM_valBootType_MP = 0;
uint32 BM_numSecurityAccessResetCount_MP;
uint32 delayForProgramRep = 80000;
extern uint8 CL_valRecDataLength_MP;
extern uint8 CL_fgDTCFunAddrVaild_MP;
/* Data_Flash_Read[16]
[0]:Ali_angle  [1]:Ali_flag  [2]:cur_kp     [3]:cur_ki
[4]:spd_kp     [5]:spd_ki    [6]:pos_kp     [7]:pos_ki
[8]:fw_kp      [9]:fw_ki     [10]:ov        [11]:oi
[12]:spd_max   [13]:spd_ki   [14]:pos_kp    [15]:pos_ki
*/

/*****************************************************************************
 Exported global variables and functions (to be accessed by other files)
 *****************************************************************************/
 
void BM_RecCAN_Frame_Handler(RecCan_valSeverDataNew valRecFrame_LO)
{
	uint8 BM_valRecData_MP[8] = {0};
	uint8 numCounter_i_LO = 0;
	if(valRecFrame_LO.CanBus_valDataLength==0x08)
	{
		for(numCounter_i_LO = 0;numCounter_i_LO < 8;numCounter_i_LO++)
		{
			BM_valRecData_MP[numCounter_i_LO] = valRecFrame_LO.CanBus_valRecCanData8.b[numCounter_i_LO];
		}
		if(((BM_valBootType_MP==4)||(BM_valBootType_MP==2))&&
		(BM_valRecData_MP[0] ==0x04)&&
		(BM_valRecData_MP[1] ==0x31)&&
		(BM_valRecData_MP[2] ==0x01)&&
		(BM_valRecData_MP[3] ==0xDD)&&
		(BM_valRecData_MP[4] ==0x01))
		{
			BM_valBootType_MP = 1;
		}
		CL_valRecDataLength_MP = 8;
		BM_numExitBoot_MP = 0;
		OBDII_CmdHandler_Rec(&BM_valRecData_MP[0]);
	}

}

uint8 BM_JudgeBootType()
{
	uint8 res;
	if((*(uint8 *)(BM_FROM_APP_ADDR_DFLASH_C) == 0x0A) && ((RESF&0x08)!=0)/*(*(volatile uint32 *)(BM_FROM_APP_ADDR_RAM_C) == 0x0101)*/)
	{
		FAD_FlashOperation();
		res = 2;
		return res;
	}
	if((*(uint32 *)(APP_ADDR_START_C) != 0xFFFFFFFF)&&(*(uint8 *)(BM_FROM_APP_ADDR_CFLASH_C) == 0x14))
	{
		res = 4;
	}
	else
	{
		BM_fgCheckSumWrong_MP = 1;
		res = 1;
		return res;
		
	}
	return res;
}

/*****************************************************************************
 * Outline				: Main program
 * Include				: 
 * Declaration			: 
 * Description			: 
 * Argument				: 
 * Return Value			: 
  * Calling Functions		: 
 *****************************************************************************/
void main(void)
{
	uint32 numCounter_j_LO = 0;
	uint8 valsendbuf_LO[8];
	uint8 numCounter_i_LO = 0;
    //Initialize clocks
    __DI();
    Clock_Init();
    
    Port_Init();
    CAN_Init(CAN0);
    CAN_Init(CAN1);
    BM_valBootType_MP = BM_JudgeBootType();
     MCAN();
     if(BM_valBootType_MP == 2)
     {
	valsendbuf_LO[0] = 0x06;
	valsendbuf_LO[1] = 0x50;
	valsendbuf_LO[2] = 0x02;
	valsendbuf_LO[3] = 0x00;
	valsendbuf_LO[4] = 0x32;
	valsendbuf_LO[5] = 0x01;
	valsendbuf_LO[6] = 0xF4;
	valsendbuf_LO[7] = 0xAA;
	OBDII_SendAck(valsendbuf_LO);//找初始化完成标志位
	CL_stDiagSeon_MP=2;
    }
//    __EI();
//    GTM_Init();
    for(;;) {
	BM_numExitBoot_MP++;
        MCAN();
	if((BM_valBootType_MP == 4)&&(BM_numExitBoot_MP>=0x2000))
	{
		((void(*)(void))APP_ADDR_START_C)();
	}
	if(BM_numExitBoot_MP>=0x110000)
	{
		if(BM_valBootType_MP == 2)
		{
			BM_numExitBoot_MP = 0;
			SWSRESA0 = 1;
		}	
		CL_stDiagSeon_MP = 1;
		CL_valSecLev_MP = 0;
	}
	if(CL_stFrameControl_MP == 1)
	{
		OBDII_SendControlFrame();
	}

	OBDII_Send_ResPonsCondata();
	if(BM_valRecSeverData_PHY_MP.CanBus_flgRecActive == 1)
	{	BM_numExitBoot_MP = 0;		
		BM_valRecSeverData_PHY_MP.CanBus_flgRecActive = 0;
		CL_fgDTCFunAddrVaild_MP = FALSE;
		BM_RecCAN_Frame_Handler(BM_valRecSeverData_PHY_MP);
	}
	if(BM_valRecSeverData_FUN_MP.CanBus_flgRecActive == 1)
	{

		BM_valRecSeverData_FUN_MP.CanBus_flgRecActive = 0;
		CL_fgDTCFunAddrVaild_MP = TRUE;
		BM_RecCAN_Frame_Handler(BM_valRecSeverData_FUN_MP);
	}
    }
}

//Init parameter before interrupt
void para_Init(void)
{
    float overload=1;
    float sppedabs;
    sppedabs = ABS(Speed_Ref);
    
    if(motortype==Booster){
        if(sppedabs>=0&&sppedabs<=250)
            overload= 3;
        else if(sppedabs>250&&sppedabs<=500)
            overload= 2;
        else 
            overload= 2;
    }
    
    pi_id.Kp   = ID_KP ;  
    pi_id.Ki   = ID_KI ;
    pi_id.Umax = ID_MAX;
    pi_id.Umin = ID_MIN;
	
    pi_iq.Kp   = IQ_KP ;   
    pi_iq.Ki   = IQ_KI ;  
    pi_iq.Umax = IQ_MAX;
    pi_iq.Umin = IQ_MIN;

    pi_spd.Kp   =SPEED_KP;
    pi_spd.Ki   =SPEED_KI;
    pi_spd.Umax =overload*SPEED_MAX;
    pi_spd.Umin =overload*SPEED_MIN;
    
    pi_fw.Kp   = FW_KP ;
    pi_fw.Ki   = FW_KI ;
    pi_fw.Umax = FW_MAX;
    pi_fw.Umin = FW_MIN;
    
    pi_pos.Kp   = POS_KP ;
    pi_pos.Ki   = POS_KI ;
    pi_pos.Umax = POS_MAX;
    pi_pos.Umin = POS_MIN;
    
    g_Control.prot.CurLevel1 = CURRENT_WARN_LEVEL1;
    g_Control.prot.CurLevel2 = CURRENT_WARN_LEVEL2;
    g_Control.prot.CurLevel3 = CURRENT_WARN_LEVEL3;
    
    g_Control.prot.VoltLevel1 = VOLTAGE_WARN_LEVEL1;
    g_Control.prot.VoltLevel2 = VOLTAGE_WARN_LEVEL2;
    
    g_Control.iRunState = 0;
    g_Control.FW.Flag   = 0;                  
    Aligment.Flag  = 1;  
    g_Control.count.SpeedLoopCount = 1;        
    g_Control.count.PosLoopCount   = 1;        
    g_Control.count.FWLoopCount    = 1;        
    g_Control.count.SatCount       = 1;
    
    g_Control.Aligmenta.Ali_angle = ANGLE_COMP;  
    g_Control.Aligmenta.Ali_count = 0;
    g_Control.TAS.TAS_angle_comp = TASCOMP;
    
    if(TestFlag==0){
	g_Control.Aligmenta.Ali_angle = ANGLE_COMP;
	g_Control.TAS.TAS_angle_comp = TASCOMP;
	FlashWrite();
    }else{
        FlashRead();
    }
}


/* Data_Flash_Read[16]
[0]:Ali_angle  [1]:Ali_flag  [2]:cur_kp     [3]:cur_ki
[4]:spd_kp     [5]:spd_ki    [6]:pos_kp     [7]:pos_ki
[8]:fw_kp      [9]:fw_ki     [10]:oi        [11]:ov
[12]:SAT       [13]:TAScopm  [14]:\         [15]:flashflag     
*/
void FlashWrite(void)
{
    Flash_Data[0] =(int)(g_Control.Aligmenta.Ali_angle*1000);
    Flash_Data[1] = flag.AliCheck;
    Flash_Data[2] = pi_iq.Kp*100;
    Flash_Data[3] = pi_iq.Ki*1000;
    Flash_Data[4] = pi_spd.Kp*100;
    Flash_Data[5] = pi_spd.Ki*1000;
    Flash_Data[6] = pi_pos.Kp*100;
    Flash_Data[7] = pi_pos.Ki*1000;
    Flash_Data[8] = pi_fw.Kp*100;
    Flash_Data[9] = pi_fw.Ki*1000;
    Flash_Data[10]= g_Control.prot.CurLevel1*10;  
    Flash_Data[11]= g_Control.prot.VoltLevel1*10;
    Flash_Data[12]= pi_spd.Umax*10;
    Flash_Data[13]= g_Control.TAS.TAS_angle_comp*10;
    Flash_Data[15]=1;  
    FAD_FlashOperation();
    Flag_CAN_flash = 0;
}

void FlashRead(void)
{
    R_FAD_DF_Read(0xFF2002C0, Data_Flash_Read ,16*4);
    if(Data_Flash_Read[15]==0)
        FlashWrite();
    R_FAD_DF_Read(0xFF2002C0, Data_Flash_Read ,16*4); 
    g_Control.Aligmenta.Ali_angle =(float)Data_Flash_Read[0]/1000;
    flag.AliCheck = Data_Flash_Read[1];
    pi_iq.Kp = (float)Data_Flash_Read[2]/100;
    pi_iq.Ki = (float)Data_Flash_Read[3]/1000;
    pi_spd.Kp= (float)Data_Flash_Read[4]/100;
    pi_spd.Ki= (float)Data_Flash_Read[5]/1000;
    pi_pos.Kp= (float)Data_Flash_Read[6]/100;
    pi_pos.Ki= (float)Data_Flash_Read[7]/1000;
    pi_fw.Kp = (float)Data_Flash_Read[8]/100;
    pi_fw.Ki = (float)Data_Flash_Read[9]/1000;
    g_Control.prot.CurLevel1 = (float)Data_Flash_Read[10]/10;
    g_Control.prot.CurLevel2 = 1.2*g_Control.prot.CurLevel1;
    g_Control.prot.CurLevel3 = 1.5*g_Control.prot.CurLevel1;
    g_Control.prot.VoltLevel1= (float)Data_Flash_Read[11]/10;
    g_Control.prot.VoltLevel2= 1.5*g_Control.prot.VoltLevel1;
    pi_spd.Umax =(float)Data_Flash_Read[12]/10;
    g_Control.TAS.TAS_angle_comp = (float)Data_Flash_Read[13]/10;
    pi_spd.Umin =-pi_spd.Umax;
}

void EPSsleep(void)
{
	if(sleepflag == 1)
	{
        sleepflag = 0;
        CANsleep();
        PMIC_standbyConfig();
	}
}

/*****************************************************************************
 * Outline				: Clock_Init program
 * Include				: 
 * Declaration			: 
 * Description			: 
 * Argument				: 
 * Return Value			: 
  * Calling Functions		: 
 *****************************************************************************/ 
void Clock_Init(void)
{	//Canceling Module standby mode
	MSR_LM3	=0x0000;		//Enable MCAN clock
	MSR_LM4	=0x0000;		//Enable FlexRay clock
//	MSR_LM5	=0x0000;		//Enable GTM clock
	MSR_LM6	=0x0000;		//Enable Ethernet clock
	MSR_LM7	=0x0000;		//Enable SENT clock
	MSR_LM8	=0x0000;		//Enable HS-USRT clock
	MSR_LM10=0x0000;		//Enable CSIH clock
	MSR_LM11=0x0000;		//Enable RLIN3 clock
	MSR_LM12=0x0000;		//Enable ADC clock
}


