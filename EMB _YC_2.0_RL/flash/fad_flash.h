#ifndef __FLASH_PARASET_H__
#define __FLASH_PARASET_H__


#include "r_fad.h"

#define READ_DATA_FLASH(addr) (*((volatile T_u2 *)(addr)))

#define Block3_Start    (0xFF200340U)
#define Block3_End      (0xFF20037FU)

#define Block4_Start    (0xFF200380U)
#define Block4_End      (0xFF2003BFU)

#define Block5_Start    (0xFF2003C0U)
#define Block5_End      (0xFF2003FFU)

#define Block6_Start    (0xFF200400U)
#define Block6_End      (0xFF20043FU)

/* Prototype declaration */
void FAD_FlashOperation(T_u4_FadAddr base_addr , T_u1 data_length, T_u4* i_p_DataBuff);
void checkError(T_u4_FadErr fadErr);
void checkBlankError(T_u4_FadErr fadErr, T_u4_FadErr exp_fadErr, T_u4_FadAddr exp_fadAddr);
void R_FAD_DF_Read( T_u4_FadAddr FadAddr, T_u4* DataBuff , T_u1 Data_Length );
void flash_operation( T_u4_FadAddr base_addr , T_u1 data_length, T_u4* i_p_DataBuff);

extern unsigned char write_flag;
extern T_u4 Flash_Data[16];
extern T_u4 Data_Flash_Read[16];
#endif