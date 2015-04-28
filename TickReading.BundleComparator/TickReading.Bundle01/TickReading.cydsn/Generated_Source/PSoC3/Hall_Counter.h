/*******************************************************************************
* File Name: Hall_Counter.h  
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
    
#if !defined(CY_COUNTER_Hall_Counter_H)
#define CY_COUNTER_Hall_Counter_H

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

#define Hall_Counter_Resolution            24u
#define Hall_Counter_UsingFixedFunction    0u
#define Hall_Counter_ControlRegRemoved     0u
#define Hall_Counter_COMPARE_MODE_SOFTWARE 0u
#define Hall_Counter_CAPTURE_MODE_SOFTWARE 0u
#define Hall_Counter_RunModeUsed           0u


/***************************************
*       Type defines
***************************************/


/**************************************************************************
 * Sleep Mode API Support
 * Backup structure for Sleep Wake up operations
 *************************************************************************/
typedef struct Hall_Counter_backupStruct
{
    /* Sleep BackUp structure */
    uint8 CounterEnableState; 
    #if (CY_PSOC5A)
        uint32 CounterUdb;    /* Current Counter Value      */
        uint32 CounterPeriod; /* Counter Period Value       */
        uint32 CompareValue;  /* Counter Compare Value      */           
        uint8 InterruptMaskValue; /* Counter Compare Value */
    #endif /* (CY_PSOC5A) */

    #if (CY_PSOC3 || CY_PSOC5LP)
            uint32 CounterUdb;
            uint8 InterruptMaskValue;
    #endif /* (CY_PSOC3 || CY_PSOC5LP) */

    #if (!Hall_Counter_ControlRegRemoved)
        uint8 CounterControlRegister;          /* Counter Control Register   */
    #endif /* (!Hall_Counter_ControlRegRemoved) */
}Hall_Counter_backupStruct;


/**************************************
 *  Function Prototypes
 *************************************/
void    Hall_Counter_Start(void) ;
void    Hall_Counter_Stop(void) ;
void    Hall_Counter_SetInterruptMode(uint8 interruptsMask) ;
uint8   Hall_Counter_ReadStatusRegister(void) ;
#define Hall_Counter_GetInterruptSource() Hall_Counter_ReadStatusRegister()
#if(!Hall_Counter_ControlRegRemoved)
    uint8   Hall_Counter_ReadControlRegister(void) ;
    void    Hall_Counter_WriteControlRegister(uint8 control) \
        ;
#endif /* (!Hall_Counter_ControlRegRemoved) */
#if (!(Hall_Counter_UsingFixedFunction && (CY_PSOC5A)))
    void    Hall_Counter_WriteCounter(uint32 counter) \
            ; 
#endif /* (!(Hall_Counter_UsingFixedFunction && (CY_PSOC5A))) */
uint32  Hall_Counter_ReadCounter(void) ;
uint32  Hall_Counter_ReadCapture(void) ;
void    Hall_Counter_WritePeriod(uint32 period) \
    ;
uint32  Hall_Counter_ReadPeriod( void ) ;
#if (!Hall_Counter_UsingFixedFunction)
    void    Hall_Counter_WriteCompare(uint32 compare) \
        ;
    uint32  Hall_Counter_ReadCompare( void ) \
        ;
#endif /* (!Hall_Counter_UsingFixedFunction) */

#if (Hall_Counter_COMPARE_MODE_SOFTWARE)
    void    Hall_Counter_SetCompareMode(uint8 comparemode) ;
#endif /* (Hall_Counter_COMPARE_MODE_SOFTWARE) */
#if (Hall_Counter_CAPTURE_MODE_SOFTWARE)
    void    Hall_Counter_SetCaptureMode(uint8 capturemode) ;
#endif /* (Hall_Counter_CAPTURE_MODE_SOFTWARE) */
void Hall_Counter_ClearFIFO(void)     ;
void Hall_Counter_Init(void)          ;
void Hall_Counter_Enable(void)        ;
void Hall_Counter_SaveConfig(void)    ;
void Hall_Counter_RestoreConfig(void) ;
void Hall_Counter_Sleep(void)         ;
void Hall_Counter_Wakeup(void)        ;


/***************************************
*   Enumerated Types and Parameters
***************************************/

