#include <p18cxxx.h>
#include <pwm.h>


/********************************************************************
*    Function Name:  ClosePWM10                                     *
*    Return Value:   void                                           *
*    Parameters:     void                                           *
*    Description:    This routine turns off PWM10.                   *
********************************************************************/
#if defined (PWM_V14) || defined (PWM_V14_3)
void ClosePWM10(void)
{
  
	CCP10CON=0;            // Turn off PWM10

}
#endif
