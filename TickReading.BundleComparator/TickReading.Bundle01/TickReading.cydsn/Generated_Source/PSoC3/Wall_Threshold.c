/*******************************************************************************
* File Name: Wall_Threshold.c  
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
#include "Wall_Threshold.h"

#if (CY_PSOC5A)
#include <CyLib.h>
#endif /* CY_PSOC5A */

uint8 Wall_Threshold_initVar = 0;

#if (CY_PSOC5A)
    uint8 Wall_Threshold_restoreVal = 0;
    uint8 Wall_Threshold_intrStatus = 0u;
#endif /* CY_PSOC5A */

#if (CY_PSOC5A)
    static Wall_Threshold_backupStruct Wall_Threshold_backup;
#endif /* CY_PSOC5A */


/*******************************************************************************
* Function Name: Wall_Threshold_Init
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
void Wall_Threshold_Init(void) 
{
    Wall_Threshold_CR0 = (Wall_Threshold_MODE_V );

    /* Set default data source */
    if(Wall_Threshold_DEFAULT_DATA_SRC != 0 )
    {
        Wall_Threshold_CR1 = (Wall_Threshold_DEFAULT_CNTL | Wall_Threshold_DACBUS_ENABLE) ;
    }
    else
    {
        Wall_Threshold_CR1 = (Wall_Threshold_DEFAULT_CNTL | Wall_Threshold_DACBUS_DISABLE) ;
    }

    /* Set default strobe mode */
    if(Wall_Threshold_DEFAULT_STRB != 0)
    {
        Wall_Threshold_Strobe |= Wall_Threshold_STRB_EN ;
    }

    /* Set default range */
    Wall_Threshold_SetRange(Wall_Threshold_DEFAULT_RANGE); 

    /* Set default speed */
    Wall_Threshold_SetSpeed(Wall_Threshold_DEFAULT_SPEED);
}


/*******************************************************************************
* Function Name: Wall_Threshold_Enable
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
void Wall_Threshold_Enable(void) 
{
    Wall_Threshold_PWRMGR |= Wall_Threshold_ACT_PWR_EN;
    Wall_Threshold_STBY_PWRMGR |= Wall_Threshold_STBY_PWR_EN;

    /*This is to restore the value of register CR0 ,
    which is modified  in Stop API , this prevents misbehaviour of VDAC */
    #if (CY_PSOC5A)
        if(Wall_Threshold_restoreVal == 1) 
        {
             Wall_Threshold_CR0 = Wall_Threshold_backup.data_value;
             Wall_Threshold_restoreVal = 0;
        }
    #endif /* CY_PSOC5A */
}


/*******************************************************************************
* Function Name: Wall_Threshold_Start
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
*  Wall_Threshold_initVar: Is modified when this function is called for the 
*  first time. Is used to ensure that initialization happens only once.
*
*******************************************************************************/
void Wall_Threshold_Start(void)  
{
    /* Hardware initiazation only needs to occure the first time */
    if(Wall_Threshold_initVar == 0)
    { 
        Wall_Threshold_Init();
        Wall_Threshold_initVar = 1;
    }

    /* Enable power to DAC */
    Wall_Threshold_Enable();

    /* Set default value */
    Wall_Threshold_SetValue(Wall_Threshold_DEFAULT_DATA); 
}


/*******************************************************************************
* Function Name: Wall_Threshold_Stop
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
void Wall_Threshold_Stop(void) 
{
    /* Disble power to DAC */
    Wall_Threshold_PWRMGR &= ~Wall_Threshold_ACT_PWR_EN;
    Wall_Threshold_STBY_PWRMGR &= ~Wall_Threshold_STBY_PWR_EN;

    /* This is a work around for PSoC5A  ,
    this sets VDAC to current mode with output off */
    #if (CY_PSOC5A)
        Wall_Threshold_backup.data_value = Wall_Threshold_CR0;
        Wall_Threshold_CR0 = Wall_Threshold_CUR_MODE_OUT_OFF;
        Wall_Threshold_restoreVal = 1;
    #endif /* CY_PSOC5A */
}


/*******************************************************************************
* Function Name: Wall_Threshold_SetSpeed
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
void Wall_Threshold_SetSpeed(uint8 speed) 
{
    /* Clear power mask then write in new value */
    Wall_Threshold_CR0 &= ~Wall_Threshold_HS_MASK ;
    Wall_Threshold_CR0 |=  ( speed & Wall_Threshold_HS_MASK) ;
}


/*******************************************************************************
* Function Name: Wall_Threshold_SetRange
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
void Wall_Threshold_SetRange(uint8 range) 
{
    Wall_Threshold_CR0 &= ~Wall_Threshold_RANGE_MASK ;      /* Clear existing mode */
    Wall_Threshold_CR0 |= ( range & Wall_Threshold_RANGE_MASK ) ; /*  Set Range  */
    Wall_Threshold_DacTrim();
}


/*******************************************************************************
* Function Name: Wall_Threshold_SetValue
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
void Wall_Threshold_SetValue(uint8 value) 
{
    #if (CY_PSOC5A)
        Wall_Threshold_intrStatus = CyEnterCriticalSection();
    #endif /* CY_PSOC5A */

    Wall_Threshold_Data = value;                /*  Set Value  */

    /* PSOC5A requires a double write */
    /* Exit Critical Section */
    #if (CY_PSOC5A)
        Wall_Threshold_Data = value;
        CyExitCriticalSection(Wall_Threshold_intrStatus);
    #endif /* CY_PSOC5A */
}


/*******************************************************************************
* Function Name: Wall_Threshold_DacTrim
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
void Wall_Threshold_DacTrim(void) 
{
    uint8 mode;

    mode = ((Wall_Threshold_CR0 & Wall_Threshold_RANGE_MASK) >> 2) + Wall_Threshold_TRIM_M7_1V_RNG_OFFSET;
    Wall_Threshold_TR = CY_GET_XTND_REG8((uint8 *)(Wall_Threshold_DAC_TRIM_BASE + mode));
}


/* [] END OF FILE */
