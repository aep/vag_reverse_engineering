#include <p18cxxx.h>
#include <timers.h>


/********************************************************************
*    Function Name:  CloseTimer0                                    *
*    Return Value:   void                                           *
*    Parameters:     void                                           *
*    Description:    This routine disables the Timer0 interrupt.    *
********************************************************************/
#if  defined (TMR_V1) || defined (TMR_V2) || defined (TMR_V3) ||\
     defined (TMR_V4) || defined (TMR_V5) || defined (TMR_V6) ||\
	 defined (TMR_V7) || defined (TMR_V7_1) || defined (TMR_V7_2)\
	  || defined (TMR_V7_3) || defined (TMR_V7_4) || defined (TMR_V7_5)
void CloseTimer0(void)
{
  T0CONbits.TMR0ON = 0;  // Disable Timer1
  INTCONbits.TMR0IE = 0;   // Disable Timer1 overflow interrupts
}

#endif
