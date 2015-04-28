/*******************************************************************************
* File Name: Vertical_Sync_Frame.h  
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

#if !defined(CY_PINS_Vertical_Sync_Frame_H) /* Pins Vertical_Sync_Frame_H */
#define CY_PINS_Vertical_Sync_Frame_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "Vertical_Sync_Frame_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    Vertical_Sync_Frame_Write(uint8 value) ;
void    Vertical_Sync_Frame_SetDriveMode(uint8 mode) ;
uint8   Vertical_Sync_Frame_ReadDataReg(void) ;
uint8   Vertical_Sync_Frame_Read(void) ;
uint8   Vertical_Sync_Frame_ClearInterrupt(void) ;

/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define Vertical_Sync_Frame_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define Vertical_Sync_Frame_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define Vertical_Sync_Frame_DM_RES_UP          PIN_DM_RES_UP
#define Vertical_Sync_Frame_DM_RES_DWN         PIN_DM_RES_DWN
#define Vertical_Sync_Frame_DM_OD_LO           PIN_DM_OD_LO
#define Vertical_Sync_Frame_DM_OD_HI           PIN_DM_OD_HI
#define Vertical_Sync_Frame_DM_STRONG          PIN_DM_STRONG
#define Vertical_Sync_Frame_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define Vertical_Sync_Frame_MASK               Vertical_Sync_Frame__MASK
#define Vertical_Sync_Frame_SHIFT              Vertical_Sync_Frame__SHIFT
#define Vertical_Sync_Frame_WIDTH              1u

/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Vertical_Sync_Frame_PS                     (* (reg8 *) Vertical_Sync_Frame__PS)
/* Data Register */
#define Vertical_Sync_Frame_DR                     (* (reg8 *) Vertical_Sync_Frame__DR)
/* Port Number */
#define Vertical_Sync_Frame_PRT_NUM                (* (reg8 *) Vertical_Sync_Frame__PRT) 
/* Connect to Analog Globals */                                                  
#define Vertical_Sync_Frame_AG                     (* (reg8 *) Vertical_Sync_Frame__AG)                       
/* Analog MUX bux enable */
#define Vertical_Sync_Frame_AMUX                   (* (reg8 *) Vertical_Sync_Frame__AMUX) 
/* Bidirectional Enable */                                                        
#define Vertical_Sync_Frame_BIE                    (* (reg8 *) Vertical_Sync_Frame__BIE)
/* Bit-mask for Aliased Register Access */
#define Vertical_Sync_Frame_BIT_MASK               (* (reg8 *) Vertical_Sync_Frame__BIT_MASK)
/* Bypass Enable */
#define Vertical_Sync_Frame_BYP                    (* (reg8 *) Vertical_Sync_Frame__BYP)
/* Port wide control signals */                                                   
#define Vertical_Sync_Frame_CTL                    (* (reg8 *) Vertical_Sync_Frame__CTL)
/* Drive Modes */
#define Vertical_Sync_Frame_DM0                    (* (reg8 *) Vertical_Sync_Frame__DM0) 
#define Vertical_Sync_Frame_DM1                    (* (reg8 *) Vertical_Sync_Frame__DM1)
#define Vertical_Sync_Frame_DM2                    (* (reg8 *) Vertical_Sync_Frame__DM2) 
/* Input Buffer Disable Override */
#define Vertical_Sync_Frame_INP_DIS                (* (reg8 *) Vertical_Sync_Frame__INP_DIS)
/* LCD Common or Segment Drive */
#define Vertical_Sync_Frame_LCD_COM_SEG            (* (reg8 *) Vertical_Sync_Frame__LCD_COM_SEG)
/* Enable Segment LCD */
#define Vertical_Sync_Frame_LCD_EN                 (* (reg8 *) Vertical_Sync_Frame__LCD_EN)
/* Slew Rate Control */
#define Vertical_Sync_Frame_SLW                    (* (reg8 *) Vertical_Sync_Frame__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define Vertical_Sync_Frame_PRTDSI__CAPS_SEL       (* (reg8 *) Vertical_Sync_Frame__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define Vertical_Sync_Frame_PRTDSI__DBL_SYNC_IN    (* (reg8 *) Vertical_Sync_Frame__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define Vertical_Sync_Frame_PRTDSI__OE_SEL0        (* (reg8 *) Vertical_Sync_Frame__PRTDSI__OE_SEL0) 
#define Vertical_Sync_Frame_PRTDSI__OE_SEL1        (* (reg8 *) Vertical_Sync_Frame__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define Vertical_Sync_Frame_PRTDSI__OUT_SEL0       (* (reg8 *) Vertical_Sync_Frame__PRTDSI__OUT_SEL0) 
#define Vertical_Sync_Frame_PRTDSI__OUT_SEL1       (* (reg8 *) Vertical_Sync_Frame__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define Vertical_Sync_Frame_PRTDSI__SYNC_OUT       (* (reg8 *) Vertical_Sync_Frame__PRTDSI__SYNC_OUT) 


#if defined(Vertical_Sync_Frame__INTSTAT)  /* Interrupt Registers */

    #define Vertical_Sync_Frame_INTSTAT                (* (reg8 *) Vertical_Sync_Frame__INTSTAT)
    #define Vertical_Sync_Frame_SNAP                   (* (reg8 *) Vertical_Sync_Frame__SNAP)

#endif /* Interrupt Registers */

#endif /* End Pins Vertical_Sync_Frame_H */


/* [] END OF FILE */
