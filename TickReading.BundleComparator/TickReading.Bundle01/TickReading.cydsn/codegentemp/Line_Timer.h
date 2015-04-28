/*******************************************************************************
* File Name: Line_Timer.h
* Version 2.30
*
*  Description:
*     Contains the function prototypes and constants available to the timer
*     user module.
*
*   Note:
*     None
*
********************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
********************************************************************************/

#if !defined(CY_Timer_v2_30_Line_Timer_H)
#define CY_Timer_v2_30_Line_Timer_H

#include "cytypes.h"
#include "cyfitter.h"
#include "CyLib.h" /* For CyEnterCriticalSection() and CyExitCriticalSection() functions */


/* Check to see if required defines such as CY_PSOC5LP are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5LP)
    #error Component Timer_v2_30 requires cy_boot v3.0 or later
#endif /* (CY_ PSOC5LP) */


/**************************************
*           Parameter Defaults
**************************************/

#define Line_Timer_Resolution                 16u
#define Line_Timer_UsingFixedFunction         0u
#define Line_Timer_UsingHWCaptureCounter      0u
#define Line_Timer_SoftwareCaptureMode        0u
#define Line_Timer_SoftwareTriggerMode        0u
#define Line_Timer_UsingHWEnable              1u
#define Line_Timer_EnableTriggerMode          0u
#define Line_Timer_InterruptOnCaptureCount    1u
#define Line_Timer_RunModeUsed                0u
#define Line_Timer_ControlRegRemoved          0u


/***************************************
*       Type defines
***************************************/


/**************************************************************************
 * Sleep Wakeup Backup structure for Timer Component
 *************************************************************************/
typedef struct Line_Timer_backupStruct
{
    uint8 TimerEnableState;
    #if(!Line_Timer_UsingFixedFunction)
        #if (CY_PSOC5A)
            uint16 TimerUdb;                 /* Timer internal counter value */
            uint16 TimerPeriod;              /* Timer Period value       */
            uint8 InterruptMaskValue;       /* Timer Compare Value */
            #if (Line_Timer_UsingHWCaptureCounter)
                uint16 TimerCaptureCounter;  /* Timer Capture Counter Value */
            #endif /* variable declaration for backing up Capture Counter value*/
        #endif /* variables for non retention registers in PSoC5A */

        #if (CY_PSOC3 || CY_PSOC5LP)
            uint16 TimerUdb;
            uint8 InterruptMaskValue;
            #if (Line_Timer_UsingHWCaptureCounter)
                uint16 TimerCaptureCounter;
            #endif /* variable declarations for backing up non retention registers in PSoC3 or PSoC5LP */
        #endif /* (CY_PSOC3 || CY_PSOC5LP) */

        #if (!Line_Timer_ControlRegRemoved)
        uint8 TimerControlRegister;
        #endif /* variable declaration for backing up enable state of the Timer */
    #endif /* define backup variables only for UDB implementation. Fixed function registers are all retention */
}Line_Timer_backupStruct;


/***************************************
*       Function Prototypes
***************************************/

void    Line_Timer_Start(void) ;
void    Line_Timer_Stop(void) ;

void    Line_Timer_SetInterruptMode(uint8 interruptMode) ;
uint8   Line_Timer_ReadStatusRegister(void) ;
/* Deprecated function. Do not use this in future. Retained for backward compatibility */
#define Line_Timer_GetInterruptSource() Line_Timer_ReadStatusRegister()

#if(!Line_Timer_ControlRegRemoved)
    uint8   Line_Timer_ReadControlRegister(void) ;
    void    Line_Timer_WriteControlRegister(uint8 control) \
        ;
#endif /* (!Line_Timer_ControlRegRemoved) */

uint16  Line_Timer_ReadPeriod(void) ;
void    Line_Timer_WritePeriod(uint16 period) \
    ;
uint16  Line_Timer_ReadCounter(void) ;
void    Line_Timer_WriteCounter(uint16 counter) \
    ;
uint16  Line_Timer_ReadCapture(void) ;
void    Line_Timer_SoftwareCapture(void) ;


