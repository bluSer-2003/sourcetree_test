
#include "OBDII_APP_IO.h"


uint8 OBDII_ECUSerialData[14];	
uint8 OBDII_System_Supplier_Identifier[10];
uint8 OBDII_Vehicle_Manufacturer_Part_Number[12];
uint8 OBDII_VehIdData[17]={0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};	//Vehicle Identification Number
uint8 OBDII_System_Num[10];
uint8 OBDII_SysSupplier_ECUHWVer_Number[2];
uint8 OBDII_SysSupplier_ECUSWVer_Number[2];
uint8 OBDII_FingerprintDataIdentifier_DATA[10];


uint8 *boot_FingerprintDataIdentifier_address;
void Get_FingerprintDataIdentifier(void)
{
	boot_FingerprintDataIdentifier_address = 0x00007000;
	OBDII_FingerprintDataIdentifier_DATA[0] = *boot_FingerprintDataIdentifier_address;
	boot_FingerprintDataIdentifier_address = 0x00007001;
	OBDII_FingerprintDataIdentifier_DATA[1] = *boot_FingerprintDataIdentifier_address;
	boot_FingerprintDataIdentifier_address = 0x00007002;
	OBDII_FingerprintDataIdentifier_DATA[2] = *boot_FingerprintDataIdentifier_address;
}

