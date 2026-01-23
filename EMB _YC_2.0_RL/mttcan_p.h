/*****************************************************************************/
/* PROJECT = MTTCAN Type MTTCAN_R321, Lower level driver API Include         */
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

#ifndef _MTTCAN_P_H
#define _MTTCAN_P_H

#include <ree_types.h>

extern bit MTTCAN_PortEnable( u08 UnitNumber_u08 );
extern bit MTTCAN_PortDisable( u08 UnitNumber_u08 );
extern bit MTTCAN_CreateInterrupt( u08  UnitNumber_u08,
                                 u08  IntLineNumber_u08,
                                 u16  SetIntLevel_u16,
                                 void ( *FunctionVector )( ) );
extern bit MTTCAN_SetInterrupt( u08 UnitNumber_u08,
                              u32 InterruptType_u32,
                              u08 InterruptLineSelection_u08,
                              bit InterruptEnable_bit );
extern bit MTTCAN_GetStatus( u08  UnitNumber_u08,
                 		       u08  StatusNumber_u08,
                 		       pu16 StatusValue_pu16 );
extern bit MTTCAN_Start( u08 UnitNumber_u08,
                       u08 OperationMode_u08,
                       u16 TimeStampSetting_u16,
                       u16 TimeOutSetting_u16 );
extern bit MTTCAN_Stop( u08 UnitNumber_u08,
                      u08 StopMode_u08 );
extern bit MTTCAN_SetConfiguration( u08  UnitNumber_u08,
                                  const struct ee_mttcan_config *Config,
                                  pu08 ErrorStatus_pu08 );
extern bit MTTCAN_SetStdFilterEntry( u08    UnitNumber_u08,
								      			       u16    RuleNumber_u16,
                                   const struct ee_mttcan_filter_std *FilterEntry );
extern bit MTTCAN_SetExtFilterEntry( u08    UnitNumber_u08,
								      			       u16    RuleNumber_u16,
                                   const struct ee_mttcan_filter_ext *FilterEntry );
extern bit MTTCAN_SendMessage( u08                UnitNumber_u08,
                             pu08               Status_pu08,
                             struct ee_mttcan_tx *Message );
extern bit MTTCAN_ReceiveMessage( u08                UnitNumber_u08,
                                pu08               Status_pu08,
                                struct ee_mttcan_rx *Message );
extern bit MTTCAN_TxAbort( u08                UnitNumber_u08,
                         struct ee_mttcan_tx *Message );


#endif
