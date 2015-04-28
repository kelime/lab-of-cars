/*******************************************************************************
* File Name: Elevator_Comparator.c
* Version 1.90
*
* Description:
*  This file provides the source code to the API for the Comparator component
*
* Note:
*  None
*
********************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#include "Elevator_Comparator.h"

uint8 Elevator_Comparator_initVar = 0u;


/* static Elevator_Comparator_backupStruct  Elevator_Comparator_backup; */
#if (CY_PSOC5A)
    static Elevator_Comparator_LOWPOWER_BACKUP_STRUCT  Elevator_Comparator_lowPowerBackup;
#endif /* CY_PSOC5A */

/* variable to decide whether or not to restore the control register in 
   Enable() API for PSoC5A only */
#if (CY_PSOC5A)
    uint8 Elevator_Comparator_restoreReg = 0u;
#endif /* CY_PSOC5A */


/*******************************************************************************
* Function Name: Elevator_Comparator_Init
********************************************************************************
*
* Summary:
*  Initialize to the schematic state
* 
* Parameters:
*  void
*
* Return:
*  void
*
*******************************************************************************/
void Elevator_Comparator_Init(void) 
{
    /* Set default speed/power */
    Elevator_Comparator_SetSpeed(Elevator_Comparator_DEFAULT_SPEED);

    /* Set default Hysteresis */
    if ( Elevator_Comparator_DEFAULT_HYSTERESIS == 0u )
    {
        Elevator_Comparator_CR |= Elevator_Comparator_HYST_OFF;
    }
    else
    {
        Elevator_Comparator_CR &= ~Elevator_Comparator_HYST_OFF; 
    }
    
    /* Power down override feature is not supported for PSoC5A. */
    #if (CY_PSOC3 || CY_PSOC5LP)
        /* Set default Power Down Override */
        if ( Elevator_Comparator_DEFAULT_PWRDWN_OVRD == 0u )
        {
            Elevator_Comparator_CR &= ~Elevator_Comparator_PWRDWN_OVRD;
        }
        else 
        {
            Elevator_Comparator_CR |= Elevator_Comparator_PWRDWN_OVRD;
        }
    #endif /* CY_PSOC3 || CY_PSOC5LP */
    
    /* Set mux always on logic */
    Elevator_Comparator_CR |= Elevator_Comparator_MX_AO;

    /* Set default sync */
    Elevator_Comparator_CLK &= ~Elevator_Comparator_SYNCCLK_MASK;
    if ( Elevator_Comparator_DEFAULT_BYPASS_SYNC == 0u )
    {
        Elevator_Comparator_CLK |= Elevator_Comparator_SYNC_CLK_EN;
    }
    else
    {
        Elevator_Comparator_CLK |= Elevator_Comparator_BYPASS_SYNC;
    }
}


/*******************************************************************************
* Function Name: Elevator_Comparator_Enable
********************************************************************************
*
* Summary:
*  Enable the Comparator
* 
* Parameters:
*  void
*
* Return:
*  void
*
*******************************************************************************/
void Elevator_Comparator_Enable(void) 
{
    Elevator_Comparator_PWRMGR |= Elevator_Comparator_ACT_PWR_EN;
    Elevator_Comparator_STBY_PWRMGR |= Elevator_Comparator_STBY_PWR_EN;
     
     /* This is to restore the value of register CR which is saved 
    in prior to the modification in stop() API */
    #if (CY_PSOC5A)
        if(Elevator_Comparator_restoreReg == 1u)
        {
            Elevator_Comparator_CR = Elevator_Comparator_lowPowerBackup.compCRReg;

            /* Clear the flag */
            Elevator_Comparator_restoreReg = 0u;
        }
    #endif /* CY_PSOC5A */
}