/* Enumerated Type B_Counter__CompareModes, Used in Compare Mode retained for backward compatibility of tests*/
#define Hall_Counter__B_COUNTER__LESS_THAN 1
#define Hall_Counter__B_COUNTER__LESS_THAN_OR_EQUAL 2
#define Hall_Counter__B_COUNTER__EQUAL 0
#define Hall_Counter__B_COUNTER__GREATER_THAN 3
#define Hall_Counter__B_COUNTER__GREATER_THAN_OR_EQUAL 4
#define Hall_Counter__B_COUNTER__SOFTWARE 5

/* Enumerated Type Counter_CompareModes */
#define Hall_Counter_CMP_MODE_LT 1u
#define Hall_Counter_CMP_MODE_LTE 2u
#define Hall_Counter_CMP_MODE_EQ 0u
#define Hall_Counter_CMP_MODE_GT 3u
#define Hall_Counter_CMP_MODE_GTE 4u
#define Hall_Counter_CMP_MODE_SOFTWARE_CONTROLLED 5u

/* Enumerated Type B_Counter__CaptureModes, Used in Capture Mode retained for backward compatibility of tests*/
#define Hall_Counter__B_COUNTER__NONE 0
#define Hall_Counter__B_COUNTER__RISING_EDGE 1
#define Hall_Counter__B_COUNTER__FALLING_EDGE 2
#define Hall_Counter__B_COUNTER__EITHER_EDGE 3
#define Hall_Counter__B_COUNTER__SOFTWARE_CONTROL 4

/* Enumerated Type Counter_CompareModes */
#define Hall_Counter_CAP_MODE_NONE 0u
#define Hall_Counter_CAP_MODE_RISE 1u
#define Hall_Counter_CAP_MODE_FALL 2u
#define Hall_Counter_CAP_MODE_BOTH 3u
#define Hall_Counter_CAP_MODE_SOFTWARE_CONTROLLED 4u


/***************************************
 *  Initialization Values
 **************************************/
#define Hall_Counter_INIT_PERIOD_VALUE       16777215u
#define Hall_Counter_INIT_COUNTER_VALUE      0u
#if (Hall_Counter_UsingFixedFunction)
#define Hall_Counter_INIT_INTERRUPTS_MASK    ((0u << Hall_Counter_STATUS_ZERO_INT_EN_MASK_SHIFT))
#else
#define Hall_Counter_INIT_COMPARE_VALUE      128u
#define Hall_Counter_INIT_INTERRUPTS_MASK ((0u << Hall_Counter_STATUS_ZERO_INT_EN_MASK_SHIFT) | \
        (1u << Hall_Counter_STATUS_CAPTURE_INT_EN_MASK_SHIFT) | \
        (0u << Hall_Counter_STATUS_CMP_INT_EN_MASK_SHIFT) | \
        (1u << Hall_Counter_STATUS_OVERFLOW_INT_EN_MASK_SHIFT) | \
        (1u << Hall_Counter_STATUS_UNDERFLOW_INT_EN_MASK_SHIFT))
#define Hall_Counter_DEFAULT_COMPARE_MODE    (1u << Hall_Counter_CTRL_CMPMODE0_SHIFT)
#define Hall_Counter_DEFAULT_CAPTURE_MODE    (1u << Hall_Counter_CTRL_CAPMODE0_SHIFT)
#endif /* (Hall_Counter_UsingFixedFunction) */


/**************************************
 *  Registers
 *************************************/
#if (Hall_Counter_UsingFixedFunction)
    #define Hall_Counter_STATICCOUNT_LSB     (*(reg16 *) Hall_Counter_CounterHW__CAP0 )
    #define Hall_Counter_STATICCOUNT_LSB_PTR ( (reg16 *) Hall_Counter_CounterHW__CAP0 )
    #define Hall_Counter_PERIOD_LSB          (*(reg16 *) Hall_Counter_CounterHW__PER0 )
    #define Hall_Counter_PERIOD_LSB_PTR      ( (reg16 *) Hall_Counter_CounterHW__PER0 )
    /* MODE must be set to 1 to set the compare value */
    #define Hall_Counter_COMPARE_LSB         (*(reg16 *) Hall_Counter_CounterHW__CNT_CMP0 )
    #define Hall_Counter_COMPARE_LSB_PTR     ( (reg16 *) Hall_Counter_CounterHW__CNT_CMP0 )
    /* MODE must be set to 0 to get the count */
    #define Hall_Counter_COUNTER_LSB         (*(reg16 *) Hall_Counter_CounterHW__CNT_CMP0 )
    #define Hall_Counter_COUNTER_LSB_PTR     ( (reg16 *) Hall_Counter_CounterHW__CNT_CMP0 )
    #define Hall_Counter_RT1                 (*(reg8 *) Hall_Counter_CounterHW__RT1)
    #define Hall_Counter_RT1_PTR             ( (reg8 *) Hall_Counter_CounterHW__RT1)
