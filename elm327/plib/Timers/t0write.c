#include <p18cxxx.h>
#include <timers.h>

/********************************************************************
*    Function Name:  WriteTimer0                                    *
*    Return Value:   void                                           *
*    Parameters:     int: value to write to Timer0                  *
*    Description:    This routine writes a 16-bit value to Timer0   *
*                    Timer0.                                        *
********************************************************************/
#if  defined (TMR_V1) || defined (TMR_V2) || defined (TMR_V3) || \
     defined (TMR_V4) || defined (TMR_V5) || defined (TMR_V6) ||\
	 defined (TMR_V7) || defined (TMR_V7_1) || defined (TMR_V7_2)\
	  || defined (TMR_V7_3) || defined (TMR_V7_4) || defined (TMR_V7_5)

void WriteTimer0(unsigned int timer0)
{
  union Timers timer;

  timer.lt = timer0;    // Copy timer value into union

  TMR0H = timer.bt[1];  // Write high byte to Timer0
  TMR0L = timer.bt[0];  // Write low byte to Timer0
}
#endif
