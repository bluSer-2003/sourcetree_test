/*****************************************************************************/
/* PROJECT = MTTCAN Type MTTCAN_R321                                             */
/*****************************************************************************/
/*                                  COPYRIGHT                                */
/*===========================================================================*/
/* Copyright (c) 2016 by Renesas Electronics Europe GmbH,                    */
/*               a company of the Renesas Electronics Corporation            */
/*===========================================================================*/
/*===========================================================================*/
/* In case of any question please do not hesitate to contact:                */
/*                                                                           */
/*        ABG.Support                                                        */
/*                                                                           */
/*        Renesas Electronics Europe GmbH                                    */
/*        Arcadiastrasse 10                                                  */
/*        D-40472 Duesseldorf, Germany                                       */
/*                                                                           */
/*        e-mail: device_support.rl78-eu@lm.renesas.com                      */
/*        FAX:   +49 - (0)211 / 65 03 - 12 79                                */
/*                                                                           */
/*===========================================================================*/
/* Warranty Disclaimer                                                       */
/*                                                                           */
/* Because the Product(s) is licensed free of charge, there is no warranty   */
/* of any kind whatsoever and expressly disclaimed and excluded by Renesas,  */
/* either expressed or implied, including but not limited to those for       */
/* non-infringement of intellectual property, merchantability and/or         */
/* fitness for the particular purpose.                                       */
/* Renesas shall not have any obligation to maintain, service or provide bug */
/* fixes for the supplied Product(s) and/or the Application.                 */
/*                                                                           */
/* Each User is solely responsible for determining the appropriateness of    */
/* using the Product(s) and assumes all risks associated with its exercise   */
/* of rights under this Agreement, including, but not limited to the risks   */
/* and costs of program errors, compliance with applicable laws, damage to   */
/* or loss of data, programs or equipment, and unavailability or             */
/* interruption of operations.                                               */
/*                                                                           */
/* Limitation of Liability                                                   */
/*                                                                           */
/* In no event shall Renesas be liable to the User for any incidental,       */
/* consequential, indirect, or punitive damage (including but not limited    */
/* to lost profits) regardless of whether such liability is based on breach  */
/* of contract, tort, strict liability, breach of warranties, failure of     */
/* essential purpose or otherwise and even if advised of the possibility of  */
/* such damages. Renesas shall not be liable for any services or products    */
/* provided by third party vendors, developers or consultants identified or  */
/* referred to the User by Renesas in connection with the Product(s) and/or  */
/* the Application.                                                          */
/*                                                                           */
/*===========================================================================*/

#ifndef _MTTCAN_R321
#define _MTTCAN_R321
                   
#include <ree_types.h>

/* MTTCAN Globals */

#define MTTCAN_0       ( 0 )         /* MTTCAN macro selection */
#define MTTCAN_1       ( 1 )
#define MTTCAN_2       ( 2 )
#define MTTCAN_INVALID ( 0xFF )      /* no macro assignment */

#define MTTCAN_NOIRQ   false         /* status report defines */
#define MTTCAN_IRQ     true
#define MTTCAN_OK      true
#define MTTCAN_ERROR   false

#define MTTCAN_CONFIG_OK                  ( 0 )
#define MTTCAN_CONFIG_ERROR_UNITNOTEXIST  ( 1 )
#define MTTCAN_CONFIG_ERROR_NOTININIT     ( 2 )
#define MTTCAN_CONFIG_ERROR_BITTIMING     ( 3 )
#define MTTCAN_CONFIG_ERROR_OUTOFRAM      ( 4 )
#define MTTCAN_CONFIG_ERROR_HWTIMEOUT     ( 5 )

#define MTTCAN_SET     ( 1 )
#define MTTCAN_CLEAR   ( 0 )

#define MTTCAN_ID_STD        ( 0 )
#define MTTCAN_ID_EXT        ( 1 )
#define MTTCAN_ID_MAX        ( 0x1FFFFFFF )
#define MTTCAN_ID_STD_SHIFT  ( 18 )

#define MTTCAN_FRAME_DATA    ( 0 )
#define MTTCAN_FRAME_REMOTE  ( 1 )

#define MTTCAN_MASK_EXTIDFULLCAN  ( 0x1FFFFFFF )
#define MTTCAN_MASK_EXTIDDONTCARE ( 0x00000000 )
#define MTTCAN_MASK_STDIDFULLCAN  ( 0x7FF )
#define MTTCAN_MASK_STDIDDONTCARE ( 0x000 )
#define MTTCAN_MASK_DONTCARE      ( 0 )
#define MTTCAN_MASK_FILTER        ( 1 )

#define MTTCAN_DLC_CMAX  ( 8 )
#define MTTCAN_DLC_FDMAX ( 64 )
#define MTTCAN_DLC_FD_12 ( 9 )
#define MTTCAN_DLC_FD_16 ( 10 )
#define MTTCAN_DLC_FD_20 ( 11 )
#define MTTCAN_DLC_FD_24 ( 12 )
#define MTTCAN_DLC_FD_32 ( 13 )
#define MTTCAN_DLC_FD_48 ( 14 )
#define MTTCAN_DLC_FD_64 ( 15 )

#define MTTCAN_BUFDL_8   ( 0 )
#define MTTCAN_BUFDL_12  ( 1 )
#define MTTCAN_BUFDL_16  ( 2 )
#define MTTCAN_BUFDL_20  ( 3 )
#define MTTCAN_BUFDL_24  ( 4 )
#define MTTCAN_BUFDL_32  ( 5 )
#define MTTCAN_BUFDL_48  ( 6 )
#define MTTCAN_BUFDL_64  ( 7 )
#define MTTCAN_BUFDL_MAX ( 64 )

