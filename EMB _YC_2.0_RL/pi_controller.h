#include "global_struct.h"
#ifndef __PI_H__
#define __PI_H__

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
      

void PI_CUR(PI_CONTROLLER *v);
void PI_SPD(PI_CONTROLLER *v);     
void PI_POS(PI_CONTROLLER *v);
void PI_1(PI_CONTROLLER *v);

#endif // __PI_H__