#include <p18cxxx.h>
#include <pwm.h>


/********************************************************************
*    Function Name:  SetDCEPWM1                                     *
*    Return Value:   void                                           *
*    Parameters:     dutycycle: holds 10-bit duty cycle value       *
*    Description:    This routine writes the 10-bit value from      *
*                    dutycycle into the PWM1 duty cycle registers   *
*                    ECCPR1L and ECCP1CON.                          *
********************************************************************/
#if defined (EPWM_V7) 

void SetDCEPWM1(unsigned int dutycycle)
{
  union PWMDC DCycle;

  // Save the dutycycle value in the union
  DCycle.lpwm = dutycycle << 6;

  // Write the high byte into ECCPR1L
  ECCPR1L = DCycle.bpwm[1];

  // Write the low byte into ECCP1CON5:4
  ECCP1CON = (ECCP1CON & 0xCF) | ((DCycle.bpwm[0] >> 2) & 0x30);
}

#elif defined (EPWM_V14) || defined (EPWM_V14_1) || defined (EPWM_V14_2) \
	||defined (EPWM_V14_3) || defined (EPWM_V14_4) || defined (EPWM_V14_5) || defined (EPWM_V15) || defined (EPWM_V15_1)

void SetDCEPWM1(unsigned int dutycycle)
{
  union PWMDC DCycle;

  // Save the dutycycle value in the union
  DCycle.lpwm = dutycycle << 6;

  // Write the high byte into ECCPR1L
  CCPR1L = DCycle.bpwm[1];

  // Write the low byte into ECCP1CON5:4
   #if defined (EPWM_V14_3) || defined (EPWM_V14_4) || defined (EPWM_V14_5) 
   CCP1CON = (CCP1CON & 0xCF) | ((DCycle.bpwm[0] >> 2) & 0x30);
   #else
   ECCP1CON = (ECCP1CON & 0xCF) | ((DCycle.bpwm[0] >> 2) & 0x30);
   #endif
   
}

#endif
