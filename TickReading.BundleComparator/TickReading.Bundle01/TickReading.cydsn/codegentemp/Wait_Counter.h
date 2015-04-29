/*******************************************************************************
* File Name: Wait_Counter.h  
* Version 2.20
*
*  Description:
*   Contains the function prototypes and constants available to the counter
*   user module.
*
*   Note:
*    None
*
********************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
********************************************************************************/
    
#if !defined(CY_COUNTER_Wait_Counter_H)
#define CY_COUNTER_Wait_Counter_H

#include "cytypes.h"
#include "cyfitter.h"
#include "CyLib.h" /* For CyEnterCriticalSection() and CyExitCriticalSection() functions */

/* Check to see if required defines such as CY_PSOC5LP are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5LP)
    #error Component Counter_v2_20 requires cy_boot v3.0 or later
#endif /* (CY_ PSOC5LP) */


/**************************************
*           Parameter Defaults        
**************************************/

#define Wait_Counter_Resolution            16u
#define Wait_Counter_UsingFixedFunction    1u
#define Wait_Counter_ControlRegRemoved     0u
#define Wait_Counter_COMPARE_MODE_SOFTWARE 0u
#define Wait_Counter_CAPTURE_MODE_SOFTWARE 0u
#define Wait_Counter_RunModeUsed           1u


/***************************************
*       Type defines
***************************************/


/**************************************************************************
 * Sleep Mode API Support
 * Backup structure for Sleep Wake up operations
 *************************************************************************/
typedef struct Wait_Counter_backupStruct
{
    /* Sleep BackUp structure */
    uint8 CounterEnableState; 
    #if (CY_PSOC5A)
        uint16 CounterUdb;    /* Current Counter Value      */
        uint16 CounterPeriod; /* Counter Period Value       */
        uint16 CompareValue;  /* Counter Compare Value      */           
        uint8 InterruptMaskValue; /* Counter Compare Value */
    #endif /* (CY_PSOC5A) */

    #if (CY_PSOC3 || CY_PSOC5LP)
            uint16 CounterUdb;
            uint8 InterruptMaskValue;
    #endif /* (CY_PSOC3 || CY_PSOC5LP) */

    #if (!Wait_Counter_ControlRegRemoved)
        uint8 CounterControlRegister;          /* Counter Control Register   */
    #endif /* (!Wait_Counter_ControlRegRemoved) */
}Wait_Counter_backupStruct;


/**************************************
 *  Function Prototypes
 *************************************/
void    Wait_Counter_Start(void) ;
void    Wait_Counter_Stop(void) ;
void    Wait_Counter_SetInterruptMode(uint8 interruptsMask) ;
uint8   Wait_Counter_ReadStatusRegister(void) ;
#define Wait_Counter_GetInterruptSource() Wait_Counter_ReadStatusRegister()
#if(!Wait_Counter_ControlRegRemoved)
    uint8   Wait_Counter_ReadControlRegister(void) ;
    void    Wait_Counter_WriteControlRegister(uint8 control) \
        ;
#endif /* (!Wait_Counter_ControlRegRemoved) */
#if (!(Wait_Counter_UsingFixedFunction && (CY_PSOC5A)))
    void    Wait_Counter_WriteCounter(uint16 counter) \
            ; 
#endif /* (!(Wait_Counter_UsingFixedFunction && (CY_PSOC5A))) */
uint16  Wait_Counter_ReadCounter(void) ;
uint16  Wait_Counter_ReadCapture(void) ;
void    Wait_Counter_WritePeriod(uint16 period) \
    ;
uint16  Wait_Counter_ReadPeriod( void ) ;
#if (!Wait_Counter_UsingFixedFunction)
    void    Wait_Counter_WriteCompare(uint16 compare) \
        ;
    uint16  Wait_Counter_ReadCompare( void ) \
        ;
#endif /* (!Wait_Counter_UsingFixedFunction) */

