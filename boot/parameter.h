#ifndef __PARAMETER_H__  
#define __PARAMETER_H__

// 烧录时间定义 (手动修改) - 格式: 0xYYMMDD (年月日)
// 示例: 2025年7月7日 = 0x19070A (25年7月10日)
#define BUILD_DATE 0x19070E    
#define VERSION 0x010401

#define EPS        1
#define Booster    2
#define EMB        3
#define JWD        4
#define motortype  4

//lsw:select control loop
#define JWDL       5
#define EPSL       4
#define position   3       //position loop
#define speed      2       //speed loop
#define current    1       //current loop
#define Aligement  0       //Aligment
#define openloop  -1       //open loop
#define LSW        5

#define TESTFLAG   1      //0:test    1:can
#define ALIG_LOOP  0      //Aligment open
#define stoptime   3       //stop time
#define POS_INTERP_STEPS 19  //位置插补步数(ms)
//asin(0.95)=1.25323589


/*********************************
             JWD
*********************************/
#if(motortype==JWD)
/*parameter define*/
#define SPEEDDIR         -1
#define ANGLE_COMP       4.52   //taijia:2.43    废:3.59   用:4.41

// Define the electrical motor parametes
#define POLES  	         5	 // Number of poles
#define RATED_CURRENT    20        //120A
#define RATED_SPEED      950
#define RATED_POSITION 
#define CURRENT_PU       100/(RATED_CURRENT*1.414)
#define CURRENT_PU_RE    (RATED_CURRENT*1.414)/100
#define SPEED_PU         100/(RATED_SPEED*1.0)
#define SPEED_PU_RE      (RATED_SPEED*1.0)/100
#define POSITION_PU      50/(2*PI)
#define POSITION_PU_RE   (2*PI)/50

#define CURRENT_IS               375       //108A-382    120A-484   10A-35.4 105.9A-375
#define IS_SQU           140625
#define POWER            356250

#define POS_LOOP         20
#define SPEED_LOOP       1
#define FW_LOOP          1
#define SAT_LOOP         20

#define JWD_REF          0   //Reference Degree
#define TASCOMP          147 //      JWD：152.5  jia：53.2
//position parameter
#define POS_MAX          220
#define POS_MIN         -220
#define POS_KP           4.5     //2-0.02
#define POS_KI           0.05
#define POS_REF          -2*PI*5   //2PI*quan

//speed parameter
#define SPEED_MAX        CURRENT_IS
#define SPEED_MIN       -CURRENT_IS
#define SPEED_KP         1.5//1.5    //2-0.02
#define SPEED_KI         0.005//0.005
#define Speed_Ref        -2000

#define idmax            100
//iq parameter
#define IQ_MAX           50.0
#define IQ_MIN          -50.0
#define IQ_KP            0.5
#define IQ_KI            0.05
#define IQ_REF           5

//id parameter
#define ID_MAX           50.0
#define ID_MIN          -50.0
#define ID_KP            0.5
#define ID_KI            0.05
#define ID_REF           0      

//FW parameter
#define FW_MAX           0
#define FW_MIN           0
#define FW_KP            0
#define FW_KI            0.01
#define FW_REF           40//50*0.8
#define FWspeedup        1100//2500     
#define FWspeedlow       800//1800

//openloop parameter
#define VD_REF          0            //d reference
#define VQ_REF          0.15          //q reference
#define OPENSTEP        0.002

//protect parameter
#define MAXDUTY               0.8
#define SPEED_WARN           4000
#define VOLTAGE_WARN_LEVEL1    28
#define VOLTAGE_WARN_LEVEL2    30
#define VOLTAGE_WARN_LOW       6
#define CURRENT_WARN_LEVEL1    130
#define CURRENT_WARN_LEVEL2    140
#define CURRENT_WARN_LEVEL3    150
#endif

/*********************************
             EPS
*********************************/
#if(motortype==EPS)
/*parameter define*/
#define SPEEDDIR       1
#define ANGLE_COMP     0.139//0.13//0.23//0.2//  

// Define the electrical motor parametes
#define POLES  	       4	 // Number of poles
#define RATED_CURRENT  20
#define RATED_SPEED    1100
#define RATED_POSITION 
#define CURRENT_PU     100/(RATED_CURRENT*1.414)
#define CURRENT_PU_RE    (RATED_CURRENT*1.414)/100
#define SPEED_PU       100/(RATED_SPEED*1.0)
#define SPEED_PU_RE    (RATED_SPEED*1.0)/100
#define POSITION_PU     50/(2*PI)
#define POSITION_PU_RE     (2*PI)/50

#define CURRENT_IS          100//382
#define IS_SQU      107584
#define POWER       328000

#define POS_LOOP    20
#define SPEED_LOOP   1
#define FW_LOOP      1
#define SAT_LOOP    20
//position parameter
#define POS_MAX  100
#define POS_MIN -100
#define POS_KP   3     //2-0.02
#define POS_KI   0
#define POS_REF  0

//speed parameter
#define SPEED_MAX  CURRENT_IS
#define SPEED_MIN -CURRENT_IS
#define SPEED_KP   1.5//1.5    //2-0.02
#define SPEED_KI   0.005//0.005
#define Speed_Ref  500

#define idmax  100
//iq parameter
#define IQ_MAX  50.0
#define IQ_MIN -50.0
#define IQ_KP   1.5
#define IQ_KI   0.15
#define IQ_REF  20

