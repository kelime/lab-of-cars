/*******************************************************************************
* File Name: PWM_Steering_PM.c
* Version 2.20
*
* Description:
*  This file provides the power management source code to API for the
*  PWM.
*
* Note:
*
********************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/
#include "cytypes.h"
#include "PWM_Steering.h"

static PWM_Steering_backupStruct PWM_Steering_backup;


/*******************************************************************************
* Function Name: PWM_Steering_SaveConfig
********************************************************************************
*
* Summary:
*  Saves the current user configuration of the component.
*  
* Parameters:  
*  void
*
* Return: 
*  void
*
* Global variables:
*  PWM_Steering_backup:  Variables of this global structure are modified to 
*  store the values of non retention configuration registers when Sleep() API is 
*  called.
*
*******************************************************************************/
void PWM_Steering_SaveConfig(void) 
{
    
    #if(!PWM_Steering_UsingFixedFunction)
        #if (CY_PSOC5A)
            PWM_Steering_backup.PWMUdb = PWM_Steering_ReadCounter();
            PWM_Steering_backup.PWMPeriod = PWM_Steering_ReadPeriod();
            #if (PWM_Steering_UseStatus)
                PWM_Steering_backup.InterruptMaskValue = PWM_Steering_STATUS_MASK;
            #endif /* (PWM_Steering_UseStatus) */
            
            #if(PWM_Steering_UseOneCompareMode)
                PWM_Steering_backup.PWMCompareValue = PWM_Steering_ReadCompare();
            #else
                PWM_Steering_backup.PWMCompareValue1 = PWM_Steering_ReadCompare1();
                PWM_Steering_backup.PWMCompareValue2 = PWM_Steering_ReadCompare2();
            #endif /* (PWM_Steering_UseOneCompareMode) */
            
           #if(PWM_Steering_DeadBandUsed)
                PWM_Steering_backup.PWMdeadBandValue = PWM_Steering_ReadDeadTime();
            #endif /* (PWM_Steering_DeadBandUsed) */
          
            #if ( PWM_Steering_KillModeMinTime)
                PWM_Steering_backup.PWMKillCounterPeriod = PWM_Steering_ReadKillTime();
            #endif /* ( PWM_Steering_KillModeMinTime) */
        #endif /* (CY_PSOC5A) */
        
        #if (CY_PSOC3 || CY_PSOC5LP)
            #if(!PWM_Steering_PWMModeIsCenterAligned)
                PWM_Steering_backup.PWMPeriod = PWM_Steering_ReadPeriod();
            #endif /* (!PWM_Steering_PWMModeIsCenterAligned) */
            PWM_Steering_backup.PWMUdb = PWM_Steering_ReadCounter();
            #if (PWM_Steering_UseStatus)
                PWM_Steering_backup.InterruptMaskValue = PWM_Steering_STATUS_MASK;
            #endif /* (PWM_Steering_UseStatus) */
            
            #if(PWM_Steering_DeadBandMode == PWM_Steering__B_PWM__DBM_256_CLOCKS || \
                PWM_Steering_DeadBandMode == PWM_Steering__B_PWM__DBM_2_4_CLOCKS)
                PWM_Steering_backup.PWMdeadBandValue = PWM_Steering_ReadDeadTime();
            #endif /*  deadband count is either 2-4 clocks or 256 clocks */
            
            #if(PWM_Steering_KillModeMinTime)
                 PWM_Steering_backup.PWMKillCounterPeriod = PWM_Steering_ReadKillTime();
            #endif /* (PWM_Steering_KillModeMinTime) */
        #endif /* (CY_PSOC3 || CY_PSOC5LP) */
        
        #if(PWM_Steering_UseControl)
            PWM_Steering_backup.PWMControlRegister = PWM_Steering_ReadControlRegister();
        #endif /* (PWM_Steering_UseControl) */
    #endif  /* (!PWM_Steering_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: PWM_Steering_RestoreConfig
