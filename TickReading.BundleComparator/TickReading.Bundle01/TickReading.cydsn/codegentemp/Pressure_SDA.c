/*******************************************************************************
* File Name: Pressure_SDA.c  
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
#include "Pressure_SDA.h"


/*******************************************************************************
* Function Name: Pressure_SDA_Write
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
void Pressure_SDA_Write(uint8 value) 
{
    uint8 staticBits = Pressure_SDA_DR & ~Pressure_SDA_MASK;
    Pressure_SDA_DR = staticBits | ((value << Pressure_SDA_SHIFT) & Pressure_SDA_MASK);
}


/*******************************************************************************
* Function Name: Pressure_SDA_SetDriveMode
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
void Pressure_SDA_SetDriveMode(uint8 mode) 
{
	CyPins_SetPinDriveMode(Pressure_SDA_0, mode);
}


/*******************************************************************************
* Function Name: Pressure_SDA_Read
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
*  Macro Pressure_SDA_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 Pressure_SDA_Read(void) 
{
    return (Pressure_SDA_PS & Pressure_SDA_MASK) >> Pressure_SDA_SHIFT;
}


/*******************************************************************************
* Function Name: Pressure_SDA_ReadDataReg
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
uint8 Pressure_SDA_ReadDataReg(void) 
{
    return (Pressure_SDA_DR & Pressure_SDA_MASK) >> Pressure_SDA_SHIFT;
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(Pressure_SDA_INTSTAT) 

    /*******************************************************************************
    * Function Name: Pressure_SDA_ClearInterrupt
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
    uint8 Pressure_SDA_ClearInterrupt(void) 
    {
        return (Pressure_SDA_INTSTAT & Pressure_SDA_MASK) >> Pressure_SDA_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 


/* [] END OF FILE */ 
