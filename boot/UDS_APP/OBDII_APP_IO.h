/*
 * OBDII_APP_IO.h
 *
 */

#ifndef DTC_HFILE_OBDII_APP_IO_H_
#define DTC_HFILE_OBDII_APP_IO_H_


#include "struct.h"



/*************************DTC故障接口***********************************************/

#define DTC_flgBatteryVL                       	    	(1)//Battery voltage is too low
#define DTC_flgBatteryVH                         	(1)//Battery voltage is too high
#define	DTC_flgCANbusoff                       		(1)//busoff
#define	DTC_flgVCUNodeErr	                      	(1)//VCU?????????
#define	DTC_flgVCUNodeSignalErr                     	(1)//VCU????????????
#define	DTC_flgToranglePowErr                      	(1)//?????????????????
#define	DTC_flgEPSTorAngleErr                    	(1)//EPS???????????
#define	DTC_flgEPSPowerErr                           	(0)//EPS???????????
#define DTC_flgEPSHardWareErr                        	(0)//EPS???????????
#define	DTC_flgEPSMotorErr                       	(0)//EPS???????????????
#define	DTC_flgTempSignalErr                      	(0)//??????????????
#define	DTC_flgECUTempSignalErr                      	(0)//ECU????�????????
#define	DTC_flgRelayBreakErr                    	(0)//???????�???
#define	DTC_flgRelayStickErr                      	(0)//???????????
#define	DTC_flgMoterLoationErr                      	(0)//????????????
#define DTC_flgTurnStickErr                         	(0)//?????????
#define	DTC_flgAutoModeInterErr                     	(0)//??????????????a??
#define	DTC_flgAngleZeroErr                      	(0)//???????????




/*************************DTC故障接口***********************************************/

/**********************************************DynamicData DID***********************************************/



/**********************************************DynamicData DID**0x6F*********************************************/

/**********************************************Snapshot List***********************************************/



/**********************************************Snapshot List end***********************************************/

extern uint8 OBDII_ECUSerialData[14];	
extern uint8 OBDII_System_Supplier_Identifier[10];
extern uint8 OBDII_Vehicle_Manufacturer_Part_Number[12];
extern uint8 OBDII_VehIdData[17];	//Vehicle Identification Number
extern uint8 OBDII_System_Num[10];
extern uint8 OBDII_SysSupplier_ECUHWVer_Number[2];
extern uint8 OBDII_SysSupplier_ECUSWVer_Number[2];

extern uint8 OBDII_FingerprintDataIdentifier_DATA[10];

extern void Get_FingerprintDataIdentifier(void);


#endif /* DTC_HFILE_OBDII_APP_IO_H_ */
