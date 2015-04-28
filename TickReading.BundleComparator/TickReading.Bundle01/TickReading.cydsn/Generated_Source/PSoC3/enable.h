/*******************************************************************************
* File Name: enable.h  
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

#if !defined(CY_PINS_enable_H) /* Pins enable_H */
#define CY_PINS_enable_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "enable_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    enable_Write(uint8 value) ;
void    enable_SetDriveMode(uint8 mode) ;
uint8   enable_ReadDataReg(void) ;
uint8   enable_Read(void) ;
uint8   enable_ClearInterrupt(void) ;

/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define enable_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define enable_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define enable_DM_RES_UP          PIN_DM_RES_UP
#define enable_DM_RES_DWN         PIN_DM_RES_DWN
#define enable_DM_OD_LO           PIN_DM_OD_LO
#define enable_DM_OD_HI           PIN_DM_OD_HI
#define enable_DM_STRONG          PIN_DM_STRONG
#define enable_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define enable_MASK               enable__MASK
#define enable_SHIFT              enable__SHIFT
#define enable_WIDTH              1u

/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define enable_PS                     (* (reg8 *) enable__PS)
/* Data Register */
#define enable_DR                     (* (reg8 *) enable__DR)
/* Port Number */
#define enable_PRT_NUM                (* (reg8 *) enable__PRT) 
/* Connect to Analog Globals */                                                  
#define enable_AG                     (* (reg8 *) enable__AG)                       
/* Analog MUX bux enable */
#define enable_AMUX                   (* (reg8 *) enable__AMUX) 
/* Bidirectional Enable */                                                        
#define enable_BIE                    (* (reg8 *) enable__BIE)
/* Bit-mask for Aliased Register Access */
#define enable_BIT_MASK               (* (reg8 *) enable__BIT_MASK)
/* Bypass Enable */
#define enable_BYP                    (* (reg8 *) enable__BYP)
/* Port wide control signals */                                                   
#define enable_CTL                    (* (reg8 *) enable__CTL)
/* Drive Modes */
#define enable_DM0                    (* (reg8 *) enable__DM0) 
#define enable_DM1                    (* (reg8 *) enable__DM1)
#define enable_DM2                    (* (reg8 *) enable__DM2) 
/* Input Buffer Disable Override */
#define enable_INP_DIS                (* (reg8 *) enable__INP_DIS)
/* LCD Common or Segment Drive */
#define enable_LCD_COM_SEG            (* (reg8 *) enable__LCD_COM_SEG)
/* Enable Segment LCD */
#define enable_LCD_EN                 (* (reg8 *) enable__LCD_EN)
/* Slew Rate Control */
#define enable_SLW                    (* (reg8 *) enable__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define enable_PRTDSI__CAPS_SEL       (* (reg8 *) enable__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define enable_PRTDSI__DBL_SYNC_IN    (* (reg8 *) enable__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define enable_PRTDSI__OE_SEL0        (* (reg8 *) enable__PRTDSI__OE_SEL0) 
#define enable_PRTDSI__OE_SEL1        (* (reg8 *) enable__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define enable_PRTDSI__OUT_SEL0       (* (reg8 *) enable__PRTDSI__OUT_SEL0) 
#define enable_PRTDSI__OUT_SEL1       (* (reg8 *) enable__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define enable_PRTDSI__SYNC_OUT       (* (reg8 *) enable__PRTDSI__SYNC_OUT) 


#if defined(enable__INTSTAT)  /* Interrupt Registers */

    #define enable_INTSTAT                (* (reg8 *) enable__INTSTAT)
    #define enable_SNAP                   (* (reg8 *) enable__SNAP)

#endif /* Interrupt Registers */

#endif /* End Pins enable_H */


/* [] END OF FILE */
