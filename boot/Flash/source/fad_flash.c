/**********************************************************************************************************************
    File Name       : main1.c
    File Revision   : $Rev$
    File Date       : $Date$
    Device(s)       : RV40 Flash based RH850 microcontroller
    Description     : Application sample for usage of Flash Access Driver (FAD)
**********************************************************************************************************************/

/**********************************************************************************************************************
    DISCLAIMER
    This software is supplied by Renesas Electronics Corporation and is only  intended for use with
    Renesas products. No other uses are authorized. This software is owned by Renesas Electronics
    Corporation and is protected under all applicable laws, including copyright laws.
    THIS SOFTWARE IS PROVIDED "AS IS" AND RENESAS MAKES NO WARRANTIES REGARDING THIS SOFTWARE,
    WHETHER EXPRESS, IMPLIED OR STATUTORY, INCLUDING BUT NOT LIMITED TO WARRANTIES OF MERCHANTABILITY,
    FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT. ALL SUCH WARRANTIES ARE EXPRESSLY DISCLAIMED.
    TO THE MAXIMUM EXTENT PERMITTED NOT PROHIBITED BY LAW, NEITHER RENESAS ELECTRONICS CORPORATION NOR
    ANY OF ITS AFFILIATED COMPANIES SHALL BE LIABLE FOR ANY DIRECT, INDIRECT, SPECIAL, INCIDENTAL OR
    CONSEQUENTIAL DAMAGES FOR ANY REASON RELATED TO THIS SOFTWARE, EVEN IF RENESAS OR ITS AFFILIATES HAVE
    BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGES.
    Renesas reserves the right, without notice, to make changes to this software and to discontinue the
    availability of this software. By using this software, you agree to the additional terms and conditions
    found by accessing the  following link:
    http://www.renesas.com/disclaimer

    Copyright (C) 2017 Renesas Electronics Corporation. All rights reserved.
**********************************************************************************************************************/

#include "r_fad.h"
#include "fad_sample.h"

/* Prototype declaration */
void FAD_FlashOperation();
void checkError(T_u4_FadErr fadErr);
void checkBlankError(T_u4_FadErr fadErr, T_u4_FadErr exp_fadErr, T_u4_FadAddr exp_fadAddr);
void R_FAD_DF_Read( T_u4_FadAddr FadAddr, T_u4* DataBuff , T_u1 Data_Length );
void flash_operation( T_u4_FadAddr base_addr , T_u1 data_length, T_u4* i_p_DataBuff);
void main();
unsigned char DFlash_BootFLG_InVaild[4] = {0x1E,00,00,00};//Need Alig 4
/* Data area definition */
extern T_u4 Flash_Data[16] = {0};
extern T_u4 Data_Flash_Read[16] = {0};


#define Block1_Start    (0xFF2002C0U)
#define Block1_End      (0xFF2002FFU)

#define Block2_Start    (0xFF200300U)
#define Block2_End      (0xFF20033FU)

#define READ_DATA_FLASH(addr) (*((volatile T_u2 *)(addr)))

/**********************************************************************************************************************
    Function Name   : main

    - Outline
        main function of sample program
    - Format
        void main(void);
    - Input parameter
        T_u2    Ali_flash;
        T_bl    Ali_flag;
    - Return
        non
**********************************************************************************************************************/

void FAD_FlashOperation()
{
    /* Defines local variables */
    T_st_HW_Init    hwInit;
    T_u4_FadErr     fadErr;
    T_u4_FadAddr    base_addr;
    T_u1            data_length;
    //T_u1            data_num;
   // T_u1            i;
    
    //data[0] = Ali_flash;
    //data[1] = Ali_flag;

    /* Release software protect */
    R_FAD_REG_FHVE3 = 0x00000001;
    R_FAD_REG_FHVE15 = 0x00000001;

    /* Hardware initialization */
    hwInit.bu2_InClock = 16;
    hwInit.bu2_CpuClock = 160;
    hwInit.bu1_EraseSuspendMode = R_FAD_SUSPRI_MODE;
    fadErr = R_FAD_HW_Init(&hwInit, R_FAD_NO_TIMEOUT);

    checkError(fadErr);

    data_length = sizeof(Flash_Data); //number of bytes
    //data_num = data_length / sizeof(Flash_Data[0]);
    base_addr = 0xFF20FF00;

    /* Erasure  BankA Block#1023 */
    fadErr = sample_DF_Erase(base_addr, R_FAD_NO_TIMEOUT);
    checkError(fadErr);

    fadErr = sample_DF_Write(base_addr, (T_p_DataBuff)&DFlash_BootFLG_InVaild[0], R_FAD_NO_TIMEOUT);
    checkError(fadErr);

    /* Sets software protect */
    R_FAD_REG_FHVE3 = 0x00000000;
    R_FAD_REG_FHVE15 = 0x00000000;
    
    return;
}

/**********************************************************************************************************************
    Function Name   : checkError

    - Outline
        Checks error
        If an error occur, enter unlimited loop.
    - Format
        void
            checkError(
                T_u4_FadErr fadErr
            );
    - Input parameter
        fadErr          : Error code
    - Return
        non
**********************************************************************************************************************/

