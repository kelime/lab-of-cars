/*******************************************************************************
* File Name: Test.c  
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
#include "Test.h"


/*******************************************************************************
* Function Name: Test_Write
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
void Test_Write(uint8 value) 
{
    uint8 staticBits = Test_DR & ~Test_MASK;
    Test_DR = staticBits | ((value << Test_SHIFT) & Test_MASK);
}


/*******************************************************************************
* Function Name: Test_SetDriveMode
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
void Test_SetDriveMode(uint8 mode) 
{
	CyPins_SetPinDriveMode(Test_0, mode);
}


/*******************************************************************************
* Function Name: Test_Read
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
*  Macro Test_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 Test_Read(void) 
{
    return (Test_PS & Test_MASK) >> Test_SHIFT;
}


/*******************************************************************************
* Function Name: Test_ReadDataReg
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
uint8 Test_ReadDataReg(void) 
{
    return (Test_DR & Test_MASK) >> Test_SHIFT;
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(Test_INTSTAT) 

    /*******************************************************************************
    * Function Name: Test_ClearInterrupt
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
    uint8 Test_ClearInterrupt(void) 
    {
        return (Test_INTSTAT & Test_MASK) >> Test_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 


/* [] END OF FILE */ 
