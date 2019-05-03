#include <p18cxxx.h>
#include <pwm.h>

/********************************************************************
*    Function Name:  OpenPWM6                                       *
*    Return Value:   void                                           *
*    Parameters:     period: PWM period                             *
*    Description:    This routine first resets the PWM registers    *
*                    to the POR state.  It then configures clock    *
*                    source.                                        *
********************************************************************/
#if defined (PWM_V14) || defined (PWM_V14_1) ||defined (PWM_V14_3) || defined (PWM_V14_4)
void OpenPWM6 ( unsigned char period, unsigned char timer_source )
{
#ifndef _OMNI_CODE_
  unsigned char TBLPTR_U, TBLPTR_L;

_asm
movff TBLPTRU, TBLPTR_U
movff TBLPTRL, TBLPTR_L
_endasm
#endif

  CCP6CON=0b00001100;    //ccpxm3:ccpxm0 11xx=pwm mode

  //configure timer source for CCP
  CCPTMRS1 &= 0b11101111;
  CCPTMRS1 |= (timer_source&0b00010000);  
 
#if defined (PWM_V14_IO_V1)  || defined (PWM_V15_IO_V1) || defined (PWM_V15_2_IO_V1)
  if (((*(unsigned char far rom *)__CONFIG3H) & 0b00000010))
     TRISEbits.TRISE6 = 0;
  #ifndef PWM_V15_2_IO_V1
  else
     TRISHbits.TRISH7 = 0;
  #endif 	 
#else
	PWM6_TRIS = 0;
#endif
 
    

  T2CONbits.TMR2ON = 0;  // STOP TIMERx registers to POR state
  PR2 = period;          // Set period
  T2CONbits.TMR2ON = 1;  // Turn on PWMx
    
}

#endif
