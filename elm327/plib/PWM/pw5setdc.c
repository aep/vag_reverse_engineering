#include <p18cxxx.h>
#include <pwm.h>


/********************************************************************
*    Function Name:  SetDCPWM5                                      *
*    Return Value:   void                                           *
*    Parameters:     dutycycle: holds 10-bit duty cycle value       *
*    Description:    This routine writes the 10-bit value from      *
*                    dutycycle into the PWM5 duty cycle registers   *
*                    CCPR5L and CCP5CON.                            *
********************************************************************/
#if defined (PWM_V4) || defined (PWM_V9) || defined (PWM_V14) || defined (PWM_V14_1)\
	 || defined (PWM_V14_2) ||defined (PWM_V14_3) || defined (PWM_V14_4) || defined (PWM_V15) ||defined (PWM_V15_1)
void SetDCPWM5(unsigned int dutycycle)
{
  union PWMDC DCycle;

  // Save the dutycycle value in the union
  DCycle.lpwm = dutycycle << 6;
  
  // Write the high byte into CCPR5L
  CCPR5L = DCycle.bpwm[1];

  // Write the low byte into CCP5CON5:4
  CCP5CON = (CCP5CON & 0xCF) | ((DCycle.bpwm[0] >> 2) & 0x30);
}
#endif
