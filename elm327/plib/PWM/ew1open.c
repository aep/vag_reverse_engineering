#include <p18cxxx.h>
#include <pwm.h>


/********************************************************************
*    Function Name:  OpenEPWM1                                      *
*    Return Value:   void                                           *
*    Parameters:     period: PWM period                             *
*    Description:    This routine first resets the PWM registers    *
*                    to the POR state.  It then configures clock    *
*                    source.                                        *
********************************************************************/

#if defined (EPWM_V7)
void OpenEPWM1( char period )
{

  ECCP1CON=0b00001100;   //ccpxm3:ccpxm0 11xx=pwm mode
  
  T2CONbits.TMR2ON = 0;  // STOP TIMER2 registers to POR state
  PR2 = period;          // Set period
  T2CONbits.TMR2ON = 1;  // Turn on PWM1
}

#elif defined (EPWM_V14) || defined (EPWM_V14_1) ||defined (EPWM_V14_3) || defined (EPWM_V14_4)
void OpenEPWM1( unsigned char period, unsigned char timer_source )
{

  #if defined (EPWM_V14_3) || defined (EPWM_V14_4)
   CCP1CON=0b00001100;   //ccpxm3:ccpxm0 11xx=pwm mode
   #else
   ECCP1CON=0b00001100;   //ccpxm3:ccpxm0 11xx=pwm mode
   #endif
   

  //configure timer source for CCP
  CCPTMRS0 &= 0b11111100;
  CCPTMRS0 |= ((timer_source&0b00011000)>>3);  
  
  if( (CCPTMRS0&0x07)==0x00)
  {
  T2CONbits.TMR2ON = 0;  // STOP TIMERx registers to POR state
  PR2 = period;          // Set period
  T2CONbits.TMR2ON = 1;  // Turn on PWMx
  }
  
  else if( (CCPTMRS0&0x07)==0x01)
  {
  T4CONbits.TMR4ON = 0;  // STOP TIMERx registers to POR state
  PR4 = period;          // Set period
  T4CONbits.TMR4ON = 1;  // Turn on PWMx
  }
  
  else if( (CCPTMRS0&0x07)==0x02)
  {
  T6CONbits.TMR6ON = 0;  // STOP TIMERx registers to POR state
  PR6 = period;          // Set period
  T6CONbits.TMR6ON = 1;  // Turn on PWMx  
  }
 
  else if( (CCPTMRS0&0x07)==0x03)
  {
  T8CONbits.TMR8ON = 0;  // STOP TIMERx registers to POR state
  PR8 = period;          // Set period
  T8CONbits.TMR8ON = 1;  // Turn on PWMx 
  }
  
#if defined (EPWM_V14)

  else if( (CCPTMRS0&0x07)==0x04)
  {
  T10CONbits.TMR10ON = 0;  // STOP TIMERx registers to POR state
  PR10 = period;          // Set period
  T10CONbits.TMR10ON = 1;  // Turn on PWMx
}  
  
  else if( (CCPTMRS0&0x07)==0x05)
  {
  T12CONbits.TMR12ON = 0;  // STOP TIMERx registers to POR state
  PR12 = period;          // Set period
  T12CONbits.TMR12ON = 1;  // Turn on PWMx 
  }
#endif  
  
}

#elif defined (EPWM_V14_2)
void OpenEPWM1( unsigned char period, unsigned char timer_source )
{

  ECCP1CON=0b00001100;   //ccpxm3:ccpxm0 11xx=pwm mode

  //configure timer source for CCP
  CCPTMRS &= 0b11101111;
  CCPTMRS |= ((timer_source&0b00010000)>>4); 
  
  if( (CCPTMRS&0x01))
  {
  T4CONbits.TMR4ON = 0;  // STOP TIMERx registers to POR state
  PR4 = period;          // Set period
  T4CONbits.TMR4ON = 1;  // Turn on PWMx 
  }
  else
  {
  T2CONbits.TMR2ON = 0;  // STOP TIMERx registers to POR state
  PR2 = period;          // Set period
  T2CONbits.TMR2ON = 1;  // Turn on PWMx
  }
  
}
#elif defined (EPWM_V14_5)
void OpenEPWM1( unsigned char period, unsigned char timer_source )
{

  CCP1CON=0b00001100;   //ccpxm3:ccpxm0 11xx=pwm mode

  //configure timer source for CCP
  CCPTMRS &= 0b11101111;
  CCPTMRS |= ((timer_source&0b00010000)>>4); 
  
  if( (CCPTMRS&0x01))
  {
  T2CONbits.TMR2ON = 0;  // STOP TIMERx registers to POR state
  PR2 = period;          // Set period
  T2CONbits.TMR2ON = 1;  // Turn on PWMx
  }
  
}
#elif defined (EPWM_V15) || defined (EPWM_V15_1)
void OpenEPWM1( unsigned char period, unsigned char timer_source )
{

  ECCP1CON=0b00001100;   //ccpxm3:ccpxm0 11xx=pwm mode

  //configure timer source for CCP
  CCPTMRS0 &= 0b11111100;
  CCPTMRS0 |= ((timer_source&0b00110000)>>4);    
  
  if( (CCPTMRS0&0x03)==0x00)
  {
  T2CONbits.TMR2ON = 0;  // STOP TIMERx registers to POR state
  PR2 = period;          // Set period
  T2CONbits.TMR2ON = 1;  // Turn on PWMx
  }
  
  else if( (CCPTMRS0&0x03)==0x01)
  {
  T4CONbits.TMR4ON = 0;  // STOP TIMERx registers to POR state
  PR4 = period;          // Set period
  T4CONbits.TMR4ON = 1;  // Turn on PWMx
  }
  
  else if( (CCPTMRS0&0x03)==0x02)
  {
  T6CONbits.TMR6ON = 0;  // STOP TIMERx registers to POR state
  PR6 = period;          // Set period
  T6CONbits.TMR6ON = 1;  // Turn on PWMx  
  }
}
#endif
