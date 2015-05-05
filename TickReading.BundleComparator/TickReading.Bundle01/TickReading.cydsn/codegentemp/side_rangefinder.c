/*******************************************************************************
* File Name: side_rangefinder.c  
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
#include "side_rangefinder.h"


/*******************************************************************************
* Function Name: side_rangefinder_Write
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
void side_rangefinder_Write(uint8 value) 
{
    uint8 staticBits = side_rangefinder_DR & ~side_rangefinder_MASK;
    side_rangefinder_DR = staticBits | ((value << side_rangefinder_SHIFT) & side_rangefinder_MASK);
}


/*******************************************************************************
* Function Name: side_rangefinder_SetDriveMode
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
void side_rangefinder_SetDriveMode(uint8 mode) 
{
	CyPins_SetPinDriveMode(side_rangefinder_0, mode);
}


/*******************************************************************************
* Function Name: side_rangefinder_Read
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
*  Macro side_rangefinder_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 side_rangefinder_Read(void) 
{
    return (side_rangefinder_PS & side_rangefinder_MASK) >> side_rangefinder_SHIFT;
}


/*******************************************************************************
* Function Name: side_rangefinder_ReadDataReg
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
uint8 side_rangefinder_ReadDataReg(void) 
{
    return (side_rangefinder_DR & side_rangefinder_MASK) >> side_rangefinder_SHIFT;
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(side_rangefinder_INTSTAT) 

    /*******************************************************************************
    * Function Name: side_rangefinder_ClearInterrupt
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
    uint8 side_rangefinder_ClearInterrupt(void) 
    {
        return (side_rangefinder_INTSTAT & side_rangefinder_MASK) >> side_rangefinder_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 


/* [] END OF FILE */ 
