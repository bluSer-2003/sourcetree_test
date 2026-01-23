/**********************************************************************************************************************
    Program Name    : Flash Access Driver (FAD)

    File Name       : r_fad_iodefine.h
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

#ifndef _R_FAD_IODEFINE_H_
#define _R_FAD_IODEFINE_H_

/**********************************************************************************************************************
    For the definition of Flash Control
**********************************************************************************************************************/

/**********************************************************************************************************************
    Register for related Flash control
**********************************************************************************************************************/

struct __faci
{                       /* Module       */
    T_u1 FPMON;         /* FPMON        */
    T_u1 dummy100[15];  /* Reserved     */
    T_u1 FASTAT;        /* FASTAT       */
    T_u1 dummy101[3];   /* Reserved     */
    T_u1 FAEINT;        /* FAEINT       */
    T_u1 dummy102[27];  /* Reserved     */
    T_u4 FSADDR;        /* FSADDR       */
    T_u4 FEADDR;        /* FEADDR       */
    T_u1 dummy103[28];  /* Reserved     */
    T_u2 FCURAME;       /* FCURAME      */
    T_u1 dummy104[2];   /* Reserved     */
    T_u2 FRAMMCR;       /* FRAMMCR      */
    T_u1 dummy105[6];   /* Reserved     */
    T_u2 FPROTDR0;      /* FPROTDR0     */
    T_u1 dummy106[2];   /* Reserved     */
    T_u4 FPROTCR0;      /* FPROTCR0     */
    T_u4 FPROTCR1;      /* FPROTCR1     */
    T_u4 FPROTCR2;      /* FPROTCR2     */
    T_u4 FPROTCR3;      /* FPROTCR3     */
    T_u4 FPROTCR4;      /* FPROTCR4     */
    T_u1 dummy107[8];   /* Reserved     */
    T_u4 FSTATR;        /* FSTATR       */
    T_u2 FENTRYR;       /* FENTRYR      */
    T_u1 dummy108[6];   /* Reserved     */
    T_u2 FSUINITR;      /* FSUINITR     */
    T_u1 dummy109[2];   /* Reserved     */
    T_u1 FLKSTAT;       /* FLKSTAT      */
    T_u1 dummy110[3];   /* Reserved     */
    T_u4 FRFSTEADR;     /* FRFSTEADR    */
    T_u1 FRTSTAT;       /* FRTSTAT      */
    T_u1 dummy111[3];   /* Reserved     */
    T_u1 FRTEINT;       /* FRTEINT      */
    T_u1 dummy112[3];   /* Reserved     */
    T_u2 FCMDR;         /* FCMDR        */
    T_u1 dummy113[14];  /* Reserved     */
    T_u2 FRAMECCR;      /* FRAMECCR     */
    T_u1 dummy114[14];  /* Reserved     */
    T_u2 FPESTAT;       /* FPESTAT      */
    T_u1 dummy115[2];   /* Reserved     */
    T_u2 FCNFPRGCNT;    /* FCNFPRGCNT   */
    T_u1 dummy116[10];  /* Reserved     */
    T_u1 FBCCNT;        /* FBCCNT       */
    T_u1 dummy117[3];   /* Reserved     */
    T_u1 FBCSTAT;       /* FBCSTAT      */
    T_u1 dummy118[3];   /* Reserved     */
    T_u4 FPSADDR;       /* FPSADDR      */
    T_u1 dummy119[4];   /* Reserved     */
    T_u2 FCPSR;         /* FCPSR        */
    T_u1 dummy120[2];   /* Reserved     */
    T_u2 FPCKAR;        /* FPCKAR       */
    T_u1 dummy121[26];  /* Reserved     */
    T_u2 FECCEMON;      /* FECCEMON     */
    T_u1 dummy122[2];   /* Reserved     */
    T_u2 FECCTMD;       /* FECCTMD      */
    T_u1 dummy123[2];   /* Reserved     */
    T_u2 FDMYECC;       /* FDMYECC      */
};

/**********************************************************************************************************************
    FACI
**********************************************************************************************************************/

#ifdef __R_FAD_USE_STUB__   /* For Internal Test */
extern struct __faci bst_Faci0;
extern struct __faci bst_Faci1;
#define R_FAD_REG_FACI0         (*(volatile struct __faci *)&bst_Faci0)
#define R_FAD_REG_FACI1         (*(volatile struct __faci *)&bst_Faci1)
#else   /* For Formal Code */
#define R_FAD_REG_FACI0         (*(volatile struct __faci *)0xFFA10000U)
#define R_FAD_REG_FACI1         (*(volatile struct __faci *)0xFFA18000U)
#endif  /* __R_FAD_USE_STUB__ */

/**********************************************************************************************************************
    FCU Firmware Area Select Register
**********************************************************************************************************************/

