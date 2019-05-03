#include <p18cxxx.h>
#include <timers.h>

/********************************************************************
*    Function Name:  ReadTimer3                                     *
*    Return Value:   int: Timer3 16-bit value                       *
*    Parameters:     void                                           *
*    Description:    This routine reads the 16-bit value from       *
*                    Timer3.                                        *
********************************************************************/
#if defined (TMR_V2) || defined (TMR_V4) || defined (TMR_V6) || defined (TMR_V7)\
	|| defined (TMR_V7_1) || defined (TMR_V7_2) || defined (TMR_V7_3) || defined (TMR_V7_4) || defined (TMR_V7_5)
unsigned int ReadTimer3(void)
{
  union Timers timer;

  timer.bt[0] = TMR3L;   // Read low byte of Timer3
  timer.bt[1] = TMR3H;   // Read high byte of Timer3

  return (timer.lt);     // Return 16-bit value
}

#endif
