/******************************************************************************* 
* DISCLAIMER 
* This software is supplied by Renesas Electronics Corporation and is only  
* intended for use with Renesas products. No other uses are authorized. This  
* software is owned by Renesas Electronics Corporation and is protected under 
* all applicable laws, including copyright laws. 
* THIS SOFTWARE IS PROVIDED "AS IS" AND RENESAS MAKES NO WARRANTIES REGARDING 
* THIS SOFTWARE, WHETHER EXPRESS, IMPLIED OR STATUTORY, INCLUDING BUT NOT 
* LIMITED TO WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE  
* AND NON-INFRINGEMENT. ALL SUCH WARRANTIES ARE EXPRESSLY DISCLAIMED. 
* TO THE MAXIMUM EXTENT PERMITTED NOT PROHIBITED BY LAW, NEITHER RENESAS  
* ELECTRONICS CORPORATION NOR ANY OF ITS AFFILIATED COMPANIES SHALL BE LIABLE  
* FOR ANY DIRECT, INDIRECT, SPECIAL, INCIDENTAL OR CONSEQUENTIAL DAMAGES FOR 
* ANY REASON RELATED TO THIS SOFTWARE, EVEN IF RENESAS OR ITS AFFILIATES HAVE 
* BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGES. 
* Renesas reserves the right, without notice, to make changes to this software 
* and to discontinue the availability of this software. By using this software, 
* you agree to the additional terms and conditions found by accessing the  
* following link: 
* http://www.renesas.com/disclaimer 
* 
* Copyright (C) 2012, 2014 Renesas Electronics Corporation. All rights reserved.     
*******************************************************************************/
#ifndef R_ADC_REG_H
#define R_ADC_REG_H

/*****************************************************************************
 Includes   <System Includes> , "Project Includes"
 *****************************************************************************/
#include "r_compiler.h"

/*****************************************************************************
 Macro definitions
 *****************************************************************************/
#define ADC0_base                               0xFFF91000UL
#define ADC1_base                               0xFFF92000UL

#define ADCC0ADSYNSTCR                          REG08(ADC0_base+0x0300UL)
#define ADCC0ADTSYNSTCR                         REG08(ADC0_base+0x0304UL)

#define VCR(n,j)                                REG32((n)+0x0000UL+(j)*0x04UL)
#define DR(n,j)                                 REG32((n)+0x0100UL+(j)*0x04UL)
#define DIR(n,j)                                REG32((n)+0x0200UL+(j)*0x04UL)

#define ADHALTR(n)                              REG08((n)+0x0380UL)
#define ADCR1(n)                                REG08((n)+0x0384UL)
#define MPXCURCR(n)                             REG08((n)+0x0388UL)
#define MPXCURR(n)                              REG32((n)+0x038CUL)
#define MPXOWR(n)                               REG08((n)+0x0390UL)
#define ADCR2(n)                                REG08((n)+0x0398UL)
#define ADENDP0(n)                              REG08((n)+0x03A0UL)

#define SFTCR(n)                                REG08((n)+0x03C0UL)
#define TDCR(n)                                 REG08((n)+0x03C4UL)
#define ODCR(n)                                 REG32((n)+0x03C8UL)
#define ULLMTBR0(n)                             REG32((n)+0x03CCUL)
#define ULLMTBR1(n)                             REG32((n)+0x03D0UL)
#define ULLMTBR2(n)                             REG32((n)+0x03D4UL)
#define ECR(n)                                  REG08((n)+0x03D8UL)
#define ULER(n)                                 REG08((n)+0x03DCUL)
#define OWER(n)                                 REG08((n)+0x03E0UL)
#define PER(n)                                  REG08((n)+0x03E4UL)
#define IDER(n)                                 REG08((n)+0x03E8UL)

#define SGSTCR(n,x)                             REG08((n)+0x0480UL+(x)*0x80UL)
#define ADTSTCR(n,y)                            REG08((n)+0x0488UL+(y)*0x80UL)
#define ADTENDCR(n,y)                           REG08((n)+0x048CUL+(y)*0x80UL)
#define SGCR(n,x)                               REG08((n)+0x0490UL+(x)*0x80UL)
#define SGVCSP(n,x)                             REG08((n)+0x0494UL+(x)*0x80UL)
#define SGVCEP(n,x)                             REG08((n)+0x0498UL+(x)*0x80UL)
#define SGMCYCR(n,x)                            REG08((n)+0x049CUL+(x)*0x80UL)
#define SGSR(n,x)                               REG08((n)+0x04A4UL+(x)*0x80UL)
#define ADTIPR(n,y)                             REG32((n)+0x04A8UL+(y)*0x80UL)
#define ADTPRR(n,y)                             REG32((n)+0x04ACUL+(y)*0x80UL)
#define ULLMSR(n,x)                             REG08((n)+0x04B0UL+(x)*0x80UL)

/*****************************************************************************
 Typedef definitions
 *****************************************************************************/

/*****************************************************************************
 Global variables
 *****************************************************************************/

/*****************************************************************************
 Global functions
 *****************************************************************************/

#endif
