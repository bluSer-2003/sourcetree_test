#include "pi_controller.h"
#include "gtm.h"

/************************************************
�Ľ�PI������ƫ���С�Ͳ�����������������
************************************************/
void PI_CUR(PI_CONTROLLER *v){
    float min = 3;             //�˳���������;: 1->0.38A
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
�Ľ�PI���ٶȵ���������ƫ������Ծ���
************************************************/
void PI_SPD(PI_CONTROLLER *v){
    /* proportional term */                          
    v->up = v->Ref - v->Fbk;                            
    v->up = SATS(v->up,-25,25); //ƫ���޷�  25->�ת��/4                                              
    /* integral term */                                                                        
    v->ui = v->Ki*v->up+ v->i1;                                                                   
    v->ui = SATS(v->ui,v->Umin,v->Umax);               
    v->i1 = v->ui;                                    
                                                     
    /* control output */                             
    v->Out = v->Kp* v->up + v->ui;         
    v->Out = SATS(v->Out,v->Umin,v->Umax);     
}

/************************************************
�Ľ�PI��λ�õ�������Сƫ������棬��ƫ��С����
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
��̬�޷�PI�������޷�ֵ=�ܵ�����޷�ֵ-�������������
************************************************/
void PI_1(PI_CONTROLLER *v){
    float KiSat=0;
    /* proportional term */                          
    v->up = v->Ref - v->Fbk; 
    //v->up = SATS(v->up,-25,25); //ƫ���޷�  25->�ת��/4  
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