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

#include "SENT_reg.h"
#include "global.h"
#include "iodefine.h"
#include "RSENT_receive.h"
#include "gtm.h"
#include "TAS_PWM_Angle.h"

//============================================================================
// Variables
//============================================================================
 struct r_sentData_fast RSENT_data_fast[3];     // Store Data For SENT0/2/5
 extern struct r_sentdata SENT_DATA = {0};      // Store the checked and processed data
 volatile uint32_t fast_buffer = 0x00;          // Variable "fast_buffer" for incrementation
 volatile uint32_t timeout_cnt[3] = {0, 0, 0};  // Variable for timeout counter with RSENT0/2/5
 volatile uint32_t com_err_flags = 0;           // Flag for commnication status
 const uint32_t TIMEOUT_THRESHOLD = 1000;       //Threshold for no-communication(T=THRESHOLD/20k)
 extern volatile uint32_t out_range = 0x00000;  //Flag for out-range data                                
//============================================================================
// Clock Initiate
//============================================================================

void init_clocks( void )
{
  MSR_LM7	=0x0000;		//Enable SENT clock
}

//============================================================================
// RSENT Port Configuration
//============================================================================

void RSENT_port_config( void ) {

  // Set RSENT port pin
  RSENT0_PORT_PCR = RSENT0_PORT_PCR_VAL;  
  RSENT2_PORT_PCR = RSENT2_PORT_PCR_VAL;    
  RSENT5_PORT_PCR = RSENT5_PORT_PCR_VAL;  

  //diag filter register
  FCLA5CTL0 = 0x00;       //SENT0 edge detection
  FCLA5CTL2 = 0x00;       //SENT2 edge detection
  FCLA5CTL5 = 0x00;       //SENT5 edge detection
  DNFA5CTL  = 0x00;       // Enable digital filter register for SENT0RX
  DNFA5EN  |= 0x25;
  
}

//============================================================================
// RSENT0 Timestamp configuration
//============================================================================

void RSENT_init_config( uint32_t RSENTn_base,uint32_t TSPC_config,uint32_t BRP_config ) {

  //operation mode change
  // Set RSENTn Module into configuration mode(RSENTnMDC)
  (*(volatile uint32_t*)(RSENTn_base + 0X001C)) = 0x01;      
  // Check if RSENTn is in configuration mode(RSENTnMST)    
  while((*(volatile uint32_t*)(RSENTn_base + 0X0024)) != 0x01 );

  //Timestamp Clock configuration(RSENTnTSPC)
  // Set RSENTn Timestamp to 0.5/1us for the expected 1.5/3us and Master mode
  (*(volatile uint32_t*)(RSENTn_base + 0X0000)) = TSPC_config; 

  // Write initial value "0" to the timestamp counter(RSENTnTSC)
  (*(volatile uint32_t*)(RSENTn_base + 0X0004)) = 0x00;         

  //communication baud rate prescaler register configuration(RSENTnBRP)
  // Configure communication settings for 16MHz, 3us and 1.5us ticktime
  (*(volatile uint32_t*)(RSENTn_base + 0X0014)) = BRP_config;   

  ///communication configuration(RSENTnCC)
  // RSENT Configuration with pause pulse for variable message length and enabled
  // Enhanced Serial Message reception,fast channel CRC check enable
  // 6 data nibbles and disable SPC mode
  // SAE J2716 2010 format
  (*(volatile uint32_t*)(RSENTn_base + 0X0010)) = 0x001A; 

  // Configure Interrupts(RSENTnIDE) disable Fast Channel Receive Interrupt
  (*(volatile uint32_t*)(RSENTn_base + 0X0018)) = 0x07FE; 
}

//============================================================================
// RSENT2 communication start
//============================================================================

void com_start(){

  uint8_t ch = 0; //Channel number

  for(ch=0;ch<3;ch++){

    // Set RSENT Module into operation active mode(RSENTnMDC)
    (*(volatile uint32_t*)(RSENT_BASE_ADDRESSES[ch]+0x001C)) = 0x05;  

    // Check if RSENT is in operation active mode(RSENTnMST)
   while((*(volatile uint32_t*)(RSENT_BASE_ADDRESSES[ch]+0x0024)) != 0x05); 

  }
}

//============================================================================
// RSENT communication end
//============================================================================

