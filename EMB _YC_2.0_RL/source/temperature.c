//============================================================================
// Includes
//============================================================================
#include "r_adc.h"
#include "temperature.h"
#include "math.h"
#include "global.h"
#include "gtm.h"

//============================================================================
// Variables
//============================================================================
static float last_adc_value = 0;
static float new_adc_value = 0;
static uint16_t hightemp_count = 0;
static uint16_t lowtemp_count = 0;
uint32_t temp_limitout_flag = 0;     //1：电阻值低于给定区间    2：电阻值高于给定区间
static uint32_t ADC_tempstay_count = 0;
uint32_t Temp_Errflag = 0;
//Parameters
extern uint16_t Gu1ReadAdcValue[32];
float temperature = 0;
uint16_t High_temperature = 0;
uint16_t Low_temperature = 0;

// 低通滤波
static inline float low_pass_filter(float last_adc_value, float new_adc_value) {
    return TEMP_ALPHA * new_adc_value + (1.0f - TEMP_ALPHA) * last_adc_value;
}

// 温度计算，参数直接传递，减少全局变量访问
static inline void temperature_calculate(float adc_value){
    float voltage = adc_value * ADC_TO_VOLTAGE; // 预先计算好常量
    float resistance;
    
    // 防止分母为0
    float v_diff = V_SUPPLY - voltage;
    if (v_diff < 0.001f) v_diff = 0.001f;
    //通过分压值计算电阻
    resistance = R_FIXED * voltage / v_diff;

    // 越界处理
    if (resistance < TempR_Limit_Low) {
        resistance = TempR_Limit_Low;
        temp_limitout_flag = 1;         //高温预警
    } else if (resistance > TempR_Limit_High) {
        resistance = TempR_Limit_High;
        temp_limitout_flag = 2;         //低温预警
    }

    //Only detect data within the range of -40~130 degrees.
    if(resistance >= 53.65 && resistance <= 196){
        temperature = 0.0009*resistance*resistance - 0.3874*resistance + 2.7585;
    }else if(resistance >= 14.674){
        temperature = 0.012*resistance*resistance - 1.6409*resistance + 35.9216;
    }else if(resistance >= 4.161){
        temperature = 0.1863*resistance*resistance - 6.9913*resistance + 75.1228;
    }else if(resistance >= 1.452){
        temperature = 2.1111*resistance*resistance - 25.7196*resistance + 117.274;
    }else if(resistance >= 0.531){
        temperature = 21.96*resistance*resistance - 88.6744*resistance + 165.1871;
    }
}

// 检查ADC值是否长时间不变
static inline void Temp_err_detect(float new_adc_value, float last_adc_value){
    uint32_t ADC_difference = (uint32_t)ABS(new_adc_value - last_adc_value);
    if(ADC_difference == 0){
        if(++ADC_tempstay_count >= Temp_Stay_limit){
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
    if((temperature >= HIGH_TEMP_LIMIT) && (High_temperature == 0))
    {
        if(++hightemp_count >= Temp_OverLimit)
        {
            High_temperature = 1;
            hightemp_count = 0;
        }
    }else{
        hightemp_count = 0;
    }

    if((temperature <= LOW_TEMP_LIMIT) && (Low_temperature == 0))
    {
        if(++lowtemp_count >= Temp_OverLimit){
            Low_temperature = 1;
            lowtemp_count = 0;
        }else{
            lowtemp_count = 0;
        }
    }
}

static int temp_inited = 0;
// 主函数，采集温度并处理
float ADC_Temperature(void) {
    float adc_raw = (float)Gu1ReadAdcValue[12];

    if (!temp_inited) {
        new_adc_value = adc_raw;
        last_adc_value = new_adc_value;
        temp_inited   = 1;
    } else {
        new_adc_value = low_pass_filter(last_adc_value, adc_raw);
        // 检查ADC是否长时间不变(采用滤波前的AD数值)
        Temp_err_detect(adc_raw, last_adc_value);
        last_adc_value = new_adc_value;
    }
    // 计算温度
    temperature_calculate(new_adc_value);
    // 检查高温报警
    warning(temperature);
    return temperature;
}