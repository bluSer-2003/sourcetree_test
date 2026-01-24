//2024.11.13

#ifndef __PARAMETER_H__
#define __PARAMETER_H__

#define EPS        1
#define Booster    2
#define EMB        3
#define EMB2       4
#define JWD        5
#define motortype  EMB2

//lsw:select control loop
#define force      4
#define position   3       //position loop
#define speed      2       //speed loop
#define current    1       //current loop
#define Aligement  0       //Aligment
#define openloop  -1       //open loop
#define LSW        3

//Vehicle parameter
#define FLEMB 0
#define FREMB 1
#define RLEMB 2
#define RREMB 3
#define EMBActuator RREMB

#define TESTFLAG   1      //0:test    1:can
#define ALIG_LOOP  0       //Aligment open
#define stoptime   1      //stop time  0.8,0.5,0.2
#define savedata_count  3000
#define Data_Interval stoptime*20000/savedata_count
#define POS_INTERP_STEPS 19  //??????(ms)

/*********************************
             EMB2
*********************************/
#if(motortype==EMB2)
/*parameter define*/
#define SPEEDDIR       1
#define ANGLE_COMP     0.889//0.74//3.963//1.219//1.716//0.74//0.631//1.197//5.714//1.756//5.2766//5.0983//5.706//

// Define the electrical motor parametes
#define POLES  	       5	 // Number of poles
#define RATED_CURRENT  40//24//20  
#define RATED_SPEED    1800//1600    YC:1500 YKZQ:1600
#define RATED_POSITION 
#define CURRENT_PU     100/(RATED_CURRENT*1.414)
#define CURRENT_PU_RE  (RATED_CURRENT*1.414)/100
#define SPEED_PU       20/(RATED_SPEED*1.0)
#define SPEED_PU_RE    (RATED_SPEED*1.0)/20
#define POSITION_PU     20/(2*PI)
#define POSITION_PU_RE   (2*PI)/20
#define FORCE_PU        1/1000
#define FORCE_PU_RE     1000

#define IS_CURRENT  100    //160//265
#define IS_SQU      10000  //25600// 
#define POWER       160000 //256000//       //RATED_SPEED*IS_CURRENT

#define POS_LOOP    20
#define SPEED_LOOP   1
#define FW_LOOP      1
#define SAT_LOOP    20

//position parameter
#define POS_MAX  20   //1=80
#define POS_MIN -20 
#define POS_KP   4.5    //2-0.02
#define POS_KI   0.02
#define POS_REF  2*PI*10

//position parameter(pure integral,feedforward)
 #define FORCE_MAX  10   //1=75
 #define FORCE_MIN  -10
 #define FORCE_KP   0   
 #define FORCE_KI   0.05
 #define FORCE_REF  15000

//force parameter(feedback)
#define FORCE_LOOP 20
//#define FORCE_MAX 20
//#define FORCE_MIN -20
//#define FORCE_KP  3
//#define FORCE_KI  0.1
//#define FORCE_REF 5000  //N


//speed parameter
#define SPEED_MAX  IS_CURRENT
#define SPEED_MIN -IS_CURRENT
#define SPEED_KP   3//2.0//2-0.02
#define SPEED_KI   0.1//0.05
#define Speed_Ref  500      //500,1000,2000

#define idmax   100
//iq parameter
#define IQ_MAX  50.0
#define IQ_MIN -50.0
#define IQ_KP   0.5//2
#define IQ_KI   0.2//0.3
#define IQ_REF  5

//id parameter
#define ID_MAX  50.0
#define ID_MIN -50.0
#define ID_KP   0.5//2
#define ID_KI   0.2//0.3
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
#define VD_REF     0          //d reference
#define VQ_REF     0.25        //q reference0.4-0.015
#define OPEN_STEP  -0.01

