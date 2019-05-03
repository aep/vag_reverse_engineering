#include <p18cxxx.h>
#include <pwm.h>


/********************************************************************
*    Function Name:  OpenEPWM3                                      *
*    Return Value:   void                                           *
*    Parameters:     period: PWM period                             *
*    Description:    This routine first resets the PWM registers    *
*                    to the POR state.  It then configures clock    *
*                    source.                                        *
********************************************************************/
#if defined (EPWM_V14) || defined (EPWM_V14_1) ||defined (EPWM_V14_3) || defined (EPWM_V14_4)
void OpenEPWM3( unsigned char period, unsigned char timer_source )
{

  CCP3CON=0b00001100;   //ccpxm3:ccpxm0 11xx=pwm mode

  //configure timer source for CCP
  CCPTMRS0 &= 0b00111111;
  CCPTMRS0 |= ((timer_source&0b00110000)<<2); 
  
  if( (CCPTMRS0&0xC0)==0x00)
  {
  T2CONbits.TMR2ON = 0;  // STOP TIMERx registers to POR state
  PR2 = period;          // Set period
  T2CONbits.TMR2ON = 1;  // Turn on PWMx
  }
  
  else if( (CCPTMRS0&0xC0)==0x40)
  {
  T4CONbits.TMR4ON = 0;  // STOP TIMERx registers to POR state
  PR4 = period;          // Set period
  T4CONbits.TMR4ON = 1;  // Turn on PWMx
  }
  
  else if( (CCPTMRS0&0xC0)==0x80)
  {
  T6CONbits.TMR6ON = 0;  // STOP TIMERx registers to POR state
  PR6 = period;          // Set period
  T6CONbits.TMR6ON = 1;  // Turn on PWMx  
  }
 
  else if( (CCPTMRS0&0xC0)==0xC0)
  {
  T8CONbits.TMR8ON = 0;  // STOP TIMERx registers to POR state
  PR8 = period;          // Set period
  T8CONbits.TMR8ON = 1;  // Turn on PWMx 
  }
  
}

#elif defined (EPWM_V15) || defined (EPWM_V15_1)
void OpenEPWM3( unsigned char period, unsigned char timer_source )
{

  CCP3CON=0b00001100;   //ccpxm3:ccpxm0 11xx=pwm mode

  //configure timer source for CCP
  CCPTMRS0 &= 0b00111111;
  CCPTMRS0 |= ((timer_source&0b00110000)<<2); 
  
  if( (CCPTMRS0&0xC0)==0x00)
  {
  T2CONbits.TMR2ON = 0;  // STOP TIMERx registers to POR state
  PR2 = period;          // Set period
  T2CONbits.TMR2ON = 1;  // Turn on PWMx
  }
  
  else if( (CCPTMRS0&0xC0)==0x40)
  {
  T4CONbits.TMR4ON = 0;  // STOP TIMERx registers to POR state
  PR4 = period;          // Set period
  T4CONbits.TMR4ON = 1;  // Turn on PWMx
  }
  
  else if( (CCPTMRS0&0xC0)==0x80)
  {
  T6CONbits.TMR6ON = 0;  // STOP TIMERx registers to POR state
  PR6 = period;          // Set period
  T6CONbits.TMR6ON = 1;  // Turn on PWMx  
  }
 
  
}

#endif
