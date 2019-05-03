#include <p18cxxx.h>
#include <pwm.h>


#if defined (PWM_V1) || defined (PWM_V2) || defined (PWM_V3) || defined (PWM_V4) || defined (PWM_V5) || defined (PWM_V6) || defined (PWM_V7) || defined (EPWM_V7) || defined (PWM_V9)

void ClosePWM1(void)
{
  CCP1CON=0;
//  TRISCbits.TRISC2=1;		//NO need to tristate the port and disable pwm output on it.  Commented to maintain consistency with respect to other colse pwm functions

}

#elif  defined (PWM_V8)
void ClosePWM1(void)
{
  CCP1CON=0;
//  TRISBbits.TRISB3=1;	//NO need to tristate the port and disable pwm output on it.  Commented to maintain consistency with respect to other colse pwm functions

}

#elif  defined (PWM_V10) || defined (PWM_V12)
//TODO add code
void ClosePWM1(void)
{
  CCP1CON=0;
  // #if defined PWM1_IO_V6		//NO need to tristate the port and disable pwm output on it.  Commented to maintain consistency with respect to other colse pwm functions
  // if(PSTRCONbits.STRA == 1) TRISCbits.TRISC5 = 1;  // P1A
  // if(PSTRCONbits.STRB == 1) TRISCbits.TRISC4 = 1;  // P1B
  // if(PSTRCONbits.STRC == 1) TRISCbits.TRISC3 = 1;  // P1C
  // if(PSTRCONbits.STRD == 1) TRISCbits.TRISC2 = 1;  // P1D		
  // #else
  // if(PSTRCONbits.STRA == 1) TRISCbits.TRISC2 = 1;  // P1A
  // if(PSTRCONbits.STRB == 1) TRISBbits.TRISB2 = 1;  // P1B
  // if(PSTRCONbits.STRC == 1) TRISBbits.TRISB1 = 1;  // P1C
  // if(PSTRCONbits.STRD == 1) TRISBbits.TRISB4 = 1;  // P1D
  // #endif
}
#elif  defined (PWM_V11)
//TODO add code
void ClosePWM1(void)
{
  CCP1CON=0;
  
  //NO need to tristate the port and disable pwm output on it.  Commented to maintain consistency with respect to other colse pwm functions
  // if(PSTRCONbits.STRA == 1) TRISCbits.TRISC2 = 1;  // P1A
  // if(PSTRCONbits.STRB == 1) TRISDbits.TRISD5 = 1;  // P1B
  // if(PSTRCONbits.STRC == 1) TRISDbits.TRISD6 = 1;  // P1C
  // if(PSTRCONbits.STRD == 1) TRISDbits.TRISD7 = 1;  // P1D
}

#elif defined (PWM_V13)
void ClosePWM1(void)
{
	CCP1CON=0;
	
}
#endif
