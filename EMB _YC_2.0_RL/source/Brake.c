#include <stdio.h>
#include <math.h>
#include "gtm.h"
#include "global.h"
#include "global_struct.h"
#include "parameter.h"
#include "Gap_Control.h"
#include "Protection.h"
#include "tmr_macrodriver.h"
#include "Brake.h"

//??????????
unsigned int break_error_code = 0;

//????????
static float targetPos1 = 0.0f;      // ????
static uint16_t magnet_counter = 0;          // ?????(???)

//???????
extern int contectFlag;	//?????
extern int reverseFlag; //?????

//???????
extern uint8_t Controlflash_Complete_Flag;
extern uint8_t Controlflash_Request_Flag;

// ????
void MagnetTask(void);
inline void Enforce_Park(void);
inline void Off_Park(void);
inline void On_Park(void);


void Magnet(int jzt)
{
    
//    GTM0.ATOM1AGCOUTENCTRL = 0x00000000;
	PM3 &= _PORT_CLEAR_BIT7;  //JZ_EN
	P3 |= _PORT_SET_BIT7;

	PMC3 |= _PORT_SET_BIT9;		//JZ_PH
	PFCE3 &= _PORT_CLEAR_BIT9;
	PFC3 &= _PORT_CLEAR_BIT9;
    PM3 &= _PORT_CLEAR_BIT9;
	
    GTM0.ATOM10CTRL = (mode_somp)+(sl_hi)+(trig_ccu0)+(cmu_clk3);
    GTM0.ATOM10CM0 = T0; // period = 1000*62,5ns = 16kHz
    GTM0.ATOM10CM1 = T0*(100-jzt)*0.01; // duty cycle = 500*62,5ns
    GTM0.ATOM10CN0 = 0x00000000; // initial delay = 0
    GTM0.ATOM10SR0 = T0;
    GTM0.ATOM10SR1 = T0*(100-jzt)*0.01;
    
    GTM0.ATOM1AGCGLBCTRL = 0x00AA0000;   // update enable of ch 0
    GTM0.ATOM1AGCOUTENCTRL = 0x0000AAAA; // enable output 0 to 7 (1 to 6)
    GTM0.ATOM1AGCENDISCTRL = 0x0000AAAA; // anable all channel
    GTM0.ATOM1AGCFUPDCTRL  = 0xAAAAAAAA; // force update on ch 0 to 7
    GTM0.ATOM1AGCGLBCTRL   = 0x00000001; // host trigger for start of ATOM0

    GTM0.ATOM1AGCFUPDCTRL  = 0x55555555; // force update on ch 1 to 7
    
}

void Magnet_Off(void) {
    P3 &= _PORT_CLEAR_BIT7;
    // ??????? PWM ??
}


// ======================================================================
// MagnetTask: ?????/?????????(???????)
// ======================================================================
void MagnetTask(void)
{
    if (!Brake_Control.busy_flag) {
        if (Brake_Control.Magnet_Control == 1 && Brake_Control.magnet_done_flag == 0 && (contectFlag == 1||contectFlag == 2))
            Brake_Control.park_mode = 1; // ????
        else if (Brake_Control.Magnet_Control == 0 && Brake_Control.magnet_done_flag == 1 && (Brake_Control.brake_error_code &0x01) == 0)
            Brake_Control.park_mode = 2; // ?????
        else if (Brake_Control.Magnet_Control == 3 && Brake_Control.magnet_done_flag == 1 )
            Brake_Control.park_mode = 3; // ???????

        if (Brake_Control.park_mode) {
            Brake_Control.Park.park_step = 0;
            Brake_Control.UnPark.unpark_step = 0;
            magnet_counter = 0;
            Brake_Control.busy_flag = 1; // ????
        }
    }

    //??????/???
    if (Brake_Control.busy_flag) {
        if (Brake_Control.park_mode == 1) 
            On_Park();
        else if (Brake_Control.park_mode == 2)
            Off_Park();
        else if (Brake_Control.park_mode == 3)
            Enforce_Park();
    }
}

