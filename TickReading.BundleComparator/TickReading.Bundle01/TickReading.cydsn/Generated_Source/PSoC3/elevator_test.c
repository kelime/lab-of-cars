/*******************************************************************************
* File Name: elevator_test.c  
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
#include "elevator_test.h"


/*******************************************************************************
* Function Name: elevator_test_Write
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
void elevator_test_Write(uint8 value) 
{
    uint8 staticBits = elevator_test_DR & ~elevator_test_MASK;
    elevator_test_DR = staticBits | ((value << elevator_test_SHIFT) & elevator_test_MASK);
}


/*******************************************************************************
* Function Name: elevator_test_SetDriveMode
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
void elevator_test_SetDriveMode(uint8 mode) 
{
	CyPins_SetPinDriveMode(elevator_test_0, mode);
}


/*******************************************************************************
* Function Name: elevator_test_Read
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
*  Macro elevator_test_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 elevator_test_Read(void) 
{
    return (elevator_test_PS & elevator_test_MASK) >> elevator_test_SHIFT;
}


/*******************************************************************************
* Function Name: elevator_test_ReadDataReg
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
uint8 elevator_test_ReadDataReg(void) 
{
    return (elevator_test_DR & elevator_test_MASK) >> elevator_test_SHIFT;
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(elevator_test_INTSTAT) 

    /*******************************************************************************
    * Function Name: elevator_test_ClearInterrupt
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
    uint8 elevator_test_ClearInterrupt(void) 
    {
        return (elevator_test_INTSTAT & elevator_test_MASK) >> elevator_test_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 


/* [] END OF FILE */ 
