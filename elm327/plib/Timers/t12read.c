#include <p18cxxx.h>
#include <timers.h>

/********************************************************************
*    Function Name:  ReadTimer12                                     *
*    Return Value:   char: Timer12 8-bit value                       *
*    Parameters:     void                                           *
*    Description:    This routine returns the 8-bit value of        *
*                    Timer12.                                        *
********************************************************************/

#if defined (TMR_V7)
#undef ReadTimer12
unsigned char ReadTimer12(void)
{
  return (TMR12);    // Return 8-bits 
}

#endif
