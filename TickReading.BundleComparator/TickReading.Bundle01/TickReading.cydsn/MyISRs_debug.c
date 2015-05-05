/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/
/* ============*/
// Constants
#include <cylib.h>
#include "MyISRs.h"

uint8	ConversionDone =0;      //  Data ready flag

//__________________________________________________________________________
CY_ISR(ConvDone)		        // Interrupt-Service-Routine definition
{
	ConversionDone =1;		    // indicate, Data ready
    CyWdtClear();               // reset the watchdog timer
}

/* [] END OF FILE */

/*******************************************************************************
* File Name: ConvDone.c  
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
//#include <ConvDone.H>


/*******************************************************************************
*  Place your includes, defines and code here 
********************************************************************************/
/* `#START ConvDone_intc` */

/* `#END` */


/*******************************************************************************
* Function Name: ConvDone_Start
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
void ConvDone_Start(void)
{
    /* For all we know the interrupt is active. */
    ConvDone_Disable();

    /* Set the ISR to point to the ConvDone Interrupt. */
    ConvDone_SetVector(ConvDone_Interrupt);

    /* Set the priority. */
    ConvDone_SetPriority(ISR_ConvDone_INTC_PRIOR_NUMBER);

    /* Enable it. */
    ConvDone_Enable();
}

/*******************************************************************************
* Function Name: ConvDone_StartEx
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
void ConvDone_StartEx(cyisraddress address)
{
    /* For all we know the interrupt is active. */
    ConvDone_Disable();

    /* Set the ISR to point to the ConvDone Interrupt. */
    ConvDone_SetVector(address);

    /* Set the priority. */
    ConvDone_SetPriority(ConvDone_INTC_PRIOR_NUMBER);

    /* Enable it. */
    ConvDone_Enable();
}

/*******************************************************************************
* Function Name: ConvDone_Stop
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
void ConvDone_Stop(void) 
{
    /* Disable this interrupt. */
    ConvDone_Disable();
}

/*******************************************************************************
* Function Name: ConvDone_Interrupt
********************************************************************************
* Summary:
*   The default Interrupt Service Routine for ConvDone.
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
CY_ISR(ConvDone_Interrupt)
{
    /*  Place your Interrupt code here. */
    /* `#START ConvDone_Interrupt` */

    /* `#END` */

    /* PSoC3 ES1, ES2 RTC ISR PATCH  */ 
    #if(CYDEV_CHIP_FAMILY_USED == CYDEV_CHIP_FAMILY_PSOC3)
        #if((CYDEV_CHIP_REVISION_USED <= CYDEV_CHIP_REVISION_3A_ES2) && (ConvDone__ES2_PATCH ))      
            ConvDone_ISR_PATCH();
        #endif
    #endif
}

/*******************************************************************************
* Function Name: ConvDone_SetVector
********************************************************************************
* Summary:
*   Change the ISR vector for the Interrupt. Note calling ConvDone_Start
*   will override any effect this method would have had. To set the vector before
*   the component has been started use ConvDone_StartEx instead.
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
void ConvDone_SetVector(cyisraddress address) 
{
    CY_SET_REG16(ConvDone_INTC_VECTOR, (uint16) address);
}

/*******************************************************************************
* Function Name: ConvDone_GetVector
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
cyisraddress ConvDone_GetVector(void) 
{
    return (cyisraddress) CY_GET_REG16(ConvDone_INTC_VECTOR);
}

/*******************************************************************************
* Function Name: ConvDone_SetPriority
********************************************************************************
* Summary:
*   Sets the Priority of the Interrupt. Note calling ConvDone_Start
*   or ConvDone_StartEx will override any effect this method would have had. 
*	This method should only be called after ConvDone_Start or 
*	ConvDone_StartEx has been called. To set the initial
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
void ConvDone_SetPriority(uint8 priority) 
{
    *ConvDone_INTC_PRIOR = priority << 5;
}

/*******************************************************************************
* Function Name: ConvDone_GetPriority
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
uint8 ConvDone_GetPriority(void) 
{
    uint8 priority;


    priority = *ConvDone_INTC_PRIOR >> 5;

    return priority;
}

/*******************************************************************************
* Function Name: ConvDone_Enable
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
void ConvDone_Enable(void) 
{
    /* Enable the general interrupt. */
    *ConvDone_INTC_SET_EN = ConvDone__INTC_MASK;
}

/*******************************************************************************
* Function Name: ConvDone_GetState
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
uint8 ConvDone_GetState(void) 
{
    /* Get the state of the general interrupt. */
    return (*ConvDone_INTC_SET_EN & ConvDone__INTC_MASK) ? 1:0;
}

/*******************************************************************************
* Function Name: ConvDone_Disable
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
void ConvDone_Disable(void) 
{
    /* Disable the general interrupt. */
    *ConvDone_INTC_CLR_EN = ConvDone__INTC_MASK;
}

/*******************************************************************************
* Function Name: ConvDone_SetPending
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
void ConvDone_SetPending(void) 
{
    *ConvDone_INTC_SET_PD = ConvDone__INTC_MASK;
}

/*******************************************************************************
* Function Name: ConvDone_ClearPending
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
void ConvDone_ClearPending(void) 
{
    *ConvDone_INTC_CLR_PD = ConvDone__INTC_MASK;
}
