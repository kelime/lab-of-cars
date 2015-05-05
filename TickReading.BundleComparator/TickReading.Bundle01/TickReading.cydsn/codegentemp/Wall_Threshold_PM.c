/*******************************************************************************
* File Name: Wall_Threshold_PM.c  
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

#include "Wall_Threshold.h"

static Wall_Threshold_backupStruct Wall_Threshold_backup;


/*******************************************************************************
* Function Name: Wall_Threshold_SaveConfig
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
void Wall_Threshold_SaveConfig(void) 
{
    if (!((Wall_Threshold_CR1 & Wall_Threshold_SRC_MASK) == Wall_Threshold_SRC_UDB))
    {
        Wall_Threshold_backup.data_value = Wall_Threshold_Data;
    }
}


/*******************************************************************************
* Function Name: Wall_Threshold_RestoreConfig
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
void Wall_Threshold_RestoreConfig(void) 
{
    if (!((Wall_Threshold_CR1 & Wall_Threshold_SRC_MASK) == Wall_Threshold_SRC_UDB))
    {
        if((Wall_Threshold_Strobe & Wall_Threshold_STRB_MASK) == Wall_Threshold_STRB_EN)
        {
            Wall_Threshold_Strobe &= ~Wall_Threshold_STRB_MASK;
            Wall_Threshold_Data = Wall_Threshold_backup.data_value;
            Wall_Threshold_Strobe |= Wall_Threshold_STRB_EN;
        }
        else
        {
            Wall_Threshold_Data = Wall_Threshold_backup.data_value;
        }
    }
}


/*******************************************************************************
* Function Name: Wall_Threshold_Sleep
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
*  Wall_Threshold_backup.enableState:  Is modified depending on the enable 
*  state  of the block before entering sleep mode.
*
*******************************************************************************/
void Wall_Threshold_Sleep(void) 
{
    /* Save VDAC8's enable state */    
    if(Wall_Threshold_ACT_PWR_EN == (Wall_Threshold_PWRMGR & Wall_Threshold_ACT_PWR_EN))
    {
        /* VDAC8 is enabled */
        Wall_Threshold_backup.enableState = 1u;
    }
    else
    {
        /* VDAC8 is disabled */
        Wall_Threshold_backup.enableState = 0u;
    }
    
    Wall_Threshold_Stop();
    Wall_Threshold_SaveConfig();
}


/*******************************************************************************
* Function Name: Wall_Threshold_Wakeup
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
*  Wall_Threshold_backup.enableState:  Is used to restore the enable state of 
*  block on wakeup from sleep mode.
*
*******************************************************************************/
void Wall_Threshold_Wakeup(void) 
{
    Wall_Threshold_RestoreConfig();
    
    if(Wall_Threshold_backup.enableState == 1u)
    {
        /* Enable VDAC8's operation */
        Wall_Threshold_Enable();

        /* Restore the data register */
        Wall_Threshold_SetValue(Wall_Threshold_Data);
    } /* Do nothing if VDAC8 was disabled before */    
}


/* [] END OF FILE */
