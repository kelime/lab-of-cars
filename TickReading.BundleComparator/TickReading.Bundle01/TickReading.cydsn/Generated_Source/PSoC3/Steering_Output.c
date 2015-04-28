/*******************************************************************************
* File Name: Steering_Output.c  
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
#include "Steering_Output.h"


/*******************************************************************************
* Function Name: Steering_Output_Write
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
void Steering_Output_Write(uint8 value) 
{
    uint8 staticBits = Steering_Output_DR & ~Steering_Output_MASK;
    Steering_Output_DR = staticBits | ((value << Steering_Output_SHIFT) & Steering_Output_MASK);
}


/*******************************************************************************
* Function Name: Steering_Output_SetDriveMode
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
void Steering_Output_SetDriveMode(uint8 mode) 
{
	CyPins_SetPinDriveMode(Steering_Output_0, mode);
}


/*******************************************************************************
* Function Name: Steering_Output_Read
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
*  Macro Steering_Output_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 Steering_Output_Read(void) 
{
    return (Steering_Output_PS & Steering_Output_MASK) >> Steering_Output_SHIFT;
}


/*******************************************************************************
* Function Name: Steering_Output_ReadDataReg
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
uint8 Steering_Output_ReadDataReg(void) 
{
    return (Steering_Output_DR & Steering_Output_MASK) >> Steering_Output_SHIFT;
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(Steering_Output_INTSTAT) 

    /*******************************************************************************
    * Function Name: Steering_Output_ClearInterrupt
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
    uint8 Steering_Output_ClearInterrupt(void) 
    {
        return (Steering_Output_INTSTAT & Steering_Output_MASK) >> Steering_Output_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 


/* [] END OF FILE */ 
