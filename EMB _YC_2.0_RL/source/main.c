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
#include "CAN_SPI.h"
#include "PMIC.h"
#include "parameter.h"
#include "global_struct.h"
#include "fad_flash.h"
#include "para_update.h"
#include "Alignment.h"
#include "main.h"
//#include "smith_predictor.h"

/*****************************************************************************
 Imported global variables and functions (from other files)
 *****************************************************************************/
unsigned char flash_flg = 0;
unsigned char UDS_write_cnt = 0;

extern unsigned int SpeedLoopCount;
extern Object_t g_CANObject;
extern int fdtest;
extern CAN_Info g_Can_Atrib;

//extern int Flag_CAN_flash;
//SmithPredictor sp;
extern unsigned int FB_Order_Flag;
extern unsigned int FB_Complete_Flag;
extern unsigned int FB_lianxu_Flag;

extern unsigned int Given_Complete_Flag;
extern unsigned int Protect_Complete_Flag;
extern unsigned int Regulator_Complete_Flag;
extern unsigned int Flag_CAN_flash_Order;
extern unsigned int Flag_CAN_flash_Complete;
extern unsigned int Run_Complete_Flag;

//For CANFD control
extern unsigned int CANfd_runState;
extern unsigned int CANfd_runMode;

//For FAD Flash:
extern uint8_t Paraflash_Complete_Flag;
extern uint8_t Paraflash_Request_Flag;
extern uint8_t Controlflash_Complete_Flag;
extern uint8_t Controlflash_Request_Flag;

 
extern int canTimer;
/*****************************************************************************
 Exported global variables and functions (to be accessed by other files)
 *****************************************************************************/


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
    unsigned int i,j;
//    unsigned int Ali_flash = 8643;
//    unsigned int Ali_flag = 0;

    //Initialize clocks
    initGlobalVariables();
    Clock_Init();
    PM2&= _PORT_CLEAR_BIT10;
    PM2&= _PORT_CLEAR_BIT11;
	
    //Initialize ports
    Port_Init();
    PMIC_Config();
    A4911_Config();
    SENT_receive_init();
//    smith_predictor_init(&sp, CLAMPING_LAG, SAMPLE_PERIOD);
    GTM0.DTM24CHCTRL2 = 0x22222200;
    for(i=0;i<30000;i++)
	{
		for(j=0;j<100;j++);
	}
    
    //A4911_Config();
    R_ADC_Init();
    //GTM_PIC_ADC_Init();	
    CAN_Init();
    CAN_SPI_Init();
    CAN1145_ModeControl(CAN_normal);
    TMR_Init();
    //printf("Start\n");
    para_Init();       
    OBDII_CallBack_Init();
    OBD_stDtcReadFromEEPROM();
    FAD_DFlashWriteBootFLG(20);
    __EI();
    GTM_Init();
    //FAD_FlashOperation(Ali_flash,Ali_flag);
    for(;;) {
        //CAN1145_ModeControl(CAN_normal);
        MCAN();
	CAN_Tx_Fun();

        /********CANFD     *********/
        UpdateFbkPara();
        UpdateRegulatorParam();
        //UpdateProctectParam();
        UpdateGivenParam();
	UpdateParam_fromBCU();
	UpdateParam_toBCU();
        
	if(flash_flg == 1)
	{
		flash_flg = 0;
		for(UDS_write_cnt = 0 ; UDS_write_cnt <100 ; UDS_write_cnt++)
	    	{
	    		OBDII_RelatedDtc_WriteToEEprom(&UDS_write_cnt);
	    	}
	}
	if(flash_flg == 2)
	{
		flash_flg = 0;
		OBDII_RelatedDtc_ReadFromEEprom();
	}
	
	if((canTimer!=0)&&(canTimer%200 == 0))
	{
		OBDII_TSKUpper_Ex();
	}
        if(FB_Complete_Flag)
           // FB_reply();	
                
        if(FB_lianxu_Flag){
            FB_Order_Flag = 1;
            FB_Complete_Flag = 0;
        }	
        if(Given_Complete_Flag)
            Given_reply();
        if(Regulator_Complete_Flag)
            Regulator_reply();		
        //if(Protect_Complete_Flag)
            //Protect_reply();

        //if(Run_Order_Flag)
            //Run_reply();	
            

        if(g_Control.iRunState==4444 && Flag_CAN_flash_Order==1){  //only stop motor can op flash
            Paraflash_Complete_Flag = 0;
            Paraflash_Request_Flag = 1;
            Para_FlashWrite();
            Flag_CAN_flash_Order = 0;
            Flag_CAN_flash_Complete = 1;
            //g_CANflash.flag |=0x8000;
        }
        
        if(Flag_CAN_flash_Complete){
            Flag_CAN_flash_Order = 0;
            Flag_CAN_flash_Complete = 0;
            Flash_reply();	
        }
        
        if(CANfd_runState==1&&g_Control.iRunState==4444){  //??off=9
            g_Control.iRunState = 1;
            lsw = CANfd_runMode;
            CANfd_runState = 0;
        }
        if(CANfd_runState==9&&g_Control.iRunState==100){   //??off=9
            g_Control.iRunState = 404;
            CANfd_runState = 0;
        }
        
        switch(g_Control.iRunState){
            case 0:   
            break;

            case 1:   
                On_Mos();
                g_Control.iRunState = 100;
            break;
            
            case 100: 
            break;

            case 404: 
                De_Mos();
                g_Control.iRunState = 4444;
            break;

            case 4444: 
            break;

            default:
                g_Control.iRunState = 404;
            break;
        }
    }
}


