/*******************************************************************************
* File Name: PWM_LED.h  
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

#if !defined(CY_PINS_PWM_LED_H) /* Pins PWM_LED_H */
#define CY_PINS_PWM_LED_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "PWM_LED_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    PWM_LED_Write(uint8 value) ;
void    PWM_LED_SetDriveMode(uint8 mode) ;
uint8   PWM_LED_ReadDataReg(void) ;
uint8   PWM_LED_Read(void) ;
uint8   PWM_LED_ClearInterrupt(void) ;

/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define PWM_LED_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define PWM_LED_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define PWM_LED_DM_RES_UP          PIN_DM_RES_UP
#define PWM_LED_DM_RES_DWN         PIN_DM_RES_DWN
#define PWM_LED_DM_OD_LO           PIN_DM_OD_LO
#define PWM_LED_DM_OD_HI           PIN_DM_OD_HI
#define PWM_LED_DM_STRONG          PIN_DM_STRONG
#define PWM_LED_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define PWM_LED_MASK               PWM_LED__MASK
#define PWM_LED_SHIFT              PWM_LED__SHIFT
#define PWM_LED_WIDTH              1u

/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define PWM_LED_PS                     (* (reg8 *) PWM_LED__PS)
/* Data Register */
#define PWM_LED_DR                     (* (reg8 *) PWM_LED__DR)
/* Port Number */
#define PWM_LED_PRT_NUM                (* (reg8 *) PWM_LED__PRT) 
/* Connect to Analog Globals */                                                  
#define PWM_LED_AG                     (* (reg8 *) PWM_LED__AG)                       
/* Analog MUX bux enable */
#define PWM_LED_AMUX                   (* (reg8 *) PWM_LED__AMUX) 
/* Bidirectional Enable */                                                        
#define PWM_LED_BIE                    (* (reg8 *) PWM_LED__BIE)
/* Bit-mask for Aliased Register Access */
#define PWM_LED_BIT_MASK               (* (reg8 *) PWM_LED__BIT_MASK)
/* Bypass Enable */
#define PWM_LED_BYP                    (* (reg8 *) PWM_LED__BYP)
/* Port wide control signals */                                                   
#define PWM_LED_CTL                    (* (reg8 *) PWM_LED__CTL)
/* Drive Modes */
#define PWM_LED_DM0                    (* (reg8 *) PWM_LED__DM0) 
#define PWM_LED_DM1                    (* (reg8 *) PWM_LED__DM1)
#define PWM_LED_DM2                    (* (reg8 *) PWM_LED__DM2) 
/* Input Buffer Disable Override */
#define PWM_LED_INP_DIS                (* (reg8 *) PWM_LED__INP_DIS)
/* LCD Common or Segment Drive */
#define PWM_LED_LCD_COM_SEG            (* (reg8 *) PWM_LED__LCD_COM_SEG)
/* Enable Segment LCD */
#define PWM_LED_LCD_EN                 (* (reg8 *) PWM_LED__LCD_EN)
/* Slew Rate Control */
#define PWM_LED_SLW                    (* (reg8 *) PWM_LED__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define PWM_LED_PRTDSI__CAPS_SEL       (* (reg8 *) PWM_LED__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define PWM_LED_PRTDSI__DBL_SYNC_IN    (* (reg8 *) PWM_LED__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define PWM_LED_PRTDSI__OE_SEL0        (* (reg8 *) PWM_LED__PRTDSI__OE_SEL0) 
#define PWM_LED_PRTDSI__OE_SEL1        (* (reg8 *) PWM_LED__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define PWM_LED_PRTDSI__OUT_SEL0       (* (reg8 *) PWM_LED__PRTDSI__OUT_SEL0) 
#define PWM_LED_PRTDSI__OUT_SEL1       (* (reg8 *) PWM_LED__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define PWM_LED_PRTDSI__SYNC_OUT       (* (reg8 *) PWM_LED__PRTDSI__SYNC_OUT) 


#if defined(PWM_LED__INTSTAT)  /* Interrupt Registers */

    #define PWM_LED_INTSTAT                (* (reg8 *) PWM_LED__INTSTAT)
    #define PWM_LED_SNAP                   (* (reg8 *) PWM_LED__SNAP)

#endif /* Interrupt Registers */

#endif /* End Pins PWM_LED_H */


/* [] END OF FILE */
