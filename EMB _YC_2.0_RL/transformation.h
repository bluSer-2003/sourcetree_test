#ifndef __TRANSFORMATION_H__
#define __TRANSFORMATION_H__


/*-----------------------------------------------------------------------------
    Structure Definition.
-----------------------------------------------------------------------------*/
typedef struct {  float  As;  		// Input: phase-a stator variable
                  float  Bs;			// Input: phase-b stator variable
                  float  Cs;			// Input: phase-c stator variable
                  float  Alpha;		// Output: stationary d-axis stator variable
                  float  Beta;		// Output: stationary q-axis stator variable
		} CLARKE;	            

typedef struct {  float  Alpha;       // Input: stationary d-axis stator variable
                  float  Beta;        // Input: stationary q-axis stator variable
                  float  Angle;       // Input: rotating angle (pu)
                  float  Ds;          // Output: rotating d-axis stator variable
                  float  Qs;          // Output: rotating q-axis stator variable
                  float  Sine;        // Input: Sine term
                  float  Cose;      // Input: Cosine term
               } PARK,IPARK;

/*-----------------------------------------------------------------------------
	Default initalizer.
-----------------------------------------------------------------------------*/                     
#define CLARKE_DEFAULTS { 0, \
                          0, \
                          0, \
                          0, \
                          0, \
                        }

#define PARK_DEFAULTS {   0, \
                          0, \
                          0, \
                          0, \
                          0, \
                          0, \
                          0, \
                      }

#define IPARK_DEFAULTS {  0, \
                          0, \
                          0, \
                          0, \
                          0, \
                          0, \
                          0, \
                        }

/*------------------------------------------------------------------------------
    CLARKE Transformation Macro Definition
------------------------------------------------------------------------------*/

#define CLARKE_MACRO(v)											\
																\
v.Alpha = v.As;													\
v.Beta  = (v.As+2*v.Bs)*0.57735026918963;	\
						   /*  1/sqrt(3) = 0.57735026918963*/   \


/*------------------------------------------------------------------------------
    PARK Transformation Macro Definition
------------------------------------------------------------------------------*/

#define PARK_MACRO(v)                                           \
		 	 	                                                \
v.Ds =  v.Alpha*v.Cose + v.Beta*v.Sine;        \
v.Qs =  v.Beta *v.Cose - v.Alpha*v.Sine;       \


/*------------------------------------------------------------------------------
    Inverse PARK Transformation Macro Definition
------------------------------------------------------------------------------*/

#define IPARK_MACRO(v)                                          \
                                                                \
v.Alpha = v.Ds*v.Cose - v.Qs*v.Sine;          \
v.Beta  = v.Qs*v.Cose + v.Ds*v.Sine;



#endif // __TRANSFORMATION_H__