#define MTTCAN_INT_LINES   ( 3 )
#define MTTCAN_INT_LINE_0  ( 0 )
#define MTTCAN_INT_LINE_1  ( 1 )
#define MTTCAN_INT_LINE_FE ( 2 )           /* Filter Event Interrupt Line */
#define MTTCAN_INT_NOINT   ( 0xFF )
#define MTTCAN_INT_ENABLE  ( 0x01 )
#define MTTCAN_INT_DISABLE ( 0x00 )

/* Msximum configuration parameters */

#define MTTCAN_MAXTXEVENTS        ( 32 )
#define MTTCAN_MAXTXBUFFERS       ( 32 )
#define MTTCAN_MAXRXBUFFERS       ( 64 )

/* RAM Object Sizes in Bytes and RAM Sections */

#define MTTCAN_RAMSIZE_STDFILTER ( 4 )
#define MTTCAN_RAMSIZE_EXTFILTER ( 8 )
#define MTTCAN_RAMSIZE_THL       ( 8 )

#define MTTCAN_RAMSIZE_OBJECT_0  ( 8 )
#define MTTCAN_RAMSIZE_OBJECT_8  ( 16 )
#define MTTCAN_RAMSIZE_OBJECT_12 ( 20 )
#define MTTCAN_RAMSIZE_OBJECT_16 ( 24 )
#define MTTCAN_RAMSIZE_OBJECT_20 ( 28 )
#define MTTCAN_RAMSIZE_OBJECT_24 ( 32 )
#define MTTCAN_RAMSIZE_OBJECT_32 ( 40 )
#define MTTCAN_RAMSIZE_OBJECT_48 ( 56 )
#define MTTCAN_RAMSIZE_OBJECT_64 ( 72 )

#define MTTCAN_RAMSECTIONS          ( 8 )
#define MTTCAN_RAMSECTION_BASE      ( 0 )
#define MTTCAN_RAMSECTION_STDFILTER ( 1 )
#define MTTCAN_RAMSECTION_EXTFILTER ( 2 )
#define MTTCAN_RAMSECTION_RXFIFO0   ( 3 )
#define MTTCAN_RAMSECTION_RXFIFO1   ( 4 )
#define MTTCAN_RAMSECTION_RXBUFFERS ( 5 )
#define MTTCAN_RAMSECTION_THL       ( 6 )
#define MTTCAN_RAMSECTION_TXBUFFERS ( 7 )

/* Arbitration Bittiming settings */

#define MTTCAN_BT_SPEC            ( true )
#define MTTCAN_BT_MAXTQ           ( 385 )
#define MTTCAN_BT_MINTQ           ( 5 )
#define MTTCAN_BT_MINTSEG1        ( 2 )
#define MTTCAN_BT_MAXTSEG1        ( 256 )
#define MTTCAN_BT_MINTSEG2        ( 2 )
#define MTTCAN_BT_MAXTSEG2        ( 128 )
#define MTTCAN_BT_MINSJW          ( 1 )
#define MTTCAN_BT_MAXSJW          ( 128 )
#define MTTCAN_BT_SYNCSEGLEN      ( 1 )

#define MTTCAN_BT_MAXBRP          ( 512 )
#define MTTCAN_BT_MINBRP          ( 1 )
#define MTTCAN_BT_SPTOPTIMUM      ( 0.75 )

/* Data Bittiming settings */

#define MTTCAN_BTD_SPEC           ( false )
#define MTTCAN_BTD_MAXTQ          ( 49 )
#define MTTCAN_BTD_MINTQ          ( 4 )
#define MTTCAN_BTD_MINTSEG1       ( 1 )
#define MTTCAN_BTD_MAXTSEG1       ( 32 )
#define MTTCAN_BTD_MINTSEG2       ( 1 )
#define MTTCAN_BTD_MAXTSEG2       ( 16 )
#define MTTCAN_BTD_MINSJW         ( 1 )
#define MTTCAN_BTD_MAXSJW         ( 16 )
#define MTTCAN_BTD_SYNCSEGLEN     ( 1 )

#define MTTCAN_BTD_MAXBRP         ( 32 )
#define MTTCAN_BTD_MINBRP         ( 1 )
#define MTTCAN_BTD_SPTOPTIMUM     ( 0.75 )

#define MTTCAN_FDF_CLASSIC        ( 0 )
#define MTTCAN_FDF_FD             ( 1 )
#define MTTCAN_BRS_SWITCH         ( 1 )
#define MTTCAN_BRS_NOSWITCH       ( 0 )

/* Clocking relationships of TL and system */

#define MTTCAN_TRLAYERFACTOR      ( 1 )
#define MTTCAN_CLKMINFACTOR       ( 4 )

/* Interrupt management */

#define MTTCAN_CINT_OFF         ( 0x00000000L )
#define MTTCAN_CINT_ALL         ( 0xFFFFFFFFL )

#define MTTCAN_CINT_RF0N        ( 0x00000001L )     /* RX FIFO Interrupts */
#define MTTCAN_CINT_RF0W        ( 0x00000002L )
#define MTTCAN_CINT_RF0F        ( 0x00000004L )
#define MTTCAN_CINT_RF0L        ( 0x00000008L )
#define MTTCAN_CINT_RF1N        ( 0x00000010L )
#define MTTCAN_CINT_RF1W        ( 0x00000020L )
#define MTTCAN_CINT_RF1F        ( 0x00000040L )
#define MTTCAN_CINT_RF1L        ( 0x00000080L )

#define MTTCAN_CINT_DRX         ( 0x00080000L )     /* RX Buffer Interrupt */

