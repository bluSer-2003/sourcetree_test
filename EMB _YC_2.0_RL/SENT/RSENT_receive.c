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

//============================================================================
// Defines
//============================================================================
#define RSENT0MDC RSENT0.MDC.UINT32
#define RSENT0MST RSENT0.MST.UINT32

#define RSENT0_PORT       P0
#define RSENT0_PORT_BIT    
#define RSENT0_PORT_PCR   PCR0_0
#define RSENT0_PORT_PCR_VAL 0x0052

#define FCLA5CTL0 FCLA5.CTL0.UINT8
#define DNFA5CTL DNFA5.CTL.UINT8
#define DNFA5EN DNFA5.EN



struct r_sentData_fast {           // Define structure for SENT fast channel data
    
 uint32_t RX0;                  // Entry 1 RX0 for message data(RSENTnFRXD)
 uint32_t RX0_calc_value;       // Entry 3 RX0 for calculated message data
 uint32_t RX0_pressure_data;  // Entry 4 RX0 for unnormal pressure signal

};

//============================================================================
// Prototypes
//============================================================================

void            init_clocks             ( void );
void            RSENT0_init_config      ( void );
void            RSENT0_port_config      ( void );
void            no_com_detect           ( void );
void            com_start               ( void );
void            com_end                 ( void );
void            fast_data_receive       ( void );
void            SENT_receive_init       ( void );
uint32_t        SENT_receive_start      ( void );
int             Err_data_detect         (uint32_t difference_value_threshold,uint32_t total_error_num);
int 		Low_data_detect         (uint32_t low_threshold,uint32_t total_num);
//============================================================================
// Variables
//============================================================================

 struct r_sentData_fast RSENT0_data_fast[8];     // Create ring buffer with 8 items of "r_sentData_s"
 
 volatile uint32_t fast_buffer = 0x00;           // Variable "fast_buffer" for incrementation
 volatile uint32_t timeout_count = 0x00;         // Variable for timeout counter
 volatile uint32_t SENT_nocom_flag = 0x00;           // Flag variable for "No Communication" detection
 volatile uint32_t data_err_flag = 0x00;         //Flag for data error:1:data error 2:sensor break
 volatile uint32_t initial_time = 0;             //                                       
 static uint32_t data_err_count = 0x00;          //Variable for continuous data exception
 static uint32_t low_data_count = 0;             //Variable for continuous low data
 uint32_t pressure_data = 0;
//============================================================================
// Clock Initiate
//============================================================================

void init_clocks( void )
{
  MSR_LM7	=0x0000;		//Enable SENT clock
}

//============================================================================
// RSENT4 Port Configuration
//============================================================================
// --> PORT ASSIGNMENTS <--
// RSENT1RX = P0_0

void RSENT0_port_config( void ) {

  // Set RSENT4 port pin
  RSENT0_PORT_PCR = RSENT0_PORT_PCR_VAL;    

  //diag filter register
  FCLA5CTL0 = 0x00;       //edge detection
  DNFA5CTL  = 0x00;       // Enable digital filter register for SENT0RX
  DNFA5EN  |= 0x01;
  
}

//============================================================================
// RSENT1 Timestamp configuration
//============================================================================

void RSENT0_init_config( void ) {

  //operation mode change
  RSENT0MDC        = 0x01;      // Set RSENT1 Module into configuration mode
  while(RSENT0MST != 0x01);     // Check if RSENT1 is in configuration mode 

  // Timestamp Clock configuration
  RSENT0TSPC       = 0x0150;      // Set RSENT1 Timestamp to 1us for the expected 3us 
                                  //SENT tick as communication clock is 80MHz
  RSENT0TSC        = 0x00;        // Write initial value "0" to the timestamp counter

  //communication baud rate prescaler register configuration
  RSENT0BRP        = 0x00020400;    // Configure communication settings for 16MHz, 
                                    // 3us ticktime, and 80 MHz Fcom
  //communication configuration
  RSENT0CC         = 0x009A;        // RSENT1 Configuration with pause pulse for 
                                    // variable message length and enabled
                                    // Enhanced Serial Message reception
                                    // CRC check enable
  RSENT0IDE        = 0x07FE;        // Configure Interrupts
}

//============================================================================
// RSENT4 communication start
//============================================================================

void com_start(void){

   RSENT0MDC = 0x05;             // Set RSENT1 Module into operation active mode
   while(RSENT0MST != 0x05);     // Check if RSENT1 is in operation active mode
   
}

//============================================================================
// RSENT1 communication end
//============================================================================

void com_end(void){

   RSENT0MDC = 0x03;             // Set RSENT1 Module into operation idle mode
   
}

//============================================================================
// detect for fast channel receive interrupt status
//============================================================================

