#ifndef __GAP_CONTROL_H__
#define __GAP_CONTROL_H__

#define contact_retreat_dist    1*2*PI          //过夹紧状态回退距离
#define contact_force_limit     500             //接触点夹紧力阈值
#define contact_speed_set       -100            //接触点识别过程转速环运行速度
#define debounce_timethres      200             //防抖时间阈值，10ms
#define reverse_dist            -1.06*2*PI      //接触点识别完成回退距离
#define contact_current_limit   8.0f            //接触点电流阈值

void EMB_ContactDetect(void);
void EMB_afterContactDetect(void);
void EMB_Retreat(void);

#endif