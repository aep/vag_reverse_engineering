#include <p18cxxx.h>
#include <timers.h>

/********************************************************************
*    Function Name:  ReadTimer0                                     *
*    Return Value:   int: Timer0 16-bit value                       *
*    Parameters:     void                                           *
*    Description:    This routine reads the 16-bit value from       *
*                    Timer0.                                        *
********************************************************************/
#if  defined (TMR_V1) || defined (TMR_V2) || defined (TMR_V3) ||\
     defined (TMR_V4) || defined (TMR_V5) || defined (TMR_V6) ||\
	 defined (TMR_V7) || defined (TMR_V7_1) || defined (TMR_V7_2)\
	  || defined (TMR_V7_3) || defined (TMR_V7_4) || defined (TMR_V7_5)

unsigned int ReadTimer0(void)
{
  union Timers timer;

  timer.bt[0] = TMR0L;  // Copy Timer0 low byte into union
  timer.bt[1] = TMR0H;  // Copy Timer0 high byte into union

  return (timer.lt);    // Return the int
}
#endif
