#include <p18cxxx.h>
#include <pwm.h>


/********************************************************************
*    Function Name:  ClosePWM3                                      *
*    Return Value:   void                                           *
*    Parameters:     void                                           *
*    Description:    This routine turns off PWM3.                   *
********************************************************************/
#if defined (PWM_V3) || defined (PWM_V4) || defined (PWM_V9)  || defined (PWM_V14_2)

void ClosePWM3(void)
{
  CCP3CON=0;            // Turn off PWM3

}

#endif
