#include <p18cxxx.h>
#include <timers.h>

/********************************************************************
*    Function Name:  ReadTimer8                                     *
*    Return Value:   char: Timer8 8-bit value                       *
*    Parameters:     void                                           *
*    Description:    This routine returns the 8-bit value of        *
*                    Timer8.                                        *
********************************************************************/

#if defined (TMR_V7) || defined (TMR_V7_1) || defined (TMR_V7_4)
#undef ReadTimer8
unsigned char ReadTimer8(void)
{
  return (TMR8);    // Return 8-bits 
}

#endif
