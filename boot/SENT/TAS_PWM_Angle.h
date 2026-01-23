#ifndef TAS_PWM_Angle_H
#define TAS_PWM_Angle_H

#include <stdio.h>
#include <math.h>
#include "global.h"
#include "iodefine.h"


#define Resolution 65535
#define Duty_Limit_Low 0.125f
#define Duty_Limit_High 0.875f
#define Duty_Range 0.75f
#define down_offset 8192    //0.125*65535 = 8192
#define Range_resolution 49151  //0.75*65535 = 49151

#define WDP 37
#define WDS 5
#define WM 22

// 步车算法查找表 (索引0-37)
static const uint16_t WALKER_LUT[38] = {
    0, 22, 7, 29, 14, 36, 21, 6, 28, 13, 
    35, 20, 5, 27, 12, 34, 19, 4, 26, 11, 
    33, 18, 3, 25, 10, 32, 17, 2, 24, 9, 
    31, 16, 1, 23, 8, 30, 15, 0
};


/*****************************************************************************
 Global functions
 *****************************************************************************/
void Pre_Processing(float P_Duty,float S_Duty);
uint16_t wrsort_err_check(uint16_t wr_sort);
int32_t ptrack_err_check(int32_t ptrack);
void Credibility_Cal( int32_t wd_comp,uint32_t wr_index);
void Step_equation(float P_Duty,float S_Duty);


#endif