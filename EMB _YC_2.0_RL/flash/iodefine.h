/******************************************************************************/
/* DISCLAIMER                                                                 */
/* This software is supplied by Renesas Electronics Corporation and is only   */
/* intended for use with Renesas products. No other uses are authorized.This  */
/* software is owned by Renesas Electronics Corporation and is protected      */
/* under all applicable laws, including copyright laws.                       */
/* THIS SOFTWARE IS PROVIDED "AS IS" AND RENESAS MAKES NO WARRANTIES          */
/* REGARDING THIS SOFTWARE, WHETHER EXPRESS, IMPLIED OR STATUTORY, INCLUDING  */
/* BUT NOT LIMITED TO WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR */
/* PURPOSE AND NON-INFRINGEMENT.  ALL SUCH WARRANTIES ARE EXPRESSLY           */
/* DISCLAIMED.                                                                */
/* TO THE MAXIMUM EXTENT PERMITTED NOT PROHIBITED BY LAW, NEITHER RENESAS     */
/* ELECTRONICS CORPORATION NOR ANY OF ITS AFFILIATED COMPANIES SHALL BE       */
/* LIABLE FOR ANY DIRECT, INDIRECT, SPECIAL, INCIDENTAL OR CONSEQUENTIAL      */
/* DAMAGES FOR ANY REASON RELATED TO THIS SOFTWARE, EVEN IF RENESAS OR ITS    */
/* AFFILIATES HAVE BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGES.           */
/* Renesas reserves the right, without notice, to make changes to this        */
/* software and to discontinue the availability of this software.             */
/* By using this software, you agree to the additional terms and conditions   */
/* found by accessing the following link:                                     */
/* www.renesas.com/disclaimer                                                 */
/*                                                                            */
/* Device     : RH/RH850G3M/R7F701374xAFP                                     */
/* File Name  : iodefine.h                                                    */
/* Abstract   : Definition of I/O Register                                    */
/* History    : V1.30  [Device File version]                                  */
/* Options    : -df=C:\Program Files (x86)\Renesas Electronics\CS+\CC\Device\ */
/*              RH850\Devicefile\DR7F701374.DVF -o=D:\FAD\Data_Flash\iodefine */
/*              .h -def=off -f                                                */
/* Date       : 2024/11/23                                                    */
/* Version    : V1.19.00.01  [df2iodef.exe version]                           */
/* This is a typical example.                                                 */
/*                                                                            */
/******************************************************************************/
#ifndef __R7F701374xAFPIODEFINE_HEADER__
#define __R7F701374xAFPIODEFINE_HEADER__

typedef struct
{
    unsigned char bit00:1;
    unsigned char bit01:1;
    unsigned char bit02:1;
    unsigned char bit03:1;
    unsigned char bit04:1;
    unsigned char bit05:1;
    unsigned char bit06:1;
    unsigned char bit07:1;
} __bitf_T;

#define  L 0
#define  H 1
#define LL 0
#define LH 1
#define HL 2
#define HH 3

struct __tag0
{                                                          /* Bit Access       */
    unsigned char  PRS0:1;                                 /* PRS0             */
    unsigned char  PRS1:1;                                 /* PRS1             */
    unsigned char  PRS2:1;                                 /* PRS2             */
    unsigned char  :2;                                     /* Reserved Bits    */
    unsigned char  NFSTS0:1;                               /* NFSTS0           */
    unsigned char  NFSTS1:1;                               /* NFSTS1           */
    unsigned char  :1;                                     /* Reserved Bits    */
};
struct __tag1
{                                                          /* Bit Access       */
    unsigned char  NFENL0:1;                               /* NFENL0           */
    unsigned char  NFENL1:1;                               /* NFENL1           */
    unsigned char  :6;                                     /* Reserved Bits    */
};
struct __tag2
{                                                          /* Bit Access       */
    unsigned char  NFENL0:1;                               /* NFENL0           */
    unsigned char  NFENL1:1;                               /* NFENL1           */
    unsigned char  NFENL2:1;                               /* NFENL2           */
    unsigned char  NFENL3:1;                               /* NFENL3           */
    unsigned char  NFENL4:1;                               /* NFENL4           */
    unsigned char  NFENL5:1;                               /* NFENL5           */
    unsigned char  NFENL6:1;                               /* NFENL6           */
    unsigned char  NFENL7:1;                               /* NFENL7           */
};
struct __tag3
{                                                          /* Bit Access       */
    unsigned char  INTR0:1;                                /* INTR0            */
    unsigned char  INTF0:1;                                /* INTF0            */
    unsigned char  INTL0:1;                                /* INTL0            */
    unsigned char  :5;                                     /* Reserved Bits    */
};
struct __tag4
{                                                          /* Bit Access       */
    unsigned char  INTR1:1;                                /* INTR1            */
    unsigned char  INTF1:1;                                /* INTF1            */
    unsigned char  INTL1:1;                                /* INTL1            */
    unsigned char  :5;                                     /* Reserved Bits    */
};
struct __tag5
{                                                          /* Bit Access       */
    unsigned char  INTR2:1;                                /* INTR2            */
    unsigned char  INTF2:1;                                /* INTF2            */
    unsigned char  INTL2:1;                                /* INTL2            */
    unsigned char  :5;                                     /* Reserved Bits    */
};
struct __tag6
{                                                          /* Bit Access       */
    unsigned char  INTR3:1;                                /* INTR3            */
    unsigned char  INTF3:1;                                /* INTF3            */
    unsigned char  INTL3:1;                                /* INTL3            */
    unsigned char  :5;                                     /* Reserved Bits    */
};
struct __tag7
{                                                          /* Bit Access       */
    unsigned char  INTR4:1;                                /* INTR4            */
    unsigned char  INTF4:1;                                /* INTF4            */
    unsigned char  INTL4:1;                                /* INTL4            */
    unsigned char  :5;                                     /* Reserved Bits    */
};
struct __tag8
{                                                          /* Bit Access       */
    unsigned char  INTR5:1;                                /* INTR5            */
    unsigned char  INTF5:1;                                /* INTF5            */
    unsigned char  INTL5:1;                                /* INTL5            */
    unsigned char  :5;                                     /* Reserved Bits    */
};
struct __tag9
{                                                          /* Bit Access       */
    unsigned char  INTR6:1;                                /* INTR6            */
    unsigned char  INTF6:1;                                /* INTF6            */
    unsigned char  INTL6:1;                                /* INTL6            */
    unsigned char  :5;                                     /* Reserved Bits    */
};
struct __tag10
{                                                          /* Bit Access       */
    unsigned char  INTR7:1;                                /* INTR7            */
    unsigned char  INTF7:1;                                /* INTF7            */
    unsigned char  INTL7:1;                                /* INTL7            */
    unsigned char  :5;                                     /* Reserved Bits    */
};
struct __tag11
{                                                          /* Bit Access       */
    unsigned char  INTR0:1;                                /* INTR0            */
    unsigned char  INTF0:1;                                /* INTF0            */
    unsigned char  :6;                                     /* Reserved Bits    */
};
struct __tag12
{                                                          /* Bit Access       */
    unsigned char  INTR1:1;                                /* INTR1            */
    unsigned char  INTF1:1;                                /* INTF1            */
    unsigned char  :6;                                     /* Reserved Bits    */
};
struct __tag13
{                                                          /* Bit Access       */
    unsigned char  :7;                                     /* Reserved Bits    */
    unsigned char  BYPS0:1;                                /* BYPS0            */
};
struct __tag14
{                                                          /* Bit Access       */
    unsigned char  :7;                                     /* Reserved Bits    */
    unsigned char  BYPS1:1;                                /* BYPS1            */
};
struct __tag15
{                                                          /* Bit Access       */
    unsigned char  :7;                                     /* Reserved Bits    */
    unsigned char  BYPS2:1;                                /* BYPS2            */
};
struct __tag16
{                                                          /* Bit Access       */
    unsigned char  :7;                                     /* Reserved Bits    */
    unsigned char  BYPS3:1;                                /* BYPS3            */
};
struct __tag17
{                                                          /* Bit Access       */
    unsigned char  :7;                                     /* Reserved Bits    */
    unsigned char  BYPS4:1;                                /* BYPS4            */
};
struct __tag18
{                                                          /* Bit Access       */
    unsigned char  :7;                                     /* Reserved Bits    */
    unsigned char  BYPS5:1;                                /* BYPS5            */
};
struct __tag19
{                                                          /* Bit Access       */
    unsigned char  :7;                                     /* Reserved Bits    */
    unsigned char  BYPS6:1;                                /* BYPS6            */
};
struct __tag20
{                                                          /* Bit Access       */
    unsigned char  :7;                                     /* Reserved Bits    */
    unsigned char  BYPS7:1;                                /* BYPS7            */
};
struct __tag21
{                                                          /* Bit Access       */
    unsigned char  MBS:1;                                  /* MBS              */
    unsigned char  JOBE:1;                                 /* JOBE             */
    unsigned char  :3;                                     /* Reserved Bits    */
    unsigned char  RXE:1;                                  /* RXE              */
    unsigned char  TXE:1;                                  /* TXE              */
    unsigned char  PWR:1;                                  /* PWR              */
};
struct __tag22
{                                                          /* Bit Access       */
    unsigned char  E:1;                                    /* E                */
    unsigned char  IRE:1;                                  /* IRE              */
    unsigned char  :6;                                     /* Reserved Bits    */
};
struct __tag23
{                                                          /* Bit Access       */
    unsigned char  R0:1;                                   /* R0               */
    unsigned char  W0:1;                                   /* W0               */
    unsigned char  X0:1;                                   /* X0               */
    unsigned char  :1;                                     /* Reserved Bits    */
    unsigned char  R1:1;                                   /* R1               */
    unsigned char  W1:1;                                   /* W1               */
    unsigned char  X1:1;                                   /* X1               */
    unsigned char  :1;                                     /* Reserved Bits    */
};
struct __tag24
{                                                          /* Bit Access       */
    unsigned char  :2;                                     /* Reserved Bits    */
    unsigned char  X0:1;                                   /* X0               */
    unsigned char  :3;                                     /* Reserved Bits    */
    unsigned char  X1:1;                                   /* X1               */
    unsigned char  :1;                                     /* Reserved Bits    */
};
struct __tag25
{                                                          /* Bit Access       */
    unsigned char  R0:1;                                   /* R0               */
    unsigned char  W0:1;                                   /* W0               */
    unsigned char  :2;                                     /* Reserved Bits    */
    unsigned char  R1:1;                                   /* R1               */
    unsigned char  W1:1;                                   /* W1               */
    unsigned char  :2;                                     /* Reserved Bits    */
};
struct __tag26
{                                                          /* Bit Access       */
    unsigned char  :4;                                     /* Reserved Bits    */
    unsigned char  R1:1;                                   /* R1               */
    unsigned char  W1:1;                                   /* W1               */
    unsigned char  :2;                                     /* Reserved Bits    */
};
struct __tag27
{                                                          /* Bit Access       */
    unsigned char  R0:1;                                   /* R0               */
    unsigned char  W0:1;                                   /* W0               */
    unsigned char  :6;                                     /* Reserved Bits    */
};
union __tag28
{                                                          /* IOR              */
    unsigned long  UINT32;                                 /* 32-bit Access    */
    unsigned short UINT16[2];                              /* 16-bit Access    */
    unsigned char  UINT8[4];                               /* 8-bit Access     */
};
union __tag29
{                                                          /* IOR              */
    unsigned char  UINT8;                                  /* 8-bit Access     */
    struct __tag0 BIT;                                     /* Bit Access       */
};
union __tag30
{                                                          /* IOR              */
    unsigned char  UINT8;                                  /* 8-bit Access     */
    struct __tag1 BIT;                                     /* Bit Access       */
};
union __tag31
{                                                          /* IOR              */
    unsigned char  UINT8;                                  /* 8-bit Access     */
    struct __tag2 BIT;                                     /* Bit Access       */
};
union __tag32
{                                                          /* IOR              */
    unsigned char  UINT8;                                  /* 8-bit Access     */
    struct __tag3 BIT;                                     /* Bit Access       */
};
union __tag33
{                                                          /* IOR              */
    unsigned char  UINT8;                                  /* 8-bit Access     */
    struct __tag4 BIT;                                     /* Bit Access       */
};
union __tag34
{                                                          /* IOR              */
    unsigned char  UINT8;                                  /* 8-bit Access     */
    struct __tag5 BIT;                                     /* Bit Access       */
};
union __tag35
{                                                          /* IOR              */
    unsigned char  UINT8;                                  /* 8-bit Access     */
    struct __tag6 BIT;                                     /* Bit Access       */
};
union __tag36
{                                                          /* IOR              */
    unsigned char  UINT8;                                  /* 8-bit Access     */
    struct __tag7 BIT;                                     /* Bit Access       */
};
union __tag37
{                                                          /* IOR              */
    unsigned char  UINT8;                                  /* 8-bit Access     */
    struct __tag8 BIT;                                     /* Bit Access       */
};
union __tag38
{                                                          /* IOR              */
    unsigned char  UINT8;                                  /* 8-bit Access     */
    struct __tag9 BIT;                                     /* Bit Access       */
};
union __tag39
{                                                          /* IOR              */
    unsigned char  UINT8;                                  /* 8-bit Access     */
    struct __tag10 BIT;                                    /* Bit Access       */
};
union __tag40
{                                                          /* IOR              */
    unsigned char  UINT8;                                  /* 8-bit Access     */
    struct __tag11 BIT;                                    /* Bit Access       */
};
union __tag41
{                                                          /* IOR              */
    unsigned char  UINT8;                                  /* 8-bit Access     */
    struct __tag12 BIT;                                    /* Bit Access       */
};
union __tag42
{                                                          /* IOR              */
    unsigned char  UINT8;                                  /* 8-bit Access     */
    struct __tag13 BIT;                                    /* Bit Access       */
};
union __tag43
{                                                          /* IOR              */
    unsigned char  UINT8;                                  /* 8-bit Access     */
    struct __tag14 BIT;                                    /* Bit Access       */
};
union __tag44
{                                                          /* IOR              */
    unsigned char  UINT8;                                  /* 8-bit Access     */
    struct __tag15 BIT;                                    /* Bit Access       */
};
union __tag45
{                                                          /* IOR              */
    unsigned char  UINT8;                                  /* 8-bit Access     */
    struct __tag16 BIT;                                    /* Bit Access       */
};
union __tag46
{                                                          /* IOR              */
    unsigned char  UINT8;                                  /* 8-bit Access     */
    struct __tag17 BIT;                                    /* Bit Access       */
};
union __tag47
{                                                          /* IOR              */
    unsigned char  UINT8;                                  /* 8-bit Access     */
    struct __tag18 BIT;                                    /* Bit Access       */
};
union __tag48
{                                                          /* IOR              */
    unsigned char  UINT8;                                  /* 8-bit Access     */
    struct __tag19 BIT;                                    /* Bit Access       */
};
union __tag49
{                                                          /* IOR              */
    unsigned char  UINT8;                                  /* 8-bit Access     */
    struct __tag20 BIT;                                    /* Bit Access       */
};
union __tag50
{                                                          /* IOR              */
    unsigned char  UINT8;                                  /* 8-bit Access     */
    struct __tag21 BIT;                                    /* Bit Access       */
};
union __tag51
{                                                          /* IOR              */
    unsigned short UINT16;                                 /* 16-bit Access    */
    unsigned char  UINT8[2];                               /* 8-bit Access     */
    struct 
    {
        union
        {                                                  /* IOR              */
            unsigned char  UINT8;                          /*  8-bit Access    */
        } LBRP0;
        union
        {                                                  /* IOR              */
            unsigned char  UINT8;                          /*  8-bit Access    */
        } LBRP1;
    } REGS8;
};
union __tag52
{                                                          /* IOR              */
    unsigned short UINT16;                                 /* 16-bit Access    */
    unsigned char  UINT8[2];                               /* 8-bit Access     */
};
union __tag53
{                                                          /* IOR              */
    unsigned long  UINT32;                                 /* 32-bit Access    */
    unsigned short UINT16[2];                              /* 16-bit Access    */
    unsigned char  UINT8[4];                               /* 8-bit Access     */
    struct 
    {
        union
        {                                                  /* IOR              */
            unsigned short UINT16;                         /* 16-bit Access    */
        } FBTPL;
        union
        {                                                  /* IOR              */
            unsigned short UINT16;                         /* 16-bit Access    */
        } FBTPH;
    } REGS16;
    struct 
    {
        union
        {                                                  /* IOR              */
            unsigned char  UINT8;                          /* 8-bit Access     */
        } FBTPLL;
        union
        {                                                  /* IOR              */
            unsigned char  UINT8;                          /* 8-bit Access     */
        } FBTPLH;
        union
        {                                                  /* IOR              */
            unsigned char  UINT8;                          /* 8-bit Access     */
        } FBTPHL;
        union
        {                                                  /* IOR              */
            unsigned char  UINT8;                          /* 8-bit Access     */
        } FBTPHH;
    } REGS8;
};
union __tag54
{                                                          /* IOR              */
    unsigned long  UINT32;                                 /* 32-bit Access    */
    unsigned short UINT16[2];                              /* 16-bit Access    */
    unsigned char  UINT8[4];                               /* 8-bit Access     */
    struct 
    {
        union
        {                                                  /* IOR              */
            unsigned short UINT16;                         /* 16-bit Access    */
        } NBTPL;
        union
        {                                                  /* IOR              */
            unsigned short UINT16;                         /* 16-bit Access    */
        } NBTPH;
    } REGS16;
    struct 
    {
        union
        {                                                  /* IOR              */
            unsigned char  UINT8;                          /* 8-bit Access     */
        } NBTPLL;
        union
        {                                                  /* IOR              */
            unsigned char  UINT8;                          /* 8-bit Access     */
        } NBTPLH;
        union
        {                                                  /* IOR              */
            unsigned char  UINT8;                          /* 8-bit Access     */
        } NBTPHL;
        union
        {                                                  /* IOR              */
            unsigned char  UINT8;                          /* 8-bit Access     */
        } NBTPHH;
    } REGS8;
};
union __tag55
{                                                          /* IOR              */
    unsigned long  UINT32;                                 /* 32-bit Access    */
    unsigned char  UINT8[4];                               /* 8-bit Access     */
};
union __tag56
{                                                          /* IOR              */
    unsigned long  UINT32;                                 /* 32-bit Access    */
    unsigned short UINT16[2];                              /* 16-bit Access    */
};
union __tag57
{                                                          /* IOR              */
    unsigned char  UINT8;                                  /* 8-bit Access     */
    struct __tag22 BIT;                                    /* Bit Access       */
};
union __tag58
{                                                          /* IOR              */
    unsigned char  UINT8;                                  /* 8-bit Access     */
    struct __tag23 BIT;                                    /* Bit Access       */
};
union __tag59
{                                                          /* IOR              */
    unsigned char  UINT8;                                  /* 8-bit Access     */
    struct __tag24 BIT;                                    /* Bit Access       */
};
union __tag60
{                                                          /* IOR              */
    unsigned char  UINT8;                                  /* 8-bit Access     */
    struct __tag25 BIT;                                    /* Bit Access       */
};
union __tag61
{                                                          /* IOR              */
    unsigned char  UINT8;                                  /* 8-bit Access     */
    struct __tag26 BIT;                                    /* Bit Access       */
};
union __tag62
{                                                          /* IOR              */
    unsigned char  UINT8;                                  /* 8-bit Access     */
    struct __tag27 BIT;                                    /* Bit Access       */
};

struct __tag63
{                                                          /* Module           */
    unsigned long  FRPV;                                   /* FRPV             */
    union __tag28 FROC;                                    /* FROC             */
    unsigned char  dummy0[4];                              /* Reserved         */
    union __tag28 FROS;                                    /* FROS             */
    union __tag28 FRTEST1;                                 /* FRTEST1          */
    union __tag28 FRTEST2;                                 /* FRTEST2          */
    unsigned char  dummy1[4];                              /* Reserved         */
    union __tag28 FRLCK;                                   /* FRLCK            */
    union __tag28 FREIR;                                   /* FREIR            */
    union __tag28 FRSIR;                                   /* FRSIR            */
    union __tag28 FREILS;                                  /* FREILS           */
    union __tag28 FRSILS;                                  /* FRSILS           */
    union __tag28 FREIES;                                  /* FREIES           */
    union __tag28 FREIER;                                  /* FREIER           */
    union __tag28 FRSIES;                                  /* FRSIES           */
    union __tag28 FRSIER;                                  /* FRSIER           */
    union __tag28 FRILE;                                   /* FRILE            */
    union __tag28 FRT0C;                                   /* FRT0C            */
    union __tag28 FRT1C;                                   /* FRT1C            */
    union __tag28 FRSTPW1;                                 /* FRSTPW1          */
    union __tag28 FRSTPW2;                                 /* FRSTPW2          */
    unsigned char  dummy2[44];                             /* Reserved         */
    union __tag28 FRSUCC1;                                 /* FRSUCC1          */
    union __tag28 FRSUCC2;                                 /* FRSUCC2          */
    union __tag28 FRSUCC3;                                 /* FRSUCC3          */
    union __tag28 FRNEMC;                                  /* FRNEMC           */
    union __tag28 FRPRTC1;                                 /* FRPRTC1          */
    union __tag28 FRPRTC2;                                 /* FRPRTC2          */
    union __tag28 FRMHDC;                                  /* FRMHDC           */
    unsigned char  dummy3[4];                              /* Reserved         */
    union __tag28 FRGTUC1;                                 /* FRGTUC1          */
    union __tag28 FRGTUC2;                                 /* FRGTUC2          */
    union __tag28 FRGTUC3;                                 /* FRGTUC3          */
    union __tag28 FRGTUC4;                                 /* FRGTUC4          */
    union __tag28 FRGTUC5;                                 /* FRGTUC5          */
    union __tag28 FRGTUC6;                                 /* FRGTUC6          */
    union __tag28 FRGTUC7;                                 /* FRGTUC7          */
    union __tag28 FRGTUC8;                                 /* FRGTUC8          */
    union __tag28 FRGTUC9;                                 /* FRGTUC9          */
    union __tag28 FRGTUC10;                                /* FRGTUC10         */
    union __tag28 FRGTUC11;                                /* FRGTUC11         */
    unsigned char  dummy4[52];                             /* Reserved         */
    union __tag28 FRCCSV;                                  /* FRCCSV           */
    union __tag28 FRCCEV;                                  /* FRCCEV           */
    unsigned char  dummy5[8];                              /* Reserved         */
    union __tag28 FRSCV;                                   /* FRSCV            */
    union __tag28 FRMTCCV;                                 /* FRMTCCV          */
    union __tag28 FRRCV;                                   /* FRRCV            */
    union __tag28 FROCV;                                   /* FROCV            */
    union __tag28 FRSFS;                                   /* FRSFS            */
    union __tag28 FRSWNIT;                                 /* FRSWNIT          */
    union __tag28 FRACS;                                   /* FRACS            */
    unsigned char  dummy6[4];                              /* Reserved         */
    union __tag28 FRESID1;                                 /* FRESID1          */
    union __tag28 FRESID2;                                 /* FRESID2          */
    union __tag28 FRESID3;                                 /* FRESID3          */
    union __tag28 FRESID4;                                 /* FRESID4          */
    union __tag28 FRESID5;                                 /* FRESID5          */
    union __tag28 FRESID6;                                 /* FRESID6          */
    union __tag28 FRESID7;                                 /* FRESID7          */
    union __tag28 FRESID8;                                 /* FRESID8          */
    union __tag28 FRESID9;                                 /* FRESID9          */
    union __tag28 FRESID10;                                /* FRESID10         */
    union __tag28 FRESID11;                                /* FRESID11         */
    union __tag28 FRESID12;                                /* FRESID12         */
    union __tag28 FRESID13;                                /* FRESID13         */
    union __tag28 FRESID14;                                /* FRESID14         */
    union __tag28 FRESID15;                                /* FRESID15         */
    unsigned char  dummy7[4];                              /* Reserved         */
    union __tag28 FROSID1;                                 /* FROSID1          */
    union __tag28 FROSID2;                                 /* FROSID2          */
    union __tag28 FROSID3;                                 /* FROSID3          */
    union __tag28 FROSID4;                                 /* FROSID4          */
    union __tag28 FROSID5;                                 /* FROSID5          */
    union __tag28 FROSID6;                                 /* FROSID6          */
    union __tag28 FROSID7;                                 /* FROSID7          */
    union __tag28 FROSID8;                                 /* FROSID8          */
    union __tag28 FROSID9;                                 /* FROSID9          */
    union __tag28 FROSID10;                                /* FROSID10         */
    union __tag28 FROSID11;                                /* FROSID11         */
    union __tag28 FROSID12;                                /* FROSID12         */
    union __tag28 FROSID13;                                /* FROSID13         */
    union __tag28 FROSID14;                                /* FROSID14         */
    union __tag28 FROSID15;                                /* FROSID15         */
    unsigned char  dummy8[4];                              /* Reserved         */
    union __tag28 FRNMV1;                                  /* FRNMV1           */
    union __tag28 FRNMV2;                                  /* FRNMV2           */
    union __tag28 FRNMV3;                                  /* FRNMV3           */
    unsigned char  dummy9[324];                            /* Reserved         */
    union __tag28 FRMRC;                                   /* FRMRC            */
    union __tag28 FRFRF;                                   /* FRFRF            */
    union __tag28 FRFRFM;                                  /* FRFRFM           */
    union __tag28 FRFCL;                                   /* FRFCL            */
    union __tag28 FRMHDS;                                  /* FRMHDS           */
    union __tag28 FRLDTS;                                  /* FRLDTS           */
    union __tag28 FRFSR;                                   /* FRFSR            */
    union __tag28 FRMHDF;                                  /* FRMHDF           */
    union __tag28 FRTXRQ1;                                 /* FRTXRQ1          */
    union __tag28 FRTXRQ2;                                 /* FRTXRQ2          */
    union __tag28 FRTXRQ3;                                 /* FRTXRQ3          */
    union __tag28 FRTXRQ4;                                 /* FRTXRQ4          */
    union __tag28 FRNDAT1;                                 /* FRNDAT1          */
    union __tag28 FRNDAT2;                                 /* FRNDAT2          */
    union __tag28 FRNDAT3;                                 /* FRNDAT3          */
    union __tag28 FRNDAT4;                                 /* FRNDAT4          */
    union __tag28 FRMBSC1;                                 /* FRMBSC1          */
    union __tag28 FRMBSC2;                                 /* FRMBSC2          */
    union __tag28 FRMBSC3;                                 /* FRMBSC3          */
    union __tag28 FRMBSC4;                                 /* FRMBSC4          */
    unsigned char  dummy10[176];                           /* Reserved         */
    union __tag28 FRWRDS1;                                 /* FRWRDS1          */
    union __tag28 FRWRDS2;                                 /* FRWRDS2          */
    union __tag28 FRWRDS3;                                 /* FRWRDS3          */
    union __tag28 FRWRDS4;                                 /* FRWRDS4          */
    union __tag28 FRWRDS5;                                 /* FRWRDS5          */
    union __tag28 FRWRDS6;                                 /* FRWRDS6          */
    union __tag28 FRWRDS7;                                 /* FRWRDS7          */
    union __tag28 FRWRDS8;                                 /* FRWRDS8          */
    union __tag28 FRWRDS9;                                 /* FRWRDS9          */
    union __tag28 FRWRDS10;                                /* FRWRDS10         */
    union __tag28 FRWRDS11;                                /* FRWRDS11         */
    union __tag28 FRWRDS12;                                /* FRWRDS12         */
    union __tag28 FRWRDS13;                                /* FRWRDS13         */
    union __tag28 FRWRDS14;                                /* FRWRDS14         */
    union __tag28 FRWRDS15;                                /* FRWRDS15         */
    union __tag28 FRWRDS16;                                /* FRWRDS16         */
    union __tag28 FRWRDS17;                                /* FRWRDS17         */
    union __tag28 FRWRDS18;                                /* FRWRDS18         */
    union __tag28 FRWRDS19;                                /* FRWRDS19         */
    union __tag28 FRWRDS20;                                /* FRWRDS20         */
    union __tag28 FRWRDS21;                                /* FRWRDS21         */
    union __tag28 FRWRDS22;                                /* FRWRDS22         */
    union __tag28 FRWRDS23;                                /* FRWRDS23         */
    union __tag28 FRWRDS24;                                /* FRWRDS24         */
    union __tag28 FRWRDS25;                                /* FRWRDS25         */
    union __tag28 FRWRDS26;                                /* FRWRDS26         */
    union __tag28 FRWRDS27;                                /* FRWRDS27         */
    union __tag28 FRWRDS28;                                /* FRWRDS28         */
    union __tag28 FRWRDS29;                                /* FRWRDS29         */
    union __tag28 FRWRDS30;                                /* FRWRDS30         */
    union __tag28 FRWRDS31;                                /* FRWRDS31         */
    union __tag28 FRWRDS32;                                /* FRWRDS32         */
    union __tag28 FRWRDS33;                                /* FRWRDS33         */
    union __tag28 FRWRDS34;                                /* FRWRDS34         */
    union __tag28 FRWRDS35;                                /* FRWRDS35         */
    union __tag28 FRWRDS36;                                /* FRWRDS36         */
    union __tag28 FRWRDS37;                                /* FRWRDS37         */
    union __tag28 FRWRDS38;                                /* FRWRDS38         */
    union __tag28 FRWRDS39;                                /* FRWRDS39         */
    union __tag28 FRWRDS40;                                /* FRWRDS40         */
    union __tag28 FRWRDS41;                                /* FRWRDS41         */
    union __tag28 FRWRDS42;                                /* FRWRDS42         */
    union __tag28 FRWRDS43;                                /* FRWRDS43         */
    union __tag28 FRWRDS44;                                /* FRWRDS44         */
    union __tag28 FRWRDS45;                                /* FRWRDS45         */
    union __tag28 FRWRDS46;                                /* FRWRDS46         */
    union __tag28 FRWRDS47;                                /* FRWRDS47         */
    union __tag28 FRWRDS48;                                /* FRWRDS48         */
    union __tag28 FRWRDS49;                                /* FRWRDS49         */
    union __tag28 FRWRDS50;                                /* FRWRDS50         */
    union __tag28 FRWRDS51;                                /* FRWRDS51         */
    union __tag28 FRWRDS52;                                /* FRWRDS52         */
    union __tag28 FRWRDS53;                                /* FRWRDS53         */
    union __tag28 FRWRDS54;                                /* FRWRDS54         */
    union __tag28 FRWRDS55;                                /* FRWRDS55         */
    union __tag28 FRWRDS56;                                /* FRWRDS56         */
    union __tag28 FRWRDS57;                                /* FRWRDS57         */
    union __tag28 FRWRDS58;                                /* FRWRDS58         */
    union __tag28 FRWRDS59;                                /* FRWRDS59         */
    union __tag28 FRWRDS60;                                /* FRWRDS60         */
    union __tag28 FRWRDS61;                                /* FRWRDS61         */
    union __tag28 FRWRDS62;                                /* FRWRDS62         */
    union __tag28 FRWRDS63;                                /* FRWRDS63         */
    union __tag28 FRWRDS64;                                /* FRWRDS64         */
    union __tag28 FRWRHS1;                                 /* FRWRHS1          */
    union __tag28 FRWRHS2;                                 /* FRWRHS2          */
    union __tag28 FRWRHS3;                                 /* FRWRHS3          */
    unsigned char  dummy11[4];                             /* Reserved         */
    union __tag28 FRIBCM;                                  /* FRIBCM           */
    union __tag28 FRIBCR;                                  /* FRIBCR           */
    unsigned char  dummy12[232];                           /* Reserved         */
    union __tag28 FRRDDS1;                                 /* FRRDDS1          */
    union __tag28 FRRDDS2;                                 /* FRRDDS2          */
    union __tag28 FRRDDS3;                                 /* FRRDDS3          */
    union __tag28 FRRDDS4;                                 /* FRRDDS4          */
    union __tag28 FRRDDS5;                                 /* FRRDDS5          */
    union __tag28 FRRDDS6;                                 /* FRRDDS6          */
    union __tag28 FRRDDS7;                                 /* FRRDDS7          */
    union __tag28 FRRDDS8;                                 /* FRRDDS8          */
    union __tag28 FRRDDS9;                                 /* FRRDDS9          */
    union __tag28 FRRDDS10;                                /* FRRDDS10         */
    union __tag28 FRRDDS11;                                /* FRRDDS11         */
    union __tag28 FRRDDS12;                                /* FRRDDS12         */
    union __tag28 FRRDDS13;                                /* FRRDDS13         */
    union __tag28 FRRDDS14;                                /* FRRDDS14         */
    union __tag28 FRRDDS15;                                /* FRRDDS15         */
    union __tag28 FRRDDS16;                                /* FRRDDS16         */
    union __tag28 FRRDDS17;                                /* FRRDDS17         */
    union __tag28 FRRDDS18;                                /* FRRDDS18         */
    union __tag28 FRRDDS19;                                /* FRRDDS19         */
    union __tag28 FRRDDS20;                                /* FRRDDS20         */
    union __tag28 FRRDDS21;                                /* FRRDDS21         */
    union __tag28 FRRDDS22;                                /* FRRDDS22         */
    union __tag28 FRRDDS23;                                /* FRRDDS23         */
    union __tag28 FRRDDS24;                                /* FRRDDS24         */
    union __tag28 FRRDDS25;                                /* FRRDDS25         */
    union __tag28 FRRDDS26;                                /* FRRDDS26         */
    union __tag28 FRRDDS27;                                /* FRRDDS27         */
    union __tag28 FRRDDS28;                                /* FRRDDS28         */
    union __tag28 FRRDDS29;                                /* FRRDDS29         */
    union __tag28 FRRDDS30;                                /* FRRDDS30         */
    union __tag28 FRRDDS31;                                /* FRRDDS31         */
    union __tag28 FRRDDS32;                                /* FRRDDS32         */
    union __tag28 FRRDDS33;                                /* FRRDDS33         */
    union __tag28 FRRDDS34;                                /* FRRDDS34         */
    union __tag28 FRRDDS35;                                /* FRRDDS35         */
    union __tag28 FRRDDS36;                                /* FRRDDS36         */
    union __tag28 FRRDDS37;                                /* FRRDDS37         */
    union __tag28 FRRDDS38;                                /* FRRDDS38         */
    union __tag28 FRRDDS39;                                /* FRRDDS39         */
    union __tag28 FRRDDS40;                                /* FRRDDS40         */
    union __tag28 FRRDDS41;                                /* FRRDDS41         */
    union __tag28 FRRDDS42;                                /* FRRDDS42         */
    union __tag28 FRRDDS43;                                /* FRRDDS43         */
    union __tag28 FRRDDS44;                                /* FRRDDS44         */
    union __tag28 FRRDDS45;                                /* FRRDDS45         */
    union __tag28 FRRDDS46;                                /* FRRDDS46         */
    union __tag28 FRRDDS47;                                /* FRRDDS47         */
    union __tag28 FRRDDS48;                                /* FRRDDS48         */
    union __tag28 FRRDDS49;                                /* FRRDDS49         */
    union __tag28 FRRDDS50;                                /* FRRDDS50         */
    union __tag28 FRRDDS51;                                /* FRRDDS51         */
    union __tag28 FRRDDS52;                                /* FRRDDS52         */
    union __tag28 FRRDDS53;                                /* FRRDDS53         */
    union __tag28 FRRDDS54;                                /* FRRDDS54         */
    union __tag28 FRRDDS55;                                /* FRRDDS55         */
    union __tag28 FRRDDS56;                                /* FRRDDS56         */
    union __tag28 FRRDDS57;                                /* FRRDDS57         */
    union __tag28 FRRDDS58;                                /* FRRDDS58         */
    union __tag28 FRRDDS59;                                /* FRRDDS59         */
    union __tag28 FRRDDS60;                                /* FRRDDS60         */
    union __tag28 FRRDDS61;                                /* FRRDDS61         */
    union __tag28 FRRDDS62;                                /* FRRDDS62         */
    union __tag28 FRRDDS63;                                /* FRRDDS63         */
    union __tag28 FRRDDS64;                                /* FRRDDS64         */
    union __tag28 FRRDHS1;                                 /* FRRDHS1          */
    union __tag28 FRRDHS2;                                 /* FRRDHS2          */
    union __tag28 FRRDHS3;                                 /* FRRDHS3          */
    union __tag28 FRMBS;                                   /* FRMBS            */
    union __tag28 FROBCM;                                  /* FROBCM           */
    union __tag28 FROBCR;                                  /* FROBCR           */
    unsigned char  dummy13[232];                           /* Reserved         */
    union __tag28 FRITC;                                   /* FRITC            */
    union __tag28 FROTC;                                   /* FROTC            */
    union __tag28 FRIBA;                                   /* FRIBA            */
    union __tag28 FRFBA;                                   /* FRFBA            */
    union __tag28 FROBA;                                   /* FROBA            */
    union __tag28 FRIQC;                                   /* FRIQC            */
    union __tag28 FRUIR;                                   /* FRUIR            */
    union __tag28 FRUOR;                                   /* FRUOR            */
    union __tag28 FRITS;                                   /* FRITS            */
    union __tag28 FROTS;                                   /* FROTS            */
    union __tag28 FRAES;                                   /* FRAES            */
    union __tag28 FRAEA;                                   /* FRAEA            */
    union __tag28 FRDA0;                                   /* FRDA0            */
    union __tag28 FRDA1;                                   /* FRDA1            */
    union __tag28 FRDA2;                                   /* FRDA2            */
    union __tag28 FRDA3;                                   /* FRDA3            */
    unsigned char  dummy14[4];                             /* Reserved         */
    union __tag28 FRT2C;                                   /* FRT2C            */
};
struct __tag64
{                                                          /* Module           */
    unsigned long  EDSR0;                                  /* EDSR0            */
    unsigned char  dummy15[12];                            /* Reserved         */
    unsigned long  TDLAR0;                                 /* TDLAR0           */
    unsigned long  TDFAR0;                                 /* TDFAR0           */
    unsigned long  TDFXR0;                                 /* TDFXR0           */
    unsigned long  TDFFR0;                                 /* TDFFR0           */
    unsigned char  dummy16[16];                            /* Reserved         */
    unsigned long  RDLAR0;                                 /* RDLAR0           */
    unsigned long  RDFAR0;                                 /* RDFAR0           */
    unsigned long  RDFXR0;                                 /* RDFXR0           */
    unsigned long  RDFFR0;                                 /* RDFFR0           */
    unsigned char  dummy17[960];                           /* Reserved         */
    unsigned long  EDMR0;                                  /* EDMR0            */
    unsigned char  dummy18[4];                             /* Reserved         */
    unsigned long  EDTRR0;                                 /* EDTRR0           */
    unsigned char  dummy19[4];                             /* Reserved         */
    unsigned long  EDRRR0;                                 /* EDRRR0           */
    unsigned char  dummy20[20];                            /* Reserved         */
    unsigned long  EESR0;                                  /* EESR0            */
    unsigned char  dummy21[4];                             /* Reserved         */
    unsigned long  EESIPR0;                                /* EESIPR0          */
    unsigned char  dummy22[4];                             /* Reserved         */
    unsigned long  TRSCER0;                                /* TRSCER0          */
    unsigned char  dummy23[4];                             /* Reserved         */
    unsigned long  RMFCR0;                                 /* RMFCR0           */
    unsigned char  dummy24[12];                            /* Reserved         */
    unsigned long  FDR0;                                   /* FDR0             */
    unsigned char  dummy25[4];                             /* Reserved         */
    unsigned long  RMCR0;                                  /* RMCR0            */
    unsigned char  dummy26[4];                             /* Reserved         */
    unsigned long  RPADIR0;                                /* RPADIR0          */
    unsigned char  dummy27[4];                             /* Reserved         */
    unsigned long  FCFTR0;                                 /* FCFTR0           */
    unsigned char  dummy28[20];                            /* Reserved         */
    unsigned long  TFSR0;                                  /* TFSR0            */
    unsigned char  dummy29[4];                             /* Reserved         */
    unsigned long  RFSR0;                                  /* RFSR0            */
    unsigned char  dummy30[116];                           /* Reserved         */
    unsigned long  ECMR0;                                  /* ECMR0            */
    unsigned char  dummy31[4];                             /* Reserved         */
    unsigned long  RFLR0;                                  /* RFLR0            */
    unsigned char  dummy32[4];                             /* Reserved         */
    unsigned long  ECSR0;                                  /* ECSR0            */
    unsigned char  dummy33[4];                             /* Reserved         */
    unsigned long  ECSIPR0;                                /* ECSIPR0          */
    unsigned char  dummy34[4];                             /* Reserved         */
    unsigned long  PIR0;                                   /* PIR0             */
    unsigned char  dummy35[4];                             /* Reserved         */
    unsigned long  PLSR0;                                  /* PLSR0            */
    unsigned long  PIPR0;                                  /* PIPR0            */
    unsigned char  dummy36[36];                            /* Reserved         */
    unsigned long  APR0;                                   /* APR0             */
    unsigned long  MPR0;                                   /* MPR0             */
    unsigned long  PFTCR0;                                 /* PFTCR0           */
    unsigned long  PFRCR0;                                 /* PFRCR0           */
    unsigned long  TPAUSER0;                               /* TPAUSER0         */
    unsigned long  TPFRCR0;                                /* TPFRCR0          */
    unsigned long  BCFRR0;                                 /* BCFRR0           */
    unsigned long  CRBCFRR0;                               /* CRBCFRR0         */
    unsigned char  dummy37[60];                            /* Reserved         */
    unsigned long  EMR0;                                   /* EMR0             */
    unsigned char  dummy38[12];                            /* Reserved         */
    unsigned long  MAHR0;                                  /* MAHR0            */
    unsigned char  dummy39[4];                             /* Reserved         */
    unsigned long  MALR0;                                  /* MALR0            */
    unsigned char  dummy40[308];                           /* Reserved         */
    unsigned long  TROCR0;                                 /* TROCR0           */
    unsigned char  dummy41[4];                             /* Reserved         */
    unsigned long  CDCR0;                                  /* CDCR0            */
    unsigned char  dummy42[4];                             /* Reserved         */
    unsigned long  LCCR0;                                  /* LCCR0            */
    unsigned char  dummy43[44];                            /* Reserved         */
    unsigned long  CEFCR0;                                 /* CEFCR0           */
    unsigned char  dummy44[4];                             /* Reserved         */
    unsigned long  FRECR0;                                 /* FRECR0           */
    unsigned char  dummy45[4];                             /* Reserved         */
    unsigned long  TSFRCR0;                                /* TSFRCR0          */
    unsigned char  dummy46[4];                             /* Reserved         */
    unsigned long  TLFRCR0;                                /* TLFRCR0          */
    unsigned char  dummy47[4];                             /* Reserved         */
    unsigned long  RFCR0;                                  /* RFCR0            */
    unsigned char  dummy48[20];                            /* Reserved         */
    unsigned long  MAFCR0;                                 /* MAFCR0           */
    unsigned char  dummy49[132];                           /* Reserved         */
    unsigned long  ARSTR;                                  /* ARSTR            */
    unsigned long  TSU_CTRST;                              /* TSU_CTRST        */
    unsigned char  dummy50[40];                            /* Reserved         */
    unsigned long  TSU_FWSL0;                              /* TSU_FWSL0        */
    unsigned long  TSU_FWSL1;                              /* TSU_FWSL1        */
    unsigned long  TSU_FWSLC;                              /* TSU_FWSLC        */
    unsigned char  dummy51[20];                            /* Reserved         */
    unsigned long  TSU_FWSR;                               /* TSU_FWSR         */
    unsigned long  TSU_FWINMK;                             /* TSU_FWINMK       */
    unsigned long  TSU_VTAG0;                              /* TSU_VTAG0        */
    unsigned long  TSU_VTAG1;                              /* TSU_VTAG1        */
    unsigned long  TSU_ADSBSY;                             /* TSU_ADSBSY       */
    unsigned long  TSU_TEN;                                /* TSU_TEN          */
    unsigned char  dummy52[8];                             /* Reserved         */
    unsigned long  TSU_POST1;                              /* TSU_POST1        */
    unsigned long  TSU_POST2;                              /* TSU_POST2        */
    unsigned long  TSU_POST3;                              /* TSU_POST3        */
    unsigned long  TSU_POST4;                              /* TSU_POST4        */
    unsigned long  TXNLCR0;                                /* TXNLCR0          */
    unsigned long  TXALCR0;                                /* TXALCR0          */
    unsigned long  RXNLCR0;                                /* RXNLCR0          */
    unsigned long  RXALCR0;                                /* RXALCR0          */
    unsigned char  dummy53[16];                            /* Reserved         */
    unsigned long  TXNLCR1;                                /* TXNLCR1          */
    unsigned long  TXALCR1;                                /* TXALCR1          */
    unsigned long  RXNLCR1;                                /* RXNLCR1          */
    unsigned long  RXALCR1;                                /* RXALCR1          */
    unsigned char  dummy54[80];                            /* Reserved         */
    unsigned long  TSU_ADRH0;                              /* TSU_ADRH0        */
    unsigned long  TSU_ADRL0;                              /* TSU_ADRL0        */
    unsigned long  TSU_ADRH1;                              /* TSU_ADRH1        */
    unsigned long  TSU_ADRL1;                              /* TSU_ADRL1        */
    unsigned long  TSU_ADRH2;                              /* TSU_ADRH2        */
    unsigned long  TSU_ADRL2;                              /* TSU_ADRL2        */
    unsigned long  TSU_ADRH3;                              /* TSU_ADRH3        */
    unsigned long  TSU_ADRL3;                              /* TSU_ADRL3        */
    unsigned long  TSU_ADRH4;                              /* TSU_ADRH4        */
    unsigned long  TSU_ADRL4;                              /* TSU_ADRL4        */
    unsigned long  TSU_ADRH5;                              /* TSU_ADRH5        */
    unsigned long  TSU_ADRL5;                              /* TSU_ADRL5        */
    unsigned long  TSU_ADRH6;                              /* TSU_ADRH6        */
    unsigned long  TSU_ADRL6;                              /* TSU_ADRL6        */
    unsigned long  TSU_ADRH7;                              /* TSU_ADRH7        */
    unsigned long  TSU_ADRL7;                              /* TSU_ADRL7        */
    unsigned long  TSU_ADRH8;                              /* TSU_ADRH8        */
    unsigned long  TSU_ADRL8;                              /* TSU_ADRL8        */
    unsigned long  TSU_ADRH9;                              /* TSU_ADRH9        */
    unsigned long  TSU_ADRL9;                              /* TSU_ADRL9        */
    unsigned long  TSU_ADRH10;                             /* TSU_ADRH10       */
    unsigned long  TSU_ADRL10;                             /* TSU_ADRL10       */
    unsigned long  TSU_ADRH11;                             /* TSU_ADRH11       */
    unsigned long  TSU_ADRL11;                             /* TSU_ADRL11       */
    unsigned long  TSU_ADRH12;                             /* TSU_ADRH12       */
    unsigned long  TSU_ADRL12;                             /* TSU_ADRL12       */
    unsigned long  TSU_ADRH13;                             /* TSU_ADRH13       */
    unsigned long  TSU_ADRL13;                             /* TSU_ADRL13       */
    unsigned long  TSU_ADRH14;                             /* TSU_ADRH14       */
    unsigned long  TSU_ADRL14;                             /* TSU_ADRL14       */
    unsigned long  TSU_ADRH15;                             /* TSU_ADRH15       */
    unsigned long  TSU_ADRL15;                             /* TSU_ADRL15       */
    unsigned long  TSU_ADRH16;                             /* TSU_ADRH16       */
    unsigned long  TSU_ADRL16;                             /* TSU_ADRL16       */
    unsigned long  TSU_ADRH17;                             /* TSU_ADRH17       */
    unsigned long  TSU_ADRL17;                             /* TSU_ADRL17       */
    unsigned long  TSU_ADRH18;                             /* TSU_ADRH18       */
    unsigned long  TSU_ADRL18;                             /* TSU_ADRL18       */
    unsigned long  TSU_ADRH19;                             /* TSU_ADRH19       */
    unsigned long  TSU_ADRL19;                             /* TSU_ADRL19       */
    unsigned long  TSU_ADRH20;                             /* TSU_ADRH20       */
    unsigned long  TSU_ADRL20;                             /* TSU_ADRL20       */
    unsigned long  TSU_ADRH21;                             /* TSU_ADRH21       */
    unsigned long  TSU_ADRL21;                             /* TSU_ADRL21       */
    unsigned long  TSU_ADRH22;                             /* TSU_ADRH22       */
    unsigned long  TSU_ADRL22;                             /* TSU_ADRL22       */
    unsigned long  TSU_ADRH23;                             /* TSU_ADRH23       */
    unsigned long  TSU_ADRL23;                             /* TSU_ADRL23       */
    unsigned long  TSU_ADRH24;                             /* TSU_ADRH24       */
    unsigned long  TSU_ADRL24;                             /* TSU_ADRL24       */
    unsigned long  TSU_ADRH25;                             /* TSU_ADRH25       */
    unsigned long  TSU_ADRL25;                             /* TSU_ADRL25       */
    unsigned long  TSU_ADRH26;                             /* TSU_ADRH26       */
    unsigned long  TSU_ADRL26;                             /* TSU_ADRL26       */
    unsigned long  TSU_ADRH27;                             /* TSU_ADRH27       */
    unsigned long  TSU_ADRL27;                             /* TSU_ADRL27       */
    unsigned long  TSU_ADRH28;                             /* TSU_ADRH28       */
    unsigned long  TSU_ADRL28;                             /* TSU_ADRL28       */
    unsigned long  TSU_ADRH29;                             /* TSU_ADRH29       */
    unsigned long  TSU_ADRL29;                             /* TSU_ADRL29       */
    unsigned long  TSU_ADRH30;                             /* TSU_ADRH30       */
    unsigned long  TSU_ADRL30;                             /* TSU_ADRL30       */
    unsigned long  TSU_ADRH31;                             /* TSU_ADRH31       */
    unsigned long  TSU_ADRL31;                             /* TSU_ADRL31       */
    unsigned char  dummy55[516];                           /* Reserved         */
    unsigned long  HDMMDR0;                                /* HDMMDR0          */
    unsigned char  dummy56[8];                             /* Reserved         */
    unsigned long  HDMISR0;                                /* HDMISR0          */
    unsigned long  HDMIER0;                                /* HDMIER0          */
};
struct __tag65
{                                                          /* Module           */
    unsigned long  CNT;                                    /* CNT              */
    unsigned long  PCMD;                                   /* PCMD             */
    unsigned long  PS;                                     /* PS               */
};
struct __tag66
{                                                          /* Module           */
    unsigned char  FPMON;                                  /* FPMON            */
    unsigned char  dummy57[15];                            /* Reserved         */
    unsigned char  FASTAT;                                 /* FASTAT           */
    unsigned char  dummy58[3];                             /* Reserved         */
    unsigned char  FAEINT;                                 /* FAEINT           */
    unsigned char  dummy59[27];                            /* Reserved         */
    unsigned long  FSADDR;                                 /* FSADDR           */
    unsigned long  FEADDR;                                 /* FEADDR           */
    unsigned char  dummy60[28];                            /* Reserved         */
    unsigned short FCURAME;                                /* FCURAME          */
    unsigned char  dummy61[2];                             /* Reserved         */
    unsigned short FRAMMCR;                                /* FRAMMCR          */
    unsigned char  dummy62[6];                             /* Reserved         */
    unsigned short FPROTDR0;                               /* FPROTDR0         */
    unsigned char  dummy63[2];                             /* Reserved         */
    unsigned long  FPROTCR0;                               /* FPROTCR0         */
    unsigned long  FPROTCR1;                               /* FPROTCR1         */
    unsigned long  FPROTCR2;                               /* FPROTCR2         */
    unsigned long  FPROTCR3;                               /* FPROTCR3         */
    unsigned long  FPROTCR4;                               /* FPROTCR4         */
    unsigned char  dummy64[8];                             /* Reserved         */
    unsigned long  FSTATR;                                 /* FSTATR           */
    unsigned short FENTRYR;                                /* FENTRYR          */
    unsigned char  dummy65[6];                             /* Reserved         */
    unsigned short FSUINITR;                               /* FSUINITR         */
    unsigned char  dummy66[2];                             /* Reserved         */
    unsigned char  FLKSTAT;                                /* FLKSTAT          */
    unsigned char  dummy67[3];                             /* Reserved         */
    unsigned long  FRFSTEADR;                              /* FRFSTEADR        */
    unsigned char  FRTSTAT;                                /* FRTSTAT          */
    unsigned char  dummy68[3];                             /* Reserved         */
    unsigned char  FRTEINT;                                /* FRTEINT          */
    unsigned char  dummy69[3];                             /* Reserved         */
    unsigned short FCMDR;                                  /* FCMDR            */
    unsigned char  dummy70[14];                            /* Reserved         */
    unsigned short FRAMECCR;                               /* FRAMECCR         */
    unsigned char  dummy71[14];                            /* Reserved         */
    unsigned short FPESTAT;                                /* FPESTAT          */
    unsigned char  dummy72[2];                             /* Reserved         */
    unsigned short FCNFPRGCNT;                             /* FCNFPRGCNT       */
    unsigned char  dummy73[10];                            /* Reserved         */
    unsigned char  FBCCNT;                                 /* FBCCNT           */
    unsigned char  dummy74[3];                             /* Reserved         */
    unsigned char  FBCSTAT;                                /* FBCSTAT          */
    unsigned char  dummy75[3];                             /* Reserved         */
    unsigned long  FPSADDR;                                /* FPSADDR          */
    unsigned char  dummy76[4];                             /* Reserved         */
    unsigned short FCPSR;                                  /* FCPSR            */
    unsigned char  dummy77[2];                             /* Reserved         */
    unsigned short FPCKAR;                                 /* FPCKAR           */
    unsigned char  dummy78[26];                            /* Reserved         */
    unsigned short FECCEMON;                               /* FECCEMON         */
    unsigned char  dummy79[2];                             /* Reserved         */
    unsigned short FECCTMD;                                /* FECCTMD          */
    unsigned char  dummy80[2];                             /* Reserved         */
    unsigned short FDMYECC;                                /* FDMYECC          */
};
struct __tag67
{                                                          /* Module           */
    union __tag29 CTL;                                     /* CTL              */
    unsigned char  dummy81[3];                             /* Reserved         */
    unsigned short EN;                                     /* EN               */
    unsigned char  dummy82[6];                             /* Reserved         */
    union __tag30 ENL;                                     /* ENL              */
};
struct __tag68
{                                                          /* Module           */
    union __tag29 CTL;                                     /* CTL              */
    unsigned char  dummy83[3];                             /* Reserved         */
    unsigned short EN;                                     /* EN               */
    unsigned char  dummy84[6];                             /* Reserved         */
    union __tag31 ENL;                                     /* ENL              */
};
struct __tag69
{                                                          /* Module           */
    union __tag32 CTL0;                                    /* CTL0             */
    unsigned char  dummy85[3];                             /* Reserved         */
    union __tag33 CTL1;                                    /* CTL1             */
    unsigned char  dummy86[3];                             /* Reserved         */
    union __tag34 CTL2;                                    /* CTL2             */
    unsigned char  dummy87[3];                             /* Reserved         */
    union __tag35 CTL3;                                    /* CTL3             */
    unsigned char  dummy88[3];                             /* Reserved         */
    union __tag36 CTL4;                                    /* CTL4             */
    unsigned char  dummy89[3];                             /* Reserved         */
    union __tag37 CTL5;                                    /* CTL5             */
    unsigned char  dummy90[3];                             /* Reserved         */
    union __tag38 CTL6;                                    /* CTL6             */
    unsigned char  dummy91[3];                             /* Reserved         */
    union __tag39 CTL7;                                    /* CTL7             */
};
struct __tag70
{                                                          /* Module           */
    union __tag32 CTL0;                                    /* CTL0             */
    unsigned char  dummy92[3];                             /* Reserved         */
    union __tag33 CTL1;                                    /* CTL1             */
    unsigned char  dummy93[3];                             /* Reserved         */
    union __tag34 CTL2;                                    /* CTL2             */
    unsigned char  dummy94[3];                             /* Reserved         */
    union __tag35 CTL3;                                    /* CTL3             */
    unsigned char  dummy95[3];                             /* Reserved         */
    union __tag36 CTL4;                                    /* CTL4             */
};
struct __tag71
{                                                          /* Module           */
    union __tag40 CTL0;                                    /* CTL0             */
    unsigned char  dummy96[3];                             /* Reserved         */
    union __tag41 CTL1;                                    /* CTL1             */
};
struct __tag72
{                                                          /* Module           */
    union __tag42 CTL0;                                    /* CTL0             */
    unsigned char  dummy97[3];                             /* Reserved         */
    union __tag43 CTL1;                                    /* CTL1             */
    unsigned char  dummy98[3];                             /* Reserved         */
    union __tag44 CTL2;                                    /* CTL2             */
    unsigned char  dummy99[3];                             /* Reserved         */
    union __tag45 CTL3;                                    /* CTL3             */
    unsigned char  dummy100[3];                            /* Reserved         */
    union __tag46 CTL4;                                    /* CTL4             */
    unsigned char  dummy101[3];                            /* Reserved         */
    union __tag47 CTL5;                                    /* CTL5             */
    unsigned char  dummy102[3];                            /* Reserved         */
    union __tag48 CTL6;                                    /* CTL6             */
    unsigned char  dummy103[3];                            /* Reserved         */
    union __tag49 CTL7;                                    /* CTL7             */
};
struct __tag73
{                                                          /* Module           */
    union __tag42 CTL0;                                    /* CTL0             */
    unsigned char  dummy104[3];                            /* Reserved         */
    union __tag43 CTL1;                                    /* CTL1             */
};
struct __tag74
{                                                          /* Module           */
    union __tag28 PROT00;                                  /* PROT00           */
    union __tag28 SPID00;                                  /* SPID00           */
    union __tag28 PROT01;                                  /* PROT01           */
    union __tag28 SPID01;                                  /* SPID01           */
    union __tag28 PROT02;                                  /* PROT02           */
    union __tag28 SPID02;                                  /* SPID02           */
    union __tag28 PROT03;                                  /* PROT03           */
    union __tag28 SPID03;                                  /* SPID03           */
    union __tag28 PROT04;                                  /* PROT04           */
    union __tag28 SPID04;                                  /* SPID04           */
    union __tag28 PROT05;                                  /* PROT05           */
    union __tag28 SPID05;                                  /* SPID05           */
};
struct __tag75
{                                                          /* Module           */
    unsigned char  CTL;                                    /* CTL              */
    unsigned char  dummy105[3];                            /* Reserved         */
    unsigned long  STAT;                                   /* STAT             */
    unsigned char  dummy106[4];                            /* Reserved         */
    unsigned long  TYPE;                                   /* TYPE             */
};
struct __tag76
{                                                          /* Module           */
    union __tag28 PROT00;                                  /* PROT00           */
    union __tag28 SPID00;                                  /* SPID00           */
    union __tag28 PROT01;                                  /* PROT01           */
    union __tag28 SPID01;                                  /* SPID01           */
    union __tag28 PROT02;                                  /* PROT02           */
    union __tag28 SPID02;                                  /* SPID02           */
    union __tag28 PROT03;                                  /* PROT03           */
    union __tag28 SPID03;                                  /* SPID03           */
};
struct __tag77
{                                                          /* Module           */
    union __tag28 PROT00;                                  /* PROT00           */
    union __tag28 SPID00;                                  /* SPID00           */
    union __tag28 PROT01;                                  /* PROT01           */
    union __tag28 SPID01;                                  /* SPID01           */
};
struct __tag78
{                                                          /* Module           */
    unsigned long  CTL;                                    /* CTL              */
    unsigned long  TMC;                                    /* TMC              */
    unsigned long  TRC;                                    /* TRC              */
    unsigned long  TED;                                    /* TED              */
    unsigned long  EAD0;                                   /* EAD0             */
};
struct __tag79
{                                                          /* Module           */
    union __tag50 CTL0;                                    /* CTL0             */
    unsigned char  dummy107[15];                           /* Reserved         */
    unsigned long  CTL1;                                   /* CTL1             */
    unsigned short CTL2;                                   /* CTL2             */
    unsigned char  dummy108[4074];                         /* Reserved         */
    unsigned long  MCTL1;                                  /* MCTL1            */
    unsigned long  MCTL2;                                  /* MCTL2            */
    unsigned long  TX0W;                                   /* TX0W             */
    unsigned short TX0H;                                   /* TX0H             */
    unsigned char  dummy109[2];                            /* Reserved         */
    unsigned long  RX0W;                                   /* RX0W             */
    unsigned short RX0H;                                   /* RX0H             */
    unsigned char  dummy110[2];                            /* Reserved         */
    unsigned long  MRWP0;                                  /* MRWP0            */
    unsigned long  STR0;                                   /* STR0             */
    unsigned short STCR0;                                  /* STCR0            */
    unsigned char  dummy111[30];                           /* Reserved         */
    unsigned short MCTL0;                                  /* MCTL0            */
    unsigned char  dummy112[2];                            /* Reserved         */
    unsigned long  CFG0;                                   /* CFG0             */
    unsigned long  CFG1;                                   /* CFG1             */
    unsigned long  CFG2;                                   /* CFG2             */
    unsigned long  CFG3;                                   /* CFG3             */
    unsigned long  CFG4;                                   /* CFG4             */
    unsigned long  CFG5;                                   /* CFG5             */
    unsigned long  CFG6;                                   /* CFG6             */
    unsigned long  CFG7;                                   /* CFG7             */
    unsigned char  dummy113[4];                            /* Reserved         */
    unsigned short BRS0;                                   /* BRS0             */
    unsigned char  dummy114[2];                            /* Reserved         */
    unsigned short BRS1;                                   /* BRS1             */
    unsigned char  dummy115[2];                            /* Reserved         */
    unsigned short BRS2;                                   /* BRS2             */
    unsigned char  dummy116[2];                            /* Reserved         */
    unsigned short BRS3;                                   /* BRS3             */
};
struct __tag80
{                                                          /* Module           */
    unsigned long  CTL;                                    /* CTL              */
    unsigned long  TCTL0;                                  /* TCTL0            */
    unsigned long  TCTL1;                                  /* TCTL1            */
    unsigned long  TCTL2;                                  /* TCTL2            */
    unsigned long  TCTL3;                                  /* TCTL3            */
    unsigned long  TCTL4;                                  /* TCTL4            */
    unsigned long  TCTL5;                                  /* TCTL5            */
    unsigned long  TCTL6;                                  /* TCTL6            */
    unsigned long  TCTL7;                                  /* TCTL7            */
    unsigned long  TTX0;                                   /* TTX0             */
    unsigned long  TTX1;                                   /* TTX1             */
    unsigned long  TTX2;                                   /* TTX2             */
    unsigned long  TTX3;                                   /* TTX3             */
    unsigned long  TTX4;                                   /* TTX4             */
    unsigned long  TTX5;                                   /* TTX5             */
    unsigned long  TTX6;                                   /* TTX6             */
    unsigned long  TTX7;                                   /* TTX7             */
    unsigned long  RX;                                     /* RX               */
    unsigned long  TCNT0;                                  /* TCNT0            */
    unsigned long  TCNT1;                                  /* TCNT1            */
    unsigned long  TCNT2;                                  /* TCNT2            */
    unsigned long  TCNT3;                                  /* TCNT3            */
    unsigned long  TCNT4;                                  /* TCNT4            */
    unsigned long  TCNT5;                                  /* TCNT5            */
    unsigned long  TCNT6;                                  /* TCNT6            */
    unsigned long  TCNT7;                                  /* TCNT7            */
    unsigned long  STR0;                                   /* STR0             */
    unsigned long  STR1;                                   /* STR1             */
    unsigned long  STC;                                    /* STC              */
};
struct __tag81
{                                                          /* Module           */
    unsigned long  CKEN;                                   /* CKEN             */
    unsigned long  SRST;                                   /* SRST             */
    unsigned long  EN;                                     /* EN               */
    unsigned long  MD;                                     /* MD               */
    unsigned long  CTL;                                    /* CTL              */
    unsigned long  TDIV;                                   /* TDIV             */
    unsigned long  TSAR;                                   /* TSAR             */
    unsigned long  TPFM;                                   /* TPFM             */
    unsigned long  RDAR;                                   /* RDAR             */
    unsigned long  RPFM;                                   /* RPFM             */
    unsigned long  RGFM;                                   /* RGFM             */
    unsigned long  IREN;                                   /* IREN             */
    unsigned long  IRST;                                   /* IRST             */
    union __tag28 IRCL;                                    /* IRCL             */
    unsigned long  CST;                                    /* CST              */
    unsigned long  CTFM;                                   /* CTFM             */
    unsigned long  CRFM;                                   /* CRFM             */
};
struct __tag82
{                                                          /* Module           */
    unsigned char  dummy117[1];                            /* Reserved         */
    unsigned char  LWBR;                                   /* LWBR             */
    union __tag51 LBRP01;                                  /* LBRP01           */
    unsigned char  LSTC;                                   /* LSTC             */
    unsigned char  dummy118[3];                            /* Reserved         */
    unsigned char  LMD;                                    /* LMD              */
    unsigned char  LBFC;                                   /* LBFC             */
    unsigned char  LSC;                                    /* LSC              */
    unsigned char  LWUP;                                   /* LWUP             */
    unsigned char  LIE;                                    /* LIE              */
    unsigned char  LEDE;                                   /* LEDE             */
    unsigned char  LCUC;                                   /* LCUC             */
    unsigned char  dummy119[1];                            /* Reserved         */
    unsigned char  LTRC;                                   /* LTRC             */
    unsigned char  LMST;                                   /* LMST             */
    unsigned char  LST;                                    /* LST              */
    unsigned char  LEST;                                   /* LEST             */
    unsigned char  LDFC;                                   /* LDFC             */
    unsigned char  LIDB;                                   /* LIDB             */
    unsigned char  LCBR;                                   /* LCBR             */
    unsigned char  LUDB0;                                  /* LUDB0            */
    unsigned char  LDBR1;                                  /* LDBR1            */
    unsigned char  LDBR2;                                  /* LDBR2            */
    unsigned char  LDBR3;                                  /* LDBR3            */
    unsigned char  LDBR4;                                  /* LDBR4            */
    unsigned char  LDBR5;                                  /* LDBR5            */
    unsigned char  LDBR6;                                  /* LDBR6            */
    unsigned char  LDBR7;                                  /* LDBR7            */
    unsigned char  LDBR8;                                  /* LDBR8            */
    unsigned char  LUOER;                                  /* LUOER            */
    unsigned char  LUOR1;                                  /* LUOR1            */
    unsigned char  dummy120[2];                            /* Reserved         */
    union __tag52 LUTDR;                                   /* LUTDR            */
    union __tag52 LURDR;                                   /* LURDR            */
    union __tag52 LUWTDR;                                  /* LUWTDR           */
};
struct __tag83
{                                                          /* Module           */
    union __tag28 TSPC;                                    /* TSPC             */
    union __tag28 TSC;                                     /* TSC              */
    unsigned char  dummy121[8];                            /* Reserved         */
    union __tag28 CC;                                      /* CC               */
    union __tag28 BRP;                                     /* BRP              */
    union __tag28 IDE;                                     /* IDE              */
    union __tag28 MDC;                                     /* MDC              */
    union __tag28 SPCT;                                    /* SPCT             */
    union __tag28 MST;                                     /* MST              */
    union __tag28 CS;                                      /* CS               */
    union __tag28 CSC;                                     /* CSC              */
    union __tag28 SRTS;                                    /* SRTS             */
    unsigned long  SRXD;                                   /* SRXD             */
    union __tag28 CPL;                                     /* CPL              */
    union __tag28 ML;                                      /* ML               */
    union __tag28 FRTS;                                    /* FRTS             */
    unsigned long  FRXD;                                   /* FRXD             */
};
struct __tag84
{                                                          /* Module           */
    unsigned long  TSPC;                                   /* TSPC             */
};
struct __tag85
{                                                          /* Module           */
    unsigned char  R0;                                     /* R0               */
    unsigned char  dummy122[3];                            /* Reserved         */
    unsigned char  R1;                                     /* R1               */
    unsigned char  dummy123[3];                            /* Reserved         */
    unsigned char  R2;                                     /* R2               */
};
struct __tag86
{                                                          /* Module           */
    union __tag28 CREL;                                    /* CREL             */
    union __tag28 ENDN;                                    /* ENDN             */
    unsigned char  dummy124[4];                            /* Reserved         */
    union __tag53 DBTP;                                    /* DBTP             */
    union __tag28 TEST;                                    /* TEST             */
    union __tag28 RWD;                                     /* RWD              */
    union __tag28 CCCR;                                    /* CCCR             */
    union __tag54 BTP;                                     /* BTP              */
    unsigned char  dummy125[4];                            /* Reserved         */
    union __tag28 TSCV;                                    /* TSCV             */
    union __tag28 TOCC;                                    /* TOCC             */
    union __tag28 TOCV;                                    /* TOCV             */
    unsigned char  dummy126[16];                           /* Reserved         */
    union __tag28 ECR;                                     /* ECR              */
    union __tag28 PSR;                                     /* PSR              */
    union __tag28 TDCR;                                    /* TDCR             */
    unsigned char  dummy127[4];                            /* Reserved         */
    union __tag28 IR;                                      /* IR               */
    union __tag28 IE;                                      /* IE               */
    union __tag28 ILS;                                     /* ILS              */
    union __tag28 ILE;                                     /* ILE              */
    unsigned char  dummy128[32];                           /* Reserved         */
    union __tag28 GFC;                                     /* GFC              */
    union __tag28 SIDFC;                                   /* SIDFC            */
    union __tag28 XIDFC;                                   /* XIDFC            */
    unsigned char  dummy129[4];                            /* Reserved         */
    union __tag28 XIDAM;                                   /* XIDAM            */
    union __tag28 HPMS;                                    /* HPMS             */
    union __tag28 NDAT1;                                   /* NDAT1            */
    union __tag28 NDAT2;                                   /* NDAT2            */
    union __tag28 RXF0C;                                   /* RXF0C            */
    union __tag28 RXF0S;                                   /* RXF0S            */
    union __tag28 RXF0A;                                   /* RXF0A            */
    union __tag28 RXBC;                                    /* RXBC             */
    union __tag28 RXF1C;                                   /* RXF1C            */
    union __tag28 RXF1S;                                   /* RXF1S            */
    union __tag28 RXF1A;                                   /* RXF1A            */
    union __tag28 RXESC;                                   /* RXESC            */
    union __tag28 TXBC;                                    /* TXBC             */
    union __tag28 TXFQS;                                   /* TXFQS            */
    union __tag28 TXESC;                                   /* TXESC            */
    union __tag28 TXBRP;                                   /* TXBRP            */
    union __tag28 TXBAR;                                   /* TXBAR            */
    union __tag28 TXBCR;                                   /* TXBCR            */
    union __tag28 TXBTO;                                   /* TXBTO            */
    union __tag28 TXBCF;                                   /* TXBCF            */
    union __tag28 TXBTIE;                                  /* TXBTIE           */
    union __tag28 TXBCIE;                                  /* TXBCIE           */
    unsigned char  dummy130[8];                            /* Reserved         */
    union __tag28 TXEFC;                                   /* TXEFC            */
    union __tag28 TXEFS;                                   /* TXEFS            */
    union __tag28 TXEFA;                                   /* TXEFA            */
    unsigned char  dummy131[4];                            /* Reserved         */
    union __tag28 TTTMC;                                   /* TTTMC            */
    union __tag28 TTRMC;                                   /* TTRMC            */
    union __tag28 TTOCF;                                   /* TTOCF            */
    union __tag28 TTMLM;                                   /* TTMLM            */
    union __tag28 TURCF;                                   /* TURCF            */
    union __tag28 TTOCN;                                   /* TTOCN            */
    union __tag28 TTGTP;                                   /* TTGTP            */
    union __tag28 TTTMK;                                   /* TTTMK            */
    union __tag28 TTIR;                                    /* TTIR             */
    union __tag28 TTIE;                                    /* TTIE             */
    union __tag28 TTILS;                                   /* TTILS            */
    union __tag28 TTOST;                                   /* TTOST            */
    union __tag28 TURNA;                                   /* TURNA            */
    union __tag28 TTLGT;                                   /* TTLGT            */
    union __tag28 TTCTC;                                   /* TTCTC            */
    union __tag28 TTCPT;                                   /* TTCPT            */
    union __tag28 TTCSM;                                   /* TTCSM            */
};
struct __tag87
{                                                          /* Module           */
    union __tag28 CREL;                                    /* CREL             */
    union __tag28 ENDN;                                    /* ENDN             */
    unsigned char  dummy132[4];                            /* Reserved         */
    union __tag53 DBTP;                                    /* DBTP             */
    unsigned char  dummy133[4];                            /* Reserved         */
    union __tag28 RWD;                                     /* RWD              */
    union __tag28 CCCR;                                    /* CCCR             */
    union __tag54 BTP;                                     /* BTP              */
    union __tag28 TSCC;                                    /* TSCC             */
    union __tag28 TSCV;                                    /* TSCV             */
    union __tag28 TOCC;                                    /* TOCC             */
    union __tag28 TOCV;                                    /* TOCV             */
    unsigned char  dummy134[16];                           /* Reserved         */
    union __tag28 ECR;                                     /* ECR              */
    union __tag28 PSR;                                     /* PSR              */
    union __tag28 TDCR;                                    /* TDCR             */
    unsigned char  dummy135[4];                            /* Reserved         */
    union __tag28 IR;                                      /* IR               */
    union __tag28 IE;                                      /* IE               */
    union __tag28 ILS;                                     /* ILS              */
    union __tag28 ILE;                                     /* ILE              */
    unsigned char  dummy136[32];                           /* Reserved         */
    union __tag28 GFC;                                     /* GFC              */
    union __tag28 SIDFC;                                   /* SIDFC            */
    union __tag28 XIDFC;                                   /* XIDFC            */
    unsigned char  dummy137[4];                            /* Reserved         */
    union __tag28 XIDAM;                                   /* XIDAM            */
    union __tag28 HPMS;                                    /* HPMS             */
    union __tag28 NDAT1;                                   /* NDAT1            */
    union __tag28 NDAT2;                                   /* NDAT2            */
    union __tag28 RXF0C;                                   /* RXF0C            */
    union __tag28 RXF0S;                                   /* RXF0S            */
    union __tag28 RXF0A;                                   /* RXF0A            */
    union __tag28 RXBC;                                    /* RXBC             */
    union __tag28 RXF1C;                                   /* RXF1C            */
    union __tag28 RXF1S;                                   /* RXF1S            */
    union __tag28 RXF1A;                                   /* RXF1A            */
    union __tag28 RXESC;                                   /* RXESC            */
    union __tag28 TXBC;                                    /* TXBC             */
    union __tag28 TXFQS;                                   /* TXFQS            */
    union __tag28 TXESC;                                   /* TXESC            */
    union __tag28 TXBRP;                                   /* TXBRP            */
    union __tag28 TXBAR;                                   /* TXBAR            */
    union __tag28 TXBCR;                                   /* TXBCR            */
    union __tag28 TXBTO;                                   /* TXBTO            */
    union __tag28 TXBCF;                                   /* TXBCF            */
    union __tag28 TXBTIE;                                  /* TXBTIE           */
    union __tag28 TXBCIE;                                  /* TXBCIE           */
    unsigned char  dummy138[8];                            /* Reserved         */
    union __tag28 TXEFC;                                   /* TXEFC            */
    union __tag28 TXEFS;                                   /* TXEFS            */
    union __tag28 TXEFA;                                   /* TXEFA            */
};
struct __tag88
{                                                          /* Module           */
    unsigned long  CIN;                                    /* CIN              */
    unsigned long  COUT;                                   /* COUT             */
    unsigned char  dummy139[24];                           /* Reserved         */
    unsigned char  CTL;                                    /* CTL              */
};
struct __tag89
{                                                          /* Module           */
    unsigned long  ESET;                                   /* ESET             */
    unsigned long  ECLR;                                   /* ECLR             */
    unsigned long  ESSTR0;                                 /* ESSTR0           */
    unsigned long  ESSTR1;                                 /* ESSTR1           */
    unsigned long  ESSTR2;                                 /* ESSTR2           */
    unsigned long  PCMD0;                                  /* PCMD0            */
};
struct __tag90
{                                                          /* Module           */
    unsigned long  EPCFG;                                  /* EPCFG            */
    unsigned long  MICFG0;                                 /* MICFG0           */
    unsigned long  MICFG1;                                 /* MICFG1           */
    unsigned long  MICFG2;                                 /* MICFG2           */
    unsigned long  NMICFG0;                                /* NMICFG0          */
    unsigned long  NMICFG1;                                /* NMICFG1          */
    unsigned long  NMICFG2;                                /* NMICFG2          */
    unsigned long  IRCFG0;                                 /* IRCFG0           */
    unsigned long  IRCFG1;                                 /* IRCFG1           */
    unsigned long  IRCFG2;                                 /* IRCFG2           */
    unsigned long  EMK0;                                   /* EMK0             */
    unsigned long  EMK1;                                   /* EMK1             */
    unsigned long  EMK2;                                   /* EMK2             */
    unsigned long  ESSTC0;                                 /* ESSTC0           */
    unsigned long  ESSTC1;                                 /* ESSTC1           */
    unsigned long  ESSTC2;                                 /* ESSTC2           */
    unsigned long  PCMD1;                                  /* PCMD1            */
    unsigned char  PS;                                     /* PS               */
    unsigned char  dummy140[3];                            /* Reserved         */
    unsigned long  PE0;                                    /* PE0              */
    unsigned long  PE1;                                    /* PE1              */
    unsigned long  PE2;                                    /* PE2              */
    unsigned long  DTMCTL;                                 /* DTMCTL           */
    unsigned short DTMR;                                   /* DTMR             */
    unsigned char  dummy141[2];                            /* Reserved         */
    unsigned long  DTMCMP;                                 /* DTMCMP           */
    unsigned long  DTMCFG0;                                /* DTMCFG0          */
    unsigned long  DTMCFG1;                                /* DTMCFG1          */
    unsigned long  DTMCFG2;                                /* DTMCFG2          */
    unsigned long  DTMCFG3;                                /* DTMCFG3          */
    unsigned long  DTMCFG4;                                /* DTMCFG4          */
    unsigned long  DTMCFG5;                                /* DTMCFG5          */
    unsigned long  EOCCFG;                                 /* EOCCFG           */
    unsigned long  PEM;                                    /* PEM              */
};
struct __tag91
{                                                          /* Module           */
    unsigned long  TRGPREMUX0;                             /* TRGPREMUX0       */
    unsigned long  TRGPREMUX1;                             /* TRGPREMUX1       */
    unsigned char  dummy142[8];                            /* Reserved         */
    unsigned long  TRGMUX0;                                /* TRGMUX0          */
    unsigned long  TRGMUX1;                                /* TRGMUX1          */
    unsigned long  EDGSEL0;                                /* EDGSEL0          */
    unsigned long  EDGSEL1;                                /* EDGSEL1          */
    unsigned long  ENP2TIM0;                               /* ENP2TIM0         */
    unsigned long  ENP2TIM1;                               /* ENP2TIM1         */
    unsigned long  ENHIZDTM;                               /* ENHIZDTM         */
};
struct __tag92
{                                                          /* Module           */
    union __tag55 CKSEL;                                   /* CKSEL            */
    unsigned char  dummy143[12];                           /* Reserved         */
    union __tag55 TS;                                      /* TS               */
    union __tag55 TT;                                      /* TT               */
    union __tag55 CSTR;                                    /* CSTR             */
    unsigned char  dummy144[4];                            /* Reserved         */
    unsigned long  STR;                                    /* STR              */
    unsigned long  STC;                                    /* STC              */
    unsigned char  dummy145[8];                            /* Reserved         */
    union __tag55 IS;                                      /* IS               */
    union __tag55 RM;                                      /* RM               */
    unsigned char  dummy146[8];                            /* Reserved         */
    unsigned long  CNT0L;                                  /* CNT0L            */
    unsigned long  CNT0H;                                  /* CNT0H            */
    unsigned char  dummy147[8];                            /* Reserved         */
    unsigned long  CMP0AL;                                 /* CMP0AL           */
    unsigned long  CMP0AH;                                 /* CMP0AH           */
    unsigned long  CMP0BL;                                 /* CMP0BL           */
    unsigned long  CMP0BH;                                 /* CMP0BH           */
    unsigned long  CMP0CL;                                 /* CMP0CL           */
    unsigned long  CMP0CH;                                 /* CMP0CH           */
    unsigned long  CMP0DL;                                 /* CMP0DL           */
    unsigned long  CMP0DH;                                 /* CMP0DH           */
    unsigned long  CNT1;                                   /* CNT1             */
    unsigned char  dummy148[12];                           /* Reserved         */
    unsigned long  CMP1A;                                  /* CMP1A            */
    unsigned long  CMP1B;                                  /* CMP1B            */
    unsigned long  CMP1C;                                  /* CMP1C            */
    unsigned long  CMP1D;                                  /* CMP1D            */
    unsigned long  CNT2;                                   /* CNT2             */
    unsigned char  dummy149[12];                           /* Reserved         */
    unsigned long  CMP2A;                                  /* CMP2A            */
    unsigned long  CMP2B;                                  /* CMP2B            */
    unsigned long  CMP2C;                                  /* CMP2C            */
    unsigned long  CMP2D;                                  /* CMP2D            */
    unsigned long  CNT3;                                   /* CNT3             */
    unsigned char  dummy150[12];                           /* Reserved         */
    unsigned long  CMP3A;                                  /* CMP3A            */
    unsigned long  CMP3B;                                  /* CMP3B            */
    unsigned long  CMP3C;                                  /* CMP3C            */
    unsigned long  CMP3D;                                  /* CMP3D            */
};
struct __tag93
{                                                          /* Module           */
    union __tag28 PROT00;                                  /* PROT00           */
    union __tag28 SPID00;                                  /* SPID00           */
    union __tag28 PROT01;                                  /* PROT01           */
    union __tag28 SPID01;                                  /* SPID01           */
    union __tag28 PROT02;                                  /* PROT02           */
    union __tag28 SPID02;                                  /* SPID02           */
    union __tag28 PROT03;                                  /* PROT03           */
    union __tag28 SPID03;                                  /* SPID03           */
    union __tag28 PROT04;                                  /* PROT04           */
    union __tag28 SPID04;                                  /* SPID04           */
    union __tag28 PROT05;                                  /* PROT05           */
    union __tag28 SPID05;                                  /* SPID05           */
    union __tag28 PROT06;                                  /* PROT06           */
    union __tag28 SPID06;                                  /* SPID06           */
    union __tag28 PROT07;                                  /* PROT07           */
    union __tag28 SPID07;                                  /* SPID07           */
    unsigned char  dummy151[16];                           /* Reserved         */
    union __tag28 PROT10;                                  /* PROT10           */
    union __tag28 SPID10;                                  /* SPID10           */
    union __tag28 PROT11;                                  /* PROT11           */
    union __tag28 SPID11;                                  /* SPID11           */
};
struct __tag94
{                                                          /* Module           */
    unsigned long  GTMREV;                                 /* GTMREV           */
    unsigned long  GTMRST;                                 /* GTMRST           */
    unsigned long  GTMCTRL;                                /* GTMCTRL          */
    unsigned long  GTMAEIADDRXPT;                          /* GTMAEIADDRXPT    */
    unsigned long  GTMIRQNOTIFY;                           /* GTMIRQNOTIFY     */
    unsigned long  GTMIRQEN;                               /* GTMIRQEN         */
    unsigned long  GTMIRQFORCINT;                          /* GTMIRQFORCINT    */
    unsigned long  GTMIRQMODE;                             /* GTMIRQMODE       */
    unsigned long  GTMEIRQEN;                              /* GTMEIRQEN        */
    unsigned long  GTMHWCONF;                              /* GTMHWCONF        */
    unsigned char  dummy152[8];                            /* Reserved         */
    unsigned long  GTMBRIDGEMODE;                          /* GTMBRIDGEMODE    */
    unsigned long  GTMBRIDGEPTR1;                          /* GTMBRIDGEPTR1    */
    unsigned long  GTMBRIDGEPTR2;                          /* GTMBRIDGEPTR2    */
    unsigned char  dummy153[4];                            /* Reserved         */
    unsigned long  GTMTIM0AUXINSRC;                        /* GTMTIM0AUXINSRC  */
    unsigned long  GTMTIM1AUXINSRC;                        /* GTMTIM1AUXINSRC  */
    unsigned char  dummy154[20];                           /* Reserved         */
    unsigned long  GTMEXTCAPEN0;                           /* GTMEXTCAPEN0     */
    unsigned char  dummy155[56];                           /* Reserved         */
    unsigned long  GTMATOM0OUT;                            /* GTMATOM0OUT      */
    unsigned char  dummy156[100];                          /* Reserved         */
    unsigned long  TBUCHEN;                                /* TBUCHEN          */
    unsigned long  TBU0CTRL;                               /* TBU0CTRL         */
    unsigned long  TBU0BASE;                               /* TBU0BASE         */
    unsigned long  TBU1CTRL;                               /* TBU1CTRL         */
    unsigned long  TBU1BASE;                               /* TBU1BASE         */
    unsigned char  dummy157[108];                          /* Reserved         */
    unsigned long  MONSTATUS;                              /* MONSTATUS        */
    unsigned long  MONACTIVITY0;                           /* MONACTIVITY0     */
    unsigned char  dummy158[4];                            /* Reserved         */
    unsigned long  MONACTIVITYMCS0;                        /* MONACTIVITYMCS0  */
    unsigned char  dummy159[112];                          /* Reserved         */
    unsigned long  CMPEN;                                  /* CMPEN            */
    unsigned long  CMPIRQNOTIFY;                           /* CMPIRQNOTIFY     */
    unsigned long  CMPIRQEN;                               /* CMPIRQEN         */
    unsigned long  CMPIRQFORCINT;                          /* CMPIRQFORCINT    */
    unsigned long  CMPIRQMODE;                             /* CMPIRQMODE       */
    unsigned long  CMPEIRQEN;                              /* CMPEIRQEN        */
    unsigned char  dummy160[104];                          /* Reserved         */
    unsigned long  ARUACCESS;                              /* ARUACCESS        */
    unsigned long  ARUDATAH;                               /* ARUDATAH         */
    unsigned long  ARUDATAL;                               /* ARUDATAL         */
    unsigned long  ARUDBGACCESS0;                          /* ARUDBGACCESS0    */
    unsigned long  ARUDBGDATA0H;                           /* ARUDBGDATA0H     */
    unsigned long  ARUDBGDATA0L;                           /* ARUDBGDATA0L     */
    unsigned long  ARUDBGACCESS1;                          /* ARUDBGACCESS1    */
    unsigned long  ARUDBGDATA1H;                           /* ARUDBGDATA1H     */
    unsigned long  ARUDBGDATA1L;                           /* ARUDBGDATA1L     */
    unsigned long  ARUIRQNOTIFY;                           /* ARUIRQNOTIFY     */
    unsigned long  ARUIRQEN;                               /* ARUIRQEN         */
    unsigned long  ARUIRQFORCINT;                          /* ARUIRQFORCINT    */
    unsigned long  ARUIRQMODE;                             /* ARUIRQMODE       */
    unsigned long  ARUCADDREND;                            /* ARUCADDREND      */
    unsigned char  dummy161[72];                           /* Reserved         */
    unsigned long  CMUCLKEN;                               /* CMUCLKEN         */
    unsigned long  CMUGCLKNUM;                             /* CMUGCLKNUM       */
    unsigned long  CMUGCLKDEN;                             /* CMUGCLKDEN       */
    unsigned long  CMUCLK0CTRL;                            /* CMUCLK0CTRL      */
    unsigned long  CMUCLK1CTRL;                            /* CMUCLK1CTRL      */
    unsigned long  CMUCLK2CTRL;                            /* CMUCLK2CTRL      */
    unsigned long  CMUCLK3CTRL;                            /* CMUCLK3CTRL      */
    unsigned long  CMUCLK4CTRL;                            /* CMUCLK4CTRL      */
    unsigned long  CMUCLK5CTRL;                            /* CMUCLK5CTRL      */
    unsigned long  CMUCLK6CTRL;                            /* CMUCLK6CTRL      */
    unsigned long  CMUCLK7CTRL;                            /* CMUCLK7CTRL      */
    unsigned char  dummy162[28];                           /* Reserved         */
    unsigned long  CMUGLBCTRL;                             /* CMUGLBCTRL       */
    unsigned char  dummy163[692];                          /* Reserved         */
    unsigned long  ICMIRQG0;                               /* ICMIRQG0         */
    unsigned char  dummy164[4];                            /* Reserved         */
    unsigned long  ICMIRQG2;                               /* ICMIRQG2         */
    unsigned char  dummy165[4];                            /* Reserved         */
    unsigned long  ICMIRQG4;                               /* ICMIRQG4         */
    unsigned char  dummy166[16];                           /* Reserved         */
    unsigned long  ICMIRQG9;                               /* ICMIRQG9         */
    unsigned char  dummy167[8];                            /* Reserved         */
    unsigned long  ICMIRQGMEI;                             /* ICMIRQGMEI       */
    unsigned char  dummy168[4];                            /* Reserved         */
    unsigned long  ICMIRQGCEI1;                            /* ICMIRQGCEI1      */
    unsigned char  dummy169[4];                            /* Reserved         */
    unsigned long  ICMIRQGCEI3;                            /* ICMIRQGCEI3      */
    unsigned char  dummy170[4];                            /* Reserved         */
    unsigned long  ICMIRQGMCS0CI;                          /* ICMIRQGMCS0CI    */
    unsigned char  dummy171[24];                           /* Reserved         */
    unsigned long  ICMIRQGMCS0CEI;                         /* ICMIRQGMCS0CEI   */
    unsigned char  dummy172[2456];                         /* Reserved         */
    unsigned long  TIM00GPR0;                              /* TIM00GPR0        */
    unsigned long  TIM00GPR1;                              /* TIM00GPR1        */
    unsigned long  TIM00CNT;                               /* TIM00CNT         */
    unsigned long  TIM00ECNT;                              /* TIM00ECNT        */
    unsigned long  TIM00CNTS;                              /* TIM00CNTS        */
    unsigned long  TIM00TDUC;                              /* TIM00TDUC        */
    unsigned long  TIM00TDUV;                              /* TIM00TDUV        */
    unsigned long  TIM00FLTRE;                             /* TIM00FLTRE       */
    unsigned long  TIM00FLTFE;                             /* TIM00FLTFE       */
    unsigned long  TIM00CTRL;                              /* TIM00CTRL        */
    unsigned long  TIM00ECTRL;                             /* TIM00ECTRL       */
    unsigned long  TIM00IRQNOTIFY;                         /* TIM00IRQNOTIFY   */
    unsigned long  TIM00IRQEN;                             /* TIM00IRQEN       */
    unsigned long  TIM00IRQFORCINT;                        /* TIM00IRQFORCINT  */
    unsigned long  TIM00IRQMODE;                           /* TIM00IRQMODE     */
    unsigned long  TIM00EIRQEN;                            /* TIM00EIRQEN      */
    unsigned char  dummy173[52];                           /* Reserved         */
    unsigned long  TIM0INPVAL;                             /* TIM0INPVAL       */
    unsigned long  TIM0INSRC;                              /* TIM0INSRC        */
    unsigned long  TIM0RST;                                /* TIM0RST          */
    unsigned long  TIM01GPR0;                              /* TIM01GPR0        */
    unsigned long  TIM01GPR1;                              /* TIM01GPR1        */
    unsigned long  TIM01CNT;                               /* TIM01CNT         */
    unsigned long  TIM01ECNT;                              /* TIM01ECNT        */
    unsigned long  TIM01CNTS;                              /* TIM01CNTS        */
    unsigned long  TIM01TDUC;                              /* TIM01TDUC        */
    unsigned long  TIM01TDUV;                              /* TIM01TDUV        */
    unsigned long  TIM01FLTRE;                             /* TIM01FLTRE       */
    unsigned long  TIM01FLTFE;                             /* TIM01FLTFE       */
    unsigned long  TIM01CTRL;                              /* TIM01CTRL        */
    unsigned long  TIM01ECTRL;                             /* TIM01ECTRL       */
    unsigned long  TIM01IRQNOTIFY;                         /* TIM01IRQNOTIFY   */
    unsigned long  TIM01IRQEN;                             /* TIM01IRQEN       */
    unsigned long  TIM01IRQFORCINT;                        /* TIM01IRQFORCINT  */
    unsigned long  TIM01IRQMODE;                           /* TIM01IRQMODE     */
    unsigned long  TIM01EIRQEN;                            /* TIM01EIRQEN      */
    unsigned char  dummy174[64];                           /* Reserved         */
    unsigned long  TIM02GPR0;                              /* TIM02GPR0        */
    unsigned long  TIM02GPR1;                              /* TIM02GPR1        */
    unsigned long  TIM02CNT;                               /* TIM02CNT         */
    unsigned long  TIM02ECNT;                              /* TIM02ECNT        */
    unsigned long  TIM02CNTS;                              /* TIM02CNTS        */
    unsigned long  TIM02TDUC;                              /* TIM02TDUC        */
    unsigned long  TIM02TDUV;                              /* TIM02TDUV        */
    unsigned long  TIM02FLTRE;                             /* TIM02FLTRE       */
    unsigned long  TIM02FLTFE;                             /* TIM02FLTFE       */
    unsigned long  TIM02CTRL;                              /* TIM02CTRL        */
    unsigned long  TIM02ECTRL;                             /* TIM02ECTRL       */
    unsigned long  TIM02IRQNOTIFY;                         /* TIM02IRQNOTIFY   */
    unsigned long  TIM02IRQEN;                             /* TIM02IRQEN       */
    unsigned long  TIM02IRQFORCINT;                        /* TIM02IRQFORCINT  */
    unsigned long  TIM02IRQMODE;                           /* TIM02IRQMODE     */
    unsigned long  TIM02EIRQEN;                            /* TIM02EIRQEN      */
    unsigned char  dummy175[64];                           /* Reserved         */
    unsigned long  TIM03GPR0;                              /* TIM03GPR0        */
    unsigned long  TIM03GPR1;                              /* TIM03GPR1        */
    unsigned long  TIM03CNT;                               /* TIM03CNT         */
    unsigned long  TIM03ECNT;                              /* TIM03ECNT        */
    unsigned long  TIM03CNTS;                              /* TIM03CNTS        */
    unsigned long  TIM03TDUC;                              /* TIM03TDUC        */
    unsigned long  TIM03TDUV;                              /* TIM03TDUV        */
    unsigned long  TIM03FLTRE;                             /* TIM03FLTRE       */
    unsigned long  TIM03FLTFE;                             /* TIM03FLTFE       */
    unsigned long  TIM03CTRL;                              /* TIM03CTRL        */
    unsigned long  TIM03ECTRL;                             /* TIM03ECTRL       */
    unsigned long  TIM03IRQNOTIFY;                         /* TIM03IRQNOTIFY   */
    unsigned long  TIM03IRQEN;                             /* TIM03IRQEN       */
    unsigned long  TIM03IRQFORCINT;                        /* TIM03IRQFORCINT  */
    unsigned long  TIM03IRQMODE;                           /* TIM03IRQMODE     */
    unsigned long  TIM03EIRQEN;                            /* TIM03EIRQEN      */
    unsigned char  dummy176[64];                           /* Reserved         */
    unsigned long  TIM04GPR0;                              /* TIM04GPR0        */
    unsigned long  TIM04GPR1;                              /* TIM04GPR1        */
    unsigned long  TIM04CNT;                               /* TIM04CNT         */
    unsigned long  TIM04ECNT;                              /* TIM04ECNT        */
    unsigned long  TIM04CNTS;                              /* TIM04CNTS        */
    unsigned long  TIM04TDUC;                              /* TIM04TDUC        */
    unsigned long  TIM04TDUV;                              /* TIM04TDUV        */
    unsigned long  TIM04FLTRE;                             /* TIM04FLTRE       */
    unsigned long  TIM04FLTFE;                             /* TIM04FLTFE       */
    unsigned long  TIM04CTRL;                              /* TIM04CTRL        */
    unsigned long  TIM04ECTRL;                             /* TIM04ECTRL       */
    unsigned long  TIM04IRQNOTIFY;                         /* TIM04IRQNOTIFY   */
    unsigned long  TIM04IRQEN;                             /* TIM04IRQEN       */
    unsigned long  TIM04IRQFORCINT;                        /* TIM04IRQFORCINT  */
    unsigned long  TIM04IRQMODE;                           /* TIM04IRQMODE     */
    unsigned long  TIM04EIRQEN;                            /* TIM04EIRQEN      */
    unsigned char  dummy177[64];                           /* Reserved         */
    unsigned long  TIM05GPR0;                              /* TIM05GPR0        */
    unsigned long  TIM05GPR1;                              /* TIM05GPR1        */
    unsigned long  TIM05CNT;                               /* TIM05CNT         */
    unsigned long  TIM05ECNT;                              /* TIM05ECNT        */
    unsigned long  TIM05CNTS;                              /* TIM05CNTS        */
    unsigned long  TIM05TDUC;                              /* TIM05TDUC        */
    unsigned long  TIM05TDUV;                              /* TIM05TDUV        */
    unsigned long  TIM05FLTRE;                             /* TIM05FLTRE       */
    unsigned long  TIM05FLTFE;                             /* TIM05FLTFE       */
    unsigned long  TIM05CTRL;                              /* TIM05CTRL        */
    unsigned long  TIM05ECTRL;                             /* TIM05ECTRL       */
    unsigned long  TIM05IRQNOTIFY;                         /* TIM05IRQNOTIFY   */
    unsigned long  TIM05IRQEN;                             /* TIM05IRQEN       */
    unsigned long  TIM05IRQFORCINT;                        /* TIM05IRQFORCINT  */
    unsigned long  TIM05IRQMODE;                           /* TIM05IRQMODE     */
    unsigned long  TIM05EIRQEN;                            /* TIM05EIRQEN      */
    unsigned char  dummy178[64];                           /* Reserved         */
    unsigned long  TIM06GPR0;                              /* TIM06GPR0        */
    unsigned long  TIM06GPR1;                              /* TIM06GPR1        */
    unsigned long  TIM06CNT;                               /* TIM06CNT         */
    unsigned long  TIM06ECNT;                              /* TIM06ECNT        */
    unsigned long  TIM06CNTS;                              /* TIM06CNTS        */
    unsigned long  TIM06TDUC;                              /* TIM06TDUC        */
    unsigned long  TIM06TDUV;                              /* TIM06TDUV        */
    unsigned long  TIM06FLTRE;                             /* TIM06FLTRE       */
    unsigned long  TIM06FLTFE;                             /* TIM06FLTFE       */
    unsigned long  TIM06CTRL;                              /* TIM06CTRL        */
    unsigned long  TIM06ECTRL;                             /* TIM06ECTRL       */
    unsigned long  TIM06IRQNOTIFY;                         /* TIM06IRQNOTIFY   */
    unsigned long  TIM06IRQEN;                             /* TIM06IRQEN       */
    unsigned long  TIM06IRQFORCINT;                        /* TIM06IRQFORCINT  */
    unsigned long  TIM06IRQMODE;                           /* TIM06IRQMODE     */
    unsigned long  TIM06EIRQEN;                            /* TIM06EIRQEN      */
    unsigned char  dummy179[64];                           /* Reserved         */
    unsigned long  TIM07GPR0;                              /* TIM07GPR0        */
    unsigned long  TIM07GPR1;                              /* TIM07GPR1        */
    unsigned long  TIM07CNT;                               /* TIM07CNT         */
    unsigned long  TIM07ECNT;                              /* TIM07ECNT        */
    unsigned long  TIM07CNTS;                              /* TIM07CNTS        */
    unsigned long  TIM07TDUC;                              /* TIM07TDUC        */
    unsigned long  TIM07TDUV;                              /* TIM07TDUV        */
    unsigned long  TIM07FLTRE;                             /* TIM07FLTRE       */
    unsigned long  TIM07FLTFE;                             /* TIM07FLTFE       */
    unsigned long  TIM07CTRL;                              /* TIM07CTRL        */
    unsigned long  TIM07ECTRL;                             /* TIM07ECTRL       */
    unsigned long  TIM07IRQNOTIFY;                         /* TIM07IRQNOTIFY   */
    unsigned long  TIM07IRQEN;                             /* TIM07IRQEN       */
    unsigned long  TIM07IRQFORCINT;                        /* TIM07IRQFORCINT  */
    unsigned long  TIM07IRQMODE;                           /* TIM07IRQMODE     */
    unsigned long  TIM07EIRQEN;                            /* TIM07EIRQEN      */
    unsigned char  dummy180[1088];                         /* Reserved         */
    unsigned long  TIM10GPR0;                              /* TIM10GPR0        */
    unsigned long  TIM10GPR1;                              /* TIM10GPR1        */
    unsigned long  TIM10CNT;                               /* TIM10CNT         */
    unsigned long  TIM10ECNT;                              /* TIM10ECNT        */
    unsigned long  TIM10CNTS;                              /* TIM10CNTS        */
    unsigned long  TIM10TDUC;                              /* TIM10TDUC        */
    unsigned long  TIM10TDUV;                              /* TIM10TDUV        */
    unsigned long  TIM10FLTRE;                             /* TIM10FLTRE       */
    unsigned long  TIM10FLTFE;                             /* TIM10FLTFE       */
    unsigned long  TIM10CTRL;                              /* TIM10CTRL        */
    unsigned long  TIM10ECTRL;                             /* TIM10ECTRL       */
    unsigned long  TIM10IRQNOTIFY;                         /* TIM10IRQNOTIFY   */
    unsigned long  TIM10IRQEN;                             /* TIM10IRQEN       */
    unsigned long  TIM10IRQFORCINT;                        /* TIM10IRQFORCINT  */
    unsigned long  TIM10IRQMODE;                           /* TIM10IRQMODE     */
    unsigned long  TIM10EIRQEN;                            /* TIM10EIRQEN      */
    unsigned char  dummy181[52];                           /* Reserved         */
    unsigned long  TIM1INPVAL;                             /* TIM1INPVAL       */
    unsigned long  TIM1INSRC;                              /* TIM1INSRC        */
    unsigned long  TIM1RST;                                /* TIM1RST          */
    unsigned long  TIM11GPR0;                              /* TIM11GPR0        */
    unsigned long  TIM11GPR1;                              /* TIM11GPR1        */
    unsigned long  TIM11CNT;                               /* TIM11CNT         */
    unsigned long  TIM11ECNT;                              /* TIM11ECNT        */
    unsigned long  TIM11CNTS;                              /* TIM11CNTS        */
    unsigned long  TIM11TDUC;                              /* TIM11TDUC        */
    unsigned long  TIM11TDUV;                              /* TIM11TDUV        */
    unsigned long  TIM11FLTRE;                             /* TIM11FLTRE       */
    unsigned long  TIM11FLTFE;                             /* TIM11FLTFE       */
    unsigned long  TIM11CTRL;                              /* TIM11CTRL        */
    unsigned long  TIM11ECTRL;                             /* TIM11ECTRL       */
    unsigned long  TIM11IRQNOTIFY;                         /* TIM11IRQNOTIFY   */
    unsigned long  TIM11IRQEN;                             /* TIM11IRQEN       */
    unsigned long  TIM11IRQFORCINT;                        /* TIM11IRQFORCINT  */
    unsigned long  TIM11IRQMODE;                           /* TIM11IRQMODE     */
    unsigned long  TIM11EIRQEN;                            /* TIM11EIRQEN      */
    unsigned char  dummy182[64];                           /* Reserved         */
    unsigned long  TIM12GPR0;                              /* TIM12GPR0        */
    unsigned long  TIM12GPR1;                              /* TIM12GPR1        */
    unsigned long  TIM12CNT;                               /* TIM12CNT         */
    unsigned long  TIM12ECNT;                              /* TIM12ECNT        */
    unsigned long  TIM12CNTS;                              /* TIM12CNTS        */
    unsigned long  TIM12TDUC;                              /* TIM12TDUC        */
    unsigned long  TIM12TDUV;                              /* TIM12TDUV        */
    unsigned long  TIM12FLTRE;                             /* TIM12FLTRE       */
    unsigned long  TIM12FLTFE;                             /* TIM12FLTFE       */
    unsigned long  TIM12CTRL;                              /* TIM12CTRL        */
    unsigned long  TIM12ECTRL;                             /* TIM12ECTRL       */
    unsigned long  TIM12IRQNOTIFY;                         /* TIM12IRQNOTIFY   */
    unsigned long  TIM12IRQEN;                             /* TIM12IRQEN       */
    unsigned long  TIM12IRQFORCINT;                        /* TIM12IRQFORCINT  */
    unsigned long  TIM12IRQMODE;                           /* TIM12IRQMODE     */
    unsigned long  TIM12EIRQEN;                            /* TIM12EIRQEN      */
    unsigned char  dummy183[64];                           /* Reserved         */
    unsigned long  TIM13GPR0;                              /* TIM13GPR0        */
    unsigned long  TIM13GPR1;                              /* TIM13GPR1        */
    unsigned long  TIM13CNT;                               /* TIM13CNT         */
    unsigned long  TIM13ECNT;                              /* TIM13ECNT        */
    unsigned long  TIM13CNTS;                              /* TIM13CNTS        */
    unsigned long  TIM13TDUC;                              /* TIM13TDUC        */
    unsigned long  TIM13TDUV;                              /* TIM13TDUV        */
    unsigned long  TIM13FLTRE;                             /* TIM13FLTRE       */
    unsigned long  TIM13FLTFE;                             /* TIM13FLTFE       */
    unsigned long  TIM13CTRL;                              /* TIM13CTRL        */
    unsigned long  TIM13ECTRL;                             /* TIM13ECTRL       */
    unsigned long  TIM13IRQNOTIFY;                         /* TIM13IRQNOTIFY   */
    unsigned long  TIM13IRQEN;                             /* TIM13IRQEN       */
    unsigned long  TIM13IRQFORCINT;                        /* TIM13IRQFORCINT  */
    unsigned long  TIM13IRQMODE;                           /* TIM13IRQMODE     */
    unsigned long  TIM13EIRQEN;                            /* TIM13EIRQEN      */
    unsigned char  dummy184[64];                           /* Reserved         */
    unsigned long  TIM14GPR0;                              /* TIM14GPR0        */
    unsigned long  TIM14GPR1;                              /* TIM14GPR1        */
    unsigned long  TIM14CNT;                               /* TIM14CNT         */
    unsigned long  TIM14ECNT;                              /* TIM14ECNT        */
    unsigned long  TIM14CNTS;                              /* TIM14CNTS        */
    unsigned long  TIM14TDUC;                              /* TIM14TDUC        */
    unsigned long  TIM14TDUV;                              /* TIM14TDUV        */
    unsigned long  TIM14FLTRE;                             /* TIM14FLTRE       */
    unsigned long  TIM14FLTFE;                             /* TIM14FLTFE       */
    unsigned long  TIM14CTRL;                              /* TIM14CTRL        */
    unsigned long  TIM14ECTRL;                             /* TIM14ECTRL       */
    unsigned long  TIM14IRQNOTIFY;                         /* TIM14IRQNOTIFY   */
    unsigned long  TIM14IRQEN;                             /* TIM14IRQEN       */
    unsigned long  TIM14IRQFORCINT;                        /* TIM14IRQFORCINT  */
    unsigned long  TIM14IRQMODE;                           /* TIM14IRQMODE     */
    unsigned long  TIM14EIRQEN;                            /* TIM14EIRQEN      */
    unsigned char  dummy185[64];                           /* Reserved         */
    unsigned long  TIM15GPR0;                              /* TIM15GPR0        */
    unsigned long  TIM15GPR1;                              /* TIM15GPR1        */
    unsigned long  TIM15CNT;                               /* TIM15CNT         */
    unsigned long  TIM15ECNT;                              /* TIM15ECNT        */
    unsigned long  TIM15CNTS;                              /* TIM15CNTS        */
    unsigned long  TIM15TDUC;                              /* TIM15TDUC        */
    unsigned long  TIM15TDUV;                              /* TIM15TDUV        */
    unsigned long  TIM15FLTRE;                             /* TIM15FLTRE       */
    unsigned long  TIM15FLTFE;                             /* TIM15FLTFE       */
    unsigned long  TIM15CTRL;                              /* TIM15CTRL        */
    unsigned long  TIM15ECTRL;                             /* TIM15ECTRL       */
    unsigned long  TIM15IRQNOTIFY;                         /* TIM15IRQNOTIFY   */
    unsigned long  TIM15IRQEN;                             /* TIM15IRQEN       */
    unsigned long  TIM15IRQFORCINT;                        /* TIM15IRQFORCINT  */
    unsigned long  TIM15IRQMODE;                           /* TIM15IRQMODE     */
    unsigned long  TIM15EIRQEN;                            /* TIM15EIRQEN      */
    unsigned char  dummy186[64];                           /* Reserved         */
    unsigned long  TIM16GPR0;                              /* TIM16GPR0        */
    unsigned long  TIM16GPR1;                              /* TIM16GPR1        */
    unsigned long  TIM16CNT;                               /* TIM16CNT         */
    unsigned long  TIM16ECNT;                              /* TIM16ECNT        */
    unsigned long  TIM16CNTS;                              /* TIM16CNTS        */
    unsigned long  TIM16TDUC;                              /* TIM16TDUC        */
    unsigned long  TIM16TDUV;                              /* TIM16TDUV        */
    unsigned long  TIM16FLTRE;                             /* TIM16FLTRE       */
    unsigned long  TIM16FLTFE;                             /* TIM16FLTFE       */
    unsigned long  TIM16CTRL;                              /* TIM16CTRL        */
    unsigned long  TIM16ECTRL;                             /* TIM16ECTRL       */
    unsigned long  TIM16IRQNOTIFY;                         /* TIM16IRQNOTIFY   */
    unsigned long  TIM16IRQEN;                             /* TIM16IRQEN       */
    unsigned long  TIM16IRQFORCINT;                        /* TIM16IRQFORCINT  */
    unsigned long  TIM16IRQMODE;                           /* TIM16IRQMODE     */
    unsigned long  TIM16EIRQEN;                            /* TIM16EIRQEN      */
    unsigned char  dummy187[64];                           /* Reserved         */
    unsigned long  TIM17GPR0;                              /* TIM17GPR0        */
    unsigned long  TIM17GPR1;                              /* TIM17GPR1        */
    unsigned long  TIM17CNT;                               /* TIM17CNT         */
    unsigned long  TIM17ECNT;                              /* TIM17ECNT        */
    unsigned long  TIM17CNTS;                              /* TIM17CNTS        */
    unsigned long  TIM17TDUC;                              /* TIM17TDUC        */
    unsigned long  TIM17TDUV;                              /* TIM17TDUV        */
    unsigned long  TIM17FLTRE;                             /* TIM17FLTRE       */
    unsigned long  TIM17FLTFE;                             /* TIM17FLTFE       */
    unsigned long  TIM17CTRL;                              /* TIM17CTRL        */
    unsigned long  TIM17ECTRL;                             /* TIM17ECTRL       */
    unsigned long  TIM17IRQNOTIFY;                         /* TIM17IRQNOTIFY   */
    unsigned long  TIM17IRQEN;                             /* TIM17IRQEN       */
    unsigned long  TIM17IRQFORCINT;                        /* TIM17IRQFORCINT  */
    unsigned long  TIM17IRQMODE;                           /* TIM17IRQMODE     */
    unsigned long  TIM17EIRQEN;                            /* TIM17EIRQEN      */
    unsigned char  dummy188[46144];                        /* Reserved         */
    unsigned long  ATOM00RDADDR;                           /* ATOM00RDADDR     */
    unsigned long  ATOM00CTRL;                             /* ATOM00CTRL       */
    unsigned long  ATOM00SR0;                              /* ATOM00SR0        */
    unsigned long  ATOM00SR1;                              /* ATOM00SR1        */
    unsigned long  ATOM00CM0;                              /* ATOM00CM0        */
    unsigned long  ATOM00CM1;                              /* ATOM00CM1        */
    unsigned long  ATOM00CN0;                              /* ATOM00CN0        */
    unsigned long  ATOM00STAT;                             /* ATOM00STAT       */
    unsigned long  ATOM00IRQNOTIFY;                        /* ATOM00IRQNOTIFY  */
    unsigned long  ATOM00IRQEN;                            /* ATOM00IRQEN      */
    unsigned long  ATOM00IRQFORCINT;                       /* ATOM00IRQFORCINT */
    unsigned long  ATOM00IRQMODE;                          /* ATOM00IRQMODE    */
    unsigned char  dummy189[16];                           /* Reserved         */
    unsigned long  ATOM0AGCGLBCTRL;                        /* ATOM0AGCGLBCTRL  */
    unsigned long  ATOM0AGCENDISCTRL;                      /* ATOM0AGCENDISCTRL */
    unsigned long  ATOM0AGCENDISSTAT;                      /* ATOM0AGCENDISSTAT */
    unsigned long  ATOM0AGCACTTB;                          /* ATOM0AGCACTTB    */
    unsigned long  ATOM0AGCOUTENCTRL;                      /* ATOM0AGCOUTENCTRL */
    unsigned long  ATOM0AGCOUTENSTAT;                      /* ATOM0AGCOUTENSTAT */
    unsigned long  ATOM0AGCFUPDCTRL;                       /* ATOM0AGCFUPDCTRL */
    unsigned long  ATOM0AGCINTTRIG;                        /* ATOM0AGCINTTRIG  */
    unsigned char  dummy190[32];                           /* Reserved         */
    unsigned long  ATOM01RDADDR;                           /* ATOM01RDADDR     */
    unsigned long  ATOM01CTRL;                             /* ATOM01CTRL       */
    unsigned long  ATOM01SR0;                              /* ATOM01SR0        */
    unsigned long  ATOM01SR1;                              /* ATOM01SR1        */
    unsigned long  ATOM01CM0;                              /* ATOM01CM0        */
    unsigned long  ATOM01CM1;                              /* ATOM01CM1        */
    unsigned long  ATOM01CN0;                              /* ATOM01CN0        */
    unsigned long  ATOM01STAT;                             /* ATOM01STAT       */
    unsigned long  ATOM01IRQNOTIFY;                        /* ATOM01IRQNOTIFY  */
    unsigned long  ATOM01IRQEN;                            /* ATOM01IRQEN      */
    unsigned long  ATOM01IRQFORCINT;                       /* ATOM01IRQFORCINT */
    unsigned long  ATOM01IRQMODE;                          /* ATOM01IRQMODE    */
    unsigned char  dummy191[80];                           /* Reserved         */
    unsigned long  ATOM02RDADDR;                           /* ATOM02RDADDR     */
    unsigned long  ATOM02CTRL;                             /* ATOM02CTRL       */
    unsigned long  ATOM02SR0;                              /* ATOM02SR0        */
    unsigned long  ATOM02SR1;                              /* ATOM02SR1        */
    unsigned long  ATOM02CM0;                              /* ATOM02CM0        */
    unsigned long  ATOM02CM1;                              /* ATOM02CM1        */
    unsigned long  ATOM02CN0;                              /* ATOM02CN0        */
    unsigned long  ATOM02STAT;                             /* ATOM02STAT       */
    unsigned long  ATOM02IRQNOTIFY;                        /* ATOM02IRQNOTIFY  */
    unsigned long  ATOM02IRQEN;                            /* ATOM02IRQEN      */
    unsigned long  ATOM02IRQFORCINT;                       /* ATOM02IRQFORCINT */
    unsigned long  ATOM02IRQMODE;                          /* ATOM02IRQMODE    */
    unsigned char  dummy192[80];                           /* Reserved         */
    unsigned long  ATOM03RDADDR;                           /* ATOM03RDADDR     */
    unsigned long  ATOM03CTRL;                             /* ATOM03CTRL       */
    unsigned long  ATOM03SR0;                              /* ATOM03SR0        */
    unsigned long  ATOM03SR1;                              /* ATOM03SR1        */
    unsigned long  ATOM03CM0;                              /* ATOM03CM0        */
    unsigned long  ATOM03CM1;                              /* ATOM03CM1        */
    unsigned long  ATOM03CN0;                              /* ATOM03CN0        */
    unsigned long  ATOM03STAT;                             /* ATOM03STAT       */
    unsigned long  ATOM03IRQNOTIFY;                        /* ATOM03IRQNOTIFY  */
    unsigned long  ATOM03IRQEN;                            /* ATOM03IRQEN      */
    unsigned long  ATOM03IRQFORCINT;                       /* ATOM03IRQFORCINT */
    unsigned long  ATOM03IRQMODE;                          /* ATOM03IRQMODE    */
    unsigned char  dummy193[80];                           /* Reserved         */
    unsigned long  ATOM04RDADDR;                           /* ATOM04RDADDR     */
    unsigned long  ATOM04CTRL;                             /* ATOM04CTRL       */
    unsigned long  ATOM04SR0;                              /* ATOM04SR0        */
    unsigned long  ATOM04SR1;                              /* ATOM04SR1        */
    unsigned long  ATOM04CM0;                              /* ATOM04CM0        */
    unsigned long  ATOM04CM1;                              /* ATOM04CM1        */
    unsigned long  ATOM04CN0;                              /* ATOM04CN0        */
    unsigned long  ATOM04STAT;                             /* ATOM04STAT       */
    unsigned long  ATOM04IRQNOTIFY;                        /* ATOM04IRQNOTIFY  */
    unsigned long  ATOM04IRQEN;                            /* ATOM04IRQEN      */
    unsigned long  ATOM04IRQFORCINT;                       /* ATOM04IRQFORCINT */
    unsigned long  ATOM04IRQMODE;                          /* ATOM04IRQMODE    */
    unsigned char  dummy194[80];                           /* Reserved         */
    unsigned long  ATOM05RDADDR;                           /* ATOM05RDADDR     */
    unsigned long  ATOM05CTRL;                             /* ATOM05CTRL       */
    unsigned long  ATOM05SR0;                              /* ATOM05SR0        */
    unsigned long  ATOM05SR1;                              /* ATOM05SR1        */
    unsigned long  ATOM05CM0;                              /* ATOM05CM0        */
    unsigned long  ATOM05CM1;                              /* ATOM05CM1        */
    unsigned long  ATOM05CN0;                              /* ATOM05CN0        */
    unsigned long  ATOM05STAT;                             /* ATOM05STAT       */
    unsigned long  ATOM05IRQNOTIFY;                        /* ATOM05IRQNOTIFY  */
    unsigned long  ATOM05IRQEN;                            /* ATOM05IRQEN      */
    unsigned long  ATOM05IRQFORCINT;                       /* ATOM05IRQFORCINT */
    unsigned long  ATOM05IRQMODE;                          /* ATOM05IRQMODE    */
    unsigned char  dummy195[80];                           /* Reserved         */
    unsigned long  ATOM06RDADDR;                           /* ATOM06RDADDR     */
    unsigned long  ATOM06CTRL;                             /* ATOM06CTRL       */
    unsigned long  ATOM06SR0;                              /* ATOM06SR0        */
    unsigned long  ATOM06SR1;                              /* ATOM06SR1        */
    unsigned long  ATOM06CM0;                              /* ATOM06CM0        */
    unsigned long  ATOM06CM1;                              /* ATOM06CM1        */
    unsigned long  ATOM06CN0;                              /* ATOM06CN0        */
    unsigned long  ATOM06STAT;                             /* ATOM06STAT       */
    unsigned long  ATOM06IRQNOTIFY;                        /* ATOM06IRQNOTIFY  */
    unsigned long  ATOM06IRQEN;                            /* ATOM06IRQEN      */
    unsigned long  ATOM06IRQFORCINT;                       /* ATOM06IRQFORCINT */
    unsigned long  ATOM06IRQMODE;                          /* ATOM06IRQMODE    */
    unsigned char  dummy196[80];                           /* Reserved         */
    unsigned long  ATOM07RDADDR;                           /* ATOM07RDADDR     */
    unsigned long  ATOM07CTRL;                             /* ATOM07CTRL       */
    unsigned long  ATOM07SR0;                              /* ATOM07SR0        */
    unsigned long  ATOM07SR1;                              /* ATOM07SR1        */
    unsigned long  ATOM07CM0;                              /* ATOM07CM0        */
    unsigned long  ATOM07CM1;                              /* ATOM07CM1        */
    unsigned long  ATOM07CN0;                              /* ATOM07CN0        */
    unsigned long  ATOM07STAT;                             /* ATOM07STAT       */
    unsigned long  ATOM07IRQNOTIFY;                        /* ATOM07IRQNOTIFY  */
    unsigned long  ATOM07IRQEN;                            /* ATOM07IRQEN      */
    unsigned long  ATOM07IRQFORCINT;                       /* ATOM07IRQFORCINT */
    unsigned long  ATOM07IRQMODE;                          /* ATOM07IRQMODE    */
    unsigned char  dummy197[1104];                         /* Reserved         */
    unsigned long  ATOM10RDADDR;                           /* ATOM10RDADDR     */
    unsigned long  ATOM10CTRL;                             /* ATOM10CTRL       */
    unsigned long  ATOM10SR0;                              /* ATOM10SR0        */
    unsigned long  ATOM10SR1;                              /* ATOM10SR1        */
    unsigned long  ATOM10CM0;                              /* ATOM10CM0        */
    unsigned long  ATOM10CM1;                              /* ATOM10CM1        */
    unsigned long  ATOM10CN0;                              /* ATOM10CN0        */
    unsigned long  ATOM10STAT;                             /* ATOM10STAT       */
    unsigned long  ATOM10IRQNOTIFY;                        /* ATOM10IRQNOTIFY  */
    unsigned long  ATOM10IRQEN;                            /* ATOM10IRQEN      */
    unsigned long  ATOM10IRQFORCINT;                       /* ATOM10IRQFORCINT */
    unsigned long  ATOM10IRQMODE;                          /* ATOM10IRQMODE    */
    unsigned char  dummy198[16];                           /* Reserved         */
    unsigned long  ATOM1AGCGLBCTRL;                        /* ATOM1AGCGLBCTRL  */
    unsigned long  ATOM1AGCENDISCTRL;                      /* ATOM1AGCENDISCTRL */
    unsigned long  ATOM1AGCENDISSTAT;                      /* ATOM1AGCENDISSTAT */
    unsigned long  ATOM1AGCACTTB;                          /* ATOM1AGCACTTB    */
    unsigned long  ATOM1AGCOUTENCTRL;                      /* ATOM1AGCOUTENCTRL */
    unsigned long  ATOM1AGCOUTENSTAT;                      /* ATOM1AGCOUTENSTAT */
    unsigned long  ATOM1AGCFUPDCTRL;                       /* ATOM1AGCFUPDCTRL */
    unsigned long  ATOM1AGCINTTRIG;                        /* ATOM1AGCINTTRIG  */
    unsigned char  dummy199[32];                           /* Reserved         */
    unsigned long  ATOM11RDADDR;                           /* ATOM11RDADDR     */
    unsigned long  ATOM11CTRL;                             /* ATOM11CTRL       */
    unsigned long  ATOM11SR0;                              /* ATOM11SR0        */
    unsigned long  ATOM11SR1;                              /* ATOM11SR1        */
    unsigned long  ATOM11CM0;                              /* ATOM11CM0        */
    unsigned long  ATOM11CM1;                              /* ATOM11CM1        */
    unsigned long  ATOM11CN0;                              /* ATOM11CN0        */
    unsigned long  ATOM11STAT;                             /* ATOM11STAT       */
    unsigned long  ATOM11IRQNOTIFY;                        /* ATOM11IRQNOTIFY  */
    unsigned long  ATOM11IRQEN;                            /* ATOM11IRQEN      */
    unsigned long  ATOM11IRQFORCINT;                       /* ATOM11IRQFORCINT */
    unsigned long  ATOM11IRQMODE;                          /* ATOM11IRQMODE    */
    unsigned char  dummy200[80];                           /* Reserved         */
    unsigned long  ATOM12RDADDR;                           /* ATOM12RDADDR     */
    unsigned long  ATOM12CTRL;                             /* ATOM12CTRL       */
    unsigned long  ATOM12SR0;                              /* ATOM12SR0        */
    unsigned long  ATOM12SR1;                              /* ATOM12SR1        */
    unsigned long  ATOM12CM0;                              /* ATOM12CM0        */
    unsigned long  ATOM12CM1;                              /* ATOM12CM1        */
    unsigned long  ATOM12CN0;                              /* ATOM12CN0        */
    unsigned long  ATOM12STAT;                             /* ATOM12STAT       */
    unsigned long  ATOM12IRQNOTIFY;                        /* ATOM12IRQNOTIFY  */
    unsigned long  ATOM12IRQEN;                            /* ATOM12IRQEN      */
    unsigned long  ATOM12IRQFORCINT;                       /* ATOM12IRQFORCINT */
    unsigned long  ATOM12IRQMODE;                          /* ATOM12IRQMODE    */
    unsigned char  dummy201[80];                           /* Reserved         */
    unsigned long  ATOM13RDADDR;                           /* ATOM13RDADDR     */
    unsigned long  ATOM13CTRL;                             /* ATOM13CTRL       */
    unsigned long  ATOM13SR0;                              /* ATOM13SR0        */
    unsigned long  ATOM13SR1;                              /* ATOM13SR1        */
    unsigned long  ATOM13CM0;                              /* ATOM13CM0        */
    unsigned long  ATOM13CM1;                              /* ATOM13CM1        */
    unsigned long  ATOM13CN0;                              /* ATOM13CN0        */
    unsigned long  ATOM13STAT;                             /* ATOM13STAT       */
    unsigned long  ATOM13IRQNOTIFY;                        /* ATOM13IRQNOTIFY  */
    unsigned long  ATOM13IRQEN;                            /* ATOM13IRQEN      */
    unsigned long  ATOM13IRQFORCINT;                       /* ATOM13IRQFORCINT */
    unsigned long  ATOM13IRQMODE;                          /* ATOM13IRQMODE    */
    unsigned char  dummy202[23632];                        /* Reserved         */
    unsigned long  DTM24CTRL;                              /* DTM24CTRL        */
    unsigned long  DTM24CHCTRL1;                           /* DTM24CHCTRL1     */
    unsigned long  DTM24CHCTRL2;                           /* DTM24CHCTRL2     */
    unsigned long  DTM24CHCTRL2SR;                         /* DTM24CHCTRL2SR   */
    unsigned long  DTM24PSCTRL;                            /* DTM24PSCTRL      */
    unsigned long  DTM240DTV;                              /* DTM240DTV        */
    unsigned long  DTM241DTV;                              /* DTM241DTV        */
    unsigned long  DTM242DTV;                              /* DTM242DTV        */
    unsigned long  DTM243DTV;                              /* DTM243DTV        */
    unsigned long  DTM24CHSR;                              /* DTM24CHSR        */
    unsigned char  dummy203[88];                           /* Reserved         */
    unsigned long  DTM26CTRL;                              /* DTM26CTRL        */
    unsigned long  DTM26CHCTRL1;                           /* DTM26CHCTRL1     */
    unsigned long  DTM26CHCTRL2;                           /* DTM26CHCTRL2     */
    unsigned long  DTM26CHCTRL2SR;                         /* DTM26CHCTRL2SR   */
    unsigned long  DTM26PSCTRL;                            /* DTM26PSCTRL      */
    unsigned long  DTM260DTV;                              /* DTM260DTV        */
    unsigned long  DTM261DTV;                              /* DTM261DTV        */
    unsigned long  DTM262DTV;                              /* DTM262DTV        */
    unsigned long  DTM263DTV;                              /* DTM263DTV        */
    unsigned long  DTM26CHSR;                              /* DTM26CHSR        */
    unsigned char  dummy204[117080];                       /* Reserved         */
    unsigned long  MCS00R0;                                /* MCS00R0          */
    unsigned long  MCS00R1;                                /* MCS00R1          */
    unsigned long  MCS00R2;                                /* MCS00R2          */
    unsigned long  MCS00R3;                                /* MCS00R3          */
    unsigned long  MCS00R4;                                /* MCS00R4          */
    unsigned long  MCS00R5;                                /* MCS00R5          */
    unsigned long  MCS00R6;                                /* MCS00R6          */
    unsigned long  MCS00R7;                                /* MCS00R7          */
    unsigned long  MCS00CTRL;                              /* MCS00CTRL        */
    unsigned long  MCS00ACB;                               /* MCS00ACB         */
    unsigned long  MCS0CTRG;                               /* MCS0CTRG         */
    unsigned long  MCS0STRG;                               /* MCS0STRG         */
    unsigned char  dummy205[12];                           /* Reserved         */
    unsigned long  MCS00MHB;                               /* MCS00MHB         */
    unsigned long  MCS00PC;                                /* MCS00PC          */
    unsigned long  MCS00IRQNOTIFY;                         /* MCS00IRQNOTIFY   */
    unsigned long  MCS00IRQEN;                             /* MCS00IRQEN       */
    unsigned long  MCS00IRQFORCINT;                        /* MCS00IRQFORCINT  */
    unsigned long  MCS00IRQMODE;                           /* MCS00IRQMODE     */
    unsigned long  MCS00EIRQEN;                            /* MCS00EIRQEN      */
    unsigned char  dummy206[12];                           /* Reserved         */
    unsigned long  MCS0CTRLSTAT;                           /* MCS0CTRLSTAT     */
    unsigned long  MCS0RESET;                              /* MCS0RESET        */
    unsigned long  MCS0CAT;                                /* MCS0CAT          */
    unsigned long  MCS0CWT;                                /* MCS0CWT          */
    unsigned char  dummy207[8];                            /* Reserved         */
    unsigned long  MCS0ERR;                                /* MCS0ERR          */
    unsigned long  MCS01R0;                                /* MCS01R0          */
    unsigned long  MCS01R1;                                /* MCS01R1          */
    unsigned long  MCS01R2;                                /* MCS01R2          */
    unsigned long  MCS01R3;                                /* MCS01R3          */
    unsigned long  MCS01R4;                                /* MCS01R4          */
    unsigned long  MCS01R5;                                /* MCS01R5          */
    unsigned long  MCS01R6;                                /* MCS01R6          */
    unsigned long  MCS01R7;                                /* MCS01R7          */
    unsigned long  MCS01CTRL;                              /* MCS01CTRL        */
    unsigned long  MCS01ACB;                               /* MCS01ACB         */
    unsigned char  dummy208[20];                           /* Reserved         */
    unsigned long  MCS01MHB;                               /* MCS01MHB         */
    unsigned long  MCS01PC;                                /* MCS01PC          */
    unsigned long  MCS01IRQNOTIFY;                         /* MCS01IRQNOTIFY   */
    unsigned long  MCS01IRQEN;                             /* MCS01IRQEN       */
    unsigned long  MCS01IRQFORCINT;                        /* MCS01IRQFORCINT  */
    unsigned long  MCS01IRQMODE;                           /* MCS01IRQMODE     */
    unsigned long  MCS01EIRQEN;                            /* MCS01EIRQEN      */
    unsigned char  dummy209[40];                           /* Reserved         */
    unsigned long  MCS02R0;                                /* MCS02R0          */
    unsigned long  MCS02R1;                                /* MCS02R1          */
    unsigned long  MCS02R2;                                /* MCS02R2          */
    unsigned long  MCS02R3;                                /* MCS02R3          */
    unsigned long  MCS02R4;                                /* MCS02R4          */
    unsigned long  MCS02R5;                                /* MCS02R5          */
    unsigned long  MCS02R6;                                /* MCS02R6          */
    unsigned long  MCS02R7;                                /* MCS02R7          */
    unsigned long  MCS02CTRL;                              /* MCS02CTRL        */
    unsigned long  MCS02ACB;                               /* MCS02ACB         */
    unsigned char  dummy210[20];                           /* Reserved         */
    unsigned long  MCS02MHB;                               /* MCS02MHB         */
    unsigned long  MCS02PC;                                /* MCS02PC          */
    unsigned long  MCS02IRQNOTIFY;                         /* MCS02IRQNOTIFY   */
    unsigned long  MCS02IRQEN;                             /* MCS02IRQEN       */
    unsigned long  MCS02IRQFORCINT;                        /* MCS02IRQFORCINT  */
    unsigned long  MCS02IRQMODE;                           /* MCS02IRQMODE     */
    unsigned long  MCS02EIRQEN;                            /* MCS02EIRQEN      */
    unsigned char  dummy211[40];                           /* Reserved         */
    unsigned long  MCS03R0;                                /* MCS03R0          */
    unsigned long  MCS03R1;                                /* MCS03R1          */
    unsigned long  MCS03R2;                                /* MCS03R2          */
    unsigned long  MCS03R3;                                /* MCS03R3          */
    unsigned long  MCS03R4;                                /* MCS03R4          */
    unsigned long  MCS03R5;                                /* MCS03R5          */
    unsigned long  MCS03R6;                                /* MCS03R6          */
    unsigned long  MCS03R7;                                /* MCS03R7          */
    unsigned long  MCS03CTRL;                              /* MCS03CTRL        */
    unsigned long  MCS03ACB;                               /* MCS03ACB         */
    unsigned char  dummy212[20];                           /* Reserved         */
    unsigned long  MCS03MHB;                               /* MCS03MHB         */
    unsigned long  MCS03PC;                                /* MCS03PC          */
    unsigned long  MCS03IRQNOTIFY;                         /* MCS03IRQNOTIFY   */
    unsigned long  MCS03IRQEN;                             /* MCS03IRQEN       */
    unsigned long  MCS03IRQFORCINT;                        /* MCS03IRQFORCINT  */
    unsigned long  MCS03IRQMODE;                           /* MCS03IRQMODE     */
    unsigned long  MCS03EIRQEN;                            /* MCS03EIRQEN      */
    unsigned char  dummy213[40];                           /* Reserved         */
    unsigned long  MCS04R0;                                /* MCS04R0          */
    unsigned long  MCS04R1;                                /* MCS04R1          */
    unsigned long  MCS04R2;                                /* MCS04R2          */
    unsigned long  MCS04R3;                                /* MCS04R3          */
    unsigned long  MCS04R4;                                /* MCS04R4          */
    unsigned long  MCS04R5;                                /* MCS04R5          */
    unsigned long  MCS04R6;                                /* MCS04R6          */
    unsigned long  MCS04R7;                                /* MCS04R7          */
    unsigned long  MCS04CTRL;                              /* MCS04CTRL        */
    unsigned long  MCS04ACB;                               /* MCS04ACB         */
    unsigned char  dummy214[20];                           /* Reserved         */
    unsigned long  MCS04MHB;                               /* MCS04MHB         */
    unsigned long  MCS04PC;                                /* MCS04PC          */
    unsigned long  MCS04IRQNOTIFY;                         /* MCS04IRQNOTIFY   */
    unsigned long  MCS04IRQEN;                             /* MCS04IRQEN       */
    unsigned long  MCS04IRQFORCINT;                        /* MCS04IRQFORCINT  */
    unsigned long  MCS04IRQMODE;                           /* MCS04IRQMODE     */
    unsigned long  MCS04EIRQEN;                            /* MCS04EIRQEN      */
    unsigned char  dummy215[40];                           /* Reserved         */
    unsigned long  MCS05R0;                                /* MCS05R0          */
    unsigned long  MCS05R1;                                /* MCS05R1          */
    unsigned long  MCS05R2;                                /* MCS05R2          */
    unsigned long  MCS05R3;                                /* MCS05R3          */
    unsigned long  MCS05R4;                                /* MCS05R4          */
    unsigned long  MCS05R5;                                /* MCS05R5          */
    unsigned long  MCS05R6;                                /* MCS05R6          */
    unsigned long  MCS05R7;                                /* MCS05R7          */
    unsigned long  MCS05CTRL;                              /* MCS05CTRL        */
    unsigned long  MCS05ACB;                               /* MCS05ACB         */
    unsigned char  dummy216[20];                           /* Reserved         */
    unsigned long  MCS05MHB;                               /* MCS05MHB         */
    unsigned long  MCS05PC;                                /* MCS05PC          */
    unsigned long  MCS05IRQNOTIFY;                         /* MCS05IRQNOTIFY   */
    unsigned long  MCS05IRQEN;                             /* MCS05IRQEN       */
    unsigned long  MCS05IRQFORCINT;                        /* MCS05IRQFORCINT  */
    unsigned long  MCS05IRQMODE;                           /* MCS05IRQMODE     */
    unsigned long  MCS05EIRQEN;                            /* MCS05EIRQEN      */
    unsigned char  dummy217[40];                           /* Reserved         */
    unsigned long  MCS06R0;                                /* MCS06R0          */
    unsigned long  MCS06R1;                                /* MCS06R1          */
    unsigned long  MCS06R2;                                /* MCS06R2          */
    unsigned long  MCS06R3;                                /* MCS06R3          */
    unsigned long  MCS06R4;                                /* MCS06R4          */
    unsigned long  MCS06R5;                                /* MCS06R5          */
    unsigned long  MCS06R6;                                /* MCS06R6          */
    unsigned long  MCS06R7;                                /* MCS06R7          */
    unsigned long  MCS06CTRL;                              /* MCS06CTRL        */
    unsigned long  MCS06ACB;                               /* MCS06ACB         */
    unsigned char  dummy218[20];                           /* Reserved         */
    unsigned long  MCS06MHB;                               /* MCS06MHB         */
    unsigned long  MCS06PC;                                /* MCS06PC          */
    unsigned long  MCS06IRQNOTIFY;                         /* MCS06IRQNOTIFY   */
    unsigned long  MCS06IRQEN;                             /* MCS06IRQEN       */
    unsigned long  MCS06IRQFORCINT;                        /* MCS06IRQFORCINT  */
    unsigned long  MCS06IRQMODE;                           /* MCS06IRQMODE     */
    unsigned long  MCS06EIRQEN;                            /* MCS06EIRQEN      */
    unsigned char  dummy219[40];                           /* Reserved         */
    unsigned long  MCS07R0;                                /* MCS07R0          */
    unsigned long  MCS07R1;                                /* MCS07R1          */
    unsigned long  MCS07R2;                                /* MCS07R2          */
    unsigned long  MCS07R3;                                /* MCS07R3          */
    unsigned long  MCS07R4;                                /* MCS07R4          */
    unsigned long  MCS07R5;                                /* MCS07R5          */
    unsigned long  MCS07R6;                                /* MCS07R6          */
    unsigned long  MCS07R7;                                /* MCS07R7          */
    unsigned long  MCS07CTRL;                              /* MCS07CTRL        */
    unsigned long  MCS07ACB;                               /* MCS07ACB         */
    unsigned char  dummy220[20];                           /* Reserved         */
    unsigned long  MCS07MHB;                               /* MCS07MHB         */
    unsigned long  MCS07PC;                                /* MCS07PC          */
    unsigned long  MCS07IRQNOTIFY;                         /* MCS07IRQNOTIFY   */
    unsigned long  MCS07IRQEN;                             /* MCS07IRQEN       */
    unsigned long  MCS07IRQFORCINT;                        /* MCS07IRQFORCINT  */
    unsigned long  MCS07IRQMODE;                           /* MCS07IRQMODE     */
    unsigned long  MCS07EIRQEN;                            /* MCS07EIRQEN      */
    unsigned char  dummy221[40];                           /* Reserved         */
    unsigned long  MCS08R0;                                /* MCS08R0          */
    unsigned long  MCS08R1;                                /* MCS08R1          */
    unsigned long  MCS08R2;                                /* MCS08R2          */
    unsigned long  MCS08R3;                                /* MCS08R3          */
    unsigned long  MCS08R4;                                /* MCS08R4          */
    unsigned long  MCS08R5;                                /* MCS08R5          */
    unsigned long  MCS08R6;                                /* MCS08R6          */
    unsigned long  MCS08R7;                                /* MCS08R7          */
    unsigned long  MCS08CTRL;                              /* MCS08CTRL        */
    unsigned long  MCS08ACB;                               /* MCS08ACB         */
    unsigned char  dummy222[20];                           /* Reserved         */
    unsigned long  MCS08MHB;                               /* MCS08MHB         */
    unsigned long  MCS08PC;                                /* MCS08PC          */
    unsigned long  MCS08IRQNOTIFY;                         /* MCS08IRQNOTIFY   */
    unsigned long  MCS08IRQEN;                             /* MCS08IRQEN       */
    unsigned long  MCS08IRQFORCINT;                        /* MCS08IRQFORCINT  */
    unsigned long  MCS08IRQMODE;                           /* MCS08IRQMODE     */
    unsigned long  MCS08EIRQEN;                            /* MCS08EIRQEN      */
};
struct __tag95
{                                                          /* Module           */
    unsigned char  WDTE;                                   /* WDTE             */
    unsigned char  dummy223[3];                            /* Reserved         */
    unsigned char  EVAC;                                   /* EVAC             */
    unsigned char  dummy224[3];                            /* Reserved         */
    unsigned char  REF;                                    /* REF              */
    unsigned char  dummy225[3];                            /* Reserved         */
    unsigned char  MD;                                     /* MD               */
};
struct __tag96
{                                                          /* Module           */
    unsigned long  CLR;                                    /* CLR              */
    unsigned long  STS0;                                   /* STS0             */
    unsigned long  STS1;                                   /* STS1             */
    unsigned long  STSC;                                   /* STSC             */
    unsigned long  WDTE;                                   /* WDTE             */
    unsigned long  MD;                                     /* MD               */
    unsigned char  dummy226[8];                            /* Reserved         */
    unsigned long  PCAD;                                   /* PCAD             */
};
struct __tag97
{                                                          /* Module           */
    union __tag28 PROT00;                                  /* PROT00           */
    union __tag28 SPID00;                                  /* SPID00           */
    union __tag28 PROT01;                                  /* PROT01           */
    union __tag28 SPID01;                                  /* SPID01           */
    unsigned char  dummy227[32];                           /* Reserved         */
    union __tag28 PROT06;                                  /* PROT06           */
    union __tag28 SPID06;                                  /* SPID06           */
    union __tag28 PROT07;                                  /* PROT07           */
    union __tag28 SPID07;                                  /* SPID07           */
    unsigned char  dummy228[16];                           /* Reserved         */
    union __tag28 PROT10;                                  /* PROT10           */
    union __tag28 SPID10;                                  /* SPID10           */
    union __tag28 PROT11;                                  /* PROT11           */
    union __tag28 SPID11;                                  /* SPID11           */
    union __tag28 PROT12;                                  /* PROT12           */
    union __tag28 SPID12;                                  /* SPID12           */
    union __tag28 PROT13;                                  /* PROT13           */
    union __tag28 SPID13;                                  /* SPID13           */
};
struct __tag98
{                                                          /* Module           */
    union __tag28 CREL;                                    /* CREL             */
    union __tag28 ENDN;                                    /* ENDN             */
    unsigned char  dummy229[4];                            /* Reserved         */
    union __tag53 DBTP;                                    /* DBTP             */
    union __tag28 TEST;                                    /* TEST             */
    union __tag28 RWD;                                     /* RWD              */
    union __tag28 CCCR;                                    /* CCCR             */
    union __tag54 BTP;                                     /* BTP              */
    union __tag28 TSCC;                                    /* TSCC             */
    union __tag28 TSCV;                                    /* TSCV             */
    union __tag28 TOCC;                                    /* TOCC             */
    union __tag28 TOCV;                                    /* TOCV             */
    unsigned char  dummy230[16];                           /* Reserved         */
    union __tag28 ECR;                                     /* ECR              */
    union __tag28 PSR;                                     /* PSR              */
    union __tag28 TDCR;                                    /* TDCR             */
    unsigned char  dummy231[4];                            /* Reserved         */
    union __tag28 IR;                                      /* IR               */
    union __tag28 IE;                                      /* IE               */
    union __tag28 ILS;                                     /* ILS              */
    union __tag28 ILE;                                     /* ILE              */
    unsigned char  dummy232[32];                           /* Reserved         */
    union __tag28 GFC;                                     /* GFC              */
    union __tag28 SIDFC;                                   /* SIDFC            */
    union __tag28 XIDFC;                                   /* XIDFC            */
    unsigned char  dummy233[4];                            /* Reserved         */
    union __tag28 XIDAM;                                   /* XIDAM            */
    union __tag28 HPMS;                                    /* HPMS             */
    union __tag28 NDAT1;                                   /* NDAT1            */
    union __tag28 NDAT2;                                   /* NDAT2            */
    union __tag28 RXF0C;                                   /* RXF0C            */
    union __tag28 RXF0S;                                   /* RXF0S            */
    union __tag28 RXF0A;                                   /* RXF0A            */
    union __tag28 RXBC;                                    /* RXBC             */
    union __tag28 RXF1C;                                   /* RXF1C            */
    union __tag28 RXF1S;                                   /* RXF1S            */
    union __tag28 RXF1A;                                   /* RXF1A            */
    union __tag28 RXESC;                                   /* RXESC            */
    union __tag28 TXBC;                                    /* TXBC             */
    union __tag28 TXFQS;                                   /* TXFQS            */
    union __tag28 TXESC;                                   /* TXESC            */
    union __tag28 TXBRP;                                   /* TXBRP            */
    union __tag28 TXBAR;                                   /* TXBAR            */
    union __tag28 TXBCR;                                   /* TXBCR            */
    union __tag28 TXBTO;                                   /* TXBTO            */
    union __tag28 TXBCF;                                   /* TXBCF            */
    union __tag28 TXBTIE;                                  /* TXBTIE           */
    union __tag28 TXBCIE;                                  /* TXBCIE           */
    unsigned char  dummy234[8];                            /* Reserved         */
    union __tag28 TXEFC;                                   /* TXEFC            */
    union __tag28 TXEFS;                                   /* TXEFS            */
    union __tag28 TXEFA;                                   /* TXEFA            */
};
struct __tag99
{                                                          /* Module           */
    unsigned char  CTL0;                                   /* CTL0             */
    unsigned char  dummy235[7];                            /* Reserved         */
    unsigned short CMPL;                                   /* CMPL             */
    unsigned char  dummy236[2];                            /* Reserved         */
    unsigned short CMPH;                                   /* CMPH             */
    unsigned char  dummy237[2];                            /* Reserved         */
    unsigned char  PCMD;                                   /* PCMD             */
    unsigned char  dummy238[3];                            /* Reserved         */
    unsigned char  PS;                                     /* PS               */
    unsigned char  dummy239[3];                            /* Reserved         */
    unsigned char  EMU0;                                   /* EMU0             */
};
struct __tag100
{                                                          /* Module           */
    unsigned char  CTL0;                                   /* CTL0             */
    unsigned char  dummy240[3];                            /* Reserved         */
    unsigned char  CTL1;                                   /* CTL1             */
    unsigned char  dummy241[3];                            /* Reserved         */
    unsigned short CMPL;                                   /* CMPL             */
    unsigned char  dummy242[2];                            /* Reserved         */
    unsigned short CMPH;                                   /* CMPH             */
    unsigned char  dummy243[2];                            /* Reserved         */
    unsigned char  PCMD;                                   /* PCMD             */
    unsigned char  dummy244[3];                            /* Reserved         */
    unsigned char  PS;                                     /* PS               */
    unsigned char  dummy245[3];                            /* Reserved         */
    unsigned char  EMU0;                                   /* EMU0             */
};
struct __tag101
{                                                          /* Module           */
    union __tag28 PROT00;                                  /* PROT00           */
    union __tag28 SPID00;                                  /* SPID00           */
    union __tag28 PROT01;                                  /* PROT01           */
    union __tag28 SPID01;                                  /* SPID01           */
    union __tag28 PROT02;                                  /* PROT02           */
    union __tag28 SPID02;                                  /* SPID02           */
    union __tag28 PROT03;                                  /* PROT03           */
    union __tag28 SPID03;                                  /* SPID03           */
    union __tag28 PROT04;                                  /* PROT04           */
    union __tag28 SPID04;                                  /* SPID04           */
    union __tag28 PROT05;                                  /* PROT05           */
    union __tag28 SPID05;                                  /* SPID05           */
    union __tag28 PROT06;                                  /* PROT06           */
    union __tag28 SPID06;                                  /* SPID06           */
    union __tag28 PROT07;                                  /* PROT07           */
    union __tag28 SPID07;                                  /* SPID07           */
    union __tag28 PROT08;                                  /* PROT08           */
    union __tag28 SPID08;                                  /* SPID08           */
    union __tag28 PROT09;                                  /* PROT09           */
    union __tag28 SPID09;                                  /* SPID09           */
    union __tag28 PROT10;                                  /* PROT10           */
    union __tag28 SPID10;                                  /* SPID10           */
    union __tag28 PROT11;                                  /* PROT11           */
    union __tag28 SPID11;                                  /* SPID11           */
    union __tag28 PROT12;                                  /* PROT12           */
    union __tag28 SPID12;                                  /* SPID12           */
    union __tag28 PROT13;                                  /* PROT13           */
    union __tag28 SPID13;                                  /* SPID13           */
    union __tag28 PROT14;                                  /* PROT14           */
    union __tag28 SPID14;                                  /* SPID14           */
    union __tag28 PROT15;                                  /* PROT15           */
    union __tag28 SPID15;                                  /* SPID15           */
};
struct __tag102
{                                                          /* Module           */
    union __tag28 PROT00;                                  /* PROT00           */
    union __tag28 SPID00;                                  /* SPID00           */
    union __tag28 PROT01;                                  /* PROT01           */
    union __tag28 SPID01;                                  /* SPID01           */
    union __tag28 PROT02;                                  /* PROT02           */
    union __tag28 SPID02;                                  /* SPID02           */
    union __tag28 PROT03;                                  /* PROT03           */
    union __tag28 SPID03;                                  /* SPID03           */
    union __tag28 PROT04;                                  /* PROT04           */
    union __tag28 SPID04;                                  /* SPID04           */
    union __tag28 PROT05;                                  /* PROT05           */
    union __tag28 SPID05;                                  /* SPID05           */
    union __tag28 PROT06;                                  /* PROT06           */
    union __tag28 SPID06;                                  /* SPID06           */
    union __tag28 PROT07;                                  /* PROT07           */
    union __tag28 SPID07;                                  /* SPID07           */
    union __tag28 PROT08;                                  /* PROT08           */
    union __tag28 SPID08;                                  /* SPID08           */
    union __tag28 PROT09;                                  /* PROT09           */
    union __tag28 SPID09;                                  /* SPID09           */
    union __tag28 PROT10;                                  /* PROT10           */
    union __tag28 SPID10;                                  /* SPID10           */
    union __tag28 PROT11;                                  /* PROT11           */
    union __tag28 SPID11;                                  /* SPID11           */
    union __tag28 PROT12;                                  /* PROT12           */
    union __tag28 SPID12;                                  /* SPID12           */
    union __tag28 PROT13;                                  /* PROT13           */
    union __tag28 SPID13;                                  /* SPID13           */
};
struct __tag103
{                                                          /* Module           */
    unsigned long  VCR0;                                   /* VCR0             */
    unsigned long  VCR1;                                   /* VCR1             */
    unsigned long  VCR2;                                   /* VCR2             */
    unsigned long  VCR3;                                   /* VCR3             */
    unsigned long  VCR4;                                   /* VCR4             */
    unsigned long  VCR5;                                   /* VCR5             */
    unsigned long  VCR6;                                   /* VCR6             */
    unsigned long  VCR7;                                   /* VCR7             */
    unsigned long  VCR8;                                   /* VCR8             */
    unsigned long  VCR9;                                   /* VCR9             */
    unsigned long  VCR10;                                  /* VCR10            */
    unsigned long  VCR11;                                  /* VCR11            */
    unsigned long  VCR12;                                  /* VCR12            */
    unsigned long  VCR13;                                  /* VCR13            */
    unsigned long  VCR14;                                  /* VCR14            */
    unsigned long  VCR15;                                  /* VCR15            */
    unsigned long  VCR16;                                  /* VCR16            */
    unsigned long  VCR17;                                  /* VCR17            */
    unsigned long  VCR18;                                  /* VCR18            */
    unsigned long  VCR19;                                  /* VCR19            */
    unsigned long  VCR20;                                  /* VCR20            */
    unsigned long  VCR21;                                  /* VCR21            */
    unsigned long  VCR22;                                  /* VCR22            */
    unsigned long  VCR23;                                  /* VCR23            */
    unsigned char  dummy246[160];                          /* Reserved         */
    unsigned long  DR00;                                   /* DR00             */
    unsigned long  DR02;                                   /* DR02             */
    unsigned long  DR04;                                   /* DR04             */
    unsigned long  DR06;                                   /* DR06             */
    unsigned long  DR08;                                   /* DR08             */
    unsigned long  DR10;                                   /* DR10             */
    unsigned long  DR12;                                   /* DR12             */
    unsigned long  DR14;                                   /* DR14             */
    unsigned long  DR16;                                   /* DR16             */
    unsigned long  DR18;                                   /* DR18             */
    unsigned long  DR20;                                   /* DR20             */
    unsigned long  DR22;                                   /* DR22             */
    unsigned char  dummy247[208];                          /* Reserved         */
    unsigned long  DIR0;                                   /* DIR0             */
    unsigned long  DIR1;                                   /* DIR1             */
    unsigned long  DIR2;                                   /* DIR2             */
    unsigned long  DIR3;                                   /* DIR3             */
    unsigned long  DIR4;                                   /* DIR4             */
    unsigned long  DIR5;                                   /* DIR5             */
    unsigned long  DIR6;                                   /* DIR6             */
    unsigned long  DIR7;                                   /* DIR7             */
    unsigned long  DIR8;                                   /* DIR8             */
    unsigned long  DIR9;                                   /* DIR9             */
    unsigned long  DIR10;                                  /* DIR10            */
    unsigned long  DIR11;                                  /* DIR11            */
    unsigned long  DIR12;                                  /* DIR12            */
    unsigned long  DIR13;                                  /* DIR13            */
    unsigned long  DIR14;                                  /* DIR14            */
    unsigned long  DIR15;                                  /* DIR15            */
    unsigned long  DIR16;                                  /* DIR16            */
    unsigned long  DIR17;                                  /* DIR17            */
    unsigned long  DIR18;                                  /* DIR18            */
    unsigned long  DIR19;                                  /* DIR19            */
    unsigned long  DIR20;                                  /* DIR20            */
    unsigned long  DIR21;                                  /* DIR21            */
    unsigned long  DIR22;                                  /* DIR22            */
    unsigned long  DIR23;                                  /* DIR23            */
    unsigned char  dummy248[160];                          /* Reserved         */
    unsigned char  ADSYNSTCR;                              /* ADSYNSTCR        */
    unsigned char  dummy249[3];                            /* Reserved         */
    unsigned char  ADTSYNSTCR;                             /* ADTSYNSTCR       */
    unsigned char  dummy250[123];                          /* Reserved         */
    unsigned char  ADHALTR;                                /* ADHALTR          */
    unsigned char  dummy251[3];                            /* Reserved         */
    unsigned char  ADCR1;                                  /* ADCR1            */
    unsigned char  dummy252[3];                            /* Reserved         */
    unsigned char  MPXCURCR;                               /* MPXCURCR         */
    unsigned char  dummy253[3];                            /* Reserved         */
    unsigned long  MPXCURR;                                /* MPXCURR          */
    unsigned char  MPXOWR;                                 /* MPXOWR           */
    unsigned char  dummy254[7];                            /* Reserved         */
    unsigned char  ADCR2;                                  /* ADCR2            */
    unsigned char  dummy255[7];                            /* Reserved         */
    unsigned char  ADENDP0;                                /* ADENDP0          */
    unsigned char  dummy256[31];                           /* Reserved         */
    unsigned char  SFTCR;                                  /* SFTCR            */
    unsigned char  dummy257[3];                            /* Reserved         */
    unsigned char  TDCR;                                   /* TDCR             */
    unsigned char  dummy258[7];                            /* Reserved         */
    union __tag56 ULLMTBR0;                                /* ULLMTBR0         */
    union __tag56 ULLMTBR1;                                /* ULLMTBR1         */
    union __tag56 ULLMTBR2;                                /* ULLMTBR2         */
    unsigned char  ECR;                                    /* ECR              */
    unsigned char  dummy259[3];                            /* Reserved         */
    unsigned char  ULER;                                   /* ULER             */
    unsigned char  dummy260[3];                            /* Reserved         */
    unsigned char  OWER;                                   /* OWER             */
    unsigned char  dummy261[3];                            /* Reserved         */
    unsigned char  PER;                                    /* PER              */
    unsigned char  dummy262[3];                            /* Reserved         */
    unsigned char  IDER;                                   /* IDER             */
    unsigned char  dummy263[151];                          /* Reserved         */
    unsigned char  SGSTCR0;                                /* SGSTCR0          */
    unsigned char  dummy264[15];                           /* Reserved         */
    unsigned char  SGCR0;                                  /* SGCR0            */
    unsigned char  dummy265[3];                            /* Reserved         */
    unsigned char  SGVCSP0;                                /* SGVCSP0          */
    unsigned char  dummy266[3];                            /* Reserved         */
    unsigned char  SGVCEP0;                                /* SGVCEP0          */
    unsigned char  dummy267[3];                            /* Reserved         */
    unsigned char  SGMCYCR0;                               /* SGMCYCR0         */
    unsigned char  dummy268[7];                            /* Reserved         */
    unsigned char  SGSR0;                                  /* SGSR0            */
    unsigned char  dummy269[11];                           /* Reserved         */
    unsigned char  ULLMSR0;                                /* ULLMSR0          */
    unsigned char  dummy270[79];                           /* Reserved         */
    unsigned char  SGSTCR1;                                /* SGSTCR1          */
    unsigned char  dummy271[15];                           /* Reserved         */
    unsigned char  SGCR1;                                  /* SGCR1            */
    unsigned char  dummy272[3];                            /* Reserved         */
    unsigned char  SGVCSP1;                                /* SGVCSP1          */
    unsigned char  dummy273[3];                            /* Reserved         */
    unsigned char  SGVCEP1;                                /* SGVCEP1          */
    unsigned char  dummy274[3];                            /* Reserved         */
    unsigned char  SGMCYCR1;                               /* SGMCYCR1         */
    unsigned char  dummy275[7];                            /* Reserved         */
    unsigned char  SGSR1;                                  /* SGSR1            */
    unsigned char  dummy276[11];                           /* Reserved         */
    unsigned char  ULLMSR1;                                /* ULLMSR1          */
    unsigned char  dummy277[79];                           /* Reserved         */
    unsigned char  SGSTCR2;                                /* SGSTCR2          */
    unsigned char  dummy278[15];                           /* Reserved         */
    unsigned char  SGCR2;                                  /* SGCR2            */
    unsigned char  dummy279[3];                            /* Reserved         */
    unsigned char  SGVCSP2;                                /* SGVCSP2          */
    unsigned char  dummy280[3];                            /* Reserved         */
    unsigned char  SGVCEP2;                                /* SGVCEP2          */
    unsigned char  dummy281[3];                            /* Reserved         */
    unsigned char  SGMCYCR2;                               /* SGMCYCR2         */
    unsigned char  dummy282[7];                            /* Reserved         */
    unsigned char  SGSR2;                                  /* SGSR2            */
    unsigned char  dummy283[11];                           /* Reserved         */
    unsigned char  ULLMSR2;                                /* ULLMSR2          */
    unsigned char  dummy284[79];                           /* Reserved         */
    unsigned char  SGSTCR3;                                /* SGSTCR3          */
    unsigned char  dummy285[7];                            /* Reserved         */
    unsigned char  ADTSTCR3;                               /* ADTSTCR3         */
    unsigned char  dummy286[3];                            /* Reserved         */
    unsigned char  ADTENDCR3;                              /* ADTENDCR3        */
    unsigned char  dummy287[3];                            /* Reserved         */
    unsigned char  SGCR3;                                  /* SGCR3            */
    unsigned char  dummy288[3];                            /* Reserved         */
    unsigned char  SGVCSP3;                                /* SGVCSP3          */
    unsigned char  dummy289[3];                            /* Reserved         */
    unsigned char  SGVCEP3;                                /* SGVCEP3          */
    unsigned char  dummy290[3];                            /* Reserved         */
    unsigned char  SGMCYCR3;                               /* SGMCYCR3         */
    unsigned char  dummy291[7];                            /* Reserved         */
    unsigned char  SGSR3;                                  /* SGSR3            */
    unsigned char  dummy292[3];                            /* Reserved         */
    unsigned long  ADTIPR3;                                /* ADTIPR3          */
    unsigned long  ADTPRR3;                                /* ADTPRR3          */
    unsigned char  ULLMSR3;                                /* ULLMSR3          */
    unsigned char  dummy293[79];                           /* Reserved         */
    unsigned char  SGSTCR4;                                /* SGSTCR4          */
    unsigned char  dummy294[7];                            /* Reserved         */
    unsigned char  ADTSTCR4;                               /* ADTSTCR4         */
    unsigned char  dummy295[3];                            /* Reserved         */
    unsigned char  ADTENDCR4;                              /* ADTENDCR4        */
    unsigned char  dummy296[3];                            /* Reserved         */
    unsigned char  SGCR4;                                  /* SGCR4            */
    unsigned char  dummy297[3];                            /* Reserved         */
    unsigned char  SGVCSP4;                                /* SGVCSP4          */
    unsigned char  dummy298[3];                            /* Reserved         */
    unsigned char  SGVCEP4;                                /* SGVCEP4          */
    unsigned char  dummy299[3];                            /* Reserved         */
    unsigned char  SGMCYCR4;                               /* SGMCYCR4         */
    unsigned char  dummy300[7];                            /* Reserved         */
    unsigned char  SGSR4;                                  /* SGSR4            */
    unsigned char  dummy301[3];                            /* Reserved         */
    unsigned long  ADTIPR4;                                /* ADTIPR4          */
    unsigned long  ADTPRR4;                                /* ADTPRR4          */
    unsigned char  ULLMSR4;                                /* ULLMSR4          */
};
struct __tag104
{                                                          /* Module           */
    unsigned long  VCR0;                                   /* VCR0             */
    unsigned long  VCR1;                                   /* VCR1             */
    unsigned long  VCR2;                                   /* VCR2             */
    unsigned long  VCR3;                                   /* VCR3             */
    unsigned long  VCR4;                                   /* VCR4             */
    unsigned long  VCR5;                                   /* VCR5             */
    unsigned long  VCR6;                                   /* VCR6             */
    unsigned long  VCR7;                                   /* VCR7             */
    unsigned long  VCR8;                                   /* VCR8             */
    unsigned long  VCR9;                                   /* VCR9             */
    unsigned long  VCR10;                                  /* VCR10            */
    unsigned long  VCR11;                                  /* VCR11            */
    unsigned long  VCR12;                                  /* VCR12            */
    unsigned long  VCR13;                                  /* VCR13            */
    unsigned long  VCR14;                                  /* VCR14            */
    unsigned long  VCR15;                                  /* VCR15            */
    unsigned long  VCR16;                                  /* VCR16            */
    unsigned long  VCR17;                                  /* VCR17            */
    unsigned long  VCR18;                                  /* VCR18            */
    unsigned long  VCR19;                                  /* VCR19            */
    unsigned char  dummy302[176];                          /* Reserved         */
    unsigned long  DR00;                                   /* DR00             */
    unsigned long  DR02;                                   /* DR02             */
    unsigned long  DR04;                                   /* DR04             */
    unsigned long  DR06;                                   /* DR06             */
    unsigned long  DR08;                                   /* DR08             */
    unsigned long  DR10;                                   /* DR10             */
    unsigned long  DR12;                                   /* DR12             */
    unsigned long  DR14;                                   /* DR14             */
    unsigned long  DR16;                                   /* DR16             */
    unsigned long  DR18;                                   /* DR18             */
    unsigned char  dummy303[216];                          /* Reserved         */
    unsigned long  DIR0;                                   /* DIR0             */
    unsigned long  DIR1;                                   /* DIR1             */
    unsigned long  DIR2;                                   /* DIR2             */
    unsigned long  DIR3;                                   /* DIR3             */
    unsigned long  DIR4;                                   /* DIR4             */
    unsigned long  DIR5;                                   /* DIR5             */
    unsigned long  DIR6;                                   /* DIR6             */
    unsigned long  DIR7;                                   /* DIR7             */
    unsigned long  DIR8;                                   /* DIR8             */
    unsigned long  DIR9;                                   /* DIR9             */
    unsigned long  DIR10;                                  /* DIR10            */
    unsigned long  DIR11;                                  /* DIR11            */
    unsigned long  DIR12;                                  /* DIR12            */
    unsigned long  DIR13;                                  /* DIR13            */
    unsigned long  DIR14;                                  /* DIR14            */
    unsigned long  DIR15;                                  /* DIR15            */
    unsigned long  DIR16;                                  /* DIR16            */
    unsigned long  DIR17;                                  /* DIR17            */
    unsigned long  DIR18;                                  /* DIR18            */
    unsigned long  DIR19;                                  /* DIR19            */
    unsigned char  dummy304[304];                          /* Reserved         */
    unsigned char  ADHALTR;                                /* ADHALTR          */
    unsigned char  dummy305[3];                            /* Reserved         */
    unsigned char  ADCR1;                                  /* ADCR1            */
    unsigned char  dummy306[3];                            /* Reserved         */
    unsigned char  MPXCURCR;                               /* MPXCURCR         */
    unsigned char  dummy307[3];                            /* Reserved         */
    unsigned long  MPXCURR;                                /* MPXCURR          */
    unsigned char  MPXOWR;                                 /* MPXOWR           */
    unsigned char  dummy308[7];                            /* Reserved         */
    unsigned char  ADCR2;                                  /* ADCR2            */
    unsigned char  dummy309[7];                            /* Reserved         */
    unsigned char  ADENDP0;                                /* ADENDP0          */
    unsigned char  dummy310[31];                           /* Reserved         */
    unsigned char  SFTCR;                                  /* SFTCR            */
    unsigned char  dummy311[3];                            /* Reserved         */
    unsigned char  TDCR;                                   /* TDCR             */
    unsigned char  dummy312[7];                            /* Reserved         */
    union __tag56 ULLMTBR0;                                /* ULLMTBR0         */
    union __tag56 ULLMTBR1;                                /* ULLMTBR1         */
    union __tag56 ULLMTBR2;                                /* ULLMTBR2         */
    unsigned char  ECR;                                    /* ECR              */
    unsigned char  dummy313[3];                            /* Reserved         */
    unsigned char  ULER;                                   /* ULER             */
    unsigned char  dummy314[3];                            /* Reserved         */
    unsigned char  OWER;                                   /* OWER             */
    unsigned char  dummy315[3];                            /* Reserved         */
    unsigned char  PER;                                    /* PER              */
    unsigned char  dummy316[3];                            /* Reserved         */
    unsigned char  IDER;                                   /* IDER             */
    unsigned char  dummy317[151];                          /* Reserved         */
    unsigned char  SGSTCR0;                                /* SGSTCR0          */
    unsigned char  dummy318[15];                           /* Reserved         */
    unsigned char  SGCR0;                                  /* SGCR0            */
    unsigned char  dummy319[3];                            /* Reserved         */
    unsigned char  SGVCSP0;                                /* SGVCSP0          */
    unsigned char  dummy320[3];                            /* Reserved         */
    unsigned char  SGVCEP0;                                /* SGVCEP0          */
    unsigned char  dummy321[3];                            /* Reserved         */
    unsigned char  SGMCYCR0;                               /* SGMCYCR0         */
    unsigned char  dummy322[7];                            /* Reserved         */
    unsigned char  SGSR0;                                  /* SGSR0            */
    unsigned char  dummy323[11];                           /* Reserved         */
    unsigned char  ULLMSR0;                                /* ULLMSR0          */
    unsigned char  dummy324[79];                           /* Reserved         */
    unsigned char  SGSTCR1;                                /* SGSTCR1          */
    unsigned char  dummy325[15];                           /* Reserved         */
    unsigned char  SGCR1;                                  /* SGCR1            */
    unsigned char  dummy326[3];                            /* Reserved         */
    unsigned char  SGVCSP1;                                /* SGVCSP1          */
    unsigned char  dummy327[3];                            /* Reserved         */
    unsigned char  SGVCEP1;                                /* SGVCEP1          */
    unsigned char  dummy328[3];                            /* Reserved         */
    unsigned char  SGMCYCR1;                               /* SGMCYCR1         */
    unsigned char  dummy329[7];                            /* Reserved         */
    unsigned char  SGSR1;                                  /* SGSR1            */
    unsigned char  dummy330[11];                           /* Reserved         */
    unsigned char  ULLMSR1;                                /* ULLMSR1          */
    unsigned char  dummy331[79];                           /* Reserved         */
    unsigned char  SGSTCR2;                                /* SGSTCR2          */
    unsigned char  dummy332[15];                           /* Reserved         */
    unsigned char  SGCR2;                                  /* SGCR2            */
    unsigned char  dummy333[3];                            /* Reserved         */
    unsigned char  SGVCSP2;                                /* SGVCSP2          */
    unsigned char  dummy334[3];                            /* Reserved         */
    unsigned char  SGVCEP2;                                /* SGVCEP2          */
    unsigned char  dummy335[3];                            /* Reserved         */
    unsigned char  SGMCYCR2;                               /* SGMCYCR2         */
    unsigned char  dummy336[7];                            /* Reserved         */
    unsigned char  SGSR2;                                  /* SGSR2            */
    unsigned char  dummy337[11];                           /* Reserved         */
    unsigned char  ULLMSR2;                                /* ULLMSR2          */
    unsigned char  dummy338[79];                           /* Reserved         */
    unsigned char  SGSTCR3;                                /* SGSTCR3          */
    unsigned char  dummy339[7];                            /* Reserved         */
    unsigned char  ADTSTCR3;                               /* ADTSTCR3         */
    unsigned char  dummy340[3];                            /* Reserved         */
    unsigned char  ADTENDCR3;                              /* ADTENDCR3        */
    unsigned char  dummy341[3];                            /* Reserved         */
    unsigned char  SGCR3;                                  /* SGCR3            */
    unsigned char  dummy342[3];                            /* Reserved         */
    unsigned char  SGVCSP3;                                /* SGVCSP3          */
    unsigned char  dummy343[3];                            /* Reserved         */
    unsigned char  SGVCEP3;                                /* SGVCEP3          */
    unsigned char  dummy344[3];                            /* Reserved         */
    unsigned char  SGMCYCR3;                               /* SGMCYCR3         */
    unsigned char  dummy345[7];                            /* Reserved         */
    unsigned char  SGSR3;                                  /* SGSR3            */
    unsigned char  dummy346[3];                            /* Reserved         */
    unsigned long  ADTIPR3;                                /* ADTIPR3          */
    unsigned long  ADTPRR3;                                /* ADTPRR3          */
    unsigned char  ULLMSR3;                                /* ULLMSR3          */
    unsigned char  dummy347[79];                           /* Reserved         */
    unsigned char  SGSTCR4;                                /* SGSTCR4          */
    unsigned char  dummy348[7];                            /* Reserved         */
    unsigned char  ADTSTCR4;                               /* ADTSTCR4         */
    unsigned char  dummy349[3];                            /* Reserved         */
    unsigned char  ADTENDCR4;                              /* ADTENDCR4        */
    unsigned char  dummy350[3];                            /* Reserved         */
    unsigned char  SGCR4;                                  /* SGCR4            */
    unsigned char  dummy351[3];                            /* Reserved         */
    unsigned char  SGVCSP4;                                /* SGVCSP4          */
    unsigned char  dummy352[3];                            /* Reserved         */
    unsigned char  SGVCEP4;                                /* SGVCEP4          */
    unsigned char  dummy353[3];                            /* Reserved         */
    unsigned char  SGMCYCR4;                               /* SGMCYCR4         */
    unsigned char  dummy354[7];                            /* Reserved         */
    unsigned char  SGSR4;                                  /* SGSR4            */
    unsigned char  dummy355[3];                            /* Reserved         */
    unsigned long  ADTIPR4;                                /* ADTIPR4          */
    unsigned long  ADTPRR4;                                /* ADTPRR4          */
    unsigned char  ULLMSR4;                                /* ULLMSR4          */
};
struct __tag105
{                                                          /* Module           */
    unsigned char  OTSTCR;                                 /* OTSTCR           */
    unsigned char  dummy356[3];                            /* Reserved         */
    unsigned char  OTENDCR;                                /* OTENDCR          */
    unsigned char  dummy357[3];                            /* Reserved         */
    unsigned char  OTCR;                                   /* OTCR             */
    unsigned char  dummy358[3];                            /* Reserved         */
    unsigned char  OTFCR;                                  /* OTFCR            */
    unsigned char  dummy359[3];                            /* Reserved         */
    unsigned char  OTFR;                                   /* OTFR             */
    unsigned char  dummy360[3];                            /* Reserved         */
    unsigned char  OTSTR;                                  /* OTSTR            */
    unsigned char  dummy361[3];                            /* Reserved         */
    unsigned short OTDR;                                   /* OTDR             */
    unsigned char  dummy362[2];                            /* Reserved         */
    unsigned short HTBRAU;                                 /* HTBRAU           */
    unsigned char  dummy363[2];                            /* Reserved         */
    unsigned short HTBRAL;                                 /* HTBRAL           */
    unsigned char  dummy364[2];                            /* Reserved         */
    unsigned short HTBRBU;                                 /* HTBRBU           */
    unsigned char  dummy365[2];                            /* Reserved         */
    unsigned short HTBRBL;                                 /* HTBRBL           */
    unsigned char  dummy366[2];                            /* Reserved         */
    unsigned short LTBRAU;                                 /* LTBRAU           */
    unsigned char  dummy367[2];                            /* Reserved         */
    unsigned short LTBRAL;                                 /* LTBRAL           */
    unsigned char  dummy368[2];                            /* Reserved         */
    unsigned short TDLR;                                   /* TDLR             */
    unsigned char  dummy369[2];                            /* Reserved         */
    unsigned short COEFFRA;                                /* COEFFRA          */
    unsigned char  dummy370[2];                            /* Reserved         */
    unsigned short COEFFRB;                                /* COEFFRB          */
    unsigned char  dummy371[2];                            /* Reserved         */
    unsigned short COEFFRC;                                /* COEFFRC          */
};
struct __tag106
{                                                          /* Module           */
    union __tag28 PROT00;                                  /* PROT00           */
    union __tag28 SPID00;                                  /* SPID00           */
    union __tag28 PROT01;                                  /* PROT01           */
    union __tag28 SPID01;                                  /* SPID01           */
    union __tag28 PROT02;                                  /* PROT02           */
    union __tag28 SPID02;                                  /* SPID02           */
    union __tag28 PROT03;                                  /* PROT03           */
    union __tag28 SPID03;                                  /* SPID03           */
    unsigned char  dummy372[16];                           /* Reserved         */
    union __tag28 PROT06;                                  /* PROT06           */
    union __tag28 SPID06;                                  /* SPID06           */
    union __tag28 PROT07;                                  /* PROT07           */
    union __tag28 SPID07;                                  /* SPID07           */
    unsigned char  dummy373[16];                           /* Reserved         */
    union __tag28 PROT10;                                  /* PROT10           */
    union __tag28 SPID10;                                  /* SPID10           */
    union __tag28 PROT11;                                  /* PROT11           */
    union __tag28 SPID11;                                  /* SPID11           */
    union __tag28 PROT12;                                  /* PROT12           */
    union __tag28 SPID12;                                  /* SPID12           */
    union __tag28 PROT13;                                  /* PROT13           */
    union __tag28 SPID13;                                  /* SPID13           */
};
struct __tag107
{                                                          /* Module           */
    unsigned char  PRSCTL;                                 /* PRSCTL           */
    unsigned char  dummy374[3];                            /* Reserved         */
    unsigned char  PRSCMP;                                 /* PRSCMP           */
    unsigned char  dummy375[251];                          /* Reserved         */
    unsigned char  BPRSCTL;                                /* BPRSCTL          */
    unsigned char  dummy376[3];                            /* Reserved         */
    unsigned char  BPRSCMP;                                /* BPRSCMP          */
    unsigned char  dummy377[251];                          /* Reserved         */
    unsigned char  CPRSCTL;                                /* CPRSCTL          */
    unsigned char  dummy378[3];                            /* Reserved         */
    unsigned char  CPRSCMP;                                /* CPRSCMP          */
    unsigned char  dummy379[1523];                         /* Reserved         */
    unsigned char  CCTL0;                                  /* CCTL0            */
    unsigned char  dummy380[7];                            /* Reserved         */
    unsigned short CCMPL;                                  /* CCMPL            */
    unsigned char  dummy381[2];                            /* Reserved         */
    unsigned short CCMPH;                                  /* CCMPH            */
    unsigned char  dummy382[2];                            /* Reserved         */
    unsigned char  CPCMD;                                  /* CPCMD            */
    unsigned char  dummy383[3];                            /* Reserved         */
    unsigned char  CPS;                                    /* CPS              */
    unsigned char  dummy384[1003];                         /* Reserved         */
    unsigned long  RST;                                    /* RST              */
    unsigned long  CFG;                                    /* CFG              */
    unsigned long  CLMEN;                                  /* CLMEN            */
    unsigned long  MON;                                    /* MON              */
};
struct __tag108
{                                                          /* Module           */
    unsigned long  RG0;                                    /* RG0              */
    unsigned long  RG1;                                    /* RG1              */
    unsigned long  RG2;                                    /* RG2              */
    unsigned long  RG3;                                    /* RG3              */
    unsigned long  RG4;                                    /* RG4              */
    unsigned long  RG5;                                    /* RG5              */
    unsigned long  RG6;                                    /* RG6              */
    unsigned long  RG7;                                    /* RG7              */
};
struct __tag109
{                                                          /* Module           */
    union __tag28 CTL;                                     /* CTL              */
    union __tag28 STAT;                                    /* STAT             */
};
struct __tag110
{                                                          /* Module           */
    unsigned char  dummy385[2];                            /* Reserved         */
    unsigned short ECRUM;                                  /* ECRUM            */
    unsigned char  dummy386[4];                            /* Reserved         */
    unsigned long  ADRUM;                                  /* ADRUM            */
    unsigned char  dummy387[1];                            /* Reserved         */
    union __tag57 ENUM;                                    /* ENUM             */
    unsigned char  dummy388[18];                           /* Reserved         */
    union __tag58 PMTUM0;                                  /* PMTUM0           */
    union __tag59 PMTUM1;                                  /* PMTUM1           */
    union __tag60 PMTUM2;                                  /* PMTUM2           */
    union __tag61 PMTUM3;                                  /* PMTUM3           */
    union __tag62 PMTUM4;                                  /* PMTUM4           */
};
struct __tag111
{                                                          /* Module           */
    union __tag28 G0MK;                                    /* G0MK             */
    union __tag28 G0BA;                                    /* G0BA             */
    union __tag28 G0SP;                                    /* G0SP             */
    unsigned char  dummy389[4];                            /* Reserved         */
    union __tag28 G1MK;                                    /* G1MK             */
    union __tag28 G1BA;                                    /* G1BA             */
    union __tag28 G1SP;                                    /* G1SP             */
    unsigned char  dummy390[4];                            /* Reserved         */
    union __tag28 G2MK;                                    /* G2MK             */
    union __tag28 G2BA;                                    /* G2BA             */
    union __tag28 G2SP;                                    /* G2SP             */
    unsigned char  dummy391[4];                            /* Reserved         */
    union __tag28 G3MK;                                    /* G3MK             */
    union __tag28 G3BA;                                    /* G3BA             */
    union __tag28 G3SP;                                    /* G3SP             */
    unsigned char  dummy392[4];                            /* Reserved         */
    union __tag28 G4MK;                                    /* G4MK             */
    union __tag28 G4BA;                                    /* G4BA             */
    union __tag28 G4SP;                                    /* G4SP             */
    unsigned char  dummy393[4];                            /* Reserved         */
    union __tag28 G5MK;                                    /* G5MK             */
    union __tag28 G5BA;                                    /* G5BA             */
    union __tag28 G5SP;                                    /* G5SP             */
    unsigned char  dummy394[4];                            /* Reserved         */
    union __tag28 G6MK;                                    /* G6MK             */
    union __tag28 G6BA;                                    /* G6BA             */
    union __tag28 G6SP;                                    /* G6SP             */
    unsigned char  dummy395[4];                            /* Reserved         */
    union __tag28 G7MK;                                    /* G7MK             */
    union __tag28 G7BA;                                    /* G7BA             */
    union __tag28 G7SP;                                    /* G7SP             */
};
struct __tag112
{                                                          /* Module           */
    unsigned short CONT;                                   /* CONT             */
    unsigned short FLAG;                                   /* FLAG             */
    unsigned short TYPE;                                   /* TYPE             */
    unsigned short SIDE;                                   /* SIDE             */
    union __tag56 ADDR;                                    /* ADDR             */
};

#define FBTP DBTP
#define FBTPL DBTPL
#define FBTPLL DBTPLL
#define FBTPLH DBTPLH
#define FBTPH DBTPH
#define FBTPHL DBTPHL
#define FBTPHH DBTPHH
#define NBTP BTP
#define NBTPL BTPL
#define NBTPLL BTPLL
#define NBTPLH BTPLH
#define NBTPH BTPH
#define NBTPHL BTPHL
#define NBTPHH BTPHH

#define ICUID                  (*(volatile unsigned long  *)0xFF1F0000)
#define ICUVER                 (*(volatile unsigned long  *)0xFF1F0004)
#define ICU2PES                (*(volatile unsigned long  *)0xFF1F0010)
#define ICU2PESL               (*(volatile unsigned short *)0xFF1F0010)
#define ICU2PESLL              (*(volatile unsigned char  *)0xFF1F0010)
#define ICU2PESLH              (*(volatile unsigned char  *)0xFF1F0011)
#define ICU2PESH               (*(volatile unsigned short *)0xFF1F0012)
#define ICU2PESHL              (*(volatile unsigned char  *)0xFF1F0012)
#define ICU2PESHH              (*(volatile unsigned char  *)0xFF1F0013)
#define PE2ICUS                (*(volatile unsigned long  *)0xFF1F0014)
#define PE2ICUSL               (*(volatile unsigned short *)0xFF1F0014)
#define PE2ICUSLL              (*(volatile unsigned char  *)0xFF1F0014)
#define PE2ICUSLH              (*(volatile unsigned char  *)0xFF1F0015)
#define PE2ICUSH               (*(volatile unsigned short *)0xFF1F0016)
#define PE2ICUSHL              (*(volatile unsigned char  *)0xFF1F0016)
#define PE2ICUSHH              (*(volatile unsigned char  *)0xFF1F0017)
#define ICUMACTFLAG            (*(volatile unsigned long  *)0xFF1F0018)
#define ICUMACTFLAGL           (*(volatile unsigned short *)0xFF1F0018)
#define ICUMACTFLAGLL          (*(volatile unsigned char  *)0xFF1F0018)
#define PEFLPRG0REQ            (*(volatile unsigned long  *)0xFF1F0020)
#define PEFLPRG0REQL           (*(volatile unsigned short *)0xFF1F0020)
#define PEFLPRG0REQLL          (*(volatile unsigned char  *)0xFF1F0020)
#define PEFLPRG1REQ            (*(volatile unsigned long  *)0xFF1F0024)
#define PEFLPRG1REQL           (*(volatile unsigned short *)0xFF1F0024)
#define PEFLPRG1REQLL          (*(volatile unsigned char  *)0xFF1F0024)
#define PEFLPRG0AC             (*(volatile unsigned long  *)0xFF1F0028)
#define PEFLPRG0ACL            (*(volatile unsigned short *)0xFF1F0028)
#define PEFLPRG0ACLL           (*(volatile unsigned char  *)0xFF1F0028)
#define PEFLPRG1AC             (*(volatile unsigned long  *)0xFF1F002C)
#define PEFLPRG1ACL            (*(volatile unsigned short *)0xFF1F002C)
#define PEFLPRG1ACLL           (*(volatile unsigned char  *)0xFF1F002C)
#define PE2ICUF                (*(volatile unsigned long  *)0xFF1F0040)
#define PE2ICUFL               (*(volatile unsigned short *)0xFF1F0040)
#define PE2ICUFLL              (*(volatile unsigned char  *)0xFF1F0040)
#define PE2ICUFLH              (*(volatile unsigned char  *)0xFF1F0041)
#define PE2ICUFH               (*(volatile unsigned short *)0xFF1F0042)
#define PE2ICUFHL              (*(volatile unsigned char  *)0xFF1F0042)
#define PE2ICUFHH              (*(volatile unsigned char  *)0xFF1F0043)
#define PE2ICUFS               (*(volatile unsigned long  *)0xFF1F0044)
#define PE2ICUFSL              (*(volatile unsigned short *)0xFF1F0044)
#define PE2ICUFSLL             (*(volatile unsigned char  *)0xFF1F0044)
#define PE2ICUFSLH             (*(volatile unsigned char  *)0xFF1F0045)
#define PE2ICUFSH              (*(volatile unsigned short *)0xFF1F0046)
#define PE2ICUFSHL             (*(volatile unsigned char  *)0xFF1F0046)
#define PE2ICUFSHH             (*(volatile unsigned char  *)0xFF1F0047)
#define PE2ICUFC               (*(volatile unsigned long  *)0xFF1F0048)
#define PE2ICUFCL              (*(volatile unsigned short *)0xFF1F0048)
#define PE2ICUFCLL             (*(volatile unsigned char  *)0xFF1F0048)
#define PE2ICUFCLH             (*(volatile unsigned char  *)0xFF1F0049)
#define PE2ICUFCH              (*(volatile unsigned short *)0xFF1F004A)
#define PE2ICUFCHL             (*(volatile unsigned char  *)0xFF1F004A)
#define PE2ICUFCHH             (*(volatile unsigned char  *)0xFF1F004B)
#define PE2ICUIE               (*(volatile unsigned long  *)0xFF1F004C)
#define PE2ICUIEL              (*(volatile unsigned short *)0xFF1F004C)
#define PE2ICUIELL             (*(volatile unsigned char  *)0xFF1F004C)
#define PE2ICUIELH             (*(volatile unsigned char  *)0xFF1F004D)
#define PE2ICUIEH              (*(volatile unsigned short *)0xFF1F004E)
#define PE2ICUIEHL             (*(volatile unsigned char  *)0xFF1F004E)
#define PE2ICUIEHH             (*(volatile unsigned char  *)0xFF1F004F)
#define ICU2PEF                (*(volatile unsigned long  *)0xFF1F0050)
#define ICU2PEFL               (*(volatile unsigned short *)0xFF1F0050)
#define ICU2PEFLL              (*(volatile unsigned char  *)0xFF1F0050)
#define ICU2PEFLH              (*(volatile unsigned char  *)0xFF1F0051)
#define ICU2PEFH               (*(volatile unsigned short *)0xFF1F0052)
#define ICU2PEFHL              (*(volatile unsigned char  *)0xFF1F0052)
#define ICU2PEFHH              (*(volatile unsigned char  *)0xFF1F0053)
#define ICU2PEFS               (*(volatile unsigned long  *)0xFF1F0054)
#define ICU2PEFSL              (*(volatile unsigned short *)0xFF1F0054)
#define ICU2PEFSLL             (*(volatile unsigned char  *)0xFF1F0054)
#define ICU2PEFSLH             (*(volatile unsigned char  *)0xFF1F0055)
#define ICU2PEFSH              (*(volatile unsigned short *)0xFF1F0056)
#define ICU2PEFSHL             (*(volatile unsigned char  *)0xFF1F0056)
#define ICU2PEFSHH             (*(volatile unsigned char  *)0xFF1F0057)
#define ICU2PEFC               (*(volatile unsigned long  *)0xFF1F0058)
#define ICU2PEFCL              (*(volatile unsigned short *)0xFF1F0058)
#define ICU2PEFCLL             (*(volatile unsigned char  *)0xFF1F0058)
#define ICU2PEFCLH             (*(volatile unsigned char  *)0xFF1F0059)
#define ICU2PEFCH              (*(volatile unsigned short *)0xFF1F005A)
#define ICU2PEFCHL             (*(volatile unsigned char  *)0xFF1F005A)
#define ICU2PEFCHH             (*(volatile unsigned char  *)0xFF1F005B)
#define ICU2PEIE               (*(volatile unsigned long  *)0xFF1F005C)
#define ICU2PEIEL              (*(volatile unsigned short *)0xFF1F005C)
#define ICU2PEIELL             (*(volatile unsigned char  *)0xFF1F005C)
#define ICU2PEIELH             (*(volatile unsigned char  *)0xFF1F005D)
#define ICU2PEIEH              (*(volatile unsigned short *)0xFF1F005E)
#define ICU2PEIEHL             (*(volatile unsigned char  *)0xFF1F005E)
#define ICU2PEIEHH             (*(volatile unsigned char  *)0xFF1F005F)
#define ICU2PEIS               (*(volatile unsigned long  *)0xFF1F0060)
#define ICU2PEISL              (*(volatile unsigned short *)0xFF1F0060)
#define ICU2PEISLL             (*(volatile unsigned char  *)0xFF1F0060)
#define SELFID0                (*(volatile unsigned long  *)0xFFA08000)
#define SELFID1                (*(volatile unsigned long  *)0xFFA08004)
#define SELFID2                (*(volatile unsigned long  *)0xFFA08008)
#define SELFID3                (*(volatile unsigned long  *)0xFFA0800C)
#define SELFID4                (*(volatile unsigned long  *)0xFFA08010)
#define SELFID5                (*(volatile unsigned long  *)0xFFA08014)
#define SELFID6                (*(volatile unsigned long  *)0xFFA08018)
#define SELFID7                (*(volatile unsigned long  *)0xFFA0801C)
#define CFRDID0                (*(volatile unsigned long  *)0xFFA08020)
#define CFRDID1                (*(volatile unsigned long  *)0xFFA08024)
#define CFRDID2                (*(volatile unsigned long  *)0xFFA08028)
#define CFRDID3                (*(volatile unsigned long  *)0xFFA0802C)
#define CFRDID4                (*(volatile unsigned long  *)0xFFA08030)
#define CFRDID5                (*(volatile unsigned long  *)0xFFA08034)
#define CFRDID6                (*(volatile unsigned long  *)0xFFA08038)
#define CFRDID7                (*(volatile unsigned long  *)0xFFA0803C)
#define DFRDID0                (*(volatile unsigned long  *)0xFFA08040)
#define DFRDID1                (*(volatile unsigned long  *)0xFFA08044)
#define DFRDID2                (*(volatile unsigned long  *)0xFFA08048)
#define DFRDID3                (*(volatile unsigned long  *)0xFFA0804C)
#define DFRDID4                (*(volatile unsigned long  *)0xFFA08050)
#define DFRDID5                (*(volatile unsigned long  *)0xFFA08054)
#define DFRDID6                (*(volatile unsigned long  *)0xFFA08058)
#define DFRDID7                (*(volatile unsigned long  *)0xFFA0805C)
#define CFPEID0                (*(volatile unsigned long  *)0xFFA08060)
#define CFPEID1                (*(volatile unsigned long  *)0xFFA08064)
#define CFPEID2                (*(volatile unsigned long  *)0xFFA08068)
#define CFPEID3                (*(volatile unsigned long  *)0xFFA0806C)
#define CFPEID4                (*(volatile unsigned long  *)0xFFA08070)
#define CFPEID5                (*(volatile unsigned long  *)0xFFA08074)
#define CFPEID6                (*(volatile unsigned long  *)0xFFA08078)
#define CFPEID7                (*(volatile unsigned long  *)0xFFA0807C)
#define DFPEID0                (*(volatile unsigned long  *)0xFFA08080)
#define DFPEID1                (*(volatile unsigned long  *)0xFFA08084)
#define DFPEID2                (*(volatile unsigned long  *)0xFFA08088)
#define DFPEID3                (*(volatile unsigned long  *)0xFFA0808C)
#define DFPEID4                (*(volatile unsigned long  *)0xFFA08090)
#define DFPEID5                (*(volatile unsigned long  *)0xFFA08094)
#define DFPEID6                (*(volatile unsigned long  *)0xFFA08098)
#define DFPEID7                (*(volatile unsigned long  *)0xFFA0809C)
#define DEGEMU                 (*(volatile unsigned long  *)0xFFA080A4)
#define SELSECLOCK             (*(volatile unsigned long  *)0xFFA080A8)
#define IDSTATUS               (*(volatile unsigned long  *)0xFFA080AC)
#define P0                     (*(volatile unsigned short *)0xFFC10000)
#define PSR0                   (*(volatile unsigned long  *)0xFFC10004)
#define PNOT0                  (*(volatile unsigned short *)0xFFC10008)
#define PPR0                   (*(volatile unsigned short *)0xFFC1000C)
#define PM0                    (*(volatile unsigned short *)0xFFC10010)
#define PMC0                   (*(volatile unsigned short *)0xFFC10014)
#define PFC0                   (*(volatile unsigned short *)0xFFC10018)
#define PFCE0                  (*(volatile unsigned short *)0xFFC1001C)
#define PMSR0                  (*(volatile unsigned long  *)0xFFC10020)
#define PMCSR0                 (*(volatile unsigned long  *)0xFFC10024)
#define PINV0                  (*(volatile unsigned short *)0xFFC10030)
#define P1                     (*(volatile unsigned short *)0xFFC10040)
#define PSR1                   (*(volatile unsigned long  *)0xFFC10044)
#define PNOT1                  (*(volatile unsigned short *)0xFFC10048)
#define PPR1                   (*(volatile unsigned short *)0xFFC1004C)
#define PM1                    (*(volatile unsigned short *)0xFFC10050)
#define PMC1                   (*(volatile unsigned short *)0xFFC10054)
#define PFC1                   (*(volatile unsigned short *)0xFFC10058)
#define PFCE1                  (*(volatile unsigned short *)0xFFC1005C)
#define PMSR1                  (*(volatile unsigned long  *)0xFFC10060)
#define PMCSR1                 (*(volatile unsigned long  *)0xFFC10064)
#define PINV1                  (*(volatile unsigned short *)0xFFC10070)
#define P2                     (*(volatile unsigned short *)0xFFC10080)
#define PSR2                   (*(volatile unsigned long  *)0xFFC10084)
#define PNOT2                  (*(volatile unsigned short *)0xFFC10088)
#define PPR2                   (*(volatile unsigned short *)0xFFC1008C)
#define PM2                    (*(volatile unsigned short *)0xFFC10090)
#define PMC2                   (*(volatile unsigned short *)0xFFC10094)
#define PFC2                   (*(volatile unsigned short *)0xFFC10098)
#define PFCE2                  (*(volatile unsigned short *)0xFFC1009C)
#define PMSR2                  (*(volatile unsigned long  *)0xFFC100A0)
#define PMCSR2                 (*(volatile unsigned long  *)0xFFC100A4)
#define PINV2                  (*(volatile unsigned short *)0xFFC100B0)
#define P3                     (*(volatile unsigned short *)0xFFC100C0)
#define PSR3                   (*(volatile unsigned long  *)0xFFC100C4)
#define PNOT3                  (*(volatile unsigned short *)0xFFC100C8)
#define PPR3                   (*(volatile unsigned short *)0xFFC100CC)
#define PM3                    (*(volatile unsigned short *)0xFFC100D0)
#define PMC3                   (*(volatile unsigned short *)0xFFC100D4)
#define PFC3                   (*(volatile unsigned short *)0xFFC100D8)
#define PFCE3                  (*(volatile unsigned short *)0xFFC100DC)
#define PMSR3                  (*(volatile unsigned long  *)0xFFC100E0)
#define PMCSR3                 (*(volatile unsigned long  *)0xFFC100E4)
#define PINV3                  (*(volatile unsigned short *)0xFFC100F0)
#define P4                     (*(volatile unsigned short *)0xFFC10100)
#define PSR4                   (*(volatile unsigned long  *)0xFFC10104)
#define PNOT4                  (*(volatile unsigned short *)0xFFC10108)
#define PPR4                   (*(volatile unsigned short *)0xFFC1010C)
#define PM4                    (*(volatile unsigned short *)0xFFC10110)
#define PMC4                   (*(volatile unsigned short *)0xFFC10114)
#define PFC4                   (*(volatile unsigned short *)0xFFC10118)
#define PFCE4                  (*(volatile unsigned short *)0xFFC1011C)
#define PMSR4                  (*(volatile unsigned long  *)0xFFC10120)
#define PMCSR4                 (*(volatile unsigned long  *)0xFFC10124)
#define PINV4                  (*(volatile unsigned short *)0xFFC10130)
#define P5                     (*(volatile unsigned short *)0xFFC10140)
#define PSR5                   (*(volatile unsigned long  *)0xFFC10144)
#define PNOT5                  (*(volatile unsigned short *)0xFFC10148)
#define PPR5                   (*(volatile unsigned short *)0xFFC1014C)
#define PM5                    (*(volatile unsigned short *)0xFFC10150)
#define PMC5                   (*(volatile unsigned short *)0xFFC10154)
#define PFC5                   (*(volatile unsigned short *)0xFFC10158)
#define PFCE5                  (*(volatile unsigned short *)0xFFC1015C)
#define PMSR5                  (*(volatile unsigned long  *)0xFFC10160)
#define PMCSR5                 (*(volatile unsigned long  *)0xFFC10164)
#define PINV5                  (*(volatile unsigned short *)0xFFC10170)
#define P6                     (*(volatile unsigned short *)0xFFC10180)
#define PSR6                   (*(volatile unsigned long  *)0xFFC10184)
#define PNOT6                  (*(volatile unsigned short *)0xFFC10188)
#define PPR6                   (*(volatile unsigned short *)0xFFC1018C)
#define PM6                    (*(volatile unsigned short *)0xFFC10190)
#define PMC6                   (*(volatile unsigned short *)0xFFC10194)
#define PFC6                   (*(volatile unsigned short *)0xFFC10198)
#define PFCE6                  (*(volatile unsigned short *)0xFFC1019C)
#define PMSR6                  (*(volatile unsigned long  *)0xFFC101A0)
#define PMCSR6                 (*(volatile unsigned long  *)0xFFC101A4)
#define PINV6                  (*(volatile unsigned short *)0xFFC101B0)
#define P7                     (*(volatile unsigned short *)0xFFC101C0)
#define PSR7                   (*(volatile unsigned long  *)0xFFC101C4)
#define PNOT7                  (*(volatile unsigned short *)0xFFC101C8)
#define PPR7                   (*(volatile unsigned short *)0xFFC101CC)
#define PM7                    (*(volatile unsigned short *)0xFFC101D0)
#define PMC7                   (*(volatile unsigned short *)0xFFC101D4)
#define PFC7                   (*(volatile unsigned short *)0xFFC101D8)
#define PFCE7                  (*(volatile unsigned short *)0xFFC101DC)
#define PMSR7                  (*(volatile unsigned long  *)0xFFC101E0)
#define PMCSR7                 (*(volatile unsigned long  *)0xFFC101E4)
#define PINV7                  (*(volatile unsigned short *)0xFFC101F0)
#define P8                     (*(volatile unsigned short *)0xFFC10200)
#define PSR8                   (*(volatile unsigned long  *)0xFFC10204)
#define PNOT8                  (*(volatile unsigned short *)0xFFC10208)
#define PPR8                   (*(volatile unsigned short *)0xFFC1020C)
#define PM8                    (*(volatile unsigned short *)0xFFC10210)
#define PMC8                   (*(volatile unsigned short *)0xFFC10214)
#define PFC8                   (*(volatile unsigned short *)0xFFC10218)
#define PFCE8                  (*(volatile unsigned short *)0xFFC1021C)
#define PMSR8                  (*(volatile unsigned long  *)0xFFC10220)
#define PMCSR8                 (*(volatile unsigned long  *)0xFFC10224)
#define PINV8                  (*(volatile unsigned short *)0xFFC10230)
#define P9                     (*(volatile unsigned short *)0xFFC10240)
#define PSR9                   (*(volatile unsigned long  *)0xFFC10244)
#define PNOT9                  (*(volatile unsigned short *)0xFFC10248)
#define PPR9                   (*(volatile unsigned short *)0xFFC1024C)
#define PM9                    (*(volatile unsigned short *)0xFFC10250)
#define PMC9                   (*(volatile unsigned short *)0xFFC10254)
#define PFC9                   (*(volatile unsigned short *)0xFFC10258)
#define PFCE9                  (*(volatile unsigned short *)0xFFC1025C)
#define PMSR9                  (*(volatile unsigned long  *)0xFFC10260)
#define PMCSR9                 (*(volatile unsigned long  *)0xFFC10264)
#define PINV9                  (*(volatile unsigned short *)0xFFC10270)
#define PCR0_0                 (*(volatile unsigned long  *)0xFFC12000)
#define PCR0_1                 (*(volatile unsigned long  *)0xFFC12004)
#define PCR0_2                 (*(volatile unsigned long  *)0xFFC12008)
#define PCR0_3                 (*(volatile unsigned long  *)0xFFC1200C)
#define PCR0_4                 (*(volatile unsigned long  *)0xFFC12010)
#define PCR0_5                 (*(volatile unsigned long  *)0xFFC12014)
#define PCR0_6                 (*(volatile unsigned long  *)0xFFC12018)
#define PCR0_7                 (*(volatile unsigned long  *)0xFFC1201C)
#define PCR0_8                 (*(volatile unsigned long  *)0xFFC12020)
#define PCR0_9                 (*(volatile unsigned long  *)0xFFC12024)
#define PCR0_10                (*(volatile unsigned long  *)0xFFC12028)
#define PCR0_13                (*(volatile unsigned long  *)0xFFC12034)
#define PCR0_14                (*(volatile unsigned long  *)0xFFC12038)
#define PCR1_1                 (*(volatile unsigned long  *)0xFFC12044)
#define PCR1_2                 (*(volatile unsigned long  *)0xFFC12048)
#define PCR1_3                 (*(volatile unsigned long  *)0xFFC1204C)
#define PCR1_4                 (*(volatile unsigned long  *)0xFFC12050)
#define PCR1_5                 (*(volatile unsigned long  *)0xFFC12054)
#define PCR1_6                 (*(volatile unsigned long  *)0xFFC12058)
#define PCR1_7                 (*(volatile unsigned long  *)0xFFC1205C)
#define PCR2_0                 (*(volatile unsigned long  *)0xFFC12080)
#define PCR2_1                 (*(volatile unsigned long  *)0xFFC12084)
#define PCR2_2                 (*(volatile unsigned long  *)0xFFC12088)
#define PCR2_3                 (*(volatile unsigned long  *)0xFFC1208C)
#define PCR2_4                 (*(volatile unsigned long  *)0xFFC12090)
#define PCR2_5                 (*(volatile unsigned long  *)0xFFC12094)
#define PCR2_6                 (*(volatile unsigned long  *)0xFFC12098)
#define PCR2_7                 (*(volatile unsigned long  *)0xFFC1209C)
#define PCR2_8                 (*(volatile unsigned long  *)0xFFC120A0)
#define PCR2_9                 (*(volatile unsigned long  *)0xFFC120A4)
#define PCR2_10                (*(volatile unsigned long  *)0xFFC120A8)
#define PCR2_11                (*(volatile unsigned long  *)0xFFC120AC)
#define PCR2_12                (*(volatile unsigned long  *)0xFFC120B0)
#define PCR2_13                (*(volatile unsigned long  *)0xFFC120B4)
#define PCR2_14                (*(volatile unsigned long  *)0xFFC120B8)
#define PCR2_15                (*(volatile unsigned long  *)0xFFC120BC)
#define PCR3_0                 (*(volatile unsigned long  *)0xFFC120C0)
#define PCR3_1                 (*(volatile unsigned long  *)0xFFC120C4)
#define PCR3_2                 (*(volatile unsigned long  *)0xFFC120C8)
#define PCR3_3                 (*(volatile unsigned long  *)0xFFC120CC)
#define PCR3_4                 (*(volatile unsigned long  *)0xFFC120D0)
#define PCR3_5                 (*(volatile unsigned long  *)0xFFC120D4)
#define PCR3_6                 (*(volatile unsigned long  *)0xFFC120D8)
#define PCR3_7                 (*(volatile unsigned long  *)0xFFC120DC)
#define PCR3_8                 (*(volatile unsigned long  *)0xFFC120E0)
#define PCR3_9                 (*(volatile unsigned long  *)0xFFC120E4)
#define PCR3_10                (*(volatile unsigned long  *)0xFFC120E8)
#define PCR3_11                (*(volatile unsigned long  *)0xFFC120EC)
#define PCR3_12                (*(volatile unsigned long  *)0xFFC120F0)
#define PCR3_13                (*(volatile unsigned long  *)0xFFC120F4)
#define PCR3_14                (*(volatile unsigned long  *)0xFFC120F8)
#define PCR4_0                 (*(volatile unsigned long  *)0xFFC12100)
#define PCR4_1                 (*(volatile unsigned long  *)0xFFC12104)
#define PCR4_2                 (*(volatile unsigned long  *)0xFFC12108)
#define PCR4_3                 (*(volatile unsigned long  *)0xFFC1210C)
#define PCR4_4                 (*(volatile unsigned long  *)0xFFC12110)
#define PCR4_5                 (*(volatile unsigned long  *)0xFFC12114)
#define PCR4_6                 (*(volatile unsigned long  *)0xFFC12118)
#define PCR4_7                 (*(volatile unsigned long  *)0xFFC1211C)
#define PCR4_8                 (*(volatile unsigned long  *)0xFFC12120)
#define PCR4_9                 (*(volatile unsigned long  *)0xFFC12124)
#define PCR4_10                (*(volatile unsigned long  *)0xFFC12128)
#define PCR4_11                (*(volatile unsigned long  *)0xFFC1212C)
#define PCR4_12                (*(volatile unsigned long  *)0xFFC12130)
#define PCR4_13                (*(volatile unsigned long  *)0xFFC12134)
#define PCR4_14                (*(volatile unsigned long  *)0xFFC12138)
#define PCR5_0                 (*(volatile unsigned long  *)0xFFC12140)
#define PCR5_1                 (*(volatile unsigned long  *)0xFFC12144)
#define PCR5_4                 (*(volatile unsigned long  *)0xFFC12150)
#define PCR5_5                 (*(volatile unsigned long  *)0xFFC12154)
#define PCR5_6                 (*(volatile unsigned long  *)0xFFC12158)
#define PCR5_7                 (*(volatile unsigned long  *)0xFFC1215C)
#define PCR5_8                 (*(volatile unsigned long  *)0xFFC12160)
#define PCR5_9                 (*(volatile unsigned long  *)0xFFC12164)
#define PCR5_10                (*(volatile unsigned long  *)0xFFC12168)
#define PCR5_11                (*(volatile unsigned long  *)0xFFC1216C)
#define PCR5_12                (*(volatile unsigned long  *)0xFFC12170)
#define PCR5_13                (*(volatile unsigned long  *)0xFFC12174)
#define PCR5_14                (*(volatile unsigned long  *)0xFFC12178)
#define PCR5_15                (*(volatile unsigned long  *)0xFFC1217C)
#define PCR6_0                 (*(volatile unsigned long  *)0xFFC12180)
#define PCR6_1                 (*(volatile unsigned long  *)0xFFC12184)
#define PCR6_2                 (*(volatile unsigned long  *)0xFFC12188)
#define PCR6_3                 (*(volatile unsigned long  *)0xFFC1218C)
#define PCR6_4                 (*(volatile unsigned long  *)0xFFC12190)
#define PCR6_5                 (*(volatile unsigned long  *)0xFFC12194)
#define PCR6_6                 (*(volatile unsigned long  *)0xFFC12198)
#define PCR6_7                 (*(volatile unsigned long  *)0xFFC1219C)
#define PCR6_8                 (*(volatile unsigned long  *)0xFFC121A0)
#define PCR6_9                 (*(volatile unsigned long  *)0xFFC121A4)
#define PCR6_10                (*(volatile unsigned long  *)0xFFC121A8)
#define PCR6_11                (*(volatile unsigned long  *)0xFFC121AC)
#define PCR6_12                (*(volatile unsigned long  *)0xFFC121B0)
#define PCR6_13                (*(volatile unsigned long  *)0xFFC121B4)
#define PCR6_14                (*(volatile unsigned long  *)0xFFC121B8)
#define PCR6_15                (*(volatile unsigned long  *)0xFFC121BC)
#define PCR7_0                 (*(volatile unsigned long  *)0xFFC121C0)
#define PCR7_1                 (*(volatile unsigned long  *)0xFFC121C4)
#define PCR7_2                 (*(volatile unsigned long  *)0xFFC121C8)
#define PCR7_3                 (*(volatile unsigned long  *)0xFFC121CC)
#define PCR7_4                 (*(volatile unsigned long  *)0xFFC121D0)
#define PCR7_5                 (*(volatile unsigned long  *)0xFFC121D4)
#define PCR7_6                 (*(volatile unsigned long  *)0xFFC121D8)
#define PCR7_7                 (*(volatile unsigned long  *)0xFFC121DC)
#define PCR7_8                 (*(volatile unsigned long  *)0xFFC121E0)
#define PCR7_9                 (*(volatile unsigned long  *)0xFFC121E4)
#define PCR8_0                 (*(volatile unsigned long  *)0xFFC12200)
#define PCR8_1                 (*(volatile unsigned long  *)0xFFC12204)
#define PCR8_2                 (*(volatile unsigned long  *)0xFFC12208)
#define PCR8_3                 (*(volatile unsigned long  *)0xFFC1220C)
#define PCR8_4                 (*(volatile unsigned long  *)0xFFC12210)
#define PCR8_5                 (*(volatile unsigned long  *)0xFFC12214)
#define PCR8_6                 (*(volatile unsigned long  *)0xFFC12218)
#define PCR8_7                 (*(volatile unsigned long  *)0xFFC1221C)
#define PCR8_8                 (*(volatile unsigned long  *)0xFFC12220)
#define PCR8_9                 (*(volatile unsigned long  *)0xFFC12224)
#define PCR8_10                (*(volatile unsigned long  *)0xFFC12228)
#define PCR8_11                (*(volatile unsigned long  *)0xFFC1222C)
#define PCR8_12                (*(volatile unsigned long  *)0xFFC12230)
#define PCR8_13                (*(volatile unsigned long  *)0xFFC12234)
#define PCR8_14                (*(volatile unsigned long  *)0xFFC12238)
#define PCR8_15                (*(volatile unsigned long  *)0xFFC1223C)
#define PCR9_0                 (*(volatile unsigned long  *)0xFFC12240)
#define PCR9_1                 (*(volatile unsigned long  *)0xFFC12244)
#define PCR9_2                 (*(volatile unsigned long  *)0xFFC12248)
#define PCR9_3                 (*(volatile unsigned long  *)0xFFC1224C)
#define PCR9_4                 (*(volatile unsigned long  *)0xFFC12250)
#define PCR9_5                 (*(volatile unsigned long  *)0xFFC12254)
#define PCR9_6                 (*(volatile unsigned long  *)0xFFC12258)
#define PCR9_7                 (*(volatile unsigned long  *)0xFFC1225C)
#define PCR9_8                 (*(volatile unsigned long  *)0xFFC12260)
#define PIBC0                  (*(volatile unsigned short *)0xFFC14000)
#define PBDC0                  (*(volatile unsigned short *)0xFFC14004)
#define PIPC0                  (*(volatile unsigned short *)0xFFC14008)
#define PU0                    (*(volatile unsigned short *)0xFFC1400C)
#define PD0                    (*(volatile unsigned short *)0xFFC14010)
#define PODC0                  (*(volatile unsigned long  *)0xFFC14014)
#define PDSC0                  (*(volatile unsigned long  *)0xFFC14018)
#define PIS0                   (*(volatile unsigned short *)0xFFC1401C)
#define PUCC0                  (*(volatile unsigned long  *)0xFFC14028)
#define PODCE0                 (*(volatile unsigned long  *)0xFFC14038)
#define PIBC1                  (*(volatile unsigned short *)0xFFC14040)
#define PBDC1                  (*(volatile unsigned short *)0xFFC14044)
#define PIPC1                  (*(volatile unsigned short *)0xFFC14048)
#define PU1                    (*(volatile unsigned short *)0xFFC1404C)
#define PD1                    (*(volatile unsigned short *)0xFFC14050)
#define PODC1                  (*(volatile unsigned long  *)0xFFC14054)
#define PDSC1                  (*(volatile unsigned long  *)0xFFC14058)
#define PIS1                   (*(volatile unsigned short *)0xFFC1405C)
#define PUCC1                  (*(volatile unsigned long  *)0xFFC14068)
#define PODCE1                 (*(volatile unsigned long  *)0xFFC14078)
#define PIBC2                  (*(volatile unsigned short *)0xFFC14080)
#define PBDC2                  (*(volatile unsigned short *)0xFFC14084)
#define PIPC2                  (*(volatile unsigned short *)0xFFC14088)
#define PU2                    (*(volatile unsigned short *)0xFFC1408C)
#define PD2                    (*(volatile unsigned short *)0xFFC14090)
#define PODC2                  (*(volatile unsigned long  *)0xFFC14094)
#define PDSC2                  (*(volatile unsigned long  *)0xFFC14098)
#define PIS2                   (*(volatile unsigned short *)0xFFC1409C)
#define PUCC2                  (*(volatile unsigned long  *)0xFFC140A8)
#define PODCE2                 (*(volatile unsigned long  *)0xFFC140B8)
#define PIBC3                  (*(volatile unsigned short *)0xFFC140C0)
#define PBDC3                  (*(volatile unsigned short *)0xFFC140C4)
#define PIPC3                  (*(volatile unsigned short *)0xFFC140C8)
#define PU3                    (*(volatile unsigned short *)0xFFC140CC)
#define PD3                    (*(volatile unsigned short *)0xFFC140D0)
#define PODC3                  (*(volatile unsigned long  *)0xFFC140D4)
#define PDSC3                  (*(volatile unsigned long  *)0xFFC140D8)
#define PIS3                   (*(volatile unsigned short *)0xFFC140DC)
#define PUCC3                  (*(volatile unsigned long  *)0xFFC140E8)
#define PODCE3                 (*(volatile unsigned long  *)0xFFC140F8)
#define PIBC4                  (*(volatile unsigned short *)0xFFC14100)
#define PBDC4                  (*(volatile unsigned short *)0xFFC14104)
#define PIPC4                  (*(volatile unsigned short *)0xFFC14108)
#define PU4                    (*(volatile unsigned short *)0xFFC1410C)
#define PD4                    (*(volatile unsigned short *)0xFFC14110)
#define PODC4                  (*(volatile unsigned long  *)0xFFC14114)
#define PDSC4                  (*(volatile unsigned long  *)0xFFC14118)
#define PIS4                   (*(volatile unsigned short *)0xFFC1411C)
#define PUCC4                  (*(volatile unsigned long  *)0xFFC14128)
#define PODCE4                 (*(volatile unsigned long  *)0xFFC14138)
#define PIBC5                  (*(volatile unsigned short *)0xFFC14140)
#define PBDC5                  (*(volatile unsigned short *)0xFFC14144)
#define PIPC5                  (*(volatile unsigned short *)0xFFC14148)
#define PU5                    (*(volatile unsigned short *)0xFFC1414C)
#define PD5                    (*(volatile unsigned short *)0xFFC14150)
#define PODC5                  (*(volatile unsigned long  *)0xFFC14154)
#define PDSC5                  (*(volatile unsigned long  *)0xFFC14158)
#define PIS5                   (*(volatile unsigned short *)0xFFC1415C)
#define PUCC5                  (*(volatile unsigned long  *)0xFFC14168)
#define PODCE5                 (*(volatile unsigned long  *)0xFFC14178)
#define PIBC6                  (*(volatile unsigned short *)0xFFC14180)
#define PBDC6                  (*(volatile unsigned short *)0xFFC14184)
#define PIPC6                  (*(volatile unsigned short *)0xFFC14188)
#define PU6                    (*(volatile unsigned short *)0xFFC1418C)
#define PD6                    (*(volatile unsigned short *)0xFFC14190)
#define PODC6                  (*(volatile unsigned long  *)0xFFC14194)
#define PDSC6                  (*(volatile unsigned long  *)0xFFC14198)
#define PIS6                   (*(volatile unsigned short *)0xFFC1419C)
#define PUCC6                  (*(volatile unsigned long  *)0xFFC141A8)
#define PODCE6                 (*(volatile unsigned long  *)0xFFC141B8)
#define PIBC7                  (*(volatile unsigned short *)0xFFC141C0)
#define PBDC7                  (*(volatile unsigned short *)0xFFC141C4)
#define PIPC7                  (*(volatile unsigned short *)0xFFC141C8)
#define PU7                    (*(volatile unsigned short *)0xFFC141CC)
#define PD7                    (*(volatile unsigned short *)0xFFC141D0)
#define PODC7                  (*(volatile unsigned long  *)0xFFC141D4)
#define PDSC7                  (*(volatile unsigned long  *)0xFFC141D8)
#define PIS7                   (*(volatile unsigned short *)0xFFC141DC)
#define PUCC7                  (*(volatile unsigned long  *)0xFFC141E8)
#define PODCE7                 (*(volatile unsigned long  *)0xFFC141F8)
#define PIBC8                  (*(volatile unsigned short *)0xFFC14200)
#define PBDC8                  (*(volatile unsigned short *)0xFFC14204)
#define PIPC8                  (*(volatile unsigned short *)0xFFC14208)
#define PU8                    (*(volatile unsigned short *)0xFFC1420C)
#define PD8                    (*(volatile unsigned short *)0xFFC14210)
#define PODC8                  (*(volatile unsigned long  *)0xFFC14214)
#define PDSC8                  (*(volatile unsigned long  *)0xFFC14218)
#define PIS8                   (*(volatile unsigned short *)0xFFC1421C)
#define PUCC8                  (*(volatile unsigned long  *)0xFFC14228)
#define PODCE8                 (*(volatile unsigned long  *)0xFFC14238)
#define PIBC9                  (*(volatile unsigned short *)0xFFC14240)
#define PBDC9                  (*(volatile unsigned short *)0xFFC14244)
#define PIPC9                  (*(volatile unsigned short *)0xFFC14248)
#define PU9                    (*(volatile unsigned short *)0xFFC1424C)
#define PD9                    (*(volatile unsigned short *)0xFFC14250)
#define PODC9                  (*(volatile unsigned long  *)0xFFC14254)
#define PDSC9                  (*(volatile unsigned long  *)0xFFC14258)
#define PIS9                   (*(volatile unsigned short *)0xFFC1425C)
#define PUCC9                  (*(volatile unsigned long  *)0xFFC14268)
#define PODCE9                 (*(volatile unsigned long  *)0xFFC14278)
#define JP0                    (*(volatile unsigned char  *)0xFFC20000)
#define JPSR0                  (*(volatile unsigned long  *)0xFFC20004)
#define JPNOT0                 (*(volatile unsigned char  *)0xFFC20008)
#define JPPR0                  (*(volatile unsigned char  *)0xFFC2000C)
#define JPM0                   (*(volatile unsigned char  *)0xFFC20010)
#define JPMC0                  (*(volatile unsigned char  *)0xFFC20014)
#define JPFCE0                 (*(volatile unsigned char  *)0xFFC2001C)
#define JPMSR0                 (*(volatile unsigned long  *)0xFFC20020)
#define JPMCSR0                (*(volatile unsigned long  *)0xFFC20024)
#define JPINV0                 (*(volatile unsigned char  *)0xFFC20030)
#define JPCR0_0                (*(volatile unsigned long  *)0xFFC22000)
#define JPCR0_1                (*(volatile unsigned long  *)0xFFC22004)
#define JPCR0_2                (*(volatile unsigned long  *)0xFFC22008)
#define JPCR0_3                (*(volatile unsigned long  *)0xFFC2200C)
#define JPCR0_4                (*(volatile unsigned long  *)0xFFC22010)
#define JPCR0_5                (*(volatile unsigned long  *)0xFFC22014)
#define JPIBC0                 (*(volatile unsigned char  *)0xFFC24000)
#define JPBDC0                 (*(volatile unsigned char  *)0xFFC24004)
#define JPU0                   (*(volatile unsigned char  *)0xFFC2400C)
#define JPD0                   (*(volatile unsigned char  *)0xFFC24010)
#define JPODC0                 (*(volatile unsigned long  *)0xFFC24014)
#define JPDSC0                 (*(volatile unsigned long  *)0xFFC24018)
#define JPIS0                  (*(volatile unsigned char  *)0xFFC2401C)
#define JPUCC0                 (*(volatile unsigned long  *)0xFFC24028)
#define JPODCE0                (*(volatile unsigned long  *)0xFFC24038)
#define MGDCFCTL_VCI2CFB       (*(volatile unsigned long  *)0xFFC48100)
#define MGDCFCTL_VCI2CFBL      (*(volatile unsigned short *)0xFFC48100)
#define MGDCFCTL_VCI2CFBLL     (*(volatile unsigned char  *)0xFFC48100)
#define MGDCFSTAT_VCI2CFB      (*(volatile unsigned long  *)0xFFC48104)
#define MGDCFSTAT_VCI2CFBL     (*(volatile unsigned short *)0xFFC48104)
#define MGDCFSTAT_VCI2CFBLL    (*(volatile unsigned char  *)0xFFC48104)
#define MGDCFTYPE_VCI2CFB      (*(volatile unsigned long  *)0xFFC4810C)
#define MGDCFTYPE_VCI2CFBL     (*(volatile unsigned short *)0xFFC4810C)
#define MGDCFTYPE_VCI2CFBLL    (*(volatile unsigned char  *)0xFFC4810C)
#define MGDCFTYPE_VCI2CFBLH    (*(volatile unsigned char  *)0xFFC4810D)
#define MGDCFTYPE_VCI2CFBH     (*(volatile unsigned short *)0xFFC4810E)
#define MGDCFTYPE_VCI2CFBHL    (*(volatile unsigned char  *)0xFFC4810E)
#define MGDCFTYPE_VCI2CFBHH    (*(volatile unsigned char  *)0xFFC4810F)
#define MGDCFCTL_PE1           (*(volatile unsigned long  *)0xFFC48200)
#define MGDCFCTL_PE1L          (*(volatile unsigned short *)0xFFC48200)
#define MGDCFCTL_PE1LL         (*(volatile unsigned char  *)0xFFC48200)
#define MGDCFSTAT_PE1          (*(volatile unsigned long  *)0xFFC48204)
#define MGDCFSTAT_PE1L         (*(volatile unsigned short *)0xFFC48204)
#define MGDCFSTAT_PE1LL        (*(volatile unsigned char  *)0xFFC48204)
#define MGDCFTYPE_PE1          (*(volatile unsigned long  *)0xFFC4820C)
#define MGDCFTYPE_PE1L         (*(volatile unsigned short *)0xFFC4820C)
#define MGDCFTYPE_PE1LL        (*(volatile unsigned char  *)0xFFC4820C)
#define MGDCFTYPE_PE1LH        (*(volatile unsigned char  *)0xFFC4820D)
#define MGDCFTYPE_PE1H         (*(volatile unsigned short *)0xFFC4820E)
#define MGDCFTYPE_PE1HL        (*(volatile unsigned char  *)0xFFC4820E)
#define MGDCFTYPE_PE1HH        (*(volatile unsigned char  *)0xFFC4820F)
#define MGDGRPROT0             (*(volatile unsigned long  *)0xFFC49000)
#define MGDGRPROT0L            (*(volatile unsigned short *)0xFFC49000)
#define MGDGRPROT0LL           (*(volatile unsigned char  *)0xFFC49000)
#define MGDGRPROT0LH           (*(volatile unsigned char  *)0xFFC49001)
#define MGDGRPROT0H            (*(volatile unsigned short *)0xFFC49002)
#define MGDGRPROT0HL           (*(volatile unsigned char  *)0xFFC49002)
#define MGDGRPROT0HH           (*(volatile unsigned char  *)0xFFC49003)
#define MGDGRSPID0             (*(volatile unsigned long  *)0xFFC49004)
#define MGDGRBAD0              (*(volatile unsigned long  *)0xFFC49008)
#define MGDGRBAD0L             (*(volatile unsigned short *)0xFFC49008)
#define MGDGRBAD0LL            (*(volatile unsigned char  *)0xFFC49008)
#define MGDGRBAD0LH            (*(volatile unsigned char  *)0xFFC49009)
#define MGDGRBAD0H             (*(volatile unsigned short *)0xFFC4900A)
#define MGDGRBAD0HL            (*(volatile unsigned char  *)0xFFC4900A)
#define MGDGRBAD0HH            (*(volatile unsigned char  *)0xFFC4900B)
#define MGDGRADV0              (*(volatile unsigned long  *)0xFFC4900C)
#define MGDGRADV0L             (*(volatile unsigned short *)0xFFC4900C)
#define MGDGRADV0LL            (*(volatile unsigned char  *)0xFFC4900C)
#define MGDGRADV0LH            (*(volatile unsigned char  *)0xFFC4900D)
#define MGDGRADV0H             (*(volatile unsigned short *)0xFFC4900E)
#define MGDGRADV0HL            (*(volatile unsigned char  *)0xFFC4900E)
#define MGDGRADV0HH            (*(volatile unsigned char  *)0xFFC4900F)
#define MGDGRPROT1             (*(volatile unsigned long  *)0xFFC49010)
#define MGDGRPROT1L            (*(volatile unsigned short *)0xFFC49010)
#define MGDGRPROT1LL           (*(volatile unsigned char  *)0xFFC49010)
#define MGDGRPROT1LH           (*(volatile unsigned char  *)0xFFC49011)
#define MGDGRPROT1H            (*(volatile unsigned short *)0xFFC49012)
#define MGDGRPROT1HL           (*(volatile unsigned char  *)0xFFC49012)
#define MGDGRPROT1HH           (*(volatile unsigned char  *)0xFFC49013)
#define MGDGRSPID1             (*(volatile unsigned long  *)0xFFC49014)
#define MGDGRBAD1              (*(volatile unsigned long  *)0xFFC49018)
#define MGDGRBAD1L             (*(volatile unsigned short *)0xFFC49018)
#define MGDGRBAD1LL            (*(volatile unsigned char  *)0xFFC49018)
#define MGDGRBAD1LH            (*(volatile unsigned char  *)0xFFC49019)
#define MGDGRBAD1H             (*(volatile unsigned short *)0xFFC4901A)
#define MGDGRBAD1HL            (*(volatile unsigned char  *)0xFFC4901A)
#define MGDGRBAD1HH            (*(volatile unsigned char  *)0xFFC4901B)
#define MGDGRADV1              (*(volatile unsigned long  *)0xFFC4901C)
#define MGDGRADV1L             (*(volatile unsigned short *)0xFFC4901C)
#define MGDGRADV1LL            (*(volatile unsigned char  *)0xFFC4901C)
#define MGDGRADV1LH            (*(volatile unsigned char  *)0xFFC4901D)
#define MGDGRADV1H             (*(volatile unsigned short *)0xFFC4901E)
#define MGDGRADV1HL            (*(volatile unsigned char  *)0xFFC4901E)
#define MGDGRADV1HH            (*(volatile unsigned char  *)0xFFC4901F)
#define MGDGRPROT2             (*(volatile unsigned long  *)0xFFC49020)
#define MGDGRPROT2L            (*(volatile unsigned short *)0xFFC49020)
#define MGDGRPROT2LL           (*(volatile unsigned char  *)0xFFC49020)
#define MGDGRPROT2LH           (*(volatile unsigned char  *)0xFFC49021)
#define MGDGRPROT2H            (*(volatile unsigned short *)0xFFC49022)
#define MGDGRPROT2HL           (*(volatile unsigned char  *)0xFFC49022)
#define MGDGRPROT2HH           (*(volatile unsigned char  *)0xFFC49023)
#define MGDGRSPID2             (*(volatile unsigned long  *)0xFFC49024)
#define MGDGRBAD2              (*(volatile unsigned long  *)0xFFC49028)
#define MGDGRBAD2L             (*(volatile unsigned short *)0xFFC49028)
#define MGDGRBAD2LL            (*(volatile unsigned char  *)0xFFC49028)
#define MGDGRBAD2LH            (*(volatile unsigned char  *)0xFFC49029)
#define MGDGRBAD2H             (*(volatile unsigned short *)0xFFC4902A)
#define MGDGRBAD2HL            (*(volatile unsigned char  *)0xFFC4902A)
#define MGDGRBAD2HH            (*(volatile unsigned char  *)0xFFC4902B)
#define MGDGRADV2              (*(volatile unsigned long  *)0xFFC4902C)
#define MGDGRADV2L             (*(volatile unsigned short *)0xFFC4902C)
#define MGDGRADV2LL            (*(volatile unsigned char  *)0xFFC4902C)
#define MGDGRADV2LH            (*(volatile unsigned char  *)0xFFC4902D)
#define MGDGRADV2H             (*(volatile unsigned short *)0xFFC4902E)
#define MGDGRADV2HL            (*(volatile unsigned char  *)0xFFC4902E)
#define MGDGRADV2HH            (*(volatile unsigned char  *)0xFFC4902F)
#define MGDGRPROT3             (*(volatile unsigned long  *)0xFFC49030)
#define MGDGRPROT3L            (*(volatile unsigned short *)0xFFC49030)
#define MGDGRPROT3LL           (*(volatile unsigned char  *)0xFFC49030)
#define MGDGRPROT3LH           (*(volatile unsigned char  *)0xFFC49031)
#define MGDGRPROT3H            (*(volatile unsigned short *)0xFFC49032)
#define MGDGRPROT3HL           (*(volatile unsigned char  *)0xFFC49032)
#define MGDGRPROT3HH           (*(volatile unsigned char  *)0xFFC49033)
#define MGDGRSPID3             (*(volatile unsigned long  *)0xFFC49034)
#define MGDGRBAD3              (*(volatile unsigned long  *)0xFFC49038)
#define MGDGRBAD3L             (*(volatile unsigned short *)0xFFC49038)
#define MGDGRBAD3LL            (*(volatile unsigned char  *)0xFFC49038)
#define MGDGRBAD3LH            (*(volatile unsigned char  *)0xFFC49039)
#define MGDGRBAD3H             (*(volatile unsigned short *)0xFFC4903A)
#define MGDGRBAD3HL            (*(volatile unsigned char  *)0xFFC4903A)
#define MGDGRBAD3HH            (*(volatile unsigned char  *)0xFFC4903B)
#define MGDGRADV3              (*(volatile unsigned long  *)0xFFC4903C)
#define MGDGRADV3L             (*(volatile unsigned short *)0xFFC4903C)
#define MGDGRADV3LL            (*(volatile unsigned char  *)0xFFC4903C)
#define MGDGRADV3LH            (*(volatile unsigned char  *)0xFFC4903D)
#define MGDGRADV3H             (*(volatile unsigned short *)0xFFC4903E)
#define MGDGRADV3HL            (*(volatile unsigned char  *)0xFFC4903E)
#define MGDGRADV3HH            (*(volatile unsigned char  *)0xFFC4903F)
#define MGDGRPROT4             (*(volatile unsigned long  *)0xFFC49040)
#define MGDGRPROT4L            (*(volatile unsigned short *)0xFFC49040)
#define MGDGRPROT4LL           (*(volatile unsigned char  *)0xFFC49040)
#define MGDGRPROT4LH           (*(volatile unsigned char  *)0xFFC49041)
#define MGDGRPROT4H            (*(volatile unsigned short *)0xFFC49042)
#define MGDGRPROT4HL           (*(volatile unsigned char  *)0xFFC49042)
#define MGDGRPROT4HH           (*(volatile unsigned char  *)0xFFC49043)
#define MGDGRSPID4             (*(volatile unsigned long  *)0xFFC49044)
#define MGDGRBAD4              (*(volatile unsigned long  *)0xFFC49048)
#define MGDGRBAD4L             (*(volatile unsigned short *)0xFFC49048)
#define MGDGRBAD4LL            (*(volatile unsigned char  *)0xFFC49048)
#define MGDGRBAD4LH            (*(volatile unsigned char  *)0xFFC49049)
#define MGDGRBAD4H             (*(volatile unsigned short *)0xFFC4904A)
#define MGDGRBAD4HL            (*(volatile unsigned char  *)0xFFC4904A)
#define MGDGRBAD4HH            (*(volatile unsigned char  *)0xFFC4904B)
#define MGDGRADV4              (*(volatile unsigned long  *)0xFFC4904C)
#define MGDGRADV4L             (*(volatile unsigned short *)0xFFC4904C)
#define MGDGRADV4LL            (*(volatile unsigned char  *)0xFFC4904C)
#define MGDGRADV4LH            (*(volatile unsigned char  *)0xFFC4904D)
#define MGDGRADV4H             (*(volatile unsigned short *)0xFFC4904E)
#define MGDGRADV4HL            (*(volatile unsigned char  *)0xFFC4904E)
#define MGDGRADV4HH            (*(volatile unsigned char  *)0xFFC4904F)
#define MGDGRPROT5             (*(volatile unsigned long  *)0xFFC49050)
#define MGDGRPROT5L            (*(volatile unsigned short *)0xFFC49050)
#define MGDGRPROT5LL           (*(volatile unsigned char  *)0xFFC49050)
#define MGDGRPROT5LH           (*(volatile unsigned char  *)0xFFC49051)
#define MGDGRPROT5H            (*(volatile unsigned short *)0xFFC49052)
#define MGDGRPROT5HL           (*(volatile unsigned char  *)0xFFC49052)
#define MGDGRPROT5HH           (*(volatile unsigned char  *)0xFFC49053)
#define MGDGRSPID5             (*(volatile unsigned long  *)0xFFC49054)
#define MGDGRBAD5              (*(volatile unsigned long  *)0xFFC49058)
#define MGDGRBAD5L             (*(volatile unsigned short *)0xFFC49058)
#define MGDGRBAD5LL            (*(volatile unsigned char  *)0xFFC49058)
#define MGDGRBAD5LH            (*(volatile unsigned char  *)0xFFC49059)
#define MGDGRBAD5H             (*(volatile unsigned short *)0xFFC4905A)
#define MGDGRBAD5HL            (*(volatile unsigned char  *)0xFFC4905A)
#define MGDGRBAD5HH            (*(volatile unsigned char  *)0xFFC4905B)
#define MGDGRADV5              (*(volatile unsigned long  *)0xFFC4905C)
#define MGDGRADV5L             (*(volatile unsigned short *)0xFFC4905C)
#define MGDGRADV5LL            (*(volatile unsigned char  *)0xFFC4905C)
#define MGDGRADV5LH            (*(volatile unsigned char  *)0xFFC4905D)
#define MGDGRADV5H             (*(volatile unsigned short *)0xFFC4905E)
#define MGDGRADV5HL            (*(volatile unsigned char  *)0xFFC4905E)
#define MGDGRADV5HH            (*(volatile unsigned char  *)0xFFC4905F)
#define MGDGRPROT6             (*(volatile unsigned long  *)0xFFC49060)
#define MGDGRPROT6L            (*(volatile unsigned short *)0xFFC49060)
#define MGDGRPROT6LL           (*(volatile unsigned char  *)0xFFC49060)
#define MGDGRPROT6LH           (*(volatile unsigned char  *)0xFFC49061)
#define MGDGRPROT6H            (*(volatile unsigned short *)0xFFC49062)
#define MGDGRPROT6HL           (*(volatile unsigned char  *)0xFFC49062)
#define MGDGRPROT6HH           (*(volatile unsigned char  *)0xFFC49063)
#define MGDGRSPID6             (*(volatile unsigned long  *)0xFFC49064)
#define MGDGRBAD6              (*(volatile unsigned long  *)0xFFC49068)
#define MGDGRBAD6L             (*(volatile unsigned short *)0xFFC49068)
#define MGDGRBAD6LL            (*(volatile unsigned char  *)0xFFC49068)
#define MGDGRBAD6LH            (*(volatile unsigned char  *)0xFFC49069)
#define MGDGRBAD6H             (*(volatile unsigned short *)0xFFC4906A)
#define MGDGRBAD6HL            (*(volatile unsigned char  *)0xFFC4906A)
#define MGDGRBAD6HH            (*(volatile unsigned char  *)0xFFC4906B)
#define MGDGRADV6              (*(volatile unsigned long  *)0xFFC4906C)
#define MGDGRADV6L             (*(volatile unsigned short *)0xFFC4906C)
#define MGDGRADV6LL            (*(volatile unsigned char  *)0xFFC4906C)
#define MGDGRADV6LH            (*(volatile unsigned char  *)0xFFC4906D)
#define MGDGRADV6H             (*(volatile unsigned short *)0xFFC4906E)
#define MGDGRADV6HL            (*(volatile unsigned char  *)0xFFC4906E)
#define MGDGRADV6HH            (*(volatile unsigned char  *)0xFFC4906F)
#define MGDGRPROT7             (*(volatile unsigned long  *)0xFFC49070)
#define MGDGRPROT7L            (*(volatile unsigned short *)0xFFC49070)
#define MGDGRPROT7LL           (*(volatile unsigned char  *)0xFFC49070)
#define MGDGRPROT7LH           (*(volatile unsigned char  *)0xFFC49071)
#define MGDGRPROT7H            (*(volatile unsigned short *)0xFFC49072)
#define MGDGRPROT7HL           (*(volatile unsigned char  *)0xFFC49072)
#define MGDGRPROT7HH           (*(volatile unsigned char  *)0xFFC49073)
#define MGDGRSPID7             (*(volatile unsigned long  *)0xFFC49074)
#define MGDGRBAD7              (*(volatile unsigned long  *)0xFFC49078)
#define MGDGRBAD7L             (*(volatile unsigned short *)0xFFC49078)
#define MGDGRBAD7LL            (*(volatile unsigned char  *)0xFFC49078)
#define MGDGRBAD7LH            (*(volatile unsigned char  *)0xFFC49079)
#define MGDGRBAD7H             (*(volatile unsigned short *)0xFFC4907A)
#define MGDGRBAD7HL            (*(volatile unsigned char  *)0xFFC4907A)
#define MGDGRBAD7HH            (*(volatile unsigned char  *)0xFFC4907B)
#define MGDGRADV7              (*(volatile unsigned long  *)0xFFC4907C)
#define MGDGRADV7L             (*(volatile unsigned short *)0xFFC4907C)
#define MGDGRADV7LL            (*(volatile unsigned char  *)0xFFC4907C)
#define MGDGRADV7LH            (*(volatile unsigned char  *)0xFFC4907D)
#define MGDGRADV7H             (*(volatile unsigned short *)0xFFC4907E)
#define MGDGRADV7HL            (*(volatile unsigned char  *)0xFFC4907E)
#define MGDGRADV7HH            (*(volatile unsigned char  *)0xFFC4907F)
#define MGDGRSCTL_VCI2GRAM     (*(volatile unsigned long  *)0xFFC49100)
#define MGDGRSSTAT_VCI2GRAM    (*(volatile unsigned long  *)0xFFC49104)
#define MGDGRSTYPE_VCI2GRAM    (*(volatile unsigned long  *)0xFFC4910C)
#define MGDGRSTYPE_VCI2GRAML   (*(volatile unsigned short *)0xFFC4910C)
#define MGDGRSTYPE_VCI2GRAMLL  (*(volatile unsigned char  *)0xFFC4910C)
#define MGDGRSTYPE_VCI2GRAMLH  (*(volatile unsigned char  *)0xFFC4910D)
#define MGDGRSTYPE_VCI2GRAMH   (*(volatile unsigned short *)0xFFC4910E)
#define MGDGRSTYPE_VCI2GRAMHL  (*(volatile unsigned char  *)0xFFC4910E)
#define MGDGRSTYPE_VCI2GRAMHH  (*(volatile unsigned char  *)0xFFC4910F)
#define MGDGRSCTL_PE1          (*(volatile unsigned long  *)0xFFC49200)
#define MGDGRSSTAT_PE1         (*(volatile unsigned long  *)0xFFC49204)
#define MGDGRSTYPE_PE1         (*(volatile unsigned long  *)0xFFC4920C)
#define MGDGRSTYPE_PE1L        (*(volatile unsigned short *)0xFFC4920C)
#define MGDGRSTYPE_PE1LL       (*(volatile unsigned char  *)0xFFC4920C)
#define MGDGRSTYPE_PE1LH       (*(volatile unsigned char  *)0xFFC4920D)
#define MGDGRSTYPE_PE1H        (*(volatile unsigned short *)0xFFC4920E)
#define MGDGRSTYPE_PE1HL       (*(volatile unsigned char  *)0xFFC4920E)
#define MGDGRSTYPE_PE1HH       (*(volatile unsigned char  *)0xFFC4920F)
#define MGDGRSCTL_AXI2GRAM     (*(volatile unsigned long  *)0xFFC49700)
#define MGDGRSSTAT_AXI2GRAM    (*(volatile unsigned long  *)0xFFC49704)
#define MGDGRSTYPE_AXI2GRAM    (*(volatile unsigned long  *)0xFFC4970C)
#define MGDGRSTYPE_AXI2GRAML   (*(volatile unsigned short *)0xFFC4970C)
#define MGDGRSTYPE_AXI2GRAMLL  (*(volatile unsigned char  *)0xFFC4970C)
#define MGDGRSTYPE_AXI2GRAMLH  (*(volatile unsigned char  *)0xFFC4970D)
#define MGDGRSTYPE_AXI2GRAMH   (*(volatile unsigned short *)0xFFC4970E)
#define MGDGRSTYPE_AXI2GRAMHL  (*(volatile unsigned char  *)0xFFC4970E)
#define MGDGRSTYPE_AXI2GRAMHH  (*(volatile unsigned char  *)0xFFC4970F)
#define PGERRSTATCTL_PE1       (*(volatile unsigned long  *)0xFFC4A200)
#define PGERRSTAT_PE1          (*(volatile unsigned long  *)0xFFC4A204)
#define PGERRINFO_PE1          (*(volatile unsigned long  *)0xFFC4A208)
#define PGERRSTATCTL_PE2       (*(volatile unsigned long  *)0xFFC4A300)
#define PGERRSTAT_PE2          (*(volatile unsigned long  *)0xFFC4A304)
#define PGERRINFO_PE2          (*(volatile unsigned long  *)0xFFC4A308)
#define APBFSGDPROT_PDMACM_A   (*(volatile unsigned long  *)0xFFC4C000)
#define APBFSGDPROT_PDMACM_AL  (*(volatile unsigned short *)0xFFC4C000)
#define APBFSGDPROT_PDMACM_ALL (*(volatile unsigned char  *)0xFFC4C000)
#define APBFSGDPROT_PDMACM_ALH (*(volatile unsigned char  *)0xFFC4C001)
#define APBFSGDPROT_PDMACM_AH  (*(volatile unsigned short *)0xFFC4C002)
#define APBFSGDPROT_PDMACM_AHL (*(volatile unsigned char  *)0xFFC4C002)
#define APBFSGDPROT_PDMACM_AHH (*(volatile unsigned char  *)0xFFC4C003)
#define APBFSGDSPID_PDMACM_A   (*(volatile unsigned long  *)0xFFC4C004)
#define APBFSGDSPID_PDMACM_AL  (*(volatile unsigned short *)0xFFC4C004)
#define APBFSGDSPID_PDMACM_ALL (*(volatile unsigned char  *)0xFFC4C004)
#define APBFSGDSPID_PDMACM_ALH (*(volatile unsigned char  *)0xFFC4C005)
#define APBFSGDSPID_PDMACM_AH  (*(volatile unsigned short *)0xFFC4C006)
#define APBFSGDSPID_PDMACM_AHL (*(volatile unsigned char  *)0xFFC4C006)
#define APBFSGDSPID_PDMACM_AHH (*(volatile unsigned char  *)0xFFC4C007)
#define APBFSGDPROT_PDMACM_B   (*(volatile unsigned long  *)0xFFC4C008)
#define APBFSGDPROT_PDMACM_BL  (*(volatile unsigned short *)0xFFC4C008)
#define APBFSGDPROT_PDMACM_BLL (*(volatile unsigned char  *)0xFFC4C008)
#define APBFSGDPROT_PDMACM_BLH (*(volatile unsigned char  *)0xFFC4C009)
#define APBFSGDPROT_PDMACM_BH  (*(volatile unsigned short *)0xFFC4C00A)
#define APBFSGDPROT_PDMACM_BHL (*(volatile unsigned char  *)0xFFC4C00A)
#define APBFSGDPROT_PDMACM_BHH (*(volatile unsigned char  *)0xFFC4C00B)
#define APBFSGDSPID_PDMACM_B   (*(volatile unsigned long  *)0xFFC4C00C)
#define APBFSGDSPID_PDMACM_BL  (*(volatile unsigned short *)0xFFC4C00C)
#define APBFSGDSPID_PDMACM_BLL (*(volatile unsigned char  *)0xFFC4C00C)
#define APBFSGDSPID_PDMACM_BLH (*(volatile unsigned char  *)0xFFC4C00D)
#define APBFSGDSPID_PDMACM_BH  (*(volatile unsigned short *)0xFFC4C00E)
#define APBFSGDSPID_PDMACM_BHL (*(volatile unsigned char  *)0xFFC4C00E)
#define APBFSGDSPID_PDMACM_BHH (*(volatile unsigned char  *)0xFFC4C00F)
#define APBFSGDPROT_PDMACH_A   (*(volatile unsigned long  *)0xFFC4C010)
#define APBFSGDPROT_PDMACH_AL  (*(volatile unsigned short *)0xFFC4C010)
#define APBFSGDPROT_PDMACH_ALL (*(volatile unsigned char  *)0xFFC4C010)
#define APBFSGDPROT_PDMACH_ALH (*(volatile unsigned char  *)0xFFC4C011)
#define APBFSGDPROT_PDMACH_AH  (*(volatile unsigned short *)0xFFC4C012)
#define APBFSGDPROT_PDMACH_AHL (*(volatile unsigned char  *)0xFFC4C012)
#define APBFSGDPROT_PDMACH_AHH (*(volatile unsigned char  *)0xFFC4C013)
#define APBFSGDSPID_PDMACH_A   (*(volatile unsigned long  *)0xFFC4C014)
#define APBFSGDSPID_PDMACH_AL  (*(volatile unsigned short *)0xFFC4C014)
#define APBFSGDSPID_PDMACH_ALL (*(volatile unsigned char  *)0xFFC4C014)
#define APBFSGDSPID_PDMACH_ALH (*(volatile unsigned char  *)0xFFC4C015)
#define APBFSGDSPID_PDMACH_AH  (*(volatile unsigned short *)0xFFC4C016)
#define APBFSGDSPID_PDMACH_AHL (*(volatile unsigned char  *)0xFFC4C016)
#define APBFSGDSPID_PDMACH_AHH (*(volatile unsigned char  *)0xFFC4C017)
#define APBFSGDPROT_PDMACH_B   (*(volatile unsigned long  *)0xFFC4C018)
#define APBFSGDPROT_PDMACH_BL  (*(volatile unsigned short *)0xFFC4C018)
#define APBFSGDPROT_PDMACH_BLL (*(volatile unsigned char  *)0xFFC4C018)
#define APBFSGDPROT_PDMACH_BLH (*(volatile unsigned char  *)0xFFC4C019)
#define APBFSGDPROT_PDMACH_BH  (*(volatile unsigned short *)0xFFC4C01A)
#define APBFSGDPROT_PDMACH_BHL (*(volatile unsigned char  *)0xFFC4C01A)
#define APBFSGDPROT_PDMACH_BHH (*(volatile unsigned char  *)0xFFC4C01B)
#define APBFSGDSPID_PDMACH_B   (*(volatile unsigned long  *)0xFFC4C01C)
#define APBFSGDSPID_PDMACH_BL  (*(volatile unsigned short *)0xFFC4C01C)
#define APBFSGDSPID_PDMACH_BLL (*(volatile unsigned char  *)0xFFC4C01C)
#define APBFSGDSPID_PDMACH_BLH (*(volatile unsigned char  *)0xFFC4C01D)
#define APBFSGDSPID_PDMACH_BH  (*(volatile unsigned short *)0xFFC4C01E)
#define APBFSGDSPID_PDMACH_BHL (*(volatile unsigned char  *)0xFFC4C01E)
#define APBFSGDSPID_PDMACH_BHH (*(volatile unsigned char  *)0xFFC4C01F)
#define APBFSGDPROT_INTC2_A    (*(volatile unsigned long  *)0xFFC4C020)
#define APBFSGDPROT_INTC2_AL   (*(volatile unsigned short *)0xFFC4C020)
#define APBFSGDPROT_INTC2_ALL  (*(volatile unsigned char  *)0xFFC4C020)
#define APBFSGDPROT_INTC2_ALH  (*(volatile unsigned char  *)0xFFC4C021)
#define APBFSGDPROT_INTC2_AH   (*(volatile unsigned short *)0xFFC4C022)
#define APBFSGDPROT_INTC2_AHL  (*(volatile unsigned char  *)0xFFC4C022)
#define APBFSGDPROT_INTC2_AHH  (*(volatile unsigned char  *)0xFFC4C023)
#define APBFSGDSPID_INTC2_A    (*(volatile unsigned long  *)0xFFC4C024)
#define APBFSGDSPID_INTC2_AL   (*(volatile unsigned short *)0xFFC4C024)
#define APBFSGDSPID_INTC2_ALL  (*(volatile unsigned char  *)0xFFC4C024)
#define APBFSGDSPID_INTC2_ALH  (*(volatile unsigned char  *)0xFFC4C025)
#define APBFSGDSPID_INTC2_AH   (*(volatile unsigned short *)0xFFC4C026)
#define APBFSGDSPID_INTC2_AHL  (*(volatile unsigned char  *)0xFFC4C026)
#define APBFSGDSPID_INTC2_AHH  (*(volatile unsigned char  *)0xFFC4C027)
#define APBFSGDPROT_INTC2_B    (*(volatile unsigned long  *)0xFFC4C028)
#define APBFSGDPROT_INTC2_BL   (*(volatile unsigned short *)0xFFC4C028)
#define APBFSGDPROT_INTC2_BLL  (*(volatile unsigned char  *)0xFFC4C028)
#define APBFSGDPROT_INTC2_BLH  (*(volatile unsigned char  *)0xFFC4C029)
#define APBFSGDPROT_INTC2_BH   (*(volatile unsigned short *)0xFFC4C02A)
#define APBFSGDPROT_INTC2_BHL  (*(volatile unsigned char  *)0xFFC4C02A)
#define APBFSGDPROT_INTC2_BHH  (*(volatile unsigned char  *)0xFFC4C02B)
#define APBFSGDSPID_INTC2_B    (*(volatile unsigned long  *)0xFFC4C02C)
#define APBFSGDSPID_INTC2_BL   (*(volatile unsigned short *)0xFFC4C02C)
#define APBFSGDSPID_INTC2_BLL  (*(volatile unsigned char  *)0xFFC4C02C)
#define APBFSGDSPID_INTC2_BLH  (*(volatile unsigned char  *)0xFFC4C02D)
#define APBFSGDSPID_INTC2_BH   (*(volatile unsigned short *)0xFFC4C02E)
#define APBFSGDSPID_INTC2_BHL  (*(volatile unsigned char  *)0xFFC4C02E)
#define APBFSGDSPID_INTC2_BHH  (*(volatile unsigned char  *)0xFFC4C02F)
#define APBFSGDPROT_PBG_A      (*(volatile unsigned long  *)0xFFC4C040)
#define APBFSGDPROT_PBG_AL     (*(volatile unsigned short *)0xFFC4C040)
#define APBFSGDPROT_PBG_ALL    (*(volatile unsigned char  *)0xFFC4C040)
#define APBFSGDPROT_PBG_ALH    (*(volatile unsigned char  *)0xFFC4C041)
#define APBFSGDPROT_PBG_AH     (*(volatile unsigned short *)0xFFC4C042)
#define APBFSGDPROT_PBG_AHL    (*(volatile unsigned char  *)0xFFC4C042)
#define APBFSGDPROT_PBG_AHH    (*(volatile unsigned char  *)0xFFC4C043)
#define APBFSGDSPID_PBG_A      (*(volatile unsigned long  *)0xFFC4C044)
#define APBFSGDSPID_PBG_AL     (*(volatile unsigned short *)0xFFC4C044)
#define APBFSGDSPID_PBG_ALL    (*(volatile unsigned char  *)0xFFC4C044)
#define APBFSGDSPID_PBG_ALH    (*(volatile unsigned char  *)0xFFC4C045)
#define APBFSGDSPID_PBG_AH     (*(volatile unsigned short *)0xFFC4C046)
#define APBFSGDSPID_PBG_AHL    (*(volatile unsigned char  *)0xFFC4C046)
#define APBFSGDSPID_PBG_AHH    (*(volatile unsigned char  *)0xFFC4C047)
#define APBFSGDPROT_PBG_B      (*(volatile unsigned long  *)0xFFC4C048)
#define APBFSGDPROT_PBG_BL     (*(volatile unsigned short *)0xFFC4C048)
#define APBFSGDPROT_PBG_BLL    (*(volatile unsigned char  *)0xFFC4C048)
#define APBFSGDPROT_PBG_BLH    (*(volatile unsigned char  *)0xFFC4C049)
#define APBFSGDPROT_PBG_BH     (*(volatile unsigned short *)0xFFC4C04A)
#define APBFSGDPROT_PBG_BHL    (*(volatile unsigned char  *)0xFFC4C04A)
#define APBFSGDPROT_PBG_BHH    (*(volatile unsigned char  *)0xFFC4C04B)
#define APBFSGDSPID_PBG_B      (*(volatile unsigned long  *)0xFFC4C04C)
#define APBFSGDSPID_PBG_BL     (*(volatile unsigned short *)0xFFC4C04C)
#define APBFSGDSPID_PBG_BLL    (*(volatile unsigned char  *)0xFFC4C04C)
#define APBFSGDSPID_PBG_BLH    (*(volatile unsigned char  *)0xFFC4C04D)
#define APBFSGDSPID_PBG_BH     (*(volatile unsigned short *)0xFFC4C04E)
#define APBFSGDSPID_PBG_BHL    (*(volatile unsigned char  *)0xFFC4C04E)
#define APBFSGDSPID_PBG_BHH    (*(volatile unsigned char  *)0xFFC4C04F)
#define APBFSGDPROT_SP1_A      (*(volatile unsigned long  *)0xFFC4C050)
#define APBFSGDPROT_SP1_AL     (*(volatile unsigned short *)0xFFC4C050)
#define APBFSGDPROT_SP1_ALL    (*(volatile unsigned char  *)0xFFC4C050)
#define APBFSGDPROT_SP1_ALH    (*(volatile unsigned char  *)0xFFC4C051)
#define APBFSGDPROT_SP1_AH     (*(volatile unsigned short *)0xFFC4C052)
#define APBFSGDPROT_SP1_AHL    (*(volatile unsigned char  *)0xFFC4C052)
#define APBFSGDPROT_SP1_AHH    (*(volatile unsigned char  *)0xFFC4C053)
#define APBFSGDSPID_SP1_A      (*(volatile unsigned long  *)0xFFC4C054)
#define APBFSGDSPID_SP1_AL     (*(volatile unsigned short *)0xFFC4C054)
#define APBFSGDSPID_SP1_ALL    (*(volatile unsigned char  *)0xFFC4C054)
#define APBFSGDSPID_SP1_ALH    (*(volatile unsigned char  *)0xFFC4C055)
#define APBFSGDSPID_SP1_AH     (*(volatile unsigned short *)0xFFC4C056)
#define APBFSGDSPID_SP1_AHL    (*(volatile unsigned char  *)0xFFC4C056)
#define APBFSGDSPID_SP1_AHH    (*(volatile unsigned char  *)0xFFC4C057)
#define APBFSGDPROT_SP1_B      (*(volatile unsigned long  *)0xFFC4C058)
#define APBFSGDPROT_SP1_BL     (*(volatile unsigned short *)0xFFC4C058)
#define APBFSGDPROT_SP1_BLL    (*(volatile unsigned char  *)0xFFC4C058)
#define APBFSGDPROT_SP1_BLH    (*(volatile unsigned char  *)0xFFC4C059)
#define APBFSGDPROT_SP1_BH     (*(volatile unsigned short *)0xFFC4C05A)
#define APBFSGDPROT_SP1_BHL    (*(volatile unsigned char  *)0xFFC4C05A)
#define APBFSGDPROT_SP1_BHH    (*(volatile unsigned char  *)0xFFC4C05B)
#define APBFSGDSPID_SP1_B      (*(volatile unsigned long  *)0xFFC4C05C)
#define APBFSGDSPID_SP1_BL     (*(volatile unsigned short *)0xFFC4C05C)
#define APBFSGDSPID_SP1_BLL    (*(volatile unsigned char  *)0xFFC4C05C)
#define APBFSGDSPID_SP1_BLH    (*(volatile unsigned char  *)0xFFC4C05D)
#define APBFSGDSPID_SP1_BH     (*(volatile unsigned short *)0xFFC4C05E)
#define APBFSGDSPID_SP1_BHL    (*(volatile unsigned char  *)0xFFC4C05E)
#define APBFSGDSPID_SP1_BHH    (*(volatile unsigned char  *)0xFFC4C05F)
#define APBFSGDPROT_SP4_A      (*(volatile unsigned long  *)0xFFC4C070)
#define APBFSGDPROT_SP4_AL     (*(volatile unsigned short *)0xFFC4C070)
#define APBFSGDPROT_SP4_ALL    (*(volatile unsigned char  *)0xFFC4C070)
#define APBFSGDPROT_SP4_ALH    (*(volatile unsigned char  *)0xFFC4C071)
#define APBFSGDPROT_SP4_AH     (*(volatile unsigned short *)0xFFC4C072)
#define APBFSGDPROT_SP4_AHL    (*(volatile unsigned char  *)0xFFC4C072)
#define APBFSGDPROT_SP4_AHH    (*(volatile unsigned char  *)0xFFC4C073)
#define APBFSGDSPID_SP4_A      (*(volatile unsigned long  *)0xFFC4C074)
#define APBFSGDSPID_SP4_AL     (*(volatile unsigned short *)0xFFC4C074)
#define APBFSGDSPID_SP4_ALL    (*(volatile unsigned char  *)0xFFC4C074)
#define APBFSGDSPID_SP4_ALH    (*(volatile unsigned char  *)0xFFC4C075)
#define APBFSGDSPID_SP4_AH     (*(volatile unsigned short *)0xFFC4C076)
#define APBFSGDSPID_SP4_AHL    (*(volatile unsigned char  *)0xFFC4C076)
#define APBFSGDSPID_SP4_AHH    (*(volatile unsigned char  *)0xFFC4C077)
#define APBFSGDPROT_SP4_B      (*(volatile unsigned long  *)0xFFC4C078)
#define APBFSGDPROT_SP4_BL     (*(volatile unsigned short *)0xFFC4C078)
#define APBFSGDPROT_SP4_BLL    (*(volatile unsigned char  *)0xFFC4C078)
#define APBFSGDPROT_SP4_BLH    (*(volatile unsigned char  *)0xFFC4C079)
#define APBFSGDPROT_SP4_BH     (*(volatile unsigned short *)0xFFC4C07A)
#define APBFSGDPROT_SP4_BHL    (*(volatile unsigned char  *)0xFFC4C07A)
#define APBFSGDPROT_SP4_BHH    (*(volatile unsigned char  *)0xFFC4C07B)
#define APBFSGDSPID_SP4_B      (*(volatile unsigned long  *)0xFFC4C07C)
#define APBFSGDSPID_SP4_BL     (*(volatile unsigned short *)0xFFC4C07C)
#define APBFSGDSPID_SP4_BLL    (*(volatile unsigned char  *)0xFFC4C07C)
#define APBFSGDSPID_SP4_BLH    (*(volatile unsigned char  *)0xFFC4C07D)
#define APBFSGDSPID_SP4_BH     (*(volatile unsigned short *)0xFFC4C07E)
#define APBFSGDSPID_SP4_BHL    (*(volatile unsigned char  *)0xFFC4C07E)
#define APBFSGDSPID_SP4_BHH    (*(volatile unsigned char  *)0xFFC4C07F)
#define ERRSLVCTL_PFSS0        (*(volatile unsigned long  *)0xFFC4C800)
#define ERRSLVSTAT_PFSS0       (*(volatile unsigned long  *)0xFFC4C804)
#define ERRSLVTYPE_PFSS0       (*(volatile unsigned long  *)0xFFC4C80C)
#define ERRSLVCTL_PFSS1        (*(volatile unsigned long  *)0xFFC4C810)
#define ERRSLVSTAT_PFSS1       (*(volatile unsigned long  *)0xFFC4C814)
#define ERRSLVTYPE_PFSS1       (*(volatile unsigned long  *)0xFFC4C81C)
#define ERRSLVCTL_PBAREA       (*(volatile unsigned long  *)0xFFC4C880)
#define ERRSLVCTL_PBAREAL      (*(volatile unsigned short *)0xFFC4C880)
#define ERRSLVCTL_PBAREALL     (*(volatile unsigned char  *)0xFFC4C880)
#define ERRSLVSTAT_PBAREA      (*(volatile unsigned long  *)0xFFC4C884)
#define ERRSLVSTAT_PBAREAL     (*(volatile unsigned short *)0xFFC4C884)
#define ERRSLVSTAT_PBAREALL    (*(volatile unsigned char  *)0xFFC4C884)
#define ERRSLVTYPE_PBAREA      (*(volatile unsigned long  *)0xFFC4C88C)
#define ERRSLVTYPE_PBAREAL     (*(volatile unsigned short *)0xFFC4C88C)
#define ERRSLVTYPE_PBAREAH     (*(volatile unsigned short *)0xFFC4C88E)
#define PDMA_COMP_CNTRL        (*(volatile unsigned long  *)0xFFC4CA00)
#define BOOTCTRL               (*(volatile unsigned long  *)0xFFC58000)
#define BOOTCTRLL              (*(volatile unsigned short *)0xFFC58000)
#define BOOTCTRLLL             (*(volatile unsigned char  *)0xFFC58000)
#define EPC                    (*(volatile unsigned long  *)0xFFC58020)
#define FCUFAREA               (*(volatile unsigned char  *)0xFFC59008)
#define EEPRDCYCL0             (*(volatile unsigned char  *)0xFFC59810)
#define EEPRDCYCL1             (*(volatile unsigned char  *)0xFFC59910)
#define DFECCCTL0              (*(volatile unsigned long  *)0xFFC5B000)
#define DFECCCTL0L             (*(volatile unsigned short *)0xFFC5B000)
#define DFERSTR0               (*(volatile unsigned long  *)0xFFC5B004)
#define DFERSTC0               (*(volatile unsigned long  *)0xFFC5B008)
#define DFERSTC0L              (*(volatile unsigned short *)0xFFC5B008)
#define DFERSTC0LL             (*(volatile unsigned char  *)0xFFC5B008)
#define DFOVFSTR0              (*(volatile unsigned long  *)0xFFC5B00C)
#define DFOVFSTC0              (*(volatile unsigned long  *)0xFFC5B010)
#define DFOVFSTC0L             (*(volatile unsigned short *)0xFFC5B010)
#define DFOVFSTC0LL            (*(volatile unsigned char  *)0xFFC5B010)
#define DFERRINT0              (*(volatile unsigned long  *)0xFFC5B014)
#define DFERRINT0L             (*(volatile unsigned short *)0xFFC5B014)
#define DFERRINT0LL            (*(volatile unsigned char  *)0xFFC5B014)
#define DFEADR0                (*(volatile unsigned long  *)0xFFC5B018)
#define DFTSTCTL0              (*(volatile unsigned long  *)0xFFC5B01C)
#define DFTSTCTL0L             (*(volatile unsigned short *)0xFFC5B01C)
#define DFECCCTL1              (*(volatile unsigned long  *)0xFFC5C000)
#define DFECCCTL1L             (*(volatile unsigned short *)0xFFC5C000)
#define DFERSTR1               (*(volatile unsigned long  *)0xFFC5C004)
#define DFERSTC1               (*(volatile unsigned long  *)0xFFC5C008)
#define DFERSTC1L              (*(volatile unsigned short *)0xFFC5C008)
#define DFERSTC1LL             (*(volatile unsigned char  *)0xFFC5C008)
#define DFOVFSTR1              (*(volatile unsigned long  *)0xFFC5C00C)
#define DFOVFSTC1              (*(volatile unsigned long  *)0xFFC5C010)
#define DFOVFSTC1L             (*(volatile unsigned short *)0xFFC5C010)
#define DFOVFSTC1LL            (*(volatile unsigned char  *)0xFFC5C010)
#define DFERRINT1              (*(volatile unsigned long  *)0xFFC5C014)
#define DFERRINT1L             (*(volatile unsigned short *)0xFFC5C014)
#define DFERRINT1LL            (*(volatile unsigned char  *)0xFFC5C014)
#define DFEADR1                (*(volatile unsigned long  *)0xFFC5C018)
#define DFTSTCTL1              (*(volatile unsigned long  *)0xFFC5C01C)
#define DFTSTCTL1L             (*(volatile unsigned short *)0xFFC5C01C)
#define IDECCCTL_PE1           (*(volatile unsigned long  *)0xFFC60400)
#define IDECCCTL_PE1L          (*(volatile unsigned short *)0xFFC60400)
#define IDERRINT_PE1           (*(volatile unsigned long  *)0xFFC60404)
#define IDERRINT_PE1L          (*(volatile unsigned short *)0xFFC60404)
#define IDERRINT_PE1LL         (*(volatile unsigned char  *)0xFFC60404)
#define IDSERSTCLR_PE1         (*(volatile unsigned long  *)0xFFC60408)
#define IDSERSTCLR_PE1L        (*(volatile unsigned short *)0xFFC60408)
#define IDSERSTCLR_PE1LL       (*(volatile unsigned char  *)0xFFC60408)
#define IDDERSTCLR_PE1         (*(volatile unsigned long  *)0xFFC6040C)
#define IDDERSTCLR_PE1L        (*(volatile unsigned short *)0xFFC6040C)
#define IDDERSTCLR_PE1LL       (*(volatile unsigned char  *)0xFFC6040C)
#define IDOVFSTR_PE1           (*(volatile unsigned long  *)0xFFC60410)
#define IDOVFSTR_PE1L          (*(volatile unsigned short *)0xFFC60410)
#define IDOVFSTR_PE1LL         (*(volatile unsigned char  *)0xFFC60410)
#define IDSERSTR_PE1           (*(volatile unsigned long  *)0xFFC60420)
#define IDSERSTR_PE1L          (*(volatile unsigned short *)0xFFC60420)
#define IDSERSTR_PE1LL         (*(volatile unsigned char  *)0xFFC60420)
#define IDSERSTR_PE1LH         (*(volatile unsigned char  *)0xFFC60421)
#define IDDERSTR_PE1           (*(volatile unsigned long  *)0xFFC60450)
#define IDDERSTR_PE1L          (*(volatile unsigned short *)0xFFC60450)
#define IDDERSTR_PE1LL         (*(volatile unsigned char  *)0xFFC60450)
#define IDDERSTR_PE1LH         (*(volatile unsigned char  *)0xFFC60451)
#define IDSEDADR0_PE1          (*(volatile unsigned long  *)0xFFC60460)
#define IDSEDADR1_PE1          (*(volatile unsigned long  *)0xFFC60464)
#define IDDEDADR0_PE1          (*(volatile unsigned long  *)0xFFC604E0)
#define IDDEDADR1_PE1          (*(volatile unsigned long  *)0xFFC604E4)
#define ITECCCTL_PE1           (*(volatile unsigned long  *)0xFFC61400)
#define ITECCCTL_PE1L          (*(volatile unsigned short *)0xFFC61400)
#define ITERRINT_PE1           (*(volatile unsigned long  *)0xFFC61404)
#define ITERRINT_PE1L          (*(volatile unsigned short *)0xFFC61404)
#define ITERRINT_PE1LL         (*(volatile unsigned char  *)0xFFC61404)
#define ITSERSTCLR_PE1         (*(volatile unsigned long  *)0xFFC61408)
#define ITSERSTCLR_PE1L        (*(volatile unsigned short *)0xFFC61408)
#define ITSERSTCLR_PE1LL       (*(volatile unsigned char  *)0xFFC61408)
#define ITDERSTCLR_PE1         (*(volatile unsigned long  *)0xFFC6140C)
#define ITDERSTCLR_PE1L        (*(volatile unsigned short *)0xFFC6140C)
#define ITDERSTCLR_PE1LL       (*(volatile unsigned char  *)0xFFC6140C)
#define ITOVFSTR_PE1           (*(volatile unsigned long  *)0xFFC61410)
#define ITOVFSTR_PE1L          (*(volatile unsigned short *)0xFFC61410)
#define ITOVFSTR_PE1LL         (*(volatile unsigned char  *)0xFFC61410)
#define ITSERSTR_PE1           (*(volatile unsigned long  *)0xFFC61420)
#define ITSERSTR_PE1L          (*(volatile unsigned short *)0xFFC61420)
#define ITSERSTR_PE1LL         (*(volatile unsigned char  *)0xFFC61420)
#define ITDERSTR_PE1           (*(volatile unsigned long  *)0xFFC61450)
#define ITDERSTR_PE1L          (*(volatile unsigned short *)0xFFC61450)
#define ITDERSTR_PE1LL         (*(volatile unsigned char  *)0xFFC61450)
#define ITSEDADR_PE1           (*(volatile unsigned long  *)0xFFC61460)
#define ITDEDADR_PE1           (*(volatile unsigned long  *)0xFFC614E0)
#define UCFERRINT              (*(volatile unsigned long  *)0xFFC62000)
#define UCFERRINTL             (*(volatile unsigned short *)0xFFC62000)
#define UCFERRINTLL            (*(volatile unsigned char  *)0xFFC62000)
#define UCFSERSTCLR            (*(volatile unsigned long  *)0xFFC62004)
#define UCFSERSTCLRL           (*(volatile unsigned short *)0xFFC62004)
#define UCFSERSTCLRLL          (*(volatile unsigned char  *)0xFFC62004)
#define UCFDERSTCLR            (*(volatile unsigned long  *)0xFFC62008)
#define UCFDERSTCLRL           (*(volatile unsigned short *)0xFFC62008)
#define UCFDERSTCLRLL          (*(volatile unsigned char  *)0xFFC62008)
#define UCFOVFSTR              (*(volatile unsigned long  *)0xFFC6200C)
#define UCFOVFSTRL             (*(volatile unsigned short *)0xFFC6200C)
#define UCFOVFSTRLL            (*(volatile unsigned char  *)0xFFC6200C)
#define UCFSERSTR              (*(volatile unsigned long  *)0xFFC62020)
#define UCFSERSTRL             (*(volatile unsigned short *)0xFFC62020)
#define UCFSERSTRLL            (*(volatile unsigned char  *)0xFFC62020)
#define UCFDERSTR              (*(volatile unsigned long  *)0xFFC62030)
#define UCFDERSTRL             (*(volatile unsigned short *)0xFFC62030)
#define UCFDERSTRLL            (*(volatile unsigned char  *)0xFFC62030)
#define UCF1SEDADR             (*(volatile unsigned long  *)0xFFC62040)
#define UCF2SEDADR             (*(volatile unsigned long  *)0xFFC62044)
#define UCF3SEDADR             (*(volatile unsigned long  *)0xFFC62048)
#define UCF4SEDADR             (*(volatile unsigned long  *)0xFFC6204C)
#define UCFDEDADR              (*(volatile unsigned long  *)0xFFC620C0)
#define CFAPCTL                (*(volatile unsigned long  *)0xFFC62100)
#define CFAPCTLL               (*(volatile unsigned short *)0xFFC62100)
#define CFECCCTL_VCI2CFBA      (*(volatile unsigned long  *)0xFFC62200)
#define CFECCCTL_VCI2CFBAL     (*(volatile unsigned short *)0xFFC62200)
#define CFSTSTCTL_VCI2CFBA     (*(volatile unsigned long  *)0xFFC622F0)
#define CFSTSTCTL_VCI2CFBAL    (*(volatile unsigned short *)0xFFC622F0)
#define CFECCCTL_PE1           (*(volatile unsigned long  *)0xFFC62400)
#define CFECCCTL_PE1L          (*(volatile unsigned short *)0xFFC62400)
#define CFSTSTCTL_PE1          (*(volatile unsigned long  *)0xFFC624F0)
#define CFSTSTCTL_PE1L         (*(volatile unsigned short *)0xFFC624F0)
#define CFECCCTL_VCI2CFBB      (*(volatile unsigned long  *)0xFFC62C00)
#define CFECCCTL_VCI2CFBBL     (*(volatile unsigned short *)0xFFC62C02)
#define CFERRINT_VCI2CFBB      (*(volatile unsigned long  *)0xFFC62C04)
#define CFERRINT_VCI2CFBBL     (*(volatile unsigned short *)0xFFC62C04)
#define CFERRINT_VCI2CFBBLL    (*(volatile unsigned char  *)0xFFC62C04)
#define CFERSTCLR_VCI2CFBB     (*(volatile unsigned long  *)0xFFC62C08)
#define CFERSTCLR_VCI2CFBBL    (*(volatile unsigned short *)0xFFC62C08)
#define CFERSTCLR_VCI2CFBBLL   (*(volatile unsigned char  *)0xFFC62C08)
#define CFOVFSTR_VCI2CFBB      (*(volatile unsigned long  *)0xFFC62C0C)
#define CFOVFSTR_VCI2CFBBL     (*(volatile unsigned short *)0xFFC62C0C)
#define CFOVFSTR_VCI2CFBBLL    (*(volatile unsigned char  *)0xFFC62C0C)
#define CFERSTR_VCI2CFBB       (*(volatile unsigned long  *)0xFFC62C10)
#define CFERSTR_VCI2CFBBL      (*(volatile unsigned short *)0xFFC62C10)
#define CFERSTR_VCI2CFBBLL     (*(volatile unsigned char  *)0xFFC62C10)
#define CFEADR0_VCI2CFBB       (*(volatile unsigned long  *)0xFFC62C50)
#define IFECCCTL_PE1           (*(volatile unsigned long  *)0xFFC63400)
#define IFECCCTL_PE1L          (*(volatile unsigned short *)0xFFC63402)
#define IFERRINT_PE1           (*(volatile unsigned long  *)0xFFC63404)
#define IFERRINT_PE1L          (*(volatile unsigned short *)0xFFC63404)
#define IFERRINT_PE1LL         (*(volatile unsigned char  *)0xFFC63404)
#define IFERSTCLR_PE1          (*(volatile unsigned long  *)0xFFC63408)
#define IFERSTCLR_PE1L         (*(volatile unsigned short *)0xFFC63408)
#define IFERSTCLR_PE1LL        (*(volatile unsigned char  *)0xFFC63408)
#define IFOVFSTR_PE1           (*(volatile unsigned long  *)0xFFC6340C)
#define IFOVFSTR_PE1L          (*(volatile unsigned short *)0xFFC6340C)
#define IFOVFSTR_PE1LL         (*(volatile unsigned char  *)0xFFC6340C)
#define IFERSTR_PE1            (*(volatile unsigned long  *)0xFFC63410)
#define IFERSTR_PE1L           (*(volatile unsigned short *)0xFFC63410)
#define IFERSTR_PE1LL          (*(volatile unsigned char  *)0xFFC63410)
#define IFERADR_PE1            (*(volatile unsigned long  *)0xFFC63450)
#define UGRERRINT              (*(volatile unsigned long  *)0xFFC64000)
#define UGRERRINTL             (*(volatile unsigned short *)0xFFC64000)
#define UGRERRINTLL            (*(volatile unsigned char  *)0xFFC64000)
#define UGRSERSTCLR            (*(volatile unsigned long  *)0xFFC64004)
#define UGRSERSTCLRL           (*(volatile unsigned short *)0xFFC64004)
#define UGRSERSTCLRLL          (*(volatile unsigned char  *)0xFFC64004)
#define UGRSERSTCLRLH          (*(volatile unsigned char  *)0xFFC64005)
#define UGRSERSTCLRH           (*(volatile unsigned short *)0xFFC64006)
#define UGRSERSTCLRHL          (*(volatile unsigned char  *)0xFFC64006)
#define UGRSERSTCLRHH          (*(volatile unsigned char  *)0xFFC64007)
#define UGRDERSTCLR            (*(volatile unsigned long  *)0xFFC64008)
#define UGRDERSTCLRL           (*(volatile unsigned short *)0xFFC64008)
#define UGRDERSTCLRLL          (*(volatile unsigned char  *)0xFFC64008)
#define UGROVFSTR              (*(volatile unsigned long  *)0xFFC6400C)
#define UGROVFSTRL             (*(volatile unsigned short *)0xFFC6400C)
#define UGROVFSTRLL            (*(volatile unsigned char  *)0xFFC6400C)
#define UGRSERSTR              (*(volatile unsigned long  *)0xFFC64020)
#define UGRSERSTRL             (*(volatile unsigned short *)0xFFC64020)
#define UGRSERSTRLL            (*(volatile unsigned char  *)0xFFC64020)
#define UGRSERSTRLH            (*(volatile unsigned char  *)0xFFC64021)
#define UGRSERSTRH             (*(volatile unsigned short *)0xFFC64022)
#define UGRSERSTRHL            (*(volatile unsigned char  *)0xFFC64022)
#define UGRSERSTRHH            (*(volatile unsigned char  *)0xFFC64023)
#define UGRDERSTR              (*(volatile unsigned long  *)0xFFC64030)
#define UGRDERSTRL             (*(volatile unsigned short *)0xFFC64030)
#define UGRDERSTRLL            (*(volatile unsigned char  *)0xFFC64030)
#define UGR1SEDADR             (*(volatile unsigned long  *)0xFFC64040)
#define UGR2SEDADR             (*(volatile unsigned long  *)0xFFC64044)
#define UGR3SEDADR             (*(volatile unsigned long  *)0xFFC64048)
#define UGR4SEDADR             (*(volatile unsigned long  *)0xFFC6404C)
#define UGR5SEDADR             (*(volatile unsigned long  *)0xFFC64050)
#define UGR6SEDADR             (*(volatile unsigned long  *)0xFFC64054)
#define UGR7SEDADR             (*(volatile unsigned long  *)0xFFC64058)
#define UGR8SEDADR             (*(volatile unsigned long  *)0xFFC6405C)
#define UGR9SEDADR             (*(volatile unsigned long  *)0xFFC64060)
#define UGR10SEDADR            (*(volatile unsigned long  *)0xFFC64064)
#define UGR11SEDADR            (*(volatile unsigned long  *)0xFFC64068)
#define UGR12SEDADR            (*(volatile unsigned long  *)0xFFC6406C)
#define UGR13SEDADR            (*(volatile unsigned long  *)0xFFC64070)
#define UGR14SEDADR            (*(volatile unsigned long  *)0xFFC64074)
#define UGR15SEDADR            (*(volatile unsigned long  *)0xFFC64078)
#define UGR16SEDADR            (*(volatile unsigned long  *)0xFFC6407C)
#define UGR17SEDADR            (*(volatile unsigned long  *)0xFFC64080)
#define UGR18SEDADR            (*(volatile unsigned long  *)0xFFC64084)
#define UGR19SEDADR            (*(volatile unsigned long  *)0xFFC64088)
#define UGR20SEDADR            (*(volatile unsigned long  *)0xFFC6408C)
#define UGR21SEDADR            (*(volatile unsigned long  *)0xFFC64090)
#define UGR22SEDADR            (*(volatile unsigned long  *)0xFFC64094)
#define UGR23SEDADR            (*(volatile unsigned long  *)0xFFC64098)
#define UGR24SEDADR            (*(volatile unsigned long  *)0xFFC6409C)
#define UGR25SEDADR            (*(volatile unsigned long  *)0xFFC640A0)
#define UGR26SEDADR            (*(volatile unsigned long  *)0xFFC640A4)
#define UGR27SEDADR            (*(volatile unsigned long  *)0xFFC640A8)
#define UGR28SEDADR            (*(volatile unsigned long  *)0xFFC640AC)
#define UGR29SEDADR            (*(volatile unsigned long  *)0xFFC640B0)
#define UGR30SEDADR            (*(volatile unsigned long  *)0xFFC640B4)
#define UGR31SEDADR            (*(volatile unsigned long  *)0xFFC640B8)
#define UGR32SEDADR            (*(volatile unsigned long  *)0xFFC640BC)
#define UGR00DEDADR            (*(volatile unsigned long  *)0xFFC640C0)
#define GRECCCTL_GRAMC         (*(volatile unsigned long  *)0xFFC64100)
#define GRECCCTL_GRAMCL        (*(volatile unsigned short *)0xFFC64100)
#define GRTSTCTL               (*(volatile unsigned long  *)0xFFC64104)
#define GRTSTCTLL              (*(volatile unsigned short *)0xFFC64104)
#define GRTDATBF0L             (*(volatile unsigned long  *)0xFFC64108)
#define GRTDATBF0LL            (*(volatile unsigned short *)0xFFC64108)
#define GRTDATBF0LLL           (*(volatile unsigned char  *)0xFFC64108)
#define GRTDATBF0LLH           (*(volatile unsigned char  *)0xFFC64109)
#define GRTDATBF0LH            (*(volatile unsigned short *)0xFFC6410A)
#define GRTDATBF0LHL           (*(volatile unsigned char  *)0xFFC6410A)
#define GRTDATBF0LHH           (*(volatile unsigned char  *)0xFFC6410B)
#define GRTDATBF0H             (*(volatile unsigned long  *)0xFFC6410C)
#define GRTDATBF0HL            (*(volatile unsigned short *)0xFFC6410C)
#define GRTDATBF0HLL           (*(volatile unsigned char  *)0xFFC6410C)
#define GRTDATBF0HLH           (*(volatile unsigned char  *)0xFFC6410D)
#define GRTDATBF0HH            (*(volatile unsigned short *)0xFFC6410E)
#define GRTDATBF0HHL           (*(volatile unsigned char  *)0xFFC6410E)
#define GRTDATBF0HHH           (*(volatile unsigned char  *)0xFFC6410F)
#define GRTDATBF1L             (*(volatile unsigned long  *)0xFFC64110)
#define GRTDATBF1LL            (*(volatile unsigned short *)0xFFC64110)
#define GRTDATBF1LLL           (*(volatile unsigned char  *)0xFFC64110)
#define GRTDATBF1LLH           (*(volatile unsigned char  *)0xFFC64111)
#define GRTDATBF1LH            (*(volatile unsigned short *)0xFFC64112)
#define GRTDATBF1LHL           (*(volatile unsigned char  *)0xFFC64112)
#define GRTDATBF1LHH           (*(volatile unsigned char  *)0xFFC64113)
#define GRTDATBF1H             (*(volatile unsigned long  *)0xFFC64114)
#define GRTDATBF1HL            (*(volatile unsigned short *)0xFFC64114)
#define GRTDATBF1HLL           (*(volatile unsigned char  *)0xFFC64114)
#define GRTDATBF1HLH           (*(volatile unsigned char  *)0xFFC64115)
#define GRTDATBF1HH            (*(volatile unsigned short *)0xFFC64116)
#define GRTDATBF1HHL           (*(volatile unsigned char  *)0xFFC64116)
#define GRTDATBF1HHH           (*(volatile unsigned char  *)0xFFC64117)
#define GRDECINBF0             (*(volatile unsigned long  *)0xFFC64118)
#define GRDECINBF0L            (*(volatile unsigned short *)0xFFC64118)
#define GRDECINBF0LL           (*(volatile unsigned char  *)0xFFC64118)
#define GRDECINBF0LH           (*(volatile unsigned char  *)0xFFC64119)
#define GRDECINBF0H            (*(volatile unsigned short *)0xFFC6411A)
#define GRDECINBF0HL           (*(volatile unsigned char  *)0xFFC6411A)
#define GRDECINBF0HH           (*(volatile unsigned char  *)0xFFC6411B)
#define GRDECINBF1             (*(volatile unsigned long  *)0xFFC6411C)
#define GRDECINBF1L            (*(volatile unsigned short *)0xFFC6411C)
#define GRDECINBF1LL           (*(volatile unsigned char  *)0xFFC6411C)
#define GRDECINBF1LH           (*(volatile unsigned char  *)0xFFC6411D)
#define GRDECINBF1H            (*(volatile unsigned short *)0xFFC6411E)
#define GRDECINBF1HL           (*(volatile unsigned char  *)0xFFC6411E)
#define GRDECINBF1HH           (*(volatile unsigned char  *)0xFFC6411F)
#define GRECCCTL_VCI2GRAM      (*(volatile unsigned long  *)0xFFC64200)
#define GRECCCTL_VCI2GRAML     (*(volatile unsigned short *)0xFFC64200)
#define GRECCCTL_PE1           (*(volatile unsigned long  *)0xFFC64400)
#define GRECCCTL_PE1L          (*(volatile unsigned short *)0xFFC64400)
#define GRECCCTL_AXI2GRAM      (*(volatile unsigned long  *)0xFFC64E00)
#define GRECCCTL_AXI2GRAML     (*(volatile unsigned short *)0xFFC64E00)
#define LRECCCTL_PE1           (*(volatile unsigned long  *)0xFFC65400)
#define LRECCCTL_PE1L          (*(volatile unsigned short *)0xFFC65400)
#define LRERRINT_PE1           (*(volatile unsigned long  *)0xFFC65404)
#define LRERRINT_PE1L          (*(volatile unsigned short *)0xFFC65404)
#define LRERRINT_PE1LL         (*(volatile unsigned char  *)0xFFC65404)
#define LRSERSTCLR_PE1         (*(volatile unsigned long  *)0xFFC65408)
#define LRSERSTCLR_PE1L        (*(volatile unsigned short *)0xFFC65408)
#define LRSERSTCLR_PE1LL       (*(volatile unsigned char  *)0xFFC65408)
#define LRSERSTCLR_PE1LH       (*(volatile unsigned char  *)0xFFC65409)
#define LRSERSTCLR_PE1H        (*(volatile unsigned short *)0xFFC6540A)
#define LRSERSTCLR_PE1HL       (*(volatile unsigned char  *)0xFFC6540A)
#define LRSERSTCLR_PE1HH       (*(volatile unsigned char  *)0xFFC6540B)
#define LRDERSTCLR_PE1         (*(volatile unsigned long  *)0xFFC6540C)
#define LRDERSTCLR_PE1L        (*(volatile unsigned short *)0xFFC6540C)
#define LRDERSTCLR_PE1LL       (*(volatile unsigned char  *)0xFFC6540C)
#define LROVFSTR_PE1           (*(volatile unsigned long  *)0xFFC65410)
#define LROVFSTR_PE1L          (*(volatile unsigned short *)0xFFC65410)
#define LROVFSTR_PE1LL         (*(volatile unsigned char  *)0xFFC65410)
#define LRSERSTR_PE1           (*(volatile unsigned long  *)0xFFC65440)
#define LRSERSTR_PE1L          (*(volatile unsigned short *)0xFFC65440)
#define LRSERSTR_PE1LL         (*(volatile unsigned char  *)0xFFC65440)
#define LRSERSTR_PE1LH         (*(volatile unsigned char  *)0xFFC65441)
#define LRSERSTR_PE1H          (*(volatile unsigned short *)0xFFC65442)
#define LRSERSTR_PE1HL         (*(volatile unsigned char  *)0xFFC65442)
#define LRSERSTR_PE1HH         (*(volatile unsigned char  *)0xFFC65443)
#define LRDERSTR_PE1           (*(volatile unsigned long  *)0xFFC65450)
#define LRDERSTR_PE1L          (*(volatile unsigned short *)0xFFC65450)
#define LRDERSTR_PE1LL         (*(volatile unsigned char  *)0xFFC65450)
#define LRDERSTR_PE1LH         (*(volatile unsigned char  *)0xFFC65451)
#define LRDERSTR_PE1H          (*(volatile unsigned short *)0xFFC65452)
#define LRDERSTR_PE1HL         (*(volatile unsigned char  *)0xFFC65452)
#define LRDERSTR_PE1HH         (*(volatile unsigned char  *)0xFFC65453)
#define LR1SEDADR0_PE1         (*(volatile unsigned long  *)0xFFC65460)
#define LR1SEDADR1_PE1         (*(volatile unsigned long  *)0xFFC65464)
#define LR1SEDADR2_PE1         (*(volatile unsigned long  *)0xFFC65468)
#define LR1SEDADR3_PE1         (*(volatile unsigned long  *)0xFFC6546C)
#define LR2SEDADR0_PE1         (*(volatile unsigned long  *)0xFFC65470)
#define LR2SEDADR1_PE1         (*(volatile unsigned long  *)0xFFC65474)
#define LR2SEDADR2_PE1         (*(volatile unsigned long  *)0xFFC65478)
#define LR2SEDADR3_PE1         (*(volatile unsigned long  *)0xFFC6547C)
#define LR3SEDADR0_PE1         (*(volatile unsigned long  *)0xFFC65480)
#define LR3SEDADR1_PE1         (*(volatile unsigned long  *)0xFFC65484)
#define LR3SEDADR2_PE1         (*(volatile unsigned long  *)0xFFC65488)
#define LR3SEDADR3_PE1         (*(volatile unsigned long  *)0xFFC6548C)
#define LR4SEDADR0_PE1         (*(volatile unsigned long  *)0xFFC65490)
#define LR4SEDADR1_PE1         (*(volatile unsigned long  *)0xFFC65494)
#define LR4SEDADR2_PE1         (*(volatile unsigned long  *)0xFFC65498)
#define LR4SEDADR3_PE1         (*(volatile unsigned long  *)0xFFC6549C)
#define LR5SEDADR0_PE1         (*(volatile unsigned long  *)0xFFC654A0)
#define LR5SEDADR1_PE1         (*(volatile unsigned long  *)0xFFC654A4)
#define LR5SEDADR2_PE1         (*(volatile unsigned long  *)0xFFC654A8)
#define LR5SEDADR3_PE1         (*(volatile unsigned long  *)0xFFC654AC)
#define LR6SEDADR0_PE1         (*(volatile unsigned long  *)0xFFC654B0)
#define LR6SEDADR1_PE1         (*(volatile unsigned long  *)0xFFC654B4)
#define LR6SEDADR2_PE1         (*(volatile unsigned long  *)0xFFC654B8)
#define LR6SEDADR3_PE1         (*(volatile unsigned long  *)0xFFC654BC)
#define LR7SEDADR0_PE1         (*(volatile unsigned long  *)0xFFC654C0)
#define LR7SEDADR1_PE1         (*(volatile unsigned long  *)0xFFC654C4)
#define LR7SEDADR2_PE1         (*(volatile unsigned long  *)0xFFC654C8)
#define LR7SEDADR3_PE1         (*(volatile unsigned long  *)0xFFC654CC)
#define LR8SEDADR0_PE1         (*(volatile unsigned long  *)0xFFC654D0)
#define LR8SEDADR1_PE1         (*(volatile unsigned long  *)0xFFC654D4)
#define LR8SEDADR2_PE1         (*(volatile unsigned long  *)0xFFC654D8)
#define LR8SEDADR3_PE1         (*(volatile unsigned long  *)0xFFC654DC)
#define LRDEDADR0_PE1          (*(volatile unsigned long  *)0xFFC654E0)
#define LRDEDADR1_PE1          (*(volatile unsigned long  *)0xFFC654E4)
#define LRDEDADR2_PE1          (*(volatile unsigned long  *)0xFFC654E8)
#define LRDEDADR3_PE1          (*(volatile unsigned long  *)0xFFC654EC)
#define LRTSTCTL_PE1           (*(volatile unsigned long  *)0xFFC65604)
#define LRTDATBF0_PE1          (*(volatile unsigned long  *)0xFFC65608)
#define LRTDATBF1_PE1          (*(volatile unsigned long  *)0xFFC6560C)
#define LSSECCCTL_PE1          (*(volatile unsigned long  *)0xFFC66000)
#define LSSECCCTL_PE1L         (*(volatile unsigned short *)0xFFC66000)
#define LSSERRINT_PE1          (*(volatile unsigned long  *)0xFFC66004)
#define LSSERRINT_PE1L         (*(volatile unsigned short *)0xFFC66004)
#define LSSERRINT_PE1LL        (*(volatile unsigned char  *)0xFFC66004)
#define LSSERSTCLR_PE1         (*(volatile unsigned long  *)0xFFC66008)
#define LSSERSTCLR_PE1L        (*(volatile unsigned short *)0xFFC66008)
#define LSSERSTCLR_PE1LL       (*(volatile unsigned char  *)0xFFC66008)
#define LSSOVFSTR_PE1          (*(volatile unsigned long  *)0xFFC6600C)
#define LSSOVFSTR_PE1L         (*(volatile unsigned short *)0xFFC6600C)
#define LSSOVFSTR_PE1LL        (*(volatile unsigned char  *)0xFFC6600C)
#define LSSERSTR_PE1           (*(volatile unsigned long  *)0xFFC66010)
#define LSSERSTR_PE1L          (*(volatile unsigned short *)0xFFC66010)
#define LSSERSTR_PE1LL         (*(volatile unsigned char  *)0xFFC66010)
#define LSSEADR_PE1            (*(volatile unsigned long  *)0xFFC66050)
#define LSMECCCTL_PE1          (*(volatile unsigned long  *)0xFFC66400)
#define LSMECCCTL_PE1L         (*(volatile unsigned short *)0xFFC66400)
#define LSMERRINT_PE1          (*(volatile unsigned long  *)0xFFC66404)
#define LSMERRINT_PE1L         (*(volatile unsigned short *)0xFFC66404)
#define LSMERRINT_PE1LL        (*(volatile unsigned char  *)0xFFC66404)
#define LSMERSTCLR_PE1         (*(volatile unsigned long  *)0xFFC66408)
#define LSMERSTCLR_PE1L        (*(volatile unsigned short *)0xFFC66408)
#define LSMERSTCLR_PE1LL       (*(volatile unsigned char  *)0xFFC66408)
#define LSMOVFSTR_PE1          (*(volatile unsigned long  *)0xFFC6640C)
#define LSMOVFSTR_PE1L         (*(volatile unsigned short *)0xFFC6640C)
#define LSMOVFSTR_PE1LL        (*(volatile unsigned char  *)0xFFC6640C)
#define LSMERSTR_PE1           (*(volatile unsigned long  *)0xFFC66410)
#define LSMERSTR_PE1L          (*(volatile unsigned short *)0xFFC66410)
#define LSMERSTR_PE1LL         (*(volatile unsigned char  *)0xFFC66410)
#define LSMEADR_PE1            (*(volatile unsigned long  *)0xFFC66450)
#define VPECCCTL_SG0           (*(volatile unsigned long  *)0xFFC67000)
#define VPECCCTL_SG0L          (*(volatile unsigned short *)0xFFC67000)
#define VPERRINT_SG0           (*(volatile unsigned long  *)0xFFC67004)
#define VPERRINT_SG0L          (*(volatile unsigned short *)0xFFC67004)
#define VPERRINT_SG0LL         (*(volatile unsigned char  *)0xFFC67004)
#define VPERSTCLR_SG0          (*(volatile unsigned long  *)0xFFC67008)
#define VPERSTCLR_SG0L         (*(volatile unsigned short *)0xFFC67008)
#define VPERSTCLR_SG0LL        (*(volatile unsigned char  *)0xFFC67008)
#define VPOVFSTR_SG0           (*(volatile unsigned long  *)0xFFC6700C)
#define VPOVFSTR_SG0L          (*(volatile unsigned short *)0xFFC6700C)
#define VPOVFSTR_SG0LL         (*(volatile unsigned char  *)0xFFC6700C)
#define VPERSTR_SG0            (*(volatile unsigned long  *)0xFFC67010)
#define VPERSTR_SG0L           (*(volatile unsigned short *)0xFFC67010)
#define VPERSTR_SG0LL          (*(volatile unsigned char  *)0xFFC67010)
#define VPEADR_SG0             (*(volatile unsigned long  *)0xFFC67050)
#define VPECCCTL_SG1           (*(volatile unsigned long  *)0xFFC67400)
#define VPECCCTL_SG1L          (*(volatile unsigned short *)0xFFC67400)
#define VPERRINT_SG1           (*(volatile unsigned long  *)0xFFC67404)
#define VPERRINT_SG1L          (*(volatile unsigned short *)0xFFC67404)
#define VPERRINT_SG1LL         (*(volatile unsigned char  *)0xFFC67404)
#define VPERSTCLR_SG1          (*(volatile unsigned long  *)0xFFC67408)
#define VPERSTCLR_SG1L         (*(volatile unsigned short *)0xFFC67408)
#define VPERSTCLR_SG1LL        (*(volatile unsigned char  *)0xFFC67408)
#define VPOVFSTR_SG1           (*(volatile unsigned long  *)0xFFC6740C)
#define VPOVFSTR_SG1L          (*(volatile unsigned short *)0xFFC6740C)
#define VPOVFSTR_SG1LL         (*(volatile unsigned char  *)0xFFC6740C)
#define VPERSTR_SG1            (*(volatile unsigned long  *)0xFFC67410)
#define VPERSTR_SG1L           (*(volatile unsigned short *)0xFFC67410)
#define VPERSTR_SG1LL          (*(volatile unsigned char  *)0xFFC67410)
#define VPEADR_SG1             (*(volatile unsigned long  *)0xFFC67450)
#define VPECCCTL_SG2           (*(volatile unsigned long  *)0xFFC67800)
#define VPECCCTL_SG2L          (*(volatile unsigned short *)0xFFC67800)
#define VPERRINT_SG2           (*(volatile unsigned long  *)0xFFC67804)
#define VPERRINT_SG2L          (*(volatile unsigned short *)0xFFC67804)
#define VPERRINT_SG2LL         (*(volatile unsigned char  *)0xFFC67804)
#define VPERSTCLR_SG2          (*(volatile unsigned long  *)0xFFC67808)
#define VPERSTCLR_SG2L         (*(volatile unsigned short *)0xFFC67808)
#define VPERSTCLR_SG2LL        (*(volatile unsigned char  *)0xFFC67808)
#define VPOVFSTR_SG2           (*(volatile unsigned long  *)0xFFC6780C)
#define VPOVFSTR_SG2L          (*(volatile unsigned short *)0xFFC6780C)
#define VPOVFSTR_SG2LL         (*(volatile unsigned char  *)0xFFC6780C)
#define VPERSTR_SG2            (*(volatile unsigned long  *)0xFFC67810)
#define VPERSTR_SG2L           (*(volatile unsigned short *)0xFFC67810)
#define VPERSTR_SG2LL          (*(volatile unsigned char  *)0xFFC67810)
#define VPEADR_SG2             (*(volatile unsigned long  *)0xFFC67850)
#define VPECCCTL_SG3           (*(volatile unsigned long  *)0xFFC67C00)
#define VPECCCTL_SG3L          (*(volatile unsigned short *)0xFFC67C00)
#define VPERRINT_SG3           (*(volatile unsigned long  *)0xFFC67C04)
#define VPERRINT_SG3L          (*(volatile unsigned short *)0xFFC67C04)
#define VPERRINT_SG3LL         (*(volatile unsigned char  *)0xFFC67C04)
#define VPERSTCLR_SG3          (*(volatile unsigned long  *)0xFFC67C08)
#define VPERSTCLR_SG3L         (*(volatile unsigned short *)0xFFC67C08)
#define VPERSTCLR_SG3LL        (*(volatile unsigned char  *)0xFFC67C08)
#define VPOVFSTR_SG3           (*(volatile unsigned long  *)0xFFC67C0C)
#define VPOVFSTR_SG3L          (*(volatile unsigned short *)0xFFC67C0C)
#define VPOVFSTR_SG3LL         (*(volatile unsigned char  *)0xFFC67C0C)
#define VPERSTR_SG3            (*(volatile unsigned long  *)0xFFC67C10)
#define VPERSTR_SG3L           (*(volatile unsigned short *)0xFFC67C10)
#define VPERSTR_SG3LL          (*(volatile unsigned char  *)0xFFC67C10)
#define VPEADR_SG3             (*(volatile unsigned long  *)0xFFC67C50)
#define VPECCCTL_SG5           (*(volatile unsigned long  *)0xFFC68400)
#define VPECCCTL_SG5L          (*(volatile unsigned short *)0xFFC68400)
#define VPERRINT_SG5           (*(volatile unsigned long  *)0xFFC68404)
#define VPERRINT_SG5L          (*(volatile unsigned short *)0xFFC68404)
#define VPERRINT_SG5LL         (*(volatile unsigned char  *)0xFFC68404)
#define VPERSTCLR_SG5          (*(volatile unsigned long  *)0xFFC68408)
#define VPERSTCLR_SG5L         (*(volatile unsigned short *)0xFFC68408)
#define VPERSTCLR_SG5LL        (*(volatile unsigned char  *)0xFFC68408)
#define VPOVFSTR_SG5           (*(volatile unsigned long  *)0xFFC6840C)
#define VPOVFSTR_SG5L          (*(volatile unsigned short *)0xFFC6840C)
#define VPOVFSTR_SG5LL         (*(volatile unsigned char  *)0xFFC6840C)
#define VPERSTR_SG5            (*(volatile unsigned long  *)0xFFC68410)
#define VPERSTR_SG5L           (*(volatile unsigned short *)0xFFC68410)
#define VPERSTR_SG5LL          (*(volatile unsigned char  *)0xFFC68410)
#define VPEADR_SG5             (*(volatile unsigned long  *)0xFFC68450)
#define VPECCCTL_TERM_SG7      (*(volatile unsigned long  *)0xFFC68E00)
#define VPECCCTL_TERM_SG7L     (*(volatile unsigned short *)0xFFC68E00)
#define VPERRINT_TERM_SG7      (*(volatile unsigned long  *)0xFFC68E04)
#define VPERRINT_TERM_SG7L     (*(volatile unsigned short *)0xFFC68E04)
#define VPERRINT_TERM_SG7LL    (*(volatile unsigned char  *)0xFFC68E04)
#define VPERSTCLR_TERM_SG7     (*(volatile unsigned long  *)0xFFC68E08)
#define VPERSTCLR_TERM_SG7L    (*(volatile unsigned short *)0xFFC68E08)
#define VPERSTCLR_TERM_SG7LL   (*(volatile unsigned char  *)0xFFC68E08)
#define VPOVFSTR_TERM_SG7      (*(volatile unsigned long  *)0xFFC68E0C)
#define VPOVFSTR_TERM_SG7L     (*(volatile unsigned short *)0xFFC68E0C)
#define VPOVFSTR_TERM_SG7LL    (*(volatile unsigned char  *)0xFFC68E0C)
#define VPERSTR_TERM_SG7       (*(volatile unsigned long  *)0xFFC68E10)
#define VPERSTR_TERM_SG7L      (*(volatile unsigned short *)0xFFC68E10)
#define VPERSTR_TERM_SG7LL     (*(volatile unsigned char  *)0xFFC68E10)
#define VPEADR_TERM_SG7        (*(volatile unsigned long  *)0xFFC68E50)
#define VPECCCTL_VCI2VPI       (*(volatile unsigned long  *)0xFFC69000)
#define VPECCCTL_VCI2VPIL      (*(volatile unsigned short *)0xFFC69000)
#define VPERRINT_VCI2VPI       (*(volatile unsigned long  *)0xFFC69004)
#define VPERRINT_VCI2VPIL      (*(volatile unsigned short *)0xFFC69004)
#define VPERRINT_VCI2VPILL     (*(volatile unsigned char  *)0xFFC69004)
#define VPERSTCLR_VCI2VPI      (*(volatile unsigned long  *)0xFFC69008)
#define VPERSTCLR_VCI2VPIL     (*(volatile unsigned short *)0xFFC69008)
#define VPERSTCLR_VCI2VPILL    (*(volatile unsigned char  *)0xFFC69008)
#define VPOVFSTR_VCI2VPI       (*(volatile unsigned long  *)0xFFC6900C)
#define VPOVFSTR_VCI2VPIL      (*(volatile unsigned short *)0xFFC6900C)
#define VPOVFSTR_VCI2VPILL     (*(volatile unsigned char  *)0xFFC6900C)
#define VPERSTR_VCI2VPI        (*(volatile unsigned long  *)0xFFC69010)
#define VPERSTR_VCI2VPIL       (*(volatile unsigned short *)0xFFC69010)
#define VPERSTR_VCI2VPILL      (*(volatile unsigned char  *)0xFFC69010)
#define VPERADR0_VCI2VPI       (*(volatile unsigned long  *)0xFFC69050)
#define VCECCCTL_PDMA          (*(volatile unsigned long  *)0xFFC6A000)
#define VCECCCTL_PDMAL         (*(volatile unsigned short *)0xFFC6A000)
#define VCERRINT_PDMA          (*(volatile unsigned long  *)0xFFC6A004)
#define VCERRINT_PDMAL         (*(volatile unsigned short *)0xFFC6A004)
#define VCERRINT_PDMALL        (*(volatile unsigned char  *)0xFFC6A004)
#define VCERSTCLR_PDMA         (*(volatile unsigned long  *)0xFFC6A008)
#define VCERSTCLR_PDMAL        (*(volatile unsigned short *)0xFFC6A008)
#define VCERSTCLR_PDMALL       (*(volatile unsigned char  *)0xFFC6A008)
#define VCOVFSTR_PDMA          (*(volatile unsigned long  *)0xFFC6A00C)
#define VCOVFSTR_PDMAL         (*(volatile unsigned short *)0xFFC6A00C)
#define VCOVFSTR_PDMALL        (*(volatile unsigned char  *)0xFFC6A00C)
#define VCERSTR_PDMA           (*(volatile unsigned long  *)0xFFC6A010)
#define VCERSTR_PDMAL          (*(volatile unsigned short *)0xFFC6A010)
#define VCERSTR_PDMALL         (*(volatile unsigned char  *)0xFFC6A010)
#define VCEADR_PDMA            (*(volatile unsigned long  *)0xFFC6A050)
#define APECCCTL_PFSS          (*(volatile unsigned long  *)0xFFC6C000)
#define APECCCTL_PFSSL         (*(volatile unsigned short *)0xFFC6C000)
#define APERRINT_PFSS          (*(volatile unsigned long  *)0xFFC6C004)
#define APERRINT_PFSSL         (*(volatile unsigned short *)0xFFC6C004)
#define APERRINT_PFSSLL        (*(volatile unsigned char  *)0xFFC6C004)
#define APERSTCLR_PFSS         (*(volatile unsigned long  *)0xFFC6C008)
#define APERSTCLR_PFSSL        (*(volatile unsigned short *)0xFFC6C008)
#define APERSTCLR_PFSSLL       (*(volatile unsigned char  *)0xFFC6C008)
#define APOVFSTR_PFSS          (*(volatile unsigned long  *)0xFFC6C00C)
#define APOVFSTR_PFSSL         (*(volatile unsigned short *)0xFFC6C00C)
#define APOVFSTR_PFSSLL        (*(volatile unsigned char  *)0xFFC6C00C)
#define APERSTR_PFSS           (*(volatile unsigned long  *)0xFFC6C010)
#define APERSTR_PFSSL          (*(volatile unsigned short *)0xFFC6C010)
#define APERSTR_PFSSLL         (*(volatile unsigned char  *)0xFFC6C010)
#define APEADR_PFSS            (*(volatile unsigned long  *)0xFFC6C050)
#define APEC0ECCCTL            (*(volatile unsigned long  *)0xFFCB8000)
#define APEC0ECCCTLL           (*(volatile unsigned short *)0xFFCB8000)
#define APEC0ERRINT            (*(volatile unsigned long  *)0xFFCB8004)
#define APEC0ERRINTL           (*(volatile unsigned short *)0xFFCB8004)
#define APEC0ERRINTLL          (*(volatile unsigned char  *)0xFFCB8004)
#define APEC0STCLR             (*(volatile unsigned long  *)0xFFCB8008)
#define APEC0STCLRL            (*(volatile unsigned short *)0xFFCB8008)
#define APEC0STCLRLL           (*(volatile unsigned char  *)0xFFCB8008)
#define APEC0OVFSTR            (*(volatile unsigned long  *)0xFFCB800C)
#define APEC0OVFSTRL           (*(volatile unsigned short *)0xFFCB800C)
#define APEC0OVFSTRLL          (*(volatile unsigned char  *)0xFFCB800C)
#define APEC01STERSTR          (*(volatile unsigned long  *)0xFFCB8010)
#define APEC01STERSTRL         (*(volatile unsigned short *)0xFFCB8010)
#define APEC01STERSTRLL        (*(volatile unsigned char  *)0xFFCB8010)
#define APEC01STEADR0          (*(volatile unsigned long  *)0xFFCB8050)
#define GREG8                  (*(volatile unsigned long  *)0xFFCD0020)
#define OPBT0                  (*(volatile unsigned long  *)0xFFCD0030)
#define OPBT1                  (*(volatile unsigned long  *)0xFFCD0034)
#define OPBT2                  (*(volatile unsigned long  *)0xFFCD0038)
#define OPBT13                 (*(volatile unsigned long  *)0xFFCD0064)
#define OPBT14                 (*(volatile unsigned long  *)0xFFCD0068)
#define OPBT15                 (*(volatile unsigned long  *)0xFFCD006C)
#define PRDNAME1               (*(volatile unsigned long  *)0xFFCD00D0)
#define PRDNAME2               (*(volatile unsigned long  *)0xFFCD00D4)
#define PRDNAME3               (*(volatile unsigned long  *)0xFFCD00D8)
#define PRDNAME4               (*(volatile unsigned long  *)0xFFCD00DC)
#define CHIPID1LL              (*(volatile unsigned long  *)0xFFCD00E0)
#define CHIPID1LH              (*(volatile unsigned long  *)0xFFCD00E4)
#define CHIPID1HL              (*(volatile unsigned long  *)0xFFCD00E8)
#define CHIPID1HH              (*(volatile unsigned long  *)0xFFCD00EC)
#define EMLK                   (*(volatile unsigned long  *)0xFFCD0140)
#define APEC4ECCCTL            (*(volatile unsigned long  *)0xFFCD8000)
#define APEC4ECCCTLL           (*(volatile unsigned short *)0xFFCD8000)
#define APEC4ERRINT            (*(volatile unsigned long  *)0xFFCD8004)
#define APEC4ERRINTL           (*(volatile unsigned short *)0xFFCD8004)
#define APEC4ERRINTLL          (*(volatile unsigned char  *)0xFFCD8004)
#define APEC4STCLR             (*(volatile unsigned long  *)0xFFCD8008)
#define APEC4STCLRL            (*(volatile unsigned short *)0xFFCD8008)
#define APEC4STCLRLL           (*(volatile unsigned char  *)0xFFCD8008)
#define APEC4OVFSTR            (*(volatile unsigned long  *)0xFFCD800C)
#define APEC4OVFSTRL           (*(volatile unsigned short *)0xFFCD800C)
#define APEC4OVFSTRLL          (*(volatile unsigned char  *)0xFFCD800C)
#define APEC41STERSTR          (*(volatile unsigned long  *)0xFFCD8010)
#define APEC41STERSTRL         (*(volatile unsigned short *)0xFFCD8010)
#define APEC41STERSTRLL        (*(volatile unsigned char  *)0xFFCD8010)
#define APEC41STEADR0          (*(volatile unsigned long  *)0xFFCD8050)
#define APEC5ECCCTL            (*(volatile unsigned long  *)0xFFCD8200)
#define APEC5ECCCTLL           (*(volatile unsigned short *)0xFFCD8200)
#define APEC5ERRINT            (*(volatile unsigned long  *)0xFFCD8204)
#define APEC5ERRINTL           (*(volatile unsigned short *)0xFFCD8204)
#define APEC5ERRINTLL          (*(volatile unsigned char  *)0xFFCD8204)
#define APEC5STCLR             (*(volatile unsigned long  *)0xFFCD8208)
#define APEC5STCLRL            (*(volatile unsigned short *)0xFFCD8208)
#define APEC5STCLRLL           (*(volatile unsigned char  *)0xFFCD8208)
#define APEC5OVFSTR            (*(volatile unsigned long  *)0xFFCD820C)
#define APEC5OVFSTRL           (*(volatile unsigned short *)0xFFCD820C)
#define APEC5OVFSTRLL          (*(volatile unsigned char  *)0xFFCD820C)
#define APEC51STERSTR          (*(volatile unsigned long  *)0xFFCD8210)
#define APEC51STERSTRL         (*(volatile unsigned short *)0xFFCD8210)
#define APEC51STERSTRLL        (*(volatile unsigned char  *)0xFFCD8210)
#define APEC51STEADR0          (*(volatile unsigned long  *)0xFFCD8250)
#define APEC6ECCCTL            (*(volatile unsigned long  *)0xFFCD8400)
#define APEC6ECCCTLL           (*(volatile unsigned short *)0xFFCD8400)
#define APEC6ERRINT            (*(volatile unsigned long  *)0xFFCD8404)
#define APEC6ERRINTL           (*(volatile unsigned short *)0xFFCD8404)
#define APEC6ERRINTLL          (*(volatile unsigned char  *)0xFFCD8404)
#define APEC6STCLR             (*(volatile unsigned long  *)0xFFCD8408)
#define APEC6STCLRL            (*(volatile unsigned short *)0xFFCD8408)
#define APEC6STCLRLL           (*(volatile unsigned char  *)0xFFCD8408)
#define APEC6OVFSTR            (*(volatile unsigned long  *)0xFFCD840C)
#define APEC6OVFSTRL           (*(volatile unsigned short *)0xFFCD840C)
#define APEC6OVFSTRLL          (*(volatile unsigned char  *)0xFFCD840C)
#define APEC61STERSTR          (*(volatile unsigned long  *)0xFFCD8410)
#define APEC61STERSTRL         (*(volatile unsigned short *)0xFFCD8410)
#define APEC61STERSTRLL        (*(volatile unsigned char  *)0xFFCD8410)
#define APEC61STEADR0          (*(volatile unsigned long  *)0xFFCD8450)
#define LBISTREF1              (*(volatile unsigned long  *)0xFFCDA000)
#define LBISTREF2              (*(volatile unsigned long  *)0xFFCDA004)
#define MBISTREF1              (*(volatile unsigned long  *)0xFFCDA008)
#define MBISTREF2              (*(volatile unsigned long  *)0xFFCDA00C)
#define LBISTSIG1              (*(volatile unsigned long  *)0xFFCDA010)
#define LBISTSIG2              (*(volatile unsigned long  *)0xFFCDA014)
#define MBISTSIG1              (*(volatile unsigned long  *)0xFFCDA018)
#define MBISTSIG2              (*(volatile unsigned long  *)0xFFCDA01C)
#define MBISTFTAGL1            (*(volatile unsigned long  *)0xFFCDA020)
#define MBISTFTAGH1            (*(volatile unsigned long  *)0xFFCDA024)
#define MBISTFTAGL2            (*(volatile unsigned long  *)0xFFCDA028)
#define MBISTFTAGH2            (*(volatile unsigned long  *)0xFFCDA02C)
#define BSEQ0ST                (*(volatile unsigned long  *)0xFFCDA030)
#define BSEQ0STB               (*(volatile unsigned long  *)0xFFCDA034)
#define BISTST                 (*(volatile unsigned long  *)0xFFCDA038)
#define RSENT0TSSEL            (*(volatile unsigned long  *)0xFFCDCF00)
#define RSENT1TSSEL            (*(volatile unsigned long  *)0xFFCDCF04)
#define RSENT2TSSEL            (*(volatile unsigned long  *)0xFFCDCF08)
#define RSENT3TSSEL            (*(volatile unsigned long  *)0xFFCDCF0C)
#define RSENT4TSSEL            (*(volatile unsigned long  *)0xFFCDCF10)
#define RSENT5TSSEL            (*(volatile unsigned long  *)0xFFCDCF14)
#define PINT0                  (*(volatile unsigned long  *)0xFFD40000)
#define PINT1                  (*(volatile unsigned long  *)0xFFD40004)
#define PINT2                  (*(volatile unsigned long  *)0xFFD40008)
#define PINT3                  (*(volatile unsigned long  *)0xFFD4000C)
#define PINT4                  (*(volatile unsigned long  *)0xFFD40010)
#define PINT5                  (*(volatile unsigned long  *)0xFFD40014)
#define PINT6                  (*(volatile unsigned long  *)0xFFD40018)
#define PINT7                  (*(volatile unsigned long  *)0xFFD4001C)
#define PINTCLR0               (*(volatile unsigned long  *)0xFFD40020)
#define PINTCLR1               (*(volatile unsigned long  *)0xFFD40024)
#define PINTCLR2               (*(volatile unsigned long  *)0xFFD40028)
#define PINTCLR3               (*(volatile unsigned long  *)0xFFD4002C)
#define PINTCLR4               (*(volatile unsigned long  *)0xFFD40030)
#define PINTCLR5               (*(volatile unsigned long  *)0xFFD40034)
#define PINTCLR6               (*(volatile unsigned long  *)0xFFD40038)
#define PINTCLR7               (*(volatile unsigned long  *)0xFFD4003C)
#define DTSTRGSEL0             (*(volatile unsigned long  *)0xFFD41000)
#define DTSTRGSEL1             (*(volatile unsigned long  *)0xFFD41004)
#define DTSTRGSEL2             (*(volatile unsigned long  *)0xFFD41008)
#define DTSTRGSEL3             (*(volatile unsigned long  *)0xFFD4100C)
#define FEINTF0                (*(volatile unsigned long  *)0xFFD42000)
#define FEINTFMSK0             (*(volatile unsigned long  *)0xFFD42004)
#define FEINTFC0               (*(volatile unsigned long  *)0xFFD42008)
#define FEINTF1                (*(volatile unsigned long  *)0xFFD43000)
#define FEINTFMSK1             (*(volatile unsigned long  *)0xFFD43004)
#define FEINTFC1               (*(volatile unsigned long  *)0xFFD43008)
#define APEC1ECCCTL            (*(volatile unsigned long  *)0xFFE88000)
#define APEC1ECCCTLL           (*(volatile unsigned short *)0xFFE88000)
#define APEC1ERRINT            (*(volatile unsigned long  *)0xFFE88004)
#define APEC1ERRINTL           (*(volatile unsigned short *)0xFFE88004)
#define APEC1ERRINTLL          (*(volatile unsigned char  *)0xFFE88004)
#define APEC1STCLR             (*(volatile unsigned long  *)0xFFE88008)
#define APEC1STCLRL            (*(volatile unsigned short *)0xFFE88008)
#define APEC1STCLRLL           (*(volatile unsigned char  *)0xFFE88008)
#define APEC1OVFSTR            (*(volatile unsigned long  *)0xFFE8800C)
#define APEC1OVFSTRL           (*(volatile unsigned short *)0xFFE8800C)
#define APEC1OVFSTRLL          (*(volatile unsigned char  *)0xFFE8800C)
#define APEC11STERSTR          (*(volatile unsigned long  *)0xFFE88010)
#define APEC11STERSTRL         (*(volatile unsigned short *)0xFFE88010)
#define APEC11STERSTRLL        (*(volatile unsigned char  *)0xFFE88010)
#define APEC11STEADR0          (*(volatile unsigned long  *)0xFFE88050)
#define APEC2ECCCTL            (*(volatile unsigned long  *)0xFFE88200)
#define APEC2ECCCTLL           (*(volatile unsigned short *)0xFFE88200)
#define APEC2ERRINT            (*(volatile unsigned long  *)0xFFE88204)
#define APEC2ERRINTL           (*(volatile unsigned short *)0xFFE88204)
#define APEC2ERRINTLL          (*(volatile unsigned char  *)0xFFE88204)
#define APEC2STCLR             (*(volatile unsigned long  *)0xFFE88208)
#define APEC2STCLRL            (*(volatile unsigned short *)0xFFE88208)
#define APEC2STCLRLL           (*(volatile unsigned char  *)0xFFE88208)
#define APEC2OVFSTR            (*(volatile unsigned long  *)0xFFE8820C)
#define APEC2OVFSTRL           (*(volatile unsigned short *)0xFFE8820C)
#define APEC2OVFSTRLL          (*(volatile unsigned char  *)0xFFE8820C)
#define APEC21STERSTR          (*(volatile unsigned long  *)0xFFE88210)
#define APEC21STERSTRL         (*(volatile unsigned short *)0xFFE88210)
#define APEC21STERSTRLL        (*(volatile unsigned char  *)0xFFE88210)
#define APEC21STEADR0          (*(volatile unsigned long  *)0xFFE88250)
#define SELB0CALC              (*(volatile unsigned long  *)0xFFED8024)
#define MODE                   (*(volatile unsigned long  *)0xFFF80104)
#define BSEQ0CTL               (*(volatile unsigned long  *)0xFFF80200)
#define RESF                   (*(volatile unsigned long  *)0xFFF81000)
#define RESFC                  (*(volatile unsigned long  *)0xFFF81008)
#define SWSRESA0               (*(volatile unsigned long  *)0xFFF81100)
#define SWARESA0               (*(volatile unsigned long  *)0xFFF81200)
#define STAC_DTSRAM            (*(volatile unsigned long  *)0xFFF81320)
#define STAC_GRAM              (*(volatile unsigned long  *)0xFFF81420)
#define STAC_LM0               (*(volatile unsigned long  *)0xFFF81520)
#define STAC_LM1               (*(volatile unsigned long  *)0xFFF81620)
#define SWLRESA3               (*(volatile unsigned long  *)0xFFF81708)
#define SWLRESS3               (*(volatile unsigned long  *)0xFFF8170C)
#define MSR_LM3                (*(volatile unsigned long  *)0xFFF81710)
#define STAC_LM3               (*(volatile unsigned long  *)0xFFF81720)
#define SWLRESA4               (*(volatile unsigned long  *)0xFFF81808)
#define SWLRESS4               (*(volatile unsigned long  *)0xFFF8180C)
#define MSR_LM4                (*(volatile unsigned long  *)0xFFF81810)
#define STAC_LM4               (*(volatile unsigned long  *)0xFFF81820)
#define SWLRESA5               (*(volatile unsigned long  *)0xFFF81908)
#define SWLRESS5               (*(volatile unsigned long  *)0xFFF8190C)
#define MSR_LM5                (*(volatile unsigned long  *)0xFFF81910)
#define STAC_LM5               (*(volatile unsigned long  *)0xFFF81920)
#define SWLRESA6               (*(volatile unsigned long  *)0xFFF81A08)
#define SWLRESS6               (*(volatile unsigned long  *)0xFFF81A0C)
#define MSR_LM6                (*(volatile unsigned long  *)0xFFF81A10)
#define SWLRESA7               (*(volatile unsigned long  *)0xFFF81B08)
#define SWLRESS7               (*(volatile unsigned long  *)0xFFF81B0C)
#define MSR_LM7                (*(volatile unsigned long  *)0xFFF81B10)
#define SWLRESA8               (*(volatile unsigned long  *)0xFFF81C08)
#define SWLRESS8               (*(volatile unsigned long  *)0xFFF81C0C)
#define MSR_LM8                (*(volatile unsigned long  *)0xFFF81C10)
#define SWLRESA10              (*(volatile unsigned long  *)0xFFF81E08)
#define SWLRESS10              (*(volatile unsigned long  *)0xFFF81E0C)
#define MSR_LM10               (*(volatile unsigned long  *)0xFFF81E10)
#define STAC_LM10              (*(volatile unsigned long  *)0xFFF81E20)
#define SWLRESA11              (*(volatile unsigned long  *)0xFFF81F08)
#define SWLRESS11              (*(volatile unsigned long  *)0xFFF81F0C)
#define MSR_LM11               (*(volatile unsigned long  *)0xFFF81F10)
#define SWLRESA12              (*(volatile unsigned long  *)0xFFF82008)
#define SWLRESS12              (*(volatile unsigned long  *)0xFFF8200C)
#define MSR_LM12               (*(volatile unsigned long  *)0xFFF82010)
#define FHVE3                  (*(volatile unsigned long  *)0xFFF82410)
#define RESC                   (*(volatile unsigned long  *)0xFFF82800)
#define CVMF                   (*(volatile unsigned char  *)0xFFF82C00)
#define CVMDE                  (*(volatile unsigned char  *)0xFFF82C04)
#define CVMDMASK               (*(volatile unsigned char  *)0xFFF82C0C)
#define CVMDIAG                (*(volatile unsigned char  *)0xFFF82C10)
#define CVMMON                 (*(volatile unsigned char  *)0xFFF82C14)
#define CVMFC                  (*(volatile unsigned char  *)0xFFF82C18)
#define CVMDEW                 (*(volatile unsigned char  *)0xFFF82C1C)
#define CLMATEST               (*(volatile unsigned long  *)0xFFF83000)
#define CLMATESTS              (*(volatile unsigned long  *)0xFFF83004)
#define CKSC4C                 (*(volatile unsigned long  *)0xFFF84000)
#define CKSC4S                 (*(volatile unsigned long  *)0xFFF84008)
#define SWSRESA1               (*(volatile unsigned long  *)0xFFF86000)
#define SWARESA1               (*(volatile unsigned long  *)0xFFF86100)
#define SWLRESA2               (*(volatile unsigned long  *)0xFFF86208)
#define SWLRESS2               (*(volatile unsigned long  *)0xFFF8620C)
#define MSR_LM2                (*(volatile unsigned long  *)0xFFF86210)
#define STAC_LM2               (*(volatile unsigned long  *)0xFFF86220)
#define ICUMRESF               (*(volatile unsigned long  *)0xFFF86300)
#define ICUMRESFC              (*(volatile unsigned long  *)0xFFF86308)
#define CLKD0DIV               (*(volatile unsigned long  *)0xFFF88800)
#define CLKD0STAT              (*(volatile unsigned long  *)0xFFF88804)
#define CLKD1DIV               (*(volatile unsigned long  *)0xFFF88808)
#define CLKD1STAT              (*(volatile unsigned long  *)0xFFF8880C)
#define CLKD2DIV               (*(volatile unsigned long  *)0xFFF88810)
#define CLKD2STAT              (*(volatile unsigned long  *)0xFFF88814)
#define CLKD3DIV               (*(volatile unsigned long  *)0xFFF88818)
#define CLKD3STAT              (*(volatile unsigned long  *)0xFFF8881C)
#define CKSC0C                 (*(volatile unsigned long  *)0xFFF89000)
#define CKSC0S                 (*(volatile unsigned long  *)0xFFF89008)
#define CKSC2C                 (*(volatile unsigned long  *)0xFFF89080)
#define CKSC2S                 (*(volatile unsigned long  *)0xFFF89088)
#define CKSC3C                 (*(volatile unsigned long  *)0xFFF890C0)
#define CKSC3S                 (*(volatile unsigned long  *)0xFFF890C8)
#define FHVE15                 (*(volatile unsigned long  *)0xFFF8A430)
#define APEC3ECCCTL            (*(volatile unsigned long  *)0xFFF98000)
#define APEC3ECCCTLL           (*(volatile unsigned short *)0xFFF98000)
#define APEC3ERRINT            (*(volatile unsigned long  *)0xFFF98004)
#define APEC3ERRINTL           (*(volatile unsigned short *)0xFFF98004)
#define APEC3ERRINTLL          (*(volatile unsigned char  *)0xFFF98004)
#define APEC3STCLR             (*(volatile unsigned long  *)0xFFF98008)
#define APEC3STCLRL            (*(volatile unsigned short *)0xFFF98008)
#define APEC3STCLRLL           (*(volatile unsigned char  *)0xFFF98008)
#define APEC3OVFSTR            (*(volatile unsigned long  *)0xFFF9800C)
#define APEC3OVFSTRL           (*(volatile unsigned short *)0xFFF9800C)
#define APEC3OVFSTRLL          (*(volatile unsigned char  *)0xFFF9800C)
#define APEC31STERSTR          (*(volatile unsigned long  *)0xFFF98010)
#define APEC31STERSTRL         (*(volatile unsigned short *)0xFFF98010)
#define APEC31STERSTRLL        (*(volatile unsigned char  *)0xFFF98010)
#define APEC31STEADR0          (*(volatile unsigned long  *)0xFFF98050)
#define EIC0                   (*(volatile unsigned short *)0xFFFEEA00)
#define EIC0L                  (*(volatile unsigned char  *)0xFFFEEA00)
#define EIC0H                  (*(volatile unsigned char  *)0xFFFEEA01)
#define EIC1                   (*(volatile unsigned short *)0xFFFEEA02)
#define EIC1L                  (*(volatile unsigned char  *)0xFFFEEA02)
#define EIC1H                  (*(volatile unsigned char  *)0xFFFEEA03)
#define EIC2                   (*(volatile unsigned short *)0xFFFEEA04)
#define EIC2L                  (*(volatile unsigned char  *)0xFFFEEA04)
#define EIC2H                  (*(volatile unsigned char  *)0xFFFEEA05)
#define EIC3                   (*(volatile unsigned short *)0xFFFEEA06)
#define EIC3L                  (*(volatile unsigned char  *)0xFFFEEA06)
#define EIC3H                  (*(volatile unsigned char  *)0xFFFEEA07)
#define EIC4                   (*(volatile unsigned short *)0xFFFEEA08)
#define EIC4L                  (*(volatile unsigned char  *)0xFFFEEA08)
#define EIC4H                  (*(volatile unsigned char  *)0xFFFEEA09)
#define EIC5                   (*(volatile unsigned short *)0xFFFEEA0A)
#define EIC5L                  (*(volatile unsigned char  *)0xFFFEEA0A)
#define EIC5H                  (*(volatile unsigned char  *)0xFFFEEA0B)
#define EIC6                   (*(volatile unsigned short *)0xFFFEEA0C)
#define EIC6L                  (*(volatile unsigned char  *)0xFFFEEA0C)
#define EIC6H                  (*(volatile unsigned char  *)0xFFFEEA0D)
#define EIC7                   (*(volatile unsigned short *)0xFFFEEA0E)
#define EIC7L                  (*(volatile unsigned char  *)0xFFFEEA0E)
#define EIC7H                  (*(volatile unsigned char  *)0xFFFEEA0F)
#define EIC8                   (*(volatile unsigned short *)0xFFFEEA10)
#define EIC8L                  (*(volatile unsigned char  *)0xFFFEEA10)
#define EIC8H                  (*(volatile unsigned char  *)0xFFFEEA11)
#define EIC9                   (*(volatile unsigned short *)0xFFFEEA12)
#define EIC9L                  (*(volatile unsigned char  *)0xFFFEEA12)
#define EIC9H                  (*(volatile unsigned char  *)0xFFFEEA13)
#define EIC10                  (*(volatile unsigned short *)0xFFFEEA14)
#define EIC10L                 (*(volatile unsigned char  *)0xFFFEEA14)
#define EIC10H                 (*(volatile unsigned char  *)0xFFFEEA15)
#define EIC11                  (*(volatile unsigned short *)0xFFFEEA16)
#define EIC11L                 (*(volatile unsigned char  *)0xFFFEEA16)
#define EIC11H                 (*(volatile unsigned char  *)0xFFFEEA17)
#define EIC12                  (*(volatile unsigned short *)0xFFFEEA18)
#define EIC12L                 (*(volatile unsigned char  *)0xFFFEEA18)
#define EIC12H                 (*(volatile unsigned char  *)0xFFFEEA19)
#define EIC13                  (*(volatile unsigned short *)0xFFFEEA1A)
#define EIC13L                 (*(volatile unsigned char  *)0xFFFEEA1A)
#define EIC13H                 (*(volatile unsigned char  *)0xFFFEEA1B)
#define EIC14                  (*(volatile unsigned short *)0xFFFEEA1C)
#define EIC14L                 (*(volatile unsigned char  *)0xFFFEEA1C)
#define EIC14H                 (*(volatile unsigned char  *)0xFFFEEA1D)
#define EIC15                  (*(volatile unsigned short *)0xFFFEEA1E)
#define EIC15L                 (*(volatile unsigned char  *)0xFFFEEA1E)
#define EIC15H                 (*(volatile unsigned char  *)0xFFFEEA1F)
#define EIC16                  (*(volatile unsigned short *)0xFFFEEA20)
#define EIC16L                 (*(volatile unsigned char  *)0xFFFEEA20)
#define EIC16H                 (*(volatile unsigned char  *)0xFFFEEA21)
#define EIC17                  (*(volatile unsigned short *)0xFFFEEA22)
#define EIC17L                 (*(volatile unsigned char  *)0xFFFEEA22)
#define EIC17H                 (*(volatile unsigned char  *)0xFFFEEA23)
#define EIC18                  (*(volatile unsigned short *)0xFFFEEA24)
#define EIC18L                 (*(volatile unsigned char  *)0xFFFEEA24)
#define EIC18H                 (*(volatile unsigned char  *)0xFFFEEA25)
#define EIC19                  (*(volatile unsigned short *)0xFFFEEA26)
#define EIC19L                 (*(volatile unsigned char  *)0xFFFEEA26)
#define EIC19H                 (*(volatile unsigned char  *)0xFFFEEA27)
#define EIC20                  (*(volatile unsigned short *)0xFFFEEA28)
#define EIC20L                 (*(volatile unsigned char  *)0xFFFEEA28)
#define EIC20H                 (*(volatile unsigned char  *)0xFFFEEA29)
#define EIC21                  (*(volatile unsigned short *)0xFFFEEA2A)
#define EIC21L                 (*(volatile unsigned char  *)0xFFFEEA2A)
#define EIC21H                 (*(volatile unsigned char  *)0xFFFEEA2B)
#define EIC22                  (*(volatile unsigned short *)0xFFFEEA2C)
#define EIC22L                 (*(volatile unsigned char  *)0xFFFEEA2C)
#define EIC22H                 (*(volatile unsigned char  *)0xFFFEEA2D)
#define EIC23                  (*(volatile unsigned short *)0xFFFEEA2E)
#define EIC23L                 (*(volatile unsigned char  *)0xFFFEEA2E)
#define EIC23H                 (*(volatile unsigned char  *)0xFFFEEA2F)
#define EIC24                  (*(volatile unsigned short *)0xFFFEEA30)
#define EIC24L                 (*(volatile unsigned char  *)0xFFFEEA30)
#define EIC24H                 (*(volatile unsigned char  *)0xFFFEEA31)
#define EIC25                  (*(volatile unsigned short *)0xFFFEEA32)
#define EIC25L                 (*(volatile unsigned char  *)0xFFFEEA32)
#define EIC25H                 (*(volatile unsigned char  *)0xFFFEEA33)
#define EIC26                  (*(volatile unsigned short *)0xFFFEEA34)
#define EIC26L                 (*(volatile unsigned char  *)0xFFFEEA34)
#define EIC26H                 (*(volatile unsigned char  *)0xFFFEEA35)
#define EIC27                  (*(volatile unsigned short *)0xFFFEEA36)
#define EIC27L                 (*(volatile unsigned char  *)0xFFFEEA36)
#define EIC27H                 (*(volatile unsigned char  *)0xFFFEEA37)
#define EIC28                  (*(volatile unsigned short *)0xFFFEEA38)
#define EIC28L                 (*(volatile unsigned char  *)0xFFFEEA38)
#define EIC28H                 (*(volatile unsigned char  *)0xFFFEEA39)
#define EIC29                  (*(volatile unsigned short *)0xFFFEEA3A)
#define EIC29L                 (*(volatile unsigned char  *)0xFFFEEA3A)
#define EIC29H                 (*(volatile unsigned char  *)0xFFFEEA3B)
#define EIC30                  (*(volatile unsigned short *)0xFFFEEA3C)
#define EIC30L                 (*(volatile unsigned char  *)0xFFFEEA3C)
#define EIC30H                 (*(volatile unsigned char  *)0xFFFEEA3D)
#define EIC31                  (*(volatile unsigned short *)0xFFFEEA3E)
#define EIC31L                 (*(volatile unsigned char  *)0xFFFEEA3E)
#define EIC31H                 (*(volatile unsigned char  *)0xFFFEEA3F)
#define FNC                    (*(volatile unsigned short *)0xFFFEEA78)
#define FNCH                   (*(volatile unsigned char  *)0xFFFEEA79)
#define FNRF                   (((volatile __bitf_T *)0xFFFEEA79)->bit04)
#define FNCT                   (((volatile __bitf_T *)0xFFFEEA79)->bit07)
#define FIC                    (*(volatile unsigned short *)0xFFFEEA7A)
#define FICH                   (*(volatile unsigned char  *)0xFFFEEA7B)
#define FIRF                   (((volatile __bitf_T *)0xFFFEEA7B)->bit04)
#define FICT                   (((volatile __bitf_T *)0xFFFEEA7B)->bit07)
#define IMR0                   (*(volatile unsigned long  *)0xFFFEEAF0)
#define IMR0L                  (*(volatile unsigned short *)0xFFFEEAF0)
#define IMR0LL                 (*(volatile unsigned char  *)0xFFFEEAF0)
#define IMR0LH                 (*(volatile unsigned char  *)0xFFFEEAF1)
#define IMR0H                  (*(volatile unsigned short *)0xFFFEEAF2)
#define IMR0HL                 (*(volatile unsigned char  *)0xFFFEEAF2)
#define IMR0HH                 (*(volatile unsigned char  *)0xFFFEEAF3)
#define IMR0EIMK0              (((volatile __bitf_T *)0xFFFEEAF0)->bit00)
#define IMR0EIMK1              (((volatile __bitf_T *)0xFFFEEAF0)->bit01)
#define IMR0EIMK2              (((volatile __bitf_T *)0xFFFEEAF0)->bit02)
#define IMR0EIMK3              (((volatile __bitf_T *)0xFFFEEAF0)->bit03)
#define IMR0EIMK4              (((volatile __bitf_T *)0xFFFEEAF0)->bit04)
#define IMR0EIMK5              (((volatile __bitf_T *)0xFFFEEAF0)->bit05)
#define IMR0EIMK6              (((volatile __bitf_T *)0xFFFEEAF0)->bit06)
#define IMR0EIMK7              (((volatile __bitf_T *)0xFFFEEAF0)->bit07)
#define IMR0EIMK8              (((volatile __bitf_T *)0xFFFEEAF1)->bit00)
#define IMR0EIMK9              (((volatile __bitf_T *)0xFFFEEAF1)->bit01)
#define IMR0EIMK10             (((volatile __bitf_T *)0xFFFEEAF1)->bit02)
#define IMR0EIMK11             (((volatile __bitf_T *)0xFFFEEAF1)->bit03)
#define IMR0EIMK12             (((volatile __bitf_T *)0xFFFEEAF1)->bit04)
#define IMR0EIMK13             (((volatile __bitf_T *)0xFFFEEAF1)->bit05)
#define IMR0EIMK14             (((volatile __bitf_T *)0xFFFEEAF1)->bit06)
#define IMR0EIMK15             (((volatile __bitf_T *)0xFFFEEAF1)->bit07)
#define IMR0EIMK16             (((volatile __bitf_T *)0xFFFEEAF2)->bit00)
#define IMR0EIMK17             (((volatile __bitf_T *)0xFFFEEAF2)->bit01)
#define IMR0EIMK18             (((volatile __bitf_T *)0xFFFEEAF2)->bit02)
#define IMR0EIMK19             (((volatile __bitf_T *)0xFFFEEAF2)->bit03)
#define IMR0EIMK20             (((volatile __bitf_T *)0xFFFEEAF2)->bit04)
#define IMR0EIMK21             (((volatile __bitf_T *)0xFFFEEAF2)->bit05)
#define IMR0EIMK22             (((volatile __bitf_T *)0xFFFEEAF2)->bit06)
#define IMR0EIMK23             (((volatile __bitf_T *)0xFFFEEAF2)->bit07)
#define IMR0EIMK24             (((volatile __bitf_T *)0xFFFEEAF3)->bit00)
#define IMR0EIMK25             (((volatile __bitf_T *)0xFFFEEAF3)->bit01)
#define IMR0EIMK26             (((volatile __bitf_T *)0xFFFEEAF3)->bit02)
#define IMR0EIMK27             (((volatile __bitf_T *)0xFFFEEAF3)->bit03)
#define IMR0EIMK28             (((volatile __bitf_T *)0xFFFEEAF3)->bit04)
#define IMR0EIMK29             (((volatile __bitf_T *)0xFFFEEAF3)->bit05)
#define IMR0EIMK30             (((volatile __bitf_T *)0xFFFEEAF3)->bit06)
#define IMR0EIMK31             (((volatile __bitf_T *)0xFFFEEAF3)->bit07)
#define EIBD0                  (*(volatile unsigned long  *)0xFFFEEB00)
#define EIBD1                  (*(volatile unsigned long  *)0xFFFEEB04)
#define EIBD2                  (*(volatile unsigned long  *)0xFFFEEB08)
#define EIBD3                  (*(volatile unsigned long  *)0xFFFEEB0C)
#define EIBD4                  (*(volatile unsigned long  *)0xFFFEEB10)
#define EIBD5                  (*(volatile unsigned long  *)0xFFFEEB14)
#define EIBD6                  (*(volatile unsigned long  *)0xFFFEEB18)
#define EIBD7                  (*(volatile unsigned long  *)0xFFFEEB1C)
#define EIBD8                  (*(volatile unsigned long  *)0xFFFEEB20)
#define EIBD9                  (*(volatile unsigned long  *)0xFFFEEB24)
#define EIBD10                 (*(volatile unsigned long  *)0xFFFEEB28)
#define EIBD11                 (*(volatile unsigned long  *)0xFFFEEB2C)
#define EIBD12                 (*(volatile unsigned long  *)0xFFFEEB30)
#define EIBD13                 (*(volatile unsigned long  *)0xFFFEEB34)
#define EIBD14                 (*(volatile unsigned long  *)0xFFFEEB38)
#define EIBD15                 (*(volatile unsigned long  *)0xFFFEEB3C)
#define EIBD16                 (*(volatile unsigned long  *)0xFFFEEB40)
#define EIBD17                 (*(volatile unsigned long  *)0xFFFEEB44)
#define EIBD18                 (*(volatile unsigned long  *)0xFFFEEB48)
#define EIBD19                 (*(volatile unsigned long  *)0xFFFEEB4C)
#define EIBD20                 (*(volatile unsigned long  *)0xFFFEEB50)
#define EIBD21                 (*(volatile unsigned long  *)0xFFFEEB54)
#define EIBD22                 (*(volatile unsigned long  *)0xFFFEEB58)
#define EIBD23                 (*(volatile unsigned long  *)0xFFFEEB5C)
#define EIBD24                 (*(volatile unsigned long  *)0xFFFEEB60)
#define EIBD25                 (*(volatile unsigned long  *)0xFFFEEB64)
#define EIBD26                 (*(volatile unsigned long  *)0xFFFEEB68)
#define EIBD27                 (*(volatile unsigned long  *)0xFFFEEB6C)
#define EIBD28                 (*(volatile unsigned long  *)0xFFFEEB70)
#define EIBD29                 (*(volatile unsigned long  *)0xFFFEEB74)
#define EIBD30                 (*(volatile unsigned long  *)0xFFFEEB78)
#define EIBD31                 (*(volatile unsigned long  *)0xFFFEEB7C)
#define CMPTST0                (*(volatile unsigned long  *)0xFFFEED00)
#define CMPTST0L               (*(volatile unsigned short *)0xFFFEED00)
#define CMPTST0LL              (*(volatile unsigned char  *)0xFFFEED00)
#define CMPTST0LH              (*(volatile unsigned char  *)0xFFFEED01)
#define CMPTST0H               (*(volatile unsigned short *)0xFFFEED02)
#define CMPTST0HL              (*(volatile unsigned char  *)0xFFFEED02)
#define CMPTST0HH              (*(volatile unsigned char  *)0xFFFEED03)
#define CMPTST1                (*(volatile unsigned long  *)0xFFFEED04)
#define CMPTST1L               (*(volatile unsigned short *)0xFFFEED04)
#define CMPTST1LL              (*(volatile unsigned char  *)0xFFFEED04)
#define CMPTST1LH              (*(volatile unsigned char  *)0xFFFEED05)
#define CMPTST1H               (*(volatile unsigned short *)0xFFFEED06)
#define CMPTST1HL              (*(volatile unsigned char  *)0xFFFEED06)
#define CMPTST1HH              (*(volatile unsigned char  *)0xFFFEED07)
#define TM_VER                 (*(volatile unsigned long  *)0xFFFF7800)
#define TM_CC                  (*(volatile unsigned long  *)0xFFFF7808)
#define TMA_ME                 (*(volatile unsigned long  *)0xFFFF7810)
#define TMA_MS                 (*(volatile unsigned long  *)0xFFFF7814)
#define TMB_ME                 (*(volatile unsigned long  *)0xFFFF7818)
#define TMB_MS                 (*(volatile unsigned long  *)0xFFFF781C)
#define TMA_MA0                (*(volatile unsigned long  *)0xFFFF7840)
#define TMA_MA1                (*(volatile unsigned long  *)0xFFFF7844)
#define TMA_MA2                (*(volatile unsigned long  *)0xFFFF7848)
#define TMA_MA3                (*(volatile unsigned long  *)0xFFFF784C)
#define TMA_MA4                (*(volatile unsigned long  *)0xFFFF7850)
#define TMA_MA5                (*(volatile unsigned long  *)0xFFFF7854)
#define TMA_MA6                (*(volatile unsigned long  *)0xFFFF7858)
#define TMA_MA7                (*(volatile unsigned long  *)0xFFFF785C)
#define TMA_MA8                (*(volatile unsigned long  *)0xFFFF7860)
#define TMA_MA9                (*(volatile unsigned long  *)0xFFFF7864)
#define TMA_MA10               (*(volatile unsigned long  *)0xFFFF7868)
#define TMA_MA11               (*(volatile unsigned long  *)0xFFFF786C)
#define TMA_MA12               (*(volatile unsigned long  *)0xFFFF7870)
#define TMA_MA13               (*(volatile unsigned long  *)0xFFFF7874)
#define TMA_MA14               (*(volatile unsigned long  *)0xFFFF7878)
#define TMA_MA15               (*(volatile unsigned long  *)0xFFFF787C)
#define TMA_MA16               (*(volatile unsigned long  *)0xFFFF7880)
#define TMA_MA17               (*(volatile unsigned long  *)0xFFFF7884)
#define TMA_MA18               (*(volatile unsigned long  *)0xFFFF7888)
#define TMA_MA19               (*(volatile unsigned long  *)0xFFFF788C)
#define TMA_MA20               (*(volatile unsigned long  *)0xFFFF7890)
#define TMA_MA21               (*(volatile unsigned long  *)0xFFFF7894)
#define TMA_MA22               (*(volatile unsigned long  *)0xFFFF7898)
#define TMA_MA23               (*(volatile unsigned long  *)0xFFFF789C)
#define TMA_MA24               (*(volatile unsigned long  *)0xFFFF78A0)
#define TMA_MA25               (*(volatile unsigned long  *)0xFFFF78A4)
#define TMA_MA26               (*(volatile unsigned long  *)0xFFFF78A8)
#define TMA_MA27               (*(volatile unsigned long  *)0xFFFF78AC)
#define TMA_MA28               (*(volatile unsigned long  *)0xFFFF78B0)
#define TMA_MA29               (*(volatile unsigned long  *)0xFFFF78B4)
#define TMA_MA30               (*(volatile unsigned long  *)0xFFFF78B8)
#define TMA_MA31               (*(volatile unsigned long  *)0xFFFF78BC)
#define TMB_MA0                (*(volatile unsigned long  *)0xFFFF78C0)
#define TMB_MA1                (*(volatile unsigned long  *)0xFFFF78C4)
#define TMB_MA2                (*(volatile unsigned long  *)0xFFFF78C8)
#define TMB_MA3                (*(volatile unsigned long  *)0xFFFF78CC)
#define TMB_MA4                (*(volatile unsigned long  *)0xFFFF78D0)
#define TMB_MA5                (*(volatile unsigned long  *)0xFFFF78D4)
#define TMB_MA6                (*(volatile unsigned long  *)0xFFFF78D8)
#define TMB_MA7                (*(volatile unsigned long  *)0xFFFF78DC)
#define TMB_MA8                (*(volatile unsigned long  *)0xFFFF78E0)
#define TMB_MA9                (*(volatile unsigned long  *)0xFFFF78E4)
#define TMB_MA10               (*(volatile unsigned long  *)0xFFFF78E8)
#define TMB_MA11               (*(volatile unsigned long  *)0xFFFF78EC)
#define TMB_MA12               (*(volatile unsigned long  *)0xFFFF78F0)
#define TMB_MA13               (*(volatile unsigned long  *)0xFFFF78F4)
#define TMB_MA14               (*(volatile unsigned long  *)0xFFFF78F8)
#define TMB_MA15               (*(volatile unsigned long  *)0xFFFF78FC)
#define TMB_MA16               (*(volatile unsigned long  *)0xFFFF7900)
#define TMB_MA17               (*(volatile unsigned long  *)0xFFFF7904)
#define TMB_MA18               (*(volatile unsigned long  *)0xFFFF7908)
#define TMB_MA19               (*(volatile unsigned long  *)0xFFFF790C)
#define TMB_MA20               (*(volatile unsigned long  *)0xFFFF7910)
#define TMB_MA21               (*(volatile unsigned long  *)0xFFFF7914)
#define TMB_MA22               (*(volatile unsigned long  *)0xFFFF7918)
#define TMB_MA23               (*(volatile unsigned long  *)0xFFFF791C)
#define TMB_MA24               (*(volatile unsigned long  *)0xFFFF7920)
#define TMB_MA25               (*(volatile unsigned long  *)0xFFFF7924)
#define TMB_MA26               (*(volatile unsigned long  *)0xFFFF7928)
#define TMB_MA27               (*(volatile unsigned long  *)0xFFFF792C)
#define TMB_MA28               (*(volatile unsigned long  *)0xFFFF7930)
#define TMB_MA29               (*(volatile unsigned long  *)0xFFFF7934)
#define TMB_MA30               (*(volatile unsigned long  *)0xFFFF7938)
#define TMB_MA31               (*(volatile unsigned long  *)0xFFFF793C)
#define GRAMC_WTBCONFIG0       (*(volatile unsigned long  *)0xFFFF7A04)
#define GRAMC_WTBCONFIG1       (*(volatile unsigned long  *)0xFFFF7A08)
#define GRAMC_WTBCONFIG2       (*(volatile unsigned long  *)0xFFFF7A0C)
#define DMACTL                 (*(volatile unsigned long  *)0xFFFF8000)
#define DTSCTL1                (*(volatile unsigned long  *)0xFFFF8010)
#define DTSCTL2                (*(volatile unsigned long  *)0xFFFF8014)
#define DTSSTS                 (*(volatile unsigned long  *)0xFFFF8018)
#define DMACER                 (*(volatile unsigned long  *)0xFFFF8020)
#define DTSER1                 (*(volatile unsigned long  *)0xFFFF8024)
#define DTSER2                 (*(volatile unsigned long  *)0xFFFF8028)
#define DTSERC                 (*(volatile unsigned long  *)0xFFFF802C)
#define DM0CMV                 (*(volatile unsigned long  *)0xFFFF8030)
#define DM1CMV                 (*(volatile unsigned long  *)0xFFFF8034)
#define DTSCMV                 (*(volatile unsigned long  *)0xFFFF8038)
#define CMVC                   (*(volatile unsigned long  *)0xFFFF803C)
#define TFRSTS                 (*(volatile unsigned long  *)0xFFFF804C)
#define DTSPR0                 (*(volatile unsigned long  *)0xFFFF8060)
#define DTSPR1                 (*(volatile unsigned long  *)0xFFFF8064)
#define DTSPR2                 (*(volatile unsigned long  *)0xFFFF8068)
#define DTSPR3                 (*(volatile unsigned long  *)0xFFFF806C)
#define DTSPR4                 (*(volatile unsigned long  *)0xFFFF8070)
#define DTSPR5                 (*(volatile unsigned long  *)0xFFFF8074)
#define DTSPR6                 (*(volatile unsigned long  *)0xFFFF8078)
#define DTSPR7                 (*(volatile unsigned long  *)0xFFFF807C)
#define DTRECCTL               (*(volatile unsigned long  *)0xFFFF8080)
#define DTRERINT               (*(volatile unsigned long  *)0xFFFF8084)
#define DTRTSCTL               (*(volatile unsigned long  *)0xFFFF8094)
#define DTRTWDAT               (*(volatile unsigned long  *)0xFFFF8098)
#define DTRTRDAT               (*(volatile unsigned long  *)0xFFFF809C)
#define ADECCTCL               (*(volatile unsigned long  *)0xFFFF80A0)
#define ADECCTDT               (*(volatile unsigned long  *)0xFFFF80A4)
#define DM00CM                 (*(volatile unsigned long  *)0xFFFF8100)
#define DM01CM                 (*(volatile unsigned long  *)0xFFFF8104)
#define DM02CM                 (*(volatile unsigned long  *)0xFFFF8108)
#define DM03CM                 (*(volatile unsigned long  *)0xFFFF810C)
#define DM04CM                 (*(volatile unsigned long  *)0xFFFF8110)
#define DM05CM                 (*(volatile unsigned long  *)0xFFFF8114)
#define DM06CM                 (*(volatile unsigned long  *)0xFFFF8118)
#define DM07CM                 (*(volatile unsigned long  *)0xFFFF811C)
#define DM10CM                 (*(volatile unsigned long  *)0xFFFF8120)
#define DM11CM                 (*(volatile unsigned long  *)0xFFFF8124)
#define DM12CM                 (*(volatile unsigned long  *)0xFFFF8128)
#define DM13CM                 (*(volatile unsigned long  *)0xFFFF812C)
#define DM14CM                 (*(volatile unsigned long  *)0xFFFF8130)
#define DM15CM                 (*(volatile unsigned long  *)0xFFFF8134)
#define DM16CM                 (*(volatile unsigned long  *)0xFFFF8138)
#define DM17CM                 (*(volatile unsigned long  *)0xFFFF813C)
#define DTS000CM               (*(volatile unsigned long  *)0xFFFF8200)
#define DTS001CM               (*(volatile unsigned long  *)0xFFFF8204)
#define DTS002CM               (*(volatile unsigned long  *)0xFFFF8208)
#define DTS003CM               (*(volatile unsigned long  *)0xFFFF820C)
#define DTS004CM               (*(volatile unsigned long  *)0xFFFF8210)
#define DTS005CM               (*(volatile unsigned long  *)0xFFFF8214)
#define DTS006CM               (*(volatile unsigned long  *)0xFFFF8218)
#define DTS007CM               (*(volatile unsigned long  *)0xFFFF821C)
#define DTS008CM               (*(volatile unsigned long  *)0xFFFF8220)
#define DTS009CM               (*(volatile unsigned long  *)0xFFFF8224)
#define DTS010CM               (*(volatile unsigned long  *)0xFFFF8228)
#define DTS011CM               (*(volatile unsigned long  *)0xFFFF822C)
#define DTS012CM               (*(volatile unsigned long  *)0xFFFF8230)
#define DTS013CM               (*(volatile unsigned long  *)0xFFFF8234)
#define DTS014CM               (*(volatile unsigned long  *)0xFFFF8238)
#define DTS015CM               (*(volatile unsigned long  *)0xFFFF823C)
#define DTS016CM               (*(volatile unsigned long  *)0xFFFF8240)
#define DTS017CM               (*(volatile unsigned long  *)0xFFFF8244)
#define DTS018CM               (*(volatile unsigned long  *)0xFFFF8248)
#define DTS019CM               (*(volatile unsigned long  *)0xFFFF824C)
#define DTS020CM               (*(volatile unsigned long  *)0xFFFF8250)
#define DTS021CM               (*(volatile unsigned long  *)0xFFFF8254)
#define DTS022CM               (*(volatile unsigned long  *)0xFFFF8258)
#define DTS023CM               (*(volatile unsigned long  *)0xFFFF825C)
#define DTS024CM               (*(volatile unsigned long  *)0xFFFF8260)
#define DTS025CM               (*(volatile unsigned long  *)0xFFFF8264)
#define DTS026CM               (*(volatile unsigned long  *)0xFFFF8268)
#define DTS027CM               (*(volatile unsigned long  *)0xFFFF826C)
#define DTS028CM               (*(volatile unsigned long  *)0xFFFF8270)
#define DTS029CM               (*(volatile unsigned long  *)0xFFFF8274)
#define DTS030CM               (*(volatile unsigned long  *)0xFFFF8278)
#define DTS031CM               (*(volatile unsigned long  *)0xFFFF827C)
#define DTS032CM               (*(volatile unsigned long  *)0xFFFF8280)
#define DTS033CM               (*(volatile unsigned long  *)0xFFFF8284)
#define DTS034CM               (*(volatile unsigned long  *)0xFFFF8288)
#define DTS035CM               (*(volatile unsigned long  *)0xFFFF828C)
#define DTS036CM               (*(volatile unsigned long  *)0xFFFF8290)
#define DTS037CM               (*(volatile unsigned long  *)0xFFFF8294)
#define DTS038CM               (*(volatile unsigned long  *)0xFFFF8298)
#define DTS039CM               (*(volatile unsigned long  *)0xFFFF829C)
#define DTS040CM               (*(volatile unsigned long  *)0xFFFF82A0)
#define DTS041CM               (*(volatile unsigned long  *)0xFFFF82A4)
#define DTS042CM               (*(volatile unsigned long  *)0xFFFF82A8)
#define DTS043CM               (*(volatile unsigned long  *)0xFFFF82AC)
#define DTS044CM               (*(volatile unsigned long  *)0xFFFF82B0)
#define DTS045CM               (*(volatile unsigned long  *)0xFFFF82B4)
#define DTS046CM               (*(volatile unsigned long  *)0xFFFF82B8)
#define DTS047CM               (*(volatile unsigned long  *)0xFFFF82BC)
#define DTS048CM               (*(volatile unsigned long  *)0xFFFF82C0)
#define DTS049CM               (*(volatile unsigned long  *)0xFFFF82C4)
#define DTS050CM               (*(volatile unsigned long  *)0xFFFF82C8)
#define DTS051CM               (*(volatile unsigned long  *)0xFFFF82CC)
#define DTS052CM               (*(volatile unsigned long  *)0xFFFF82D0)
#define DTS053CM               (*(volatile unsigned long  *)0xFFFF82D4)
#define DTS054CM               (*(volatile unsigned long  *)0xFFFF82D8)
#define DTS055CM               (*(volatile unsigned long  *)0xFFFF82DC)
#define DTS056CM               (*(volatile unsigned long  *)0xFFFF82E0)
#define DTS057CM               (*(volatile unsigned long  *)0xFFFF82E4)
#define DTS058CM               (*(volatile unsigned long  *)0xFFFF82E8)
#define DTS059CM               (*(volatile unsigned long  *)0xFFFF82EC)
#define DTS060CM               (*(volatile unsigned long  *)0xFFFF82F0)
#define DTS061CM               (*(volatile unsigned long  *)0xFFFF82F4)
#define DTS062CM               (*(volatile unsigned long  *)0xFFFF82F8)
#define DTS063CM               (*(volatile unsigned long  *)0xFFFF82FC)
#define DTS064CM               (*(volatile unsigned long  *)0xFFFF8300)
#define DTS065CM               (*(volatile unsigned long  *)0xFFFF8304)
#define DTS066CM               (*(volatile unsigned long  *)0xFFFF8308)
#define DTS067CM               (*(volatile unsigned long  *)0xFFFF830C)
#define DTS068CM               (*(volatile unsigned long  *)0xFFFF8310)
#define DTS069CM               (*(volatile unsigned long  *)0xFFFF8314)
#define DTS070CM               (*(volatile unsigned long  *)0xFFFF8318)
#define DTS071CM               (*(volatile unsigned long  *)0xFFFF831C)
#define DTS072CM               (*(volatile unsigned long  *)0xFFFF8320)
#define DTS073CM               (*(volatile unsigned long  *)0xFFFF8324)
#define DTS074CM               (*(volatile unsigned long  *)0xFFFF8328)
#define DTS075CM               (*(volatile unsigned long  *)0xFFFF832C)
#define DTS076CM               (*(volatile unsigned long  *)0xFFFF8330)
#define DTS077CM               (*(volatile unsigned long  *)0xFFFF8334)
#define DTS078CM               (*(volatile unsigned long  *)0xFFFF8338)
#define DTS079CM               (*(volatile unsigned long  *)0xFFFF833C)
#define DTS080CM               (*(volatile unsigned long  *)0xFFFF8340)
#define DTS081CM               (*(volatile unsigned long  *)0xFFFF8344)
#define DTS082CM               (*(volatile unsigned long  *)0xFFFF8348)
#define DTS083CM               (*(volatile unsigned long  *)0xFFFF834C)
#define DTS084CM               (*(volatile unsigned long  *)0xFFFF8350)
#define DTS085CM               (*(volatile unsigned long  *)0xFFFF8354)
#define DTS086CM               (*(volatile unsigned long  *)0xFFFF8358)
#define DTS087CM               (*(volatile unsigned long  *)0xFFFF835C)
#define DTS088CM               (*(volatile unsigned long  *)0xFFFF8360)
#define DTS089CM               (*(volatile unsigned long  *)0xFFFF8364)
#define DTS090CM               (*(volatile unsigned long  *)0xFFFF8368)
#define DTS091CM               (*(volatile unsigned long  *)0xFFFF836C)
#define DTS092CM               (*(volatile unsigned long  *)0xFFFF8370)
#define DTS093CM               (*(volatile unsigned long  *)0xFFFF8374)
#define DTS094CM               (*(volatile unsigned long  *)0xFFFF8378)
#define DTS095CM               (*(volatile unsigned long  *)0xFFFF837C)
#define DTS096CM               (*(volatile unsigned long  *)0xFFFF8380)
#define DTS097CM               (*(volatile unsigned long  *)0xFFFF8384)
#define DTS098CM               (*(volatile unsigned long  *)0xFFFF8388)
#define DTS099CM               (*(volatile unsigned long  *)0xFFFF838C)
#define DTS100CM               (*(volatile unsigned long  *)0xFFFF8390)
#define DTS101CM               (*(volatile unsigned long  *)0xFFFF8394)
#define DTS102CM               (*(volatile unsigned long  *)0xFFFF8398)
#define DTS103CM               (*(volatile unsigned long  *)0xFFFF839C)
#define DTS104CM               (*(volatile unsigned long  *)0xFFFF83A0)
#define DTS105CM               (*(volatile unsigned long  *)0xFFFF83A4)
#define DTS106CM               (*(volatile unsigned long  *)0xFFFF83A8)
#define DTS107CM               (*(volatile unsigned long  *)0xFFFF83AC)
#define DTS108CM               (*(volatile unsigned long  *)0xFFFF83B0)
#define DTS109CM               (*(volatile unsigned long  *)0xFFFF83B4)
#define DTS110CM               (*(volatile unsigned long  *)0xFFFF83B8)
#define DTS111CM               (*(volatile unsigned long  *)0xFFFF83BC)
#define DTS112CM               (*(volatile unsigned long  *)0xFFFF83C0)
#define DTS113CM               (*(volatile unsigned long  *)0xFFFF83C4)
#define DTS114CM               (*(volatile unsigned long  *)0xFFFF83C8)
#define DTS115CM               (*(volatile unsigned long  *)0xFFFF83CC)
#define DTS116CM               (*(volatile unsigned long  *)0xFFFF83D0)
#define DTS117CM               (*(volatile unsigned long  *)0xFFFF83D4)
#define DTS118CM               (*(volatile unsigned long  *)0xFFFF83D8)
#define DTS119CM               (*(volatile unsigned long  *)0xFFFF83DC)
#define DTS120CM               (*(volatile unsigned long  *)0xFFFF83E0)
#define DTS121CM               (*(volatile unsigned long  *)0xFFFF83E4)
#define DTS122CM               (*(volatile unsigned long  *)0xFFFF83E8)
#define DTS123CM               (*(volatile unsigned long  *)0xFFFF83EC)
#define DTS124CM               (*(volatile unsigned long  *)0xFFFF83F0)
#define DTS125CM               (*(volatile unsigned long  *)0xFFFF83F4)
#define DTS126CM               (*(volatile unsigned long  *)0xFFFF83F8)
#define DTS127CM               (*(volatile unsigned long  *)0xFFFF83FC)
#define DSA0                   (*(volatile unsigned long  *)0xFFFF8400)
#define DDA0                   (*(volatile unsigned long  *)0xFFFF8404)
#define DTC0                   (*(volatile unsigned long  *)0xFFFF8408)
#define DTCT0                  (*(volatile unsigned long  *)0xFFFF840C)
#define DRSA0                  (*(volatile unsigned long  *)0xFFFF8410)
#define DRDA0                  (*(volatile unsigned long  *)0xFFFF8414)
#define DRTC0                  (*(volatile unsigned long  *)0xFFFF8418)
#define DTCC0                  (*(volatile unsigned long  *)0xFFFF841C)
#define DCEN0                  (*(volatile unsigned long  *)0xFFFF8420)
#define DCST0                  (*(volatile unsigned long  *)0xFFFF8424)
#define DCSTS0                 (*(volatile unsigned long  *)0xFFFF8428)
#define DCSTC0                 (*(volatile unsigned long  *)0xFFFF842C)
#define DTFR0                  (*(volatile unsigned long  *)0xFFFF8430)
#define DTFRRQ0                (*(volatile unsigned long  *)0xFFFF8434)
#define DTFRRQC0               (*(volatile unsigned long  *)0xFFFF8438)
#define DSA1                   (*(volatile unsigned long  *)0xFFFF8440)
#define DDA1                   (*(volatile unsigned long  *)0xFFFF8444)
#define DTC1                   (*(volatile unsigned long  *)0xFFFF8448)
#define DTCT1                  (*(volatile unsigned long  *)0xFFFF844C)
#define DRSA1                  (*(volatile unsigned long  *)0xFFFF8450)
#define DRDA1                  (*(volatile unsigned long  *)0xFFFF8454)
#define DRTC1                  (*(volatile unsigned long  *)0xFFFF8458)
#define DTCC1                  (*(volatile unsigned long  *)0xFFFF845C)
#define DCEN1                  (*(volatile unsigned long  *)0xFFFF8460)
#define DCST1                  (*(volatile unsigned long  *)0xFFFF8464)
#define DCSTS1                 (*(volatile unsigned long  *)0xFFFF8468)
#define DCSTC1                 (*(volatile unsigned long  *)0xFFFF846C)
#define DTFR1                  (*(volatile unsigned long  *)0xFFFF8470)
#define DTFRRQ1                (*(volatile unsigned long  *)0xFFFF8474)
#define DTFRRQC1               (*(volatile unsigned long  *)0xFFFF8478)
#define DSA2                   (*(volatile unsigned long  *)0xFFFF8480)
#define DDA2                   (*(volatile unsigned long  *)0xFFFF8484)
#define DTC2                   (*(volatile unsigned long  *)0xFFFF8488)
#define DTCT2                  (*(volatile unsigned long  *)0xFFFF848C)
#define DRSA2                  (*(volatile unsigned long  *)0xFFFF8490)
#define DRDA2                  (*(volatile unsigned long  *)0xFFFF8494)
#define DRTC2                  (*(volatile unsigned long  *)0xFFFF8498)
#define DTCC2                  (*(volatile unsigned long  *)0xFFFF849C)
#define DCEN2                  (*(volatile unsigned long  *)0xFFFF84A0)
#define DCST2                  (*(volatile unsigned long  *)0xFFFF84A4)
#define DCSTS2                 (*(volatile unsigned long  *)0xFFFF84A8)
#define DCSTC2                 (*(volatile unsigned long  *)0xFFFF84AC)
#define DTFR2                  (*(volatile unsigned long  *)0xFFFF84B0)
#define DTFRRQ2                (*(volatile unsigned long  *)0xFFFF84B4)
#define DTFRRQC2               (*(volatile unsigned long  *)0xFFFF84B8)
#define DSA3                   (*(volatile unsigned long  *)0xFFFF84C0)
#define DDA3                   (*(volatile unsigned long  *)0xFFFF84C4)
#define DTC3                   (*(volatile unsigned long  *)0xFFFF84C8)
#define DTCT3                  (*(volatile unsigned long  *)0xFFFF84CC)
#define DRSA3                  (*(volatile unsigned long  *)0xFFFF84D0)
#define DRDA3                  (*(volatile unsigned long  *)0xFFFF84D4)
#define DRTC3                  (*(volatile unsigned long  *)0xFFFF84D8)
#define DTCC3                  (*(volatile unsigned long  *)0xFFFF84DC)
#define DCEN3                  (*(volatile unsigned long  *)0xFFFF84E0)
#define DCST3                  (*(volatile unsigned long  *)0xFFFF84E4)
#define DCSTS3                 (*(volatile unsigned long  *)0xFFFF84E8)
#define DCSTC3                 (*(volatile unsigned long  *)0xFFFF84EC)
#define DTFR3                  (*(volatile unsigned long  *)0xFFFF84F0)
#define DTFRRQ3                (*(volatile unsigned long  *)0xFFFF84F4)
#define DTFRRQC3               (*(volatile unsigned long  *)0xFFFF84F8)
#define DSA4                   (*(volatile unsigned long  *)0xFFFF8500)
#define DDA4                   (*(volatile unsigned long  *)0xFFFF8504)
#define DTC4                   (*(volatile unsigned long  *)0xFFFF8508)
#define DTCT4                  (*(volatile unsigned long  *)0xFFFF850C)
#define DRSA4                  (*(volatile unsigned long  *)0xFFFF8510)
#define DRDA4                  (*(volatile unsigned long  *)0xFFFF8514)
#define DRTC4                  (*(volatile unsigned long  *)0xFFFF8518)
#define DTCC4                  (*(volatile unsigned long  *)0xFFFF851C)
#define DCEN4                  (*(volatile unsigned long  *)0xFFFF8520)
#define DCST4                  (*(volatile unsigned long  *)0xFFFF8524)
#define DCSTS4                 (*(volatile unsigned long  *)0xFFFF8528)
#define DCSTC4                 (*(volatile unsigned long  *)0xFFFF852C)
#define DTFR4                  (*(volatile unsigned long  *)0xFFFF8530)
#define DTFRRQ4                (*(volatile unsigned long  *)0xFFFF8534)
#define DTFRRQC4               (*(volatile unsigned long  *)0xFFFF8538)
#define DSA5                   (*(volatile unsigned long  *)0xFFFF8540)
#define DDA5                   (*(volatile unsigned long  *)0xFFFF8544)
#define DTC5                   (*(volatile unsigned long  *)0xFFFF8548)
#define DTCT5                  (*(volatile unsigned long  *)0xFFFF854C)
#define DRSA5                  (*(volatile unsigned long  *)0xFFFF8550)
#define DRDA5                  (*(volatile unsigned long  *)0xFFFF8554)
#define DRTC5                  (*(volatile unsigned long  *)0xFFFF8558)
#define DTCC5                  (*(volatile unsigned long  *)0xFFFF855C)
#define DCEN5                  (*(volatile unsigned long  *)0xFFFF8560)
#define DCST5                  (*(volatile unsigned long  *)0xFFFF8564)
#define DCSTS5                 (*(volatile unsigned long  *)0xFFFF8568)
#define DCSTC5                 (*(volatile unsigned long  *)0xFFFF856C)
#define DTFR5                  (*(volatile unsigned long  *)0xFFFF8570)
#define DTFRRQ5                (*(volatile unsigned long  *)0xFFFF8574)
#define DTFRRQC5               (*(volatile unsigned long  *)0xFFFF8578)
#define DSA6                   (*(volatile unsigned long  *)0xFFFF8580)
#define DDA6                   (*(volatile unsigned long  *)0xFFFF8584)
#define DTC6                   (*(volatile unsigned long  *)0xFFFF8588)
#define DTCT6                  (*(volatile unsigned long  *)0xFFFF858C)
#define DRSA6                  (*(volatile unsigned long  *)0xFFFF8590)
#define DRDA6                  (*(volatile unsigned long  *)0xFFFF8594)
#define DRTC6                  (*(volatile unsigned long  *)0xFFFF8598)
#define DTCC6                  (*(volatile unsigned long  *)0xFFFF859C)
#define DCEN6                  (*(volatile unsigned long  *)0xFFFF85A0)
#define DCST6                  (*(volatile unsigned long  *)0xFFFF85A4)
#define DCSTS6                 (*(volatile unsigned long  *)0xFFFF85A8)
#define DCSTC6                 (*(volatile unsigned long  *)0xFFFF85AC)
#define DTFR6                  (*(volatile unsigned long  *)0xFFFF85B0)
#define DTFRRQ6                (*(volatile unsigned long  *)0xFFFF85B4)
#define DTFRRQC6               (*(volatile unsigned long  *)0xFFFF85B8)
#define DSA7                   (*(volatile unsigned long  *)0xFFFF85C0)
#define DDA7                   (*(volatile unsigned long  *)0xFFFF85C4)
#define DTC7                   (*(volatile unsigned long  *)0xFFFF85C8)
#define DTCT7                  (*(volatile unsigned long  *)0xFFFF85CC)
#define DRSA7                  (*(volatile unsigned long  *)0xFFFF85D0)
#define DRDA7                  (*(volatile unsigned long  *)0xFFFF85D4)
#define DRTC7                  (*(volatile unsigned long  *)0xFFFF85D8)
#define DTCC7                  (*(volatile unsigned long  *)0xFFFF85DC)
#define DCEN7                  (*(volatile unsigned long  *)0xFFFF85E0)
#define DCST7                  (*(volatile unsigned long  *)0xFFFF85E4)
#define DCSTS7                 (*(volatile unsigned long  *)0xFFFF85E8)
#define DCSTC7                 (*(volatile unsigned long  *)0xFFFF85EC)
#define DTFR7                  (*(volatile unsigned long  *)0xFFFF85F0)
#define DTFRRQ7                (*(volatile unsigned long  *)0xFFFF85F4)
#define DTFRRQC7               (*(volatile unsigned long  *)0xFFFF85F8)
#define DSA8                   (*(volatile unsigned long  *)0xFFFF8600)
#define DDA8                   (*(volatile unsigned long  *)0xFFFF8604)
#define DTC8                   (*(volatile unsigned long  *)0xFFFF8608)
#define DTCT8                  (*(volatile unsigned long  *)0xFFFF860C)
#define DRSA8                  (*(volatile unsigned long  *)0xFFFF8610)
#define DRDA8                  (*(volatile unsigned long  *)0xFFFF8614)
#define DRTC8                  (*(volatile unsigned long  *)0xFFFF8618)
#define DTCC8                  (*(volatile unsigned long  *)0xFFFF861C)
#define DCEN8                  (*(volatile unsigned long  *)0xFFFF8620)
#define DCST8                  (*(volatile unsigned long  *)0xFFFF8624)
#define DCSTS8                 (*(volatile unsigned long  *)0xFFFF8628)
#define DCSTC8                 (*(volatile unsigned long  *)0xFFFF862C)
#define DTFR8                  (*(volatile unsigned long  *)0xFFFF8630)
#define DTFRRQ8                (*(volatile unsigned long  *)0xFFFF8634)
#define DTFRRQC8               (*(volatile unsigned long  *)0xFFFF8638)
#define DSA9                   (*(volatile unsigned long  *)0xFFFF8640)
#define DDA9                   (*(volatile unsigned long  *)0xFFFF8644)
#define DTC9                   (*(volatile unsigned long  *)0xFFFF8648)
#define DTCT9                  (*(volatile unsigned long  *)0xFFFF864C)
#define DRSA9                  (*(volatile unsigned long  *)0xFFFF8650)
#define DRDA9                  (*(volatile unsigned long  *)0xFFFF8654)
#define DRTC9                  (*(volatile unsigned long  *)0xFFFF8658)
#define DTCC9                  (*(volatile unsigned long  *)0xFFFF865C)
#define DCEN9                  (*(volatile unsigned long  *)0xFFFF8660)
#define DCST9                  (*(volatile unsigned long  *)0xFFFF8664)
#define DCSTS9                 (*(volatile unsigned long  *)0xFFFF8668)
#define DCSTC9                 (*(volatile unsigned long  *)0xFFFF866C)
#define DTFR9                  (*(volatile unsigned long  *)0xFFFF8670)
#define DTFRRQ9                (*(volatile unsigned long  *)0xFFFF8674)
#define DTFRRQC9               (*(volatile unsigned long  *)0xFFFF8678)
#define DSA10                  (*(volatile unsigned long  *)0xFFFF8680)
#define DDA10                  (*(volatile unsigned long  *)0xFFFF8684)
#define DTC10                  (*(volatile unsigned long  *)0xFFFF8688)
#define DTCT10                 (*(volatile unsigned long  *)0xFFFF868C)
#define DRSA10                 (*(volatile unsigned long  *)0xFFFF8690)
#define DRDA10                 (*(volatile unsigned long  *)0xFFFF8694)
#define DRTC10                 (*(volatile unsigned long  *)0xFFFF8698)
#define DTCC10                 (*(volatile unsigned long  *)0xFFFF869C)
#define DCEN10                 (*(volatile unsigned long  *)0xFFFF86A0)
#define DCST10                 (*(volatile unsigned long  *)0xFFFF86A4)
#define DCSTS10                (*(volatile unsigned long  *)0xFFFF86A8)
#define DCSTC10                (*(volatile unsigned long  *)0xFFFF86AC)
#define DTFR10                 (*(volatile unsigned long  *)0xFFFF86B0)
#define DTFRRQ10               (*(volatile unsigned long  *)0xFFFF86B4)
#define DTFRRQC10              (*(volatile unsigned long  *)0xFFFF86B8)
#define DSA11                  (*(volatile unsigned long  *)0xFFFF86C0)
#define DDA11                  (*(volatile unsigned long  *)0xFFFF86C4)
#define DTC11                  (*(volatile unsigned long  *)0xFFFF86C8)
#define DTCT11                 (*(volatile unsigned long  *)0xFFFF86CC)
#define DRSA11                 (*(volatile unsigned long  *)0xFFFF86D0)
#define DRDA11                 (*(volatile unsigned long  *)0xFFFF86D4)
#define DRTC11                 (*(volatile unsigned long  *)0xFFFF86D8)
#define DTCC11                 (*(volatile unsigned long  *)0xFFFF86DC)
#define DCEN11                 (*(volatile unsigned long  *)0xFFFF86E0)
#define DCST11                 (*(volatile unsigned long  *)0xFFFF86E4)
#define DCSTS11                (*(volatile unsigned long  *)0xFFFF86E8)
#define DCSTC11                (*(volatile unsigned long  *)0xFFFF86EC)
#define DTFR11                 (*(volatile unsigned long  *)0xFFFF86F0)
#define DTFRRQ11               (*(volatile unsigned long  *)0xFFFF86F4)
#define DTFRRQC11              (*(volatile unsigned long  *)0xFFFF86F8)
#define DSA12                  (*(volatile unsigned long  *)0xFFFF8700)
#define DDA12                  (*(volatile unsigned long  *)0xFFFF8704)
#define DTC12                  (*(volatile unsigned long  *)0xFFFF8708)
#define DTCT12                 (*(volatile unsigned long  *)0xFFFF870C)
#define DRSA12                 (*(volatile unsigned long  *)0xFFFF8710)
#define DRDA12                 (*(volatile unsigned long  *)0xFFFF8714)
#define DRTC12                 (*(volatile unsigned long  *)0xFFFF8718)
#define DTCC12                 (*(volatile unsigned long  *)0xFFFF871C)
#define DCEN12                 (*(volatile unsigned long  *)0xFFFF8720)
#define DCST12                 (*(volatile unsigned long  *)0xFFFF8724)
#define DCSTS12                (*(volatile unsigned long  *)0xFFFF8728)
#define DCSTC12                (*(volatile unsigned long  *)0xFFFF872C)
#define DTFR12                 (*(volatile unsigned long  *)0xFFFF8730)
#define DTFRRQ12               (*(volatile unsigned long  *)0xFFFF8734)
#define DTFRRQC12              (*(volatile unsigned long  *)0xFFFF8738)
#define DSA13                  (*(volatile unsigned long  *)0xFFFF8740)
#define DDA13                  (*(volatile unsigned long  *)0xFFFF8744)
#define DTC13                  (*(volatile unsigned long  *)0xFFFF8748)
#define DTCT13                 (*(volatile unsigned long  *)0xFFFF874C)
#define DRSA13                 (*(volatile unsigned long  *)0xFFFF8750)
#define DRDA13                 (*(volatile unsigned long  *)0xFFFF8754)
#define DRTC13                 (*(volatile unsigned long  *)0xFFFF8758)
#define DTCC13                 (*(volatile unsigned long  *)0xFFFF875C)
#define DCEN13                 (*(volatile unsigned long  *)0xFFFF8760)
#define DCST13                 (*(volatile unsigned long  *)0xFFFF8764)
#define DCSTS13                (*(volatile unsigned long  *)0xFFFF8768)
#define DCSTC13                (*(volatile unsigned long  *)0xFFFF876C)
#define DTFR13                 (*(volatile unsigned long  *)0xFFFF8770)
#define DTFRRQ13               (*(volatile unsigned long  *)0xFFFF8774)
#define DTFRRQC13              (*(volatile unsigned long  *)0xFFFF8778)
#define DSA14                  (*(volatile unsigned long  *)0xFFFF8780)
#define DDA14                  (*(volatile unsigned long  *)0xFFFF8784)
#define DTC14                  (*(volatile unsigned long  *)0xFFFF8788)
#define DTCT14                 (*(volatile unsigned long  *)0xFFFF878C)
#define DRSA14                 (*(volatile unsigned long  *)0xFFFF8790)
#define DRDA14                 (*(volatile unsigned long  *)0xFFFF8794)
#define DRTC14                 (*(volatile unsigned long  *)0xFFFF8798)
#define DTCC14                 (*(volatile unsigned long  *)0xFFFF879C)
#define DCEN14                 (*(volatile unsigned long  *)0xFFFF87A0)
#define DCST14                 (*(volatile unsigned long  *)0xFFFF87A4)
#define DCSTS14                (*(volatile unsigned long  *)0xFFFF87A8)
#define DCSTC14                (*(volatile unsigned long  *)0xFFFF87AC)
#define DTFR14                 (*(volatile unsigned long  *)0xFFFF87B0)
#define DTFRRQ14               (*(volatile unsigned long  *)0xFFFF87B4)
#define DTFRRQC14              (*(volatile unsigned long  *)0xFFFF87B8)
#define DSA15                  (*(volatile unsigned long  *)0xFFFF87C0)
#define DDA15                  (*(volatile unsigned long  *)0xFFFF87C4)
#define DTC15                  (*(volatile unsigned long  *)0xFFFF87C8)
#define DTCT15                 (*(volatile unsigned long  *)0xFFFF87CC)
#define DRSA15                 (*(volatile unsigned long  *)0xFFFF87D0)
#define DRDA15                 (*(volatile unsigned long  *)0xFFFF87D4)
#define DRTC15                 (*(volatile unsigned long  *)0xFFFF87D8)
#define DTCC15                 (*(volatile unsigned long  *)0xFFFF87DC)
#define DCEN15                 (*(volatile unsigned long  *)0xFFFF87E0)
#define DCST15                 (*(volatile unsigned long  *)0xFFFF87E4)
#define DCSTS15                (*(volatile unsigned long  *)0xFFFF87E8)
#define DCSTC15                (*(volatile unsigned long  *)0xFFFF87EC)
#define DTFR15                 (*(volatile unsigned long  *)0xFFFF87F0)
#define DTFRRQ15               (*(volatile unsigned long  *)0xFFFF87F4)
#define DTFRRQC15              (*(volatile unsigned long  *)0xFFFF87F8)
#define DTSA000                (*(volatile unsigned long  *)0xFFFF9000)
#define DTDA000                (*(volatile unsigned long  *)0xFFFF9004)
#define DTTC000                (*(volatile unsigned long  *)0xFFFF9008)
#define DTTCT000               (*(volatile unsigned long  *)0xFFFF900C)
#define DTRSA000               (*(volatile unsigned long  *)0xFFFF9010)
#define DTRDA000               (*(volatile unsigned long  *)0xFFFF9014)
#define DTRTC000               (*(volatile unsigned long  *)0xFFFF9018)
#define DTTCC000               (*(volatile unsigned long  *)0xFFFF901C)
#define DTFSL000               (*(volatile unsigned long  *)0xFFFF9020)
#define DTFST000               (*(volatile unsigned long  *)0xFFFF9024)
#define DTFSS000               (*(volatile unsigned long  *)0xFFFF9028)
#define DTFSC000               (*(volatile unsigned long  *)0xFFFF902C)
#define DTSA001                (*(volatile unsigned long  *)0xFFFF9040)
#define DTDA001                (*(volatile unsigned long  *)0xFFFF9044)
#define DTTC001                (*(volatile unsigned long  *)0xFFFF9048)
#define DTTCT001               (*(volatile unsigned long  *)0xFFFF904C)
#define DTRSA001               (*(volatile unsigned long  *)0xFFFF9050)
#define DTRDA001               (*(volatile unsigned long  *)0xFFFF9054)
#define DTRTC001               (*(volatile unsigned long  *)0xFFFF9058)
#define DTTCC001               (*(volatile unsigned long  *)0xFFFF905C)
#define DTFSL001               (*(volatile unsigned long  *)0xFFFF9060)
#define DTFST001               (*(volatile unsigned long  *)0xFFFF9064)
#define DTFSS001               (*(volatile unsigned long  *)0xFFFF9068)
#define DTFSC001               (*(volatile unsigned long  *)0xFFFF906C)
#define DTSA002                (*(volatile unsigned long  *)0xFFFF9080)
#define DTDA002                (*(volatile unsigned long  *)0xFFFF9084)
#define DTTC002                (*(volatile unsigned long  *)0xFFFF9088)
#define DTTCT002               (*(volatile unsigned long  *)0xFFFF908C)
#define DTRSA002               (*(volatile unsigned long  *)0xFFFF9090)
#define DTRDA002               (*(volatile unsigned long  *)0xFFFF9094)
#define DTRTC002               (*(volatile unsigned long  *)0xFFFF9098)
#define DTTCC002               (*(volatile unsigned long  *)0xFFFF909C)
#define DTFSL002               (*(volatile unsigned long  *)0xFFFF90A0)
#define DTFST002               (*(volatile unsigned long  *)0xFFFF90A4)
#define DTFSS002               (*(volatile unsigned long  *)0xFFFF90A8)
#define DTFSC002               (*(volatile unsigned long  *)0xFFFF90AC)
#define DTSA003                (*(volatile unsigned long  *)0xFFFF90C0)
#define DTDA003                (*(volatile unsigned long  *)0xFFFF90C4)
#define DTTC003                (*(volatile unsigned long  *)0xFFFF90C8)
#define DTTCT003               (*(volatile unsigned long  *)0xFFFF90CC)
#define DTRSA003               (*(volatile unsigned long  *)0xFFFF90D0)
#define DTRDA003               (*(volatile unsigned long  *)0xFFFF90D4)
#define DTRTC003               (*(volatile unsigned long  *)0xFFFF90D8)
#define DTTCC003               (*(volatile unsigned long  *)0xFFFF90DC)
#define DTFSL003               (*(volatile unsigned long  *)0xFFFF90E0)
#define DTFST003               (*(volatile unsigned long  *)0xFFFF90E4)
#define DTFSS003               (*(volatile unsigned long  *)0xFFFF90E8)
#define DTFSC003               (*(volatile unsigned long  *)0xFFFF90EC)
#define DTSA004                (*(volatile unsigned long  *)0xFFFF9100)
#define DTDA004                (*(volatile unsigned long  *)0xFFFF9104)
#define DTTC004                (*(volatile unsigned long  *)0xFFFF9108)
#define DTTCT004               (*(volatile unsigned long  *)0xFFFF910C)
#define DTRSA004               (*(volatile unsigned long  *)0xFFFF9110)
#define DTRDA004               (*(volatile unsigned long  *)0xFFFF9114)
#define DTRTC004               (*(volatile unsigned long  *)0xFFFF9118)
#define DTTCC004               (*(volatile unsigned long  *)0xFFFF911C)
#define DTFSL004               (*(volatile unsigned long  *)0xFFFF9120)
#define DTFST004               (*(volatile unsigned long  *)0xFFFF9124)
#define DTFSS004               (*(volatile unsigned long  *)0xFFFF9128)
#define DTFSC004               (*(volatile unsigned long  *)0xFFFF912C)
#define DTSA005                (*(volatile unsigned long  *)0xFFFF9140)
#define DTDA005                (*(volatile unsigned long  *)0xFFFF9144)
#define DTTC005                (*(volatile unsigned long  *)0xFFFF9148)
#define DTTCT005               (*(volatile unsigned long  *)0xFFFF914C)
#define DTRSA005               (*(volatile unsigned long  *)0xFFFF9150)
#define DTRDA005               (*(volatile unsigned long  *)0xFFFF9154)
#define DTRTC005               (*(volatile unsigned long  *)0xFFFF9158)
#define DTTCC005               (*(volatile unsigned long  *)0xFFFF915C)
#define DTFSL005               (*(volatile unsigned long  *)0xFFFF9160)
#define DTFST005               (*(volatile unsigned long  *)0xFFFF9164)
#define DTFSS005               (*(volatile unsigned long  *)0xFFFF9168)
#define DTFSC005               (*(volatile unsigned long  *)0xFFFF916C)
#define DTSA006                (*(volatile unsigned long  *)0xFFFF9180)
#define DTDA006                (*(volatile unsigned long  *)0xFFFF9184)
#define DTTC006                (*(volatile unsigned long  *)0xFFFF9188)
#define DTTCT006               (*(volatile unsigned long  *)0xFFFF918C)
#define DTRSA006               (*(volatile unsigned long  *)0xFFFF9190)
#define DTRDA006               (*(volatile unsigned long  *)0xFFFF9194)
#define DTRTC006               (*(volatile unsigned long  *)0xFFFF9198)
#define DTTCC006               (*(volatile unsigned long  *)0xFFFF919C)
#define DTFSL006               (*(volatile unsigned long  *)0xFFFF91A0)
#define DTFST006               (*(volatile unsigned long  *)0xFFFF91A4)
#define DTFSS006               (*(volatile unsigned long  *)0xFFFF91A8)
#define DTFSC006               (*(volatile unsigned long  *)0xFFFF91AC)
#define DTSA007                (*(volatile unsigned long  *)0xFFFF91C0)
#define DTDA007                (*(volatile unsigned long  *)0xFFFF91C4)
#define DTTC007                (*(volatile unsigned long  *)0xFFFF91C8)
#define DTTCT007               (*(volatile unsigned long  *)0xFFFF91CC)
#define DTRSA007               (*(volatile unsigned long  *)0xFFFF91D0)
#define DTRDA007               (*(volatile unsigned long  *)0xFFFF91D4)
#define DTRTC007               (*(volatile unsigned long  *)0xFFFF91D8)
#define DTTCC007               (*(volatile unsigned long  *)0xFFFF91DC)
#define DTFSL007               (*(volatile unsigned long  *)0xFFFF91E0)
#define DTFST007               (*(volatile unsigned long  *)0xFFFF91E4)
#define DTFSS007               (*(volatile unsigned long  *)0xFFFF91E8)
#define DTFSC007               (*(volatile unsigned long  *)0xFFFF91EC)
#define DTSA008                (*(volatile unsigned long  *)0xFFFF9200)
#define DTDA008                (*(volatile unsigned long  *)0xFFFF9204)
#define DTTC008                (*(volatile unsigned long  *)0xFFFF9208)
#define DTTCT008               (*(volatile unsigned long  *)0xFFFF920C)
#define DTRSA008               (*(volatile unsigned long  *)0xFFFF9210)
#define DTRDA008               (*(volatile unsigned long  *)0xFFFF9214)
#define DTRTC008               (*(volatile unsigned long  *)0xFFFF9218)
#define DTTCC008               (*(volatile unsigned long  *)0xFFFF921C)
#define DTFSL008               (*(volatile unsigned long  *)0xFFFF9220)
#define DTFST008               (*(volatile unsigned long  *)0xFFFF9224)
#define DTFSS008               (*(volatile unsigned long  *)0xFFFF9228)
#define DTFSC008               (*(volatile unsigned long  *)0xFFFF922C)
#define DTSA009                (*(volatile unsigned long  *)0xFFFF9240)
#define DTDA009                (*(volatile unsigned long  *)0xFFFF9244)
#define DTTC009                (*(volatile unsigned long  *)0xFFFF9248)
#define DTTCT009               (*(volatile unsigned long  *)0xFFFF924C)
#define DTRSA009               (*(volatile unsigned long  *)0xFFFF9250)
#define DTRDA009               (*(volatile unsigned long  *)0xFFFF9254)
#define DTRTC009               (*(volatile unsigned long  *)0xFFFF9258)
#define DTTCC009               (*(volatile unsigned long  *)0xFFFF925C)
#define DTFSL009               (*(volatile unsigned long  *)0xFFFF9260)
#define DTFST009               (*(volatile unsigned long  *)0xFFFF9264)
#define DTFSS009               (*(volatile unsigned long  *)0xFFFF9268)
#define DTFSC009               (*(volatile unsigned long  *)0xFFFF926C)
#define DTSA010                (*(volatile unsigned long  *)0xFFFF9280)
#define DTDA010                (*(volatile unsigned long  *)0xFFFF9284)
#define DTTC010                (*(volatile unsigned long  *)0xFFFF9288)
#define DTTCT010               (*(volatile unsigned long  *)0xFFFF928C)
#define DTRSA010               (*(volatile unsigned long  *)0xFFFF9290)
#define DTRDA010               (*(volatile unsigned long  *)0xFFFF9294)
#define DTRTC010               (*(volatile unsigned long  *)0xFFFF9298)
#define DTTCC010               (*(volatile unsigned long  *)0xFFFF929C)
#define DTFSL010               (*(volatile unsigned long  *)0xFFFF92A0)
#define DTFST010               (*(volatile unsigned long  *)0xFFFF92A4)
#define DTFSS010               (*(volatile unsigned long  *)0xFFFF92A8)
#define DTFSC010               (*(volatile unsigned long  *)0xFFFF92AC)
#define DTSA011                (*(volatile unsigned long  *)0xFFFF92C0)
#define DTDA011                (*(volatile unsigned long  *)0xFFFF92C4)
#define DTTC011                (*(volatile unsigned long  *)0xFFFF92C8)
#define DTTCT011               (*(volatile unsigned long  *)0xFFFF92CC)
#define DTRSA011               (*(volatile unsigned long  *)0xFFFF92D0)
#define DTRDA011               (*(volatile unsigned long  *)0xFFFF92D4)
#define DTRTC011               (*(volatile unsigned long  *)0xFFFF92D8)
#define DTTCC011               (*(volatile unsigned long  *)0xFFFF92DC)
#define DTFSL011               (*(volatile unsigned long  *)0xFFFF92E0)
#define DTFST011               (*(volatile unsigned long  *)0xFFFF92E4)
#define DTFSS011               (*(volatile unsigned long  *)0xFFFF92E8)
#define DTFSC011               (*(volatile unsigned long  *)0xFFFF92EC)
#define DTSA012                (*(volatile unsigned long  *)0xFFFF9300)
#define DTDA012                (*(volatile unsigned long  *)0xFFFF9304)
#define DTTC012                (*(volatile unsigned long  *)0xFFFF9308)
#define DTTCT012               (*(volatile unsigned long  *)0xFFFF930C)
#define DTRSA012               (*(volatile unsigned long  *)0xFFFF9310)
#define DTRDA012               (*(volatile unsigned long  *)0xFFFF9314)
#define DTRTC012               (*(volatile unsigned long  *)0xFFFF9318)
#define DTTCC012               (*(volatile unsigned long  *)0xFFFF931C)
#define DTFSL012               (*(volatile unsigned long  *)0xFFFF9320)
#define DTFST012               (*(volatile unsigned long  *)0xFFFF9324)
#define DTFSS012               (*(volatile unsigned long  *)0xFFFF9328)
#define DTFSC012               (*(volatile unsigned long  *)0xFFFF932C)
#define DTSA013                (*(volatile unsigned long  *)0xFFFF9340)
#define DTDA013                (*(volatile unsigned long  *)0xFFFF9344)
#define DTTC013                (*(volatile unsigned long  *)0xFFFF9348)
#define DTTCT013               (*(volatile unsigned long  *)0xFFFF934C)
#define DTRSA013               (*(volatile unsigned long  *)0xFFFF9350)
#define DTRDA013               (*(volatile unsigned long  *)0xFFFF9354)
#define DTRTC013               (*(volatile unsigned long  *)0xFFFF9358)
#define DTTCC013               (*(volatile unsigned long  *)0xFFFF935C)
#define DTFSL013               (*(volatile unsigned long  *)0xFFFF9360)
#define DTFST013               (*(volatile unsigned long  *)0xFFFF9364)
#define DTFSS013               (*(volatile unsigned long  *)0xFFFF9368)
#define DTFSC013               (*(volatile unsigned long  *)0xFFFF936C)
#define DTSA014                (*(volatile unsigned long  *)0xFFFF9380)
#define DTDA014                (*(volatile unsigned long  *)0xFFFF9384)
#define DTTC014                (*(volatile unsigned long  *)0xFFFF9388)
#define DTTCT014               (*(volatile unsigned long  *)0xFFFF938C)
#define DTRSA014               (*(volatile unsigned long  *)0xFFFF9390)
#define DTRDA014               (*(volatile unsigned long  *)0xFFFF9394)
#define DTRTC014               (*(volatile unsigned long  *)0xFFFF9398)
#define DTTCC014               (*(volatile unsigned long  *)0xFFFF939C)
#define DTFSL014               (*(volatile unsigned long  *)0xFFFF93A0)
#define DTFST014               (*(volatile unsigned long  *)0xFFFF93A4)
#define DTFSS014               (*(volatile unsigned long  *)0xFFFF93A8)
#define DTFSC014               (*(volatile unsigned long  *)0xFFFF93AC)
#define DTSA015                (*(volatile unsigned long  *)0xFFFF93C0)
#define DTDA015                (*(volatile unsigned long  *)0xFFFF93C4)
#define DTTC015                (*(volatile unsigned long  *)0xFFFF93C8)
#define DTTCT015               (*(volatile unsigned long  *)0xFFFF93CC)
#define DTRSA015               (*(volatile unsigned long  *)0xFFFF93D0)
#define DTRDA015               (*(volatile unsigned long  *)0xFFFF93D4)
#define DTRTC015               (*(volatile unsigned long  *)0xFFFF93D8)
#define DTTCC015               (*(volatile unsigned long  *)0xFFFF93DC)
#define DTFSL015               (*(volatile unsigned long  *)0xFFFF93E0)
#define DTFST015               (*(volatile unsigned long  *)0xFFFF93E4)
#define DTFSS015               (*(volatile unsigned long  *)0xFFFF93E8)
#define DTFSC015               (*(volatile unsigned long  *)0xFFFF93EC)
#define DTSA016                (*(volatile unsigned long  *)0xFFFF9400)
#define DTDA016                (*(volatile unsigned long  *)0xFFFF9404)
#define DTTC016                (*(volatile unsigned long  *)0xFFFF9408)
#define DTTCT016               (*(volatile unsigned long  *)0xFFFF940C)
#define DTRSA016               (*(volatile unsigned long  *)0xFFFF9410)
#define DTRDA016               (*(volatile unsigned long  *)0xFFFF9414)
#define DTRTC016               (*(volatile unsigned long  *)0xFFFF9418)
#define DTTCC016               (*(volatile unsigned long  *)0xFFFF941C)
#define DTFSL016               (*(volatile unsigned long  *)0xFFFF9420)
#define DTFST016               (*(volatile unsigned long  *)0xFFFF9424)
#define DTFSS016               (*(volatile unsigned long  *)0xFFFF9428)
#define DTFSC016               (*(volatile unsigned long  *)0xFFFF942C)
#define DTSA017                (*(volatile unsigned long  *)0xFFFF9440)
#define DTDA017                (*(volatile unsigned long  *)0xFFFF9444)
#define DTTC017                (*(volatile unsigned long  *)0xFFFF9448)
#define DTTCT017               (*(volatile unsigned long  *)0xFFFF944C)
#define DTRSA017               (*(volatile unsigned long  *)0xFFFF9450)
#define DTRDA017               (*(volatile unsigned long  *)0xFFFF9454)
#define DTRTC017               (*(volatile unsigned long  *)0xFFFF9458)
#define DTTCC017               (*(volatile unsigned long  *)0xFFFF945C)
#define DTFSL017               (*(volatile unsigned long  *)0xFFFF9460)
#define DTFST017               (*(volatile unsigned long  *)0xFFFF9464)
#define DTFSS017               (*(volatile unsigned long  *)0xFFFF9468)
#define DTFSC017               (*(volatile unsigned long  *)0xFFFF946C)
#define DTSA018                (*(volatile unsigned long  *)0xFFFF9480)
#define DTDA018                (*(volatile unsigned long  *)0xFFFF9484)
#define DTTC018                (*(volatile unsigned long  *)0xFFFF9488)
#define DTTCT018               (*(volatile unsigned long  *)0xFFFF948C)
#define DTRSA018               (*(volatile unsigned long  *)0xFFFF9490)
#define DTRDA018               (*(volatile unsigned long  *)0xFFFF9494)
#define DTRTC018               (*(volatile unsigned long  *)0xFFFF9498)
#define DTTCC018               (*(volatile unsigned long  *)0xFFFF949C)
#define DTFSL018               (*(volatile unsigned long  *)0xFFFF94A0)
#define DTFST018               (*(volatile unsigned long  *)0xFFFF94A4)
#define DTFSS018               (*(volatile unsigned long  *)0xFFFF94A8)
#define DTFSC018               (*(volatile unsigned long  *)0xFFFF94AC)
#define DTSA019                (*(volatile unsigned long  *)0xFFFF94C0)
#define DTDA019                (*(volatile unsigned long  *)0xFFFF94C4)
#define DTTC019                (*(volatile unsigned long  *)0xFFFF94C8)
#define DTTCT019               (*(volatile unsigned long  *)0xFFFF94CC)
#define DTRSA019               (*(volatile unsigned long  *)0xFFFF94D0)
#define DTRDA019               (*(volatile unsigned long  *)0xFFFF94D4)
#define DTRTC019               (*(volatile unsigned long  *)0xFFFF94D8)
#define DTTCC019               (*(volatile unsigned long  *)0xFFFF94DC)
#define DTFSL019               (*(volatile unsigned long  *)0xFFFF94E0)
#define DTFST019               (*(volatile unsigned long  *)0xFFFF94E4)
#define DTFSS019               (*(volatile unsigned long  *)0xFFFF94E8)
#define DTFSC019               (*(volatile unsigned long  *)0xFFFF94EC)
#define DTSA020                (*(volatile unsigned long  *)0xFFFF9500)
#define DTDA020                (*(volatile unsigned long  *)0xFFFF9504)
#define DTTC020                (*(volatile unsigned long  *)0xFFFF9508)
#define DTTCT020               (*(volatile unsigned long  *)0xFFFF950C)
#define DTRSA020               (*(volatile unsigned long  *)0xFFFF9510)
#define DTRDA020               (*(volatile unsigned long  *)0xFFFF9514)
#define DTRTC020               (*(volatile unsigned long  *)0xFFFF9518)
#define DTTCC020               (*(volatile unsigned long  *)0xFFFF951C)
#define DTFSL020               (*(volatile unsigned long  *)0xFFFF9520)
#define DTFST020               (*(volatile unsigned long  *)0xFFFF9524)
#define DTFSS020               (*(volatile unsigned long  *)0xFFFF9528)
#define DTFSC020               (*(volatile unsigned long  *)0xFFFF952C)
#define DTSA021                (*(volatile unsigned long  *)0xFFFF9540)
#define DTDA021                (*(volatile unsigned long  *)0xFFFF9544)
#define DTTC021                (*(volatile unsigned long  *)0xFFFF9548)
#define DTTCT021               (*(volatile unsigned long  *)0xFFFF954C)
#define DTRSA021               (*(volatile unsigned long  *)0xFFFF9550)
#define DTRDA021               (*(volatile unsigned long  *)0xFFFF9554)
#define DTRTC021               (*(volatile unsigned long  *)0xFFFF9558)
#define DTTCC021               (*(volatile unsigned long  *)0xFFFF955C)
#define DTFSL021               (*(volatile unsigned long  *)0xFFFF9560)
#define DTFST021               (*(volatile unsigned long  *)0xFFFF9564)
#define DTFSS021               (*(volatile unsigned long  *)0xFFFF9568)
#define DTFSC021               (*(volatile unsigned long  *)0xFFFF956C)
#define DTSA022                (*(volatile unsigned long  *)0xFFFF9580)
#define DTDA022                (*(volatile unsigned long  *)0xFFFF9584)
#define DTTC022                (*(volatile unsigned long  *)0xFFFF9588)
#define DTTCT022               (*(volatile unsigned long  *)0xFFFF958C)
#define DTRSA022               (*(volatile unsigned long  *)0xFFFF9590)
#define DTRDA022               (*(volatile unsigned long  *)0xFFFF9594)
#define DTRTC022               (*(volatile unsigned long  *)0xFFFF9598)
#define DTTCC022               (*(volatile unsigned long  *)0xFFFF959C)
#define DTFSL022               (*(volatile unsigned long  *)0xFFFF95A0)
#define DTFST022               (*(volatile unsigned long  *)0xFFFF95A4)
#define DTFSS022               (*(volatile unsigned long  *)0xFFFF95A8)
#define DTFSC022               (*(volatile unsigned long  *)0xFFFF95AC)
#define DTSA023                (*(volatile unsigned long  *)0xFFFF95C0)
#define DTDA023                (*(volatile unsigned long  *)0xFFFF95C4)
#define DTTC023                (*(volatile unsigned long  *)0xFFFF95C8)
#define DTTCT023               (*(volatile unsigned long  *)0xFFFF95CC)
#define DTRSA023               (*(volatile unsigned long  *)0xFFFF95D0)
#define DTRDA023               (*(volatile unsigned long  *)0xFFFF95D4)
#define DTRTC023               (*(volatile unsigned long  *)0xFFFF95D8)
#define DTTCC023               (*(volatile unsigned long  *)0xFFFF95DC)
#define DTFSL023               (*(volatile unsigned long  *)0xFFFF95E0)
#define DTFST023               (*(volatile unsigned long  *)0xFFFF95E4)
#define DTFSS023               (*(volatile unsigned long  *)0xFFFF95E8)
#define DTFSC023               (*(volatile unsigned long  *)0xFFFF95EC)
#define DTSA024                (*(volatile unsigned long  *)0xFFFF9600)
#define DTDA024                (*(volatile unsigned long  *)0xFFFF9604)
#define DTTC024                (*(volatile unsigned long  *)0xFFFF9608)
#define DTTCT024               (*(volatile unsigned long  *)0xFFFF960C)
#define DTRSA024               (*(volatile unsigned long  *)0xFFFF9610)
#define DTRDA024               (*(volatile unsigned long  *)0xFFFF9614)
#define DTRTC024               (*(volatile unsigned long  *)0xFFFF9618)
#define DTTCC024               (*(volatile unsigned long  *)0xFFFF961C)
#define DTFSL024               (*(volatile unsigned long  *)0xFFFF9620)
#define DTFST024               (*(volatile unsigned long  *)0xFFFF9624)
#define DTFSS024               (*(volatile unsigned long  *)0xFFFF9628)
#define DTFSC024               (*(volatile unsigned long  *)0xFFFF962C)
#define DTSA025                (*(volatile unsigned long  *)0xFFFF9640)
#define DTDA025                (*(volatile unsigned long  *)0xFFFF9644)
#define DTTC025                (*(volatile unsigned long  *)0xFFFF9648)
#define DTTCT025               (*(volatile unsigned long  *)0xFFFF964C)
#define DTRSA025               (*(volatile unsigned long  *)0xFFFF9650)
#define DTRDA025               (*(volatile unsigned long  *)0xFFFF9654)
#define DTRTC025               (*(volatile unsigned long  *)0xFFFF9658)
#define DTTCC025               (*(volatile unsigned long  *)0xFFFF965C)
#define DTFSL025               (*(volatile unsigned long  *)0xFFFF9660)
#define DTFST025               (*(volatile unsigned long  *)0xFFFF9664)
#define DTFSS025               (*(volatile unsigned long  *)0xFFFF9668)
#define DTFSC025               (*(volatile unsigned long  *)0xFFFF966C)
#define DTSA026                (*(volatile unsigned long  *)0xFFFF9680)
#define DTDA026                (*(volatile unsigned long  *)0xFFFF9684)
#define DTTC026                (*(volatile unsigned long  *)0xFFFF9688)
#define DTTCT026               (*(volatile unsigned long  *)0xFFFF968C)
#define DTRSA026               (*(volatile unsigned long  *)0xFFFF9690)
#define DTRDA026               (*(volatile unsigned long  *)0xFFFF9694)
#define DTRTC026               (*(volatile unsigned long  *)0xFFFF9698)
#define DTTCC026               (*(volatile unsigned long  *)0xFFFF969C)
#define DTFSL026               (*(volatile unsigned long  *)0xFFFF96A0)
#define DTFST026               (*(volatile unsigned long  *)0xFFFF96A4)
#define DTFSS026               (*(volatile unsigned long  *)0xFFFF96A8)
#define DTFSC026               (*(volatile unsigned long  *)0xFFFF96AC)
#define DTSA027                (*(volatile unsigned long  *)0xFFFF96C0)
#define DTDA027                (*(volatile unsigned long  *)0xFFFF96C4)
#define DTTC027                (*(volatile unsigned long  *)0xFFFF96C8)
#define DTTCT027               (*(volatile unsigned long  *)0xFFFF96CC)
#define DTRSA027               (*(volatile unsigned long  *)0xFFFF96D0)
#define DTRDA027               (*(volatile unsigned long  *)0xFFFF96D4)
#define DTRTC027               (*(volatile unsigned long  *)0xFFFF96D8)
#define DTTCC027               (*(volatile unsigned long  *)0xFFFF96DC)
#define DTFSL027               (*(volatile unsigned long  *)0xFFFF96E0)
#define DTFST027               (*(volatile unsigned long  *)0xFFFF96E4)
#define DTFSS027               (*(volatile unsigned long  *)0xFFFF96E8)
#define DTFSC027               (*(volatile unsigned long  *)0xFFFF96EC)
#define DTSA028                (*(volatile unsigned long  *)0xFFFF9700)
#define DTDA028                (*(volatile unsigned long  *)0xFFFF9704)
#define DTTC028                (*(volatile unsigned long  *)0xFFFF9708)
#define DTTCT028               (*(volatile unsigned long  *)0xFFFF970C)
#define DTRSA028               (*(volatile unsigned long  *)0xFFFF9710)
#define DTRDA028               (*(volatile unsigned long  *)0xFFFF9714)
#define DTRTC028               (*(volatile unsigned long  *)0xFFFF9718)
#define DTTCC028               (*(volatile unsigned long  *)0xFFFF971C)
#define DTFSL028               (*(volatile unsigned long  *)0xFFFF9720)
#define DTFST028               (*(volatile unsigned long  *)0xFFFF9724)
#define DTFSS028               (*(volatile unsigned long  *)0xFFFF9728)
#define DTFSC028               (*(volatile unsigned long  *)0xFFFF972C)
#define DTSA029                (*(volatile unsigned long  *)0xFFFF9740)
#define DTDA029                (*(volatile unsigned long  *)0xFFFF9744)
#define DTTC029                (*(volatile unsigned long  *)0xFFFF9748)
#define DTTCT029               (*(volatile unsigned long  *)0xFFFF974C)
#define DTRSA029               (*(volatile unsigned long  *)0xFFFF9750)
#define DTRDA029               (*(volatile unsigned long  *)0xFFFF9754)
#define DTRTC029               (*(volatile unsigned long  *)0xFFFF9758)
#define DTTCC029               (*(volatile unsigned long  *)0xFFFF975C)
#define DTFSL029               (*(volatile unsigned long  *)0xFFFF9760)
#define DTFST029               (*(volatile unsigned long  *)0xFFFF9764)
#define DTFSS029               (*(volatile unsigned long  *)0xFFFF9768)
#define DTFSC029               (*(volatile unsigned long  *)0xFFFF976C)
#define DTSA030                (*(volatile unsigned long  *)0xFFFF9780)
#define DTDA030                (*(volatile unsigned long  *)0xFFFF9784)
#define DTTC030                (*(volatile unsigned long  *)0xFFFF9788)
#define DTTCT030               (*(volatile unsigned long  *)0xFFFF978C)
#define DTRSA030               (*(volatile unsigned long  *)0xFFFF9790)
#define DTRDA030               (*(volatile unsigned long  *)0xFFFF9794)
#define DTRTC030               (*(volatile unsigned long  *)0xFFFF9798)
#define DTTCC030               (*(volatile unsigned long  *)0xFFFF979C)
#define DTFSL030               (*(volatile unsigned long  *)0xFFFF97A0)
#define DTFST030               (*(volatile unsigned long  *)0xFFFF97A4)
#define DTFSS030               (*(volatile unsigned long  *)0xFFFF97A8)
#define DTFSC030               (*(volatile unsigned long  *)0xFFFF97AC)
#define DTSA031                (*(volatile unsigned long  *)0xFFFF97C0)
#define DTDA031                (*(volatile unsigned long  *)0xFFFF97C4)
#define DTTC031                (*(volatile unsigned long  *)0xFFFF97C8)
#define DTTCT031               (*(volatile unsigned long  *)0xFFFF97CC)
#define DTRSA031               (*(volatile unsigned long  *)0xFFFF97D0)
#define DTRDA031               (*(volatile unsigned long  *)0xFFFF97D4)
#define DTRTC031               (*(volatile unsigned long  *)0xFFFF97D8)
#define DTTCC031               (*(volatile unsigned long  *)0xFFFF97DC)
#define DTFSL031               (*(volatile unsigned long  *)0xFFFF97E0)
#define DTFST031               (*(volatile unsigned long  *)0xFFFF97E4)
#define DTFSS031               (*(volatile unsigned long  *)0xFFFF97E8)
#define DTFSC031               (*(volatile unsigned long  *)0xFFFF97EC)
#define DTSA032                (*(volatile unsigned long  *)0xFFFF9800)
#define DTDA032                (*(volatile unsigned long  *)0xFFFF9804)
#define DTTC032                (*(volatile unsigned long  *)0xFFFF9808)
#define DTTCT032               (*(volatile unsigned long  *)0xFFFF980C)
#define DTRSA032               (*(volatile unsigned long  *)0xFFFF9810)
#define DTRDA032               (*(volatile unsigned long  *)0xFFFF9814)
#define DTRTC032               (*(volatile unsigned long  *)0xFFFF9818)
#define DTTCC032               (*(volatile unsigned long  *)0xFFFF981C)
#define DTFSL032               (*(volatile unsigned long  *)0xFFFF9820)
#define DTFST032               (*(volatile unsigned long  *)0xFFFF9824)
#define DTFSS032               (*(volatile unsigned long  *)0xFFFF9828)
#define DTFSC032               (*(volatile unsigned long  *)0xFFFF982C)
#define DTSA033                (*(volatile unsigned long  *)0xFFFF9840)
#define DTDA033                (*(volatile unsigned long  *)0xFFFF9844)
#define DTTC033                (*(volatile unsigned long  *)0xFFFF9848)
#define DTTCT033               (*(volatile unsigned long  *)0xFFFF984C)
#define DTRSA033               (*(volatile unsigned long  *)0xFFFF9850)
#define DTRDA033               (*(volatile unsigned long  *)0xFFFF9854)
#define DTRTC033               (*(volatile unsigned long  *)0xFFFF9858)
#define DTTCC033               (*(volatile unsigned long  *)0xFFFF985C)
#define DTFSL033               (*(volatile unsigned long  *)0xFFFF9860)
#define DTFST033               (*(volatile unsigned long  *)0xFFFF9864)
#define DTFSS033               (*(volatile unsigned long  *)0xFFFF9868)
#define DTFSC033               (*(volatile unsigned long  *)0xFFFF986C)
#define DTSA034                (*(volatile unsigned long  *)0xFFFF9880)
#define DTDA034                (*(volatile unsigned long  *)0xFFFF9884)
#define DTTC034                (*(volatile unsigned long  *)0xFFFF9888)
#define DTTCT034               (*(volatile unsigned long  *)0xFFFF988C)
#define DTRSA034               (*(volatile unsigned long  *)0xFFFF9890)
#define DTRDA034               (*(volatile unsigned long  *)0xFFFF9894)
#define DTRTC034               (*(volatile unsigned long  *)0xFFFF9898)
#define DTTCC034               (*(volatile unsigned long  *)0xFFFF989C)
#define DTFSL034               (*(volatile unsigned long  *)0xFFFF98A0)
#define DTFST034               (*(volatile unsigned long  *)0xFFFF98A4)
#define DTFSS034               (*(volatile unsigned long  *)0xFFFF98A8)
#define DTFSC034               (*(volatile unsigned long  *)0xFFFF98AC)
#define DTSA035                (*(volatile unsigned long  *)0xFFFF98C0)
#define DTDA035                (*(volatile unsigned long  *)0xFFFF98C4)
#define DTTC035                (*(volatile unsigned long  *)0xFFFF98C8)
#define DTTCT035               (*(volatile unsigned long  *)0xFFFF98CC)
#define DTRSA035               (*(volatile unsigned long  *)0xFFFF98D0)
#define DTRDA035               (*(volatile unsigned long  *)0xFFFF98D4)
#define DTRTC035               (*(volatile unsigned long  *)0xFFFF98D8)
#define DTTCC035               (*(volatile unsigned long  *)0xFFFF98DC)
#define DTFSL035               (*(volatile unsigned long  *)0xFFFF98E0)
#define DTFST035               (*(volatile unsigned long  *)0xFFFF98E4)
#define DTFSS035               (*(volatile unsigned long  *)0xFFFF98E8)
#define DTFSC035               (*(volatile unsigned long  *)0xFFFF98EC)
#define DTSA036                (*(volatile unsigned long  *)0xFFFF9900)
#define DTDA036                (*(volatile unsigned long  *)0xFFFF9904)
#define DTTC036                (*(volatile unsigned long  *)0xFFFF9908)
#define DTTCT036               (*(volatile unsigned long  *)0xFFFF990C)
#define DTRSA036               (*(volatile unsigned long  *)0xFFFF9910)
#define DTRDA036               (*(volatile unsigned long  *)0xFFFF9914)
#define DTRTC036               (*(volatile unsigned long  *)0xFFFF9918)
#define DTTCC036               (*(volatile unsigned long  *)0xFFFF991C)
#define DTFSL036               (*(volatile unsigned long  *)0xFFFF9920)
#define DTFST036               (*(volatile unsigned long  *)0xFFFF9924)
#define DTFSS036               (*(volatile unsigned long  *)0xFFFF9928)
#define DTFSC036               (*(volatile unsigned long  *)0xFFFF992C)
#define DTSA037                (*(volatile unsigned long  *)0xFFFF9940)
#define DTDA037                (*(volatile unsigned long  *)0xFFFF9944)
#define DTTC037                (*(volatile unsigned long  *)0xFFFF9948)
#define DTTCT037               (*(volatile unsigned long  *)0xFFFF994C)
#define DTRSA037               (*(volatile unsigned long  *)0xFFFF9950)
#define DTRDA037               (*(volatile unsigned long  *)0xFFFF9954)
#define DTRTC037               (*(volatile unsigned long  *)0xFFFF9958)
#define DTTCC037               (*(volatile unsigned long  *)0xFFFF995C)
#define DTFSL037               (*(volatile unsigned long  *)0xFFFF9960)
#define DTFST037               (*(volatile unsigned long  *)0xFFFF9964)
#define DTFSS037               (*(volatile unsigned long  *)0xFFFF9968)
#define DTFSC037               (*(volatile unsigned long  *)0xFFFF996C)
#define DTSA038                (*(volatile unsigned long  *)0xFFFF9980)
#define DTDA038                (*(volatile unsigned long  *)0xFFFF9984)
#define DTTC038                (*(volatile unsigned long  *)0xFFFF9988)
#define DTTCT038               (*(volatile unsigned long  *)0xFFFF998C)
#define DTRSA038               (*(volatile unsigned long  *)0xFFFF9990)
#define DTRDA038               (*(volatile unsigned long  *)0xFFFF9994)
#define DTRTC038               (*(volatile unsigned long  *)0xFFFF9998)
#define DTTCC038               (*(volatile unsigned long  *)0xFFFF999C)
#define DTFSL038               (*(volatile unsigned long  *)0xFFFF99A0)
#define DTFST038               (*(volatile unsigned long  *)0xFFFF99A4)
#define DTFSS038               (*(volatile unsigned long  *)0xFFFF99A8)
#define DTFSC038               (*(volatile unsigned long  *)0xFFFF99AC)
#define DTSA039                (*(volatile unsigned long  *)0xFFFF99C0)
#define DTDA039                (*(volatile unsigned long  *)0xFFFF99C4)
#define DTTC039                (*(volatile unsigned long  *)0xFFFF99C8)
#define DTTCT039               (*(volatile unsigned long  *)0xFFFF99CC)
#define DTRSA039               (*(volatile unsigned long  *)0xFFFF99D0)
#define DTRDA039               (*(volatile unsigned long  *)0xFFFF99D4)
#define DTRTC039               (*(volatile unsigned long  *)0xFFFF99D8)
#define DTTCC039               (*(volatile unsigned long  *)0xFFFF99DC)
#define DTFSL039               (*(volatile unsigned long  *)0xFFFF99E0)
#define DTFST039               (*(volatile unsigned long  *)0xFFFF99E4)
#define DTFSS039               (*(volatile unsigned long  *)0xFFFF99E8)
#define DTFSC039               (*(volatile unsigned long  *)0xFFFF99EC)
#define DTSA040                (*(volatile unsigned long  *)0xFFFF9A00)
#define DTDA040                (*(volatile unsigned long  *)0xFFFF9A04)
#define DTTC040                (*(volatile unsigned long  *)0xFFFF9A08)
#define DTTCT040               (*(volatile unsigned long  *)0xFFFF9A0C)
#define DTRSA040               (*(volatile unsigned long  *)0xFFFF9A10)
#define DTRDA040               (*(volatile unsigned long  *)0xFFFF9A14)
#define DTRTC040               (*(volatile unsigned long  *)0xFFFF9A18)
#define DTTCC040               (*(volatile unsigned long  *)0xFFFF9A1C)
#define DTFSL040               (*(volatile unsigned long  *)0xFFFF9A20)
#define DTFST040               (*(volatile unsigned long  *)0xFFFF9A24)
#define DTFSS040               (*(volatile unsigned long  *)0xFFFF9A28)
#define DTFSC040               (*(volatile unsigned long  *)0xFFFF9A2C)
#define DTSA041                (*(volatile unsigned long  *)0xFFFF9A40)
#define DTDA041                (*(volatile unsigned long  *)0xFFFF9A44)
#define DTTC041                (*(volatile unsigned long  *)0xFFFF9A48)
#define DTTCT041               (*(volatile unsigned long  *)0xFFFF9A4C)
#define DTRSA041               (*(volatile unsigned long  *)0xFFFF9A50)
#define DTRDA041               (*(volatile unsigned long  *)0xFFFF9A54)
#define DTRTC041               (*(volatile unsigned long  *)0xFFFF9A58)
#define DTTCC041               (*(volatile unsigned long  *)0xFFFF9A5C)
#define DTFSL041               (*(volatile unsigned long  *)0xFFFF9A60)
#define DTFST041               (*(volatile unsigned long  *)0xFFFF9A64)
#define DTFSS041               (*(volatile unsigned long  *)0xFFFF9A68)
#define DTFSC041               (*(volatile unsigned long  *)0xFFFF9A6C)
#define DTSA042                (*(volatile unsigned long  *)0xFFFF9A80)
#define DTDA042                (*(volatile unsigned long  *)0xFFFF9A84)
#define DTTC042                (*(volatile unsigned long  *)0xFFFF9A88)
#define DTTCT042               (*(volatile unsigned long  *)0xFFFF9A8C)
#define DTRSA042               (*(volatile unsigned long  *)0xFFFF9A90)
#define DTRDA042               (*(volatile unsigned long  *)0xFFFF9A94)
#define DTRTC042               (*(volatile unsigned long  *)0xFFFF9A98)
#define DTTCC042               (*(volatile unsigned long  *)0xFFFF9A9C)
#define DTFSL042               (*(volatile unsigned long  *)0xFFFF9AA0)
#define DTFST042               (*(volatile unsigned long  *)0xFFFF9AA4)
#define DTFSS042               (*(volatile unsigned long  *)0xFFFF9AA8)
#define DTFSC042               (*(volatile unsigned long  *)0xFFFF9AAC)
#define DTSA043                (*(volatile unsigned long  *)0xFFFF9AC0)
#define DTDA043                (*(volatile unsigned long  *)0xFFFF9AC4)
#define DTTC043                (*(volatile unsigned long  *)0xFFFF9AC8)
#define DTTCT043               (*(volatile unsigned long  *)0xFFFF9ACC)
#define DTRSA043               (*(volatile unsigned long  *)0xFFFF9AD0)
#define DTRDA043               (*(volatile unsigned long  *)0xFFFF9AD4)
#define DTRTC043               (*(volatile unsigned long  *)0xFFFF9AD8)
#define DTTCC043               (*(volatile unsigned long  *)0xFFFF9ADC)
#define DTFSL043               (*(volatile unsigned long  *)0xFFFF9AE0)
#define DTFST043               (*(volatile unsigned long  *)0xFFFF9AE4)
#define DTFSS043               (*(volatile unsigned long  *)0xFFFF9AE8)
#define DTFSC043               (*(volatile unsigned long  *)0xFFFF9AEC)
#define DTSA044                (*(volatile unsigned long  *)0xFFFF9B00)
#define DTDA044                (*(volatile unsigned long  *)0xFFFF9B04)
#define DTTC044                (*(volatile unsigned long  *)0xFFFF9B08)
#define DTTCT044               (*(volatile unsigned long  *)0xFFFF9B0C)
#define DTRSA044               (*(volatile unsigned long  *)0xFFFF9B10)
#define DTRDA044               (*(volatile unsigned long  *)0xFFFF9B14)
#define DTRTC044               (*(volatile unsigned long  *)0xFFFF9B18)
#define DTTCC044               (*(volatile unsigned long  *)0xFFFF9B1C)
#define DTFSL044               (*(volatile unsigned long  *)0xFFFF9B20)
#define DTFST044               (*(volatile unsigned long  *)0xFFFF9B24)
#define DTFSS044               (*(volatile unsigned long  *)0xFFFF9B28)
#define DTFSC044               (*(volatile unsigned long  *)0xFFFF9B2C)
#define DTSA045                (*(volatile unsigned long  *)0xFFFF9B40)
#define DTDA045                (*(volatile unsigned long  *)0xFFFF9B44)
#define DTTC045                (*(volatile unsigned long  *)0xFFFF9B48)
#define DTTCT045               (*(volatile unsigned long  *)0xFFFF9B4C)
#define DTRSA045               (*(volatile unsigned long  *)0xFFFF9B50)
#define DTRDA045               (*(volatile unsigned long  *)0xFFFF9B54)
#define DTRTC045               (*(volatile unsigned long  *)0xFFFF9B58)
#define DTTCC045               (*(volatile unsigned long  *)0xFFFF9B5C)
#define DTFSL045               (*(volatile unsigned long  *)0xFFFF9B60)
#define DTFST045               (*(volatile unsigned long  *)0xFFFF9B64)
#define DTFSS045               (*(volatile unsigned long  *)0xFFFF9B68)
#define DTFSC045               (*(volatile unsigned long  *)0xFFFF9B6C)
#define DTSA046                (*(volatile unsigned long  *)0xFFFF9B80)
#define DTDA046                (*(volatile unsigned long  *)0xFFFF9B84)
#define DTTC046                (*(volatile unsigned long  *)0xFFFF9B88)
#define DTTCT046               (*(volatile unsigned long  *)0xFFFF9B8C)
#define DTRSA046               (*(volatile unsigned long  *)0xFFFF9B90)
#define DTRDA046               (*(volatile unsigned long  *)0xFFFF9B94)
#define DTRTC046               (*(volatile unsigned long  *)0xFFFF9B98)
#define DTTCC046               (*(volatile unsigned long  *)0xFFFF9B9C)
#define DTFSL046               (*(volatile unsigned long  *)0xFFFF9BA0)
#define DTFST046               (*(volatile unsigned long  *)0xFFFF9BA4)
#define DTFSS046               (*(volatile unsigned long  *)0xFFFF9BA8)
#define DTFSC046               (*(volatile unsigned long  *)0xFFFF9BAC)
#define DTSA047                (*(volatile unsigned long  *)0xFFFF9BC0)
#define DTDA047                (*(volatile unsigned long  *)0xFFFF9BC4)
#define DTTC047                (*(volatile unsigned long  *)0xFFFF9BC8)
#define DTTCT047               (*(volatile unsigned long  *)0xFFFF9BCC)
#define DTRSA047               (*(volatile unsigned long  *)0xFFFF9BD0)
#define DTRDA047               (*(volatile unsigned long  *)0xFFFF9BD4)
#define DTRTC047               (*(volatile unsigned long  *)0xFFFF9BD8)
#define DTTCC047               (*(volatile unsigned long  *)0xFFFF9BDC)
#define DTFSL047               (*(volatile unsigned long  *)0xFFFF9BE0)
#define DTFST047               (*(volatile unsigned long  *)0xFFFF9BE4)
#define DTFSS047               (*(volatile unsigned long  *)0xFFFF9BE8)
#define DTFSC047               (*(volatile unsigned long  *)0xFFFF9BEC)
#define DTSA048                (*(volatile unsigned long  *)0xFFFF9C00)
#define DTDA048                (*(volatile unsigned long  *)0xFFFF9C04)
#define DTTC048                (*(volatile unsigned long  *)0xFFFF9C08)
#define DTTCT048               (*(volatile unsigned long  *)0xFFFF9C0C)
#define DTRSA048               (*(volatile unsigned long  *)0xFFFF9C10)
#define DTRDA048               (*(volatile unsigned long  *)0xFFFF9C14)
#define DTRTC048               (*(volatile unsigned long  *)0xFFFF9C18)
#define DTTCC048               (*(volatile unsigned long  *)0xFFFF9C1C)
#define DTFSL048               (*(volatile unsigned long  *)0xFFFF9C20)
#define DTFST048               (*(volatile unsigned long  *)0xFFFF9C24)
#define DTFSS048               (*(volatile unsigned long  *)0xFFFF9C28)
#define DTFSC048               (*(volatile unsigned long  *)0xFFFF9C2C)
#define DTSA049                (*(volatile unsigned long  *)0xFFFF9C40)
#define DTDA049                (*(volatile unsigned long  *)0xFFFF9C44)
#define DTTC049                (*(volatile unsigned long  *)0xFFFF9C48)
#define DTTCT049               (*(volatile unsigned long  *)0xFFFF9C4C)
#define DTRSA049               (*(volatile unsigned long  *)0xFFFF9C50)
#define DTRDA049               (*(volatile unsigned long  *)0xFFFF9C54)
#define DTRTC049               (*(volatile unsigned long  *)0xFFFF9C58)
#define DTTCC049               (*(volatile unsigned long  *)0xFFFF9C5C)
#define DTFSL049               (*(volatile unsigned long  *)0xFFFF9C60)
#define DTFST049               (*(volatile unsigned long  *)0xFFFF9C64)
#define DTFSS049               (*(volatile unsigned long  *)0xFFFF9C68)
#define DTFSC049               (*(volatile unsigned long  *)0xFFFF9C6C)
#define DTSA050                (*(volatile unsigned long  *)0xFFFF9C80)
#define DTDA050                (*(volatile unsigned long  *)0xFFFF9C84)
#define DTTC050                (*(volatile unsigned long  *)0xFFFF9C88)
#define DTTCT050               (*(volatile unsigned long  *)0xFFFF9C8C)
#define DTRSA050               (*(volatile unsigned long  *)0xFFFF9C90)
#define DTRDA050               (*(volatile unsigned long  *)0xFFFF9C94)
#define DTRTC050               (*(volatile unsigned long  *)0xFFFF9C98)
#define DTTCC050               (*(volatile unsigned long  *)0xFFFF9C9C)
#define DTFSL050               (*(volatile unsigned long  *)0xFFFF9CA0)
#define DTFST050               (*(volatile unsigned long  *)0xFFFF9CA4)
#define DTFSS050               (*(volatile unsigned long  *)0xFFFF9CA8)
#define DTFSC050               (*(volatile unsigned long  *)0xFFFF9CAC)
#define DTSA051                (*(volatile unsigned long  *)0xFFFF9CC0)
#define DTDA051                (*(volatile unsigned long  *)0xFFFF9CC4)
#define DTTC051                (*(volatile unsigned long  *)0xFFFF9CC8)
#define DTTCT051               (*(volatile unsigned long  *)0xFFFF9CCC)
#define DTRSA051               (*(volatile unsigned long  *)0xFFFF9CD0)
#define DTRDA051               (*(volatile unsigned long  *)0xFFFF9CD4)
#define DTRTC051               (*(volatile unsigned long  *)0xFFFF9CD8)
#define DTTCC051               (*(volatile unsigned long  *)0xFFFF9CDC)
#define DTFSL051               (*(volatile unsigned long  *)0xFFFF9CE0)
#define DTFST051               (*(volatile unsigned long  *)0xFFFF9CE4)
#define DTFSS051               (*(volatile unsigned long  *)0xFFFF9CE8)
#define DTFSC051               (*(volatile unsigned long  *)0xFFFF9CEC)
#define DTSA052                (*(volatile unsigned long  *)0xFFFF9D00)
#define DTDA052                (*(volatile unsigned long  *)0xFFFF9D04)
#define DTTC052                (*(volatile unsigned long  *)0xFFFF9D08)
#define DTTCT052               (*(volatile unsigned long  *)0xFFFF9D0C)
#define DTRSA052               (*(volatile unsigned long  *)0xFFFF9D10)
#define DTRDA052               (*(volatile unsigned long  *)0xFFFF9D14)
#define DTRTC052               (*(volatile unsigned long  *)0xFFFF9D18)
#define DTTCC052               (*(volatile unsigned long  *)0xFFFF9D1C)
#define DTFSL052               (*(volatile unsigned long  *)0xFFFF9D20)
#define DTFST052               (*(volatile unsigned long  *)0xFFFF9D24)
#define DTFSS052               (*(volatile unsigned long  *)0xFFFF9D28)
#define DTFSC052               (*(volatile unsigned long  *)0xFFFF9D2C)
#define DTSA053                (*(volatile unsigned long  *)0xFFFF9D40)
#define DTDA053                (*(volatile unsigned long  *)0xFFFF9D44)
#define DTTC053                (*(volatile unsigned long  *)0xFFFF9D48)
#define DTTCT053               (*(volatile unsigned long  *)0xFFFF9D4C)
#define DTRSA053               (*(volatile unsigned long  *)0xFFFF9D50)
#define DTRDA053               (*(volatile unsigned long  *)0xFFFF9D54)
#define DTRTC053               (*(volatile unsigned long  *)0xFFFF9D58)
#define DTTCC053               (*(volatile unsigned long  *)0xFFFF9D5C)
#define DTFSL053               (*(volatile unsigned long  *)0xFFFF9D60)
#define DTFST053               (*(volatile unsigned long  *)0xFFFF9D64)
#define DTFSS053               (*(volatile unsigned long  *)0xFFFF9D68)
#define DTFSC053               (*(volatile unsigned long  *)0xFFFF9D6C)
#define DTSA054                (*(volatile unsigned long  *)0xFFFF9D80)
#define DTDA054                (*(volatile unsigned long  *)0xFFFF9D84)
#define DTTC054                (*(volatile unsigned long  *)0xFFFF9D88)
#define DTTCT054               (*(volatile unsigned long  *)0xFFFF9D8C)
#define DTRSA054               (*(volatile unsigned long  *)0xFFFF9D90)
#define DTRDA054               (*(volatile unsigned long  *)0xFFFF9D94)
#define DTRTC054               (*(volatile unsigned long  *)0xFFFF9D98)
#define DTTCC054               (*(volatile unsigned long  *)0xFFFF9D9C)
#define DTFSL054               (*(volatile unsigned long  *)0xFFFF9DA0)
#define DTFST054               (*(volatile unsigned long  *)0xFFFF9DA4)
#define DTFSS054               (*(volatile unsigned long  *)0xFFFF9DA8)
#define DTFSC054               (*(volatile unsigned long  *)0xFFFF9DAC)
#define DTSA055                (*(volatile unsigned long  *)0xFFFF9DC0)
#define DTDA055                (*(volatile unsigned long  *)0xFFFF9DC4)
#define DTTC055                (*(volatile unsigned long  *)0xFFFF9DC8)
#define DTTCT055               (*(volatile unsigned long  *)0xFFFF9DCC)
#define DTRSA055               (*(volatile unsigned long  *)0xFFFF9DD0)
#define DTRDA055               (*(volatile unsigned long  *)0xFFFF9DD4)
#define DTRTC055               (*(volatile unsigned long  *)0xFFFF9DD8)
#define DTTCC055               (*(volatile unsigned long  *)0xFFFF9DDC)
#define DTFSL055               (*(volatile unsigned long  *)0xFFFF9DE0)
#define DTFST055               (*(volatile unsigned long  *)0xFFFF9DE4)
#define DTFSS055               (*(volatile unsigned long  *)0xFFFF9DE8)
#define DTFSC055               (*(volatile unsigned long  *)0xFFFF9DEC)
#define DTSA056                (*(volatile unsigned long  *)0xFFFF9E00)
#define DTDA056                (*(volatile unsigned long  *)0xFFFF9E04)
#define DTTC056                (*(volatile unsigned long  *)0xFFFF9E08)
#define DTTCT056               (*(volatile unsigned long  *)0xFFFF9E0C)
#define DTRSA056               (*(volatile unsigned long  *)0xFFFF9E10)
#define DTRDA056               (*(volatile unsigned long  *)0xFFFF9E14)
#define DTRTC056               (*(volatile unsigned long  *)0xFFFF9E18)
#define DTTCC056               (*(volatile unsigned long  *)0xFFFF9E1C)
#define DTFSL056               (*(volatile unsigned long  *)0xFFFF9E20)
#define DTFST056               (*(volatile unsigned long  *)0xFFFF9E24)
#define DTFSS056               (*(volatile unsigned long  *)0xFFFF9E28)
#define DTFSC056               (*(volatile unsigned long  *)0xFFFF9E2C)
#define DTSA057                (*(volatile unsigned long  *)0xFFFF9E40)
#define DTDA057                (*(volatile unsigned long  *)0xFFFF9E44)
#define DTTC057                (*(volatile unsigned long  *)0xFFFF9E48)
#define DTTCT057               (*(volatile unsigned long  *)0xFFFF9E4C)
#define DTRSA057               (*(volatile unsigned long  *)0xFFFF9E50)
#define DTRDA057               (*(volatile unsigned long  *)0xFFFF9E54)
#define DTRTC057               (*(volatile unsigned long  *)0xFFFF9E58)
#define DTTCC057               (*(volatile unsigned long  *)0xFFFF9E5C)
#define DTFSL057               (*(volatile unsigned long  *)0xFFFF9E60)
#define DTFST057               (*(volatile unsigned long  *)0xFFFF9E64)
#define DTFSS057               (*(volatile unsigned long  *)0xFFFF9E68)
#define DTFSC057               (*(volatile unsigned long  *)0xFFFF9E6C)
#define DTSA058                (*(volatile unsigned long  *)0xFFFF9E80)
#define DTDA058                (*(volatile unsigned long  *)0xFFFF9E84)
#define DTTC058                (*(volatile unsigned long  *)0xFFFF9E88)
#define DTTCT058               (*(volatile unsigned long  *)0xFFFF9E8C)
#define DTRSA058               (*(volatile unsigned long  *)0xFFFF9E90)
#define DTRDA058               (*(volatile unsigned long  *)0xFFFF9E94)
#define DTRTC058               (*(volatile unsigned long  *)0xFFFF9E98)
#define DTTCC058               (*(volatile unsigned long  *)0xFFFF9E9C)
#define DTFSL058               (*(volatile unsigned long  *)0xFFFF9EA0)
#define DTFST058               (*(volatile unsigned long  *)0xFFFF9EA4)
#define DTFSS058               (*(volatile unsigned long  *)0xFFFF9EA8)
#define DTFSC058               (*(volatile unsigned long  *)0xFFFF9EAC)
#define DTSA059                (*(volatile unsigned long  *)0xFFFF9EC0)
#define DTDA059                (*(volatile unsigned long  *)0xFFFF9EC4)
#define DTTC059                (*(volatile unsigned long  *)0xFFFF9EC8)
#define DTTCT059               (*(volatile unsigned long  *)0xFFFF9ECC)
#define DTRSA059               (*(volatile unsigned long  *)0xFFFF9ED0)
#define DTRDA059               (*(volatile unsigned long  *)0xFFFF9ED4)
#define DTRTC059               (*(volatile unsigned long  *)0xFFFF9ED8)
#define DTTCC059               (*(volatile unsigned long  *)0xFFFF9EDC)
#define DTFSL059               (*(volatile unsigned long  *)0xFFFF9EE0)
#define DTFST059               (*(volatile unsigned long  *)0xFFFF9EE4)
#define DTFSS059               (*(volatile unsigned long  *)0xFFFF9EE8)
#define DTFSC059               (*(volatile unsigned long  *)0xFFFF9EEC)
#define DTSA060                (*(volatile unsigned long  *)0xFFFF9F00)
#define DTDA060                (*(volatile unsigned long  *)0xFFFF9F04)
#define DTTC060                (*(volatile unsigned long  *)0xFFFF9F08)
#define DTTCT060               (*(volatile unsigned long  *)0xFFFF9F0C)
#define DTRSA060               (*(volatile unsigned long  *)0xFFFF9F10)
#define DTRDA060               (*(volatile unsigned long  *)0xFFFF9F14)
#define DTRTC060               (*(volatile unsigned long  *)0xFFFF9F18)
#define DTTCC060               (*(volatile unsigned long  *)0xFFFF9F1C)
#define DTFSL060               (*(volatile unsigned long  *)0xFFFF9F20)
#define DTFST060               (*(volatile unsigned long  *)0xFFFF9F24)
#define DTFSS060               (*(volatile unsigned long  *)0xFFFF9F28)
#define DTFSC060               (*(volatile unsigned long  *)0xFFFF9F2C)
#define DTSA061                (*(volatile unsigned long  *)0xFFFF9F40)
#define DTDA061                (*(volatile unsigned long  *)0xFFFF9F44)
#define DTTC061                (*(volatile unsigned long  *)0xFFFF9F48)
#define DTTCT061               (*(volatile unsigned long  *)0xFFFF9F4C)
#define DTRSA061               (*(volatile unsigned long  *)0xFFFF9F50)
#define DTRDA061               (*(volatile unsigned long  *)0xFFFF9F54)
#define DTRTC061               (*(volatile unsigned long  *)0xFFFF9F58)
#define DTTCC061               (*(volatile unsigned long  *)0xFFFF9F5C)
#define DTFSL061               (*(volatile unsigned long  *)0xFFFF9F60)
#define DTFST061               (*(volatile unsigned long  *)0xFFFF9F64)
#define DTFSS061               (*(volatile unsigned long  *)0xFFFF9F68)
#define DTFSC061               (*(volatile unsigned long  *)0xFFFF9F6C)
#define DTSA062                (*(volatile unsigned long  *)0xFFFF9F80)
#define DTDA062                (*(volatile unsigned long  *)0xFFFF9F84)
#define DTTC062                (*(volatile unsigned long  *)0xFFFF9F88)
#define DTTCT062               (*(volatile unsigned long  *)0xFFFF9F8C)
#define DTRSA062               (*(volatile unsigned long  *)0xFFFF9F90)
#define DTRDA062               (*(volatile unsigned long  *)0xFFFF9F94)
#define DTRTC062               (*(volatile unsigned long  *)0xFFFF9F98)
#define DTTCC062               (*(volatile unsigned long  *)0xFFFF9F9C)
#define DTFSL062               (*(volatile unsigned long  *)0xFFFF9FA0)
#define DTFST062               (*(volatile unsigned long  *)0xFFFF9FA4)
#define DTFSS062               (*(volatile unsigned long  *)0xFFFF9FA8)
#define DTFSC062               (*(volatile unsigned long  *)0xFFFF9FAC)
#define DTSA063                (*(volatile unsigned long  *)0xFFFF9FC0)
#define DTDA063                (*(volatile unsigned long  *)0xFFFF9FC4)
#define DTTC063                (*(volatile unsigned long  *)0xFFFF9FC8)
#define DTTCT063               (*(volatile unsigned long  *)0xFFFF9FCC)
#define DTRSA063               (*(volatile unsigned long  *)0xFFFF9FD0)
#define DTRDA063               (*(volatile unsigned long  *)0xFFFF9FD4)
#define DTRTC063               (*(volatile unsigned long  *)0xFFFF9FD8)
#define DTTCC063               (*(volatile unsigned long  *)0xFFFF9FDC)
#define DTFSL063               (*(volatile unsigned long  *)0xFFFF9FE0)
#define DTFST063               (*(volatile unsigned long  *)0xFFFF9FE4)
#define DTFSS063               (*(volatile unsigned long  *)0xFFFF9FE8)
#define DTFSC063               (*(volatile unsigned long  *)0xFFFF9FEC)
#define DTSA064                (*(volatile unsigned long  *)0xFFFFA000)
#define DTDA064                (*(volatile unsigned long  *)0xFFFFA004)
#define DTTC064                (*(volatile unsigned long  *)0xFFFFA008)
#define DTTCT064               (*(volatile unsigned long  *)0xFFFFA00C)
#define DTRSA064               (*(volatile unsigned long  *)0xFFFFA010)
#define DTRDA064               (*(volatile unsigned long  *)0xFFFFA014)
#define DTRTC064               (*(volatile unsigned long  *)0xFFFFA018)
#define DTTCC064               (*(volatile unsigned long  *)0xFFFFA01C)
#define DTFSL064               (*(volatile unsigned long  *)0xFFFFA020)
#define DTFST064               (*(volatile unsigned long  *)0xFFFFA024)
#define DTFSS064               (*(volatile unsigned long  *)0xFFFFA028)
#define DTFSC064               (*(volatile unsigned long  *)0xFFFFA02C)
#define DTSA065                (*(volatile unsigned long  *)0xFFFFA040)
#define DTDA065                (*(volatile unsigned long  *)0xFFFFA044)
#define DTTC065                (*(volatile unsigned long  *)0xFFFFA048)
#define DTTCT065               (*(volatile unsigned long  *)0xFFFFA04C)
#define DTRSA065               (*(volatile unsigned long  *)0xFFFFA050)
#define DTRDA065               (*(volatile unsigned long  *)0xFFFFA054)
#define DTRTC065               (*(volatile unsigned long  *)0xFFFFA058)
#define DTTCC065               (*(volatile unsigned long  *)0xFFFFA05C)
#define DTFSL065               (*(volatile unsigned long  *)0xFFFFA060)
#define DTFST065               (*(volatile unsigned long  *)0xFFFFA064)
#define DTFSS065               (*(volatile unsigned long  *)0xFFFFA068)
#define DTFSC065               (*(volatile unsigned long  *)0xFFFFA06C)
#define DTSA066                (*(volatile unsigned long  *)0xFFFFA080)
#define DTDA066                (*(volatile unsigned long  *)0xFFFFA084)
#define DTTC066                (*(volatile unsigned long  *)0xFFFFA088)
#define DTTCT066               (*(volatile unsigned long  *)0xFFFFA08C)
#define DTRSA066               (*(volatile unsigned long  *)0xFFFFA090)
#define DTRDA066               (*(volatile unsigned long  *)0xFFFFA094)
#define DTRTC066               (*(volatile unsigned long  *)0xFFFFA098)
#define DTTCC066               (*(volatile unsigned long  *)0xFFFFA09C)
#define DTFSL066               (*(volatile unsigned long  *)0xFFFFA0A0)
#define DTFST066               (*(volatile unsigned long  *)0xFFFFA0A4)
#define DTFSS066               (*(volatile unsigned long  *)0xFFFFA0A8)
#define DTFSC066               (*(volatile unsigned long  *)0xFFFFA0AC)
#define DTSA067                (*(volatile unsigned long  *)0xFFFFA0C0)
#define DTDA067                (*(volatile unsigned long  *)0xFFFFA0C4)
#define DTTC067                (*(volatile unsigned long  *)0xFFFFA0C8)
#define DTTCT067               (*(volatile unsigned long  *)0xFFFFA0CC)
#define DTRSA067               (*(volatile unsigned long  *)0xFFFFA0D0)
#define DTRDA067               (*(volatile unsigned long  *)0xFFFFA0D4)
#define DTRTC067               (*(volatile unsigned long  *)0xFFFFA0D8)
#define DTTCC067               (*(volatile unsigned long  *)0xFFFFA0DC)
#define DTFSL067               (*(volatile unsigned long  *)0xFFFFA0E0)
#define DTFST067               (*(volatile unsigned long  *)0xFFFFA0E4)
#define DTFSS067               (*(volatile unsigned long  *)0xFFFFA0E8)
#define DTFSC067               (*(volatile unsigned long  *)0xFFFFA0EC)
#define DTSA068                (*(volatile unsigned long  *)0xFFFFA100)
#define DTDA068                (*(volatile unsigned long  *)0xFFFFA104)
#define DTTC068                (*(volatile unsigned long  *)0xFFFFA108)
#define DTTCT068               (*(volatile unsigned long  *)0xFFFFA10C)
#define DTRSA068               (*(volatile unsigned long  *)0xFFFFA110)
#define DTRDA068               (*(volatile unsigned long  *)0xFFFFA114)
#define DTRTC068               (*(volatile unsigned long  *)0xFFFFA118)
#define DTTCC068               (*(volatile unsigned long  *)0xFFFFA11C)
#define DTFSL068               (*(volatile unsigned long  *)0xFFFFA120)
#define DTFST068               (*(volatile unsigned long  *)0xFFFFA124)
#define DTFSS068               (*(volatile unsigned long  *)0xFFFFA128)
#define DTFSC068               (*(volatile unsigned long  *)0xFFFFA12C)
#define DTSA069                (*(volatile unsigned long  *)0xFFFFA140)
#define DTDA069                (*(volatile unsigned long  *)0xFFFFA144)
#define DTTC069                (*(volatile unsigned long  *)0xFFFFA148)
#define DTTCT069               (*(volatile unsigned long  *)0xFFFFA14C)
#define DTRSA069               (*(volatile unsigned long  *)0xFFFFA150)
#define DTRDA069               (*(volatile unsigned long  *)0xFFFFA154)
#define DTRTC069               (*(volatile unsigned long  *)0xFFFFA158)
#define DTTCC069               (*(volatile unsigned long  *)0xFFFFA15C)
#define DTFSL069               (*(volatile unsigned long  *)0xFFFFA160)
#define DTFST069               (*(volatile unsigned long  *)0xFFFFA164)
#define DTFSS069               (*(volatile unsigned long  *)0xFFFFA168)
#define DTFSC069               (*(volatile unsigned long  *)0xFFFFA16C)
#define DTSA070                (*(volatile unsigned long  *)0xFFFFA180)
#define DTDA070                (*(volatile unsigned long  *)0xFFFFA184)
#define DTTC070                (*(volatile unsigned long  *)0xFFFFA188)
#define DTTCT070               (*(volatile unsigned long  *)0xFFFFA18C)
#define DTRSA070               (*(volatile unsigned long  *)0xFFFFA190)
#define DTRDA070               (*(volatile unsigned long  *)0xFFFFA194)
#define DTRTC070               (*(volatile unsigned long  *)0xFFFFA198)
#define DTTCC070               (*(volatile unsigned long  *)0xFFFFA19C)
#define DTFSL070               (*(volatile unsigned long  *)0xFFFFA1A0)
#define DTFST070               (*(volatile unsigned long  *)0xFFFFA1A4)
#define DTFSS070               (*(volatile unsigned long  *)0xFFFFA1A8)
#define DTFSC070               (*(volatile unsigned long  *)0xFFFFA1AC)
#define DTSA071                (*(volatile unsigned long  *)0xFFFFA1C0)
#define DTDA071                (*(volatile unsigned long  *)0xFFFFA1C4)
#define DTTC071                (*(volatile unsigned long  *)0xFFFFA1C8)
#define DTTCT071               (*(volatile unsigned long  *)0xFFFFA1CC)
#define DTRSA071               (*(volatile unsigned long  *)0xFFFFA1D0)
#define DTRDA071               (*(volatile unsigned long  *)0xFFFFA1D4)
#define DTRTC071               (*(volatile unsigned long  *)0xFFFFA1D8)
#define DTTCC071               (*(volatile unsigned long  *)0xFFFFA1DC)
#define DTFSL071               (*(volatile unsigned long  *)0xFFFFA1E0)
#define DTFST071               (*(volatile unsigned long  *)0xFFFFA1E4)
#define DTFSS071               (*(volatile unsigned long  *)0xFFFFA1E8)
#define DTFSC071               (*(volatile unsigned long  *)0xFFFFA1EC)
#define DTSA072                (*(volatile unsigned long  *)0xFFFFA200)
#define DTDA072                (*(volatile unsigned long  *)0xFFFFA204)
#define DTTC072                (*(volatile unsigned long  *)0xFFFFA208)
#define DTTCT072               (*(volatile unsigned long  *)0xFFFFA20C)
#define DTRSA072               (*(volatile unsigned long  *)0xFFFFA210)
#define DTRDA072               (*(volatile unsigned long  *)0xFFFFA214)
#define DTRTC072               (*(volatile unsigned long  *)0xFFFFA218)
#define DTTCC072               (*(volatile unsigned long  *)0xFFFFA21C)
#define DTFSL072               (*(volatile unsigned long  *)0xFFFFA220)
#define DTFST072               (*(volatile unsigned long  *)0xFFFFA224)
#define DTFSS072               (*(volatile unsigned long  *)0xFFFFA228)
#define DTFSC072               (*(volatile unsigned long  *)0xFFFFA22C)
#define DTSA073                (*(volatile unsigned long  *)0xFFFFA240)
#define DTDA073                (*(volatile unsigned long  *)0xFFFFA244)
#define DTTC073                (*(volatile unsigned long  *)0xFFFFA248)
#define DTTCT073               (*(volatile unsigned long  *)0xFFFFA24C)
#define DTRSA073               (*(volatile unsigned long  *)0xFFFFA250)
#define DTRDA073               (*(volatile unsigned long  *)0xFFFFA254)
#define DTRTC073               (*(volatile unsigned long  *)0xFFFFA258)
#define DTTCC073               (*(volatile unsigned long  *)0xFFFFA25C)
#define DTFSL073               (*(volatile unsigned long  *)0xFFFFA260)
#define DTFST073               (*(volatile unsigned long  *)0xFFFFA264)
#define DTFSS073               (*(volatile unsigned long  *)0xFFFFA268)
#define DTFSC073               (*(volatile unsigned long  *)0xFFFFA26C)
#define DTSA074                (*(volatile unsigned long  *)0xFFFFA280)
#define DTDA074                (*(volatile unsigned long  *)0xFFFFA284)
#define DTTC074                (*(volatile unsigned long  *)0xFFFFA288)
#define DTTCT074               (*(volatile unsigned long  *)0xFFFFA28C)
#define DTRSA074               (*(volatile unsigned long  *)0xFFFFA290)
#define DTRDA074               (*(volatile unsigned long  *)0xFFFFA294)
#define DTRTC074               (*(volatile unsigned long  *)0xFFFFA298)
#define DTTCC074               (*(volatile unsigned long  *)0xFFFFA29C)
#define DTFSL074               (*(volatile unsigned long  *)0xFFFFA2A0)
#define DTFST074               (*(volatile unsigned long  *)0xFFFFA2A4)
#define DTFSS074               (*(volatile unsigned long  *)0xFFFFA2A8)
#define DTFSC074               (*(volatile unsigned long  *)0xFFFFA2AC)
#define DTSA075                (*(volatile unsigned long  *)0xFFFFA2C0)
#define DTDA075                (*(volatile unsigned long  *)0xFFFFA2C4)
#define DTTC075                (*(volatile unsigned long  *)0xFFFFA2C8)
#define DTTCT075               (*(volatile unsigned long  *)0xFFFFA2CC)
#define DTRSA075               (*(volatile unsigned long  *)0xFFFFA2D0)
#define DTRDA075               (*(volatile unsigned long  *)0xFFFFA2D4)
#define DTRTC075               (*(volatile unsigned long  *)0xFFFFA2D8)
#define DTTCC075               (*(volatile unsigned long  *)0xFFFFA2DC)
#define DTFSL075               (*(volatile unsigned long  *)0xFFFFA2E0)
#define DTFST075               (*(volatile unsigned long  *)0xFFFFA2E4)
#define DTFSS075               (*(volatile unsigned long  *)0xFFFFA2E8)
#define DTFSC075               (*(volatile unsigned long  *)0xFFFFA2EC)
#define DTSA076                (*(volatile unsigned long  *)0xFFFFA300)
#define DTDA076                (*(volatile unsigned long  *)0xFFFFA304)
#define DTTC076                (*(volatile unsigned long  *)0xFFFFA308)
#define DTTCT076               (*(volatile unsigned long  *)0xFFFFA30C)
#define DTRSA076               (*(volatile unsigned long  *)0xFFFFA310)
#define DTRDA076               (*(volatile unsigned long  *)0xFFFFA314)
#define DTRTC076               (*(volatile unsigned long  *)0xFFFFA318)
#define DTTCC076               (*(volatile unsigned long  *)0xFFFFA31C)
#define DTFSL076               (*(volatile unsigned long  *)0xFFFFA320)
#define DTFST076               (*(volatile unsigned long  *)0xFFFFA324)
#define DTFSS076               (*(volatile unsigned long  *)0xFFFFA328)
#define DTFSC076               (*(volatile unsigned long  *)0xFFFFA32C)
#define DTSA077                (*(volatile unsigned long  *)0xFFFFA340)
#define DTDA077                (*(volatile unsigned long  *)0xFFFFA344)
#define DTTC077                (*(volatile unsigned long  *)0xFFFFA348)
#define DTTCT077               (*(volatile unsigned long  *)0xFFFFA34C)
#define DTRSA077               (*(volatile unsigned long  *)0xFFFFA350)
#define DTRDA077               (*(volatile unsigned long  *)0xFFFFA354)
#define DTRTC077               (*(volatile unsigned long  *)0xFFFFA358)
#define DTTCC077               (*(volatile unsigned long  *)0xFFFFA35C)
#define DTFSL077               (*(volatile unsigned long  *)0xFFFFA360)
#define DTFST077               (*(volatile unsigned long  *)0xFFFFA364)
#define DTFSS077               (*(volatile unsigned long  *)0xFFFFA368)
#define DTFSC077               (*(volatile unsigned long  *)0xFFFFA36C)
#define DTSA078                (*(volatile unsigned long  *)0xFFFFA380)
#define DTDA078                (*(volatile unsigned long  *)0xFFFFA384)
#define DTTC078                (*(volatile unsigned long  *)0xFFFFA388)
#define DTTCT078               (*(volatile unsigned long  *)0xFFFFA38C)
#define DTRSA078               (*(volatile unsigned long  *)0xFFFFA390)
#define DTRDA078               (*(volatile unsigned long  *)0xFFFFA394)
#define DTRTC078               (*(volatile unsigned long  *)0xFFFFA398)
#define DTTCC078               (*(volatile unsigned long  *)0xFFFFA39C)
#define DTFSL078               (*(volatile unsigned long  *)0xFFFFA3A0)
#define DTFST078               (*(volatile unsigned long  *)0xFFFFA3A4)
#define DTFSS078               (*(volatile unsigned long  *)0xFFFFA3A8)
#define DTFSC078               (*(volatile unsigned long  *)0xFFFFA3AC)
#define DTSA079                (*(volatile unsigned long  *)0xFFFFA3C0)
#define DTDA079                (*(volatile unsigned long  *)0xFFFFA3C4)
#define DTTC079                (*(volatile unsigned long  *)0xFFFFA3C8)
#define DTTCT079               (*(volatile unsigned long  *)0xFFFFA3CC)
#define DTRSA079               (*(volatile unsigned long  *)0xFFFFA3D0)
#define DTRDA079               (*(volatile unsigned long  *)0xFFFFA3D4)
#define DTRTC079               (*(volatile unsigned long  *)0xFFFFA3D8)
#define DTTCC079               (*(volatile unsigned long  *)0xFFFFA3DC)
#define DTFSL079               (*(volatile unsigned long  *)0xFFFFA3E0)
#define DTFST079               (*(volatile unsigned long  *)0xFFFFA3E4)
#define DTFSS079               (*(volatile unsigned long  *)0xFFFFA3E8)
#define DTFSC079               (*(volatile unsigned long  *)0xFFFFA3EC)
#define DTSA080                (*(volatile unsigned long  *)0xFFFFA400)
#define DTDA080                (*(volatile unsigned long  *)0xFFFFA404)
#define DTTC080                (*(volatile unsigned long  *)0xFFFFA408)
#define DTTCT080               (*(volatile unsigned long  *)0xFFFFA40C)
#define DTRSA080               (*(volatile unsigned long  *)0xFFFFA410)
#define DTRDA080               (*(volatile unsigned long  *)0xFFFFA414)
#define DTRTC080               (*(volatile unsigned long  *)0xFFFFA418)
#define DTTCC080               (*(volatile unsigned long  *)0xFFFFA41C)
#define DTFSL080               (*(volatile unsigned long  *)0xFFFFA420)
#define DTFST080               (*(volatile unsigned long  *)0xFFFFA424)
#define DTFSS080               (*(volatile unsigned long  *)0xFFFFA428)
#define DTFSC080               (*(volatile unsigned long  *)0xFFFFA42C)
#define DTSA081                (*(volatile unsigned long  *)0xFFFFA440)
#define DTDA081                (*(volatile unsigned long  *)0xFFFFA444)
#define DTTC081                (*(volatile unsigned long  *)0xFFFFA448)
#define DTTCT081               (*(volatile unsigned long  *)0xFFFFA44C)
#define DTRSA081               (*(volatile unsigned long  *)0xFFFFA450)
#define DTRDA081               (*(volatile unsigned long  *)0xFFFFA454)
#define DTRTC081               (*(volatile unsigned long  *)0xFFFFA458)
#define DTTCC081               (*(volatile unsigned long  *)0xFFFFA45C)
#define DTFSL081               (*(volatile unsigned long  *)0xFFFFA460)
#define DTFST081               (*(volatile unsigned long  *)0xFFFFA464)
#define DTFSS081               (*(volatile unsigned long  *)0xFFFFA468)
#define DTFSC081               (*(volatile unsigned long  *)0xFFFFA46C)
#define DTSA082                (*(volatile unsigned long  *)0xFFFFA480)
#define DTDA082                (*(volatile unsigned long  *)0xFFFFA484)
#define DTTC082                (*(volatile unsigned long  *)0xFFFFA488)
#define DTTCT082               (*(volatile unsigned long  *)0xFFFFA48C)
#define DTRSA082               (*(volatile unsigned long  *)0xFFFFA490)
#define DTRDA082               (*(volatile unsigned long  *)0xFFFFA494)
#define DTRTC082               (*(volatile unsigned long  *)0xFFFFA498)
#define DTTCC082               (*(volatile unsigned long  *)0xFFFFA49C)
#define DTFSL082               (*(volatile unsigned long  *)0xFFFFA4A0)
#define DTFST082               (*(volatile unsigned long  *)0xFFFFA4A4)
#define DTFSS082               (*(volatile unsigned long  *)0xFFFFA4A8)
#define DTFSC082               (*(volatile unsigned long  *)0xFFFFA4AC)
#define DTSA083                (*(volatile unsigned long  *)0xFFFFA4C0)
#define DTDA083                (*(volatile unsigned long  *)0xFFFFA4C4)
#define DTTC083                (*(volatile unsigned long  *)0xFFFFA4C8)
#define DTTCT083               (*(volatile unsigned long  *)0xFFFFA4CC)
#define DTRSA083               (*(volatile unsigned long  *)0xFFFFA4D0)
#define DTRDA083               (*(volatile unsigned long  *)0xFFFFA4D4)
#define DTRTC083               (*(volatile unsigned long  *)0xFFFFA4D8)
#define DTTCC083               (*(volatile unsigned long  *)0xFFFFA4DC)
#define DTFSL083               (*(volatile unsigned long  *)0xFFFFA4E0)
#define DTFST083               (*(volatile unsigned long  *)0xFFFFA4E4)
#define DTFSS083               (*(volatile unsigned long  *)0xFFFFA4E8)
#define DTFSC083               (*(volatile unsigned long  *)0xFFFFA4EC)
#define DTSA084                (*(volatile unsigned long  *)0xFFFFA500)
#define DTDA084                (*(volatile unsigned long  *)0xFFFFA504)
#define DTTC084                (*(volatile unsigned long  *)0xFFFFA508)
#define DTTCT084               (*(volatile unsigned long  *)0xFFFFA50C)
#define DTRSA084               (*(volatile unsigned long  *)0xFFFFA510)
#define DTRDA084               (*(volatile unsigned long  *)0xFFFFA514)
#define DTRTC084               (*(volatile unsigned long  *)0xFFFFA518)
#define DTTCC084               (*(volatile unsigned long  *)0xFFFFA51C)
#define DTFSL084               (*(volatile unsigned long  *)0xFFFFA520)
#define DTFST084               (*(volatile unsigned long  *)0xFFFFA524)
#define DTFSS084               (*(volatile unsigned long  *)0xFFFFA528)
#define DTFSC084               (*(volatile unsigned long  *)0xFFFFA52C)
#define DTSA085                (*(volatile unsigned long  *)0xFFFFA540)
#define DTDA085                (*(volatile unsigned long  *)0xFFFFA544)
#define DTTC085                (*(volatile unsigned long  *)0xFFFFA548)
#define DTTCT085               (*(volatile unsigned long  *)0xFFFFA54C)
#define DTRSA085               (*(volatile unsigned long  *)0xFFFFA550)
#define DTRDA085               (*(volatile unsigned long  *)0xFFFFA554)
#define DTRTC085               (*(volatile unsigned long  *)0xFFFFA558)
#define DTTCC085               (*(volatile unsigned long  *)0xFFFFA55C)
#define DTFSL085               (*(volatile unsigned long  *)0xFFFFA560)
#define DTFST085               (*(volatile unsigned long  *)0xFFFFA564)
#define DTFSS085               (*(volatile unsigned long  *)0xFFFFA568)
#define DTFSC085               (*(volatile unsigned long  *)0xFFFFA56C)
#define DTSA086                (*(volatile unsigned long  *)0xFFFFA580)
#define DTDA086                (*(volatile unsigned long  *)0xFFFFA584)
#define DTTC086                (*(volatile unsigned long  *)0xFFFFA588)
#define DTTCT086               (*(volatile unsigned long  *)0xFFFFA58C)
#define DTRSA086               (*(volatile unsigned long  *)0xFFFFA590)
#define DTRDA086               (*(volatile unsigned long  *)0xFFFFA594)
#define DTRTC086               (*(volatile unsigned long  *)0xFFFFA598)
#define DTTCC086               (*(volatile unsigned long  *)0xFFFFA59C)
#define DTFSL086               (*(volatile unsigned long  *)0xFFFFA5A0)
#define DTFST086               (*(volatile unsigned long  *)0xFFFFA5A4)
#define DTFSS086               (*(volatile unsigned long  *)0xFFFFA5A8)
#define DTFSC086               (*(volatile unsigned long  *)0xFFFFA5AC)
#define DTSA087                (*(volatile unsigned long  *)0xFFFFA5C0)
#define DTDA087                (*(volatile unsigned long  *)0xFFFFA5C4)
#define DTTC087                (*(volatile unsigned long  *)0xFFFFA5C8)
#define DTTCT087               (*(volatile unsigned long  *)0xFFFFA5CC)
#define DTRSA087               (*(volatile unsigned long  *)0xFFFFA5D0)
#define DTRDA087               (*(volatile unsigned long  *)0xFFFFA5D4)
#define DTRTC087               (*(volatile unsigned long  *)0xFFFFA5D8)
#define DTTCC087               (*(volatile unsigned long  *)0xFFFFA5DC)
#define DTFSL087               (*(volatile unsigned long  *)0xFFFFA5E0)
#define DTFST087               (*(volatile unsigned long  *)0xFFFFA5E4)
#define DTFSS087               (*(volatile unsigned long  *)0xFFFFA5E8)
#define DTFSC087               (*(volatile unsigned long  *)0xFFFFA5EC)
#define DTSA088                (*(volatile unsigned long  *)0xFFFFA600)
#define DTDA088                (*(volatile unsigned long  *)0xFFFFA604)
#define DTTC088                (*(volatile unsigned long  *)0xFFFFA608)
#define DTTCT088               (*(volatile unsigned long  *)0xFFFFA60C)
#define DTRSA088               (*(volatile unsigned long  *)0xFFFFA610)
#define DTRDA088               (*(volatile unsigned long  *)0xFFFFA614)
#define DTRTC088               (*(volatile unsigned long  *)0xFFFFA618)
#define DTTCC088               (*(volatile unsigned long  *)0xFFFFA61C)
#define DTFSL088               (*(volatile unsigned long  *)0xFFFFA620)
#define DTFST088               (*(volatile unsigned long  *)0xFFFFA624)
#define DTFSS088               (*(volatile unsigned long  *)0xFFFFA628)
#define DTFSC088               (*(volatile unsigned long  *)0xFFFFA62C)
#define DTSA089                (*(volatile unsigned long  *)0xFFFFA640)
#define DTDA089                (*(volatile unsigned long  *)0xFFFFA644)
#define DTTC089                (*(volatile unsigned long  *)0xFFFFA648)
#define DTTCT089               (*(volatile unsigned long  *)0xFFFFA64C)
#define DTRSA089               (*(volatile unsigned long  *)0xFFFFA650)
#define DTRDA089               (*(volatile unsigned long  *)0xFFFFA654)
#define DTRTC089               (*(volatile unsigned long  *)0xFFFFA658)
#define DTTCC089               (*(volatile unsigned long  *)0xFFFFA65C)
#define DTFSL089               (*(volatile unsigned long  *)0xFFFFA660)
#define DTFST089               (*(volatile unsigned long  *)0xFFFFA664)
#define DTFSS089               (*(volatile unsigned long  *)0xFFFFA668)
#define DTFSC089               (*(volatile unsigned long  *)0xFFFFA66C)
#define DTSA090                (*(volatile unsigned long  *)0xFFFFA680)
#define DTDA090                (*(volatile unsigned long  *)0xFFFFA684)
#define DTTC090                (*(volatile unsigned long  *)0xFFFFA688)
#define DTTCT090               (*(volatile unsigned long  *)0xFFFFA68C)
#define DTRSA090               (*(volatile unsigned long  *)0xFFFFA690)
#define DTRDA090               (*(volatile unsigned long  *)0xFFFFA694)
#define DTRTC090               (*(volatile unsigned long  *)0xFFFFA698)
#define DTTCC090               (*(volatile unsigned long  *)0xFFFFA69C)
#define DTFSL090               (*(volatile unsigned long  *)0xFFFFA6A0)
#define DTFST090               (*(volatile unsigned long  *)0xFFFFA6A4)
#define DTFSS090               (*(volatile unsigned long  *)0xFFFFA6A8)
#define DTFSC090               (*(volatile unsigned long  *)0xFFFFA6AC)
#define DTSA091                (*(volatile unsigned long  *)0xFFFFA6C0)
#define DTDA091                (*(volatile unsigned long  *)0xFFFFA6C4)
#define DTTC091                (*(volatile unsigned long  *)0xFFFFA6C8)
#define DTTCT091               (*(volatile unsigned long  *)0xFFFFA6CC)
#define DTRSA091               (*(volatile unsigned long  *)0xFFFFA6D0)
#define DTRDA091               (*(volatile unsigned long  *)0xFFFFA6D4)
#define DTRTC091               (*(volatile unsigned long  *)0xFFFFA6D8)
#define DTTCC091               (*(volatile unsigned long  *)0xFFFFA6DC)
#define DTFSL091               (*(volatile unsigned long  *)0xFFFFA6E0)
#define DTFST091               (*(volatile unsigned long  *)0xFFFFA6E4)
#define DTFSS091               (*(volatile unsigned long  *)0xFFFFA6E8)
#define DTFSC091               (*(volatile unsigned long  *)0xFFFFA6EC)
#define DTSA092                (*(volatile unsigned long  *)0xFFFFA700)
#define DTDA092                (*(volatile unsigned long  *)0xFFFFA704)
#define DTTC092                (*(volatile unsigned long  *)0xFFFFA708)
#define DTTCT092               (*(volatile unsigned long  *)0xFFFFA70C)
#define DTRSA092               (*(volatile unsigned long  *)0xFFFFA710)
#define DTRDA092               (*(volatile unsigned long  *)0xFFFFA714)
#define DTRTC092               (*(volatile unsigned long  *)0xFFFFA718)
#define DTTCC092               (*(volatile unsigned long  *)0xFFFFA71C)
#define DTFSL092               (*(volatile unsigned long  *)0xFFFFA720)
#define DTFST092               (*(volatile unsigned long  *)0xFFFFA724)
#define DTFSS092               (*(volatile unsigned long  *)0xFFFFA728)
#define DTFSC092               (*(volatile unsigned long  *)0xFFFFA72C)
#define DTSA093                (*(volatile unsigned long  *)0xFFFFA740)
#define DTDA093                (*(volatile unsigned long  *)0xFFFFA744)
#define DTTC093                (*(volatile unsigned long  *)0xFFFFA748)
#define DTTCT093               (*(volatile unsigned long  *)0xFFFFA74C)
#define DTRSA093               (*(volatile unsigned long  *)0xFFFFA750)
#define DTRDA093               (*(volatile unsigned long  *)0xFFFFA754)
#define DTRTC093               (*(volatile unsigned long  *)0xFFFFA758)
#define DTTCC093               (*(volatile unsigned long  *)0xFFFFA75C)
#define DTFSL093               (*(volatile unsigned long  *)0xFFFFA760)
#define DTFST093               (*(volatile unsigned long  *)0xFFFFA764)
#define DTFSS093               (*(volatile unsigned long  *)0xFFFFA768)
#define DTFSC093               (*(volatile unsigned long  *)0xFFFFA76C)
#define DTSA094                (*(volatile unsigned long  *)0xFFFFA780)
#define DTDA094                (*(volatile unsigned long  *)0xFFFFA784)
#define DTTC094                (*(volatile unsigned long  *)0xFFFFA788)
#define DTTCT094               (*(volatile unsigned long  *)0xFFFFA78C)
#define DTRSA094               (*(volatile unsigned long  *)0xFFFFA790)
#define DTRDA094               (*(volatile unsigned long  *)0xFFFFA794)
#define DTRTC094               (*(volatile unsigned long  *)0xFFFFA798)
#define DTTCC094               (*(volatile unsigned long  *)0xFFFFA79C)
#define DTFSL094               (*(volatile unsigned long  *)0xFFFFA7A0)
#define DTFST094               (*(volatile unsigned long  *)0xFFFFA7A4)
#define DTFSS094               (*(volatile unsigned long  *)0xFFFFA7A8)
#define DTFSC094               (*(volatile unsigned long  *)0xFFFFA7AC)
#define DTSA095                (*(volatile unsigned long  *)0xFFFFA7C0)
#define DTDA095                (*(volatile unsigned long  *)0xFFFFA7C4)
#define DTTC095                (*(volatile unsigned long  *)0xFFFFA7C8)
#define DTTCT095               (*(volatile unsigned long  *)0xFFFFA7CC)
#define DTRSA095               (*(volatile unsigned long  *)0xFFFFA7D0)
#define DTRDA095               (*(volatile unsigned long  *)0xFFFFA7D4)
#define DTRTC095               (*(volatile unsigned long  *)0xFFFFA7D8)
#define DTTCC095               (*(volatile unsigned long  *)0xFFFFA7DC)
#define DTFSL095               (*(volatile unsigned long  *)0xFFFFA7E0)
#define DTFST095               (*(volatile unsigned long  *)0xFFFFA7E4)
#define DTFSS095               (*(volatile unsigned long  *)0xFFFFA7E8)
#define DTFSC095               (*(volatile unsigned long  *)0xFFFFA7EC)
#define DTSA096                (*(volatile unsigned long  *)0xFFFFA800)
#define DTDA096                (*(volatile unsigned long  *)0xFFFFA804)
#define DTTC096                (*(volatile unsigned long  *)0xFFFFA808)
#define DTTCT096               (*(volatile unsigned long  *)0xFFFFA80C)
#define DTRSA096               (*(volatile unsigned long  *)0xFFFFA810)
#define DTRDA096               (*(volatile unsigned long  *)0xFFFFA814)
#define DTRTC096               (*(volatile unsigned long  *)0xFFFFA818)
#define DTTCC096               (*(volatile unsigned long  *)0xFFFFA81C)
#define DTFSL096               (*(volatile unsigned long  *)0xFFFFA820)
#define DTFST096               (*(volatile unsigned long  *)0xFFFFA824)
#define DTFSS096               (*(volatile unsigned long  *)0xFFFFA828)
#define DTFSC096               (*(volatile unsigned long  *)0xFFFFA82C)
#define DTSA097                (*(volatile unsigned long  *)0xFFFFA840)
#define DTDA097                (*(volatile unsigned long  *)0xFFFFA844)
#define DTTC097                (*(volatile unsigned long  *)0xFFFFA848)
#define DTTCT097               (*(volatile unsigned long  *)0xFFFFA84C)
#define DTRSA097               (*(volatile unsigned long  *)0xFFFFA850)
#define DTRDA097               (*(volatile unsigned long  *)0xFFFFA854)
#define DTRTC097               (*(volatile unsigned long  *)0xFFFFA858)
#define DTTCC097               (*(volatile unsigned long  *)0xFFFFA85C)
#define DTFSL097               (*(volatile unsigned long  *)0xFFFFA860)
#define DTFST097               (*(volatile unsigned long  *)0xFFFFA864)
#define DTFSS097               (*(volatile unsigned long  *)0xFFFFA868)
#define DTFSC097               (*(volatile unsigned long  *)0xFFFFA86C)
#define DTSA098                (*(volatile unsigned long  *)0xFFFFA880)
#define DTDA098                (*(volatile unsigned long  *)0xFFFFA884)
#define DTTC098                (*(volatile unsigned long  *)0xFFFFA888)
#define DTTCT098               (*(volatile unsigned long  *)0xFFFFA88C)
#define DTRSA098               (*(volatile unsigned long  *)0xFFFFA890)
#define DTRDA098               (*(volatile unsigned long  *)0xFFFFA894)
#define DTRTC098               (*(volatile unsigned long  *)0xFFFFA898)
#define DTTCC098               (*(volatile unsigned long  *)0xFFFFA89C)
#define DTFSL098               (*(volatile unsigned long  *)0xFFFFA8A0)
#define DTFST098               (*(volatile unsigned long  *)0xFFFFA8A4)
#define DTFSS098               (*(volatile unsigned long  *)0xFFFFA8A8)
#define DTFSC098               (*(volatile unsigned long  *)0xFFFFA8AC)
#define DTSA099                (*(volatile unsigned long  *)0xFFFFA8C0)
#define DTDA099                (*(volatile unsigned long  *)0xFFFFA8C4)
#define DTTC099                (*(volatile unsigned long  *)0xFFFFA8C8)
#define DTTCT099               (*(volatile unsigned long  *)0xFFFFA8CC)
#define DTRSA099               (*(volatile unsigned long  *)0xFFFFA8D0)
#define DTRDA099               (*(volatile unsigned long  *)0xFFFFA8D4)
#define DTRTC099               (*(volatile unsigned long  *)0xFFFFA8D8)
#define DTTCC099               (*(volatile unsigned long  *)0xFFFFA8DC)
#define DTFSL099               (*(volatile unsigned long  *)0xFFFFA8E0)
#define DTFST099               (*(volatile unsigned long  *)0xFFFFA8E4)
#define DTFSS099               (*(volatile unsigned long  *)0xFFFFA8E8)
#define DTFSC099               (*(volatile unsigned long  *)0xFFFFA8EC)
#define DTSA100                (*(volatile unsigned long  *)0xFFFFA900)
#define DTDA100                (*(volatile unsigned long  *)0xFFFFA904)
#define DTTC100                (*(volatile unsigned long  *)0xFFFFA908)
#define DTTCT100               (*(volatile unsigned long  *)0xFFFFA90C)
#define DTRSA100               (*(volatile unsigned long  *)0xFFFFA910)
#define DTRDA100               (*(volatile unsigned long  *)0xFFFFA914)
#define DTRTC100               (*(volatile unsigned long  *)0xFFFFA918)
#define DTTCC100               (*(volatile unsigned long  *)0xFFFFA91C)
#define DTFSL100               (*(volatile unsigned long  *)0xFFFFA920)
#define DTFST100               (*(volatile unsigned long  *)0xFFFFA924)
#define DTFSS100               (*(volatile unsigned long  *)0xFFFFA928)
#define DTFSC100               (*(volatile unsigned long  *)0xFFFFA92C)
#define DTSA101                (*(volatile unsigned long  *)0xFFFFA940)
#define DTDA101                (*(volatile unsigned long  *)0xFFFFA944)
#define DTTC101                (*(volatile unsigned long  *)0xFFFFA948)
#define DTTCT101               (*(volatile unsigned long  *)0xFFFFA94C)
#define DTRSA101               (*(volatile unsigned long  *)0xFFFFA950)
#define DTRDA101               (*(volatile unsigned long  *)0xFFFFA954)
#define DTRTC101               (*(volatile unsigned long  *)0xFFFFA958)
#define DTTCC101               (*(volatile unsigned long  *)0xFFFFA95C)
#define DTFSL101               (*(volatile unsigned long  *)0xFFFFA960)
#define DTFST101               (*(volatile unsigned long  *)0xFFFFA964)
#define DTFSS101               (*(volatile unsigned long  *)0xFFFFA968)
#define DTFSC101               (*(volatile unsigned long  *)0xFFFFA96C)
#define DTSA102                (*(volatile unsigned long  *)0xFFFFA980)
#define DTDA102                (*(volatile unsigned long  *)0xFFFFA984)
#define DTTC102                (*(volatile unsigned long  *)0xFFFFA988)
#define DTTCT102               (*(volatile unsigned long  *)0xFFFFA98C)
#define DTRSA102               (*(volatile unsigned long  *)0xFFFFA990)
#define DTRDA102               (*(volatile unsigned long  *)0xFFFFA994)
#define DTRTC102               (*(volatile unsigned long  *)0xFFFFA998)
#define DTTCC102               (*(volatile unsigned long  *)0xFFFFA99C)
#define DTFSL102               (*(volatile unsigned long  *)0xFFFFA9A0)
#define DTFST102               (*(volatile unsigned long  *)0xFFFFA9A4)
#define DTFSS102               (*(volatile unsigned long  *)0xFFFFA9A8)
#define DTFSC102               (*(volatile unsigned long  *)0xFFFFA9AC)
#define DTSA103                (*(volatile unsigned long  *)0xFFFFA9C0)
#define DTDA103                (*(volatile unsigned long  *)0xFFFFA9C4)
#define DTTC103                (*(volatile unsigned long  *)0xFFFFA9C8)
#define DTTCT103               (*(volatile unsigned long  *)0xFFFFA9CC)
#define DTRSA103               (*(volatile unsigned long  *)0xFFFFA9D0)
#define DTRDA103               (*(volatile unsigned long  *)0xFFFFA9D4)
#define DTRTC103               (*(volatile unsigned long  *)0xFFFFA9D8)
#define DTTCC103               (*(volatile unsigned long  *)0xFFFFA9DC)
#define DTFSL103               (*(volatile unsigned long  *)0xFFFFA9E0)
#define DTFST103               (*(volatile unsigned long  *)0xFFFFA9E4)
#define DTFSS103               (*(volatile unsigned long  *)0xFFFFA9E8)
#define DTFSC103               (*(volatile unsigned long  *)0xFFFFA9EC)
#define DTSA104                (*(volatile unsigned long  *)0xFFFFAA00)
#define DTDA104                (*(volatile unsigned long  *)0xFFFFAA04)
#define DTTC104                (*(volatile unsigned long  *)0xFFFFAA08)
#define DTTCT104               (*(volatile unsigned long  *)0xFFFFAA0C)
#define DTRSA104               (*(volatile unsigned long  *)0xFFFFAA10)
#define DTRDA104               (*(volatile unsigned long  *)0xFFFFAA14)
#define DTRTC104               (*(volatile unsigned long  *)0xFFFFAA18)
#define DTTCC104               (*(volatile unsigned long  *)0xFFFFAA1C)
#define DTFSL104               (*(volatile unsigned long  *)0xFFFFAA20)
#define DTFST104               (*(volatile unsigned long  *)0xFFFFAA24)
#define DTFSS104               (*(volatile unsigned long  *)0xFFFFAA28)
#define DTFSC104               (*(volatile unsigned long  *)0xFFFFAA2C)
#define DTSA105                (*(volatile unsigned long  *)0xFFFFAA40)
#define DTDA105                (*(volatile unsigned long  *)0xFFFFAA44)
#define DTTC105                (*(volatile unsigned long  *)0xFFFFAA48)
#define DTTCT105               (*(volatile unsigned long  *)0xFFFFAA4C)
#define DTRSA105               (*(volatile unsigned long  *)0xFFFFAA50)
#define DTRDA105               (*(volatile unsigned long  *)0xFFFFAA54)
#define DTRTC105               (*(volatile unsigned long  *)0xFFFFAA58)
#define DTTCC105               (*(volatile unsigned long  *)0xFFFFAA5C)
#define DTFSL105               (*(volatile unsigned long  *)0xFFFFAA60)
#define DTFST105               (*(volatile unsigned long  *)0xFFFFAA64)
#define DTFSS105               (*(volatile unsigned long  *)0xFFFFAA68)
#define DTFSC105               (*(volatile unsigned long  *)0xFFFFAA6C)
#define DTSA106                (*(volatile unsigned long  *)0xFFFFAA80)
#define DTDA106                (*(volatile unsigned long  *)0xFFFFAA84)
#define DTTC106                (*(volatile unsigned long  *)0xFFFFAA88)
#define DTTCT106               (*(volatile unsigned long  *)0xFFFFAA8C)
#define DTRSA106               (*(volatile unsigned long  *)0xFFFFAA90)
#define DTRDA106               (*(volatile unsigned long  *)0xFFFFAA94)
#define DTRTC106               (*(volatile unsigned long  *)0xFFFFAA98)
#define DTTCC106               (*(volatile unsigned long  *)0xFFFFAA9C)
#define DTFSL106               (*(volatile unsigned long  *)0xFFFFAAA0)
#define DTFST106               (*(volatile unsigned long  *)0xFFFFAAA4)
#define DTFSS106               (*(volatile unsigned long  *)0xFFFFAAA8)
#define DTFSC106               (*(volatile unsigned long  *)0xFFFFAAAC)
#define DTSA107                (*(volatile unsigned long  *)0xFFFFAAC0)
#define DTDA107                (*(volatile unsigned long  *)0xFFFFAAC4)
#define DTTC107                (*(volatile unsigned long  *)0xFFFFAAC8)
#define DTTCT107               (*(volatile unsigned long  *)0xFFFFAACC)
#define DTRSA107               (*(volatile unsigned long  *)0xFFFFAAD0)
#define DTRDA107               (*(volatile unsigned long  *)0xFFFFAAD4)
#define DTRTC107               (*(volatile unsigned long  *)0xFFFFAAD8)
#define DTTCC107               (*(volatile unsigned long  *)0xFFFFAADC)
#define DTFSL107               (*(volatile unsigned long  *)0xFFFFAAE0)
#define DTFST107               (*(volatile unsigned long  *)0xFFFFAAE4)
#define DTFSS107               (*(volatile unsigned long  *)0xFFFFAAE8)
#define DTFSC107               (*(volatile unsigned long  *)0xFFFFAAEC)
#define DTSA108                (*(volatile unsigned long  *)0xFFFFAB00)
#define DTDA108                (*(volatile unsigned long  *)0xFFFFAB04)
#define DTTC108                (*(volatile unsigned long  *)0xFFFFAB08)
#define DTTCT108               (*(volatile unsigned long  *)0xFFFFAB0C)
#define DTRSA108               (*(volatile unsigned long  *)0xFFFFAB10)
#define DTRDA108               (*(volatile unsigned long  *)0xFFFFAB14)
#define DTRTC108               (*(volatile unsigned long  *)0xFFFFAB18)
#define DTTCC108               (*(volatile unsigned long  *)0xFFFFAB1C)
#define DTFSL108               (*(volatile unsigned long  *)0xFFFFAB20)
#define DTFST108               (*(volatile unsigned long  *)0xFFFFAB24)
#define DTFSS108               (*(volatile unsigned long  *)0xFFFFAB28)
#define DTFSC108               (*(volatile unsigned long  *)0xFFFFAB2C)
#define DTSA109                (*(volatile unsigned long  *)0xFFFFAB40)
#define DTDA109                (*(volatile unsigned long  *)0xFFFFAB44)
#define DTTC109                (*(volatile unsigned long  *)0xFFFFAB48)
#define DTTCT109               (*(volatile unsigned long  *)0xFFFFAB4C)
#define DTRSA109               (*(volatile unsigned long  *)0xFFFFAB50)
#define DTRDA109               (*(volatile unsigned long  *)0xFFFFAB54)
#define DTRTC109               (*(volatile unsigned long  *)0xFFFFAB58)
#define DTTCC109               (*(volatile unsigned long  *)0xFFFFAB5C)
#define DTFSL109               (*(volatile unsigned long  *)0xFFFFAB60)
#define DTFST109               (*(volatile unsigned long  *)0xFFFFAB64)
#define DTFSS109               (*(volatile unsigned long  *)0xFFFFAB68)
#define DTFSC109               (*(volatile unsigned long  *)0xFFFFAB6C)
#define DTSA110                (*(volatile unsigned long  *)0xFFFFAB80)
#define DTDA110                (*(volatile unsigned long  *)0xFFFFAB84)
#define DTTC110                (*(volatile unsigned long  *)0xFFFFAB88)
#define DTTCT110               (*(volatile unsigned long  *)0xFFFFAB8C)
#define DTRSA110               (*(volatile unsigned long  *)0xFFFFAB90)
#define DTRDA110               (*(volatile unsigned long  *)0xFFFFAB94)
#define DTRTC110               (*(volatile unsigned long  *)0xFFFFAB98)
#define DTTCC110               (*(volatile unsigned long  *)0xFFFFAB9C)
#define DTFSL110               (*(volatile unsigned long  *)0xFFFFABA0)
#define DTFST110               (*(volatile unsigned long  *)0xFFFFABA4)
#define DTFSS110               (*(volatile unsigned long  *)0xFFFFABA8)
#define DTFSC110               (*(volatile unsigned long  *)0xFFFFABAC)
#define DTSA111                (*(volatile unsigned long  *)0xFFFFABC0)
#define DTDA111                (*(volatile unsigned long  *)0xFFFFABC4)
#define DTTC111                (*(volatile unsigned long  *)0xFFFFABC8)
#define DTTCT111               (*(volatile unsigned long  *)0xFFFFABCC)
#define DTRSA111               (*(volatile unsigned long  *)0xFFFFABD0)
#define DTRDA111               (*(volatile unsigned long  *)0xFFFFABD4)
#define DTRTC111               (*(volatile unsigned long  *)0xFFFFABD8)
#define DTTCC111               (*(volatile unsigned long  *)0xFFFFABDC)
#define DTFSL111               (*(volatile unsigned long  *)0xFFFFABE0)
#define DTFST111               (*(volatile unsigned long  *)0xFFFFABE4)
#define DTFSS111               (*(volatile unsigned long  *)0xFFFFABE8)
#define DTFSC111               (*(volatile unsigned long  *)0xFFFFABEC)
#define DTSA112                (*(volatile unsigned long  *)0xFFFFAC00)
#define DTDA112                (*(volatile unsigned long  *)0xFFFFAC04)
#define DTTC112                (*(volatile unsigned long  *)0xFFFFAC08)
#define DTTCT112               (*(volatile unsigned long  *)0xFFFFAC0C)
#define DTRSA112               (*(volatile unsigned long  *)0xFFFFAC10)
#define DTRDA112               (*(volatile unsigned long  *)0xFFFFAC14)
#define DTRTC112               (*(volatile unsigned long  *)0xFFFFAC18)
#define DTTCC112               (*(volatile unsigned long  *)0xFFFFAC1C)
#define DTFSL112               (*(volatile unsigned long  *)0xFFFFAC20)
#define DTFST112               (*(volatile unsigned long  *)0xFFFFAC24)
#define DTFSS112               (*(volatile unsigned long  *)0xFFFFAC28)
#define DTFSC112               (*(volatile unsigned long  *)0xFFFFAC2C)
#define DTSA113                (*(volatile unsigned long  *)0xFFFFAC40)
#define DTDA113                (*(volatile unsigned long  *)0xFFFFAC44)
#define DTTC113                (*(volatile unsigned long  *)0xFFFFAC48)
#define DTTCT113               (*(volatile unsigned long  *)0xFFFFAC4C)
#define DTRSA113               (*(volatile unsigned long  *)0xFFFFAC50)
#define DTRDA113               (*(volatile unsigned long  *)0xFFFFAC54)
#define DTRTC113               (*(volatile unsigned long  *)0xFFFFAC58)
#define DTTCC113               (*(volatile unsigned long  *)0xFFFFAC5C)
#define DTFSL113               (*(volatile unsigned long  *)0xFFFFAC60)
#define DTFST113               (*(volatile unsigned long  *)0xFFFFAC64)
#define DTFSS113               (*(volatile unsigned long  *)0xFFFFAC68)
#define DTFSC113               (*(volatile unsigned long  *)0xFFFFAC6C)
#define DTSA114                (*(volatile unsigned long  *)0xFFFFAC80)
#define DTDA114                (*(volatile unsigned long  *)0xFFFFAC84)
#define DTTC114                (*(volatile unsigned long  *)0xFFFFAC88)
#define DTTCT114               (*(volatile unsigned long  *)0xFFFFAC8C)
#define DTRSA114               (*(volatile unsigned long  *)0xFFFFAC90)
#define DTRDA114               (*(volatile unsigned long  *)0xFFFFAC94)
#define DTRTC114               (*(volatile unsigned long  *)0xFFFFAC98)
#define DTTCC114               (*(volatile unsigned long  *)0xFFFFAC9C)
#define DTFSL114               (*(volatile unsigned long  *)0xFFFFACA0)
#define DTFST114               (*(volatile unsigned long  *)0xFFFFACA4)
#define DTFSS114               (*(volatile unsigned long  *)0xFFFFACA8)
#define DTFSC114               (*(volatile unsigned long  *)0xFFFFACAC)
#define DTSA115                (*(volatile unsigned long  *)0xFFFFACC0)
#define DTDA115                (*(volatile unsigned long  *)0xFFFFACC4)
#define DTTC115                (*(volatile unsigned long  *)0xFFFFACC8)
#define DTTCT115               (*(volatile unsigned long  *)0xFFFFACCC)
#define DTRSA115               (*(volatile unsigned long  *)0xFFFFACD0)
#define DTRDA115               (*(volatile unsigned long  *)0xFFFFACD4)
#define DTRTC115               (*(volatile unsigned long  *)0xFFFFACD8)
#define DTTCC115               (*(volatile unsigned long  *)0xFFFFACDC)
#define DTFSL115               (*(volatile unsigned long  *)0xFFFFACE0)
#define DTFST115               (*(volatile unsigned long  *)0xFFFFACE4)
#define DTFSS115               (*(volatile unsigned long  *)0xFFFFACE8)
#define DTFSC115               (*(volatile unsigned long  *)0xFFFFACEC)
#define DTSA116                (*(volatile unsigned long  *)0xFFFFAD00)
#define DTDA116                (*(volatile unsigned long  *)0xFFFFAD04)
#define DTTC116                (*(volatile unsigned long  *)0xFFFFAD08)
#define DTTCT116               (*(volatile unsigned long  *)0xFFFFAD0C)
#define DTRSA116               (*(volatile unsigned long  *)0xFFFFAD10)
#define DTRDA116               (*(volatile unsigned long  *)0xFFFFAD14)
#define DTRTC116               (*(volatile unsigned long  *)0xFFFFAD18)
#define DTTCC116               (*(volatile unsigned long  *)0xFFFFAD1C)
#define DTFSL116               (*(volatile unsigned long  *)0xFFFFAD20)
#define DTFST116               (*(volatile unsigned long  *)0xFFFFAD24)
#define DTFSS116               (*(volatile unsigned long  *)0xFFFFAD28)
#define DTFSC116               (*(volatile unsigned long  *)0xFFFFAD2C)
#define DTSA117                (*(volatile unsigned long  *)0xFFFFAD40)
#define DTDA117                (*(volatile unsigned long  *)0xFFFFAD44)
#define DTTC117                (*(volatile unsigned long  *)0xFFFFAD48)
#define DTTCT117               (*(volatile unsigned long  *)0xFFFFAD4C)
#define DTRSA117               (*(volatile unsigned long  *)0xFFFFAD50)
#define DTRDA117               (*(volatile unsigned long  *)0xFFFFAD54)
#define DTRTC117               (*(volatile unsigned long  *)0xFFFFAD58)
#define DTTCC117               (*(volatile unsigned long  *)0xFFFFAD5C)
#define DTFSL117               (*(volatile unsigned long  *)0xFFFFAD60)
#define DTFST117               (*(volatile unsigned long  *)0xFFFFAD64)
#define DTFSS117               (*(volatile unsigned long  *)0xFFFFAD68)
#define DTFSC117               (*(volatile unsigned long  *)0xFFFFAD6C)
#define DTSA118                (*(volatile unsigned long  *)0xFFFFAD80)
#define DTDA118                (*(volatile unsigned long  *)0xFFFFAD84)
#define DTTC118                (*(volatile unsigned long  *)0xFFFFAD88)
#define DTTCT118               (*(volatile unsigned long  *)0xFFFFAD8C)
#define DTRSA118               (*(volatile unsigned long  *)0xFFFFAD90)
#define DTRDA118               (*(volatile unsigned long  *)0xFFFFAD94)
#define DTRTC118               (*(volatile unsigned long  *)0xFFFFAD98)
#define DTTCC118               (*(volatile unsigned long  *)0xFFFFAD9C)
#define DTFSL118               (*(volatile unsigned long  *)0xFFFFADA0)
#define DTFST118               (*(volatile unsigned long  *)0xFFFFADA4)
#define DTFSS118               (*(volatile unsigned long  *)0xFFFFADA8)
#define DTFSC118               (*(volatile unsigned long  *)0xFFFFADAC)
#define DTSA119                (*(volatile unsigned long  *)0xFFFFADC0)
#define DTDA119                (*(volatile unsigned long  *)0xFFFFADC4)
#define DTTC119                (*(volatile unsigned long  *)0xFFFFADC8)
#define DTTCT119               (*(volatile unsigned long  *)0xFFFFADCC)
#define DTRSA119               (*(volatile unsigned long  *)0xFFFFADD0)
#define DTRDA119               (*(volatile unsigned long  *)0xFFFFADD4)
#define DTRTC119               (*(volatile unsigned long  *)0xFFFFADD8)
#define DTTCC119               (*(volatile unsigned long  *)0xFFFFADDC)
#define DTFSL119               (*(volatile unsigned long  *)0xFFFFADE0)
#define DTFST119               (*(volatile unsigned long  *)0xFFFFADE4)
#define DTFSS119               (*(volatile unsigned long  *)0xFFFFADE8)
#define DTFSC119               (*(volatile unsigned long  *)0xFFFFADEC)
#define DTSA120                (*(volatile unsigned long  *)0xFFFFAE00)
#define DTDA120                (*(volatile unsigned long  *)0xFFFFAE04)
#define DTTC120                (*(volatile unsigned long  *)0xFFFFAE08)
#define DTTCT120               (*(volatile unsigned long  *)0xFFFFAE0C)
#define DTRSA120               (*(volatile unsigned long  *)0xFFFFAE10)
#define DTRDA120               (*(volatile unsigned long  *)0xFFFFAE14)
#define DTRTC120               (*(volatile unsigned long  *)0xFFFFAE18)
#define DTTCC120               (*(volatile unsigned long  *)0xFFFFAE1C)
#define DTFSL120               (*(volatile unsigned long  *)0xFFFFAE20)
#define DTFST120               (*(volatile unsigned long  *)0xFFFFAE24)
#define DTFSS120               (*(volatile unsigned long  *)0xFFFFAE28)
#define DTFSC120               (*(volatile unsigned long  *)0xFFFFAE2C)
#define DTSA121                (*(volatile unsigned long  *)0xFFFFAE40)
#define DTDA121                (*(volatile unsigned long  *)0xFFFFAE44)
#define DTTC121                (*(volatile unsigned long  *)0xFFFFAE48)
#define DTTCT121               (*(volatile unsigned long  *)0xFFFFAE4C)
#define DTRSA121               (*(volatile unsigned long  *)0xFFFFAE50)
#define DTRDA121               (*(volatile unsigned long  *)0xFFFFAE54)
#define DTRTC121               (*(volatile unsigned long  *)0xFFFFAE58)
#define DTTCC121               (*(volatile unsigned long  *)0xFFFFAE5C)
#define DTFSL121               (*(volatile unsigned long  *)0xFFFFAE60)
#define DTFST121               (*(volatile unsigned long  *)0xFFFFAE64)
#define DTFSS121               (*(volatile unsigned long  *)0xFFFFAE68)
#define DTFSC121               (*(volatile unsigned long  *)0xFFFFAE6C)
#define DTSA122                (*(volatile unsigned long  *)0xFFFFAE80)
#define DTDA122                (*(volatile unsigned long  *)0xFFFFAE84)
#define DTTC122                (*(volatile unsigned long  *)0xFFFFAE88)
#define DTTCT122               (*(volatile unsigned long  *)0xFFFFAE8C)
#define DTRSA122               (*(volatile unsigned long  *)0xFFFFAE90)
#define DTRDA122               (*(volatile unsigned long  *)0xFFFFAE94)
#define DTRTC122               (*(volatile unsigned long  *)0xFFFFAE98)
#define DTTCC122               (*(volatile unsigned long  *)0xFFFFAE9C)
#define DTFSL122               (*(volatile unsigned long  *)0xFFFFAEA0)
#define DTFST122               (*(volatile unsigned long  *)0xFFFFAEA4)
#define DTFSS122               (*(volatile unsigned long  *)0xFFFFAEA8)
#define DTFSC122               (*(volatile unsigned long  *)0xFFFFAEAC)
#define DTSA123                (*(volatile unsigned long  *)0xFFFFAEC0)
#define DTDA123                (*(volatile unsigned long  *)0xFFFFAEC4)
#define DTTC123                (*(volatile unsigned long  *)0xFFFFAEC8)
#define DTTCT123               (*(volatile unsigned long  *)0xFFFFAECC)
#define DTRSA123               (*(volatile unsigned long  *)0xFFFFAED0)
#define DTRDA123               (*(volatile unsigned long  *)0xFFFFAED4)
#define DTRTC123               (*(volatile unsigned long  *)0xFFFFAED8)
#define DTTCC123               (*(volatile unsigned long  *)0xFFFFAEDC)
#define DTFSL123               (*(volatile unsigned long  *)0xFFFFAEE0)
#define DTFST123               (*(volatile unsigned long  *)0xFFFFAEE4)
#define DTFSS123               (*(volatile unsigned long  *)0xFFFFAEE8)
#define DTFSC123               (*(volatile unsigned long  *)0xFFFFAEEC)
#define DTSA124                (*(volatile unsigned long  *)0xFFFFAF00)
#define DTDA124                (*(volatile unsigned long  *)0xFFFFAF04)
#define DTTC124                (*(volatile unsigned long  *)0xFFFFAF08)
#define DTTCT124               (*(volatile unsigned long  *)0xFFFFAF0C)
#define DTRSA124               (*(volatile unsigned long  *)0xFFFFAF10)
#define DTRDA124               (*(volatile unsigned long  *)0xFFFFAF14)
#define DTRTC124               (*(volatile unsigned long  *)0xFFFFAF18)
#define DTTCC124               (*(volatile unsigned long  *)0xFFFFAF1C)
#define DTFSL124               (*(volatile unsigned long  *)0xFFFFAF20)
#define DTFST124               (*(volatile unsigned long  *)0xFFFFAF24)
#define DTFSS124               (*(volatile unsigned long  *)0xFFFFAF28)
#define DTFSC124               (*(volatile unsigned long  *)0xFFFFAF2C)
#define DTSA125                (*(volatile unsigned long  *)0xFFFFAF40)
#define DTDA125                (*(volatile unsigned long  *)0xFFFFAF44)
#define DTTC125                (*(volatile unsigned long  *)0xFFFFAF48)
#define DTTCT125               (*(volatile unsigned long  *)0xFFFFAF4C)
#define DTRSA125               (*(volatile unsigned long  *)0xFFFFAF50)
#define DTRDA125               (*(volatile unsigned long  *)0xFFFFAF54)
#define DTRTC125               (*(volatile unsigned long  *)0xFFFFAF58)
#define DTTCC125               (*(volatile unsigned long  *)0xFFFFAF5C)
#define DTFSL125               (*(volatile unsigned long  *)0xFFFFAF60)
#define DTFST125               (*(volatile unsigned long  *)0xFFFFAF64)
#define DTFSS125               (*(volatile unsigned long  *)0xFFFFAF68)
#define DTFSC125               (*(volatile unsigned long  *)0xFFFFAF6C)
#define DTSA126                (*(volatile unsigned long  *)0xFFFFAF80)
#define DTDA126                (*(volatile unsigned long  *)0xFFFFAF84)
#define DTTC126                (*(volatile unsigned long  *)0xFFFFAF88)
#define DTTCT126               (*(volatile unsigned long  *)0xFFFFAF8C)
#define DTRSA126               (*(volatile unsigned long  *)0xFFFFAF90)
#define DTRDA126               (*(volatile unsigned long  *)0xFFFFAF94)
#define DTRTC126               (*(volatile unsigned long  *)0xFFFFAF98)
#define DTTCC126               (*(volatile unsigned long  *)0xFFFFAF9C)
#define DTFSL126               (*(volatile unsigned long  *)0xFFFFAFA0)
#define DTFST126               (*(volatile unsigned long  *)0xFFFFAFA4)
#define DTFSS126               (*(volatile unsigned long  *)0xFFFFAFA8)
#define DTFSC126               (*(volatile unsigned long  *)0xFFFFAFAC)
#define DTSA127                (*(volatile unsigned long  *)0xFFFFAFC0)
#define DTDA127                (*(volatile unsigned long  *)0xFFFFAFC4)
#define DTTC127                (*(volatile unsigned long  *)0xFFFFAFC8)
#define DTTCT127               (*(volatile unsigned long  *)0xFFFFAFCC)
#define DTRSA127               (*(volatile unsigned long  *)0xFFFFAFD0)
#define DTRDA127               (*(volatile unsigned long  *)0xFFFFAFD4)
#define DTRTC127               (*(volatile unsigned long  *)0xFFFFAFD8)
#define DTTCC127               (*(volatile unsigned long  *)0xFFFFAFDC)
#define DTFSL127               (*(volatile unsigned long  *)0xFFFFAFE0)
#define DTFST127               (*(volatile unsigned long  *)0xFFFFAFE4)
#define DTFSS127               (*(volatile unsigned long  *)0xFFFFAFE8)
#define DTFSC127               (*(volatile unsigned long  *)0xFFFFAFEC)
#define EIC32                  (*(volatile unsigned short *)0xFFFFB040)
#define EIC32L                 (*(volatile unsigned char  *)0xFFFFB040)
#define EIC32H                 (*(volatile unsigned char  *)0xFFFFB041)
#define EIC33                  (*(volatile unsigned short *)0xFFFFB042)
#define EIC33L                 (*(volatile unsigned char  *)0xFFFFB042)
#define EIC33H                 (*(volatile unsigned char  *)0xFFFFB043)
#define EIC34                  (*(volatile unsigned short *)0xFFFFB044)
#define EIC34L                 (*(volatile unsigned char  *)0xFFFFB044)
#define EIC34H                 (*(volatile unsigned char  *)0xFFFFB045)
#define EIC35                  (*(volatile unsigned short *)0xFFFFB046)
#define EIC35L                 (*(volatile unsigned char  *)0xFFFFB046)
#define EIC35H                 (*(volatile unsigned char  *)0xFFFFB047)
#define EIC36                  (*(volatile unsigned short *)0xFFFFB048)
#define EIC36L                 (*(volatile unsigned char  *)0xFFFFB048)
#define EIC36H                 (*(volatile unsigned char  *)0xFFFFB049)
#define EIC37                  (*(volatile unsigned short *)0xFFFFB04A)
#define EIC37L                 (*(volatile unsigned char  *)0xFFFFB04A)
#define EIC37H                 (*(volatile unsigned char  *)0xFFFFB04B)
#define EIC38                  (*(volatile unsigned short *)0xFFFFB04C)
#define EIC38L                 (*(volatile unsigned char  *)0xFFFFB04C)
#define EIC38H                 (*(volatile unsigned char  *)0xFFFFB04D)
#define EIC39                  (*(volatile unsigned short *)0xFFFFB04E)
#define EIC39L                 (*(volatile unsigned char  *)0xFFFFB04E)
#define EIC39H                 (*(volatile unsigned char  *)0xFFFFB04F)
#define EIC40                  (*(volatile unsigned short *)0xFFFFB050)
#define EIC40L                 (*(volatile unsigned char  *)0xFFFFB050)
#define EIC40H                 (*(volatile unsigned char  *)0xFFFFB051)
#define EIC41                  (*(volatile unsigned short *)0xFFFFB052)
#define EIC41L                 (*(volatile unsigned char  *)0xFFFFB052)
#define EIC41H                 (*(volatile unsigned char  *)0xFFFFB053)
#define EIC42                  (*(volatile unsigned short *)0xFFFFB054)
#define EIC42L                 (*(volatile unsigned char  *)0xFFFFB054)
#define EIC42H                 (*(volatile unsigned char  *)0xFFFFB055)
#define EIC43                  (*(volatile unsigned short *)0xFFFFB056)
#define EIC43L                 (*(volatile unsigned char  *)0xFFFFB056)
#define EIC43H                 (*(volatile unsigned char  *)0xFFFFB057)
#define EIC44                  (*(volatile unsigned short *)0xFFFFB058)
#define EIC44L                 (*(volatile unsigned char  *)0xFFFFB058)
#define EIC44H                 (*(volatile unsigned char  *)0xFFFFB059)
#define EIC45                  (*(volatile unsigned short *)0xFFFFB05A)
#define EIC45L                 (*(volatile unsigned char  *)0xFFFFB05A)
#define EIC45H                 (*(volatile unsigned char  *)0xFFFFB05B)
#define EIC46                  (*(volatile unsigned short *)0xFFFFB05C)
#define EIC46L                 (*(volatile unsigned char  *)0xFFFFB05C)
#define EIC46H                 (*(volatile unsigned char  *)0xFFFFB05D)
#define EIC47                  (*(volatile unsigned short *)0xFFFFB05E)
#define EIC47L                 (*(volatile unsigned char  *)0xFFFFB05E)
#define EIC47H                 (*(volatile unsigned char  *)0xFFFFB05F)
#define EIC48                  (*(volatile unsigned short *)0xFFFFB060)
#define EIC48L                 (*(volatile unsigned char  *)0xFFFFB060)
#define EIC48H                 (*(volatile unsigned char  *)0xFFFFB061)
#define EIC49                  (*(volatile unsigned short *)0xFFFFB062)
#define EIC49L                 (*(volatile unsigned char  *)0xFFFFB062)
#define EIC49H                 (*(volatile unsigned char  *)0xFFFFB063)
#define EIC50                  (*(volatile unsigned short *)0xFFFFB064)
#define EIC50L                 (*(volatile unsigned char  *)0xFFFFB064)
#define EIC50H                 (*(volatile unsigned char  *)0xFFFFB065)
#define EIC51                  (*(volatile unsigned short *)0xFFFFB066)
#define EIC51L                 (*(volatile unsigned char  *)0xFFFFB066)
#define EIC51H                 (*(volatile unsigned char  *)0xFFFFB067)
#define EIC52                  (*(volatile unsigned short *)0xFFFFB068)
#define EIC52L                 (*(volatile unsigned char  *)0xFFFFB068)
#define EIC52H                 (*(volatile unsigned char  *)0xFFFFB069)
#define EIC53                  (*(volatile unsigned short *)0xFFFFB06A)
#define EIC53L                 (*(volatile unsigned char  *)0xFFFFB06A)
#define EIC53H                 (*(volatile unsigned char  *)0xFFFFB06B)
#define EIC54                  (*(volatile unsigned short *)0xFFFFB06C)
#define EIC54L                 (*(volatile unsigned char  *)0xFFFFB06C)
#define EIC54H                 (*(volatile unsigned char  *)0xFFFFB06D)
#define EIC55                  (*(volatile unsigned short *)0xFFFFB06E)
#define EIC55L                 (*(volatile unsigned char  *)0xFFFFB06E)
#define EIC55H                 (*(volatile unsigned char  *)0xFFFFB06F)
#define EIC56                  (*(volatile unsigned short *)0xFFFFB070)
#define EIC56L                 (*(volatile unsigned char  *)0xFFFFB070)
#define EIC56H                 (*(volatile unsigned char  *)0xFFFFB071)
#define EIC57                  (*(volatile unsigned short *)0xFFFFB072)
#define EIC57L                 (*(volatile unsigned char  *)0xFFFFB072)
#define EIC57H                 (*(volatile unsigned char  *)0xFFFFB073)
#define EIC58                  (*(volatile unsigned short *)0xFFFFB074)
#define EIC58L                 (*(volatile unsigned char  *)0xFFFFB074)
#define EIC58H                 (*(volatile unsigned char  *)0xFFFFB075)
#define EIC59                  (*(volatile unsigned short *)0xFFFFB076)
#define EIC59L                 (*(volatile unsigned char  *)0xFFFFB076)
#define EIC59H                 (*(volatile unsigned char  *)0xFFFFB077)
#define EIC60                  (*(volatile unsigned short *)0xFFFFB078)
#define EIC60L                 (*(volatile unsigned char  *)0xFFFFB078)
#define EIC60H                 (*(volatile unsigned char  *)0xFFFFB079)
#define EIC61                  (*(volatile unsigned short *)0xFFFFB07A)
#define EIC61L                 (*(volatile unsigned char  *)0xFFFFB07A)
#define EIC61H                 (*(volatile unsigned char  *)0xFFFFB07B)
#define EIC62                  (*(volatile unsigned short *)0xFFFFB07C)
#define EIC62L                 (*(volatile unsigned char  *)0xFFFFB07C)
#define EIC62H                 (*(volatile unsigned char  *)0xFFFFB07D)
#define EIC63                  (*(volatile unsigned short *)0xFFFFB07E)
#define EIC63L                 (*(volatile unsigned char  *)0xFFFFB07E)
#define EIC63H                 (*(volatile unsigned char  *)0xFFFFB07F)
#define EIC64                  (*(volatile unsigned short *)0xFFFFB080)
#define EIC64L                 (*(volatile unsigned char  *)0xFFFFB080)
#define EIC64H                 (*(volatile unsigned char  *)0xFFFFB081)
#define EIC65                  (*(volatile unsigned short *)0xFFFFB082)
#define EIC65L                 (*(volatile unsigned char  *)0xFFFFB082)
#define EIC65H                 (*(volatile unsigned char  *)0xFFFFB083)
#define EIC66                  (*(volatile unsigned short *)0xFFFFB084)
#define EIC66L                 (*(volatile unsigned char  *)0xFFFFB084)
#define EIC66H                 (*(volatile unsigned char  *)0xFFFFB085)
#define EIC67                  (*(volatile unsigned short *)0xFFFFB086)
#define EIC67L                 (*(volatile unsigned char  *)0xFFFFB086)
#define EIC67H                 (*(volatile unsigned char  *)0xFFFFB087)
#define EIC68                  (*(volatile unsigned short *)0xFFFFB088)
#define EIC68L                 (*(volatile unsigned char  *)0xFFFFB088)
#define EIC68H                 (*(volatile unsigned char  *)0xFFFFB089)
#define EIC69                  (*(volatile unsigned short *)0xFFFFB08A)
#define EIC69L                 (*(volatile unsigned char  *)0xFFFFB08A)
#define EIC69H                 (*(volatile unsigned char  *)0xFFFFB08B)
#define EIC70                  (*(volatile unsigned short *)0xFFFFB08C)
#define EIC70L                 (*(volatile unsigned char  *)0xFFFFB08C)
#define EIC70H                 (*(volatile unsigned char  *)0xFFFFB08D)
#define EIC71                  (*(volatile unsigned short *)0xFFFFB08E)
#define EIC71L                 (*(volatile unsigned char  *)0xFFFFB08E)
#define EIC71H                 (*(volatile unsigned char  *)0xFFFFB08F)
#define EIC72                  (*(volatile unsigned short *)0xFFFFB090)
#define EIC72L                 (*(volatile unsigned char  *)0xFFFFB090)
#define EIC72H                 (*(volatile unsigned char  *)0xFFFFB091)
#define EIC73                  (*(volatile unsigned short *)0xFFFFB092)
#define EIC73L                 (*(volatile unsigned char  *)0xFFFFB092)
#define EIC73H                 (*(volatile unsigned char  *)0xFFFFB093)
#define EIC74                  (*(volatile unsigned short *)0xFFFFB094)
#define EIC74L                 (*(volatile unsigned char  *)0xFFFFB094)
#define EIC74H                 (*(volatile unsigned char  *)0xFFFFB095)
#define EIC75                  (*(volatile unsigned short *)0xFFFFB096)
#define EIC75L                 (*(volatile unsigned char  *)0xFFFFB096)
#define EIC75H                 (*(volatile unsigned char  *)0xFFFFB097)
#define EIC76                  (*(volatile unsigned short *)0xFFFFB098)
#define EIC76L                 (*(volatile unsigned char  *)0xFFFFB098)
#define EIC76H                 (*(volatile unsigned char  *)0xFFFFB099)
#define EIC77                  (*(volatile unsigned short *)0xFFFFB09A)
#define EIC77L                 (*(volatile unsigned char  *)0xFFFFB09A)
#define EIC77H                 (*(volatile unsigned char  *)0xFFFFB09B)
#define EIC78                  (*(volatile unsigned short *)0xFFFFB09C)
#define EIC78L                 (*(volatile unsigned char  *)0xFFFFB09C)
#define EIC78H                 (*(volatile unsigned char  *)0xFFFFB09D)
#define EIC79                  (*(volatile unsigned short *)0xFFFFB09E)
#define EIC79L                 (*(volatile unsigned char  *)0xFFFFB09E)
#define EIC79H                 (*(volatile unsigned char  *)0xFFFFB09F)
#define EIC80                  (*(volatile unsigned short *)0xFFFFB0A0)
#define EIC80L                 (*(volatile unsigned char  *)0xFFFFB0A0)
#define EIC80H                 (*(volatile unsigned char  *)0xFFFFB0A1)
#define EIC81                  (*(volatile unsigned short *)0xFFFFB0A2)
#define EIC81L                 (*(volatile unsigned char  *)0xFFFFB0A2)
#define EIC81H                 (*(volatile unsigned char  *)0xFFFFB0A3)
#define EIC82                  (*(volatile unsigned short *)0xFFFFB0A4)
#define EIC82L                 (*(volatile unsigned char  *)0xFFFFB0A4)
#define EIC82H                 (*(volatile unsigned char  *)0xFFFFB0A5)
#define EIC83                  (*(volatile unsigned short *)0xFFFFB0A6)
#define EIC83L                 (*(volatile unsigned char  *)0xFFFFB0A6)
#define EIC83H                 (*(volatile unsigned char  *)0xFFFFB0A7)
#define EIC84                  (*(volatile unsigned short *)0xFFFFB0A8)
#define EIC84L                 (*(volatile unsigned char  *)0xFFFFB0A8)
#define EIC84H                 (*(volatile unsigned char  *)0xFFFFB0A9)
#define EIC85                  (*(volatile unsigned short *)0xFFFFB0AA)
#define EIC85L                 (*(volatile unsigned char  *)0xFFFFB0AA)
#define EIC85H                 (*(volatile unsigned char  *)0xFFFFB0AB)
#define EIC86                  (*(volatile unsigned short *)0xFFFFB0AC)
#define EIC86L                 (*(volatile unsigned char  *)0xFFFFB0AC)
#define EIC86H                 (*(volatile unsigned char  *)0xFFFFB0AD)
#define EIC87                  (*(volatile unsigned short *)0xFFFFB0AE)
#define EIC87L                 (*(volatile unsigned char  *)0xFFFFB0AE)
#define EIC87H                 (*(volatile unsigned char  *)0xFFFFB0AF)
#define EIC88                  (*(volatile unsigned short *)0xFFFFB0B0)
#define EIC88L                 (*(volatile unsigned char  *)0xFFFFB0B0)
#define EIC88H                 (*(volatile unsigned char  *)0xFFFFB0B1)
#define EIC89                  (*(volatile unsigned short *)0xFFFFB0B2)
#define EIC89L                 (*(volatile unsigned char  *)0xFFFFB0B2)
#define EIC89H                 (*(volatile unsigned char  *)0xFFFFB0B3)
#define EIC90                  (*(volatile unsigned short *)0xFFFFB0B4)
#define EIC90L                 (*(volatile unsigned char  *)0xFFFFB0B4)
#define EIC90H                 (*(volatile unsigned char  *)0xFFFFB0B5)
#define EIC91                  (*(volatile unsigned short *)0xFFFFB0B6)
#define EIC91L                 (*(volatile unsigned char  *)0xFFFFB0B6)
#define EIC91H                 (*(volatile unsigned char  *)0xFFFFB0B7)
#define EIC92                  (*(volatile unsigned short *)0xFFFFB0B8)
#define EIC92L                 (*(volatile unsigned char  *)0xFFFFB0B8)
#define EIC92H                 (*(volatile unsigned char  *)0xFFFFB0B9)
#define EIC93                  (*(volatile unsigned short *)0xFFFFB0BA)
#define EIC93L                 (*(volatile unsigned char  *)0xFFFFB0BA)
#define EIC93H                 (*(volatile unsigned char  *)0xFFFFB0BB)
#define EIC94                  (*(volatile unsigned short *)0xFFFFB0BC)
#define EIC94L                 (*(volatile unsigned char  *)0xFFFFB0BC)
#define EIC94H                 (*(volatile unsigned char  *)0xFFFFB0BD)
#define EIC95                  (*(volatile unsigned short *)0xFFFFB0BE)
#define EIC95L                 (*(volatile unsigned char  *)0xFFFFB0BE)
#define EIC95H                 (*(volatile unsigned char  *)0xFFFFB0BF)
#define EIC96                  (*(volatile unsigned short *)0xFFFFB0C0)
#define EIC96L                 (*(volatile unsigned char  *)0xFFFFB0C0)
#define EIC96H                 (*(volatile unsigned char  *)0xFFFFB0C1)
#define EIC97                  (*(volatile unsigned short *)0xFFFFB0C2)
#define EIC97L                 (*(volatile unsigned char  *)0xFFFFB0C2)
#define EIC97H                 (*(volatile unsigned char  *)0xFFFFB0C3)
#define EIC98                  (*(volatile unsigned short *)0xFFFFB0C4)
#define EIC98L                 (*(volatile unsigned char  *)0xFFFFB0C4)
#define EIC98H                 (*(volatile unsigned char  *)0xFFFFB0C5)
#define EIC99                  (*(volatile unsigned short *)0xFFFFB0C6)
#define EIC99L                 (*(volatile unsigned char  *)0xFFFFB0C6)
#define EIC99H                 (*(volatile unsigned char  *)0xFFFFB0C7)
#define EIC100                 (*(volatile unsigned short *)0xFFFFB0C8)
#define EIC100L                (*(volatile unsigned char  *)0xFFFFB0C8)
#define EIC100H                (*(volatile unsigned char  *)0xFFFFB0C9)
#define EIC101                 (*(volatile unsigned short *)0xFFFFB0CA)
#define EIC101L                (*(volatile unsigned char  *)0xFFFFB0CA)
#define EIC101H                (*(volatile unsigned char  *)0xFFFFB0CB)
#define EIC102                 (*(volatile unsigned short *)0xFFFFB0CC)
#define EIC102L                (*(volatile unsigned char  *)0xFFFFB0CC)
#define EIC102H                (*(volatile unsigned char  *)0xFFFFB0CD)
#define EIC103                 (*(volatile unsigned short *)0xFFFFB0CE)
#define EIC103L                (*(volatile unsigned char  *)0xFFFFB0CE)
#define EIC103H                (*(volatile unsigned char  *)0xFFFFB0CF)
#define EIC104                 (*(volatile unsigned short *)0xFFFFB0D0)
#define EIC104L                (*(volatile unsigned char  *)0xFFFFB0D0)
#define EIC104H                (*(volatile unsigned char  *)0xFFFFB0D1)
#define EIC105                 (*(volatile unsigned short *)0xFFFFB0D2)
#define EIC105L                (*(volatile unsigned char  *)0xFFFFB0D2)
#define EIC105H                (*(volatile unsigned char  *)0xFFFFB0D3)
#define EIC106                 (*(volatile unsigned short *)0xFFFFB0D4)
#define EIC106L                (*(volatile unsigned char  *)0xFFFFB0D4)
#define EIC106H                (*(volatile unsigned char  *)0xFFFFB0D5)
#define EIC107                 (*(volatile unsigned short *)0xFFFFB0D6)
#define EIC107L                (*(volatile unsigned char  *)0xFFFFB0D6)
#define EIC107H                (*(volatile unsigned char  *)0xFFFFB0D7)
#define EIC108                 (*(volatile unsigned short *)0xFFFFB0D8)
#define EIC108L                (*(volatile unsigned char  *)0xFFFFB0D8)
#define EIC108H                (*(volatile unsigned char  *)0xFFFFB0D9)
#define EIC109                 (*(volatile unsigned short *)0xFFFFB0DA)
#define EIC109L                (*(volatile unsigned char  *)0xFFFFB0DA)
#define EIC109H                (*(volatile unsigned char  *)0xFFFFB0DB)
#define EIC110                 (*(volatile unsigned short *)0xFFFFB0DC)
#define EIC110L                (*(volatile unsigned char  *)0xFFFFB0DC)
#define EIC110H                (*(volatile unsigned char  *)0xFFFFB0DD)
#define EIC111                 (*(volatile unsigned short *)0xFFFFB0DE)
#define EIC111L                (*(volatile unsigned char  *)0xFFFFB0DE)
#define EIC111H                (*(volatile unsigned char  *)0xFFFFB0DF)
#define EIC112                 (*(volatile unsigned short *)0xFFFFB0E0)
#define EIC112L                (*(volatile unsigned char  *)0xFFFFB0E0)
#define EIC112H                (*(volatile unsigned char  *)0xFFFFB0E1)
#define EIC113                 (*(volatile unsigned short *)0xFFFFB0E2)
#define EIC113L                (*(volatile unsigned char  *)0xFFFFB0E2)
#define EIC113H                (*(volatile unsigned char  *)0xFFFFB0E3)
#define EIC114                 (*(volatile unsigned short *)0xFFFFB0E4)
#define EIC114L                (*(volatile unsigned char  *)0xFFFFB0E4)
#define EIC114H                (*(volatile unsigned char  *)0xFFFFB0E5)
#define EIC115                 (*(volatile unsigned short *)0xFFFFB0E6)
#define EIC115L                (*(volatile unsigned char  *)0xFFFFB0E6)
#define EIC115H                (*(volatile unsigned char  *)0xFFFFB0E7)
#define EIC116                 (*(volatile unsigned short *)0xFFFFB0E8)
#define EIC116L                (*(volatile unsigned char  *)0xFFFFB0E8)
#define EIC116H                (*(volatile unsigned char  *)0xFFFFB0E9)
#define EIC117                 (*(volatile unsigned short *)0xFFFFB0EA)
#define EIC117L                (*(volatile unsigned char  *)0xFFFFB0EA)
#define EIC117H                (*(volatile unsigned char  *)0xFFFFB0EB)
#define EIC118                 (*(volatile unsigned short *)0xFFFFB0EC)
#define EIC118L                (*(volatile unsigned char  *)0xFFFFB0EC)
#define EIC118H                (*(volatile unsigned char  *)0xFFFFB0ED)
#define EIC119                 (*(volatile unsigned short *)0xFFFFB0EE)
#define EIC119L                (*(volatile unsigned char  *)0xFFFFB0EE)
#define EIC119H                (*(volatile unsigned char  *)0xFFFFB0EF)
#define EIC120                 (*(volatile unsigned short *)0xFFFFB0F0)
#define EIC120L                (*(volatile unsigned char  *)0xFFFFB0F0)
#define EIC120H                (*(volatile unsigned char  *)0xFFFFB0F1)
#define EIC121                 (*(volatile unsigned short *)0xFFFFB0F2)
#define EIC121L                (*(volatile unsigned char  *)0xFFFFB0F2)
#define EIC121H                (*(volatile unsigned char  *)0xFFFFB0F3)
#define EIC122                 (*(volatile unsigned short *)0xFFFFB0F4)
#define EIC122L                (*(volatile unsigned char  *)0xFFFFB0F4)
#define EIC122H                (*(volatile unsigned char  *)0xFFFFB0F5)
#define EIC123                 (*(volatile unsigned short *)0xFFFFB0F6)
#define EIC123L                (*(volatile unsigned char  *)0xFFFFB0F6)
#define EIC123H                (*(volatile unsigned char  *)0xFFFFB0F7)
#define EIC124                 (*(volatile unsigned short *)0xFFFFB0F8)
#define EIC124L                (*(volatile unsigned char  *)0xFFFFB0F8)
#define EIC124H                (*(volatile unsigned char  *)0xFFFFB0F9)
#define EIC125                 (*(volatile unsigned short *)0xFFFFB0FA)
#define EIC125L                (*(volatile unsigned char  *)0xFFFFB0FA)
#define EIC125H                (*(volatile unsigned char  *)0xFFFFB0FB)
#define EIC126                 (*(volatile unsigned short *)0xFFFFB0FC)
#define EIC126L                (*(volatile unsigned char  *)0xFFFFB0FC)
#define EIC126H                (*(volatile unsigned char  *)0xFFFFB0FD)
#define EIC127                 (*(volatile unsigned short *)0xFFFFB0FE)
#define EIC127L                (*(volatile unsigned char  *)0xFFFFB0FE)
#define EIC127H                (*(volatile unsigned char  *)0xFFFFB0FF)
#define EIC128                 (*(volatile unsigned short *)0xFFFFB100)
#define EIC128L                (*(volatile unsigned char  *)0xFFFFB100)
#define EIC128H                (*(volatile unsigned char  *)0xFFFFB101)
#define EIC129                 (*(volatile unsigned short *)0xFFFFB102)
#define EIC129L                (*(volatile unsigned char  *)0xFFFFB102)
#define EIC129H                (*(volatile unsigned char  *)0xFFFFB103)
#define EIC130                 (*(volatile unsigned short *)0xFFFFB104)
#define EIC130L                (*(volatile unsigned char  *)0xFFFFB104)
#define EIC130H                (*(volatile unsigned char  *)0xFFFFB105)
#define EIC131                 (*(volatile unsigned short *)0xFFFFB106)
#define EIC131L                (*(volatile unsigned char  *)0xFFFFB106)
#define EIC131H                (*(volatile unsigned char  *)0xFFFFB107)
#define EIC132                 (*(volatile unsigned short *)0xFFFFB108)
#define EIC132L                (*(volatile unsigned char  *)0xFFFFB108)
#define EIC132H                (*(volatile unsigned char  *)0xFFFFB109)
#define EIC133                 (*(volatile unsigned short *)0xFFFFB10A)
#define EIC133L                (*(volatile unsigned char  *)0xFFFFB10A)
#define EIC133H                (*(volatile unsigned char  *)0xFFFFB10B)
#define EIC134                 (*(volatile unsigned short *)0xFFFFB10C)
#define EIC134L                (*(volatile unsigned char  *)0xFFFFB10C)
#define EIC134H                (*(volatile unsigned char  *)0xFFFFB10D)
#define EIC135                 (*(volatile unsigned short *)0xFFFFB10E)
#define EIC135L                (*(volatile unsigned char  *)0xFFFFB10E)
#define EIC135H                (*(volatile unsigned char  *)0xFFFFB10F)
#define EIC136                 (*(volatile unsigned short *)0xFFFFB110)
#define EIC136L                (*(volatile unsigned char  *)0xFFFFB110)
#define EIC136H                (*(volatile unsigned char  *)0xFFFFB111)
#define EIC137                 (*(volatile unsigned short *)0xFFFFB112)
#define EIC137L                (*(volatile unsigned char  *)0xFFFFB112)
#define EIC137H                (*(volatile unsigned char  *)0xFFFFB113)
#define EIC138                 (*(volatile unsigned short *)0xFFFFB114)
#define EIC138L                (*(volatile unsigned char  *)0xFFFFB114)
#define EIC138H                (*(volatile unsigned char  *)0xFFFFB115)
#define EIC139                 (*(volatile unsigned short *)0xFFFFB116)
#define EIC139L                (*(volatile unsigned char  *)0xFFFFB116)
#define EIC139H                (*(volatile unsigned char  *)0xFFFFB117)
#define EIC140                 (*(volatile unsigned short *)0xFFFFB118)
#define EIC140L                (*(volatile unsigned char  *)0xFFFFB118)
#define EIC140H                (*(volatile unsigned char  *)0xFFFFB119)
#define EIC141                 (*(volatile unsigned short *)0xFFFFB11A)
#define EIC141L                (*(volatile unsigned char  *)0xFFFFB11A)
#define EIC141H                (*(volatile unsigned char  *)0xFFFFB11B)
#define EIC142                 (*(volatile unsigned short *)0xFFFFB11C)
#define EIC142L                (*(volatile unsigned char  *)0xFFFFB11C)
#define EIC142H                (*(volatile unsigned char  *)0xFFFFB11D)
#define EIC143                 (*(volatile unsigned short *)0xFFFFB11E)
#define EIC143L                (*(volatile unsigned char  *)0xFFFFB11E)
#define EIC143H                (*(volatile unsigned char  *)0xFFFFB11F)
#define EIC144                 (*(volatile unsigned short *)0xFFFFB120)
#define EIC144L                (*(volatile unsigned char  *)0xFFFFB120)
#define EIC144H                (*(volatile unsigned char  *)0xFFFFB121)
#define EIC145                 (*(volatile unsigned short *)0xFFFFB122)
#define EIC145L                (*(volatile unsigned char  *)0xFFFFB122)
#define EIC145H                (*(volatile unsigned char  *)0xFFFFB123)
#define EIC146                 (*(volatile unsigned short *)0xFFFFB124)
#define EIC146L                (*(volatile unsigned char  *)0xFFFFB124)
#define EIC146H                (*(volatile unsigned char  *)0xFFFFB125)
#define EIC147                 (*(volatile unsigned short *)0xFFFFB126)
#define EIC147L                (*(volatile unsigned char  *)0xFFFFB126)
#define EIC147H                (*(volatile unsigned char  *)0xFFFFB127)
#define EIC148                 (*(volatile unsigned short *)0xFFFFB128)
#define EIC148L                (*(volatile unsigned char  *)0xFFFFB128)
#define EIC148H                (*(volatile unsigned char  *)0xFFFFB129)
#define EIC149                 (*(volatile unsigned short *)0xFFFFB12A)
#define EIC149L                (*(volatile unsigned char  *)0xFFFFB12A)
#define EIC149H                (*(volatile unsigned char  *)0xFFFFB12B)
#define EIC150                 (*(volatile unsigned short *)0xFFFFB12C)
#define EIC150L                (*(volatile unsigned char  *)0xFFFFB12C)
#define EIC150H                (*(volatile unsigned char  *)0xFFFFB12D)
#define EIC151                 (*(volatile unsigned short *)0xFFFFB12E)
#define EIC151L                (*(volatile unsigned char  *)0xFFFFB12E)
#define EIC151H                (*(volatile unsigned char  *)0xFFFFB12F)
#define EIC152                 (*(volatile unsigned short *)0xFFFFB130)
#define EIC152L                (*(volatile unsigned char  *)0xFFFFB130)
#define EIC152H                (*(volatile unsigned char  *)0xFFFFB131)
#define EIC153                 (*(volatile unsigned short *)0xFFFFB132)
#define EIC153L                (*(volatile unsigned char  *)0xFFFFB132)
#define EIC153H                (*(volatile unsigned char  *)0xFFFFB133)
#define EIC154                 (*(volatile unsigned short *)0xFFFFB134)
#define EIC154L                (*(volatile unsigned char  *)0xFFFFB134)
#define EIC154H                (*(volatile unsigned char  *)0xFFFFB135)
#define EIC155                 (*(volatile unsigned short *)0xFFFFB136)
#define EIC155L                (*(volatile unsigned char  *)0xFFFFB136)
#define EIC155H                (*(volatile unsigned char  *)0xFFFFB137)
#define EIC156                 (*(volatile unsigned short *)0xFFFFB138)
#define EIC156L                (*(volatile unsigned char  *)0xFFFFB138)
#define EIC156H                (*(volatile unsigned char  *)0xFFFFB139)
#define EIC157                 (*(volatile unsigned short *)0xFFFFB13A)
#define EIC157L                (*(volatile unsigned char  *)0xFFFFB13A)
#define EIC157H                (*(volatile unsigned char  *)0xFFFFB13B)
#define EIC158                 (*(volatile unsigned short *)0xFFFFB13C)
#define EIC158L                (*(volatile unsigned char  *)0xFFFFB13C)
#define EIC158H                (*(volatile unsigned char  *)0xFFFFB13D)
#define EIC159                 (*(volatile unsigned short *)0xFFFFB13E)
#define EIC159L                (*(volatile unsigned char  *)0xFFFFB13E)
#define EIC159H                (*(volatile unsigned char  *)0xFFFFB13F)
#define EIC160                 (*(volatile unsigned short *)0xFFFFB140)
#define EIC160L                (*(volatile unsigned char  *)0xFFFFB140)
#define EIC160H                (*(volatile unsigned char  *)0xFFFFB141)
#define EIC161                 (*(volatile unsigned short *)0xFFFFB142)
#define EIC161L                (*(volatile unsigned char  *)0xFFFFB142)
#define EIC161H                (*(volatile unsigned char  *)0xFFFFB143)
#define EIC162                 (*(volatile unsigned short *)0xFFFFB144)
#define EIC162L                (*(volatile unsigned char  *)0xFFFFB144)
#define EIC162H                (*(volatile unsigned char  *)0xFFFFB145)
#define EIC163                 (*(volatile unsigned short *)0xFFFFB146)
#define EIC163L                (*(volatile unsigned char  *)0xFFFFB146)
#define EIC163H                (*(volatile unsigned char  *)0xFFFFB147)
#define EIC164                 (*(volatile unsigned short *)0xFFFFB148)
#define EIC164L                (*(volatile unsigned char  *)0xFFFFB148)
#define EIC164H                (*(volatile unsigned char  *)0xFFFFB149)
#define EIC165                 (*(volatile unsigned short *)0xFFFFB14A)
#define EIC165L                (*(volatile unsigned char  *)0xFFFFB14A)
#define EIC165H                (*(volatile unsigned char  *)0xFFFFB14B)
#define EIC166                 (*(volatile unsigned short *)0xFFFFB14C)
#define EIC166L                (*(volatile unsigned char  *)0xFFFFB14C)
#define EIC166H                (*(volatile unsigned char  *)0xFFFFB14D)
#define EIC167                 (*(volatile unsigned short *)0xFFFFB14E)
#define EIC167L                (*(volatile unsigned char  *)0xFFFFB14E)
#define EIC167H                (*(volatile unsigned char  *)0xFFFFB14F)
#define EIC168                 (*(volatile unsigned short *)0xFFFFB150)
#define EIC168L                (*(volatile unsigned char  *)0xFFFFB150)
#define EIC168H                (*(volatile unsigned char  *)0xFFFFB151)
#define EIC169                 (*(volatile unsigned short *)0xFFFFB152)
#define EIC169L                (*(volatile unsigned char  *)0xFFFFB152)
#define EIC169H                (*(volatile unsigned char  *)0xFFFFB153)
#define EIC170                 (*(volatile unsigned short *)0xFFFFB154)
#define EIC170L                (*(volatile unsigned char  *)0xFFFFB154)
#define EIC170H                (*(volatile unsigned char  *)0xFFFFB155)
#define EIC171                 (*(volatile unsigned short *)0xFFFFB156)
#define EIC171L                (*(volatile unsigned char  *)0xFFFFB156)
#define EIC171H                (*(volatile unsigned char  *)0xFFFFB157)
#define EIC172                 (*(volatile unsigned short *)0xFFFFB158)
#define EIC172L                (*(volatile unsigned char  *)0xFFFFB158)
#define EIC172H                (*(volatile unsigned char  *)0xFFFFB159)
#define EIC173                 (*(volatile unsigned short *)0xFFFFB15A)
#define EIC173L                (*(volatile unsigned char  *)0xFFFFB15A)
#define EIC173H                (*(volatile unsigned char  *)0xFFFFB15B)
#define EIC174                 (*(volatile unsigned short *)0xFFFFB15C)
#define EIC174L                (*(volatile unsigned char  *)0xFFFFB15C)
#define EIC174H                (*(volatile unsigned char  *)0xFFFFB15D)
#define EIC175                 (*(volatile unsigned short *)0xFFFFB15E)
#define EIC175L                (*(volatile unsigned char  *)0xFFFFB15E)
#define EIC175H                (*(volatile unsigned char  *)0xFFFFB15F)
#define EIC176                 (*(volatile unsigned short *)0xFFFFB160)
#define EIC176L                (*(volatile unsigned char  *)0xFFFFB160)
#define EIC176H                (*(volatile unsigned char  *)0xFFFFB161)
#define EIC177                 (*(volatile unsigned short *)0xFFFFB162)
#define EIC177L                (*(volatile unsigned char  *)0xFFFFB162)
#define EIC177H                (*(volatile unsigned char  *)0xFFFFB163)
#define EIC178                 (*(volatile unsigned short *)0xFFFFB164)
#define EIC178L                (*(volatile unsigned char  *)0xFFFFB164)
#define EIC178H                (*(volatile unsigned char  *)0xFFFFB165)
#define EIC179                 (*(volatile unsigned short *)0xFFFFB166)
#define EIC179L                (*(volatile unsigned char  *)0xFFFFB166)
#define EIC179H                (*(volatile unsigned char  *)0xFFFFB167)
#define EIC180                 (*(volatile unsigned short *)0xFFFFB168)
#define EIC180L                (*(volatile unsigned char  *)0xFFFFB168)
#define EIC180H                (*(volatile unsigned char  *)0xFFFFB169)
#define EIC181                 (*(volatile unsigned short *)0xFFFFB16A)
#define EIC181L                (*(volatile unsigned char  *)0xFFFFB16A)
#define EIC181H                (*(volatile unsigned char  *)0xFFFFB16B)
#define EIC182                 (*(volatile unsigned short *)0xFFFFB16C)
#define EIC182L                (*(volatile unsigned char  *)0xFFFFB16C)
#define EIC182H                (*(volatile unsigned char  *)0xFFFFB16D)
#define EIC183                 (*(volatile unsigned short *)0xFFFFB16E)
#define EIC183L                (*(volatile unsigned char  *)0xFFFFB16E)
#define EIC183H                (*(volatile unsigned char  *)0xFFFFB16F)
#define EIC184                 (*(volatile unsigned short *)0xFFFFB170)
#define EIC184L                (*(volatile unsigned char  *)0xFFFFB170)
#define EIC184H                (*(volatile unsigned char  *)0xFFFFB171)
#define EIC185                 (*(volatile unsigned short *)0xFFFFB172)
#define EIC185L                (*(volatile unsigned char  *)0xFFFFB172)
#define EIC185H                (*(volatile unsigned char  *)0xFFFFB173)
#define EIC186                 (*(volatile unsigned short *)0xFFFFB174)
#define EIC186L                (*(volatile unsigned char  *)0xFFFFB174)
#define EIC186H                (*(volatile unsigned char  *)0xFFFFB175)
#define EIC187                 (*(volatile unsigned short *)0xFFFFB176)
#define EIC187L                (*(volatile unsigned char  *)0xFFFFB176)
#define EIC187H                (*(volatile unsigned char  *)0xFFFFB177)
#define EIC188                 (*(volatile unsigned short *)0xFFFFB178)
#define EIC188L                (*(volatile unsigned char  *)0xFFFFB178)
#define EIC188H                (*(volatile unsigned char  *)0xFFFFB179)
#define EIC189                 (*(volatile unsigned short *)0xFFFFB17A)
#define EIC189L                (*(volatile unsigned char  *)0xFFFFB17A)
#define EIC189H                (*(volatile unsigned char  *)0xFFFFB17B)
#define EIC190                 (*(volatile unsigned short *)0xFFFFB17C)
#define EIC190L                (*(volatile unsigned char  *)0xFFFFB17C)
#define EIC190H                (*(volatile unsigned char  *)0xFFFFB17D)
#define EIC191                 (*(volatile unsigned short *)0xFFFFB17E)
#define EIC191L                (*(volatile unsigned char  *)0xFFFFB17E)
#define EIC191H                (*(volatile unsigned char  *)0xFFFFB17F)
#define EIC192                 (*(volatile unsigned short *)0xFFFFB180)
#define EIC192L                (*(volatile unsigned char  *)0xFFFFB180)
#define EIC192H                (*(volatile unsigned char  *)0xFFFFB181)
#define EIC193                 (*(volatile unsigned short *)0xFFFFB182)
#define EIC193L                (*(volatile unsigned char  *)0xFFFFB182)
#define EIC193H                (*(volatile unsigned char  *)0xFFFFB183)
#define EIC194                 (*(volatile unsigned short *)0xFFFFB184)
#define EIC194L                (*(volatile unsigned char  *)0xFFFFB184)
#define EIC194H                (*(volatile unsigned char  *)0xFFFFB185)
#define EIC195                 (*(volatile unsigned short *)0xFFFFB186)
#define EIC195L                (*(volatile unsigned char  *)0xFFFFB186)
#define EIC195H                (*(volatile unsigned char  *)0xFFFFB187)
#define EIC196                 (*(volatile unsigned short *)0xFFFFB188)
#define EIC196L                (*(volatile unsigned char  *)0xFFFFB188)
#define EIC196H                (*(volatile unsigned char  *)0xFFFFB189)
#define EIC197                 (*(volatile unsigned short *)0xFFFFB18A)
#define EIC197L                (*(volatile unsigned char  *)0xFFFFB18A)
#define EIC197H                (*(volatile unsigned char  *)0xFFFFB18B)
#define EIC198                 (*(volatile unsigned short *)0xFFFFB18C)
#define EIC198L                (*(volatile unsigned char  *)0xFFFFB18C)
#define EIC198H                (*(volatile unsigned char  *)0xFFFFB18D)
#define EIC199                 (*(volatile unsigned short *)0xFFFFB18E)
#define EIC199L                (*(volatile unsigned char  *)0xFFFFB18E)
#define EIC199H                (*(volatile unsigned char  *)0xFFFFB18F)
#define EIC200                 (*(volatile unsigned short *)0xFFFFB190)
#define EIC200L                (*(volatile unsigned char  *)0xFFFFB190)
#define EIC200H                (*(volatile unsigned char  *)0xFFFFB191)
#define EIC201                 (*(volatile unsigned short *)0xFFFFB192)
#define EIC201L                (*(volatile unsigned char  *)0xFFFFB192)
#define EIC201H                (*(volatile unsigned char  *)0xFFFFB193)
#define EIC202                 (*(volatile unsigned short *)0xFFFFB194)
#define EIC202L                (*(volatile unsigned char  *)0xFFFFB194)
#define EIC202H                (*(volatile unsigned char  *)0xFFFFB195)
#define EIC203                 (*(volatile unsigned short *)0xFFFFB196)
#define EIC203L                (*(volatile unsigned char  *)0xFFFFB196)
#define EIC203H                (*(volatile unsigned char  *)0xFFFFB197)
#define EIC204                 (*(volatile unsigned short *)0xFFFFB198)
#define EIC204L                (*(volatile unsigned char  *)0xFFFFB198)
#define EIC204H                (*(volatile unsigned char  *)0xFFFFB199)
#define EIC205                 (*(volatile unsigned short *)0xFFFFB19A)
#define EIC205L                (*(volatile unsigned char  *)0xFFFFB19A)
#define EIC205H                (*(volatile unsigned char  *)0xFFFFB19B)
#define EIC206                 (*(volatile unsigned short *)0xFFFFB19C)
#define EIC206L                (*(volatile unsigned char  *)0xFFFFB19C)
#define EIC206H                (*(volatile unsigned char  *)0xFFFFB19D)
#define EIC207                 (*(volatile unsigned short *)0xFFFFB19E)
#define EIC207L                (*(volatile unsigned char  *)0xFFFFB19E)
#define EIC207H                (*(volatile unsigned char  *)0xFFFFB19F)
#define EIC208                 (*(volatile unsigned short *)0xFFFFB1A0)
#define EIC208L                (*(volatile unsigned char  *)0xFFFFB1A0)
#define EIC208H                (*(volatile unsigned char  *)0xFFFFB1A1)
#define EIC209                 (*(volatile unsigned short *)0xFFFFB1A2)
#define EIC209L                (*(volatile unsigned char  *)0xFFFFB1A2)
#define EIC209H                (*(volatile unsigned char  *)0xFFFFB1A3)
#define EIC210                 (*(volatile unsigned short *)0xFFFFB1A4)
#define EIC210L                (*(volatile unsigned char  *)0xFFFFB1A4)
#define EIC210H                (*(volatile unsigned char  *)0xFFFFB1A5)
#define EIC211                 (*(volatile unsigned short *)0xFFFFB1A6)
#define EIC211L                (*(volatile unsigned char  *)0xFFFFB1A6)
#define EIC211H                (*(volatile unsigned char  *)0xFFFFB1A7)
#define EIC212                 (*(volatile unsigned short *)0xFFFFB1A8)
#define EIC212L                (*(volatile unsigned char  *)0xFFFFB1A8)
#define EIC212H                (*(volatile unsigned char  *)0xFFFFB1A9)
#define EIC213                 (*(volatile unsigned short *)0xFFFFB1AA)
#define EIC213L                (*(volatile unsigned char  *)0xFFFFB1AA)
#define EIC213H                (*(volatile unsigned char  *)0xFFFFB1AB)
#define EIC214                 (*(volatile unsigned short *)0xFFFFB1AC)
#define EIC214L                (*(volatile unsigned char  *)0xFFFFB1AC)
#define EIC214H                (*(volatile unsigned char  *)0xFFFFB1AD)
#define EIC215                 (*(volatile unsigned short *)0xFFFFB1AE)
#define EIC215L                (*(volatile unsigned char  *)0xFFFFB1AE)
#define EIC215H                (*(volatile unsigned char  *)0xFFFFB1AF)
#define EIC216                 (*(volatile unsigned short *)0xFFFFB1B0)
#define EIC216L                (*(volatile unsigned char  *)0xFFFFB1B0)
#define EIC216H                (*(volatile unsigned char  *)0xFFFFB1B1)
#define EIC217                 (*(volatile unsigned short *)0xFFFFB1B2)
#define EIC217L                (*(volatile unsigned char  *)0xFFFFB1B2)
#define EIC217H                (*(volatile unsigned char  *)0xFFFFB1B3)
#define EIC218                 (*(volatile unsigned short *)0xFFFFB1B4)
#define EIC218L                (*(volatile unsigned char  *)0xFFFFB1B4)
#define EIC218H                (*(volatile unsigned char  *)0xFFFFB1B5)
#define EIC219                 (*(volatile unsigned short *)0xFFFFB1B6)
#define EIC219L                (*(volatile unsigned char  *)0xFFFFB1B6)
#define EIC219H                (*(volatile unsigned char  *)0xFFFFB1B7)
#define EIC220                 (*(volatile unsigned short *)0xFFFFB1B8)
#define EIC220L                (*(volatile unsigned char  *)0xFFFFB1B8)
#define EIC220H                (*(volatile unsigned char  *)0xFFFFB1B9)
#define EIC221                 (*(volatile unsigned short *)0xFFFFB1BA)
#define EIC221L                (*(volatile unsigned char  *)0xFFFFB1BA)
#define EIC221H                (*(volatile unsigned char  *)0xFFFFB1BB)
#define EIC222                 (*(volatile unsigned short *)0xFFFFB1BC)
#define EIC222L                (*(volatile unsigned char  *)0xFFFFB1BC)
#define EIC222H                (*(volatile unsigned char  *)0xFFFFB1BD)
#define EIC223                 (*(volatile unsigned short *)0xFFFFB1BE)
#define EIC223L                (*(volatile unsigned char  *)0xFFFFB1BE)
#define EIC223H                (*(volatile unsigned char  *)0xFFFFB1BF)
#define EIC224                 (*(volatile unsigned short *)0xFFFFB1C0)
#define EIC224L                (*(volatile unsigned char  *)0xFFFFB1C0)
#define EIC224H                (*(volatile unsigned char  *)0xFFFFB1C1)
#define EIC225                 (*(volatile unsigned short *)0xFFFFB1C2)
#define EIC225L                (*(volatile unsigned char  *)0xFFFFB1C2)
#define EIC225H                (*(volatile unsigned char  *)0xFFFFB1C3)
#define EIC226                 (*(volatile unsigned short *)0xFFFFB1C4)
#define EIC226L                (*(volatile unsigned char  *)0xFFFFB1C4)
#define EIC226H                (*(volatile unsigned char  *)0xFFFFB1C5)
#define EIC227                 (*(volatile unsigned short *)0xFFFFB1C6)
#define EIC227L                (*(volatile unsigned char  *)0xFFFFB1C6)
#define EIC227H                (*(volatile unsigned char  *)0xFFFFB1C7)
#define EIC228                 (*(volatile unsigned short *)0xFFFFB1C8)
#define EIC228L                (*(volatile unsigned char  *)0xFFFFB1C8)
#define EIC228H                (*(volatile unsigned char  *)0xFFFFB1C9)
#define EIC229                 (*(volatile unsigned short *)0xFFFFB1CA)
#define EIC229L                (*(volatile unsigned char  *)0xFFFFB1CA)
#define EIC229H                (*(volatile unsigned char  *)0xFFFFB1CB)
#define EIC230                 (*(volatile unsigned short *)0xFFFFB1CC)
#define EIC230L                (*(volatile unsigned char  *)0xFFFFB1CC)
#define EIC230H                (*(volatile unsigned char  *)0xFFFFB1CD)
#define EIC231                 (*(volatile unsigned short *)0xFFFFB1CE)
#define EIC231L                (*(volatile unsigned char  *)0xFFFFB1CE)
#define EIC231H                (*(volatile unsigned char  *)0xFFFFB1CF)
#define EIC232                 (*(volatile unsigned short *)0xFFFFB1D0)
#define EIC232L                (*(volatile unsigned char  *)0xFFFFB1D0)
#define EIC232H                (*(volatile unsigned char  *)0xFFFFB1D1)
#define EIC233                 (*(volatile unsigned short *)0xFFFFB1D2)
#define EIC233L                (*(volatile unsigned char  *)0xFFFFB1D2)
#define EIC233H                (*(volatile unsigned char  *)0xFFFFB1D3)
#define EIC234                 (*(volatile unsigned short *)0xFFFFB1D4)
#define EIC234L                (*(volatile unsigned char  *)0xFFFFB1D4)
#define EIC234H                (*(volatile unsigned char  *)0xFFFFB1D5)
#define EIC235                 (*(volatile unsigned short *)0xFFFFB1D6)
#define EIC235L                (*(volatile unsigned char  *)0xFFFFB1D6)
#define EIC235H                (*(volatile unsigned char  *)0xFFFFB1D7)
#define EIC236                 (*(volatile unsigned short *)0xFFFFB1D8)
#define EIC236L                (*(volatile unsigned char  *)0xFFFFB1D8)
#define EIC236H                (*(volatile unsigned char  *)0xFFFFB1D9)
#define EIC237                 (*(volatile unsigned short *)0xFFFFB1DA)
#define EIC237L                (*(volatile unsigned char  *)0xFFFFB1DA)
#define EIC237H                (*(volatile unsigned char  *)0xFFFFB1DB)
#define EIC238                 (*(volatile unsigned short *)0xFFFFB1DC)
#define EIC238L                (*(volatile unsigned char  *)0xFFFFB1DC)
#define EIC238H                (*(volatile unsigned char  *)0xFFFFB1DD)
#define EIC239                 (*(volatile unsigned short *)0xFFFFB1DE)
#define EIC239L                (*(volatile unsigned char  *)0xFFFFB1DE)
#define EIC239H                (*(volatile unsigned char  *)0xFFFFB1DF)
#define EIC240                 (*(volatile unsigned short *)0xFFFFB1E0)
#define EIC240L                (*(volatile unsigned char  *)0xFFFFB1E0)
#define EIC240H                (*(volatile unsigned char  *)0xFFFFB1E1)
#define EIC241                 (*(volatile unsigned short *)0xFFFFB1E2)
#define EIC241L                (*(volatile unsigned char  *)0xFFFFB1E2)
#define EIC241H                (*(volatile unsigned char  *)0xFFFFB1E3)
#define EIC242                 (*(volatile unsigned short *)0xFFFFB1E4)
#define EIC242L                (*(volatile unsigned char  *)0xFFFFB1E4)
#define EIC242H                (*(volatile unsigned char  *)0xFFFFB1E5)
#define EIC243                 (*(volatile unsigned short *)0xFFFFB1E6)
#define EIC243L                (*(volatile unsigned char  *)0xFFFFB1E6)
#define EIC243H                (*(volatile unsigned char  *)0xFFFFB1E7)
#define EIC244                 (*(volatile unsigned short *)0xFFFFB1E8)
#define EIC244L                (*(volatile unsigned char  *)0xFFFFB1E8)
#define EIC244H                (*(volatile unsigned char  *)0xFFFFB1E9)
#define EIC245                 (*(volatile unsigned short *)0xFFFFB1EA)
#define EIC245L                (*(volatile unsigned char  *)0xFFFFB1EA)
#define EIC245H                (*(volatile unsigned char  *)0xFFFFB1EB)
#define IMR1                   (*(volatile unsigned long  *)0xFFFFB404)
#define IMR1L                  (*(volatile unsigned short *)0xFFFFB404)
#define IMR1LL                 (*(volatile unsigned char  *)0xFFFFB404)
#define IMR1LH                 (*(volatile unsigned char  *)0xFFFFB405)
#define IMR1H                  (*(volatile unsigned short *)0xFFFFB406)
#define IMR1HL                 (*(volatile unsigned char  *)0xFFFFB406)
#define IMR1HH                 (*(volatile unsigned char  *)0xFFFFB407)
#define IMR1EIMK32             (((volatile __bitf_T *)0xFFFFB404)->bit00)
#define IMR1EIMK33             (((volatile __bitf_T *)0xFFFFB404)->bit01)
#define IMR1EIMK34             (((volatile __bitf_T *)0xFFFFB404)->bit02)
#define IMR1EIMK35             (((volatile __bitf_T *)0xFFFFB404)->bit03)
#define IMR1EIMK36             (((volatile __bitf_T *)0xFFFFB404)->bit04)
#define IMR1EIMK37             (((volatile __bitf_T *)0xFFFFB404)->bit05)
#define IMR1EIMK38             (((volatile __bitf_T *)0xFFFFB404)->bit06)
#define IMR1EIMK39             (((volatile __bitf_T *)0xFFFFB404)->bit07)
#define IMR1EIMK40             (((volatile __bitf_T *)0xFFFFB405)->bit00)
#define IMR1EIMK41             (((volatile __bitf_T *)0xFFFFB405)->bit01)
#define IMR1EIMK42             (((volatile __bitf_T *)0xFFFFB405)->bit02)
#define IMR1EIMK43             (((volatile __bitf_T *)0xFFFFB405)->bit03)
#define IMR1EIMK44             (((volatile __bitf_T *)0xFFFFB405)->bit04)
#define IMR1EIMK45             (((volatile __bitf_T *)0xFFFFB405)->bit05)
#define IMR1EIMK46             (((volatile __bitf_T *)0xFFFFB405)->bit06)
#define IMR1EIMK47             (((volatile __bitf_T *)0xFFFFB405)->bit07)
#define IMR1EIMK48             (((volatile __bitf_T *)0xFFFFB406)->bit00)
#define IMR1EIMK49             (((volatile __bitf_T *)0xFFFFB406)->bit01)
#define IMR1EIMK50             (((volatile __bitf_T *)0xFFFFB406)->bit02)
#define IMR1EIMK51             (((volatile __bitf_T *)0xFFFFB406)->bit03)
#define IMR1EIMK52             (((volatile __bitf_T *)0xFFFFB406)->bit04)
#define IMR1EIMK53             (((volatile __bitf_T *)0xFFFFB406)->bit05)
#define IMR1EIMK54             (((volatile __bitf_T *)0xFFFFB406)->bit06)
#define IMR1EIMK55             (((volatile __bitf_T *)0xFFFFB406)->bit07)
#define IMR1EIMK56             (((volatile __bitf_T *)0xFFFFB407)->bit00)
#define IMR1EIMK57             (((volatile __bitf_T *)0xFFFFB407)->bit01)
#define IMR1EIMK58             (((volatile __bitf_T *)0xFFFFB407)->bit02)
#define IMR1EIMK59             (((volatile __bitf_T *)0xFFFFB407)->bit03)
#define IMR1EIMK60             (((volatile __bitf_T *)0xFFFFB407)->bit04)
#define IMR1EIMK61             (((volatile __bitf_T *)0xFFFFB407)->bit05)
#define IMR1EIMK62             (((volatile __bitf_T *)0xFFFFB407)->bit06)
#define IMR1EIMK63             (((volatile __bitf_T *)0xFFFFB407)->bit07)
#define IMR2                   (*(volatile unsigned long  *)0xFFFFB408)
#define IMR2L                  (*(volatile unsigned short *)0xFFFFB408)
#define IMR2LL                 (*(volatile unsigned char  *)0xFFFFB408)
#define IMR2LH                 (*(volatile unsigned char  *)0xFFFFB409)
#define IMR2H                  (*(volatile unsigned short *)0xFFFFB40A)
#define IMR2HL                 (*(volatile unsigned char  *)0xFFFFB40A)
#define IMR2HH                 (*(volatile unsigned char  *)0xFFFFB40B)
#define IMR2EIMK64             (((volatile __bitf_T *)0xFFFFB408)->bit00)
#define IMR2EIMK65             (((volatile __bitf_T *)0xFFFFB408)->bit01)
#define IMR2EIMK66             (((volatile __bitf_T *)0xFFFFB408)->bit02)
#define IMR2EIMK67             (((volatile __bitf_T *)0xFFFFB408)->bit03)
#define IMR2EIMK68             (((volatile __bitf_T *)0xFFFFB408)->bit04)
#define IMR2EIMK69             (((volatile __bitf_T *)0xFFFFB408)->bit05)
#define IMR2EIMK70             (((volatile __bitf_T *)0xFFFFB408)->bit06)
#define IMR2EIMK71             (((volatile __bitf_T *)0xFFFFB408)->bit07)
#define IMR2EIMK72             (((volatile __bitf_T *)0xFFFFB409)->bit00)
#define IMR2EIMK73             (((volatile __bitf_T *)0xFFFFB409)->bit01)
#define IMR2EIMK74             (((volatile __bitf_T *)0xFFFFB409)->bit02)
#define IMR2EIMK75             (((volatile __bitf_T *)0xFFFFB409)->bit03)
#define IMR2EIMK76             (((volatile __bitf_T *)0xFFFFB409)->bit04)
#define IMR2EIMK77             (((volatile __bitf_T *)0xFFFFB409)->bit05)
#define IMR2EIMK78             (((volatile __bitf_T *)0xFFFFB409)->bit06)
#define IMR2EIMK79             (((volatile __bitf_T *)0xFFFFB409)->bit07)
#define IMR2EIMK80             (((volatile __bitf_T *)0xFFFFB40A)->bit00)
#define IMR2EIMK81             (((volatile __bitf_T *)0xFFFFB40A)->bit01)
#define IMR2EIMK82             (((volatile __bitf_T *)0xFFFFB40A)->bit02)
#define IMR2EIMK83             (((volatile __bitf_T *)0xFFFFB40A)->bit03)
#define IMR2EIMK84             (((volatile __bitf_T *)0xFFFFB40A)->bit04)
#define IMR2EIMK85             (((volatile __bitf_T *)0xFFFFB40A)->bit05)
#define IMR2EIMK86             (((volatile __bitf_T *)0xFFFFB40A)->bit06)
#define IMR2EIMK87             (((volatile __bitf_T *)0xFFFFB40A)->bit07)
#define IMR2EIMK88             (((volatile __bitf_T *)0xFFFFB40B)->bit00)
#define IMR2EIMK89             (((volatile __bitf_T *)0xFFFFB40B)->bit01)
#define IMR2EIMK90             (((volatile __bitf_T *)0xFFFFB40B)->bit02)
#define IMR2EIMK91             (((volatile __bitf_T *)0xFFFFB40B)->bit03)
#define IMR2EIMK92             (((volatile __bitf_T *)0xFFFFB40B)->bit04)
#define IMR2EIMK93             (((volatile __bitf_T *)0xFFFFB40B)->bit05)
#define IMR2EIMK94             (((volatile __bitf_T *)0xFFFFB40B)->bit06)
#define IMR2EIMK95             (((volatile __bitf_T *)0xFFFFB40B)->bit07)
#define IMR3                   (*(volatile unsigned long  *)0xFFFFB40C)
#define IMR3L                  (*(volatile unsigned short *)0xFFFFB40C)
#define IMR3LL                 (*(volatile unsigned char  *)0xFFFFB40C)
#define IMR3LH                 (*(volatile unsigned char  *)0xFFFFB40D)
#define IMR3H                  (*(volatile unsigned short *)0xFFFFB40E)
#define IMR3HL                 (*(volatile unsigned char  *)0xFFFFB40E)
#define IMR3HH                 (*(volatile unsigned char  *)0xFFFFB40F)
#define IMR3EIMK96             (((volatile __bitf_T *)0xFFFFB40C)->bit00)
#define IMR3EIMK97             (((volatile __bitf_T *)0xFFFFB40C)->bit01)
#define IMR3EIMK98             (((volatile __bitf_T *)0xFFFFB40C)->bit02)
#define IMR3EIMK99             (((volatile __bitf_T *)0xFFFFB40C)->bit03)
#define IMR3EIMK100            (((volatile __bitf_T *)0xFFFFB40C)->bit04)
#define IMR3EIMK101            (((volatile __bitf_T *)0xFFFFB40C)->bit05)
#define IMR3EIMK102            (((volatile __bitf_T *)0xFFFFB40C)->bit06)
#define IMR3EIMK103            (((volatile __bitf_T *)0xFFFFB40C)->bit07)
#define IMR3EIMK104            (((volatile __bitf_T *)0xFFFFB40D)->bit00)
#define IMR3EIMK105            (((volatile __bitf_T *)0xFFFFB40D)->bit01)
#define IMR3EIMK106            (((volatile __bitf_T *)0xFFFFB40D)->bit02)
#define IMR3EIMK107            (((volatile __bitf_T *)0xFFFFB40D)->bit03)
#define IMR3EIMK108            (((volatile __bitf_T *)0xFFFFB40D)->bit04)
#define IMR3EIMK109            (((volatile __bitf_T *)0xFFFFB40D)->bit05)
#define IMR3EIMK110            (((volatile __bitf_T *)0xFFFFB40D)->bit06)
#define IMR3EIMK111            (((volatile __bitf_T *)0xFFFFB40D)->bit07)
#define IMR3EIMK112            (((volatile __bitf_T *)0xFFFFB40E)->bit00)
#define IMR3EIMK113            (((volatile __bitf_T *)0xFFFFB40E)->bit01)
#define IMR3EIMK114            (((volatile __bitf_T *)0xFFFFB40E)->bit02)
#define IMR3EIMK115            (((volatile __bitf_T *)0xFFFFB40E)->bit03)
#define IMR3EIMK116            (((volatile __bitf_T *)0xFFFFB40E)->bit04)
#define IMR3EIMK117            (((volatile __bitf_T *)0xFFFFB40E)->bit05)
#define IMR3EIMK118            (((volatile __bitf_T *)0xFFFFB40E)->bit06)
#define IMR3EIMK119            (((volatile __bitf_T *)0xFFFFB40E)->bit07)
#define IMR3EIMK120            (((volatile __bitf_T *)0xFFFFB40F)->bit00)
#define IMR3EIMK121            (((volatile __bitf_T *)0xFFFFB40F)->bit01)
#define IMR3EIMK122            (((volatile __bitf_T *)0xFFFFB40F)->bit02)
#define IMR3EIMK123            (((volatile __bitf_T *)0xFFFFB40F)->bit03)
#define IMR3EIMK124            (((volatile __bitf_T *)0xFFFFB40F)->bit04)
#define IMR3EIMK125            (((volatile __bitf_T *)0xFFFFB40F)->bit05)
#define IMR3EIMK126            (((volatile __bitf_T *)0xFFFFB40F)->bit06)
#define IMR3EIMK127            (((volatile __bitf_T *)0xFFFFB40F)->bit07)
#define IMR4                   (*(volatile unsigned long  *)0xFFFFB410)
#define IMR4L                  (*(volatile unsigned short *)0xFFFFB410)
#define IMR4LL                 (*(volatile unsigned char  *)0xFFFFB410)
#define IMR4LH                 (*(volatile unsigned char  *)0xFFFFB411)
#define IMR4H                  (*(volatile unsigned short *)0xFFFFB412)
#define IMR4HL                 (*(volatile unsigned char  *)0xFFFFB412)
#define IMR4HH                 (*(volatile unsigned char  *)0xFFFFB413)
#define IMR4EIMK128            (((volatile __bitf_T *)0xFFFFB410)->bit00)
#define IMR4EIMK129            (((volatile __bitf_T *)0xFFFFB410)->bit01)
#define IMR4EIMK130            (((volatile __bitf_T *)0xFFFFB410)->bit02)
#define IMR4EIMK131            (((volatile __bitf_T *)0xFFFFB410)->bit03)
#define IMR4EIMK132            (((volatile __bitf_T *)0xFFFFB410)->bit04)
#define IMR4EIMK133            (((volatile __bitf_T *)0xFFFFB410)->bit05)
#define IMR4EIMK134            (((volatile __bitf_T *)0xFFFFB410)->bit06)
#define IMR4EIMK135            (((volatile __bitf_T *)0xFFFFB410)->bit07)
#define IMR4EIMK136            (((volatile __bitf_T *)0xFFFFB411)->bit00)
#define IMR4EIMK137            (((volatile __bitf_T *)0xFFFFB411)->bit01)
#define IMR4EIMK138            (((volatile __bitf_T *)0xFFFFB411)->bit02)
#define IMR4EIMK139            (((volatile __bitf_T *)0xFFFFB411)->bit03)
#define IMR4EIMK140            (((volatile __bitf_T *)0xFFFFB411)->bit04)
#define IMR4EIMK141            (((volatile __bitf_T *)0xFFFFB411)->bit05)
#define IMR4EIMK142            (((volatile __bitf_T *)0xFFFFB411)->bit06)
#define IMR4EIMK143            (((volatile __bitf_T *)0xFFFFB411)->bit07)
#define IMR4EIMK144            (((volatile __bitf_T *)0xFFFFB412)->bit00)
#define IMR4EIMK145            (((volatile __bitf_T *)0xFFFFB412)->bit01)
#define IMR4EIMK146            (((volatile __bitf_T *)0xFFFFB412)->bit02)
#define IMR4EIMK147            (((volatile __bitf_T *)0xFFFFB412)->bit03)
#define IMR4EIMK148            (((volatile __bitf_T *)0xFFFFB412)->bit04)
#define IMR4EIMK149            (((volatile __bitf_T *)0xFFFFB412)->bit05)
#define IMR4EIMK150            (((volatile __bitf_T *)0xFFFFB412)->bit06)
#define IMR4EIMK151            (((volatile __bitf_T *)0xFFFFB412)->bit07)
#define IMR4EIMK152            (((volatile __bitf_T *)0xFFFFB413)->bit00)
#define IMR4EIMK153            (((volatile __bitf_T *)0xFFFFB413)->bit01)
#define IMR4EIMK154            (((volatile __bitf_T *)0xFFFFB413)->bit02)
#define IMR4EIMK155            (((volatile __bitf_T *)0xFFFFB413)->bit03)
#define IMR4EIMK156            (((volatile __bitf_T *)0xFFFFB413)->bit04)
#define IMR4EIMK157            (((volatile __bitf_T *)0xFFFFB413)->bit05)
#define IMR4EIMK158            (((volatile __bitf_T *)0xFFFFB413)->bit06)
#define IMR4EIMK159            (((volatile __bitf_T *)0xFFFFB413)->bit07)
#define IMR5                   (*(volatile unsigned long  *)0xFFFFB414)
#define IMR5L                  (*(volatile unsigned short *)0xFFFFB414)
#define IMR5LL                 (*(volatile unsigned char  *)0xFFFFB414)
#define IMR5LH                 (*(volatile unsigned char  *)0xFFFFB415)
#define IMR5H                  (*(volatile unsigned short *)0xFFFFB416)
#define IMR5HL                 (*(volatile unsigned char  *)0xFFFFB416)
#define IMR5HH                 (*(volatile unsigned char  *)0xFFFFB417)
#define IMR5EIMK160            (((volatile __bitf_T *)0xFFFFB414)->bit00)
#define IMR5EIMK161            (((volatile __bitf_T *)0xFFFFB414)->bit01)
#define IMR5EIMK162            (((volatile __bitf_T *)0xFFFFB414)->bit02)
#define IMR5EIMK163            (((volatile __bitf_T *)0xFFFFB414)->bit03)
#define IMR5EIMK164            (((volatile __bitf_T *)0xFFFFB414)->bit04)
#define IMR5EIMK165            (((volatile __bitf_T *)0xFFFFB414)->bit05)
#define IMR5EIMK166            (((volatile __bitf_T *)0xFFFFB414)->bit06)
#define IMR5EIMK167            (((volatile __bitf_T *)0xFFFFB414)->bit07)
#define IMR5EIMK168            (((volatile __bitf_T *)0xFFFFB415)->bit00)
#define IMR5EIMK169            (((volatile __bitf_T *)0xFFFFB415)->bit01)
#define IMR5EIMK170            (((volatile __bitf_T *)0xFFFFB415)->bit02)
#define IMR5EIMK171            (((volatile __bitf_T *)0xFFFFB415)->bit03)
#define IMR5EIMK172            (((volatile __bitf_T *)0xFFFFB415)->bit04)
#define IMR5EIMK173            (((volatile __bitf_T *)0xFFFFB415)->bit05)
#define IMR5EIMK174            (((volatile __bitf_T *)0xFFFFB415)->bit06)
#define IMR5EIMK175            (((volatile __bitf_T *)0xFFFFB415)->bit07)
#define IMR5EIMK176            (((volatile __bitf_T *)0xFFFFB416)->bit00)
#define IMR5EIMK177            (((volatile __bitf_T *)0xFFFFB416)->bit01)
#define IMR5EIMK178            (((volatile __bitf_T *)0xFFFFB416)->bit02)
#define IMR5EIMK179            (((volatile __bitf_T *)0xFFFFB416)->bit03)
#define IMR5EIMK180            (((volatile __bitf_T *)0xFFFFB416)->bit04)
#define IMR5EIMK181            (((volatile __bitf_T *)0xFFFFB416)->bit05)
#define IMR5EIMK182            (((volatile __bitf_T *)0xFFFFB416)->bit06)
#define IMR5EIMK183            (((volatile __bitf_T *)0xFFFFB416)->bit07)
#define IMR5EIMK184            (((volatile __bitf_T *)0xFFFFB417)->bit00)
#define IMR5EIMK185            (((volatile __bitf_T *)0xFFFFB417)->bit01)
#define IMR5EIMK186            (((volatile __bitf_T *)0xFFFFB417)->bit02)
#define IMR5EIMK187            (((volatile __bitf_T *)0xFFFFB417)->bit03)
#define IMR5EIMK188            (((volatile __bitf_T *)0xFFFFB417)->bit04)
#define IMR5EIMK189            (((volatile __bitf_T *)0xFFFFB417)->bit05)
#define IMR5EIMK190            (((volatile __bitf_T *)0xFFFFB417)->bit06)
#define IMR5EIMK191            (((volatile __bitf_T *)0xFFFFB417)->bit07)
#define IMR6                   (*(volatile unsigned long  *)0xFFFFB418)
#define IMR6L                  (*(volatile unsigned short *)0xFFFFB418)
#define IMR6LL                 (*(volatile unsigned char  *)0xFFFFB418)
#define IMR6LH                 (*(volatile unsigned char  *)0xFFFFB419)
#define IMR6H                  (*(volatile unsigned short *)0xFFFFB41A)
#define IMR6HL                 (*(volatile unsigned char  *)0xFFFFB41A)
#define IMR6HH                 (*(volatile unsigned char  *)0xFFFFB41B)
#define IMR6EIMK192            (((volatile __bitf_T *)0xFFFFB418)->bit00)
#define IMR6EIMK193            (((volatile __bitf_T *)0xFFFFB418)->bit01)
#define IMR6EIMK194            (((volatile __bitf_T *)0xFFFFB418)->bit02)
#define IMR6EIMK195            (((volatile __bitf_T *)0xFFFFB418)->bit03)
#define IMR6EIMK196            (((volatile __bitf_T *)0xFFFFB418)->bit04)
#define IMR6EIMK197            (((volatile __bitf_T *)0xFFFFB418)->bit05)
#define IMR6EIMK198            (((volatile __bitf_T *)0xFFFFB418)->bit06)
#define IMR6EIMK199            (((volatile __bitf_T *)0xFFFFB418)->bit07)
#define IMR6IMK200             (((volatile __bitf_T *)0xFFFFB419)->bit00)
#define IMR6IMK201             (((volatile __bitf_T *)0xFFFFB419)->bit01)
#define IMR6IMK202             (((volatile __bitf_T *)0xFFFFB419)->bit02)
#define IMR6IMK203             (((volatile __bitf_T *)0xFFFFB419)->bit03)
#define IMR6IMK204             (((volatile __bitf_T *)0xFFFFB419)->bit04)
#define IMR6IMK205             (((volatile __bitf_T *)0xFFFFB419)->bit05)
#define IMR6IMK206             (((volatile __bitf_T *)0xFFFFB419)->bit06)
#define IMR6IMK207             (((volatile __bitf_T *)0xFFFFB419)->bit07)
#define IMR6EIMK208            (((volatile __bitf_T *)0xFFFFB41A)->bit00)
#define IMR6EIMK209            (((volatile __bitf_T *)0xFFFFB41A)->bit01)
#define IMR6EIMK210            (((volatile __bitf_T *)0xFFFFB41A)->bit02)
#define IMR6EIMK211            (((volatile __bitf_T *)0xFFFFB41A)->bit03)
#define IMR6EIMK212            (((volatile __bitf_T *)0xFFFFB41A)->bit04)
#define IMR6EIMK213            (((volatile __bitf_T *)0xFFFFB41A)->bit05)
#define IMR6EIMK214            (((volatile __bitf_T *)0xFFFFB41A)->bit06)
#define IMR6EIMK215            (((volatile __bitf_T *)0xFFFFB41A)->bit07)
#define IMR6EIMK216            (((volatile __bitf_T *)0xFFFFB41B)->bit00)
#define IMR6EIMK217            (((volatile __bitf_T *)0xFFFFB41B)->bit01)
#define IMR6EIMK218            (((volatile __bitf_T *)0xFFFFB41B)->bit02)
#define IMR6EIMK219            (((volatile __bitf_T *)0xFFFFB41B)->bit03)
#define IMR6EIMK220            (((volatile __bitf_T *)0xFFFFB41B)->bit04)
#define IMR6EIMK221            (((volatile __bitf_T *)0xFFFFB41B)->bit05)
#define IMR6EIMK222            (((volatile __bitf_T *)0xFFFFB41B)->bit06)
#define IMR6EIMK223            (((volatile __bitf_T *)0xFFFFB41B)->bit07)
#define IMR7                   (*(volatile unsigned long  *)0xFFFFB41C)
#define IMR7L                  (*(volatile unsigned short *)0xFFFFB41C)
#define IMR7LL                 (*(volatile unsigned char  *)0xFFFFB41C)
#define IMR7LH                 (*(volatile unsigned char  *)0xFFFFB41D)
#define IMR7H                  (*(volatile unsigned short *)0xFFFFB41E)
#define IMR7HL                 (*(volatile unsigned char  *)0xFFFFB41E)
#define IMR7HH                 (*(volatile unsigned char  *)0xFFFFB41F)
#define IMR7EIMK224            (((volatile __bitf_T *)0xFFFFB41C)->bit00)
#define IMR7EIMK225            (((volatile __bitf_T *)0xFFFFB41C)->bit01)
#define IMR7EIMK226            (((volatile __bitf_T *)0xFFFFB41C)->bit02)
#define IMR7EIMK227            (((volatile __bitf_T *)0xFFFFB41C)->bit03)
#define IMR7EIMK228            (((volatile __bitf_T *)0xFFFFB41C)->bit04)
#define IMR7EIMK229            (((volatile __bitf_T *)0xFFFFB41C)->bit05)
#define IMR7EIMK230            (((volatile __bitf_T *)0xFFFFB41C)->bit06)
#define IMR7EIMK231            (((volatile __bitf_T *)0xFFFFB41C)->bit07)
#define IMR7EIMK232            (((volatile __bitf_T *)0xFFFFB41D)->bit00)
#define IMR7EIMK233            (((volatile __bitf_T *)0xFFFFB41D)->bit01)
#define IMR7EIMK234            (((volatile __bitf_T *)0xFFFFB41D)->bit02)
#define IMR7EIMK235            (((volatile __bitf_T *)0xFFFFB41D)->bit03)
#define IMR7EIMK236            (((volatile __bitf_T *)0xFFFFB41D)->bit04)
#define IMR7EIMK237            (((volatile __bitf_T *)0xFFFFB41D)->bit05)
#define IMR7EIMK238            (((volatile __bitf_T *)0xFFFFB41D)->bit06)
#define IMR7EIMK239            (((volatile __bitf_T *)0xFFFFB41D)->bit07)
#define IMR7EIMK240            (((volatile __bitf_T *)0xFFFFB41E)->bit00)
#define IMR7EIMK241            (((volatile __bitf_T *)0xFFFFB41E)->bit01)
#define IMR7EIMK242            (((volatile __bitf_T *)0xFFFFB41E)->bit02)
#define IMR7EIMK243            (((volatile __bitf_T *)0xFFFFB41E)->bit03)
#define IMR7EIMK244            (((volatile __bitf_T *)0xFFFFB41E)->bit04)
#define IMR7EIMK245            (((volatile __bitf_T *)0xFFFFB41E)->bit05)
#define IMR7EIMK246            (((volatile __bitf_T *)0xFFFFB41E)->bit06)
#define IMR7EIMK247            (((volatile __bitf_T *)0xFFFFB41E)->bit07)
#define IMR7EIMK248            (((volatile __bitf_T *)0xFFFFB41F)->bit00)
#define IMR7EIMK249            (((volatile __bitf_T *)0xFFFFB41F)->bit01)
#define IMR7EIMK250            (((volatile __bitf_T *)0xFFFFB41F)->bit02)
#define IMR7EIMK251            (((volatile __bitf_T *)0xFFFFB41F)->bit03)
#define IMR7EIMK252            (((volatile __bitf_T *)0xFFFFB41F)->bit04)
#define IMR7EIMK253            (((volatile __bitf_T *)0xFFFFB41F)->bit05)
#define IMR7EIMK254            (((volatile __bitf_T *)0xFFFFB41F)->bit06)
#define IMR7EIMK255            (((volatile __bitf_T *)0xFFFFB41F)->bit07)
#define EIBD32                 (*(volatile unsigned long  *)0xFFFFB880)
#define EIBD33                 (*(volatile unsigned long  *)0xFFFFB884)
#define EIBD34                 (*(volatile unsigned long  *)0xFFFFB888)
#define EIBD35                 (*(volatile unsigned long  *)0xFFFFB88C)
#define EIBD36                 (*(volatile unsigned long  *)0xFFFFB890)
#define EIBD37                 (*(volatile unsigned long  *)0xFFFFB894)
#define EIBD38                 (*(volatile unsigned long  *)0xFFFFB898)
#define EIBD39                 (*(volatile unsigned long  *)0xFFFFB89C)
#define EIBD40                 (*(volatile unsigned long  *)0xFFFFB8A0)
#define EIBD41                 (*(volatile unsigned long  *)0xFFFFB8A4)
#define EIBD42                 (*(volatile unsigned long  *)0xFFFFB8A8)
#define EIBD43                 (*(volatile unsigned long  *)0xFFFFB8AC)
#define EIBD44                 (*(volatile unsigned long  *)0xFFFFB8B0)
#define EIBD45                 (*(volatile unsigned long  *)0xFFFFB8B4)
#define EIBD46                 (*(volatile unsigned long  *)0xFFFFB8B8)
#define EIBD47                 (*(volatile unsigned long  *)0xFFFFB8BC)
#define EIBD48                 (*(volatile unsigned long  *)0xFFFFB8C0)
#define EIBD49                 (*(volatile unsigned long  *)0xFFFFB8C4)
#define EIBD50                 (*(volatile unsigned long  *)0xFFFFB8C8)
#define EIBD51                 (*(volatile unsigned long  *)0xFFFFB8CC)
#define EIBD52                 (*(volatile unsigned long  *)0xFFFFB8D0)
#define EIBD53                 (*(volatile unsigned long  *)0xFFFFB8D4)
#define EIBD54                 (*(volatile unsigned long  *)0xFFFFB8D8)
#define EIBD55                 (*(volatile unsigned long  *)0xFFFFB8DC)
#define EIBD56                 (*(volatile unsigned long  *)0xFFFFB8E0)
#define EIBD57                 (*(volatile unsigned long  *)0xFFFFB8E4)
#define EIBD58                 (*(volatile unsigned long  *)0xFFFFB8E8)
#define EIBD59                 (*(volatile unsigned long  *)0xFFFFB8EC)
#define EIBD60                 (*(volatile unsigned long  *)0xFFFFB8F0)
#define EIBD61                 (*(volatile unsigned long  *)0xFFFFB8F4)
#define EIBD62                 (*(volatile unsigned long  *)0xFFFFB8F8)
#define EIBD63                 (*(volatile unsigned long  *)0xFFFFB8FC)
#define EIBD64                 (*(volatile unsigned long  *)0xFFFFB900)
#define EIBD65                 (*(volatile unsigned long  *)0xFFFFB904)
#define EIBD66                 (*(volatile unsigned long  *)0xFFFFB908)
#define EIBD67                 (*(volatile unsigned long  *)0xFFFFB90C)
#define EIBD68                 (*(volatile unsigned long  *)0xFFFFB910)
#define EIBD69                 (*(volatile unsigned long  *)0xFFFFB914)
#define EIBD70                 (*(volatile unsigned long  *)0xFFFFB918)
#define EIBD71                 (*(volatile unsigned long  *)0xFFFFB91C)
#define EIBD72                 (*(volatile unsigned long  *)0xFFFFB920)
#define EIBD73                 (*(volatile unsigned long  *)0xFFFFB924)
#define EIBD74                 (*(volatile unsigned long  *)0xFFFFB928)
#define EIBD75                 (*(volatile unsigned long  *)0xFFFFB92C)
#define EIBD76                 (*(volatile unsigned long  *)0xFFFFB930)
#define EIBD77                 (*(volatile unsigned long  *)0xFFFFB934)
#define EIBD78                 (*(volatile unsigned long  *)0xFFFFB938)
#define EIBD79                 (*(volatile unsigned long  *)0xFFFFB93C)
#define EIBD80                 (*(volatile unsigned long  *)0xFFFFB940)
#define EIBD81                 (*(volatile unsigned long  *)0xFFFFB944)
#define EIBD82                 (*(volatile unsigned long  *)0xFFFFB948)
#define EIBD83                 (*(volatile unsigned long  *)0xFFFFB94C)
#define EIBD84                 (*(volatile unsigned long  *)0xFFFFB950)
#define EIBD85                 (*(volatile unsigned long  *)0xFFFFB954)
#define EIBD86                 (*(volatile unsigned long  *)0xFFFFB958)
#define EIBD87                 (*(volatile unsigned long  *)0xFFFFB95C)
#define EIBD88                 (*(volatile unsigned long  *)0xFFFFB960)
#define EIBD89                 (*(volatile unsigned long  *)0xFFFFB964)
#define EIBD90                 (*(volatile unsigned long  *)0xFFFFB968)
#define EIBD91                 (*(volatile unsigned long  *)0xFFFFB96C)
#define EIBD92                 (*(volatile unsigned long  *)0xFFFFB970)
#define EIBD93                 (*(volatile unsigned long  *)0xFFFFB974)
#define EIBD94                 (*(volatile unsigned long  *)0xFFFFB978)
#define EIBD95                 (*(volatile unsigned long  *)0xFFFFB97C)
#define EIBD96                 (*(volatile unsigned long  *)0xFFFFB980)
#define EIBD97                 (*(volatile unsigned long  *)0xFFFFB984)
#define EIBD98                 (*(volatile unsigned long  *)0xFFFFB988)
#define EIBD99                 (*(volatile unsigned long  *)0xFFFFB98C)
#define EIBD100                (*(volatile unsigned long  *)0xFFFFB990)
#define EIBD101                (*(volatile unsigned long  *)0xFFFFB994)
#define EIBD102                (*(volatile unsigned long  *)0xFFFFB998)
#define EIBD103                (*(volatile unsigned long  *)0xFFFFB99C)
#define EIBD104                (*(volatile unsigned long  *)0xFFFFB9A0)
#define EIBD105                (*(volatile unsigned long  *)0xFFFFB9A4)
#define EIBD106                (*(volatile unsigned long  *)0xFFFFB9A8)
#define EIBD107                (*(volatile unsigned long  *)0xFFFFB9AC)
#define EIBD108                (*(volatile unsigned long  *)0xFFFFB9B0)
#define EIBD109                (*(volatile unsigned long  *)0xFFFFB9B4)
#define EIBD110                (*(volatile unsigned long  *)0xFFFFB9B8)
#define EIBD111                (*(volatile unsigned long  *)0xFFFFB9BC)
#define EIBD112                (*(volatile unsigned long  *)0xFFFFB9C0)
#define EIBD113                (*(volatile unsigned long  *)0xFFFFB9C4)
#define EIBD114                (*(volatile unsigned long  *)0xFFFFB9C8)
#define EIBD115                (*(volatile unsigned long  *)0xFFFFB9CC)
#define EIBD116                (*(volatile unsigned long  *)0xFFFFB9D0)
#define EIBD117                (*(volatile unsigned long  *)0xFFFFB9D4)
#define EIBD118                (*(volatile unsigned long  *)0xFFFFB9D8)
#define EIBD119                (*(volatile unsigned long  *)0xFFFFB9DC)
#define EIBD120                (*(volatile unsigned long  *)0xFFFFB9E0)
#define EIBD121                (*(volatile unsigned long  *)0xFFFFB9E4)
#define EIBD122                (*(volatile unsigned long  *)0xFFFFB9E8)
#define EIBD123                (*(volatile unsigned long  *)0xFFFFB9EC)
#define EIBD124                (*(volatile unsigned long  *)0xFFFFB9F0)
#define EIBD125                (*(volatile unsigned long  *)0xFFFFB9F4)
#define EIBD126                (*(volatile unsigned long  *)0xFFFFB9F8)
#define EIBD127                (*(volatile unsigned long  *)0xFFFFB9FC)
#define EIBD128                (*(volatile unsigned long  *)0xFFFFBA00)
#define EIBD129                (*(volatile unsigned long  *)0xFFFFBA04)
#define EIBD130                (*(volatile unsigned long  *)0xFFFFBA08)
#define EIBD131                (*(volatile unsigned long  *)0xFFFFBA0C)
#define EIBD132                (*(volatile unsigned long  *)0xFFFFBA10)
#define EIBD133                (*(volatile unsigned long  *)0xFFFFBA14)
#define EIBD134                (*(volatile unsigned long  *)0xFFFFBA18)
#define EIBD135                (*(volatile unsigned long  *)0xFFFFBA1C)
#define EIBD136                (*(volatile unsigned long  *)0xFFFFBA20)
#define EIBD137                (*(volatile unsigned long  *)0xFFFFBA24)
#define EIBD138                (*(volatile unsigned long  *)0xFFFFBA28)
#define EIBD139                (*(volatile unsigned long  *)0xFFFFBA2C)
#define EIBD140                (*(volatile unsigned long  *)0xFFFFBA30)
#define EIBD141                (*(volatile unsigned long  *)0xFFFFBA34)
#define EIBD142                (*(volatile unsigned long  *)0xFFFFBA38)
#define EIBD143                (*(volatile unsigned long  *)0xFFFFBA3C)
#define EIBD144                (*(volatile unsigned long  *)0xFFFFBA40)
#define EIBD145                (*(volatile unsigned long  *)0xFFFFBA44)
#define EIBD146                (*(volatile unsigned long  *)0xFFFFBA48)
#define EIBD147                (*(volatile unsigned long  *)0xFFFFBA4C)
#define EIBD148                (*(volatile unsigned long  *)0xFFFFBA50)
#define EIBD149                (*(volatile unsigned long  *)0xFFFFBA54)
#define EIBD150                (*(volatile unsigned long  *)0xFFFFBA58)
#define EIBD151                (*(volatile unsigned long  *)0xFFFFBA5C)
#define EIBD152                (*(volatile unsigned long  *)0xFFFFBA60)
#define EIBD153                (*(volatile unsigned long  *)0xFFFFBA64)
#define EIBD154                (*(volatile unsigned long  *)0xFFFFBA68)
#define EIBD155                (*(volatile unsigned long  *)0xFFFFBA6C)
#define EIBD156                (*(volatile unsigned long  *)0xFFFFBA70)
#define EIBD157                (*(volatile unsigned long  *)0xFFFFBA74)
#define EIBD158                (*(volatile unsigned long  *)0xFFFFBA78)
#define EIBD159                (*(volatile unsigned long  *)0xFFFFBA7C)
#define EIBD160                (*(volatile unsigned long  *)0xFFFFBA80)
#define EIBD161                (*(volatile unsigned long  *)0xFFFFBA84)
#define EIBD162                (*(volatile unsigned long  *)0xFFFFBA88)
#define EIBD163                (*(volatile unsigned long  *)0xFFFFBA8C)
#define EIBD164                (*(volatile unsigned long  *)0xFFFFBA90)
#define EIBD165                (*(volatile unsigned long  *)0xFFFFBA94)
#define EIBD166                (*(volatile unsigned long  *)0xFFFFBA98)
#define EIBD167                (*(volatile unsigned long  *)0xFFFFBA9C)
#define EIBD168                (*(volatile unsigned long  *)0xFFFFBAA0)
#define EIBD169                (*(volatile unsigned long  *)0xFFFFBAA4)
#define EIBD170                (*(volatile unsigned long  *)0xFFFFBAA8)
#define EIBD171                (*(volatile unsigned long  *)0xFFFFBAAC)
#define EIBD172                (*(volatile unsigned long  *)0xFFFFBAB0)
#define EIBD173                (*(volatile unsigned long  *)0xFFFFBAB4)
#define EIBD174                (*(volatile unsigned long  *)0xFFFFBAB8)
#define EIBD175                (*(volatile unsigned long  *)0xFFFFBABC)
#define EIBD176                (*(volatile unsigned long  *)0xFFFFBAC0)
#define EIBD177                (*(volatile unsigned long  *)0xFFFFBAC4)
#define EIBD178                (*(volatile unsigned long  *)0xFFFFBAC8)
#define EIBD179                (*(volatile unsigned long  *)0xFFFFBACC)
#define EIBD180                (*(volatile unsigned long  *)0xFFFFBAD0)
#define EIBD181                (*(volatile unsigned long  *)0xFFFFBAD4)
#define EIBD182                (*(volatile unsigned long  *)0xFFFFBAD8)
#define EIBD183                (*(volatile unsigned long  *)0xFFFFBADC)
#define EIBD184                (*(volatile unsigned long  *)0xFFFFBAE0)
#define EIBD185                (*(volatile unsigned long  *)0xFFFFBAE4)
#define EIBD186                (*(volatile unsigned long  *)0xFFFFBAE8)
#define EIBD187                (*(volatile unsigned long  *)0xFFFFBAEC)
#define EIBD188                (*(volatile unsigned long  *)0xFFFFBAF0)
#define EIBD189                (*(volatile unsigned long  *)0xFFFFBAF4)
#define EIBD190                (*(volatile unsigned long  *)0xFFFFBAF8)
#define EIBD191                (*(volatile unsigned long  *)0xFFFFBAFC)
#define EIBD192                (*(volatile unsigned long  *)0xFFFFBB00)
#define EIBD193                (*(volatile unsigned long  *)0xFFFFBB04)
#define EIBD194                (*(volatile unsigned long  *)0xFFFFBB08)
#define EIBD195                (*(volatile unsigned long  *)0xFFFFBB0C)
#define EIBD196                (*(volatile unsigned long  *)0xFFFFBB10)
#define EIBD197                (*(volatile unsigned long  *)0xFFFFBB14)
#define EIBD198                (*(volatile unsigned long  *)0xFFFFBB18)
#define EIBD199                (*(volatile unsigned long  *)0xFFFFBB1C)
#define EIBD200                (*(volatile unsigned long  *)0xFFFFBB20)
#define EIBD201                (*(volatile unsigned long  *)0xFFFFBB24)
#define EIBD202                (*(volatile unsigned long  *)0xFFFFBB28)
#define EIBD203                (*(volatile unsigned long  *)0xFFFFBB2C)
#define EIBD204                (*(volatile unsigned long  *)0xFFFFBB30)
#define EIBD205                (*(volatile unsigned long  *)0xFFFFBB34)
#define EIBD206                (*(volatile unsigned long  *)0xFFFFBB38)
#define EIBD207                (*(volatile unsigned long  *)0xFFFFBB3C)
#define EIBD208                (*(volatile unsigned long  *)0xFFFFBB40)
#define EIBD209                (*(volatile unsigned long  *)0xFFFFBB44)
#define EIBD210                (*(volatile unsigned long  *)0xFFFFBB48)
#define EIBD211                (*(volatile unsigned long  *)0xFFFFBB4C)
#define EIBD212                (*(volatile unsigned long  *)0xFFFFBB50)
#define EIBD213                (*(volatile unsigned long  *)0xFFFFBB54)
#define EIBD214                (*(volatile unsigned long  *)0xFFFFBB58)
#define EIBD215                (*(volatile unsigned long  *)0xFFFFBB5C)
#define EIBD216                (*(volatile unsigned long  *)0xFFFFBB60)
#define EIBD217                (*(volatile unsigned long  *)0xFFFFBB64)
#define EIBD218                (*(volatile unsigned long  *)0xFFFFBB68)
#define EIBD219                (*(volatile unsigned long  *)0xFFFFBB6C)
#define EIBD220                (*(volatile unsigned long  *)0xFFFFBB70)
#define EIBD221                (*(volatile unsigned long  *)0xFFFFBB74)
#define EIBD222                (*(volatile unsigned long  *)0xFFFFBB78)
#define EIBD223                (*(volatile unsigned long  *)0xFFFFBB7C)
#define EIBD224                (*(volatile unsigned long  *)0xFFFFBB80)
#define EIBD225                (*(volatile unsigned long  *)0xFFFFBB84)
#define EIBD226                (*(volatile unsigned long  *)0xFFFFBB88)
#define EIBD227                (*(volatile unsigned long  *)0xFFFFBB8C)
#define EIBD228                (*(volatile unsigned long  *)0xFFFFBB90)
#define EIBD229                (*(volatile unsigned long  *)0xFFFFBB94)
#define EIBD230                (*(volatile unsigned long  *)0xFFFFBB98)
#define EIBD231                (*(volatile unsigned long  *)0xFFFFBB9C)
#define EIBD232                (*(volatile unsigned long  *)0xFFFFBBA0)
#define EIBD233                (*(volatile unsigned long  *)0xFFFFBBA4)
#define EIBD234                (*(volatile unsigned long  *)0xFFFFBBA8)
#define EIBD235                (*(volatile unsigned long  *)0xFFFFBBAC)
#define EIBD236                (*(volatile unsigned long  *)0xFFFFBBB0)
#define EIBD237                (*(volatile unsigned long  *)0xFFFFBBB4)
#define EIBD238                (*(volatile unsigned long  *)0xFFFFBBB8)
#define EIBD239                (*(volatile unsigned long  *)0xFFFFBBBC)
#define EIBD240                (*(volatile unsigned long  *)0xFFFFBBC0)
#define EIBD241                (*(volatile unsigned long  *)0xFFFFBBC4)
#define EIBD242                (*(volatile unsigned long  *)0xFFFFBBC8)
#define EIBD243                (*(volatile unsigned long  *)0xFFFFBBCC)
#define EIBD244                (*(volatile unsigned long  *)0xFFFFBBD0)
#define EIBD245                (*(volatile unsigned long  *)0xFFFFBBD4)

#define FLXA0    (*(volatile struct __tag63  *)0x10020000) /* FLXA0 */
#define ETNA0    (*(volatile struct __tag64  *)0x10024000) /* ETNA0 */
#define FLMD     (*(volatile struct __tag65  *)0xFFA00000) /* FLMD */
#define FACI0    (*(volatile struct __tag66  *)0xFFA10000) /* FACI0 */
#define FACI1    (*(volatile struct __tag66  *)0xFFA18000) /* FACI1 */
#define DNFA2    (*(volatile struct __tag67  *)0xFFC30200) /* DNFA2 */
#define DNFA3    (*(volatile struct __tag67  *)0xFFC30300) /* DNFA3 */
#define DNFA4    (*(volatile struct __tag67  *)0xFFC30400) /* DNFA4 */
#define DNFA5    (*(volatile struct __tag68  *)0xFFC30500) /* DNFA5 */
#define DNFA6    (*(volatile struct __tag67  *)0xFFC30600) /* DNFA6 */
#define DNFA7    (*(volatile struct __tag67  *)0xFFC30700) /* DNFA7 */
#define FCLA0    (*(volatile struct __tag69  *)0xFFC34000) /* FCLA0 */
#define FCLA1    (*(volatile struct __tag70  *)0xFFC34100) /* FCLA1 */
#define FCLA2    (*(volatile struct __tag71  *)0xFFC34200) /* FCLA2 */
#define FCLA3    (*(volatile struct __tag71  *)0xFFC34300) /* FCLA3 */
#define FCLA4    (*(volatile struct __tag71  *)0xFFC34400) /* FCLA4 */
#define FCLA5    (*(volatile struct __tag72  *)0xFFC34500) /* FCLA5 */
#define FCLA6    (*(volatile struct __tag73  *)0xFFC34600) /* FCLA6 */
#define FSGD5A   (*(volatile struct __tag74  *)0xFFC5A000) /* FSGD5A */
#define ERRSLV5A (*(volatile struct __tag75  *)0xFFC5A100) /* ERRSLV5A */
#define FSGD5B   (*(volatile struct __tag76  *)0xFFC5A200) /* FSGD5B */
#define ERRSLV5B (*(volatile struct __tag75  *)0xFFC5A300) /* ERRSLV5B */
#define FSGD5C   (*(volatile struct __tag77  *)0xFFC5A400) /* FSGD5C */
#define ERRSLV5C (*(volatile struct __tag75  *)0xFFC5A500) /* ERRSLV5C */
#define FSGD5D   (*(volatile struct __tag76  *)0xFFC5A600) /* FSGD5D */
#define ERRSLV5D (*(volatile struct __tag75  *)0xFFC5A700) /* ERRSLV5D */
#define ERRSLV5AI (*(volatile struct __tag75  *)0xFFC5A800) /* ERRSLV5AI */
#define ERRSLV5BI (*(volatile struct __tag75  *)0xFFC5A900) /* ERRSLV5BI */
#define ERRSLVDG0 (*(volatile struct __tag75  *)0xFFC5AE00) /* ERRSLVDG0 */
#define ERRSLVDG1 (*(volatile struct __tag75  *)0xFFC5AF00) /* ERRSLVDG1 */
#define ECCCSIH0 (*(volatile struct __tag78  *)0xFFC70000) /* ECCCSIH0 */
#define ECCCSIH2 (*(volatile struct __tag78  *)0xFFC70100) /* ECCCSIH2 */
#define ECCTTCAN0 (*(volatile struct __tag78  *)0xFFC71000) /* ECCTTCAN0 */
#define ECCMCAN1 (*(volatile struct __tag78  *)0xFFC71100) /* ECCMCAN1 */
#define ECCFLX0  (*(volatile struct __tag78  *)0xFFC72000) /* ECCFLX0 */
#define ECCFLX0T0 (*(volatile struct __tag78  *)0xFFC72100) /* ECCFLX0T0 */
#define ECCFLX0T1 (*(volatile struct __tag78  *)0xFFC72200) /* ECCFLX0T1 */
#define ECCCSIH1 (*(volatile struct __tag78  *)0xFFC78000) /* ECCCSIH1 */
#define ECCCSIH3 (*(volatile struct __tag78  *)0xFFC78100) /* ECCCSIH3 */
#define ECCMCAN0 (*(volatile struct __tag78  *)0xFFC79000) /* ECCMCAN0 */
#define CSIH1    (*(volatile struct __tag79  *)0xFFCA0000) /* CSIH1 */
#define PMMA1    (*(volatile struct __tag80  *)0xFFCA2000) /* PMMA1 */
#define CSIH3    (*(volatile struct __tag79  *)0xFFCA3000) /* CSIH3 */
#define PMMA3    (*(volatile struct __tag80  *)0xFFCA5000) /* PMMA3 */
#define HSUS1    (*(volatile struct __tag81  *)0xFFCA8000) /* HSUS1 */
#define RLN31    (*(volatile struct __tag82  *)0xFFCAC000) /* RLN31 */
#define RSENT0   (*(volatile struct __tag83  *)0xFFCDC000) /* RSENT0 */
#define RSENT1   (*(volatile struct __tag83  *)0xFFCDC100) /* RSENT1 */
#define RSENT2   (*(volatile struct __tag83  *)0xFFCDC200) /* RSENT2 */
#define RSENT3   (*(volatile struct __tag83  *)0xFFCDC300) /* RSENT3 */
#define RSENT4   (*(volatile struct __tag83  *)0xFFCDC400) /* RSENT4 */
#define RSENT5   (*(volatile struct __tag83  *)0xFFCDC500) /* RSENT5 */
#define RSENT6   (*(volatile struct __tag84  *)0xFFCDC600) /* RSENT6 */
#define SINT     (*(volatile struct __tag85  *)0xFFCDE000) /* SINT */
#define MTTCAN0  (*(volatile struct __tag86  *)0xFFD30000) /* MTTCAN0 */
#define MCAN1    (*(volatile struct __tag87  *)0xFFD31000) /* MCAN1 */
#define DCRB0    (*(volatile struct __tag88  *)0xFFD50000) /* DCRB0 */
#define DCRB2    (*(volatile struct __tag88  *)0xFFD51000) /* DCRB2 */
#define ECMM0    (*(volatile struct __tag89  *)0xFFD60000) /* ECMM0 */
#define ECMC0    (*(volatile struct __tag89  *)0xFFD61000) /* ECMC0 */
#define ECM0     (*(volatile struct __tag90  *)0xFFD62000) /* ECM0 */
#define PIC2C    (*(volatile struct __tag91  *)0xFFD68000) /* PIC2C */
#define CSIH0    (*(volatile struct __tag79  *)0xFFD80000) /* CSIH0 */
#define PMMA0    (*(volatile struct __tag80  *)0xFFD82000) /* PMMA0 */
#define CSIH2    (*(volatile struct __tag79  *)0xFFD83000) /* CSIH2 */
#define PMMA2    (*(volatile struct __tag80  *)0xFFD85000) /* PMMA2 */
#define HSUS0    (*(volatile struct __tag81  *)0xFFD88000) /* HSUS0 */
#define RLN30    (*(volatile struct __tag82  *)0xFFD8C000) /* RLN30 */
#define STM0     (*(volatile struct __tag92  *)0xFFDD8000) /* STM0 */
#define FSGD2A   (*(volatile struct __tag93  *)0xFFDDD000) /* FSGD2A */
#define ERRSLV2  (*(volatile struct __tag75  *)0xFFDDD100) /* ERRSLV2 */
#define ERRSLV2AI (*(volatile struct __tag75  *)0xFFDDD800) /* ERRSLV2AI */
#define GTM0     (*(volatile struct __tag94  *)0xFFE00000) /* GTM0 */
#define ECCGTM0  (*(volatile struct __tag78  *)0xFFE80000) /* ECCGTM0 */
#define ECCGTM1  (*(volatile struct __tag78  *)0xFFE80100) /* ECCGTM1 */
#define ECCGTM2  (*(volatile struct __tag78  *)0xFFE80200) /* ECCGTM2 */
#define ECCGTM3  (*(volatile struct __tag78  *)0xFFE80300) /* ECCGTM3 */
#define WDTA0    (*(volatile struct __tag95  *)0xFFED0000) /* WDTA0 */
#define SWD0     (*(volatile struct __tag96  *)0xFFED8000) /* SWD0 */
#define FSGD1A   (*(volatile struct __tag74  *)0xFFEE0000) /* FSGD1A */
#define ERRSLV1  (*(volatile struct __tag75  *)0xFFEE0100) /* ERRSLV1 */
#define FSGD1B   (*(volatile struct __tag97  *)0xFFEE0200) /* FSGD1B */
#define ERRSLV1AI (*(volatile struct __tag75  *)0xFFEE0800) /* ERRSLV1AI */
#define MCAN0    (*(volatile struct __tag98  *)0xFFEF0000) /* MCAN0 */
#define DCRB1    (*(volatile struct __tag88  *)0xFFF70000) /* DCRB1 */
#define DCRB3    (*(volatile struct __tag88  *)0xFFF71000) /* DCRB3 */
#define CLMA0    (*(volatile struct __tag99  *)0xFFF83100) /* CLMA0 */
#define CLMA1    (*(volatile struct __tag99  *)0xFFF83200) /* CLMA1 */
#define CLMA2    (*(volatile struct __tag99  *)0xFFF83300) /* CLMA2 */
#define CLMA3    (*(volatile struct __tag99  *)0xFFF83400) /* CLMA3 */
#define CLMA5    (*(volatile struct __tag100 *)0xFFF86800) /* CLMA5 */
#define FSGD4A   (*(volatile struct __tag101 *)0xFFF90000) /* FSGD4A */
#define ERRSLV4  (*(volatile struct __tag75  *)0xFFF90100) /* ERRSLV4 */
#define FSGD4B   (*(volatile struct __tag102 *)0xFFF90200) /* FSGD4B */
#define FSGD4C   (*(volatile struct __tag102 *)0xFFF90400) /* FSGD4C */
#define ERRSLV4C (*(volatile struct __tag75  *)0xFFF90500) /* ERRSLV4C */
#define ERRSLV4AI (*(volatile struct __tag75  *)0xFFF90800) /* ERRSLV4AI */
#define ADCF0    (*(volatile struct __tag103 *)0xFFF91000) /* ADCF0 */
#define ADCF1    (*(volatile struct __tag104 *)0xFFF92000) /* ADCF1 */
#define OTS0     (*(volatile struct __tag105 *)0xFFF93000) /* OTS0 */
#define FSGD3A   (*(volatile struct __tag101 *)0xFFF94000) /* FSGD3A */
#define ERRSLV3  (*(volatile struct __tag75  *)0xFFF94100) /* ERRSLV3 */
#define FSGD3B   (*(volatile struct __tag106 *)0xFFF94200) /* FSGD3B */
#define ERRSLV3AI (*(volatile struct __tag75  *)0xFFF94800) /* ERRSLV3AI */
#define NTU0     (*(volatile struct __tag107 *)0xFFF9C008) /* NTU0 */
#define FSGDF0   (*(volatile struct __tag77  *)0xFFFA0000) /* FSGDF0 */
#define ERRSLVF0 (*(volatile struct __tag75  *)0xFFFA0010) /* ERRSLVF0 */
#define FSGDE0   (*(volatile struct __tag77  *)0xFFFA0040) /* FSGDE0 */
#define ERRSLVE0 (*(volatile struct __tag75  *)0xFFFA0050) /* ERRSLVE0 */
#define ERRSLVFI (*(volatile struct __tag75  *)0xFFFA0100) /* ERRSLVFI */
#define ERRSLVEI (*(volatile struct __tag75  *)0xFFFA0110) /* ERRSLVEI */
#define ERRSLVMI (*(volatile struct __tag75  *)0xFFFA0120) /* ERRSLVMI */
#define ERRSLVHI (*(volatile struct __tag75  *)0xFFFA0130) /* ERRSLVHI */
#define ERRSLVXI (*(volatile struct __tag75  *)0xFFFA0140) /* ERRSLVXI */
#define HSSPID   (*(volatile struct __tag108 *)0xFFFA1000) /* HSSPID */
#define HTHDMA   (*(volatile struct __tag109 *)0xFFFA2000) /* HTHDMA */
#define IPG      (*(volatile struct __tag110 *)0xFFFEE000) /* IPG */
#define PEG      (*(volatile struct __tag111 *)0xFFFEE680) /* PEG */
#define SEG      (*(volatile struct __tag112 *)0xFFFEE980) /* SEG */

/* IOR List *
FLXA0.FRPV
FLXA0.FROC.UINT32
FLXA0.FROC.UINT16[L/H]
FLXA0.FROC.UINT8[LL/HL]
FLXA0.FROS.UINT32
FLXA0.FROS.UINT16[L/H]
FLXA0.FROS.UINT8[LL/HL]
FLXA0.FRTEST1.UINT32
FLXA0.FRTEST1.UINT16[L/H]
FLXA0.FRTEST1.UINT8[LL/LH/HL/HH]
FLXA0.FRTEST2.UINT32
FLXA0.FRTEST2.UINT16[L]
FLXA0.FRTEST2.UINT8[LL]
FLXA0.FRLCK.UINT32
FLXA0.FRLCK.UINT16[L]
FLXA0.FRLCK.UINT8[LL/LH]
FLXA0.FREIR.UINT32
FLXA0.FREIR.UINT16[L/H]
FLXA0.FREIR.UINT8[LL/LH/HL/HH]
FLXA0.FRSIR.UINT32
FLXA0.FRSIR.UINT16[L/H]
FLXA0.FRSIR.UINT8[LL/LH/HL/HH]
FLXA0.FREILS.UINT32
FLXA0.FREILS.UINT16[L/H]
FLXA0.FREILS.UINT8[LL/LH/HL/HH]
FLXA0.FRSILS.UINT32
FLXA0.FRSILS.UINT16[L/H]
FLXA0.FRSILS.UINT8[LL/LH/HL/HH]
FLXA0.FREIES.UINT32
FLXA0.FREIES.UINT16[L/H]
FLXA0.FREIES.UINT8[LL/LH/HL/HH]
FLXA0.FREIER.UINT32
FLXA0.FREIER.UINT16[L/H]
FLXA0.FREIER.UINT8[LL/LH/HL/HH]
FLXA0.FRSIES.UINT32
FLXA0.FRSIES.UINT16[L/H]
FLXA0.FRSIES.UINT8[LL/LH/HL/HH]
FLXA0.FRSIER.UINT32
FLXA0.FRSIER.UINT16[L/H]
FLXA0.FRSIER.UINT8[LL/LH/HL/HH]
FLXA0.FRILE.UINT32
FLXA0.FRILE.UINT16[L]
FLXA0.FRILE.UINT8[LL]
FLXA0.FRT0C.UINT32
FLXA0.FRT0C.UINT16[L/H]
FLXA0.FRT0C.UINT8[LL/LH/HL/HH]
FLXA0.FRT1C.UINT32
FLXA0.FRT1C.UINT16[L/H]
FLXA0.FRT1C.UINT8[LL/HL/HH]
FLXA0.FRSTPW1.UINT32
FLXA0.FRSTPW1.UINT16[L/H]
FLXA0.FRSTPW1.UINT8[LL/LH/HL/HH]
FLXA0.FRSTPW2.UINT32
FLXA0.FRSTPW2.UINT16[L/H]
FLXA0.FRSTPW2.UINT8[LL/LH/HL/HH]
FLXA0.FRSUCC1.UINT32
FLXA0.FRSUCC1.UINT16[L/H]
FLXA0.FRSUCC1.UINT8[LL/LH/HL/HH]
FLXA0.FRSUCC2.UINT32
FLXA0.FRSUCC2.UINT16[L/H]
FLXA0.FRSUCC2.UINT8[LL/LH/HL/HH]
FLXA0.FRSUCC3.UINT32
FLXA0.FRSUCC3.UINT16[L]
FLXA0.FRSUCC3.UINT8[LL]
FLXA0.FRNEMC.UINT32
FLXA0.FRNEMC.UINT16[L]
FLXA0.FRNEMC.UINT8[LL]
FLXA0.FRPRTC1.UINT32
FLXA0.FRPRTC1.UINT16[L/H]
FLXA0.FRPRTC1.UINT8[LL/LH/HL/HH]
FLXA0.FRPRTC2.UINT32
FLXA0.FRPRTC2.UINT16[L/H]
FLXA0.FRPRTC2.UINT8[LL/LH/HL/HH]
FLXA0.FRMHDC.UINT32
FLXA0.FRMHDC.UINT16[L/H]
FLXA0.FRMHDC.UINT8[LL/HL/HH]
FLXA0.FRGTUC1.UINT32
FLXA0.FRGTUC1.UINT16[L/H]
FLXA0.FRGTUC1.UINT8[LL/LH/HL]
FLXA0.FRGTUC2.UINT32
FLXA0.FRGTUC2.UINT16[L/H]
FLXA0.FRGTUC2.UINT8[LL/LH/HL]
FLXA0.FRGTUC3.UINT32
FLXA0.FRGTUC3.UINT16[L/H]
FLXA0.FRGTUC3.UINT8[LL/LH/HL/HH]
FLXA0.FRGTUC4.UINT32
FLXA0.FRGTUC4.UINT16[L/H]
FLXA0.FRGTUC4.UINT8[LL/LH/HL/HH]
FLXA0.FRGTUC5.UINT32
FLXA0.FRGTUC5.UINT16[L/H]
FLXA0.FRGTUC5.UINT8[LL/LH/HL/HH]
FLXA0.FRGTUC6.UINT32
FLXA0.FRGTUC6.UINT16[L/H]
FLXA0.FRGTUC6.UINT8[LL/LH/HL/HH]
FLXA0.FRGTUC7.UINT32
FLXA0.FRGTUC7.UINT16[L/H]
FLXA0.FRGTUC7.UINT8[LL/LH/HL/HH]
FLXA0.FRGTUC8.UINT32
FLXA0.FRGTUC8.UINT16[L/H]
FLXA0.FRGTUC8.UINT8[LL/HL/HH]
FLXA0.FRGTUC9.UINT32
FLXA0.FRGTUC9.UINT16[L/H]
FLXA0.FRGTUC9.UINT8[LL/LH/HL]
FLXA0.FRGTUC10.UINT32
FLXA0.FRGTUC10.UINT16[L/H]
FLXA0.FRGTUC10.UINT8[LL/LH/HL/HH]
FLXA0.FRGTUC11.UINT32
FLXA0.FRGTUC11.UINT16[L/H]
FLXA0.FRGTUC11.UINT8[LL/LH/HL/HH]
FLXA0.FRCCSV.UINT32
FLXA0.FRCCSV.UINT16[L/H]
FLXA0.FRCCSV.UINT8[LL/LH/HL/HH]
FLXA0.FRCCEV.UINT32
FLXA0.FRCCEV.UINT16[L]
FLXA0.FRCCEV.UINT8[LL/LH]
FLXA0.FRSCV.UINT32
FLXA0.FRSCV.UINT16[L/H]
FLXA0.FRSCV.UINT8[LL/LH/HL/HH]
FLXA0.FRMTCCV.UINT32
FLXA0.FRMTCCV.UINT16[L/H]
FLXA0.FRMTCCV.UINT8[LL/LH/HL]
FLXA0.FRRCV.UINT32
FLXA0.FRRCV.UINT16[L]
FLXA0.FRRCV.UINT8[LL/LH]
FLXA0.FROCV.UINT32
FLXA0.FROCV.UINT16[L/H]
FLXA0.FROCV.UINT8[LL/LH/HL]
FLXA0.FRSFS.UINT32
FLXA0.FRSFS.UINT16[L/H]
FLXA0.FRSFS.UINT8[LL/LH/HL]
FLXA0.FRSWNIT.UINT32
FLXA0.FRSWNIT.UINT16[L]
FLXA0.FRSWNIT.UINT8[LL/LH]
FLXA0.FRACS.UINT32
FLXA0.FRACS.UINT16[L]
FLXA0.FRACS.UINT8[LL/LH]
FLXA0.FRESID1.UINT32
FLXA0.FRESID1.UINT16[L]
FLXA0.FRESID1.UINT8[LL/LH]
FLXA0.FRESID2.UINT32
FLXA0.FRESID2.UINT16[L]
FLXA0.FRESID2.UINT8[LL/LH]
FLXA0.FRESID3.UINT32
FLXA0.FRESID3.UINT16[L]
FLXA0.FRESID3.UINT8[LL/LH]
FLXA0.FRESID4.UINT32
FLXA0.FRESID4.UINT16[L]
FLXA0.FRESID4.UINT8[LL/LH]
FLXA0.FRESID5.UINT32
FLXA0.FRESID5.UINT16[L]
FLXA0.FRESID5.UINT8[LL/LH]
FLXA0.FRESID6.UINT32
FLXA0.FRESID6.UINT16[L]
FLXA0.FRESID6.UINT8[LL/LH]
FLXA0.FRESID7.UINT32
FLXA0.FRESID7.UINT16[L]
FLXA0.FRESID7.UINT8[LL/LH]
FLXA0.FRESID8.UINT32
FLXA0.FRESID8.UINT16[L]
FLXA0.FRESID8.UINT8[LL/LH]
FLXA0.FRESID9.UINT32
FLXA0.FRESID9.UINT16[L]
FLXA0.FRESID9.UINT8[LL/LH]
FLXA0.FRESID10.UINT32
FLXA0.FRESID10.UINT16[L]
FLXA0.FRESID10.UINT8[LL/LH]
FLXA0.FRESID11.UINT32
FLXA0.FRESID11.UINT16[L]
FLXA0.FRESID11.UINT8[LL/LH]
FLXA0.FRESID12.UINT32
FLXA0.FRESID12.UINT16[L]
FLXA0.FRESID12.UINT8[LL/LH]
FLXA0.FRESID13.UINT32
FLXA0.FRESID13.UINT16[L]
FLXA0.FRESID13.UINT8[LL/LH]
FLXA0.FRESID14.UINT32
FLXA0.FRESID14.UINT16[L]
FLXA0.FRESID14.UINT8[LL/LH]
FLXA0.FRESID15.UINT32
FLXA0.FRESID15.UINT16[L]
FLXA0.FRESID15.UINT8[LL/LH]
FLXA0.FROSID1.UINT32
FLXA0.FROSID1.UINT16[L]
FLXA0.FROSID1.UINT8[LL/LH]
FLXA0.FROSID2.UINT32
FLXA0.FROSID2.UINT16[L]
FLXA0.FROSID2.UINT8[LL/LH]
FLXA0.FROSID3.UINT32
FLXA0.FROSID3.UINT16[L]
FLXA0.FROSID3.UINT8[LL/LH]
FLXA0.FROSID4.UINT32
FLXA0.FROSID4.UINT16[L]
FLXA0.FROSID4.UINT8[LL/LH]
FLXA0.FROSID5.UINT32
FLXA0.FROSID5.UINT16[L]
FLXA0.FROSID5.UINT8[LL/LH]
FLXA0.FROSID6.UINT32
FLXA0.FROSID6.UINT16[L]
FLXA0.FROSID6.UINT8[LL/LH]
FLXA0.FROSID7.UINT32
FLXA0.FROSID7.UINT16[L]
FLXA0.FROSID7.UINT8[LL/LH]
FLXA0.FROSID8.UINT32
FLXA0.FROSID8.UINT16[L]
FLXA0.FROSID8.UINT8[LL/LH]
FLXA0.FROSID9.UINT32
FLXA0.FROSID9.UINT16[L]
FLXA0.FROSID9.UINT8[LL/LH]
FLXA0.FROSID10.UINT32
FLXA0.FROSID10.UINT16[L]
FLXA0.FROSID10.UINT8[LL/LH]
FLXA0.FROSID11.UINT32
FLXA0.FROSID11.UINT16[L]
FLXA0.FROSID11.UINT8[LL/LH]
FLXA0.FROSID12.UINT32
FLXA0.FROSID12.UINT16[L]
FLXA0.FROSID12.UINT8[LL/LH]
FLXA0.FROSID13.UINT32
FLXA0.FROSID13.UINT16[L]
FLXA0.FROSID13.UINT8[LL/LH]
FLXA0.FROSID14.UINT32
FLXA0.FROSID14.UINT16[L]
FLXA0.FROSID14.UINT8[LL/LH]
FLXA0.FROSID15.UINT32
FLXA0.FROSID15.UINT16[L]
FLXA0.FROSID15.UINT8[LL/LH]
FLXA0.FRNMV1.UINT32
FLXA0.FRNMV1.UINT16[L/H]
FLXA0.FRNMV1.UINT8[LL/LH/HL/HH]
FLXA0.FRNMV2.UINT32
FLXA0.FRNMV2.UINT16[L/H]
FLXA0.FRNMV2.UINT8[LL/LH/HL/HH]
FLXA0.FRNMV3.UINT32
FLXA0.FRNMV3.UINT16[L/H]
FLXA0.FRNMV3.UINT8[LL/LH/HL/HH]
FLXA0.FRMRC.UINT32
FLXA0.FRMRC.UINT16[L/H]
FLXA0.FRMRC.UINT8[LL/LH/HL/HH]
FLXA0.FRFRF.UINT32
FLXA0.FRFRF.UINT16[L/H]
FLXA0.FRFRF.UINT8[LL/LH/HL/HH]
FLXA0.FRFRFM.UINT32
FLXA0.FRFRFM.UINT16[L]
FLXA0.FRFRFM.UINT8[LL/LH]
FLXA0.FRFCL.UINT32
FLXA0.FRFCL.UINT16[L]
FLXA0.FRFCL.UINT8[LL]
FLXA0.FRMHDS.UINT32
FLXA0.FRMHDS.UINT16[L/H]
FLXA0.FRMHDS.UINT8[LL/LH/HL/HH]
FLXA0.FRLDTS.UINT32
FLXA0.FRLDTS.UINT16[L/H]
FLXA0.FRLDTS.UINT8[LL/LH/HL/HH]
FLXA0.FRFSR.UINT32
FLXA0.FRFSR.UINT16[L]
FLXA0.FRFSR.UINT8[LL/LH]
FLXA0.FRMHDF.UINT32
FLXA0.FRMHDF.UINT16[L]
FLXA0.FRMHDF.UINT8[LL/LH]
FLXA0.FRTXRQ1.UINT32
FLXA0.FRTXRQ1.UINT16[L/H]
FLXA0.FRTXRQ1.UINT8[LL/LH/HL/HH]
FLXA0.FRTXRQ2.UINT32
FLXA0.FRTXRQ2.UINT16[L/H]
FLXA0.FRTXRQ2.UINT8[LL/LH/HL/HH]
FLXA0.FRTXRQ3.UINT32
FLXA0.FRTXRQ3.UINT16[L/H]
FLXA0.FRTXRQ3.UINT8[LL/LH/HL/HH]
FLXA0.FRTXRQ4.UINT32
FLXA0.FRTXRQ4.UINT16[L/H]
FLXA0.FRTXRQ4.UINT8[LL/LH/HL/HH]
FLXA0.FRNDAT1.UINT32
FLXA0.FRNDAT1.UINT16[L/H]
FLXA0.FRNDAT1.UINT8[LL/LH/HL/HH]
FLXA0.FRNDAT2.UINT32
FLXA0.FRNDAT2.UINT16[L/H]
FLXA0.FRNDAT2.UINT8[LL/LH/HL/HH]
FLXA0.FRNDAT3.UINT32
FLXA0.FRNDAT3.UINT16[L/H]
FLXA0.FRNDAT3.UINT8[LL/LH/HL/HH]
FLXA0.FRNDAT4.UINT32
FLXA0.FRNDAT4.UINT16[L/H]
FLXA0.FRNDAT4.UINT8[LL/LH/HL/HH]
FLXA0.FRMBSC1.UINT32
FLXA0.FRMBSC1.UINT16[L/H]
FLXA0.FRMBSC1.UINT8[LL/LH/HL/HH]
FLXA0.FRMBSC2.UINT32
FLXA0.FRMBSC2.UINT16[L/H]
FLXA0.FRMBSC2.UINT8[LL/LH/HL/HH]
FLXA0.FRMBSC3.UINT32
FLXA0.FRMBSC3.UINT16[L/H]
FLXA0.FRMBSC3.UINT8[LL/LH/HL/HH]
FLXA0.FRMBSC4.UINT32
FLXA0.FRMBSC4.UINT16[L/H]
FLXA0.FRMBSC4.UINT8[LL/LH/HL/HH]
FLXA0.FRWRDS1.UINT32
FLXA0.FRWRDS1.UINT16[L/H]
FLXA0.FRWRDS1.UINT8[LL/LH/HL/HH]
FLXA0.FRWRDS2.UINT32
FLXA0.FRWRDS2.UINT16[L/H]
FLXA0.FRWRDS2.UINT8[LL/LH/HL/HH]
FLXA0.FRWRDS3.UINT32
FLXA0.FRWRDS3.UINT16[L/H]
FLXA0.FRWRDS3.UINT8[LL/LH/HL/HH]
FLXA0.FRWRDS4.UINT32
FLXA0.FRWRDS4.UINT16[L/H]
FLXA0.FRWRDS4.UINT8[LL/LH/HL/HH]
FLXA0.FRWRDS5.UINT32
FLXA0.FRWRDS5.UINT16[L/H]
FLXA0.FRWRDS5.UINT8[LL/LH/HL/HH]
FLXA0.FRWRDS6.UINT32
FLXA0.FRWRDS6.UINT16[L/H]
FLXA0.FRWRDS6.UINT8[LL/LH/HL/HH]
FLXA0.FRWRDS7.UINT32
FLXA0.FRWRDS7.UINT16[L/H]
FLXA0.FRWRDS7.UINT8[LL/LH/HL/HH]
FLXA0.FRWRDS8.UINT32
FLXA0.FRWRDS8.UINT16[L/H]
FLXA0.FRWRDS8.UINT8[LL/LH/HL/HH]
FLXA0.FRWRDS9.UINT32
FLXA0.FRWRDS9.UINT16[L/H]
FLXA0.FRWRDS9.UINT8[LL/LH/HL/HH]
FLXA0.FRWRDS10.UINT32
FLXA0.FRWRDS10.UINT16[L/H]
FLXA0.FRWRDS10.UINT8[LL/LH/HL/HH]
FLXA0.FRWRDS11.UINT32
FLXA0.FRWRDS11.UINT16[L/H]
FLXA0.FRWRDS11.UINT8[LL/LH/HL/HH]
FLXA0.FRWRDS12.UINT32
FLXA0.FRWRDS12.UINT16[L/H]
FLXA0.FRWRDS12.UINT8[LL/LH/HL/HH]
FLXA0.FRWRDS13.UINT32
FLXA0.FRWRDS13.UINT16[L/H]
FLXA0.FRWRDS13.UINT8[LL/LH/HL/HH]
FLXA0.FRWRDS14.UINT32
FLXA0.FRWRDS14.UINT16[L/H]
FLXA0.FRWRDS14.UINT8[LL/LH/HL/HH]
FLXA0.FRWRDS15.UINT32
FLXA0.FRWRDS15.UINT16[L/H]
FLXA0.FRWRDS15.UINT8[LL/LH/HL/HH]
FLXA0.FRWRDS16.UINT32
FLXA0.FRWRDS16.UINT16[L/H]
FLXA0.FRWRDS16.UINT8[LL/LH/HL/HH]
FLXA0.FRWRDS17.UINT32
FLXA0.FRWRDS17.UINT16[L/H]
FLXA0.FRWRDS17.UINT8[LL/LH/HL/HH]
FLXA0.FRWRDS18.UINT32
FLXA0.FRWRDS18.UINT16[L/H]
FLXA0.FRWRDS18.UINT8[LL/LH/HL/HH]
FLXA0.FRWRDS19.UINT32
FLXA0.FRWRDS19.UINT16[L/H]
FLXA0.FRWRDS19.UINT8[LL/LH/HL/HH]
FLXA0.FRWRDS20.UINT32
FLXA0.FRWRDS20.UINT16[L/H]
FLXA0.FRWRDS20.UINT8[LL/LH/HL/HH]
FLXA0.FRWRDS21.UINT32
FLXA0.FRWRDS21.UINT16[L/H]
FLXA0.FRWRDS21.UINT8[LL/LH/HL/HH]
FLXA0.FRWRDS22.UINT32
FLXA0.FRWRDS22.UINT16[L/H]
FLXA0.FRWRDS22.UINT8[LL/LH/HL/HH]
FLXA0.FRWRDS23.UINT32
FLXA0.FRWRDS23.UINT16[L/H]
FLXA0.FRWRDS23.UINT8[LL/LH/HL/HH]
FLXA0.FRWRDS24.UINT32
FLXA0.FRWRDS24.UINT16[L/H]
FLXA0.FRWRDS24.UINT8[LL/LH/HL/HH]
FLXA0.FRWRDS25.UINT32
FLXA0.FRWRDS25.UINT16[L/H]
FLXA0.FRWRDS25.UINT8[LL/LH/HL/HH]
FLXA0.FRWRDS26.UINT32
FLXA0.FRWRDS26.UINT16[L/H]
FLXA0.FRWRDS26.UINT8[LL/LH/HL/HH]
FLXA0.FRWRDS27.UINT32
FLXA0.FRWRDS27.UINT16[L/H]
FLXA0.FRWRDS27.UINT8[LL/LH/HL/HH]
FLXA0.FRWRDS28.UINT32
FLXA0.FRWRDS28.UINT16[L/H]
FLXA0.FRWRDS28.UINT8[LL/LH/HL/HH]
FLXA0.FRWRDS29.UINT32
FLXA0.FRWRDS29.UINT16[L/H]
FLXA0.FRWRDS29.UINT8[LL/LH/HL/HH]
FLXA0.FRWRDS30.UINT32
FLXA0.FRWRDS30.UINT16[L/H]
FLXA0.FRWRDS30.UINT8[LL/LH/HL/HH]
FLXA0.FRWRDS31.UINT32
FLXA0.FRWRDS31.UINT16[L/H]
FLXA0.FRWRDS31.UINT8[LL/LH/HL/HH]
FLXA0.FRWRDS32.UINT32
FLXA0.FRWRDS32.UINT16[L/H]
FLXA0.FRWRDS32.UINT8[LL/LH/HL/HH]
FLXA0.FRWRDS33.UINT32
FLXA0.FRWRDS33.UINT16[L/H]
FLXA0.FRWRDS33.UINT8[LL/LH/HL/HH]
FLXA0.FRWRDS34.UINT32
FLXA0.FRWRDS34.UINT16[L/H]
FLXA0.FRWRDS34.UINT8[LL/LH/HL/HH]
FLXA0.FRWRDS35.UINT32
FLXA0.FRWRDS35.UINT16[L/H]
FLXA0.FRWRDS35.UINT8[LL/LH/HL/HH]
FLXA0.FRWRDS36.UINT32
FLXA0.FRWRDS36.UINT16[L/H]
FLXA0.FRWRDS36.UINT8[LL/LH/HL/HH]
FLXA0.FRWRDS37.UINT32
FLXA0.FRWRDS37.UINT16[L/H]
FLXA0.FRWRDS37.UINT8[LL/LH/HL/HH]
FLXA0.FRWRDS38.UINT32
FLXA0.FRWRDS38.UINT16[L/H]
FLXA0.FRWRDS38.UINT8[LL/LH/HL/HH]
FLXA0.FRWRDS39.UINT32
FLXA0.FRWRDS39.UINT16[L/H]
FLXA0.FRWRDS39.UINT8[LL/LH/HL/HH]
FLXA0.FRWRDS40.UINT32
FLXA0.FRWRDS40.UINT16[L/H]
FLXA0.FRWRDS40.UINT8[LL/LH/HL/HH]
FLXA0.FRWRDS41.UINT32
FLXA0.FRWRDS41.UINT16[L/H]
FLXA0.FRWRDS41.UINT8[LL/LH/HL/HH]
FLXA0.FRWRDS42.UINT32
FLXA0.FRWRDS42.UINT16[L/H]
FLXA0.FRWRDS42.UINT8[LL/LH/HL/HH]
FLXA0.FRWRDS43.UINT32
FLXA0.FRWRDS43.UINT16[L/H]
FLXA0.FRWRDS43.UINT8[LL/LH/HL/HH]
FLXA0.FRWRDS44.UINT32
FLXA0.FRWRDS44.UINT16[L/H]
FLXA0.FRWRDS44.UINT8[LL/LH/HL/HH]
FLXA0.FRWRDS45.UINT32
FLXA0.FRWRDS45.UINT16[L/H]
FLXA0.FRWRDS45.UINT8[LL/LH/HL/HH]
FLXA0.FRWRDS46.UINT32
FLXA0.FRWRDS46.UINT16[L/H]
FLXA0.FRWRDS46.UINT8[LL/LH/HL/HH]
FLXA0.FRWRDS47.UINT32
FLXA0.FRWRDS47.UINT16[L/H]
FLXA0.FRWRDS47.UINT8[LL/LH/HL/HH]
FLXA0.FRWRDS48.UINT32
FLXA0.FRWRDS48.UINT16[L/H]
FLXA0.FRWRDS48.UINT8[LL/LH/HL/HH]
FLXA0.FRWRDS49.UINT32
FLXA0.FRWRDS49.UINT16[L/H]
FLXA0.FRWRDS49.UINT8[LL/LH/HL/HH]
FLXA0.FRWRDS50.UINT32
FLXA0.FRWRDS50.UINT16[L/H]
FLXA0.FRWRDS50.UINT8[LL/LH/HL/HH]
FLXA0.FRWRDS51.UINT32
FLXA0.FRWRDS51.UINT16[L/H]
FLXA0.FRWRDS51.UINT8[LL/LH/HL/HH]
FLXA0.FRWRDS52.UINT32
FLXA0.FRWRDS52.UINT16[L/H]
FLXA0.FRWRDS52.UINT8[LL/LH/HL/HH]
FLXA0.FRWRDS53.UINT32
FLXA0.FRWRDS53.UINT16[L/H]
FLXA0.FRWRDS53.UINT8[LL/LH/HL/HH]
FLXA0.FRWRDS54.UINT32
FLXA0.FRWRDS54.UINT16[L/H]
FLXA0.FRWRDS54.UINT8[LL/LH/HL/HH]
FLXA0.FRWRDS55.UINT32
FLXA0.FRWRDS55.UINT16[L/H]
FLXA0.FRWRDS55.UINT8[LL/LH/HL/HH]
FLXA0.FRWRDS56.UINT32
FLXA0.FRWRDS56.UINT16[L/H]
FLXA0.FRWRDS56.UINT8[LL/LH/HL/HH]
FLXA0.FRWRDS57.UINT32
FLXA0.FRWRDS57.UINT16[L/H]
FLXA0.FRWRDS57.UINT8[LL/LH/HL/HH]
FLXA0.FRWRDS58.UINT32
FLXA0.FRWRDS58.UINT16[L/H]
FLXA0.FRWRDS58.UINT8[LL/LH/HL/HH]
FLXA0.FRWRDS59.UINT32
FLXA0.FRWRDS59.UINT16[L/H]
FLXA0.FRWRDS59.UINT8[LL/LH/HL/HH]
FLXA0.FRWRDS60.UINT32
FLXA0.FRWRDS60.UINT16[L/H]
FLXA0.FRWRDS60.UINT8[LL/LH/HL/HH]
FLXA0.FRWRDS61.UINT32
FLXA0.FRWRDS61.UINT16[L/H]
FLXA0.FRWRDS61.UINT8[LL/LH/HL/HH]
FLXA0.FRWRDS62.UINT32
FLXA0.FRWRDS62.UINT16[L/H]
FLXA0.FRWRDS62.UINT8[LL/LH/HL/HH]
FLXA0.FRWRDS63.UINT32
FLXA0.FRWRDS63.UINT16[L/H]
FLXA0.FRWRDS63.UINT8[LL/LH/HL/HH]
FLXA0.FRWRDS64.UINT32
FLXA0.FRWRDS64.UINT16[L/H]
FLXA0.FRWRDS64.UINT8[LL/LH/HL/HH]
FLXA0.FRWRHS1.UINT32
FLXA0.FRWRHS1.UINT16[L/H]
FLXA0.FRWRHS1.UINT8[LL/LH/HL/HH]
FLXA0.FRWRHS2.UINT32
FLXA0.FRWRHS2.UINT16[L/H]
FLXA0.FRWRHS2.UINT8[LL/LH/HL]
FLXA0.FRWRHS3.UINT32
FLXA0.FRWRHS3.UINT16[L]
FLXA0.FRWRHS3.UINT8[LL/LH]
FLXA0.FRIBCM.UINT32
FLXA0.FRIBCM.UINT16[L/H]
FLXA0.FRIBCM.UINT8[LL/HL]
FLXA0.FRIBCR.UINT32
FLXA0.FRIBCR.UINT16[L/H]
FLXA0.FRIBCR.UINT8[LL/LH/HL/HH]
FLXA0.FRRDDS1.UINT32
FLXA0.FRRDDS1.UINT16[L/H]
FLXA0.FRRDDS1.UINT8[LL/LH/HL/HH]
FLXA0.FRRDDS2.UINT32
FLXA0.FRRDDS2.UINT16[L/H]
FLXA0.FRRDDS2.UINT8[LL/LH/HL/HH]
FLXA0.FRRDDS3.UINT32
FLXA0.FRRDDS3.UINT16[L/H]
FLXA0.FRRDDS3.UINT8[LL/LH/HL/HH]
FLXA0.FRRDDS4.UINT32
FLXA0.FRRDDS4.UINT16[L/H]
FLXA0.FRRDDS4.UINT8[LL/LH/HL/HH]
FLXA0.FRRDDS5.UINT32
FLXA0.FRRDDS5.UINT16[L/H]
FLXA0.FRRDDS5.UINT8[LL/LH/HL/HH]
FLXA0.FRRDDS6.UINT32
FLXA0.FRRDDS6.UINT16[L/H]
FLXA0.FRRDDS6.UINT8[LL/LH/HL/HH]
FLXA0.FRRDDS7.UINT32
FLXA0.FRRDDS7.UINT16[L/H]
FLXA0.FRRDDS7.UINT8[LL/LH/HL/HH]
FLXA0.FRRDDS8.UINT32
FLXA0.FRRDDS8.UINT16[L/H]
FLXA0.FRRDDS8.UINT8[LL/LH/HL/HH]
FLXA0.FRRDDS9.UINT32
FLXA0.FRRDDS9.UINT16[L/H]
FLXA0.FRRDDS9.UINT8[LL/LH/HL/HH]
FLXA0.FRRDDS10.UINT32
FLXA0.FRRDDS10.UINT16[L/H]
FLXA0.FRRDDS10.UINT8[LL/LH/HL/HH]
FLXA0.FRRDDS11.UINT32
FLXA0.FRRDDS11.UINT16[L/H]
FLXA0.FRRDDS11.UINT8[LL/LH/HL/HH]
FLXA0.FRRDDS12.UINT32
FLXA0.FRRDDS12.UINT16[L/H]
FLXA0.FRRDDS12.UINT8[LL/LH/HL/HH]
FLXA0.FRRDDS13.UINT32
FLXA0.FRRDDS13.UINT16[L/H]
FLXA0.FRRDDS13.UINT8[LL/LH/HL/HH]
FLXA0.FRRDDS14.UINT32
FLXA0.FRRDDS14.UINT16[L/H]
FLXA0.FRRDDS14.UINT8[LL/LH/HL/HH]
FLXA0.FRRDDS15.UINT32
FLXA0.FRRDDS15.UINT16[L/H]
FLXA0.FRRDDS15.UINT8[LL/LH/HL/HH]
FLXA0.FRRDDS16.UINT32
FLXA0.FRRDDS16.UINT16[L/H]
FLXA0.FRRDDS16.UINT8[LL/LH/HL/HH]
FLXA0.FRRDDS17.UINT32
FLXA0.FRRDDS17.UINT16[L/H]
FLXA0.FRRDDS17.UINT8[LL/LH/HL/HH]
FLXA0.FRRDDS18.UINT32
FLXA0.FRRDDS18.UINT16[L/H]
FLXA0.FRRDDS18.UINT8[LL/LH/HL/HH]
FLXA0.FRRDDS19.UINT32
FLXA0.FRRDDS19.UINT16[L/H]
FLXA0.FRRDDS19.UINT8[LL/LH/HL/HH]
FLXA0.FRRDDS20.UINT32
FLXA0.FRRDDS20.UINT16[L/H]
FLXA0.FRRDDS20.UINT8[LL/LH/HL/HH]
FLXA0.FRRDDS21.UINT32
FLXA0.FRRDDS21.UINT16[L/H]
FLXA0.FRRDDS21.UINT8[LL/LH/HL/HH]
FLXA0.FRRDDS22.UINT32
FLXA0.FRRDDS22.UINT16[L/H]
FLXA0.FRRDDS22.UINT8[LL/LH/HL/HH]
FLXA0.FRRDDS23.UINT32
FLXA0.FRRDDS23.UINT16[L/H]
FLXA0.FRRDDS23.UINT8[LL/LH/HL/HH]
FLXA0.FRRDDS24.UINT32
FLXA0.FRRDDS24.UINT16[L/H]
FLXA0.FRRDDS24.UINT8[LL/LH/HL/HH]
FLXA0.FRRDDS25.UINT32
FLXA0.FRRDDS25.UINT16[L/H]
FLXA0.FRRDDS25.UINT8[LL/LH/HL/HH]
FLXA0.FRRDDS26.UINT32
FLXA0.FRRDDS26.UINT16[L/H]
FLXA0.FRRDDS26.UINT8[LL/LH/HL/HH]
FLXA0.FRRDDS27.UINT32
FLXA0.FRRDDS27.UINT16[L/H]
FLXA0.FRRDDS27.UINT8[LL/LH/HL/HH]
FLXA0.FRRDDS28.UINT32
FLXA0.FRRDDS28.UINT16[L/H]
FLXA0.FRRDDS28.UINT8[LL/LH/HL/HH]
FLXA0.FRRDDS29.UINT32
FLXA0.FRRDDS29.UINT16[L/H]
FLXA0.FRRDDS29.UINT8[LL/LH/HL/HH]
FLXA0.FRRDDS30.UINT32
FLXA0.FRRDDS30.UINT16[L/H]
FLXA0.FRRDDS30.UINT8[LL/LH/HL/HH]
FLXA0.FRRDDS31.UINT32
FLXA0.FRRDDS31.UINT16[L/H]
FLXA0.FRRDDS31.UINT8[LL/LH/HL/HH]
FLXA0.FRRDDS32.UINT32
FLXA0.FRRDDS32.UINT16[L/H]
FLXA0.FRRDDS32.UINT8[LL/LH/HL/HH]
FLXA0.FRRDDS33.UINT32
FLXA0.FRRDDS33.UINT16[L/H]
FLXA0.FRRDDS33.UINT8[LL/LH/HL/HH]
FLXA0.FRRDDS34.UINT32
FLXA0.FRRDDS34.UINT16[L/H]
FLXA0.FRRDDS34.UINT8[LL/LH/HL/HH]
FLXA0.FRRDDS35.UINT32
FLXA0.FRRDDS35.UINT16[L/H]
FLXA0.FRRDDS35.UINT8[LL/LH/HL/HH]
FLXA0.FRRDDS36.UINT32
FLXA0.FRRDDS36.UINT16[L/H]
FLXA0.FRRDDS36.UINT8[LL/LH/HL/HH]
FLXA0.FRRDDS37.UINT32
FLXA0.FRRDDS37.UINT16[L/H]
FLXA0.FRRDDS37.UINT8[LL/LH/HL/HH]
FLXA0.FRRDDS38.UINT32
FLXA0.FRRDDS38.UINT16[L/H]
FLXA0.FRRDDS38.UINT8[LL/LH/HL/HH]
FLXA0.FRRDDS39.UINT32
FLXA0.FRRDDS39.UINT16[L/H]
FLXA0.FRRDDS39.UINT8[LL/LH/HL/HH]
FLXA0.FRRDDS40.UINT32
FLXA0.FRRDDS40.UINT16[L/H]
FLXA0.FRRDDS40.UINT8[LL/LH/HL/HH]
FLXA0.FRRDDS41.UINT32
FLXA0.FRRDDS41.UINT16[L/H]
FLXA0.FRRDDS41.UINT8[LL/LH/HL/HH]
FLXA0.FRRDDS42.UINT32
FLXA0.FRRDDS42.UINT16[L/H]
FLXA0.FRRDDS42.UINT8[LL/LH/HL/HH]
FLXA0.FRRDDS43.UINT32
FLXA0.FRRDDS43.UINT16[L/H]
FLXA0.FRRDDS43.UINT8[LL/LH/HL/HH]
FLXA0.FRRDDS44.UINT32
FLXA0.FRRDDS44.UINT16[L/H]
FLXA0.FRRDDS44.UINT8[LL/LH/HL/HH]
FLXA0.FRRDDS45.UINT32
FLXA0.FRRDDS45.UINT16[L/H]
FLXA0.FRRDDS45.UINT8[LL/LH/HL/HH]
FLXA0.FRRDDS46.UINT32
FLXA0.FRRDDS46.UINT16[L/H]
FLXA0.FRRDDS46.UINT8[LL/LH/HL/HH]
FLXA0.FRRDDS47.UINT32
FLXA0.FRRDDS47.UINT16[L/H]
FLXA0.FRRDDS47.UINT8[LL/LH/HL/HH]
FLXA0.FRRDDS48.UINT32
FLXA0.FRRDDS48.UINT16[L/H]
FLXA0.FRRDDS48.UINT8[LL/LH/HL/HH]
FLXA0.FRRDDS49.UINT32
FLXA0.FRRDDS49.UINT16[L/H]
FLXA0.FRRDDS49.UINT8[LL/LH/HL/HH]
FLXA0.FRRDDS50.UINT32
FLXA0.FRRDDS50.UINT16[L/H]
FLXA0.FRRDDS50.UINT8[LL/LH/HL/HH]
FLXA0.FRRDDS51.UINT32
FLXA0.FRRDDS51.UINT16[L/H]
FLXA0.FRRDDS51.UINT8[LL/LH/HL/HH]
FLXA0.FRRDDS52.UINT32
FLXA0.FRRDDS52.UINT16[L/H]
FLXA0.FRRDDS52.UINT8[LL/LH/HL/HH]
FLXA0.FRRDDS53.UINT32
FLXA0.FRRDDS53.UINT16[L/H]
FLXA0.FRRDDS53.UINT8[LL/LH/HL/HH]
FLXA0.FRRDDS54.UINT32
FLXA0.FRRDDS54.UINT16[L/H]
FLXA0.FRRDDS54.UINT8[LL/LH/HL/HH]
FLXA0.FRRDDS55.UINT32
FLXA0.FRRDDS55.UINT16[L/H]
FLXA0.FRRDDS55.UINT8[LL/LH/HL/HH]
FLXA0.FRRDDS56.UINT32
FLXA0.FRRDDS56.UINT16[L/H]
FLXA0.FRRDDS56.UINT8[LL/LH/HL/HH]
FLXA0.FRRDDS57.UINT32
FLXA0.FRRDDS57.UINT16[L/H]
FLXA0.FRRDDS57.UINT8[LL/LH/HL/HH]
FLXA0.FRRDDS58.UINT32
FLXA0.FRRDDS58.UINT16[L/H]
FLXA0.FRRDDS58.UINT8[LL/LH/HL/HH]
FLXA0.FRRDDS59.UINT32
FLXA0.FRRDDS59.UINT16[L/H]
FLXA0.FRRDDS59.UINT8[LL/LH/HL/HH]
FLXA0.FRRDDS60.UINT32
FLXA0.FRRDDS60.UINT16[L/H]
FLXA0.FRRDDS60.UINT8[LL/LH/HL/HH]
FLXA0.FRRDDS61.UINT32
FLXA0.FRRDDS61.UINT16[L/H]
FLXA0.FRRDDS61.UINT8[LL/LH/HL/HH]
FLXA0.FRRDDS62.UINT32
FLXA0.FRRDDS62.UINT16[L/H]
FLXA0.FRRDDS62.UINT8[LL/LH/HL/HH]
FLXA0.FRRDDS63.UINT32
FLXA0.FRRDDS63.UINT16[L/H]
FLXA0.FRRDDS63.UINT8[LL/LH/HL/HH]
FLXA0.FRRDDS64.UINT32
FLXA0.FRRDDS64.UINT16[L/H]
FLXA0.FRRDDS64.UINT8[LL/LH/HL/HH]
FLXA0.FRRDHS1.UINT32
FLXA0.FRRDHS1.UINT16[L/H]
FLXA0.FRRDHS1.UINT8[LL/LH/HL/HH]
FLXA0.FRRDHS2.UINT32
FLXA0.FRRDHS2.UINT16[L/H]
FLXA0.FRRDHS2.UINT8[LL/LH/HL/HH]
FLXA0.FRRDHS3.UINT32
FLXA0.FRRDHS3.UINT16[L/H]
FLXA0.FRRDHS3.UINT8[LL/LH/HL/HH]
FLXA0.FRMBS.UINT32
FLXA0.FRMBS.UINT16[L/H]
FLXA0.FRMBS.UINT8[LL/LH/HL/HH]
FLXA0.FROBCM.UINT32
FLXA0.FROBCM.UINT16[L/H]
FLXA0.FROBCM.UINT8[LL/HL]
FLXA0.FROBCR.UINT32
FLXA0.FROBCR.UINT16[L/H]
FLXA0.FROBCR.UINT8[LL/LH/HL]
FLXA0.FRITC.UINT32
FLXA0.FRITC.UINT16[L/H]
FLXA0.FRITC.UINT8[LL/LH/HL]
FLXA0.FROTC.UINT32
FLXA0.FROTC.UINT16[L/H]
FLXA0.FROTC.UINT8[LL/LH/HL]
FLXA0.FRIBA.UINT32
FLXA0.FRIBA.UINT16[L/H]
FLXA0.FRIBA.UINT8[LL/LH/HL/HH]
FLXA0.FRFBA.UINT32
FLXA0.FRFBA.UINT16[L/H]
FLXA0.FRFBA.UINT8[LL/LH/HL/HH]
FLXA0.FROBA.UINT32
FLXA0.FROBA.UINT16[L/H]
FLXA0.FROBA.UINT8[LL/LH/HL/HH]
FLXA0.FRIQC.UINT32
FLXA0.FRIQC.UINT16[L]
FLXA0.FRIQC.UINT8[LL]
FLXA0.FRUIR.UINT32
FLXA0.FRUIR.UINT16[L]
FLXA0.FRUIR.UINT8[LL]
FLXA0.FRUOR.UINT32
FLXA0.FRUOR.UINT16[L]
FLXA0.FRUOR.UINT8[LL/LH]
FLXA0.FRITS.UINT32
FLXA0.FRITS.UINT16[L/H]
FLXA0.FRITS.UINT8[LL/LH/HL/HH]
FLXA0.FROTS.UINT32
FLXA0.FROTS.UINT16[L/H]
FLXA0.FROTS.UINT8[LL/LH/HL/HH]
FLXA0.FRAES.UINT32
FLXA0.FRAES.UINT16[L]
FLXA0.FRAES.UINT8[LL/LH]
FLXA0.FRAEA.UINT32
FLXA0.FRAEA.UINT16[L/H]
FLXA0.FRAEA.UINT8[LL/LH/HL/HH]
FLXA0.FRDA0.UINT32
FLXA0.FRDA0.UINT16[L/H]
FLXA0.FRDA0.UINT8[LL/LH/HL/HH]
FLXA0.FRDA1.UINT32
FLXA0.FRDA1.UINT16[L/H]
FLXA0.FRDA1.UINT8[LL/LH/HL/HH]
FLXA0.FRDA2.UINT32
FLXA0.FRDA2.UINT16[L/H]
FLXA0.FRDA2.UINT8[LL/LH/HL/HH]
FLXA0.FRDA3.UINT32
FLXA0.FRDA3.UINT16[L/H]
FLXA0.FRDA3.UINT8[LL/LH/HL/HH]
FLXA0.FRT2C.UINT32
FLXA0.FRT2C.UINT16[L/H]
FLXA0.FRT2C.UINT8[LL/LH/HL/HH]
ETNA0.EDSR0
ETNA0.TDLAR0
ETNA0.TDFAR0
ETNA0.TDFXR0
ETNA0.TDFFR0
ETNA0.RDLAR0
ETNA0.RDFAR0
ETNA0.RDFXR0
ETNA0.RDFFR0
ETNA0.EDMR0
ETNA0.EDTRR0
ETNA0.EDRRR0
ETNA0.EESR0
ETNA0.EESIPR0
ETNA0.TRSCER0
ETNA0.RMFCR0
ETNA0.FDR0
ETNA0.RMCR0
ETNA0.RPADIR0
ETNA0.FCFTR0
ETNA0.TFSR0
ETNA0.RFSR0
ETNA0.ECMR0
ETNA0.RFLR0
ETNA0.ECSR0
ETNA0.ECSIPR0
ETNA0.PIR0
ETNA0.PLSR0
ETNA0.PIPR0
ETNA0.APR0
ETNA0.MPR0
ETNA0.PFTCR0
ETNA0.PFRCR0
ETNA0.TPAUSER0
ETNA0.TPFRCR0
ETNA0.BCFRR0
ETNA0.CRBCFRR0
ETNA0.EMR0
ETNA0.MAHR0
ETNA0.MALR0
ETNA0.TROCR0
ETNA0.CDCR0
ETNA0.LCCR0
ETNA0.CEFCR0
ETNA0.FRECR0
ETNA0.TSFRCR0
ETNA0.TLFRCR0
ETNA0.RFCR0
ETNA0.MAFCR0
ETNA0.ARSTR
ETNA0.TSU_CTRST
ETNA0.TSU_FWSL0
ETNA0.TSU_FWSL1
ETNA0.TSU_FWSLC
ETNA0.TSU_FWSR
ETNA0.TSU_FWINMK
ETNA0.TSU_VTAG0
ETNA0.TSU_VTAG1
ETNA0.TSU_ADSBSY
ETNA0.TSU_TEN
ETNA0.TSU_POST1 ... ETNA0.TSU_POST4
ETNA0.TXNLCR0
ETNA0.TXALCR0
ETNA0.RXNLCR0
ETNA0.RXALCR0
ETNA0.TXNLCR1
ETNA0.TXALCR1
ETNA0.RXNLCR1
ETNA0.RXALCR1
ETNA0.TSU_ADRH0
ETNA0.TSU_ADRL0
ETNA0.TSU_ADRH1
ETNA0.TSU_ADRL1
ETNA0.TSU_ADRH2
ETNA0.TSU_ADRL2
ETNA0.TSU_ADRH3
ETNA0.TSU_ADRL3
ETNA0.TSU_ADRH4
ETNA0.TSU_ADRL4
ETNA0.TSU_ADRH5
ETNA0.TSU_ADRL5
ETNA0.TSU_ADRH6
ETNA0.TSU_ADRL6
ETNA0.TSU_ADRH7
ETNA0.TSU_ADRL7
ETNA0.TSU_ADRH8
ETNA0.TSU_ADRL8
ETNA0.TSU_ADRH9
ETNA0.TSU_ADRL9
ETNA0.TSU_ADRH10
ETNA0.TSU_ADRL10
ETNA0.TSU_ADRH11
ETNA0.TSU_ADRL11
ETNA0.TSU_ADRH12
ETNA0.TSU_ADRL12
ETNA0.TSU_ADRH13
ETNA0.TSU_ADRL13
ETNA0.TSU_ADRH14
ETNA0.TSU_ADRL14
ETNA0.TSU_ADRH15
ETNA0.TSU_ADRL15
ETNA0.TSU_ADRH16
ETNA0.TSU_ADRL16
ETNA0.TSU_ADRH17
ETNA0.TSU_ADRL17
ETNA0.TSU_ADRH18
ETNA0.TSU_ADRL18
ETNA0.TSU_ADRH19
ETNA0.TSU_ADRL19
ETNA0.TSU_ADRH20
ETNA0.TSU_ADRL20
ETNA0.TSU_ADRH21
ETNA0.TSU_ADRL21
ETNA0.TSU_ADRH22
ETNA0.TSU_ADRL22
ETNA0.TSU_ADRH23
ETNA0.TSU_ADRL23
ETNA0.TSU_ADRH24
ETNA0.TSU_ADRL24
ETNA0.TSU_ADRH25
ETNA0.TSU_ADRL25
ETNA0.TSU_ADRH26
ETNA0.TSU_ADRL26
ETNA0.TSU_ADRH27
ETNA0.TSU_ADRL27
ETNA0.TSU_ADRH28
ETNA0.TSU_ADRL28
ETNA0.TSU_ADRH29
ETNA0.TSU_ADRL29
ETNA0.TSU_ADRH30
ETNA0.TSU_ADRL30
ETNA0.TSU_ADRH31
ETNA0.TSU_ADRL31
ETNA0.HDMMDR0
ETNA0.HDMISR0
ETNA0.HDMIER0
ICUID
ICUVER
ICU2PES
ICU2PESL
ICU2PESLL
ICU2PESLH
ICU2PESH
ICU2PESHL
ICU2PESHH
PE2ICUS
PE2ICUSL
PE2ICUSLL
PE2ICUSLH
PE2ICUSH
PE2ICUSHL
PE2ICUSHH
ICUMACTFLAG
ICUMACTFLAGL
ICUMACTFLAGLL
PEFLPRG0REQ
PEFLPRG0REQL
PEFLPRG0REQLL
PEFLPRG1REQ
PEFLPRG1REQL
PEFLPRG1REQLL
PEFLPRG0AC
PEFLPRG0ACL
PEFLPRG0ACLL
PEFLPRG1AC
PEFLPRG1ACL
PEFLPRG1ACLL
PE2ICUF
PE2ICUFL
PE2ICUFLL
PE2ICUFLH
PE2ICUFH
PE2ICUFHL
PE2ICUFHH
PE2ICUFS
PE2ICUFSL
PE2ICUFSLL
PE2ICUFSLH
PE2ICUFSH
PE2ICUFSHL
PE2ICUFSHH
PE2ICUFC
PE2ICUFCL
PE2ICUFCLL
PE2ICUFCLH
PE2ICUFCH
PE2ICUFCHL
PE2ICUFCHH
PE2ICUIE
PE2ICUIEL
PE2ICUIELL
PE2ICUIELH
PE2ICUIEH
PE2ICUIEHL
PE2ICUIEHH
ICU2PEF
ICU2PEFL
ICU2PEFLL
ICU2PEFLH
ICU2PEFH
ICU2PEFHL
ICU2PEFHH
ICU2PEFS
ICU2PEFSL
ICU2PEFSLL
ICU2PEFSLH
ICU2PEFSH
ICU2PEFSHL
ICU2PEFSHH
ICU2PEFC
ICU2PEFCL
ICU2PEFCLL
ICU2PEFCLH
ICU2PEFCH
ICU2PEFCHL
ICU2PEFCHH
ICU2PEIE
ICU2PEIEL
ICU2PEIELL
ICU2PEIELH
ICU2PEIEH
ICU2PEIEHL
ICU2PEIEHH
ICU2PEIS
ICU2PEISL
ICU2PEISLL
SELFID0 ... SELFID7
CFRDID0 ... CFRDID7
DFRDID0 ... DFRDID7
CFPEID0 ... CFPEID7
DFPEID0 ... DFPEID7
DEGEMU
SELSECLOCK
IDSTATUS
P0
PSR0
PNOT0
PPR0
PM0
PMC0
PFC0
PFCE0
PMSR0
PMCSR0
PINV0
P1
PSR1
PNOT1
PPR1
PM1
PMC1
PFC1
PFCE1
PMSR1
PMCSR1
PINV1
P2
PSR2
PNOT2
PPR2
PM2
PMC2
PFC2
PFCE2
PMSR2
PMCSR2
PINV2
P3
PSR3
PNOT3
PPR3
PM3
PMC3
PFC3
PFCE3
PMSR3
PMCSR3
PINV3
P4
PSR4
PNOT4
PPR4
PM4
PMC4
PFC4
PFCE4
PMSR4
PMCSR4
PINV4
P5
PSR5
PNOT5
PPR5
PM5
PMC5
PFC5
PFCE5
PMSR5
PMCSR5
PINV5
P6
PSR6
PNOT6
PPR6
PM6
PMC6
PFC6
PFCE6
PMSR6
PMCSR6
PINV6
P7
PSR7
PNOT7
PPR7
PM7
PMC7
PFC7
PFCE7
PMSR7
PMCSR7
PINV7
P8
PSR8
PNOT8
PPR8
PM8
PMC8
PFC8
PFCE8
PMSR8
PMCSR8
PINV8
P9
PSR9
PNOT9
PPR9
PM9
PMC9
PFC9
PFCE9
PMSR9
PMCSR9
PINV9
PCR0_0 ... PCR0_10
PCR0_13
PCR0_14
PCR1_1 ... PCR1_7
PCR2_0 ... PCR2_15
PCR3_0 ... PCR3_14
PCR4_0 ... PCR4_14
PCR5_0
PCR5_1
PCR5_4 ... PCR5_15
PCR6_0 ... PCR6_15
PCR7_0 ... PCR7_9
PCR8_0 ... PCR8_15
PCR9_0 ... PCR9_8
PIBC0
PBDC0
PIPC0
PU0
PD0
PODC0
PDSC0
PIS0
PUCC0
PODCE0
PIBC1
PBDC1
PIPC1
PU1
PD1
PODC1
PDSC1
PIS1
PUCC1
PODCE1
PIBC2
PBDC2
PIPC2
PU2
PD2
PODC2
PDSC2
PIS2
PUCC2
PODCE2
PIBC3
PBDC3
PIPC3
PU3
PD3
PODC3
PDSC3
PIS3
PUCC3
PODCE3
PIBC4
PBDC4
PIPC4
PU4
PD4
PODC4
PDSC4
PIS4
PUCC4
PODCE4
PIBC5
PBDC5
PIPC5
PU5
PD5
PODC5
PDSC5
PIS5
PUCC5
PODCE5
PIBC6
PBDC6
PIPC6
PU6
PD6
PODC6
PDSC6
PIS6
PUCC6
PODCE6
PIBC7
PBDC7
PIPC7
PU7
PD7
PODC7
PDSC7
PIS7
PUCC7
PODCE7
PIBC8
PBDC8
PIPC8
PU8
PD8
PODC8
PDSC8
PIS8
PUCC8
PODCE8
PIBC9
PBDC9
PIPC9
PU9
PD9
PODC9
PDSC9
PIS9
PUCC9
PODCE9
JP0
JPSR0
JPNOT0
JPPR0
JPM0
JPMC0
JPFCE0
JPMSR0
JPMCSR0
JPINV0
JPCR0_0 ... JPCR0_5
JPIBC0
JPBDC0
JPU0
JPD0
JPODC0
JPDSC0
JPIS0
JPUCC0
JPODCE0
MGDCFCTL_VCI2CFB
MGDCFCTL_VCI2CFBL
MGDCFCTL_VCI2CFBLL
MGDCFSTAT_VCI2CFB
MGDCFSTAT_VCI2CFBL
MGDCFSTAT_VCI2CFBLL
MGDCFTYPE_VCI2CFB
MGDCFTYPE_VCI2CFBL
MGDCFTYPE_VCI2CFBLL
MGDCFTYPE_VCI2CFBLH
MGDCFTYPE_VCI2CFBH
MGDCFTYPE_VCI2CFBHL
MGDCFTYPE_VCI2CFBHH
MGDCFCTL_PE1
MGDCFCTL_PE1L
MGDCFCTL_PE1LL
MGDCFSTAT_PE1
MGDCFSTAT_PE1L
MGDCFSTAT_PE1LL
MGDCFTYPE_PE1
MGDCFTYPE_PE1L
MGDCFTYPE_PE1LL
MGDCFTYPE_PE1LH
MGDCFTYPE_PE1H
MGDCFTYPE_PE1HL
MGDCFTYPE_PE1HH
MGDGRPROT0
MGDGRPROT0L
MGDGRPROT0LL
MGDGRPROT0LH
MGDGRPROT0H
MGDGRPROT0HL
MGDGRPROT0HH
MGDGRSPID0
MGDGRBAD0
MGDGRBAD0L
MGDGRBAD0LL
MGDGRBAD0LH
MGDGRBAD0H
MGDGRBAD0HL
MGDGRBAD0HH
MGDGRADV0
MGDGRADV0L
MGDGRADV0LL
MGDGRADV0LH
MGDGRADV0H
MGDGRADV0HL
MGDGRADV0HH
MGDGRPROT1
MGDGRPROT1L
MGDGRPROT1LL
MGDGRPROT1LH
MGDGRPROT1H
MGDGRPROT1HL
MGDGRPROT1HH
MGDGRSPID1
MGDGRBAD1
MGDGRBAD1L
MGDGRBAD1LL
MGDGRBAD1LH
MGDGRBAD1H
MGDGRBAD1HL
MGDGRBAD1HH
MGDGRADV1
MGDGRADV1L
MGDGRADV1LL
MGDGRADV1LH
MGDGRADV1H
MGDGRADV1HL
MGDGRADV1HH
MGDGRPROT2
MGDGRPROT2L
MGDGRPROT2LL
MGDGRPROT2LH
MGDGRPROT2H
MGDGRPROT2HL
MGDGRPROT2HH
MGDGRSPID2
MGDGRBAD2
MGDGRBAD2L
MGDGRBAD2LL
MGDGRBAD2LH
MGDGRBAD2H
MGDGRBAD2HL
MGDGRBAD2HH
MGDGRADV2
MGDGRADV2L
MGDGRADV2LL
MGDGRADV2LH
MGDGRADV2H
MGDGRADV2HL
MGDGRADV2HH
MGDGRPROT3
MGDGRPROT3L
MGDGRPROT3LL
MGDGRPROT3LH
MGDGRPROT3H
MGDGRPROT3HL
MGDGRPROT3HH
MGDGRSPID3
MGDGRBAD3
MGDGRBAD3L
MGDGRBAD3LL
MGDGRBAD3LH
MGDGRBAD3H
MGDGRBAD3HL
MGDGRBAD3HH
MGDGRADV3
MGDGRADV3L
MGDGRADV3LL
MGDGRADV3LH
MGDGRADV3H
MGDGRADV3HL
MGDGRADV3HH
MGDGRPROT4
MGDGRPROT4L
MGDGRPROT4LL
MGDGRPROT4LH
MGDGRPROT4H
MGDGRPROT4HL
MGDGRPROT4HH
MGDGRSPID4
MGDGRBAD4
MGDGRBAD4L
MGDGRBAD4LL
MGDGRBAD4LH
MGDGRBAD4H
MGDGRBAD4HL
MGDGRBAD4HH
MGDGRADV4
MGDGRADV4L
MGDGRADV4LL
MGDGRADV4LH
MGDGRADV4H
MGDGRADV4HL
MGDGRADV4HH
MGDGRPROT5
MGDGRPROT5L
MGDGRPROT5LL
MGDGRPROT5LH
MGDGRPROT5H
MGDGRPROT5HL
MGDGRPROT5HH
MGDGRSPID5
MGDGRBAD5
MGDGRBAD5L
MGDGRBAD5LL
MGDGRBAD5LH
MGDGRBAD5H
MGDGRBAD5HL
MGDGRBAD5HH
MGDGRADV5
MGDGRADV5L
MGDGRADV5LL
MGDGRADV5LH
MGDGRADV5H
MGDGRADV5HL
MGDGRADV5HH
MGDGRPROT6
MGDGRPROT6L
MGDGRPROT6LL
MGDGRPROT6LH
MGDGRPROT6H
MGDGRPROT6HL
MGDGRPROT6HH
MGDGRSPID6
MGDGRBAD6
MGDGRBAD6L
MGDGRBAD6LL
MGDGRBAD6LH
MGDGRBAD6H
MGDGRBAD6HL
MGDGRBAD6HH
MGDGRADV6
MGDGRADV6L
MGDGRADV6LL
MGDGRADV6LH
MGDGRADV6H
MGDGRADV6HL
MGDGRADV6HH
MGDGRPROT7
MGDGRPROT7L
MGDGRPROT7LL
MGDGRPROT7LH
MGDGRPROT7H
MGDGRPROT7HL
MGDGRPROT7HH
MGDGRSPID7
MGDGRBAD7
MGDGRBAD7L
MGDGRBAD7LL
MGDGRBAD7LH
MGDGRBAD7H
MGDGRBAD7HL
MGDGRBAD7HH
MGDGRADV7
MGDGRADV7L
MGDGRADV7LL
MGDGRADV7LH
MGDGRADV7H
MGDGRADV7HL
MGDGRADV7HH
MGDGRSCTL_VCI2GRAM
MGDGRSSTAT_VCI2GRAM
MGDGRSTYPE_VCI2GRAM
MGDGRSTYPE_VCI2GRAML
MGDGRSTYPE_VCI2GRAMLL
MGDGRSTYPE_VCI2GRAMLH
MGDGRSTYPE_VCI2GRAMH
MGDGRSTYPE_VCI2GRAMHL
MGDGRSTYPE_VCI2GRAMHH
MGDGRSCTL_PE1
MGDGRSSTAT_PE1
MGDGRSTYPE_PE1
MGDGRSTYPE_PE1L
MGDGRSTYPE_PE1LL
MGDGRSTYPE_PE1LH
MGDGRSTYPE_PE1H
MGDGRSTYPE_PE1HL
MGDGRSTYPE_PE1HH
MGDGRSCTL_AXI2GRAM
MGDGRSSTAT_AXI2GRAM
MGDGRSTYPE_AXI2GRAM
MGDGRSTYPE_AXI2GRAML
MGDGRSTYPE_AXI2GRAMLL
MGDGRSTYPE_AXI2GRAMLH
MGDGRSTYPE_AXI2GRAMH
MGDGRSTYPE_AXI2GRAMHL
MGDGRSTYPE_AXI2GRAMHH
PGERRSTATCTL_PE1
PGERRSTAT_PE1
PGERRINFO_PE1
PGERRSTATCTL_PE2
PGERRSTAT_PE2
PGERRINFO_PE2
APBFSGDPROT_PDMACM_A
APBFSGDPROT_PDMACM_AL
APBFSGDPROT_PDMACM_ALL
APBFSGDPROT_PDMACM_ALH
APBFSGDPROT_PDMACM_AH
APBFSGDPROT_PDMACM_AHL
APBFSGDPROT_PDMACM_AHH
APBFSGDSPID_PDMACM_A
APBFSGDSPID_PDMACM_AL
APBFSGDSPID_PDMACM_ALL
APBFSGDSPID_PDMACM_ALH
APBFSGDSPID_PDMACM_AH
APBFSGDSPID_PDMACM_AHL
APBFSGDSPID_PDMACM_AHH
APBFSGDPROT_PDMACM_B
APBFSGDPROT_PDMACM_BL
APBFSGDPROT_PDMACM_BLL
APBFSGDPROT_PDMACM_BLH
APBFSGDPROT_PDMACM_BH
APBFSGDPROT_PDMACM_BHL
APBFSGDPROT_PDMACM_BHH
APBFSGDSPID_PDMACM_B
APBFSGDSPID_PDMACM_BL
APBFSGDSPID_PDMACM_BLL
APBFSGDSPID_PDMACM_BLH
APBFSGDSPID_PDMACM_BH
APBFSGDSPID_PDMACM_BHL
APBFSGDSPID_PDMACM_BHH
APBFSGDPROT_PDMACH_A
APBFSGDPROT_PDMACH_AL
APBFSGDPROT_PDMACH_ALL
APBFSGDPROT_PDMACH_ALH
APBFSGDPROT_PDMACH_AH
APBFSGDPROT_PDMACH_AHL
APBFSGDPROT_PDMACH_AHH
APBFSGDSPID_PDMACH_A
APBFSGDSPID_PDMACH_AL
APBFSGDSPID_PDMACH_ALL
APBFSGDSPID_PDMACH_ALH
APBFSGDSPID_PDMACH_AH
APBFSGDSPID_PDMACH_AHL
APBFSGDSPID_PDMACH_AHH
APBFSGDPROT_PDMACH_B
APBFSGDPROT_PDMACH_BL
APBFSGDPROT_PDMACH_BLL
APBFSGDPROT_PDMACH_BLH
APBFSGDPROT_PDMACH_BH
APBFSGDPROT_PDMACH_BHL
APBFSGDPROT_PDMACH_BHH
APBFSGDSPID_PDMACH_B
APBFSGDSPID_PDMACH_BL
APBFSGDSPID_PDMACH_BLL
APBFSGDSPID_PDMACH_BLH
APBFSGDSPID_PDMACH_BH
APBFSGDSPID_PDMACH_BHL
APBFSGDSPID_PDMACH_BHH
APBFSGDPROT_INTC2_A
APBFSGDPROT_INTC2_AL
APBFSGDPROT_INTC2_ALL
APBFSGDPROT_INTC2_ALH
APBFSGDPROT_INTC2_AH
APBFSGDPROT_INTC2_AHL
APBFSGDPROT_INTC2_AHH
APBFSGDSPID_INTC2_A
APBFSGDSPID_INTC2_AL
APBFSGDSPID_INTC2_ALL
APBFSGDSPID_INTC2_ALH
APBFSGDSPID_INTC2_AH
APBFSGDSPID_INTC2_AHL
APBFSGDSPID_INTC2_AHH
APBFSGDPROT_INTC2_B
APBFSGDPROT_INTC2_BL
APBFSGDPROT_INTC2_BLL
APBFSGDPROT_INTC2_BLH
APBFSGDPROT_INTC2_BH
APBFSGDPROT_INTC2_BHL
APBFSGDPROT_INTC2_BHH
APBFSGDSPID_INTC2_B
APBFSGDSPID_INTC2_BL
APBFSGDSPID_INTC2_BLL
APBFSGDSPID_INTC2_BLH
APBFSGDSPID_INTC2_BH
APBFSGDSPID_INTC2_BHL
APBFSGDSPID_INTC2_BHH
APBFSGDPROT_PBG_A
APBFSGDPROT_PBG_AL
APBFSGDPROT_PBG_ALL
APBFSGDPROT_PBG_ALH
APBFSGDPROT_PBG_AH
APBFSGDPROT_PBG_AHL
APBFSGDPROT_PBG_AHH
APBFSGDSPID_PBG_A
APBFSGDSPID_PBG_AL
APBFSGDSPID_PBG_ALL
APBFSGDSPID_PBG_ALH
APBFSGDSPID_PBG_AH
APBFSGDSPID_PBG_AHL
APBFSGDSPID_PBG_AHH
APBFSGDPROT_PBG_B
APBFSGDPROT_PBG_BL
APBFSGDPROT_PBG_BLL
APBFSGDPROT_PBG_BLH
APBFSGDPROT_PBG_BH
APBFSGDPROT_PBG_BHL
APBFSGDPROT_PBG_BHH
APBFSGDSPID_PBG_B
APBFSGDSPID_PBG_BL
APBFSGDSPID_PBG_BLL
APBFSGDSPID_PBG_BLH
APBFSGDSPID_PBG_BH
APBFSGDSPID_PBG_BHL
APBFSGDSPID_PBG_BHH
APBFSGDPROT_SP1_A
APBFSGDPROT_SP1_AL
APBFSGDPROT_SP1_ALL
APBFSGDPROT_SP1_ALH
APBFSGDPROT_SP1_AH
APBFSGDPROT_SP1_AHL
APBFSGDPROT_SP1_AHH
APBFSGDSPID_SP1_A
APBFSGDSPID_SP1_AL
APBFSGDSPID_SP1_ALL
APBFSGDSPID_SP1_ALH
APBFSGDSPID_SP1_AH
APBFSGDSPID_SP1_AHL
APBFSGDSPID_SP1_AHH
APBFSGDPROT_SP1_B
APBFSGDPROT_SP1_BL
APBFSGDPROT_SP1_BLL
APBFSGDPROT_SP1_BLH
APBFSGDPROT_SP1_BH
APBFSGDPROT_SP1_BHL
APBFSGDPROT_SP1_BHH
APBFSGDSPID_SP1_B
APBFSGDSPID_SP1_BL
APBFSGDSPID_SP1_BLL
APBFSGDSPID_SP1_BLH
APBFSGDSPID_SP1_BH
APBFSGDSPID_SP1_BHL
APBFSGDSPID_SP1_BHH
APBFSGDPROT_SP4_A
APBFSGDPROT_SP4_AL
APBFSGDPROT_SP4_ALL
APBFSGDPROT_SP4_ALH
APBFSGDPROT_SP4_AH
APBFSGDPROT_SP4_AHL
APBFSGDPROT_SP4_AHH
APBFSGDSPID_SP4_A
APBFSGDSPID_SP4_AL
APBFSGDSPID_SP4_ALL
APBFSGDSPID_SP4_ALH
APBFSGDSPID_SP4_AH
APBFSGDSPID_SP4_AHL
APBFSGDSPID_SP4_AHH
APBFSGDPROT_SP4_B
APBFSGDPROT_SP4_BL
APBFSGDPROT_SP4_BLL
APBFSGDPROT_SP4_BLH
APBFSGDPROT_SP4_BH
APBFSGDPROT_SP4_BHL
APBFSGDPROT_SP4_BHH
APBFSGDSPID_SP4_B
APBFSGDSPID_SP4_BL
APBFSGDSPID_SP4_BLL
APBFSGDSPID_SP4_BLH
APBFSGDSPID_SP4_BH
APBFSGDSPID_SP4_BHL
APBFSGDSPID_SP4_BHH
ERRSLVCTL_PFSS0
ERRSLVSTAT_PFSS0
ERRSLVTYPE_PFSS0
ERRSLVCTL_PFSS1
ERRSLVSTAT_PFSS1
ERRSLVTYPE_PFSS1
ERRSLVCTL_PBAREA
ERRSLVCTL_PBAREAL
ERRSLVCTL_PBAREALL
ERRSLVSTAT_PBAREA
ERRSLVSTAT_PBAREAL
ERRSLVSTAT_PBAREALL
ERRSLVTYPE_PBAREA
ERRSLVTYPE_PBAREAL
ERRSLVTYPE_PBAREAH
PDMA_COMP_CNTRL
BOOTCTRL
BOOTCTRLL
BOOTCTRLLL
EPC
FCUFAREA
EEPRDCYCL0
EEPRDCYCL1
DFECCCTL0
DFECCCTL0L
DFERSTR0
DFERSTC0
DFERSTC0L
DFERSTC0LL
DFOVFSTR0
DFOVFSTC0
DFOVFSTC0L
DFOVFSTC0LL
DFERRINT0
DFERRINT0L
DFERRINT0LL
DFEADR0
DFTSTCTL0
DFTSTCTL0L
DFECCCTL1
DFECCCTL1L
DFERSTR1
DFERSTC1
DFERSTC1L
DFERSTC1LL
DFOVFSTR1
DFOVFSTC1
DFOVFSTC1L
DFOVFSTC1LL
DFERRINT1
DFERRINT1L
DFERRINT1LL
DFEADR1
DFTSTCTL1
DFTSTCTL1L
IDECCCTL_PE1
IDECCCTL_PE1L
IDERRINT_PE1
IDERRINT_PE1L
IDERRINT_PE1LL
IDSERSTCLR_PE1
IDSERSTCLR_PE1L
IDSERSTCLR_PE1LL
IDDERSTCLR_PE1
IDDERSTCLR_PE1L
IDDERSTCLR_PE1LL
IDOVFSTR_PE1
IDOVFSTR_PE1L
IDOVFSTR_PE1LL
IDSERSTR_PE1
IDSERSTR_PE1L
IDSERSTR_PE1LL
IDSERSTR_PE1LH
IDDERSTR_PE1
IDDERSTR_PE1L
IDDERSTR_PE1LL
IDDERSTR_PE1LH
IDSEDADR0_PE1
IDSEDADR1_PE1
IDDEDADR0_PE1
IDDEDADR1_PE1
ITECCCTL_PE1
ITECCCTL_PE1L
ITERRINT_PE1
ITERRINT_PE1L
ITERRINT_PE1LL
ITSERSTCLR_PE1
ITSERSTCLR_PE1L
ITSERSTCLR_PE1LL
ITDERSTCLR_PE1
ITDERSTCLR_PE1L
ITDERSTCLR_PE1LL
ITOVFSTR_PE1
ITOVFSTR_PE1L
ITOVFSTR_PE1LL
ITSERSTR_PE1
ITSERSTR_PE1L
ITSERSTR_PE1LL
ITDERSTR_PE1
ITDERSTR_PE1L
ITDERSTR_PE1LL
ITSEDADR_PE1
ITDEDADR_PE1
UCFERRINT
UCFERRINTL
UCFERRINTLL
UCFSERSTCLR
UCFSERSTCLRL
UCFSERSTCLRLL
UCFDERSTCLR
UCFDERSTCLRL
UCFDERSTCLRLL
UCFOVFSTR
UCFOVFSTRL
UCFOVFSTRLL
UCFSERSTR
UCFSERSTRL
UCFSERSTRLL
UCFDERSTR
UCFDERSTRL
UCFDERSTRLL
UCF1SEDADR
UCF2SEDADR
UCF3SEDADR
UCF4SEDADR
UCFDEDADR
CFAPCTL
CFAPCTLL
CFECCCTL_VCI2CFBA
CFECCCTL_VCI2CFBAL
CFSTSTCTL_VCI2CFBA
CFSTSTCTL_VCI2CFBAL
CFECCCTL_PE1
CFECCCTL_PE1L
CFSTSTCTL_PE1
CFSTSTCTL_PE1L
CFECCCTL_VCI2CFBB
CFECCCTL_VCI2CFBBL
CFERRINT_VCI2CFBB
CFERRINT_VCI2CFBBL
CFERRINT_VCI2CFBBLL
CFERSTCLR_VCI2CFBB
CFERSTCLR_VCI2CFBBL
CFERSTCLR_VCI2CFBBLL
CFOVFSTR_VCI2CFBB
CFOVFSTR_VCI2CFBBL
CFOVFSTR_VCI2CFBBLL
CFERSTR_VCI2CFBB
CFERSTR_VCI2CFBBL
CFERSTR_VCI2CFBBLL
CFEADR0_VCI2CFBB
IFECCCTL_PE1
IFECCCTL_PE1L
IFERRINT_PE1
IFERRINT_PE1L
IFERRINT_PE1LL
IFERSTCLR_PE1
IFERSTCLR_PE1L
IFERSTCLR_PE1LL
IFOVFSTR_PE1
IFOVFSTR_PE1L
IFOVFSTR_PE1LL
IFERSTR_PE1
IFERSTR_PE1L
IFERSTR_PE1LL
IFERADR_PE1
UGRERRINT
UGRERRINTL
UGRERRINTLL
UGRSERSTCLR
UGRSERSTCLRL
UGRSERSTCLRLL
UGRSERSTCLRLH
UGRSERSTCLRH
UGRSERSTCLRHL
UGRSERSTCLRHH
UGRDERSTCLR
UGRDERSTCLRL
UGRDERSTCLRLL
UGROVFSTR
UGROVFSTRL
UGROVFSTRLL
UGRSERSTR
UGRSERSTRL
UGRSERSTRLL
UGRSERSTRLH
UGRSERSTRH
UGRSERSTRHL
UGRSERSTRHH
UGRDERSTR
UGRDERSTRL
UGRDERSTRLL
UGR1SEDADR
UGR2SEDADR
UGR3SEDADR
UGR4SEDADR
UGR5SEDADR
UGR6SEDADR
UGR7SEDADR
UGR8SEDADR
UGR9SEDADR
UGR10SEDADR
UGR11SEDADR
UGR12SEDADR
UGR13SEDADR
UGR14SEDADR
UGR15SEDADR
UGR16SEDADR
UGR17SEDADR
UGR18SEDADR
UGR19SEDADR
UGR20SEDADR
UGR21SEDADR
UGR22SEDADR
UGR23SEDADR
UGR24SEDADR
UGR25SEDADR
UGR26SEDADR
UGR27SEDADR
UGR28SEDADR
UGR29SEDADR
UGR30SEDADR
UGR31SEDADR
UGR32SEDADR
UGR00DEDADR
GRECCCTL_GRAMC
GRECCCTL_GRAMCL
GRTSTCTL
GRTSTCTLL
GRTDATBF0L
GRTDATBF0LL
GRTDATBF0LLL
GRTDATBF0LLH
GRTDATBF0LH
GRTDATBF0LHL
GRTDATBF0LHH
GRTDATBF0H
GRTDATBF0HL
GRTDATBF0HLL
GRTDATBF0HLH
GRTDATBF0HH
GRTDATBF0HHL
GRTDATBF0HHH
GRTDATBF1L
GRTDATBF1LL
GRTDATBF1LLL
GRTDATBF1LLH
GRTDATBF1LH
GRTDATBF1LHL
GRTDATBF1LHH
GRTDATBF1H
GRTDATBF1HL
GRTDATBF1HLL
GRTDATBF1HLH
GRTDATBF1HH
GRTDATBF1HHL
GRTDATBF1HHH
GRDECINBF0
GRDECINBF0L
GRDECINBF0LL
GRDECINBF0LH
GRDECINBF0H
GRDECINBF0HL
GRDECINBF0HH
GRDECINBF1
GRDECINBF1L
GRDECINBF1LL
GRDECINBF1LH
GRDECINBF1H
GRDECINBF1HL
GRDECINBF1HH
GRECCCTL_VCI2GRAM
GRECCCTL_VCI2GRAML
GRECCCTL_PE1
GRECCCTL_PE1L
GRECCCTL_AXI2GRAM
GRECCCTL_AXI2GRAML
LRECCCTL_PE1
LRECCCTL_PE1L
LRERRINT_PE1
LRERRINT_PE1L
LRERRINT_PE1LL
LRSERSTCLR_PE1
LRSERSTCLR_PE1L
LRSERSTCLR_PE1LL
LRSERSTCLR_PE1LH
LRSERSTCLR_PE1H
LRSERSTCLR_PE1HL
LRSERSTCLR_PE1HH
LRDERSTCLR_PE1
LRDERSTCLR_PE1L
LRDERSTCLR_PE1LL
LROVFSTR_PE1
LROVFSTR_PE1L
LROVFSTR_PE1LL
LRSERSTR_PE1
LRSERSTR_PE1L
LRSERSTR_PE1LL
LRSERSTR_PE1LH
LRSERSTR_PE1H
LRSERSTR_PE1HL
LRSERSTR_PE1HH
LRDERSTR_PE1
LRDERSTR_PE1L
LRDERSTR_PE1LL
LRDERSTR_PE1LH
LRDERSTR_PE1H
LRDERSTR_PE1HL
LRDERSTR_PE1HH
LR1SEDADR0_PE1
LR1SEDADR1_PE1
LR1SEDADR2_PE1
LR1SEDADR3_PE1
LR2SEDADR0_PE1
LR2SEDADR1_PE1
LR2SEDADR2_PE1
LR2SEDADR3_PE1
LR3SEDADR0_PE1
LR3SEDADR1_PE1
LR3SEDADR2_PE1
LR3SEDADR3_PE1
LR4SEDADR0_PE1
LR4SEDADR1_PE1
LR4SEDADR2_PE1
LR4SEDADR3_PE1
LR5SEDADR0_PE1
LR5SEDADR1_PE1
LR5SEDADR2_PE1
LR5SEDADR3_PE1
LR6SEDADR0_PE1
LR6SEDADR1_PE1
LR6SEDADR2_PE1
LR6SEDADR3_PE1
LR7SEDADR0_PE1
LR7SEDADR1_PE1
LR7SEDADR2_PE1
LR7SEDADR3_PE1
LR8SEDADR0_PE1
LR8SEDADR1_PE1
LR8SEDADR2_PE1
LR8SEDADR3_PE1
LRDEDADR0_PE1
LRDEDADR1_PE1
LRDEDADR2_PE1
LRDEDADR3_PE1
LRTSTCTL_PE1
LRTDATBF0_PE1
LRTDATBF1_PE1
LSSECCCTL_PE1
LSSECCCTL_PE1L
LSSERRINT_PE1
LSSERRINT_PE1L
LSSERRINT_PE1LL
LSSERSTCLR_PE1
LSSERSTCLR_PE1L
LSSERSTCLR_PE1LL
LSSOVFSTR_PE1
LSSOVFSTR_PE1L
LSSOVFSTR_PE1LL
LSSERSTR_PE1
LSSERSTR_PE1L
LSSERSTR_PE1LL
LSSEADR_PE1
LSMECCCTL_PE1
LSMECCCTL_PE1L
LSMERRINT_PE1
LSMERRINT_PE1L
LSMERRINT_PE1LL
LSMERSTCLR_PE1
LSMERSTCLR_PE1L
LSMERSTCLR_PE1LL
LSMOVFSTR_PE1
LSMOVFSTR_PE1L
LSMOVFSTR_PE1LL
LSMERSTR_PE1
LSMERSTR_PE1L
LSMERSTR_PE1LL
LSMEADR_PE1
VPECCCTL_SG0
VPECCCTL_SG0L
VPERRINT_SG0
VPERRINT_SG0L
VPERRINT_SG0LL
VPERSTCLR_SG0
VPERSTCLR_SG0L
VPERSTCLR_SG0LL
VPOVFSTR_SG0
VPOVFSTR_SG0L
VPOVFSTR_SG0LL
VPERSTR_SG0
VPERSTR_SG0L
VPERSTR_SG0LL
VPEADR_SG0
VPECCCTL_SG1
VPECCCTL_SG1L
VPERRINT_SG1
VPERRINT_SG1L
VPERRINT_SG1LL
VPERSTCLR_SG1
VPERSTCLR_SG1L
VPERSTCLR_SG1LL
VPOVFSTR_SG1
VPOVFSTR_SG1L
VPOVFSTR_SG1LL
VPERSTR_SG1
VPERSTR_SG1L
VPERSTR_SG1LL
VPEADR_SG1
VPECCCTL_SG2
VPECCCTL_SG2L
VPERRINT_SG2
VPERRINT_SG2L
VPERRINT_SG2LL
VPERSTCLR_SG2
VPERSTCLR_SG2L
VPERSTCLR_SG2LL
VPOVFSTR_SG2
VPOVFSTR_SG2L
VPOVFSTR_SG2LL
VPERSTR_SG2
VPERSTR_SG2L
VPERSTR_SG2LL
VPEADR_SG2
VPECCCTL_SG3
VPECCCTL_SG3L
VPERRINT_SG3
VPERRINT_SG3L
VPERRINT_SG3LL
VPERSTCLR_SG3
VPERSTCLR_SG3L
VPERSTCLR_SG3LL
VPOVFSTR_SG3
VPOVFSTR_SG3L
VPOVFSTR_SG3LL
VPERSTR_SG3
VPERSTR_SG3L
VPERSTR_SG3LL
VPEADR_SG3
VPECCCTL_SG5
VPECCCTL_SG5L
VPERRINT_SG5
VPERRINT_SG5L
VPERRINT_SG5LL
VPERSTCLR_SG5
VPERSTCLR_SG5L
VPERSTCLR_SG5LL
VPOVFSTR_SG5
VPOVFSTR_SG5L
VPOVFSTR_SG5LL
VPERSTR_SG5
VPERSTR_SG5L
VPERSTR_SG5LL
VPEADR_SG5
VPECCCTL_TERM_SG7
VPECCCTL_TERM_SG7L
VPERRINT_TERM_SG7
VPERRINT_TERM_SG7L
VPERRINT_TERM_SG7LL
VPERSTCLR_TERM_SG7
VPERSTCLR_TERM_SG7L
VPERSTCLR_TERM_SG7LL
VPOVFSTR_TERM_SG7
VPOVFSTR_TERM_SG7L
VPOVFSTR_TERM_SG7LL
VPERSTR_TERM_SG7
VPERSTR_TERM_SG7L
VPERSTR_TERM_SG7LL
VPEADR_TERM_SG7
VPECCCTL_VCI2VPI
VPECCCTL_VCI2VPIL
VPERRINT_VCI2VPI
VPERRINT_VCI2VPIL
VPERRINT_VCI2VPILL
VPERSTCLR_VCI2VPI
VPERSTCLR_VCI2VPIL
VPERSTCLR_VCI2VPILL
VPOVFSTR_VCI2VPI
VPOVFSTR_VCI2VPIL
VPOVFSTR_VCI2VPILL
VPERSTR_VCI2VPI
VPERSTR_VCI2VPIL
VPERSTR_VCI2VPILL
VPERADR0_VCI2VPI
VCECCCTL_PDMA
VCECCCTL_PDMAL
VCERRINT_PDMA
VCERRINT_PDMAL
VCERRINT_PDMALL
VCERSTCLR_PDMA
VCERSTCLR_PDMAL
VCERSTCLR_PDMALL
VCOVFSTR_PDMA
VCOVFSTR_PDMAL
VCOVFSTR_PDMALL
VCERSTR_PDMA
VCERSTR_PDMAL
VCERSTR_PDMALL
VCEADR_PDMA
APECCCTL_PFSS
APECCCTL_PFSSL
APERRINT_PFSS
APERRINT_PFSSL
APERRINT_PFSSLL
APERSTCLR_PFSS
APERSTCLR_PFSSL
APERSTCLR_PFSSLL
APOVFSTR_PFSS
APOVFSTR_PFSSL
APOVFSTR_PFSSLL
APERSTR_PFSS
APERSTR_PFSSL
APERSTR_PFSSLL
APEADR_PFSS
APEC0ECCCTL
APEC0ECCCTLL
APEC0ERRINT
APEC0ERRINTL
APEC0ERRINTLL
APEC0STCLR
APEC0STCLRL
APEC0STCLRLL
APEC0OVFSTR
APEC0OVFSTRL
APEC0OVFSTRLL
APEC01STERSTR
APEC01STERSTRL
APEC01STERSTRLL
APEC01STEADR0
GREG8
OPBT0 ... OPBT2
OPBT13 ... OPBT15
PRDNAME1 ... PRDNAME4
CHIPID1LL
CHIPID1LH
CHIPID1HL
CHIPID1HH
EMLK
APEC4ECCCTL
APEC4ECCCTLL
APEC4ERRINT
APEC4ERRINTL
APEC4ERRINTLL
APEC4STCLR
APEC4STCLRL
APEC4STCLRLL
APEC4OVFSTR
APEC4OVFSTRL
APEC4OVFSTRLL
APEC41STERSTR
APEC41STERSTRL
APEC41STERSTRLL
APEC41STEADR0
APEC5ECCCTL
APEC5ECCCTLL
APEC5ERRINT
APEC5ERRINTL
APEC5ERRINTLL
APEC5STCLR
APEC5STCLRL
APEC5STCLRLL
APEC5OVFSTR
APEC5OVFSTRL
APEC5OVFSTRLL
APEC51STERSTR
APEC51STERSTRL
APEC51STERSTRLL
APEC51STEADR0
APEC6ECCCTL
APEC6ECCCTLL
APEC6ERRINT
APEC6ERRINTL
APEC6ERRINTLL
APEC6STCLR
APEC6STCLRL
APEC6STCLRLL
APEC6OVFSTR
APEC6OVFSTRL
APEC6OVFSTRLL
APEC61STERSTR
APEC61STERSTRL
APEC61STERSTRLL
APEC61STEADR0
LBISTREF1
LBISTREF2
MBISTREF1
MBISTREF2
LBISTSIG1
LBISTSIG2
MBISTSIG1
MBISTSIG2
MBISTFTAGL1
MBISTFTAGH1
MBISTFTAGL2
MBISTFTAGH2
BSEQ0ST
BSEQ0STB
BISTST
RSENT0TSSEL
RSENT1TSSEL
RSENT2TSSEL
RSENT3TSSEL
RSENT4TSSEL
RSENT5TSSEL
PINT0 ... PINT7
PINTCLR0 ... PINTCLR7
DTSTRGSEL0 ... DTSTRGSEL3
FEINTF0
FEINTFMSK0
FEINTFC0
FEINTF1
FEINTFMSK1
FEINTFC1
APEC1ECCCTL
APEC1ECCCTLL
APEC1ERRINT
APEC1ERRINTL
APEC1ERRINTLL
APEC1STCLR
APEC1STCLRL
APEC1STCLRLL
APEC1OVFSTR
APEC1OVFSTRL
APEC1OVFSTRLL
APEC11STERSTR
APEC11STERSTRL
APEC11STERSTRLL
APEC11STEADR0
APEC2ECCCTL
APEC2ECCCTLL
APEC2ERRINT
APEC2ERRINTL
APEC2ERRINTLL
APEC2STCLR
APEC2STCLRL
APEC2STCLRLL
APEC2OVFSTR
APEC2OVFSTRL
APEC2OVFSTRLL
APEC21STERSTR
APEC21STERSTRL
APEC21STERSTRLL
APEC21STEADR0
SELB0CALC
MODE
BSEQ0CTL
RESF
RESFC
SWSRESA0
SWARESA0
STAC_DTSRAM
STAC_GRAM
STAC_LM0
STAC_LM1
SWLRESA3
SWLRESS3
MSR_LM3
STAC_LM3
SWLRESA4
SWLRESS4
MSR_LM4
STAC_LM4
SWLRESA5
SWLRESS5
MSR_LM5
STAC_LM5
SWLRESA6
SWLRESS6
MSR_LM6
SWLRESA7
SWLRESS7
MSR_LM7
SWLRESA8
SWLRESS8
MSR_LM8
SWLRESA10
SWLRESS10
MSR_LM10
STAC_LM10
SWLRESA11
SWLRESS11
MSR_LM11
SWLRESA12
SWLRESS12
MSR_LM12
FHVE3
RESC
CVMF
CVMDE
CVMDMASK
CVMDIAG
CVMMON
CVMFC
CVMDEW
CLMATEST
CLMATESTS
CKSC4C
CKSC4S
SWSRESA1
SWARESA1
SWLRESA2
SWLRESS2
MSR_LM2
STAC_LM2
ICUMRESF
ICUMRESFC
CLKD0DIV
CLKD0STAT
CLKD1DIV
CLKD1STAT
CLKD2DIV
CLKD2STAT
CLKD3DIV
CLKD3STAT
CKSC0C
CKSC0S
CKSC2C
CKSC2S
CKSC3C
CKSC3S
FHVE15
APEC3ECCCTL
APEC3ECCCTLL
APEC3ERRINT
APEC3ERRINTL
APEC3ERRINTLL
APEC3STCLR
APEC3STCLRL
APEC3STCLRLL
APEC3OVFSTR
APEC3OVFSTRL
APEC3OVFSTRLL
APEC31STERSTR
APEC31STERSTRL
APEC31STERSTRLL
APEC31STEADR0
EIC0
EIC0L
EIC0H
EIC1
EIC1L
EIC1H
EIC2
EIC2L
EIC2H
EIC3
EIC3L
EIC3H
EIC4
EIC4L
EIC4H
EIC5
EIC5L
EIC5H
EIC6
EIC6L
EIC6H
EIC7
EIC7L
EIC7H
EIC8
EIC8L
EIC8H
EIC9
EIC9L
EIC9H
EIC10
EIC10L
EIC10H
EIC11
EIC11L
EIC11H
EIC12
EIC12L
EIC12H
EIC13
EIC13L
EIC13H
EIC14
EIC14L
EIC14H
EIC15
EIC15L
EIC15H
EIC16
EIC16L
EIC16H
EIC17
EIC17L
EIC17H
EIC18
EIC18L
EIC18H
EIC19
EIC19L
EIC19H
EIC20
EIC20L
EIC20H
EIC21
EIC21L
EIC21H
EIC22
EIC22L
EIC22H
EIC23
EIC23L
EIC23H
EIC24
EIC24L
EIC24H
EIC25
EIC25L
EIC25H
EIC26
EIC26L
EIC26H
EIC27
EIC27L
EIC27H
EIC28
EIC28L
EIC28H
EIC29
EIC29L
EIC29H
EIC30
EIC30L
EIC30H
EIC31
EIC31L
EIC31H
FNC
FNCH
FNRF
FNCT
FIC
FICH
FIRF
FICT
IMR0
IMR0L
IMR0LL
IMR0LH
IMR0H
IMR0HL
IMR0HH
IMR0EIMK0 ... IMR0EIMK31
EIBD0 ... EIBD31
CMPTST0
CMPTST0L
CMPTST0LL
CMPTST0LH
CMPTST0H
CMPTST0HL
CMPTST0HH
CMPTST1
CMPTST1L
CMPTST1LL
CMPTST1LH
CMPTST1H
CMPTST1HL
CMPTST1HH
TM_VER
TM_CC
TMA_ME
TMA_MS
TMB_ME
TMB_MS
TMA_MA0 ... TMA_MA31
TMB_MA0 ... TMB_MA31
GRAMC_WTBCONFIG0 ... GRAMC_WTBCONFIG2
DMACTL
DTSCTL1
DTSCTL2
DTSSTS
DMACER
DTSER1
DTSER2
DTSERC
DM0CMV
DM1CMV
DTSCMV
CMVC
TFRSTS
DTSPR0 ... DTSPR7
DTRECCTL
DTRERINT
DTRTSCTL
DTRTWDAT
DTRTRDAT
ADECCTCL
ADECCTDT
DM00CM
DM01CM
DM02CM
DM03CM
DM04CM
DM05CM
DM06CM
DM07CM
DM10CM
DM11CM
DM12CM
DM13CM
DM14CM
DM15CM
DM16CM
DM17CM
DTS000CM
DTS001CM
DTS002CM
DTS003CM
DTS004CM
DTS005CM
DTS006CM
DTS007CM
DTS008CM
DTS009CM
DTS010CM
DTS011CM
DTS012CM
DTS013CM
DTS014CM
DTS015CM
DTS016CM
DTS017CM
DTS018CM
DTS019CM
DTS020CM
DTS021CM
DTS022CM
DTS023CM
DTS024CM
DTS025CM
DTS026CM
DTS027CM
DTS028CM
DTS029CM
DTS030CM
DTS031CM
DTS032CM
DTS033CM
DTS034CM
DTS035CM
DTS036CM
DTS037CM
DTS038CM
DTS039CM
DTS040CM
DTS041CM
DTS042CM
DTS043CM
DTS044CM
DTS045CM
DTS046CM
DTS047CM
DTS048CM
DTS049CM
DTS050CM
DTS051CM
DTS052CM
DTS053CM
DTS054CM
DTS055CM
DTS056CM
DTS057CM
DTS058CM
DTS059CM
DTS060CM
DTS061CM
DTS062CM
DTS063CM
DTS064CM
DTS065CM
DTS066CM
DTS067CM
DTS068CM
DTS069CM
DTS070CM
DTS071CM
DTS072CM
DTS073CM
DTS074CM
DTS075CM
DTS076CM
DTS077CM
DTS078CM
DTS079CM
DTS080CM
DTS081CM
DTS082CM
DTS083CM
DTS084CM
DTS085CM
DTS086CM
DTS087CM
DTS088CM
DTS089CM
DTS090CM
DTS091CM
DTS092CM
DTS093CM
DTS094CM
DTS095CM
DTS096CM
DTS097CM
DTS098CM
DTS099CM
DTS100CM
DTS101CM
DTS102CM
DTS103CM
DTS104CM
DTS105CM
DTS106CM
DTS107CM
DTS108CM
DTS109CM
DTS110CM
DTS111CM
DTS112CM
DTS113CM
DTS114CM
DTS115CM
DTS116CM
DTS117CM
DTS118CM
DTS119CM
DTS120CM
DTS121CM
DTS122CM
DTS123CM
DTS124CM
DTS125CM
DTS126CM
DTS127CM
DSA0
DDA0
DTC0
DTCT0
DRSA0
DRDA0
DRTC0
DTCC0
DCEN0
DCST0
DCSTS0
DCSTC0
DTFR0
DTFRRQ0
DTFRRQC0
DSA1
DDA1
DTC1
DTCT1
DRSA1
DRDA1
DRTC1
DTCC1
DCEN1
DCST1
DCSTS1
DCSTC1
DTFR1
DTFRRQ1
DTFRRQC1
DSA2
DDA2
DTC2
DTCT2
DRSA2
DRDA2
DRTC2
DTCC2
DCEN2
DCST2
DCSTS2
DCSTC2
DTFR2
DTFRRQ2
DTFRRQC2
DSA3
DDA3
DTC3
DTCT3
DRSA3
DRDA3
DRTC3
DTCC3
DCEN3
DCST3
DCSTS3
DCSTC3
DTFR3
DTFRRQ3
DTFRRQC3
DSA4
DDA4
DTC4
DTCT4
DRSA4
DRDA4
DRTC4
DTCC4
DCEN4
DCST4
DCSTS4
DCSTC4
DTFR4
DTFRRQ4
DTFRRQC4
DSA5
DDA5
DTC5
DTCT5
DRSA5
DRDA5
DRTC5
DTCC5
DCEN5
DCST5
DCSTS5
DCSTC5
DTFR5
DTFRRQ5
DTFRRQC5
DSA6
DDA6
DTC6
DTCT6
DRSA6
DRDA6
DRTC6
DTCC6
DCEN6
DCST6
DCSTS6
DCSTC6
DTFR6
DTFRRQ6
DTFRRQC6
DSA7
DDA7
DTC7
DTCT7
DRSA7
DRDA7
DRTC7
DTCC7
DCEN7
DCST7
DCSTS7
DCSTC7
DTFR7
DTFRRQ7
DTFRRQC7
DSA8
DDA8
DTC8
DTCT8
DRSA8
DRDA8
DRTC8
DTCC8
DCEN8
DCST8
DCSTS8
DCSTC8
DTFR8
DTFRRQ8
DTFRRQC8
DSA9
DDA9
DTC9
DTCT9
DRSA9
DRDA9
DRTC9
DTCC9
DCEN9
DCST9
DCSTS9
DCSTC9
DTFR9
DTFRRQ9
DTFRRQC9
DSA10
DDA10
DTC10
DTCT10
DRSA10
DRDA10
DRTC10
DTCC10
DCEN10
DCST10
DCSTS10
DCSTC10
DTFR10
DTFRRQ10
DTFRRQC10
DSA11
DDA11
DTC11
DTCT11
DRSA11
DRDA11
DRTC11
DTCC11
DCEN11
DCST11
DCSTS11
DCSTC11
DTFR11
DTFRRQ11
DTFRRQC11
DSA12
DDA12
DTC12
DTCT12
DRSA12
DRDA12
DRTC12
DTCC12
DCEN12
DCST12
DCSTS12
DCSTC12
DTFR12
DTFRRQ12
DTFRRQC12
DSA13
DDA13
DTC13
DTCT13
DRSA13
DRDA13
DRTC13
DTCC13
DCEN13
DCST13
DCSTS13
DCSTC13
DTFR13
DTFRRQ13
DTFRRQC13
DSA14
DDA14
DTC14
DTCT14
DRSA14
DRDA14
DRTC14
DTCC14
DCEN14
DCST14
DCSTS14
DCSTC14
DTFR14
DTFRRQ14
DTFRRQC14
DSA15
DDA15
DTC15
DTCT15
DRSA15
DRDA15
DRTC15
DTCC15
DCEN15
DCST15
DCSTS15
DCSTC15
DTFR15
DTFRRQ15
DTFRRQC15
DTSA000
DTDA000
DTTC000
DTTCT000
DTRSA000
DTRDA000
DTRTC000
DTTCC000
DTFSL000
DTFST000
DTFSS000
DTFSC000
DTSA001
DTDA001
DTTC001
DTTCT001
DTRSA001
DTRDA001
DTRTC001
DTTCC001
DTFSL001
DTFST001
DTFSS001
DTFSC001
DTSA002
DTDA002
DTTC002
DTTCT002
DTRSA002
DTRDA002
DTRTC002
DTTCC002
DTFSL002
DTFST002
DTFSS002
DTFSC002
DTSA003
DTDA003
DTTC003
DTTCT003
DTRSA003
DTRDA003
DTRTC003
DTTCC003
DTFSL003
DTFST003
DTFSS003
DTFSC003
DTSA004
DTDA004
DTTC004
DTTCT004
DTRSA004
DTRDA004
DTRTC004
DTTCC004
DTFSL004
DTFST004
DTFSS004
DTFSC004
DTSA005
DTDA005
DTTC005
DTTCT005
DTRSA005
DTRDA005
DTRTC005
DTTCC005
DTFSL005
DTFST005
DTFSS005
DTFSC005
DTSA006
DTDA006
DTTC006
DTTCT006
DTRSA006
DTRDA006
DTRTC006
DTTCC006
DTFSL006
DTFST006
DTFSS006
DTFSC006
DTSA007
DTDA007
DTTC007
DTTCT007
DTRSA007
DTRDA007
DTRTC007
DTTCC007
DTFSL007
DTFST007
DTFSS007
DTFSC007
DTSA008
DTDA008
DTTC008
DTTCT008
DTRSA008
DTRDA008
DTRTC008
DTTCC008
DTFSL008
DTFST008
DTFSS008
DTFSC008
DTSA009
DTDA009
DTTC009
DTTCT009
DTRSA009
DTRDA009
DTRTC009
DTTCC009
DTFSL009
DTFST009
DTFSS009
DTFSC009
DTSA010
DTDA010
DTTC010
DTTCT010
DTRSA010
DTRDA010
DTRTC010
DTTCC010
DTFSL010
DTFST010
DTFSS010
DTFSC010
DTSA011
DTDA011
DTTC011
DTTCT011
DTRSA011
DTRDA011
DTRTC011
DTTCC011
DTFSL011
DTFST011
DTFSS011
DTFSC011
DTSA012
DTDA012
DTTC012
DTTCT012
DTRSA012
DTRDA012
DTRTC012
DTTCC012
DTFSL012
DTFST012
DTFSS012
DTFSC012
DTSA013
DTDA013
DTTC013
DTTCT013
DTRSA013
DTRDA013
DTRTC013
DTTCC013
DTFSL013
DTFST013
DTFSS013
DTFSC013
DTSA014
DTDA014
DTTC014
DTTCT014
DTRSA014
DTRDA014
DTRTC014
DTTCC014
DTFSL014
DTFST014
DTFSS014
DTFSC014
DTSA015
DTDA015
DTTC015
DTTCT015
DTRSA015
DTRDA015
DTRTC015
DTTCC015
DTFSL015
DTFST015
DTFSS015
DTFSC015
DTSA016
DTDA016
DTTC016
DTTCT016
DTRSA016
DTRDA016
DTRTC016
DTTCC016
DTFSL016
DTFST016
DTFSS016
DTFSC016
DTSA017
DTDA017
DTTC017
DTTCT017
DTRSA017
DTRDA017
DTRTC017
DTTCC017
DTFSL017
DTFST017
DTFSS017
DTFSC017
DTSA018
DTDA018
DTTC018
DTTCT018
DTRSA018
DTRDA018
DTRTC018
DTTCC018
DTFSL018
DTFST018
DTFSS018
DTFSC018
DTSA019
DTDA019
DTTC019
DTTCT019
DTRSA019
DTRDA019
DTRTC019
DTTCC019
DTFSL019
DTFST019
DTFSS019
DTFSC019
DTSA020
DTDA020
DTTC020
DTTCT020
DTRSA020
DTRDA020
DTRTC020
DTTCC020
DTFSL020
DTFST020
DTFSS020
DTFSC020
DTSA021
DTDA021
DTTC021
DTTCT021
DTRSA021
DTRDA021
DTRTC021
DTTCC021
DTFSL021
DTFST021
DTFSS021
DTFSC021
DTSA022
DTDA022
DTTC022
DTTCT022
DTRSA022
DTRDA022
DTRTC022
DTTCC022
DTFSL022
DTFST022
DTFSS022
DTFSC022
DTSA023
DTDA023
DTTC023
DTTCT023
DTRSA023
DTRDA023
DTRTC023
DTTCC023
DTFSL023
DTFST023
DTFSS023
DTFSC023
DTSA024
DTDA024
DTTC024
DTTCT024
DTRSA024
DTRDA024
DTRTC024
DTTCC024
DTFSL024
DTFST024
DTFSS024
DTFSC024
DTSA025
DTDA025
DTTC025
DTTCT025
DTRSA025
DTRDA025
DTRTC025
DTTCC025
DTFSL025
DTFST025
DTFSS025
DTFSC025
DTSA026
DTDA026
DTTC026
DTTCT026
DTRSA026
DTRDA026
DTRTC026
DTTCC026
DTFSL026
DTFST026
DTFSS026
DTFSC026
DTSA027
DTDA027
DTTC027
DTTCT027
DTRSA027
DTRDA027
DTRTC027
DTTCC027
DTFSL027
DTFST027
DTFSS027
DTFSC027
DTSA028
DTDA028
DTTC028
DTTCT028
DTRSA028
DTRDA028
DTRTC028
DTTCC028
DTFSL028
DTFST028
DTFSS028
DTFSC028
DTSA029
DTDA029
DTTC029
DTTCT029
DTRSA029
DTRDA029
DTRTC029
DTTCC029
DTFSL029
DTFST029
DTFSS029
DTFSC029
DTSA030
DTDA030
DTTC030
DTTCT030
DTRSA030
DTRDA030
DTRTC030
DTTCC030
DTFSL030
DTFST030
DTFSS030
DTFSC030
DTSA031
DTDA031
DTTC031
DTTCT031
DTRSA031
DTRDA031
DTRTC031
DTTCC031
DTFSL031
DTFST031
DTFSS031
DTFSC031
DTSA032
DTDA032
DTTC032
DTTCT032
DTRSA032
DTRDA032
DTRTC032
DTTCC032
DTFSL032
DTFST032
DTFSS032
DTFSC032
DTSA033
DTDA033
DTTC033
DTTCT033
DTRSA033
DTRDA033
DTRTC033
DTTCC033
DTFSL033
DTFST033
DTFSS033
DTFSC033
DTSA034
DTDA034
DTTC034
DTTCT034
DTRSA034
DTRDA034
DTRTC034
DTTCC034
DTFSL034
DTFST034
DTFSS034
DTFSC034
DTSA035
DTDA035
DTTC035
DTTCT035
DTRSA035
DTRDA035
DTRTC035
DTTCC035
DTFSL035
DTFST035
DTFSS035
DTFSC035
DTSA036
DTDA036
DTTC036
DTTCT036
DTRSA036
DTRDA036
DTRTC036
DTTCC036
DTFSL036
DTFST036
DTFSS036
DTFSC036
DTSA037
DTDA037
DTTC037
DTTCT037
DTRSA037
DTRDA037
DTRTC037
DTTCC037
DTFSL037
DTFST037
DTFSS037
DTFSC037
DTSA038
DTDA038
DTTC038
DTTCT038
DTRSA038
DTRDA038
DTRTC038
DTTCC038
DTFSL038
DTFST038
DTFSS038
DTFSC038
DTSA039
DTDA039
DTTC039
DTTCT039
DTRSA039
DTRDA039
DTRTC039
DTTCC039
DTFSL039
DTFST039
DTFSS039
DTFSC039
DTSA040
DTDA040
DTTC040
DTTCT040
DTRSA040
DTRDA040
DTRTC040
DTTCC040
DTFSL040
DTFST040
DTFSS040
DTFSC040
DTSA041
DTDA041
DTTC041
DTTCT041
DTRSA041
DTRDA041
DTRTC041
DTTCC041
DTFSL041
DTFST041
DTFSS041
DTFSC041
DTSA042
DTDA042
DTTC042
DTTCT042
DTRSA042
DTRDA042
DTRTC042
DTTCC042
DTFSL042
DTFST042
DTFSS042
DTFSC042
DTSA043
DTDA043
DTTC043
DTTCT043
DTRSA043
DTRDA043
DTRTC043
DTTCC043
DTFSL043
DTFST043
DTFSS043
DTFSC043
DTSA044
DTDA044
DTTC044
DTTCT044
DTRSA044
DTRDA044
DTRTC044
DTTCC044
DTFSL044
DTFST044
DTFSS044
DTFSC044
DTSA045
DTDA045
DTTC045
DTTCT045
DTRSA045
DTRDA045
DTRTC045
DTTCC045
DTFSL045
DTFST045
DTFSS045
DTFSC045
DTSA046
DTDA046
DTTC046
DTTCT046
DTRSA046
DTRDA046
DTRTC046
DTTCC046
DTFSL046
DTFST046
DTFSS046
DTFSC046
DTSA047
DTDA047
DTTC047
DTTCT047
DTRSA047
DTRDA047
DTRTC047
DTTCC047
DTFSL047
DTFST047
DTFSS047
DTFSC047
DTSA048
DTDA048
DTTC048
DTTCT048
DTRSA048
DTRDA048
DTRTC048
DTTCC048
DTFSL048
DTFST048
DTFSS048
DTFSC048
DTSA049
DTDA049
DTTC049
DTTCT049
DTRSA049
DTRDA049
DTRTC049
DTTCC049
DTFSL049
DTFST049
DTFSS049
DTFSC049
DTSA050
DTDA050
DTTC050
DTTCT050
DTRSA050
DTRDA050
DTRTC050
DTTCC050
DTFSL050
DTFST050
DTFSS050
DTFSC050
DTSA051
DTDA051
DTTC051
DTTCT051
DTRSA051
DTRDA051
DTRTC051
DTTCC051
DTFSL051
DTFST051
DTFSS051
DTFSC051
DTSA052
DTDA052
DTTC052
DTTCT052
DTRSA052
DTRDA052
DTRTC052
DTTCC052
DTFSL052
DTFST052
DTFSS052
DTFSC052
DTSA053
DTDA053
DTTC053
DTTCT053
DTRSA053
DTRDA053
DTRTC053
DTTCC053
DTFSL053
DTFST053
DTFSS053
DTFSC053
DTSA054
DTDA054
DTTC054
DTTCT054
DTRSA054
DTRDA054
DTRTC054
DTTCC054
DTFSL054
DTFST054
DTFSS054
DTFSC054
DTSA055
DTDA055
DTTC055
DTTCT055
DTRSA055
DTRDA055
DTRTC055
DTTCC055
DTFSL055
DTFST055
DTFSS055
DTFSC055
DTSA056
DTDA056
DTTC056
DTTCT056
DTRSA056
DTRDA056
DTRTC056
DTTCC056
DTFSL056
DTFST056
DTFSS056
DTFSC056
DTSA057
DTDA057
DTTC057
DTTCT057
DTRSA057
DTRDA057
DTRTC057
DTTCC057
DTFSL057
DTFST057
DTFSS057
DTFSC057
DTSA058
DTDA058
DTTC058
DTTCT058
DTRSA058
DTRDA058
DTRTC058
DTTCC058
DTFSL058
DTFST058
DTFSS058
DTFSC058
DTSA059
DTDA059
DTTC059
DTTCT059
DTRSA059
DTRDA059
DTRTC059
DTTCC059
DTFSL059
DTFST059
DTFSS059
DTFSC059
DTSA060
DTDA060
DTTC060
DTTCT060
DTRSA060
DTRDA060
DTRTC060
DTTCC060
DTFSL060
DTFST060
DTFSS060
DTFSC060
DTSA061
DTDA061
DTTC061
DTTCT061
DTRSA061
DTRDA061
DTRTC061
DTTCC061
DTFSL061
DTFST061
DTFSS061
DTFSC061
DTSA062
DTDA062
DTTC062
DTTCT062
DTRSA062
DTRDA062
DTRTC062
DTTCC062
DTFSL062
DTFST062
DTFSS062
DTFSC062
DTSA063
DTDA063
DTTC063
DTTCT063
DTRSA063
DTRDA063
DTRTC063
DTTCC063
DTFSL063
DTFST063
DTFSS063
DTFSC063
DTSA064
DTDA064
DTTC064
DTTCT064
DTRSA064
DTRDA064
DTRTC064
DTTCC064
DTFSL064
DTFST064
DTFSS064
DTFSC064
DTSA065
DTDA065
DTTC065
DTTCT065
DTRSA065
DTRDA065
DTRTC065
DTTCC065
DTFSL065
DTFST065
DTFSS065
DTFSC065
DTSA066
DTDA066
DTTC066
DTTCT066
DTRSA066
DTRDA066
DTRTC066
DTTCC066
DTFSL066
DTFST066
DTFSS066
DTFSC066
DTSA067
DTDA067
DTTC067
DTTCT067
DTRSA067
DTRDA067
DTRTC067
DTTCC067
DTFSL067
DTFST067
DTFSS067
DTFSC067
DTSA068
DTDA068
DTTC068
DTTCT068
DTRSA068
DTRDA068
DTRTC068
DTTCC068
DTFSL068
DTFST068
DTFSS068
DTFSC068
DTSA069
DTDA069
DTTC069
DTTCT069
DTRSA069
DTRDA069
DTRTC069
DTTCC069
DTFSL069
DTFST069
DTFSS069
DTFSC069
DTSA070
DTDA070
DTTC070
DTTCT070
DTRSA070
DTRDA070
DTRTC070
DTTCC070
DTFSL070
DTFST070
DTFSS070
DTFSC070
DTSA071
DTDA071
DTTC071
DTTCT071
DTRSA071
DTRDA071
DTRTC071
DTTCC071
DTFSL071
DTFST071
DTFSS071
DTFSC071
DTSA072
DTDA072
DTTC072
DTTCT072
DTRSA072
DTRDA072
DTRTC072
DTTCC072
DTFSL072
DTFST072
DTFSS072
DTFSC072
DTSA073
DTDA073
DTTC073
DTTCT073
DTRSA073
DTRDA073
DTRTC073
DTTCC073
DTFSL073
DTFST073
DTFSS073
DTFSC073
DTSA074
DTDA074
DTTC074
DTTCT074
DTRSA074
DTRDA074
DTRTC074
DTTCC074
DTFSL074
DTFST074
DTFSS074
DTFSC074
DTSA075
DTDA075
DTTC075
DTTCT075
DTRSA075
DTRDA075
DTRTC075
DTTCC075
DTFSL075
DTFST075
DTFSS075
DTFSC075
DTSA076
DTDA076
DTTC076
DTTCT076
DTRSA076
DTRDA076
DTRTC076
DTTCC076
DTFSL076
DTFST076
DTFSS076
DTFSC076
DTSA077
DTDA077
DTTC077
DTTCT077
DTRSA077
DTRDA077
DTRTC077
DTTCC077
DTFSL077
DTFST077
DTFSS077
DTFSC077
DTSA078
DTDA078
DTTC078
DTTCT078
DTRSA078
DTRDA078
DTRTC078
DTTCC078
DTFSL078
DTFST078
DTFSS078
DTFSC078
DTSA079
DTDA079
DTTC079
DTTCT079
DTRSA079
DTRDA079
DTRTC079
DTTCC079
DTFSL079
DTFST079
DTFSS079
DTFSC079
DTSA080
DTDA080
DTTC080
DTTCT080
DTRSA080
DTRDA080
DTRTC080
DTTCC080
DTFSL080
DTFST080
DTFSS080
DTFSC080
DTSA081
DTDA081
DTTC081
DTTCT081
DTRSA081
DTRDA081
DTRTC081
DTTCC081
DTFSL081
DTFST081
DTFSS081
DTFSC081
DTSA082
DTDA082
DTTC082
DTTCT082
DTRSA082
DTRDA082
DTRTC082
DTTCC082
DTFSL082
DTFST082
DTFSS082
DTFSC082
DTSA083
DTDA083
DTTC083
DTTCT083
DTRSA083
DTRDA083
DTRTC083
DTTCC083
DTFSL083
DTFST083
DTFSS083
DTFSC083
DTSA084
DTDA084
DTTC084
DTTCT084
DTRSA084
DTRDA084
DTRTC084
DTTCC084
DTFSL084
DTFST084
DTFSS084
DTFSC084
DTSA085
DTDA085
DTTC085
DTTCT085
DTRSA085
DTRDA085
DTRTC085
DTTCC085
DTFSL085
DTFST085
DTFSS085
DTFSC085
DTSA086
DTDA086
DTTC086
DTTCT086
DTRSA086
DTRDA086
DTRTC086
DTTCC086
DTFSL086
DTFST086
DTFSS086
DTFSC086
DTSA087
DTDA087
DTTC087
DTTCT087
DTRSA087
DTRDA087
DTRTC087
DTTCC087
DTFSL087
DTFST087
DTFSS087
DTFSC087
DTSA088
DTDA088
DTTC088
DTTCT088
DTRSA088
DTRDA088
DTRTC088
DTTCC088
DTFSL088
DTFST088
DTFSS088
DTFSC088
DTSA089
DTDA089
DTTC089
DTTCT089
DTRSA089
DTRDA089
DTRTC089
DTTCC089
DTFSL089
DTFST089
DTFSS089
DTFSC089
DTSA090
DTDA090
DTTC090
DTTCT090
DTRSA090
DTRDA090
DTRTC090
DTTCC090
DTFSL090
DTFST090
DTFSS090
DTFSC090
DTSA091
DTDA091
DTTC091
DTTCT091
DTRSA091
DTRDA091
DTRTC091
DTTCC091
DTFSL091
DTFST091
DTFSS091
DTFSC091
DTSA092
DTDA092
DTTC092
DTTCT092
DTRSA092
DTRDA092
DTRTC092
DTTCC092
DTFSL092
DTFST092
DTFSS092
DTFSC092
DTSA093
DTDA093
DTTC093
DTTCT093
DTRSA093
DTRDA093
DTRTC093
DTTCC093
DTFSL093
DTFST093
DTFSS093
DTFSC093
DTSA094
DTDA094
DTTC094
DTTCT094
DTRSA094
DTRDA094
DTRTC094
DTTCC094
DTFSL094
DTFST094
DTFSS094
DTFSC094
DTSA095
DTDA095
DTTC095
DTTCT095
DTRSA095
DTRDA095
DTRTC095
DTTCC095
DTFSL095
DTFST095
DTFSS095
DTFSC095
DTSA096
DTDA096
DTTC096
DTTCT096
DTRSA096
DTRDA096
DTRTC096
DTTCC096
DTFSL096
DTFST096
DTFSS096
DTFSC096
DTSA097
DTDA097
DTTC097
DTTCT097
DTRSA097
DTRDA097
DTRTC097
DTTCC097
DTFSL097
DTFST097
DTFSS097
DTFSC097
DTSA098
DTDA098
DTTC098
DTTCT098
DTRSA098
DTRDA098
DTRTC098
DTTCC098
DTFSL098
DTFST098
DTFSS098
DTFSC098
DTSA099
DTDA099
DTTC099
DTTCT099
DTRSA099
DTRDA099
DTRTC099
DTTCC099
DTFSL099
DTFST099
DTFSS099
DTFSC099
DTSA100
DTDA100
DTTC100
DTTCT100
DTRSA100
DTRDA100
DTRTC100
DTTCC100
DTFSL100
DTFST100
DTFSS100
DTFSC100
DTSA101
DTDA101
DTTC101
DTTCT101
DTRSA101
DTRDA101
DTRTC101
DTTCC101
DTFSL101
DTFST101
DTFSS101
DTFSC101
DTSA102
DTDA102
DTTC102
DTTCT102
DTRSA102
DTRDA102
DTRTC102
DTTCC102
DTFSL102
DTFST102
DTFSS102
DTFSC102
DTSA103
DTDA103
DTTC103
DTTCT103
DTRSA103
DTRDA103
DTRTC103
DTTCC103
DTFSL103
DTFST103
DTFSS103
DTFSC103
DTSA104
DTDA104
DTTC104
DTTCT104
DTRSA104
DTRDA104
DTRTC104
DTTCC104
DTFSL104
DTFST104
DTFSS104
DTFSC104
DTSA105
DTDA105
DTTC105
DTTCT105
DTRSA105
DTRDA105
DTRTC105
DTTCC105
DTFSL105
DTFST105
DTFSS105
DTFSC105
DTSA106
DTDA106
DTTC106
DTTCT106
DTRSA106
DTRDA106
DTRTC106
DTTCC106
DTFSL106
DTFST106
DTFSS106
DTFSC106
DTSA107
DTDA107
DTTC107
DTTCT107
DTRSA107
DTRDA107
DTRTC107
DTTCC107
DTFSL107
DTFST107
DTFSS107
DTFSC107
DTSA108
DTDA108
DTTC108
DTTCT108
DTRSA108
DTRDA108
DTRTC108
DTTCC108
DTFSL108
DTFST108
DTFSS108
DTFSC108
DTSA109
DTDA109
DTTC109
DTTCT109
DTRSA109
DTRDA109
DTRTC109
DTTCC109
DTFSL109
DTFST109
DTFSS109
DTFSC109
DTSA110
DTDA110
DTTC110
DTTCT110
DTRSA110
DTRDA110
DTRTC110
DTTCC110
DTFSL110
DTFST110
DTFSS110
DTFSC110
DTSA111
DTDA111
DTTC111
DTTCT111
DTRSA111
DTRDA111
DTRTC111
DTTCC111
DTFSL111
DTFST111
DTFSS111
DTFSC111
DTSA112
DTDA112
DTTC112
DTTCT112
DTRSA112
DTRDA112
DTRTC112
DTTCC112
DTFSL112
DTFST112
DTFSS112
DTFSC112
DTSA113
DTDA113
DTTC113
DTTCT113
DTRSA113
DTRDA113
DTRTC113
DTTCC113
DTFSL113
DTFST113
DTFSS113
DTFSC113
DTSA114
DTDA114
DTTC114
DTTCT114
DTRSA114
DTRDA114
DTRTC114
DTTCC114
DTFSL114
DTFST114
DTFSS114
DTFSC114
DTSA115
DTDA115
DTTC115
DTTCT115
DTRSA115
DTRDA115
DTRTC115
DTTCC115
DTFSL115
DTFST115
DTFSS115
DTFSC115
DTSA116
DTDA116
DTTC116
DTTCT116
DTRSA116
DTRDA116
DTRTC116
DTTCC116
DTFSL116
DTFST116
DTFSS116
DTFSC116
DTSA117
DTDA117
DTTC117
DTTCT117
DTRSA117
DTRDA117
DTRTC117
DTTCC117
DTFSL117
DTFST117
DTFSS117
DTFSC117
DTSA118
DTDA118
DTTC118
DTTCT118
DTRSA118
DTRDA118
DTRTC118
DTTCC118
DTFSL118
DTFST118
DTFSS118
DTFSC118
DTSA119
DTDA119
DTTC119
DTTCT119
DTRSA119
DTRDA119
DTRTC119
DTTCC119
DTFSL119
DTFST119
DTFSS119
DTFSC119
DTSA120
DTDA120
DTTC120
DTTCT120
DTRSA120
DTRDA120
DTRTC120
DTTCC120
DTFSL120
DTFST120
DTFSS120
DTFSC120
DTSA121
DTDA121
DTTC121
DTTCT121
DTRSA121
DTRDA121
DTRTC121
DTTCC121
DTFSL121
DTFST121
DTFSS121
DTFSC121
DTSA122
DTDA122
DTTC122
DTTCT122
DTRSA122
DTRDA122
DTRTC122
DTTCC122
DTFSL122
DTFST122
DTFSS122
DTFSC122
DTSA123
DTDA123
DTTC123
DTTCT123
DTRSA123
DTRDA123
DTRTC123
DTTCC123
DTFSL123
DTFST123
DTFSS123
DTFSC123
DTSA124
DTDA124
DTTC124
DTTCT124
DTRSA124
DTRDA124
DTRTC124
DTTCC124
DTFSL124
DTFST124
DTFSS124
DTFSC124
DTSA125
DTDA125
DTTC125
DTTCT125
DTRSA125
DTRDA125
DTRTC125
DTTCC125
DTFSL125
DTFST125
DTFSS125
DTFSC125
DTSA126
DTDA126
DTTC126
DTTCT126
DTRSA126
DTRDA126
DTRTC126
DTTCC126
DTFSL126
DTFST126
DTFSS126
DTFSC126
DTSA127
DTDA127
DTTC127
DTTCT127
DTRSA127
DTRDA127
DTRTC127
DTTCC127
DTFSL127
DTFST127
DTFSS127
DTFSC127
EIC32
EIC32L
EIC32H
EIC33
EIC33L
EIC33H
EIC34
EIC34L
EIC34H
EIC35
EIC35L
EIC35H
EIC36
EIC36L
EIC36H
EIC37
EIC37L
EIC37H
EIC38
EIC38L
EIC38H
EIC39
EIC39L
EIC39H
EIC40
EIC40L
EIC40H
EIC41
EIC41L
EIC41H
EIC42
EIC42L
EIC42H
EIC43
EIC43L
EIC43H
EIC44
EIC44L
EIC44H
EIC45
EIC45L
EIC45H
EIC46
EIC46L
EIC46H
EIC47
EIC47L
EIC47H
EIC48
EIC48L
EIC48H
EIC49
EIC49L
EIC49H
EIC50
EIC50L
EIC50H
EIC51
EIC51L
EIC51H
EIC52
EIC52L
EIC52H
EIC53
EIC53L
EIC53H
EIC54
EIC54L
EIC54H
EIC55
EIC55L
EIC55H
EIC56
EIC56L
EIC56H
EIC57
EIC57L
EIC57H
EIC58
EIC58L
EIC58H
EIC59
EIC59L
EIC59H
EIC60
EIC60L
EIC60H
EIC61
EIC61L
EIC61H
EIC62
EIC62L
EIC62H
EIC63
EIC63L
EIC63H
EIC64
EIC64L
EIC64H
EIC65
EIC65L
EIC65H
EIC66
EIC66L
EIC66H
EIC67
EIC67L
EIC67H
EIC68
EIC68L
EIC68H
EIC69
EIC69L
EIC69H
EIC70
EIC70L
EIC70H
EIC71
EIC71L
EIC71H
EIC72
EIC72L
EIC72H
EIC73
EIC73L
EIC73H
EIC74
EIC74L
EIC74H
EIC75
EIC75L
EIC75H
EIC76
EIC76L
EIC76H
EIC77
EIC77L
EIC77H
EIC78
EIC78L
EIC78H
EIC79
EIC79L
EIC79H
EIC80
EIC80L
EIC80H
EIC81
EIC81L
EIC81H
EIC82
EIC82L
EIC82H
EIC83
EIC83L
EIC83H
EIC84
EIC84L
EIC84H
EIC85
EIC85L
EIC85H
EIC86
EIC86L
EIC86H
EIC87
EIC87L
EIC87H
EIC88
EIC88L
EIC88H
EIC89
EIC89L
EIC89H
EIC90
EIC90L
EIC90H
EIC91
EIC91L
EIC91H
EIC92
EIC92L
EIC92H
EIC93
EIC93L
EIC93H
EIC94
EIC94L
EIC94H
EIC95
EIC95L
EIC95H
EIC96
EIC96L
EIC96H
EIC97
EIC97L
EIC97H
EIC98
EIC98L
EIC98H
EIC99
EIC99L
EIC99H
EIC100
EIC100L
EIC100H
EIC101
EIC101L
EIC101H
EIC102
EIC102L
EIC102H
EIC103
EIC103L
EIC103H
EIC104
EIC104L
EIC104H
EIC105
EIC105L
EIC105H
EIC106
EIC106L
EIC106H
EIC107
EIC107L
EIC107H
EIC108
EIC108L
EIC108H
EIC109
EIC109L
EIC109H
EIC110
EIC110L
EIC110H
EIC111
EIC111L
EIC111H
EIC112
EIC112L
EIC112H
EIC113
EIC113L
EIC113H
EIC114
EIC114L
EIC114H
EIC115
EIC115L
EIC115H
EIC116
EIC116L
EIC116H
EIC117
EIC117L
EIC117H
EIC118
EIC118L
EIC118H
EIC119
EIC119L
EIC119H
EIC120
EIC120L
EIC120H
EIC121
EIC121L
EIC121H
EIC122
EIC122L
EIC122H
EIC123
EIC123L
EIC123H
EIC124
EIC124L
EIC124H
EIC125
EIC125L
EIC125H
EIC126
EIC126L
EIC126H
EIC127
EIC127L
EIC127H
EIC128
EIC128L
EIC128H
EIC129
EIC129L
EIC129H
EIC130
EIC130L
EIC130H
EIC131
EIC131L
EIC131H
EIC132
EIC132L
EIC132H
EIC133
EIC133L
EIC133H
EIC134
EIC134L
EIC134H
EIC135
EIC135L
EIC135H
EIC136
EIC136L
EIC136H
EIC137
EIC137L
EIC137H
EIC138
EIC138L
EIC138H
EIC139
EIC139L
EIC139H
EIC140
EIC140L
EIC140H
EIC141
EIC141L
EIC141H
EIC142
EIC142L
EIC142H
EIC143
EIC143L
EIC143H
EIC144
EIC144L
EIC144H
EIC145
EIC145L
EIC145H
EIC146
EIC146L
EIC146H
EIC147
EIC147L
EIC147H
EIC148
EIC148L
EIC148H
EIC149
EIC149L
EIC149H
EIC150
EIC150L
EIC150H
EIC151
EIC151L
EIC151H
EIC152
EIC152L
EIC152H
EIC153
EIC153L
EIC153H
EIC154
EIC154L
EIC154H
EIC155
EIC155L
EIC155H
EIC156
EIC156L
EIC156H
EIC157
EIC157L
EIC157H
EIC158
EIC158L
EIC158H
EIC159
EIC159L
EIC159H
EIC160
EIC160L
EIC160H
EIC161
EIC161L
EIC161H
EIC162
EIC162L
EIC162H
EIC163
EIC163L
EIC163H
EIC164
EIC164L
EIC164H
EIC165
EIC165L
EIC165H
EIC166
EIC166L
EIC166H
EIC167
EIC167L
EIC167H
EIC168
EIC168L
EIC168H
EIC169
EIC169L
EIC169H
EIC170
EIC170L
EIC170H
EIC171
EIC171L
EIC171H
EIC172
EIC172L
EIC172H
EIC173
EIC173L
EIC173H
EIC174
EIC174L
EIC174H
EIC175
EIC175L
EIC175H
EIC176
EIC176L
EIC176H
EIC177
EIC177L
EIC177H
EIC178
EIC178L
EIC178H
EIC179
EIC179L
EIC179H
EIC180
EIC180L
EIC180H
EIC181
EIC181L
EIC181H
EIC182
EIC182L
EIC182H
EIC183
EIC183L
EIC183H
EIC184
EIC184L
EIC184H
EIC185
EIC185L
EIC185H
EIC186
EIC186L
EIC186H
EIC187
EIC187L
EIC187H
EIC188
EIC188L
EIC188H
EIC189
EIC189L
EIC189H
EIC190
EIC190L
EIC190H
EIC191
EIC191L
EIC191H
EIC192
EIC192L
EIC192H
EIC193
EIC193L
EIC193H
EIC194
EIC194L
EIC194H
EIC195
EIC195L
EIC195H
EIC196
EIC196L
EIC196H
EIC197
EIC197L
EIC197H
EIC198
EIC198L
EIC198H
EIC199
EIC199L
EIC199H
EIC200
EIC200L
EIC200H
EIC201
EIC201L
EIC201H
EIC202
EIC202L
EIC202H
EIC203
EIC203L
EIC203H
EIC204
EIC204L
EIC204H
EIC205
EIC205L
EIC205H
EIC206
EIC206L
EIC206H
EIC207
EIC207L
EIC207H
EIC208
EIC208L
EIC208H
EIC209
EIC209L
EIC209H
EIC210
EIC210L
EIC210H
EIC211
EIC211L
EIC211H
EIC212
EIC212L
EIC212H
EIC213
EIC213L
EIC213H
EIC214
EIC214L
EIC214H
EIC215
EIC215L
EIC215H
EIC216
EIC216L
EIC216H
EIC217
EIC217L
EIC217H
EIC218
EIC218L
EIC218H
EIC219
EIC219L
EIC219H
EIC220
EIC220L
EIC220H
EIC221
EIC221L
EIC221H
EIC222
EIC222L
EIC222H
EIC223
EIC223L
EIC223H
EIC224
EIC224L
EIC224H
EIC225
EIC225L
EIC225H
EIC226
EIC226L
EIC226H
EIC227
EIC227L
EIC227H
EIC228
EIC228L
EIC228H
EIC229
EIC229L
EIC229H
EIC230
EIC230L
EIC230H
EIC231
EIC231L
EIC231H
EIC232
EIC232L
EIC232H
EIC233
EIC233L
EIC233H
EIC234
EIC234L
EIC234H
EIC235
EIC235L
EIC235H
EIC236
EIC236L
EIC236H
EIC237
EIC237L
EIC237H
EIC238
EIC238L
EIC238H
EIC239
EIC239L
EIC239H
EIC240
EIC240L
EIC240H
EIC241
EIC241L
EIC241H
EIC242
EIC242L
EIC242H
EIC243
EIC243L
EIC243H
EIC244
EIC244L
EIC244H
EIC245
EIC245L
EIC245H
IMR1
IMR1L
IMR1LL
IMR1LH
IMR1H
IMR1HL
IMR1HH
IMR1EIMK32 ... IMR1EIMK63
IMR2
IMR2L
IMR2LL
IMR2LH
IMR2H
IMR2HL
IMR2HH
IMR2EIMK64 ... IMR2EIMK95
IMR3
IMR3L
IMR3LL
IMR3LH
IMR3H
IMR3HL
IMR3HH
IMR3EIMK96 ... IMR3EIMK127
IMR4
IMR4L
IMR4LL
IMR4LH
IMR4H
IMR4HL
IMR4HH
IMR4EIMK128 ... IMR4EIMK159
IMR5
IMR5L
IMR5LL
IMR5LH
IMR5H
IMR5HL
IMR5HH
IMR5EIMK160 ... IMR5EIMK191
IMR6
IMR6L
IMR6LL
IMR6LH
IMR6H
IMR6HL
IMR6HH
IMR6EIMK192 ... IMR6EIMK199
IMR6IMK200 ... IMR6IMK207
IMR6EIMK208 ... IMR6EIMK223
IMR7
IMR7L
IMR7LL
IMR7LH
IMR7H
IMR7HL
IMR7HH
IMR7EIMK224 ... IMR7EIMK255
EIBD32 ... EIBD245
FLMD.CNT
FLMD.PCMD
FLMD.PS
FACI0.FPMON
FACI0.FASTAT
FACI0.FAEINT
FACI0.FSADDR
FACI0.FEADDR
FACI0.FCURAME
FACI0.FRAMMCR
FACI0.FPROTDR0
FACI0.FPROTCR0 ... FACI0.FPROTCR4
FACI0.FSTATR
FACI0.FENTRYR
FACI0.FSUINITR
FACI0.FLKSTAT
FACI0.FRFSTEADR
FACI0.FRTSTAT
FACI0.FRTEINT
FACI0.FCMDR
FACI0.FRAMECCR
FACI0.FPESTAT
FACI0.FCNFPRGCNT
FACI0.FBCCNT
FACI0.FBCSTAT
FACI0.FPSADDR
FACI0.FCPSR
FACI0.FPCKAR
FACI0.FECCEMON
FACI0.FECCTMD
FACI0.FDMYECC
FACI1.FPMON
FACI1.FASTAT
FACI1.FAEINT
FACI1.FSADDR
FACI1.FEADDR
FACI1.FCURAME
FACI1.FRAMMCR
FACI1.FPROTDR0
FACI1.FPROTCR0 ... FACI1.FPROTCR4
FACI1.FSTATR
FACI1.FENTRYR
FACI1.FSUINITR
FACI1.FLKSTAT
FACI1.FRFSTEADR
FACI1.FRTSTAT
FACI1.FRTEINT
FACI1.FCMDR
FACI1.FRAMECCR
FACI1.FPESTAT
FACI1.FCNFPRGCNT
FACI1.FBCCNT
FACI1.FBCSTAT
FACI1.FPSADDR
FACI1.FCPSR
FACI1.FPCKAR
FACI1.FECCEMON
FACI1.FECCTMD
FACI1.FDMYECC
DNFA2.CTL.UINT8
DNFA2.CTL.BIT.PRS0 ... DNFA2.CTL.BIT.PRS2
DNFA2.CTL.BIT.NFSTS0
DNFA2.CTL.BIT.NFSTS1
DNFA2.EN
DNFA2.ENL.UINT8
DNFA2.ENL.BIT.NFENL0
DNFA2.ENL.BIT.NFENL1
DNFA3.CTL.UINT8
DNFA3.CTL.BIT.PRS0 ... DNFA3.CTL.BIT.PRS2
DNFA3.CTL.BIT.NFSTS0
DNFA3.CTL.BIT.NFSTS1
DNFA3.EN
DNFA3.ENL.UINT8
DNFA3.ENL.BIT.NFENL0
DNFA3.ENL.BIT.NFENL1
DNFA4.CTL.UINT8
DNFA4.CTL.BIT.PRS0 ... DNFA4.CTL.BIT.PRS2
DNFA4.CTL.BIT.NFSTS0
DNFA4.CTL.BIT.NFSTS1
DNFA4.EN
DNFA4.ENL.UINT8
DNFA4.ENL.BIT.NFENL0
DNFA4.ENL.BIT.NFENL1
DNFA5.CTL.UINT8
DNFA5.CTL.BIT.PRS0 ... DNFA5.CTL.BIT.PRS2
DNFA5.CTL.BIT.NFSTS0
DNFA5.CTL.BIT.NFSTS1
DNFA5.EN
DNFA5.ENL.UINT8
DNFA5.ENL.BIT.NFENL0 ... DNFA5.ENL.BIT.NFENL7
DNFA6.CTL.UINT8
DNFA6.CTL.BIT.PRS0 ... DNFA6.CTL.BIT.PRS2
DNFA6.CTL.BIT.NFSTS0
DNFA6.CTL.BIT.NFSTS1
DNFA6.EN
DNFA6.ENL.UINT8
DNFA6.ENL.BIT.NFENL0
DNFA6.ENL.BIT.NFENL1
DNFA7.CTL.UINT8
DNFA7.CTL.BIT.PRS0 ... DNFA7.CTL.BIT.PRS2
DNFA7.CTL.BIT.NFSTS0
DNFA7.CTL.BIT.NFSTS1
DNFA7.EN
DNFA7.ENL.UINT8
DNFA7.ENL.BIT.NFENL0
DNFA7.ENL.BIT.NFENL1
FCLA0.CTL0.UINT8
FCLA0.CTL0.BIT.INTR0
FCLA0.CTL0.BIT.INTF0
FCLA0.CTL0.BIT.INTL0
FCLA0.CTL1.UINT8
FCLA0.CTL1.BIT.INTR1
FCLA0.CTL1.BIT.INTF1
FCLA0.CTL1.BIT.INTL1
FCLA0.CTL2.UINT8
FCLA0.CTL2.BIT.INTR2
FCLA0.CTL2.BIT.INTF2
FCLA0.CTL2.BIT.INTL2
FCLA0.CTL3.UINT8
FCLA0.CTL3.BIT.INTR3
FCLA0.CTL3.BIT.INTF3
FCLA0.CTL3.BIT.INTL3
FCLA0.CTL4.UINT8
FCLA0.CTL4.BIT.INTR4
FCLA0.CTL4.BIT.INTF4
FCLA0.CTL4.BIT.INTL4
FCLA0.CTL5.UINT8
FCLA0.CTL5.BIT.INTR5
FCLA0.CTL5.BIT.INTF5
FCLA0.CTL5.BIT.INTL5
FCLA0.CTL6.UINT8
FCLA0.CTL6.BIT.INTR6
FCLA0.CTL6.BIT.INTF6
FCLA0.CTL6.BIT.INTL6
FCLA0.CTL7.UINT8
FCLA0.CTL7.BIT.INTR7
FCLA0.CTL7.BIT.INTF7
FCLA0.CTL7.BIT.INTL7
FCLA1.CTL0.UINT8
FCLA1.CTL0.BIT.INTR0
FCLA1.CTL0.BIT.INTF0
FCLA1.CTL0.BIT.INTL0
FCLA1.CTL1.UINT8
FCLA1.CTL1.BIT.INTR1
FCLA1.CTL1.BIT.INTF1
FCLA1.CTL1.BIT.INTL1
FCLA1.CTL2.UINT8
FCLA1.CTL2.BIT.INTR2
FCLA1.CTL2.BIT.INTF2
FCLA1.CTL2.BIT.INTL2
FCLA1.CTL3.UINT8
FCLA1.CTL3.BIT.INTR3
FCLA1.CTL3.BIT.INTF3
FCLA1.CTL3.BIT.INTL3
FCLA1.CTL4.UINT8
FCLA1.CTL4.BIT.INTR4
FCLA1.CTL4.BIT.INTF4
FCLA1.CTL4.BIT.INTL4
FCLA2.CTL0.UINT8
FCLA2.CTL0.BIT.INTR0
FCLA2.CTL0.BIT.INTF0
FCLA2.CTL1.UINT8
FCLA2.CTL1.BIT.INTR1
FCLA2.CTL1.BIT.INTF1
FCLA3.CTL0.UINT8
FCLA3.CTL0.BIT.INTR0
FCLA3.CTL0.BIT.INTF0
FCLA3.CTL1.UINT8
FCLA3.CTL1.BIT.INTR1
FCLA3.CTL1.BIT.INTF1
FCLA4.CTL0.UINT8
FCLA4.CTL0.BIT.INTR0
FCLA4.CTL0.BIT.INTF0
FCLA4.CTL1.UINT8
FCLA4.CTL1.BIT.INTR1
FCLA4.CTL1.BIT.INTF1
FCLA5.CTL0.UINT8
FCLA5.CTL0.BIT.BYPS0
FCLA5.CTL1.UINT8
FCLA5.CTL1.BIT.BYPS1
FCLA5.CTL2.UINT8
FCLA5.CTL2.BIT.BYPS2
FCLA5.CTL3.UINT8
FCLA5.CTL3.BIT.BYPS3
FCLA5.CTL4.UINT8
FCLA5.CTL4.BIT.BYPS4
FCLA5.CTL5.UINT8
FCLA5.CTL5.BIT.BYPS5
FCLA5.CTL6.UINT8
FCLA5.CTL6.BIT.BYPS6
FCLA5.CTL7.UINT8
FCLA5.CTL7.BIT.BYPS7
FCLA6.CTL0.UINT8
FCLA6.CTL0.BIT.BYPS0
FCLA6.CTL1.UINT8
FCLA6.CTL1.BIT.BYPS1
FSGD5A.PROT00.UINT32
FSGD5A.PROT00.UINT16[L/H]
FSGD5A.PROT00.UINT8[LL/LH/HL/HH]
FSGD5A.SPID00.UINT32
FSGD5A.SPID00.UINT16[L/H]
FSGD5A.SPID00.UINT8[LL/LH/HL/HH]
FSGD5A.PROT01.UINT32
FSGD5A.PROT01.UINT16[L/H]
FSGD5A.PROT01.UINT8[LL/LH/HL/HH]
FSGD5A.SPID01.UINT32
FSGD5A.SPID01.UINT16[L/H]
FSGD5A.SPID01.UINT8[LL/LH/HL/HH]
FSGD5A.PROT02.UINT32
FSGD5A.PROT02.UINT16[L/H]
FSGD5A.PROT02.UINT8[LL/LH/HL/HH]
FSGD5A.SPID02.UINT32
FSGD5A.SPID02.UINT16[L/H]
FSGD5A.SPID02.UINT8[LL/LH/HL/HH]
FSGD5A.PROT03.UINT32
FSGD5A.PROT03.UINT16[L/H]
FSGD5A.PROT03.UINT8[LL/LH/HL/HH]
FSGD5A.SPID03.UINT32
FSGD5A.SPID03.UINT16[L/H]
FSGD5A.SPID03.UINT8[LL/LH/HL/HH]
FSGD5A.PROT04.UINT32
FSGD5A.PROT04.UINT16[L/H]
FSGD5A.PROT04.UINT8[LL/LH/HL/HH]
FSGD5A.SPID04.UINT32
FSGD5A.SPID04.UINT16[L/H]
FSGD5A.SPID04.UINT8[LL/LH/HL/HH]
FSGD5A.PROT05.UINT32
FSGD5A.PROT05.UINT16[L/H]
FSGD5A.PROT05.UINT8[LL/LH/HL/HH]
FSGD5A.SPID05.UINT32
FSGD5A.SPID05.UINT16[L/H]
FSGD5A.SPID05.UINT8[LL/LH/HL/HH]
ERRSLV5A.CTL
ERRSLV5A.STAT
ERRSLV5A.TYPE
FSGD5B.PROT00.UINT32
FSGD5B.PROT00.UINT16[L/H]
FSGD5B.PROT00.UINT8[LL/LH/HL/HH]
FSGD5B.SPID00.UINT32
FSGD5B.SPID00.UINT16[L/H]
FSGD5B.SPID00.UINT8[LL/LH/HL/HH]
FSGD5B.PROT01.UINT32
FSGD5B.PROT01.UINT16[L/H]
FSGD5B.PROT01.UINT8[LL/LH/HL/HH]
FSGD5B.SPID01.UINT32
FSGD5B.SPID01.UINT16[L/H]
FSGD5B.SPID01.UINT8[LL/LH/HL/HH]
FSGD5B.PROT02.UINT32
FSGD5B.PROT02.UINT16[L/H]
FSGD5B.PROT02.UINT8[LL/LH/HL/HH]
FSGD5B.SPID02.UINT32
FSGD5B.SPID02.UINT16[L/H]
FSGD5B.SPID02.UINT8[LL/LH/HL/HH]
FSGD5B.PROT03.UINT32
FSGD5B.PROT03.UINT16[L/H]
FSGD5B.PROT03.UINT8[LL/LH/HL/HH]
FSGD5B.SPID03.UINT32
FSGD5B.SPID03.UINT16[L/H]
FSGD5B.SPID03.UINT8[LL/LH/HL/HH]
ERRSLV5B.CTL
ERRSLV5B.STAT
ERRSLV5B.TYPE
FSGD5C.PROT00.UINT32
FSGD5C.PROT00.UINT16[L/H]
FSGD5C.PROT00.UINT8[LL/LH/HL/HH]
FSGD5C.SPID00.UINT32
FSGD5C.SPID00.UINT16[L/H]
FSGD5C.SPID00.UINT8[LL/LH/HL/HH]
FSGD5C.PROT01.UINT32
FSGD5C.PROT01.UINT16[L/H]
FSGD5C.PROT01.UINT8[LL/LH/HL/HH]
FSGD5C.SPID01.UINT32
FSGD5C.SPID01.UINT16[L/H]
FSGD5C.SPID01.UINT8[LL/LH/HL/HH]
ERRSLV5C.CTL
ERRSLV5C.STAT
ERRSLV5C.TYPE
FSGD5D.PROT00.UINT32
FSGD5D.PROT00.UINT16[L/H]
FSGD5D.PROT00.UINT8[LL/LH/HL/HH]
FSGD5D.SPID00.UINT32
FSGD5D.SPID00.UINT16[L/H]
FSGD5D.SPID00.UINT8[LL/LH/HL/HH]
FSGD5D.PROT01.UINT32
FSGD5D.PROT01.UINT16[L/H]
FSGD5D.PROT01.UINT8[LL/LH/HL/HH]
FSGD5D.SPID01.UINT32
FSGD5D.SPID01.UINT16[L/H]
FSGD5D.SPID01.UINT8[LL/LH/HL/HH]
FSGD5D.PROT02.UINT32
FSGD5D.PROT02.UINT16[L/H]
FSGD5D.PROT02.UINT8[LL/LH/HL/HH]
FSGD5D.SPID02.UINT32
FSGD5D.SPID02.UINT16[L/H]
FSGD5D.SPID02.UINT8[LL/LH/HL/HH]
FSGD5D.PROT03.UINT32
FSGD5D.PROT03.UINT16[L/H]
FSGD5D.PROT03.UINT8[LL/LH/HL/HH]
FSGD5D.SPID03.UINT32
FSGD5D.SPID03.UINT16[L/H]
FSGD5D.SPID03.UINT8[LL/LH/HL/HH]
ERRSLV5D.CTL
ERRSLV5D.STAT
ERRSLV5D.TYPE
ERRSLV5AI.CTL
ERRSLV5AI.STAT
ERRSLV5AI.TYPE
ERRSLV5BI.CTL
ERRSLV5BI.STAT
ERRSLV5BI.TYPE
ERRSLVDG0.CTL
ERRSLVDG0.STAT
ERRSLVDG0.TYPE
ERRSLVDG1.CTL
ERRSLVDG1.STAT
ERRSLVDG1.TYPE
ECCCSIH0.CTL
ECCCSIH0.TMC
ECCCSIH0.TRC
ECCCSIH0.TED
ECCCSIH0.EAD0
ECCCSIH2.CTL
ECCCSIH2.TMC
ECCCSIH2.TRC
ECCCSIH2.TED
ECCCSIH2.EAD0
ECCTTCAN0.CTL
ECCTTCAN0.TMC
ECCTTCAN0.TRC
ECCTTCAN0.TED
ECCTTCAN0.EAD0
ECCMCAN1.CTL
ECCMCAN1.TMC
ECCMCAN1.TRC
ECCMCAN1.TED
ECCMCAN1.EAD0
ECCFLX0.CTL
ECCFLX0.TMC
ECCFLX0.TRC
ECCFLX0.TED
ECCFLX0.EAD0
ECCFLX0T0.CTL
ECCFLX0T0.TMC
ECCFLX0T0.TRC
ECCFLX0T0.TED
ECCFLX0T0.EAD0
ECCFLX0T1.CTL
ECCFLX0T1.TMC
ECCFLX0T1.TRC
ECCFLX0T1.TED
ECCFLX0T1.EAD0
ECCCSIH1.CTL
ECCCSIH1.TMC
ECCCSIH1.TRC
ECCCSIH1.TED
ECCCSIH1.EAD0
ECCCSIH3.CTL
ECCCSIH3.TMC
ECCCSIH3.TRC
ECCCSIH3.TED
ECCCSIH3.EAD0
ECCMCAN0.CTL
ECCMCAN0.TMC
ECCMCAN0.TRC
ECCMCAN0.TED
ECCMCAN0.EAD0
CSIH1.CTL0.UINT8
CSIH1.CTL0.BIT.MBS
CSIH1.CTL0.BIT.JOBE
CSIH1.CTL0.BIT.RXE
CSIH1.CTL0.BIT.TXE
CSIH1.CTL0.BIT.PWR
CSIH1.CTL1
CSIH1.CTL2
CSIH1.MCTL1
CSIH1.MCTL2
CSIH1.TX0W
CSIH1.TX0H
CSIH1.RX0W
CSIH1.RX0H
CSIH1.MRWP0
CSIH1.STR0
CSIH1.STCR0
CSIH1.MCTL0
CSIH1.CFG0 ... CSIH1.CFG7
CSIH1.BRS0 ... CSIH1.BRS3
PMMA1.CTL
PMMA1.TCTL0 ... PMMA1.TCTL7
PMMA1.TTX0 ... PMMA1.TTX7
PMMA1.RX
PMMA1.TCNT0 ... PMMA1.TCNT7
PMMA1.STR0
PMMA1.STR1
PMMA1.STC
CSIH3.CTL0.UINT8
CSIH3.CTL0.BIT.MBS
CSIH3.CTL0.BIT.JOBE
CSIH3.CTL0.BIT.RXE
CSIH3.CTL0.BIT.TXE
CSIH3.CTL0.BIT.PWR
CSIH3.CTL1
CSIH3.CTL2
CSIH3.MCTL1
CSIH3.MCTL2
CSIH3.TX0W
CSIH3.TX0H
CSIH3.RX0W
CSIH3.RX0H
CSIH3.MRWP0
CSIH3.STR0
CSIH3.STCR0
CSIH3.MCTL0
CSIH3.CFG0 ... CSIH3.CFG7
CSIH3.BRS0 ... CSIH3.BRS3
PMMA3.CTL
PMMA3.TCTL0 ... PMMA3.TCTL7
PMMA3.TTX0 ... PMMA3.TTX7
PMMA3.RX
PMMA3.TCNT0 ... PMMA3.TCNT7
PMMA3.STR0
PMMA3.STR1
PMMA3.STC
HSUS1.CKEN
HSUS1.SRST
HSUS1.EN
HSUS1.MD
HSUS1.CTL
HSUS1.TDIV
HSUS1.TSAR
HSUS1.TPFM
HSUS1.RDAR
HSUS1.RPFM
HSUS1.RGFM
HSUS1.IREN
HSUS1.IRST
HSUS1.IRCL.UINT32
HSUS1.IRCL.UINT16[L]
HSUS1.IRCL.UINT8[LL]
HSUS1.CST
HSUS1.CTFM
HSUS1.CRFM
RLN31.LWBR
RLN31.LBRP01.UINT16
RLN31.LBRP01.UINT8[L/H]
RLN31.LBRP01.REGS8.LBRP0.UINT8
RLN31.LBRP01.REGS8.LBRP1.UINT8
RLN31.LSTC
RLN31.LMD
RLN31.LBFC
RLN31.LSC
RLN31.LWUP
RLN31.LIE
RLN31.LEDE
RLN31.LCUC
RLN31.LTRC
RLN31.LMST
RLN31.LST
RLN31.LEST
RLN31.LDFC
RLN31.LIDB
RLN31.LCBR
RLN31.LUDB0
RLN31.LDBR1 ... RLN31.LDBR8
RLN31.LUOER
RLN31.LUOR1
RLN31.LUTDR.UINT16
RLN31.LUTDR.UINT8[L/H]
RLN31.LURDR.UINT16
RLN31.LURDR.UINT8[L/H]
RLN31.LUWTDR.UINT16
RLN31.LUWTDR.UINT8[L/H]
RSENT0.TSPC.UINT32
RSENT0.TSPC.UINT16[L/H]
RSENT0.TSPC.UINT8[LL/LH/HL]
RSENT0.TSC.UINT32
RSENT0.TSC.UINT16[L/H]
RSENT0.TSC.UINT8[LL/LH/HL/HH]
RSENT0.CC.UINT32
RSENT0.CC.UINT16[L]
RSENT0.CC.UINT8[LL/LH]
RSENT0.BRP.UINT32
RSENT0.BRP.UINT16[L/H]
RSENT0.BRP.UINT8[LL/LH/HL/HH]
RSENT0.IDE.UINT32
RSENT0.IDE.UINT16[L]
RSENT0.IDE.UINT8[LL/LH]
RSENT0.MDC.UINT32
RSENT0.MDC.UINT16[L]
RSENT0.MDC.UINT8[LL]
RSENT0.SPCT.UINT32
RSENT0.SPCT.UINT16[L]
RSENT0.SPCT.UINT8[LL]
RSENT0.MST.UINT32
RSENT0.MST.UINT16[L]
RSENT0.MST.UINT8[LL]
RSENT0.CS.UINT32
RSENT0.CS.UINT16[L]
RSENT0.CS.UINT8[LL/LH]
RSENT0.CSC.UINT32
RSENT0.CSC.UINT16[L]
RSENT0.CSC.UINT8[LL/LH]
RSENT0.SRTS.UINT32
RSENT0.SRTS.UINT16[L/H]
RSENT0.SRTS.UINT8[LL/LH/HL/HH]
RSENT0.SRXD
RSENT0.CPL.UINT32
RSENT0.CPL.UINT16[L/H]
RSENT0.CPL.UINT8[LL/LH/HL]
RSENT0.ML.UINT32
RSENT0.ML.UINT16[L/H]
RSENT0.ML.UINT8[LL/LH/HL]
RSENT0.FRTS.UINT32
RSENT0.FRTS.UINT16[L/H]
RSENT0.FRTS.UINT8[LL/LH/HL/HH]
RSENT0.FRXD
RSENT1.TSPC.UINT32
RSENT1.TSPC.UINT16[L/H]
RSENT1.TSPC.UINT8[LL/LH/HL]
RSENT1.TSC.UINT32
RSENT1.TSC.UINT16[L/H]
RSENT1.TSC.UINT8[LL/LH/HL/HH]
RSENT1.CC.UINT32
RSENT1.CC.UINT16[L]
RSENT1.CC.UINT8[LL/LH]
RSENT1.BRP.UINT32
RSENT1.BRP.UINT16[L/H]
RSENT1.BRP.UINT8[LL/LH/HL/HH]
RSENT1.IDE.UINT32
RSENT1.IDE.UINT16[L]
RSENT1.IDE.UINT8[LL/LH]
RSENT1.MDC.UINT32
RSENT1.MDC.UINT16[L]
RSENT1.MDC.UINT8[LL]
RSENT1.SPCT.UINT32
RSENT1.SPCT.UINT16[L]
RSENT1.SPCT.UINT8[LL]
RSENT1.MST.UINT32
RSENT1.MST.UINT16[L]
RSENT1.MST.UINT8[LL]
RSENT1.CS.UINT32
RSENT1.CS.UINT16[L]
RSENT1.CS.UINT8[LL/LH]
RSENT1.CSC.UINT32
RSENT1.CSC.UINT16[L]
RSENT1.CSC.UINT8[LL/LH]
RSENT1.SRTS.UINT32
RSENT1.SRTS.UINT16[L/H]
RSENT1.SRTS.UINT8[LL/LH/HL/HH]
RSENT1.SRXD
RSENT1.CPL.UINT32
RSENT1.CPL.UINT16[L/H]
RSENT1.CPL.UINT8[LL/LH/HL]
RSENT1.ML.UINT32
RSENT1.ML.UINT16[L/H]
RSENT1.ML.UINT8[LL/LH/HL]
RSENT1.FRTS.UINT32
RSENT1.FRTS.UINT16[L/H]
RSENT1.FRTS.UINT8[LL/LH/HL/HH]
RSENT1.FRXD
RSENT2.TSPC.UINT32
RSENT2.TSPC.UINT16[L/H]
RSENT2.TSPC.UINT8[LL/LH/HL]
RSENT2.TSC.UINT32
RSENT2.TSC.UINT16[L/H]
RSENT2.TSC.UINT8[LL/LH/HL/HH]
RSENT2.CC.UINT32
RSENT2.CC.UINT16[L]
RSENT2.CC.UINT8[LL/LH]
RSENT2.BRP.UINT32
RSENT2.BRP.UINT16[L/H]
RSENT2.BRP.UINT8[LL/LH/HL/HH]
RSENT2.IDE.UINT32
RSENT2.IDE.UINT16[L]
RSENT2.IDE.UINT8[LL/LH]
RSENT2.MDC.UINT32
RSENT2.MDC.UINT16[L]
RSENT2.MDC.UINT8[LL]
RSENT2.SPCT.UINT32
RSENT2.SPCT.UINT16[L]
RSENT2.SPCT.UINT8[LL]
RSENT2.MST.UINT32
RSENT2.MST.UINT16[L]
RSENT2.MST.UINT8[LL]
RSENT2.CS.UINT32
RSENT2.CS.UINT16[L]
RSENT2.CS.UINT8[LL/LH]
RSENT2.CSC.UINT32
RSENT2.CSC.UINT16[L]
RSENT2.CSC.UINT8[LL/LH]
RSENT2.SRTS.UINT32
RSENT2.SRTS.UINT16[L/H]
RSENT2.SRTS.UINT8[LL/LH/HL/HH]
RSENT2.SRXD
RSENT2.CPL.UINT32
RSENT2.CPL.UINT16[L/H]
RSENT2.CPL.UINT8[LL/LH/HL]
RSENT2.ML.UINT32
RSENT2.ML.UINT16[L/H]
RSENT2.ML.UINT8[LL/LH/HL]
RSENT2.FRTS.UINT32
RSENT2.FRTS.UINT16[L/H]
RSENT2.FRTS.UINT8[LL/LH/HL/HH]
RSENT2.FRXD
RSENT3.TSPC.UINT32
RSENT3.TSPC.UINT16[L/H]
RSENT3.TSPC.UINT8[LL/LH/HL]
RSENT3.TSC.UINT32
RSENT3.TSC.UINT16[L/H]
RSENT3.TSC.UINT8[LL/LH/HL/HH]
RSENT3.CC.UINT32
RSENT3.CC.UINT16[L]
RSENT3.CC.UINT8[LL/LH]
RSENT3.BRP.UINT32
RSENT3.BRP.UINT16[L/H]
RSENT3.BRP.UINT8[LL/LH/HL/HH]
RSENT3.IDE.UINT32
RSENT3.IDE.UINT16[L]
RSENT3.IDE.UINT8[LL/LH]
RSENT3.MDC.UINT32
RSENT3.MDC.UINT16[L]
RSENT3.MDC.UINT8[LL]
RSENT3.SPCT.UINT32
RSENT3.SPCT.UINT16[L]
RSENT3.SPCT.UINT8[LL]
RSENT3.MST.UINT32
RSENT3.MST.UINT16[L]
RSENT3.MST.UINT8[LL]
RSENT3.CS.UINT32
RSENT3.CS.UINT16[L]
RSENT3.CS.UINT8[LL/LH]
RSENT3.CSC.UINT32
RSENT3.CSC.UINT16[L]
RSENT3.CSC.UINT8[LL/LH]
RSENT3.SRTS.UINT32
RSENT3.SRTS.UINT16[L/H]
RSENT3.SRTS.UINT8[LL/LH/HL/HH]
RSENT3.SRXD
RSENT3.CPL.UINT32
RSENT3.CPL.UINT16[L/H]
RSENT3.CPL.UINT8[LL/LH/HL]
RSENT3.ML.UINT32
RSENT3.ML.UINT16[L/H]
RSENT3.ML.UINT8[LL/LH/HL]
RSENT3.FRTS.UINT32
RSENT3.FRTS.UINT16[L/H]
RSENT3.FRTS.UINT8[LL/LH/HL/HH]
RSENT3.FRXD
RSENT4.TSPC.UINT32
RSENT4.TSPC.UINT16[L/H]
RSENT4.TSPC.UINT8[LL/LH/HL]
RSENT4.TSC.UINT32
RSENT4.TSC.UINT16[L/H]
RSENT4.TSC.UINT8[LL/LH/HL/HH]
RSENT4.CC.UINT32
RSENT4.CC.UINT16[L]
RSENT4.CC.UINT8[LL/LH]
RSENT4.BRP.UINT32
RSENT4.BRP.UINT16[L/H]
RSENT4.BRP.UINT8[LL/LH/HL/HH]
RSENT4.IDE.UINT32
RSENT4.IDE.UINT16[L]
RSENT4.IDE.UINT8[LL/LH]
RSENT4.MDC.UINT32
RSENT4.MDC.UINT16[L]
RSENT4.MDC.UINT8[LL]
RSENT4.SPCT.UINT32
RSENT4.SPCT.UINT16[L]
RSENT4.SPCT.UINT8[LL]
RSENT4.MST.UINT32
RSENT4.MST.UINT16[L]
RSENT4.MST.UINT8[LL]
RSENT4.CS.UINT32
RSENT4.CS.UINT16[L]
RSENT4.CS.UINT8[LL/LH]
RSENT4.CSC.UINT32
RSENT4.CSC.UINT16[L]
RSENT4.CSC.UINT8[LL/LH]
RSENT4.SRTS.UINT32
RSENT4.SRTS.UINT16[L/H]
RSENT4.SRTS.UINT8[LL/LH/HL/HH]
RSENT4.SRXD
RSENT4.CPL.UINT32
RSENT4.CPL.UINT16[L/H]
RSENT4.CPL.UINT8[LL/LH/HL]
RSENT4.ML.UINT32
RSENT4.ML.UINT16[L/H]
RSENT4.ML.UINT8[LL/LH/HL]
RSENT4.FRTS.UINT32
RSENT4.FRTS.UINT16[L/H]
RSENT4.FRTS.UINT8[LL/LH/HL/HH]
RSENT4.FRXD
RSENT5.TSPC.UINT32
RSENT5.TSPC.UINT16[L/H]
RSENT5.TSPC.UINT8[LL/LH/HL]
RSENT5.TSC.UINT32
RSENT5.TSC.UINT16[L/H]
RSENT5.TSC.UINT8[LL/LH/HL/HH]
RSENT5.CC.UINT32
RSENT5.CC.UINT16[L]
RSENT5.CC.UINT8[LL/LH]
RSENT5.BRP.UINT32
RSENT5.BRP.UINT16[L/H]
RSENT5.BRP.UINT8[LL/LH/HL/HH]
RSENT5.IDE.UINT32
RSENT5.IDE.UINT16[L]
RSENT5.IDE.UINT8[LL/LH]
RSENT5.MDC.UINT32
RSENT5.MDC.UINT16[L]
RSENT5.MDC.UINT8[LL]
RSENT5.SPCT.UINT32
RSENT5.SPCT.UINT16[L]
RSENT5.SPCT.UINT8[LL]
RSENT5.MST.UINT32
RSENT5.MST.UINT16[L]
RSENT5.MST.UINT8[LL]
RSENT5.CS.UINT32
RSENT5.CS.UINT16[L]
RSENT5.CS.UINT8[LL/LH]
RSENT5.CSC.UINT32
RSENT5.CSC.UINT16[L]
RSENT5.CSC.UINT8[LL/LH]
RSENT5.SRTS.UINT32
RSENT5.SRTS.UINT16[L/H]
RSENT5.SRTS.UINT8[LL/LH/HL/HH]
RSENT5.SRXD
RSENT5.CPL.UINT32
RSENT5.CPL.UINT16[L/H]
RSENT5.CPL.UINT8[LL/LH/HL]
RSENT5.ML.UINT32
RSENT5.ML.UINT16[L/H]
RSENT5.ML.UINT8[LL/LH/HL]
RSENT5.FRTS.UINT32
RSENT5.FRTS.UINT16[L/H]
RSENT5.FRTS.UINT8[LL/LH/HL/HH]
RSENT5.FRXD
RSENT6.TSPC
SINT.R0 ... SINT.R2
MTTCAN0.CREL.UINT32
MTTCAN0.CREL.UINT16[L/H]
MTTCAN0.CREL.UINT8[LL/LH/HL/HH]
MTTCAN0.ENDN.UINT32
MTTCAN0.ENDN.UINT16[L/H]
MTTCAN0.ENDN.UINT8[LL/LH/HL/HH]
MTTCAN0.DBTP.UINT32
MTTCAN0.DBTP.UINT32
MTTCAN0.DBTP.UINT16[L/H]
MTTCAN0.DBTP.UINT8[LL/LH/HL/HH]
MTTCAN0.DBTP.REGS16.FBTPL.UINT16
MTTCAN0.DBTP.REGS16.FBTPH.UINT16
MTTCAN0.TEST.UINT32
MTTCAN0.TEST.UINT16[L]
MTTCAN0.TEST.UINT8[LL/LH]
MTTCAN0.RWD.UINT32
MTTCAN0.RWD.UINT16[L]
MTTCAN0.RWD.UINT8[LL/LH]
MTTCAN0.CCCR.UINT32
MTTCAN0.CCCR.UINT16[L]
MTTCAN0.CCCR.UINT8[LL/LH]
MTTCAN0.BTP.UINT32
MTTCAN0.BTP.UINT32
MTTCAN0.BTP.UINT16[L/H]
MTTCAN0.BTP.UINT8[LL/LH/HL/HH]
MTTCAN0.TSCV.UINT32
MTTCAN0.TSCV.UINT16[L]
MTTCAN0.TSCV.UINT8[LL/LH]
MTTCAN0.TOCC.UINT32
MTTCAN0.TOCC.UINT16[L/H]
MTTCAN0.TOCC.UINT8[LL/LH/HL/HH]
MTTCAN0.TOCV.UINT32
MTTCAN0.TOCV.UINT16[L]
MTTCAN0.TOCV.UINT8[LL/LH]
MTTCAN0.ECR.UINT32
MTTCAN0.ECR.UINT16[L/H]
MTTCAN0.ECR.UINT8[LL/LH/HL/HH]
MTTCAN0.PSR.UINT32
MTTCAN0.PSR.UINT16[L]
MTTCAN0.PSR.UINT8[LL/LH]
MTTCAN0.TDCR.UINT32
MTTCAN0.TDCR.UINT16[L]
MTTCAN0.TDCR.UINT8[LL/LH]
MTTCAN0.IR.UINT32
MTTCAN0.IR.UINT16[L/H]
MTTCAN0.IR.UINT8[LL/LH/HL/HH]
MTTCAN0.IE.UINT32
MTTCAN0.IE.UINT16[L/H]
MTTCAN0.IE.UINT8[LL/LH/HL/HH]
MTTCAN0.ILS.UINT32
MTTCAN0.ILS.UINT16[L/H]
MTTCAN0.ILS.UINT8[LL/LH/HL/HH]
MTTCAN0.ILE.UINT32
MTTCAN0.ILE.UINT16[L]
MTTCAN0.ILE.UINT8[LL/LH]
MTTCAN0.GFC.UINT32
MTTCAN0.GFC.UINT16[L]
MTTCAN0.GFC.UINT8[LL/LH]
MTTCAN0.SIDFC.UINT32
MTTCAN0.SIDFC.UINT16[L/H]
MTTCAN0.SIDFC.UINT8[LL/LH/HL/HH]
MTTCAN0.XIDFC.UINT32
MTTCAN0.XIDFC.UINT16[L/H]
MTTCAN0.XIDFC.UINT8[LL/LH/HL/HH]
MTTCAN0.XIDAM.UINT32
MTTCAN0.XIDAM.UINT16[L/H]
MTTCAN0.XIDAM.UINT8[LL/LH/HL/HH]
MTTCAN0.HPMS.UINT32
MTTCAN0.HPMS.UINT16[L]
MTTCAN0.HPMS.UINT8[LL/LH]
MTTCAN0.NDAT1.UINT32
MTTCAN0.NDAT1.UINT16[L/H]
MTTCAN0.NDAT1.UINT8[LL/LH/HL/HH]
MTTCAN0.NDAT2.UINT32
MTTCAN0.NDAT2.UINT16[L/H]
MTTCAN0.NDAT2.UINT8[LL/LH/HL/HH]
MTTCAN0.RXF0C.UINT32
MTTCAN0.RXF0C.UINT16[L/H]
MTTCAN0.RXF0C.UINT8[LL/LH/HL/HH]
MTTCAN0.RXF0S.UINT32
MTTCAN0.RXF0S.UINT16[L/H]
MTTCAN0.RXF0S.UINT8[LL/LH/HL/HH]
MTTCAN0.RXF0A.UINT32
MTTCAN0.RXF0A.UINT16[L]
MTTCAN0.RXF0A.UINT8[LL/LH]
MTTCAN0.RXBC.UINT32
MTTCAN0.RXBC.UINT16[L]
MTTCAN0.RXBC.UINT8[LL/LH]
MTTCAN0.RXF1C.UINT32
MTTCAN0.RXF1C.UINT16[L/H]
MTTCAN0.RXF1C.UINT8[LL/LH/HL/HH]
MTTCAN0.RXF1S.UINT32
MTTCAN0.RXF1S.UINT16[L/H]
MTTCAN0.RXF1S.UINT8[LL/LH/HL/HH]
MTTCAN0.RXF1A.UINT32
MTTCAN0.RXF1A.UINT16[L]
MTTCAN0.RXF1A.UINT8[LL/LH]
MTTCAN0.RXESC.UINT32
MTTCAN0.RXESC.UINT16[L]
MTTCAN0.RXESC.UINT8[LL/LH]
MTTCAN0.TXBC.UINT32
MTTCAN0.TXBC.UINT16[L/H]
MTTCAN0.TXBC.UINT8[LL/LH/HL/HH]
MTTCAN0.TXFQS.UINT32
MTTCAN0.TXFQS.UINT16[L/H]
MTTCAN0.TXFQS.UINT8[LL/LH/HL/HH]
MTTCAN0.TXESC.UINT32
MTTCAN0.TXESC.UINT16[L]
MTTCAN0.TXESC.UINT8[LL/LH]
MTTCAN0.TXBRP.UINT32
MTTCAN0.TXBRP.UINT16[L/H]
MTTCAN0.TXBRP.UINT8[LL/LH/HL/HH]
MTTCAN0.TXBAR.UINT32
MTTCAN0.TXBAR.UINT16[L/H]
MTTCAN0.TXBAR.UINT8[LL/LH/HL/HH]
MTTCAN0.TXBCR.UINT32
MTTCAN0.TXBCR.UINT16[L/H]
MTTCAN0.TXBCR.UINT8[LL/LH/HL/HH]
MTTCAN0.TXBTO.UINT32
MTTCAN0.TXBTO.UINT16[L/H]
MTTCAN0.TXBTO.UINT8[LL/LH/HL/HH]
MTTCAN0.TXBCF.UINT32
MTTCAN0.TXBCF.UINT16[L/H]
MTTCAN0.TXBCF.UINT8[LL/LH/HL/HH]
MTTCAN0.TXBTIE.UINT32
MTTCAN0.TXBTIE.UINT16[L/H]
MTTCAN0.TXBTIE.UINT8[LL/LH/HL/HH]
MTTCAN0.TXBCIE.UINT32
MTTCAN0.TXBCIE.UINT16[L/H]
MTTCAN0.TXBCIE.UINT8[LL/LH/HL/HH]
MTTCAN0.TXEFC.UINT32
MTTCAN0.TXEFC.UINT16[L/H]
MTTCAN0.TXEFC.UINT8[LL/LH/HL/HH]
MTTCAN0.TXEFS.UINT32
MTTCAN0.TXEFS.UINT16[L/H]
MTTCAN0.TXEFS.UINT8[LL/LH/HL/HH]
MTTCAN0.TXEFA.UINT32
MTTCAN0.TXEFA.UINT16[L]
MTTCAN0.TXEFA.UINT8[LL/LH]
MTTCAN0.TTTMC.UINT32
MTTCAN0.TTTMC.UINT16[L/H]
MTTCAN0.TTTMC.UINT8[LL/LH/HL/HH]
MTTCAN0.TTRMC.UINT32
MTTCAN0.TTRMC.UINT16[L/H]
MTTCAN0.TTRMC.UINT8[LL/LH/HL/HH]
MTTCAN0.TTOCF.UINT32
MTTCAN0.TTOCF.UINT16[L/H]
MTTCAN0.TTOCF.UINT8[LL/LH/HL/HH]
MTTCAN0.TTMLM.UINT32
MTTCAN0.TTMLM.UINT16[L/H]
MTTCAN0.TTMLM.UINT8[LL/LH/HL/HH]
MTTCAN0.TURCF.UINT32
MTTCAN0.TURCF.UINT16[L/H]
MTTCAN0.TURCF.UINT8[LL/LH/HL/HH]
MTTCAN0.TTOCN.UINT32
MTTCAN0.TTOCN.UINT16[L]
MTTCAN0.TTOCN.UINT8[LL/LH]
MTTCAN0.TTGTP.UINT32
MTTCAN0.TTGTP.UINT16[L/H]
MTTCAN0.TTGTP.UINT8[LL/LH/HL/HH]
MTTCAN0.TTTMK.UINT32
MTTCAN0.TTTMK.UINT16[L/H]
MTTCAN0.TTTMK.UINT8[LL/LH/HL/HH]
MTTCAN0.TTIR.UINT32
MTTCAN0.TTIR.UINT16[L/H]
MTTCAN0.TTIR.UINT8[LL/LH/HL/HH]
MTTCAN0.TTIE.UINT32
MTTCAN0.TTIE.UINT16[L/H]
MTTCAN0.TTIE.UINT8[LL/LH/HL/HH]
MTTCAN0.TTILS.UINT32
MTTCAN0.TTILS.UINT16[L/H]
MTTCAN0.TTILS.UINT8[LL/LH/HL/HH]
MTTCAN0.TTOST.UINT32
MTTCAN0.TTOST.UINT16[L/H]
MTTCAN0.TTOST.UINT8[LL/LH/HL/HH]
MTTCAN0.TURNA.UINT32
MTTCAN0.TURNA.UINT16[L/H]
MTTCAN0.TURNA.UINT8[LL/LH/HL/HH]
MTTCAN0.TTLGT.UINT32
MTTCAN0.TTLGT.UINT16[L/H]
MTTCAN0.TTLGT.UINT8[LL/LH/HL/HH]
MTTCAN0.TTCTC.UINT32
MTTCAN0.TTCTC.UINT16[L/H]
MTTCAN0.TTCTC.UINT8[LL/LH/HL/HH]
MTTCAN0.TTCPT.UINT32
MTTCAN0.TTCPT.UINT16[L/H]
MTTCAN0.TTCPT.UINT8[LL/LH/HL/HH]
MTTCAN0.TTCSM.UINT32
MTTCAN0.TTCSM.UINT16[L]
MTTCAN0.TTCSM.UINT8[LL/LH]
MCAN1.CREL.UINT32
MCAN1.CREL.UINT16[L/H]
MCAN1.CREL.UINT8[LL/LH/HL/HH]
MCAN1.ENDN.UINT32
MCAN1.ENDN.UINT16[L/H]
MCAN1.ENDN.UINT8[LL/LH/HL/HH]
MCAN1.DBTP.UINT32
MCAN1.DBTP.UINT32
MCAN1.DBTP.UINT16[L/H]
MCAN1.DBTP.UINT8[LL/LH/HL/HH]
MCAN1.DBTP.REGS16.FBTPL.UINT16
MCAN1.DBTP.REGS16.FBTPH.UINT16
MCAN1.RWD.UINT32
MCAN1.RWD.UINT16[L]
MCAN1.RWD.UINT8[LL/LH]
MCAN1.CCCR.UINT32
MCAN1.CCCR.UINT16[L]
MCAN1.CCCR.UINT8[LL/LH]
MCAN1.BTP.UINT32
MCAN1.BTP.UINT32
MCAN1.BTP.UINT16[L/H]
MCAN1.BTP.UINT8[LL/LH/HL/HH]
MCAN1.TSCC.UINT32
MCAN1.TSCC.UINT16[L/H]
MCAN1.TSCC.UINT8[LL/LH/HL/HH]
MCAN1.TSCV.UINT32
MCAN1.TSCV.UINT16[L]
MCAN1.TSCV.UINT8[LL/LH]
MCAN1.TOCC.UINT32
MCAN1.TOCC.UINT16[L/H]
MCAN1.TOCC.UINT8[LL/LH/HL/HH]
MCAN1.TOCV.UINT32
MCAN1.TOCV.UINT16[L]
MCAN1.TOCV.UINT8[LL/LH]
MCAN1.ECR.UINT32
MCAN1.ECR.UINT16[L/H]
MCAN1.ECR.UINT8[LL/LH/HL/HH]
MCAN1.PSR.UINT32
MCAN1.PSR.UINT16[L]
MCAN1.PSR.UINT8[LL/LH]
MCAN1.TDCR.UINT32
MCAN1.TDCR.UINT16[L]
MCAN1.TDCR.UINT8[LL/LH]
MCAN1.IR.UINT32
MCAN1.IR.UINT16[L/H]
MCAN1.IR.UINT8[LL/LH/HL/HH]
MCAN1.IE.UINT32
MCAN1.IE.UINT16[L/H]
MCAN1.IE.UINT8[LL/LH/HL/HH]
MCAN1.ILS.UINT32
MCAN1.ILS.UINT16[L/H]
MCAN1.ILS.UINT8[LL/LH/HL/HH]
MCAN1.ILE.UINT32
MCAN1.ILE.UINT16[L]
MCAN1.ILE.UINT8[LL/LH]
MCAN1.GFC.UINT32
MCAN1.GFC.UINT16[L]
MCAN1.GFC.UINT8[LL/LH]
MCAN1.SIDFC.UINT32
MCAN1.SIDFC.UINT16[L/H]
MCAN1.SIDFC.UINT8[LL/LH/HL/HH]
MCAN1.XIDFC.UINT32
MCAN1.XIDFC.UINT16[L/H]
MCAN1.XIDFC.UINT8[LL/LH/HL/HH]
MCAN1.XIDAM.UINT32
MCAN1.XIDAM.UINT16[L/H]
MCAN1.XIDAM.UINT8[LL/LH/HL/HH]
MCAN1.HPMS.UINT32
MCAN1.HPMS.UINT16[L]
MCAN1.HPMS.UINT8[LL/LH]
MCAN1.NDAT1.UINT32
MCAN1.NDAT1.UINT16[L/H]
MCAN1.NDAT1.UINT8[LL/LH/HL/HH]
MCAN1.NDAT2.UINT32
MCAN1.NDAT2.UINT16[L/H]
MCAN1.NDAT2.UINT8[LL/LH/HL/HH]
MCAN1.RXF0C.UINT32
MCAN1.RXF0C.UINT16[L/H]
MCAN1.RXF0C.UINT8[LL/LH/HL/HH]
MCAN1.RXF0S.UINT32
MCAN1.RXF0S.UINT16[L/H]
MCAN1.RXF0S.UINT8[LL/LH/HL/HH]
MCAN1.RXF0A.UINT32
MCAN1.RXF0A.UINT16[L]
MCAN1.RXF0A.UINT8[LL/LH]
MCAN1.RXBC.UINT32
MCAN1.RXBC.UINT16[L]
MCAN1.RXBC.UINT8[LL/LH]
MCAN1.RXF1C.UINT32
MCAN1.RXF1C.UINT16[L/H]
MCAN1.RXF1C.UINT8[LL/LH/HL/HH]
MCAN1.RXF1S.UINT32
MCAN1.RXF1S.UINT16[L/H]
MCAN1.RXF1S.UINT8[LL/LH/HL/HH]
MCAN1.RXF1A.UINT32
MCAN1.RXF1A.UINT16[L]
MCAN1.RXF1A.UINT8[LL/LH]
MCAN1.RXESC.UINT32
MCAN1.RXESC.UINT16[L]
MCAN1.RXESC.UINT8[LL/LH]
MCAN1.TXBC.UINT32
MCAN1.TXBC.UINT16[L/H]
MCAN1.TXBC.UINT8[LL/LH/HL/HH]
MCAN1.TXFQS.UINT32
MCAN1.TXFQS.UINT16[L/H]
MCAN1.TXFQS.UINT8[LL/LH/HL/HH]
MCAN1.TXESC.UINT32
MCAN1.TXESC.UINT16[L]
MCAN1.TXESC.UINT8[LL/LH]
MCAN1.TXBRP.UINT32
MCAN1.TXBRP.UINT16[L/H]
MCAN1.TXBRP.UINT8[LL/LH/HL/HH]
MCAN1.TXBAR.UINT32
MCAN1.TXBAR.UINT16[L/H]
MCAN1.TXBAR.UINT8[LL/LH/HL/HH]
MCAN1.TXBCR.UINT32
MCAN1.TXBCR.UINT16[L/H]
MCAN1.TXBCR.UINT8[LL/LH/HL/HH]
MCAN1.TXBTO.UINT32
MCAN1.TXBTO.UINT16[L/H]
MCAN1.TXBTO.UINT8[LL/LH/HL/HH]
MCAN1.TXBCF.UINT32
MCAN1.TXBCF.UINT16[L/H]
MCAN1.TXBCF.UINT8[LL/LH/HL/HH]
MCAN1.TXBTIE.UINT32
MCAN1.TXBTIE.UINT16[L/H]
MCAN1.TXBTIE.UINT8[LL/LH/HL/HH]
MCAN1.TXBCIE.UINT32
MCAN1.TXBCIE.UINT16[L/H]
MCAN1.TXBCIE.UINT8[LL/LH/HL/HH]
MCAN1.TXEFC.UINT32
MCAN1.TXEFC.UINT16[L/H]
MCAN1.TXEFC.UINT8[LL/LH/HL/HH]
MCAN1.TXEFS.UINT32
MCAN1.TXEFS.UINT16[L/H]
MCAN1.TXEFS.UINT8[LL/LH/HL/HH]
MCAN1.TXEFA.UINT32
MCAN1.TXEFA.UINT16[L]
MCAN1.TXEFA.UINT8[LL/LH]
DCRB0.CIN
DCRB0.COUT
DCRB0.CTL
DCRB2.CIN
DCRB2.COUT
DCRB2.CTL
ECMM0.ESET
ECMM0.ECLR
ECMM0.ESSTR0 ... ECMM0.ESSTR2
ECMM0.PCMD0
ECMC0.ESET
ECMC0.ECLR
ECMC0.ESSTR0 ... ECMC0.ESSTR2
ECMC0.PCMD0
ECM0.EPCFG
ECM0.MICFG0 ... ECM0.MICFG2
ECM0.NMICFG0 ... ECM0.NMICFG2
ECM0.IRCFG0 ... ECM0.IRCFG2
ECM0.EMK0 ... ECM0.EMK2
ECM0.ESSTC0 ... ECM0.ESSTC2
ECM0.PCMD1
ECM0.PS
ECM0.PE0 ... ECM0.PE2
ECM0.DTMCTL
ECM0.DTMR
ECM0.DTMCMP
ECM0.DTMCFG0 ... ECM0.DTMCFG5
ECM0.EOCCFG
ECM0.PEM
PIC2C.TRGPREMUX0
PIC2C.TRGPREMUX1
PIC2C.TRGMUX0
PIC2C.TRGMUX1
PIC2C.EDGSEL0
PIC2C.EDGSEL1
PIC2C.ENP2TIM0
PIC2C.ENP2TIM1
PIC2C.ENHIZDTM
CSIH0.CTL0.UINT8
CSIH0.CTL0.BIT.MBS
CSIH0.CTL0.BIT.JOBE
CSIH0.CTL0.BIT.RXE
CSIH0.CTL0.BIT.TXE
CSIH0.CTL0.BIT.PWR
CSIH0.CTL1
CSIH0.CTL2
CSIH0.MCTL1
CSIH0.MCTL2
CSIH0.TX0W
CSIH0.TX0H
CSIH0.RX0W
CSIH0.RX0H
CSIH0.MRWP0
CSIH0.STR0
CSIH0.STCR0
CSIH0.MCTL0
CSIH0.CFG0 ... CSIH0.CFG7
CSIH0.BRS0 ... CSIH0.BRS3
PMMA0.CTL
PMMA0.TCTL0 ... PMMA0.TCTL7
PMMA0.TTX0 ... PMMA0.TTX7
PMMA0.RX
PMMA0.TCNT0 ... PMMA0.TCNT7
PMMA0.STR0
PMMA0.STR1
PMMA0.STC
CSIH2.CTL0.UINT8
CSIH2.CTL0.BIT.MBS
CSIH2.CTL0.BIT.JOBE
CSIH2.CTL0.BIT.RXE
CSIH2.CTL0.BIT.TXE
CSIH2.CTL0.BIT.PWR
CSIH2.CTL1
CSIH2.CTL2
CSIH2.MCTL1
CSIH2.MCTL2
CSIH2.TX0W
CSIH2.TX0H
CSIH2.RX0W
CSIH2.RX0H
CSIH2.MRWP0
CSIH2.STR0
CSIH2.STCR0
CSIH2.MCTL0
CSIH2.CFG0 ... CSIH2.CFG7
CSIH2.BRS0 ... CSIH2.BRS3
PMMA2.CTL
PMMA2.TCTL0 ... PMMA2.TCTL7
PMMA2.TTX0 ... PMMA2.TTX7
PMMA2.RX
PMMA2.TCNT0 ... PMMA2.TCNT7
PMMA2.STR0
PMMA2.STR1
PMMA2.STC
HSUS0.CKEN
HSUS0.SRST
HSUS0.EN
HSUS0.MD
HSUS0.CTL
HSUS0.TDIV
HSUS0.TSAR
HSUS0.TPFM
HSUS0.RDAR
HSUS0.RPFM
HSUS0.RGFM
HSUS0.IREN
HSUS0.IRST
HSUS0.IRCL.UINT32
HSUS0.IRCL.UINT16[L]
HSUS0.IRCL.UINT8[LL]
HSUS0.CST
HSUS0.CTFM
HSUS0.CRFM
RLN30.LWBR
RLN30.LBRP01.UINT16
RLN30.LBRP01.UINT8[L/H]
RLN30.LBRP01.REGS8.LBRP0.UINT8
RLN30.LBRP01.REGS8.LBRP1.UINT8
RLN30.LSTC
RLN30.LMD
RLN30.LBFC
RLN30.LSC
RLN30.LWUP
RLN30.LIE
RLN30.LEDE
RLN30.LCUC
RLN30.LTRC
RLN30.LMST
RLN30.LST
RLN30.LEST
RLN30.LDFC
RLN30.LIDB
RLN30.LCBR
RLN30.LUDB0
RLN30.LDBR1 ... RLN30.LDBR8
RLN30.LUOER
RLN30.LUOR1
RLN30.LUTDR.UINT16
RLN30.LUTDR.UINT8[L/H]
RLN30.LURDR.UINT16
RLN30.LURDR.UINT8[L/H]
RLN30.LUWTDR.UINT16
RLN30.LUWTDR.UINT8[L/H]
STM0.CKSEL.UINT32
STM0.CKSEL.UINT8[LL]
STM0.TS.UINT32
STM0.TS.UINT8[LL]
STM0.TT.UINT32
STM0.TT.UINT8[LL]
STM0.CSTR.UINT32
STM0.CSTR.UINT8[LL]
STM0.STR
STM0.STC
STM0.IS.UINT32
STM0.IS.UINT8[LL/LH]
STM0.RM.UINT32
STM0.RM.UINT8[LL]
STM0.CNT0L
STM0.CNT0H
STM0.CMP0AL
STM0.CMP0AH
STM0.CMP0BL
STM0.CMP0BH
STM0.CMP0CL
STM0.CMP0CH
STM0.CMP0DL
STM0.CMP0DH
STM0.CNT1
STM0.CMP1A
STM0.CMP1B
STM0.CMP1C
STM0.CMP1D
STM0.CNT2
STM0.CMP2A
STM0.CMP2B
STM0.CMP2C
STM0.CMP2D
STM0.CNT3
STM0.CMP3A
STM0.CMP3B
STM0.CMP3C
STM0.CMP3D
FSGD2A.PROT00.UINT32
FSGD2A.PROT00.UINT16[L/H]
FSGD2A.PROT00.UINT8[LL/LH/HL/HH]
FSGD2A.SPID00.UINT32
FSGD2A.SPID00.UINT16[L/H]
FSGD2A.SPID00.UINT8[LL/LH/HL/HH]
FSGD2A.PROT01.UINT32
FSGD2A.PROT01.UINT16[L/H]
FSGD2A.PROT01.UINT8[LL/LH/HL/HH]
FSGD2A.SPID01.UINT32
FSGD2A.SPID01.UINT16[L/H]
FSGD2A.SPID01.UINT8[LL/LH/HL/HH]
FSGD2A.PROT02.UINT32
FSGD2A.PROT02.UINT16[L/H]
FSGD2A.PROT02.UINT8[LL/LH/HL/HH]
FSGD2A.SPID02.UINT32
FSGD2A.SPID02.UINT16[L/H]
FSGD2A.SPID02.UINT8[LL/LH/HL/HH]
FSGD2A.PROT03.UINT32
FSGD2A.PROT03.UINT16[L/H]
FSGD2A.PROT03.UINT8[LL/LH/HL/HH]
FSGD2A.SPID03.UINT32
FSGD2A.SPID03.UINT16[L/H]
FSGD2A.SPID03.UINT8[LL/LH/HL/HH]
FSGD2A.PROT04.UINT32
FSGD2A.PROT04.UINT16[L/H]
FSGD2A.PROT04.UINT8[LL/LH/HL/HH]
FSGD2A.SPID04.UINT32
FSGD2A.SPID04.UINT16[L/H]
FSGD2A.SPID04.UINT8[LL/LH/HL/HH]
FSGD2A.PROT05.UINT32
FSGD2A.PROT05.UINT16[L/H]
FSGD2A.PROT05.UINT8[LL/LH/HL/HH]
FSGD2A.SPID05.UINT32
FSGD2A.SPID05.UINT16[L/H]
FSGD2A.SPID05.UINT8[LL/LH/HL/HH]
FSGD2A.PROT06.UINT32
FSGD2A.PROT06.UINT16[L/H]
FSGD2A.PROT06.UINT8[LL/LH/HL/HH]
FSGD2A.SPID06.UINT32
FSGD2A.SPID06.UINT16[L/H]
FSGD2A.SPID06.UINT8[LL/LH/HL/HH]
FSGD2A.PROT07.UINT32
FSGD2A.PROT07.UINT16[L/H]
FSGD2A.PROT07.UINT8[LL/LH/HL/HH]
FSGD2A.SPID07.UINT32
FSGD2A.SPID07.UINT16[L/H]
FSGD2A.SPID07.UINT8[LL/LH/HL/HH]
FSGD2A.PROT10.UINT32
FSGD2A.PROT10.UINT16[L/H]
FSGD2A.PROT10.UINT8[LL/LH/HL/HH]
FSGD2A.SPID10.UINT32
FSGD2A.SPID10.UINT16[L/H]
FSGD2A.SPID10.UINT8[LL/LH/HL/HH]
FSGD2A.PROT11.UINT32
FSGD2A.PROT11.UINT16[L/H]
FSGD2A.PROT11.UINT8[LL/LH/HL/HH]
FSGD2A.SPID11.UINT32
FSGD2A.SPID11.UINT16[L/H]
FSGD2A.SPID11.UINT8[LL/LH/HL/HH]
ERRSLV2.CTL
ERRSLV2.STAT
ERRSLV2.TYPE
ERRSLV2AI.CTL
ERRSLV2AI.STAT
ERRSLV2AI.TYPE
GTM0.GTMREV
GTM0.GTMRST
GTM0.GTMCTRL
GTM0.GTMAEIADDRXPT
GTM0.GTMIRQNOTIFY
GTM0.GTMIRQEN
GTM0.GTMIRQFORCINT
GTM0.GTMIRQMODE
GTM0.GTMEIRQEN
GTM0.GTMHWCONF
GTM0.GTMBRIDGEMODE
GTM0.GTMBRIDGEPTR1
GTM0.GTMBRIDGEPTR2
GTM0.GTMTIM0AUXINSRC
GTM0.GTMTIM1AUXINSRC
GTM0.GTMEXTCAPEN0
GTM0.GTMATOM0OUT
GTM0.TBUCHEN
GTM0.TBU0CTRL
GTM0.TBU0BASE
GTM0.TBU1CTRL
GTM0.TBU1BASE
GTM0.MONSTATUS
GTM0.MONACTIVITY0
GTM0.MONACTIVITYMCS0
GTM0.CMPEN
GTM0.CMPIRQNOTIFY
GTM0.CMPIRQEN
GTM0.CMPIRQFORCINT
GTM0.CMPIRQMODE
GTM0.CMPEIRQEN
GTM0.ARUACCESS
GTM0.ARUDATAH
GTM0.ARUDATAL
GTM0.ARUDBGACCESS0
GTM0.ARUDBGDATA0H
GTM0.ARUDBGDATA0L
GTM0.ARUDBGACCESS1
GTM0.ARUDBGDATA1H
GTM0.ARUDBGDATA1L
GTM0.ARUIRQNOTIFY
GTM0.ARUIRQEN
GTM0.ARUIRQFORCINT
GTM0.ARUIRQMODE
GTM0.ARUCADDREND
GTM0.CMUCLKEN
GTM0.CMUGCLKNUM
GTM0.CMUGCLKDEN
GTM0.CMUCLK0CTRL
GTM0.CMUCLK1CTRL
GTM0.CMUCLK2CTRL
GTM0.CMUCLK3CTRL
GTM0.CMUCLK4CTRL
GTM0.CMUCLK5CTRL
GTM0.CMUCLK6CTRL
GTM0.CMUCLK7CTRL
GTM0.CMUGLBCTRL
GTM0.ICMIRQG0
GTM0.ICMIRQG2
GTM0.ICMIRQG4
GTM0.ICMIRQG9
GTM0.ICMIRQGMEI
GTM0.ICMIRQGCEI1
GTM0.ICMIRQGCEI3
GTM0.ICMIRQGMCS0CI
GTM0.ICMIRQGMCS0CEI
GTM0.TIM00GPR0
GTM0.TIM00GPR1
GTM0.TIM00CNT
GTM0.TIM00ECNT
GTM0.TIM00CNTS
GTM0.TIM00TDUC
GTM0.TIM00TDUV
GTM0.TIM00FLTRE
GTM0.TIM00FLTFE
GTM0.TIM00CTRL
GTM0.TIM00ECTRL
GTM0.TIM00IRQNOTIFY
GTM0.TIM00IRQEN
GTM0.TIM00IRQFORCINT
GTM0.TIM00IRQMODE
GTM0.TIM00EIRQEN
GTM0.TIM0INPVAL
GTM0.TIM0INSRC
GTM0.TIM0RST
GTM0.TIM01GPR0
GTM0.TIM01GPR1
GTM0.TIM01CNT
GTM0.TIM01ECNT
GTM0.TIM01CNTS
GTM0.TIM01TDUC
GTM0.TIM01TDUV
GTM0.TIM01FLTRE
GTM0.TIM01FLTFE
GTM0.TIM01CTRL
GTM0.TIM01ECTRL
GTM0.TIM01IRQNOTIFY
GTM0.TIM01IRQEN
GTM0.TIM01IRQFORCINT
GTM0.TIM01IRQMODE
GTM0.TIM01EIRQEN
GTM0.TIM02GPR0
GTM0.TIM02GPR1
GTM0.TIM02CNT
GTM0.TIM02ECNT
GTM0.TIM02CNTS
GTM0.TIM02TDUC
GTM0.TIM02TDUV
GTM0.TIM02FLTRE
GTM0.TIM02FLTFE
GTM0.TIM02CTRL
GTM0.TIM02ECTRL
GTM0.TIM02IRQNOTIFY
GTM0.TIM02IRQEN
GTM0.TIM02IRQFORCINT
GTM0.TIM02IRQMODE
GTM0.TIM02EIRQEN
GTM0.TIM03GPR0
GTM0.TIM03GPR1
GTM0.TIM03CNT
GTM0.TIM03ECNT
GTM0.TIM03CNTS
GTM0.TIM03TDUC
GTM0.TIM03TDUV
GTM0.TIM03FLTRE
GTM0.TIM03FLTFE
GTM0.TIM03CTRL
GTM0.TIM03ECTRL
GTM0.TIM03IRQNOTIFY
GTM0.TIM03IRQEN
GTM0.TIM03IRQFORCINT
GTM0.TIM03IRQMODE
GTM0.TIM03EIRQEN
GTM0.TIM04GPR0
GTM0.TIM04GPR1
GTM0.TIM04CNT
GTM0.TIM04ECNT
GTM0.TIM04CNTS
GTM0.TIM04TDUC
GTM0.TIM04TDUV
GTM0.TIM04FLTRE
GTM0.TIM04FLTFE
GTM0.TIM04CTRL
GTM0.TIM04ECTRL
GTM0.TIM04IRQNOTIFY
GTM0.TIM04IRQEN
GTM0.TIM04IRQFORCINT
GTM0.TIM04IRQMODE
GTM0.TIM04EIRQEN
GTM0.TIM05GPR0
GTM0.TIM05GPR1
GTM0.TIM05CNT
GTM0.TIM05ECNT
GTM0.TIM05CNTS
GTM0.TIM05TDUC
GTM0.TIM05TDUV
GTM0.TIM05FLTRE
GTM0.TIM05FLTFE
GTM0.TIM05CTRL
GTM0.TIM05ECTRL
GTM0.TIM05IRQNOTIFY
GTM0.TIM05IRQEN
GTM0.TIM05IRQFORCINT
GTM0.TIM05IRQMODE
GTM0.TIM05EIRQEN
GTM0.TIM06GPR0
GTM0.TIM06GPR1
GTM0.TIM06CNT
GTM0.TIM06ECNT
GTM0.TIM06CNTS
GTM0.TIM06TDUC
GTM0.TIM06TDUV
GTM0.TIM06FLTRE
GTM0.TIM06FLTFE
GTM0.TIM06CTRL
GTM0.TIM06ECTRL
GTM0.TIM06IRQNOTIFY
GTM0.TIM06IRQEN
GTM0.TIM06IRQFORCINT
GTM0.TIM06IRQMODE
GTM0.TIM06EIRQEN
GTM0.TIM07GPR0
GTM0.TIM07GPR1
GTM0.TIM07CNT
GTM0.TIM07ECNT
GTM0.TIM07CNTS
GTM0.TIM07TDUC
GTM0.TIM07TDUV
GTM0.TIM07FLTRE
GTM0.TIM07FLTFE
GTM0.TIM07CTRL
GTM0.TIM07ECTRL
GTM0.TIM07IRQNOTIFY
GTM0.TIM07IRQEN
GTM0.TIM07IRQFORCINT
GTM0.TIM07IRQMODE
GTM0.TIM07EIRQEN
GTM0.TIM10GPR0
GTM0.TIM10GPR1
GTM0.TIM10CNT
GTM0.TIM10ECNT
GTM0.TIM10CNTS
GTM0.TIM10TDUC
GTM0.TIM10TDUV
GTM0.TIM10FLTRE
GTM0.TIM10FLTFE
GTM0.TIM10CTRL
GTM0.TIM10ECTRL
GTM0.TIM10IRQNOTIFY
GTM0.TIM10IRQEN
GTM0.TIM10IRQFORCINT
GTM0.TIM10IRQMODE
GTM0.TIM10EIRQEN
GTM0.TIM1INPVAL
GTM0.TIM1INSRC
GTM0.TIM1RST
GTM0.TIM11GPR0
GTM0.TIM11GPR1
GTM0.TIM11CNT
GTM0.TIM11ECNT
GTM0.TIM11CNTS
GTM0.TIM11TDUC
GTM0.TIM11TDUV
GTM0.TIM11FLTRE
GTM0.TIM11FLTFE
GTM0.TIM11CTRL
GTM0.TIM11ECTRL
GTM0.TIM11IRQNOTIFY
GTM0.TIM11IRQEN
GTM0.TIM11IRQFORCINT
GTM0.TIM11IRQMODE
GTM0.TIM11EIRQEN
GTM0.TIM12GPR0
GTM0.TIM12GPR1
GTM0.TIM12CNT
GTM0.TIM12ECNT
GTM0.TIM12CNTS
GTM0.TIM12TDUC
GTM0.TIM12TDUV
GTM0.TIM12FLTRE
GTM0.TIM12FLTFE
GTM0.TIM12CTRL
GTM0.TIM12ECTRL
GTM0.TIM12IRQNOTIFY
GTM0.TIM12IRQEN
GTM0.TIM12IRQFORCINT
GTM0.TIM12IRQMODE
GTM0.TIM12EIRQEN
GTM0.TIM13GPR0
GTM0.TIM13GPR1
GTM0.TIM13CNT
GTM0.TIM13ECNT
GTM0.TIM13CNTS
GTM0.TIM13TDUC
GTM0.TIM13TDUV
GTM0.TIM13FLTRE
GTM0.TIM13FLTFE
GTM0.TIM13CTRL
GTM0.TIM13ECTRL
GTM0.TIM13IRQNOTIFY
GTM0.TIM13IRQEN
GTM0.TIM13IRQFORCINT
GTM0.TIM13IRQMODE
GTM0.TIM13EIRQEN
GTM0.TIM14GPR0
GTM0.TIM14GPR1
GTM0.TIM14CNT
GTM0.TIM14ECNT
GTM0.TIM14CNTS
GTM0.TIM14TDUC
GTM0.TIM14TDUV
GTM0.TIM14FLTRE
GTM0.TIM14FLTFE
GTM0.TIM14CTRL
GTM0.TIM14ECTRL
GTM0.TIM14IRQNOTIFY
GTM0.TIM14IRQEN
GTM0.TIM14IRQFORCINT
GTM0.TIM14IRQMODE
GTM0.TIM14EIRQEN
GTM0.TIM15GPR0
GTM0.TIM15GPR1
GTM0.TIM15CNT
GTM0.TIM15ECNT
GTM0.TIM15CNTS
GTM0.TIM15TDUC
GTM0.TIM15TDUV
GTM0.TIM15FLTRE
GTM0.TIM15FLTFE
GTM0.TIM15CTRL
GTM0.TIM15ECTRL
GTM0.TIM15IRQNOTIFY
GTM0.TIM15IRQEN
GTM0.TIM15IRQFORCINT
GTM0.TIM15IRQMODE
GTM0.TIM15EIRQEN
GTM0.TIM16GPR0
GTM0.TIM16GPR1
GTM0.TIM16CNT
GTM0.TIM16ECNT
GTM0.TIM16CNTS
GTM0.TIM16TDUC
GTM0.TIM16TDUV
GTM0.TIM16FLTRE
GTM0.TIM16FLTFE
GTM0.TIM16CTRL
GTM0.TIM16ECTRL
GTM0.TIM16IRQNOTIFY
GTM0.TIM16IRQEN
GTM0.TIM16IRQFORCINT
GTM0.TIM16IRQMODE
GTM0.TIM16EIRQEN
GTM0.TIM17GPR0
GTM0.TIM17GPR1
GTM0.TIM17CNT
GTM0.TIM17ECNT
GTM0.TIM17CNTS
GTM0.TIM17TDUC
GTM0.TIM17TDUV
GTM0.TIM17FLTRE
GTM0.TIM17FLTFE
GTM0.TIM17CTRL
GTM0.TIM17ECTRL
GTM0.TIM17IRQNOTIFY
GTM0.TIM17IRQEN
GTM0.TIM17IRQFORCINT
GTM0.TIM17IRQMODE
GTM0.TIM17EIRQEN
GTM0.ATOM00RDADDR
GTM0.ATOM00CTRL
GTM0.ATOM00SR0
GTM0.ATOM00SR1
GTM0.ATOM00CM0
GTM0.ATOM00CM1
GTM0.ATOM00CN0
GTM0.ATOM00STAT
GTM0.ATOM00IRQNOTIFY
GTM0.ATOM00IRQEN
GTM0.ATOM00IRQFORCINT
GTM0.ATOM00IRQMODE
GTM0.ATOM0AGCGLBCTRL
GTM0.ATOM0AGCENDISCTRL
GTM0.ATOM0AGCENDISSTAT
GTM0.ATOM0AGCACTTB
GTM0.ATOM0AGCOUTENCTRL
GTM0.ATOM0AGCOUTENSTAT
GTM0.ATOM0AGCFUPDCTRL
GTM0.ATOM0AGCINTTRIG
GTM0.ATOM01RDADDR
GTM0.ATOM01CTRL
GTM0.ATOM01SR0
GTM0.ATOM01SR1
GTM0.ATOM01CM0
GTM0.ATOM01CM1
GTM0.ATOM01CN0
GTM0.ATOM01STAT
GTM0.ATOM01IRQNOTIFY
GTM0.ATOM01IRQEN
GTM0.ATOM01IRQFORCINT
GTM0.ATOM01IRQMODE
GTM0.ATOM02RDADDR
GTM0.ATOM02CTRL
GTM0.ATOM02SR0
GTM0.ATOM02SR1
GTM0.ATOM02CM0
GTM0.ATOM02CM1
GTM0.ATOM02CN0
GTM0.ATOM02STAT
GTM0.ATOM02IRQNOTIFY
GTM0.ATOM02IRQEN
GTM0.ATOM02IRQFORCINT
GTM0.ATOM02IRQMODE
GTM0.ATOM03RDADDR
GTM0.ATOM03CTRL
GTM0.ATOM03SR0
GTM0.ATOM03SR1
GTM0.ATOM03CM0
GTM0.ATOM03CM1
GTM0.ATOM03CN0
GTM0.ATOM03STAT
GTM0.ATOM03IRQNOTIFY
GTM0.ATOM03IRQEN
GTM0.ATOM03IRQFORCINT
GTM0.ATOM03IRQMODE
GTM0.ATOM04RDADDR
GTM0.ATOM04CTRL
GTM0.ATOM04SR0
GTM0.ATOM04SR1
GTM0.ATOM04CM0
GTM0.ATOM04CM1
GTM0.ATOM04CN0
GTM0.ATOM04STAT
GTM0.ATOM04IRQNOTIFY
GTM0.ATOM04IRQEN
GTM0.ATOM04IRQFORCINT
GTM0.ATOM04IRQMODE
GTM0.ATOM05RDADDR
GTM0.ATOM05CTRL
GTM0.ATOM05SR0
GTM0.ATOM05SR1
GTM0.ATOM05CM0
GTM0.ATOM05CM1
GTM0.ATOM05CN0
GTM0.ATOM05STAT
GTM0.ATOM05IRQNOTIFY
GTM0.ATOM05IRQEN
GTM0.ATOM05IRQFORCINT
GTM0.ATOM05IRQMODE
GTM0.ATOM06RDADDR
GTM0.ATOM06CTRL
GTM0.ATOM06SR0
GTM0.ATOM06SR1
GTM0.ATOM06CM0
GTM0.ATOM06CM1
GTM0.ATOM06CN0
GTM0.ATOM06STAT
GTM0.ATOM06IRQNOTIFY
GTM0.ATOM06IRQEN
GTM0.ATOM06IRQFORCINT
GTM0.ATOM06IRQMODE
GTM0.ATOM07RDADDR
GTM0.ATOM07CTRL
GTM0.ATOM07SR0
GTM0.ATOM07SR1
GTM0.ATOM07CM0
GTM0.ATOM07CM1
GTM0.ATOM07CN0
GTM0.ATOM07STAT
GTM0.ATOM07IRQNOTIFY
GTM0.ATOM07IRQEN
GTM0.ATOM07IRQFORCINT
GTM0.ATOM07IRQMODE
GTM0.ATOM10RDADDR
GTM0.ATOM10CTRL
GTM0.ATOM10SR0
GTM0.ATOM10SR1
GTM0.ATOM10CM0
GTM0.ATOM10CM1
GTM0.ATOM10CN0
GTM0.ATOM10STAT
GTM0.ATOM10IRQNOTIFY
GTM0.ATOM10IRQEN
GTM0.ATOM10IRQFORCINT
GTM0.ATOM10IRQMODE
GTM0.ATOM1AGCGLBCTRL
GTM0.ATOM1AGCENDISCTRL
GTM0.ATOM1AGCENDISSTAT
GTM0.ATOM1AGCACTTB
GTM0.ATOM1AGCOUTENCTRL
GTM0.ATOM1AGCOUTENSTAT
GTM0.ATOM1AGCFUPDCTRL
GTM0.ATOM1AGCINTTRIG
GTM0.ATOM11RDADDR
GTM0.ATOM11CTRL
GTM0.ATOM11SR0
GTM0.ATOM11SR1
GTM0.ATOM11CM0
GTM0.ATOM11CM1
GTM0.ATOM11CN0
GTM0.ATOM11STAT
GTM0.ATOM11IRQNOTIFY
GTM0.ATOM11IRQEN
GTM0.ATOM11IRQFORCINT
GTM0.ATOM11IRQMODE
GTM0.ATOM12RDADDR
GTM0.ATOM12CTRL
GTM0.ATOM12SR0
GTM0.ATOM12SR1
GTM0.ATOM12CM0
GTM0.ATOM12CM1
GTM0.ATOM12CN0
GTM0.ATOM12STAT
GTM0.ATOM12IRQNOTIFY
GTM0.ATOM12IRQEN
GTM0.ATOM12IRQFORCINT
GTM0.ATOM12IRQMODE
GTM0.ATOM13RDADDR
GTM0.ATOM13CTRL
GTM0.ATOM13SR0
GTM0.ATOM13SR1
GTM0.ATOM13CM0
GTM0.ATOM13CM1
GTM0.ATOM13CN0
GTM0.ATOM13STAT
GTM0.ATOM13IRQNOTIFY
GTM0.ATOM13IRQEN
GTM0.ATOM13IRQFORCINT
GTM0.ATOM13IRQMODE
GTM0.DTM24CTRL
GTM0.DTM24CHCTRL1
GTM0.DTM24CHCTRL2
GTM0.DTM24CHCTRL2SR
GTM0.DTM24PSCTRL
GTM0.DTM240DTV
GTM0.DTM241DTV
GTM0.DTM242DTV
GTM0.DTM243DTV
GTM0.DTM24CHSR
GTM0.DTM26CTRL
GTM0.DTM26CHCTRL1
GTM0.DTM26CHCTRL2
GTM0.DTM26CHCTRL2SR
GTM0.DTM26PSCTRL
GTM0.DTM260DTV
GTM0.DTM261DTV
GTM0.DTM262DTV
GTM0.DTM263DTV
GTM0.DTM26CHSR
GTM0.MCS00R0 ... GTM0.MCS00R7
GTM0.MCS00CTRL
GTM0.MCS00ACB
GTM0.MCS0CTRG
GTM0.MCS0STRG
GTM0.MCS00MHB
GTM0.MCS00PC
GTM0.MCS00IRQNOTIFY
GTM0.MCS00IRQEN
GTM0.MCS00IRQFORCINT
GTM0.MCS00IRQMODE
GTM0.MCS00EIRQEN
GTM0.MCS0CTRLSTAT
GTM0.MCS0RESET
GTM0.MCS0CAT
GTM0.MCS0CWT
GTM0.MCS0ERR
GTM0.MCS01R0 ... GTM0.MCS01R7
GTM0.MCS01CTRL
GTM0.MCS01ACB
GTM0.MCS01MHB
GTM0.MCS01PC
GTM0.MCS01IRQNOTIFY
GTM0.MCS01IRQEN
GTM0.MCS01IRQFORCINT
GTM0.MCS01IRQMODE
GTM0.MCS01EIRQEN
GTM0.MCS02R0 ... GTM0.MCS02R7
GTM0.MCS02CTRL
GTM0.MCS02ACB
GTM0.MCS02MHB
GTM0.MCS02PC
GTM0.MCS02IRQNOTIFY
GTM0.MCS02IRQEN
GTM0.MCS02IRQFORCINT
GTM0.MCS02IRQMODE
GTM0.MCS02EIRQEN
GTM0.MCS03R0 ... GTM0.MCS03R7
GTM0.MCS03CTRL
GTM0.MCS03ACB
GTM0.MCS03MHB
GTM0.MCS03PC
GTM0.MCS03IRQNOTIFY
GTM0.MCS03IRQEN
GTM0.MCS03IRQFORCINT
GTM0.MCS03IRQMODE
GTM0.MCS03EIRQEN
GTM0.MCS04R0 ... GTM0.MCS04R7
GTM0.MCS04CTRL
GTM0.MCS04ACB
GTM0.MCS04MHB
GTM0.MCS04PC
GTM0.MCS04IRQNOTIFY
GTM0.MCS04IRQEN
GTM0.MCS04IRQFORCINT
GTM0.MCS04IRQMODE
GTM0.MCS04EIRQEN
GTM0.MCS05R0 ... GTM0.MCS05R7
GTM0.MCS05CTRL
GTM0.MCS05ACB
GTM0.MCS05MHB
GTM0.MCS05PC
GTM0.MCS05IRQNOTIFY
GTM0.MCS05IRQEN
GTM0.MCS05IRQFORCINT
GTM0.MCS05IRQMODE
GTM0.MCS05EIRQEN
GTM0.MCS06R0 ... GTM0.MCS06R7
GTM0.MCS06CTRL
GTM0.MCS06ACB
GTM0.MCS06MHB
GTM0.MCS06PC
GTM0.MCS06IRQNOTIFY
GTM0.MCS06IRQEN
GTM0.MCS06IRQFORCINT
GTM0.MCS06IRQMODE
GTM0.MCS06EIRQEN
GTM0.MCS07R0 ... GTM0.MCS07R7
GTM0.MCS07CTRL
GTM0.MCS07ACB
GTM0.MCS07MHB
GTM0.MCS07PC
GTM0.MCS07IRQNOTIFY
GTM0.MCS07IRQEN
GTM0.MCS07IRQFORCINT
GTM0.MCS07IRQMODE
GTM0.MCS07EIRQEN
GTM0.MCS08R0 ... GTM0.MCS08R7
GTM0.MCS08CTRL
GTM0.MCS08ACB
GTM0.MCS08MHB
GTM0.MCS08PC
GTM0.MCS08IRQNOTIFY
GTM0.MCS08IRQEN
GTM0.MCS08IRQFORCINT
GTM0.MCS08IRQMODE
GTM0.MCS08EIRQEN
ECCGTM0.CTL
ECCGTM0.TMC
ECCGTM0.TRC
ECCGTM0.TED
ECCGTM0.EAD0
ECCGTM1.CTL
ECCGTM1.TMC
ECCGTM1.TRC
ECCGTM1.TED
ECCGTM1.EAD0
ECCGTM2.CTL
ECCGTM2.TMC
ECCGTM2.TRC
ECCGTM2.TED
ECCGTM2.EAD0
ECCGTM3.CTL
ECCGTM3.TMC
ECCGTM3.TRC
ECCGTM3.TED
ECCGTM3.EAD0
WDTA0.WDTE
WDTA0.EVAC
WDTA0.REF
WDTA0.MD
SWD0.CLR
SWD0.STS0
SWD0.STS1
SWD0.STSC
SWD0.WDTE
SWD0.MD
SWD0.PCAD
FSGD1A.PROT00.UINT32
FSGD1A.PROT00.UINT16[L/H]
FSGD1A.PROT00.UINT8[LL/LH/HL/HH]
FSGD1A.SPID00.UINT32
FSGD1A.SPID00.UINT16[L/H]
FSGD1A.SPID00.UINT8[LL/LH/HL/HH]
FSGD1A.PROT01.UINT32
FSGD1A.PROT01.UINT16[L/H]
FSGD1A.PROT01.UINT8[LL/LH/HL/HH]
FSGD1A.SPID01.UINT32
FSGD1A.SPID01.UINT16[L/H]
FSGD1A.SPID01.UINT8[LL/LH/HL/HH]
FSGD1A.PROT02.UINT32
FSGD1A.PROT02.UINT16[L/H]
FSGD1A.PROT02.UINT8[LL/LH/HL/HH]
FSGD1A.SPID02.UINT32
FSGD1A.SPID02.UINT16[L/H]
FSGD1A.SPID02.UINT8[LL/LH/HL/HH]
FSGD1A.PROT03.UINT32
FSGD1A.PROT03.UINT16[L/H]
FSGD1A.PROT03.UINT8[LL/LH/HL/HH]
FSGD1A.SPID03.UINT32
FSGD1A.SPID03.UINT16[L/H]
FSGD1A.SPID03.UINT8[LL/LH/HL/HH]
FSGD1A.PROT04.UINT32
FSGD1A.PROT04.UINT16[L/H]
FSGD1A.PROT04.UINT8[LL/LH/HL/HH]
FSGD1A.SPID04.UINT32
FSGD1A.SPID04.UINT16[L/H]
FSGD1A.SPID04.UINT8[LL/LH/HL/HH]
FSGD1A.PROT05.UINT32
FSGD1A.PROT05.UINT16[L/H]
FSGD1A.PROT05.UINT8[LL/LH/HL/HH]
FSGD1A.SPID05.UINT32
FSGD1A.SPID05.UINT16[L/H]
FSGD1A.SPID05.UINT8[LL/LH/HL/HH]
ERRSLV1.CTL
ERRSLV1.STAT
ERRSLV1.TYPE
FSGD1B.PROT00.UINT32
FSGD1B.PROT00.UINT16[L/H]
FSGD1B.PROT00.UINT8[LL/LH/HL/HH]
FSGD1B.SPID00.UINT32
FSGD1B.SPID00.UINT16[L/H]
FSGD1B.SPID00.UINT8[LL/LH/HL/HH]
FSGD1B.PROT01.UINT32
FSGD1B.PROT01.UINT16[L/H]
FSGD1B.PROT01.UINT8[LL/LH/HL/HH]
FSGD1B.SPID01.UINT32
FSGD1B.SPID01.UINT16[L/H]
FSGD1B.SPID01.UINT8[LL/LH/HL/HH]
FSGD1B.PROT06.UINT32
FSGD1B.PROT06.UINT16[L/H]
FSGD1B.PROT06.UINT8[LL/LH/HL/HH]
FSGD1B.SPID06.UINT32
FSGD1B.SPID06.UINT16[L/H]
FSGD1B.SPID06.UINT8[LL/LH/HL/HH]
FSGD1B.PROT07.UINT32
FSGD1B.PROT07.UINT16[L/H]
FSGD1B.PROT07.UINT8[LL/LH/HL/HH]
FSGD1B.SPID07.UINT32
FSGD1B.SPID07.UINT16[L/H]
FSGD1B.SPID07.UINT8[LL/LH/HL/HH]
FSGD1B.PROT10.UINT32
FSGD1B.PROT10.UINT16[L/H]
FSGD1B.PROT10.UINT8[LL/LH/HL/HH]
FSGD1B.SPID10.UINT32
FSGD1B.SPID10.UINT16[L/H]
FSGD1B.SPID10.UINT8[LL/LH/HL/HH]
FSGD1B.PROT11.UINT32
FSGD1B.PROT11.UINT16[L/H]
FSGD1B.PROT11.UINT8[LL/LH/HL/HH]
FSGD1B.SPID11.UINT32
FSGD1B.SPID11.UINT16[L/H]
FSGD1B.SPID11.UINT8[LL/LH/HL/HH]
FSGD1B.PROT12.UINT32
FSGD1B.PROT12.UINT16[L/H]
FSGD1B.PROT12.UINT8[LL/LH/HL/HH]
FSGD1B.SPID12.UINT32
FSGD1B.SPID12.UINT16[L/H]
FSGD1B.SPID12.UINT8[LL/LH/HL/HH]
FSGD1B.PROT13.UINT32
FSGD1B.PROT13.UINT16[L/H]
FSGD1B.PROT13.UINT8[LL/LH/HL/HH]
FSGD1B.SPID13.UINT32
FSGD1B.SPID13.UINT16[L/H]
FSGD1B.SPID13.UINT8[LL/LH/HL/HH]
ERRSLV1AI.CTL
ERRSLV1AI.STAT
ERRSLV1AI.TYPE
MCAN0.CREL.UINT32
MCAN0.CREL.UINT16[L/H]
MCAN0.CREL.UINT8[LL/LH/HL/HH]
MCAN0.ENDN.UINT32
MCAN0.ENDN.UINT16[L/H]
MCAN0.ENDN.UINT8[LL/LH/HL/HH]
MCAN0.DBTP.UINT32
MCAN0.DBTP.UINT32
MCAN0.DBTP.UINT16[L/H]
MCAN0.DBTP.UINT8[LL/LH/HL/HH]
MCAN0.DBTP.REGS16.FBTPL.UINT16
MCAN0.DBTP.REGS16.FBTPH.UINT16
MCAN0.TEST.UINT32
MCAN0.TEST.UINT16[L]
MCAN0.TEST.UINT8[LL/LH]
MCAN0.RWD.UINT32
MCAN0.RWD.UINT16[L]
MCAN0.RWD.UINT8[LL/LH]
MCAN0.CCCR.UINT32
MCAN0.CCCR.UINT16[L]
MCAN0.CCCR.UINT8[LL/LH]
MCAN0.BTP.UINT32
MCAN0.BTP.UINT32
MCAN0.BTP.UINT16[L/H]
MCAN0.BTP.UINT8[LL/LH/HL/HH]
MCAN0.TSCC.UINT32
MCAN0.TSCC.UINT16[L/H]
MCAN0.TSCC.UINT8[LL/LH/HL/HH]
MCAN0.TSCV.UINT32
MCAN0.TSCV.UINT16[L]
MCAN0.TSCV.UINT8[LL/LH]
MCAN0.TOCC.UINT32
MCAN0.TOCC.UINT16[L/H]
MCAN0.TOCC.UINT8[LL/LH/HL/HH]
MCAN0.TOCV.UINT32
MCAN0.TOCV.UINT16[L]
MCAN0.TOCV.UINT8[LL/LH]
MCAN0.ECR.UINT32
MCAN0.ECR.UINT16[L/H]
MCAN0.ECR.UINT8[LL/LH/HL/HH]
MCAN0.PSR.UINT32
MCAN0.PSR.UINT16[L]
MCAN0.PSR.UINT8[LL/LH]
MCAN0.TDCR.UINT32
MCAN0.TDCR.UINT16[L]
MCAN0.TDCR.UINT8[LL/LH]
MCAN0.IR.UINT32
MCAN0.IR.UINT16[L/H]
MCAN0.IR.UINT8[LL/LH/HL/HH]
MCAN0.IE.UINT32
MCAN0.IE.UINT16[L/H]
MCAN0.IE.UINT8[LL/LH/HL/HH]
MCAN0.ILS.UINT32
MCAN0.ILS.UINT16[L/H]
MCAN0.ILS.UINT8[LL/LH/HL/HH]
MCAN0.ILE.UINT32
MCAN0.ILE.UINT16[L]
MCAN0.ILE.UINT8[LL/LH]
MCAN0.GFC.UINT32
MCAN0.GFC.UINT16[L]
MCAN0.GFC.UINT8[LL/LH]
MCAN0.SIDFC.UINT32
MCAN0.SIDFC.UINT16[L/H]
MCAN0.SIDFC.UINT8[LL/LH/HL/HH]
MCAN0.XIDFC.UINT32
MCAN0.XIDFC.UINT16[L/H]
MCAN0.XIDFC.UINT8[LL/LH/HL/HH]
MCAN0.XIDAM.UINT32
MCAN0.XIDAM.UINT16[L/H]
MCAN0.XIDAM.UINT8[LL/LH/HL/HH]
MCAN0.HPMS.UINT32
MCAN0.HPMS.UINT16[L]
MCAN0.HPMS.UINT8[LL/LH]
MCAN0.NDAT1.UINT32
MCAN0.NDAT1.UINT16[L/H]
MCAN0.NDAT1.UINT8[LL/LH/HL/HH]
MCAN0.NDAT2.UINT32
MCAN0.NDAT2.UINT16[L/H]
MCAN0.NDAT2.UINT8[LL/LH/HL/HH]
MCAN0.RXF0C.UINT32
MCAN0.RXF0C.UINT16[L/H]
MCAN0.RXF0C.UINT8[LL/LH/HL/HH]
MCAN0.RXF0S.UINT32
MCAN0.RXF0S.UINT16[L/H]
MCAN0.RXF0S.UINT8[LL/LH/HL/HH]
MCAN0.RXF0A.UINT32
MCAN0.RXF0A.UINT16[L]
MCAN0.RXF0A.UINT8[LL/LH]
MCAN0.RXBC.UINT32
MCAN0.RXBC.UINT16[L]
MCAN0.RXBC.UINT8[LL/LH]
MCAN0.RXF1C.UINT32
MCAN0.RXF1C.UINT16[L/H]
MCAN0.RXF1C.UINT8[LL/LH/HL/HH]
MCAN0.RXF1S.UINT32
MCAN0.RXF1S.UINT16[L/H]
MCAN0.RXF1S.UINT8[LL/LH/HL/HH]
MCAN0.RXF1A.UINT32
MCAN0.RXF1A.UINT16[L]
MCAN0.RXF1A.UINT8[LL/LH]
MCAN0.RXESC.UINT32
MCAN0.RXESC.UINT16[L]
MCAN0.RXESC.UINT8[LL/LH]
MCAN0.TXBC.UINT32
MCAN0.TXBC.UINT16[L/H]
MCAN0.TXBC.UINT8[LL/LH/HL/HH]
MCAN0.TXFQS.UINT32
MCAN0.TXFQS.UINT16[L/H]
MCAN0.TXFQS.UINT8[LL/LH/HL/HH]
MCAN0.TXESC.UINT32
MCAN0.TXESC.UINT16[L]
MCAN0.TXESC.UINT8[LL/LH]
MCAN0.TXBRP.UINT32
MCAN0.TXBRP.UINT16[L/H]
MCAN0.TXBRP.UINT8[LL/LH/HL/HH]
MCAN0.TXBAR.UINT32
MCAN0.TXBAR.UINT16[L/H]
MCAN0.TXBAR.UINT8[LL/LH/HL/HH]
MCAN0.TXBCR.UINT32
MCAN0.TXBCR.UINT16[L/H]
MCAN0.TXBCR.UINT8[LL/LH/HL/HH]
MCAN0.TXBTO.UINT32
MCAN0.TXBTO.UINT16[L/H]
MCAN0.TXBTO.UINT8[LL/LH/HL/HH]
MCAN0.TXBCF.UINT32
MCAN0.TXBCF.UINT16[L/H]
MCAN0.TXBCF.UINT8[LL/LH/HL/HH]
MCAN0.TXBTIE.UINT32
MCAN0.TXBTIE.UINT16[L/H]
MCAN0.TXBTIE.UINT8[LL/LH/HL/HH]
MCAN0.TXBCIE.UINT32
MCAN0.TXBCIE.UINT16[L/H]
MCAN0.TXBCIE.UINT8[LL/LH/HL/HH]
MCAN0.TXEFC.UINT32
MCAN0.TXEFC.UINT16[L/H]
MCAN0.TXEFC.UINT8[LL/LH/HL/HH]
MCAN0.TXEFS.UINT32
MCAN0.TXEFS.UINT16[L/H]
MCAN0.TXEFS.UINT8[LL/LH/HL/HH]
MCAN0.TXEFA.UINT32
MCAN0.TXEFA.UINT16[L]
MCAN0.TXEFA.UINT8[LL/LH]
DCRB1.CIN
DCRB1.COUT
DCRB1.CTL
DCRB3.CIN
DCRB3.COUT
DCRB3.CTL
CLMA0.CTL0
CLMA0.CMPL
CLMA0.CMPH
CLMA0.PCMD
CLMA0.PS
CLMA0.EMU0
CLMA1.CTL0
CLMA1.CMPL
CLMA1.CMPH
CLMA1.PCMD
CLMA1.PS
CLMA1.EMU0
CLMA2.CTL0
CLMA2.CMPL
CLMA2.CMPH
CLMA2.PCMD
CLMA2.PS
CLMA2.EMU0
CLMA3.CTL0
CLMA3.CMPL
CLMA3.CMPH
CLMA3.PCMD
CLMA3.PS
CLMA3.EMU0
CLMA5.CTL0
CLMA5.CTL1
CLMA5.CMPL
CLMA5.CMPH
CLMA5.PCMD
CLMA5.PS
CLMA5.EMU0
FSGD4A.PROT00.UINT32
FSGD4A.PROT00.UINT16[L/H]
FSGD4A.PROT00.UINT8[LL/LH/HL/HH]
FSGD4A.SPID00.UINT32
FSGD4A.SPID00.UINT16[L/H]
FSGD4A.SPID00.UINT8[LL/LH/HL/HH]
FSGD4A.PROT01.UINT32
FSGD4A.PROT01.UINT16[L/H]
FSGD4A.PROT01.UINT8[LL/LH/HL/HH]
FSGD4A.SPID01.UINT32
FSGD4A.SPID01.UINT16[L/H]
FSGD4A.SPID01.UINT8[LL/LH/HL/HH]
FSGD4A.PROT02.UINT32
FSGD4A.PROT02.UINT16[L/H]
FSGD4A.PROT02.UINT8[LL/LH/HL/HH]
FSGD4A.SPID02.UINT32
FSGD4A.SPID02.UINT16[L/H]
FSGD4A.SPID02.UINT8[LL/LH/HL/HH]
FSGD4A.PROT03.UINT32
FSGD4A.PROT03.UINT16[L/H]
FSGD4A.PROT03.UINT8[LL/LH/HL/HH]
FSGD4A.SPID03.UINT32
FSGD4A.SPID03.UINT16[L/H]
FSGD4A.SPID03.UINT8[LL/LH/HL/HH]
FSGD4A.PROT04.UINT32
FSGD4A.PROT04.UINT16[L/H]
FSGD4A.PROT04.UINT8[LL/LH/HL/HH]
FSGD4A.SPID04.UINT32
FSGD4A.SPID04.UINT16[L/H]
FSGD4A.SPID04.UINT8[LL/LH/HL/HH]
FSGD4A.PROT05.UINT32
FSGD4A.PROT05.UINT16[L/H]
FSGD4A.PROT05.UINT8[LL/LH/HL/HH]
FSGD4A.SPID05.UINT32
FSGD4A.SPID05.UINT16[L/H]
FSGD4A.SPID05.UINT8[LL/LH/HL/HH]
FSGD4A.PROT06.UINT32
FSGD4A.PROT06.UINT16[L/H]
FSGD4A.PROT06.UINT8[LL/LH/HL/HH]
FSGD4A.SPID06.UINT32
FSGD4A.SPID06.UINT16[L/H]
FSGD4A.SPID06.UINT8[LL/LH/HL/HH]
FSGD4A.PROT07.UINT32
FSGD4A.PROT07.UINT16[L/H]
FSGD4A.PROT07.UINT8[LL/LH/HL/HH]
FSGD4A.SPID07.UINT32
FSGD4A.SPID07.UINT16[L/H]
FSGD4A.SPID07.UINT8[LL/LH/HL/HH]
FSGD4A.PROT08.UINT32
FSGD4A.PROT08.UINT16[L/H]
FSGD4A.PROT08.UINT8[LL/LH/HL/HH]
FSGD4A.SPID08.UINT32
FSGD4A.SPID08.UINT16[L/H]
FSGD4A.SPID08.UINT8[LL/LH/HL/HH]
FSGD4A.PROT09.UINT32
FSGD4A.PROT09.UINT16[L/H]
FSGD4A.PROT09.UINT8[LL/LH/HL/HH]
FSGD4A.SPID09.UINT32
FSGD4A.SPID09.UINT16[L/H]
FSGD4A.SPID09.UINT8[LL/LH/HL/HH]
FSGD4A.PROT10.UINT32
FSGD4A.PROT10.UINT16[L/H]
FSGD4A.PROT10.UINT8[LL/LH/HL/HH]
FSGD4A.SPID10.UINT32
FSGD4A.SPID10.UINT16[L/H]
FSGD4A.SPID10.UINT8[LL/LH/HL/HH]
FSGD4A.PROT11.UINT32
FSGD4A.PROT11.UINT16[L/H]
FSGD4A.PROT11.UINT8[LL/LH/HL/HH]
FSGD4A.SPID11.UINT32
FSGD4A.SPID11.UINT16[L/H]
FSGD4A.SPID11.UINT8[LL/LH/HL/HH]
FSGD4A.PROT12.UINT32
FSGD4A.PROT12.UINT16[L/H]
FSGD4A.PROT12.UINT8[LL/LH/HL/HH]
FSGD4A.SPID12.UINT32
FSGD4A.SPID12.UINT16[L/H]
FSGD4A.SPID12.UINT8[LL/LH/HL/HH]
FSGD4A.PROT13.UINT32
FSGD4A.PROT13.UINT16[L/H]
FSGD4A.PROT13.UINT8[LL/LH/HL/HH]
FSGD4A.SPID13.UINT32
FSGD4A.SPID13.UINT16[L/H]
FSGD4A.SPID13.UINT8[LL/LH/HL/HH]
FSGD4A.PROT14.UINT32
FSGD4A.PROT14.UINT16[L/H]
FSGD4A.PROT14.UINT8[LL/LH/HL/HH]
FSGD4A.SPID14.UINT32
FSGD4A.SPID14.UINT16[L/H]
FSGD4A.SPID14.UINT8[LL/LH/HL/HH]
FSGD4A.PROT15.UINT32
FSGD4A.PROT15.UINT16[L/H]
FSGD4A.PROT15.UINT8[LL/LH/HL/HH]
FSGD4A.SPID15.UINT32
FSGD4A.SPID15.UINT16[L/H]
FSGD4A.SPID15.UINT8[LL/LH/HL/HH]
ERRSLV4.CTL
ERRSLV4.STAT
ERRSLV4.TYPE
FSGD4B.PROT00.UINT32
FSGD4B.PROT00.UINT16[L/H]
FSGD4B.PROT00.UINT8[LL/LH/HL/HH]
FSGD4B.SPID00.UINT32
FSGD4B.SPID00.UINT16[L/H]
FSGD4B.SPID00.UINT8[LL/LH/HL/HH]
FSGD4B.PROT01.UINT32
FSGD4B.PROT01.UINT16[L/H]
FSGD4B.PROT01.UINT8[LL/LH/HL/HH]
FSGD4B.SPID01.UINT32
FSGD4B.SPID01.UINT16[L/H]
FSGD4B.SPID01.UINT8[LL/LH/HL/HH]
FSGD4B.PROT02.UINT32
FSGD4B.PROT02.UINT16[L/H]
FSGD4B.PROT02.UINT8[LL/LH/HL/HH]
FSGD4B.SPID02.UINT32
FSGD4B.SPID02.UINT16[L/H]
FSGD4B.SPID02.UINT8[LL/LH/HL/HH]
FSGD4B.PROT03.UINT32
FSGD4B.PROT03.UINT16[L/H]
FSGD4B.PROT03.UINT8[LL/LH/HL/HH]
FSGD4B.SPID03.UINT32
FSGD4B.SPID03.UINT16[L/H]
FSGD4B.SPID03.UINT8[LL/LH/HL/HH]
FSGD4B.PROT04.UINT32
FSGD4B.PROT04.UINT16[L/H]
FSGD4B.PROT04.UINT8[LL/LH/HL/HH]
FSGD4B.SPID04.UINT32
FSGD4B.SPID04.UINT16[L/H]
FSGD4B.SPID04.UINT8[LL/LH/HL/HH]
FSGD4B.PROT05.UINT32
FSGD4B.PROT05.UINT16[L/H]
FSGD4B.PROT05.UINT8[LL/LH/HL/HH]
FSGD4B.SPID05.UINT32
FSGD4B.SPID05.UINT16[L/H]
FSGD4B.SPID05.UINT8[LL/LH/HL/HH]
FSGD4B.PROT06.UINT32
FSGD4B.PROT06.UINT16[L/H]
FSGD4B.PROT06.UINT8[LL/LH/HL/HH]
FSGD4B.SPID06.UINT32
FSGD4B.SPID06.UINT16[L/H]
FSGD4B.SPID06.UINT8[LL/LH/HL/HH]
FSGD4B.PROT07.UINT32
FSGD4B.PROT07.UINT16[L/H]
FSGD4B.PROT07.UINT8[LL/LH/HL/HH]
FSGD4B.SPID07.UINT32
FSGD4B.SPID07.UINT16[L/H]
FSGD4B.SPID07.UINT8[LL/LH/HL/HH]
FSGD4B.PROT08.UINT32
FSGD4B.PROT08.UINT16[L/H]
FSGD4B.PROT08.UINT8[LL/LH/HL/HH]
FSGD4B.SPID08.UINT32
FSGD4B.SPID08.UINT16[L/H]
FSGD4B.SPID08.UINT8[LL/LH/HL/HH]
FSGD4B.PROT09.UINT32
FSGD4B.PROT09.UINT16[L/H]
FSGD4B.PROT09.UINT8[LL/LH/HL/HH]
FSGD4B.SPID09.UINT32
FSGD4B.SPID09.UINT16[L/H]
FSGD4B.SPID09.UINT8[LL/LH/HL/HH]
FSGD4B.PROT10.UINT32
FSGD4B.PROT10.UINT16[L/H]
FSGD4B.PROT10.UINT8[LL/LH/HL/HH]
FSGD4B.SPID10.UINT32
FSGD4B.SPID10.UINT16[L/H]
FSGD4B.SPID10.UINT8[LL/LH/HL/HH]
FSGD4B.PROT11.UINT32
FSGD4B.PROT11.UINT16[L/H]
FSGD4B.PROT11.UINT8[LL/LH/HL/HH]
FSGD4B.SPID11.UINT32
FSGD4B.SPID11.UINT16[L/H]
FSGD4B.SPID11.UINT8[LL/LH/HL/HH]
FSGD4B.PROT12.UINT32
FSGD4B.PROT12.UINT16[L/H]
FSGD4B.PROT12.UINT8[LL/LH/HL/HH]
FSGD4B.SPID12.UINT32
FSGD4B.SPID12.UINT16[L/H]
FSGD4B.SPID12.UINT8[LL/LH/HL/HH]
FSGD4B.PROT13.UINT32
FSGD4B.PROT13.UINT16[L/H]
FSGD4B.PROT13.UINT8[LL/LH/HL/HH]
FSGD4B.SPID13.UINT32
FSGD4B.SPID13.UINT16[L/H]
FSGD4B.SPID13.UINT8[LL/LH/HL/HH]
FSGD4C.PROT00.UINT32
FSGD4C.PROT00.UINT16[L/H]
FSGD4C.PROT00.UINT8[LL/LH/HL/HH]
FSGD4C.SPID00.UINT32
FSGD4C.SPID00.UINT16[L/H]
FSGD4C.SPID00.UINT8[LL/LH/HL/HH]
FSGD4C.PROT01.UINT32
FSGD4C.PROT01.UINT16[L/H]
FSGD4C.PROT01.UINT8[LL/LH/HL/HH]
FSGD4C.SPID01.UINT32
FSGD4C.SPID01.UINT16[L/H]
FSGD4C.SPID01.UINT8[LL/LH/HL/HH]
FSGD4C.PROT02.UINT32
FSGD4C.PROT02.UINT16[L/H]
FSGD4C.PROT02.UINT8[LL/LH/HL/HH]
FSGD4C.SPID02.UINT32
FSGD4C.SPID02.UINT16[L/H]
FSGD4C.SPID02.UINT8[LL/LH/HL/HH]
FSGD4C.PROT03.UINT32
FSGD4C.PROT03.UINT16[L/H]
FSGD4C.PROT03.UINT8[LL/LH/HL/HH]
FSGD4C.SPID03.UINT32
FSGD4C.SPID03.UINT16[L/H]
FSGD4C.SPID03.UINT8[LL/LH/HL/HH]
FSGD4C.PROT04.UINT32
FSGD4C.PROT04.UINT16[L/H]
FSGD4C.PROT04.UINT8[LL/LH/HL/HH]
FSGD4C.SPID04.UINT32
FSGD4C.SPID04.UINT16[L/H]
FSGD4C.SPID04.UINT8[LL/LH/HL/HH]
FSGD4C.PROT05.UINT32
FSGD4C.PROT05.UINT16[L/H]
FSGD4C.PROT05.UINT8[LL/LH/HL/HH]
FSGD4C.SPID05.UINT32
FSGD4C.SPID05.UINT16[L/H]
FSGD4C.SPID05.UINT8[LL/LH/HL/HH]
FSGD4C.PROT06.UINT32
FSGD4C.PROT06.UINT16[L/H]
FSGD4C.PROT06.UINT8[LL/LH/HL/HH]
FSGD4C.SPID06.UINT32
FSGD4C.SPID06.UINT16[L/H]
FSGD4C.SPID06.UINT8[LL/LH/HL/HH]
FSGD4C.PROT07.UINT32
FSGD4C.PROT07.UINT16[L/H]
FSGD4C.PROT07.UINT8[LL/LH/HL/HH]
FSGD4C.SPID07.UINT32
FSGD4C.SPID07.UINT16[L/H]
FSGD4C.SPID07.UINT8[LL/LH/HL/HH]
FSGD4C.PROT08.UINT32
FSGD4C.PROT08.UINT16[L/H]
FSGD4C.PROT08.UINT8[LL/LH/HL/HH]
FSGD4C.SPID08.UINT32
FSGD4C.SPID08.UINT16[L/H]
FSGD4C.SPID08.UINT8[LL/LH/HL/HH]
FSGD4C.PROT09.UINT32
FSGD4C.PROT09.UINT16[L/H]
FSGD4C.PROT09.UINT8[LL/LH/HL/HH]
FSGD4C.SPID09.UINT32
FSGD4C.SPID09.UINT16[L/H]
FSGD4C.SPID09.UINT8[LL/LH/HL/HH]
FSGD4C.PROT10.UINT32
FSGD4C.PROT10.UINT16[L/H]
FSGD4C.PROT10.UINT8[LL/LH/HL/HH]
FSGD4C.SPID10.UINT32
FSGD4C.SPID10.UINT16[L/H]
FSGD4C.SPID10.UINT8[LL/LH/HL/HH]
FSGD4C.PROT11.UINT32
FSGD4C.PROT11.UINT16[L/H]
FSGD4C.PROT11.UINT8[LL/LH/HL/HH]
FSGD4C.SPID11.UINT32
FSGD4C.SPID11.UINT16[L/H]
FSGD4C.SPID11.UINT8[LL/LH/HL/HH]
FSGD4C.PROT12.UINT32
FSGD4C.PROT12.UINT16[L/H]
FSGD4C.PROT12.UINT8[LL/LH/HL/HH]
FSGD4C.SPID12.UINT32
FSGD4C.SPID12.UINT16[L/H]
FSGD4C.SPID12.UINT8[LL/LH/HL/HH]
FSGD4C.PROT13.UINT32
FSGD4C.PROT13.UINT16[L/H]
FSGD4C.PROT13.UINT8[LL/LH/HL/HH]
FSGD4C.SPID13.UINT32
FSGD4C.SPID13.UINT16[L/H]
FSGD4C.SPID13.UINT8[LL/LH/HL/HH]
ERRSLV4C.CTL
ERRSLV4C.STAT
ERRSLV4C.TYPE
ERRSLV4AI.CTL
ERRSLV4AI.STAT
ERRSLV4AI.TYPE
ADCF0.VCR0 ... ADCF0.VCR23
ADCF0.DR00
ADCF0.DR02
ADCF0.DR04
ADCF0.DR06
ADCF0.DR08
ADCF0.DR10
ADCF0.DR12
ADCF0.DR14
ADCF0.DR16
ADCF0.DR18
ADCF0.DR20
ADCF0.DR22
ADCF0.DIR0 ... ADCF0.DIR23
ADCF0.ADSYNSTCR
ADCF0.ADTSYNSTCR
ADCF0.ADHALTR
ADCF0.ADCR1
ADCF0.MPXCURCR
ADCF0.MPXCURR
ADCF0.MPXOWR
ADCF0.ADCR2
ADCF0.ADENDP0
ADCF0.SFTCR
ADCF0.TDCR
ADCF0.ULLMTBR0.UINT32
ADCF0.ULLMTBR0.UINT16[L/H]
ADCF0.ULLMTBR1.UINT32
ADCF0.ULLMTBR1.UINT16[L/H]
ADCF0.ULLMTBR2.UINT32
ADCF0.ULLMTBR2.UINT16[L/H]
ADCF0.ECR
ADCF0.ULER
ADCF0.OWER
ADCF0.PER
ADCF0.IDER
ADCF0.SGSTCR0
ADCF0.SGCR0
ADCF0.SGVCSP0
ADCF0.SGVCEP0
ADCF0.SGMCYCR0
ADCF0.SGSR0
ADCF0.ULLMSR0
ADCF0.SGSTCR1
ADCF0.SGCR1
ADCF0.SGVCSP1
ADCF0.SGVCEP1
ADCF0.SGMCYCR1
ADCF0.SGSR1
ADCF0.ULLMSR1
ADCF0.SGSTCR2
ADCF0.SGCR2
ADCF0.SGVCSP2
ADCF0.SGVCEP2
ADCF0.SGMCYCR2
ADCF0.SGSR2
ADCF0.ULLMSR2
ADCF0.SGSTCR3
ADCF0.ADTSTCR3
ADCF0.ADTENDCR3
ADCF0.SGCR3
ADCF0.SGVCSP3
ADCF0.SGVCEP3
ADCF0.SGMCYCR3
ADCF0.SGSR3
ADCF0.ADTIPR3
ADCF0.ADTPRR3
ADCF0.ULLMSR3
ADCF0.SGSTCR4
ADCF0.ADTSTCR4
ADCF0.ADTENDCR4
ADCF0.SGCR4
ADCF0.SGVCSP4
ADCF0.SGVCEP4
ADCF0.SGMCYCR4
ADCF0.SGSR4
ADCF0.ADTIPR4
ADCF0.ADTPRR4
ADCF0.ULLMSR4
ADCF1.VCR0 ... ADCF1.VCR19
ADCF1.DR00
ADCF1.DR02
ADCF1.DR04
ADCF1.DR06
ADCF1.DR08
ADCF1.DR10
ADCF1.DR12
ADCF1.DR14
ADCF1.DR16
ADCF1.DR18
ADCF1.DIR0 ... ADCF1.DIR19
ADCF1.ADHALTR
ADCF1.ADCR1
ADCF1.MPXCURCR
ADCF1.MPXCURR
ADCF1.MPXOWR
ADCF1.ADCR2
ADCF1.ADENDP0
ADCF1.SFTCR
ADCF1.TDCR
ADCF1.ULLMTBR0.UINT32
ADCF1.ULLMTBR0.UINT16[L/H]
ADCF1.ULLMTBR1.UINT32
ADCF1.ULLMTBR1.UINT16[L/H]
ADCF1.ULLMTBR2.UINT32
ADCF1.ULLMTBR2.UINT16[L/H]
ADCF1.ECR
ADCF1.ULER
ADCF1.OWER
ADCF1.PER
ADCF1.IDER
ADCF1.SGSTCR0
ADCF1.SGCR0
ADCF1.SGVCSP0
ADCF1.SGVCEP0
ADCF1.SGMCYCR0
ADCF1.SGSR0
ADCF1.ULLMSR0
ADCF1.SGSTCR1
ADCF1.SGCR1
ADCF1.SGVCSP1
ADCF1.SGVCEP1
ADCF1.SGMCYCR1
ADCF1.SGSR1
ADCF1.ULLMSR1
ADCF1.SGSTCR2
ADCF1.SGCR2
ADCF1.SGVCSP2
ADCF1.SGVCEP2
ADCF1.SGMCYCR2
ADCF1.SGSR2
ADCF1.ULLMSR2
ADCF1.SGSTCR3
ADCF1.ADTSTCR3
ADCF1.ADTENDCR3
ADCF1.SGCR3
ADCF1.SGVCSP3
ADCF1.SGVCEP3
ADCF1.SGMCYCR3
ADCF1.SGSR3
ADCF1.ADTIPR3
ADCF1.ADTPRR3
ADCF1.ULLMSR3
ADCF1.SGSTCR4
ADCF1.ADTSTCR4
ADCF1.ADTENDCR4
ADCF1.SGCR4
ADCF1.SGVCSP4
ADCF1.SGVCEP4
ADCF1.SGMCYCR4
ADCF1.SGSR4
ADCF1.ADTIPR4
ADCF1.ADTPRR4
ADCF1.ULLMSR4
OTS0.OTSTCR
OTS0.OTENDCR
OTS0.OTCR
OTS0.OTFCR
OTS0.OTFR
OTS0.OTSTR
OTS0.OTDR
OTS0.HTBRAU
OTS0.HTBRAL
OTS0.HTBRBU
OTS0.HTBRBL
OTS0.LTBRAU
OTS0.LTBRAL
OTS0.TDLR
OTS0.COEFFRA
OTS0.COEFFRB
OTS0.COEFFRC
FSGD3A.PROT00.UINT32
FSGD3A.PROT00.UINT16[L/H]
FSGD3A.PROT00.UINT8[LL/LH/HL/HH]
FSGD3A.SPID00.UINT32
FSGD3A.SPID00.UINT16[L/H]
FSGD3A.SPID00.UINT8[LL/LH/HL/HH]
FSGD3A.PROT01.UINT32
FSGD3A.PROT01.UINT16[L/H]
FSGD3A.PROT01.UINT8[LL/LH/HL/HH]
FSGD3A.SPID01.UINT32
FSGD3A.SPID01.UINT16[L/H]
FSGD3A.SPID01.UINT8[LL/LH/HL/HH]
FSGD3A.PROT02.UINT32
FSGD3A.PROT02.UINT16[L/H]
FSGD3A.PROT02.UINT8[LL/LH/HL/HH]
FSGD3A.SPID02.UINT32
FSGD3A.SPID02.UINT16[L/H]
FSGD3A.SPID02.UINT8[LL/LH/HL/HH]
FSGD3A.PROT03.UINT32
FSGD3A.PROT03.UINT16[L/H]
FSGD3A.PROT03.UINT8[LL/LH/HL/HH]
FSGD3A.SPID03.UINT32
FSGD3A.SPID03.UINT16[L/H]
FSGD3A.SPID03.UINT8[LL/LH/HL/HH]
FSGD3A.PROT04.UINT32
FSGD3A.PROT04.UINT16[L/H]
FSGD3A.PROT04.UINT8[LL/LH/HL/HH]
FSGD3A.SPID04.UINT32
FSGD3A.SPID04.UINT16[L/H]
FSGD3A.SPID04.UINT8[LL/LH/HL/HH]
FSGD3A.PROT05.UINT32
FSGD3A.PROT05.UINT16[L/H]
FSGD3A.PROT05.UINT8[LL/LH/HL/HH]
FSGD3A.SPID05.UINT32
FSGD3A.SPID05.UINT16[L/H]
FSGD3A.SPID05.UINT8[LL/LH/HL/HH]
FSGD3A.PROT06.UINT32
FSGD3A.PROT06.UINT16[L/H]
FSGD3A.PROT06.UINT8[LL/LH/HL/HH]
FSGD3A.SPID06.UINT32
FSGD3A.SPID06.UINT16[L/H]
FSGD3A.SPID06.UINT8[LL/LH/HL/HH]
FSGD3A.PROT07.UINT32
FSGD3A.PROT07.UINT16[L/H]
FSGD3A.PROT07.UINT8[LL/LH/HL/HH]
FSGD3A.SPID07.UINT32
FSGD3A.SPID07.UINT16[L/H]
FSGD3A.SPID07.UINT8[LL/LH/HL/HH]
FSGD3A.PROT08.UINT32
FSGD3A.PROT08.UINT16[L/H]
FSGD3A.PROT08.UINT8[LL/LH/HL/HH]
FSGD3A.SPID08.UINT32
FSGD3A.SPID08.UINT16[L/H]
FSGD3A.SPID08.UINT8[LL/LH/HL/HH]
FSGD3A.PROT09.UINT32
FSGD3A.PROT09.UINT16[L/H]
FSGD3A.PROT09.UINT8[LL/LH/HL/HH]
FSGD3A.SPID09.UINT32
FSGD3A.SPID09.UINT16[L/H]
FSGD3A.SPID09.UINT8[LL/LH/HL/HH]
FSGD3A.PROT10.UINT32
FSGD3A.PROT10.UINT16[L/H]
FSGD3A.PROT10.UINT8[LL/LH/HL/HH]
FSGD3A.SPID10.UINT32
FSGD3A.SPID10.UINT16[L/H]
FSGD3A.SPID10.UINT8[LL/LH/HL/HH]
FSGD3A.PROT11.UINT32
FSGD3A.PROT11.UINT16[L/H]
FSGD3A.PROT11.UINT8[LL/LH/HL/HH]
FSGD3A.SPID11.UINT32
FSGD3A.SPID11.UINT16[L/H]
FSGD3A.SPID11.UINT8[LL/LH/HL/HH]
FSGD3A.PROT12.UINT32
FSGD3A.PROT12.UINT16[L/H]
FSGD3A.PROT12.UINT8[LL/LH/HL/HH]
FSGD3A.SPID12.UINT32
FSGD3A.SPID12.UINT16[L/H]
FSGD3A.SPID12.UINT8[LL/LH/HL/HH]
FSGD3A.PROT13.UINT32
FSGD3A.PROT13.UINT16[L/H]
FSGD3A.PROT13.UINT8[LL/LH/HL/HH]
FSGD3A.SPID13.UINT32
FSGD3A.SPID13.UINT16[L/H]
FSGD3A.SPID13.UINT8[LL/LH/HL/HH]
FSGD3A.PROT14.UINT32
FSGD3A.PROT14.UINT16[L/H]
FSGD3A.PROT14.UINT8[LL/LH/HL/HH]
FSGD3A.SPID14.UINT32
FSGD3A.SPID14.UINT16[L/H]
FSGD3A.SPID14.UINT8[LL/LH/HL/HH]
FSGD3A.PROT15.UINT32
FSGD3A.PROT15.UINT16[L/H]
FSGD3A.PROT15.UINT8[LL/LH/HL/HH]
FSGD3A.SPID15.UINT32
FSGD3A.SPID15.UINT16[L/H]
FSGD3A.SPID15.UINT8[LL/LH/HL/HH]
ERRSLV3.CTL
ERRSLV3.STAT
ERRSLV3.TYPE
FSGD3B.PROT00.UINT32
FSGD3B.PROT00.UINT16[L/H]
FSGD3B.PROT00.UINT8[LL/LH/HL/HH]
FSGD3B.SPID00.UINT32
FSGD3B.SPID00.UINT16[L/H]
FSGD3B.SPID00.UINT8[LL/LH/HL/HH]
FSGD3B.PROT01.UINT32
FSGD3B.PROT01.UINT16[L/H]
FSGD3B.PROT01.UINT8[LL/LH/HL/HH]
FSGD3B.SPID01.UINT32
FSGD3B.SPID01.UINT16[L/H]
FSGD3B.SPID01.UINT8[LL/LH/HL/HH]
FSGD3B.PROT02.UINT32
FSGD3B.PROT02.UINT16[L/H]
FSGD3B.PROT02.UINT8[LL/LH/HL/HH]
FSGD3B.SPID02.UINT32
FSGD3B.SPID02.UINT16[L/H]
FSGD3B.SPID02.UINT8[LL/LH/HL/HH]
FSGD3B.PROT03.UINT32
FSGD3B.PROT03.UINT16[L/H]
FSGD3B.PROT03.UINT8[LL/LH/HL/HH]
FSGD3B.SPID03.UINT32
FSGD3B.SPID03.UINT16[L/H]
FSGD3B.SPID03.UINT8[LL/LH/HL/HH]
FSGD3B.PROT06.UINT32
FSGD3B.PROT06.UINT16[L/H]
FSGD3B.PROT06.UINT8[LL/LH/HL/HH]
FSGD3B.SPID06.UINT32
FSGD3B.SPID06.UINT16[L/H]
FSGD3B.SPID06.UINT8[LL/LH/HL/HH]
FSGD3B.PROT07.UINT32
FSGD3B.PROT07.UINT16[L/H]
FSGD3B.PROT07.UINT8[LL/LH/HL/HH]
FSGD3B.SPID07.UINT32
FSGD3B.SPID07.UINT16[L/H]
FSGD3B.SPID07.UINT8[LL/LH/HL/HH]
FSGD3B.PROT10.UINT32
FSGD3B.PROT10.UINT16[L/H]
FSGD3B.PROT10.UINT8[LL/LH/HL/HH]
FSGD3B.SPID10.UINT32
FSGD3B.SPID10.UINT16[L/H]
FSGD3B.SPID10.UINT8[LL/LH/HL/HH]
FSGD3B.PROT11.UINT32
FSGD3B.PROT11.UINT16[L/H]
FSGD3B.PROT11.UINT8[LL/LH/HL/HH]
FSGD3B.SPID11.UINT32
FSGD3B.SPID11.UINT16[L/H]
FSGD3B.SPID11.UINT8[LL/LH/HL/HH]
FSGD3B.PROT12.UINT32
FSGD3B.PROT12.UINT16[L/H]
FSGD3B.PROT12.UINT8[LL/LH/HL/HH]
FSGD3B.SPID12.UINT32
FSGD3B.SPID12.UINT16[L/H]
FSGD3B.SPID12.UINT8[LL/LH/HL/HH]
FSGD3B.PROT13.UINT32
FSGD3B.PROT13.UINT16[L/H]
FSGD3B.PROT13.UINT8[LL/LH/HL/HH]
FSGD3B.SPID13.UINT32
FSGD3B.SPID13.UINT16[L/H]
FSGD3B.SPID13.UINT8[LL/LH/HL/HH]
ERRSLV3AI.CTL
ERRSLV3AI.STAT
ERRSLV3AI.TYPE
NTU0.PRSCTL
NTU0.PRSCMP
NTU0.BPRSCTL
NTU0.BPRSCMP
NTU0.CPRSCTL
NTU0.CPRSCMP
NTU0.CCTL0
NTU0.CCMPL
NTU0.CCMPH
NTU0.CPCMD
NTU0.CPS
NTU0.RST
NTU0.CFG
NTU0.CLMEN
NTU0.MON
FSGDF0.PROT00.UINT32
FSGDF0.PROT00.UINT16[L/H]
FSGDF0.PROT00.UINT8[LL/LH/HL/HH]
FSGDF0.SPID00.UINT32
FSGDF0.SPID00.UINT16[L/H]
FSGDF0.SPID00.UINT8[LL/LH/HL/HH]
FSGDF0.PROT01.UINT32
FSGDF0.PROT01.UINT16[L/H]
FSGDF0.PROT01.UINT8[LL/LH/HL/HH]
FSGDF0.SPID01.UINT32
FSGDF0.SPID01.UINT16[L/H]
FSGDF0.SPID01.UINT8[LL/LH/HL/HH]
ERRSLVF0.CTL
ERRSLVF0.STAT
ERRSLVF0.TYPE
FSGDE0.PROT00.UINT32
FSGDE0.PROT00.UINT16[L/H]
FSGDE0.PROT00.UINT8[LL/LH/HL/HH]
FSGDE0.SPID00.UINT32
FSGDE0.SPID00.UINT16[L/H]
FSGDE0.SPID00.UINT8[LL/LH/HL/HH]
FSGDE0.PROT01.UINT32
FSGDE0.PROT01.UINT16[L/H]
FSGDE0.PROT01.UINT8[LL/LH/HL/HH]
FSGDE0.SPID01.UINT32
FSGDE0.SPID01.UINT16[L/H]
FSGDE0.SPID01.UINT8[LL/LH/HL/HH]
ERRSLVE0.CTL
ERRSLVE0.STAT
ERRSLVE0.TYPE
ERRSLVFI.CTL
ERRSLVFI.STAT
ERRSLVFI.TYPE
ERRSLVEI.CTL
ERRSLVEI.STAT
ERRSLVEI.TYPE
ERRSLVMI.CTL
ERRSLVMI.STAT
ERRSLVMI.TYPE
ERRSLVHI.CTL
ERRSLVHI.STAT
ERRSLVHI.TYPE
ERRSLVXI.CTL
ERRSLVXI.STAT
ERRSLVXI.TYPE
HSSPID.RG0 ... HSSPID.RG7
HTHDMA.CTL.UINT32
HTHDMA.CTL.UINT16[L]
HTHDMA.CTL.UINT8[LL]
HTHDMA.STAT.UINT32
HTHDMA.STAT.UINT16[L]
HTHDMA.STAT.UINT8[LL]
IPG.ECRUM
IPG.ADRUM
IPG.ENUM.UINT8
IPG.ENUM.BIT.E
IPG.ENUM.BIT.IRE
IPG.PMTUM0.UINT8
IPG.PMTUM0.BIT.R0
IPG.PMTUM0.BIT.W0
IPG.PMTUM0.BIT.X0
IPG.PMTUM0.BIT.R1
IPG.PMTUM0.BIT.W1
IPG.PMTUM0.BIT.X1
IPG.PMTUM1.UINT8
IPG.PMTUM1.BIT.X0
IPG.PMTUM1.BIT.X1
IPG.PMTUM2.UINT8
IPG.PMTUM2.BIT.R0
IPG.PMTUM2.BIT.W0
IPG.PMTUM2.BIT.R1
IPG.PMTUM2.BIT.W1
IPG.PMTUM3.UINT8
IPG.PMTUM3.BIT.R1
IPG.PMTUM3.BIT.W1
IPG.PMTUM4.UINT8
IPG.PMTUM4.BIT.R0
IPG.PMTUM4.BIT.W0
PEG.G0MK.UINT32
PEG.G0MK.UINT16[L/H]
PEG.G0MK.UINT8[LL/LH/HL/HH]
PEG.G0BA.UINT32
PEG.G0BA.UINT16[L/H]
PEG.G0BA.UINT8[LL/LH/HL/HH]
PEG.G0SP.UINT32
PEG.G0SP.UINT16[L/H]
PEG.G0SP.UINT8[LL/LH/HL/HH]
PEG.G1MK.UINT32
PEG.G1MK.UINT16[L/H]
PEG.G1MK.UINT8[LL/LH/HL/HH]
PEG.G1BA.UINT32
PEG.G1BA.UINT16[L/H]
PEG.G1BA.UINT8[LL/LH/HL/HH]
PEG.G1SP.UINT32
PEG.G1SP.UINT16[L/H]
PEG.G1SP.UINT8[LL/LH/HL/HH]
PEG.G2MK.UINT32
PEG.G2MK.UINT16[L/H]
PEG.G2MK.UINT8[LL/LH/HL/HH]
PEG.G2BA.UINT32
PEG.G2BA.UINT16[L/H]
PEG.G2BA.UINT8[LL/LH/HL/HH]
PEG.G2SP.UINT32
PEG.G2SP.UINT16[L/H]
PEG.G2SP.UINT8[LL/LH/HL/HH]
PEG.G3MK.UINT32
PEG.G3MK.UINT16[L/H]
PEG.G3MK.UINT8[LL/LH/HL/HH]
PEG.G3BA.UINT32
PEG.G3BA.UINT16[L/H]
PEG.G3BA.UINT8[LL/LH/HL/HH]
PEG.G3SP.UINT32
PEG.G3SP.UINT16[L/H]
PEG.G3SP.UINT8[LL/LH/HL/HH]
PEG.G4MK.UINT32
PEG.G4MK.UINT16[L/H]
PEG.G4MK.UINT8[LL/LH/HL/HH]
PEG.G4BA.UINT32
PEG.G4BA.UINT16[L/H]
PEG.G4BA.UINT8[LL/LH/HL/HH]
PEG.G4SP.UINT32
PEG.G4SP.UINT16[L/H]
PEG.G4SP.UINT8[LL/LH/HL/HH]
PEG.G5MK.UINT32
PEG.G5MK.UINT16[L/H]
PEG.G5MK.UINT8[LL/LH/HL/HH]
PEG.G5BA.UINT32
PEG.G5BA.UINT16[L/H]
PEG.G5BA.UINT8[LL/LH/HL/HH]
PEG.G5SP.UINT32
PEG.G5SP.UINT16[L/H]
PEG.G5SP.UINT8[LL/LH/HL/HH]
PEG.G6MK.UINT32
PEG.G6MK.UINT16[L/H]
PEG.G6MK.UINT8[LL/LH/HL/HH]
PEG.G6BA.UINT32
PEG.G6BA.UINT16[L/H]
PEG.G6BA.UINT8[LL/LH/HL/HH]
PEG.G6SP.UINT32
PEG.G6SP.UINT16[L/H]
PEG.G6SP.UINT8[LL/LH/HL/HH]
PEG.G7MK.UINT32
PEG.G7MK.UINT16[L/H]
PEG.G7MK.UINT8[LL/LH/HL/HH]
PEG.G7BA.UINT32
PEG.G7BA.UINT16[L/H]
PEG.G7BA.UINT8[LL/LH/HL/HH]
PEG.G7SP.UINT32
PEG.G7SP.UINT16[L/H]
PEG.G7SP.UINT8[LL/LH/HL/HH]
SEG.CONT
SEG.FLAG
SEG.TYPE
SEG.SIDE
SEG.ADDR.UINT32
SEG.ADDR.UINT16[L/H]
*/
#endif