#define R_FAD_REG_FCUFAREA      (*(volatile T_u1 *)0xFFC59008U)



/**********************************************************************************************************************
    For the definition of Device Control
**********************************************************************************************************************/

/**********************************************************************************************************************
    Data Flash Memory Read Cycle Setting Register
**********************************************************************************************************************/

#define R_FAD_REG_EEPRDCYCL0    (*(volatile T_u1 *)0xFFC59810U)
#define R_FAD_REG_EEPRDCYCL1    (*(volatile T_u1 *)0xFFC59910U)

/**********************************************************************************************************************
    Option Byte
**********************************************************************************************************************/

#define R_FAD_REG_OPBT0         (*(volatile T_u4 *)0xFFCD0030U)

#ifdef __R_FAD_USE_STUB__   /* For Internal Test */
extern T_u4 bu4_Opbt1;
#define R_FAD_REG_OPBT1         (*(volatile T_u4 *)&bu4_Opbt1)
#else   /* For Formal Code */
#define R_FAD_REG_OPBT1         (*(volatile T_u4 *)0xFFCD0034U)
#endif  /* __R_FAD_USE_STUB__ */

#define R_FAD_REG_OPBT2         (*(volatile T_u4 *)0xFFCD0038U)
#define R_FAD_REG_OPBT13        (*(volatile T_u4 *)0xFFCD0064U)
#define R_FAD_REG_OPBT14        (*(volatile T_u4 *)0xFFCD0068U)
#define R_FAD_REG_OPBT15        (*(volatile T_u4 *)0xFFCD006CU)

/**********************************************************************************************************************
    Product Name
**********************************************************************************************************************/

#define R_FAD_REG_PRDNAME1      (*(volatile T_u4 *)0xFFCD00D0U)
#define R_FAD_REG_PRDNAME2      (*(volatile T_u4 *)0xFFCD00D4U)
#define R_FAD_REG_PRDNAME3      (*(volatile T_u4 *)0xFFCD00D8U)
#define R_FAD_REG_PRDNAME4      (*(volatile T_u4 *)0xFFCD00DCU)

/**********************************************************************************************************************
    Related Clock
**********************************************************************************************************************/

#define R_FAD_REG_CLKD0DIV      (*(volatile T_u4 *)0xFFF88800U)

/**********************************************************************************************************************
    Reset Vector
**********************************************************************************************************************/

#define R_FAD_REG_GREG8         (*(volatile T_u4 *)0xFFCD0020U)


/**********************************************************************************************************************
    Related FLMD
**********************************************************************************************************************/

#define R_FAD_REG_FLMDCNT       (*(volatile T_u4 *)0xFFA00000U)
#define R_FAD_REG_FLMDPCMD      (*(volatile T_u4 *)0xFFA00004U)
#define R_FAD_REG_FLMDPS        (*(volatile T_u4 *)0xFFA00008U)


/**********************************************************************************************************************
    Related to Write and Erase Protect of Flash Memory
**********************************************************************************************************************/

#define R_FAD_REG_FHVE3         (*(volatile T_u4 *)0xFFF82410U)
#define R_FAD_REG_FHVE15        (*(volatile T_u4 *)0xFFF8A430U)

/**********************************************************************************************************************
    Authenticate ID of SELFID
**********************************************************************************************************************/

#define R_FAD_REG_SELFID        ((volatile T_u4 *)0xFFA08000U)
#define R_FAD_REG_SELFID0       (*(volatile T_u4 *)0xFFA08000U)
#define R_FAD_REG_SELFID1       (*(volatile T_u4 *)0xFFA08004U)
#define R_FAD_REG_SELFID2       (*(volatile T_u4 *)0xFFA08008U)
#define R_FAD_REG_SELFID3       (*(volatile T_u4 *)0xFFA0800CU)
#define R_FAD_REG_SELFID4       (*(volatile T_u4 *)0xFFA08010U)
#define R_FAD_REG_SELFID5       (*(volatile T_u4 *)0xFFA08014U)
#define R_FAD_REG_SELFID6       (*(volatile T_u4 *)0xFFA08018U)
#define R_FAD_REG_SELFID7       (*(volatile T_u4 *)0xFFA0801CU)

/**********************************************************************************************************************
    ID Status for Authenticate ID
**********************************************************************************************************************/

#define R_FAD_REG_IDSTATUS      (*(volatile T_u4 *)0xFFA080ACU)


/* For Security Part Begin */

/**********************************************************************************************************************
    Authenticate ID for Security
**********************************************************************************************************************/

