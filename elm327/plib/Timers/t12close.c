#include <p18cxxx.h>
#include <timers.h>

/********************************************************************
*    Function Name:  CloseTimer12                                    *
*    Return Value:   void                                           *
*    Parameters:     void                                           *
*    Description:    This routine disables the Timer8 and the       *
*                    interrupt.                                     *
********************************************************************/

#if defined (TMR_V7)

void CloseTimer12(void)
{
  T12CONbits.TMR12ON = 0;  // Disable Timer12
  PIE5bits.TMR12IE = 0;   // Disable Timer12 overflow interrupts
}

#endif

