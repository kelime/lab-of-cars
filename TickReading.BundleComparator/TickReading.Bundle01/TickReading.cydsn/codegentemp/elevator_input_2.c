/*******************************************************************************
* File Name: elevator_input_2.c  
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
#include "elevator_input_2.h"


/*******************************************************************************
* Function Name: elevator_input_2_Write
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
void elevator_input_2_Write(uint8 value) 
{
    uint8 staticBits = elevator_input_2_DR & ~elevator_input_2_MASK;
    elevator_input_2_DR = staticBits | ((value << elevator_input_2_SHIFT) & elevator_input_2_MASK);
}


/*******************************************************************************
* Function Name: elevator_input_2_SetDriveMode
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
void elevator_input_2_SetDriveMode(uint8 mode) 
{
	CyPins_SetPinDriveMode(elevator_input_2_0, mode);
}


/*******************************************************************************
* Function Name: elevator_input_2_Read
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
*  Macro elevator_input_2_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 elevator_input_2_Read(void) 
{
    return (elevator_input_2_PS & elevator_input_2_MASK) >> elevator_input_2_SHIFT;
}


/*******************************************************************************
* Function Name: elevator_input_2_ReadDataReg
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
uint8 elevator_input_2_ReadDataReg(void) 
{
    return (elevator_input_2_DR & elevator_input_2_MASK) >> elevator_input_2_SHIFT;
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(elevator_input_2_INTSTAT) 

    /*******************************************************************************
    * Function Name: elevator_input_2_ClearInterrupt
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
    uint8 elevator_input_2_ClearInterrupt(void) 
    {
        return (elevator_input_2_INTSTAT & elevator_input_2_MASK) >> elevator_input_2_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 


/* [] END OF FILE */ 
