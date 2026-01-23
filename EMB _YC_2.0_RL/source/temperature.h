#ifndef __TEMPERATURE_H__
#define __TEMPERATURE_H__


#define Temp_OverLimit    200  
#define LOW_TEMP_LIMIT    -40
#define HIGH_TEMP_LIMIT   95
#define TempR_Limit_Low   0.531
#define TempR_Limit_High  196
#define TEMP_ALPHA        0.9      
#define Temp_Stay_limit   10000   
#define ADC_TO_VOLTAGE (0.0008058608f)  // 3.3/4095.0 ?????
#define R_FIXED        110.0f           //????
#define V_SUPPLY       5.0f             //??

static inline float low_pass_filter(float last_adc_value, float new_adc_value);
static inline void Temp_search(float adc_value);
static inline void Temp_err_detect(float new_adc_value, float last_adc_value);
static inline void warning(float temperature);
float ADC_Temperature(void);


#endif
