/*******************************************************************************
* File Name: forwardreverse.c  
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
#include "forwardreverse.h"


/*******************************************************************************
* Function Name: forwardreverse_Write
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
void forwardreverse_Write(uint8 value) 
{
    uint8 staticBits = forwardreverse_DR & ~forwardreverse_MASK;
    forwardreverse_DR = staticBits | ((value << forwardreverse_SHIFT) & forwardreverse_MASK);
}


/*******************************************************************************
* Function Name: forwardreverse_SetDriveMode
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
void forwardreverse_SetDriveMode(uint8 mode) 
{
	CyPins_SetPinDriveMode(forwardreverse_0, mode);
}


/*******************************************************************************
* Function Name: forwardreverse_Read
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
*  Macro forwardreverse_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 forwardreverse_Read(void) 
{
    return (forwardreverse_PS & forwardreverse_MASK) >> forwardreverse_SHIFT;
}


/*******************************************************************************
* Function Name: forwardreverse_ReadDataReg
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
uint8 forwardreverse_ReadDataReg(void) 
{
    return (forwardreverse_DR & forwardreverse_MASK) >> forwardreverse_SHIFT;
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(forwardreverse_INTSTAT) 

    /*******************************************************************************
    * Function Name: forwardreverse_ClearInterrupt
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
    uint8 forwardreverse_ClearInterrupt(void) 
    {
        return (forwardreverse_INTSTAT & forwardreverse_MASK) >> forwardreverse_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 


/* [] END OF FILE */ 
