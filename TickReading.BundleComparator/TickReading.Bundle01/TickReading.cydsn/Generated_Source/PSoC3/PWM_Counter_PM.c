/*******************************************************************************
* File Name: PWM_Counter_PM.c  
* Version 2.20
*
*  Description:
*    This file provides the power management source code to API for the
*    Counter.  
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

#include "PWM_Counter.h"

static PWM_Counter_backupStruct PWM_Counter_backup;


/*******************************************************************************
* Function Name: PWM_Counter_SaveConfig
********************************************************************************
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
*  PWM_Counter_backup:  Variables of this global structure are modified to 
*  store the values of non retention configuration registers when Sleep() API is 
*  called.
*
*******************************************************************************/
void PWM_Counter_SaveConfig(void) 
{
    #if (!PWM_Counter_UsingFixedFunction)
        /* Backup the UDB non-rentention registers for PSoC5A */
        #if (CY_PSOC5A)
            PWM_Counter_backup.CounterUdb = PWM_Counter_ReadCounter();
            PWM_Counter_backup.CounterPeriod = PWM_Counter_ReadPeriod();
            PWM_Counter_backup.CompareValue = PWM_Counter_ReadCompare();
            PWM_Counter_backup.InterruptMaskValue = PWM_Counter_STATUS_MASK;
        #endif /* (CY_PSOC5A) */
        
        #if (CY_PSOC3 || CY_PSOC5LP)
            PWM_Counter_backup.CounterUdb = PWM_Counter_ReadCounter();
            PWM_Counter_backup.InterruptMaskValue = PWM_Counter_STATUS_MASK;
        #endif /* (CY_PSOC3 || CY_PSOC5LP) */
        
        #if(!PWM_Counter_ControlRegRemoved)
            PWM_Counter_backup.CounterControlRegister = PWM_Counter_ReadControlRegister();
        #endif /* (!PWM_Counter_ControlRegRemoved) */
    #endif /* (!PWM_Counter_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: PWM_Counter_RestoreConfig
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
*  PWM_Counter_backup:  Variables of this global structure are used to 
*  restore the values of non retention registers on wakeup from sleep mode.
*
*******************************************************************************/
void PWM_Counter_RestoreConfig(void) 
{      
    #if (!PWM_Counter_UsingFixedFunction)     
        /* Restore the UDB non-rentention registers for PSoC5A */
        #if (CY_PSOC5A)
            /* Interrupt State Backup for Critical Region*/
            uint8 PWM_Counter_interruptState;
        
            PWM_Counter_WriteCounter(PWM_Counter_backup.CounterUdb);
            PWM_Counter_WritePeriod(PWM_Counter_backup.CounterPeriod);
            PWM_Counter_WriteCompare(PWM_Counter_backup.CompareValue);
            /* Enter Critical Region*/
            PWM_Counter_interruptState = CyEnterCriticalSection();
        
            PWM_Counter_STATUS_AUX_CTRL |= PWM_Counter_STATUS_ACTL_INT_EN_MASK;
            /* Exit Critical Region*/
            CyExitCriticalSection(PWM_Counter_interruptState);
            PWM_Counter_STATUS_MASK = PWM_Counter_backup.InterruptMaskValue;
        #endif  /* (CY_PSOC5A) */
        
        #if (CY_PSOC3 || CY_PSOC5LP)
            PWM_Counter_WriteCounter(PWM_Counter_backup.CounterUdb);
            PWM_Counter_STATUS_MASK = PWM_Counter_backup.InterruptMaskValue;
        #endif /* (CY_PSOC3 || CY_PSOC5LP) */
        
        #if(!PWM_Counter_ControlRegRemoved)
            PWM_Counter_WriteControlRegister(PWM_Counter_backup.CounterControlRegister);
        #endif /* (!PWM_Counter_ControlRegRemoved) */
    #endif /* (!PWM_Counter_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: PWM_Counter_Sleep
********************************************************************************
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
*  PWM_Counter_backup.enableState:  Is modified depending on the enable 
*  state of the block before entering sleep mode.
*
*******************************************************************************/
void PWM_Counter_Sleep(void) 
{
    #if(!PWM_Counter_ControlRegRemoved)
        /* Save Counter's enable state */
        if(PWM_Counter_CTRL_ENABLE == (PWM_Counter_CONTROL & PWM_Counter_CTRL_ENABLE))
        {
            /* Counter is enabled */
            PWM_Counter_backup.CounterEnableState = 1u;
        }
        else
        {
            /* Counter is disabled */
            PWM_Counter_backup.CounterEnableState = 0u;
        }
    #endif /* (!PWM_Counter_ControlRegRemoved) */
    PWM_Counter_Stop();
    PWM_Counter_SaveConfig();
}


/*******************************************************************************
* Function Name: PWM_Counter_Wakeup
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
*  PWM_Counter_backup.enableState:  Is used to restore the enable state of 
*  block on wakeup from sleep mode.
*
*******************************************************************************/
void PWM_Counter_Wakeup(void) 
{
    PWM_Counter_RestoreConfig();
    #if(!PWM_Counter_ControlRegRemoved)
        if(PWM_Counter_backup.CounterEnableState == 1u)
        {
            /* Enable Counter's operation */
            PWM_Counter_Enable();
        } /* Do nothing if Counter was disabled before */    
    #endif /* (!PWM_Counter_ControlRegRemoved) */
    
}


/* [] END OF FILE */
