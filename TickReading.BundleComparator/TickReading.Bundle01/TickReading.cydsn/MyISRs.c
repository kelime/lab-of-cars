/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/
/* ============*/
// Constants
#include <cylib.h>
#include "MyISRs.h"

uint8	ConversionDone =0;      //  Data ready flag

//__________________________________________________________________________
CY_ISR(ConvDone)		        // Interrupt-Service-Routine definition
{
    ConversionDone =1;		    // indicate, Data ready
    CyWdtClear();               // reset the watchdog timer
}

/* [] END OF FILE */
