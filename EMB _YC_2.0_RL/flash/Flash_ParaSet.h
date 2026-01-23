#ifndef __FLASH_PARASET_H__
#define __FLASH_PARASET_H__

//DataFlash Address
#define Block1_Start    (0xFF2002C0U)
#define Block1_End      (0xFF2002FFU)
#define Block2_Start    (0xFF200300U)
#define Block2_End      (0xFF20033FU)

void Para_FlashRead(void);
void Para_FlashWrite(void);
void Control_FlashWrite(void);
void Control_FlashRead(void);

#endif