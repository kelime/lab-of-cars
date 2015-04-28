/*******************************************************************************
* File Name: PWM_Output.h  
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

#if !defined(CY_PINS_PWM_Output_H) /* Pins PWM_Output_H */
#define CY_PINS_PWM_Output_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "PWM_Output_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    PWM_Output_Write(uint8 value) ;
void    PWM_Output_SetDriveMode(uint8 mode) ;
uint8   PWM_Output_ReadDataReg(void) ;
uint8   PWM_Output_Read(void) ;
uint8   PWM_Output_ClearInterrupt(void) ;

/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define PWM_Output_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define PWM_Output_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define PWM_Output_DM_RES_UP          PIN_DM_RES_UP
#define PWM_Output_DM_RES_DWN         PIN_DM_RES_DWN
#define PWM_Output_DM_OD_LO           PIN_DM_OD_LO
#define PWM_Output_DM_OD_HI           PIN_DM_OD_HI
#define PWM_Output_DM_STRONG          PIN_DM_STRONG
#define PWM_Output_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define PWM_Output_MASK               PWM_Output__MASK
#define PWM_Output_SHIFT              PWM_Output__SHIFT
#define PWM_Output_WIDTH              1u

/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define PWM_Output_PS                     (* (reg8 *) PWM_Output__PS)
/* Data Register */
#define PWM_Output_DR                     (* (reg8 *) PWM_Output__DR)
/* Port Number */
#define PWM_Output_PRT_NUM                (* (reg8 *) PWM_Output__PRT) 
/* Connect to Analog Globals */                                                  
#define PWM_Output_AG                     (* (reg8 *) PWM_Output__AG)                       
/* Analog MUX bux enable */
#define PWM_Output_AMUX                   (* (reg8 *) PWM_Output__AMUX) 
/* Bidirectional Enable */                                                        
#define PWM_Output_BIE                    (* (reg8 *) PWM_Output__BIE)
/* Bit-mask for Aliased Register Access */
#define PWM_Output_BIT_MASK               (* (reg8 *) PWM_Output__BIT_MASK)
/* Bypass Enable */
#define PWM_Output_BYP                    (* (reg8 *) PWM_Output__BYP)
/* Port wide control signals */                                                   
#define PWM_Output_CTL                    (* (reg8 *) PWM_Output__CTL)
/* Drive Modes */
#define PWM_Output_DM0                    (* (reg8 *) PWM_Output__DM0) 
#define PWM_Output_DM1                    (* (reg8 *) PWM_Output__DM1)
#define PWM_Output_DM2                    (* (reg8 *) PWM_Output__DM2) 
/* Input Buffer Disable Override */
#define PWM_Output_INP_DIS                (* (reg8 *) PWM_Output__INP_DIS)
/* LCD Common or Segment Drive */
#define PWM_Output_LCD_COM_SEG            (* (reg8 *) PWM_Output__LCD_COM_SEG)
/* Enable Segment LCD */
#define PWM_Output_LCD_EN                 (* (reg8 *) PWM_Output__LCD_EN)
/* Slew Rate Control */
#define PWM_Output_SLW                    (* (reg8 *) PWM_Output__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define PWM_Output_PRTDSI__CAPS_SEL       (* (reg8 *) PWM_Output__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define PWM_Output_PRTDSI__DBL_SYNC_IN    (* (reg8 *) PWM_Output__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define PWM_Output_PRTDSI__OE_SEL0        (* (reg8 *) PWM_Output__PRTDSI__OE_SEL0) 
#define PWM_Output_PRTDSI__OE_SEL1        (* (reg8 *) PWM_Output__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define PWM_Output_PRTDSI__OUT_SEL0       (* (reg8 *) PWM_Output__PRTDSI__OUT_SEL0) 
#define PWM_Output_PRTDSI__OUT_SEL1       (* (reg8 *) PWM_Output__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define PWM_Output_PRTDSI__SYNC_OUT       (* (reg8 *) PWM_Output__PRTDSI__SYNC_OUT) 


#if defined(PWM_Output__INTSTAT)  /* Interrupt Registers */

    #define PWM_Output_INTSTAT                (* (reg8 *) PWM_Output__INTSTAT)
    #define PWM_Output_SNAP                   (* (reg8 *) PWM_Output__SNAP)

#endif /* Interrupt Registers */

#endif /* End Pins PWM_Output_H */


/* [] END OF FILE */
