/*******************************************************************************
* File Name: PWM_Steering.c  
* Version 2.20
*
* Description:
*  The PWM User Module consist of an 8 or 16-bit counter with two 8 or 16-bit
*  comparitors. Each instance of this user module is capable of generating
*  two PWM outputs with the same period. The pulse width is selectable between
*  1 and 255/65535. The period is selectable between 2 and 255/65536 clocks. 
*  The compare value output may be configured to be active when the present 
*  counter is less than or less than/equal to the compare value.
*  A terminal count output is also provided. It generates a pulse one clock
*  width wide when the counter is equal to zero.
*
* Note:
*
*******************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
********************************************************************************/

#include "cytypes.h"
#include "PWM_Steering.h"

uint8 PWM_Steering_initVar = 0u;


/*******************************************************************************
* Function Name: PWM_Steering_Start
********************************************************************************
*
* Summary:
*  The start function initializes the pwm with the default values, the 
*  enables the counter to begin counting.  It does not enable interrupts,
*  the EnableInt command should be called if interrupt generation is required.
*
* Parameters:  
*  void  
*
* Return: 
*  void
*
* Global variables:
*  PWM_Steering_initVar: Is modified when this function is called for the 
*   first time. Is used to ensure that initialization happens only once.
*
*******************************************************************************/
void PWM_Steering_Start(void) 
{
    /* If not Initialized then initialize all required hardware and software */
    if(PWM_Steering_initVar == 0u)
    {
        PWM_Steering_Init();
        PWM_Steering_initVar = 1u;
    }
    PWM_Steering_Enable();

}