//protect parameter
#define LEAK_H      16     
#define LEAK_L      15
#define MAXDUTY               0.8
#define SPEED_WARN           9000
#define FORCE_HIGH           30000
#define VOLTAGE_WARN_LOW       6
#define VOLTAGE_WARN_LEVEL1    18
#define VOLTAGE_WARN_LEVEL2    24
#define CURRENT_WARN_LEVEL1    60
#define CURRENT_WARN_LEVEL2    72
#define CURRENT_WARN_LEVEL3    85
#endif

/*********************************
             JWD
*********************************/
#if(motortype==JWD)
/*parameter define*/
#define SPEEDDIR         -1
#define ANGLE_COMP       2.45   //taijia:2.43    ��:3.59   ��:4.41

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
#define FORCE_PU        1/1000
#define FORCE_PU_RE     1000

#define IS_CURRENT       375       //108A-382    120A-484   10A-35.4 105.9A-375
#define IS_SQU           140625
#define POWER            356250

#define POS_LOOP         20
#define SPEED_LOOP       10
#define FW_LOOP          1
#define SAT_LOOP         20

#define JWD_REF          0   //Reference Degree
#define TASCOMP          0 //      JWD��152.5  jia��53.2
//position parameter
#define POS_MAX          100
#define POS_MIN         -100
#define POS_KP           2     //2-0.02
#define POS_KI           0.0
#define POS_REF          -100//-2*PI*5   //2PI*quan

//position parameter(pure integral)
#define FORCE_MAX  10   //1=75
#define FORCE_MIN  -10
#define FORCE_KP   0   
#define FORCE_KI   0.05
#define FORCE_REF  13000

//speed parameter
#define SPEED_MAX        IS_CURRENT
#define SPEED_MIN       -IS_CURRENT
#define SPEED_KP         1.2//1.5    //2-0.02
#define SPEED_KI         0.001//0.005
#define Speed_Ref        -1200

#define idmax            100
//iq parameter
#define IQ_MAX           50.0
#define IQ_MIN          -50.0
#define IQ_KP            0.5
#define IQ_KI            0.05
#define IQ_REF           20

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
#define VQ_REF          0.25          //q reference
#define OPEN_STEP       0.01

//protect parameter
//protect parameter
#define LEAK_H      16     
#define LEAK_L      15
#define MAXDUTY               0.8
#define FORCE_HIGH           20000
#define SPEED_WARN           4000
#define VOLTAGE_WARN_LEVEL1    28
#define VOLTAGE_WARN_LEVEL2    30
#define VOLTAGE_WARN_LOW       6
#define CURRENT_WARN_LEVEL1    130
#define CURRENT_WARN_LEVEL2    140
#define CURRENT_WARN_LEVEL3    150
#define HIGH_TEMPERATURE       95
#define HIGH_TEMPERATURE_CLEAR 85
#endif
/*********************************
             EMB
*********************************/
#if(motortype==EMB)
/*parameter define*/
#define SPEEDDIR       1
#define ANGLE_COMP     3.543//4.95//  

// Define the electrical motor parametes
#define POLES  	       5	 // Number of poles
#define RATED_CURRENT  27
#define RATED_SPEED    3300
#define RATED_POSITION 
#define CURRENT_PU     100/(RATED_CURRENT*1.414)
#define CURRENT_PU_RE	(RATED_CURRENT*1.414)/100
#define SPEED_PU       20/(RATED_SPEED*1.0)
#define SPEED_PU_RE   (RATED_SPEED*1.0)/20
#define POSITION_PU    20/(2*PI)

#define IS_CURRENT          100//382
#define IS_SQU      10000
#define POWER       330000

#define POS_LOOP    20
#define SPEED_LOOP   1
#define FW_LOOP      1
#define SAT_LOOP    20

//position parameter
#define POS_MAX  10   //1=165    
#define POS_MIN -10
#define POS_KP   1    //2-0.02
#define POS_KI   0
#define POS_REF  2*PI*10 

//speed parameter
#define SPEED_MAX  IS_CURRENT
#define SPEED_MIN -IS_CURRENT
#define SPEED_KP   1    //2-0.02
#define SPEED_KI   0.02
#define Speed_Ref  500

