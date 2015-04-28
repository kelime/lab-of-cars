/*******************************************************************************
* File Name: Elevator_Threshold.c  
* Version 1.80
*
* Description:
*  This file provides the source code to the API for the 8-bit Voltage DAC 
*  (VDAC8) User Module.
*
* Note:
*  Any unusual or non-standard behavior should be noted here. Other-
*  wise, this section should remain blank.
*
********************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#include "cytypes.h"
#include "Elevator_Threshold.h"

#if (CY_PSOC5A)
#include <CyLib.h>
#endif /* CY_PSOC5A */

uint8 Elevator_Threshold_initVar = 0;

#if (CY_PSOC5A)
    uint8 Elevator_Threshold_restoreVal = 0;
    uint8 Elevator_Threshold_intrStatus = 0u;
#endif /* CY_PSOC5A */

#if (CY_PSOC5A)
    static Elevator_Threshold_backupStruct Elevator_Threshold_backup;
#endif /* CY_PSOC5A */


/*******************************************************************************
* Function Name: Elevator_Threshold_Init
********************************************************************************
* Summary:
*  Initialize to the schematic state.
* 
* Parameters:
*  void:
*
* Return:
*  void
*
* Theory:
*
* Side Effects:
*
*******************************************************************************/
void Elevator_Threshold_Init(void) 
{
    Elevator_Threshold_CR0 = (Elevator_Threshold_MODE_V );

    /* Set default data source */
    if(Elevator_Threshold_DEFAULT_DATA_SRC != 0 )
    {
        Elevator_Threshold_CR1 = (Elevator_Threshold_DEFAULT_CNTL | Elevator_Threshold_DACBUS_ENABLE) ;
    }
    else
    {
        Elevator_Threshold_CR1 = (Elevator_Threshold_DEFAULT_CNTL | Elevator_Threshold_DACBUS_DISABLE) ;
    }

    /* Set default strobe mode */
    if(Elevator_Threshold_DEFAULT_STRB != 0)
    {
        Elevator_Threshold_Strobe |= Elevator_Threshold_STRB_EN ;
    }

    /* Set default range */
    Elevator_Threshold_SetRange(Elevator_Threshold_DEFAULT_RANGE); 

    /* Set default speed */
    Elevator_Threshold_SetSpeed(Elevator_Threshold_DEFAULT_SPEED);
}


/*******************************************************************************
* Function Name: Elevator_Threshold_Enable
********************************************************************************
* Summary:
*  Enable the VDAC8
* 
* Parameters:
*  void
*
* Return:
*  void
*
* Theory:
*
* Side Effects:
*
*******************************************************************************/
void Elevator_Threshold_Enable(void) 
{
    Elevator_Threshold_PWRMGR |= Elevator_Threshold_ACT_PWR_EN;
    Elevator_Threshold_STBY_PWRMGR |= Elevator_Threshold_STBY_PWR_EN;

    /*This is to restore the value of register CR0 ,
    which is modified  in Stop API , this prevents misbehaviour of VDAC */
    #if (CY_PSOC5A)
        if(Elevator_Threshold_restoreVal == 1) 
        {
             Elevator_Threshold_CR0 = Elevator_Threshold_backup.data_value;
             Elevator_Threshold_restoreVal = 0;
        }
    #endif /* CY_PSOC5A */
}


/*******************************************************************************
* Function Name: Elevator_Threshold_Start
********************************************************************************
*
* Summary:
*  The start function initializes the voltage DAC with the default values, 
*  and sets the power to the given level.  A power level of 0, is the same as
*  executing the stop function.
*
* Parameters:
*  Power: Sets power level between off (0) and (3) high power
*
* Return:
*  void 
*
* Global variables:
*  Elevator_Threshold_initVar: Is modified when this function is called for the 
*  first time. Is used to ensure that initialization happens only once.
*
*******************************************************************************/
void Elevator_Threshold_Start(void)  
{
    /* Hardware initiazation only needs to occure the first time */
    if(Elevator_Threshold_initVar == 0)
    { 
        Elevator_Threshold_Init();
        Elevator_Threshold_initVar = 1;
    }

    /* Enable power to DAC */
    Elevator_Threshold_Enable();

    /* Set default value */
    Elevator_Threshold_SetValue(Elevator_Threshold_DEFAULT_DATA); 
}


