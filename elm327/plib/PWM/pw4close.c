#include <p18cxxx.h>
#include <pwm.h>


/********************************************************************
*    Function Name:  ClosePWM4                                      *
*    Return Value:   void                                           *
*    Parameters:     void                                           *
*    Description:    This routine turns off PWM4.                   *
********************************************************************/

#if defined (PWM_V4) || defined (PWM_V9) || defined (PWM_V14) || defined (PWM_V14_1)\
	 || defined (PWM_V14_2) ||defined (PWM_V14_3) || defined (PWM_V14_4) ||\
	 defined (PWM_V15) ||defined (PWM_V15_1)
void ClosePWM4(void)
{  
	CCP4CON=0;            // Turn off PWM4
	
}

#endif