void com_end(uint32_t RSENTn_base){

  uint8_t ch = 0;  //Channel number

  for(ch=0;ch<3;ch++){

    // Set RSENT Module into operation idle mode(RSENTnMDC)
    (*(volatile uint32_t*)(RSENT_BASE_ADDRESSES[ch]+0x001C)) = 0x03;   

  }
}

//============================================================================
// detect for fast channel receive interrupt status
//============================================================================

void no_com_detect(){	
  uint8_t ch = 0;       //Channel number
  uint32_t base = 0;    //Base address of different SENT channel
  uint32_t cs = 0;      //Status for communication status 
  uint32_t flag = 0;    //Error bit of the corresponding channel

  const uint32_t flag_bits[3] = { COM_ERR_CH0, COM_ERR_CH2, COM_ERR_CH5 };
  
  for (ch = 0; ch < 3; ++ch) {
    base = RSENT_BASE_ADDRESSES[ch];
    cs   = (*(volatile uint32_t*)(base + 0x0028)) & 0x01;  //RSENTnCS
    flag = flag_bits[ch];  

    if (cs == 0) {
      //No-communication status
      if (timeout_cnt[ch] >= TIMEOUT_THRESHOLD) {
          com_err_flags |= flag;       // Set communication error flag
          timeout_cnt[ch] = 0;         // Reset time-out counter
      } else {
          timeout_cnt[ch]++;
      }
    } else {
      // Clear flag after receiving new SENT data
      com_err_flags &= ~flag;
      timeout_cnt[ch] = 0;
    }
  }
}

//============================================================================
// Deal with data from fast channel
//============================================================================
void fast_data_receive(){
  uint16_t low4 = 0;
  uint16_t mid4 = 0;
  uint16_t high4 = 0;
  uint8_t ch = 0;

  for(ch = 0;ch < 3; ch++){
    // Fast Channel Receive  detected(RSENTnCS)
    if (((*(volatile uint32_t*)(RSENT_BASE_ADDRESSES[ch]+0x0028)) & 0x01 ) == 1 ){   

      // -> FAST CHANNEL MESSAGE HANDLING <-
      // Perform sensor value calculation from fast message content()
      // Write value of RSENTFRXD into "RX0"
      RSENT_data_fast[ch].RX0 = (*(volatile uint32_t*)(RSENT_BASE_ADDRESSES[ch]+0x0044)); 
      // Get first 3 data nibbles
      RSENT_data_fast[ch].SENT_A = (( RSENT_data_fast[ch].RX0 >> 12) & 0x0fff );  
       // Get last 3  data nibbles  
      RSENT_data_fast[ch].SENT_B = ( RSENT_data_fast[ch].RX0 & 0x0fff ); 
       
      //Swap the high four bits and the low four bits for SENT dataB
      high4 = (RSENT_data_fast[ch].SENT_B >> 8) & 0x0f;
      mid4 = (RSENT_data_fast[ch].SENT_B >>4) & 0x0f ;
      low4 = (RSENT_data_fast[ch].SENT_B) & 0x0f ;
      RSENT_data_fast[ch].SENT_B  = (low4 << 8) | (mid4 << 4) | high4;
    }

  }
  

}

//============================================================================
// Check the data range
//============================================================================
 void Range_check(){

  uint32_t A_lowlimit = 1;
  uint32_t A_upperlimit = 4093;
  uint32_t B_lowlimit = 8;
  uint32_t B_upperlimit = 4087;
  uint32_t ANG_lowlimit = 1;
  uint32_t ANG_upperlimit = 4088;
  uint32_t out_range = 0x00000;

  //Check SENT Data 1A,2A
  if(SENT_DATA.SENT1A < A_lowlimit || SENT_DATA.SENT1A  > A_upperlimit)
      out_range |= FLAG_SENT1A_OUT;
  else if((SENT_DATA.SENT1A >= A_lowlimit) && (SENT_DATA.SENT1A <= A_upperlimit))
      out_range &= ~FLAG_SENT1A_OUT;
  if(SENT_DATA.SENT2A < A_lowlimit || SENT_DATA.SENT2A  > A_upperlimit)
      out_range |= FLAG_SENT2A_OUT;
  else if((SENT_DATA.SENT2A >= A_lowlimit) && (SENT_DATA.SENT2A  <= A_upperlimit))
      out_range &= ~FLAG_SENT2A_OUT;

  //Check SENT Data 1B,2B
  if(SENT_DATA.SENT1B  < B_lowlimit || SENT_DATA.SENT1B > B_upperlimit)
    out_range |= FLAG_SENT1B_OUT;
  else if((SENT_DATA.SENT1B >= B_lowlimit) &&(SENT_DATA.SENT1B <= B_upperlimit))
    out_range &= ~FLAG_SENT1B_OUT;
  if(SENT_DATA.SENT2B  < B_lowlimit || SENT_DATA.SENT2B > B_upperlimit)
    out_range |= FLAG_SENT2B_OUT;
  else if((SENT_DATA.SENT2B >= B_lowlimit) && (SENT_DATA.SENT2B <= B_upperlimit))
    out_range &= ~FLAG_SENT2B_OUT;

  //Check SENT Data 3A
  if(SENT_DATA.SENT3A  < ANG_lowlimit || SENT_DATA.SENT3A > ANG_upperlimit)
    out_range |= FLAG_SENT3A_OUT;
  else if((SENT_DATA.SENT3A >= ANG_lowlimit) && (SENT_DATA.SENT3A <= ANG_upperlimit))
    out_range &= ~FLAG_SENT3A_OUT;

}

