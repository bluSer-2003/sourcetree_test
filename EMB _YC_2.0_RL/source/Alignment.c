#include <stdio.h>
#include <math.h>
#include "parameter.h"
#include "Alignment.h"
#include "global_struct.h"
#include "gtm.h"
#include "global.h"
#include "pi_controller.h"
#include "transformation.h"
#include "hv_svgen.h"

//初始定位数组、变量
double Alig_eangle_forward[POLES+1] = {0};    //正向旋转时每个极对的电角度
double Alig_eangle_reverse[POLES+1] = {0};    //反向旋转时每个极对的电角度
double Alig_eangle_all[2*(POLES+1)] = {0};    //正反转所有角度汇总
double Ali_angle_forward[POLES+1] = {0};      //记录正向旋转时的实际角度
double Ali_angle_reverse[POLES+1] = {0};      //记录反向旋转时的实际角度
int rotate_direction = 1;                     // 旋转方向，1为正，-1为反
int xb_forward = 0;                           // 正转极对计数
int xb_reverse = 0;                           // 反转极对计数
double rotate_start_angle = 0;

//电机换相时的计数
uint32_t rotate_timecount = 0;          //切换扇区旋转计时
int rotate_errflag = 0;                 //切换扇区旋转超时标志
int rotate_err_count = 0;               //旋转超时计数

// 容错相关变量
int disturb_count = 0;                  // 异常数据统计 
int ReAlignment = 0;                    //重定位标志位
int Alignment_outcome = 0;              //定位结果标志位
int Ali_Anglestatus_forward = 0;        //前向定位数据状态标志位
int Ali_Anglestatus_reverse = 0;        //反向定位数据状态标志位
int Ali_Anglestatus_all = 0;            //所有定位数据状态标志位

//外部变量
extern int TestFlag;                        //0:test    1:can
extern unsigned int error_state_code_0101;  //故障标志位
extern volatile double angle;               //tmr角度数据
extern int lswpre;                          //储存给定环路信息
extern uint8_t Paraflash_Complete_Flag;     //flash烧写完成标志位
extern uint8_t Paraflash_Request_Flag;      //flash烧写需求标志位

