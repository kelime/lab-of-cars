/*******************************************************************************
* File Name: Lines_Per_Frame_Counter_PM.c  
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

#include "Lines_Per_Frame_Counter.h"

static Lines_Per_Frame_Counter_backupStruct Lines_Per_Frame_Counter_backup;


/*******************************************************************************
* Function Name: Lines_Per_Frame_Counter_SaveConfig
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
*  Lines_Per_Frame_Counter_backup:  Variables of this global structure are modified to 
*  store the values of non retention configuration registers when Sleep() API is 
*  called.
*
*******************************************************************************/
void Lines_Per_Frame_Counter_SaveConfig(void) 
{
    #if (!Lines_Per_Frame_Counter_UsingFixedFunction)
        /* Backup the UDB non-rentention registers for PSoC5A */
        #if (CY_PSOC5A)
            Lines_Per_Frame_Counter_backup.CounterUdb = Lines_Per_Frame_Counter_ReadCounter();
            Lines_Per_Frame_Counter_backup.CounterPeriod = Lines_Per_Frame_Counter_ReadPeriod();
            Lines_Per_Frame_Counter_backup.CompareValue = Lines_Per_Frame_Counter_ReadCompare();
            Lines_Per_Frame_Counter_backup.InterruptMaskValue = Lines_Per_Frame_Counter_STATUS_MASK;
        #endif /* (CY_PSOC5A) */
        
        #if (CY_PSOC3 || CY_PSOC5LP)
            Lines_Per_Frame_Counter_backup.CounterUdb = Lines_Per_Frame_Counter_ReadCounter();
            Lines_Per_Frame_Counter_backup.InterruptMaskValue = Lines_Per_Frame_Counter_STATUS_MASK;
        #endif /* (CY_PSOC3 || CY_PSOC5LP) */
        
        #if(!Lines_Per_Frame_Counter_ControlRegRemoved)
            Lines_Per_Frame_Counter_backup.CounterControlRegister = Lines_Per_Frame_Counter_ReadControlRegister();
        #endif /* (!Lines_Per_Frame_Counter_ControlRegRemoved) */
    #endif /* (!Lines_Per_Frame_Counter_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: Lines_Per_Frame_Counter_RestoreConfig
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
*  Lines_Per_Frame_Counter_backup:  Variables of this global structure are used to 
*  restore the values of non retention registers on wakeup from sleep mode.
*
*******************************************************************************/
void Lines_Per_Frame_Counter_RestoreConfig(void) 
{      
    #if (!Lines_Per_Frame_Counter_UsingFixedFunction)     
        /* Restore the UDB non-rentention registers for PSoC5A */
        #if (CY_PSOC5A)
            /* Interrupt State Backup for Critical Region*/
            uint8 Lines_Per_Frame_Counter_interruptState;
        
            Lines_Per_Frame_Counter_WriteCounter(Lines_Per_Frame_Counter_backup.CounterUdb);
            Lines_Per_Frame_Counter_WritePeriod(Lines_Per_Frame_Counter_backup.CounterPeriod);
            Lines_Per_Frame_Counter_WriteCompare(Lines_Per_Frame_Counter_backup.CompareValue);
            /* Enter Critical Region*/
            Lines_Per_Frame_Counter_interruptState = CyEnterCriticalSection();
        
            Lines_Per_Frame_Counter_STATUS_AUX_CTRL |= Lines_Per_Frame_Counter_STATUS_ACTL_INT_EN_MASK;
            /* Exit Critical Region*/
            CyExitCriticalSection(Lines_Per_Frame_Counter_interruptState);
            Lines_Per_Frame_Counter_STATUS_MASK = Lines_Per_Frame_Counter_backup.InterruptMaskValue;
        #endif  /* (CY_PSOC5A) */
        
        #if (CY_PSOC3 || CY_PSOC5LP)
            Lines_Per_Frame_Counter_WriteCounter(Lines_Per_Frame_Counter_backup.CounterUdb);
            Lines_Per_Frame_Counter_STATUS_MASK = Lines_Per_Frame_Counter_backup.InterruptMaskValue;
        #endif /* (CY_PSOC3 || CY_PSOC5LP) */
        
        #if(!Lines_Per_Frame_Counter_ControlRegRemoved)
            Lines_Per_Frame_Counter_WriteControlRegister(Lines_Per_Frame_Counter_backup.CounterControlRegister);
        #endif /* (!Lines_Per_Frame_Counter_ControlRegRemoved) */
    #endif /* (!Lines_Per_Frame_Counter_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: Lines_Per_Frame_Counter_Sleep
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
*  Lines_Per_Frame_Counter_backup.enableState:  Is modified depending on the enable 
*  state of the block before entering sleep mode.
*
*******************************************************************************/
void Lines_Per_Frame_Counter_Sleep(void) 
{
    #if(!Lines_Per_Frame_Counter_ControlRegRemoved)
        /* Save Counter's enable state */
        if(Lines_Per_Frame_Counter_CTRL_ENABLE == (Lines_Per_Frame_Counter_CONTROL & Lines_Per_Frame_Counter_CTRL_ENABLE))
        {
            /* Counter is enabled */
            Lines_Per_Frame_Counter_backup.CounterEnableState = 1u;
        }
        else
        {
            /* Counter is disabled */
            Lines_Per_Frame_Counter_backup.CounterEnableState = 0u;
        }
    #endif /* (!Lines_Per_Frame_Counter_ControlRegRemoved) */
    Lines_Per_Frame_Counter_Stop();
    Lines_Per_Frame_Counter_SaveConfig();
}


/*******************************************************************************
* Function Name: Lines_Per_Frame_Counter_Wakeup
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
*  Lines_Per_Frame_Counter_backup.enableState:  Is used to restore the enable state of 
*  block on wakeup from sleep mode.
*
*******************************************************************************/
void Lines_Per_Frame_Counter_Wakeup(void) 
{
    Lines_Per_Frame_Counter_RestoreConfig();
    #if(!Lines_Per_Frame_Counter_ControlRegRemoved)
        if(Lines_Per_Frame_Counter_backup.CounterEnableState == 1u)
        {
            /* Enable Counter's operation */
            Lines_Per_Frame_Counter_Enable();
        } /* Do nothing if Counter was disabled before */    
    #endif /* (!Lines_Per_Frame_Counter_ControlRegRemoved) */
    
}


/* [] END OF FILE */
