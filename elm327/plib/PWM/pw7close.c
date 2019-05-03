#include <p18cxxx.h>
#include <pwm.h>


/********************************************************************
*    Function Name:  ClosePWM7                                     *
*    Return Value:   void                                           *
*    Parameters:     void                                           *
*    Description:    This routine turns off PWM7.                   *
********************************************************************/
#if defined (PWM_V14) || defined (PWM_V14_1) || defined (PWM_V14_3) || defined (PWM_V14_4)
void ClosePWM7(void)
{
  
	CCP7CON=0;            // Turn off PWM7

}
#endif
