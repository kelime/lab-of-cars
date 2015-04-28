/*******************************************************************************
* File Name: Horizontal_Sync_Line.c  
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
#include "Horizontal_Sync_Line.h"


/*******************************************************************************
* Function Name: Horizontal_Sync_Line_Write
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
void Horizontal_Sync_Line_Write(uint8 value) 
{
    uint8 staticBits = Horizontal_Sync_Line_DR & ~Horizontal_Sync_Line_MASK;
    Horizontal_Sync_Line_DR = staticBits | ((value << Horizontal_Sync_Line_SHIFT) & Horizontal_Sync_Line_MASK);
}


/*******************************************************************************
* Function Name: Horizontal_Sync_Line_SetDriveMode
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
void Horizontal_Sync_Line_SetDriveMode(uint8 mode) 
{
	CyPins_SetPinDriveMode(Horizontal_Sync_Line_0, mode);
}


/*******************************************************************************
* Function Name: Horizontal_Sync_Line_Read
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
*  Macro Horizontal_Sync_Line_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 Horizontal_Sync_Line_Read(void) 
{
    return (Horizontal_Sync_Line_PS & Horizontal_Sync_Line_MASK) >> Horizontal_Sync_Line_SHIFT;
}


/*******************************************************************************
* Function Name: Horizontal_Sync_Line_ReadDataReg
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
uint8 Horizontal_Sync_Line_ReadDataReg(void) 
{
    return (Horizontal_Sync_Line_DR & Horizontal_Sync_Line_MASK) >> Horizontal_Sync_Line_SHIFT;
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(Horizontal_Sync_Line_INTSTAT) 

    /*******************************************************************************
    * Function Name: Horizontal_Sync_Line_ClearInterrupt
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
    uint8 Horizontal_Sync_Line_ClearInterrupt(void) 
    {
        return (Horizontal_Sync_Line_INTSTAT & Horizontal_Sync_Line_MASK) >> Horizontal_Sync_Line_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 


/* [] END OF FILE */ 
