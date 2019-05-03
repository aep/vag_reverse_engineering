#include <p18cxxx.h>
#include "rtcc.h"

/********************************************************************
*    Function Name:  close_RTCC                                     *
*    Return Value:   void                                           *
*    Parameters:     None											*
*    Description:    This routine disable Timer1, clear TMR1 		*
*					 interrupt flag, disable TMR1 interrupt 		*
********************************************************************/

void Close_RTCC(void)
{
	T1CONbits.TMR1ON=0;		//disable Timer1
	PIR1bits.TMR1IF=0;		//Clear TMR1 interrupt flag
	PIE1bits.TMR1IE=0;		//disable TMR1 interrupt 
} 
