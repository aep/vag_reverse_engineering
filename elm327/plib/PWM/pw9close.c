#include <p18cxxx.h>
#include <pwm.h>


/********************************************************************
*    Function Name:  ClosePWM9                                     *
*    Return Value:   void                                           *
*    Parameters:     void                                           *
*    Description:    This routine turns off PWM9.                   *
********************************************************************/
#if defined (PWM_V14) ||defined (PWM_V14_3) 
void ClosePWM9(void)
{
  
	CCP9CON=0;            // Turn off PWM9

}
#endif