#define MTTCAN_CINT_HPM         ( 0x00000100L )     /* High Priority Message */

#define MTTCAN_CINT_TC          ( 0x00000200L )     /* Transmit Interrupts */
#define MTTCAN_CINT_TCF         ( 0x00000400L )

#define MTTCAN_CINT_TFE         ( 0x00000800L )     /* TX FIFO Interrupts */

#define MTTCAN_CINT_TEFN        ( 0x00001000L )     /* TX Event FIFO Interrupts */
#define MTTCAN_CINT_TEFW        ( 0x00002000L )
#define MTTCAN_CINT_TEFF        ( 0x00004000L )
#define MTTCAN_CINT_TEFL        ( 0x00008000L )

#define MTTCAN_CINT_ELO         ( 0x00400000L )     /* Error Processing Interrupts */
#define MTTCAN_CINT_EP          ( 0x00800000L )
#define MTTCAN_CINT_EW          ( 0x01000000L )
#define MTTCAN_CINT_BO          ( 0x02000000L )

#define MTTCAN_CINT_PEA         ( 0x08000000L )     /* Protocol Error Interrupts */
#define MTTCAN_CINT_PED         ( 0x10000000L )

#define MTTCAN_CINT_TSW         ( 0x00010000L )     /* Timestamp Interrupt */

#define MTTCAN_CINT_MRAF        ( 0x00020000L )     /* Supervision Interrupts */
#define MTTCAN_CINT_TOO         ( 0x00040000L )
#define MTTCAN_CINT_BEC         ( 0x00100000L )
#define MTTCAN_CINT_BEU         ( 0x00200000L )
#define MTTCAN_CINT_WDI         ( 0x04000000L )
#define MTTCAN_CINT_ARA         ( 0x20000000L )

/* Operation Modes */

#define MTTCAN_OPMODE           ( 0x0F )
#define MTTCAN_OPMODE_KEEP      ( 0x00 )
#define MTTCAN_OPMODE_INIT      ( 0x04 )
#define MTTCAN_OPMODE_CLASSIC   ( 0x03 )
#define MTTCAN_OPMODE_CANFD     ( 0x01 )
#define MTTCAN_OPMODE_CANFDBRS  ( 0x02 )

/* Special Modes */

#define MTTCAN_SPMODE           ( 0xF0 )
#define MTTCAN_SPMODE_NONE      ( 0x00 )
#define MTTCAN_SPMODE_STEST     ( 0x10 )
#define MTTCAN_SPMODE_RECONLY   ( 0x20 )
#define MTTCAN_SPMODE_SSHOT     ( 0x40 )
#define MTTCAN_SPMODE_RESTRICT  ( 0x80 )

/* Power Modes */

#define MTTCAN_PSMODE           ( MTTCAN_OPMODE )
#define MTTCAN_PSMODE_RUN       ( MTTCAN_OPMODE_KEEP )
#define MTTCAN_PSMODE_STOP      ( 0x08 )
#define MTTCAN_PSMODE_INIT      ( MTTCAN_OPMODE_INIT )

/* Bus activity */

#define MTTCAN_ACT_INTEGRATING  ( 0x00 )
#define MTTCAN_ACT_IDLE         ( 0x01 )
#define MTTCAN_ACT_RECEIVE      ( 0x02 )
#define MTTCAN_ACT_TRANSMIT     ( 0x03 )

/* Error Levels */

#define MTTCAN_ERROR_ACTIVE     ( 0x00 )
#define MTTCAN_ERROR_WARNING    ( 0x01 )
#define MTTCAN_ERROR_PASSIVE    ( 0x02 )
#define MTTCAN_ERROR_BUSOFF     ( 0x04 )

/* Detail Error Codes */

#define MTTCAN_ERRORDETAIL_NONE    ( 0x00 )
#define MTTCAN_ERRORDETAIL_STUFF   ( 0x01 )
#define MTTCAN_ERRORDETAIL_FORM    ( 0x02 )
#define MTTCAN_ERRORDETAIL_ACK     ( 0x03 )
#define MTTCAN_ERRORDETAIL_BIT1    ( 0x04 )
#define MTTCAN_ERRORDETAIL_BIT0    ( 0x05 )
#define MTTCAN_ERRORDETAIL_CRC     ( 0x06 )
#define MTTCAN_ERRORDETAIL_CLEAR   ( 0x07 )

/* Status Qualifiers */

#define MTTCAN_STATUS_OPMODE       ( 0x01 )
#define MTTCAN_STATUS_SPMODE       ( 0x02 )
#define MTTCAN_STATUS_PSMODE       ( 0x03 )
#define MTTCAN_STATUS_RECEIVE      ( 0x04 )
#define MTTCAN_STATUS_TRANSMIT     ( 0x05 )
#define MTTCAN_STATUS_BUSOFF       ( 0x06 )
#define MTTCAN_STATUS_ERRCNTLEV    ( 0x07 )
#define MTTCAN_STATUS_TOVF         ( 0x08 )
#define MTTCAN_STATUS_THPM         ( 0x09 )
#define MTTCAN_STATUS_TGPT         ( 0x0A )
#define MTTCAN_STATUS_NEWTXHISTORY ( 0x0B )
#define MTTCAN_STATUS_VALID        ( 0x0C )
#define MTTCAN_STATUS_TRERRCOUNT   ( 0x0D )
#define MTTCAN_STATUS_RXERRCOUNT   ( 0x0E )
#define MTTCAN_STATUS_ERRPLEV      ( 0x0F )
#define MTTCAN_STATUS_MLT_RXFIFO0  ( 0x10 )
#define MTTCAN_STATUS_MLT_RXFIFO1  ( 0x11 )
#define MTTCAN_STATUS_ERRCODE_CLAR ( 0x12 )
#define MTTCAN_STATUS_ERRCODE_FDAT ( 0x13 )
#define MTTCAN_STATUS_TXTS         ( 0x14 )

