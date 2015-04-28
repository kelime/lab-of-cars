/*******************************************************************************
* File Name: Elevator_Threshold_PM.c  
* Version 1.80
*
* Description:
*  This file provides the power management source code to API for the
*  VDAC8.  
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

#include "Elevator_Threshold.h"

static Elevator_Threshold_backupStruct Elevator_Threshold_backup;


/*******************************************************************************
* Function Name: Elevator_Threshold_SaveConfig
********************************************************************************
* Summary:
*  Save the current user configuration
*
* Parameters:  
*  void  
*
* Return: 
*  void
*
*******************************************************************************/
void Elevator_Threshold_SaveConfig(void) 
{
    if (!((Elevator_Threshold_CR1 & Elevator_Threshold_SRC_MASK) == Elevator_Threshold_SRC_UDB))
    {
        Elevator_Threshold_backup.data_value = Elevator_Threshold_Data;
    }
}


/*******************************************************************************
* Function Name: Elevator_Threshold_RestoreConfig
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
*******************************************************************************/
void Elevator_Threshold_RestoreConfig(void) 
{
    if (!((Elevator_Threshold_CR1 & Elevator_Threshold_SRC_MASK) == Elevator_Threshold_SRC_UDB))
    {
        if((Elevator_Threshold_Strobe & Elevator_Threshold_STRB_MASK) == Elevator_Threshold_STRB_EN)
        {
            Elevator_Threshold_Strobe &= ~Elevator_Threshold_STRB_MASK;
            Elevator_Threshold_Data = Elevator_Threshold_backup.data_value;
            Elevator_Threshold_Strobe |= Elevator_Threshold_STRB_EN;
        }
        else
        {
            Elevator_Threshold_Data = Elevator_Threshold_backup.data_value;
        }
    }
}


/*******************************************************************************
* Function Name: Elevator_Threshold_Sleep
********************************************************************************
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
*  Elevator_Threshold_backup.enableState:  Is modified depending on the enable 
*  state  of the block before entering sleep mode.
*
*******************************************************************************/
void Elevator_Threshold_Sleep(void) 
{
    /* Save VDAC8's enable state */    
    if(Elevator_Threshold_ACT_PWR_EN == (Elevator_Threshold_PWRMGR & Elevator_Threshold_ACT_PWR_EN))
    {
        /* VDAC8 is enabled */
        Elevator_Threshold_backup.enableState = 1u;
    }
    else
    {
        /* VDAC8 is disabled */
        Elevator_Threshold_backup.enableState = 0u;
    }
    
    Elevator_Threshold_Stop();
    Elevator_Threshold_SaveConfig();
}


/*******************************************************************************
* Function Name: Elevator_Threshold_Wakeup
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
*  Elevator_Threshold_backup.enableState:  Is used to restore the enable state of 
*  block on wakeup from sleep mode.
*
*******************************************************************************/
void Elevator_Threshold_Wakeup(void) 
{
    Elevator_Threshold_RestoreConfig();
    
    if(Elevator_Threshold_backup.enableState == 1u)
    {
        /* Enable VDAC8's operation */
        Elevator_Threshold_Enable();

        /* Restore the data register */
        Elevator_Threshold_SetValue(Elevator_Threshold_Data);
    } /* Do nothing if VDAC8 was disabled before */    
}


/* [] END OF FILE */
