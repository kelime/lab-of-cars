/*******************************************************************************
* File Name: Pressure_SDA.h  
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

#if !defined(CY_PINS_Pressure_SDA_H) /* Pins Pressure_SDA_H */
#define CY_PINS_Pressure_SDA_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "Pressure_SDA_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    Pressure_SDA_Write(uint8 value) ;
void    Pressure_SDA_SetDriveMode(uint8 mode) ;
uint8   Pressure_SDA_ReadDataReg(void) ;
uint8   Pressure_SDA_Read(void) ;
uint8   Pressure_SDA_ClearInterrupt(void) ;

/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define Pressure_SDA_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define Pressure_SDA_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define Pressure_SDA_DM_RES_UP          PIN_DM_RES_UP
#define Pressure_SDA_DM_RES_DWN         PIN_DM_RES_DWN
#define Pressure_SDA_DM_OD_LO           PIN_DM_OD_LO
#define Pressure_SDA_DM_OD_HI           PIN_DM_OD_HI
#define Pressure_SDA_DM_STRONG          PIN_DM_STRONG
#define Pressure_SDA_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define Pressure_SDA_MASK               Pressure_SDA__MASK
#define Pressure_SDA_SHIFT              Pressure_SDA__SHIFT
#define Pressure_SDA_WIDTH              1u

/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Pressure_SDA_PS                     (* (reg8 *) Pressure_SDA__PS)
/* Data Register */
#define Pressure_SDA_DR                     (* (reg8 *) Pressure_SDA__DR)
/* Port Number */
#define Pressure_SDA_PRT_NUM                (* (reg8 *) Pressure_SDA__PRT) 
/* Connect to Analog Globals */                                                  
#define Pressure_SDA_AG                     (* (reg8 *) Pressure_SDA__AG)                       
/* Analog MUX bux enable */
#define Pressure_SDA_AMUX                   (* (reg8 *) Pressure_SDA__AMUX) 
/* Bidirectional Enable */                                                        
#define Pressure_SDA_BIE                    (* (reg8 *) Pressure_SDA__BIE)
/* Bit-mask for Aliased Register Access */
#define Pressure_SDA_BIT_MASK               (* (reg8 *) Pressure_SDA__BIT_MASK)
/* Bypass Enable */
#define Pressure_SDA_BYP                    (* (reg8 *) Pressure_SDA__BYP)
/* Port wide control signals */                                                   
#define Pressure_SDA_CTL                    (* (reg8 *) Pressure_SDA__CTL)
/* Drive Modes */
#define Pressure_SDA_DM0                    (* (reg8 *) Pressure_SDA__DM0) 
#define Pressure_SDA_DM1                    (* (reg8 *) Pressure_SDA__DM1)
#define Pressure_SDA_DM2                    (* (reg8 *) Pressure_SDA__DM2) 
/* Input Buffer Disable Override */
#define Pressure_SDA_INP_DIS                (* (reg8 *) Pressure_SDA__INP_DIS)
/* LCD Common or Segment Drive */
#define Pressure_SDA_LCD_COM_SEG            (* (reg8 *) Pressure_SDA__LCD_COM_SEG)
/* Enable Segment LCD */
#define Pressure_SDA_LCD_EN                 (* (reg8 *) Pressure_SDA__LCD_EN)
/* Slew Rate Control */
#define Pressure_SDA_SLW                    (* (reg8 *) Pressure_SDA__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define Pressure_SDA_PRTDSI__CAPS_SEL       (* (reg8 *) Pressure_SDA__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define Pressure_SDA_PRTDSI__DBL_SYNC_IN    (* (reg8 *) Pressure_SDA__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define Pressure_SDA_PRTDSI__OE_SEL0        (* (reg8 *) Pressure_SDA__PRTDSI__OE_SEL0) 
#define Pressure_SDA_PRTDSI__OE_SEL1        (* (reg8 *) Pressure_SDA__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define Pressure_SDA_PRTDSI__OUT_SEL0       (* (reg8 *) Pressure_SDA__PRTDSI__OUT_SEL0) 
#define Pressure_SDA_PRTDSI__OUT_SEL1       (* (reg8 *) Pressure_SDA__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define Pressure_SDA_PRTDSI__SYNC_OUT       (* (reg8 *) Pressure_SDA__PRTDSI__SYNC_OUT) 


#if defined(Pressure_SDA__INTSTAT)  /* Interrupt Registers */

    #define Pressure_SDA_INTSTAT                (* (reg8 *) Pressure_SDA__INTSTAT)
    #define Pressure_SDA_SNAP                   (* (reg8 *) Pressure_SDA__SNAP)

#endif /* Interrupt Registers */

#endif /* End Pins Pressure_SDA_H */


/* [] END OF FILE */
