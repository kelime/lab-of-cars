/*******************************************************************************
* File Name: Comparator_Input_UNMAPPED.c  
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
#include "Comparator_Input_UNMAPPED.h"


/*******************************************************************************
* Function Name: Comparator_Input_UNMAPPED_Write
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
void Comparator_Input_UNMAPPED_Write(uint8 value) 
{
    uint8 staticBits = Comparator_Input_UNMAPPED_DR & ~Comparator_Input_UNMAPPED_MASK;
    Comparator_Input_UNMAPPED_DR = staticBits | ((value << Comparator_Input_UNMAPPED_SHIFT) & Comparator_Input_UNMAPPED_MASK);
}


/*******************************************************************************
* Function Name: Comparator_Input_UNMAPPED_SetDriveMode
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
void Comparator_Input_UNMAPPED_SetDriveMode(uint8 mode) 
{
	CyPins_SetPinDriveMode(Comparator_Input_UNMAPPED_0, mode);
}


/*******************************************************************************
* Function Name: Comparator_Input_UNMAPPED_Read
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
*  Macro Comparator_Input_UNMAPPED_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 Comparator_Input_UNMAPPED_Read(void) 
{
    return (Comparator_Input_UNMAPPED_PS & Comparator_Input_UNMAPPED_MASK) >> Comparator_Input_UNMAPPED_SHIFT;
}


/*******************************************************************************
* Function Name: Comparator_Input_UNMAPPED_ReadDataReg
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
uint8 Comparator_Input_UNMAPPED_ReadDataReg(void) 
{
    return (Comparator_Input_UNMAPPED_DR & Comparator_Input_UNMAPPED_MASK) >> Comparator_Input_UNMAPPED_SHIFT;
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(Comparator_Input_UNMAPPED_INTSTAT) 

    /*******************************************************************************
    * Function Name: Comparator_Input_UNMAPPED_ClearInterrupt
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
    uint8 Comparator_Input_UNMAPPED_ClearInterrupt(void) 
    {
        return (Comparator_Input_UNMAPPED_INTSTAT & Comparator_Input_UNMAPPED_MASK) >> Comparator_Input_UNMAPPED_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 


/* [] END OF FILE */ 
