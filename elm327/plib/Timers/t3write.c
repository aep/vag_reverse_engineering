#include <p18cxxx.h>
#include <timers.h>

/********************************************************************
*    Function Name:  WriteTimer3                                    *
*    Return Value:   void                                           *
*    Parameters:     int: value to write to Timer3                  *
*    Description:    This routine writes a 16-bit value to Timer3   *
********************************************************************/
#if defined (TMR_V2) || defined (TMR_V4) || defined (TMR_V6) || defined (TMR_V7)\
	|| defined (TMR_V7_1) || defined (TMR_V7_2) || defined (TMR_V7_3) || defined (TMR_V7_4) || defined (TMR_V7_5)
void WriteTimer3(unsigned int timer3)
{
  union Timers timer;

  timer.lt = timer3;    // Save value in local variable
  TMR3H = timer.bt[1];  // Write high byte to Timer3
  TMR3L = timer.bt[0];  // Write low byte to Timer3
}

#endif
