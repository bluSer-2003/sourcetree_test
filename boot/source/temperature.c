//============================================================================
// PROJECT  :  RSENT0 Demo P1M-C (292pin & 156pin)
//============================================================================
//                           C O P Y R I G H T
//============================================================================
// Copyright (c) 2019 by Renesas Electronics Europe GmbH. All rights reserved.
// Arcadiastr.10
// D-40472 Duesseldorf
// Germany
//============================================================================
//
// Warranty Disclaimer :
// Because the Product(s) is licensed free of charge, there is no warranty of
// any kind whatsoever and expressly disclaimed and excluded by Renesas, either
// expressed or implied, including but not limited to those for non-
// infringement of intellectual property, merchantability and/or fitness for
// the particular purpose. Renesas shall not have any obligation to maintain,
// service or provide bug fixes for the supplied Product(s) and/or the
// Application.
//
// Each User is solely responsible for determining the appropriateness of
// using the Product(s) and assumes all risks associated with its exercise
// of rights under this Agreement, including, but not limited to the risks
// and costs of program errors, compliance with applicable laws, damage to
// or loss of data, programs or equipment, and unavailability or
// interruption of operations.
//
// Limitation of Liability :
// In no event shall Renesas be liable to the User for any incidental,
// consequential, indirect, or punitive damage (including but not limited to
// lost profits) regardless of whether such liability is based on breach of
// contract, tort, strict liability, breach of warranties, failure of
// essential purpose or otherwise and even if advised of the possibility of
// such damages. Renesas shall not be liable for any services or products provided
// by third party vendors, developers or consultants identified or referred
// to the User by Renesas in connection with the Product(s) and/or the
// Application.
//
//============================================================================
// Environment : Devices    : RH850/P1M-C (dr7f701373)
//               Debugger   : GHS Multi 6.1.6
//============================================================================
//
// GHS Multi example project for use with Piggyback board RH850/P1M-C V1 
// for 16 MHz MainOsc and Mainboard RH850-X2X-MB-T1-V1 in conjunction with an
// sensor board (applying the ELMOS chip 520.22 with SENT I/F) plugged to the 
// SENT0 I/F connector.
// This example shows the functions of the RSENT0 module. The program contains 
// a complete configuration of the RSENT0 module and the necessary interrupt 
// processing. The received new messages will be stored into a ring buffer 
// structure so that they can read out with a debugging tool.
//
// Error and status signalization is carried out by port group 6, since the 
// Piggyback board doesn't provide dedicated LEDs. These ports are related to 
// the (four) Signal-LEDs on the Mainboard.
// 
//
//============================================================================

//============================================================================
// Includes
//============================================================================

#include "r_adc.h"
#include "temperature.h"

//============================================================================
// Defines
//============================================================================
#define ALPHA        0.9      // 
#define Temp_Err_limit 10000   
#define ADC_TO_VOLTAGE (0.0008058608f) // 3.3/4095.0 预先计算好
#define R_FIXED 100.0f
#define V_SUPPLY 5.0f


//============================================================================
// Prototypes
//============================================================================
static inline float low_pass_filter(float last_adc_value, float new_adc_value);
static inline void temperature_calculate(float adc_value);
static inline void Temp_err_detect(float new_adc_value, float last_adc_value);
static inline void warning(float temperature);

//============================================================================
// Variables
//============================================================================
static float last_adc_value = 0;
static float new_adc_value = 0;
static uint16_t count = 0;
static uint32_t temp_limitout_flag = 0;
static uint32_t ADC_tempstay_count = 0;
static uint32_t Temp_Errflag = 0;
//Parameters
extern uint16_t Gu1ReadAdcValue[32];
float temperature = 0;
uint16_t High_temperature = 0;

// 低通滤波，直接内联
static inline float low_pass_filter(float last_adc_value, float new_adc_value) {
    return ALPHA * new_adc_value + (1.0f - ALPHA) * last_adc_value;
}

// 温度计算，参数直接传递，减少全局变量访问
static inline void temperature_calculate(float adc_value){
    float voltage = adc_value * ADC_TO_VOLTAGE; // 预先计算好常量
    float resistance;
    // 防止分母为0
    float v_diff = V_SUPPLY - voltage;
    if (v_diff < 0.001f) v_diff = 0.001f;
    resistance = R_FIXED * voltage / v_diff;

    //Only detect data within the range of 30-130 degrees.
    if((resistance >= 4.568) && (resistance <= 11)){     //The lower limit of temperature:25
        temperature = 0.4515*resistance*resistance - 10.0503*resistance + 81.9003;
    }else if(resistance >= 2.228){
        temperature = 1.3758*resistance*resistance - 19.0758*resistance + 104.0059;
    }else if(resistance >= 0.976){
        temperature = 7.8956*resistance*resistance - 49.2922*resistance + 139.6428;
    }else if(resistance >= 0.38){
        temperature = 37.1984*resistance*resistance - 115.4380*resistance + 176.7793;
    }else if(resistance > 11){
        temp_limitout_flag = 1;
    }else if(resistance < 0.38){
        temp_limitout_flag = 2;
    }
}

// 检查ADC值是否长时间不变
static inline void Temp_err_detect(float new_adc_value, float last_adc_value){
    uint32_t ADC_difference = (uint32_t)abs(new_adc_value - last_adc_value);
    if(ADC_difference == 0){
        if(++ADC_tempstay_count >= Temp_Err_limit){
            Temp_Errflag = 1;
        }
    }else{
        ADC_tempstay_count = 0;
        Temp_Errflag = 0;
    }
}

// 温度过高报警
static inline void warning(float temperature)
{
    if(temperature >= 95.0f && High_temperature == 0){
        if(++count >= 200){
            High_temperature = 1;
            count = 0;
        }
    }else{
        count = 0;
    }
}

// 主函数，采集温度并处理
float ADC_Temperature(void) {
    // 只在首次初始化时赋值
    if(last_adc_value == 0){
        new_adc_value = (float)Gu1ReadAdcValue[12];
        last_adc_value = new_adc_value; 
    }
    else{
        new_adc_value = low_pass_filter(last_adc_value, (float)Gu1ReadAdcValue[12]);
        // 检查ADC是否长时间不变
        Temp_err_detect(new_adc_value, last_adc_value);
        last_adc_value = new_adc_value; // 更新
    }
    // 计算温度
    temperature_calculate(new_adc_value);
    // 检查高温报警
    warning(temperature);
    return temperature;
}