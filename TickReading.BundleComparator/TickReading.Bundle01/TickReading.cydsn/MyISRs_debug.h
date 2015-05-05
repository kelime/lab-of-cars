/* ============*/
#if !defined(__MyISRs_INTC_H__)
#define __MyISRs_INTC_H__
// Constants
#include <cylib.h>
#include <cytypes.h>
#include <cyfitter.h>

#if(CYDEV_CHIP_FAMILY_USED == CYDEV_CHIP_FAMILY_PSOC3)     
    #if(CYDEV_CHIP_REVISION_USED <= CYDEV_CHIP_REVISION_3A_ES2)      
        #include <intrins.h>
        #define ConvDone_ISR_PATCH() _nop_(); _nop_(); _nop_(); _nop_(); _nop_(); _nop_(); _nop_(); _nop_();
    #endif
#endif

extern uint8	ConversionDone;      //  Data ready flag

/* Interrupt Controller API. */
void ConvDone_Start(void);
void ConvDone_StartEx(cyisraddress address);
void ConvDone_Stop(void) ;

CY_ISR_PROTO(ConvDone_Interrupt);

void ConvDone_SetVector(cyisraddress address) ;
cyisraddress ConvDone_GetVector(void) ;

void ConvDone_SetPriority(uint8 priority) ;
uint8 ConvDone_GetPriority(void) ;

void ConvDone_Enable(void) ;
uint8 ConvDone_GetState(void) ;
void ConvDone_Disable(void) ;

void ConvDone_SetPending(void) ;
void ConvDone_ClearPending(void) ;


/* Interrupt Controller Constants */

/* Address of the INTC.VECT[x] register that contains the Address of the ISR_Wait ISR. */
#define ISR_ConvDone_INTC_VECTOR            ((reg16 *) ISR_ConvDone__INTC_VECT)

/* Address of the ISR_Wait ISR priority. */
#define ISR_ConvDone_INTC_PRIOR             ((reg8 *) ISR_ConvDone__INTC_PRIOR_REG)

/* Priority of the ISR_Wait interrupt. */
#define ISR_ConvDone_INTC_PRIOR_NUMBER      ISR_ConvDone__INTC_PRIOR_NUM

/* Address of the INTC.SET_EN[x] byte to bit enable ISR_Wait interrupt. */
#define ISR_ConvDone_INTC_SET_EN            ((reg8 *) ISR_ConvDone__INTC_SET_EN_REG)

/* Address of the INTC.CLR_EN[x] register to bit clear the ISR_Wait interrupt. */
#define ConvDone_INTC_CLR_EN            ((reg8 *) ConvDone__INTC_CLR_EN_REG)

/* Address of the INTC.SET_PD[x] register to set the ISR_Wait interrupt state to pending. */
#define ConvDone_INTC_SET_PD            ((reg8 *) ConvDone__INTC_SET_PD_REG)

/* Address of the INTC.CLR_PD[x] register to clear the ISR_Wait interrupt. */
#define ConvDone_INTC_CLR_PD            ((reg8 *) ConvDone__INTC_CLR_PD_REG)



/* __ISR_Wait_INTC_H__ */
#endif

//__________________________________________________________________________
//CY_ISR_PROTO(ConvDone);

//#endif
