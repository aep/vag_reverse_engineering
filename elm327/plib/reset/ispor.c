#include <p18cxxx.h>
#include <reset.h>

/********************************************************************
*       Function Name:  isPOR                                       *
*       Return Value:   char                                        *
*       Parameters:     void                                        *
*       Description:    This routine checks to see if a POR occurred*
********************************************************************/
char isPOR(void)
{
        if(!RCONbits.NOT_POR)           // If POR cleared
        {
                if(RCONbits.NOT_PD)     // If PD set
                {
                // If BOR is enabled
#if defined(BOR_ENABLED)
                        if(!RCONbits.NOT_BOR)   // If BOR cleared
                        {
                        // if BOR and WDT are enabled
#if defined(WDT_ENABLED)
                                if(!RCONbits.NOT_TO)    // If TO cleared
                                        return 0x00;// Return FALSE
#endif
                                return 1;       // Else return TRUE
                        }
                        return 0x00;            // Else return FALSE
                // BOR is disabled
#else 
                // If WDT is enabled
#if defined(WDT_ENABLED)
                        if(!RCONbits.NOT_TO)    // If TO cleared
                                return 0x00;    // Return FALSE
                        return 1;               // Else return TRUE
#else
                // Otherwise BOR and WDT are disabled
                        return 1;               // Else return TRUE
#endif
#endif
                }
                return 0x00;                    // Else return FALSE
        }
        return 0x00;
}

