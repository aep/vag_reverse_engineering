#include <p18cxxx.h>
#include <timers.h>

/********************************************************************
*    Function Name:  CloseTimer5                                    *
*    Return Value:   void                                           *
*    Parameters:     void                                           *
*    Description:    This routine disables the Timer5 and the       *
*                    interrupt.                                     *
********************************************************************/

#if defined (TMR_V5) 

void CloseTimer5(void)
{
  T5CONbits.TMR5ON = 0;  // Disable Timer5
  PIE3bits.TMR5IE = 0;   // Disable Timer5 overflow interrupts
}

#elif defined (TMR_V7) || defined (TMR_V7_1) || defined (TMR_V7_3) || defined (TMR_V7_4) 

void CloseTimer5(void)
{
  T5CONbits.TMR5ON = 0;  // Disable Timer5
  PIE5bits.TMR5IE = 0;   // Disable Timer5 overflow interrupts
#if defined (TMR_V7_1_INT_V1) || defined (TMR_V7_4_INT_V1)
  PIR5bits.TMR5GIF=0;
  PIE5bits.TMR5GIE=0;
#else
  PIR3bits.TMR5GIF=0;
  PIE3bits.TMR5GIE=0;
#endif    
}

#endif
