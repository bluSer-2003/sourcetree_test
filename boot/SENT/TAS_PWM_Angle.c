#include <stdio.h>
#include <math.h>
#include "global.h"
#include "iodefine.h"
#include "TAS_PWM_Angle.h" 


//For verification
float Vres = 0; //可信度
int8_t Vres_FD = 0; //Vres_FD=1 数据不可信

float angle_out = 0;    //输出角度
static int32_t ptrack_old = 0;     //用于校正
static uint16_t wr_sort_old = 0;   //用于校正
	
int32_t ptrack = 0;
int32_t mean_OS2IS = 0;
int32_t ch3 = 0;
uint32_t wr_sort = 0;

void Pre_Processing(float P_Duty,float S_Duty)
{
    uint32_t PWM_P_pc = 0;    
    uint32_t PWM_S_pc = 0;   

    //Convert the duty cycle to a numerical value（0-65535)
    PWM_P_pc = P_Duty * Resolution  ;
    PWM_S_pc = S_Duty * Resolution  ;

    //Preprocessing primary signal
    mean_OS2IS = PWM_P_pc - down_offset;    //12.5%*65535 = 8192
    
    if(mean_OS2IS < 0){
        mean_OS2IS = mean_OS2IS + Range_resolution;   
    }else if(mean_OS2IS > Range_resolution){
        mean_OS2IS = mean_OS2IS - Range_resolution;
    }
    mean_OS2IS = mean_OS2IS * 341 / 1024;   //range:0-16368 

    //Preprocessing Sencondary Signal
    ch3 = PWM_S_pc - down_offset;       //range:0-49152
    if(ch3 < 0){
        ch3 = ch3 + Range_resolution;
    }else if(ch3 > Range_resolution){
        ch3 = ch3 - Range_resolution;
    }
    ch3 = ch3 * 20187 / 8192; 
}

uint16_t wrsort_err_check(uint16_t wr_sort){
    uint16_t count_diff = 0;
    
    count_diff = abs(wr_sort - wr_sort_old);    //????

    //if(count_diff > 2 && wr_sort_err <= 20){
    if((count_diff == 15) || (count_diff == 22) ){
        wr_sort = wr_sort_old;
        //wr_sort_err++;
    }
    wr_sort_old = wr_sort;

    return wr_sort;
}

int32_t ptrack_err_check(int32_t ptrack){
    uint32_t count_diff = 0;
    static uint16_t ptrack_err = 0;

    count_diff = abs(ptrack - ptrack_old);    //????

    if(count_diff > 40 && ptrack_err <= 20){
        ptrack = ptrack_old;
        ptrack_err++;
    }
    else {
        ptrack_err = 0;
        ptrack_old = ptrack;
    }

    return ptrack;
}

void Credibility_Cal( int32_t wd_comp,uint32_t wr_index){

    uint32_t wd_nominal = 0;
    uint32_t wd_real = 0;
    uint32_t wdiff_nom = 0;

    wd_nominal = wr_index * 32736 + 16368;
    wd_real = wd_comp * 10;
    if(wd_nominal > wd_real){
        wdiff_nom = wd_nominal - wd_real;
    }else{
        wdiff_nom = wd_real - wd_nominal;
    }

    if(wdiff_nom > 16368){
        wdiff_nom = 16368;
    }
    Vres = 16368 - wdiff_nom;
    Vres = (Vres/4092/4)*100;	//???

    if(wdiff_nom > 12276){
        Vres_FD = 1;      //Vres<25%,????????
    }else{
        Vres_FD = 0;
    }
}

void Step_equation(float P_Duty,float S_Duty)
{

    int32_t wd = 0;         //????
    int32_t wd_comp = 0;
    uint32_t wr_index = 0;
    int32_t angle_norm = 0;
    int32_t strack = 0;
    //For test
    //uint16_t sort_diff = 0;
    //int32_t ptrack_diff = 0;
    //static uint8_t operation_times_1 = 0;
    //static uint8_t operation_times_2 = 0;
    //static int32_t ptrack_old = 0;
    //static int32_t angle_norm_old = 0;
    
    Pre_Processing(P_Duty,S_Duty);
    
    ptrack = mean_OS2IS;            //range:0-16368
    strack = ch3;    //range:0-121122
    
    wd = ptrack - strack ;      //????,??????
    if(wd < 0){
        wd_comp = wd + 121122;
    }else{
        wd_comp = wd;
    }
    wd_comp += 1637;        //?????????? range:1637-122758

    wr_index = (wd_comp * 5125)/ 4096 / 4096;  //???????0-37
    wr_sort = WALKER_LUT[wr_index];
    wr_sort = wrsort_err_check(wr_sort);
    
    angle_norm = ptrack + wr_sort * 16368;      //IS-angle
    angle_out = (angle_norm - 302828) / 409.2f;
	     
    Credibility_Cal(wd_comp,wr_index);
    

}