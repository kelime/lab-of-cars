/*******************************************************************************
* File Name: Altimeter_Clock.h
* Version 1.70
*
*  Description:
*   Provides the function and constant definitions for the clock component.
*
* Note:
*
********************************************************************************
* Copyright 2008-2010, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
********************************************************************************/

#if !defined(CY_CLOCK_Altimeter_Clock_H)
#define CY_CLOCK_Altimeter_Clock_H

#include <cytypes.h>
#include <cyfitter.h>

/***************************************
* Conditional Compilation Parameters
***************************************/

/* Check to see if required defines such as CY_PSOC5LP are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5LP)
    #error Component cy_clock_v1_70 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5LP) */

/***************************************
*        Function Prototypes
***************************************/

void Altimeter_Clock_Start(void) ;
void Altimeter_Clock_Stop(void) ;

#if(CY_PSOC3 || CY_PSOC5LP)
void Altimeter_Clock_StopBlock(void) ;
#endif

void Altimeter_Clock_StandbyPower(uint8 state) ;
void Altimeter_Clock_SetDividerRegister(uint16 clkDivider, uint8 reset) ;
uint16 Altimeter_Clock_GetDividerRegister(void) ;
void Altimeter_Clock_SetModeRegister(uint8 modeBitMask) ;
void Altimeter_Clock_ClearModeRegister(uint8 modeBitMask) ;
uint8 Altimeter_Clock_GetModeRegister(void) ;
void Altimeter_Clock_SetSourceRegister(uint8 clkSource) ;
uint8 Altimeter_Clock_GetSourceRegister(void) ;
#if defined(Altimeter_Clock__CFG3)
void Altimeter_Clock_SetPhaseRegister(uint8 clkPhase) ;
uint8 Altimeter_Clock_GetPhaseRegister(void) ;
#endif

#define Altimeter_Clock_Enable()                       Altimeter_Clock_Start()
#define Altimeter_Clock_Disable()                      Altimeter_Clock_Stop()
#define Altimeter_Clock_SetDivider(clkDivider)         Altimeter_Clock_SetDividerRegister(clkDivider, 1)
#define Altimeter_Clock_SetDividerValue(clkDivider)    Altimeter_Clock_SetDividerRegister((clkDivider) - 1, 1)
#define Altimeter_Clock_SetMode(clkMode)               Altimeter_Clock_SetModeRegister(clkMode)
#define Altimeter_Clock_SetSource(clkSource)           Altimeter_Clock_SetSourceRegister(clkSource)
#if defined(Altimeter_Clock__CFG3)
#define Altimeter_Clock_SetPhase(clkPhase)             Altimeter_Clock_SetPhaseRegister(clkPhase)
#define Altimeter_Clock_SetPhaseValue(clkPhase)        Altimeter_Clock_SetPhaseRegister((clkPhase) + 1)
#endif


/***************************************
*             Registers
***************************************/

/* Register to enable or disable the clock */
#define Altimeter_Clock_CLKEN              (* (reg8 *) Altimeter_Clock__PM_ACT_CFG)
#define Altimeter_Clock_CLKEN_PTR          ((reg8 *) Altimeter_Clock__PM_ACT_CFG)

/* Register to enable or disable the clock */
#define Altimeter_Clock_CLKSTBY            (* (reg8 *) Altimeter_Clock__PM_STBY_CFG)
#define Altimeter_Clock_CLKSTBY_PTR        ((reg8 *) Altimeter_Clock__PM_STBY_CFG)

/* Clock LSB divider configuration register. */
#define Altimeter_Clock_DIV_LSB            (* (reg8 *) Altimeter_Clock__CFG0)
#define Altimeter_Clock_DIV_LSB_PTR        ((reg8 *) Altimeter_Clock__CFG0)
#define Altimeter_Clock_DIV_PTR            ((reg16 *) Altimeter_Clock__CFG0)

/* Clock MSB divider configuration register. */
#define Altimeter_Clock_DIV_MSB            (* (reg8 *) Altimeter_Clock__CFG1)
#define Altimeter_Clock_DIV_MSB_PTR        ((reg8 *) Altimeter_Clock__CFG1)

/* Mode and source configuration register */
#define Altimeter_Clock_MOD_SRC            (* (reg8 *) Altimeter_Clock__CFG2)
#define Altimeter_Clock_MOD_SRC_PTR        ((reg8 *) Altimeter_Clock__CFG2)

#if defined(Altimeter_Clock__CFG3)
/* Analog clock phase configuration register */
#define Altimeter_Clock_PHASE              (* (reg8 *) Altimeter_Clock__CFG3)
#define Altimeter_Clock_PHASE_PTR          ((reg8 *) Altimeter_Clock__CFG3)
#endif


/**************************************
*       Register Constants
**************************************/

/* Power manager register masks */
#define Altimeter_Clock_CLKEN_MASK         Altimeter_Clock__PM_ACT_MSK
#define Altimeter_Clock_CLKSTBY_MASK       Altimeter_Clock__PM_STBY_MSK

/* CFG2 field masks */
#define Altimeter_Clock_SRC_SEL_MSK        Altimeter_Clock__CFG2_SRC_SEL_MASK
#define Altimeter_Clock_MODE_MASK          (~(Altimeter_Clock_SRC_SEL_MSK))

#if defined(Altimeter_Clock__CFG3)
/* CFG3 phase mask */
#define Altimeter_Clock_PHASE_MASK         Altimeter_Clock__CFG3_PHASE_DLY_MASK
#endif

#endif /* CY_CLOCK_Altimeter_Clock_H */


/* [] END OF FILE */