********************************************************************************
* 
* Summary:
*  Restores the current user configuration of the component.
*
* Parameters:  
*  void
*
* Return: 
*  void
*
* Global variables:
*  PWM_Steering_backup:  Variables of this global structure are used to  
*  restore the values of non retention registers on wakeup from sleep mode.
*
*******************************************************************************/
void PWM_Steering_RestoreConfig(void) 
{
        #if(!PWM_Steering_UsingFixedFunction)
            #if (CY_PSOC5A)
                /* Interrupt State Backup for Critical Region*/
                uint8 PWM_Steering_interruptState;
                /* Enter Critical Region*/
                PWM_Steering_interruptState = CyEnterCriticalSection();
                #if (PWM_Steering_UseStatus)
                    /* Use the interrupt output of the status register for IRQ output */
                    PWM_Steering_STATUS_AUX_CTRL |= PWM_Steering_STATUS_ACTL_INT_EN_MASK;
                    
                    PWM_Steering_STATUS_MASK = PWM_Steering_backup.InterruptMaskValue;
                #endif /* (PWM_Steering_UseStatus) */
                
                #if (PWM_Steering_Resolution == 8)
                    /* Set FIFO 0 to 1 byte register for period*/
                    PWM_Steering_AUX_CONTROLDP0 |= (PWM_Steering_AUX_CTRL_FIFO0_CLR);
                #else /* (PWM_Steering_Resolution == 16)*/
                    /* Set FIFO 0 to 1 byte register for period */
                    PWM_Steering_AUX_CONTROLDP0 |= (PWM_Steering_AUX_CTRL_FIFO0_CLR);
                    PWM_Steering_AUX_CONTROLDP1 |= (PWM_Steering_AUX_CTRL_FIFO0_CLR);
                #endif /* (PWM_Steering_Resolution == 8) */
                /* Exit Critical Region*/
                CyExitCriticalSection(PWM_Steering_interruptState);
                
                PWM_Steering_WriteCounter(PWM_Steering_backup.PWMUdb);
                PWM_Steering_WritePeriod(PWM_Steering_backup.PWMPeriod);
                
                #if(PWM_Steering_UseOneCompareMode)
                    PWM_Steering_WriteCompare(PWM_Steering_backup.PWMCompareValue);
                #else
                    PWM_Steering_WriteCompare1(PWM_Steering_backup.PWMCompareValue1);
                    PWM_Steering_WriteCompare2(PWM_Steering_backup.PWMCompareValue2);
                #endif /* (PWM_Steering_UseOneCompareMode) */
                
               #if(PWM_Steering_DeadBandMode == PWM_Steering__B_PWM__DBM_256_CLOCKS || \
                   PWM_Steering_DeadBandMode == PWM_Steering__B_PWM__DBM_2_4_CLOCKS)
                    PWM_Steering_WriteDeadTime(PWM_Steering_backup.PWMdeadBandValue);
                #endif /* deadband count is either 2-4 clocks or 256 clocks */
            
                #if ( PWM_Steering_KillModeMinTime)
                    PWM_Steering_WriteKillTime(PWM_Steering_backup.PWMKillCounterPeriod);
                #endif /* ( PWM_Steering_KillModeMinTime) */
            #endif /* (CY_PSOC5A) */
            
            #if (CY_PSOC3 || CY_PSOC5LP)
                #if(!PWM_Steering_PWMModeIsCenterAligned)
                    PWM_Steering_WritePeriod(PWM_Steering_backup.PWMPeriod);
                #endif /* (!PWM_Steering_PWMModeIsCenterAligned) */
                PWM_Steering_WriteCounter(PWM_Steering_backup.PWMUdb);
                #if (PWM_Steering_UseStatus)
                    PWM_Steering_STATUS_MASK = PWM_Steering_backup.InterruptMaskValue;
                #endif /* (PWM_Steering_UseStatus) */
                
                #if(PWM_Steering_DeadBandMode == PWM_Steering__B_PWM__DBM_256_CLOCKS || \
                    PWM_Steering_DeadBandMode == PWM_Steering__B_PWM__DBM_2_4_CLOCKS)
                    PWM_Steering_WriteDeadTime(PWM_Steering_backup.PWMdeadBandValue);
                #endif /* deadband count is either 2-4 clocks or 256 clocks */
                
                #if(PWM_Steering_KillModeMinTime)
                    PWM_Steering_WriteKillTime(PWM_Steering_backup.PWMKillCounterPeriod);
                #endif /* (PWM_Steering_KillModeMinTime) */
            #endif /* (CY_PSOC3 || CY_PSOC5LP) */
            
            #if(PWM_Steering_UseControl)
                PWM_Steering_WriteControlRegister(PWM_Steering_backup.PWMControlRegister); 
            #endif /* (PWM_Steering_UseControl) */
        #endif  /* (!PWM_Steering_UsingFixedFunction) */
    }


/*******************************************************************************
* Function Name: PWM_Steering_Sleep
********************************************************************************
* 
* Summary:
*  Disables block's operation and saves the user configuration. Should be called 
*  just prior to entering sleep.
*  
* Parameters:  
*  void
*
* Return: 
*  void
*
* Global variables:
*  PWM_Steering_backup.PWMEnableState:  Is modified depending on the enable 
*  state of the block before entering sleep mode.
*
*******************************************************************************/
void PWM_Steering_Sleep(void) 
{
    #if(PWM_Steering_UseControl)
        if(PWM_Steering_CTRL_ENABLE == (PWM_Steering_CONTROL & PWM_Steering_CTRL_ENABLE))
        {
            /*Component is enabled */
            PWM_Steering_backup.PWMEnableState = 1u;
        }
        else
        {
            /* Component is disabled */
            PWM_Steering_backup.PWMEnableState = 0u;
        }
    #endif /* (PWM_Steering_UseControl) */
    /* Stop component */
    PWM_Steering_Stop();
    
    /* Save registers configuration */
    PWM_Steering_SaveConfig();
}


/*******************************************************************************
* Function Name: PWM_Steering_Wakeup
********************************************************************************
* 
* Summary:
*  Restores and enables the user configuration. Should be called just after 
*  awaking from sleep.
*  
* Parameters:  
*  void
*
* Return: 
*  void
*
* Global variables:
*  PWM_Steering_backup.pwmEnable:  Is used to restore the enable state of 
*  block on wakeup from sleep mode.
*
*******************************************************************************/
void PWM_Steering_Wakeup(void) 
{
     /* Restore registers values */
    PWM_Steering_RestoreConfig();
    
    if(PWM_Steering_backup.PWMEnableState != 0u)
    {
        /* Enable component's operation */
        PWM_Steering_Enable();
    } /* Do nothing if component's block was disabled before */
    
}


/* [] END OF FILE */
