/*******************************************************************************
* File Name: Camera_Threshold_PM.c  
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

#include "Camera_Threshold.h"

static Camera_Threshold_backupStruct Camera_Threshold_backup;


/*******************************************************************************
* Function Name: Camera_Threshold_SaveConfig
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
void Camera_Threshold_SaveConfig(void) 
{
    if (!((Camera_Threshold_CR1 & Camera_Threshold_SRC_MASK) == Camera_Threshold_SRC_UDB))
    {
        Camera_Threshold_backup.data_value = Camera_Threshold_Data;
    }
}


/*******************************************************************************
* Function Name: Camera_Threshold_RestoreConfig
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
void Camera_Threshold_RestoreConfig(void) 
{
    if (!((Camera_Threshold_CR1 & Camera_Threshold_SRC_MASK) == Camera_Threshold_SRC_UDB))
    {
        if((Camera_Threshold_Strobe & Camera_Threshold_STRB_MASK) == Camera_Threshold_STRB_EN)
        {
            Camera_Threshold_Strobe &= ~Camera_Threshold_STRB_MASK;
            Camera_Threshold_Data = Camera_Threshold_backup.data_value;
            Camera_Threshold_Strobe |= Camera_Threshold_STRB_EN;
        }
        else
        {
            Camera_Threshold_Data = Camera_Threshold_backup.data_value;
        }
    }
}


/*******************************************************************************
* Function Name: Camera_Threshold_Sleep
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
*  Camera_Threshold_backup.enableState:  Is modified depending on the enable 
*  state  of the block before entering sleep mode.
*
*******************************************************************************/
void Camera_Threshold_Sleep(void) 
{
    /* Save VDAC8's enable state */    
    if(Camera_Threshold_ACT_PWR_EN == (Camera_Threshold_PWRMGR & Camera_Threshold_ACT_PWR_EN))
    {
        /* VDAC8 is enabled */
        Camera_Threshold_backup.enableState = 1u;
    }
    else
    {
        /* VDAC8 is disabled */
        Camera_Threshold_backup.enableState = 0u;
    }
    
    Camera_Threshold_Stop();
    Camera_Threshold_SaveConfig();
}


/*******************************************************************************
* Function Name: Camera_Threshold_Wakeup
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
*  Camera_Threshold_backup.enableState:  Is used to restore the enable state of 
*  block on wakeup from sleep mode.
*
*******************************************************************************/
void Camera_Threshold_Wakeup(void) 
{
    Camera_Threshold_RestoreConfig();
    
    if(Camera_Threshold_backup.enableState == 1u)
    {
        /* Enable VDAC8's operation */
        Camera_Threshold_Enable();

        /* Restore the data register */
        Camera_Threshold_SetValue(Camera_Threshold_Data);
    } /* Do nothing if VDAC8 was disabled before */    
}


/* [] END OF FILE */