//??????
//????????????????
void On_Park(){
 //   static unsigned int park_count = 0;
    switch (Brake_Control.Park.park_step) {
        case 0: // ??0: ??????
			targetPos1 = PARK_SCALE * 2.0f * PI * POSITION_PU;
			g_Control.PosRef = targetPos1;
			Brake_Control.Park.park_step = 1;
		break;

        case 1: // ??1: ???????/????
			if (ABS(g_Control.PosRef - g_Control.PosFbk) < 0.1f  || magnet_counter++ >= 20000) {
				Brake_Control.Park.park_step = 2;
				magnet_counter = 0;	
			}					
		break;

        case 2: // ??2: ??????????
			if (++magnet_counter >= 200){     //10ms
				Magnet(80);              // ????? 
				Brake_Control.Park.park_step = 3;
				magnet_counter = 0;
			}
        break;

        case 3: // ??3: ????,????
			if (++magnet_counter >= 8000) {
				Magnet_Off();
				Brake_Control.Magnet_Control = 2;  
				Brake_Control.magnet_done_flag = 1;
				magnet_counter =0;
				Controlflash_Request_Flag = 1;
				Controlflash_Complete_Flag = 0;
				De_Mos();                       // ???????
				Brake_Control.Park.park_step = 0;
				Brake_Control.busy_flag = 0;                   // ??
				Brake_Control.park_mode = 0;
			}
        break;

//        case 4: // ??4: ?????? (?200ms),?????????
//            g_Control.PosRef = targetPos1;
//            if (++magnet_counter >= 8000) {
//                Magnet_Off();
//		    }
//            targetPos1 = (PARK_SCALE-HALF_PITCH*2) * 2.0f * PI * POSITION_PU;
//            g_Control.PosRef = targetPos1;
//            Brake_Control.Park.park_step = 5;
//		break;
        
//        case 5: // ??5: ????10ms,????????????
//        //????1600rpm,????????10ms?????1.67rad(0.267r)
//            //????
//		    if (ABS(g_Control.PosRef - g_Control.PosFbk) < HALF_PITCH && (magnet_jiajin_count++) >=200){
//                magnet_jiajin_count =0;
//                Brake_Control.Magnet_Control = 2;   // ?????????
//                Brake_Control.magnet_state = 0;               // ???????
//                Brake_Control.magnet_done_flag = 1;           // ???????
//                Controlflash_Request_Flag = 1;              // ????,???????
//                Controlflash_Complete_Flag = 0;
//                De_Mos();                       // ???????
//                Brake_Control.Park.park_step = 0;                  // ????
//                Brake_Control.busy_flag = 0;                  // ??
//                Brake_Control.park_mode = 0;                  //??????
//                park_count = 0;                 //??????
//            }else if(park_count <= PARK_COUNT_LIMIT){                              //?10ms????????????
//                magnet_jiajin_count =0;
//                Brake_Control.Magnet_Control = 1;   // ??????
//                Brake_Control.magnet_state = 0;               // ???????
//                Brake_Control.Park.park_step = 0;                  // ????
//                Brake_Control.busy_flag = 1;                  // ????
//                Brake_Control.park_mode = 0;                  // ?????
//                park_count++;                   //??????
//            }else{
//                break_error_code |= (0x0001);   //????
//            }
//        break;

    }

}

