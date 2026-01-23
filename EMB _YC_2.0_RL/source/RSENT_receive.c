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
#define RSENT1MDC RSENT1.MDC.UINT32
#define RSENT1MST RSENT1.MST.UINT32

#define RSENT1_PORT       P0
#define RSENT1_PORT_BIT    
#define RSENT1_PORT_PCR   PCR0_1
#define RSENT1_PORT_PCR_VAL 0x0052

#define FCLA5CTL0 FCLA5.CTL0.UINT8
#define DNFA5CTL DNFA5.CTL.UINT8
#define DNFA5EN DNFA5.EN

struct r_sentData_fast {           // Define structure for SENT fast channel data
    
 uint32_t RX0;                  // Entry 1 RX0 for message data(RSENTnFRXD)
 uint32_t RX0_calc_value;       // Entry 3 RX0 for calculated message data
 uint32_t RX0_pressure_signal;  // Entry 4 RX0 for unnormal pressure signal

};

struct r_sentData_slow {          // Define structure for SENT slow channel data
    
 uint32_t RX0_sc;               // Entry 1 RX0 for slow channel message data
 uint32_t RX0_sc_mID;           // Entry 2 RX0 for calculated slow channel message ID   
 uint32_t RX0_sc_data;          // Entry 3 RX0 for calculated slow channel data
 uint32_t RX0_sc_ts;            // Entry 4 for RX0 slow channel timestamp data
};



//============================================================================
// Prototypes
//============================================================================

void            init_clocks             ( void );
void            RSENT1_init_config      ( void );
void            RSENT1_port_config      ( void );
void            INT_config              ( void );
void            no_com_detect           ( void );
void            com_start               ( void );
void            com_end                 ( void );
void            fast_data_receive       ( void );
void            SENT_receive_init       ( void );
uint32_t        SENT_receive_start      ( void );
uint32_t        Err_data_detect         (uint32_t difference_value_threshold,uint32_t total_error_num);
//============================================================================
// Variables
//============================================================================

 struct r_sentData_fast RSENT1_data_fast[8];     // Create ring buffer with 8 items of "r_sentData_s"
 struct r_sentData_slow RSENT1_data_slow[8];     // Create ring buffer with 8 items of the slow channel SENT data
 
 volatile uint32_t fast_buffer = 0x00;           // Variable "fast_buffer" for incrementation
 volatile uint32_t slow_buffer = 0x00;           // Variable "slow_buffer" for incrementation
 volatile uint32_t timeout_count = 0x00;         // Variable for timeout counter
 volatile uint32_t no_com_flag = 0x00;           // Flag variable for "No Communication" detection

 volatile uint32_t data_err_flag = 0x00;       //Flag for data error:
                                                //1:data error   
                                                //2:pressure data too low
 volatile uint32_t data_err_count = 0x00;       //Variable for continuous data exception 
 uint32_t buffer_count = 0x00;
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
// RSENT41X = P0_1

void RSENT1_port_config( void ) {

  // Set RSENT4 port pin
  RSENT1_PORT_PCR = RSENT1_PORT_PCR_VAL;    

  //diag filter register
  FCLA5CTL0 = 0x00;       //edge detection
  DNFA5CTL  = 0x00;       // Enable digital filter register for SENT0RX
  DNFA5EN  |= 0x01;
  
}

//============================================================================
// RSENT4 Timestamp configuration
//============================================================================

void RSENT1_init_config( void ) {

  //operation mode change
  RSENT1MDC        = 0x01;      // Set RSENT1 Module into configuration mode
  while(RSENT1MST != 0x01);     // Check if RSENT1 is in configuration mode 

  // Timestamp Clock configuration
  RSENT1TSPC       = 0x0150;      // Set RSENT1 Timestamp to 1us for the expected 3us 
                                //SENT tick as communication clock is 80MHz
  RSENT1TSC        = 0x00;      // Write initial value "0" to the timestamp counter

  //communication baud rate prescaler register configuration
  RSENT1BRP        = 0x00020400;    // Configure communication settings for 16MHz, 
                                    // 3us ticktime, and 80 MHz Fcom
  //communication configuration
  RSENT1CC         = 0x009A;        // RSENT1 Configuration with pause pulse for 
                                    // variable message length and enabled
                                    // Enhanced Serial Message reception
                                    // CRC check enable
  RSENT1IDE        = 0x07FE;        // Configure Interrupts
  
}


//============================================================================
// RSENT4 interrupt configuration
//============================================================================

// void INT_config( void ){

// EIC217 = 0x004E;    // Initiate Interrupt for SENT4 message receive with highest priority
// EIC216 = 0x004F;    // Initiate Interrupt for SENT4 status with lower priority

// }

//============================================================================
// RSENT1 communication start
//============================================================================

void com_start(void){

   RSENT1MDC = 0x05;             // Set RSENT1 Module into operation active mode
   while(RSENT1MST != 0x05);     // Check if RSENT1 is in operation active mode
}

