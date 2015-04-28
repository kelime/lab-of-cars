/*******************************************************************************
* File Name: elevator_input.h  
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

#if !defined(CY_PINS_elevator_input_H) /* Pins elevator_input_H */
#define CY_PINS_elevator_input_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "elevator_input_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    elevator_input_Write(uint8 value) ;
void    elevator_input_SetDriveMode(uint8 mode) ;
uint8   elevator_input_ReadDataReg(void) ;
uint8   elevator_input_Read(void) ;
uint8   elevator_input_ClearInterrupt(void) ;

/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define elevator_input_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define elevator_input_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define elevator_input_DM_RES_UP          PIN_DM_RES_UP
#define elevator_input_DM_RES_DWN         PIN_DM_RES_DWN
#define elevator_input_DM_OD_LO           PIN_DM_OD_LO
#define elevator_input_DM_OD_HI           PIN_DM_OD_HI
#define elevator_input_DM_STRONG          PIN_DM_STRONG
#define elevator_input_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define elevator_input_MASK               elevator_input__MASK
#define elevator_input_SHIFT              elevator_input__SHIFT
#define elevator_input_WIDTH              1u

/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define elevator_input_PS                     (* (reg8 *) elevator_input__PS)
/* Data Register */
#define elevator_input_DR                     (* (reg8 *) elevator_input__DR)
/* Port Number */
#define elevator_input_PRT_NUM                (* (reg8 *) elevator_input__PRT) 
/* Connect to Analog Globals */                                                  
#define elevator_input_AG                     (* (reg8 *) elevator_input__AG)                       
/* Analog MUX bux enable */
#define elevator_input_AMUX                   (* (reg8 *) elevator_input__AMUX) 
/* Bidirectional Enable */                                                        
#define elevator_input_BIE                    (* (reg8 *) elevator_input__BIE)
/* Bit-mask for Aliased Register Access */
#define elevator_input_BIT_MASK               (* (reg8 *) elevator_input__BIT_MASK)
/* Bypass Enable */
#define elevator_input_BYP                    (* (reg8 *) elevator_input__BYP)
/* Port wide control signals */                                                   
#define elevator_input_CTL                    (* (reg8 *) elevator_input__CTL)
/* Drive Modes */
#define elevator_input_DM0                    (* (reg8 *) elevator_input__DM0) 
#define elevator_input_DM1                    (* (reg8 *) elevator_input__DM1)
#define elevator_input_DM2                    (* (reg8 *) elevator_input__DM2) 
/* Input Buffer Disable Override */
#define elevator_input_INP_DIS                (* (reg8 *) elevator_input__INP_DIS)
/* LCD Common or Segment Drive */
#define elevator_input_LCD_COM_SEG            (* (reg8 *) elevator_input__LCD_COM_SEG)
/* Enable Segment LCD */
#define elevator_input_LCD_EN                 (* (reg8 *) elevator_input__LCD_EN)
/* Slew Rate Control */
#define elevator_input_SLW                    (* (reg8 *) elevator_input__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define elevator_input_PRTDSI__CAPS_SEL       (* (reg8 *) elevator_input__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define elevator_input_PRTDSI__DBL_SYNC_IN    (* (reg8 *) elevator_input__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define elevator_input_PRTDSI__OE_SEL0        (* (reg8 *) elevator_input__PRTDSI__OE_SEL0) 
#define elevator_input_PRTDSI__OE_SEL1        (* (reg8 *) elevator_input__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define elevator_input_PRTDSI__OUT_SEL0       (* (reg8 *) elevator_input__PRTDSI__OUT_SEL0) 
#define elevator_input_PRTDSI__OUT_SEL1       (* (reg8 *) elevator_input__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define elevator_input_PRTDSI__SYNC_OUT       (* (reg8 *) elevator_input__PRTDSI__SYNC_OUT) 


#if defined(elevator_input__INTSTAT)  /* Interrupt Registers */

    #define elevator_input_INTSTAT                (* (reg8 *) elevator_input__INTSTAT)
    #define elevator_input_SNAP                   (* (reg8 *) elevator_input__SNAP)

#endif /* Interrupt Registers */

#endif /* End Pins elevator_input_H */


/* [] END OF FILE */
