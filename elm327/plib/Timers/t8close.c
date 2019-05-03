#include <p18cxxx.h>
#include <timers.h>

/********************************************************************
*    Function Name:  CloseTimer8                                    *
*    Return Value:   void                                           *
*    Parameters:     void                                           *
*    Description:    This routine disables the Timer8 and the       *
*                    interrupt.                                     *
********************************************************************/

#if defined (TMR_V7) || defined (TMR_V7_1) || defined (TMR_V7_4)

void CloseTimer8(void)
{
  T8CONbits.TMR8ON = 0;  // Disable Timer8
  PIE5bits.TMR8IE = 0;   // Disable Timer8 overflow interrupts
}

#endif

