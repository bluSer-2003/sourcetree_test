#ifndef __SVGEN_H__
#define __SVGEN_H__

                    
/*-----------------------------------------------------------------------------
Default initalisation values for the PI_GRANDO objects
-----------------------------------------------------------------------------*/         
typedef struct  { 
    float  Ualpha;          // Input: reference alpha-axis phase voltage
    float  Ubeta;           // Input: reference beta-axis phase voltage
    float  Ta;              // Output: reference phase-a switching function
    float  Tb;              // Output: reference phase-b switching function
    float  Tc;              // Output: reference phase-c switching function
    float  tmp1;            // Variable: temp variable
    float  tmp2;            // Variable: temp variable
    float  tmp3;            // Variable: temp variable
    float  max_tmp;
    unsigned int VecSector;     // Space vector sector
} SVGEN;


/*-----------------------------------------------------------------------------
Default initalizer for the SVGEN object.
-----------------------------------------------------------------------------*/                     
#define SVGEN_DEFAULTS { 0,0,0,0,0,0 }   

/*------------------------------------------------------------------------------
    Space Vector  Generator (SVGEN) Macro Definition
------------------------------------------------------------------------------*/

#define SVGENDQ_MACRO(v)                                                        \
    v.tmp1= v.Ubeta;                                                            \
    v.tmp2= v.Ubeta/2 + 0.866*v.Ualpha;                                         \
    v.tmp3= v.tmp2 - v.tmp1;                                                    \
                                                                                \
    v.VecSector=3;                                                              \
    v.VecSector=(v.tmp2> 0)?( v.VecSector-1):v.VecSector;                       \
    v.VecSector=(v.tmp3> 0)?( v.VecSector-1):v.VecSector;                       \
    v.VecSector=(v.tmp1< 0)?( 7-v.VecSector):v.VecSector;                       \
                                                                                \
    if     (v.VecSector==1 || v.VecSector==4)                                   \
      {     v.Ta= v.tmp2;                                                       \
            v.Tb= v.tmp1-v.tmp3;                                                \
            v.Tc=-v.tmp2;                                                       \
      }                                                                         \
                                                                                \
    else if(v.VecSector==2 || v.VecSector==5)                                   \
      {     v.Ta= v.tmp3+v.tmp2;                                                \
            v.Tb= v.tmp1;                                                       \
            v.Tc=-v.tmp1;                                                       \
      }                                                                         \
                                                                                \
    else                                                                        \
      {     v.Ta= v.tmp3;                                                       \
            v.Tb=-v.tmp3;                                                       \
            v.Tc=-(v.tmp1+v.tmp2);                                              \
      }                                                                         \
                                                                                
static inline void svpwm(SVGEN *v)
{
    int Sector = 0;
/* Inverse clarke transformation */
    float Va = v->Ubeta;
    float Vb = 0.8660254*v->Ualpha - v->Ubeta/2;
    float Vc =-0.8660254*v->Ualpha - v->Ubeta/2;
    float t0=0,t4=0,t6=0;
    float T1,T2,T3;
    /*sqrt(3)/2=0.8660254*/

/*60 degree Sector determination */
    if (Va>0) Sector = 1;
    if (Vb>0) Sector = Sector+2;
    if (Vc>0) Sector = Sector+4;

    switch(Sector){
        case 1:
        t4 = -Vb;
        t6 = -Vc;
        if(t4+t6>1){
            t4 = t4/(t4+t6);
            t6 = t6/(t4+t6);
        }
        t0 = 1-t4-t6; 
        break;

        case 2:
        t4 = -Vc;
        t6 = -Va;
        if(t4+t6>1){
            t4 = t4/(t4+t6);
            t6 = t6/(t4+t6);
        }
        t0 = 1-t4-t6;
        break;

        case 3:
        t4 =  Vb;
        t6 =  Va;
        if(t4+t6>1){
            t4 = t4/(t4+t6);
            t6 = t6/(t4+t6);
        }
        t0 = 1-t4-t6;
        break;

        case 4:
        t4 = -Va;
        t6 = -Vb;
        if(t4+t6>1){
            t4 = t4/(t4+t6);
            t6 = t6/(t4+t6);
        }
        t0 = 1-t4-t6;
        break;

        case 5:
        t4 =  Va;
        t6 =  Vc;
        if(t4+t6>1){
            t4 = t4/(t4+t6);
            t6 = t6/(t4+t6);
        }
        t0 = 1-t4-t6;
        break;

        case 6:
        t4 =  Vc;
        t6 =  Vb;
        if(t4+t6>1){
            t4 = t4/(t4+t6);
            t6 = t6/(t4+t6);
        }
        t0 = 1-t4-t6;
        break;
    }

    T1 = (1-t4-t6)/2;
    T2 = T1 + t4;
    T3 = T2 + t6;

    switch(Sector){
        case 1:
        case 7:
        v->Ta = T2;
        v->Tb = T1;
        v->Tc = T3;
        break;

        case 2:
        v->Ta = T1;
        v->Tb = T3;
        v->Tc = T2;
        break;

        case 3:
        v->Ta = T1;
        v->Tb = T2;
        v->Tc = T3;
        break;

        case 4:
        v->Ta = T3;
        v->Tb = T2;
        v->Tc = T1;
        break;

        case 5:
        v->Ta = T3;
        v->Tb = T1;
        v->Tc = T2;
        break;

        case 6:
        v->Ta = T2;
        v->Tb = T3;
        v->Tc = T1;
        break;
    }
    v->Ta = -(v->Ta-0.5)*2;
    v->Tb = -(v->Tb-0.5)*2;
    v->Tc = -(v->Tc-0.5)*2;
}

#endif // __SVGEN_H__