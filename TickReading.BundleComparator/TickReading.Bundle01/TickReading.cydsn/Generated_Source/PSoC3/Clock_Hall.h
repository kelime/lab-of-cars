/*******************************************************************************
* File Name: Clock_Hall.h
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

#if !defined(CY_CLOCK_Clock_Hall_H)
#define CY_CLOCK_Clock_Hall_H

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

void Clock_Hall_Start(void) ;
void Clock_Hall_Stop(void) ;

#if(CY_PSOC3 || CY_PSOC5LP)
void Clock_Hall_StopBlock(void) ;
#endif

void Clock_Hall_StandbyPower(uint8 state) ;
void Clock_Hall_SetDividerRegister(uint16 clkDivider, uint8 reset) ;
uint16 Clock_Hall_GetDividerRegister(void) ;
void Clock_Hall_SetModeRegister(uint8 modeBitMask) ;
void Clock_Hall_ClearModeRegister(uint8 modeBitMask) ;
uint8 Clock_Hall_GetModeRegister(void) ;
void Clock_Hall_SetSourceRegister(uint8 clkSource) ;
uint8 Clock_Hall_GetSourceRegister(void) ;
#if defined(Clock_Hall__CFG3)
void Clock_Hall_SetPhaseRegister(uint8 clkPhase) ;
uint8 Clock_Hall_GetPhaseRegister(void) ;
#endif

#define Clock_Hall_Enable()                       Clock_Hall_Start()
#define Clock_Hall_Disable()                      Clock_Hall_Stop()
#define Clock_Hall_SetDivider(clkDivider)         Clock_Hall_SetDividerRegister(clkDivider, 1)
#define Clock_Hall_SetDividerValue(clkDivider)    Clock_Hall_SetDividerRegister((clkDivider) - 1, 1)
#define Clock_Hall_SetMode(clkMode)               Clock_Hall_SetModeRegister(clkMode)
#define Clock_Hall_SetSource(clkSource)           Clock_Hall_SetSourceRegister(clkSource)
#if defined(Clock_Hall__CFG3)
#define Clock_Hall_SetPhase(clkPhase)             Clock_Hall_SetPhaseRegister(clkPhase)
#define Clock_Hall_SetPhaseValue(clkPhase)        Clock_Hall_SetPhaseRegister((clkPhase) + 1)
#endif


/***************************************
*             Registers
***************************************/

/* Register to enable or disable the clock */
#define Clock_Hall_CLKEN              (* (reg8 *) Clock_Hall__PM_ACT_CFG)
#define Clock_Hall_CLKEN_PTR          ((reg8 *) Clock_Hall__PM_ACT_CFG)

/* Register to enable or disable the clock */
#define Clock_Hall_CLKSTBY            (* (reg8 *) Clock_Hall__PM_STBY_CFG)
#define Clock_Hall_CLKSTBY_PTR        ((reg8 *) Clock_Hall__PM_STBY_CFG)

/* Clock LSB divider configuration register. */
#define Clock_Hall_DIV_LSB            (* (reg8 *) Clock_Hall__CFG0)
#define Clock_Hall_DIV_LSB_PTR        ((reg8 *) Clock_Hall__CFG0)
#define Clock_Hall_DIV_PTR            ((reg16 *) Clock_Hall__CFG0)

/* Clock MSB divider configuration register. */
#define Clock_Hall_DIV_MSB            (* (reg8 *) Clock_Hall__CFG1)
#define Clock_Hall_DIV_MSB_PTR        ((reg8 *) Clock_Hall__CFG1)

/* Mode and source configuration register */
#define Clock_Hall_MOD_SRC            (* (reg8 *) Clock_Hall__CFG2)
#define Clock_Hall_MOD_SRC_PTR        ((reg8 *) Clock_Hall__CFG2)

#if defined(Clock_Hall__CFG3)
/* Analog clock phase configuration register */
#define Clock_Hall_PHASE              (* (reg8 *) Clock_Hall__CFG3)
#define Clock_Hall_PHASE_PTR          ((reg8 *) Clock_Hall__CFG3)
#endif


/**************************************
*       Register Constants
**************************************/

/* Power manager register masks */
#define Clock_Hall_CLKEN_MASK         Clock_Hall__PM_ACT_MSK
#define Clock_Hall_CLKSTBY_MASK       Clock_Hall__PM_STBY_MSK

/* CFG2 field masks */
#define Clock_Hall_SRC_SEL_MSK        Clock_Hall__CFG2_SRC_SEL_MASK
#define Clock_Hall_MODE_MASK          (~(Clock_Hall_SRC_SEL_MSK))

#if defined(Clock_Hall__CFG3)
/* CFG3 phase mask */
#define Clock_Hall_PHASE_MASK         Clock_Hall__CFG3_PHASE_DLY_MASK
#endif

#endif /* CY_CLOCK_Clock_Hall_H */


/* [] END OF FILE */