//默认已经进行过tmr状态位的判断，在tmr正常的情况下进行定位程序
void Alignment(void)
{
    int j = 0;
    double angle_forward = 0;
    double angle_reverse = 0;
    double angle_all = 0;
    double angle_diff = 0;

    // ----------------------------------------------------------------------
    //  判断是否处于定位阶段，并检查 xb 是否未达到极对数 POLES // Flag == 1 表示进入定位状态
    // ----------------------------------------------------------------------
    if (Aligment.Flag == 1 && rotate_direction == 1 && xb_forward != (POLES+1)) {       
        if (ALIG_LOOP == 0)                                   // ALIG_LOOP == 0 表示开环定位
            Alignment_open(xb_forward,Alig_eangle_forward);   // 调用开环定位函数
        else if (ALIG_LOOP == 1)                              // ALIG_LOOP == 1 表示闭环定位
            Aligment_close();                                 // 调用闭环定位函数
        else
            De_Mos();                                         // 错误状态下关闭功率管
    } 
    else if(Aligment.Flag == 1 && rotate_direction == -1 && xb_reverse != (POLES+1)){
        if (ALIG_LOOP == 0)                                   // ALIG_LOOP == 0 表示开环定位
            Alignment_open(xb_reverse,Alig_eangle_reverse);   // 调用开环定位函数
        else if (ALIG_LOOP == 1)                              // ALIG_LOOP == 1 表示闭环定位
            Aligment_close();                                 // 调用闭环定位函数
        else
            De_Mos();                                         // 错误状态下关闭功率管
    }
    // ---------------------------------------------------------------------------------
    //  判断是否处于旋转阶段，并检查 xb 是否未达到极对数 POLES以及电机旋转时间是否超限
    // ---------------------------------------------------------------------------------
    else if (Aligment.Flag == 2 && ((rotate_direction == 1 && xb_forward != (POLES+1)) ||
                                    (rotate_direction == -1 && xb_reverse != (POLES+1))) ){    // Flag == 2 表示进入旋转状态
        rotate_timecount++;
        //如果电机旋转时间已经超限但是仍有旋转趋势
        if( rotate_timecount >= Alignment_timelimit){
            rotate_errflag = 1;     //旋转状态标记为错误
            Aligment.Flag = 1;      // 进入定位状态
            ipark1.Angle = 0;       // 清除旋转角度
            rotate_timecount = 0;   // 清除计数值
        }else
            Aligment_rotate();      // 调用旋转函数
    } 

    // ---------------------------------------------------------------------------------
    //  达到极对数 处理定位数据和结果
    // ---------------------------------------------------------------------------------
    else { 
        //  检查每个极对方向的电角度是否有偏差较大的数据
//        Alig_eangle_forward[0] = 5.0322107;
//        Alig_eangle_forward[1] = 6.0333;
//        Alig_eangle_forward[2] = 4.444;
//        Alig_eangle_forward[3] = 0;
//        Alig_eangle_forward[4] = 0;
//        Alig_eangle_forward[5] = 5.0294105;
//        Alig_eangle_reverse[0] = 1.0000000;
//        Alig_eangle_reverse[1] = 5.9992808;
//        Alig_eangle_reverse[2] = 6.0355493;
//        Alig_eangle_reverse[3] = 1.0255177;
//        Alig_eangle_reverse[4] = 0.09745571;
//        Alig_eangle_reverse[5] = 0.0495914;
        
        //合并两个定位数组
        for(j = 0;j<POLES+1;j++){
            Alig_eangle_all[j] = Alig_eangle_forward[j];
        }
        for(j = 0;j<POLES+1;j++){
            Alig_eangle_all[j+POLES+1] = Alig_eangle_reverse[j];
        }

        //分别对正向定位数据，反向定位数据和数据之和进行处理
	    Ali_Anglestatus_forward = Similarity_anglecheck_cluster(AliFault_Tolerance,Alig_eangle_forward,POLES+1);
        Ali_Anglestatus_reverse = Similarity_anglecheck_cluster(AliFault_Tolerance,Alig_eangle_reverse,POLES+1);
        Ali_Anglestatus_all = Similarity_anglecheck_cluster(AliFault_Tolerance,Alig_eangle_all,2*(POLES+1));

        // 计算极对数方向的平均电角度
	    if(Ali_Anglestatus_forward != 2 || Ali_Anglestatus_reverse != 2 || Ali_Anglestatus_all != 2){
            //定位完成后关闭功率管
            De_Mos();        
            //分别计算有效定位角度以及正反转的有效极对数
            angle_forward = Ali_AngleCal(Alig_eangle_forward,POLES+1,1);
            angle_reverse = Ali_AngleCal(Alig_eangle_reverse,POLES+1,-1);
            angle_all = Ali_AngleCal(Alig_eangle_all,2*(POLES+1),2);
            //正反转数组均有有效数据
            if(Ali_Anglestatus_forward != 2 && Ali_Anglestatus_reverse != 2){
                angle_diff = ABS(angle_reverse - angle_forward);
                if(angle_diff > PI) 
                    angle_diff = 2*PI - angle_diff;
		        if(angle_diff < 0.1 ){         //0.1弧度对应5.7°
                    g_Control.Aligmenta.Ali_angle = (angle_forward + angle_reverse)/2;
                }else if(ABS(angle_reverse - angle_forward) >= 0.1 && ABS(angle_reverse - angle_forward) < 0.65){
                    g_Control.Aligmenta.Ali_angle = angle_reverse;     //取占空比更大的定向角度，减小负载的干扰
                }else {
                    // 正反转所得的角度差过大，选择可靠性更高的方向
                    if(g_Control.Aligmenta.Ali_reliability_forward > g_Control.Aligmenta.Ali_reliability_reverse) {
                        g_Control.Aligmenta.Ali_angle = angle_forward;
                    } else {
                        g_Control.Aligmenta.Ali_angle = angle_reverse;
                    }
                }
            }
            //只有一个方向的数据正常，取正常数据定为最终角度值
            else if(Ali_Anglestatus_forward != 2 || Ali_Anglestatus_reverse != 2){
                if(Ali_Anglestatus_forward != 2){
                    g_Control.Aligmenta.Ali_angle = angle_forward;
                }else if(Ali_Anglestatus_reverse != 2){
                    g_Control.Aligmenta.Ali_angle = angle_reverse;
                }
            }
            else if(Ali_Anglestatus_all != 2)
                g_Control.Aligmenta.Ali_angle = angle_all;

            error_state_code_0101 &= 0xFFFE;                   //将定位错误标志位复位
            lsw = lswpre;                                      //恢复环路设置
            if(TestFlag == 1){                                     //不处于调试模式时
                flag.AliCheck = 1;                                 //初始角度定位完成标志 需要烧写到FLAH中
            }else if(TestFlag == 0){                               //预留位，调试模式下需要在定位结束把数据烧写进去
                if(g_Control.iRunState == 4444){
                    Paraflash_Complete_Flag = 0;
                    Paraflash_Request_Flag = 1;
                    Para_FlashWrite();                             //电机停机状态下把新的定位数据烧写进去
                }
            }
        }
        //没有有效数据
        else if((Ali_Anglestatus_forward == 2 && Ali_Anglestatus_reverse == 2 && Ali_Anglestatus_all == 2) || ReAlignment >= Re_AlignmentCount){
            De_Mos();
            Alignment_outcome = 1;
            g_Control.Aligmenta.Ali_reliability_forward = 0;  // 无效标识
            g_Control.Aligmenta.Ali_reliability_reverse = 0;  // 无效标识
            g_Control.Aligmenta.Ali_angle = 0;
        }
        else if(ReAlignment < Re_AlignmentCount){  
            ReAligment_reset();    
            ReAlignment++;
        }
    }
}

