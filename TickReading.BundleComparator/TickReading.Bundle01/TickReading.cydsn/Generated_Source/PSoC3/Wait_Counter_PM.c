/*******************************************************************************
* File Name: Wait_Counter_PM.c  
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

#include "Wait_Counter.h"

static Wait_Counter_backupStruct Wait_Counter_backup;


/*******************************************************************************
* Function Name: Wait_Counter_SaveConfig
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
*  Wait_Counter_backup:  Variables of this global structure are modified to 
*  store the values of non retention configuration registers when Sleep() API is 
*  called.
*
*******************************************************************************/
void Wait_Counter_SaveConfig(void) 
{
    #if (!Wait_Counter_UsingFixedFunction)
        /* Backup the UDB non-rentention registers for PSoC5A */
        #if (CY_PSOC5A)
            Wait_Counter_backup.CounterUdb = Wait_Counter_ReadCounter();
            Wait_Counter_backup.CounterPeriod = Wait_Counter_ReadPeriod();
            Wait_Counter_backup.CompareValue = Wait_Counter_ReadCompare();
            Wait_Counter_backup.InterruptMaskValue = Wait_Counter_STATUS_MASK;
        #endif /* (CY_PSOC5A) */
        
        #if (CY_PSOC3 || CY_PSOC5LP)
            Wait_Counter_backup.CounterUdb = Wait_Counter_ReadCounter();
            Wait_Counter_backup.InterruptMaskValue = Wait_Counter_STATUS_MASK;
        #endif /* (CY_PSOC3 || CY_PSOC5LP) */
        
        #if(!Wait_Counter_ControlRegRemoved)
            Wait_Counter_backup.CounterControlRegister = Wait_Counter_ReadControlRegister();
        #endif /* (!Wait_Counter_ControlRegRemoved) */
    #endif /* (!Wait_Counter_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: Wait_Counter_RestoreConfig
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
*  Wait_Counter_backup:  Variables of this global structure are used to 
*  restore the values of non retention registers on wakeup from sleep mode.
*
*******************************************************************************/
void Wait_Counter_RestoreConfig(void) 
{      
    #if (!Wait_Counter_UsingFixedFunction)     
        /* Restore the UDB non-rentention registers for PSoC5A */
        #if (CY_PSOC5A)
            /* Interrupt State Backup for Critical Region*/
            uint8 Wait_Counter_interruptState;
        
            Wait_Counter_WriteCounter(Wait_Counter_backup.CounterUdb);
            Wait_Counter_WritePeriod(Wait_Counter_backup.CounterPeriod);
            Wait_Counter_WriteCompare(Wait_Counter_backup.CompareValue);
            /* Enter Critical Region*/
            Wait_Counter_interruptState = CyEnterCriticalSection();
        
            Wait_Counter_STATUS_AUX_CTRL |= Wait_Counter_STATUS_ACTL_INT_EN_MASK;
            /* Exit Critical Region*/
            CyExitCriticalSection(Wait_Counter_interruptState);
            Wait_Counter_STATUS_MASK = Wait_Counter_backup.InterruptMaskValue;
        #endif  /* (CY_PSOC5A) */
        
        #if (CY_PSOC3 || CY_PSOC5LP)
            Wait_Counter_WriteCounter(Wait_Counter_backup.CounterUdb);
            Wait_Counter_STATUS_MASK = Wait_Counter_backup.InterruptMaskValue;
        #endif /* (CY_PSOC3 || CY_PSOC5LP) */
        
        #if(!Wait_Counter_ControlRegRemoved)
            Wait_Counter_WriteControlRegister(Wait_Counter_backup.CounterControlRegister);
        #endif /* (!Wait_Counter_ControlRegRemoved) */
    #endif /* (!Wait_Counter_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: Wait_Counter_Sleep
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
*  Wait_Counter_backup.enableState:  Is modified depending on the enable 
*  state of the block before entering sleep mode.
*
*******************************************************************************/
void Wait_Counter_Sleep(void) 
{
    #if(!Wait_Counter_ControlRegRemoved)
        /* Save Counter's enable state */
        if(Wait_Counter_CTRL_ENABLE == (Wait_Counter_CONTROL & Wait_Counter_CTRL_ENABLE))
        {
            /* Counter is enabled */
            Wait_Counter_backup.CounterEnableState = 1u;
        }
        else
        {
            /* Counter is disabled */
            Wait_Counter_backup.CounterEnableState = 0u;
        }
    #endif /* (!Wait_Counter_ControlRegRemoved) */
    Wait_Counter_Stop();
    Wait_Counter_SaveConfig();
}


/*******************************************************************************
* Function Name: Wait_Counter_Wakeup
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
*  Wait_Counter_backup.enableState:  Is used to restore the enable state of 
*  block on wakeup from sleep mode.
*
*******************************************************************************/
void Wait_Counter_Wakeup(void) 
{
    Wait_Counter_RestoreConfig();
    #if(!Wait_Counter_ControlRegRemoved)
        if(Wait_Counter_backup.CounterEnableState == 1u)
        {
            /* Enable Counter's operation */
            Wait_Counter_Enable();
        } /* Do nothing if Counter was disabled before */    
    #endif /* (!Wait_Counter_ControlRegRemoved) */
    
}


/* [] END OF FILE */
