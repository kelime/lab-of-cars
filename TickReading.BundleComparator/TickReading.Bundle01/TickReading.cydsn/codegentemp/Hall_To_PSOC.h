/*******************************************************************************
* File Name: Hall_To_PSOC.h  
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

#if !defined(CY_PINS_Hall_To_PSOC_H) /* Pins Hall_To_PSOC_H */
#define CY_PINS_Hall_To_PSOC_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "Hall_To_PSOC_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    Hall_To_PSOC_Write(uint8 value) ;
void    Hall_To_PSOC_SetDriveMode(uint8 mode) ;
uint8   Hall_To_PSOC_ReadDataReg(void) ;
uint8   Hall_To_PSOC_Read(void) ;
uint8   Hall_To_PSOC_ClearInterrupt(void) ;

/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define Hall_To_PSOC_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define Hall_To_PSOC_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define Hall_To_PSOC_DM_RES_UP          PIN_DM_RES_UP
#define Hall_To_PSOC_DM_RES_DWN         PIN_DM_RES_DWN
#define Hall_To_PSOC_DM_OD_LO           PIN_DM_OD_LO
#define Hall_To_PSOC_DM_OD_HI           PIN_DM_OD_HI
#define Hall_To_PSOC_DM_STRONG          PIN_DM_STRONG
#define Hall_To_PSOC_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define Hall_To_PSOC_MASK               Hall_To_PSOC__MASK
#define Hall_To_PSOC_SHIFT              Hall_To_PSOC__SHIFT
#define Hall_To_PSOC_WIDTH              1u

/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Hall_To_PSOC_PS                     (* (reg8 *) Hall_To_PSOC__PS)
/* Data Register */
#define Hall_To_PSOC_DR                     (* (reg8 *) Hall_To_PSOC__DR)
/* Port Number */
#define Hall_To_PSOC_PRT_NUM                (* (reg8 *) Hall_To_PSOC__PRT) 
/* Connect to Analog Globals */                                                  
#define Hall_To_PSOC_AG                     (* (reg8 *) Hall_To_PSOC__AG)                       
/* Analog MUX bux enable */
#define Hall_To_PSOC_AMUX                   (* (reg8 *) Hall_To_PSOC__AMUX) 
/* Bidirectional Enable */                                                        
#define Hall_To_PSOC_BIE                    (* (reg8 *) Hall_To_PSOC__BIE)
/* Bit-mask for Aliased Register Access */
#define Hall_To_PSOC_BIT_MASK               (* (reg8 *) Hall_To_PSOC__BIT_MASK)
/* Bypass Enable */
#define Hall_To_PSOC_BYP                    (* (reg8 *) Hall_To_PSOC__BYP)
/* Port wide control signals */                                                   
#define Hall_To_PSOC_CTL                    (* (reg8 *) Hall_To_PSOC__CTL)
/* Drive Modes */
#define Hall_To_PSOC_DM0                    (* (reg8 *) Hall_To_PSOC__DM0) 
#define Hall_To_PSOC_DM1                    (* (reg8 *) Hall_To_PSOC__DM1)
#define Hall_To_PSOC_DM2                    (* (reg8 *) Hall_To_PSOC__DM2) 
/* Input Buffer Disable Override */
#define Hall_To_PSOC_INP_DIS                (* (reg8 *) Hall_To_PSOC__INP_DIS)
/* LCD Common or Segment Drive */
#define Hall_To_PSOC_LCD_COM_SEG            (* (reg8 *) Hall_To_PSOC__LCD_COM_SEG)
/* Enable Segment LCD */
#define Hall_To_PSOC_LCD_EN                 (* (reg8 *) Hall_To_PSOC__LCD_EN)
/* Slew Rate Control */
#define Hall_To_PSOC_SLW                    (* (reg8 *) Hall_To_PSOC__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define Hall_To_PSOC_PRTDSI__CAPS_SEL       (* (reg8 *) Hall_To_PSOC__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define Hall_To_PSOC_PRTDSI__DBL_SYNC_IN    (* (reg8 *) Hall_To_PSOC__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define Hall_To_PSOC_PRTDSI__OE_SEL0        (* (reg8 *) Hall_To_PSOC__PRTDSI__OE_SEL0) 
#define Hall_To_PSOC_PRTDSI__OE_SEL1        (* (reg8 *) Hall_To_PSOC__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define Hall_To_PSOC_PRTDSI__OUT_SEL0       (* (reg8 *) Hall_To_PSOC__PRTDSI__OUT_SEL0) 
#define Hall_To_PSOC_PRTDSI__OUT_SEL1       (* (reg8 *) Hall_To_PSOC__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define Hall_To_PSOC_PRTDSI__SYNC_OUT       (* (reg8 *) Hall_To_PSOC__PRTDSI__SYNC_OUT) 


#if defined(Hall_To_PSOC__INTSTAT)  /* Interrupt Registers */

    #define Hall_To_PSOC_INTSTAT                (* (reg8 *) Hall_To_PSOC__INTSTAT)
    #define Hall_To_PSOC_SNAP                   (* (reg8 *) Hall_To_PSOC__SNAP)

#endif /* Interrupt Registers */

#endif /* End Pins Hall_To_PSOC_H */


/* [] END OF FILE */