//id parameter
#define ID_MAX  50.0
#define ID_MIN -50.0
#define ID_KP   1.5
#define ID_KI   0.15
#define ID_REF  0      

//FW parameter
#define FW_MAX  0
#define FW_MIN  0
#define FW_KP   0
#define FW_KI   0.01
#define FW_REF  50*0.8
#define FWspeedup  1100//2500     
#define FWspeedlow 800//1800

//openloop parameter
#define VD_REF    0          //d reference
#define VQ_REF  0.1          //q reference

//protect parameter
#define MAXDUTY               0.9
#define SPEED_WARN           4000
#define VOLTAGE_WARN_LEVEL1    28
#define VOLTAGE_WARN_LEVEL2    30
#define VOLTAGE_WARN_LOW       6
#define CURRENT_WARN_LEVEL1    120
#define CURRENT_WARN_LEVEL2    140
#define CURRENT_WARN_LEVEL3    150
#endif


/*********************************
             EMB
*********************************/
#if(motortype==EMB)
/*parameter define*/
#define SPEEDDIR       1
#define ANGLE_COMP     0.25  

// Define the electrical motor parametes
#define POLES  	       5	 // Number of poles
#define RATED_CURRENT  27
#define RATED_SPEED    3300
#define RATED_POSITION 
#define CURRENT_PU     100/(RATED_CURRENT*1.414)
#define SPEED_PU       100/(RATED_SPEED*1.0)
#define POSITION_PU     50/(2*PI)

#define CURRENT_IS     100

#define POS_LOOP    1
#define SPEED_LOOP  10
#define FW_LOOP     1
//position parameter
#define POS_MAX  200
#define POS_MIN -200
#define POS_KP   8    //2-0.02
#define POS_KI   0
#define POS_REF  2*PI*4.5 

//speed parameter
#define SPEED_MAX  CURRENT_IS
#define SPEED_MIN -CURRENT_IS
#define SPEED_KP   2    //2-0.02
#define SPEED_KI   0.05
#define Speed_Ref  1000

#define idmax   100
//iq parameter
#define IQ_MAX  50.0
#define IQ_MIN -50.0
#define IQ_KP   2
#define IQ_KI   0.2
#define IQ_REF  10

//id parameter
#define ID_MAX  50.0
#define ID_MIN -50.0
#define ID_KP   2
#define ID_KI   0.2
#define ID_REF  0      

//FW parameter
#define FW_MAX  0
#define FW_MIN -50
#define FW_KP   0
#define FW_KI   0.01
#define FW_REF  50*0.9
#define FWspeedup  4000//2500
#define FWspeedlow 3500//1800

//openloop parameter
#define VD_REF 0          //d reference
#define VQ_REF 0.1        //q reference

//protect parameter
#define MAXDUTY               0.9
#define SPEED_WARN           9000
#define VOLTAGE_WARN_LEVEL1    18
#define VOLTAGE_WARN_LEVEL2    24
#define CURRENT_WARN_LEVEL1    57
#define CURRENT_WARN_LEVEL2    68
#define CURRENT_WARN_LEVEL3    76
#endif

/*********************************
             Booster
*********************************/
#if(motortype==Booster)
/*parameter define*/
#define SPEEDDIR       -1
#define ANGLE_COMP     4.5  

// Define the electrical motor parametes
#define POLES  	       10	 // Number of poles
#define RATED_CURRENT  26.4
#define RATED_SPEED    1100
#define RATED_POSITION 
#define CURRENT_PU     100/(RATED_CURRENT*1.414)
#define SPEED_PU       100/(RATED_SPEED*1.0)
#define POSITION_PU     10/(2*PI)

#define CURRENT_IS     100

#define POS_LOOP   20
#define SPEED_LOOP  1
#define FW_LOOP     1
//position parameter
#define POS_MAX  100
#define POS_MIN -100
#define POS_KP   1    //2-0.02
#define POS_KI   0
#define POS_REF  2*PI*0.01 

//speed parameter
#define SPEED_MAX  CURRENT_IS
#define SPEED_MIN -CURRENT_IS
#define SPEED_KP   5    //2-0.02
#define SPEED_KI   0.1
#define Speed_Ref  300

#define idmax  100
//iq parameter
#define IQ_MAX  50.0
#define IQ_MIN -50.0
#define IQ_KP   2
#define IQ_KI   0.2
#define IQ_REF  2

//id parameter
#define ID_MAX  50.0
#define ID_MIN -50.0
#define ID_KP   2
#define ID_KI   0.2
#define ID_REF  0      

//FW parameter
#define FW_MAX  0
#define FW_MIN -50
#define FW_KP   0
#define FW_KI   0.1
#define FW_REF  50*0.8
#define FWspeedup  1100//2500
#define FWspeedlow 800//1800

//openloop parameter
#define VD_REF 0          //d reference
#define VQ_REF 0.1        //q reference

//protect parameter
#define MAXDUTY               0.9
#define SPEED_WARN           3500
#define VOLTAGE_WARN_LEVEL1    32
#define VOLTAGE_WARN_LEVEL2    36
#define CURRENT_WARN_LEVEL1    140
#define CURRENT_WARN_LEVEL2    160
#define CURRENT_WARN_LEVEL3    180
#endif
#endif