//根据最后存储定位数据的数组计算定位数据
//其中可能存在问题的数据均为0
double Ali_AngleCal(double* Alig_angle_e,int array_length,int direction){
    int xbs = 0;
    double aglsum = 0;
    double delta = 0;
    double initial_valid_angle = 0;        //记录第一个有效数据（替代之前的Alig_angle_e[1])
    double angle_out = 0;
    int first_valid_index = -1;
    int valid_pole_count = 0;               // 有效极对数据数量（用于标记可靠性）
   
    //寻找第一个不为0的有效数据并统计有效数据量
    for(xbs = 0; xbs < array_length; xbs++){
        if(Alig_angle_e[xbs] != 0){
            if(first_valid_index == -1){
                first_valid_index = xbs;
                initial_valid_angle = Alig_angle_e[xbs];
            }
            valid_pole_count++;
        }
    }
    
    // 检查是否有足够有效数据
    if(valid_pole_count == 0){
        if(direction == 1 || direction == 2)
            g_Control.Aligmenta.Ali_reliability_forward = 0;
        else if(direction == -1|| direction == 2)
            g_Control.Aligmenta.Ali_reliability_reverse = 0;
        return 0.0; // 无有效数据
    }

    // 只有一个有效数据，直接返回
    if(valid_pole_count == 1){
        if(direction == 1)
            g_Control.Aligmenta.Ali_reliability_forward = 1;
        else if(direction == -1)
            g_Control.Aligmenta.Ali_reliability_reverse = 1;
        return initial_valid_angle; 
    }
   
    //计算差值之和
    for (xbs = 0; xbs < array_length; xbs++) {
        if(Alig_angle_e[xbs] != 0 && xbs != first_valid_index){
            delta = Alig_angle_e[xbs]-initial_valid_angle;
            // wrap 到 [-π, π)
            if (delta > PI) delta -= 2*PI;
            if (delta < -PI) delta += 2*PI;
            aglsum += delta;
        }
    }
    // 计算平均电角度
    angle_out = initial_valid_angle + aglsum / valid_pole_count;
    if(direction == 1)
        g_Control.Aligmenta.Ali_reliability_forward = valid_pole_count;
    else if(direction == -1)
        g_Control.Aligmenta.Ali_reliability_reverse = valid_pole_count;
    if (angle_out >= 2 * PI)
        angle_out -= 2 * PI;

    return angle_out;
}

