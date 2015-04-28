/*******************************************************************************
* File Name: ISR_Hall.c  
* Version 1.60
*
*  Description:
*   API for controlling the state of an interrupt.
*
*
*  Note:
*
********************************************************************************
* Copyright 2008-2010, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
********************************************************************************/


#include <CYDEVICE.H>
#include <CYDEVICE_TRM.H>
#include <CYLIB.H>
#include <ISR_Hall.H>


/*******************************************************************************
*  Place your includes, defines and code here 
********************************************************************************/
/* `#START ISR_Hall_intc` */

/* `#END` */


/*******************************************************************************
* Function Name: ISR_Hall_Start
********************************************************************************
* Summary:
*  Set up the interrupt and enable it.
*
* Parameters:  
*   void.
*
*
* Return:
*   void.
*
*******************************************************************************/
void ISR_Hall_Start(void)
{
    /* For all we know the interrupt is active. */
    ISR_Hall_Disable();

    /* Set the ISR to point to the ISR_Hall Interrupt. */
    ISR_Hall_SetVector(ISR_Hall_Interrupt);

    /* Set the priority. */
    ISR_Hall_SetPriority(ISR_Hall_INTC_PRIOR_NUMBER);

    /* Enable it. */
    ISR_Hall_Enable();
}

/*******************************************************************************
* Function Name: ISR_Hall_StartEx
********************************************************************************
* Summary:
*  Set up the interrupt and enable it.
*
* Parameters:  
*   address: Address of the ISR to set in the interrupt vector table.
*
*
* Return:
*   void.
*
*******************************************************************************/
void ISR_Hall_StartEx(cyisraddress address)
{
    /* For all we know the interrupt is active. */
    ISR_Hall_Disable();

    /* Set the ISR to point to the ISR_Hall Interrupt. */
    ISR_Hall_SetVector(address);

    /* Set the priority. */
    ISR_Hall_SetPriority(ISR_Hall_INTC_PRIOR_NUMBER);

    /* Enable it. */
    ISR_Hall_Enable();
}

/*******************************************************************************
* Function Name: ISR_Hall_Stop
********************************************************************************
* Summary:
*   Disables and removes the interrupt.
*
* Parameters:  
*
*
* Return:
*   void.
*
*******************************************************************************/
void ISR_Hall_Stop(void) 
{
    /* Disable this interrupt. */
    ISR_Hall_Disable();
}

/*******************************************************************************
* Function Name: ISR_Hall_Interrupt
********************************************************************************
* Summary:
*   The default Interrupt Service Routine for ISR_Hall.
*
*   Add custom code between the coments to keep the next version of this file
*   from over writting your code.
*
*
*
* Parameters:  
*
*
* Return:
*   void.
*
*******************************************************************************/
CY_ISR(ISR_Hall_Interrupt)
{
    /*  Place your Interrupt code here. */
    /* `#START ISR_Hall_Interrupt` */

    /* `#END` */

    /* PSoC3 ES1, ES2 RTC ISR PATCH  */ 
    #if(CYDEV_CHIP_FAMILY_USED == CYDEV_CHIP_FAMILY_PSOC3)
        #if((CYDEV_CHIP_REVISION_USED <= CYDEV_CHIP_REVISION_3A_ES2) && (ISR_Hall__ES2_PATCH ))      
            ISR_Hall_ISR_PATCH();
        #endif
    #endif
}

/*******************************************************************************
* Function Name: ISR_Hall_SetVector
********************************************************************************
* Summary:
*   Change the ISR vector for the Interrupt. Note calling ISR_Hall_Start
*   will override any effect this method would have had. To set the vector before
*   the component has been started use ISR_Hall_StartEx instead.
*
*
* Parameters:
*   address: Address of the ISR to set in the interrupt vector table.
*
*
* Return:
*   void.
*
*
*******************************************************************************/
void ISR_Hall_SetVector(cyisraddress address) 
{
    CY_SET_REG16(ISR_Hall_INTC_VECTOR, (uint16) address);
}