#define R_FAD_REG_CFRDID        ((volatile T_u4 *)0xFFA08020U)      /* Pointer for CFRDID */
#define R_FAD_REG_CFRDID0       (*(volatile T_u4 *)0xFFA08020U)
#define R_FAD_REG_CFRDID1       (*(volatile T_u4 *)0xFFA08024U)
#define R_FAD_REG_CFRDID2       (*(volatile T_u4 *)0xFFA08028U)
#define R_FAD_REG_CFRDID3       (*(volatile T_u4 *)0xFFA0802CU)
#define R_FAD_REG_CFRDID4       (*(volatile T_u4 *)0xFFA08030U)
#define R_FAD_REG_CFRDID5       (*(volatile T_u4 *)0xFFA08034U)
#define R_FAD_REG_CFRDID6       (*(volatile T_u4 *)0xFFA08038U)
#define R_FAD_REG_CFRDID7       (*(volatile T_u4 *)0xFFA0803CU)

#define R_FAD_REG_DFRDID        ((volatile T_u4 *)0xFFA08040U)      /* Pointer for DFRDID */
#define R_FAD_REG_DFRDID0       (*(volatile T_u4 *)0xFFA08040U)
#define R_FAD_REG_DFRDID1       (*(volatile T_u4 *)0xFFA08044U)
#define R_FAD_REG_DFRDID2       (*(volatile T_u4 *)0xFFA08048U)
#define R_FAD_REG_DFRDID3       (*(volatile T_u4 *)0xFFA0804CU)
#define R_FAD_REG_DFRDID4       (*(volatile T_u4 *)0xFFA08050U)
#define R_FAD_REG_DFRDID5       (*(volatile T_u4 *)0xFFA08054U)
#define R_FAD_REG_DFRDID6       (*(volatile T_u4 *)0xFFA08058U)
#define R_FAD_REG_DFRDID7       (*(volatile T_u4 *)0xFFA0805CU)

#define R_FAD_REG_CFPEID        ((volatile T_u4 *)0xFFA08060U)      /* Pointer for CFPEID */
#define R_FAD_REG_CFPEID0       (*(volatile T_u4 *)0xFFA08060U)
#define R_FAD_REG_CFPEID1       (*(volatile T_u4 *)0xFFA08064U)
#define R_FAD_REG_CFPEID2       (*(volatile T_u4 *)0xFFA08068U)
#define R_FAD_REG_CFPEID3       (*(volatile T_u4 *)0xFFA0806CU)
#define R_FAD_REG_CFPEID4       (*(volatile T_u4 *)0xFFA08070U)
#define R_FAD_REG_CFPEID5       (*(volatile T_u4 *)0xFFA08074U)
#define R_FAD_REG_CFPEID6       (*(volatile T_u4 *)0xFFA08078U)
#define R_FAD_REG_CFPEID7       (*(volatile T_u4 *)0xFFA0807CU)

#define R_FAD_REG_DFPEID        ((volatile T_u4 *)0xFFA08080U)      /* Pointer for DFPEID */
#define R_FAD_REG_DFPEID0       (*(volatile T_u4 *)0xFFA08080U)
#define R_FAD_REG_DFPEID1       (*(volatile T_u4 *)0xFFA08084U)
#define R_FAD_REG_DFPEID2       (*(volatile T_u4 *)0xFFA08088U)
#define R_FAD_REG_DFPEID3       (*(volatile T_u4 *)0xFFA0808CU)
#define R_FAD_REG_DFPEID4       (*(volatile T_u4 *)0xFFA08090U)
#define R_FAD_REG_DFPEID5       (*(volatile T_u4 *)0xFFA08094U)
#define R_FAD_REG_DFPEID6       (*(volatile T_u4 *)0xFFA08098U)
#define R_FAD_REG_DFPEID7       (*(volatile T_u4 *)0xFFA0809CU)

/**********************************************************************************************************************
    Lock bit Protection Control for Security
**********************************************************************************************************************/

#define R_FAD_REG_FACI0FPROTCR0 (*(volatile T_u4 *)0xFFA10064U)
#define R_FAD_REG_FACI0FPROTCR1 (*(volatile T_u4 *)0xFFA10068U)
#define R_FAD_REG_FACI0FPROTCR2 (*(volatile T_u4 *)0xFFA1006CU)
#define R_FAD_REG_FACI0FPROTCR3 (*(volatile T_u4 *)0xFFA10070U)
#define R_FAD_REG_FACI0FPROTCR4 (*(volatile T_u4 *)0xFFA10074U)
#define R_FAD_REG_FACI1FPROTCR0 (*(volatile T_u4 *)0xFFA18064U)
#define R_FAD_REG_FACI1FPROTCR1 (*(volatile T_u4 *)0xFFA18068U)
#define R_FAD_REG_FACI1FPROTCR2 (*(volatile T_u4 *)0xFFA1806CU)
#define R_FAD_REG_FACI1FPROTCR3 (*(volatile T_u4 *)0xFFA18070U)
#define R_FAD_REG_FACI1FPROTCR4 (*(volatile T_u4 *)0xFFA18074U)

/* For Security Part End */


#endif  /* _R_FAD_IODEFINE_H_ */
