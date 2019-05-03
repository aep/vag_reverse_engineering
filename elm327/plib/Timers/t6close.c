#include <p18cxxx.h>
#include <timers.h>

/********************************************************************
*    Function Name:  CloseTimer6                                    *
*    Return Value:   void                                           *
*    Parameters:     void                                           *
*    Description:    This routine disables the Timer6 and the       *
*                    interrupt.                                     *
********************************************************************/

#if defined (TMR_V7) || defined (TMR_V7_1) || defined (TMR_V7_3) || defined (TMR_V7_4)

void CloseTimer6(void)
{
  T6CONbits.TMR6ON = 0;  // Disable Timer6
  PIE5bits.TMR6IE = 0;   // Disable Timer6 overflow interrupts
}

#endif

