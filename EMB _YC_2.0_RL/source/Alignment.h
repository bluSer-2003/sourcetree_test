#ifndef __ALIGNMENT_H__
#define __ALIGNMENT_H__

//五对极旋转72° 按照0.005递增量 计数值为251 这里设置为2倍
#define Alignment_timelimit 1500
#define Re_AlignmentCount 2
#define PARTIAL_ALIGN_OUTCOME 2         // 部分定位结果标识（区别于0-成功、1-失败）
#define AliFault_Tolerance 0.65

/* ---------------------------------------------------
 * Function prototype
 * --------------------------------------------------- */
//初始定位
void Alignment(void);
void Alignment_open(int xb,double* Alig_angle_e) ;
void Aligment_rotate(void);
void Aligment_close(void);
void ReAligment_reset();
double Ali_AngleCal(double* Alig_angle_e,int array_length,int direction);
int Similarity_anglecheck_cluster(double diff_limit, double* angle_array, int array_length);
int AliCheck(double angle,double Aliangle);

#endif