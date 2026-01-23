/***********************************************************************************************************************
Global functions
***********************************************************************************************************************/
void R_Config_CSIH3_Create(void);
void R_Config_CSIH3_Start(void);


void R_CSIH1_Master_Send(uint16_t* const tx_buf, uint32_t chip_id,uint16_t* const rx_buf);
void CAN1145_ModeControl(int CAN_Mode);

#define CAN_normal                      0 /* CAN Mode */
#define CAN_sleep                       1 /* CAN Mode */
#define CAN_standby                     2 /* CAN Mode */


#define CS_CAN0		0x00FE0000
#define CS_CAN1		0x00FB0000

#define CAN_W		0
#define CAN_R		1

//#define 

