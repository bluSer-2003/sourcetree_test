/**********************************************************************************************************************
    File Name       : initsct.c
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

/* section information */
typedef struct {
    unsigned long dest;     /* Destination Address    */
    unsigned long src;      /* Source Address        */
    unsigned long size;     /* Section Size            */
} SEC_INFO;

//#pragma ghs section text=".startup"

/**********************************************************************************************************************
    Function Name   : _INITSCT_RH

    - Outline
        Copies initialization data on ROM to RAM
        Clears RAM
        This is GHS sample.
**********************************************************************************************************************/

void _INITSCT_RH(void *p_sinfo_copy, void *p_einfo_copy, void *p_sinfo_clear, void *p_einfo_clear)
{
    SEC_INFO        *p_info;
    SEC_INFO        *p_einfo;
    unsigned long   n;
    unsigned char   *p;
    unsigned char   *q;

    /* COPY (ROM->RAM) */
    p_info = (SEC_INFO *)p_sinfo_copy;
    p_einfo = (SEC_INFO *)p_einfo_copy;
    while (p_info < p_einfo)
    {
        if (p_info->size != 0)
        {
            n = p_info->size;
            p = (unsigned char *)p_info->src;
            q = (unsigned char *)p_info->dest;
            while (n--)
            {
                *q++ = *p++;
            }
        }
        p_info++;
    }
    
    /* CLEAR */
    p_info = (SEC_INFO *)p_sinfo_clear;
    p_einfo = (SEC_INFO *)p_einfo_clear;
    while (p_info < p_einfo)
    {
        if (p_info->size != 0)
        {
            n = p_info->size;
            p = (unsigned char *)p_info->dest;
            while (n--)
            {
                *p++ = 0;
            }
        }
        p_info++;
    }
    
    return;
}
