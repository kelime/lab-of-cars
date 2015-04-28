/*******************************************************************************
* File Name: Steering_Output.h  
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

#if !defined(CY_PINS_Steering_Output_H) /* Pins Steering_Output_H */
#define CY_PINS_Steering_Output_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "Steering_Output_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    Steering_Output_Write(uint8 value) ;
void    Steering_Output_SetDriveMode(uint8 mode) ;
uint8   Steering_Output_ReadDataReg(void) ;
uint8   Steering_Output_Read(void) ;
uint8   Steering_Output_ClearInterrupt(void) ;

/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define Steering_Output_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define Steering_Output_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define Steering_Output_DM_RES_UP          PIN_DM_RES_UP
#define Steering_Output_DM_RES_DWN         PIN_DM_RES_DWN
#define Steering_Output_DM_OD_LO           PIN_DM_OD_LO
#define Steering_Output_DM_OD_HI           PIN_DM_OD_HI
#define Steering_Output_DM_STRONG          PIN_DM_STRONG
#define Steering_Output_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define Steering_Output_MASK               Steering_Output__MASK
#define Steering_Output_SHIFT              Steering_Output__SHIFT
#define Steering_Output_WIDTH              1u

/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Steering_Output_PS                     (* (reg8 *) Steering_Output__PS)
/* Data Register */
#define Steering_Output_DR                     (* (reg8 *) Steering_Output__DR)
/* Port Number */
#define Steering_Output_PRT_NUM                (* (reg8 *) Steering_Output__PRT) 
/* Connect to Analog Globals */                                                  
#define Steering_Output_AG                     (* (reg8 *) Steering_Output__AG)                       
/* Analog MUX bux enable */
#define Steering_Output_AMUX                   (* (reg8 *) Steering_Output__AMUX) 
/* Bidirectional Enable */                                                        
#define Steering_Output_BIE                    (* (reg8 *) Steering_Output__BIE)
/* Bit-mask for Aliased Register Access */
#define Steering_Output_BIT_MASK               (* (reg8 *) Steering_Output__BIT_MASK)
/* Bypass Enable */
#define Steering_Output_BYP                    (* (reg8 *) Steering_Output__BYP)
/* Port wide control signals */                                                   
#define Steering_Output_CTL                    (* (reg8 *) Steering_Output__CTL)
/* Drive Modes */
#define Steering_Output_DM0                    (* (reg8 *) Steering_Output__DM0) 
#define Steering_Output_DM1                    (* (reg8 *) Steering_Output__DM1)
#define Steering_Output_DM2                    (* (reg8 *) Steering_Output__DM2) 
/* Input Buffer Disable Override */
#define Steering_Output_INP_DIS                (* (reg8 *) Steering_Output__INP_DIS)
/* LCD Common or Segment Drive */
#define Steering_Output_LCD_COM_SEG            (* (reg8 *) Steering_Output__LCD_COM_SEG)
/* Enable Segment LCD */
#define Steering_Output_LCD_EN                 (* (reg8 *) Steering_Output__LCD_EN)
/* Slew Rate Control */
#define Steering_Output_SLW                    (* (reg8 *) Steering_Output__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define Steering_Output_PRTDSI__CAPS_SEL       (* (reg8 *) Steering_Output__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define Steering_Output_PRTDSI__DBL_SYNC_IN    (* (reg8 *) Steering_Output__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define Steering_Output_PRTDSI__OE_SEL0        (* (reg8 *) Steering_Output__PRTDSI__OE_SEL0) 
#define Steering_Output_PRTDSI__OE_SEL1        (* (reg8 *) Steering_Output__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define Steering_Output_PRTDSI__OUT_SEL0       (* (reg8 *) Steering_Output__PRTDSI__OUT_SEL0) 
#define Steering_Output_PRTDSI__OUT_SEL1       (* (reg8 *) Steering_Output__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define Steering_Output_PRTDSI__SYNC_OUT       (* (reg8 *) Steering_Output__PRTDSI__SYNC_OUT) 


#if defined(Steering_Output__INTSTAT)  /* Interrupt Registers */

    #define Steering_Output_INTSTAT                (* (reg8 *) Steering_Output__INTSTAT)
    #define Steering_Output_SNAP                   (* (reg8 *) Steering_Output__SNAP)

#endif /* Interrupt Registers */

#endif /* End Pins Steering_Output_H */


/* [] END OF FILE */
