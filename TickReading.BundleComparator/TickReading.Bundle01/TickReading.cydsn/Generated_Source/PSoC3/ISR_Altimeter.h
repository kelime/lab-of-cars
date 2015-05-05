/*******************************************************************************
* File Name: ISR_Altimeter.h
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
#if !defined(__ISR_Altimeter_INTC_H__)
#define __ISR_Altimeter_INTC_H__


#include <cytypes.h>
#include <cyfitter.h>

#if(CYDEV_CHIP_FAMILY_USED == CYDEV_CHIP_FAMILY_PSOC3)     
    #if(CYDEV_CHIP_REVISION_USED <= CYDEV_CHIP_REVISION_3A_ES2)      
        #include <intrins.h>
        #define ISR_Altimeter_ISR_PATCH() _nop_(); _nop_(); _nop_(); _nop_(); _nop_(); _nop_(); _nop_(); _nop_();
    #endif
#endif


/* Interrupt Controller API. */
void ISR_Altimeter_Start(void);
void ISR_Altimeter_StartEx(cyisraddress address);
void ISR_Altimeter_Stop(void) ;

CY_ISR_PROTO(ISR_Altimeter_Interrupt);

void ISR_Altimeter_SetVector(cyisraddress address) ;
cyisraddress ISR_Altimeter_GetVector(void) ;

void ISR_Altimeter_SetPriority(uint8 priority) ;
uint8 ISR_Altimeter_GetPriority(void) ;

void ISR_Altimeter_Enable(void) ;
uint8 ISR_Altimeter_GetState(void) ;
void ISR_Altimeter_Disable(void) ;

void ISR_Altimeter_SetPending(void) ;
void ISR_Altimeter_ClearPending(void) ;


/* Interrupt Controller Constants */

/* Address of the INTC.VECT[x] register that contains the Address of the ISR_Altimeter ISR. */
#define ISR_Altimeter_INTC_VECTOR            ((reg16 *) ISR_Altimeter__INTC_VECT)

/* Address of the ISR_Altimeter ISR priority. */
#define ISR_Altimeter_INTC_PRIOR             ((reg8 *) ISR_Altimeter__INTC_PRIOR_REG)

/* Priority of the ISR_Altimeter interrupt. */
#define ISR_Altimeter_INTC_PRIOR_NUMBER      ISR_Altimeter__INTC_PRIOR_NUM

/* Address of the INTC.SET_EN[x] byte to bit enable ISR_Altimeter interrupt. */
#define ISR_Altimeter_INTC_SET_EN            ((reg8 *) ISR_Altimeter__INTC_SET_EN_REG)

/* Address of the INTC.CLR_EN[x] register to bit clear the ISR_Altimeter interrupt. */
#define ISR_Altimeter_INTC_CLR_EN            ((reg8 *) ISR_Altimeter__INTC_CLR_EN_REG)

/* Address of the INTC.SET_PD[x] register to set the ISR_Altimeter interrupt state to pending. */
#define ISR_Altimeter_INTC_SET_PD            ((reg8 *) ISR_Altimeter__INTC_SET_PD_REG)

/* Address of the INTC.CLR_PD[x] register to clear the ISR_Altimeter interrupt. */
#define ISR_Altimeter_INTC_CLR_PD            ((reg8 *) ISR_Altimeter__INTC_CLR_PD_REG)



/* __ISR_Altimeter_INTC_H__ */
#endif
