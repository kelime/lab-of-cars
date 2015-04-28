/*******************************************************************************
* File Name: Comparator_Input_UNMAPPED.h  
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

#if !defined(CY_PINS_Comparator_Input_UNMAPPED_H) /* Pins Comparator_Input_UNMAPPED_H */
#define CY_PINS_Comparator_Input_UNMAPPED_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "Comparator_Input_UNMAPPED_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    Comparator_Input_UNMAPPED_Write(uint8 value) ;
void    Comparator_Input_UNMAPPED_SetDriveMode(uint8 mode) ;
uint8   Comparator_Input_UNMAPPED_ReadDataReg(void) ;
uint8   Comparator_Input_UNMAPPED_Read(void) ;
uint8   Comparator_Input_UNMAPPED_ClearInterrupt(void) ;

/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define Comparator_Input_UNMAPPED_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define Comparator_Input_UNMAPPED_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define Comparator_Input_UNMAPPED_DM_RES_UP          PIN_DM_RES_UP
#define Comparator_Input_UNMAPPED_DM_RES_DWN         PIN_DM_RES_DWN
#define Comparator_Input_UNMAPPED_DM_OD_LO           PIN_DM_OD_LO
#define Comparator_Input_UNMAPPED_DM_OD_HI           PIN_DM_OD_HI
#define Comparator_Input_UNMAPPED_DM_STRONG          PIN_DM_STRONG
#define Comparator_Input_UNMAPPED_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define Comparator_Input_UNMAPPED_MASK               Comparator_Input_UNMAPPED__MASK
#define Comparator_Input_UNMAPPED_SHIFT              Comparator_Input_UNMAPPED__SHIFT
#define Comparator_Input_UNMAPPED_WIDTH              1u

/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Comparator_Input_UNMAPPED_PS                     (* (reg8 *) Comparator_Input_UNMAPPED__PS)
/* Data Register */
#define Comparator_Input_UNMAPPED_DR                     (* (reg8 *) Comparator_Input_UNMAPPED__DR)
/* Port Number */
#define Comparator_Input_UNMAPPED_PRT_NUM                (* (reg8 *) Comparator_Input_UNMAPPED__PRT) 
/* Connect to Analog Globals */                                                  
#define Comparator_Input_UNMAPPED_AG                     (* (reg8 *) Comparator_Input_UNMAPPED__AG)                       
/* Analog MUX bux enable */
#define Comparator_Input_UNMAPPED_AMUX                   (* (reg8 *) Comparator_Input_UNMAPPED__AMUX) 
/* Bidirectional Enable */                                                        
#define Comparator_Input_UNMAPPED_BIE                    (* (reg8 *) Comparator_Input_UNMAPPED__BIE)
/* Bit-mask for Aliased Register Access */
#define Comparator_Input_UNMAPPED_BIT_MASK               (* (reg8 *) Comparator_Input_UNMAPPED__BIT_MASK)
/* Bypass Enable */
#define Comparator_Input_UNMAPPED_BYP                    (* (reg8 *) Comparator_Input_UNMAPPED__BYP)
/* Port wide control signals */                                                   
#define Comparator_Input_UNMAPPED_CTL                    (* (reg8 *) Comparator_Input_UNMAPPED__CTL)
/* Drive Modes */
#define Comparator_Input_UNMAPPED_DM0                    (* (reg8 *) Comparator_Input_UNMAPPED__DM0) 
#define Comparator_Input_UNMAPPED_DM1                    (* (reg8 *) Comparator_Input_UNMAPPED__DM1)
#define Comparator_Input_UNMAPPED_DM2                    (* (reg8 *) Comparator_Input_UNMAPPED__DM2) 
/* Input Buffer Disable Override */
#define Comparator_Input_UNMAPPED_INP_DIS                (* (reg8 *) Comparator_Input_UNMAPPED__INP_DIS)
/* LCD Common or Segment Drive */
#define Comparator_Input_UNMAPPED_LCD_COM_SEG            (* (reg8 *) Comparator_Input_UNMAPPED__LCD_COM_SEG)
/* Enable Segment LCD */
#define Comparator_Input_UNMAPPED_LCD_EN                 (* (reg8 *) Comparator_Input_UNMAPPED__LCD_EN)
/* Slew Rate Control */
#define Comparator_Input_UNMAPPED_SLW                    (* (reg8 *) Comparator_Input_UNMAPPED__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define Comparator_Input_UNMAPPED_PRTDSI__CAPS_SEL       (* (reg8 *) Comparator_Input_UNMAPPED__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define Comparator_Input_UNMAPPED_PRTDSI__DBL_SYNC_IN    (* (reg8 *) Comparator_Input_UNMAPPED__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define Comparator_Input_UNMAPPED_PRTDSI__OE_SEL0        (* (reg8 *) Comparator_Input_UNMAPPED__PRTDSI__OE_SEL0) 
#define Comparator_Input_UNMAPPED_PRTDSI__OE_SEL1        (* (reg8 *) Comparator_Input_UNMAPPED__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define Comparator_Input_UNMAPPED_PRTDSI__OUT_SEL0       (* (reg8 *) Comparator_Input_UNMAPPED__PRTDSI__OUT_SEL0) 
#define Comparator_Input_UNMAPPED_PRTDSI__OUT_SEL1       (* (reg8 *) Comparator_Input_UNMAPPED__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define Comparator_Input_UNMAPPED_PRTDSI__SYNC_OUT       (* (reg8 *) Comparator_Input_UNMAPPED__PRTDSI__SYNC_OUT) 


#if defined(Comparator_Input_UNMAPPED__INTSTAT)  /* Interrupt Registers */

    #define Comparator_Input_UNMAPPED_INTSTAT                (* (reg8 *) Comparator_Input_UNMAPPED__INTSTAT)
    #define Comparator_Input_UNMAPPED_SNAP                   (* (reg8 *) Comparator_Input_UNMAPPED__SNAP)

#endif /* Interrupt Registers */

#endif /* End Pins Comparator_Input_UNMAPPED_H */


/* [] END OF FILE */