#if (Wait_Counter_COMPARE_MODE_SOFTWARE)
    void    Wait_Counter_SetCompareMode(uint8 comparemode) ;
#endif /* (Wait_Counter_COMPARE_MODE_SOFTWARE) */
#if (Wait_Counter_CAPTURE_MODE_SOFTWARE)
    void    Wait_Counter_SetCaptureMode(uint8 capturemode) ;
#endif /* (Wait_Counter_CAPTURE_MODE_SOFTWARE) */
void Wait_Counter_ClearFIFO(void)     ;
void Wait_Counter_Init(void)          ;
void Wait_Counter_Enable(void)        ;
void Wait_Counter_SaveConfig(void)    ;
void Wait_Counter_RestoreConfig(void) ;
void Wait_Counter_Sleep(void)         ;
void Wait_Counter_Wakeup(void)        ;


/***************************************
*   Enumerated Types and Parameters
***************************************/

/* Enumerated Type B_Counter__CompareModes, Used in Compare Mode retained for backward compatibility of tests*/
#define Wait_Counter__B_COUNTER__LESS_THAN 1
#define Wait_Counter__B_COUNTER__LESS_THAN_OR_EQUAL 2
#define Wait_Counter__B_COUNTER__EQUAL 0
#define Wait_Counter__B_COUNTER__GREATER_THAN 3
#define Wait_Counter__B_COUNTER__GREATER_THAN_OR_EQUAL 4
#define Wait_Counter__B_COUNTER__SOFTWARE 5

/* Enumerated Type Counter_CompareModes */
#define Wait_Counter_CMP_MODE_LT 1u
#define Wait_Counter_CMP_MODE_LTE 2u
#define Wait_Counter_CMP_MODE_EQ 0u
#define Wait_Counter_CMP_MODE_GT 3u
#define Wait_Counter_CMP_MODE_GTE 4u
#define Wait_Counter_CMP_MODE_SOFTWARE_CONTROLLED 5u

/* Enumerated Type B_Counter__CaptureModes, Used in Capture Mode retained for backward compatibility of tests*/
#define Wait_Counter__B_COUNTER__NONE 0
#define Wait_Counter__B_COUNTER__RISING_EDGE 1
#define Wait_Counter__B_COUNTER__FALLING_EDGE 2
#define Wait_Counter__B_COUNTER__EITHER_EDGE 3
#define Wait_Counter__B_COUNTER__SOFTWARE_CONTROL 4

/* Enumerated Type Counter_CompareModes */
#define Wait_Counter_CAP_MODE_NONE 0u
#define Wait_Counter_CAP_MODE_RISE 1u
#define Wait_Counter_CAP_MODE_FALL 2u
#define Wait_Counter_CAP_MODE_BOTH 3u
#define Wait_Counter_CAP_MODE_SOFTWARE_CONTROLLED 4u


/***************************************
 *  Initialization Values
 **************************************/
#define Wait_Counter_INIT_PERIOD_VALUE       1000u
#define Wait_Counter_INIT_COUNTER_VALUE      1000u
#if (Wait_Counter_UsingFixedFunction)
#define Wait_Counter_INIT_INTERRUPTS_MASK    ((1u << Wait_Counter_STATUS_ZERO_INT_EN_MASK_SHIFT))
#else
#define Wait_Counter_INIT_COMPARE_VALUE      0u
#define Wait_Counter_INIT_INTERRUPTS_MASK ((1u << Wait_Counter_STATUS_ZERO_INT_EN_MASK_SHIFT) | \
        (0u << Wait_Counter_STATUS_CAPTURE_INT_EN_MASK_SHIFT) | \
        (0u << Wait_Counter_STATUS_CMP_INT_EN_MASK_SHIFT) | \
        (0u << Wait_Counter_STATUS_OVERFLOW_INT_EN_MASK_SHIFT) | \
        (0u << Wait_Counter_STATUS_UNDERFLOW_INT_EN_MASK_SHIFT))
