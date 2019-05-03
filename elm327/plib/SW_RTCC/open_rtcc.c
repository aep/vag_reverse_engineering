#include <p18cxxx.h>
#include "rtcc.h"

/********************************************************************
*    Function Name:  Open_RTCC                                      *
*    Return Value:   void                                           *
*    Parameters:     None    										*
*    Description:    This routine cinfigures Timer1 to work as      *
*                    clock source for RTCC and enables Timer1 		*
					 interrupts		                    			*
********************************************************************/
//**************************************/
void Open_RTCC(void)
{
	TMR1H = 0x80;			// count to get 1 sec interrupt
	TMR1L = 0x00;			
	PIR1bits.TMR1IF=0;		// clear TMR1 interrupt flag
	PIE1bits.TMR1IE=1;		// enable TMR1 interrupt
	T1CON = 0b00001111;		// enable TMR1 OSC, TMR1 clock selection external, run timer1
} 
