/*******************************************************************************
* File Name: Hall_Counter_PM.c  
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

#include "Hall_Counter.h"

static Hall_Counter_backupStruct Hall_Counter_backup;


/*******************************************************************************
* Function Name: Hall_Counter_SaveConfig
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
*  Hall_Counter_backup:  Variables of this global structure are modified to 
*  store the values of non retention configuration registers when Sleep() API is 
*  called.
*
*******************************************************************************/
void Hall_Counter_SaveConfig(void) 
{
    #if (!Hall_Counter_UsingFixedFunction)
        /* Backup the UDB non-rentention registers for PSoC5A */
        #if (CY_PSOC5A)
            Hall_Counter_backup.CounterUdb = Hall_Counter_ReadCounter();
            Hall_Counter_backup.CounterPeriod = Hall_Counter_ReadPeriod();
            Hall_Counter_backup.CompareValue = Hall_Counter_ReadCompare();
            Hall_Counter_backup.InterruptMaskValue = Hall_Counter_STATUS_MASK;
        #endif /* (CY_PSOC5A) */
        
        #if (CY_PSOC3 || CY_PSOC5LP)
            Hall_Counter_backup.CounterUdb = Hall_Counter_ReadCounter();
            Hall_Counter_backup.InterruptMaskValue = Hall_Counter_STATUS_MASK;
        #endif /* (CY_PSOC3 || CY_PSOC5LP) */
        
        #if(!Hall_Counter_ControlRegRemoved)
            Hall_Counter_backup.CounterControlRegister = Hall_Counter_ReadControlRegister();
        #endif /* (!Hall_Counter_ControlRegRemoved) */
    #endif /* (!Hall_Counter_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: Hall_Counter_RestoreConfig
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
*  Hall_Counter_backup:  Variables of this global structure are used to 
*  restore the values of non retention registers on wakeup from sleep mode.
*
*******************************************************************************/
void Hall_Counter_RestoreConfig(void) 
{      
    #if (!Hall_Counter_UsingFixedFunction)     
        /* Restore the UDB non-rentention registers for PSoC5A */
        #if (CY_PSOC5A)
            /* Interrupt State Backup for Critical Region*/
            uint8 Hall_Counter_interruptState;
        
            Hall_Counter_WriteCounter(Hall_Counter_backup.CounterUdb);
            Hall_Counter_WritePeriod(Hall_Counter_backup.CounterPeriod);
            Hall_Counter_WriteCompare(Hall_Counter_backup.CompareValue);
            /* Enter Critical Region*/
            Hall_Counter_interruptState = CyEnterCriticalSection();
        
            Hall_Counter_STATUS_AUX_CTRL |= Hall_Counter_STATUS_ACTL_INT_EN_MASK;
            /* Exit Critical Region*/
            CyExitCriticalSection(Hall_Counter_interruptState);
            Hall_Counter_STATUS_MASK = Hall_Counter_backup.InterruptMaskValue;
        #endif  /* (CY_PSOC5A) */
        
        #if (CY_PSOC3 || CY_PSOC5LP)
            Hall_Counter_WriteCounter(Hall_Counter_backup.CounterUdb);
            Hall_Counter_STATUS_MASK = Hall_Counter_backup.InterruptMaskValue;
        #endif /* (CY_PSOC3 || CY_PSOC5LP) */
        
        #if(!Hall_Counter_ControlRegRemoved)
            Hall_Counter_WriteControlRegister(Hall_Counter_backup.CounterControlRegister);
        #endif /* (!Hall_Counter_ControlRegRemoved) */
    #endif /* (!Hall_Counter_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: Hall_Counter_Sleep
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
*  Hall_Counter_backup.enableState:  Is modified depending on the enable 
*  state of the block before entering sleep mode.
*
*******************************************************************************/
void Hall_Counter_Sleep(void) 
{
    #if(!Hall_Counter_ControlRegRemoved)
        /* Save Counter's enable state */
        if(Hall_Counter_CTRL_ENABLE == (Hall_Counter_CONTROL & Hall_Counter_CTRL_ENABLE))
        {
            /* Counter is enabled */
            Hall_Counter_backup.CounterEnableState = 1u;
        }
        else
        {
            /* Counter is disabled */
            Hall_Counter_backup.CounterEnableState = 0u;
        }
    #endif /* (!Hall_Counter_ControlRegRemoved) */
    Hall_Counter_Stop();
    Hall_Counter_SaveConfig();
}


/*******************************************************************************
* Function Name: Hall_Counter_Wakeup
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
*  Hall_Counter_backup.enableState:  Is used to restore the enable state of 
*  block on wakeup from sleep mode.
*
*******************************************************************************/
void Hall_Counter_Wakeup(void) 
{
    Hall_Counter_RestoreConfig();
    #if(!Hall_Counter_ControlRegRemoved)
        if(Hall_Counter_backup.CounterEnableState == 1u)
        {
            /* Enable Counter's operation */
            Hall_Counter_Enable();
        } /* Do nothing if Counter was disabled before */    
    #endif /* (!Hall_Counter_ControlRegRemoved) */
    
}


/* [] END OF FILE */