/*******************************************************************************
* Function Name: Elevator_Comparator_Start
********************************************************************************
*
* Summary:
*  The start function initializes the Analog Comparator with the default values.
*
* Parameters:
*  void
*
* Return:
*  void 
*
* Global variables:
*  Elevator_Comparator_initVar: Is modified when this function is called for the 
*   first time. Is used to ensure that initialization happens only once.
*  
*******************************************************************************/
void Elevator_Comparator_Start(void) 
{

    if ( Elevator_Comparator_initVar == 0u )
    {
        Elevator_Comparator_Init();
        
        Elevator_Comparator_initVar = 1u;
    }   

    /* Enable power to comparator */
    Elevator_Comparator_Enable();    
}


/*******************************************************************************
* Function Name: Elevator_Comparator_Stop
********************************************************************************
*
* Summary:
*  Powers down amplifier to lowest power state.
*
* Parameters:
*  void
*
* Return:
*  void
*
*******************************************************************************/
void Elevator_Comparator_Stop(void) 
{
    /* Disable power to comparator */
    Elevator_Comparator_PWRMGR &= ~Elevator_Comparator_ACT_PWR_EN;
    Elevator_Comparator_STBY_PWRMGR &= ~Elevator_Comparator_STBY_PWR_EN;    

    #if (CY_PSOC5A)
        /* Enable the variable */
        Elevator_Comparator_restoreReg = 1u;

        /* Save the control register before clearing it */
        Elevator_Comparator_lowPowerBackup.compCRReg = Elevator_Comparator_CR;
        Elevator_Comparator_CR = Elevator_Comparator_COMP_REG_CLR;
    #endif /* CY_PSOC5A */
}


/*******************************************************************************
* Function Name: Elevator_Comparator_SetSpeed
********************************************************************************
*
* Summary:
*  This function sets the speed of the Analog Comparator. The faster the speed
*  the more power that is used.
*
* Parameters:
*  speed: (uint8) Sets operation mode of Comparator
*
* Return:
*  void
*
*******************************************************************************/
void Elevator_Comparator_SetSpeed(uint8 speed) 
{
    /* Clear and Set power level */    
    Elevator_Comparator_CR = (Elevator_Comparator_CR & ~Elevator_Comparator_PWR_MODE_MASK) |
                           (speed & Elevator_Comparator_PWR_MODE_MASK);

    /* Set trim value for high speed comparator */
    if(speed == Elevator_Comparator_HIGHSPEED)
    {
        /* PSoC5A */
        #if (CY_PSOC5A)
            Elevator_Comparator_TR = Elevator_Comparator_HS_TRIM_TR0;
        #endif /* CY_PSOC5A */
        
        /* PSoC3, PSoC5LP or later */
        #if (CY_PSOC3 || CY_PSOC5LP) 
            Elevator_Comparator_TR0 = Elevator_Comparator_HS_TRIM_TR0;
            Elevator_Comparator_TR1 = Elevator_Comparator_HS_TRIM_TR1;
        #endif /* CY_PSOC3 || CY_PSOC5LP */
    }
    else
    {
    /* PSoC5A */
        #if (CY_PSOC5A)
            Elevator_Comparator_TR = Elevator_Comparator_LS_TRIM_TR0;
        #endif /* CY_PSOC5A */
        
        /* PSoC3, PSoC5LP or later */
        #if (CY_PSOC3 || CY_PSOC5LP) 
            Elevator_Comparator_TR0 = Elevator_Comparator_LS_TRIM_TR0;
            Elevator_Comparator_TR1 = Elevator_Comparator_LS_TRIM_TR1;
        #endif /* CY_PSOC3 || CY_PSOC5LP */
    }

}


/*******************************************************************************
* Function Name: Elevator_Comparator_GetCompare
********************************************************************************
*
* Summary:
*  This function returns the comparator output value.
*
* Parameters:
*   None
*
* Return:
*  (uint8)  0  if Pos_Input less than Neg_input
*           1  if Pos_Input greater than Neg_input.
*
*******************************************************************************/
uint8 Elevator_Comparator_GetCompare(void) 
{
    return( Elevator_Comparator_WRK & Elevator_Comparator_CMP_OUT_MASK);
}


