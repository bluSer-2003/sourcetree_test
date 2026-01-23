#include "OBDII_APP_IO.h"


uint8 OBDII_ECUSerialData[14] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1};	
uint8 OBDII_System_Supplier_Identifier[10] = {2,2,2,2,2,2,2,2,2,2};
uint8 OBDII_Vehicle_Manufacturer_Part_Number[12] = {3,3,3,3,3,3,3,3,3,3,3,3};
uint8 OBDII_VehIdData[17]={4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4};	//Vehicle Identification Number
uint8 OBDII_System_Num[10] = {6,6,6,6,6,6,6,6,6,6};
uint8 OBDII_SysSupplier_ECUHWVer_Number[2] = {7,7};
uint8 OBDII_SysSupplier_ECUSWVer_Number[2] = {8,8};
uint8 OBDII_FingerprintDataIdentifier_DATA[10] = {9,9,9,9,9,9,9,9,9,9};

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

