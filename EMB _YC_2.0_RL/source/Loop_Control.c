#include "gtm.h"
#include "global_struct.h"
#include "parameter.h"
#include "global.h"
#include "Loop_Control.h"
#include "math.h"

extern uint32_t force_data;
extern volatile double angle;
extern uint8_t Contact_busy_flag;
double omiga=0;
float  beta = 0;


// 电流环控制
void CurrentLoop(float IqRef, float Idref, float IqFbk, float IdFbk)
{
    // 设置Iq和Id的参考值
    pi_iq.Ref = IqRef;  // 设置Q轴电流参考值
    pi_id.Ref = Idref;  // 设置D轴电流参考值

    // 设置电流反馈值，经过PU变换（电流归一化）
    pi_iq.Fbk = IqFbk * CURRENT_PU;  // Q轴电流反馈值
    pi_id.Fbk = IdFbk * CURRENT_PU;  // D轴电流反馈值

    // 调用PI控制器计算电流控制输出
    //PI_MACRO(pi_iq);
    //PI_MACRO(pi_id);
    PI_CUR(&pi_iq);  // Q轴电流控制
    PI_CUR(&pi_id);  // D轴电流控制

    // 根据PI控制输出更新电流控制参考值
    ipark1.Ds = pi_id.Out;  // 更新D轴电流输出
    ipark1.Qs = pi_iq.Out;  // 更新Q轴电流输出

    // 进行反 Park 变换，计算出α、β轴电流
    ipark1.Sine = park1.Sine;  // 使用Park变换后的正弦值
    ipark1.Cose = park1.Cose;  // 使用Park变换后的余弦值
    IPARK_MACRO(ipark1);  // 反Park变换，计算α、β轴电流

    // 设置空间矢量生成器的输入，进行电压空间矢量计算
    svgen1.Ualpha = ipark1.Alpha / IQ_MAX;  // α轴电压（归一化）
    svgen1.Ubeta = ipark1.Beta / IQ_MAX;   // β轴电压（归一化）

    // 调用PWM生成模块，计算出各相的占空比
    svpwm(&svgen1);  // 生成三相PWM信号

    // 将PWM占空比输出到控制结构体
    g_Control.Dutycycle_A = svgen1.Ta;  // A相占空比
    g_Control.Dutycycle_B = svgen1.Tb;  // B相占空比
    g_Control.Dutycycle_C = svgen1.Tc;  // C相占空比
}

// 弱磁控制环
inline void FWLoop(void)
{
    g_Control.count.FWLoopCount=2;
    // 当FWLoopCount为1时，进行弱磁环的分频操作
    if (g_Control.count.FWLoopCount == 1) {    
        // 设置参考值
        pi_fw.Ref = FW_REF;  // 弱磁参考值
        
        // 获取反馈电压
        pi_fw.Fbk = g_Control.FW.Vdcfbkfli;  // 获取反馈电压值
	pi_fw.Fbk = sqrt(pi_iq.Out*pi_iq.Out + pi_id.Out*pi_id.Out);  // 获取反馈电压值
        
        // 调用PI控制器进行计算
        PI_MACRO(pi_fw);
        
        // 根据PI控制输出设置电流参考值
        g_Control.IqRef = pi_spd.Out;  // 设置q轴电流参考值
        g_Control.IdRef = pi_fw.Out;   // 设置d轴电流参考值
        
        // 重置FWLoopCount为下次分频周期
        g_Control.count.FWLoopCount = FW_LOOP;
    } else {
        // 否则减小FWLoopCount
        g_Control.count.FWLoopCount--;
    }
}

