#include <p18cxxx.h>
#include <timers.h>

/********************************************************************
*    Function Name:  CloseTimer4                                    *
*    Return Value:   void                                           *
*    Parameters:     void                                           *
*    Description:    This routine disables the Timer4 and the       *
*                    interrupt.                                     *
********************************************************************/

#if defined (TMR_V4) || defined (TMR_V6)

void CloseTimer4(void)
{
  T4CONbits.TMR4ON = 0;  // Disable Timer4
  PIE3bits.TMR4IE = 0;   // Disable Timer4 overflow interrupts
}

#endif

#if defined (TMR_V7) || defined (TMR_V7_1) || defined (TMR_V7_2) || defined (TMR_V7_3) || defined (TMR_V7_4)

void CloseTimer4(void)
{
  T4CONbits.TMR4ON = 0;  // Disable Timer4
#if defined(TMR_INT_V2) || defined (TMR_V7_1_INT_V1)
	PIR3bits.TMR4IF = 0;
#elif defined(TMR_V7_2)
	PIR4bits.TMR4IF = 0;	
#else  
  PIR5bits.TMR4IF = 0;
#endif    
}

#endif