void checkError(T_u4_FadErr fadErr)
{
    /* Defines local variables */
    T_u4_FadErr         err;
    T_u4_FadStsExInfo   errInfo;    /* Detail error information   */
    T_u4_FadStsExInfo   execCmd;    /* Command                    */

    if (R_FAD_IS_ERROR(fadErr))
    {
        err = R_FAD_GET_ERRCD(fadErr);

        switch (err)
        {
            case R_FAD_ERR_CMDLK:
                R_FAD_GetStatus(R_FAD_GET_FACI_NUMBER(fadErr), &errInfo);
                break;

            case R_FAD_ERR_BUSY:
                R_FAD_GetStatus(R_FAD_GET_FACI_NUMBER(fadErr), &execCmd);
                break;

            default:
                break;
        }
        while (1) ;
    }
}

/**********************************************************************************************************************
    Function Name   : checkBlankError

    - Outline
        Checks error for blank check
        If an error occur, enter unlimited loop.
    - Format
        void
            checkBlankError(
                T_u4_FadErr fadErr
                T_u4_FadErr exp_fadErr
                T_u4_FadErr exp_fadAddr
            );
    - Input parameter
        fadErr          : Error code
        exp_fadErr      : Expected Error code
        exp_fadAddr     : Expected Written address
    - Return
        non
**********************************************************************************************************************/

void checkBlankError(T_u4_FadErr fadErr, T_u4_FadErr exp_fadErr, T_u4_FadAddr exp_fadAddr)
{
    /* Defines local variables */
    T_u4_FadErr     err;
    T_u4_FadAddr    addr;   /* Written address */

    /* Error check */
    checkError(fadErr);

    err = R_FAD_GET_ERRCD(fadErr);
    if (err != exp_fadErr)
    {
        while (1) ;
    }

    if (err == R_FAD_BLKCHK1)   /* There is a programmed area */
    {
        R_FAD_GetStatus(R_FAD_GET_FACI_NUMBER(fadErr), &addr);

        if (addr != exp_fadAddr)
        {
            while (1) ;
        }
    }
}

/**********************************************************************************************************************
    Function Name   : R_FAD_DF_Read

    - Outline
        Read data from Data Flash
    - Format
        void
            R_FAD_DF_Read(
                T_u4_FadAddr    FadAddr,
                T_u4_FadAddr    DataBuff
                T_u1            Data_Length
            );
    - Input parameter
        FadAddr        : Start address to read
        DataBuff        : To write data
**********************************************************************************************************************/
void R_FAD_DF_Read( T_u4_FadAddr FadAddr, T_u4* DataBuff , T_u1 Data_Length )
{
    T_u4    i;
    T_u4    combinedata;
    T_u2    readdata1;
    T_u2    readdata2;
    T_u2    Data_Num  = Data_Length / 4;
    T_u1 remainder = Data_Length % 4;
    
    R_FAD_REG_EEPRDCYCL0 = 0xF3;   //Read cycle 3

    for( i=0 ; i < Data_Num ; i++ ){
	readdata1 = READ_DATA_FLASH(FadAddr);
	readdata2 = READ_DATA_FLASH(FadAddr+2);
        combinedata = (readdata2<<16) | readdata1 ;
	DataBuff[i] = combinedata;
        FadAddr += 4;
    }
    if (remainder == 2) {
        readdata1 = READ_DATA_FLASH(FadAddr);
        //DataBuff[Data_Num] = (readdata1 << 16) | 0;
	DataBuff[Data_Num] = readdata1 ;
    } else if (remainder == 1 || remainder == 3) {
        printf("Error: Invalid Data_Length value. Remainder is %d\n", remainder);
    }

}

/**********************************************************************************************************************
    Function Name   : flash_operation

    - Outline
        Operation of Blankcheck and write
    - Format
        void
            flash_operation(
                T_u4_FadAddr    base_addr,
                T_u1            data_length,
                T_u1*           i_p_DataBuff
            );
    - Input parameter
        base_addr      : Start address to write
        data_length    : Length of data
        i_p_DataBuff   : Data to be written
**********************************************************************************************************************/
void flash_operation( T_u4_FadAddr base_addr , T_u1 data_length, T_u4* i_p_DataBuff)
{
    T_u4_FadErr     fadErr = R_FAD_OK;
    T_u1            count;
    T_u1	    data_count = 0;

//    /* Writes to BankA Block#1023 Offset12 */
//    for( count = 0; count < data_length; count = count + 256 )
//    {
        fadErr = sample_CF_Write(base_addr, (T_p_DataBuff)&i_p_DataBuff[0], R_FAD_NO_TIMEOUT);
//	data_count += 1;
        checkError(fadErr);
//    }

    /* Shifts read mode BankA */
    fadErr = R_FAD_ShiftToReadMode(R_FAD_GET_FACI_NUMBER(fadErr), R_FAD_NO_TIMEOUT);
    checkError(fadErr);
    
    R_FAD_REG_FHVE3 = 0x00000000;
    R_FAD_REG_FHVE15 = 0x00000000;
    
    return;
}

