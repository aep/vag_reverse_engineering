#include <p18cxxx.h>
#include <timers.h>

/********************************************************************
*    Function Name:  WriteTimer7                                    *
*    Return Value:   void                                           *
*    Parameters:     int: value to write to Timer7                  *
*    Description:    This routine writes a 16-bit value to Timer7.  *
********************************************************************/
#if defined (TMR_V7)
void WriteTimer7(unsigned int timer7)
{
  union Timers timer;

  timer.lt = timer7;    // Save the 16-bit value in local

  TMR7H = timer.bt[1];  // Write high byte to Timer7 High byte
  TMR7L = timer.bt[0];  // Write low byte to Timer7 Low byte
}

#endif
