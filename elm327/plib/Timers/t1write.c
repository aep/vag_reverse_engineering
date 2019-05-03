#include <p18cxxx.h>
#include <timers.h>

/********************************************************************
*    Function Name:  WriteTimer1                                    *
*    Return Value:   void                                           *
*    Parameters:     int: value to write to Timer1                  *
*    Description:    This routine writes a 16-bit value to Timer1.  *
********************************************************************/
#if defined (TMR_V1) || defined (TMR_V2) || defined (TMR_V3) ||\
    defined (TMR_V4) || defined (TMR_V5) || defined (TMR_V6) ||\
	defined (TMR_V7) || defined (TMR_V7_1) || defined (TMR_V7_2)\
	 || defined (TMR_V7_3) || defined (TMR_V7_4) || defined (TMR_V7_5)
void WriteTimer1(unsigned int timer1)
{
  union Timers timer;

  timer.lt = timer1;    // Save the 16-bit value in local

  TMR1H = timer.bt[1];  // Write high byte to Timer1 High byte
  TMR1L = timer.bt[0];  // Write low byte to Timer1 Low byte
}

#endif
