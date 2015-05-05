/*******************************************************************************
* File Name: ISR_Side_Rangefinder.h
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
#if !defined(__ISR_Side_Rangefinder_INTC_H__)
#define __ISR_Side_Rangefinder_INTC_H__


#include <cytypes.h>
#include <cyfitter.h>

#if(CYDEV_CHIP_FAMILY_USED == CYDEV_CHIP_FAMILY_PSOC3)     
    #if(CYDEV_CHIP_REVISION_USED <= CYDEV_CHIP_REVISION_3A_ES2)      
        #include <intrins.h>
        #define ISR_Side_Rangefinder_ISR_PATCH() _nop_(); _nop_(); _nop_(); _nop_(); _nop_(); _nop_(); _nop_(); _nop_();
    #endif
#endif


/* Interrupt Controller API. */
void ISR_Side_Rangefinder_Start(void);
void ISR_Side_Rangefinder_StartEx(cyisraddress address);
void ISR_Side_Rangefinder_Stop(void) ;

CY_ISR_PROTO(ISR_Side_Rangefinder_Interrupt);

void ISR_Side_Rangefinder_SetVector(cyisraddress address) ;
cyisraddress ISR_Side_Rangefinder_GetVector(void) ;

void ISR_Side_Rangefinder_SetPriority(uint8 priority) ;
uint8 ISR_Side_Rangefinder_GetPriority(void) ;

void ISR_Side_Rangefinder_Enable(void) ;
uint8 ISR_Side_Rangefinder_GetState(void) ;
void ISR_Side_Rangefinder_Disable(void) ;

void ISR_Side_Rangefinder_SetPending(void) ;
void ISR_Side_Rangefinder_ClearPending(void) ;


/* Interrupt Controller Constants */

/* Address of the INTC.VECT[x] register that contains the Address of the ISR_Side_Rangefinder ISR. */
#define ISR_Side_Rangefinder_INTC_VECTOR            ((reg16 *) ISR_Side_Rangefinder__INTC_VECT)

/* Address of the ISR_Side_Rangefinder ISR priority. */
#define ISR_Side_Rangefinder_INTC_PRIOR             ((reg8 *) ISR_Side_Rangefinder__INTC_PRIOR_REG)

/* Priority of the ISR_Side_Rangefinder interrupt. */
#define ISR_Side_Rangefinder_INTC_PRIOR_NUMBER      ISR_Side_Rangefinder__INTC_PRIOR_NUM

/* Address of the INTC.SET_EN[x] byte to bit enable ISR_Side_Rangefinder interrupt. */
#define ISR_Side_Rangefinder_INTC_SET_EN            ((reg8 *) ISR_Side_Rangefinder__INTC_SET_EN_REG)

/* Address of the INTC.CLR_EN[x] register to bit clear the ISR_Side_Rangefinder interrupt. */
#define ISR_Side_Rangefinder_INTC_CLR_EN            ((reg8 *) ISR_Side_Rangefinder__INTC_CLR_EN_REG)

/* Address of the INTC.SET_PD[x] register to set the ISR_Side_Rangefinder interrupt state to pending. */
#define ISR_Side_Rangefinder_INTC_SET_PD            ((reg8 *) ISR_Side_Rangefinder__INTC_SET_PD_REG)

/* Address of the INTC.CLR_PD[x] register to clear the ISR_Side_Rangefinder interrupt. */
#define ISR_Side_Rangefinder_INTC_CLR_PD            ((reg8 *) ISR_Side_Rangefinder__INTC_CLR_PD_REG)



/* __ISR_Side_Rangefinder_INTC_H__ */
#endif
