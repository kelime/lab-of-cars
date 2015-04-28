/*******************************************************************************
* File Name: Hall_To_PSOC.c  
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
#include "Hall_To_PSOC.h"


/*******************************************************************************
* Function Name: Hall_To_PSOC_Write
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
void Hall_To_PSOC_Write(uint8 value) 
{
    uint8 staticBits = Hall_To_PSOC_DR & ~Hall_To_PSOC_MASK;
    Hall_To_PSOC_DR = staticBits | ((value << Hall_To_PSOC_SHIFT) & Hall_To_PSOC_MASK);
}


/*******************************************************************************
* Function Name: Hall_To_PSOC_SetDriveMode
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
void Hall_To_PSOC_SetDriveMode(uint8 mode) 
{
	CyPins_SetPinDriveMode(Hall_To_PSOC_0, mode);
}


/*******************************************************************************
* Function Name: Hall_To_PSOC_Read
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
*  Macro Hall_To_PSOC_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 Hall_To_PSOC_Read(void) 
{
    return (Hall_To_PSOC_PS & Hall_To_PSOC_MASK) >> Hall_To_PSOC_SHIFT;
}


/*******************************************************************************
* Function Name: Hall_To_PSOC_ReadDataReg
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
uint8 Hall_To_PSOC_ReadDataReg(void) 
{
    return (Hall_To_PSOC_DR & Hall_To_PSOC_MASK) >> Hall_To_PSOC_SHIFT;
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(Hall_To_PSOC_INTSTAT) 

    /*******************************************************************************
    * Function Name: Hall_To_PSOC_ClearInterrupt
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
    uint8 Hall_To_PSOC_ClearInterrupt(void) 
    {
        return (Hall_To_PSOC_INTSTAT & Hall_To_PSOC_MASK) >> Hall_To_PSOC_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 


/* [] END OF FILE */ 
