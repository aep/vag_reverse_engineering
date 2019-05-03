#include <p18cxxx.h>
#include <pwm.h>

/********************************************************************
*    Function Name:  OpenPWM10                                      *
*    Return Value:   void                                           *
*    Parameters:     period: PWM period                             *
*    Description:    This routine first resets the PWM registers    *
*                    to the POR state.  It then configures clock    *
*                    source.                                        *
********************************************************************/
#if defined (PWM_V14) ||defined (PWM_V14_3) 
void OpenPWM10 ( unsigned char period, unsigned char timer_source )
{

  CCP10CON=0b00001100;    //ccpxm3:ccpxm0 11xx=pwm mode

  //configure timer source for CCP
  CCPTMRS2 &= 0b11101111;
  CCPTMRS2 |= (timer_source&0b00010000); 
 
	PWM10_TRIS = 0;

  T2CONbits.TMR2ON = 0;  // STOP TIMERx registers to POR state
  PR2 = period;          // Set period
  T2CONbits.TMR2ON = 1;  // Turn on PWMx
  
   
    
}

#endif
