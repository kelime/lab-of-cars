/*******************************************************************************
* File Name: Elevator_Comparator_1.c
* Version 1.90
*
* Description:
*  This file provides the power management source code APIs for the
*  Comparator.
*
* Note:
*  None
*
********************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#include "Elevator_Comparator_1.h"

static Elevator_Comparator_1_backupStruct Elevator_Comparator_1_backup;


/*******************************************************************************
* Function Name: Elevator_Comparator_1_SaveConfig
********************************************************************************
*
* Summary:
*  Save the current user configuration
*
* Parameters:
*  void:
*
* Return:
*  void
*
*******************************************************************************/
void Elevator_Comparator_1_SaveConfig(void) 
{
    /* Empty since all are system reset for retention flops */
}


/*******************************************************************************
* Function Name: Elevator_Comparator_1_RestoreConfig
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
********************************************************************************/
void Elevator_Comparator_1_RestoreConfig(void) 
{
    /* Empty since all are system reset for retention flops */    
}


/*******************************************************************************
* Function Name: Elevator_Comparator_1_Sleep
********************************************************************************
*
* Summary:
*  Stop and Save the user configuration
*
* Parameters:
*  void:
*
* Return:
*  void
*
* Global variables:
*  Elevator_Comparator_1_backup.enableState:  Is modified depending on the enable 
*   state of the block before entering sleep mode.
*
*******************************************************************************/
void Elevator_Comparator_1_Sleep(void) 
{
    /* Save Comp's enable state */    
    if(Elevator_Comparator_1_ACT_PWR_EN == (Elevator_Comparator_1_PWRMGR & Elevator_Comparator_1_ACT_PWR_EN))
    {
        /* Comp is enabled */
        Elevator_Comparator_1_backup.enableState = 1u;
    }
    else
    {
        /* Comp is disabled */
        Elevator_Comparator_1_backup.enableState = 0u;
    }    
    
    Elevator_Comparator_1_Stop();
    Elevator_Comparator_1_SaveConfig();
}


/*******************************************************************************
* Function Name: Elevator_Comparator_1_Wakeup
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
*  Elevator_Comparator_1_backup.enableState:  Is used to restore the enable state of 
*  block on wakeup from sleep mode.
*
*******************************************************************************/
void Elevator_Comparator_1_Wakeup(void) 
{
    Elevator_Comparator_1_RestoreConfig();
    
    if(Elevator_Comparator_1_backup.enableState == 1u)
    {
        /* Enable Comp's operation */
        Elevator_Comparator_1_Enable();

    } /* Do nothing if Comp was disabled before */
    
}


/* [] END OF FILE */