/*******************************************************************************
* Function Name: Elevator_Comparator_trimAdjust
********************************************************************************
*
* Summary:
*  This function adjusts the value in the low nibble/high nibble of the Analog 
*  Comparator trim register
*
* Parameters:  
*  nibble:
*      0 -- adjusts the value in the low nibble
*      1 -- adjusts the value in the high nibble
*
* Return:
*  None
*
* Theory: 
*  Function assumes comparator block is setup for trim adjust.
*  Intended to be called from Comp_ZeroCal()
* 
* Side Effects:
*  Routine uses a course 1ms delay following each trim adjustment to allow 
*  the comparator output to respond.
*
*******************************************************************************/
void Elevator_Comparator_trimAdjust(uint8 nibble) 
{
    uint8 trimCnt, trimCntMax;
    uint8 cmpState;   

    /* get current state of comparator output */
    cmpState = Elevator_Comparator_WRK & Elevator_Comparator_CMP_OUT_MASK;
    
    if (nibble == 0u)
    {    
        /* if comparator output is high, negative offset adjust is required */
        if ( cmpState != 0u )
        {
            /* PSoC5A */
            #if (CY_PSOC5A)
                Elevator_Comparator_TR |= Elevator_Comparator_CMP_TRIM1_DIR;
            #endif /* CY_PSOC5A */
            
            /* PSoC3, PSoC5LP or later */
            #if (CY_PSOC3 || CY_PSOC5LP)
                Elevator_Comparator_TR0 |= Elevator_Comparator_CMP_TR0_DIR;
            #endif /* CY_PSOC3 || CY_PSOC5LP */
        }
    }
    else
    {
        /* if comparator output is low, positive offset adjust is required */
        if ( cmpState == 0u )
        {
            /* PSoC5A */
            #if (CY_PSOC5A)
                Elevator_Comparator_TR |= Elevator_Comparator_CMP_TRIM2_DIR; 
            #endif /* CY_PSOC5A */
            
            /* PSoC3, PSoC5LP or later */
            #if (CY_PSOC3 || CY_PSOC5LP)
                Elevator_Comparator_TR1 |= Elevator_Comparator_CMP_TR1_DIR;
            #endif /* CY_PSOC3 || CY_PSOC5LP */
        }
    }

    /* Increment trim value until compare output changes state */
	
    /* PSoC5A */
	#if (CY_PSOC5A)
	trimCntMax = 7;
    #endif
	
	/* PSoC3, PSoC5LP or later */
	#if (CY_PSOC3 || CY_PSOC5LP)
	if(nibble == 0u)
	{
		trimCntMax = 15;
	}
	else
	{
		trimCntMax = 7;
	}
	#endif
	
    for ( trimCnt = 0; trimCnt < trimCntMax; trimCnt++ )
	{
        if (nibble == 0u)
        {
            /* PSoC5A */
            #if (CY_PSOC5A)
                Elevator_Comparator_TR += 1u;
            #endif /* CY_PSOC5A */
            
            /* PSoC3, PSoC5LP or later */
            #if (CY_PSOC3 || CY_PSOC5LP)
                Elevator_Comparator_TR0 += 1u;
            #endif /* CY_PSOC3 || CY_PSOC5LP */
        }
        else
        {
            /* PSoC5A */
            #if (CY_PSOC5A)
                Elevator_Comparator_TR += 0x10u;
            #endif /* CY_PSOC5A */
            
            /* PSoC3, PSoC5LP or later */
            #if (CY_PSOC3 || CY_PSOC5LP)
                Elevator_Comparator_TR1 += 1u;
            #endif /* CY_PSOC3 || CY_PSOC5LP */
        }
        
        CyDelayUs(10);
        
        /* Check for change in comparator output */
        if ((Elevator_Comparator_WRK & Elevator_Comparator_CMP_OUT_MASK) != cmpState)
        {
            break;      /* output changed state, trim phase is complete */
        }        
    }    
}


