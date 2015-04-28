/*******************************************************************************
* File Name: Camera_Comp.c
* Version 1.90
*
* Description:
*  This file contains the function prototypes and constants used in
*  the Analog Comparator User Module.
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

#if !defined(CY_COMP_Camera_Comp_H) 
#define CY_COMP_Camera_Comp_H

#include "cytypes.h"
#include "CyLib.h"
#include "cyfitter.h" 


#define Camera_Comp_RECALMODE 0u

/* Check to see if required defines such as CY_PSOC5LP are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5LP)
    #error Component Comp_v1_90 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5LP) */


/***************************************
*       Type defines
***************************************/

/* Sleep Mode API Support */
typedef struct Camera_Comp_backupStruct
{
    uint8 enableState;
   /* uint8 compCRReg; */
}Camera_Comp_backupStruct;

#if (CY_PSOC5A)
    /* Stop API changes for PSoC5A */
    typedef struct _Camera_Comp_lowPowerBackupStruct
    {
        uint8 compCRReg;
    }   Camera_Comp_LOWPOWER_BACKUP_STRUCT;
#endif /* CY_PSOC5A */


/**************************************
*        Function Prototypes 
**************************************/

void    Camera_Comp_Start(void)                  ;
void    Camera_Comp_Stop(void)                   ;
void    Camera_Comp_SetSpeed(uint8 speed)        ;
uint8   Camera_Comp_GetCompare(void)             ;
uint16  Camera_Comp_ZeroCal(void)                ;
void    Camera_Comp_LoadTrim(uint16 trimVal)     ;
void Camera_Comp_Init(void)                      ; 
void Camera_Comp_Enable(void)                    ;
void Camera_Comp_trimAdjust(uint8 nibble)        ;
void Camera_Comp_SaveConfig(void)                ;
void Camera_Comp_RestoreConfig(void)             ;
void Camera_Comp_Sleep(void)                     ;
void Camera_Comp_Wakeup(void)                    ;
/* Below APIs are valid only for PSoC3, PSoC5LP silicons.*/
#if (CY_PSOC3 || CY_PSOC5LP) 
    void Camera_Comp_PwrDwnOverrideEnable(void)  ;
    void Camera_Comp_PwrDwnOverrideDisable(void) ;
#endif /* CY_PSOC3 || CY_PSOC5LP */


/**************************************
*           API Constants        
**************************************/

/* Power constants for SetSpeed() function */
#define Camera_Comp_SLOWSPEED   0x00u
#define Camera_Comp_HIGHSPEED   0x01u
#define Camera_Comp_LOWPOWER    0x02u


/***************************************
*         Trim Locations               
****************************************/

/* High speed trim values */
#define Camera_Comp_HS_TRIM_TR0        (CY_GET_XTND_REG8(Camera_Comp_ctComp__TRIM__TR0_HS))

#if (CY_PSOC3 || CY_PSOC5LP)
    #define Camera_Comp_HS_TRIM_TR1    (CY_GET_XTND_REG8(Camera_Comp_ctComp__TRIM__TR1_HS))
#endif /* (CY_PSOC3 || CY_PSOC5LP) */

/* Low speed trim values */
#define Camera_Comp_LS_TRIM_TR0        (CY_GET_XTND_REG8(Camera_Comp_ctComp__TRIM__TR0 + 1))

#if (CY_PSOC3 || CY_PSOC5LP)
    #define Camera_Comp_LS_TRIM_TR1    (CY_GET_XTND_REG8(Camera_Comp_ctComp__TRIM__TR1 + 1))
#endif /* CY_PSOC3 || CY_PSOC5LP */


/**************************************
*           Parameter Defaults        
**************************************/

#define Camera_Comp_DEFAULT_SPEED       1u 
#define Camera_Comp_DEFAULT_HYSTERESIS  0u
#define Camera_Comp_DEFAULT_POLARITY    1u
#define Camera_Comp_DEFAULT_BYPASS_SYNC 0u
#define Camera_Comp_DEFAULT_PWRDWN_OVRD 0u


/**************************************
*             Registers        
**************************************/

#define Camera_Comp_CR      (* (reg8 *) Camera_Comp_ctComp__CR )   /* Config register   */
#define Camera_Comp_CR_PTR  (  (reg8 *) Camera_Comp_ctComp__CR )
#define Camera_Comp_CLK     (* (reg8 *) Camera_Comp_ctComp__CLK )  /* Comp clock control register */
#define Camera_Comp_CLK_PTR (  (reg8 *) Camera_Comp_ctComp__CLK )
#define Camera_Comp_SW0     (* (reg8 *) Camera_Comp_ctComp__SW0 )  /* Routing registers */
#define Camera_Comp_SW0_PTR (  (reg8 *) Camera_Comp_ctComp__SW0 )
#define Camera_Comp_SW2     (* (reg8 *) Camera_Comp_ctComp__SW2 )
#define Camera_Comp_SW2_PTR (  (reg8 *) Camera_Comp_ctComp__SW2 )
#define Camera_Comp_SW3     (* (reg8 *) Camera_Comp_ctComp__SW3 )
#define Camera_Comp_SW3_PTR (  (reg8 *) Camera_Comp_ctComp__SW3 )
#define Camera_Comp_SW4     (* (reg8 *) Camera_Comp_ctComp__SW4 )
#define Camera_Comp_SW4_PTR (  (reg8 *) Camera_Comp_ctComp__SW4 )
#define Camera_Comp_SW6     (* (reg8 *) Camera_Comp_ctComp__SW6 )
#define Camera_Comp_SW6_PTR (  (reg8 *) Camera_Comp_ctComp__SW6 )