#define idmax   100
//iq parameter
#define IQ_MAX  50.0
#define IQ_MIN -50.0
#define IQ_KP   2
#define IQ_KI   0.2
#define IQ_REF  5

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
#define VD_REF     0          //d reference
#define VQ_REF     0.25        //q reference0.4-0.015
#define OPEN_STEP  -0.005

//protect parameter
#define LEAK_H      16     
#define LEAK_L      15
#define MAXDUTY               0.9
#define SPEED_WARN           9000
#define FORCE_HIGH          10000
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
#define SPEEDDIR       1
#define ANGLE_COMP     1.12 

// Define the electrical motor parametes
#define POLES  	       6	 // Number of poles
#define RATED_CURRENT  20
#define RATED_SPEED    1100
#define RATED_POSITION 
#define CURRENT_PU     100/(RATED_CURRENT*1.414)
#define CURRENT_PU_RE  (RATED_CURRENT*1.414)/100
#define SPEED_PU       100/(RATED_SPEED*1.0)
#define SPEED_PU_RE    (RATED_SPEED*1.0)/100
#define POSITION_PU     10/(2*PI)

#define IS_CURRENT          100//382
#define IS_SQU      10000
#define POWER       100000

#define POS_LOOP    20
#define SPEED_LOOP   1
#define FW_LOOP      1
#define SAT_LOOP    20

//position parameter
#define POS_MAX  100
#define POS_MIN -100
#define POS_KP   1    //2-0.02
#define POS_KI   0
#define POS_REF  2*PI*0.01 

//speed parameter
#define SPEED_MAX  IS_CURRENT
#define SPEED_MIN -IS_CURRENT
#define SPEED_KP   1.5    //2-0.02
#define SPEED_KI   0.005
#define Speed_Ref  1000

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
#define FW_MIN -50
#define FW_KP   0
#define FW_KI   0.1
#define FW_REF  50*0.8
#define FWspeedup  1100//2500
#define FWspeedlow 800//1800

//openloop parameter
#define VD_REF     0          //d reference
#define VQ_REF     0.35       //q reference0.4-0.015
#define OPEN_STEP  0.012

//protect parameter 
#define LEAK_H      27     
#define LEAK_L      26
#define MAXDUTY     0.9
#define SPEED_WARN  3500
#define FORCE_HIGH          10000
#define VOLTAGE_WARN_LEVEL1    32
#define VOLTAGE_WARN_LEVEL2    36
#define CURRENT_WARN_LEVEL1    57
#define CURRENT_WARN_LEVEL2    68
#define CURRENT_WARN_LEVEL3    76
#endif


/*********************************
             EPS
*********************************/
#if(motortype==EPS)
/*parameter define*/
#define SPEEDDIR       1
#define ANGLE_COMP     4.1//0.23//0.2//  

// Define the electrical motor parametes
#define POLES  	       4	 // Number of poles
#define RATED_CURRENT  20
#define RATED_SPEED    1100
#define RATED_POSITION 
#define CURRENT_PU     100/(RATED_CURRENT*1.414)
#define SPEED_PU       100/(RATED_SPEED*1.0)
#define POSITION_PU     50/(2*PI)

#define IS_CURRENT          328//382
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
#define SPEED_MAX  IS_CURRENT
#define SPEED_MIN -IS_CURRENT
#define SPEED_KP   1.5//1.5    //2-0.02
#define SPEED_KI   0.01//0.005
#define Speed_Ref  100

#define idmax  100
//iq parameter
#define IQ_MAX  50.0
#define IQ_MIN -50.0
#define IQ_KP   1.5
#define IQ_KI   0.3
#define IQ_REF  20

//id parameter
#define ID_MAX  50.0
#define ID_MIN -50.0
#define ID_KP   1.5
#define ID_KI   0.3
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
#define CURRENT_WARN_LEVEL1    120
#define CURRENT_WARN_LEVEL2    140
#define CURRENT_WARN_LEVEL3    160
#endif
#endif
