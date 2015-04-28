/*******************************************************************************
* File Name: Camera_Threshold.h  
* Version 1.80
*
*  Description:
*    This file contains the function prototypes and constants used in
*    the 8-bit Voltage DAC (vDAC8) User Module.
*
*   Note:
*     
*
********************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_VDAC8_Camera_Threshold_H) 
#define CY_VDAC8_Camera_Threshold_H

#include "cytypes.h"
#include "cyfitter.h"

/* Check to see if required defines such as CY_PSOC5LP are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5LP)
    #error Component VDAC8_v1_80 requires cy_boot v3.0 or later
#endif /* (CY_ PSOC5LP) */


/***************************************
*       Type defines
***************************************/

/* Sleep Mode API Support */
typedef struct Camera_Threshold_backupStruct
{
    uint8 enableState; 
    uint8 data_value;
}Camera_Threshold_backupStruct;


/***************************************
*        Function Prototypes 
***************************************/

void Camera_Threshold_Start(void)           ;
void Camera_Threshold_Stop(void)            ;
void Camera_Threshold_SetSpeed(uint8 speed) ;
void Camera_Threshold_SetRange(uint8 range) ;
void Camera_Threshold_SetValue(uint8 value) ;
void Camera_Threshold_DacTrim(void)         ;
void Camera_Threshold_Init(void)            ;
void Camera_Threshold_Enable(void)          ;
void Camera_Threshold_SaveConfig(void)      ;
void Camera_Threshold_RestoreConfig(void)   ;
void Camera_Threshold_Sleep(void)           ;
void Camera_Threshold_Wakeup(void)          ;


/***************************************
*            API Constants
***************************************/

/* SetRange constants */

#define Camera_Threshold_RANGE_1V       0x00u
#define Camera_Threshold_RANGE_4V       0x04u


/* Power setting for Start API  */
#define Camera_Threshold_LOWSPEED       0x00u
#define Camera_Threshold_HIGHSPEED      0x02u


/***************************************
*  Initialization Parameter Constants
***************************************/

 /* Default DAC range */
#define Camera_Threshold_DEFAULT_RANGE    0u
 /* Default DAC speed */
#define Camera_Threshold_DEFAULT_SPEED    0u
 /* Default Control */
#define Camera_Threshold_DEFAULT_CNTL      0x00u
/* Default Strobe mode */
#define Camera_Threshold_DEFAULT_STRB     0u
 /* Initial DAC value */
#define Camera_Threshold_DEFAULT_DATA     193u
 /* Default Data Source */
#define Camera_Threshold_DEFAULT_DATA_SRC 0u


/***************************************
*              Registers        
***************************************/

#define Camera_Threshold_CR0         (* (reg8 *) Camera_Threshold_viDAC8__CR0 )
#define Camera_Threshold_CR1         (* (reg8 *) Camera_Threshold_viDAC8__CR1 )
#define Camera_Threshold_Data        (* (reg8 *) Camera_Threshold_viDAC8__D )
#define Camera_Threshold_Data_PTR    (  (reg8 *) Camera_Threshold_viDAC8__D )
#define Camera_Threshold_Strobe      (* (reg8 *) Camera_Threshold_viDAC8__STROBE )
#define Camera_Threshold_SW0         (* (reg8 *) Camera_Threshold_viDAC8__SW0 )
#define Camera_Threshold_SW2         (* (reg8 *) Camera_Threshold_viDAC8__SW2 )
#define Camera_Threshold_SW3         (* (reg8 *) Camera_Threshold_viDAC8__SW3 )
#define Camera_Threshold_SW4         (* (reg8 *) Camera_Threshold_viDAC8__SW4 )
#define Camera_Threshold_TR          (* (reg8 *) Camera_Threshold_viDAC8__TR )
/* Power manager */
#define Camera_Threshold_PWRMGR      (* (reg8 *) Camera_Threshold_viDAC8__PM_ACT_CFG )
  /* Standby Power manager */
#define Camera_Threshold_STBY_PWRMGR (* (reg8 *) Camera_Threshold_viDAC8__PM_STBY_CFG )


/***************************************
*         Register Constants       
***************************************/

/* CR0 vDac Control Register 0 definitions */

/* Bit Field  DAC_HS_MODE                  */
#define Camera_Threshold_HS_MASK        0x02u
#define Camera_Threshold_HS_LOWPOWER    0x00u
#define Camera_Threshold_HS_HIGHSPEED   0x02u

/* Bit Field  DAC_MODE                  */
#define Camera_Threshold_MODE_MASK      0x10u
#define Camera_Threshold_MODE_V         0x00u
#define Camera_Threshold_MODE_I         0x10u

/* Bit Field  DAC_RANGE                  */
#define Camera_Threshold_RANGE_MASK     0x0Cu
#define Camera_Threshold_RANGE_0        0x00u
#define Camera_Threshold_RANGE_1        0x04u

/* CR1 iDac Control Register 1 definitions */

/* Bit Field  DAC_MX_DATA                  */
#define Camera_Threshold_SRC_MASK       0x20u
#define Camera_Threshold_SRC_REG        0x00u
#define Camera_Threshold_SRC_UDB        0x20u

/* This bit enable reset from UDB array      */
#define Camera_Threshold_RESET_MASK     0x10u
#define Camera_Threshold_RESET_ENABLE   0x10u
#define Camera_Threshold_RESET_DISABLE  0x00u

/* This bit enables data from DAC bus      */
#define Camera_Threshold_DACBUS_MASK     0x20u
#define Camera_Threshold_DACBUS_ENABLE   0x20u
#define Camera_Threshold_DACBUS_DISABLE  0x00u

/* DAC STROBE Strobe Control Register definitions */

/* Bit Field  DAC_MX_STROBE                  */
#define Camera_Threshold_STRB_MASK     0x08u
#define Camera_Threshold_STRB_EN       0x08u
#define Camera_Threshold_STRB_DIS      0x00u

/* PM_ACT_CFG (Active Power Mode CFG Register)     */ 
#define Camera_Threshold_ACT_PWR_EN   Camera_Threshold_viDAC8__PM_ACT_MSK
  /* Standby Power enable mask */
#define Camera_Threshold_STBY_PWR_EN  Camera_Threshold_viDAC8__PM_STBY_MSK


/*******************************************************************************
*              Trim    
* Note - VDAC trim values are stored in the "Customer Table" area in * Row 1 of
*the Hidden Flash.  There are 8 bytes of trim data for each VDAC block.
* The values are:
*       I Gain offset, min range, Sourcing
*       I Gain offset, min range, Sinking
*       I Gain offset, med range, Sourcing
*       I Gain offset, med range, Sinking
*       I Gain offset, max range, Sourcing
*       I Gain offset, max range, Sinking
*       V Gain offset, 1V range
*       V Gain offset, 4V range
*
* The data set for the 4 VDACs are arranged using a left side/right side
* approach:
*   Left 0, Left 1, Right 0, Right 1.
* When mapped to the VDAC0 thru VDAC3 as:
*   VDAC 0, VDAC 2, VDAC 1, VDAC 3
*******************************************************************************/
#define Camera_Threshold_TRIM_M7_1V_RNG_OFFSET  0x06u
#define Camera_Threshold_TRIM_M8_4V_RNG_OFFSET  0x07u
/*Constatnt to set DAC in current mode and turnoff output */
#define Camera_Threshold_CUR_MODE_OUT_OFF       0x1Eu 
#define Camera_Threshold_DAC_TRIM_BASE     (Camera_Threshold_viDAC8__TRIM__M1)

#endif /* CY_VDAC8_Camera_Threshold_H  */


/* [] END OF FILE */


