/*****************************************************************************/
/* PROJECT = MTTCAN Type MTTCAN_R321, Driver Hardware Configuration Sets     */
/*****************************************************************************/
/*                                  COPYRIGHT                                */
/*===========================================================================*/
/* Copyright (c) 2015 by Renesas Electronics Europe GmbH,                    */
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

#include <stddef.h>
#include <ree_types.h>

//#define  DRIVER_LOCAL

#include <map_mttcan.h>

/* Default Configuration Macros */

#define MTTCAN_A_BTD_AUTO { 0, 0, 0, 0, \
                          0, 0, \
                          0, \
                          0 }                         /* Automatic bit timing */
#define MTTCAN_A_BTA_AUTO { 0, 0, 0, 0, 0  }

#define MTTCAN_A_OPMFLAGS_DEFAULT { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, \
                                  0,     /* PXHD: Protocol Exception enabled */\
                                  0,        /* EFBI: Edge Filtering disabled */\
                                  0,         /* TXP: Transmit Pause disabled */\
                                  0,      /* NISO: ISO 11989-1:2015 selected */\
                                  0 }

#define MTTCAN_A_TS_OFF   { MTTCAN_TSS_OFF, 0, 0, 0 }            /* Timestamp off */
#define MTTCAN_A_TS_SLOW  { MTTCAN_TSS_INTERNAL, 0, 15, 0 }  /* Slowest Timestamp */

                                              /* Closed Global Filter Setting */
#define MTTCAN_A_FILTER_GLOBALREJECT { MTTCAN_GFC_REMOTEREJECT, \
                                     MTTCAN_GFC_REMOTEREJECT, \
                                     MTTCAN_GFC_NOMATCHREJECT, \
                                     MTTCAN_GFC_NOMATCHREJECT, 0 }

                       /* Open Global Filter for all kinds of Standard Frames */
#define MTTCAN_A_FILTER_GLOBALSTANDARD { MTTCAN_GFC_REMOTEREJECT, \
                                       MTTCAN_GFC_REMOTEACCEPT, \
                                       MTTCAN_GFC_NOMATCHREJECT, \
                                       MTTCAN_GFC_NOMATCHFIFO0, 0 }

/* RAM Objects: Size and Addresses are set zero here - these are configured
 * by the separate structure ee_mttcan_ramconfig inside of the configuration */

                                                  /* RX FIFO default Settings */
#define MTTCAN_A_RXFIFO_DEFAULT { 0, 0, 0, 0, \
                                MTTCAN_WATERMARK_OFF, \
                                MTTCAN_FIFO_MODE_BLOCKING }

                                                /* TX Buffer default Settings */
#define MTTCAN_A_TXBUFFER_DEFAULT { 0, 0, 0, 0, 0, \
                                  MTTCAN_TXB_FIFOMODE, 0 } 

                                                  /* TX Buffers with TX Queue */
#define MTTCAN_A_TXBUFFER_QUEUED  { 0, 0, 0, 0, 0, \
                                  MTTCAN_TXB_QUEUEMODE, 0 } 

                                                      /* THL default settings */
#define MTTCAN_A_THL_DEFAULT { 0, 0, 0, 0, \
                             MTTCAN_WATERMARK_OFF, 0 }

/* Example Configuration 1: 
 *
 * 100 kbit/s classical CAN, TX by Buffer and RX by RX FIFO
 * One Filter for receiving all Standard-IDs,
 * One RX FIFO,
 * One TX Buffer, No TX Queue
 *
 * One Reception rule, which accepts all standard-ID messages
 */

