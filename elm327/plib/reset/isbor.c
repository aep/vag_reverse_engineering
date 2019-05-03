#include <p18cxxx.h>
#include <reset.h>

// Only if Brown-out Reset is enabled
#if defined(BOR_V1)
/********************************************************************
*       Function Name:  isBOR                                       *
*       Return Value:   char                                        *
*       Parameters:     void                                        *
*       Description:    This routine checks to see if a BOR occurred*
********************************************************************/
char isBOR(void)
{
        if(!RCONbits.NOT_BOR)           // If BOR is clear
        {
                if(!RCONbits.NOT_POR)   // And POR is clear
                        return 0x00;    // Return FALSE
                return 1;               // Else return TRUE
        }
        return 0x00;                    // Else return FALSE
}
#endif
