/*******************************************************************************
* File Name: ISR_Pixy.h
* Version 1.60
*
*  Description:
*   Provides the function definitions for the Interrupt Controller.
*
*
********************************************************************************
* Copyright 2008-2010, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
********************************************************************************/
#if !defined(__ISR_Pixy_INTC_H__)
#define __ISR_Pixy_INTC_H__


#include <cytypes.h>
#include <cyfitter.h>

#if(CYDEV_CHIP_FAMILY_USED == CYDEV_CHIP_FAMILY_PSOC3)     
    #if(CYDEV_CHIP_REVISION_USED <= CYDEV_CHIP_REVISION_3A_ES2)      
        #include <intrins.h>
        #define ISR_Pixy_ISR_PATCH() _nop_(); _nop_(); _nop_(); _nop_(); _nop_(); _nop_(); _nop_(); _nop_();
    #endif
#endif


/* Interrupt Controller API. */
void ISR_Pixy_Start(void);
void ISR_Pixy_StartEx(cyisraddress address);
void ISR_Pixy_Stop(void) ;

CY_ISR_PROTO(ISR_Pixy_Interrupt);

void ISR_Pixy_SetVector(cyisraddress address) ;
cyisraddress ISR_Pixy_GetVector(void) ;

void ISR_Pixy_SetPriority(uint8 priority) ;
uint8 ISR_Pixy_GetPriority(void) ;

void ISR_Pixy_Enable(void) ;
uint8 ISR_Pixy_GetState(void) ;
void ISR_Pixy_Disable(void) ;

void ISR_Pixy_SetPending(void) ;
void ISR_Pixy_ClearPending(void) ;


/* Interrupt Controller Constants */

/* Address of the INTC.VECT[x] register that contains the Address of the ISR_Pixy ISR. */
#define ISR_Pixy_INTC_VECTOR            ((reg16 *) ISR_Pixy__INTC_VECT)

/* Address of the ISR_Pixy ISR priority. */
#define ISR_Pixy_INTC_PRIOR             ((reg8 *) ISR_Pixy__INTC_PRIOR_REG)

/* Priority of the ISR_Pixy interrupt. */
#define ISR_Pixy_INTC_PRIOR_NUMBER      ISR_Pixy__INTC_PRIOR_NUM

/* Address of the INTC.SET_EN[x] byte to bit enable ISR_Pixy interrupt. */
#define ISR_Pixy_INTC_SET_EN            ((reg8 *) ISR_Pixy__INTC_SET_EN_REG)

/* Address of the INTC.CLR_EN[x] register to bit clear the ISR_Pixy interrupt. */
#define ISR_Pixy_INTC_CLR_EN            ((reg8 *) ISR_Pixy__INTC_CLR_EN_REG)

/* Address of the INTC.SET_PD[x] register to set the ISR_Pixy interrupt state to pending. */
#define ISR_Pixy_INTC_SET_PD            ((reg8 *) ISR_Pixy__INTC_SET_PD_REG)

/* Address of the INTC.CLR_PD[x] register to clear the ISR_Pixy interrupt. */
#define ISR_Pixy_INTC_CLR_PD            ((reg8 *) ISR_Pixy__INTC_CLR_PD_REG)



/* __ISR_Pixy_INTC_H__ */
#endif
