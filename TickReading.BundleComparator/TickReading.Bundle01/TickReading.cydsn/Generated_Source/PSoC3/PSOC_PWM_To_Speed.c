/*******************************************************************************
* File Name: PSOC_PWM_To_Speed.c  
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
#include "PSOC_PWM_To_Speed.h"


/*******************************************************************************
* Function Name: PSOC_PWM_To_Speed_Write
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
void PSOC_PWM_To_Speed_Write(uint8 value) 
{
    uint8 staticBits = PSOC_PWM_To_Speed_DR & ~PSOC_PWM_To_Speed_MASK;
    PSOC_PWM_To_Speed_DR = staticBits | ((value << PSOC_PWM_To_Speed_SHIFT) & PSOC_PWM_To_Speed_MASK);
}


/*******************************************************************************
* Function Name: PSOC_PWM_To_Speed_SetDriveMode
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
void PSOC_PWM_To_Speed_SetDriveMode(uint8 mode) 
{
	CyPins_SetPinDriveMode(PSOC_PWM_To_Speed_0, mode);
}


/*******************************************************************************
* Function Name: PSOC_PWM_To_Speed_Read
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
*  Macro PSOC_PWM_To_Speed_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 PSOC_PWM_To_Speed_Read(void) 
{
    return (PSOC_PWM_To_Speed_PS & PSOC_PWM_To_Speed_MASK) >> PSOC_PWM_To_Speed_SHIFT;
}


/*******************************************************************************
* Function Name: PSOC_PWM_To_Speed_ReadDataReg
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
uint8 PSOC_PWM_To_Speed_ReadDataReg(void) 
{
    return (PSOC_PWM_To_Speed_DR & PSOC_PWM_To_Speed_MASK) >> PSOC_PWM_To_Speed_SHIFT;
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(PSOC_PWM_To_Speed_INTSTAT) 

    /*******************************************************************************
    * Function Name: PSOC_PWM_To_Speed_ClearInterrupt
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
    uint8 PSOC_PWM_To_Speed_ClearInterrupt(void) 
    {
        return (PSOC_PWM_To_Speed_INTSTAT & PSOC_PWM_To_Speed_MASK) >> PSOC_PWM_To_Speed_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 


/* [] END OF FILE */ 
