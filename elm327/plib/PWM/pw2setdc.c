#include <p18cxxx.h>
#include <pwm.h>

#if defined (PWM_V2) || defined (PWM_V3) || defined (PWM_V4) || defined (PWM_V5) ||\
	defined (PWM_V6) || defined (PWM_V9) ||  defined (PWM_V10) ||  defined (PWM_V11)\
	|| defined (PWM_V13)  || defined (PWM_V14_2) || defined (PWM_V14_5)
void SetDCPWM2(unsigned int dutycycle)
{
  union PWMDC DCycle;

  // Save the dutycycle value in the union
  DCycle.lpwm = dutycycle << 6;

  // Write the high byte into CCPR2L
  CCPR2L = DCycle.bpwm[1];

  // Write the low byte into CCP2CON5:4
  CCP2CON = (CCP2CON & 0xCF) | ((DCycle.bpwm[0] >> 2) & 0x30);
}

#endif