#define Wait_Counter_DEFAULT_COMPARE_MODE    (1u << Wait_Counter_CTRL_CMPMODE0_SHIFT)
#define Wait_Counter_DEFAULT_CAPTURE_MODE    (0u << Wait_Counter_CTRL_CAPMODE0_SHIFT)
#endif /* (Wait_Counter_UsingFixedFunction) */


/**************************************
 *  Registers
 *************************************/
#if (Wait_Counter_UsingFixedFunction)
    #define Wait_Counter_STATICCOUNT_LSB     (*(reg16 *) Wait_Counter_CounterHW__CAP0 )
    #define Wait_Counter_STATICCOUNT_LSB_PTR ( (reg16 *) Wait_Counter_CounterHW__CAP0 )
    #define Wait_Counter_PERIOD_LSB          (*(reg16 *) Wait_Counter_CounterHW__PER0 )
    #define Wait_Counter_PERIOD_LSB_PTR      ( (reg16 *) Wait_Counter_CounterHW__PER0 )
    /* MODE must be set to 1 to set the compare value */
    #define Wait_Counter_COMPARE_LSB         (*(reg16 *) Wait_Counter_CounterHW__CNT_CMP0 )
    #define Wait_Counter_COMPARE_LSB_PTR     ( (reg16 *) Wait_Counter_CounterHW__CNT_CMP0 )
    /* MODE must be set to 0 to get the count */
    #define Wait_Counter_COUNTER_LSB         (*(reg16 *) Wait_Counter_CounterHW__CNT_CMP0 )
    #define Wait_Counter_COUNTER_LSB_PTR     ( (reg16 *) Wait_Counter_CounterHW__CNT_CMP0 )
    #define Wait_Counter_RT1                 (*(reg8 *) Wait_Counter_CounterHW__RT1)
    #define Wait_Counter_RT1_PTR             ( (reg8 *) Wait_Counter_CounterHW__RT1)
#else
    #define Wait_Counter_STATICCOUNT_LSB     (*(reg16 *) \
        Wait_Counter_CounterUDB_sC16_counterdp_u0__F0_REG )
    #define Wait_Counter_STATICCOUNT_LSB_PTR ( (reg16 *) \
        Wait_Counter_CounterUDB_sC16_counterdp_u0__F0_REG )
    #define Wait_Counter_PERIOD_LSB          (*(reg16 *) \
        Wait_Counter_CounterUDB_sC16_counterdp_u0__D0_REG )
    #define Wait_Counter_PERIOD_LSB_PTR      ( (reg16 *) \
        Wait_Counter_CounterUDB_sC16_counterdp_u0__D0_REG )
    #define Wait_Counter_COMPARE_LSB         (*(reg16 *) \
        Wait_Counter_CounterUDB_sC16_counterdp_u0__D1_REG )
    #define Wait_Counter_COMPARE_LSB_PTR     ( (reg16 *) \
        Wait_Counter_CounterUDB_sC16_counterdp_u0__D1_REG )
    #define Wait_Counter_COUNTER_LSB         (*(reg16 *) \
        Wait_Counter_CounterUDB_sC16_counterdp_u0__A0_REG )
    #define Wait_Counter_COUNTER_LSB_PTR     ( (reg16 *)\
        Wait_Counter_CounterUDB_sC16_counterdp_u0__A0_REG )

    #define Wait_Counter_AUX_CONTROLDP0 \
        (*(reg8 *) Wait_Counter_CounterUDB_sC16_counterdp_u0__DP_AUX_CTL_REG)
    #define Wait_Counter_AUX_CONTROLDP0_PTR \
        ( (reg8 *) Wait_Counter_CounterUDB_sC16_counterdp_u0__DP_AUX_CTL_REG)
    #if (Wait_Counter_Resolution == 16 || Wait_Counter_Resolution == 24 || Wait_Counter_Resolution == 32)
       #define Wait_Counter_AUX_CONTROLDP1 \
           (*(reg8 *) Wait_Counter_CounterUDB_sC16_counterdp_u1__DP_AUX_CTL_REG)
       #define Wait_Counter_AUX_CONTROLDP1_PTR \
           ( (reg8 *) Wait_Counter_CounterUDB_sC16_counterdp_u1__DP_AUX_CTL_REG)
    #endif /* (Wait_Counter_Resolution == 16 || Wait_Counter_Resolution == 24 || Wait_Counter_Resolution == 32) */
    #if (Wait_Counter_Resolution == 24 || Wait_Counter_Resolution == 32)
       #define Wait_Counter_AUX_CONTROLDP2 \
           (*(reg8 *) Wait_Counter_CounterUDB_sC16_counterdp_u2__DP_AUX_CTL_REG)
       #define Wait_Counter_AUX_CONTROLDP2_PTR \
           ( (reg8 *) Wait_Counter_CounterUDB_sC16_counterdp_u2__DP_AUX_CTL_REG)
    #endif /* (Wait_Counter_Resolution == 24 || Wait_Counter_Resolution == 32) */
    #if (Wait_Counter_Resolution == 32)
       #define Wait_Counter_AUX_CONTROLDP3 \
           (*(reg8 *) Wait_Counter_CounterUDB_sC16_counterdp_u3__DP_AUX_CTL_REG)
       #define Wait_Counter_AUX_CONTROLDP3_PTR \
           ( (reg8 *) Wait_Counter_CounterUDB_sC16_counterdp_u3__DP_AUX_CTL_REG)
    #endif /* (Wait_Counter_Resolution == 32) */
