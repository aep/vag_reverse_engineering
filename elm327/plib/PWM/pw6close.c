#include <p18cxxx.h>
#include <pwm.h>


/********************************************************************
*    Function Name:  ClosePWM6                                     *
*    Return Value:   void                                           *
*    Parameters:     void                                           *
*    Description:    This routine turns off PWM6.                   *
********************************************************************/
#if defined (PWM_V14) || defined (PWM_V14_1) ||defined (PWM_V14_3) || defined (PWM_V14_4)
void ClosePWM6(void)
{
  
	CCP6CON=0;            // Turn off PWM6

}
#endif