/*******************************************************************************
* Function Name: ISR_Hall_GetVector
********************************************************************************
* Summary:
*   Gets the "address" of the current ISR vector for the Interrupt.
*
*
* Parameters:
*   void.
*
*
* Return:
*   Address of the ISR in the interrupt vector table.
*
*
*******************************************************************************/
cyisraddress ISR_Hall_GetVector(void) 
{
    return (cyisraddress) CY_GET_REG16(ISR_Hall_INTC_VECTOR);
}

/*******************************************************************************
* Function Name: ISR_Hall_SetPriority
********************************************************************************
* Summary:
*   Sets the Priority of the Interrupt. Note calling ISR_Hall_Start
*   or ISR_Hall_StartEx will override any effect this method would have had. 
*	This method should only be called after ISR_Hall_Start or 
*	ISR_Hall_StartEx has been called. To set the initial
*	priority for the component use the cydwr file in the tool.
*
*
* Parameters:
*   priority: Priority of the interrupt. 0 - 7, 0 being the highest.
*
*
* Return:
*   void.
*
*
*******************************************************************************/
void ISR_Hall_SetPriority(uint8 priority) 
{
    *ISR_Hall_INTC_PRIOR = priority << 5;
}

/*******************************************************************************
* Function Name: ISR_Hall_GetPriority
********************************************************************************
* Summary:
*   Gets the Priority of the Interrupt.
*
*
* Parameters:
*   void.
*
*
* Return:
*   Priority of the interrupt. 0 - 7, 0 being the highest.
*
*
*******************************************************************************/
uint8 ISR_Hall_GetPriority(void) 
{
    uint8 priority;


    priority = *ISR_Hall_INTC_PRIOR >> 5;

    return priority;
}

/*******************************************************************************
* Function Name: ISR_Hall_Enable
********************************************************************************
* Summary:
*   Enables the interrupt.
*
*
* Parameters:
*   void.
*
*
* Return:
*   void.
*
*
*******************************************************************************/
void ISR_Hall_Enable(void) 
{
    /* Enable the general interrupt. */
    *ISR_Hall_INTC_SET_EN = ISR_Hall__INTC_MASK;
}

/*******************************************************************************
* Function Name: ISR_Hall_GetState
********************************************************************************
* Summary:
*   Gets the state (enabled, disabled) of the Interrupt.
*
*
* Parameters:
*   void.
*
*
* Return:
*   1 if enabled, 0 if disabled.
*
*
*******************************************************************************/
uint8 ISR_Hall_GetState(void) 
{
    /* Get the state of the general interrupt. */
    return (*ISR_Hall_INTC_SET_EN & ISR_Hall__INTC_MASK) ? 1:0;
}

/*******************************************************************************
* Function Name: ISR_Hall_Disable
********************************************************************************
* Summary:
*   Disables the Interrupt.
*
*
* Parameters:
*   void.
*
*
* Return:
*   void.
*
*
*******************************************************************************/
void ISR_Hall_Disable(void) 
{
    /* Disable the general interrupt. */
    *ISR_Hall_INTC_CLR_EN = ISR_Hall__INTC_MASK;
}

/*******************************************************************************
* Function Name: ISR_Hall_SetPending
********************************************************************************
* Summary:
*   Causes the Interrupt to enter the pending state, a software method of
*   generating the interrupt.
*
*
* Parameters:
*   void.
*
*
* Return:
*   void.
*
*
*******************************************************************************/
void ISR_Hall_SetPending(void) 
{
    *ISR_Hall_INTC_SET_PD = ISR_Hall__INTC_MASK;
}

/*******************************************************************************
* Function Name: ISR_Hall_ClearPending
********************************************************************************
* Summary:
*   Clears a pending interrupt.
*
* Parameters:
*   void.
*
*
* Return:
*   void.
*
*
*******************************************************************************/
void ISR_Hall_ClearPending(void) 
{
    *ISR_Hall_INTC_CLR_PD = ISR_Hall__INTC_MASK;
}
