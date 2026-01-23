#include "global_struct.h"
#include "can_command.h"
#include "parameter.h"
#include "global_struct.h"
extern unsigned int error_state_code_0101;


void UpdateRef()
{
    g_Control.PosRef = g_CANflash.posRef_float;
    g_Control.SpdRef = g_CANflash.spdRef_float;
    g_Control.IqRef  = g_CANflash.qRef_float;
    g_Control.IdRef  = g_CANflash.dRef_float;

}


void UpdatePara(void)
{
    if(g_CANflash.flag&_PORT_SET_BIT0){          //0:Cur Ki
	pi_iq.Kp = g_CANflash.cur.kp;
	pi_id.Kp = g_CANflash.cur.kp;
        g_CANflash.flag &=_PORT_CLEAR_BIT0;
    }
    
    if(g_CANflash.flag&_PORT_SET_BIT1){          //1:Cur Kp
	pi_iq.Ki = g_CANflash.cur.ki;
	pi_id.Ki = g_CANflash.cur.ki;
        g_CANflash.flag &=_PORT_CLEAR_BIT1;
    }
    
    /*if(g_CANflash.flag&_PORT_SET_BIT2){          //2:IdRef&IqRef
	g_Control.IqRef = g_CANflash.qRef_float;
        g_Control.IdRef = g_CANflash.dRef_float;
	g_CANflash.flag &=_PORT_CLEAR_BIT2;
    }*/
    
    if(g_CANflash.flag&_PORT_SET_BIT3){          //3.Spd Kp
	pi_spd.Kp = g_CANflash.spd.kp;
	g_CANflash.flag &=_PORT_CLEAR_BIT3;
    }
    
    if(g_CANflash.flag&_PORT_SET_BIT4){          //4.Spd ki
	pi_spd.Ki = g_CANflash.spd.ki;
	g_CANflash.flag &=_PORT_CLEAR_BIT4;
    }
    
    /*if(g_CANflash.flag&_PORT_SET_BIT5){          //5.Spdref&SpdMax
        g_Control.SpdRef = g_CANflash.spdRef_float;
	pi_spd.Umax = g_CANflash.CurMax;
	g_CANflash.flag &=_PORT_CLEAR_BIT5;
    }*/
    
    if(g_CANflash.flag&_PORT_SET_BIT6){          //6.PosKp
	pi_pos.Kp = g_CANflash.pos.kp;
	g_CANflash.flag &=_PORT_CLEAR_BIT6;
    }
    
    if(g_CANflash.flag&_PORT_SET_BIT7){          //7.PosKi
	pi_pos.Ki = g_CANflash.pos.ki;
	g_CANflash.flag &=_PORT_CLEAR_BIT7;
    }
    
    /*if(g_CANflash.flag&_PORT_SET_BIT8){          //8.PosRef&SpdMax&CurMax
        g_Control.prot.VoltLevel1 = g_CANflash.Ov*0.1;
	g_Control.prot.VoltLevel2 = g_CANflash.Ov*0.1*1.5;
        g_CANflash.flag &=_PORT_CLEAR_BIT8;
    }*/
    
    if(g_CANflash.flag&_PORT_SET_BIT9){          //9.FwKp
        pi_fw.Kp = g_CANflash.weak.kp;
        g_CANflash.flag &=_PORT_CLEAR_BIT9;
    }
    
    if(g_CANflash.flag&_PORT_SET_BIT10){         //10.FwKi
	pi_fw.Ki = g_CANflash.weak.ki;
        g_CANflash.flag &=_PORT_CLEAR_BIT10;
    }
    
    if(g_CANflash.flag&_PORT_SET_BIT11){         //11.FwCurMax
	pi_fw.Umin = -g_CANflash.fwCurMax;
        g_CANflash.flag &=_PORT_CLEAR_BIT11;
    }
    
    if(g_CANflash.flag&_PORT_SET_BIT12){          //12.OverVoltage
	g_Control.prot.VoltLevel1 = g_CANflash.Ov*0.1;
	g_Control.prot.VoltLevel2 = g_CANflash.Ov*0.1*1.5;
        g_CANflash.flag &=_PORT_CLEAR_BIT12;
    }
     
    if(g_CANflash.flag&_PORT_SET_BIT13){          //13.OverCur
	g_Control.prot.CurLevel1 = g_CANflash.Oi*0.1;
	g_Control.prot.CurLevel2 = g_CANflash.Oi*0.1*1.2;
	g_Control.prot.CurLevel3 = g_CANflash.Oi*0.1*1.5;
        g_CANflash.flag &=_PORT_CLEAR_BIT13;
    }
}