/* Trim registers */
/* PSoC5A */
#if (CY_PSOC5A)
    #define Camera_Comp_TR      (* (reg8 *) Camera_Comp_ctComp__TR )   /* Trim registers */
    #define Camera_Comp_TR_PTR  (  (reg8 *) Camera_Comp_ctComp__TR )
#endif /* CY_PSOC5A */

/* PSoC3, PSoC5LP or later */
#if (CY_PSOC3 || CY_PSOC5LP) 
    #define Camera_Comp_TR0         (* (reg8 *) Camera_Comp_ctComp__TR0 ) /* Trim register for P-type load */
    #define Camera_Comp_TR0_PTR     (  (reg8 *) Camera_Comp_ctComp__TR0 ) 
    #define Camera_Comp_TR1         (* (reg8 *) Camera_Comp_ctComp__TR1 ) /* Trim register for N-type load */
    #define Camera_Comp_TR1_PTR     (  (reg8 *) Camera_Comp_ctComp__TR1 ) 
#endif /* CY_PSOC3 || CY_PSOC5LP */

#define Camera_Comp_WRK             (* (reg8 *) Camera_Comp_ctComp__WRK )  /* Working register - output */
#define Camera_Comp_WRK_PTR         (  (reg8 *) Camera_Comp_ctComp__WRK )
#define Camera_Comp_PWRMGR          (* (reg8 *) Camera_Comp_ctComp__PM_ACT_CFG )  /* Active Power manager */
#define Camera_Comp_PWRMGR_PTR      ( (reg8 *) Camera_Comp_ctComp__PM_ACT_CFG )
#define Camera_Comp_STBY_PWRMGR     (* (reg8 *) Camera_Comp_ctComp__PM_STBY_CFG )  /* Standby Power manager */
#define Camera_Comp_STBY_PWRMGR_PTR ( (reg8 *) Camera_Comp_ctComp__PM_STBY_CFG )


/**************************************
*       Register Constants        
**************************************/

/* CR (Comp Control Register)             */
#define Camera_Comp_CFG_MODE_MASK  0x78u
#define Camera_Comp_FILTER_ON      0x40u
#define Camera_Comp_HYST_OFF       0x20u
#define Camera_Comp_CAL_ON         0x10u
#define Camera_Comp_MX_AO          0x08u
#define Camera_Comp_PWRDWN_OVRD    0x04u

#define Camera_Comp_PWR_MODE_SHIFT 0x00u
#define Camera_Comp_PWR_MODE_MASK  (0x03u << Camera_Comp_PWR_MODE_SHIFT)
#define Camera_Comp_PWR_MODE_SLOW  (0x00u << Camera_Comp_PWR_MODE_SHIFT)
#define Camera_Comp_PWR_MODE_FAST  (0x01u << Camera_Comp_PWR_MODE_SHIFT)
#define Camera_Comp_PWR_MODE_ULOW  (0x02u << Camera_Comp_PWR_MODE_SHIFT)

/* CLK (Comp Clock Control Register)      */
#define Camera_Comp_BYPASS_SYNC    0x10u
#define Camera_Comp_SYNC_CLK_EN    0x08u
#define Camera_Comp_SYNCCLK_MASK   (Camera_Comp_BYPASS_SYNC | Camera_Comp_SYNC_CLK_EN)

/* SW3 Routing Register definitions */
#define Camera_Comp_CMP_SW3_INPCTL_MASK    0x09u   /* SW3 bits for inP routing control */

/* TR (Comp Trim Register)     */
#define Camera_Comp_DEFAULT_CMP_TRIM  0x00u

/* PSoC5A */
#if (CY_PSOC5A)
    #define Camera_Comp_CMP_TRIM1_DIR  0x08u   /* Trim direction for N-type load for offset calibration */
    #define Camera_Comp_CMP_TRIM1_MASK 0x07u   /* Trim for N-type load for offset calibration */
    #define Camera_Comp_CMP_TRIM2_DIR  0x80u   /* Trim direction for P-type load for offset calibration */
    #define Camera_Comp_CMP_TRIM2_MASK 0x70u   /* Trim for P-type load for offset calibration */
#endif /* CY_PSOC5A */

/* PSoC3, PSoC5LP or later */
#if (CY_PSOC3 || CY_PSOC5LP)
    #define Camera_Comp_CMP_TR0_DIR 0x10u    /* Trim direction for N-type load for offset calibration */
    #define Camera_Comp_CMP_TR0_MASK 0x0Fu   /* Trim for N-type load for offset calibration */
    #define Camera_Comp_CMP_TR1_DIR 0x10u    /* Trim direction for P-type load for offset calibration */
    #define Camera_Comp_CMP_TR1_MASK 0x07u   /* Trim for P-type load for offset calibration */ 
#endif /* CY_PSOC3 || CY_PSOC5LP */


/* WRK (Comp output working register)     */ 
#define Camera_Comp_CMP_OUT_MASK   Camera_Comp_ctComp__WRK_MASK /* Specific comparator out mask */

/* PM_ACT_CFG7 (Active Power Mode CFG Register)     */ 
#define Camera_Comp_ACT_PWR_EN     Camera_Comp_ctComp__PM_ACT_MSK /* Power enable mask */

/* PM_STBY_CFG7 (Standby Power Mode CFG Register)     */ 
#define Camera_Comp_STBY_PWR_EN     Camera_Comp_ctComp__PM_STBY_MSK /* Standby Power enable mask */

#if (CY_PSOC5A)
    /* For stop API changes mask to make the COMP register CR to 0X00  */
    #define Camera_Comp_COMP_REG_CLR             (0x00u)
#endif /* CY_PSOC5A */

#endif /* CY_COMP_Camera_Comp_H */


/* [] END OF FILE */