void para_Init(void)
{
    //float overload=1;
    //float sppedabs = 0;
    //sppedabs = ABS(Speed_Ref);
    
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
    pi_spd.Umax =SPEED_MAX;
    pi_spd.Umin =SPEED_MIN;
    
    pi_fw.Kp   = FW_KP ;
    pi_fw.Ki   = FW_KI ;
    pi_fw.Umax = FW_MAX;
    pi_fw.Umin = FW_MIN;
    
    pi_pos.Kp   = POS_KP ;
    pi_pos.Ki   = POS_KI ;
    pi_pos.Umax = POS_MAX;
    pi_pos.Umin = POS_MIN;
    
    pi_force.Kp   = FORCE_KP ;
    pi_force.Ki   = FORCE_KI ;
    pi_force.Umax = FORCE_MAX;
    pi_force.Umin = FORCE_MIN;
    
    pi_preforce.Kp   = FORCE_KP ;
    pi_preforce.Ki   = FORCE_KI ;
    pi_preforce.Umax = FORCE_MAX;
    pi_preforce.Umin = FORCE_MIN;
    
    g_Control.prot.CurLevel1 = CURRENT_WARN_LEVEL1;
    g_Control.prot.CurLevel2 = CURRENT_WARN_LEVEL2;
    g_Control.prot.CurLevel3 = CURRENT_WARN_LEVEL3;
    
    g_Control.prot.VoltLevel1 = VOLTAGE_WARN_LEVEL1;
    g_Control.prot.VoltLevel2 = VOLTAGE_WARN_LEVEL2;
    
    g_Control.iRunState = 0;
    g_Control.FW.Flag   = 0;                 
    Aligment.Flag  =1;  
    g_Control.count.SpeedLoopCount = 1;      
    g_Control.count.PosLoopCount   = 1;   
    g_Control.count.ForceLoopCount = 1; 
    g_Control.count.FWLoopCount    = 1;        
    g_Control.count.SatCount       = 1;
    
    g_Control.Aligmenta.Ali_angle = ANGLE_COMP;  
    g_Control.Aligmenta.Ali_count = 0;

    
    if(TestFlag==0){
	    g_Control.Aligmenta.Ali_angle = ANGLE_COMP;
	    Paraflash_Complete_Flag = 0;
        Paraflash_Request_Flag = 1;
        Para_FlashWrite();
    }else{
        Para_FlashRead();
    }
}

void Clock_Init(void)
{
	//Canceling Module standby mode
	MSR_LM3	=0x0000;		//Enable MCAN clock
	MSR_LM4	=0x0000;		//Enable FlexRay clock
	MSR_LM5	=0x0000;		//Enable GTM clock
	MSR_LM6	=0x0000;		//Enable Ethernet clock
	MSR_LM7	=0x0000;		//Enable SENT clock
	MSR_LM8	=0x0000;		//Enable HS-USRT clock
	MSR_LM10=0x0000;		//Enable CSIH clock
	MSR_LM11=0x0000;		//Enable RLIN3 clock
	MSR_LM12=0x0000;		//Enable ADC clock
}


