#ifndef RSENT_RECEIVE_H
#define RSENT_RECEIVE_H

#include "iodefine.h"
#include "SENT_reg.h"

/*****************************************************************************
 Global functions
 *****************************************************************************/
void RSENT1_port_config( void );
void RSENT1_init_config( void );
void INT_config( void );
void com_start( void );
void com_end( void );
void no_com_detect( void );
void fast_data_receive( void );
void slow_data_receive( void );
void SENT_receive_init( void );
uint32_t SENT_receive_start( void );
uint32_t Err_data_detect(uint32_t difference_value_threshold,uint32_t total_error_num);

#endif