//改进的相似性检测算法 - 基于最大聚类原则
int Similarity_anglecheck_cluster(double diff_limit, double* angle_array, int array_length) {
    int i = 0, j = 0;
    double angle_diff = 0;
    int cluster_count = 0;
    int max_cluster_size = 0;
    int max_cluster_index = -1;
    int valid_count = 0;
    int zero_count = 0;
  
    int cluster_labels[2*(POLES+1)];  // 聚类标签数组：记录每个点属于哪个聚类，-1表示未分类
    int cluster_sizes[2*(POLES+1)] = {0};// 聚类大小数组：记录每个聚类包含的点数
    int queue[2*(POLES+1)];
    int head,tail;
    int cur_size = 0;
    int u = 0;

    //数组初始化
    for(i = 0;i<2*(POLES+1);i++)
        cluster_labels[i] = -1;
	//为了避免对零值数据进行异常处理，对其进行额外的标签
    for (i = 0; i < array_length; i++) {
        if (angle_array[i] == 0.0) {
            cluster_labels[i] = -2;  // 标记为零值数据
            zero_count++;
        }
    }
    // 如果所有数据都是零，直接返回无效
    if (zero_count == array_length) {
        return 2; // 无任何有效数据
    }
    
    // 第一步：进行聚类分析,并基于“传递相似”做连通分量聚类
    for (i = 0; i < array_length; i++) {
        // 跳过零值数据和已分类的数据
        if (cluster_labels[i] == -2 || cluster_labels[i] != -1) 
            continue;
        
        head = 0;
        tail = 0;
        queue[tail++] = i;

        while (head < tail) {
            u = queue[head++];
            cur_size++;

            for (j = 0; j < array_length; j++) {
                if (cluster_labels[j] != -1) continue; // 只考虑未分类且非零的点
                if (j == u) continue;                  //跳过本身节点

                angle_diff = ABS(angle_array[u] - angle_array[j]);
                if (angle_diff > PI)
                    angle_diff = 2*PI - angle_diff;
                if (angle_diff <= diff_limit) {
                    if (tail >= 2*(POLES+1))
                        break;// 队列溢出处理
                    cluster_labels[j] = cluster_count;
                    queue[tail++] = j;
                }
            }
        }
        cluster_sizes[cluster_count] = cur_size;
        cluster_count++;
    }
    
    // 第二步：找出最大的聚类
    for (i = 0; i < cluster_count; i++) {
        if (cluster_sizes[i] > max_cluster_size) {
            max_cluster_size = cluster_sizes[i];
            max_cluster_index = i;
        }
    }
    
    // 第三步：只保留最大聚类中的数据，其他清零
    for (i = 0; i < array_length; i++) {
        if (cluster_labels[i] == max_cluster_index) {
            valid_count++; // 保留最大聚类中的点
        } else {
            angle_array[i] = 0.0; // 清零非最大聚类的点
        }
    }
    
    // 第四步：状态判断
    if (valid_count == array_length)
        return 0; // 全部数据都在最大聚类中
    else if (valid_count >= 2) 
        return 1; // 有有效数据但不是全部
    else
        return 2; // 无有效数据
}

