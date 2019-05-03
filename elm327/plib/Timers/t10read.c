#include <p18cxxx.h>
#include <timers.h>

/********************************************************************
*    Function Name:  ReadTimer10                                     *
*    Return Value:   char: Timer10 8-bit value                       *
*    Parameters:     void                                           *
*    Description:    This routine returns the 8-bit value of        *
*                    Timer10.                                        *
********************************************************************/

#if defined (TMR_V7)
#undef ReadTimer10
unsigned char ReadTimer10(void)
{
  return (TMR10);    // Return 8-bits 
}

#endif
