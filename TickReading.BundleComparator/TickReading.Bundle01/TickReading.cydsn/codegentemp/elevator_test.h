/*******************************************************************************
* File Name: elevator_test.h  
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

#if !defined(CY_PINS_elevator_test_H) /* Pins elevator_test_H */
#define CY_PINS_elevator_test_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "elevator_test_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    elevator_test_Write(uint8 value) ;
void    elevator_test_SetDriveMode(uint8 mode) ;
uint8   elevator_test_ReadDataReg(void) ;
uint8   elevator_test_Read(void) ;
uint8   elevator_test_ClearInterrupt(void) ;

/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define elevator_test_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define elevator_test_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define elevator_test_DM_RES_UP          PIN_DM_RES_UP
#define elevator_test_DM_RES_DWN         PIN_DM_RES_DWN
#define elevator_test_DM_OD_LO           PIN_DM_OD_LO
#define elevator_test_DM_OD_HI           PIN_DM_OD_HI
#define elevator_test_DM_STRONG          PIN_DM_STRONG
#define elevator_test_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define elevator_test_MASK               elevator_test__MASK
#define elevator_test_SHIFT              elevator_test__SHIFT
#define elevator_test_WIDTH              1u

/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define elevator_test_PS                     (* (reg8 *) elevator_test__PS)
/* Data Register */
#define elevator_test_DR                     (* (reg8 *) elevator_test__DR)
/* Port Number */
#define elevator_test_PRT_NUM                (* (reg8 *) elevator_test__PRT) 
/* Connect to Analog Globals */                                                  
#define elevator_test_AG                     (* (reg8 *) elevator_test__AG)                       
/* Analog MUX bux enable */
#define elevator_test_AMUX                   (* (reg8 *) elevator_test__AMUX) 
/* Bidirectional Enable */                                                        
#define elevator_test_BIE                    (* (reg8 *) elevator_test__BIE)
/* Bit-mask for Aliased Register Access */
#define elevator_test_BIT_MASK               (* (reg8 *) elevator_test__BIT_MASK)
/* Bypass Enable */
#define elevator_test_BYP                    (* (reg8 *) elevator_test__BYP)
/* Port wide control signals */                                                   
#define elevator_test_CTL                    (* (reg8 *) elevator_test__CTL)
/* Drive Modes */
#define elevator_test_DM0                    (* (reg8 *) elevator_test__DM0) 
#define elevator_test_DM1                    (* (reg8 *) elevator_test__DM1)
#define elevator_test_DM2                    (* (reg8 *) elevator_test__DM2) 
/* Input Buffer Disable Override */
#define elevator_test_INP_DIS                (* (reg8 *) elevator_test__INP_DIS)
/* LCD Common or Segment Drive */
#define elevator_test_LCD_COM_SEG            (* (reg8 *) elevator_test__LCD_COM_SEG)
/* Enable Segment LCD */
#define elevator_test_LCD_EN                 (* (reg8 *) elevator_test__LCD_EN)
/* Slew Rate Control */
#define elevator_test_SLW                    (* (reg8 *) elevator_test__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define elevator_test_PRTDSI__CAPS_SEL       (* (reg8 *) elevator_test__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define elevator_test_PRTDSI__DBL_SYNC_IN    (* (reg8 *) elevator_test__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define elevator_test_PRTDSI__OE_SEL0        (* (reg8 *) elevator_test__PRTDSI__OE_SEL0) 
#define elevator_test_PRTDSI__OE_SEL1        (* (reg8 *) elevator_test__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define elevator_test_PRTDSI__OUT_SEL0       (* (reg8 *) elevator_test__PRTDSI__OUT_SEL0) 
#define elevator_test_PRTDSI__OUT_SEL1       (* (reg8 *) elevator_test__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define elevator_test_PRTDSI__SYNC_OUT       (* (reg8 *) elevator_test__PRTDSI__SYNC_OUT) 


#if defined(elevator_test__INTSTAT)  /* Interrupt Registers */

    #define elevator_test_INTSTAT                (* (reg8 *) elevator_test__INTSTAT)
    #define elevator_test_SNAP                   (* (reg8 *) elevator_test__SNAP)

#endif /* Interrupt Registers */

#endif /* End Pins elevator_test_H */


/* [] END OF FILE */
