#include <p18cxxx.h>
#include <timers.h>

/********************************************************************
*    Function Name:  ReadTimer2                                     *
*    Return Value:   char: Timer2 8-bit value                       *
*    Parameters:     void                                           *
*    Description:    This routine reads the 8-bit value from        *
*                    Timer2.                                        *
********************************************************************/
#if defined (TMR_V2) || defined (TMR_V3) || defined (TMR_V4) || \
    defined (TMR_V5) || defined (TMR_V6) || defined (TMR_V7) || defined (TMR_V7_1)\
	|| defined (TMR_V7_2) || defined (TMR_V7_3) || defined (TMR_V7_4) || defined (TMR_V7_5)
#undef ReadTimer2
unsigned char ReadTimer2(void)
{
  unsigned char timer;

  timer = TMR2;      // Read Timer2

  return (timer);    // Return 8-bits
}

#endif
