#include <p18cxxx.h>
#include <pwm.h>



#if  defined (PWM_V1) || defined (PWM_V2) || defined (PWM_V3) || defined (PWM_V5) ||\
     defined (PWM_V6) || defined (PWM_V7) || defined (EPWM_V7)
void OpenPWM1( char period )
{
  
  	CCP1CON |= 0b00001100;    //ccpxm3:ccpxm0 11xx=pwm mode  

	TRISCbits.TRISC2 = 0;
//---------------------------------------------------
  	T2CONbits.TMR2ON = 0;  // STOP TIMER2 registers to POR state
  	PR2 = period;          // Set period
  	T2CONbits.TMR2ON = 1;  // Turn on PWM1

}
////////////////////////////////////////////////////////////////////
// Configure I/Os
////////////////////////////////////////////////////////////////////
void OpenPWM1ConfigIO(void)
{

    TRISCbits.TRISC2=0;    //configure pin portc,2 as output

}
#elif  defined (PWM_V8) 
void OpenPWM1( char period )
{
  
  	CCP1CON |= 0b00001100;    //ccpxm3:ccpxm0 11xx=pwm mode  

	TRISBbits.TRISB3 = 0;
//---------------------------------------------------
  	T2CONbits.TMR2ON = 0;  // STOP TIMER2 registers to POR state
  	PR2 = period;          // Set period
  	T2CONbits.TMR2ON = 1;  // Turn on PWM1

}
////////////////////////////////////////////////////////////////////
// Configure I/Os
////////////////////////////////////////////////////////////////////
void OpenPWM1ConfigIO(void)
{

    TRISBbits.TRISB3=0;    //configure pin portc,2 as output
	
}

#elif  defined (PWM_V4) || defined (PWM_V9) 
void OpenPWM1( char period )
{
  
  	CCP1CON |= 0b00001100;    //ccpxm3:ccpxm0 11xx=pwm mode
  

	TRISCbits.TRISC2 = 0;
//---------------------------------------------------
	if (T3CONbits.T3CCP2 == 1 && T3CONbits.T3CCP1 == 1)
  	{
      	T4CONbits.TMR4ON = 0;  // STOP TIMER4 registers to POR state
     	PR4 = period;          // Set period
     	T4CONbits.TMR4ON = 1;  // Turn on PWM1
 	}
  	else
  	{
     	T2CONbits.TMR2ON = 0;  // STOP TIMER2 registers to POR state
     	PR2 = period;          // Set period
     	T2CONbits.TMR2ON = 1;  // Turn on PWM1
  	}

}

void OpenPWM1ConfigIO(void)
{

    TRISCbits.TRISC2=0;    //configure pin portc,2 as output
}

#elif   defined (PWM_V10) || defined (PWM_V12)
void OpenPWM1( char period )
{
  
  	CCP1CON |= 0b00001100;    //ccpxm3:ccpxm0 11xx=pwm mode
  

#if defined CCP1_V0
	#if defined PWM1_IO_V6
	TRISCbits.TRISC5 = 0;
	#else
	TRISCbits.TRISC2 = 0;
	#endif
#endif
//---------------------------------------------------
  	T2CONbits.TMR2ON = 0;  // STOP TIMER2 registers to POR state
  	PR2 = period;          // Set period
  	T2CONbits.TMR2ON = 1;  // Turn on PWM1
}


void OpenPWM1ConfigIO(void)
{

    if(PSTRCONbits.STRA == 1)
	{
		#if defined PWM1_IO_V6
		TRISCbits.TRISC5 = 0;
		#else
		TRISCbits.TRISC2 = 0;
		#endif
	}
    if(PSTRCONbits.STRB == 1)
    {
		#if defined PWM1_IO_V6
		TRISCbits.TRISC4 = 0;
		#else
		TRISBbits.TRISB2 = 0;  // P1B
		#endif
        ANSELHbits.ANS8 = 0;   // disable P1B analog
    }
    if(PSTRCONbits.STRC == 1)
    {
	   #if defined PWM1_IO_V6
	   TRISCbits.TRISC3 = 0;
	   #else
       TRISBbits.TRISB1 = 0;  // P1C
	   #endif
       ANSELHbits.ANS10 = 0;  // disable P1C analog
    }
    if(PSTRCONbits.STRD == 1)
    { 
	   #if defined PWM1_IO_V6
	   TRISCbits.TRISC2 = 0;
	   #else
       TRISBbits.TRISB4 = 0;  // P1D
	   #endif
       ANSELHbits.ANS11 = 0;  // disable P1D analog
    }

} 


#elif   defined (PWM_V11)
void OpenPWM1( char period )
{
  
  	CCP1CON |= 0b00001100;    //ccpxm3:ccpxm0 11xx=pwm mode
  

	TRISCbits.TRISC2 = 0;
//---------------------------------------------------
  	T2CONbits.TMR2ON = 0;  // STOP TIMER2 registers to POR state
  	PR2 = period;          // Set period
  	T2CONbits.TMR2ON = 1;  // Turn on PWM1


}

void OpenPWM1ConfigIO(void)
{
   if(PSTRCONbits.STRA == 1) TRISCbits.TRISC2 = 0;  // P1A
   if(PSTRCONbits.STRB == 1) TRISDbits.TRISD5 = 0;  // P1B
   if(PSTRCONbits.STRC == 1) TRISDbits.TRISD6 = 0;  // P1C
   if(PSTRCONbits.STRD == 1) TRISDbits.TRISD7 = 0;  // P1D
}

#elif   defined (PWM_V13)
void OpenPWM1( char period )
{
  
  	CCP1CON |= 0b00001100;    //ccpxm3:ccpxm0 11xx=pwm mode

  	T2CONbits.TMR2ON = 0;  // STOP TIMER2 registers to POR state
  	PR2 = period;          // Set period
  	T2CONbits.TMR2ON = 1;  // Turn on PWM1

}

#endif