//============================================================================
// RSENT1 communication end
//============================================================================

void com_end(void){

   RSENT1MDC = 0x03;             // Set RSENT1 Module into operation idle mode
}

//============================================================================
// detect for fast channel receive interrupt status
//============================================================================

void no_com_detect(void){
	
  if( (RSENT1CS & 0x01) == 0){
	  
    if ( timeout_count >= 1000000){ // Check if the timeout condition is true

      no_com_flag = 0x01;           // Set the "No Communication" flag
	    timeout_count = 0;

    }
    else {                          // Increment timeout counter

      timeout_count++;
      
    }
  }
}

//============================================================================
// deal with data from fast channel
//============================================================================
void fast_data_receive(void){
	
  if (( RSENT1CS & 0x01 ) == 1 ){                              // Fast Channel Receive Interrupt detected
      // -> FAST CHANNEL MESSAGE HANDLING <-
      // Perform sensor value calculation from fast message content
      //RSENT1_data_fast[buffer_count].RX0_ts = RSENT1FRTS;  
	    // Write timestamp value to "RX0_ts" of RSENT4_data
        RSENT1_data_fast[buffer_count].RX0    = RSENT1FRXD;            // Write value of RSENT4.FRXD into "RX0"
	      RSENT1MDC = 0x01;
        RSENT1_data_fast[buffer_count].RX0_calc_value = 
         (( RSENT1_data_fast[buffer_count].RX0 << 8)  >> 20 );          // Get 6 data nibbles
	      if((RSENT1_data_fast[buffer_count].RX0_calc_value <= 410) &&
            (RSENT1_data_fast[buffer_count].RX0_calc_value >= 405)){
		          RSENT1_data_fast[buffer_count].RX0_calc_value = 410;
	      }                                                               //zoom in minimum
        RSENT1_data_fast[buffer_count].RX0_calc_value = 
        (unsigned long)(RSENT1_data_fast[buffer_count].RX0_calc_value - 410)*45000/3276; //Get force data

        if(RSENT1_data_fast[buffer_count].RX0_calc_value < 10){        //pressure < 410
          RSENT1_data_fast[buffer_count].RX0_pressure_signal = 1 ;      //Get %FS data;
        }
        else if(RSENT1_data_fast[buffer_count].RX0_calc_value > 45000 ){  // pressure > 3686
          RSENT1_data_fast[buffer_count].RX0_pressure_signal = 2 ;
        }
        else if( 10<= RSENT1_data_fast[buffer_count].RX0_calc_value <= 45000) {   //410 <= pressure <= 3686
          RSENT1_data_fast[buffer_count].RX0_pressure_signal = 0;
        } 
        buffer_count++ ;                                       // Incrementation of "buffer_count" with 1
    }   
    //com_start();
}

//============================================================================
// Deal with data received
//============================================================================
uint32_t Err_data_detect(uint32_t difference_value_threshold,uint32_t total_error_num)
{
  uint32_t force_1,force_2;
  uint32_t difference_value;

  if(buffer_count >= 2 && buffer_count <= 8){
    force_1 = RSENT1_data_fast[buffer_count - 1].RX0_calc_value;
    force_2 = RSENT1_data_fast[buffer_count].RX0_calc_value;
  }
  else if(buffer_count == 1){
    force_1 = RSENT1_data_fast[7].RX0_calc_value;
    force_2 = RSENT1_data_fast[0].RX0_calc_value;
  }

  //Determine whether an exception occurs based on the data difference
  difference_value = abs(force_1 - force_2);

  //Force data too small
  if(force_2 <= 10){
      data_err_flag = 2;  
  }
  //disturbed data
  if((difference_value < difference_value_threshold) & (data_err_flag == 0)){
    RSENT1_data_fast[buffer_count].RX0_calc_value = RSENT1_data_fast[buffer_count - 1].RX0_calc_value;
    data_err_count = data_err_count + 1;
  }
  else{
    data_err_count = 0; //data recovery
  }
  //continuous disturbed data:error data
  if(data_err_count >= total_error_num){
    data_err_flag = 1;
  }
  return data_err_flag;
}

//============================================================================
// Main function
//============================================================================

void SENT_receive_init( void ) {

   init_clocks();                     // Initiate clocks
    
   RSENT1_port_config();              // Call port configuration for SENT interface
   RSENT1_init_config();              // Call RSENT1 timestamp configuration
   //INT_config();                      // Call interrupt configuration          
   __EI();                            // Enable global interrupt processing 
   com_start(); 
} 

uint32_t SENT_receive_start( void ){

  //initial configuration
  //SENT_receive_init();

  //start communication and deal with data from fast and slow channel
  fast_data_receive();
  com_start();
  //slow_data_receive();
  data_err_flag = Err_data_detect(30,5);

  //detect status of communication
  no_com_detect();
  
  data_err_flag = Err_data_detect(50,5);
  
  return data_err_flag;
  

}