/* Acceptance Filter Management */

#define MTTCAN_GAF_RXFIFO0      ( 0x00 )            /* Non-matching acceptance */
#define MTTCAN_GAF_RXFIFO1      ( 0x01 )
#define MTTCAN_GAF_REJECT       ( 0x03 )

/* Message Storage Indicator */

#define MTTCAN_MSI_NOFIFO       ( 0x00 )            /* Status of high-prio messages */
#define MTTCAN_MSI_LOST         ( 0x01 )
#define MTTCAN_MSI_FIFO0        ( 0x02 )
#define MTTCAN_MSI_FIFO1        ( 0x03 )

/* Transmit handling */

#define MTTCAN_TX_REQUEST       ( 0x01 )            /* to be shifted to buffer bit position */
#define MTTCAN_TX_ABORT         ( 0x01 )            /* in corresponding registers */
#define MTTCAN_TX_PENDING       ( 0x01 )
#define MTTCAN_TX_COMPLETE      ( 0x01 )
#define MTTCAN_TX_ABORTED       ( 0x01 )
#define MTTCAN_TX_INT_ENABLE    ( 0x01 )
#define MTTCAN_TX_INT_DISABLE   ( 0x00 )
#define MTTCAN_TX_ABORTALL      ( 0xFFFFFFFF )

/* Timestamp Configuration */

#define MTTCAN_TSS_OFF          ( 0x00 )
#define MTTCAN_TSS_INTERNAL     ( 0x01 )
#define MTTCAN_TSS_EXTERNAL     ( 0x02 )

/* Filter Configuration */

#define MTTCAN_GFC_REMOTEREJECT  ( 0x01 )
#define MTTCAN_GFC_REMOTEACCEPT  ( 0x00 )
#define MTTCAN_GFC_NOMATCHFIFO0  ( 0x00 )
#define MTTCAN_GFC_NOMATCHFIFO1  ( 0x01 )
#define MTTCAN_GFC_NOMATCHREJECT ( 0x02 )

#define MTTCAN_EID_MASK_INACTIVE ( 0x1FFFFFFF )

#define MTTCAN_FILTER_DISABLED     ( 0x00 )
#define MTTCAN_FILTER_STORE_FIFO0  ( 0x01 )
#define MTTCAN_FILTER_STORE_FIFO1  ( 0x02 )
#define MTTCAN_FILTER_REJECT       ( 0x03 )
#define MTTCAN_FILTER_PRIORITY     ( 0x04 )
#define MTTCAN_FILTER_STORE_BUFFER ( 0x07 )

#define MTTCAN_FILTER_BUFFER_STORE ( 0x00000000 )
#define MTTCAN_FILTER_BUFFER_DBG_A ( 0x00000200 )
#define MTTCAN_FILTER_BUFFER_DBG_B ( 0x00000400 )
#define MTTCAN_FILTER_BUFFER_DBG_C ( 0x00000600 )

#define MTTCAN_FILTERTYPE_IGNORED  ( 0 )
#define MTTCAN_FILTERTYPE_RANGE    ( 0 )
#define MTTCAN_FILTERTYPE_DUAL     ( 1 )
#define MTTCAN_FILTERTYPE_CLASSIC  ( 2 )

/* Watermark off configuration */

#define MTTCAN_WATERMARK_OFF       ( 0 )

/* RX FIFO Configuration */

#define MTTCAN_FIFO_MODE_BLOCKING  ( 0 )
#define MTTCAN_FIFO_MODE_OVERWRITE ( 1 )

/* TX Buffer Configuration */

#define MTTCAN_TXB_FIFOMODE        ( 0 )
#define MTTCAN_TXB_QUEUEMODE       ( 1 )

/* Driver Parameters */

#define MTTCAN_PATH_MSGBOX      ( 0x00 )
#define MTTCAN_PATH_FIFOQUEUE   ( 0x01 )
#define MTTCAN_PATH_ANY         ( 0xFF )

#define MTTCAN_PATHDETAIL_ANY   ( 0xFF )

#define MTTCAN_FAULT_NONE       ( 0x00 )
#define MTTCAN_FAULT_PARAMETER  ( 0x01 )
#define MTTCAN_FAULT_BUSY       ( 0x02 )
#define MTTCAN_FAULT_NODATA     ( 0x04 )
#define MTTCAN_FAULT_OTHER      ( 0xFF )

/*............... The MTTCAN access structures ............................*/

/* Registers */

typedef struct ee_mttcan_c_crel
{
  volatile u32                  day       : 8;
  volatile u32                  mon       : 8;
  volatile u32                  year      : 4;
  volatile u32                  substep   : 4;
  volatile u32                  step      : 4;
  volatile u32                  rel       : 4;
  
} ee_mttcan_c_crel;

typedef struct ee_mttcan_c_dbtp
{
  volatile u32                  dsjw      : 4;
  volatile u32                  dtseg2    : 4;
  volatile u32                  dtseg1    : 5;
  volatile u32                  RESERVED0 : 3;
  volatile u32                  dbrp      : 5;
  volatile u32                  RESERVED1 : 2;
  volatile u32                  tdc       : 1;
  volatile u32                  RESERVED4 : 8;
  
} ee_mttcan_c_dbtp;

