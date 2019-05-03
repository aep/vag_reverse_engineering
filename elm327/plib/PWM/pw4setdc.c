#include <p18cxxx.h>
#include <pwm.h>


/********************************************************************
*    Function Name:  SetDCPWM4                                      *
*    Return Value:   void                                           *
*    Parameters:     dutycycle: holds 10-bit duty cycle value       *
*    Description:    This routine writes the 10-bit value from      *
*                    dutycycle into the PWM4 duty cycle registers   *
*                    CCPR4L and CCP4CON.                            *
********************************************************************/

#if defined (PWM_V4) || defined (PWM_V9) || defined (PWM_V14) || defined (PWM_V14_1)\
	 || defined (PWM_V14_2) ||defined (PWM_V14_3) || defined (PWM_V14_4) \
	 || defined (PWM_V15) ||defined (PWM_V15_1)
void SetDCPWM4(unsigned int dutycycle)
{
  union PWMDC DCycle;

  // Save the dutycycle value in the union
  DCycle.lpwm = dutycycle << 6;

  // Write the high byte into CCPR4L
  CCPR4L = DCycle.bpwm[1];

  // Write the low byte into CCP4CON5:4
  CCP4CON = (CCP4CON & 0xCF) | ((DCycle.bpwm[0] >> 2) & 0x30);
}

#endif