void ReAligment_reset(){
    int i = 0;
    // 重置定位相关参数
    GTM0.DTM24CHCTRL2 = 0x88888800; 
    Aligment.Flag = 1;
    xb_forward = 0;
    xb_reverse = 0;
    rotate_direction = 1;

    //重置容错相关参数
    rotate_timecount = 0;
    rotate_errflag = 0;
    disturb_count = 0;
    
    // 重置角度数组
    for(i = 0;i<POLES+1;i++){
        Alig_eangle_forward[i] = 0;
        Alig_eangle_reverse[i] = 0;
        Ali_angle_forward[i] = 0;
        Ali_angle_reverse[i] = 0;
    }
    for(i = 0 ;i < 2*(POLES+1);i++){
        Alig_eangle_all[i] = 0;
    }
    
    // 重置旋转角度
    ipark1.Angle = 0;
    ipark1.Sine = 0;
    ipark1.Cose = 1;
    
    // 重置控制状态
    g_Control.iRunState = 100;
    g_Control.Dutycycle_A = -1;
    g_Control.Dutycycle_B = -1;
    g_Control.Dutycycle_C = -1;
}

//// 初始角度定位 - 旋转
//void Aligment_rotate(void)
//{
//    double agldelta;                      // 定义角度差变量
    
//    // 设置 d-q 坐标系中的电压指令值
//    ipark1.Ds = 0;                        // d 轴电压设为 0
//    ipark1.Qs = 0.15* rotate_direction;   // q 轴电压设为 0.15，提供旋转力矩

//    // 增加旋转角度,每次增加一个固定的小角度
//    // 不再从 0 扫描
//    ipark1.Angle += 0.005 * rotate_direction;

//    // 仅用于 sin/cos 的 wrap
//    if (ipark1.Angle > 2*PI)        ipark1.Angle -= 2*PI;
//    if (ipark1.Angle < -2 * PI)     ipark1.Angle += 2*PI;

//    // 计算当前角度对应的正弦和余弦值
//    ipark1.Sine = sin(ipark1.Angle);    // 当前角度的正弦值
//    ipark1.Cose = cos(ipark1.Angle);    // 当前角度的余弦值

//    // 执行反 d-q 坐标变换（IPARK 宏定义需外部实现）
//    IPARK_MACRO(ipark1);

//    // ----------------------------------------------------------------------
//    //  将反 d-q 坐标变换的输出连接到 SVPWM（空间矢量脉宽调制）的输入
//    // ----------------------------------------------------------------------
//    svgen1.Ualpha = ipark1.Alpha;       // d-q 转换后的 α 轴值
//    svgen1.Ubeta  = ipark1.Beta;        // d-q 转换后的 β 轴值
//    svgentest.Ualpha = ipark1.Alpha;    // 用于测试的 α 轴值
//    svgentest.Ubeta  = ipark1.Beta;     // 用于测试的 β 轴值
//    svpwm(&svgen1);  // 调用空间矢量脉宽调制函数，计算占空比

//    // 将计算出的占空比赋值给对应的三相 PWM 信号
//    g_Control.Dutycycle_A = svgen1.Ta;  // 相 A 的占空比
//    g_Control.Dutycycle_B = svgen1.Tb;  // 相 B 的占空比
//    g_Control.Dutycycle_C = svgen1.Tc;  // 相 C 的占空比

//    // 计算当前电角度与历史角度的差值
//    agldelta = angle - rotate_start_angle;
//    if (agldelta > PI)  agldelta -= 2*PI;
//    if (agldelta < -PI) agldelta += 2*PI;

//    if (ABS(agldelta) >= (2*PI/POLES)) {
//        Aligment.Flag = 1;
//        rotate_timecount = 0;
//    }
//}