#else
    #define Hall_Counter_STATICCOUNT_LSB     (*(reg32 *) \
        Hall_Counter_CounterUDB_sC24_counterdp_u0__F0_REG )
    #define Hall_Counter_STATICCOUNT_LSB_PTR ( (reg32 *) \
        Hall_Counter_CounterUDB_sC24_counterdp_u0__F0_REG )
    #define Hall_Counter_PERIOD_LSB          (*(reg32 *) \
        Hall_Counter_CounterUDB_sC24_counterdp_u0__D0_REG )
    #define Hall_Counter_PERIOD_LSB_PTR      ( (reg32 *) \
        Hall_Counter_CounterUDB_sC24_counterdp_u0__D0_REG )
    #define Hall_Counter_COMPARE_LSB         (*(reg32 *) \
        Hall_Counter_CounterUDB_sC24_counterdp_u0__D1_REG )
    #define Hall_Counter_COMPARE_LSB_PTR     ( (reg32 *) \
        Hall_Counter_CounterUDB_sC24_counterdp_u0__D1_REG )
    #define Hall_Counter_COUNTER_LSB         (*(reg32 *) \
        Hall_Counter_CounterUDB_sC24_counterdp_u0__A0_REG )
    #define Hall_Counter_COUNTER_LSB_PTR     ( (reg32 *)\
        Hall_Counter_CounterUDB_sC24_counterdp_u0__A0_REG )

    #define Hall_Counter_AUX_CONTROLDP0 \
        (*(reg8 *) Hall_Counter_CounterUDB_sC24_counterdp_u0__DP_AUX_CTL_REG)
    #define Hall_Counter_AUX_CONTROLDP0_PTR \
        ( (reg8 *) Hall_Counter_CounterUDB_sC24_counterdp_u0__DP_AUX_CTL_REG)
    #if (Hall_Counter_Resolution == 16 || Hall_Counter_Resolution == 24 || Hall_Counter_Resolution == 32)
       #define Hall_Counter_AUX_CONTROLDP1 \
           (*(reg8 *) Hall_Counter_CounterUDB_sC24_counterdp_u1__DP_AUX_CTL_REG)
       #define Hall_Counter_AUX_CONTROLDP1_PTR \
           ( (reg8 *) Hall_Counter_CounterUDB_sC24_counterdp_u1__DP_AUX_CTL_REG)
    #endif /* (Hall_Counter_Resolution == 16 || Hall_Counter_Resolution == 24 || Hall_Counter_Resolution == 32) */
    #if (Hall_Counter_Resolution == 24 || Hall_Counter_Resolution == 32)
       #define Hall_Counter_AUX_CONTROLDP2 \
           (*(reg8 *) Hall_Counter_CounterUDB_sC24_counterdp_u2__DP_AUX_CTL_REG)
       #define Hall_Counter_AUX_CONTROLDP2_PTR \
           ( (reg8 *) Hall_Counter_CounterUDB_sC24_counterdp_u2__DP_AUX_CTL_REG)
    #endif /* (Hall_Counter_Resolution == 24 || Hall_Counter_Resolution == 32) */
    #if (Hall_Counter_Resolution == 32)
       #define Hall_Counter_AUX_CONTROLDP3 \
           (*(reg8 *) Hall_Counter_CounterUDB_sC24_counterdp_u3__DP_AUX_CTL_REG)
       #define Hall_Counter_AUX_CONTROLDP3_PTR \
           ( (reg8 *) Hall_Counter_CounterUDB_sC24_counterdp_u3__DP_AUX_CTL_REG)
    #endif /* (Hall_Counter_Resolution == 32) */
#endif  /* (Hall_Counter_UsingFixedFunction) */