/*******************************************************************************
* Function Name: Elevator_Comparator_ZeroCal
********************************************************************************
*
* Summary:
*  This function calibrates the offset of the Analog Comparator.
*
* Parameters:
*  None
*
* Return:
*  (uint16)  value written in trim register when calibration complete.
*
* Theory: 
*  This function is used to optimize the calibration for user specific voltage
*  range.  The comparator trim is adjusted to counter transistor offsets
*   - offset is defined as positive if the output transitions to high before inP
*     is greater than inN
*   - offset is defined as negative if the output transitions to high after inP
*     is greater than inP
*
*  PSoC5A
*  The Analog Comparator provides 1 byte for offset trim.  The byte contains two
*  4 bit trim fields - one is a course trim and the other allows smaller
*  offset adjustments only for slow modes.
*  - low nibble - fine trim
*  - high nibble - course trim
*  PSoC3, PSoC5LP or later
*  The Analog Comparator provides 2 bytes for offset trim.  The bytes contain two
*  5 bit trim fields - one is a course trim and the other allows smaller
*  offset adjustments only for slow modes.
*  - TR0 - fine trim
*  - TR1 - course trim
*
*  Trim algorithm is a two phase process
*  The first phase performs course offset adjustment
*  The second phase serves one of two purposes depending on the outcome of the
*  first phase
*  - if the first trim value was maxed out without a comparator output 
*    transition, more offset will be added by adjusting the second trim value.
*  - if the first trim phase resulted in a comparator output transition, the
*    second trim value will serve as fine trim (in the opposite direction)to
*    ensure the offset is < 1 mV.
*
* Trim Process:   
*  1) User applies a voltage to the negative input.  Voltage should be in the
*     comparator operating range or an average of the operating voltage range.
*  2) Clear registers associated with analog routing to the positive input.
*  3) Disable Hysteresis
*  4) Set the calibration bit to short the negative and positive inputs to
*     the users calibration voltage.
*  5) Clear the TR register  ( TR = 0x00 )
*  ** LOW MODES
*  6) Check if compare output is high, if so, set the MSb of course trim field 
*     to a 1.
*  7) Increment the course trim field until the compare output changes
*  8) Check if compare output is low, if so, set the MSb of fine trim field
*     to a 1.
*  9) Increment the fine trim field until the compare output changes
*  ** FAST MODE - skip the steps 8,9
*
* Side Effects:
*  Routine clears analog routing associated with the comparator positive input.  
*  This may affect routing of signals from other components that are connected
*  to the positive input of the comparator.
*
*******************************************************************************/
uint16 Elevator_Comparator_ZeroCal(void) 
{
    uint8 tmpSW0;
    uint8 tmpSW2;
    uint8 tmpSW3;
    uint8 tmpCR;

    /* Save a copy of routing registers associated with inP */
    tmpSW0 = Elevator_Comparator_SW0;
    tmpSW2 = Elevator_Comparator_SW2;
    tmpSW3 = Elevator_Comparator_SW3;

     /* Clear routing for inP, retain routing for inN */
    Elevator_Comparator_SW0 = 0x00u;
    Elevator_Comparator_SW2 = 0x00u;
    Elevator_Comparator_SW3 = tmpSW3 & ~Elevator_Comparator_CMP_SW3_INPCTL_MASK;

    /* Preserve original configuration
     * - turn off Hysteresis
     * - set calibration bit - shorts inN to inP
    */
    tmpCR = Elevator_Comparator_CR;
    Elevator_Comparator_CR |= (Elevator_Comparator_CAL_ON | Elevator_Comparator_HYST_OFF);
    
    /* Write default low values to trim register - no offset adjust */
    /* PSoC5A */
    #if (CY_PSOC5A)
        Elevator_Comparator_TR = Elevator_Comparator_DEFAULT_CMP_TRIM;
    #endif /* CY_PSOC5A */
    
    /* PSoC3, PSoC5LP or later */
    #if (CY_PSOC3 || CY_PSOC5LP)
        Elevator_Comparator_TR0 = Elevator_Comparator_DEFAULT_CMP_TRIM;
        Elevator_Comparator_TR1 = Elevator_Comparator_DEFAULT_CMP_TRIM;
    #endif /* CY_PSOC3 || CY_PSOC5LP */
	
	/* Two phase trim - slow modes, one phase trim - for fast */ 
    if ( (Elevator_Comparator_CR & Elevator_Comparator_PWR_MODE_MASK) == Elevator_Comparator_PWR_MODE_FAST)
    {
        Elevator_Comparator_trimAdjust(0);
    }
    else /* default to trim for fast modes */
    {
        Elevator_Comparator_trimAdjust(1);
		Elevator_Comparator_trimAdjust(0);
    }
   
    /* Restore Config Register */
    Elevator_Comparator_CR = tmpCR;
    
    /* Restore routing registers for inP */
    Elevator_Comparator_SW0 = tmpSW0;
    Elevator_Comparator_SW2 = tmpSW2;
    Elevator_Comparator_SW3 = tmpSW3;
    
    /* PSoC5A */
    #if (CY_PSOC5A)
        return (uint16) Elevator_Comparator_TR;
    #endif /* CY_PSOC5A */
    
    /* PSoC3, PSoC5LP or later */
    #if (CY_PSOC3 || CY_PSOC5LP)
        return (((uint16)Elevator_Comparator_TR1 << 8) | (Elevator_Comparator_TR0));        
    #endif /* CY_PSOC3 || CY_PSOC5LP */
}


