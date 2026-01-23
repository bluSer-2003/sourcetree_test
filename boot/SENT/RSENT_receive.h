#ifndef RSENT_RECEIVE_H
#define RSENT_RECEIVE_H

#include "iodefine.h"
#include "SENT_reg.h"
#include "global.h"


/*For SENT communication*/
//============================================================================
// Defines
//============================================================================
//Port allocation
#define RSENT0_PORT       P4
#define RSENT0_PORT_PCR   PCR4_7
#define RSENT2_PORT       P4
#define RSENT2_PORT_PCR   PCR4_13
#define RSENT5_PORT       P6
#define RSENT5_PORT_PCR   PCR6_3
#define RSENT0_PORT_PCR_VAL 0x0053
#define RSENT2_PORT_PCR_VAL 0x0052
#define RSENT5_PORT_PCR_VAL 0x0052

//Base address of different SENT channel 
#define RSENT0_base 0xFFCDC000
#define RSENT2_base 0xFFCDC200
#define RSENT5_base 0xFFCDC500

//Over-limit flag
#define FLAG_SENT1A_OUT    (1U << 0)  // bit0
#define FLAG_SENT2A_OUT    (1U << 1)  // bit1
#define FLAG_SENT1B_OUT    (1U << 2)  // bit2
#define FLAG_SENT2B_OUT    (1U << 3)  // bit3
#define FLAG_SENT3A_OUT    (1U << 4)  // bit4

// Communication Fault Flag Bit
#define COM_ERR_CH0   (1U << 0)   // No communication on Channel 0.
#define COM_ERR_CH2   (1U << 1)   // No communication on Channel 2.
#define COM_ERR_CH5   (1U << 2)   // No communication on Channel 5.

//Digital filter at the receive port
#define FCLA5CTL0 FCLA5.CTL0.UINT8
#define FCLA5CTL2 FCLA5.CTL2.UINT8
#define FCLA5CTL5 FCLA5.CTL5.UINT8
#define DNFA5CTL DNFA5.CTL.UINT8
#define DNFA5EN DNFA5.EN

static const uint32_t RSENT_BASE_ADDRESSES[3] = {
    RSENT0_base,        //RSENT0 base address
    RSENT2_base,        //RSENT2 base address
    RSENT5_base         //RSENT5 base address
};

// Define structure for SENT fast channel data
struct r_sentData_fast {       
 uint32_t RX0;                  // Entry 1 RX0 for message data(RSENTnFRXD)
 uint32_t SENT_A;               // First 12 bits data
 uint32_t SENT_B;               // Last 12 bits data
};

struct r_sentdata{
  uint32_t SENT1A;
  uint32_t SENT2A;
  uint32_t SENT3A;  //Data for angle
  uint32_t SENT1B;
  uint32_t SENT2B;  //Data for torque
};
//============================================================================
// Prototypes
//============================================================================
void init_clocks( void );
void RSENT_port_config( void );
void RSENT_init_config( uint32_t RSENTn_base,uint32_t TSPC_config,uint32_t BRP_config );
void com_start();
void com_end();
void no_com_detect();
void fast_data_receive();
void SENT_receive_init( void );
void SENT_receive_start( void );
void Range_check();


/*For PWM communication*/
//============================================================================
// Defines
//============================================================================

#define PWM0_PORT       P0
#define PWM1_PORT       P4
#define PWM2_PORT       P4
#define PWM3_PORT       P4
#define PWM0_PORT_PCR   PCR0_6
#define PWM1_PORT_PCR   PCR4_12
#define PWM2_PORT_PCR   PCR4_11
#define PWM3_PORT_PCR   PCR4_10
#define PWM0_PORT_PCR_VAL 0x0050
#define PWM1_PORT_PCR_VAL 0x0050
#define PWM2_PORT_PCR_VAL 0x0050
#define PWM3_PORT_PCR_VAL 0x0050

#define Freq_Low_T  1700
#define Freq_High_T 2300
#define Period_High_P  1176
#define Period_Low_P 870
#define Period_High_S  5618
#define Period_Low_S 4505
#define Duty_Low 0.125f
#define Duty_High 0.875f
#define TASErr_Limit 1500

#define GTM0_BASE 0xFFE00000

#define ANGLE_P_PERIOD 40.0f 
#define ANGLE_S_PERIOD 296.0f 
#define SENT_P1_RESOLUTION (ANGLE_P_PERIOD / 4093.0f) 
#define SENT_S_RESOLUTION (ANGLE_S_PERIOD / 4088.0f)  
//Over-limit flag
#define PWM_T1_OUT    (1U << 0)  // bit0
#define PWM_T2_OUT    (1U << 1)  // bit1
#define PWM_P_OUT    (1U << 2)  // bit2
#define PWM_S_OUT    (1U << 3)  // bit3

struct PWM_Signal{
  uint32_t PWM_Duty_Count;
  uint32_t PWM_Period_Count;
  float PWM_Period;
  float PWM_Duty;
};
struct ErrCount{
  uint32_t PeriodErr_Count;
  uint32_t DutyErr_Count;
  uint32_t Timeout_Count;
};

void GTM_init_clocks( void );
void PWM_Port_Init();
void GTM_TIM_init();
static inline void Get_Duty_Period(void);
static inline void Period_range_check(void);
static inline void Over_Time_Detect(uint32_t Over_Time_limit);
float AngleDiff_Limit(float New_Angle,float difference_limit);
void Get_PWM_Data_Init();
void Get_Angle_Data(void);

#endif