// 转速环控制
void SpeedLoop(float SpdRef, float SpdFbk)
{
    // 平滑速度反馈值，使用一阶惯性滤波
    // 0.99的平滑系数
    g_Control.FW.Speed = 0.99 * g_Control.FW.Speed + 0.01 * g_Control.m_speed.Speed; 

    // 每20次计算一次弱磁限度
    if (g_Control.count.SatCount == 1) {
        // 设置为最大速度-不弱
        //g_Control.FW.Speed = 0;
        
        // 如果速度超过1200，则进行弱磁限度计算
        if (ABS(g_Control.FW.Speed) > 1500) {
            // 根据速度计算电压上下限
            pi_spd.Umax = POWER / ABS(g_Control.FW.Speed);  // 最大电压
            pi_spd.Umin = -pi_spd.Umax;  // 最小电压
            pi_fw.Umin = -sqrt(IS_SQU - pi_spd.Umax * pi_spd.Umax);  // 弱磁限度
        } else {
            pi_spd.Umax = SPEED_MAX;  // 设置最大转速
            pi_spd.Umin = SPEED_MIN;  // 设置最小转速
            pi_fw.Umin = 0;           // 弱磁限度为0
        }

        // 重置SatCount计数器
        g_Control.count.SatCount = SAT_LOOP;
    } else {
        // 每次调用递减SatCount计数器
        g_Control.count.SatCount--;
    }

    // 转速环控制计算
    if (g_Control.count.SpeedLoopCount == 1) {  // 转速环分频

	pi_spd.Ref = -SpdRef;  // 设置转速参考值
        pi_spd.Fbk = SpdFbk * SPEEDDIR;  // 设置转速反馈值（方向调节）

        // 调用PI控制器进行转速环计算
        // PI_SPD(&pi_spd);  // 使用标准PI控制器
        PI_1(&pi_spd);  // 调用定制的PI控制器进行动态限幅

        // 重置SpeedLoopCount计数器
        g_Control.count.SpeedLoopCount = SPEED_LOOP;
    } else {
        // 每次调用递减SpeedLoopCount计数器
        g_Control.count.SpeedLoopCount--;
    }

    // 弱磁环控制
    FWLoop();  // 调用弱磁环函数
    
    g_Control.IqRef = pi_spd.Out;//10;//
    g_Control.IdRef = 0;
    // 电流环控制
    CurrentLoop(g_Control.IqRef, g_Control.IdRef, park1.Qs, park1.Ds);  // 调用电流环函数
}

inline void PressureIntUpdate(float ForceRef,float ForceFbk){
    float force_diff = 0;
    
    pi_preforce.Ref = ForceRef;
    pi_preforce.Fbk = ForceFbk * FORCE_PU;
    force_diff = ABS(pi_preforce.Ref - pi_preforce.Fbk);
    if(force_diff <= 5.0f){
        PI_1(&pi_preforce);
    }
    if (ForceRef <= 0.1f) {
        pi_preforce.i1 = 0.0;
        pi_preforce.ui = 0.0;
        pi_preforce.Out = 0.0f;
    }
}

// 位置插补函数
inline float PosInterpolation(float target_pos)
{
    // 如果目标位置改变，重新开始插补
    if (target_pos != g_PosInterp.target_pos) {
        g_PosInterp.target_pos = target_pos;
        g_PosInterp.start_pos = g_PosInterp.current_pos;
        g_PosInterp.interpolation_count = 0;
    }
    
    // 执行插补（POS_INTERP_STEPS 内完成）
    if (g_PosInterp.interpolation_count < POS_INTERP_STEPS) {
        g_PosInterp.interpolation_count++;
        g_PosInterp.current_pos = g_PosInterp.start_pos + 
            (g_PosInterp.target_pos - g_PosInterp.start_pos) * g_PosInterp.interpolation_count / (float)POS_INTERP_STEPS;
    } else {
        g_PosInterp.current_pos = g_PosInterp.target_pos;
    }
    
    return g_PosInterp.current_pos;
}