#if(!Line_Timer_UsingFixedFunction) /* UDB Prototypes */
    #if (Line_Timer_SoftwareCaptureMode)
        void    Line_Timer_SetCaptureMode(uint8 captureMode) ;
    #endif /* (!Line_Timer_UsingFixedFunction) */

    #if (Line_Timer_SoftwareTriggerMode)
        void    Line_Timer_SetTriggerMode(uint8 triggerMode) ;
    #endif /* (Line_Timer_SoftwareTriggerMode) */
    #if (Line_Timer_EnableTriggerMode)
        void    Line_Timer_EnableTrigger(void) ;
        void    Line_Timer_DisableTrigger(void) ;
    #endif /* (Line_Timer_EnableTriggerMode) */

    #if(Line_Timer_InterruptOnCaptureCount)
        #if(!Line_Timer_ControlRegRemoved)
            void    Line_Timer_SetInterruptCount(uint8 interruptCount) \
                ;
        #endif /* (!Line_Timer_ControlRegRemoved) */
    #endif /* (Line_Timer_InterruptOnCaptureCount) */

    #if (Line_Timer_UsingHWCaptureCounter)
        void    Line_Timer_SetCaptureCount(uint8 captureCount) \
            ;
        uint8   Line_Timer_ReadCaptureCount(void) ;
    #endif /* (Line_Timer_UsingHWCaptureCounter) */

    void Line_Timer_ClearFIFO(void) ;
#endif /* UDB Prototypes */

/* Sleep Retention APIs */
void Line_Timer_Init(void)          ;
void Line_Timer_Enable(void)        ;
void Line_Timer_SaveConfig(void)    ;
void Line_Timer_RestoreConfig(void) ;
void Line_Timer_Sleep(void)         ;
void Line_Timer_Wakeup(void)        ;


/***************************************
*   Enumerated Types and Parameters
***************************************/

/* Enumerated Type B_Timer__CaptureModes, Used in Capture Mode */
#define Line_Timer__B_TIMER__CM_NONE 0
#define Line_Timer__B_TIMER__CM_RISINGEDGE 1
#define Line_Timer__B_TIMER__CM_FALLINGEDGE 2
#define Line_Timer__B_TIMER__CM_EITHEREDGE 3
#define Line_Timer__B_TIMER__CM_SOFTWARE 4



/* Enumerated Type B_Timer__TriggerModes, Used in Trigger Mode */
#define Line_Timer__B_TIMER__TM_NONE 0x00u
#define Line_Timer__B_TIMER__TM_RISINGEDGE 0x04u
#define Line_Timer__B_TIMER__TM_FALLINGEDGE 0x08u
#define Line_Timer__B_TIMER__TM_EITHEREDGE 0x0Cu
#define Line_Timer__B_TIMER__TM_SOFTWARE 0x10u


/***************************************
*    Initialial Parameter Constants
***************************************/

#define Line_Timer_INIT_PERIOD             65535u
#define Line_Timer_INIT_CAPTURE_MODE       (2u << Line_Timer_CTRL_CAP_MODE_SHIFT)
#define Line_Timer_INIT_TRIGGER_MODE       (0u << Line_Timer_CTRL_TRIG_MODE_SHIFT)
#if (Line_Timer_UsingFixedFunction)
    #define Line_Timer_INIT_INTERRUPT_MODE ((0u << Line_Timer_STATUS_TC_INT_MASK_SHIFT) | \
                                                  (1 << Line_Timer_STATUS_CAPTURE_INT_MASK_SHIFT))
#else
    #define Line_Timer_INIT_INTERRUPT_MODE ((0u << Line_Timer_STATUS_TC_INT_MASK_SHIFT) | \
                                                 (1 << Line_Timer_STATUS_CAPTURE_INT_MASK_SHIFT) | \
                                                 (0 << Line_Timer_STATUS_FIFOFULL_INT_MASK_SHIFT))
#endif /* (Line_Timer_UsingFixedFunction) */
#define Line_Timer_INIT_CAPTURE_COUNT      (2u)
#define Line_Timer_INIT_INT_CAPTURE_COUNT  ((2u - 1) << Line_Timer_CTRL_INTCNT_SHIFT)