typedef struct ee_mttcan_c_test
{
  volatile u32                  RESERVED0 : 4;
  volatile u32                  lbck      : 1;
  volatile u32                  tx        : 2;
  volatile u32                  rx        : 1;
  volatile u32                  RESERVED1 : 24;
  
} ee_mttcan_c_test;

typedef struct ee_mttcan_c_rwd
{
  volatile u32                  wdc       : 8;
  volatile u32                  wdv       : 8;
  volatile u32                  RESERVED0 : 16;
  
} ee_mttcan_c_rwd;

typedef struct ee_mttcan_c_cccr
{
  volatile u32                  init      : 1;
  volatile u32                  cce       : 1;
  volatile u32                  rom       : 1;
  volatile u32                  csa       : 1;
  volatile u32                  csr       : 1;
  volatile u32                  mon       : 1;
  volatile u32                  dar       : 1;
  volatile u32                  test      : 1;
  volatile u32                  fdoe      : 1;
  volatile u32                  brse      : 1;
  volatile u32                  RESERVED0 : 2;
  volatile u32                  pxhd      : 1;
  volatile u32                  efbi      : 1;
  volatile u32                  txp       : 1;
  volatile u32                  niso      : 1;
  volatile u32                  RESERVED1 : 16;
  
} ee_mttcan_c_cccr;

typedef struct ee_mttcan_c_nbtp
{
  volatile u32                  ntseg2    : 7;
  volatile u32                  RESERVED0 : 1;
  volatile u32                  ntseg1    : 8;
  volatile u32                  nbrp      : 9;
  volatile u32                  nsjw      : 7;
  
} ee_mttcan_c_nbtp;

typedef struct ee_mttcan_c_tscc
{
  volatile u32                  tss       : 2;
  volatile u32                  RESERVED0 : 14;
  volatile u32                  tcp       : 4;
  volatile u32                  RESERVED1 : 12;
  
} ee_mttcan_c_tscc;

typedef struct ee_mttcan_c_tscv
{
  volatile u32                  tsc       : 16;
  volatile u32                  RESERVED0 : 16;
  
} ee_mttcan_c_tscv;

typedef struct ee_mttcan_c_tocc
{
  volatile u32                  etoc      : 1;
  volatile u32                  tos       : 2;
  volatile u32                  RESERVED0 : 13;
  volatile u32                  top       : 16;
  
} ee_mttcan_c_tocc;

typedef struct ee_mttcan_c_tocv
{
  volatile u32                  toc       : 16;
  volatile u32                  RESERVED0 : 16;
  
} ee_mttcan_c_tocv;

typedef struct ee_mttcan_c_ecr
{
  volatile u32                  tec       : 8;
  volatile u32                  rec       : 7;
  volatile u32                  rp        : 1;
  volatile u32                  cel       : 8;
  volatile u32                  RESERVED0 : 8;
  
} ee_mttcan_c_ecr;

typedef struct ee_mttcan_c_psr
{
  volatile u32                  lec       : 3;
  volatile u32                  act       : 2;
  volatile u32                  ep        : 1;
  volatile u32                  ew        : 1;
  volatile u32                  bo        : 1;
  volatile u32                  dlec      : 3;
  volatile u32                  resi      : 1;
  volatile u32                  rbrs      : 1;
  volatile u32                  rfdf      : 1;
  volatile u32                  pxe       : 1;
  volatile u32                  RESERVED0 : 1;
  volatile u32                  tdcv      : 7;
  volatile u32                  RESERVED1 : 9;
  
} ee_mttcan_c_psr;

typedef struct ee_mttcan_c_tdcr
{
  volatile u32									tdcf      : 7;
  volatile u32									RESERVED0 : 1;
  volatile u32									tdco      : 7;
  volatile u32									RESERVED1 : 17;
	
} ee_mttcan_c_tdcr;

typedef struct ee_mttcan_c_ile
{
  volatile u32                  eint      : 2;
  volatile u32                  RESERVED0 : 30;
  
} ee_mttcan_c_ile;

typedef struct ee_mttcan_c_gfc
{
  volatile u32                  rrfe      : 1;
  volatile u32                  rrfs      : 1;
  volatile u32                  anfe      : 2;
  volatile u32                  anfs      : 2;
  volatile u32                  RESERVED0 : 26;
  
} ee_mttcan_c_gfc;

typedef struct ee_mttcan_c_sidfc
{
  volatile u32                  RESERVED0 : 2;
  volatile u32                  flssa     : 14;
  volatile u32                  lss       : 8;
  volatile u32                  RESERVED1 : 8;
  
} ee_mttcan_c_sidfc;

typedef struct ee_mttcan_c_xidfc
{
  volatile u32                  RESERVED0 : 2;
  volatile u32                  flesa     : 14;
  volatile u32                  lse       : 8;
  volatile u32                  RESERVED1 : 8;
  
} ee_mttcan_c_xidfc;

typedef struct ee_mttcan_c_xidam
{
  volatile u32                  eidm      : 29;
  volatile u32                  RESERVED0 : 3;
  
} ee_mttcan_c_xidam;

typedef struct ee_mttcan_c_hpms
{
  volatile u32                  bidx      : 6;
  volatile u32                  msi       : 2;
  volatile u32                  fidx      : 7;
  volatile u32                  flst      : 1;
  volatile u32                  RESERVED0 : 16;
  
} ee_mttcan_c_hpms;

typedef struct ee_mttcan_c_rxfc
{
  volatile u32                  RESERVED0 : 2;
  volatile u32                  fsa       : 14;
  volatile u32                  fs        : 7;
  volatile u32                  RESERVED1 : 1;
  volatile u32                  fwm       : 7;
  volatile u32                  fom       : 1;
  
} ee_mttcan_c_rxfc;