#endif  /* (Wait_Counter_UsingFixedFunction) */

#if (Wait_Counter_UsingFixedFunction)
    #define Wait_Counter_STATUS         (*(reg8 *) Wait_Counter_CounterHW__SR0 )
    /* In Fixed Function Block Status and Mask are the same register */
    #define Wait_Counter_STATUS_MASK             (*(reg8 *) Wait_Counter_CounterHW__SR0 )
    #define Wait_Counter_STATUS_MASK_PTR         ( (reg8 *) Wait_Counter_CounterHW__SR0 )
    #define Wait_Counter_CONTROL                 (*(reg8 *) Wait_Counter_CounterHW__CFG0)
    #define Wait_Counter_CONTROL_PTR             ( (reg8 *) Wait_Counter_CounterHW__CFG0)
    #define Wait_Counter_CONTROL2                (*(reg8 *) Wait_Counter_CounterHW__CFG1)
    #define Wait_Counter_CONTROL2_PTR            ( (reg8 *) Wait_Counter_CounterHW__CFG1)
    #if (CY_PSOC3 || CY_PSOC5LP)
        #define Wait_Counter_CONTROL3       (*(reg8 *) Wait_Counter_CounterHW__CFG2)
        #define Wait_Counter_CONTROL3_PTR   ( (reg8 *) Wait_Counter_CounterHW__CFG2)
    #endif /* (CY_PSOC3 || CY_PSOC5LP) */
    #define Wait_Counter_GLOBAL_ENABLE           (*(reg8 *) Wait_Counter_CounterHW__PM_ACT_CFG)
    #define Wait_Counter_GLOBAL_ENABLE_PTR       ( (reg8 *) Wait_Counter_CounterHW__PM_ACT_CFG)
    #define Wait_Counter_GLOBAL_STBY_ENABLE      (*(reg8 *) Wait_Counter_CounterHW__PM_STBY_CFG)
    #define Wait_Counter_GLOBAL_STBY_ENABLE_PTR  ( (reg8 *) Wait_Counter_CounterHW__PM_STBY_CFG)
    

    /********************************
    *    Constants
    ********************************/

    /* Fixed Function Block Chosen */
    #define Wait_Counter_BLOCK_EN_MASK          Wait_Counter_CounterHW__PM_ACT_MSK
    #define Wait_Counter_BLOCK_STBY_EN_MASK     Wait_Counter_CounterHW__PM_STBY_MSK 
    
    /* Control Register Bit Locations */    
    /* As defined in Register Map, part of TMRX_CFG0 register */
    #define Wait_Counter_CTRL_ENABLE_SHIFT      0x00u
    #define Wait_Counter_ONESHOT_SHIFT          0x02u
    /* Control Register Bit Masks */
    #define Wait_Counter_CTRL_ENABLE            (0x01u << Wait_Counter_CTRL_ENABLE_SHIFT)         
    #define Wait_Counter_ONESHOT                (0x01u << Wait_Counter_ONESHOT_SHIFT)

    /* Control2 Register Bit Masks */
    /* Set the mask for run mode */
    #if (CY_PSOC5A)
        /* Use CFG1 Mode bits to set run mode */
        #define Wait_Counter_CTRL_MODE_SHIFT        0x01u    
        #define Wait_Counter_CTRL_MODE_MASK         (0x07u << Wait_Counter_CTRL_MODE_SHIFT)
    #endif /* (CY_PSOC5A) */
    #if (CY_PSOC3 || CY_PSOC5LP)
        /* Use CFG2 Mode bits to set run mode */
        #define Wait_Counter_CTRL_MODE_SHIFT        0x00u    
        #define Wait_Counter_CTRL_MODE_MASK         (0x03u << Wait_Counter_CTRL_MODE_SHIFT)
    #endif /* (CY_PSOC3 || CY_PSOC5LP) */
    /* Set the mask for interrupt (raw/status register) */
    #define Wait_Counter_CTRL2_IRQ_SEL_SHIFT     0x00u
    #define Wait_Counter_CTRL2_IRQ_SEL          (0x01u << Wait_Counter_CTRL2_IRQ_SEL_SHIFT)     
    
    /* Status Register Bit Locations */
    #define Wait_Counter_STATUS_ZERO_SHIFT      0x07u  /* As defined in Register Map, part of TMRX_SR0 register */ 

    /* Status Register Interrupt Enable Bit Locations */
    #define Wait_Counter_STATUS_ZERO_INT_EN_MASK_SHIFT      (Wait_Counter_STATUS_ZERO_SHIFT - 0x04u)

    /* Status Register Bit Masks */                           
    #define Wait_Counter_STATUS_ZERO            (0x01u << Wait_Counter_STATUS_ZERO_SHIFT)

    /* Status Register Interrupt Bit Masks*/
    #define Wait_Counter_STATUS_ZERO_INT_EN_MASK       (Wait_Counter_STATUS_ZERO >> 0x04u)
    
    /*RT1 Synch Constants: Applicable for PSoC3 and PSoC5LP */
    #define Wait_Counter_RT1_SHIFT            0x04u
    #define Wait_Counter_RT1_MASK             (0x03u << Wait_Counter_RT1_SHIFT)  /* Sync TC and CMP bit masks */
    #define Wait_Counter_SYNC                 (0x03u << Wait_Counter_RT1_SHIFT)
    #define Wait_Counter_SYNCDSI_SHIFT        0x00u
    #define Wait_Counter_SYNCDSI_MASK         (0x0Fu << Wait_Counter_SYNCDSI_SHIFT) /* Sync all DSI inputs */
    #define Wait_Counter_SYNCDSI_EN           (0x0Fu << Wait_Counter_SYNCDSI_SHIFT) /* Sync all DSI inputs */
    
