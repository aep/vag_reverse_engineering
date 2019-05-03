#include <p18cxxx.h>
#include <pwm.h>


/********************************************************************
*    Function Name:  SetDCPWM3                                      *
*    Return Value:   void                                           *
*    Parameters:     dutycycle: holds 10-bit duty cycle value       *
*    Description:    This routine writes the 10-bit value from      *
*                    dutycycle into the PWM3 duty cycle registers   *
*                    CCPR3L and CCP3CON.                            *
********************************************************************/

#if defined (PWM_V3) || defined (PWM_V4) || defined (PWM_V9) || defined (PWM_V14_2)

void SetDCPWM3(unsigned int dutycycle)
{
  union PWMDC DCycle;

  // Save the dutycycle value in the union
  DCycle.lpwm = dutycycle << 6;

  // Write the high byte into CCPR3L
  CCPR3L = DCycle.bpwm[1];

  // Write the low byte into CCP3CON5:4
  CCP3CON = (CCP3CON & 0xCF) | ((DCycle.bpwm[0] >> 2) & 0x30);
}

#endif
