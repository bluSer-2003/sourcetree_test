#ifndef __BRAKE_H__
#define __BRAKE_H__

#define PARK_COUNT_LIMIT 2
#define PARK_SCALE       3.0f
#define HALF_PITCH       0.28f
#define Retreat_SCALE    2.7f
#define Unpark_Count_limit 1
#define EnForce_Brake_Scale 5.0f

void Magnet(int jzt);
void Magnet_Off(void) ;
void MagnetTask(void);

#endif