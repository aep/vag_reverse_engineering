#include <p18cxxx.h>
#include <pwm.h>


#if defined (PWM_V2) || defined (PWM_V3) || defined (PWM_V4) || defined (PWM_V5)\
	|| defined (PWM_V6) || defined (PWM_V9) ||  defined (PWM_V10) ||  defined (PWM_V11)\
	|| defined (PWM_V13)  || defined (PWM_V14_2) || defined (PWM_V14_5)

void ClosePWM2(void)
{
  CCP2CON=0;          // Disable PWM2
}

#endif