// 初始角度定位 - 旋转
void Aligment_rotate(void)
{
    double agldelta;  // 定义角度差变量
    
    // 设置 d-q 坐标系中的电压指令值
    ipark1.Ds = 0;     // d 轴电压设为 0
    ipark1.Qs = 0.25* rotate_direction;   // q 轴电压设为 0.15，提供旋转力矩

    // 增加旋转角度
    ipark1.Angle += 0.01 * rotate_direction;
    if (ipark1.Angle > (2 * PI)) {        // 防止角度超出 2π
        ipark1.Angle = ipark1.Angle - 2 * PI;  // 限制在 0 到 2π 之间
    }

    // 计算当前角度对应的正弦和余弦值
    ipark1.Sine = sin(ipark1.Angle);  // 当前角度的正弦值
    ipark1.Cose = cos(ipark1.Angle);  // 当前角度的余弦值

    // 执行反 d-q 坐标变换（IPARK 宏定义需外部实现）
    IPARK_MACRO(ipark1);

    // ----------------------------------------------------------------------
    //  将反 d-q 坐标变换的输出连接到 SVPWM（空间矢量脉宽调制）的输入
    // ----------------------------------------------------------------------
    svgen1.Ualpha = ipark1.Alpha;  // d-q 转换后的 α 轴值
    svgen1.Ubeta  = ipark1.Beta;   // d-q 转换后的 β 轴值
    svgentest.Ualpha = ipark1.Alpha;  // 用于测试的 α 轴值
    svgentest.Ubeta  = ipark1.Beta;   // 用于测试的 β 轴值
    svpwm(&svgen1);  // 调用空间矢量脉宽调制函数，计算占空比

    // 将计算出的占空比赋值给对应的三相 PWM 信号
    g_Control.Dutycycle_A = svgen1.Ta;  // 相 A 的占空比
    g_Control.Dutycycle_B = svgen1.Tb;  // 相 B 的占空比
    g_Control.Dutycycle_C = svgen1.Tc;  // 相 C 的占空比

    // 计算当前电角度与历史角度的差值
    agldelta = Aligment.anglepre - angle;  // 目标角度和当前角度的差值
    if (agldelta > PI) {                   // 如果角度差超过 π
        agldelta = agldelta - 2 * PI;      // 调整为 -π 到 π 之间
    }
    if (agldelta < -PI) {                  // 如果角度差小于 -π
        agldelta = agldelta + 2 * PI;      // 调整为 -π 到 π 之间
    }

    // 判断角度差是否超过限制范围
    if (ABS(agldelta) > (2 * PI / POLES - 0.1)) {  
        Aligment.Flag = 1;  // 进入定位状态
        ipark1.Angle = 0;   // 清除旋转角度
        rotate_timecount = 0;    // 清除计数值
    }
}

// 初始角度定位 - 开环定位
void Alignment_open(int xb,double* Alig_angle_e) 
{
    // 设置初始的 PWM 占空比，用于开环定位
    if(rotate_direction == 1){
        g_Control.Dutycycle_A = -0.6;   // 相 A 的占空比
    }else if(rotate_direction == -1){
        g_Control.Dutycycle_A = -0.5;   // 反向给更大的占空比（用于对比）
    }
    g_Control.Dutycycle_B = -1;     // 相 B 的占空比
    g_Control.Dutycycle_C = -1;     // 相 C 的占空比

    // 阶段 1：定位稳定阶段，计数器增加到 30000
    if (Aligment.count < 30000) {  
        Aligment.count++; // 增加计数器，进入稳定阶段
    }
    // 阶段 2：稳定阶段结束，记录电角度
    else if (Aligment.count == 30000) {
        Aligment.angle = g_Control.angle_e; // 记录当前电角度
        Aligment.count++;                   // 进入下一阶段
    }
    // 阶段 3：电角度的平滑过渡
    else if (Aligment.count > 30000 && Aligment.count < 60000) {
        // 平滑更新电角度，0.001 为新值权重，0.999 为旧值权重
        Aligment.angle = 0.001 * g_Control.angle_e + 0.999 * Aligment.angle; 
        Aligment.count++; // 增加计数器
    }
    // 阶段 4：记录角度并结束定位
    else {
        Alig_angle_e[xb] = Aligment.angle;  // 记录平滑后的电角度
        if(rotate_errflag == 1){
            Alig_angle_e[xb] = 0;           //当前极对旋转超时，数据不可信
            rotate_err_count++;
            rotate_errflag = 0;
        }
        if(rotate_direction == 1){
            xb_forward++; 
            if (xb_forward >= POLES+1) {
                rotate_direction = -1;
            }
        }else if(rotate_direction == -1){
            xb_reverse++;   
        }
        Aligment.anglepre = angle;          // 保存当前角度作为历史值
        Aligment.Flag = 2;                  // 标志位设为 2，表示定位完成，进入旋转阶段
        Aligment.count = 0;                 // 计数器复位，准备下一次操作
    }

    // 更新控制结构体中的电角度值，用于监控
    g_Control.Aligmenta.Ali_angle = g_Control.angle_e;
    //rotate_start_angle = angle;     // 记录旋转起始真实角度
    //ipark1.Angle = angle;                    // ★关键：Park 角度对齐真实角度

}