typedef struct ee_mttcan_c_rxfs
{
  volatile u32                  ffl       : 7;
  volatile u32                  RESERVED0 : 1;
  volatile u32                  fgi       : 6;
  volatile u32                  RESERVED1 : 2;
  volatile u32                  fpi       : 6;
  volatile u32                  RESERVED2 : 2;
  volatile u32                  ff        : 1;
  volatile u32                  rfl       : 1;
  volatile u32                  RESERVED3 : 6;
  
} ee_mttcan_c_rxfs;

typedef struct ee_mttcan_c_rxfa
{
  volatile u32                  fai       : 6;
  volatile u32                  RESERVED0 : 26;
  
} ee_mttcan_c_rxfa;

typedef struct ee_mttcan_c_rxbc
{
  volatile u32                  RESERVED0 : 2;
  volatile u32                  rbsa      : 14;
  volatile u32                  RESERVED1 : 16;
  
} ee_mttcan_c_rxbc;

typedef struct ee_mttcan_c_rxesc
{
  volatile u32                  f0ds      : 3;
  volatile u32                  RESERVED0 : 1;
  volatile u32                  f1ds      : 3;
  volatile u32                  RESERVED1 : 1;
  volatile u32                  rbds      : 3;
  volatile u32                  RESERVED2 : 21;
  
} ee_mttcan_c_rxesc;

typedef struct ee_mttcan_c_txbc
{
  volatile u32                  RESERVED0 : 2;
  volatile u32                  tbsa      : 14;
  volatile u32                  ndtb      : 6;
  volatile u32                  RESERVED1 : 2;
  volatile u32                  tfqs      : 6;
  volatile u32                  tfqm      : 1;
  volatile u32                  RESERVED2 : 1;
  
} ee_mttcan_c_txbc;

typedef struct ee_mttcan_c_txfqs
{
  volatile u32                  tffl      : 6;
  volatile u32                  RESERVED0 : 2;
  volatile u32                  tfgi      : 5;
  volatile u32                  RESERVED1 : 3;
  volatile u32                  tfqpi     : 5;
  volatile u32                  tfqf      : 1;
  volatile u32                  RESERVED2 : 10;
  
} ee_mttcan_c_txfqs;

typedef struct ee_mttcan_c_txesc
{
  volatile u32                  tbds      : 3;
  volatile u32                  RESERVED0 : 29;
  
} ee_mttcan_c_txesc;

typedef struct ee_mttcan_c_txefc
{
  volatile u32                  RESERVED0 : 2;
  volatile u32                  efsa      : 14;
  volatile u32                  efs       : 6;
  volatile u32                  RESERVED1 : 2;
  volatile u32                  efwm      : 6;
  volatile u32                  RESERVED2 : 2;
  
} ee_mttcan_c_txefc;

typedef struct ee_mttcan_c_txefs
{
  volatile u32                  effl      : 6;
  volatile u32                  RESERVED0 : 2;
  volatile u32                  efgi      : 5;
  volatile u32                  RESERVED1 : 3;
  volatile u32                  efpi      : 5;
  volatile u32                  RESERVED2 : 3;
  volatile u32                  eff       : 1;
  volatile u32                  tefl      : 1;
  volatile u32                  RESERVED3 : 6;
  
} ee_mttcan_c_txefs;

typedef struct ee_mttcan_c_txefa
{
  volatile u32                  efai      : 5;
  volatile u32                  RESERVED0 : 27;
  
} ee_mttcan_c_txefa;

/* Register Set */

