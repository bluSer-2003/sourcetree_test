#ifndef SMITH_PREDICTOR_H
#define SMITH_PREDICTOR_H

/**
 * Smith预估器结构体
 * 用于补偿夹紧力反馈中的滞后
 */
typedef struct {
    float b[4];    // 分子系数: b0, b1, b2, b3
    float a[4];    // 分母系数: a0, a1, a2, a3 (a0=1)
    float state[6]; // 状态变量: [x[k-1], x[k-2], x[k-3], y[k-1], y[k-2], y[k-3]]
} SmithPredictor;

/**
 * 初始化Smith预估器
 * @param sp          Smith预估器结构体指针
 * @param τ           滞后时间 (秒)
 * @param T           采样周期 (秒)
 */
void smith_predictor_init(SmithPredictor *sp, float τ, float T);

/**
 * 应用Smith预估器进行预测
 * @param sp          Smith预估器结构体指针
 * @param feedback    当前夹紧力反馈值 (含滞后)
 * @return            预测的无滞后夹紧力
 */
float smith_predictor_predict(SmithPredictor *sp, float feedback);

#endif // SMITH_PREDICTOR_H