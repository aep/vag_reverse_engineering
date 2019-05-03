#include <p18cxxx.h>
#include <rtcc.h>

/********************************************************************
*    Function Name:  update_rtcc                                     *
*    Return Value:   unsigned char (state of TMR1 interrupt Flag)    *
*    Parameters:     void                                            *
*    Description:    This routine ckecks for the TMR1 interrupt flag,*
*					 refreshes TMR1H if interrupt has occurred and	 *
*					 returns the state of TMR1IF.					 * 	 		
********************************************************************/

unsigned char update_RTCC(void) 
{
	if(PIR1bits.TMR1IF ==0 ) return 0;
	TMR1H |= 0b10000000;
	PIR1bits.TMR1IF=0;
	return 1;
} 

