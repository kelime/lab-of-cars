/*******************************************************************************
* File Name: side_rangefinder.h  
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

#if !defined(CY_PINS_side_rangefinder_H) /* Pins side_rangefinder_H */
#define CY_PINS_side_rangefinder_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "side_rangefinder_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    side_rangefinder_Write(uint8 value) ;
void    side_rangefinder_SetDriveMode(uint8 mode) ;
uint8   side_rangefinder_ReadDataReg(void) ;
uint8   side_rangefinder_Read(void) ;
uint8   side_rangefinder_ClearInterrupt(void) ;

/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define side_rangefinder_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define side_rangefinder_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define side_rangefinder_DM_RES_UP          PIN_DM_RES_UP
#define side_rangefinder_DM_RES_DWN         PIN_DM_RES_DWN
#define side_rangefinder_DM_OD_LO           PIN_DM_OD_LO
#define side_rangefinder_DM_OD_HI           PIN_DM_OD_HI
#define side_rangefinder_DM_STRONG          PIN_DM_STRONG
#define side_rangefinder_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define side_rangefinder_MASK               side_rangefinder__MASK
#define side_rangefinder_SHIFT              side_rangefinder__SHIFT
#define side_rangefinder_WIDTH              1u

/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define side_rangefinder_PS                     (* (reg8 *) side_rangefinder__PS)
/* Data Register */
#define side_rangefinder_DR                     (* (reg8 *) side_rangefinder__DR)
/* Port Number */
#define side_rangefinder_PRT_NUM                (* (reg8 *) side_rangefinder__PRT) 
/* Connect to Analog Globals */                                                  
#define side_rangefinder_AG                     (* (reg8 *) side_rangefinder__AG)                       
/* Analog MUX bux enable */
#define side_rangefinder_AMUX                   (* (reg8 *) side_rangefinder__AMUX) 
/* Bidirectional Enable */                                                        
#define side_rangefinder_BIE                    (* (reg8 *) side_rangefinder__BIE)
/* Bit-mask for Aliased Register Access */
#define side_rangefinder_BIT_MASK               (* (reg8 *) side_rangefinder__BIT_MASK)
/* Bypass Enable */
#define side_rangefinder_BYP                    (* (reg8 *) side_rangefinder__BYP)
/* Port wide control signals */                                                   
#define side_rangefinder_CTL                    (* (reg8 *) side_rangefinder__CTL)
/* Drive Modes */
#define side_rangefinder_DM0                    (* (reg8 *) side_rangefinder__DM0) 
#define side_rangefinder_DM1                    (* (reg8 *) side_rangefinder__DM1)
#define side_rangefinder_DM2                    (* (reg8 *) side_rangefinder__DM2) 
/* Input Buffer Disable Override */
#define side_rangefinder_INP_DIS                (* (reg8 *) side_rangefinder__INP_DIS)
/* LCD Common or Segment Drive */
#define side_rangefinder_LCD_COM_SEG            (* (reg8 *) side_rangefinder__LCD_COM_SEG)
/* Enable Segment LCD */
#define side_rangefinder_LCD_EN                 (* (reg8 *) side_rangefinder__LCD_EN)
/* Slew Rate Control */
#define side_rangefinder_SLW                    (* (reg8 *) side_rangefinder__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define side_rangefinder_PRTDSI__CAPS_SEL       (* (reg8 *) side_rangefinder__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define side_rangefinder_PRTDSI__DBL_SYNC_IN    (* (reg8 *) side_rangefinder__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define side_rangefinder_PRTDSI__OE_SEL0        (* (reg8 *) side_rangefinder__PRTDSI__OE_SEL0) 
#define side_rangefinder_PRTDSI__OE_SEL1        (* (reg8 *) side_rangefinder__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define side_rangefinder_PRTDSI__OUT_SEL0       (* (reg8 *) side_rangefinder__PRTDSI__OUT_SEL0) 
#define side_rangefinder_PRTDSI__OUT_SEL1       (* (reg8 *) side_rangefinder__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define side_rangefinder_PRTDSI__SYNC_OUT       (* (reg8 *) side_rangefinder__PRTDSI__SYNC_OUT) 


#if defined(side_rangefinder__INTSTAT)  /* Interrupt Registers */

    #define side_rangefinder_INTSTAT                (* (reg8 *) side_rangefinder__INTSTAT)
    #define side_rangefinder_SNAP                   (* (reg8 *) side_rangefinder__SNAP)

#endif /* Interrupt Registers */

#endif /* End Pins side_rangefinder_H */


/* [] END OF FILE */
