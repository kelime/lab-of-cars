/*******************************************************************************
* File Name: Wait_Clock.h
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

#if !defined(CY_CLOCK_Wait_Clock_H)
#define CY_CLOCK_Wait_Clock_H

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

void Wait_Clock_Start(void) ;
void Wait_Clock_Stop(void) ;

#if(CY_PSOC3 || CY_PSOC5LP)
void Wait_Clock_StopBlock(void) ;
#endif

void Wait_Clock_StandbyPower(uint8 state) ;
void Wait_Clock_SetDividerRegister(uint16 clkDivider, uint8 reset) ;
uint16 Wait_Clock_GetDividerRegister(void) ;
void Wait_Clock_SetModeRegister(uint8 modeBitMask) ;
void Wait_Clock_ClearModeRegister(uint8 modeBitMask) ;
uint8 Wait_Clock_GetModeRegister(void) ;
void Wait_Clock_SetSourceRegister(uint8 clkSource) ;
uint8 Wait_Clock_GetSourceRegister(void) ;
#if defined(Wait_Clock__CFG3)
void Wait_Clock_SetPhaseRegister(uint8 clkPhase) ;
uint8 Wait_Clock_GetPhaseRegister(void) ;
#endif

#define Wait_Clock_Enable()                       Wait_Clock_Start()
#define Wait_Clock_Disable()                      Wait_Clock_Stop()
#define Wait_Clock_SetDivider(clkDivider)         Wait_Clock_SetDividerRegister(clkDivider, 1)
#define Wait_Clock_SetDividerValue(clkDivider)    Wait_Clock_SetDividerRegister((clkDivider) - 1, 1)
#define Wait_Clock_SetMode(clkMode)               Wait_Clock_SetModeRegister(clkMode)
#define Wait_Clock_SetSource(clkSource)           Wait_Clock_SetSourceRegister(clkSource)
#if defined(Wait_Clock__CFG3)
#define Wait_Clock_SetPhase(clkPhase)             Wait_Clock_SetPhaseRegister(clkPhase)
#define Wait_Clock_SetPhaseValue(clkPhase)        Wait_Clock_SetPhaseRegister((clkPhase) + 1)
#endif


/***************************************
*             Registers
***************************************/

/* Register to enable or disable the clock */
#define Wait_Clock_CLKEN              (* (reg8 *) Wait_Clock__PM_ACT_CFG)
#define Wait_Clock_CLKEN_PTR          ((reg8 *) Wait_Clock__PM_ACT_CFG)

/* Register to enable or disable the clock */
#define Wait_Clock_CLKSTBY            (* (reg8 *) Wait_Clock__PM_STBY_CFG)
#define Wait_Clock_CLKSTBY_PTR        ((reg8 *) Wait_Clock__PM_STBY_CFG)

/* Clock LSB divider configuration register. */
#define Wait_Clock_DIV_LSB            (* (reg8 *) Wait_Clock__CFG0)
#define Wait_Clock_DIV_LSB_PTR        ((reg8 *) Wait_Clock__CFG0)
#define Wait_Clock_DIV_PTR            ((reg16 *) Wait_Clock__CFG0)

/* Clock MSB divider configuration register. */
#define Wait_Clock_DIV_MSB            (* (reg8 *) Wait_Clock__CFG1)
#define Wait_Clock_DIV_MSB_PTR        ((reg8 *) Wait_Clock__CFG1)

/* Mode and source configuration register */
#define Wait_Clock_MOD_SRC            (* (reg8 *) Wait_Clock__CFG2)
#define Wait_Clock_MOD_SRC_PTR        ((reg8 *) Wait_Clock__CFG2)

#if defined(Wait_Clock__CFG3)
/* Analog clock phase configuration register */
#define Wait_Clock_PHASE              (* (reg8 *) Wait_Clock__CFG3)
#define Wait_Clock_PHASE_PTR          ((reg8 *) Wait_Clock__CFG3)
#endif


/**************************************
*       Register Constants
**************************************/

/* Power manager register masks */
#define Wait_Clock_CLKEN_MASK         Wait_Clock__PM_ACT_MSK
#define Wait_Clock_CLKSTBY_MASK       Wait_Clock__PM_STBY_MSK

/* CFG2 field masks */
#define Wait_Clock_SRC_SEL_MSK        Wait_Clock__CFG2_SRC_SEL_MASK
#define Wait_Clock_MODE_MASK          (~(Wait_Clock_SRC_SEL_MSK))

#if defined(Wait_Clock__CFG3)
/* CFG3 phase mask */
#define Wait_Clock_PHASE_MASK         Wait_Clock__CFG3_PHASE_DLY_MASK
#endif

#endif /* CY_CLOCK_Wait_Clock_H */


/* [] END OF FILE */
