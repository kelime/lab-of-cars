/*******************************************************************************
* File Name: Horizontal_Sync_Line.h  
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

#if !defined(CY_PINS_Horizontal_Sync_Line_H) /* Pins Horizontal_Sync_Line_H */
#define CY_PINS_Horizontal_Sync_Line_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "Horizontal_Sync_Line_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    Horizontal_Sync_Line_Write(uint8 value) ;
void    Horizontal_Sync_Line_SetDriveMode(uint8 mode) ;
uint8   Horizontal_Sync_Line_ReadDataReg(void) ;
uint8   Horizontal_Sync_Line_Read(void) ;
uint8   Horizontal_Sync_Line_ClearInterrupt(void) ;

/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define Horizontal_Sync_Line_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define Horizontal_Sync_Line_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define Horizontal_Sync_Line_DM_RES_UP          PIN_DM_RES_UP
#define Horizontal_Sync_Line_DM_RES_DWN         PIN_DM_RES_DWN
#define Horizontal_Sync_Line_DM_OD_LO           PIN_DM_OD_LO
#define Horizontal_Sync_Line_DM_OD_HI           PIN_DM_OD_HI
#define Horizontal_Sync_Line_DM_STRONG          PIN_DM_STRONG
#define Horizontal_Sync_Line_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define Horizontal_Sync_Line_MASK               Horizontal_Sync_Line__MASK
#define Horizontal_Sync_Line_SHIFT              Horizontal_Sync_Line__SHIFT
#define Horizontal_Sync_Line_WIDTH              1u

/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Horizontal_Sync_Line_PS                     (* (reg8 *) Horizontal_Sync_Line__PS)
/* Data Register */
#define Horizontal_Sync_Line_DR                     (* (reg8 *) Horizontal_Sync_Line__DR)
/* Port Number */
#define Horizontal_Sync_Line_PRT_NUM                (* (reg8 *) Horizontal_Sync_Line__PRT) 
/* Connect to Analog Globals */                                                  
#define Horizontal_Sync_Line_AG                     (* (reg8 *) Horizontal_Sync_Line__AG)                       
/* Analog MUX bux enable */
#define Horizontal_Sync_Line_AMUX                   (* (reg8 *) Horizontal_Sync_Line__AMUX) 
/* Bidirectional Enable */                                                        
#define Horizontal_Sync_Line_BIE                    (* (reg8 *) Horizontal_Sync_Line__BIE)
/* Bit-mask for Aliased Register Access */
#define Horizontal_Sync_Line_BIT_MASK               (* (reg8 *) Horizontal_Sync_Line__BIT_MASK)
/* Bypass Enable */
#define Horizontal_Sync_Line_BYP                    (* (reg8 *) Horizontal_Sync_Line__BYP)
/* Port wide control signals */                                                   
#define Horizontal_Sync_Line_CTL                    (* (reg8 *) Horizontal_Sync_Line__CTL)
/* Drive Modes */
#define Horizontal_Sync_Line_DM0                    (* (reg8 *) Horizontal_Sync_Line__DM0) 
#define Horizontal_Sync_Line_DM1                    (* (reg8 *) Horizontal_Sync_Line__DM1)
#define Horizontal_Sync_Line_DM2                    (* (reg8 *) Horizontal_Sync_Line__DM2) 
/* Input Buffer Disable Override */
#define Horizontal_Sync_Line_INP_DIS                (* (reg8 *) Horizontal_Sync_Line__INP_DIS)
/* LCD Common or Segment Drive */
#define Horizontal_Sync_Line_LCD_COM_SEG            (* (reg8 *) Horizontal_Sync_Line__LCD_COM_SEG)
/* Enable Segment LCD */
#define Horizontal_Sync_Line_LCD_EN                 (* (reg8 *) Horizontal_Sync_Line__LCD_EN)
/* Slew Rate Control */
#define Horizontal_Sync_Line_SLW                    (* (reg8 *) Horizontal_Sync_Line__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define Horizontal_Sync_Line_PRTDSI__CAPS_SEL       (* (reg8 *) Horizontal_Sync_Line__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define Horizontal_Sync_Line_PRTDSI__DBL_SYNC_IN    (* (reg8 *) Horizontal_Sync_Line__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define Horizontal_Sync_Line_PRTDSI__OE_SEL0        (* (reg8 *) Horizontal_Sync_Line__PRTDSI__OE_SEL0) 
#define Horizontal_Sync_Line_PRTDSI__OE_SEL1        (* (reg8 *) Horizontal_Sync_Line__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define Horizontal_Sync_Line_PRTDSI__OUT_SEL0       (* (reg8 *) Horizontal_Sync_Line__PRTDSI__OUT_SEL0) 
#define Horizontal_Sync_Line_PRTDSI__OUT_SEL1       (* (reg8 *) Horizontal_Sync_Line__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define Horizontal_Sync_Line_PRTDSI__SYNC_OUT       (* (reg8 *) Horizontal_Sync_Line__PRTDSI__SYNC_OUT) 


#if defined(Horizontal_Sync_Line__INTSTAT)  /* Interrupt Registers */

    #define Horizontal_Sync_Line_INTSTAT                (* (reg8 *) Horizontal_Sync_Line__INTSTAT)
    #define Horizontal_Sync_Line_SNAP                   (* (reg8 *) Horizontal_Sync_Line__SNAP)

#endif /* Interrupt Registers */

#endif /* End Pins Horizontal_Sync_Line_H */


/* [] END OF FILE */
