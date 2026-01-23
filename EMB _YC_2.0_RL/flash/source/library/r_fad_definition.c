/**********************************************************************************************************************
    Program Name    : Flash Access Driver (FAD)

    File Name       : r_fad_definition.c
    Program Version : V2.00
    File Revision   : $Rev$
    File Date       : $Date$
    Device(s)       : RV40 Flash based RH850 microcontroller
    Description     : 
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

/**********************************************************************************************************************
    Definition of the external variable
**********************************************************************************************************************/

T_u4    bu4_CommandArea;    /* Address for the area of issuing command                  */
T_u4    bu4_FaciBase;       /* Base address of FACI                                     */
T_u4    bu4_FCPSR;       /* Erase suspend mode                                       */
T_u4    bu4_FRDY1Loop;      /* The number of the roop of waiting FRDY1                  */
T_u4    bu4_DBFULL0Loop;    /* The number of the roop of waiting for DBFULL0            */
T_u4    bu4_27uWaitLoop;    /* The number of the roop of waiting 2.7us                  */
T_u4    bu4_IcacheLoop;     /* The number of the roop of clearing the instruction cache */

/**********************************************************************************************************************
    Definition of the external variable for STUB
**********************************************************************************************************************/
#ifdef __R_FAD_USE_STUB__

struct __faci   bst_Faci0;
struct __faci   bst_Faci1;
T_u4    bu4_Opbt1;
T_u4    bu4_ReturnFcutrans;
T_bl    bl1_GetStatusStub;
T_u4    bu4_IndexGetStatusStub;
T_u4    bu4_StatusData[5];

#endif  /* __R_FAD_USE_STUB__ */