//============================================================================
// Main function
//============================================================================

void SENT_receive_init( void ) {

  init_clocks();                     // Initiate clocks
    
  RSENT_port_config();              // Call port configuration for SENT interface
  // Call RSENT0 timestamp configuration   
  RSENT_init_config(RSENT0_base,0x0309,0x05000400);     //0.5us timestamp,1.5us tick
  RSENT_init_config(RSENT2_base,0x0309,0x05000400);
  RSENT_init_config(RSENT5_base,0x0f04,0x00020400);     //1us timestamp,3us tick

  __EI();                            // Enable global interrupt processing 

  //start communication and deal with data from fast and slow channel
  com_start();
} 

void SENT_receive_start( void ){	
 
  //Get and processing data
  fast_data_receive();

  SENT_DATA.SENT1A = RSENT_data_fast[0].SENT_A;
  SENT_DATA.SENT1B = RSENT_data_fast[0].SENT_B;
  SENT_DATA.SENT2A = RSENT_data_fast[1].SENT_A;
  SENT_DATA.SENT2B = RSENT_data_fast[1].SENT_B;
  SENT_DATA.SENT3A = RSENT_data_fast[2].SENT_A;

  Range_check();

  //detect status of communication
  no_com_detect();

}


uint32_t err_flag[4] = {PWM_T1_OUT, PWM_T2_OUT, PWM_P_OUT, PWM_S_OUT};
struct PWM_Signal PWM_Duty_Period[4];
struct ErrCount Period_Duty_Errcount[4];
uint32_t period_range_error = 0x0000;
uint32_t duty_range_error = 0x0000;
uint32_t Over_Time_TAS = 0x0000;
uint32_t receive_flag = 0;
float Old_Angle = 0;
float old_difference = 0; 
float current_difference = 0;
uint32_t TAS_Err_Count = 0;
uint8_t TAS_Err_Flag = 0;
uint32_t initial_time = 0;
extern float angle_out ;
uint16_t angle_index = 0;

//============================================================================
// Clock Initiate
//============================================================================

void GTM_init_clocks( void )
{
  MSR_LM5	=0x0000;		//Enable GTM clock
}


void PWM_Port_Init(){

  // Set PWM port pin
  PWM0_PORT_PCR = PWM0_PORT_PCR_VAL;  
  PWM1_PORT_PCR = PWM1_PORT_PCR_VAL;    
  PWM2_PORT_PCR = PWM2_PORT_PCR_VAL; 
  PWM3_PORT_PCR = PWM3_PORT_PCR_VAL;
  
  PM4&=0xFEFFU;
  P4 |=0x0100U;
}

