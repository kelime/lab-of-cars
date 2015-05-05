/*******************************************************************************
* File Name: Side_Rangefinder_Comparator.c
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

#include "Side_Rangefinder_Comparator.h"

static Side_Rangefinder_Comparator_backupStruct Side_Rangefinder_Comparator_backup;


/*******************************************************************************
* Function Name: Side_Rangefinder_Comparator_SaveConfig
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
void Side_Rangefinder_Comparator_SaveConfig(void) 
{
    /* Empty since all are system reset for retention flops */
}


/*******************************************************************************
* Function Name: Side_Rangefinder_Comparator_RestoreConfig
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
void Side_Rangefinder_Comparator_RestoreConfig(void) 
{
    /* Empty since all are system reset for retention flops */    
}


/*******************************************************************************
* Function Name: Side_Rangefinder_Comparator_Sleep
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
*  Side_Rangefinder_Comparator_backup.enableState:  Is modified depending on the enable 
*   state of the block before entering sleep mode.
*
*******************************************************************************/
void Side_Rangefinder_Comparator_Sleep(void) 
{
    /* Save Comp's enable state */    
    if(Side_Rangefinder_Comparator_ACT_PWR_EN == (Side_Rangefinder_Comparator_PWRMGR & Side_Rangefinder_Comparator_ACT_PWR_EN))
    {
        /* Comp is enabled */
        Side_Rangefinder_Comparator_backup.enableState = 1u;
    }
    else
    {
        /* Comp is disabled */
        Side_Rangefinder_Comparator_backup.enableState = 0u;
    }    
    
    Side_Rangefinder_Comparator_Stop();
    Side_Rangefinder_Comparator_SaveConfig();
}


/*******************************************************************************
* Function Name: Side_Rangefinder_Comparator_Wakeup
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
*  Side_Rangefinder_Comparator_backup.enableState:  Is used to restore the enable state of 
*  block on wakeup from sleep mode.
*
*******************************************************************************/
void Side_Rangefinder_Comparator_Wakeup(void) 
{
    Side_Rangefinder_Comparator_RestoreConfig();
    
    if(Side_Rangefinder_Comparator_backup.enableState == 1u)
    {
        /* Enable Comp's operation */
        Side_Rangefinder_Comparator_Enable();

    } /* Do nothing if Comp was disabled before */
    
}


/* [] END OF FILE */
