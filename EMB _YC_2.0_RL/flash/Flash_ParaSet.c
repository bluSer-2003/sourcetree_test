#include "Flash_ParaSet.h"
#include "global_struct.h"
#include "global.h"
#include "gtm.h"
#include "parameter.h"
#include "fad_flash.h"
#include "r_fad.h"

T_u4 ParaData_Flash_Read[16];
T_u4 Para_Flash_Data[16];
T_u4 ControlData_Flash_Read[16];
T_u4 Control_Flash_Data[16];

//控制烧写的标志位
uint8_t Paraflash_Complete_Flag = 0;
uint8_t Paraflash_Request_Flag = 0;
uint8_t Controlflash_Complete_Flag = 0;
uint8_t Controlflash_Request_Flag = 0;

//外部变量
extern unsigned int Flag_CAN_flash_Order;
extern volatile uint8_t magnet_done_flag;//驻车完成标志位

/**********Flash operation**************/
/* ParaData_Flash_Read[16]
[0]:Ali_angle  [1]:Ali_flag  [2]:cur_kp     [3]:cur_ki
[4]:spd_kp     [5]:spd_ki    [6]:pos_kp     [7]:pos_ki
[8]:fw_kp      [9]:fw_ki     [10]:oi        [11]:ov
[12]:spdSAT    [13]:posSAT   [14]:\         [15]:flashflag     
*/
void Para_FlashWrite(void)
{
    T_u4_FadAddr    base_addr;
    T_u1            data_length;

    data_length = sizeof(Para_Flash_Data); //number of bytes
    base_addr = Block1_Start;
    Para_Flash_Data[0] =(int)(g_Control.Aligmenta.Ali_angle*1000);   
    Para_Flash_Data[1] = flag.AliCheck;
    Para_Flash_Data[2] = pi_iq.Kp*100;
    Para_Flash_Data[3] = pi_iq.Ki*1000;
    Para_Flash_Data[4] = pi_spd.Kp*100;
    Para_Flash_Data[5] = pi_spd.Ki*1000;
    Para_Flash_Data[6] = pi_pos.Kp*100;
    Para_Flash_Data[7] = pi_pos.Ki*1000;
    Para_Flash_Data[8] = pi_fw.Kp*100;
    Para_Flash_Data[9] = pi_fw.Ki*1000;
    Para_Flash_Data[10]= g_Control.prot.CurLevel1*10;  
    Para_Flash_Data[11]= g_Control.prot.VoltLevel1*10;
    Para_Flash_Data[12]= pi_spd.Umax*10;
    Para_Flash_Data[13]= pi_pos.Umax*100;
    Para_Flash_Data[14]= 0;     
    Para_Flash_Data[15]= 1;                    // 数据有效标志  
    if(Paraflash_Request_Flag == 1 && Paraflash_Complete_Flag == 0){
        FAD_FlashOperation(base_addr,data_length,Para_Flash_Data);
        Paraflash_Request_Flag = 0;
        Paraflash_Complete_Flag = 1;
    }
    Flag_CAN_flash_Order = 0;
}

void Para_FlashRead(void)
{
    R_FAD_DF_Read(Block1_Start, ParaData_Flash_Read ,16*4); 

    g_Control.Aligmenta.Ali_angle =(float)ParaData_Flash_Read[0]/1000;
    flag.AliCheck = ParaData_Flash_Read[1];
    pi_iq.Kp = (float)ParaData_Flash_Read[2]/100;
    pi_iq.Ki = (float)ParaData_Flash_Read[3]/1000;
    pi_spd.Kp= (float)ParaData_Flash_Read[4]/100;
    pi_spd.Ki= (float)ParaData_Flash_Read[5]/1000;
    pi_pos.Kp= (float)ParaData_Flash_Read[6]/100;
    pi_pos.Ki= (float)ParaData_Flash_Read[7]/1000;
    pi_fw.Kp = (float)ParaData_Flash_Read[8]/100;
    pi_fw.Ki = (float)ParaData_Flash_Read[9]/1000;
    g_Control.prot.CurLevel1 = (float)ParaData_Flash_Read[10]/10;
    g_Control.prot.CurLevel2 = 1.2*g_Control.prot.CurLevel1;
    g_Control.prot.CurLevel3 = 1.5*g_Control.prot.CurLevel1;
    g_Control.prot.VoltLevel1= (float)ParaData_Flash_Read[11]/10;
    g_Control.prot.VoltLevel2= 1.5*g_Control.prot.VoltLevel1;
    
    pi_spd.Umax =(float)ParaData_Flash_Read[12]/10;
    pi_spd.Umin =-pi_spd.Umax;

    pi_pos.Umax = (float)ParaData_Flash_Read[13]/100;
    pi_pos.Umin = -pi_pos.Umax;

    Paraflash_Request_Flag = 1;
    Paraflash_Complete_Flag = 0;
    Para_FlashWrite();
}

/**********Flash operation**************/
/* ParaData_Flash_Read[16]
[0]:magnet_done_flag  [1]:pos   [2]:\       [3]:\
[4]:\                 [5]:\     [6]:\       [7]:\
[8]:\                 [9]:\     [10]:\      [11]:\
[12]:\                [13]:\    [14]:\      [15]:\     
*/
void Control_FlashWrite(void)
{
    T_u4_FadAddr    base_addr;
    T_u1            data_length;

    data_length = sizeof(Control_Flash_Data); //number of bytes
    base_addr = Block2_Start;
    Control_Flash_Data[0] = Brake_Control.magnet_done_flag;     // 新增：保存电磁铁完成标志
    Control_Flash_Data[1] = g_Control.pos.PosSum*POSITION_PU*100;
    Control_Flash_Data[2] = 0;
    Control_Flash_Data[3] = 0;
    Control_Flash_Data[4] = 0;
    Control_Flash_Data[5] = 0;
    Control_Flash_Data[6] = 0;
    Control_Flash_Data[7] = 0;
    Control_Flash_Data[8] = 0;
    Control_Flash_Data[9] = 0;
    Control_Flash_Data[10]= 0;  
    Control_Flash_Data[11]= 0;
    Control_Flash_Data[12]= 0;
    Control_Flash_Data[13]= 0;
    Control_Flash_Data[14]= 0;
    Control_Flash_Data[15]= 1;     // 数据有效标志  
    if(Controlflash_Request_Flag == 1 && Controlflash_Complete_Flag == 0){
        FAD_FlashOperation(base_addr,data_length,Control_Flash_Data);
        Controlflash_Request_Flag  = 0;
        Controlflash_Complete_Flag = 1;
    }
    Flag_CAN_flash_Order = 0;
}

void Control_FlashRead(void)
{
    R_FAD_DF_Read(Block2_Start, ControlData_Flash_Read ,16*4); 

    Brake_Control.magnet_done_flag = ControlData_Flash_Read[0];   // 新增：恢复电磁铁标志位

    g_Control.pos.PosSum=(float)ControlData_Flash_Read[1]*POSITION_PU_RE/100;
    
    Control_FlashWrite();
}