/* Timer Input Module */
void GTM_TIM_init(){

  /* Clock Management Unit */
    GTM0.CMUGCLKNUM = 0x0FFFF;   // Numerator for global clock divider
    GTM0.CMUGCLKDEN = 0x0FFFF;   // Denominator for global clock divider
    GTM0.CMUCLKEN = 0x0005;      // CMU(Ch0, Ch1) disable 
    GTM0.CMUCLK0CTRL = 0x0004;   //Defines the clock divider count value
                                 // sys_clk_period *5 = 62.5ns  @ 80MH sys_clk
    GTM0.CMUCLK1CTRL = 0x0F9F;   // Clock divider count value = 4000 times (50us)
    GTM0.CMUCLKEN = 0x000A;      // CMU(Ch0, Ch1) enable

    /* Timer Input Module TIM00,for PWM_T1*/
   /* GTM0.TIM0RST = 0x01;    //Reset Channel 0
    GTM0.TIM00CTRL = 0x80000F01;//0x80010F01;    //Channel0 enable;TPWM;Continuous operation;ARU_disable;
                            //Timeout for falling edge enable;CMU_CLK0 for channle0
                            //Exteral capture disable;Filter counter for CMU_CLK0;Filter disable
                            //falling edge;CNT/CNTS as input;Immediate edge propagation mode
    GTM0.TIM00ECTRL = 0x00000000;  //Disable exteral capture functionality
    GTM0.TIM00TDUV = 0x1000000E;   //750us (1/1MHz=1us) TOV=14
    GTM0.TIM00TDUC = 0x00000000;   //Reset counter
    GTM0.TIM00IRQNOTIFY = 0x0000;    //Clear interrupt flag
    GTM0.TIM00IRQEN = 0x00;          //Disable all interrupt  
    */
    /* Timer Input Module TIM01, for PWM_T2*/
    /*GTM0.TIM01CTRL = 0x80000F01;//0x80010F01;  //falling edge;Timeout for falling edge enable
    GTM0.TIM01ECTRL = 0x00000000;  
    GTM0.TIM01TDUV = 0x100000E;   //CMU_CLK1;TOV=14 15*50us=750us
    GTM0.TIM01TDUC = 0x00000000;   //Reset counter      
    GTM0.TIM01IRQNOTIFY = 0x0000;     
    GTM0.TIM01IRQEN = 0x00; 
    */

    /* Timer Input Module TIM02,for PWM_P*/
    GTM0.TIM02CTRL = 0x80000F01;//0x80010F01; // //falling edge;Timeout for falling edge enable
    GTM0.TIM02ECTRL = 0x00000000;  
    GTM0.TIM02TDUV = 0x1000001D;   //CMU_CLK1;TOV=29 30*50us=1500us=1.5ms
    GTM0.TIM02TDUC = 0x00000000;   //Reset counter      
    GTM0.TIM02IRQNOTIFY = 0x0000;     
    GTM0.TIM02IRQEN = 0x00;     

    /* Timer Input Module TIM02,for PWM_S*/
    GTM0.TIM03CTRL = 0x40002F01;//0x40012F01;  //rising edge;Timeout for rising edge enable
    GTM0.TIM03ECTRL = 0x00000000;  
    GTM0.TIM03TDUV = 0x10000095;   //CMU_CLK1;TOV=149 150*50=7.5ms
    GTM0.TIM03TDUC = 0x00000000;   //Reset counter
    GTM0.TIM03IRQNOTIFY = 0x0000;     
    GTM0.TIM03IRQEN = 0x00; 
}


static inline void Get_Duty_Period(void) {
    int flag = GTM0.TIM02IRQNOTIFY & 0x01;
    if(flag) {   //New Data arrival
      PWM_Duty_Period[2].PWM_Period_Count = (GTM0.TIM02GPR1 << 8) >> 8;  
      PWM_Duty_Period[2].PWM_Duty_Count = (GTM0.TIM02GPR0 << 8) >> 8;    
      PWM_Duty_Period[2].PWM_Duty =  (float) PWM_Duty_Period[2].PWM_Duty_Count / PWM_Duty_Period[2].PWM_Period_Count;
      PWM_Duty_Period[2].PWM_Period = PWM_Duty_Period[2].PWM_Period_Count * 0.0625; //uint:us
      receive_flag |= 0x01;
    }
    GTM0.TIM02IRQNOTIFY = 0x3f;	      //Clear receive flag
    
    flag = GTM0.TIM03IRQNOTIFY & 0x01;
    if(flag ){      //New Data arrival
      PWM_Duty_Period[3].PWM_Period_Count = (GTM0.TIM03GPR1 << 8) >> 8;  
      PWM_Duty_Period[3].PWM_Duty_Count = (GTM0.TIM03GPR0 << 8) >> 8;   
      PWM_Duty_Period[3].PWM_Duty =  (float)PWM_Duty_Period[3].PWM_Duty_Count / PWM_Duty_Period[3].PWM_Period_Count;
      PWM_Duty_Period[3].PWM_Period = PWM_Duty_Period[3].PWM_Period_Count * 0.0625; //uint:us
      receive_flag |= 0x10;
    }
    GTM0.TIM03IRQNOTIFY = 0x3f;	      //Clear receive flag
}

