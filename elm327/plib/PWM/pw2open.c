#include <p18cxxx.h>
#include <pwm.h>


/********************************************************************
*    Function Name:  OpenPWM2                                       *
*    Return Value:   void                                           *
*    Parameters:     period: PWM period                             *
*    Description:    This routine first resets the PWM registers    *
*                    to the POR state.  It then configures clock    *
*                    source.                                        *
*    Notes:          The bit definitions for config can be found    *
*                    in the pwm.h file.                             *
********************************************************************/

#if defined (PWM_V2) || defined (PWM_V3) || defined (PWM_V5) || defined (PWM_V6) || defined (PWM_V10) ||  defined (PWM_V11) 

void OpenPWM2( char period )
{
#define __CONFIG3L 0x300004
#define __CONFIG3H 0x300005
char pmmode; /* will be set iff either bit 0 AND bit 1 or bit 5 AND bit 4 of __CONFIG3L are set */
char ccp2mx; /* will be set iff bit 0 of __CONFIG3H is set */
#ifndef _OMNI_CODE_
unsigned char TBLPTR_U, TBLPTR_L;

_asm
movff TBLPTRU, TBLPTR_U
movff TBLPTRL, TBLPTR_L
_endasm
#endif

  	CCP2CON = 0b00001100;    //ccpxm3:ccpxm0 11xx=pwm mode

 	if (((*(unsigned char far rom *)__CONFIG3H) & 0b00000001))
    	ccp2mx=0xff;
 	else
     	ccp2mx = 0;

#if defined PWM_CONFIG3L_V1
  	if (((*(unsigned char far rom *)__CONFIG3L) & 0b00000011) == 0b00000011)
     	pmmode=0xff;
  	else
     	pmmode = 0;
#elif defined PWM_CONFIG3L_V2
	if (((*(unsigned char far rom *)__CONFIG3L) & 0b00110000) == 0b00110000)
     	pmmode=0xff;
  	else
    	pmmode = 0;
#endif

#if defined CCP2_V0
	TRISCbits.TRISC1 = 0;
#elif defined PWM2_IO_V1
	if(ccp2mx)	TRISCbits.TRISC1 = 0;
	else 		TRISBbits.TRISB3 = 0;
#elif defined PWM2_IO_V7
	TRISBbits.TRISB3 = 0;
#elif defined PWM2_IO_V8
	TRISEbits.TRISE7 = 0;
#elif defined PWM2_IO_V2
	if(ccp2mx)	TRISCbits.TRISC1 = 0;
	else 		TRISEbits.TRISE7 = 0;
#elif defined PWM2_IO_V4
	if(ccp2mx)	TRISCbits.TRISC1 = 0;
	else if(pmmode)		TRISEbits.TRISE7 = 0;		// Microcontroller mode
	else				TRISBbits.TRISB3 = 0;
#endif
//-------------------------------------
  		T2CONbits.TMR2ON = 0;  // STOP TIMER2 registers to POR state
  		PR2 = period;          // Set period
  		T2CONbits.TMR2ON = 1;  // Turn on PWM1

#ifndef _OMNI_CODE_		
_asm
movff TBLPTR_U, TBLPTRU
movff TBLPTR_L, TBLPTRL
_endasm
#endif
}

#elif  defined (PWM_V4) || defined (PWM_V9) 

void OpenPWM2( char period )
{
#define __CONFIG3L 0x300004
#define __CONFIG3H 0x300005
char pmmode; /* will be set iff either bit 0 AND bit 1 or bit 5 AND bit 4 of __CONFIG3L are set */
char ccp2mx; /* will be set iff bit 0 of __CONFIG3H is set */
#ifndef _OMNI_CODE_
unsigned char TBLPTR_U, TBLPTR_L;

_asm
movff TBLPTRU, TBLPTR_U
movff TBLPTRL, TBLPTR_L
_endasm
#endif
  	CCP2CON = 0b00001100;    //ccpxm3:ccpxm0 11xx=pwm mode

 	if (((*(unsigned char far rom *)__CONFIG3H) & 0b00000001))
    	ccp2mx=0xff;
 	else
     	ccp2mx = 0;

#if defined PWM_CONFIG3L_V1
  	if (((*(unsigned char far rom *)__CONFIG3L) & 0b00000011) == 0b00000011)
     	pmmode=0xff;
  	else
     	pmmode = 0;
#elif defined PWM_CONFIG3L_V2
	if (((*(unsigned char far rom *)__CONFIG3L) & 0b00110000) == 0b00110000)
     	pmmode=0xff;
  	else
    	pmmode = 0;
#endif

#if defined PWM2_IO_V1
	if(ccp2mx)	TRISCbits.TRISC1 = 0;
	else 		TRISBbits.TRISB3 = 0;
#elif defined PWM2_IO_V7
	TRISBbits.TRISB3 = 0;
#elif defined PWM2_IO_V8
	TRISEbits.TRISE7 = 0;
#elif defined PWM2_IO_V2
	if(ccp2mx)	TRISCbits.TRISC1 = 0;
	else 		TRISEbits.TRISE7 = 0;
#elif defined PWM2_IO_V4
	if(ccp2mx)	TRISCbits.TRISC1 = 0;
	else if(pmmode)		TRISEbits.TRISE7 = 0;		// Microcontroller mode
	else				TRISBbits.TRISB3 = 0;
#else
	TRISCbits.TRISC1 = 0;
#endif
//-------------------------------------

	if (T3CONbits.T3CCP1 == 0)
  	{
     	T2CONbits.TMR2ON = 0;  // STOP TIMER2 registers to POR state
     	PR2 = period;          // Set period
       	T2CONbits.TMR2ON = 1;  // Turn on PWM2
  	}
 	else
  	{
     	T4CONbits.TMR4ON = 0;  // STOP TIMER4 registers to POR state
     	PR4 = period;          // Set period
     	T4CONbits.TMR4ON = 1;  // Turn on PWM2
  	}

#ifndef _OMNI_CODE_	
_asm
movff TBLPTR_U, TBLPTRU
movff TBLPTR_L, TBLPTRL
_endasm	
#endif
}

#elif defined (PWM_V13)

void OpenPWM2( char period )
{
  	CCP2CON = 0b00001100;    //ccpxm3:ccpxm0 11xx=pwm mode

  	T2CONbits.TMR2ON = 0;  // STOP TIMER2 registers to POR state
  	PR2 = period;          // Set period
  	T2CONbits.TMR2ON = 1;  // Turn on PWM
	
}

#elif defined (PWM_V14_2)
void OpenPWM2 ( unsigned char period, unsigned char timer_source )
{

  CCP2CON=0b00001100;    //ccpxm3:ccpxm0 11xx=pwm mode

  //configure timer source for CCP
  CCPTMRS &= 0b11101111;
  CCPTMRS |= ((timer_source&0b00010000)>>3); 
  
    PWM2_TRIS = 0;

  if( (CCPTMRS&0x02))
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

#elif defined (PWM_V14_5)
void OpenPWM2 ( unsigned char period, unsigned char timer_source )
{

  CCP2CON=0b00001100;    //ccpxm3:ccpxm0 11xx=pwm mode

  //configure timer source for CCP
  CCPTMRS &= 0b11101111;
  CCPTMRS |= ((timer_source&0b00010000)>>1); 
  
    PWM2_TRIS = 0;

  if( (CCPTMRS&0x08))
  {
  T2CONbits.TMR2ON = 0;  // STOP TIMERx registers to POR state
  PR2 = period;          // Set period
  T2CONbits.TMR2ON = 1;  // Turn on PWMx 
  }
 
}
#endif