/*******************************************************************************
* Function Name: PWM_Steering_Init
********************************************************************************
*
* Summary:
*  Initialize component's parameters to the parameters set by user in the 
*  customizer of the component placed onto schematic. Usually called in 
*  PWM_Steering_Start().
*
* Parameters:  
*  void
*
* Return: 
*  void
*
*******************************************************************************/
void PWM_Steering_Init(void) 
{
    #if (PWM_Steering_UsingFixedFunction || PWM_Steering_UseControl)
        uint8 ctrl;
    #endif /* (PWM_Steering_UsingFixedFunction || PWM_Steering_UseControl) */
    
    #if(!PWM_Steering_UsingFixedFunction) 
        #if(PWM_Steering_UseStatus)
            /* Interrupt State Backup for Critical Region*/
            uint8 PWM_Steering_interruptState;
        #endif /* (PWM_Steering_UseStatus) */
    #endif /* (!PWM_Steering_UsingFixedFunction) */
    
    #if (PWM_Steering_UsingFixedFunction)
        /* You are allowed to write the compare value (FF only) */
        PWM_Steering_CONTROL |= PWM_Steering_CFG0_MODE;
        #if (PWM_Steering_DeadBand2_4)
            PWM_Steering_CONTROL |= PWM_Steering_CFG0_DB;
        #endif /* (PWM_Steering_DeadBand2_4) */
                
        /* Set the default Compare Mode */
        #if(CY_PSOC5A)
                ctrl = PWM_Steering_CONTROL2 & ~PWM_Steering_CTRL_CMPMODE1_MASK;
                PWM_Steering_CONTROL2 = ctrl | PWM_Steering_DEFAULT_COMPARE1_MODE;
        #endif /* (CY_PSOC5A) */
        #if(CY_PSOC3 || CY_PSOC5LP)
                ctrl = PWM_Steering_CONTROL3 & ~PWM_Steering_CTRL_CMPMODE1_MASK;
                PWM_Steering_CONTROL3 = ctrl | PWM_Steering_DEFAULT_COMPARE1_MODE;
        #endif /* (CY_PSOC3 || CY_PSOC5LP) */
        
         /* Clear and Set SYNCTC and SYNCCMP bits of RT1 register */
        PWM_Steering_RT1 &= ~PWM_Steering_RT1_MASK;
        PWM_Steering_RT1 |= PWM_Steering_SYNC;     
                
        /*Enable DSI Sync all all inputs of the PWM*/
        PWM_Steering_RT1 &= ~(PWM_Steering_SYNCDSI_MASK);
        PWM_Steering_RT1 |= PWM_Steering_SYNCDSI_EN;
       
    #elif (PWM_Steering_UseControl)
        /* Set the default compare mode defined in the parameter */
        ctrl = PWM_Steering_CONTROL & ~PWM_Steering_CTRL_CMPMODE2_MASK & ~PWM_Steering_CTRL_CMPMODE1_MASK;
        PWM_Steering_CONTROL = ctrl | PWM_Steering_DEFAULT_COMPARE2_MODE | 
                                   PWM_Steering_DEFAULT_COMPARE1_MODE;
    #endif /* (PWM_Steering_UsingFixedFunction) */
        
    #if (!PWM_Steering_UsingFixedFunction)
        #if (PWM_Steering_Resolution == 8)
            /* Set FIFO 0 to 1 byte register for period*/
            PWM_Steering_AUX_CONTROLDP0 |= (PWM_Steering_AUX_CTRL_FIFO0_CLR);
        #else /* (PWM_Steering_Resolution == 16)*/
            /* Set FIFO 0 to 1 byte register for period */
            PWM_Steering_AUX_CONTROLDP0 |= (PWM_Steering_AUX_CTRL_FIFO0_CLR);
            PWM_Steering_AUX_CONTROLDP1 |= (PWM_Steering_AUX_CTRL_FIFO0_CLR);
        #endif /* (PWM_Steering_Resolution == 8) */

        PWM_Steering_WriteCounter(PWM_Steering_INIT_PERIOD_VALUE);
    #endif /* (!PWM_Steering_UsingFixedFunction) */
        
    PWM_Steering_WritePeriod(PWM_Steering_INIT_PERIOD_VALUE);

        #if (PWM_Steering_UseOneCompareMode)
            PWM_Steering_WriteCompare(PWM_Steering_INIT_COMPARE_VALUE1);
        #else
            PWM_Steering_WriteCompare1(PWM_Steering_INIT_COMPARE_VALUE1);
            PWM_Steering_WriteCompare2(PWM_Steering_INIT_COMPARE_VALUE2);
        #endif /* (PWM_Steering_UseOneCompareMode) */
        
        #if (PWM_Steering_KillModeMinTime)
            PWM_Steering_WriteKillTime(PWM_Steering_MinimumKillTime);
        #endif /* (PWM_Steering_KillModeMinTime) */
        
        #if (PWM_Steering_DeadBandUsed)
            PWM_Steering_WriteDeadTime(PWM_Steering_INIT_DEAD_TIME);
        #endif /* (PWM_Steering_DeadBandUsed) */

    #if (PWM_Steering_UseStatus || PWM_Steering_UsingFixedFunction)
        PWM_Steering_SetInterruptMode(PWM_Steering_INIT_INTERRUPTS_MODE);
    #endif /* (PWM_Steering_UseStatus || PWM_Steering_UsingFixedFunction) */
        
    #if (PWM_Steering_UsingFixedFunction)
        /* Globally Enable the Fixed Function Block chosen */
        PWM_Steering_GLOBAL_ENABLE |= PWM_Steering_BLOCK_EN_MASK;
        /* Set the Interrupt source to come from the status register */
        PWM_Steering_CONTROL2 |= PWM_Steering_CTRL2_IRQ_SEL;
    #else
        #if(PWM_Steering_UseStatus)
            
            /* CyEnterCriticalRegion and CyExitCriticalRegion are used to mark following region critical*/
            /* Enter Critical Region*/
            PWM_Steering_interruptState = CyEnterCriticalSection();
            /* Use the interrupt output of the status register for IRQ output */
            PWM_Steering_STATUS_AUX_CTRL |= PWM_Steering_STATUS_ACTL_INT_EN_MASK;
            
             /* Exit Critical Region*/
            CyExitCriticalSection(PWM_Steering_interruptState);
            
            /* Clear the FIFO to enable the PWM_Steering_STATUS_FIFOFULL
                   bit to be set on FIFO full. */
            PWM_Steering_ClearFIFO();
        #endif /* (PWM_Steering_UseStatus) */
    #endif /* (PWM_Steering_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: PWM_Steering_Enable
********************************************************************************
*
* Summary: 
*  Enables the PWM block operation
*
* Parameters:  
*  void
*
* Return: 
*  void
*
* Side Effects: 
*  This works only if software enable mode is chosen
*
*******************************************************************************/
void PWM_Steering_Enable(void) 
{
    /* Globally Enable the Fixed Function Block chosen */
    #if (PWM_Steering_UsingFixedFunction)
        PWM_Steering_GLOBAL_ENABLE |= PWM_Steering_BLOCK_EN_MASK;
        PWM_Steering_GLOBAL_STBY_ENABLE |= PWM_Steering_BLOCK_STBY_EN_MASK;
    #endif /* (PWM_Steering_UsingFixedFunction) */
    
    /* Enable the PWM from the control register  */
    #if (PWM_Steering_UseControl || PWM_Steering_UsingFixedFunction)
        PWM_Steering_CONTROL |= PWM_Steering_CTRL_ENABLE;
    #endif /* (PWM_Steering_UseControl || PWM_Steering_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: PWM_Steering_Stop
********************************************************************************
*
* Summary:
*  The stop function halts the PWM, but does not change any modes or disable
*  interrupts.
*
* Parameters:  
*  void  
*
* Return: 
*  void
*
* Side Effects:
*  If the Enable mode is set to Hardware only then this function
*  has no effect on the operation of the PWM
*
*******************************************************************************/
void PWM_Steering_Stop(void) 
{
    #if (PWM_Steering_UseControl || PWM_Steering_UsingFixedFunction)
        PWM_Steering_CONTROL &= ~PWM_Steering_CTRL_ENABLE;
    #endif /* (PWM_Steering_UseControl || PWM_Steering_UsingFixedFunction) */
    
    /* Globally disable the Fixed Function Block chosen */
    #if (PWM_Steering_UsingFixedFunction)
        PWM_Steering_GLOBAL_ENABLE &= ~PWM_Steering_BLOCK_EN_MASK;
        PWM_Steering_GLOBAL_STBY_ENABLE &= ~PWM_Steering_BLOCK_STBY_EN_MASK;
    #endif /* (PWM_Steering_UsingFixedFunction) */
}


#if (PWM_Steering_UseOneCompareMode)
#if (PWM_Steering_CompareMode1SW)


/*******************************************************************************
* Function Name: PWM_Steering_SetCompareMode
********************************************************************************
* 
* Summary:
*  This function writes the Compare Mode for the pwm output when in Dither mode,
*  Center Align Mode or One Output Mode.
*
* Parameters:
*  comparemode:  The new compare mode for the PWM output. Use the compare types
*                defined in the H file as input arguments.
*
* Return:
*  void
*
*******************************************************************************/
void PWM_Steering_SetCompareMode(uint8 comparemode) 
{
    #if(PWM_Steering_UsingFixedFunction)
        #if(CY_PSOC5A)
            uint8 comparemodemasked = (comparemode << PWM_Steering_CTRL_CMPMODE1_SHIFT);
            PWM_Steering_CONTROL2 &= ~PWM_Steering_CTRL_CMPMODE1_MASK; /*Clear Existing Data */
            PWM_Steering_CONTROL2 |= comparemodemasked;  
        #endif /* (CY_PSOC5A) */
                
        #if(CY_PSOC3 || CY_PSOC5LP)
            uint8 comparemodemasked = (comparemode << PWM_Steering_CTRL_CMPMODE1_SHIFT);
            PWM_Steering_CONTROL3 &= ~PWM_Steering_CTRL_CMPMODE1_MASK; /*Clear Existing Data */
            PWM_Steering_CONTROL3 |= comparemodemasked;     
        #endif /* (CY_PSOC3 || CY_PSOC5LP) */
                
    #elif (PWM_Steering_UseControl)
        uint8 comparemode1masked = (comparemode << PWM_Steering_CTRL_CMPMODE1_SHIFT) & 
                                    PWM_Steering_CTRL_CMPMODE1_MASK;
        uint8 comparemode2masked = (comparemode << PWM_Steering_CTRL_CMPMODE2_SHIFT) & 
                                   PWM_Steering_CTRL_CMPMODE2_MASK;
        /*Clear existing mode */
        PWM_Steering_CONTROL &= ~(PWM_Steering_CTRL_CMPMODE1_MASK | PWM_Steering_CTRL_CMPMODE2_MASK); 
        PWM_Steering_CONTROL |= (comparemode1masked | comparemode2masked);
        
    #else
        uint8 temp = comparemode;
    #endif /* (PWM_Steering_UsingFixedFunction) */
}
#endif /* PWM_Steering_CompareMode1SW */

#else /* UseOneCompareMode */


#if (PWM_Steering_CompareMode1SW)


/*******************************************************************************
* Function Name: PWM_Steering_SetCompareMode1
********************************************************************************
* 
* Summary:
*  This function writes the Compare Mode for the pwm or pwm1 output
*
* Parameters:  
*  comparemode:  The new compare mode for the PWM output. Use the compare types
*                defined in the H file as input arguments.
*
* Return: 
*  void
*
*******************************************************************************/
void PWM_Steering_SetCompareMode1(uint8 comparemode) 
{
    uint8 comparemodemasked = (comparemode << PWM_Steering_CTRL_CMPMODE1_SHIFT) & 
                               PWM_Steering_CTRL_CMPMODE1_MASK;
    #if(PWM_Steering_UsingFixedFunction)
        #if(CY_PSOC5A)
            PWM_Steering_CONTROL2 &= PWM_Steering_CTRL_CMPMODE1_MASK; /*Clear existing mode */
            PWM_Steering_CONTROL2 |= comparemodemasked; 
        #endif /* (CY_PSOC5A) */
                
        #if(CY_PSOC3 || CY_PSOC5LP)
            PWM_Steering_CONTROL3 &= PWM_Steering_CTRL_CMPMODE1_MASK; /*Clear existing mode */
            PWM_Steering_CONTROL3 |= comparemodemasked; 
        #endif /* (CY_PSOC3 || CY_PSOC5LP) */
                
    #elif (PWM_Steering_UseControl)
        PWM_Steering_CONTROL &= PWM_Steering_CTRL_CMPMODE1_MASK; /*Clear existing mode */
        PWM_Steering_CONTROL |= comparemodemasked;
    #endif    /* (PWM_Steering_UsingFixedFunction) */
}
#endif /* PWM_Steering_CompareMode1SW */


#if (PWM_Steering_CompareMode2SW)


/*******************************************************************************
* Function Name: PWM_Steering_SetCompareMode2
********************************************************************************
* 
* Summary:
*  This function writes the Compare Mode for the pwm or pwm2 output
*
* Parameters:  
*  comparemode:  The new compare mode for the PWM output. Use the compare types
*                defined in the H file as input arguments.
*
* Return: 
*  void
*
*******************************************************************************/
void PWM_Steering_SetCompareMode2(uint8 comparemode) 
{
    #if(PWM_Steering_UsingFixedFunction)
        /* Do Nothing because there is no second Compare Mode Register in FF block */ 
    #elif (PWM_Steering_UseControl)
        uint8 comparemodemasked = (comparemode << PWM_Steering_CTRL_CMPMODE2_SHIFT) & 
                                             PWM_Steering_CTRL_CMPMODE2_MASK;
        PWM_Steering_CONTROL &= PWM_Steering_CTRL_CMPMODE2_MASK; /*Clear existing mode */
        PWM_Steering_CONTROL |= comparemodemasked;
    #endif /* (PWM_Steering_UsingFixedFunction) */
}
#endif /*PWM_Steering_CompareMode2SW */
#endif /* UseOneCompareMode */


#if (!PWM_Steering_UsingFixedFunction)


/*******************************************************************************
* Function Name: PWM_Steering_WriteCounter
********************************************************************************
* 
* Summary:
*  This function is used to change the counter value.
*
* Parameters:  
*  counter:  This value may be between 1 and (2^Resolution)-1.   
*
* Return: 
*  void
*
*******************************************************************************/
void PWM_Steering_WriteCounter(uint16 counter) \
                                   
{
    CY_SET_REG16(PWM_Steering_COUNTER_LSB_PTR, counter);
}

/*******************************************************************************
* Function Name: PWM_Steering_ReadCounter
********************************************************************************
* 
* Summary:
*  This function returns the current value of the counter.  It doesn't matter
*  if the counter is enabled or running.
*
* Parameters:  
*  void  
*
* Return: 
*  The current value of the counter.
*
*******************************************************************************/
uint16 PWM_Steering_ReadCounter(void) 
{
    /* Force capture by reading Accumulator */
    /* Must first do a software capture to be able to read the counter */
    /* It is up to the user code to make sure there isn't already captured data in the FIFO */
    CY_GET_REG8(PWM_Steering_COUNTERCAP_LSB_PTR);
    
    /* Read the data from the FIFO (or capture register for Fixed Function)*/
    return (CY_GET_REG16(PWM_Steering_CAPTURE_LSB_PTR));
}


#if (PWM_Steering_UseStatus)


/*******************************************************************************
* Function Name: PWM_Steering_ClearFIFO
********************************************************************************
* 
* Summary:
*  This function clears all capture data from the capture FIFO
*
* Parameters:  
*  void
*
* Return: 
*  void
*
*******************************************************************************/
void PWM_Steering_ClearFIFO(void) 
{
    while(PWM_Steering_ReadStatusRegister() & PWM_Steering_STATUS_FIFONEMPTY)
        PWM_Steering_ReadCapture();
}
#endif /* PWM_Steering_UseStatus */
#endif /* !PWM_Steering_UsingFixedFunction */


/*******************************************************************************
* Function Name: PWM_Steering_WritePeriod
********************************************************************************
* 
* Summary:
*  This function is used to change the period of the counter.  The new period 
*  will be loaded the next time terminal count is detected.
*
* Parameters:  
*  period:  Period value. May be between 1 and (2^Resolution)-1.  A value of 0 
*           will result in the counter remaining at zero.
*
* Return: 
*  void
*
*******************************************************************************/
void PWM_Steering_WritePeriod(uint16 period) 
{
    #if(PWM_Steering_UsingFixedFunction)
        CY_SET_REG16(PWM_Steering_PERIOD_LSB_PTR, (uint16)period);
    #else
        CY_SET_REG16(PWM_Steering_PERIOD_LSB_PTR, period);
    #endif /* (PWM_Steering_UsingFixedFunction) */
}


#if (PWM_Steering_UseOneCompareMode)


/*******************************************************************************
* Function Name: PWM_Steering_WriteCompare
********************************************************************************
* 
* Summary:
*  This funtion is used to change the compare1 value when the PWM is in Dither
*  mode. The compare output will reflect the new value on the next UDB clock. 
*  The compare output will be driven high when the present counter value is 
*  compared to the compare value based on the compare mode defined in 
*  Dither Mode.
*
* Parameters:  
*  compare:  New compare value.  
*
* Return: 
*  void
*
* Side Effects:
*  This function is only available if the PWM mode parameter is set to
*  Dither Mode, Center Aligned Mode or One Output Mode
*
*******************************************************************************/
void PWM_Steering_WriteCompare(uint16 compare) \
                                   
{
   CY_SET_REG16(PWM_Steering_COMPARE1_LSB_PTR, compare);
   #if (PWM_Steering_PWMMode == PWM_Steering__B_PWM__DITHER)
        CY_SET_REG16(PWM_Steering_COMPARE2_LSB_PTR, compare+1);
   #endif /* (PWM_Steering_PWMMode == PWM_Steering__B_PWM__DITHER) */
}


#else


/*******************************************************************************
* Function Name: PWM_Steering_WriteCompare1
********************************************************************************
* 
* Summary:
*  This funtion is used to change the compare1 value.  The compare output will 
*  reflect the new value on the next UDB clock.  The compare output will be 
*  driven high when the present counter value is less than or less than or 
*  equal to the compare register, depending on the mode.
*
* Parameters:  
*  compare:  New compare value.  
*
* Return: 
*  void
*
*******************************************************************************/
void PWM_Steering_WriteCompare1(uint16 compare) \
                                    
{
    #if(PWM_Steering_UsingFixedFunction)
        CY_SET_REG16(PWM_Steering_COMPARE1_LSB_PTR, (uint16)compare);
    #else
        CY_SET_REG16(PWM_Steering_COMPARE1_LSB_PTR, compare);
    #endif /* (PWM_Steering_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: PWM_Steering_WriteCompare2
********************************************************************************
* 
* Summary:
*  This funtion is used to change the compare value, for compare1 output.  
*  The compare output will reflect the new value on the next UDB clock.  
*  The compare output will be driven high when the present counter value is 
*  less than or less than or equal to the compare register, depending on the 
*  mode.
*
* Parameters:  
*  compare:  New compare value.  
*
* Return: 
*  void
*
*******************************************************************************/
void PWM_Steering_WriteCompare2(uint16 compare) \
                                    
{
    #if(PWM_Steering_UsingFixedFunction)
        CY_SET_REG16(PWM_Steering_COMPARE2_LSB_PTR, compare);
    #else
        CY_SET_REG16(PWM_Steering_COMPARE2_LSB_PTR, compare);
    #endif /* (PWM_Steering_UsingFixedFunction) */
}
#endif /* UseOneCompareMode */


#if (PWM_Steering_DeadBandUsed)


/*******************************************************************************
* Function Name: PWM_Steering_WriteDeadTime
********************************************************************************
* 
* Summary:
*  This function writes the dead-band counts to the corresponding register
*
* Parameters:  
*  deadtime:  Number of counts for dead time 
*
* Return: 
*  void
*
*******************************************************************************/
void PWM_Steering_WriteDeadTime(uint8 deadtime) 
{
    /* If using the Dead Band 1-255 mode then just write the register */
    #if(!PWM_Steering_DeadBand2_4)
        CY_SET_REG8(PWM_Steering_DEADBAND_COUNT_PTR, deadtime);
    #else
        /* Otherwise the data has to be masked and offset */        
        /* Clear existing data */
        PWM_Steering_DEADBAND_COUNT &= ~PWM_Steering_DEADBAND_COUNT_MASK; 
            /* Set new dead time */
        PWM_Steering_DEADBAND_COUNT |= (deadtime << PWM_Steering_DEADBAND_COUNT_SHIFT) & 
                                            PWM_Steering_DEADBAND_COUNT_MASK; 
    #endif /* (!PWM_Steering_DeadBand2_4) */
}


/*******************************************************************************
* Function Name: PWM_Steering_ReadDeadTime
********************************************************************************
* 
* Summary:
*  This function reads the dead-band counts from the corresponding register
*
* Parameters:  
*  void
*
* Return: 
*  Dead Band Counts
*
*******************************************************************************/
uint8 PWM_Steering_ReadDeadTime(void) 
{
    /* If using the Dead Band 1-255 mode then just read the register */
    #if(!PWM_Steering_DeadBand2_4)
        return (CY_GET_REG8(PWM_Steering_DEADBAND_COUNT_PTR));
    #else
        /* Otherwise the data has to be masked and offset */
        return ((PWM_Steering_DEADBAND_COUNT & PWM_Steering_DEADBAND_COUNT_MASK) >> 
                 PWM_Steering_DEADBAND_COUNT_SHIFT);
    #endif /* (!PWM_Steering_DeadBand2_4) */
}
#endif /* DeadBandUsed */


/* [] END OF FILE */
