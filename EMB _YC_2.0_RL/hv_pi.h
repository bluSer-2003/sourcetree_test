#ifndef __PI_H__
#define __PI_H__

typedef struct {  float  Ref;             // Input: reference set-point
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


/*------------------------------------------------------------------------------
    PI_GRANDO Macro Definition
------------------------------------------------------------------------------*/

#define PI_MACRO(v) /*normal PI controller*/         \
                                                     \
    /* proportional term */                          \
    v.up = v.Ref - v.Fbk;                            \
                                                     \
    /* integral term */                              \
    if(v.Out >=v.Umax || v.Out <=v.Umin)             \
    {                                                \
        if (v.ui >= 0 && v.up < 0)                   \
        {                                            \
           v.ui = v.Ki * v.up+ v.i1;                 \
        }                                            \
        else if( v.ui < 0 && v.up > 0 )              \
        {                                            \
           v.ui = v.Ki * v.up+ v.i1;                 \
        }                                            \
    }                                                \
    else                                             \
    {                                                \
        v.ui = v.Ki*v.up+ v.i1;                      \
    }                                                \
    v.ui = SATS(v.ui,v.Umin,v.Umax);                  \
    v.i1 = v.ui;                                     \
                                                     \
    /* control output */                             \
    v.Out = v.Kp* v.up + v.ui;                       \
    v.Out=(v.Out>v.Umax)?v.Umax:v.Out;               \
    v.Out=(v.Out<v.Umin)?v.Umin:v.Out;               \
       

#define PI_SEP(v)    /*sepera I PI controller*/      \
                                                     \
     /* proportional term */                         \
     v.up = v.Ref - v.Fbk;                           \
                                                     \
     if(v.Fbk>v.Ref*0.4)                             \
         v.index=v.Ki;                               \
     else                                            \
         v.index=0;                                  \
                                                     \
     /* integral term */                             \
     v.ui = v.index*v.up+ v.u1;                      \
     v.ui=(v.ui>=v.Umax)?v.Umax:v.ui;                \
     v.ui=(v.ui< v.Umin)?v.Umin:v.ui;                \
                                                     \
     /* control output */                            \
     v.v1 = v.Kp* v.up + v.ui;                       \
     v.Out=(v.v1>=v.Umax)?v.Umax :v.v1;              \
     v.Out=(v.v1< v.Umin)?v.Umin :v.v1;              \
     
     
/************************************************
改进PI：电流偏差过小就不介入比例项，抑制噪音
************************************************/
void PI_CUR(PI_CONTROLLER *v){
    float min = 5;             //退出比例介入;: 1->0.38A
    /* proportional term */                          
    v->up = v->Ref - v->Fbk;                            
                                                     
    /* integral term */                                                                        
    v->ui = v->Ki*v->up+ v->i1;                                                                      
    v->ui = SATS(v->ui,v->Umin,v->Umax);                  
    v->i1 = v->ui;                                    
                                                     
    /* control output */                             
    if(v->up>-min&&v->up<min)                                                                         
        v->Out =v->ui;                                                    
    else              
        v->Out = v->Kp* v->up + v->ui;                

    v->Out = SATS(v->Out,v->Umin,v->Umax);     
}

/************************************************
改进PI：速度调节器限制偏差，避免阶跃冲击
************************************************/
void PI_SPD(PI_CONTROLLER *v){
    /* proportional term */                          
    v->up = v->Ref - v->Fbk;                            
    v->up = SATS(v->up,-25,25); //偏差限幅  25->额定转速/4                                              
    /* integral term */                                                                        
    v->ui = v->Ki*v->up+ v->i1;                                                                   
    v->ui = SATS(v->ui,v->Umin,v->Umax);               
    v->i1 = v->ui;                                    
                                                     
    /* control output */                             
    v->Out = v->Kp* v->up + v->ui;         
    v->Out = SATS(v->Out,v->Umin,v->Umax);     
}

/************************************************
改进PI：位置调节器，小偏差大增益，大偏差小增益
************************************************/
void PI_POS(PI_CONTROLLER *v){
    /* proportional term */                          
    v->up = v->Ref - v->Fbk;                                                                         
    /* integral term */ 
    if(v->ui<5&&v->ui>-5){
        v->ui = v->Ki*v->up+ v->i1;                                                                   
        v->ui = SATS(v->ui,v->Umin,v->Umax);               
        v->i1 = v->ui;
    }
                                                     
    /* control output */
    //if(v->ui<35&&v->ui>-35)
        //v->Out = 8* v->up + v->ui;
    //else
    v->Out = v->Kp* v->up + v->ui;         
    v->Out = SATS(v->Out,v->Umin,v->Umax);     
}

/************************************************
动态限幅PI：积分限幅值=总的输出限幅值-比例环节输出。
************************************************/
void PI_1(PI_CONTROLLER *v){
    float KiSat=0;
    /* proportional term */                          
    v->up = v->Ref - v->Fbk; 
    //v->up = SATS(v->up,-25,25); //偏差限幅  25->额定转速/4  
    /* integral term */ 
    KiSat = v->Umax - ABS(v->Kp*v->up);
    if(KiSat<=0)
        KiSat = 0;
    
    v->ui = v->Ki*v->up+ v->i1;                                                                   
    v->ui = SATS(v->ui,-KiSat,KiSat);               
    v->i1 = v->ui;
                                                     
    /* control output */
    v->Out = v->Kp*v->up + v->ui;         
    v->Out = SATS(v->Out,v->Umin,v->Umax);     
}

#endif // __PI_H__