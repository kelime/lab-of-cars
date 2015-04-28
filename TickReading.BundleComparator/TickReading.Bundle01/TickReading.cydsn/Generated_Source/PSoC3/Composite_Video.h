/*******************************************************************************
* File Name: Composite_Video.h  
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

#if !defined(CY_PINS_Composite_Video_H) /* Pins Composite_Video_H */
#define CY_PINS_Composite_Video_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "Composite_Video_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    Composite_Video_Write(uint8 value) ;
void    Composite_Video_SetDriveMode(uint8 mode) ;
uint8   Composite_Video_ReadDataReg(void) ;
uint8   Composite_Video_Read(void) ;
uint8   Composite_Video_ClearInterrupt(void) ;

/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define Composite_Video_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define Composite_Video_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define Composite_Video_DM_RES_UP          PIN_DM_RES_UP
#define Composite_Video_DM_RES_DWN         PIN_DM_RES_DWN
#define Composite_Video_DM_OD_LO           PIN_DM_OD_LO
#define Composite_Video_DM_OD_HI           PIN_DM_OD_HI
#define Composite_Video_DM_STRONG          PIN_DM_STRONG
#define Composite_Video_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define Composite_Video_MASK               Composite_Video__MASK
#define Composite_Video_SHIFT              Composite_Video__SHIFT
#define Composite_Video_WIDTH              1u

/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Composite_Video_PS                     (* (reg8 *) Composite_Video__PS)
/* Data Register */
#define Composite_Video_DR                     (* (reg8 *) Composite_Video__DR)
/* Port Number */
#define Composite_Video_PRT_NUM                (* (reg8 *) Composite_Video__PRT) 
/* Connect to Analog Globals */                                                  
#define Composite_Video_AG                     (* (reg8 *) Composite_Video__AG)                       
/* Analog MUX bux enable */
#define Composite_Video_AMUX                   (* (reg8 *) Composite_Video__AMUX) 
/* Bidirectional Enable */                                                        
#define Composite_Video_BIE                    (* (reg8 *) Composite_Video__BIE)
/* Bit-mask for Aliased Register Access */
#define Composite_Video_BIT_MASK               (* (reg8 *) Composite_Video__BIT_MASK)
/* Bypass Enable */
#define Composite_Video_BYP                    (* (reg8 *) Composite_Video__BYP)
/* Port wide control signals */                                                   
#define Composite_Video_CTL                    (* (reg8 *) Composite_Video__CTL)
/* Drive Modes */
#define Composite_Video_DM0                    (* (reg8 *) Composite_Video__DM0) 
#define Composite_Video_DM1                    (* (reg8 *) Composite_Video__DM1)
#define Composite_Video_DM2                    (* (reg8 *) Composite_Video__DM2) 
/* Input Buffer Disable Override */
#define Composite_Video_INP_DIS                (* (reg8 *) Composite_Video__INP_DIS)
/* LCD Common or Segment Drive */
#define Composite_Video_LCD_COM_SEG            (* (reg8 *) Composite_Video__LCD_COM_SEG)
/* Enable Segment LCD */
#define Composite_Video_LCD_EN                 (* (reg8 *) Composite_Video__LCD_EN)
/* Slew Rate Control */
#define Composite_Video_SLW                    (* (reg8 *) Composite_Video__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define Composite_Video_PRTDSI__CAPS_SEL       (* (reg8 *) Composite_Video__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define Composite_Video_PRTDSI__DBL_SYNC_IN    (* (reg8 *) Composite_Video__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define Composite_Video_PRTDSI__OE_SEL0        (* (reg8 *) Composite_Video__PRTDSI__OE_SEL0) 
#define Composite_Video_PRTDSI__OE_SEL1        (* (reg8 *) Composite_Video__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define Composite_Video_PRTDSI__OUT_SEL0       (* (reg8 *) Composite_Video__PRTDSI__OUT_SEL0) 
#define Composite_Video_PRTDSI__OUT_SEL1       (* (reg8 *) Composite_Video__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define Composite_Video_PRTDSI__SYNC_OUT       (* (reg8 *) Composite_Video__PRTDSI__SYNC_OUT) 


#if defined(Composite_Video__INTSTAT)  /* Interrupt Registers */

    #define Composite_Video_INTSTAT                (* (reg8 *) Composite_Video__INTSTAT)
    #define Composite_Video_SNAP                   (* (reg8 *) Composite_Video__SNAP)

#endif /* Interrupt Registers */

#endif /* End Pins Composite_Video_H */


/* [] END OF FILE */
