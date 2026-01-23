#include <stdio.h>
#include <math.h>
#include "smith_predictor.h"

// 3阶Pade近似系数计算 (z变换)
void smith_predictor_init(SmithPredictor *sp, float τ, float T) {
    int i = 0;
    // 计算系数 (使用3阶Pade近似 + z变换)
    float c = 2.0f / T;
    float c2 = c * c;
    float c3 = c * c * c;
    
    // 连续域分子系数 (num)
    float num0 = τ * τ * τ;
    float num1 = 12.0f * τ * τ;
    float num2 = 60.0f * τ;
    float num3 = 120.0f;
    
    // 连续域分母系数 (den)
    float den0 = -τ * τ * τ;
    float den1 = 12.0f * τ * τ;
    float den2 = -60.0f * τ;
    float den3 = 120.0f;
    
    // 计算离散域分子系数 (num_z)
    float num_z3 = num0 * c3 + num1 * c2 + num2 * c + num3;
    float num_z2 = -3.0f * num0 * c3 + num1 * c2 - num2 * c + num3;
    float num_z1 = 3.0f * num0 * c3 + num1 * c2 - num2 * c + num3;
    float num_z0 = -num0 * c3 + num1 * c2 - num2 * c + num3;
    
    // 计算离散域分母系数 (den_z)
    float den_z3 = den0 * c3 + den1 * c2 + den2 * c + den3;
    float den_z2 = -3.0f * den0 * c3 + den1 * c2 - den2 * c + den3;
    float den_z1 = 3.0f * den0 * c3 + den1 * c2 - den2 * c + den3;
    float den_z0 = -den0 * c3 + den1 * c2 - den2 * c + den3;
    
    // 归一化分母 (使a0=1)
    float inv_den0 = 1.0f / den_z3;
    
    // 设置系数 (b0, b1, b2, b3)
    sp->b[0] = num_z3 * inv_den0;
    sp->b[1] = num_z2 * inv_den0;
    sp->b[2] = num_z1 * inv_den0;
    sp->b[3] = num_z0 * inv_den0;
    
    // 设置系数 (a0=1, a1, a2, a3)
    sp->a[0] = 1.0f;
    sp->a[1] = den_z2 * inv_den0;
    sp->a[2] = den_z1 * inv_den0;
    sp->a[3] = den_z0 * inv_den0;
    
    // 初始化状态 (全为0)
    for (i = 0; i < 6; i++) {
        sp->state[i] = 0.0f;
    }
}

float smith_predictor_predict(SmithPredictor *sp, float feedback) {
    float y = 0;
    // 1. 更新输入状态: [x[k-1], x[k-2], x[k-3]]
    sp->state[2] = sp->state[1];  // x[k-3] = x[k-2]
    sp->state[1] = sp->state[0];  // x[k-2] = x[k-1]
    sp->state[0] = feedback;      // x[k-1] = current input
    
    // 2. 计算预测值: y[k] = b0*x[k] + b1*x[k-1] + b2*x[k-2] + b3*x[k-3] - a1*y[k-1] - a2*y[k-2] - a3*y[k-3]
    y = sp->b[0] * feedback +
              sp->b[1] * sp->state[0] +
              sp->b[2] * sp->state[1] +
              sp->b[3] * sp->state[2] -
              sp->a[1] * sp->state[3] -
              sp->a[2] * sp->state[4] -
              sp->a[3] * sp->state[5];
    
    // 3. 更新输出状态: [y[k-1], y[k-2], y[k-3]]
    sp->state[5] = sp->state[4];  // y[k-3] = y[k-2]
    sp->state[4] = sp->state[3];  // y[k-2] = y[k-1]
    sp->state[3] = y;             // y[k-1] = current output
    
    return y;
}