#include <p18cxxx.h>
#include <timers.h>

/********************************************************************
*    Function Name:  CloseTimer3                                    *
*    Return Value:   void                                           *
*    Parameters:     void                                           *
*    Description:    This routine disables the Timer3 and the       *
*                    interrupt.                                     *
********************************************************************/
#if defined (TMR_V2) || defined (TMR_V4)
void CloseTimer3(void)
{
  T3CONbits.TMR3ON = 0;  // Disable Timer3
  PIE2bits.TMR3IE = 0;   // Disable Timer3 overflow interrupts
}
#endif

#if defined (TMR_V6)
void CloseTimer3(void)
{
  T3CONbits.TMR3ON = 0;  // Disable Timer3
  PIE2bits.TMR3IE = 0;   // Disable Timer3 overflow interrupts
  PIE3bits.TMR3GIE=0;  
}
#endif

#if defined (TMR_V7) || defined (TMR_V7_1) || defined (TMR_V7_2) || defined (TMR_V7_3) || defined (TMR_V7_4) || defined (TMR_V7_5)
void CloseTimer3(void)
{
  T3CONbits.TMR3ON = 0;  // Disable Timer3
  PIE2bits.TMR3IE = 0;   // Disable Timer3 overflow interrupts
#if defined(TMR_INT_V2) || defined (TMR_INT_V7_3) || defined (TMR_INT_V7_5) || defined (TMR_V7_1_INT_V1)
	PIR3bits.TMR3GIF =0;
	PIE3bits.TMR3GIE=0;
#else  
	PIR2bits.TMR3GIF =0;
	PIE2bits.TMR3GIE=0;
#endif
}
#endif

