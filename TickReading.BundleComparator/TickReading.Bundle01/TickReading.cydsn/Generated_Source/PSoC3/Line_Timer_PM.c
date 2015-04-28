/*******************************************************************************
* File Name: Line_Timer_PM.c
* Version 2.30
*
*  Description:
*     This file provides the power management source code to API for the
*     Timer.
*
*   Note:
*     None
*
*******************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
********************************************************************************/

#include "Line_Timer.h"
static Line_Timer_backupStruct Line_Timer_backup;


/*******************************************************************************
* Function Name: Line_Timer_SaveConfig
********************************************************************************
*
* Summary:
*     Save the current user configuration
*
* Parameters:
*  void
*
* Return:
*  void
*
* Global variables:
*  Line_Timer_backup:  Variables of this global structure are modified to
*  store the values of non retention configuration registers when Sleep() API is
*  called.
*
*******************************************************************************/
void Line_Timer_SaveConfig(void) 
{
    #if (!Line_Timer_UsingFixedFunction)
        /* Backup the UDB non-rentention registers for PSoC5A*/
        #if (CY_PSOC5A)
            Line_Timer_backup.TimerUdb = Line_Timer_ReadCounter();
            Line_Timer_backup.TimerPeriod = Line_Timer_ReadPeriod();
            Line_Timer_backup.InterruptMaskValue = Line_Timer_STATUS_MASK;
            #if (Line_Timer_UsingHWCaptureCounter)
                Line_Timer_backup.TimerCaptureCounter = Line_Timer_ReadCaptureCount();
            #endif /* Backup the UDB non-rentention register capture counter for PSoC5A */
        #endif /* Backup the UDB non-rentention registers for PSoC5A */

        #if (CY_PSOC3 || CY_PSOC5LP)
            Line_Timer_backup.TimerUdb = Line_Timer_ReadCounter();
            Line_Timer_backup.InterruptMaskValue = Line_Timer_STATUS_MASK;
            #if (Line_Timer_UsingHWCaptureCounter)
                Line_Timer_backup.TimerCaptureCounter = Line_Timer_ReadCaptureCount();
            #endif /* Back Up capture counter register  */
        #endif /* Backup non retention registers, interrupt mask and capture counter for PSoC3 or PSoC5LP */

        #if(!Line_Timer_ControlRegRemoved)
            Line_Timer_backup.TimerControlRegister = Line_Timer_ReadControlRegister();
        #endif /* Backup the enable state of the Timer component */
    #endif /* Backup non retention registers in UDB implementation. All fixed function registers are retention */
}


/*******************************************************************************
* Function Name: Line_Timer_RestoreConfig
********************************************************************************
*
* Summary:
*  Restores the current user configuration.
*
* Parameters:
*  void
*
* Return:
*  void
*
* Global variables:
*  Line_Timer_backup:  Variables of this global structure are used to
*  restore the values of non retention registers on wakeup from sleep mode.
*
*******************************************************************************/
void Line_Timer_RestoreConfig(void) 
{   
    #if (!Line_Timer_UsingFixedFunction)
        /* Restore the UDB non-rentention registers for PSoC5A */
        #if (CY_PSOC5A)
            /* Interrupt State Backup for Critical Region*/
            uint8 Line_Timer_interruptState;

            Line_Timer_WriteCounter(Line_Timer_backup.TimerUdb);
            Line_Timer_WritePeriod(Line_Timer_backup.TimerPeriod);
            /* CyEnterCriticalRegion and CyExitCriticalRegion are used to mark following region critical*/
            /* Enter Critical Region*/
            Line_Timer_interruptState = CyEnterCriticalSection();
            /* Use the interrupt output of the status register for IRQ output */
            Line_Timer_STATUS_AUX_CTRL |= Line_Timer_STATUS_ACTL_INT_EN_MASK;
            /* Exit Critical Region*/
            CyExitCriticalSection(Line_Timer_interruptState);
            Line_Timer_STATUS_MASK =Line_Timer_backup.InterruptMaskValue;
            #if (Line_Timer_UsingHWCaptureCounter)
                Line_Timer_SetCaptureCount(Line_Timer_backup.TimerCaptureCounter);
            #endif /* Restore the UDB non-rentention register capture counter for PSoC5A */
        #endif /* Restore the UDB non-rentention registers for PSoC5A */

        #if (CY_PSOC3 || CY_PSOC5LP)
            Line_Timer_WriteCounter(Line_Timer_backup.TimerUdb);
            Line_Timer_STATUS_MASK =Line_Timer_backup.InterruptMaskValue;
            #if (Line_Timer_UsingHWCaptureCounter)
                Line_Timer_SetCaptureCount(Line_Timer_backup.TimerCaptureCounter);
            #endif /* Restore Capture counter register*/
        #endif /* Restore up non retention registers, interrupt mask and capture counter for PSoC3 or PSoC5LP */

        #if(!Line_Timer_ControlRegRemoved)
            Line_Timer_WriteControlRegister(Line_Timer_backup.TimerControlRegister);
        #endif /* Restore the enable state of the Timer component */
    #endif /* Restore non retention registers in the UDB implementation only */
}


/*******************************************************************************
* Function Name: Line_Timer_Sleep
********************************************************************************
*
* Summary:
*     Stop and Save the user configuration
*
* Parameters:
*  void
*
* Return:
*  void
*
* Global variables:
*  Line_Timer_backup.TimerEnableState:  Is modified depending on the
*  enable state of the block before entering sleep mode.
*
*******************************************************************************/
void Line_Timer_Sleep(void) 
{
    #if(!Line_Timer_ControlRegRemoved)
        /* Save Counter's enable state */
        if(Line_Timer_CTRL_ENABLE == (Line_Timer_CONTROL & Line_Timer_CTRL_ENABLE))
        {
            /* Timer is enabled */
            Line_Timer_backup.TimerEnableState = 1u;
        }
        else
        {
            /* Timer is disabled */
            Line_Timer_backup.TimerEnableState = 0u;
        }
    #endif /* Back up enable state from the Timer control register */
    Line_Timer_Stop();
    Line_Timer_SaveConfig();
}


/*******************************************************************************
* Function Name: Line_Timer_Wakeup
********************************************************************************
*
* Summary:
*  Restores and enables the user configuration
*
* Parameters:
*  void
*
* Return:
*  void
*
* Global variables:
*  Line_Timer_backup.enableState:  Is used to restore the enable state of
*  block on wakeup from sleep mode.
*
*******************************************************************************/
void Line_Timer_Wakeup(void) 
{
    Line_Timer_RestoreConfig();
    #if(!Line_Timer_ControlRegRemoved)
        if(Line_Timer_backup.TimerEnableState == 1u)
        {     /* Enable Timer's operation */
                Line_Timer_Enable();
        } /* Do nothing if Timer was disabled before */
    #endif /* Remove this code section if Control register is removed */
}


/* [] END OF FILE */
