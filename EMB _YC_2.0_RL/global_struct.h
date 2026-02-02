#ifndef GLOBAL_STRUCT_H
#define GLOBAL_STRUCT_H

#include "transformation.h"
#include "hv_svgen.h"
#include "pi_controller.h"
#include "struct.h"

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

typedef struct {
    uint8 BrkForceCmdActive;
    float BrkForceCmd;
    uint8 BrkForceCmdGrdMaxLmtA;
    uint8 BrkForceCmdGrdMinLmtA;
    float BrkForceCmdGrdLmt;
    uint8 BrkForceRelPosReq;
    uint8 BrkForceDiffAllow;
    uint8 ABSActive;
    uint8 ParkRequest;
}fromBCU_YC;

typedef struct {
    uint8 BrkForceVld;
    uint8 BrkForceActive;
    float BrkForceActual;
    float BrkForceLmt;
    uint8 BrkForceGrdActive;
    uint8 BrkForceGrdLmtMax;
    uint8 BrkForceGrdLmtMin;
    uint8 BrkForceRelPos;
    uint8 ParkBrkState;
    uint8 ServiceBrkFailState;
    uint8 PrakBrkFailState;
    uint8 MotorControlState;
    uint8 ParkValveControlState;
    float WheelSpeed;
    uint8 WheelSpeedDir;
    uint8 WheelSpeedVld;
    uint16 WheelPulseCounter;
    uint8 WheelPulseReset;
    float WheelTimestamp;
    uint8 WheelTimestampRC;
    uint8 Comm_Avaliable_BCU_M;
    uint8 Comm_Avaliable_BCU_R;
    uint8 AliveRollingCount;
    uint16 Checksum;
}toBCU_YC;

// ControlManage_t 结构体定义
typedef struct
{
    int   iRunState;                 // 运行状态
    float ControlBoardPowerDC;
    float Vdc;
    float Vdcmax;
    float Vdcmin;

    struct{
        unsigned long Ali_count;   
        float Ali_angle;
        unsigned int Id_count;     
        float Id_Cal;              // d轴电流值
        float Id_Ref;              // d轴电流参考值
	int Ali_reliability_forward;
        int Ali_reliability_reverse;
	int Ali_reliability;
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
        int ForceLoopCount;
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
    float PosRefStep;
    float PosFbk;
    float target_pressure;
    float pressure_Fbk;
    float ForceRef;
    float ForceFbk;
    float ForceRefStep;
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
    int current_errcount;
    int ADC12_outrange;
    int ADC12_recovery;
    int voltage_low;
    int spd_outrange;
    int temp_High_recovery;
    int temp_low_recovery;
    int force_outrange;
    int voltlow_recovery;
    int voltlow_recovery2;
    int boardvolt_high_recovery;
    int boardvolt_high_recovery2;

} alarmcount;

typedef struct
{
    unsigned int busy_flag;         //（解）驻车锁定标志
    unsigned int magnet_state;      //电磁铁状态：0:空闲, 1:吸合中, 2:释放中
    unsigned int magnet_done_flag;  //驻车状态：0：未驻车 1：驻车
    unsigned int brake_error_code;  //故障状态位
    unsigned int Magnet_Control;    //驻车指令：2：初始化 1：驻车 0：解驻车
    unsigned int park_mode;
    
    struct{
        unsigned int park_step;     //驻车步骤

    }Park;

    struct{
        unsigned int unpark_step;   //解驻车步骤
    }UnPark;

}BrakeManage;

typedef struct{
   int AliCheck;  //定位
}FLAG;

//fromBCU_YC fromBCU_YC_FL;
//fromBCU_YC fromBCU_YC_FR;
//fromBCU_YC fromBCU_YC_RL;
//fromBCU_YC fromBCU_YC_RR;

// 声明全局变量
extern int lsw ;  
extern ControlManage_t g_Control;
extern BrakeManage Brake_Control;
extern SpeedCal Speed1;
extern Aligment_d Aligment;
extern alarmcount alarm;
extern FLAG flag;
extern PosInterpolation_t g_PosInterp;

//Instance CLARKE and PARK transformation instances
extern CLARKE clarke1 ;
extern CLARKE clarke2 ;
extern PARK   park1 ;
extern IPARK  ipark1 ;

//Instance SVGEN transformation instances
extern SVGEN svgen1 ;
extern SVGEN svgentest ;

// Instance PI regulators to regulate the d and q  axis currents, and speed
extern PI_CONTROLLER pi_force;
extern PI_CONTROLLER pi_preforce;
extern PI_CONTROLLER pi_pos ;
extern PI_CONTROLLER pi_fw ;
extern PI_CONTROLLER pi_spd ;
extern PI_CONTROLLER pi_id  ;
extern PI_CONTROLLER pi_iq ;

extern fromBCU_YC fromBCU_YC_FL;
extern fromBCU_YC fromBCU_YC_FR;
extern fromBCU_YC fromBCU_YC_RL;
extern fromBCU_YC fromBCU_YC_RR;

extern toBCU_YC toBCU_YC_FL;
extern toBCU_YC toBCU_YC_FR;
extern toBCU_YC toBCU_YC_RL;
extern toBCU_YC toBCU_YC_RR;

#endif  // GLOBAL_STRUCT_H