const struct ee_mttcan_config MTTCAN_A_CFG_EXAMPLE_1 = 
{
  500000,  0.75,                 /* arbitration bitrate 100 kbit/s, default BT */
  2000000,  0.75,              /* (unused) data bitrate  100 kbit/s, default BT */
  
  MTTCAN_A_BTA_AUTO,                    /* automatic bit timing setup by driver */
  MTTCAN_A_BTD_AUTO,
  MTTCAN_A_OPMFLAGS_DEFAULT,              /* default operation mode (ISO) flags */
  MTTCAN_A_TS_SLOW,                                   /* Timestamps are disabled */

  {
    0, 0,              /* Transmitter Delay Compensation Filter Window Length */
    0, 0,                            /* Transmitter Delay Compensation Offset */
  },
  MTTCAN_A_FILTER_GLOBALREJECT,       /* No Remote Frames, No Global Acceptance */
  
  { MTTCAN_EID_MASK_INACTIVE, 0 },            /* No SAE J1939 Exteneded ID Mask */
  
  MTTCAN_A_RXFIFO_DEFAULT,                /* RX FIFO0 is using default settings */
  MTTCAN_A_RXFIFO_DEFAULT,                              /* RX FIFO1 is not used */
  MTTCAN_A_TXBUFFER_DEFAULT,           /* TX Buffers used in classical way only */
  MTTCAN_A_THL_DEFAULT,                         /* THL (Event FIFO) is not used */
  
  {                                                  /* RAM Layout definition */
    1,                           /* EIGHT Filter for receiving all Standard-IDs */
    0,                                               /* No Extended ID Filter */
    64, 0,                     /* RX-FIFO0 has 2 objects, RX FIFO1 is not used */
    0,                                                   /* No RX Message Box */
    1,                                                  /* One TX Message Box */
    0,                                                  /* No TX Queue / FIFO */
    0                                               /* No THL / Event Buffers */
  },
  {                                                 /* Object Size definition */
    MTTCAN_BUFDL_64, 0,                       /* Default object size for RXFIFO0 */
    MTTCAN_BUFDL_64, 0,                       /* Default object size for RXFIFO1 */
    MTTCAN_BUFDL_64, 0                          /* Object size <=8 for RX Buffer */
  },
  {
    MTTCAN_BUFDL_64, 0                         /* Object size <=8 for TX Buffer  */
  }
};

const struct ee_mttcan_filter_std MTTCAN_A_FILTER_EXAMPLE_1 =
{
  0x000, 0,             /* fully open mask, accepts all IDs */
  0x001,                 /* the ID is not relevant here, because mask is open */
  MTTCAN_FILTER_STORE_FIFO0,                              /* store in RX FIFO 0 */
  MTTCAN_FILTERTYPE_CLASSIC               /* use ID and mask to set this filter */
};


const struct ee_mttcan_filter_std MTTCAN_A_FILTER_EXAMPLE_test0 =
{
  0x1FF, 0,             /* mask: 11 bits of ID are the target bus */
  0x221,                 /* the ID is relevant here,0x11 */
  MTTCAN_FILTER_STORE_FIFO0,                              /* store in RX FIFO 0 */
  MTTCAN_FILTERTYPE_CLASSIC               /* use ID and mask to set this filter */
};

const struct ee_mttcan_filter_std MTTCAN_A_FILTER_EXAMPLE_test1 =
{
  0x1FF, 0,             /*  mask: 11 bits of ID are the target bus */
  0x2A1,                 /* the ID is relevant here,0x15 */
  MTTCAN_FILTER_STORE_FIFO0,                              /* store in RX FIFO 0 */
  MTTCAN_FILTERTYPE_CLASSIC               /* use ID and mask to set this filter */
};

const struct ee_mttcan_filter_std MTTCAN_A_FILTER_EXAMPLE_test2 =
{
  0x1FF, 0,             /*  mask: 11 bits of ID are the target bus */
  0x301,                 /* the ID is relevant here,0x18 */
  MTTCAN_FILTER_STORE_FIFO0,                              /* store in RX FIFO 0 */
  MTTCAN_FILTERTYPE_CLASSIC               /* use ID and mask to set this filter */
};

const struct ee_mttcan_filter_std MTTCAN_A_FILTER_EXAMPLE_test3 =
{
  0x1FF, 0,             /*  mask: 11 bits of ID are the target bus */
  0x321,                 /* the ID is relevant here,0x19 */
  MTTCAN_FILTER_STORE_FIFO0,                              /* store in RX FIFO 0 */
  MTTCAN_FILTERTYPE_CLASSIC               /* use ID and mask to set this filter */
};

const struct ee_mttcan_filter_std MTTCAN_A_FILTER_EXAMPLE_test4 =
{
  0x1FF, 0,             /*  mask: 11 bits of ID are the target bus */
  0x341,                 /* the ID is relevant here,0x1A */
  MTTCAN_FILTER_STORE_FIFO0,                              /* store in RX FIFO 0 */
  MTTCAN_FILTERTYPE_CLASSIC               /* use ID and mask to set this filter */
};

const struct ee_mttcan_filter_std MTTCAN_A_FILTER_EXAMPLE_test5 =
{
  0x1FF, 0,             /*  mask: 11 bits of ID are the target bus */
  0x381,                 /* the ID is relevant here,0x1C */
  MTTCAN_FILTER_STORE_FIFO0,                              /* store in RX FIFO 0 */
  MTTCAN_FILTERTYPE_CLASSIC               /* use ID and mask to set this filter */
};

const struct ee_mttcan_filter_std MTTCAN_A_FILTER_EXAMPLE_test6 =
{
  0x1FF, 0,             /*  mask: 11 bits of ID are the target bus */
  0x3A1,                 /* the ID is relevant here ,0x1D*/
  MTTCAN_FILTER_STORE_FIFO0,                              /* store in RX FIFO 0 */
  MTTCAN_FILTERTYPE_CLASSIC               /* use ID and mask to set this filter */
};

