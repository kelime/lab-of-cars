/*******************************************************************************
* File Name: Hall_Input.h  
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

#if !defined(CY_PINS_Hall_Input_H) /* Pins Hall_Input_H */
#define CY_PINS_Hall_Input_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "Hall_Input_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    Hall_Input_Write(uint8 value) ;
void    Hall_Input_SetDriveMode(uint8 mode) ;
uint8   Hall_Input_ReadDataReg(void) ;
uint8   Hall_Input_Read(void) ;
uint8   Hall_Input_ClearInterrupt(void) ;

/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define Hall_Input_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define Hall_Input_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define Hall_Input_DM_RES_UP          PIN_DM_RES_UP
#define Hall_Input_DM_RES_DWN         PIN_DM_RES_DWN
#define Hall_Input_DM_OD_LO           PIN_DM_OD_LO
#define Hall_Input_DM_OD_HI           PIN_DM_OD_HI
#define Hall_Input_DM_STRONG          PIN_DM_STRONG
#define Hall_Input_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define Hall_Input_MASK               Hall_Input__MASK
#define Hall_Input_SHIFT              Hall_Input__SHIFT
#define Hall_Input_WIDTH              1u

/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Hall_Input_PS                     (* (reg8 *) Hall_Input__PS)
/* Data Register */
#define Hall_Input_DR                     (* (reg8 *) Hall_Input__DR)
/* Port Number */
#define Hall_Input_PRT_NUM                (* (reg8 *) Hall_Input__PRT) 
/* Connect to Analog Globals */                                                  
#define Hall_Input_AG                     (* (reg8 *) Hall_Input__AG)                       
/* Analog MUX bux enable */
#define Hall_Input_AMUX                   (* (reg8 *) Hall_Input__AMUX) 
/* Bidirectional Enable */                                                        
#define Hall_Input_BIE                    (* (reg8 *) Hall_Input__BIE)
/* Bit-mask for Aliased Register Access */
#define Hall_Input_BIT_MASK               (* (reg8 *) Hall_Input__BIT_MASK)
/* Bypass Enable */
#define Hall_Input_BYP                    (* (reg8 *) Hall_Input__BYP)
/* Port wide control signals */                                                   
#define Hall_Input_CTL                    (* (reg8 *) Hall_Input__CTL)
/* Drive Modes */
#define Hall_Input_DM0                    (* (reg8 *) Hall_Input__DM0) 
#define Hall_Input_DM1                    (* (reg8 *) Hall_Input__DM1)
#define Hall_Input_DM2                    (* (reg8 *) Hall_Input__DM2) 
/* Input Buffer Disable Override */
#define Hall_Input_INP_DIS                (* (reg8 *) Hall_Input__INP_DIS)
/* LCD Common or Segment Drive */
#define Hall_Input_LCD_COM_SEG            (* (reg8 *) Hall_Input__LCD_COM_SEG)
/* Enable Segment LCD */
#define Hall_Input_LCD_EN                 (* (reg8 *) Hall_Input__LCD_EN)
/* Slew Rate Control */
#define Hall_Input_SLW                    (* (reg8 *) Hall_Input__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define Hall_Input_PRTDSI__CAPS_SEL       (* (reg8 *) Hall_Input__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define Hall_Input_PRTDSI__DBL_SYNC_IN    (* (reg8 *) Hall_Input__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define Hall_Input_PRTDSI__OE_SEL0        (* (reg8 *) Hall_Input__PRTDSI__OE_SEL0) 
#define Hall_Input_PRTDSI__OE_SEL1        (* (reg8 *) Hall_Input__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define Hall_Input_PRTDSI__OUT_SEL0       (* (reg8 *) Hall_Input__PRTDSI__OUT_SEL0) 
#define Hall_Input_PRTDSI__OUT_SEL1       (* (reg8 *) Hall_Input__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define Hall_Input_PRTDSI__SYNC_OUT       (* (reg8 *) Hall_Input__PRTDSI__SYNC_OUT) 


#if defined(Hall_Input__INTSTAT)  /* Interrupt Registers */

    #define Hall_Input_INTSTAT                (* (reg8 *) Hall_Input__INTSTAT)
    #define Hall_Input_SNAP                   (* (reg8 *) Hall_Input__SNAP)

#endif /* Interrupt Registers */

#endif /* End Pins Hall_Input_H */


/* [] END OF FILE */
