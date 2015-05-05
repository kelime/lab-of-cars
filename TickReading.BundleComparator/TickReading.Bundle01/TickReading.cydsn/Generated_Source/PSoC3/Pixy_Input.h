/*******************************************************************************
* File Name: Pixy_Input.h  
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

#if !defined(CY_PINS_Pixy_Input_H) /* Pins Pixy_Input_H */
#define CY_PINS_Pixy_Input_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "Pixy_Input_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    Pixy_Input_Write(uint8 value) ;
void    Pixy_Input_SetDriveMode(uint8 mode) ;
uint8   Pixy_Input_ReadDataReg(void) ;
uint8   Pixy_Input_Read(void) ;
uint8   Pixy_Input_ClearInterrupt(void) ;

/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define Pixy_Input_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define Pixy_Input_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define Pixy_Input_DM_RES_UP          PIN_DM_RES_UP
#define Pixy_Input_DM_RES_DWN         PIN_DM_RES_DWN
#define Pixy_Input_DM_OD_LO           PIN_DM_OD_LO
#define Pixy_Input_DM_OD_HI           PIN_DM_OD_HI
#define Pixy_Input_DM_STRONG          PIN_DM_STRONG
#define Pixy_Input_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define Pixy_Input_MASK               Pixy_Input__MASK
#define Pixy_Input_SHIFT              Pixy_Input__SHIFT
#define Pixy_Input_WIDTH              1u

/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Pixy_Input_PS                     (* (reg8 *) Pixy_Input__PS)
/* Data Register */
#define Pixy_Input_DR                     (* (reg8 *) Pixy_Input__DR)
/* Port Number */
#define Pixy_Input_PRT_NUM                (* (reg8 *) Pixy_Input__PRT) 
/* Connect to Analog Globals */                                                  
#define Pixy_Input_AG                     (* (reg8 *) Pixy_Input__AG)                       
/* Analog MUX bux enable */
#define Pixy_Input_AMUX                   (* (reg8 *) Pixy_Input__AMUX) 
/* Bidirectional Enable */                                                        
#define Pixy_Input_BIE                    (* (reg8 *) Pixy_Input__BIE)
/* Bit-mask for Aliased Register Access */
#define Pixy_Input_BIT_MASK               (* (reg8 *) Pixy_Input__BIT_MASK)
/* Bypass Enable */
#define Pixy_Input_BYP                    (* (reg8 *) Pixy_Input__BYP)
/* Port wide control signals */                                                   
#define Pixy_Input_CTL                    (* (reg8 *) Pixy_Input__CTL)
/* Drive Modes */
#define Pixy_Input_DM0                    (* (reg8 *) Pixy_Input__DM0) 
#define Pixy_Input_DM1                    (* (reg8 *) Pixy_Input__DM1)
#define Pixy_Input_DM2                    (* (reg8 *) Pixy_Input__DM2) 
/* Input Buffer Disable Override */
#define Pixy_Input_INP_DIS                (* (reg8 *) Pixy_Input__INP_DIS)
/* LCD Common or Segment Drive */
#define Pixy_Input_LCD_COM_SEG            (* (reg8 *) Pixy_Input__LCD_COM_SEG)
/* Enable Segment LCD */
#define Pixy_Input_LCD_EN                 (* (reg8 *) Pixy_Input__LCD_EN)
/* Slew Rate Control */
#define Pixy_Input_SLW                    (* (reg8 *) Pixy_Input__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define Pixy_Input_PRTDSI__CAPS_SEL       (* (reg8 *) Pixy_Input__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define Pixy_Input_PRTDSI__DBL_SYNC_IN    (* (reg8 *) Pixy_Input__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define Pixy_Input_PRTDSI__OE_SEL0        (* (reg8 *) Pixy_Input__PRTDSI__OE_SEL0) 
#define Pixy_Input_PRTDSI__OE_SEL1        (* (reg8 *) Pixy_Input__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define Pixy_Input_PRTDSI__OUT_SEL0       (* (reg8 *) Pixy_Input__PRTDSI__OUT_SEL0) 
#define Pixy_Input_PRTDSI__OUT_SEL1       (* (reg8 *) Pixy_Input__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define Pixy_Input_PRTDSI__SYNC_OUT       (* (reg8 *) Pixy_Input__PRTDSI__SYNC_OUT) 


#if defined(Pixy_Input__INTSTAT)  /* Interrupt Registers */

    #define Pixy_Input_INTSTAT                (* (reg8 *) Pixy_Input__INTSTAT)
    #define Pixy_Input_SNAP                   (* (reg8 *) Pixy_Input__SNAP)

#endif /* Interrupt Registers */

#endif /* End Pins Pixy_Input_H */


/* [] END OF FILE */