/*******************************************************************************
* Function Name: Elevator_Comparator_LoadTrim
********************************************************************************
*
* Summary:
*  This function stores a value in the Analog Comparator trim register.
*
* Parameters:  
*  uint8 trimVal - trim value.  This value is the same format as the value 
*  returned by the _ZeroCal routine.
*
* Return:
*  None
*
*******************************************************************************/
void Elevator_Comparator_LoadTrim(uint16 trimVal) 
{
    /* Stores value in the Analog Comparator trim register */
    /* PSoC5A */
    #if (CY_PSOC5A)
        Elevator_Comparator_TR = (uint8) trimVal;
    #endif /* CY_PSOC5A */
    
    /* PSoC3, PSoC5LP or later */
    #if (CY_PSOC3 || CY_PSOC5LP)
        /* Stores value in the Analog Comparator trim register for P-type load */
        Elevator_Comparator_TR0 = (uint8) trimVal;
        
        /* Stores value in the Analog Comparator trim register for N-type load */
        Elevator_Comparator_TR1 = (uint8) (trimVal >> 8); 
    #endif /* CY_PSOC3 || CY_PSOC5LP */
}


#if (CY_PSOC3 || CY_PSOC5LP)

    /*******************************************************************************
    * Function Name: Elevator_Comparator_PwrDwnOverrideEnable
    ********************************************************************************
    *
    * Summary:
    *  This is the power down over-ride feature. This function ignores sleep 
    *  parameter and allows the component to stay active during sleep mode.
    *
    * Parameters:
    *  None
    *
    * Return:
    *  None
    *
    *******************************************************************************/
    void Elevator_Comparator_PwrDwnOverrideEnable(void) 
    {
        /* Set the pd_override bit in CMP_CR register */
        Elevator_Comparator_CR |= Elevator_Comparator_PWRDWN_OVRD;
    }


    /*******************************************************************************
    * Function Name: Elevator_Comparator_PwrDwnOverrideDisable
    ********************************************************************************
    *
    * Summary:
    *  This is the power down over-ride feature. This allows the component to stay
    *  inactive during sleep.
    *
    * Parameters:
    *  None
    *
    * Return:
    *  None
    *
    *******************************************************************************/
    void Elevator_Comparator_PwrDwnOverrideDisable(void) 
    {
        /* Reset the pd_override bit in CMP_CR register */
        Elevator_Comparator_CR &= ~Elevator_Comparator_PWRDWN_OVRD;
    }
#endif /* (CY_PSOC3 || CY_PSOC5LP) */


/* [] END OF FILE */