#if (Hall_Counter_UsingFixedFunction)
    #define Hall_Counter_STATUS         (*(reg8 *) Hall_Counter_CounterHW__SR0 )
    /* In Fixed Function Block Status and Mask are the same register */
    #define Hall_Counter_STATUS_MASK             (*(reg8 *) Hall_Counter_CounterHW__SR0 )
    #define Hall_Counter_STATUS_MASK_PTR         ( (reg8 *) Hall_Counter_CounterHW__SR0 )
    #define Hall_Counter_CONTROL                 (*(reg8 *) Hall_Counter_CounterHW__CFG0)
    #define Hall_Counter_CONTROL_PTR             ( (reg8 *) Hall_Counter_CounterHW__CFG0)
    #define Hall_Counter_CONTROL2                (*(reg8 *) Hall_Counter_CounterHW__CFG1)
    #define Hall_Counter_CONTROL2_PTR            ( (reg8 *) Hall_Counter_CounterHW__CFG1)
    #if (CY_PSOC3 || CY_PSOC5LP)
        #define Hall_Counter_CONTROL3       (*(reg8 *) Hall_Counter_CounterHW__CFG2)
        #define Hall_Counter_CONTROL3_PTR   ( (reg8 *) Hall_Counter_CounterHW__CFG2)
    #endif /* (CY_PSOC3 || CY_PSOC5LP) */
    #define Hall_Counter_GLOBAL_ENABLE           (*(reg8 *) Hall_Counter_CounterHW__PM_ACT_CFG)
    #define Hall_Counter_GLOBAL_ENABLE_PTR       ( (reg8 *) Hall_Counter_CounterHW__PM_ACT_CFG)
    #define Hall_Counter_GLOBAL_STBY_ENABLE      (*(reg8 *) Hall_Counter_CounterHW__PM_STBY_CFG)
    #define Hall_Counter_GLOBAL_STBY_ENABLE_PTR  ( (reg8 *) Hall_Counter_CounterHW__PM_STBY_CFG)
    

    /********************************
    *    Constants
    ********************************/

    /* Fixed Function Block Chosen */
    #define Hall_Counter_BLOCK_EN_MASK          Hall_Counter_CounterHW__PM_ACT_MSK
    #define Hall_Counter_BLOCK_STBY_EN_MASK     Hall_Counter_CounterHW__PM_STBY_MSK 
    
    /* Control Register Bit Locations */    
    /* As defined in Register Map, part of TMRX_CFG0 register */
    #define Hall_Counter_CTRL_ENABLE_SHIFT      0x00u
    #define Hall_Counter_ONESHOT_SHIFT          0x02u
    /* Control Register Bit Masks */
    #define Hall_Counter_CTRL_ENABLE            (0x01u << Hall_Counter_CTRL_ENABLE_SHIFT)         
    #define Hall_Counter_ONESHOT                (0x01u << Hall_Counter_ONESHOT_SHIFT)

    /* Control2 Register Bit Masks */
    /* Set the mask for run mode */
    #if (CY_PSOC5A)
        /* Use CFG1 Mode bits to set run mode */
        #define Hall_Counter_CTRL_MODE_SHIFT        0x01u    
        #define Hall_Counter_CTRL_MODE_MASK         (0x07u << Hall_Counter_CTRL_MODE_SHIFT)
    #endif /* (CY_PSOC5A) */
    #if (CY_PSOC3 || CY_PSOC5LP)
        /* Use CFG2 Mode bits to set run mode */
        #define Hall_Counter_CTRL_MODE_SHIFT        0x00u    
        #define Hall_Counter_CTRL_MODE_MASK         (0x03u << Hall_Counter_CTRL_MODE_SHIFT)
    #endif /* (CY_PSOC3 || CY_PSOC5LP) */
    /* Set the mask for interrupt (raw/status register) */
    #define Hall_Counter_CTRL2_IRQ_SEL_SHIFT     0x00u
    #define Hall_Counter_CTRL2_IRQ_SEL          (0x01u << Hall_Counter_CTRL2_IRQ_SEL_SHIFT)     
    
    /* Status Register Bit Locations */
    #define Hall_Counter_STATUS_ZERO_SHIFT      0x07u  /* As defined in Register Map, part of TMRX_SR0 register */ 

    /* Status Register Interrupt Enable Bit Locations */
    #define Hall_Counter_STATUS_ZERO_INT_EN_MASK_SHIFT      (Hall_Counter_STATUS_ZERO_SHIFT - 0x04u)

    /* Status Register Bit Masks */                           
    #define Hall_Counter_STATUS_ZERO            (0x01u << Hall_Counter_STATUS_ZERO_SHIFT)

    /* Status Register Interrupt Bit Masks*/
    #define Hall_Counter_STATUS_ZERO_INT_EN_MASK       (Hall_Counter_STATUS_ZERO >> 0x04u)
    
    /*RT1 Synch Constants: Applicable for PSoC3 and PSoC5LP */
    #define Hall_Counter_RT1_SHIFT            0x04u
    #define Hall_Counter_RT1_MASK             (0x03u << Hall_Counter_RT1_SHIFT)  /* Sync TC and CMP bit masks */
    #define Hall_Counter_SYNC                 (0x03u << Hall_Counter_RT1_SHIFT)
    #define Hall_Counter_SYNCDSI_SHIFT        0x00u
    #define Hall_Counter_SYNCDSI_MASK         (0x0Fu << Hall_Counter_SYNCDSI_SHIFT) /* Sync all DSI inputs */
    #define Hall_Counter_SYNCDSI_EN           (0x0Fu << Hall_Counter_SYNCDSI_SHIFT) /* Sync all DSI inputs */
    
