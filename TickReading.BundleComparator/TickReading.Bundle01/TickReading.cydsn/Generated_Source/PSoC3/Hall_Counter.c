/*******************************************************************************
* File Name: Hall_Counter.c  
* Version 2.20
*
*  Description:
*     The Counter component consists of a 8, 16, 24 or 32-bit counter with
*     a selectable period between 2 and 2^Width - 1.  
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

uint8 Hall_Counter_initVar = 0u;


/*******************************************************************************
* Function Name: Hall_Counter_Init
********************************************************************************
* Summary:
*     Initialize to the schematic state
* 
* Parameters:  
*  void  
*
* Return: 
*  void
*
*******************************************************************************/
void Hall_Counter_Init(void) 
{
        #if (!Hall_Counter_UsingFixedFunction && !Hall_Counter_ControlRegRemoved)
            uint8 ctrl;
        #endif /* (!Hall_Counter_UsingFixedFunction && !Hall_Counter_ControlRegRemoved) */
        
        #if(!Hall_Counter_UsingFixedFunction) 
            /* Interrupt State Backup for Critical Region*/
            uint8 Hall_Counter_interruptState;
        #endif /* (!Hall_Counter_UsingFixedFunction) */
        
        #if (Hall_Counter_UsingFixedFunction)
            /* Clear all bits but the enable bit (if it's already set for Timer operation */
            Hall_Counter_CONTROL &= Hall_Counter_CTRL_ENABLE;
            
            /* Clear the mode bits for continuous run mode */
            #if (CY_PSOC5A)
                Hall_Counter_CONTROL2 &= ~Hall_Counter_CTRL_MODE_MASK;
            #endif /* (CY_PSOC5A) */
            #if (CY_PSOC3 || CY_PSOC5LP)
                Hall_Counter_CONTROL3 &= ~Hall_Counter_CTRL_MODE_MASK;                
            #endif /* (CY_PSOC3 || CY_PSOC5LP) */
            /* Check if One Shot mode is enabled i.e. RunMode !=0*/
            #if (Hall_Counter_RunModeUsed != 0x0u)
                /* Set 3rd bit of Control register to enable one shot mode */
                Hall_Counter_CONTROL |= Hall_Counter_ONESHOT;
            #endif /* (Hall_Counter_RunModeUsed != 0x0u) */
            
            /* Set the IRQ to use the status register interrupts */
            Hall_Counter_CONTROL2 |= Hall_Counter_CTRL2_IRQ_SEL;
            
            /* Clear and Set SYNCTC and SYNCCMP bits of RT1 register */
            Hall_Counter_RT1 &= ~Hall_Counter_RT1_MASK;
            Hall_Counter_RT1 |= Hall_Counter_SYNC;     
                    
            /*Enable DSI Sync all all inputs of the Timer*/
            Hall_Counter_RT1 &= ~(Hall_Counter_SYNCDSI_MASK);
            Hall_Counter_RT1 |= Hall_Counter_SYNCDSI_EN;

        #else
            #if(!Hall_Counter_ControlRegRemoved)
            /* Set the default compare mode defined in the parameter */
            ctrl = Hall_Counter_CONTROL & ~Hall_Counter_CTRL_CMPMODE_MASK;
            Hall_Counter_CONTROL = ctrl | Hall_Counter_DEFAULT_COMPARE_MODE;
            
            /* Set the default capture mode defined in the parameter */
            ctrl = Hall_Counter_CONTROL & ~Hall_Counter_CTRL_CAPMODE_MASK;
            Hall_Counter_CONTROL = ctrl | Hall_Counter_DEFAULT_CAPTURE_MODE;
            #endif /* (!Hall_Counter_ControlRegRemoved) */
        #endif /* (Hall_Counter_UsingFixedFunction) */
        
        /* Clear all data in the FIFO's */
        #if (!Hall_Counter_UsingFixedFunction)
            Hall_Counter_ClearFIFO();
        #endif /* (!Hall_Counter_UsingFixedFunction) */
        
        /* Set Initial values from Configuration */
        Hall_Counter_WritePeriod(Hall_Counter_INIT_PERIOD_VALUE);
        #if (!(Hall_Counter_UsingFixedFunction && (CY_PSOC5A)))
            Hall_Counter_WriteCounter(Hall_Counter_INIT_COUNTER_VALUE);
        #endif /* (!(Hall_Counter_UsingFixedFunction && (CY_PSOC5A))) */
        Hall_Counter_SetInterruptMode(Hall_Counter_INIT_INTERRUPTS_MASK);
        
        #if (!Hall_Counter_UsingFixedFunction)
            /* Read the status register to clear the unwanted interrupts */
            Hall_Counter_ReadStatusRegister();
            /* Set the compare value (only available to non-fixed function implementation */
            Hall_Counter_WriteCompare(Hall_Counter_INIT_COMPARE_VALUE);
            /* Use the interrupt output of the status register for IRQ output */
            
            /* CyEnterCriticalRegion and CyExitCriticalRegion are used to mark following region critical*/
            /* Enter Critical Region*/
            Hall_Counter_interruptState = CyEnterCriticalSection();
            
            Hall_Counter_STATUS_AUX_CTRL |= Hall_Counter_STATUS_ACTL_INT_EN_MASK;
            
            /* Exit Critical Region*/
            CyExitCriticalSection(Hall_Counter_interruptState);
            
        #endif /* (!Hall_Counter_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: Hall_Counter_Enable
********************************************************************************
* Summary:
*     Enable the Counter
* 
* Parameters:  
*  void  
*
* Return: 
*  void
*
* Side Effects: 
*   If the Enable mode is set to Hardware only then this function has no effect 
*   on the operation of the counter.
*
*******************************************************************************/
void Hall_Counter_Enable(void) 
{
    /* Globally Enable the Fixed Function Block chosen */
    #if (Hall_Counter_UsingFixedFunction)
        Hall_Counter_GLOBAL_ENABLE |= Hall_Counter_BLOCK_EN_MASK;
        Hall_Counter_GLOBAL_STBY_ENABLE |= Hall_Counter_BLOCK_STBY_EN_MASK;
    #endif /* (Hall_Counter_UsingFixedFunction) */  
        
    /* Enable the counter from the control register  */
    /* If Fixed Function then make sure Mode is set correctly */
    /* else make sure reset is clear */
    #if(!Hall_Counter_ControlRegRemoved || Hall_Counter_UsingFixedFunction)
        Hall_Counter_CONTROL |= Hall_Counter_CTRL_ENABLE;                
    #endif /* (!Hall_Counter_ControlRegRemoved || Hall_Counter_UsingFixedFunction) */
    
}


/*******************************************************************************
* Function Name: Hall_Counter_Start
********************************************************************************
* Summary:
*  Enables the counter for operation 
*
* Parameters:  
*  void  
*
* Return: 
*  void
*
* Global variables:
*  Hall_Counter_initVar: Is modified when this function is called for the  
*   first time. Is used to ensure that initialization happens only once.
*
*******************************************************************************/
void Hall_Counter_Start(void) 
{
    if(Hall_Counter_initVar == 0u)
    {
        Hall_Counter_Init();
        
        Hall_Counter_initVar = 1u; /* Clear this bit for Initialization */        
    }
    
    /* Enable the Counter */
    Hall_Counter_Enable();        
}


/*******************************************************************************
* Function Name: Hall_Counter_Stop
********************************************************************************
* Summary:
* Halts the counter, but does not change any modes or disable interrupts.
*
* Parameters:  
*  void  
*
* Return: 
*  void
*
* Side Effects: If the Enable mode is set to Hardware only then this function
*               has no effect on the operation of the counter.
*
*******************************************************************************/
void Hall_Counter_Stop(void) 
{
    /* Disable Counter */
    #if(!Hall_Counter_ControlRegRemoved || Hall_Counter_UsingFixedFunction)
        Hall_Counter_CONTROL &= ~Hall_Counter_CTRL_ENABLE;        
    #endif /* (!Hall_Counter_ControlRegRemoved || Hall_Counter_UsingFixedFunction) */
    
    /* Globally disable the Fixed Function Block chosen */
    #if (Hall_Counter_UsingFixedFunction)
        Hall_Counter_GLOBAL_ENABLE &= ~Hall_Counter_BLOCK_EN_MASK;
        Hall_Counter_GLOBAL_STBY_ENABLE &= ~Hall_Counter_BLOCK_STBY_EN_MASK;
    #endif /* (Hall_Counter_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: Hall_Counter_SetInterruptMode
********************************************************************************
* Summary:
* Configures which interrupt sources are enabled to generate the final interrupt
*
* Parameters:  
*  InterruptsMask: This parameter is an or'd collection of the status bits
*                   which will be allowed to generate the counters interrupt.   
*
* Return: 
*  void
*
*******************************************************************************/
void Hall_Counter_SetInterruptMode(uint8 interruptsMask) 
{
    Hall_Counter_STATUS_MASK = interruptsMask;
}


/*******************************************************************************
* Function Name: Hall_Counter_ReadStatusRegister
********************************************************************************
* Summary:
*   Reads the status register and returns it's state. This function should use
*       defined types for the bit-field information as the bits in this
*       register may be permuteable.
*
* Parameters:  
*  void
*
* Return: 
*  (uint8) The contents of the status register
*
* Side Effects:
*   Status register bits may be clear on read. 
*
*******************************************************************************/
uint8   Hall_Counter_ReadStatusRegister(void) 
{
    return Hall_Counter_STATUS;
}


#if(!Hall_Counter_ControlRegRemoved)
/*******************************************************************************
* Function Name: Hall_Counter_ReadControlRegister
********************************************************************************
* Summary:
*   Reads the control register and returns it's state. This function should use
*       defined types for the bit-field information as the bits in this
*       register may be permuteable.
*
* Parameters:  
*  void
*
* Return: 
*  (uint8) The contents of the control register
*
*******************************************************************************/
uint8   Hall_Counter_ReadControlRegister(void) 
{
    return Hall_Counter_CONTROL;
}


/*******************************************************************************
* Function Name: Hall_Counter_WriteControlRegister
********************************************************************************
* Summary:
*   Sets the bit-field of the control register.  This function should use
*       defined types for the bit-field information as the bits in this
*       register may be permuteable.
*
* Parameters:  
*  void
*
* Return: 
*  (uint8) The contents of the control register
*
*******************************************************************************/
void    Hall_Counter_WriteControlRegister(uint8 control) 
{
    Hall_Counter_CONTROL = control;
}

#endif  /* (!Hall_Counter_ControlRegRemoved) */


#if (!(Hall_Counter_UsingFixedFunction && (CY_PSOC5A)))
/*******************************************************************************
* Function Name: Hall_Counter_WriteCounter
********************************************************************************
* Summary:
*   This funtion is used to set the counter to a specific value
*
* Parameters:  
*  counter:  New counter value. 
*
* Return: 
*  void 
*
*******************************************************************************/
void Hall_Counter_WriteCounter(uint32 counter) \
                                   
{
    #if(Hall_Counter_UsingFixedFunction)
        /* assert if block is already enabled */
        CYASSERT (!(Hall_Counter_GLOBAL_ENABLE & Hall_Counter_BLOCK_EN_MASK));
        /* If block is disabled, enable it and then write the counter */
        Hall_Counter_GLOBAL_ENABLE |= Hall_Counter_BLOCK_EN_MASK;
        CY_SET_REG16(Hall_Counter_COUNTER_LSB_PTR, (uint16)counter);
        Hall_Counter_GLOBAL_ENABLE &= ~Hall_Counter_BLOCK_EN_MASK;
    #else
        CY_SET_REG24(Hall_Counter_COUNTER_LSB_PTR, counter);
    #endif /* (Hall_Counter_UsingFixedFunction) */
}
#endif /* (!(Hall_Counter_UsingFixedFunction && (CY_PSOC5A))) */


/*******************************************************************************
* Function Name: Hall_Counter_ReadCounter
********************************************************************************
* Summary:
* Returns the current value of the counter.  It doesn't matter
* if the counter is enabled or running.
*
* Parameters:  
*  void:  
*
* Return: 
*  (uint32) The present value of the counter.
*
*******************************************************************************/
uint32 Hall_Counter_ReadCounter(void) 
{
    /* Force capture by reading Accumulator */
    /* Must first do a software capture to be able to read the counter */
    /* It is up to the user code to make sure there isn't already captured data in the FIFO */
    CY_GET_REG8(Hall_Counter_COUNTER_LSB_PTR);
    
    /* Read the data from the FIFO (or capture register for Fixed Function)*/
    return (CY_GET_REG24(Hall_Counter_STATICCOUNT_LSB_PTR));
}


/*******************************************************************************
* Function Name: Hall_Counter_ReadCapture
********************************************************************************
* Summary:
*   This function returns the last value captured.
*
* Parameters:  
*  void
*
* Return: 
*  (uint32) Present Capture value.
*
*******************************************************************************/
uint32 Hall_Counter_ReadCapture(void) 
{
   return ( CY_GET_REG24(Hall_Counter_STATICCOUNT_LSB_PTR) );  
}


/*******************************************************************************
* Function Name: Hall_Counter_WritePeriod
********************************************************************************
* Summary:
* Changes the period of the counter.  The new period 
* will be loaded the next time terminal count is detected.
*
* Parameters:  
*  period: (uint32) A value of 0 will result in
*         the counter remaining at zero.  
*
* Return: 
*  void
*
*******************************************************************************/
void Hall_Counter_WritePeriod(uint32 period) 
{
    #if(Hall_Counter_UsingFixedFunction)
        CY_SET_REG16(Hall_Counter_PERIOD_LSB_PTR,(uint16)period);
    #else
        CY_SET_REG24(Hall_Counter_PERIOD_LSB_PTR,period);
    #endif /* (Hall_Counter_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: Hall_Counter_ReadPeriod
********************************************************************************
* Summary:
* Reads the current period value without affecting counter operation.
*
* Parameters:  
*  void:  
*
* Return: 
*  (uint32) Present period value.
*
*******************************************************************************/
uint32 Hall_Counter_ReadPeriod(void) 
{
   return ( CY_GET_REG24(Hall_Counter_PERIOD_LSB_PTR));
}


#if (!Hall_Counter_UsingFixedFunction)
/*******************************************************************************
* Function Name: Hall_Counter_WriteCompare
********************************************************************************
* Summary:
* Changes the compare value.  The compare output will 
* reflect the new value on the next UDB clock.  The compare output will be 
* driven high when the present counter value compares true based on the 
* configured compare mode setting. 
*
* Parameters:  
*  Compare:  New compare value. 
*
* Return: 
*  void
*
*******************************************************************************/
void Hall_Counter_WriteCompare(uint32 compare) \
                                   
{
    #if(Hall_Counter_UsingFixedFunction)
        CY_SET_REG16(Hall_Counter_COMPARE_LSB_PTR,(uint16)compare);
    #else
        CY_SET_REG24(Hall_Counter_COMPARE_LSB_PTR,compare);
    #endif /* (Hall_Counter_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: Hall_Counter_ReadCompare
********************************************************************************
* Summary:
* Returns the compare value.
*
* Parameters:  
*  void:
*
* Return: 
*  (uint32) Present compare value.
*
*******************************************************************************/
uint32 Hall_Counter_ReadCompare(void) 
{
   return ( CY_GET_REG24(Hall_Counter_COMPARE_LSB_PTR));
}


#if (Hall_Counter_COMPARE_MODE_SOFTWARE)
/*******************************************************************************
* Function Name: Hall_Counter_SetCompareMode
********************************************************************************
* Summary:
*  Sets the software controlled Compare Mode.
*
* Parameters:
*  compareMode:  Compare Mode Enumerated Type.
*
* Return:
*  void
*
*******************************************************************************/
void Hall_Counter_SetCompareMode(uint8 compareMode) 
{
    /* Clear the compare mode bits in the control register */
    Hall_Counter_CONTROL &= ~Hall_Counter_CTRL_CMPMODE_MASK;
    
    /* Write the new setting */
    Hall_Counter_CONTROL |= (compareMode << Hall_Counter_CTRL_CMPMODE0_SHIFT);
}
#endif  /* (Hall_Counter_COMPARE_MODE_SOFTWARE) */


#if (Hall_Counter_CAPTURE_MODE_SOFTWARE)
/*******************************************************************************
* Function Name: Hall_Counter_SetCaptureMode
********************************************************************************
* Summary:
*  Sets the software controlled Capture Mode.
*
* Parameters:
*  captureMode:  Capture Mode Enumerated Type.
*
* Return:
*  void
*
*******************************************************************************/
void Hall_Counter_SetCaptureMode(uint8 captureMode) 
{
    /* Clear the capture mode bits in the control register */
    Hall_Counter_CONTROL &= ~Hall_Counter_CTRL_CAPMODE_MASK;
    
    /* Write the new setting */
    Hall_Counter_CONTROL |= (captureMode << Hall_Counter_CTRL_CAPMODE0_SHIFT);
}
#endif  /* (Hall_Counter_CAPTURE_MODE_SOFTWARE) */


/*******************************************************************************
* Function Name: Hall_Counter_ClearFIFO
********************************************************************************
* Summary:
*   This function clears all capture data from the capture FIFO
*
* Parameters:  
*  void:
*
* Return: 
*  None
*
*******************************************************************************/
void Hall_Counter_ClearFIFO(void) 
{

    while(Hall_Counter_ReadStatusRegister() & Hall_Counter_STATUS_FIFONEMP)
    {
        Hall_Counter_ReadCapture();
    }

}
#endif  /* (!Hall_Counter_UsingFixedFunction) */


/* [] END OF FILE */

