#ifndef __TEMPERATURE_H__
#define __TEMPERATURE_H__

#include "global.h"
extern uint16_t Gu1ReadAdcValue[32];

static inline float low_pass_filter(float last_adc_value, float new_adc_value);
static inline void temperature_calculate(float adc_value);
static inline void Temp_err_detect(float new_adc_value, float last_adc_value);
static inline void warning(float temperature);
float ADC_Temperature(void) ;

#endif
