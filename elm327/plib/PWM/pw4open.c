#include <p18cxxx.h>
#include <pwm.h>


/********************************************************************
*    Function Name:  OpenPWM4                                       *
*    Return Value:   void                                           *
*    Parameters:     period: PWM period                             *
*    Description:    This routine first resets the PWM registers    *
*                    to the POR state.  It then configures clock    *
*                    source.                                        *
********************************************************************/
#if defined (PWM_V4) || defined (PWM_V9)	
void OpenPWM4( char period )
{
  CCP4CON=0b00001100;    //ccpxm3:ccpxm0 11xx=pwm mode

#if defined PWM4_IO_V1
	TRISDbits.TRISD2=0;    //configure pin portd,2 an output
#else
	TRISGbits.TRISG3=0;    //configure pin portg,3 an output
#endif 

	if (T3CONbits.T3CCP2 == 0 && T3CONbits.T3CCP1 == 0)
  	{
     	T2CONbits.TMR2ON = 0;  // STOP TIMER2 registers to POR state
     	PR2 = period;          // Set period
     	T2CONbits.TMR2ON = 1;  // Turn on PWM4
  	}
  	else
  	{
     	T4CONbits.TMR4ON = 0;  // STOP TIMER4 registers to POR state
     	PR4 = period;          // Set period
    	T4CONbits.TMR4ON = 1;  // Turn on PWM4
  	}
}

#elif defined (PWM_V14) || defined (PWM_V14_1) ||defined (PWM_V14_3) || defined (PWM_V14_4)
void OpenPWM4 ( unsigned char period, unsigned char timer_source )
{

  CCP4CON=0b00001100;    //ccpxm3:ccpxm0 11xx=pwm mode

  //configure timer source for CCP
  CCPTMRS1 &= 0b11111100;
  CCPTMRS1 |= ((timer_source&0b00110000)>>4);   
  
    PWM4_TRIS = 0;

  if( (CCPTMRS1&0x03)==0x00)
  {
  T2CONbits.TMR2ON = 0;  // STOP TIMERx registers to POR state
  PR2 = period;          // Set period
  T2CONbits.TMR2ON = 1;  // Turn on PWMx
  }
  
  else if( (CCPTMRS1&0x03)==0x01)
  {
  T4CONbits.TMR4ON = 0;  // STOP TIMERx registers to POR state
  PR4 = period;          // Set period
  T4CONbits.TMR4ON = 1;  // Turn on PWMx
  }
  
  else if( (CCPTMRS1&0x03)==0x02)
  {
  T6CONbits.TMR6ON = 0;  // STOP TIMERx registers to POR state
  PR6 = period;          // Set period
  T6CONbits.TMR6ON = 1;  // Turn on PWMx  
  }
}

#elif defined (PWM_V14_2)
void OpenPWM4 ( unsigned char period, unsigned char timer_source )
{

  CCP4CON=0b00001100;    //ccpxm3:ccpxm0 11xx=pwm mode

  //configure timer source for CCP
  CCPTMRS &= 0b11101111;
  CCPTMRS |= ((timer_source&0b00010000)>>1); 
  
    PWM4_TRIS = 0;

  if( (CCPTMRS&0x08))
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
#elif defined (PWM_V15) || defined (PWM_V15_1)
void OpenPWM4 ( unsigned char period, unsigned char timer_source )
{

  CCP4CON=0b00001100;    //ccpxm3:ccpxm0 11xx=pwm mode

  //configure timer source for CCP
  CCPTMRS1 &= 0b11111100;
  CCPTMRS1 |= ((timer_source&0b00110000)>>4);    
  
    PWM4_TRIS = 0;

  if( (CCPTMRS1&0x03)==0x00)
  {
  T2CONbits.TMR2ON = 0;  // STOP TIMERx registers to POR state
  PR2 = period;          // Set period
  T2CONbits.TMR2ON = 1;  // Turn on PWMx
  }
  
  else if( (CCPTMRS1&0x03)==0x01)
  {
  T4CONbits.TMR4ON = 0;  // STOP TIMERx registers to POR state
  PR4 = period;          // Set period
  T4CONbits.TMR4ON = 1;  // Turn on PWMx
  }
  
  else if( (CCPTMRS1&0x03)==0x02)
  {
  T6CONbits.TMR6ON = 0;  // STOP TIMERx registers to POR state
  PR6 = period;          // Set period
  T6CONbits.TMR6ON = 1;  // Turn on PWMx  
  }
}

#endif