#else /* !Wait_Counter_UsingFixedFunction */
    #define Wait_Counter_STATUS               (* (reg8 *) Wait_Counter_CounterUDB_sSTSReg_rstSts_stsreg__STATUS_REG )
    #define Wait_Counter_STATUS_PTR           (  (reg8 *) Wait_Counter_CounterUDB_sSTSReg_rstSts_stsreg__STATUS_REG )
    #define Wait_Counter_STATUS_MASK          (* (reg8 *) Wait_Counter_CounterUDB_sSTSReg_rstSts_stsreg__MASK_REG )
    #define Wait_Counter_STATUS_MASK_PTR      (  (reg8 *) Wait_Counter_CounterUDB_sSTSReg_rstSts_stsreg__MASK_REG )
    #define Wait_Counter_STATUS_AUX_CTRL      (*(reg8 *) Wait_Counter_CounterUDB_sSTSReg_rstSts_stsreg__STATUS_AUX_CTL_REG)
    #define Wait_Counter_STATUS_AUX_CTRL_PTR  ( (reg8 *) Wait_Counter_CounterUDB_sSTSReg_rstSts_stsreg__STATUS_AUX_CTL_REG)
    #define Wait_Counter_CONTROL              (* (reg8 *) Wait_Counter_CounterUDB_sCTRLReg_SyncCtl_ctrlreg__CONTROL_REG )
    #define Wait_Counter_CONTROL_PTR          (  (reg8 *) Wait_Counter_CounterUDB_sCTRLReg_SyncCtl_ctrlreg__CONTROL_REG )


    /********************************
    *    Constants
    ********************************/
    /* Control Register Bit Locations */
    #define Wait_Counter_CTRL_CMPMODE0_SHIFT    0x00u       /* As defined by Verilog Implementation */
    #define Wait_Counter_CTRL_CAPMODE0_SHIFT    0x03u       /* As defined by Verilog Implementation */
    #define Wait_Counter_CTRL_RESET_SHIFT       0x06u       /* As defined by Verilog Implementation */
    #define Wait_Counter_CTRL_ENABLE_SHIFT      0x07u       /* As defined by Verilog Implementation */
    /* Control Register Bit Masks */
    #define Wait_Counter_CTRL_CMPMODE_MASK      (0x07u << Wait_Counter_CTRL_CMPMODE0_SHIFT)  
    #define Wait_Counter_CTRL_CAPMODE_MASK      (0x03u << Wait_Counter_CTRL_CAPMODE0_SHIFT)  
    #define Wait_Counter_CTRL_RESET             (0x01u << Wait_Counter_CTRL_RESET_SHIFT)  
    #define Wait_Counter_CTRL_ENABLE            (0x01u << Wait_Counter_CTRL_ENABLE_SHIFT) 

    /* Status Register Bit Locations */
    #define Wait_Counter_STATUS_CMP_SHIFT       0x00u       /* As defined by Verilog Implementation */
    #define Wait_Counter_STATUS_ZERO_SHIFT      0x01u       /* As defined by Verilog Implementation */
    #define Wait_Counter_STATUS_OVERFLOW_SHIFT  0x02u       /* As defined by Verilog Implementation */
    #define Wait_Counter_STATUS_UNDERFLOW_SHIFT 0x03u       /* As defined by Verilog Implementation */
    #define Wait_Counter_STATUS_CAPTURE_SHIFT   0x04u       /* As defined by Verilog Implementation */
    #define Wait_Counter_STATUS_FIFOFULL_SHIFT  0x05u       /* As defined by Verilog Implementation */
    #define Wait_Counter_STATUS_FIFONEMP_SHIFT  0x06u       /* As defined by Verilog Implementation */
    /* Status Register Interrupt Enable Bit Locations - UDB Status Interrupt Mask match Status Bit Locations*/
    #define Wait_Counter_STATUS_CMP_INT_EN_MASK_SHIFT       Wait_Counter_STATUS_CMP_SHIFT       
    #define Wait_Counter_STATUS_ZERO_INT_EN_MASK_SHIFT      Wait_Counter_STATUS_ZERO_SHIFT      
    #define Wait_Counter_STATUS_OVERFLOW_INT_EN_MASK_SHIFT  Wait_Counter_STATUS_OVERFLOW_SHIFT  
    #define Wait_Counter_STATUS_UNDERFLOW_INT_EN_MASK_SHIFT Wait_Counter_STATUS_UNDERFLOW_SHIFT 
    #define Wait_Counter_STATUS_CAPTURE_INT_EN_MASK_SHIFT   Wait_Counter_STATUS_CAPTURE_SHIFT   
    #define Wait_Counter_STATUS_FIFOFULL_INT_EN_MASK_SHIFT  Wait_Counter_STATUS_FIFOFULL_SHIFT  
    #define Wait_Counter_STATUS_FIFONEMP_INT_EN_MASK_SHIFT  Wait_Counter_STATUS_FIFONEMP_SHIFT  
    /* Status Register Bit Masks */                
    #define Wait_Counter_STATUS_CMP             (0x01u << Wait_Counter_STATUS_CMP_SHIFT)  
    #define Wait_Counter_STATUS_ZERO            (0x01u << Wait_Counter_STATUS_ZERO_SHIFT) 
    #define Wait_Counter_STATUS_OVERFLOW        (0x01u << Wait_Counter_STATUS_OVERFLOW_SHIFT) 
    #define Wait_Counter_STATUS_UNDERFLOW       (0x01u << Wait_Counter_STATUS_UNDERFLOW_SHIFT) 
    #define Wait_Counter_STATUS_CAPTURE         (0x01u << Wait_Counter_STATUS_CAPTURE_SHIFT) 
    #define Wait_Counter_STATUS_FIFOFULL        (0x01u << Wait_Counter_STATUS_FIFOFULL_SHIFT)
    #define Wait_Counter_STATUS_FIFONEMP        (0x01u << Wait_Counter_STATUS_FIFONEMP_SHIFT)
    /* Status Register Interrupt Bit Masks  - UDB Status Interrupt Mask match Status Bit Locations */
    #define Wait_Counter_STATUS_CMP_INT_EN_MASK            Wait_Counter_STATUS_CMP                    
    #define Wait_Counter_STATUS_ZERO_INT_EN_MASK           Wait_Counter_STATUS_ZERO            
    #define Wait_Counter_STATUS_OVERFLOW_INT_EN_MASK       Wait_Counter_STATUS_OVERFLOW        
    #define Wait_Counter_STATUS_UNDERFLOW_INT_EN_MASK      Wait_Counter_STATUS_UNDERFLOW       
    #define Wait_Counter_STATUS_CAPTURE_INT_EN_MASK        Wait_Counter_STATUS_CAPTURE         
    #define Wait_Counter_STATUS_FIFOFULL_INT_EN_MASK       Wait_Counter_STATUS_FIFOFULL        
    #define Wait_Counter_STATUS_FIFONEMP_INT_EN_MASK       Wait_Counter_STATUS_FIFONEMP         
    

    /* StatusI Interrupt Enable bit Location in the Auxilliary Control Register */
    #define Wait_Counter_STATUS_ACTL_INT_EN     0x10u /* As defined for the ACTL Register */
    
    /* Datapath Auxillary Control Register definitions */
    #define Wait_Counter_AUX_CTRL_FIFO0_CLR         0x01u   /* As defined by Register map */
    #define Wait_Counter_AUX_CTRL_FIFO1_CLR         0x02u   /* As defined by Register map */
    #define Wait_Counter_AUX_CTRL_FIFO0_LVL         0x04u   /* As defined by Register map */
    #define Wait_Counter_AUX_CTRL_FIFO1_LVL         0x08u   /* As defined by Register map */
    #define Wait_Counter_STATUS_ACTL_INT_EN_MASK    0x10u   /* As defined for the ACTL Register */
    
#endif /* Wait_Counter_UsingFixedFunction */

#endif  /* CY_COUNTER_Wait_Counter_H */


/* [] END OF FILE */

