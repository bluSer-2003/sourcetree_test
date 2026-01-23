#ifndef RSENT_RECEIVE_H
#define RSENT_RECEIVE_H

#include "iodefine.h"
#include "SENT_reg.h"
#include "global.h"
/*****************************************************************************
 Global functions
 *****************************************************************************/
void RSENT0_port_config( void );
void RSENT0_init_config( void );
//void INT_config( void );
void com_start( void );
void com_end( void );
void no_com_detect( void );
void fast_data_receive( void );
//void slow_data_receive( void );
void SENT_receive_init( void );
uint32_t SENT_receive_start( void );
int Err_data_detect(uint32_t diff_threshold,uint32_t total_error_num);
int Low_data_detect(uint32_t low_threshold,uint32_t total_num);

#endif