static inline void Period_range_check(void) {
  const uint32_t limit_count = 100;
  int i = 0;
  // P信号周期检查
  if((PWM_Duty_Period[2].PWM_Period < Period_Low_P || PWM_Duty_Period[2].PWM_Period > Period_High_P)) {
      if(++Period_Duty_Errcount[2].PeriodErr_Count > limit_count)
          period_range_error |= PWM_P_OUT;
  } else {
      period_range_error &= ~PWM_P_OUT;
      Period_Duty_Errcount[2].PeriodErr_Count = 0;
  }
  // S信号周期检查
  if((PWM_Duty_Period[3].PWM_Period < Period_Low_S || PWM_Duty_Period[3].PWM_Period > Period_High_S)) {
      if(++Period_Duty_Errcount[3].PeriodErr_Count > limit_count)
          period_range_error |= PWM_S_OUT;
  } else {
      period_range_error &= ~PWM_S_OUT;
      Period_Duty_Errcount[3].PeriodErr_Count = 0;
  }
  
  //Verify Duty 12.5%-87.5%
  for(i=2;i<4;i++){
      float duty_data = PWM_Duty_Period[i].PWM_Duty;
      if(duty_data < Duty_Low || duty_data > Duty_High) {
        if(++Period_Duty_Errcount[i].DutyErr_Count > limit_count)
          duty_range_error |= err_flag[i];
        if((duty_data < Duty_Low) && (duty_data > 0))
          PWM_Duty_Period[i].PWM_Duty = Duty_Low;
        if((duty_data > Duty_High) && (duty_data < 1))
            PWM_Duty_Period[i].PWM_Duty = Duty_High;
      }
      else if((duty_data >= Duty_Low) && (duty_data <= Duty_High)){
        duty_range_error &= ~err_flag[i];
        Period_Duty_Errcount[i].DutyErr_Count = 0;
      }
  }

}

//According to the flag bit for data reception(without consulting the register)
static inline void Over_Time_Detect(uint32_t Over_Time_limit) {
    // P信号
    if((receive_flag & 0x01) == 0) {
        if(++Period_Duty_Errcount[2].Timeout_Count > Over_Time_limit)
            Over_Time_TAS |= err_flag[2];
    } else {
        Over_Time_TAS &= ~err_flag[2];
        Period_Duty_Errcount[2].Timeout_Count = 0;
    }
    // S信号
    if((receive_flag & 0x10) == 0) {
        if(++Period_Duty_Errcount[3].Timeout_Count > Over_Time_limit)
            Over_Time_TAS |= err_flag[3];
    } else {
        Over_Time_TAS &= ~err_flag[3];
        Period_Duty_Errcount[3].Timeout_Count = 0;
    }
}

float AngleDiff_Limit(float New_Angle,float difference_limit){

  current_difference = New_Angle - Old_Angle;   //Get new angle difference

  if((ABS(current_difference) > difference_limit) && (TAS_Err_Count < TASErr_Limit)){
    New_Angle = Old_Angle + old_difference;
    current_difference = old_difference;
    TAS_Err_Count++;
  }
  else if((ABS(current_difference) > difference_limit)&& (TAS_Err_Count >= TASErr_Limit)){
    TAS_Err_Flag = 1;
    TAS_Err_Count =  TASErr_Limit;
  }
  else{
    TAS_Err_Count = 0;
    TAS_Err_Flag = 0;
  }

  old_difference = current_difference;
  Old_Angle = New_Angle;

  return New_Angle;
}


void Get_PWM_Data_Init()
{
    GTM_init_clocks();
    PWM_Port_Init();
    GTM_TIM_init();

}

void Get_Angle_Data(void) {
    Get_Duty_Period();
    Over_Time_Detect(10000);

    if(receive_flag != 0){    //Confirm the new duty cycle data
      Period_range_check();
      initial_time++;            
      Step_equation(PWM_Duty_Period[2].PWM_Duty,PWM_Duty_Period[3].PWM_Duty);   //Cursor algorithm
      if(initial_time == 1){      //Obtain the data for the first time
        Old_Angle = angle_out;          //To check the range of differences
      }
      else if(initial_time == 2){
        old_difference = angle_out - Old_Angle; //Initialize the angle difference
      }
      else if(initial_time >= 3 ){  
       angle_out = AngleDiff_Limit(angle_out,100.0);
	      initial_time = 3;
      }
    }
    receive_flag = 0x00;
}