void Off_Park(void){
    static uint8_t unpark_count = 0;        // ???????????(?? 1 ?)
    switch (Brake_Control.UnPark.unpark_step) {
        case 0: // ??0: ??????
            targetPos1 = g_Control.PosFbk;
	        g_Control.PosRef = targetPos1;
	        Brake_Control.UnPark.unpark_step = 1;
            magnet_counter = 0;
        break;

        case 1: // ??1:?????
			g_Control.PosRef = targetPos1;
			if (magnet_counter++ >= 2000) {
				Magnet(10);
				magnet_counter = 0;
				Brake_Control.UnPark.unpark_step = 2;
			}
        break;

        case 2: // ??2:??
			g_Control.PosRef = targetPos1;
			if (magnet_counter++ >= 2000){
				targetPos1 = g_Control.PosFbk + (HALF_PITCH * 2.0f * PI * POSITION_PU);
				Brake_Control.UnPark.unpark_step = 3;
				magnet_counter=0;
			}
        break;

        case 3: // ??3: ????????????
			g_Control.PosRef = targetPos1;
			if (magnet_counter++ >= 8000) {
				magnet_counter = 0;
				Magnet_Off();
				Brake_Control.UnPark.unpark_step = 4;
				targetPos1 = g_Control.PosFbk;  //????????
			}
        break;
		    
		case 4: // ??4:????????
			g_Control.PosRef = targetPos1;
			if(magnet_counter++ >= 4000){
				Magnet(10);
				magnet_counter = 0;
				Brake_Control.UnPark.unpark_step = 5;
			}
        break; 
        
	    case 5: //??5:???????????
			g_Control.PosRef = targetPos1;
			if (magnet_counter++ >= 8000) {
				Magnet_Off();
				magnet_counter = 0;
//				if(contectFlag ==1 && reverseFlag ==1)
					targetPos1 = Retreat_SCALE * 2.0f * PI * POSITION_PU;
//				else
//					targetPos1 = g_Control.PosFbk + (0.05 * 2.0f * PI * POSITION_PU);
				Brake_Control.UnPark.unpark_step = 6;
			}
				break;

	    case 6: //??6:?????????
			g_Control.PosRef = targetPos1;
			magnet_counter++;
			//????????
			if (ABS(g_Control.PosRef - g_Control.PosFbk) < 0.1f ) {
				Controlflash_Request_Flag = 1;						//Flash????????1
				Controlflash_Complete_Flag = 0;						//Flash?????????
				Brake_Control.magnet_done_flag = 0;		//?????????
				Brake_Control.UnPark.unpark_step = 0;	//?????
				g_Control.iRunState = 4444;				//????????
				magnet_counter = 0;
				Brake_Control.brake_error_code = 0;		//??????????
				Brake_Control.park_mode = 0;
				Brake_Control.busy_flag = 0;
				unpark_count = 0;
			}
			//???????????
			if(magnet_counter>20000){
				// ???????????
			    if (unpark_count <= Unpark_Count_limit){   // ????????????
					unpark_count ++;						
					Brake_Control.UnPark.unpark_step = 0;  //??????????
					//Brake_Control.park_mode = 2;
					//Brake_Control.busy_flag = 0;
					magnet_counter = 0;
					Brake_Control.Magnet_Control = 0; 	   // ???????
					Brake_Control.magnet_done_flag = 1;    // ??????
				}else{
					Brake_Control.magnet_done_flag = 1;
					Brake_Control.UnPark.unpark_step = 0;
					Brake_Control.brake_error_code |= 0x01;//?????
					magnet_counter = 0;
					Brake_Control.park_mode = 0;
					Brake_Control.busy_flag = 0;
					De_Mos();
				}  					
			}
		break;
    }
}

void Enforce_Park(){
	targetPos1=  EnForce_Brake_Scale*2.0f * PI * POSITION_PU;
	g_Control.PosRef = targetPos1;
	Magnet(0);
	magnet_counter++;
	if(magnet_counter>8000){
		Magnet_Off();
		De_Mos();
		magnet_counter = 0;
		Brake_Control.brake_error_code &= 0x00;
		Brake_Control.busy_flag = 0;
		Brake_Control.UnPark.unpark_step = 0;
		Brake_Control.park_mode = 0;
    }
}
