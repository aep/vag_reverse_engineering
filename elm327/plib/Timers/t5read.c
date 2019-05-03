#include <p18cxxx.h>
#include <timers.h>

/********************************************************************
*    Function Name:  ReadTimer5                                     *
*    Return Value:   unsigned int: Timer5 16-bit value                       *
*    Parameters:     void                                           *
*    Description:    This routine returns the 16-bit value of        *
*                    Timer5.                                        *
********************************************************************/

#if defined (TMR_V5) || defined (TMR_V7) || defined (TMR_V7_1) || defined (TMR_V7_3) || defined (TMR_V7_4)

unsigned int ReadTimer5(void)
{
union Timers timer;
 
  timer.bt[0] = TMR5L;    // Read Lower byte
  timer.bt[1] = TMR5H;    // Read upper byte
  return (timer.lt);      // Return the 16-bit value
}

#endif




  
