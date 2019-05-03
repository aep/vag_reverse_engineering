#include <p18cxxx.h>
#include <timers.h>


/********************************************************************
*    Function Name:  CloseTimer1                                    *
*    Return Value:   void                                           *
*    Parameters:     void                                           *
*    Description:    This routine disables Timer1 and interrupt.    *
********************************************************************/
#if defined (TMR_V1) || defined (TMR_V2) || defined (TMR_V3) ||\
    defined (TMR_V4) || defined (TMR_V5) || defined (TMR_V6) ||\
	 defined (TMR_V7) || defined (TMR_V7_1) || defined (TMR_V7_2)\
	  || defined (TMR_V7_3) || defined (TMR_V7_4) || defined (TMR_V7_5)
void CloseTimer1(void)
{
  T1CONbits.TMR1ON = 0;  // Disable Timer1
  PIE1bits.TMR1IE = 0;   // Disable Timer1 overflow interrupts 
}
#endif
