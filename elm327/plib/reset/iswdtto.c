#include <p18cxxx.h>
#include <reset.h>

/********************************************************************
*       Function Name:  isWDTTO                                     *
*       Return Value:   char                                        *
*       Parameters:     void                                        *
*       Description:    This routine checks to see if a WDT timeout *
*                       has occurred during normal operation.       *
********************************************************************/

// If WDT is enabled
#if defined(WDT_ENABLED)

char isWDTTO(void)
{
        if(RCONbits.NOT_POR)                            // if POR is set
        {
                if(RCONbits.NOT_PD)                     // if NOT_PD is set
                {
                // If BOR is enabled
#if defined(BOR_ENABLED)
                        if(RCONbits.NOT_BOR)            // if BOR is set
                        {
                                if(RCONbits.NOT_TO)     // if TO is set
                                        return 0x00;    // Return FALSE
                                return 1;               // Else return TRUE
                        }
                        return 0x00;                    // Else return FALSE
                // BOR is disabled
#else
                        if(RCONbits.NOT_TO)             // if TO is set
                                return 0x00;            // Return FALSE
                        return 1;                       // Else return TRUE
#endif
                }
                return 0x00;                            // Else return FALSE
        }
        return 0x00;                                    // Else return FALSE
}
#endif
