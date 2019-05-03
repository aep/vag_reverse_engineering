#include <p18cxxx.h>
#include <timers.h>

/********************************************************************
*    Function Name:  CloseTimer10                                    *
*    Return Value:   void                                           *
*    Parameters:     void                                           *
*    Description:    This routine disables the Timer8 and the       *
*                    interrupt.                                     *
********************************************************************/

#if defined (TMR_V7)

void CloseTimer10(void)
{
  T10CONbits.TMR10ON = 0;  // Disable Timer10
  PIE5bits.TMR10IE = 0;   // Disable Timer10 overflow interrupts
}

#endif

