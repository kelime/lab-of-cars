/*******************************************************************************
* File Name: Pressure_SCL.c  
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
#include "Pressure_SCL.h"


/*******************************************************************************
* Function Name: Pressure_SCL_Write
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
void Pressure_SCL_Write(uint8 value) 
{
    uint8 staticBits = Pressure_SCL_DR & ~Pressure_SCL_MASK;
    Pressure_SCL_DR = staticBits | ((value << Pressure_SCL_SHIFT) & Pressure_SCL_MASK);
}


/*******************************************************************************
* Function Name: Pressure_SCL_SetDriveMode
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
void Pressure_SCL_SetDriveMode(uint8 mode) 
{
	CyPins_SetPinDriveMode(Pressure_SCL_0, mode);
}


/*******************************************************************************
* Function Name: Pressure_SCL_Read
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
*  Macro Pressure_SCL_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 Pressure_SCL_Read(void) 
{
    return (Pressure_SCL_PS & Pressure_SCL_MASK) >> Pressure_SCL_SHIFT;
}


/*******************************************************************************
* Function Name: Pressure_SCL_ReadDataReg
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
uint8 Pressure_SCL_ReadDataReg(void) 
{
    return (Pressure_SCL_DR & Pressure_SCL_MASK) >> Pressure_SCL_SHIFT;
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(Pressure_SCL_INTSTAT) 

    /*******************************************************************************
    * Function Name: Pressure_SCL_ClearInterrupt
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
    uint8 Pressure_SCL_ClearInterrupt(void) 
    {
        return (Pressure_SCL_INTSTAT & Pressure_SCL_MASK) >> Pressure_SCL_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 


/* [] END OF FILE */ 
