#include <p18cxxx.h>
#include <timers.h>
/********************************************************************
*    Function Name:  CloseTimer2                                    *
*    Return Value:   void                                           *
*    Parameters:     void                                           *
*    Description:    This routine disables the Timer2 and the       *
*                    interrupt.                                     *
********************************************************************/
#if defined (TMR_V2) || defined (TMR_V3) || defined (TMR_V4) ||\
    defined (TMR_V5) || defined (TMR_V6) || defined (TMR_V7) || defined (TMR_V7_1) \
	|| defined (TMR_V7_2) || defined (TMR_V7_3) || defined (TMR_V7_4) || defined (TMR_V7_5)
void CloseTimer2(void)
{
  T2CONbits.TMR2ON = 0;  // Disable Timer2
  PIE1bits.TMR2IE = 0;   // Disable Timer2 overflow interrupts
}

#endif