typedef struct ee_mttcan_common
{
  struct ee_mttcan_c_crel         crel;           /* Core release register */
  volatile u32                  endn;           /* Endian register */
  volatile u32                  cust;           /* Customer register */
  struct ee_mttcan_c_dbtp         dbtp;           /* Fast bit timing & Prescaler register */
  struct ee_mttcan_c_test         test;           /* Test register */
  struct ee_mttcan_c_rwd          rwd;            /* RAM watchdog */
  struct ee_mttcan_c_cccr         cccr;           /* CC Control register */
  struct ee_mttcan_c_nbtp         nbtp;           /* Bit timing & Prescaler register */
  struct ee_mttcan_c_tscc         tscc;           /* Timestamp Counter configuration */
  struct ee_mttcan_c_tscv         tscv;           /* Timestamp Counter Value */
  struct ee_mttcan_c_tocc         tocc;           /* Timeout Counter Configuration */
  struct ee_mttcan_c_tocv         tocv;           /* Timeout Counter Value */
  volatile u32                  RESERVED1[ 4 ];
  struct ee_mttcan_c_ecr          ecr;            /* Error Counter Register */
  struct ee_mttcan_c_psr          psr;            /* Protocol Status Register */
  struct ee_mttcan_c_tdcr         tdcr;						/* Transmitter Delay Compensation Register */
  volatile u32                  RESERVED2[ 1 ];
  volatile u32                  ir;             /* Interrupt Register */
  volatile u32                  ie;             /* Interrupt Enable */
  volatile u32                  ils;            /* Interrupt Line Select */
  struct ee_mttcan_c_ile          ile;            /* Interrupt Line Enable */
  volatile u32                  RESERVED3[ 8 ];
  struct ee_mttcan_c_gfc          gfc;            /* Global Filter Configuration */
  struct ee_mttcan_c_sidfc        sidfc;          /* Standard ID Filter Configuration */
  struct ee_mttcan_c_xidfc        xidfc;          /* Extended ID Filter Configuration */
  volatile u32                  RESERVED4[ 1 ];
  struct ee_mttcan_c_xidam        xidam;          /* Extended ID AND Mask */
  struct ee_mttcan_c_hpms         hpms;           /* High Priority Message Status */
  volatile u32                  ndat1;          /* New Data 1 */
  volatile u32                  ndat2;          /* New Data 2 */
  struct ee_mttcan_c_rxfc         rxf0c;          /* RX FIFO 0 Configuration */
  struct ee_mttcan_c_rxfs         rxf0s;          /* RX FIFO 0 Status */
  struct ee_mttcan_c_rxfa         rxf0a;          /* RX FIFO 0 Acknowledge */
  struct ee_mttcan_c_rxbc         rxbc;           /* RX Buffer Configuration */
  struct ee_mttcan_c_rxfc         rxf1c;          /* RX FIFO 1 Configuration */
  struct ee_mttcan_c_rxfs         rxf1s;          /* RX FIFO 1 Status */
  struct ee_mttcan_c_rxfa         rxf1a;          /* RX FIFO 1 Acknowledge */
  struct ee_mttcan_c_rxesc        rxesc;          /* RX Buffer / FIFO Element Size Configuration */
  struct ee_mttcan_c_txbc         txbc;           /* TX Buffer Configuration */
  struct ee_mttcan_c_txfqs        txfqs;          /* TX FIFO / Queue Status */
  struct ee_mttcan_c_txesc        txesc;          /* TX Buffer Element Size Configuration */
  volatile u32                  txbrp;          /* TX Buffer Request Pending */
  volatile u32                  txbar;          /* TX Buffer Add Request */
  volatile u32                  txbcr;          /* TX Buffer Cancellation Request */
  volatile u32                  txbto;          /* TX Buffer Transmission Occurred */
  volatile u32                  txbcf;          /* TX Buffer Cancellation Finished */
  volatile u32                  txbtie;         /* TX Buffer Transmission Interrupt Enable */
  volatile u32                  txbcie;         /* TX Buffer Cancellation Finished Interrupt Enable */
  volatile u32                  RESERVED5[ 2 ];
  struct ee_mttcan_c_txefc        txefc;          /* TX Event FIFO Configuration */
  struct ee_mttcan_c_txefs        txefs;          /* TX Event FIFO Status */
  struct ee_mttcan_c_txefa        txefa;          /* TX Event FIFO Acknowledge */
  volatile u32                  RESERVED6[ 1 ];
  
} ee_mttcan_common;

/* TX Event List */

typedef struct ee_mttcan_thl_e1
{
  volatile u32                  txts      : 16;
  volatile u32                  dlc       : 4;
  volatile u32                  brs       : 1;
  volatile u32                  edl       : 1;
  volatile u32                  et        : 2;
  volatile u32                  mm        : 8;
  
} ee_mttcan_thl_e1;

typedef struct ee_mttcan_thl_e0
{
  volatile u32                  id        : 29;
  volatile u32                  rtr       : 1;
  volatile u32                  xtd       : 1;
  volatile u32                  esi       : 1;
  
} ee_mttcan_thl_e0;

typedef struct ee_mttcan_thl
{
  struct ee_mttcan_thl_e0         e0;
  struct ee_mttcan_thl_e1         e1;
  
} ee_mttcan_thl;

/* Buffer and FIFO Elements */

typedef struct ee_mttcan_rx_r0
{
  volatile u32                  id        : 29;
  volatile u32                  rtr       : 1;
  volatile u32                  xtd       : 1;
  volatile u32                  esi       : 1;
  
} ee_mttcan_rx_r0;

typedef struct ee_mttcan_rx_r1
{
  volatile u32                  rxts      : 16;
  volatile u16                  dlc       : 4;
  volatile u32                  brs       : 1;
  volatile u32                  fdf       : 1;
  volatile u32                  RESERVED0 : 2;
  volatile u32                  fidx      : 7;
  volatile u32                  anmf      : 1;
  
} ee_mttcan_rx_r1;

typedef struct ee_mttcan_tx_t0
{
  volatile u32                  id        : 29;
  volatile u32                  rtr       : 1;
  volatile u32                  xtd       : 1;
  volatile u32                  esi       : 1;
  
} ee_mttcan_tx_t0;

typedef struct ee_mttcan_tx_t1
{
  volatile u32                  RESERVED0 : 16;
  volatile u32                  dlc       : 4;
  volatile u32                  brs       : 1;
  volatile u32                  fdf       : 1;
  volatile u32                  RESERVED1 : 1;
  volatile u32                  efc       : 1;
  volatile u32                  mm        : 8;
  
} ee_mttcan_tx_t1;

typedef union ee_mttcan_data
{
  volatile u32                  lw[ MTTCAN_DLC_FDMAX/4 ];
  volatile u16                  sw[ MTTCAN_DLC_FDMAX/2 ];
  volatile u08                  b [ MTTCAN_DLC_FDMAX ];
  
} ee_mttcan_data;

typedef struct ee_mttcan_rx
{
  struct ee_mttcan_rx_r0          r0;
  struct ee_mttcan_rx_r1          r1;
  union  ee_mttcan_data           d;
  
  u08                           path;
  u08                           pathdetail;

} ee_mttcan_rx;

typedef struct{
	u32 id;
	u16 format;
	u16 type;
	u16 len;
	u16 data8[8];
}CAN_MSG;




typedef struct ee_mttcan_tx
{
  struct ee_mttcan_tx_t0          t0;
  struct ee_mttcan_tx_t1          t1;
  union  ee_mttcan_data           d;

  u08                           path;
  u08                           pathdetail;
  u08                           irq_enable;
  
} ee_mttcan_tx;