#else /* !Hall_Counter_UsingFixedFunction */
    #define Hall_Counter_STATUS               (* (reg8 *) Hall_Counter_CounterUDB_sSTSReg_rstSts_stsreg__STATUS_REG )
    #define Hall_Counter_STATUS_PTR           (  (reg8 *) Hall_Counter_CounterUDB_sSTSReg_rstSts_stsreg__STATUS_REG )
    #define Hall_Counter_STATUS_MASK          (* (reg8 *) Hall_Counter_CounterUDB_sSTSReg_rstSts_stsreg__MASK_REG )
    #define Hall_Counter_STATUS_MASK_PTR      (  (reg8 *) Hall_Counter_CounterUDB_sSTSReg_rstSts_stsreg__MASK_REG )
    #define Hall_Counter_STATUS_AUX_CTRL      (*(reg8 *) Hall_Counter_CounterUDB_sSTSReg_rstSts_stsreg__STATUS_AUX_CTL_REG)
    #define Hall_Counter_STATUS_AUX_CTRL_PTR  ( (reg8 *) Hall_Counter_CounterUDB_sSTSReg_rstSts_stsreg__STATUS_AUX_CTL_REG)
    #define Hall_Counter_CONTROL              (* (reg8 *) Hall_Counter_CounterUDB_sCTRLReg_SyncCtl_ctrlreg__CONTROL_REG )
    #define Hall_Counter_CONTROL_PTR          (  (reg8 *) Hall_Counter_CounterUDB_sCTRLReg_SyncCtl_ctrlreg__CONTROL_REG )


    /********************************
    *    Constants
    ********************************/
    /* Control Register Bit Locations */
    #define Hall_Counter_CTRL_CMPMODE0_SHIFT    0x00u       /* As defined by Verilog Implementation */
    #define Hall_Counter_CTRL_CAPMODE0_SHIFT    0x03u       /* As defined by Verilog Implementation */
    #define Hall_Counter_CTRL_RESET_SHIFT       0x06u       /* As defined by Verilog Implementation */
    #define Hall_Counter_CTRL_ENABLE_SHIFT      0x07u       /* As defined by Verilog Implementation */
    /* Control Register Bit Masks */
    #define Hall_Counter_CTRL_CMPMODE_MASK      (0x07u << Hall_Counter_CTRL_CMPMODE0_SHIFT)  
    #define Hall_Counter_CTRL_CAPMODE_MASK      (0x03u << Hall_Counter_CTRL_CAPMODE0_SHIFT)  
    #define Hall_Counter_CTRL_RESET             (0x01u << Hall_Counter_CTRL_RESET_SHIFT)  
    #define Hall_Counter_CTRL_ENABLE            (0x01u << Hall_Counter_CTRL_ENABLE_SHIFT) 

    /* Status Register Bit Locations */
    #define Hall_Counter_STATUS_CMP_SHIFT       0x00u       /* As defined by Verilog Implementation */
    #define Hall_Counter_STATUS_ZERO_SHIFT      0x01u       /* As defined by Verilog Implementation */
    #define Hall_Counter_STATUS_OVERFLOW_SHIFT  0x02u       /* As defined by Verilog Implementation */
    #define Hall_Counter_STATUS_UNDERFLOW_SHIFT 0x03u       /* As defined by Verilog Implementation */
    #define Hall_Counter_STATUS_CAPTURE_SHIFT   0x04u       /* As defined by Verilog Implementation */
    #define Hall_Counter_STATUS_FIFOFULL_SHIFT  0x05u       /* As defined by Verilog Implementation */
    #define Hall_Counter_STATUS_FIFONEMP_SHIFT  0x06u       /* As defined by Verilog Implementation */
    /* Status Register Interrupt Enable Bit Locations - UDB Status Interrupt Mask match Status Bit Locations*/
    #define Hall_Counter_STATUS_CMP_INT_EN_MASK_SHIFT       Hall_Counter_STATUS_CMP_SHIFT       
    #define Hall_Counter_STATUS_ZERO_INT_EN_MASK_SHIFT      Hall_Counter_STATUS_ZERO_SHIFT      
    #define Hall_Counter_STATUS_OVERFLOW_INT_EN_MASK_SHIFT  Hall_Counter_STATUS_OVERFLOW_SHIFT  
    #define Hall_Counter_STATUS_UNDERFLOW_INT_EN_MASK_SHIFT Hall_Counter_STATUS_UNDERFLOW_SHIFT 
    #define Hall_Counter_STATUS_CAPTURE_INT_EN_MASK_SHIFT   Hall_Counter_STATUS_CAPTURE_SHIFT   
    #define Hall_Counter_STATUS_FIFOFULL_INT_EN_MASK_SHIFT  Hall_Counter_STATUS_FIFOFULL_SHIFT  
    #define Hall_Counter_STATUS_FIFONEMP_INT_EN_MASK_SHIFT  Hall_Counter_STATUS_FIFONEMP_SHIFT  
    /* Status Register Bit Masks */                
    #define Hall_Counter_STATUS_CMP             (0x01u << Hall_Counter_STATUS_CMP_SHIFT)  
    #define Hall_Counter_STATUS_ZERO            (0x01u << Hall_Counter_STATUS_ZERO_SHIFT) 
    #define Hall_Counter_STATUS_OVERFLOW        (0x01u << Hall_Counter_STATUS_OVERFLOW_SHIFT) 
    #define Hall_Counter_STATUS_UNDERFLOW       (0x01u << Hall_Counter_STATUS_UNDERFLOW_SHIFT) 
    #define Hall_Counter_STATUS_CAPTURE         (0x01u << Hall_Counter_STATUS_CAPTURE_SHIFT) 
    #define Hall_Counter_STATUS_FIFOFULL        (0x01u << Hall_Counter_STATUS_FIFOFULL_SHIFT)
    #define Hall_Counter_STATUS_FIFONEMP        (0x01u << Hall_Counter_STATUS_FIFONEMP_SHIFT)
    /* Status Register Interrupt Bit Masks  - UDB Status Interrupt Mask match Status Bit Locations */
    #define Hall_Counter_STATUS_CMP_INT_EN_MASK            Hall_Counter_STATUS_CMP                    
    #define Hall_Counter_STATUS_ZERO_INT_EN_MASK           Hall_Counter_STATUS_ZERO            
    #define Hall_Counter_STATUS_OVERFLOW_INT_EN_MASK       Hall_Counter_STATUS_OVERFLOW        
    #define Hall_Counter_STATUS_UNDERFLOW_INT_EN_MASK      Hall_Counter_STATUS_UNDERFLOW       
    #define Hall_Counter_STATUS_CAPTURE_INT_EN_MASK        Hall_Counter_STATUS_CAPTURE         
    #define Hall_Counter_STATUS_FIFOFULL_INT_EN_MASK       Hall_Counter_STATUS_FIFOFULL        
    #define Hall_Counter_STATUS_FIFONEMP_INT_EN_MASK       Hall_Counter_STATUS_FIFONEMP         
    

    /* StatusI Interrupt Enable bit Location in the Auxilliary Control Register */
    #define Hall_Counter_STATUS_ACTL_INT_EN     0x10u /* As defined for the ACTL Register */
    
    /* Datapath Auxillary Control Register definitions */
    #define Hall_Counter_AUX_CTRL_FIFO0_CLR         0x01u   /* As defined by Register map */
    #define Hall_Counter_AUX_CTRL_FIFO1_CLR         0x02u   /* As defined by Register map */
    #define Hall_Counter_AUX_CTRL_FIFO0_LVL         0x04u   /* As defined by Register map */
    #define Hall_Counter_AUX_CTRL_FIFO1_LVL         0x08u   /* As defined by Register map */
    #define Hall_Counter_STATUS_ACTL_INT_EN_MASK    0x10u   /* As defined for the ACTL Register */
    
#endif /* Hall_Counter_UsingFixedFunction */

#endif  /* CY_COUNTER_Hall_Counter_H */


/* [] END OF FILE */