// 位置环控制
void PosLoop(float PosRef, float PosFbk)
{  

    // 当PosLoopCount为1时，进行位置环的计算
    if (g_Control.count.PosLoopCount == 1) {
        // 控制角速度（omiga）逐渐增加，频率范围为500-2Hz
        if (omiga <= 2 * PI)
            omiga = omiga + 2 * PI / 20;  // 频率增加速度为2*PI/20
        else
            omiga = omiga - 2 * PI;  // 一旦超出范围，重新设置为较小值
        
        //计算压力环前馈值
        PressureIntUpdate(g_Control.target_pressure,force_data);
	
        // 将位置参考值传给PI控制器
	PosRef = PosRef + pi_preforce.Out;  // 设置位置环的参考值	
	pi_pos.Ref = PosInterpolation(PosRef);
        pi_pos.Ref = PosRef ; 
	
        // 将当前位置反馈值传给PI控制器
        pi_pos.Fbk = PosFbk;  // 设置位置环的反馈值
        
        // 调用PI控制器进行计算
        // PI_POS(&pi_pos); // 使用标准的PI控制器
        PI_1(&pi_pos);  // 调用定制的PI控制器
	
        
    } 
    
    // 转速环：位置环的输出作为转速环的参考值
    g_Control.SpdRef = -pi_pos.Out;  // 设置转速参考值为位置环的输出
    
    // 当前速度反馈（SPEED_PU为单位化常数）
    g_Control.SpdFbk = -g_Control.m_speed.Speed * SPEED_PU;//改正负号 // 设置转速反馈
    
    // 调用转速环控制函数
    SpeedLoop(g_Control.SpdRef, g_Control.SpdFbk);  // 调用转速环控制
}


//压力环控制
void ForceLoop(float ForceRef,float ForceFbk){
    // 当ForceLoopCount为1时，进行压力环的计算
    if (g_Control.count.ForceLoopCount == 1) {
        // 控制角速度（omiga）逐渐增加，频率范围为500-2Hz
        if (omiga <= 2 * PI)
            omiga = omiga + 2 * PI / 20;  // 频率增加速度为2*PI/20
        else
            omiga = omiga - 2 * PI;  // 一旦超出范围，重新设置为较小值
        
        // 将压力参考值传给PI控制器
        pi_force.Ref = ForceRef;  // 设置压力环的参考值
        
        // 将当前压力反馈值传给PI控制器
        pi_force.Fbk = ForceFbk;  // 设置压力环的反馈值
        
        // 调用PI控制器进行计算
        // PI_POS(&pi_pos); // 使用标准的PI控制器
        PI_1(&pi_force);  // 调用定制的PI控制器
        g_Control.count.ForceLoopCount = FORCE_LOOP;    //T=1ms
    } else{
        g_Control.count.ForceLoopCount--;
    }
    
    // 转速环
    // 位置环的输出作为转速环的参考值
    g_Control.SpdRef = -SATS(pi_force.Out,-2000*SPEED_PU,2000*SPEED_PU);  // 设置转速参考值为位置环的输出
    
    // 当前速度反馈（SPEED_PU为单位化常数）
    g_Control.SpdFbk = -g_Control.m_speed.Speed * SPEED_PU;//改正负号 // 设置转速反馈
    
    // 调用转速环控制函数
    SpeedLoop(g_Control.SpdRef, g_Control.SpdFbk);  // 调用转速环控制
}

//位置环计算
void GetPosition(void){
    // 如果位置环计数器等于 1，则更新位置
    if (g_Control.count.PosLoopCount == 1) {
        // 获取新的位置角度
        g_Control.pos.PosNew = angle;

        // 计算当前位置与前一次位置的角度差
        g_Control.pos.PosDif = g_Control.pos.PosNew - g_Control.pos.PosOld;

        // 处理角度差的范围，使其保持在 [-PI, PI] 内
        if (g_Control.pos.PosDif > PI)
            g_Control.pos.PosDif = g_Control.pos.PosDif - 2 * PI; // 如果角度差超过 PI，则减去 2PI
        else if (g_Control.pos.PosDif < -PI)
            g_Control.pos.PosDif = g_Control.pos.PosDif + 2 * PI; // 如果角度差小于 -PI，则加上 2PI
        
        // 累加角度差，计算总位置变化量
        g_Control.pos.PosSum = g_Control.pos.PosDif + g_Control.pos.PosSum;

        // 更新旧的角度值，供下一次计算使用
        g_Control.pos.PosOld = g_Control.pos.PosNew;
	// 重新设定位置环计数器
        g_Control.count.PosLoopCount = POS_LOOP;
	
    }else{
        // 否则，递减计数器值
        g_Control.count.PosLoopCount--;
    }
} 


