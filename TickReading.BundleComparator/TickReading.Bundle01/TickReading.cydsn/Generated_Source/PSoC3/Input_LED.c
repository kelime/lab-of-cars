/*******************************************************************************
* File Name: Input_LED.c  
* Version 1.70
*
* Description:
*  This file contains API to enable firmware control of a Pins component.
*
* Note:
*
********************************************************************************
* Copyright 2008-2010, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
********************************************************************************/

#include "cytypes.h"
#include "Input_LED.h"


/*******************************************************************************
* Function Name: Input_LED_Write
********************************************************************************
* Summary:
*  Assign a new value to the digital port's data output register.  
*
* Parameters:  
*  prtValue:  The value to be assigned to the Digital Port. 
*
* Return: 
*  void 
*  
*******************************************************************************/
void Input_LED_Write(uint8 value) 
{
    uint8 staticBits = Input_LED_DR & ~Input_LED_MASK;
    Input_LED_DR = staticBits | ((value << Input_LED_SHIFT) & Input_LED_MASK);
}


/*******************************************************************************
* Function Name: Input_LED_SetDriveMode
********************************************************************************
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to this drive mode.
*
* Return: 
*  void
*
*******************************************************************************/
void Input_LED_SetDriveMode(uint8 mode) 
{
	CyPins_SetPinDriveMode(Input_LED_0, mode);
}


/*******************************************************************************
* Function Name: Input_LED_Read
********************************************************************************
* Summary:
*  Read the current value on the pins of the Digital Port in right justified 
*  form.
*
* Parameters:  
*  void 
*
* Return: 
*  Returns the current value of the Digital Port as a right justified number
*  
* Note:
*  Macro Input_LED_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 Input_LED_Read(void) 
{
    return (Input_LED_PS & Input_LED_MASK) >> Input_LED_SHIFT;
}


/*******************************************************************************
* Function Name: Input_LED_ReadDataReg
********************************************************************************
* Summary:
*  Read the current value assigned to a Digital Port's data output register
*
* Parameters:  
*  void 
*
* Return: 
*  Returns the current value assigned to the Digital Port's data output register
*  
*******************************************************************************/
uint8 Input_LED_ReadDataReg(void) 
{
    return (Input_LED_DR & Input_LED_MASK) >> Input_LED_SHIFT;
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(Input_LED_INTSTAT) 

    /*******************************************************************************
    * Function Name: Input_LED_ClearInterrupt
    ********************************************************************************
    * Summary:
    *  Clears any active interrupts attached to port and returns the value of the 
    *  interrupt status register.
    *
    * Parameters:  
    *  void 
    *
    * Return: 
    *  Returns the value of the interrupt status register
    *  
    *******************************************************************************/
    uint8 Input_LED_ClearInterrupt(void) 
    {
        return (Input_LED_INTSTAT & Input_LED_MASK) >> Input_LED_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 


/* [] END OF FILE */ 
