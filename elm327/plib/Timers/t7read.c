#include <p18cxxx.h>
#include <timers.h>

/********************************************************************
*    Function Name:  ReadTimer7                                     *
*    Return Value:   char: Timer7 16-bit value                      *
*    Parameters:     void                                           *
*    Description:    This routine reads the 16-bit value from       *
*                    Timer7.                                        *
********************************************************************/
#if defined (TMR_V7) 
unsigned int ReadTimer7(void)
{
  union Timers timer;

  timer.bt[0] = TMR7L;    // Read Lower byte
  timer.bt[1] = TMR7H;    // Read upper byte

  return (timer.lt);      // Return the 16-bit value
}
#endif
