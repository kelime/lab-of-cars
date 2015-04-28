/*******************************************************************************
* File Name: Vertical_Sync_Frame.c  
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
#include "Vertical_Sync_Frame.h"


/*******************************************************************************
* Function Name: Vertical_Sync_Frame_Write
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
void Vertical_Sync_Frame_Write(uint8 value) 
{
    uint8 staticBits = Vertical_Sync_Frame_DR & ~Vertical_Sync_Frame_MASK;
    Vertical_Sync_Frame_DR = staticBits | ((value << Vertical_Sync_Frame_SHIFT) & Vertical_Sync_Frame_MASK);
}


/*******************************************************************************
* Function Name: Vertical_Sync_Frame_SetDriveMode
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
void Vertical_Sync_Frame_SetDriveMode(uint8 mode) 
{
	CyPins_SetPinDriveMode(Vertical_Sync_Frame_0, mode);
}


/*******************************************************************************
* Function Name: Vertical_Sync_Frame_Read
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
*  Macro Vertical_Sync_Frame_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 Vertical_Sync_Frame_Read(void) 
{
    return (Vertical_Sync_Frame_PS & Vertical_Sync_Frame_MASK) >> Vertical_Sync_Frame_SHIFT;
}


/*******************************************************************************
* Function Name: Vertical_Sync_Frame_ReadDataReg
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
uint8 Vertical_Sync_Frame_ReadDataReg(void) 
{
    return (Vertical_Sync_Frame_DR & Vertical_Sync_Frame_MASK) >> Vertical_Sync_Frame_SHIFT;
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(Vertical_Sync_Frame_INTSTAT) 

    /*******************************************************************************
    * Function Name: Vertical_Sync_Frame_ClearInterrupt
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
    uint8 Vertical_Sync_Frame_ClearInterrupt(void) 
    {
        return (Vertical_Sync_Frame_INTSTAT & Vertical_Sync_Frame_MASK) >> Vertical_Sync_Frame_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 


/* [] END OF FILE */ 
