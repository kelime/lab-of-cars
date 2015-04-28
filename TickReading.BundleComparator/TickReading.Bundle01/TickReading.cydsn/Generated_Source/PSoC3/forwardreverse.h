/*******************************************************************************
* File Name: forwardreverse.h  
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

#if !defined(CY_PINS_forwardreverse_H) /* Pins forwardreverse_H */
#define CY_PINS_forwardreverse_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "forwardreverse_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    forwardreverse_Write(uint8 value) ;
void    forwardreverse_SetDriveMode(uint8 mode) ;
uint8   forwardreverse_ReadDataReg(void) ;
uint8   forwardreverse_Read(void) ;
uint8   forwardreverse_ClearInterrupt(void) ;

/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define forwardreverse_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define forwardreverse_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define forwardreverse_DM_RES_UP          PIN_DM_RES_UP
#define forwardreverse_DM_RES_DWN         PIN_DM_RES_DWN
#define forwardreverse_DM_OD_LO           PIN_DM_OD_LO
#define forwardreverse_DM_OD_HI           PIN_DM_OD_HI
#define forwardreverse_DM_STRONG          PIN_DM_STRONG
#define forwardreverse_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define forwardreverse_MASK               forwardreverse__MASK
#define forwardreverse_SHIFT              forwardreverse__SHIFT
#define forwardreverse_WIDTH              1u

/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define forwardreverse_PS                     (* (reg8 *) forwardreverse__PS)
/* Data Register */
#define forwardreverse_DR                     (* (reg8 *) forwardreverse__DR)
/* Port Number */
#define forwardreverse_PRT_NUM                (* (reg8 *) forwardreverse__PRT) 
/* Connect to Analog Globals */                                                  
#define forwardreverse_AG                     (* (reg8 *) forwardreverse__AG)                       
/* Analog MUX bux enable */
#define forwardreverse_AMUX                   (* (reg8 *) forwardreverse__AMUX) 
/* Bidirectional Enable */                                                        
#define forwardreverse_BIE                    (* (reg8 *) forwardreverse__BIE)
/* Bit-mask for Aliased Register Access */
#define forwardreverse_BIT_MASK               (* (reg8 *) forwardreverse__BIT_MASK)
/* Bypass Enable */
#define forwardreverse_BYP                    (* (reg8 *) forwardreverse__BYP)
/* Port wide control signals */                                                   
#define forwardreverse_CTL                    (* (reg8 *) forwardreverse__CTL)
/* Drive Modes */
#define forwardreverse_DM0                    (* (reg8 *) forwardreverse__DM0) 
#define forwardreverse_DM1                    (* (reg8 *) forwardreverse__DM1)
#define forwardreverse_DM2                    (* (reg8 *) forwardreverse__DM2) 
/* Input Buffer Disable Override */
#define forwardreverse_INP_DIS                (* (reg8 *) forwardreverse__INP_DIS)
/* LCD Common or Segment Drive */
#define forwardreverse_LCD_COM_SEG            (* (reg8 *) forwardreverse__LCD_COM_SEG)
/* Enable Segment LCD */
#define forwardreverse_LCD_EN                 (* (reg8 *) forwardreverse__LCD_EN)
/* Slew Rate Control */
#define forwardreverse_SLW                    (* (reg8 *) forwardreverse__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define forwardreverse_PRTDSI__CAPS_SEL       (* (reg8 *) forwardreverse__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define forwardreverse_PRTDSI__DBL_SYNC_IN    (* (reg8 *) forwardreverse__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define forwardreverse_PRTDSI__OE_SEL0        (* (reg8 *) forwardreverse__PRTDSI__OE_SEL0) 
#define forwardreverse_PRTDSI__OE_SEL1        (* (reg8 *) forwardreverse__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define forwardreverse_PRTDSI__OUT_SEL0       (* (reg8 *) forwardreverse__PRTDSI__OUT_SEL0) 
#define forwardreverse_PRTDSI__OUT_SEL1       (* (reg8 *) forwardreverse__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define forwardreverse_PRTDSI__SYNC_OUT       (* (reg8 *) forwardreverse__PRTDSI__SYNC_OUT) 


#if defined(forwardreverse__INTSTAT)  /* Interrupt Registers */

    #define forwardreverse_INTSTAT                (* (reg8 *) forwardreverse__INTSTAT)
    #define forwardreverse_SNAP                   (* (reg8 *) forwardreverse__SNAP)

#endif /* Interrupt Registers */

#endif /* End Pins forwardreverse_H */


/* [] END OF FILE */