//初始角度定位-闭环定位
void Aligment_close(void)
{
    // 将 Clarke 变换输入的 A 相电流和 B 相电流反转
    clarke1.As = -clarke1.As; // 反转 A 相电流
    clarke1.Bs = -clarke1.Bs; // 反转 B 相电流

    // 进行 Clarke 变换，将三相静止坐标系转换为两相静止坐标系
    CLARKE_MACRO(clarke1);

    // 设置 Park 变换的角度为零（相当于坐标轴对齐），a 轴指向 alpha 轴
    park1.Sine = 0;        // 正弦值为 0
    park1.Cose = 1;        // 余弦值为 1
    PARK_MACRO(park1);

    // 更新控制变量的计数值
    g_Control.Aligmenta.Ali_count++;
    // 根据 Ali_count 计算 Id_count 的值
    g_Control.Aligmenta.Id_count = g_Control.Aligmenta.Ali_count / 100;
    if (g_Control.Aligmenta.Id_count > 0 && g_Control.Aligmenta.Id_Cal < 1)
    {
        // 如果 Id_count > 0 并且 Id_Cal 小于 1，则进行增量更新
        g_Control.Aligmenta.Ali_count = 0;         // 重置 Ali_count
        g_Control.Aligmenta.Id_Cal += 0.05;       // 每次递增 0.05
    }

    // 设置电流环 PI 控制器的参考值和反馈值
    pi_iq.Ref = 0;          // Q 轴电流参考值
    pi_iq.Fbk = park1.Qs;   // Q 轴电流反馈值
    pi_id.Ref = 2;          // D 轴电流参考值
    pi_id.Fbk = park1.Ds;   // D 轴电流反馈值

    // 调用 PI 控制器宏定义
    PI_MACRO(pi_iq);
    PI_MACRO(pi_id);

    // 进行逆 Park 变换，将控制输出值从旋转坐标系转换回静止坐标系
    ipark1.Ds   = pi_id.Out;  // D 轴电流控制输出
    ipark1.Qs   = pi_iq.Out;  // Q 轴电流控制输出
    ipark1.Sine = park1.Sine; // 正弦值
    ipark1.Cose = park1.Cose; // 余弦值
    IPARK_MACRO(ipark1);

    // 空间矢量生成，将 Alpha-Beta 坐标系中的电压值转换为三相占空比
    svgen1.Ualpha = ipark1.Alpha; // Alpha 轴电压
    svgen1.Ubeta  = ipark1.Beta;  // Beta 轴电压
    SVGENDQ_MACRO(svgen1);

    // 计算三相占空比并归一化
    g_Control.Dutycycle_A = svgen1.Ta / IQ_MAX; // A 相占空比
    g_Control.Dutycycle_B = svgen1.Tb / IQ_MAX; // B 相占空比
    g_Control.Dutycycle_C = svgen1.Tc / IQ_MAX; // C 相占空比
}

//初始定位检查
int AliCheck(double angle,double Aliangle)
{
    double error = Aliangle - angle;
    
    if(error<0)
        error = -error;
    if(error>PI)
        error = 2*PI - error;
	
    if(error>=0.5)
        return 0;  //偏差过大，定位有问题
    else
        return 1;  //定位正常
}