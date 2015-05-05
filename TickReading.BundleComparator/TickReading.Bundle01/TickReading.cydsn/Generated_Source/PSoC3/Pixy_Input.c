/*******************************************************************************
* File Name: Pixy_Input.c  
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
#include "Pixy_Input.h"


/*******************************************************************************
* Function Name: Pixy_Input_Write
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
void Pixy_Input_Write(uint8 value) 
{
    uint8 staticBits = Pixy_Input_DR & ~Pixy_Input_MASK;
    Pixy_Input_DR = staticBits | ((value << Pixy_Input_SHIFT) & Pixy_Input_MASK);
}


/*******************************************************************************
* Function Name: Pixy_Input_SetDriveMode
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
void Pixy_Input_SetDriveMode(uint8 mode) 
{
	CyPins_SetPinDriveMode(Pixy_Input_0, mode);
}


/*******************************************************************************
* Function Name: Pixy_Input_Read
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
*  Macro Pixy_Input_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 Pixy_Input_Read(void) 
{
    return (Pixy_Input_PS & Pixy_Input_MASK) >> Pixy_Input_SHIFT;
}


/*******************************************************************************
* Function Name: Pixy_Input_ReadDataReg
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
uint8 Pixy_Input_ReadDataReg(void) 
{
    return (Pixy_Input_DR & Pixy_Input_MASK) >> Pixy_Input_SHIFT;
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(Pixy_Input_INTSTAT) 

    /*******************************************************************************
    * Function Name: Pixy_Input_ClearInterrupt
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
    uint8 Pixy_Input_ClearInterrupt(void) 
    {
        return (Pixy_Input_INTSTAT & Pixy_Input_MASK) >> Pixy_Input_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 


/* [] END OF FILE */ 
