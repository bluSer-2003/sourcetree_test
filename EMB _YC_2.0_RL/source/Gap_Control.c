#include "gtm.h"
#include "global_struct.h"
#include "parameter.h"
#include "global.h"
#include "Gap_Control.h"
#include "Loop_Control.h"

extern uint32_t force_data;
int retreatFlag = 0;      // 是否已经触发回退
int reverseFlag = 0;
int timeoutFlag = 0;
int contectFlag = 0;
extern volatile double angle;

float targetPosr = 0.0f;
float current_filtered = 0.0f;
uint16_t ContactCount = 0;
uint16_t stateTimer = 0;
uint32_t Contact_force_data = 0;
uint8_t ContactState = 0;
uint8_t Contact_busy_flag = 0;

void SpeedLoop(float SpdRef,float SpdFbk);
void PosLoop(float PosRef,float PosFbk);

//对作为判断依据的电流进行滤波
float Filter_Current(float new_val, float old_val) {
    return old_val * 0.9f + new_val * 0.1f;
}

void EMB_ContactDetect(){
    int isPositionReached = 0;
    int isForceReleased = 0;

    //数据预处理
    current_filtered = Filter_Current(pi_iq.Fbk * CURRENT_PU_RE,current_filtered);
    Contact_force_data = force_data;
    GetPosition();

    switch (ContactState) {
        case 0:// 初始化
            ContactState = 1;
            stateTimer = 0;
            ContactCount = 0;
            Contact_busy_flag = 1;
            break;
        
        case 1:// 初始判断
            //当前位置在夹紧状态，先回退再进行接触点识别
            if (Contact_force_data > contact_force_limit){
                targetPosr = g_Control.PosFbk - contact_retreat_dist*POSITION_PU; 
                g_Control.PosRef = targetPosr;
                g_Control.PosFbk = -g_Control.pos.PosSum * POSITION_PU;
                PosLoop(g_Control.PosRef, g_Control.PosFbk);
                ContactState = 2;       
                stateTimer = 0;
            }
            //回到未夹紧状态 开始进行接触点识别
            else {
                stateTimer++;
                if(stateTimer > debounce_timethres){
                    ContactState = 3;        //接触点识别
                    stateTimer = 0;
                    ContactCount = 0; 
                }
            }
            break;

        case 2://case1判定当前在夹紧状态，需要回退
            g_Control.PosRef = targetPosr;
            g_Control.PosFbk = -g_Control.pos.PosSum * POSITION_PU;
            PosLoop(g_Control.PosRef, g_Control.PosFbk);

            isPositionReached = (ABS(g_Control.PosRef - g_Control.PosFbk) < 0.1f);
            isForceReleased = (Contact_force_data < 0.5*contact_force_limit);

            stateTimer++; 
           
            if(isForceReleased){                //夹紧力释放成功
                stateTimer = 0;
                ContactState = 3;               //回退完成，跳到接触点识别
            }else if(isPositionReached){        //到位置但是仍然不满足释放条件
                stateTimer = 0;
                ContactState = 1;               //回到第一步 重新设置目标位置 继续回退
            }else if(stateTimer > 100*debounce_timethres){       //超时仍未达到目标位置100*10ms
                stateTimer = 0;
                ContactState = 4;               //故障
            }
            break;

        case 3: //接触点识别，速度环缓慢接近接触点
            g_Control.SpdRef = contact_speed_set*SPEED_PU;
            g_Control.SpdFbk = -g_Control.m_speed.Speed*SPEED_PU;    //改正负号        //转速反馈
            SpeedLoop(g_Control.SpdRef,g_Control.SpdFbk);
            stateTimer ++;

            //夹紧力反馈大于500N
            if ((force_data > contact_force_limit) || (current_filtered > contact_current_limit)){
           // if ((force_data > contact_force_limit)){
                ContactCount++;
            }else if(ContactCount > 0){
                ContactCount--;
            }      
            //防抖，持续10ms
            if(ContactCount > debounce_timethres){
                g_Control.pos.PosSum = 0;
                g_Control.pos.PosOld = angle;   
                stateTimer = 0;                 //转速环运行计时
                contectFlag = 1;                //分离点识别完成标志 
                ContactCount = 0;               //计数值清零
                Contact_busy_flag = 0;          //结束接触点识别
            }else if((stateTimer > 1200*debounce_timethres) && (current_filtered > 4.0f)){      //一圈0.6s  1200*10ms=12s
                g_Control.pos.PosSum = 0;
                g_Control.pos.PosOld = angle;   
                g_Control.SpdRef = 0;
                contectFlag = 2;                //超时
                ContactCount = 0;               //计数值清零
                stateTimer = 0;
                ContactState = 4;
            } 
            break;
        case 4:
            contectFlag = 2;                    // 失败标志
            Contact_busy_flag = 0;              // 解锁
            break;
    }
}

unsigned int reversecount = 0;
unsigned int task_count = 0;
void EMB_afterContactDetect(void){
    static float targetPos = 0.0f;

    GetPosition();
    
// ============= 正常情况：反转1.06圈 =============
    //接触点识别完成
    if(contectFlag == 1 || contectFlag == 2 )
        targetPos = -1.5 *2*PI*POSITION_PU;// 根据输入圈数计算目标位置
    //    
    if((contectFlag == 1 || contectFlag == 2)&& reverseFlag == 0){
        g_Control.PosRef = targetPos;
        g_Control.PosFbk = -g_Control.pos.PosSum * POSITION_PU;
        PosLoop(g_Control.PosRef, g_Control.PosFbk);
	task_count++;
	
	//制动间隙回退完成
        if(ABS(g_Control.PosFbk - targetPos) < 0.1f ){
		reversecount++;
		if(reversecount>=100)
			reverseFlag = 1; 
			task_count = 0;
	}
    }
    
}


// 给定为0时回退
void EMB_Retreat(void)
{
    static float TargetPos = 0.0f;   // 回退的目标位置
        
    //压力给定为零 && 没有触发过回退 && 当前在夹紧状态   //后续可以设置当前压力值为多少时触发位置环回退 
    if((g_Control.target_pressure == 0 || g_Control.PosRef == 0) && (retreatFlag == 0) && (force_data>=1000)&&lsw == 3)
    {
        GetPosition();
	    lsw=3; 
        TargetPos = 1.06 * 2.0* PI * POSITION_PU;       // 计算目标位置： - 1.06 圈
        retreatFlag = 1;                // 标记已进入回退模式
    }
    //位置环回退
    if(retreatFlag == 1||retreatFlag == 2)
    {
	g_Control.PosRef = TargetPos;
    	g_Control.PosFbk =-g_Control.pos.PosSum*POSITION_PU;
        PosLoop(g_Control.PosRef, g_Control.PosFbk);
        // 判断是否到达目标点（误差小于阈值时认为完成）
        if(fabsf(g_Control.PosRef + g_Control.PosFbk) < 0.01f)
        {
            retreatFlag = 0;   // 回退完成，清除标志
	    lsw=4;
        }
    }
}