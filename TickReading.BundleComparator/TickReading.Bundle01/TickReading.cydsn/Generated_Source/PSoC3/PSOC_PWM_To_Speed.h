/*******************************************************************************
* File Name: PSOC_PWM_To_Speed.h  
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

#if !defined(CY_PINS_PSOC_PWM_To_Speed_H) /* Pins PSOC_PWM_To_Speed_H */
#define CY_PINS_PSOC_PWM_To_Speed_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "PSOC_PWM_To_Speed_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    PSOC_PWM_To_Speed_Write(uint8 value) ;
void    PSOC_PWM_To_Speed_SetDriveMode(uint8 mode) ;
uint8   PSOC_PWM_To_Speed_ReadDataReg(void) ;
uint8   PSOC_PWM_To_Speed_Read(void) ;
uint8   PSOC_PWM_To_Speed_ClearInterrupt(void) ;

/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define PSOC_PWM_To_Speed_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define PSOC_PWM_To_Speed_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define PSOC_PWM_To_Speed_DM_RES_UP          PIN_DM_RES_UP
#define PSOC_PWM_To_Speed_DM_RES_DWN         PIN_DM_RES_DWN
#define PSOC_PWM_To_Speed_DM_OD_LO           PIN_DM_OD_LO
#define PSOC_PWM_To_Speed_DM_OD_HI           PIN_DM_OD_HI
#define PSOC_PWM_To_Speed_DM_STRONG          PIN_DM_STRONG
#define PSOC_PWM_To_Speed_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define PSOC_PWM_To_Speed_MASK               PSOC_PWM_To_Speed__MASK
#define PSOC_PWM_To_Speed_SHIFT              PSOC_PWM_To_Speed__SHIFT
#define PSOC_PWM_To_Speed_WIDTH              1u

/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define PSOC_PWM_To_Speed_PS                     (* (reg8 *) PSOC_PWM_To_Speed__PS)
/* Data Register */
#define PSOC_PWM_To_Speed_DR                     (* (reg8 *) PSOC_PWM_To_Speed__DR)
/* Port Number */
#define PSOC_PWM_To_Speed_PRT_NUM                (* (reg8 *) PSOC_PWM_To_Speed__PRT) 
/* Connect to Analog Globals */                                                  
#define PSOC_PWM_To_Speed_AG                     (* (reg8 *) PSOC_PWM_To_Speed__AG)                       
/* Analog MUX bux enable */
#define PSOC_PWM_To_Speed_AMUX                   (* (reg8 *) PSOC_PWM_To_Speed__AMUX) 
/* Bidirectional Enable */                                                        
#define PSOC_PWM_To_Speed_BIE                    (* (reg8 *) PSOC_PWM_To_Speed__BIE)
/* Bit-mask for Aliased Register Access */
#define PSOC_PWM_To_Speed_BIT_MASK               (* (reg8 *) PSOC_PWM_To_Speed__BIT_MASK)
/* Bypass Enable */
#define PSOC_PWM_To_Speed_BYP                    (* (reg8 *) PSOC_PWM_To_Speed__BYP)
/* Port wide control signals */                                                   
#define PSOC_PWM_To_Speed_CTL                    (* (reg8 *) PSOC_PWM_To_Speed__CTL)
/* Drive Modes */
#define PSOC_PWM_To_Speed_DM0                    (* (reg8 *) PSOC_PWM_To_Speed__DM0) 
#define PSOC_PWM_To_Speed_DM1                    (* (reg8 *) PSOC_PWM_To_Speed__DM1)
#define PSOC_PWM_To_Speed_DM2                    (* (reg8 *) PSOC_PWM_To_Speed__DM2) 
/* Input Buffer Disable Override */
#define PSOC_PWM_To_Speed_INP_DIS                (* (reg8 *) PSOC_PWM_To_Speed__INP_DIS)
/* LCD Common or Segment Drive */
#define PSOC_PWM_To_Speed_LCD_COM_SEG            (* (reg8 *) PSOC_PWM_To_Speed__LCD_COM_SEG)
/* Enable Segment LCD */
#define PSOC_PWM_To_Speed_LCD_EN                 (* (reg8 *) PSOC_PWM_To_Speed__LCD_EN)
/* Slew Rate Control */
#define PSOC_PWM_To_Speed_SLW                    (* (reg8 *) PSOC_PWM_To_Speed__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define PSOC_PWM_To_Speed_PRTDSI__CAPS_SEL       (* (reg8 *) PSOC_PWM_To_Speed__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define PSOC_PWM_To_Speed_PRTDSI__DBL_SYNC_IN    (* (reg8 *) PSOC_PWM_To_Speed__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define PSOC_PWM_To_Speed_PRTDSI__OE_SEL0        (* (reg8 *) PSOC_PWM_To_Speed__PRTDSI__OE_SEL0) 
#define PSOC_PWM_To_Speed_PRTDSI__OE_SEL1        (* (reg8 *) PSOC_PWM_To_Speed__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define PSOC_PWM_To_Speed_PRTDSI__OUT_SEL0       (* (reg8 *) PSOC_PWM_To_Speed__PRTDSI__OUT_SEL0) 
#define PSOC_PWM_To_Speed_PRTDSI__OUT_SEL1       (* (reg8 *) PSOC_PWM_To_Speed__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define PSOC_PWM_To_Speed_PRTDSI__SYNC_OUT       (* (reg8 *) PSOC_PWM_To_Speed__PRTDSI__SYNC_OUT) 


#if defined(PSOC_PWM_To_Speed__INTSTAT)  /* Interrupt Registers */

    #define PSOC_PWM_To_Speed_INTSTAT                (* (reg8 *) PSOC_PWM_To_Speed__INTSTAT)
    #define PSOC_PWM_To_Speed_SNAP                   (* (reg8 *) PSOC_PWM_To_Speed__SNAP)

#endif /* Interrupt Registers */

#endif /* End Pins PSOC_PWM_To_Speed_H */


/* [] END OF FILE */
