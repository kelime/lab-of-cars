/*******************************************************************************
* File Name: drive_output_1.h  
* Version 1.70
*
* Description:
*  This file containts Control Register function prototypes and register defines
*
* Note:
*
********************************************************************************
* Copyright 2008-2010, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
********************************************************************************/

#if !defined(CY_PINS_drive_output_1_H) /* Pins drive_output_1_H */
#define CY_PINS_drive_output_1_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "drive_output_1_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    drive_output_1_Write(uint8 value) ;
void    drive_output_1_SetDriveMode(uint8 mode) ;
uint8   drive_output_1_ReadDataReg(void) ;
uint8   drive_output_1_Read(void) ;
uint8   drive_output_1_ClearInterrupt(void) ;

/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define drive_output_1_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define drive_output_1_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define drive_output_1_DM_RES_UP          PIN_DM_RES_UP
#define drive_output_1_DM_RES_DWN         PIN_DM_RES_DWN
#define drive_output_1_DM_OD_LO           PIN_DM_OD_LO
#define drive_output_1_DM_OD_HI           PIN_DM_OD_HI
#define drive_output_1_DM_STRONG          PIN_DM_STRONG
#define drive_output_1_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define drive_output_1_MASK               drive_output_1__MASK
#define drive_output_1_SHIFT              drive_output_1__SHIFT
#define drive_output_1_WIDTH              1u

/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define drive_output_1_PS                     (* (reg8 *) drive_output_1__PS)
/* Data Register */
#define drive_output_1_DR                     (* (reg8 *) drive_output_1__DR)
/* Port Number */
#define drive_output_1_PRT_NUM                (* (reg8 *) drive_output_1__PRT) 
/* Connect to Analog Globals */                                                  
#define drive_output_1_AG                     (* (reg8 *) drive_output_1__AG)                       
/* Analog MUX bux enable */
#define drive_output_1_AMUX                   (* (reg8 *) drive_output_1__AMUX) 
/* Bidirectional Enable */                                                        
#define drive_output_1_BIE                    (* (reg8 *) drive_output_1__BIE)
/* Bit-mask for Aliased Register Access */
#define drive_output_1_BIT_MASK               (* (reg8 *) drive_output_1__BIT_MASK)
/* Bypass Enable */
#define drive_output_1_BYP                    (* (reg8 *) drive_output_1__BYP)
/* Port wide control signals */                                                   
#define drive_output_1_CTL                    (* (reg8 *) drive_output_1__CTL)
/* Drive Modes */
#define drive_output_1_DM0                    (* (reg8 *) drive_output_1__DM0) 
#define drive_output_1_DM1                    (* (reg8 *) drive_output_1__DM1)
#define drive_output_1_DM2                    (* (reg8 *) drive_output_1__DM2) 
/* Input Buffer Disable Override */
#define drive_output_1_INP_DIS                (* (reg8 *) drive_output_1__INP_DIS)
/* LCD Common or Segment Drive */
#define drive_output_1_LCD_COM_SEG            (* (reg8 *) drive_output_1__LCD_COM_SEG)
/* Enable Segment LCD */
#define drive_output_1_LCD_EN                 (* (reg8 *) drive_output_1__LCD_EN)
/* Slew Rate Control */
#define drive_output_1_SLW                    (* (reg8 *) drive_output_1__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define drive_output_1_PRTDSI__CAPS_SEL       (* (reg8 *) drive_output_1__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define drive_output_1_PRTDSI__DBL_SYNC_IN    (* (reg8 *) drive_output_1__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define drive_output_1_PRTDSI__OE_SEL0        (* (reg8 *) drive_output_1__PRTDSI__OE_SEL0) 
#define drive_output_1_PRTDSI__OE_SEL1        (* (reg8 *) drive_output_1__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define drive_output_1_PRTDSI__OUT_SEL0       (* (reg8 *) drive_output_1__PRTDSI__OUT_SEL0) 
#define drive_output_1_PRTDSI__OUT_SEL1       (* (reg8 *) drive_output_1__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define drive_output_1_PRTDSI__SYNC_OUT       (* (reg8 *) drive_output_1__PRTDSI__SYNC_OUT) 


#if defined(drive_output_1__INTSTAT)  /* Interrupt Registers */

    #define drive_output_1_INTSTAT                (* (reg8 *) drive_output_1__INTSTAT)
    #define drive_output_1_SNAP                   (* (reg8 *) drive_output_1__SNAP)

#endif /* Interrupt Registers */

#endif /* End Pins drive_output_1_H */


/* [] END OF FILE */
