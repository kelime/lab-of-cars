/*******************************************************************************
* File Name: Input_LED_1.h  
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

#if !defined(CY_PINS_Input_LED_1_H) /* Pins Input_LED_1_H */
#define CY_PINS_Input_LED_1_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "Input_LED_1_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    Input_LED_1_Write(uint8 value) ;
void    Input_LED_1_SetDriveMode(uint8 mode) ;
uint8   Input_LED_1_ReadDataReg(void) ;
uint8   Input_LED_1_Read(void) ;
uint8   Input_LED_1_ClearInterrupt(void) ;

/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define Input_LED_1_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define Input_LED_1_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define Input_LED_1_DM_RES_UP          PIN_DM_RES_UP
#define Input_LED_1_DM_RES_DWN         PIN_DM_RES_DWN
#define Input_LED_1_DM_OD_LO           PIN_DM_OD_LO
#define Input_LED_1_DM_OD_HI           PIN_DM_OD_HI
#define Input_LED_1_DM_STRONG          PIN_DM_STRONG
#define Input_LED_1_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define Input_LED_1_MASK               Input_LED_1__MASK
#define Input_LED_1_SHIFT              Input_LED_1__SHIFT
#define Input_LED_1_WIDTH              1u

/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Input_LED_1_PS                     (* (reg8 *) Input_LED_1__PS)
/* Data Register */
#define Input_LED_1_DR                     (* (reg8 *) Input_LED_1__DR)
/* Port Number */
#define Input_LED_1_PRT_NUM                (* (reg8 *) Input_LED_1__PRT) 
/* Connect to Analog Globals */                                                  
#define Input_LED_1_AG                     (* (reg8 *) Input_LED_1__AG)                       
/* Analog MUX bux enable */
#define Input_LED_1_AMUX                   (* (reg8 *) Input_LED_1__AMUX) 
/* Bidirectional Enable */                                                        
#define Input_LED_1_BIE                    (* (reg8 *) Input_LED_1__BIE)
/* Bit-mask for Aliased Register Access */
#define Input_LED_1_BIT_MASK               (* (reg8 *) Input_LED_1__BIT_MASK)
/* Bypass Enable */
#define Input_LED_1_BYP                    (* (reg8 *) Input_LED_1__BYP)
/* Port wide control signals */                                                   
#define Input_LED_1_CTL                    (* (reg8 *) Input_LED_1__CTL)
/* Drive Modes */
#define Input_LED_1_DM0                    (* (reg8 *) Input_LED_1__DM0) 
#define Input_LED_1_DM1                    (* (reg8 *) Input_LED_1__DM1)
#define Input_LED_1_DM2                    (* (reg8 *) Input_LED_1__DM2) 
/* Input Buffer Disable Override */
#define Input_LED_1_INP_DIS                (* (reg8 *) Input_LED_1__INP_DIS)
/* LCD Common or Segment Drive */
#define Input_LED_1_LCD_COM_SEG            (* (reg8 *) Input_LED_1__LCD_COM_SEG)
/* Enable Segment LCD */
#define Input_LED_1_LCD_EN                 (* (reg8 *) Input_LED_1__LCD_EN)
/* Slew Rate Control */
#define Input_LED_1_SLW                    (* (reg8 *) Input_LED_1__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define Input_LED_1_PRTDSI__CAPS_SEL       (* (reg8 *) Input_LED_1__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define Input_LED_1_PRTDSI__DBL_SYNC_IN    (* (reg8 *) Input_LED_1__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define Input_LED_1_PRTDSI__OE_SEL0        (* (reg8 *) Input_LED_1__PRTDSI__OE_SEL0) 
#define Input_LED_1_PRTDSI__OE_SEL1        (* (reg8 *) Input_LED_1__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define Input_LED_1_PRTDSI__OUT_SEL0       (* (reg8 *) Input_LED_1__PRTDSI__OUT_SEL0) 
#define Input_LED_1_PRTDSI__OUT_SEL1       (* (reg8 *) Input_LED_1__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define Input_LED_1_PRTDSI__SYNC_OUT       (* (reg8 *) Input_LED_1__PRTDSI__SYNC_OUT) 


#if defined(Input_LED_1__INTSTAT)  /* Interrupt Registers */

    #define Input_LED_1_INTSTAT                (* (reg8 *) Input_LED_1__INTSTAT)
    #define Input_LED_1_SNAP                   (* (reg8 *) Input_LED_1__SNAP)

#endif /* Interrupt Registers */

#endif /* End Pins Input_LED_1_H */


/* [] END OF FILE */
