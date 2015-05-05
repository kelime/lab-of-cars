/*******************************************************************************
* File Name: Pressure_SCL.h  
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

#if !defined(CY_PINS_Pressure_SCL_H) /* Pins Pressure_SCL_H */
#define CY_PINS_Pressure_SCL_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "Pressure_SCL_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    Pressure_SCL_Write(uint8 value) ;
void    Pressure_SCL_SetDriveMode(uint8 mode) ;
uint8   Pressure_SCL_ReadDataReg(void) ;
uint8   Pressure_SCL_Read(void) ;
uint8   Pressure_SCL_ClearInterrupt(void) ;

/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define Pressure_SCL_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define Pressure_SCL_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define Pressure_SCL_DM_RES_UP          PIN_DM_RES_UP
#define Pressure_SCL_DM_RES_DWN         PIN_DM_RES_DWN
#define Pressure_SCL_DM_OD_LO           PIN_DM_OD_LO
#define Pressure_SCL_DM_OD_HI           PIN_DM_OD_HI
#define Pressure_SCL_DM_STRONG          PIN_DM_STRONG
#define Pressure_SCL_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define Pressure_SCL_MASK               Pressure_SCL__MASK
#define Pressure_SCL_SHIFT              Pressure_SCL__SHIFT
#define Pressure_SCL_WIDTH              1u

/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Pressure_SCL_PS                     (* (reg8 *) Pressure_SCL__PS)
/* Data Register */
#define Pressure_SCL_DR                     (* (reg8 *) Pressure_SCL__DR)
/* Port Number */
#define Pressure_SCL_PRT_NUM                (* (reg8 *) Pressure_SCL__PRT) 
/* Connect to Analog Globals */                                                  
#define Pressure_SCL_AG                     (* (reg8 *) Pressure_SCL__AG)                       
/* Analog MUX bux enable */
#define Pressure_SCL_AMUX                   (* (reg8 *) Pressure_SCL__AMUX) 
/* Bidirectional Enable */                                                        
#define Pressure_SCL_BIE                    (* (reg8 *) Pressure_SCL__BIE)
/* Bit-mask for Aliased Register Access */
#define Pressure_SCL_BIT_MASK               (* (reg8 *) Pressure_SCL__BIT_MASK)
/* Bypass Enable */
#define Pressure_SCL_BYP                    (* (reg8 *) Pressure_SCL__BYP)
/* Port wide control signals */                                                   
#define Pressure_SCL_CTL                    (* (reg8 *) Pressure_SCL__CTL)
/* Drive Modes */
#define Pressure_SCL_DM0                    (* (reg8 *) Pressure_SCL__DM0) 
#define Pressure_SCL_DM1                    (* (reg8 *) Pressure_SCL__DM1)
#define Pressure_SCL_DM2                    (* (reg8 *) Pressure_SCL__DM2) 
/* Input Buffer Disable Override */
#define Pressure_SCL_INP_DIS                (* (reg8 *) Pressure_SCL__INP_DIS)
/* LCD Common or Segment Drive */
#define Pressure_SCL_LCD_COM_SEG            (* (reg8 *) Pressure_SCL__LCD_COM_SEG)
/* Enable Segment LCD */
#define Pressure_SCL_LCD_EN                 (* (reg8 *) Pressure_SCL__LCD_EN)
/* Slew Rate Control */
#define Pressure_SCL_SLW                    (* (reg8 *) Pressure_SCL__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define Pressure_SCL_PRTDSI__CAPS_SEL       (* (reg8 *) Pressure_SCL__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define Pressure_SCL_PRTDSI__DBL_SYNC_IN    (* (reg8 *) Pressure_SCL__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define Pressure_SCL_PRTDSI__OE_SEL0        (* (reg8 *) Pressure_SCL__PRTDSI__OE_SEL0) 
#define Pressure_SCL_PRTDSI__OE_SEL1        (* (reg8 *) Pressure_SCL__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define Pressure_SCL_PRTDSI__OUT_SEL0       (* (reg8 *) Pressure_SCL__PRTDSI__OUT_SEL0) 
#define Pressure_SCL_PRTDSI__OUT_SEL1       (* (reg8 *) Pressure_SCL__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define Pressure_SCL_PRTDSI__SYNC_OUT       (* (reg8 *) Pressure_SCL__PRTDSI__SYNC_OUT) 


#if defined(Pressure_SCL__INTSTAT)  /* Interrupt Registers */

    #define Pressure_SCL_INTSTAT                (* (reg8 *) Pressure_SCL__INTSTAT)
    #define Pressure_SCL_SNAP                   (* (reg8 *) Pressure_SCL__SNAP)

#endif /* Interrupt Registers */

#endif /* End Pins Pressure_SCL_H */


/* [] END OF FILE */
