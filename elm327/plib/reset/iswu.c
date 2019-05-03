#include <p18cxxx.h>
#include <reset.h>

/********************************************************************
*       Function Name:  isWU                                        *
*       Return Value:   char                                        *
*       Parameters:     void                                        *
*       Description:    This routine checks to see if a wakeup from *
*                       sleep has occurred.                         *
********************************************************************/
char isWU(void)
{
        if(RCONbits.NOT_POR)                    // If POR is set
        {
                if(!RCONbits.NOT_PD)            // If PD is cleared
                {
                // If BOR is enabled
#if defined(BOR_ENABLED)
                        if(RCONbits.NOT_BOR)    // If BOR is set
                        {
                        // If WDT is enabled
#if defined(WDT_ENABLED)
                                if(!RCONbits.NOT_TO)    // If TO is cleared
                                        return 0x00;// Return FALSE
#endif
                                return 1;       // Else return TRUE
                        }
                        return 0x00;            // Else return FALSE
        // BOR is disabled
#else 
        // If WDT is enabled
#if defined(WDT_ENABLED)
                        if(!RCONbits.NOT_TO)    // If TO is cleared
                                return 0x00;    // Return FALSE
                        return 1;               // Else return TRUE
#else
                        return 1;               // Else return TRUE
#endif
#endif
                }
                return 0x00;                    // Else return FALSE
        }
        return 0x00;                            // Else return FALSE
}

