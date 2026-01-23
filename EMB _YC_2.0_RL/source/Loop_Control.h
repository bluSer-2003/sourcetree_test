#ifndef __LOOP_CONTROL_H__
#define __LOOP_CONTROL_H__

void CurrentLoop(float IqRef,float Idref,float IqFbk,float IdFbk);
inline void FWLoop(void);
void SpeedLoop(float SpdRef,float SpdFbk);
void PosLoop(float PosRef,float PosFbk);
void PressureIntUpdate(float ForceRef,float ForceFbk);
void ForceLoop(float ForceRef,float ForceFbk);
void Openloop(void);
void GetPosition(void);

#endif
