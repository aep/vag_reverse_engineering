#include <p18cxxx.h>
#include <timers.h>

/********************************************************************
*    Function Name:  WriteTimer5                                    *
*    Return Value:   void                                           *
*    Parameters:     unsigned int: value to write to Timer5                *
*    Description:    This routine writes a 16-bit value to Timer5.   *
********************************************************************/

#if defined (TMR_V5) || defined (TMR_V7) || defined (TMR_V7_1) || defined (TMR_V7_3) || defined (TMR_V7_4)

void WriteTimer5(unsigned int tmr5)
{
  union Timers timer;
  timer.lt = tmr5;      // Save the 16-bit value in local
  
  TMR5H = timer.bt[1];  // Write high byte to Timer5 High byte
  TMR5L = timer.bt[0];  // Write low byte to Timer5 Low byte

}

#endif
