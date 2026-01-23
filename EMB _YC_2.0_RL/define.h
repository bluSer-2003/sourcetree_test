#ifndef __DEFINE_H__
#define __DEFINE_H__
#define SAT(x, lower, upper) ((x) < (lower) ? (lower) : ((x) > (upper) ? (upper) : (x)))
#define ABS(x) ((x) < 0 ? -(x) : (x))
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))

typedef struct
{
    int   iRunState;                 //???
    float ControlBoardPowerDC;
    float Vdc;
    float Vdcmax;

    struct{
        unsigned int  Ali_Flag_t;
        unsigned int  Ali_Flag;    //
        unsigned long Ali_count;   //
        float         Ali_angle;
        unsigned int  t_ms;//
	unsigned int  Id_count;//????
        float Id_Cal;//d??????
        float Id_Ref;//d???
    }Aligmenta;

    struct{
        float cur_A;
        float cur_B;
        float cur_C;
    }m_Current;

    struct{
        int   Flag;
        float Speedmax;
        float Speedmin;
	float Speed;
	float Vdcfbk;
	float Vdcfbkfli;
    }FW;
    
    struct{
        float I_A;
        float I_B;
        float I_C;
        float I_Max;
        float I_Max_Keep;
    }r_Current;

    struct{
        double oldtime_angle_e;
        double newtime_angle_e;
        double differ_angle_e;
	double differ_angle_e_pre;
        float  Speed;
        float  Speed_pre;
        float  SpeedRpm;//??????им????
        float  SpeedMax;
        float  Speed_ref;//??????им????
    }m_speed;

    
    double angle_e;
    unsigned int Speedloopcount;
    float Dutycycle_A;
    float Dutycycle_B;
    float Dutycycle_C;
}ControlManage_t;


typedef struct
{
    int current_level1;
    int current_level2;
    int current_level3;
}alarmcount;

#endif