/***************************************
*           Registers
***************************************/

#if (Line_Timer_UsingFixedFunction) /* Implementation Specific Registers and Register Constants */


    /***************************************
    *    Fixed Function Registers
    ***************************************/

    #define Line_Timer_STATUS         (*(reg8 *) Line_Timer_TimerHW__SR0 )
    /* In Fixed Function Block Status and Mask are the same register */
    #define Line_Timer_STATUS_MASK    (*(reg8 *) Line_Timer_TimerHW__SR0 )
    #define Line_Timer_CONTROL        (*(reg8 *) Line_Timer_TimerHW__CFG0)
    #define Line_Timer_CONTROL2       (*(reg8 *) Line_Timer_TimerHW__CFG1)
    #define Line_Timer_CONTROL2_PTR   ( (reg8 *) Line_Timer_TimerHW__CFG1)
    #define Line_Timer_RT1            (*(reg8 *) Line_Timer_TimerHW__RT1)
    #define Line_Timer_RT1_PTR        ( (reg8 *) Line_Timer_TimerHW__RT1)

    #if (CY_PSOC3 || CY_PSOC5LP)
        #define Line_Timer_CONTROL3       (*(reg8 *) Line_Timer_TimerHW__CFG2)
        #define Line_Timer_CONTROL3_PTR   ( (reg8 *) Line_Timer_TimerHW__CFG2)
    #endif /* (CY_PSOC3 || CY_PSOC5LP) */
    #define Line_Timer_GLOBAL_ENABLE  (*(reg8 *) Line_Timer_TimerHW__PM_ACT_CFG)
    #define Line_Timer_GLOBAL_STBY_ENABLE  (*(reg8 *) Line_Timer_TimerHW__PM_STBY_CFG)

    #define Line_Timer_CAPTURE_LSB         (* (reg16 *) Line_Timer_TimerHW__CAP0 )
    #define Line_Timer_CAPTURE_LSB_PTR       ((reg16 *) Line_Timer_TimerHW__CAP0 )
    #define Line_Timer_PERIOD_LSB          (* (reg16 *) Line_Timer_TimerHW__PER0 )
    #define Line_Timer_PERIOD_LSB_PTR        ((reg16 *) Line_Timer_TimerHW__PER0 )
    #define Line_Timer_COUNTER_LSB         (* (reg16 *) Line_Timer_TimerHW__CNT_CMP0 )
    #define Line_Timer_COUNTER_LSB_PTR       ((reg16 *) Line_Timer_TimerHW__CNT_CMP0 )


    /***************************************
    *    Register Constants
    ***************************************/

    /* Fixed Function Block Chosen */
    #define Line_Timer_BLOCK_EN_MASK                     Line_Timer_TimerHW__PM_ACT_MSK
    #define Line_Timer_BLOCK_STBY_EN_MASK                Line_Timer_TimerHW__PM_STBY_MSK

    /* Control Register Bit Locations */
    /* Interrupt Count - Not valid for Fixed Function Block */
    #define Line_Timer_CTRL_INTCNT_SHIFT                  0x00u
    /* Trigger Polarity - Not valid for Fixed Function Block */
    #define Line_Timer_CTRL_TRIG_MODE_SHIFT               0x00u
    /* Trigger Enable - Not valid for Fixed Function Block */
    #define Line_Timer_CTRL_TRIG_EN_SHIFT                 0x00u
    /* Capture Polarity - Not valid for Fixed Function Block */
    #define Line_Timer_CTRL_CAP_MODE_SHIFT                0x00u
    /* Timer Enable - As defined in Register Map, part of TMRX_CFG0 register */
    #define Line_Timer_CTRL_ENABLE_SHIFT                  0x00u

    /* Control Register Bit Masks */
    #define Line_Timer_CTRL_ENABLE                        (0x01u << Line_Timer_CTRL_ENABLE_SHIFT)

    /* Control2 Register Bit Masks */
    /* As defined in Register Map, Part of the TMRX_CFG1 register */
    #define Line_Timer_CTRL2_IRQ_SEL_SHIFT                 0x00u
    #define Line_Timer_CTRL2_IRQ_SEL                      (0x01u << Line_Timer_CTRL2_IRQ_SEL_SHIFT)

    #if (CY_PSOC5A)
        /* Use CFG1 Mode bits to set run mode */
        /* As defined by Verilog Implementation */
        #define Line_Timer_CTRL_MODE_SHIFT                     0x01u
        #define Line_Timer_CTRL_MODE_MASK                     (0x07u << Line_Timer_CTRL_MODE_SHIFT)
    #endif /* (CY_PSOC5A) */
    #if (CY_PSOC3 || CY_PSOC5LP)
        /* Control3 Register Bit Locations */
        #define Line_Timer_CTRL_RCOD_SHIFT        0x02u
        #define Line_Timer_CTRL_ENBL_SHIFT        0x00u
        #define Line_Timer_CTRL_MODE_SHIFT        0x00u

        /* Control3 Register Bit Masks */
        #define Line_Timer_CTRL_RCOD_MASK  (0x03u << Line_Timer_CTRL_RCOD_SHIFT) /* ROD and COD bit masks */
        #define Line_Timer_CTRL_ENBL_MASK  (0x80u << Line_Timer_CTRL_ENBL_SHIFT) /* HW_EN bit mask */
        #define Line_Timer_CTRL_MODE_MASK  (0x03u << Line_Timer_CTRL_MODE_SHIFT) /* Run mode bit mask */

        #define Line_Timer_CTRL_RCOD       (0x03u << Line_Timer_CTRL_RCOD_SHIFT)
        #define Line_Timer_CTRL_ENBL       (0x80u << Line_Timer_CTRL_ENBL_SHIFT)
    #endif /* (CY_PSOC3 || CY_PSOC5LP) */

    /*RT1 Synch Constants: Applicable for PSoC3 and PSoC5LP */
    #define Line_Timer_RT1_SHIFT                       0x04u
    /* Sync TC and CMP bit masks */
    #define Line_Timer_RT1_MASK                        (0x03u << Line_Timer_RT1_SHIFT)
    #define Line_Timer_SYNC                            (0x03u << Line_Timer_RT1_SHIFT)
    #define Line_Timer_SYNCDSI_SHIFT                   0x00u
    /* Sync all DSI inputs with Mask  */
    #define Line_Timer_SYNCDSI_MASK                    (0x0Fu << Line_Timer_SYNCDSI_SHIFT)
    /* Sync all DSI inputs */
    #define Line_Timer_SYNCDSI_EN                      (0x0Fu << Line_Timer_SYNCDSI_SHIFT)

    #define Line_Timer_CTRL_MODE_PULSEWIDTH            (0x01u << Line_Timer_CTRL_MODE_SHIFT)
    #define Line_Timer_CTRL_MODE_PERIOD                (0x02u << Line_Timer_CTRL_MODE_SHIFT)
    #define Line_Timer_CTRL_MODE_CONTINUOUS            (0x00u << Line_Timer_CTRL_MODE_SHIFT)

    /* Status Register Bit Locations */
    /* As defined in Register Map, part of TMRX_SR0 register */
    #define Line_Timer_STATUS_TC_SHIFT                 0x07u
    /* As defined in Register Map, part of TMRX_SR0 register, Shared with Compare Status */
    #define Line_Timer_STATUS_CAPTURE_SHIFT            0x06u
    /* As defined in Register Map, part of TMRX_SR0 register */
    #define Line_Timer_STATUS_TC_INT_MASK_SHIFT        (Line_Timer_STATUS_TC_SHIFT - 4)
    /* As defined in Register Map, part of TMRX_SR0 register, Shared with Compare Status */
    #define Line_Timer_STATUS_CAPTURE_INT_MASK_SHIFT   (Line_Timer_STATUS_CAPTURE_SHIFT - 4)

    /* Status Register Bit Masks */
    #define Line_Timer_STATUS_TC                       (0x01u << Line_Timer_STATUS_TC_SHIFT)
    #define Line_Timer_STATUS_CAPTURE                  (0x01u << Line_Timer_STATUS_CAPTURE_SHIFT)
    /* Interrupt Enable Bit-Mask for interrupt on TC */
    #define Line_Timer_STATUS_TC_INT_MASK              (0x01u << Line_Timer_STATUS_TC_INT_MASK_SHIFT)
    /* Interrupt Enable Bit-Mask for interrupt on Capture */
    #define Line_Timer_STATUS_CAPTURE_INT_MASK         (0x01u << Line_Timer_STATUS_CAPTURE_INT_MASK_SHIFT)

