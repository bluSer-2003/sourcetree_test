#ifndef __FLITER_H__
#define __FLITER_H__
typedef int bool;

// 定义二阶滤波器系数 600HZ
#define B0   0.00782
#define B1   0.01564
#define B2   0.00782
#define A1  -1.73472
#define A2   0.76601
/*
// 定义二阶滤波器系数 2000HZ
#define B0   0.06745527
#define B1   0.13491055
#define B2   0.06745527
#define A1  -1.1429805
#define A2   0.4128016


// 定义二阶滤波器系数 3000HZ
#define B0   0.13110644
#define B1   0.26221288
#define B2   0.13110644
#define A1  -0.74778918
#define A2   0.27221494
*/

// 定义一阶滤波器系数 600HZ
#define C0   0.1586
#define C1   0.8414

//各种PI
#define PI   3.14159265
#define HALF_PI 1.5707963
#define OH_PI   4.712389
#define TWO_PI  6.2831853

//阈值
#define THRESHOLD_LOW 0.3
#define THRESHOLD_HIGH 6
#define TOLERANCE 0.01  // 误差范围
#define TOLERANCE_16 150  // 误差范围

// 二阶低通滤波器状态变量
double x_history[2] = {0.0, 0.0}; // 输入历史
double y_history[2] = {0.0, 0.0}; // 输出历史
double ref_pre;
double output_pre;
int fli_flag = 0;
int flag_1   = 0;



//二阶角度偏差滤波器-浮点
double angle_precess_2order(double delta,double angle_ref){
    static double delta_output;
    double output;
    
    //到固定位置就初始化-Z脉冲
    if(ABS(angle_ref-1)< TOLERANCE||ABS(angle_ref-4.1415926)< TOLERANCE)
       flag_1 = 0;
    
    //起始初始化
    if(fli_flag==0){
        x_history[0] = delta;
	x_history[1] = delta;
	y_history[0] = delta;
	y_history[1] = delta;
	fli_flag = 1;
    }
    //固定位置初始化
    if(flag_1==0){
	ref_pre = angle_ref;
	flag_1 = 1;
    }
    
    //计算输出-二阶滤波
    delta_output = B0 * delta + B1 * x_history[0] + B2 * x_history[1]- A1 * y_history[0] - A2 * y_history[1];
    //计算输出-一阶滤波
    //delta_output = C0 * delta + C1 * y_history[0];
    
    // 更新历史输入和输出
    x_history[1] = x_history[0];
    x_history[0] = delta;

    y_history[1] = y_history[0];
    y_history[0] = delta_output;
    
    //output = angle_ref + delta_output;
    ref_pre += delta_output;
    if(ref_pre>TWO_PI)
        ref_pre -= TWO_PI;
    if(ref_pre<0)
        ref_pre += TWO_PI;
	
    output = ref_pre;  
    return output;
    //return delta_output;
}



// 修正角度计算输出
double  adjust_if_needed(double input, double x_hist_0, double x_hist_1, double y_hist_0, double y_hist_1) {
    
    double output;
    // 如果相差过大就补偿角度
    if(((input-y_hist_0)>PI||(input-y_hist_0)<-PI)||((input-y_hist_1)>PI||(input-y_hist_1)<-PI)) {  
        // 对小于 THRESHOLD_LOW 的数加 2*PI
        if (input > THRESHOLD_HIGH) 
            input -= TWO_PI;
        if (x_hist_0 > THRESHOLD_HIGH) 
            x_hist_0 -= TWO_PI;
        if (x_hist_1 > THRESHOLD_HIGH)
            x_hist_1 -= TWO_PI;
        if (y_hist_0 > THRESHOLD_HIGH)
            y_hist_0 -= TWO_PI;
        if (y_hist_1 > THRESHOLD_HIGH)
            y_hist_1 -= TWO_PI;
    }
    output = B0 * input + B1 * x_hist_0 + B2 * x_hist_1
                    - A1 * y_hist_0 - A2 * y_hist_1;
    // 将输出限制在 [0, 2PI] 范围内
    if(output>TWO_PI)
        output -= TWO_PI;
    if(output<0)
        output += TWO_PI;
	
    return output;
}

// 滤波器函数：处理编码器角度滤波，防止角度跳变对滤波器的影响
double lowpass_filter_angle(double input) {
    double output;
    //初始化
    if(flag_1==0){
        x_history[0] = input;
	x_history[1] = input;
	y_history[0] = input;
	y_history[1] = input;
	flag_1 = 1;
    }
    
    // 处理输入角度的跳变，避免突变
    output = adjust_if_needed(input, x_history[0], x_history[1], y_history[0], y_history[1]);
    
    // 更新历史输入和输出
    x_history[1] = x_history[0];
    x_history[0] = input;

    y_history[1] = y_history[0];
    y_history[0] = output;

    return output;
}

// 滤波器函数：二阶滤波
float filter_2nd_order(float input) {
    float output;
    //初始化
    if(flag_1==0){
        x_history[0] = input;
	x_history[1] = input;
	y_history[0] = input;
	y_history[1] = input;
	flag_1 = 1;
    }
    
    // 处理输入角度的跳变，避免突变
    output =  B0 * input + B1 * x_history[0] + B2 * x_history[1]
              - A1 * y_history[0] - A2 * y_history[1];
    
    // 更新历史输入和输出
    x_history[1] = x_history[0];
    x_history[0] = input;

    y_history[1] = y_history[0];
    y_history[0] = output;

    return output;
}

// 滤波器函数：三阶滤波
//三阶IIR滤波器系数
#define N 3  // 三阶滤波器
float B_3[N+1] = {0.00069935f, 0.00209805f, 0.00209805f, 0.00069935f};
float A_3[N+1] = {1.0f       ,-2.62355181f, 2.31468258f,-0.68553598f};

// 输入和输出历史值 (使用float类型)
float x_3order[N+1] = {0};  // 输入历史
float y_3order[N+1] = {0};  // 输出历史

float filter_3nd_order(float input) {
    float output = 0.0f;
    int i=N;

    // 滤波器初始化
    //for(i = N; i >= 0; i--) {
      //  x_3order[i] = input;
     //   y_3order[i] = input;
   // }
    
    // 更新输入历史
    for(i = N; i > 0; i--) {
        x_3order[i] = x_3order[i-1];
        y_3order[i] = y_3order[i-1];
    }
    x_3order[0] = input;

    // 计算滤波器输出
    for(i = 0;i <= N; i++) {
        output += B_3[i] * x_3order[i];
        if (i > 0) {
            output -= A_3[i] * y_3order[i];
        }
    }

    // 更新输出历史
    y_3order[0] = output;

    return output;
}
#endif // __FLITER_H__