const struct ee_mttcan_filter_std MTTCAN_A_FILTER_EXAMPLE_test7 =
{
  0x1FF, 0,             /*  mask: 11 bits of ID are the target bus */
  0x3C1,                 /* the ID is relevant here,0x1E */
  MTTCAN_FILTER_STORE_FIFO0,                              /* store in RX FIFO 0 */
  MTTCAN_FILTERTYPE_CLASSIC               /* use ID and mask to set this filter */
};
/* Example Configuration 2: 
 *
 * 1 Mbit/s classical CAN, TX by Queue and RX by RX FIFO and RX Buffer
 * FullCAN Filter for receiving Extended-ID 0x0000000 in RX Buffer,
 * Negative Filter for rejecting Standard-ID with routing destination
 * mapped into lowest 4 bits of ID, matching own channel (bus) number
 * BasicCAN Global Operation for receiving all Standard-ID with routing destination 
 * mapped into lowest 4 bits of ID
 * One RX FIFO,
 * One TX Buffer, One TX Queue
 *
 * 2 Reception rules, one for each filter mentioned above, except global BasicCAN
 * The BasicCAN is performed by the global reception setting
 */

const struct ee_mttcan_config MTTCAN_A_CFG_EXAMPLE_2 = 
{
  1000000,  0.0,                  /* arbitration bitrate 1 Mbit/s, default BT */
  1000000,  0.0,               /* (unused) data bitrate  1 Mbit/s, default BT */
  
  MTTCAN_A_BTA_AUTO,                    /* automatic bit timing setup by driver */
  MTTCAN_A_BTD_AUTO,
  MTTCAN_A_OPMFLAGS_DEFAULT,              /* default operation mode (ISO) flags */
  MTTCAN_A_TS_SLOW,                           /* Slow Timestamps for monitoring */

  {
    0, 0,              /* Transmitter Delay Compensation Filter Window Length */
    0, 0,                            /* Transmitter Delay Compensation Offset */
  },
  MTTCAN_A_FILTER_GLOBALSTANDARD,      /* Global Acceptance of all Standard IDs */
  
  { MTTCAN_EID_MASK_INACTIVE, 0 },            /* No SAE J1939 Exteneded ID Mask */
  
  MTTCAN_A_RXFIFO_DEFAULT,                /* RX FIFO0 is using default settings */
  MTTCAN_A_RXFIFO_DEFAULT,                              /* RX FIFO1 is not used */
  MTTCAN_A_TXBUFFER_QUEUED,                       /* TX Buffers used in a queue */
  MTTCAN_A_THL_DEFAULT,              /* THL (Event FIFO) used in default config */
  
  {                                                  /* RAM Layout definition */
    1,          /* One Filter for rejecting Standard-IDs which are not routed */
    1,                             /* One Extended ID Filter for ID 0x0000000 */
    64, 0,                   /* RX-FIFO0 has 64 objects, RX FIFO1 is not used */
    1,                                                  /* One RX Message Box */
    32,                                /* 32 TX Message Boxes used in a queue */
    32,                                                /* TX Queue size is 32 */
    32                                              /* 32 THL / Event Buffers */
  },
  {                                                 /* Object Size definition */
    MTTCAN_BUFDL_8, 0,                       /* Default object size for RXFIFO0 */
    MTTCAN_BUFDL_8, 0,                       /* Default object size for RXFIFO1 */
    MTTCAN_BUFDL_8, 0                          /* Object size <=8 for RX Buffer */
  },
  {
    MTTCAN_BUFDL_8, 0                         /* Object size <=8 for TX Buffer  */
  }
};

struct ee_mttcan_filter_std MTTCAN_A_FILTER_STD_EXAMPLE_2 =
{
  0x00F, 0,                  /* mask: lowest 4 bits of ID are the target bus, */
  0x000,               /* so the local bus number must be set here at runtime */         
  MTTCAN_FILTER_REJECT,                            /* reject all these messages */
  MTTCAN_FILTERTYPE_CLASSIC               /* use ID and mask to set this filter */
};

//const struct ee_mttcan_filter_ext MTTCAN_A_FILTER_EXT_EXAMPLE_2 =
//{
  //{
   // 0x00000000,                  /* extended ID 0x0000000 received in FullCAN */
   // MTTCAN_FILTER_STORE_BUFFER                 /* into a RX Buffer (no masking) */
  //},
  //{
   // MTTCAN_FILTER_BUFFER_STORE, 0,                    /* to be stored in buffer */
   // MTTCAN_FILTERTYPE_IGNORED               /* filter type is not relevant here */
 // }
//};