/* Filter List Element */

typedef struct ee_mttcan_filter_std
{
  volatile u32                  sfid2     : 11;
  volatile u32                  RESERVED0 : 5;
  volatile u32                  sfid1     : 11;
  volatile u32                  sfec      : 3;
  volatile u32                  sft       : 2;
  
} ee_mttcan_filter_std;

typedef struct ee_mttcan_filter_f0
{
  volatile u32                  efid1     : 29;
  volatile u32                  efec      : 3;
  
} ee_mttcan_filter_f0;

typedef struct ee_mttcan_filter_f1
{
  volatile u32                  efid2     : 29;
  volatile u32                  RESERVED0 : 1;
  volatile u32                  eft       : 2;
  
} ee_mttcan_filter_f1;

typedef struct ee_mttcan_filter_ext
{
  struct ee_mttcan_filter_f0      f0;
  struct ee_mttcan_filter_f1      f1;
  
} ee_mttcan_filter_ext;

/* Configuration Settings */

typedef struct ee_mttcan_ramconfig
{
  u16 mttcan_a_stdfilters_count;                  /* amount of standard ID filters */
  u16 mttcan_a_extfilters_count;                  /* amount of extended ID filters */
  u16 mttcan_a_fifo0_size;                        /* size of RX FIFO 0 */
  u16 mttcan_a_fifo1_size;                        /* size of RX FIFO 1 */
  u16 mttcan_a_rxbuffers_count;                   /* amount of classical RX Buffers */
  u16 mttcan_a_txbuffers_count;                   /* amount of classical TX Buffers */
  u16 mttcan_a_txqueue_size;                      /* amount of queued TX Buffers */
  u16 mttcan_a_thl_size;                          /* size of TX Event FIFO */
  
} ee_mttcan_ramconfig;

typedef struct ee_mttcan_config
{
  u32 arb_bitrate;                              /* if set to 0, register set "btp" is used */
  flt arb_samplingpointpos;                     /* optional Parameter, can be 0.0 */
  u32 data_bitrate;                             /* if set to 0, register set "fbtp" is used */
  flt data_samplingpointpos;                    /* optional Parameter, can be 0.0 */

  struct ee_mttcan_c_nbtp         nbtp;           /* Bit timing & Prescaler register */
  struct ee_mttcan_c_dbtp         dbtp;           /* Fast bit timing & Prescaler register */
  struct ee_mttcan_c_cccr         cccr;           /* CC Control register (PXHD, TXP, NISO, EFBI) */

  struct ee_mttcan_c_tscc         tscc;           /* Timestamp Counter configuration */
  struct ee_mttcan_c_tdcr         tdcr;						/* Transmitter Delay Compensation Register */

  struct ee_mttcan_c_gfc          gfc;            /* Global Filter Configuration */
  struct ee_mttcan_c_xidam        xidam;          /* Extended ID AND Mask */

  struct ee_mttcan_c_rxfc         rxf0c;          /* RX FIFO 0 Configuration (apart from RAM) */
  struct ee_mttcan_c_rxfc         rxf1c;          /* RX FIFO 1 Configuration (apart from RAM) */
  struct ee_mttcan_c_txbc         txbc;           /* TX Buffer Configuration (apart from RAM) */
  struct ee_mttcan_c_txefc        txefc;          /* TX Event FIFO Configuration (apart from RAM) */

  struct ee_mttcan_ramconfig      ram;            /* RAM Configuration, see above */

  struct ee_mttcan_c_rxesc        rxesc;          /* RX Buffer / FIFO Element Size Configuration */
  struct ee_mttcan_c_txesc        txesc;          /* TX Buffer Element Size Configuration */
  
} ee_mttcan_config;

//hyxx
typedef struct
{
    Uint16 AttriNum;//????
    Uint16 NodeID;//??ID
    Uint16 NodeStatus;//????
    Uint16 ErrorReg;//?????

    Uint16 DevType;//????
    Uint16 DevNum;//????

}Object_0x00A0_t;

typedef struct
{
    Uint16 poleNum;//????
    Uint16 ratedVol;//????
    Uint16 ratedCur;//????
    Uint16 ratedSpd;//????
}Object_0x00B0_t;

typedef struct
{
    Uint16 cur_Kp;//???kp
    Uint16 cur_Ki;//???ki
    Uint16 spd_Kp;//???kp
    Uint16 spd_Ki;//???ki
    Uint16 fluxWk_Kp;//???kp
    Uint16 fluxWk_Ki;//???ki
}Object_0x00C0_t;

typedef struct
{
    Uint16 overVol_set;//??????
    Uint16 overCul_set;//??????
    Uint16 overSpd_set;//??????
}Object_0x00D0_t;

typedef struct
{
    Object_0x00A0_t m_Obj_0x00A0;
    Object_0x00B0_t m_Obj_0x00B0;
    Object_0x00C0_t m_Obj_0x00C0;
    Object_0x00D0_t m_Obj_0x00D0;
}Object_t;

typedef struct//CAN????
{
    Uint16 statusSym;//???
    Uint16 runState;//????
    Uint16 runTime;//????
    Uint16 dRef;//d???
    Uint16 qRef;//q???
    Uint32 spdRef;//????

    float dRef_float;//d???
    float qRef_float;//q???
    float spdRef_float;//????


    float  CyclesNum;//???
    Uint16 onlineFlag;//????
    Uint32 offline_timeCount;//????
    Uint16 Error_Code;//???
}CAN_Info;





#define MTTCAN_MACROS 2
#define OSCILLATOR_FREQUENCY  (float) 80.0E6
#define RH850_P1M_C

#endif