void no_com_detect(void){	
  if( (RSENT0CS & 0x01) == 0){
    if ( timeout_count >= 10000){     // Check if the timeout condition is true(0.5s)
        SENT_nocom_flag = 0x01;       // Set the "No Communication" flag
        timeout_count = 0;
    }
    else                              // Increment timeout counter
        timeout_count++;
  }
  else{
      SENT_nocom_flag = 0;            // Reset error flag
      timeout_count = 0;
  }
}

//============================================================================
// deal with data from fast channel
//============================================================================
void fast_data_receive(void){
  uint32_t temp = 0;
  if (( RSENT0CS & 0x01 ) == 1 ){                              // Fast Channel Receive Interrupt detected
          
        // -> FAST CHANNEL MESSAGE HANDLING <-
        // Perform sensor value calculation from fast message content
        //RSENT0_data_fast[fast_buffer].RX0_ts = RSENT4FRTS;            // Write timestamp value to "RX0_ts" of RSENT1_data
        RSENT0_data_fast[fast_buffer].RX0  = RSENT0FRXD;                // Write value of RSENT1.FRXD into "RX0"
        RSENT0_data_fast[fast_buffer].RX0_calc_value = 
        (( RSENT0_data_fast[fast_buffer].RX0 << 8)  >> 20 );            // Get 6 data nibbles
        temp = RSENT0_data_fast[fast_buffer].RX0_calc_value;
        if(temp < 410 && temp > 370)                                    //零漂补偿
            temp = 410;
        else if(temp > 3700 && temp > 3686)                             // pressure > 3686
            temp = 3686;
        RSENT0_data_fast[fast_buffer].RX0_pressure_data =  (temp - 410)*45000/3276; //Get force data
        pressure_data = RSENT0_data_fast[fast_buffer].RX0_pressure_data;
        fast_buffer++ ;                                       // Incrementation of "fast_buffer" with 1
    }	

    if (fast_buffer >= 8){                                 // Check if "fast_buffer" is >= 8
        fast_buffer=0;                                       // Reset "fast_buffer" to 0
    }   
}

//============================================================================
// Deal with data received
//Return:data_err_flag
//                0 : normal operation
//                1 : continuous disturbed data,the value between adjacent data exceeds the threshold
//                2 : The pressure data is persistently too low
//============================================================================
int Err_data_detect(uint32_t diff_threshold,uint32_t total_error_num)
{
  uint32_t force_1,force_2;
  uint32_t difference_value;

  //Determine whether an exception occurs based on the data difference
  force_1 = RSENT0_data_fast[(fast_buffer + 6) % 8].RX0_pressure_data;
  force_2 = RSENT0_data_fast[(fast_buffer + 7) % 8].RX0_pressure_data;
  difference_value = abs(force_2 - force_1);

  //disturbed data
  //Deal with disturbed data,replace with last data
  if((difference_value > diff_threshold) && (data_err_flag == 0) && (SENT_nocom_flag == 0)){
    RSENT0_data_fast[(fast_buffer + 7) % 8].RX0_pressure_data = RSENT0_data_fast[(fast_buffer + 6) % 8].RX0_pressure_data;
    data_err_count = data_err_count + 1;
  }
  else if(difference_value <= diff_threshold){
    data_err_count = 0; //data recovery
    data_err_flag = 0;
  }
  //continuous disturbed data:error data
  if(data_err_count >= total_error_num){
    data_err_flag = 1;
  }
  return data_err_flag;
}

int Low_data_detect(uint32_t low_threshold,uint32_t total_num)
{
    uint32_t force = 0;
    force = RSENT0_data_fast[(fast_buffer + 7) % 8].RX0_pressure_data;

    if( SENT_nocom_flag == 0){
      //Low data detect
      if((force <= low_threshold) && (low_data_count > total_num)){
        data_err_flag = 2;
      }
      else if( (force <= low_threshold) && (low_data_count <= total_num)){
        low_data_count++;
      }else if(force > low_threshold){
        low_data_count = 0;
        if(data_err_flag == 2){
          data_err_flag = 0;
        }
      }
    }
    return data_err_flag;
}

//============================================================================
// Main function
//============================================================================

void SENT_receive_init( void ) {

   init_clocks();                     // Initiate clocks
    
   RSENT0_port_config();              // Call port configuration for SENT interface
   RSENT0_init_config();              // Call RSENT1 timestamp configuration   
   __EI();                            // Enable global interrupt processing 
   
} 

uint32_t SENT_receive_start( void ){	

  //initial configuration(在main函数中已经初始化)
  //SENT_receive_init();

  //start communication and deal with data from fast and slow channel
  com_start();
 
  //Receive force data
  fast_data_receive();
  initial_time++;

  //detect status of communication
  no_com_detect();

  if(SENT_nocom_flag == 0){
    //先检测是否存在数据不合理的情况
    data_err_flag = Low_data_detect(80,1000);
    //检测数据是否有突变,至少检测到两个数据
    if(initial_time >= 2)
    {
      data_err_flag = Err_data_detect(30,1000);
      initial_time = 2;
    }
  }
  return data_err_flag;
}