#else   /* UDB Registers and Register Constants */


    /***************************************
    *           UDB Registers
    ***************************************/

    #define Line_Timer_STATUS              (* (reg8 *) Line_Timer_TimerUDB_rstSts_stsreg__STATUS_REG )
    #define Line_Timer_STATUS_MASK         (* (reg8 *) Line_Timer_TimerUDB_rstSts_stsreg__MASK_REG)
    #define Line_Timer_STATUS_AUX_CTRL     (* (reg8 *) Line_Timer_TimerUDB_rstSts_stsreg__STATUS_AUX_CTL_REG)
    #define Line_Timer_CONTROL             (* (reg8 *) Line_Timer_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__CONTROL_REG )

    #define Line_Timer_CAPTURE_LSB         (* (reg16 *) Line_Timer_TimerUDB_sT16_timerdp_u0__F0_REG )
    #define Line_Timer_CAPTURE_LSB_PTR       ((reg16 *) Line_Timer_TimerUDB_sT16_timerdp_u0__F0_REG )
    #define Line_Timer_PERIOD_LSB          (* (reg16 *) Line_Timer_TimerUDB_sT16_timerdp_u0__D0_REG )
    #define Line_Timer_PERIOD_LSB_PTR        ((reg16 *) Line_Timer_TimerUDB_sT16_timerdp_u0__D0_REG )
    #define Line_Timer_COUNTER_LSB         (* (reg16 *) Line_Timer_TimerUDB_sT16_timerdp_u0__A0_REG )
    #define Line_Timer_COUNTER_LSB_PTR       ((reg16 *) Line_Timer_TimerUDB_sT16_timerdp_u0__A0_REG )

    #if (Line_Timer_UsingHWCaptureCounter)
        #define Line_Timer_CAP_COUNT              (*(reg8 *) Line_Timer_TimerUDB_sCapCount_counter__PERIOD_REG )
        #define Line_Timer_CAP_COUNT_PTR          ( (reg8 *) Line_Timer_TimerUDB_sCapCount_counter__PERIOD_REG )
        #define Line_Timer_CAPTURE_COUNT_CTRL     (*(reg8 *) Line_Timer_TimerUDB_sCapCount_counter__CONTROL_AUX_CTL_REG )
        #define Line_Timer_CAPTURE_COUNT_CTRL_PTR ( (reg8 *) Line_Timer_TimerUDB_sCapCount_counter__CONTROL_AUX_CTL_REG )
    #endif /* (Line_Timer_UsingHWCaptureCounter) */


    /***************************************
    *       Register Constants
    ***************************************/

    /* Control Register Bit Locations */
    #define Line_Timer_CTRL_INTCNT_SHIFT              0x00u       /* As defined by Verilog Implementation */
    #define Line_Timer_CTRL_TRIG_MODE_SHIFT           0x02u       /* As defined by Verilog Implementation */
    #define Line_Timer_CTRL_TRIG_EN_SHIFT             0x04u       /* As defined by Verilog Implementation */
    #define Line_Timer_CTRL_CAP_MODE_SHIFT            0x05u       /* As defined by Verilog Implementation */
    #define Line_Timer_CTRL_ENABLE_SHIFT              0x07u       /* As defined by Verilog Implementation */

    /* Control Register Bit Masks */
    #define Line_Timer_CTRL_INTCNT_MASK               (0x03u << Line_Timer_CTRL_INTCNT_SHIFT)
    #define Line_Timer_CTRL_TRIG_MODE_MASK            (0x03u << Line_Timer_CTRL_TRIG_MODE_SHIFT)
    #define Line_Timer_CTRL_TRIG_EN                   (0x01u << Line_Timer_CTRL_TRIG_EN_SHIFT)
    #define Line_Timer_CTRL_CAP_MODE_MASK             (0x03u << Line_Timer_CTRL_CAP_MODE_SHIFT)
    #define Line_Timer_CTRL_ENABLE                    (0x01u << Line_Timer_CTRL_ENABLE_SHIFT)

    /* Bit Counter (7-bit) Control Register Bit Definitions */
    /* As defined by the Register map for the AUX Control Register */
    #define Line_Timer_CNTR_ENABLE                    0x20u

    /* Status Register Bit Locations */
    #define Line_Timer_STATUS_TC_SHIFT                0x00u  /* As defined by Verilog Implementation */
    #define Line_Timer_STATUS_CAPTURE_SHIFT           0x01u  /* As defined by Verilog Implementation */
    #define Line_Timer_STATUS_TC_INT_MASK_SHIFT       Line_Timer_STATUS_TC_SHIFT
    #define Line_Timer_STATUS_CAPTURE_INT_MASK_SHIFT  Line_Timer_STATUS_CAPTURE_SHIFT
    #define Line_Timer_STATUS_FIFOFULL_SHIFT          0x02u  /* As defined by Verilog Implementation */
    #define Line_Timer_STATUS_FIFONEMP_SHIFT          0x03u  /* As defined by Verilog Implementation */
    #define Line_Timer_STATUS_FIFOFULL_INT_MASK_SHIFT Line_Timer_STATUS_FIFOFULL_SHIFT

    /* Status Register Bit Masks */
    /* Sticky TC Event Bit-Mask */
    #define Line_Timer_STATUS_TC                      (0x01u << Line_Timer_STATUS_TC_SHIFT)
    /* Sticky Capture Event Bit-Mask */
    #define Line_Timer_STATUS_CAPTURE                 (0x01u << Line_Timer_STATUS_CAPTURE_SHIFT)
    /* Interrupt Enable Bit-Mask */
    #define Line_Timer_STATUS_TC_INT_MASK             (0x01u << Line_Timer_STATUS_TC_SHIFT)
    /* Interrupt Enable Bit-Mask */
    #define Line_Timer_STATUS_CAPTURE_INT_MASK        (0x01u << Line_Timer_STATUS_CAPTURE_SHIFT)
    /* NOT-Sticky FIFO Full Bit-Mask */
    #define Line_Timer_STATUS_FIFOFULL                (0x01u << Line_Timer_STATUS_FIFOFULL_SHIFT)
    /* NOT-Sticky FIFO Not Empty Bit-Mask */
    #define Line_Timer_STATUS_FIFONEMP                (0x01u << Line_Timer_STATUS_FIFONEMP_SHIFT)
    /* Interrupt Enable Bit-Mask */
    #define Line_Timer_STATUS_FIFOFULL_INT_MASK       (0x01u << Line_Timer_STATUS_FIFOFULL_SHIFT)

    #define Line_Timer_STATUS_ACTL_INT_EN             0x10u   /* As defined for the ACTL Register */

    /* Datapath Auxillary Control Register definitions */
    #define Line_Timer_AUX_CTRL_FIFO0_CLR             0x01u   /* As defined by Register map */
    #define Line_Timer_AUX_CTRL_FIFO1_CLR             0x02u   /* As defined by Register map */
    #define Line_Timer_AUX_CTRL_FIFO0_LVL             0x04u   /* As defined by Register map */
    #define Line_Timer_AUX_CTRL_FIFO1_LVL             0x08u   /* As defined by Register map */
    #define Line_Timer_STATUS_ACTL_INT_EN_MASK        0x10u   /* As defined for the ACTL Register */

#endif /* Implementation Specific Registers and Register Constants */

#endif  /* CY_Timer_v2_30_Line_Timer_H */


/* [] END OF FILE */
