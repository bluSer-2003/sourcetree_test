#ifndef GLOBAL_STRUCT_H
#define GLOBAL_STRUCT_H

// ControlManage_t 结构体定义
typedef struct
{
    int   iRunState;                 // 运行状态
    float ControlBoardPowerDC;
    float Vdc;
    float Vdcmax;
    float Vdcmin;

    struct{
        unsigned long Ali_count;   // ??
        float Ali_angle;
        unsigned int Id_count;     // ??
        float Id_Cal;              // d轴电流值??
        float Id_Ref;              // d轴电流参考值
    }Aligmenta;

    struct{
        float cur_A;
        float cur_B;
        float cur_C;
    }m_Current;

    struct{
        int Flag;
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
        int SpeedLoopCount;
        int FWLoopCount;
        int PosLoopCount;
        int SatCount;
	int EPSTasLoopCount;
    }count;
    
    struct{
        double oldtime_angle_e;
        double newtime_angle_e;
        double differ_angle_e;
        double differ_angle_e_pre; // previous angle delta
        float Speed;               // real speed (rpm)
        float SpeedPre;
        float Speed_ctl;           // speed for controller
        float SpeedMax;            // max speed
        float Speed_ref;           // speed reference
    }m_speed;
    
    struct{
        double PosOld;
        double PosNew;
        double PosDif;
        double PosSum;
    }pos;
    
    struct{
	float CurLevel1;
	float CurLevel2;
	float CurLevel3;
	float VoltLevel1;
	float VoltLevel2;
    }prot;
    
    struct{
	float TAS_angle_comp;
	float TAS_angle;  
    }TAS;
    
    double angle_e;
    float Dutycycle_A;
    float Dutycycle_B;
    float Dutycycle_C;
    float IqRef;
    float IdRef;
    float IqFbk;
    float IdFbk;
    float SpdRef;
    float SpdFbk;
    float POSRefDeg;
    float PosRef;
    float PosFbk;
} ControlManage_t;

// SpeedCal 结构体定义
typedef struct{
    float dif_angle;
    float angle_now;
    float angle_pre;
    float realspeed;
    float dif_angle_pre;
} SpeedCal;

// Aligment_d 结构体定义
typedef struct{
    double anglepre;
    double angle;
    float Id_Ref;  // 闭环d给定
    float Duty;    // 开环占空比给定
    int Flag;      // 标志位
    long count;    // 时间计算
} Aligment_d;

// alarmcount 结构体定义
typedef struct
{
    int current_level1;
    int current_level2;
    int current_level3;
    int Lock_rotor;
    int TAS_break;
    int TAS_signal_abnormal;
    int ADC12_outrange;
    int voltage_low;
    int spd_outrange;
    int temp_High;
} alarmcount;

typedef struct 
{
    int speed_norm;
    int temp_norm;
    int posRef_norm;
    int Lock_rotor_norm;
}alarmrecovercount;


typedef struct {  
    float  Ref;             // Input: reference set-point
    float  Fbk;             // Input: feedback
    float  Out;             // Output: controller output
    float  Kp;              // Parameter: proportional loop gain
    float  Ki;              // Parameter: integral gain
    float  Umax;            // Parameter: upper saturation limit
    float  Umin;            // Parameter: lower saturation limit
    float  up;              // Data: proportional term
    double ui;              // Data: integral term
    double i1;              // Data: integral term
    unsigned int  index;
} PI_CONTROLLER;


typedef struct{
   int AliCheck;  //定位检查标志位
}FLAG;

typedef struct{
		float kp;
		float ki;
	}flashpi;

typedef struct{
	flashpi cur;
	flashpi spd;
	flashpi pos;
	flashpi weak;
	float Ov;
	float Oi;
	float Max;
	float CurMax;
	float fwCurMax;
	float SpeedMax;
	float vehspd;
	int flag;
	unsigned short dRef;//d???
    	unsigned short qRef;//q???
    	unsigned long spdRef;//????
	unsigned short posRef;
    	float dRef_float;//d???
    	float qRef_float;//q???
    	float spdRef_float;//????
	float posRef_float;
	unsigned long runState;
	unsigned long statusSym;
	
}CANflash;

typedef struct{
	unsigned long id;
	unsigned short format;
	unsigned short type;
	unsigned short len;
	unsigned short data[8];
}exCAN_MSG;

typedef struct{
	unsigned short ControlRequest;
	float AngleSpd;
	float Angle;
	unsigned short RollCount;
	unsigned short SumCheck;
	unsigned short TestObc;
	unsigned short Status;
	unsigned short AngleFault;
	unsigned short FaultRank;
	unsigned short StateFlow;
	unsigned short error1;
	unsigned short error2;
	unsigned short error3;
	unsigned short supply;
	unsigned short SoftVersion;
	unsigned short HardVersion;
	int flag;
	

}JWDcan;
/*-----------------------------------------------------------------------------
Default initalisation values for the PI_GRANDO objects
-----------------------------------------------------------------------------*/                     

#define PI_CONTROLLER_DEFAULTS {                   \
                           0,                      \
                           0,                      \
                           0,                      \
                           0,                      \
                           0,                      \
                           0,                      \
                           0,                      \
                           0,                      \
                           0,                      \
                           0.0,                    \
			   0,                      \
                          }

//ControlManage_t g_Control;  //状态
//alarmcount      alarm;      //报警
//SpeedCal        Speed1;     //速度
//Aligment_d Aligment;

// 位置插补结构体定义
typedef struct{
    float target_pos;       // 目标位置
    float current_pos;      // 当前插补位置
    float start_pos;        // 插补起始位置
    int interpolation_count; // 插补计数器（0-10）
} PosInterpolation_t;

//位置插补默认初始化值
#define POS_INTERPOLATION_DEFAULTS { \
    0.0,    /* target_pos */ \
    0.0,    /* current_pos */ \
    0.0,    /* start_pos */ \
    0       /* interpolation_count */ \
}

// 声明全局变量
extern ControlManage_t g_Control;
extern SpeedCal Speed1;
extern Aligment_d Aligment;
extern alarmcount alarm;
extern alarmrecovercount alarm_recover;
extern PI_CONTROLLER pi_pos ;
extern PI_CONTROLLER pi_fw ;
extern PI_CONTROLLER pi_spd;
extern PI_CONTROLLER pi_id  ;
extern PI_CONTROLLER pi_iq  ;
extern FLAG flag;
extern CANflash g_CANflash  ;
extern exCAN_MSG exmsg;
extern JWDcan CAN2;
extern PosInterpolation_t g_PosInterp;  // 位置插补全局变量

#endif  // GLOBAL_STRUCT_H