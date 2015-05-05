/*******************************************************************************
* File Name: Altimeter_Counter_PM.c  
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

#include "Altimeter_Counter.h"

static Altimeter_Counter_backupStruct Altimeter_Counter_backup;


/*******************************************************************************
* Function Name: Altimeter_Counter_SaveConfig
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
*  Altimeter_Counter_backup:  Variables of this global structure are modified to 
*  store the values of non retention configuration registers when Sleep() API is 
*  called.
*
*******************************************************************************/
void Altimeter_Counter_SaveConfig(void) 
{
    #if (!Altimeter_Counter_UsingFixedFunction)
        /* Backup the UDB non-rentention registers for PSoC5A */
        #if (CY_PSOC5A)
            Altimeter_Counter_backup.CounterUdb = Altimeter_Counter_ReadCounter();
            Altimeter_Counter_backup.CounterPeriod = Altimeter_Counter_ReadPeriod();
            Altimeter_Counter_backup.CompareValue = Altimeter_Counter_ReadCompare();
            Altimeter_Counter_backup.InterruptMaskValue = Altimeter_Counter_STATUS_MASK;
        #endif /* (CY_PSOC5A) */
        
        #if (CY_PSOC3 || CY_PSOC5LP)
            Altimeter_Counter_backup.CounterUdb = Altimeter_Counter_ReadCounter();
            Altimeter_Counter_backup.InterruptMaskValue = Altimeter_Counter_STATUS_MASK;
        #endif /* (CY_PSOC3 || CY_PSOC5LP) */
        
        #if(!Altimeter_Counter_ControlRegRemoved)
            Altimeter_Counter_backup.CounterControlRegister = Altimeter_Counter_ReadControlRegister();
        #endif /* (!Altimeter_Counter_ControlRegRemoved) */
    #endif /* (!Altimeter_Counter_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: Altimeter_Counter_RestoreConfig
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
*  Altimeter_Counter_backup:  Variables of this global structure are used to 
*  restore the values of non retention registers on wakeup from sleep mode.
*
*******************************************************************************/
void Altimeter_Counter_RestoreConfig(void) 
{      
    #if (!Altimeter_Counter_UsingFixedFunction)     
        /* Restore the UDB non-rentention registers for PSoC5A */
        #if (CY_PSOC5A)
            /* Interrupt State Backup for Critical Region*/
            uint8 Altimeter_Counter_interruptState;
        
            Altimeter_Counter_WriteCounter(Altimeter_Counter_backup.CounterUdb);
            Altimeter_Counter_WritePeriod(Altimeter_Counter_backup.CounterPeriod);
            Altimeter_Counter_WriteCompare(Altimeter_Counter_backup.CompareValue);
            /* Enter Critical Region*/
            Altimeter_Counter_interruptState = CyEnterCriticalSection();
        
            Altimeter_Counter_STATUS_AUX_CTRL |= Altimeter_Counter_STATUS_ACTL_INT_EN_MASK;
            /* Exit Critical Region*/
            CyExitCriticalSection(Altimeter_Counter_interruptState);
            Altimeter_Counter_STATUS_MASK = Altimeter_Counter_backup.InterruptMaskValue;
        #endif  /* (CY_PSOC5A) */
        
        #if (CY_PSOC3 || CY_PSOC5LP)
            Altimeter_Counter_WriteCounter(Altimeter_Counter_backup.CounterUdb);
            Altimeter_Counter_STATUS_MASK = Altimeter_Counter_backup.InterruptMaskValue;
        #endif /* (CY_PSOC3 || CY_PSOC5LP) */
        
        #if(!Altimeter_Counter_ControlRegRemoved)
            Altimeter_Counter_WriteControlRegister(Altimeter_Counter_backup.CounterControlRegister);
        #endif /* (!Altimeter_Counter_ControlRegRemoved) */
    #endif /* (!Altimeter_Counter_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: Altimeter_Counter_Sleep
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
*  Altimeter_Counter_backup.enableState:  Is modified depending on the enable 
*  state of the block before entering sleep mode.
*
*******************************************************************************/
void Altimeter_Counter_Sleep(void) 
{
    #if(!Altimeter_Counter_ControlRegRemoved)
        /* Save Counter's enable state */
        if(Altimeter_Counter_CTRL_ENABLE == (Altimeter_Counter_CONTROL & Altimeter_Counter_CTRL_ENABLE))
        {
            /* Counter is enabled */
            Altimeter_Counter_backup.CounterEnableState = 1u;
        }
        else
        {
            /* Counter is disabled */
            Altimeter_Counter_backup.CounterEnableState = 0u;
        }
    #endif /* (!Altimeter_Counter_ControlRegRemoved) */
    Altimeter_Counter_Stop();
    Altimeter_Counter_SaveConfig();
}


/*******************************************************************************
* Function Name: Altimeter_Counter_Wakeup
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
*  Altimeter_Counter_backup.enableState:  Is used to restore the enable state of 
*  block on wakeup from sleep mode.
*
*******************************************************************************/
void Altimeter_Counter_Wakeup(void) 
{
    Altimeter_Counter_RestoreConfig();
    #if(!Altimeter_Counter_ControlRegRemoved)
        if(Altimeter_Counter_backup.CounterEnableState == 1u)
        {
            /* Enable Counter's operation */
            Altimeter_Counter_Enable();
        } /* Do nothing if Counter was disabled before */    
    #endif /* (!Altimeter_Counter_ControlRegRemoved) */
    
}


/* [] END OF FILE */