/*******************************************************************************
* Function Name: Elevator_Threshold_Stop
********************************************************************************
*
* Summary:
*  Powers down DAC to lowest power state.
*
* Parameters:
*  void
*
* Return:
*  void
*
* Theory:
*
* Side Effects:
*
*******************************************************************************/
void Elevator_Threshold_Stop(void) 
{
    /* Disble power to DAC */
    Elevator_Threshold_PWRMGR &= ~Elevator_Threshold_ACT_PWR_EN;
    Elevator_Threshold_STBY_PWRMGR &= ~Elevator_Threshold_STBY_PWR_EN;

    /* This is a work around for PSoC5A  ,
    this sets VDAC to current mode with output off */
    #if (CY_PSOC5A)
        Elevator_Threshold_backup.data_value = Elevator_Threshold_CR0;
        Elevator_Threshold_CR0 = Elevator_Threshold_CUR_MODE_OUT_OFF;
        Elevator_Threshold_restoreVal = 1;
    #endif /* CY_PSOC5A */
}


/*******************************************************************************
* Function Name: Elevator_Threshold_SetSpeed
********************************************************************************
*
* Summary:
*  Set DAC speed
*
* Parameters:
*  power: Sets speed value
*
* Return:
*  void
*
* Theory:
*
* Side Effects:
*
*******************************************************************************/
void Elevator_Threshold_SetSpeed(uint8 speed) 
{
    /* Clear power mask then write in new value */
    Elevator_Threshold_CR0 &= ~Elevator_Threshold_HS_MASK ;
    Elevator_Threshold_CR0 |=  ( speed & Elevator_Threshold_HS_MASK) ;
}


/*******************************************************************************
* Function Name: Elevator_Threshold_SetRange
********************************************************************************
*
* Summary:
*  Set one of three current ranges.
*
* Parameters:
*  Range: Sets one of Three valid ranges.
*
* Return:
*  void 
*
* Theory:
*
* Side Effects:
*
*******************************************************************************/
void Elevator_Threshold_SetRange(uint8 range) 
{
    Elevator_Threshold_CR0 &= ~Elevator_Threshold_RANGE_MASK ;      /* Clear existing mode */
    Elevator_Threshold_CR0 |= ( range & Elevator_Threshold_RANGE_MASK ) ; /*  Set Range  */
    Elevator_Threshold_DacTrim();
}


/*******************************************************************************
* Function Name: Elevator_Threshold_SetValue
********************************************************************************
*
* Summary:
*  Set 8-bit DAC value
*
* Parameters:  
*  value:  Sets DAC value between 0 and 255.
*
* Return: 
*  void 
*
* Theory: 
*
* Side Effects:
*
*******************************************************************************/
void Elevator_Threshold_SetValue(uint8 value) 
{
    #if (CY_PSOC5A)
        Elevator_Threshold_intrStatus = CyEnterCriticalSection();
    #endif /* CY_PSOC5A */

    Elevator_Threshold_Data = value;                /*  Set Value  */

    /* PSOC5A requires a double write */
    /* Exit Critical Section */
    #if (CY_PSOC5A)
        Elevator_Threshold_Data = value;
        CyExitCriticalSection(Elevator_Threshold_intrStatus);
    #endif /* CY_PSOC5A */
}


/*******************************************************************************
* Function Name: Elevator_Threshold_DacTrim
********************************************************************************
*
* Summary:
*  Set the trim value for the given range.
*
* Parameters:
*  range:  1V or 4V range.  See constants.
*
* Return:
*  void
*
* Theory: 
*
* Side Effects:
*
*******************************************************************************/
void Elevator_Threshold_DacTrim(void) 
{
    uint8 mode;

    mode = ((Elevator_Threshold_CR0 & Elevator_Threshold_RANGE_MASK) >> 2) + Elevator_Threshold_TRIM_M7_1V_RNG_OFFSET;
    Elevator_Threshold_TR = CY_GET_XTND_REG8((uint8 *)(Elevator_Threshold_DAC_TRIM_BASE + mode));
}


/* [] END OF FILE */
