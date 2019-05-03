#include <p18cxxx.h>
#include <reset.h>

/********************************************************************
*       Function Name:  isMCLR                                      *
*       Return Value:   char                                        *
*       Parameters:     void                                        *
*       Description:    This routine checks to see if a MCLR induced*
*                       reset occurred.                             *
********************************************************************/

char isMCLR(void)
{
        if(RCONbits.NOT_POR)                    // If POR is set
        {
                if(RCONbits.NOT_PD)             // If NOT_PD is set
                {
                // If BOR is enabled
#if defined(BOR_ENABLED)
                        if(RCONbits.NOT_BOR)    // If BOR is set
                        {
                        // If BOR and WDT are enabled
#if defined(WDT_ENABLED)
                                if(!RCONbits.NOT_TO)    // If TO is cleared
                                        return 0x00;// Return FALSE
#endif
                                if(!RCONbits.NOT_RI)    // If RI is cleared
                                        return 0x00;// Return FALSE

#if defined(STVR_ENABLED)

	#if defined (STK_SFR_V1)
                                if(STKPTRbits.STKFUL)    // If STKFUL is set
	#else
                                if(STKPTRbits.STKOVF)    // If STKOVF is set
	#endif
                                        return 0x00;// Return FALSE

                                if(STKPTRbits.STKUNF)    // If STKUNF is set
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

                        if(!RCONbits.NOT_RI)    // If RI is cleared
                                return 0x00;// Return FALSE
#if defined(STVR_ENABLED)

                        if(STKPTRbits.STKOVF)    // If STKOVF is set
                                return 0x00;// Return FALSE

                        if(STKPTRbits.STKUNF)    // If STKUNF is set
                                return 0x00;// Return FALSE
#endif
                         return 1;               // Else return TRUE
        // BOR and WDT are disabled
#else
                        if(!RCONbits.NOT_RI)    // If RI is cleared
                                return 0x00;// Return FALSE

#if defined(STVR_ENABLED)
                        if(STKPTRbits.STKOVF)    // If STKOVF is set
                                return 0x00;// Return FALSE

                        if(STKPTRbits.STKUNF)    // If STKUNF is set
                                return 0x00;// Return FALSE
#endif
                        return 1;               // Else return TRUE
#endif
#endif
                }
                return 0x00;                    // Else return FALSE
        }
        return 0x00;                            // Else return FALSE
}

