#include <p18cxxx.h>
#include <pwm.h>


/********************************************************************
*    Function Name:  SetOutputPWM1                                  *
*    Return Value:   void                                           *
*    Parameters:     outputconfig: holds PWM output configuration.  *
*                    These configurations are defined in pwm.h.     *
*                    outputmode: holds PWM output mode.             *
*                    These modes are defined in pwm.h.              *
*    Description:    This routine sets the PWM output config bits   *
*                    and mode bits for ECCP and configures the      *
*                    appropriate TRIS bits for output.              *
********************************************************************/


#if defined (PWM_V1) || defined (PWM_V2) || defined (PWM_V3) || defined (PWM_V4) ||\
    defined (PWM_V5) || defined (PWM_V6) || defined (PWM_V7) || defined (EPWM_V7) ||\
	defined (PWM_V9) ||  defined (PWM_V10) ||  defined (PWM_V11) ||  defined (PWM_V12) 

void SetOutputPWM1(unsigned char outputconfig, unsigned char outputmode)
{
  char eccpmx; /* will be set iff bit 1 of __CONFIG3H is set */
#ifndef _OMNI_CODE_
  unsigned char TBLPTR_U, TBLPTR_L;

_asm
movff TBLPTRU, TBLPTR_U
movff TBLPTRL, TBLPTR_L
_endasm
#endif

  /* set P1M1 and P1M0 */
  	outputconfig |= 0b00111111;
  	outputmode |= 0b11111100;
  	CCP1CON = (CCP1CON | 0b11000000) & outputconfig;
  /* set CCP1M3, CCP1M2, CCP1M1, CCP1M0 */
  CCP1CON = (CCP1CON | 0b00001111) & outputmode;
  
#if defined (PWM_CONFIG3L_V1) || defined (PWM_CONFIG3L_V2)
#if defined (PWM1_IO_V4)
  if (((*(unsigned char far rom *)__CONFIG3H) & 0b00000010))
     eccpmx=0xff;
  else
     eccpmx = 0;
#endif
#endif
//--------------------------------------

#if defined PWM1_IO_V1	
	if (SINGLE_OUT == outputconfig)
  	{
   	 	 	TRISCbits.TRISC2 = 0;
	}
  	else if (IS_DUAL_PWM(outputconfig))
  	{				
			TRISCbits.TRISC2 = 0;
			TRISDbits.TRISD5 = 0;
  	}
  	else if (IS_QUAD_PWM(outputconfig))
  	{
			TRISCbits.TRISC2 = 0;
			TRISDbits.TRISD5 = 0;
			TRISDbits.TRISD6 = 0;
			TRISDbits.TRISD7 = 0;
  	}
#elif defined PWM1_IO_V2 
	if (SINGLE_OUT == outputconfig)
  	{
   	 	 	TRISCbits.TRISC2 = 0;
	}
  	else if (IS_DUAL_PWM(outputconfig))
  	{				
			TRISCbits.TRISC2 = 0;
			TRISEbits.TRISE6 = 0;
  	}
  	else if (IS_QUAD_PWM(outputconfig))
  	{
			TRISCbits.TRISC2 = 0;
			TRISEbits.TRISE6 = 0;
			TRISEbits.TRISE5 = 0;
			TRISGbits.TRISG4 = 0;
  	}
#elif defined PWM1_IO_V3 
	if (SINGLE_OUT == outputconfig)
  	{
   	 	 	TRISCbits.TRISC2 = 0;
	}
  	else if (IS_DUAL_PWM(outputconfig))
  	{				
			TRISCbits.TRISC2 = 0;
			TRISDbits.TRISD0 = 0;
  	}
  	else if (IS_QUAD_PWM(outputconfig))
  	{
			TRISCbits.TRISC2 = 0;
			TRISDbits.TRISD0 = 0;
			TRISEbits.TRISE5 = 0;
			TRISGbits.TRISG4 = 0;
  	}
	
#elif defined PWM1_IO_V4
	if (SINGLE_OUT == outputconfig)
  	{
   	 	 	TRISCbits.TRISC2 = 0;
	}
  	else if (IS_DUAL_PWM(outputconfig))
  	{				
			TRISCbits.TRISC2 = 0;
		if(eccpmx)
			TRISEbits.TRISE6 = 0;
		else
			 TRISHbits.TRISH7 = 0;
  	}
  	else if (IS_QUAD_PWM(outputconfig))
  	{
			TRISCbits.TRISC2 = 0;
		if(eccpmx)	{TRISEbits.TRISE6 = 0;TRISEbits.TRISE5 = 0;}
		else		{TRISHbits.TRISH7 = 0;TRISHbits.TRISH6 = 0;}
			TRISGbits.TRISG4 = 0;
  	}
	
#elif defined PWM1_IO_V6
	if (SINGLE_OUT == outputconfig)
  	{
   	 	 	TRISCbits.TRISC5 = 0;
	}
  	else if (IS_DUAL_PWM(outputconfig))
  	{				
			TRISCbits.TRISC5 = 0;
			TRISCbits.TRISC4 = 0;
  	}
  	else if (IS_QUAD_PWM(outputconfig))
  	{
			TRISCbits.TRISC5 = 0;
			TRISCbits.TRISC4 = 0;
			TRISCbits.TRISC3 = 0;
			TRISCbits.TRISC2 = 0;

  	}	
//---------------------------------------------
#endif

#ifndef _OMNI_CODE_
_asm
movff TBLPTR_U, TBLPTRU
movff TBLPTR_L, TBLPTRL
_endasm
#endif
}


#elif defined (PWM_V8)  
void SetOutputPWM1(unsigned char outputconfig, unsigned char outputmode)
{
  char eccpmx; /* will be set iff bit 1 of __CONFIG3H is set */
#ifndef _OMNI_CODE_
  unsigned char TBLPTR_U, TBLPTR_L;

_asm
movff TBLPTRU, TBLPTR_U
movff TBLPTRL, TBLPTR_L
_endasm
#endif

  /* set P1M1 and P1M0 */
  	outputconfig |= 0b00111111;
  	outputmode |= 0b11111100;
  	CCP1CON = (CCP1CON | 0b11000000) & outputconfig;
  /* set CCP1M3, CCP1M2, CCP1M1, CCP1M0 */
  CCP1CON = (CCP1CON | 0b00001111) & outputmode;

#if defined (PWM1_IO_V4)
  if (((*(unsigned char far rom *)__CONFIG3H) & 0b00000010))
     eccpmx=0xff;
  else
     eccpmx = 0;
#endif
//--------------------------------------

	if (SINGLE_OUT == outputconfig)
  	{
   	 	TRISBbits.TRISB3 = 0;
	}
  	else if (IS_DUAL_PWM(outputconfig))
  	{
		TRISBbits.TRISB3 = 0;
		TRISBbits.TRISB2 = 0;	
  	}
  	else if (IS_QUAD_PWM(outputconfig))
  	{
		TRISBbits.TRISB3 = 0;
		TRISBbits.TRISB2 = 0;
		TRISBbits.TRISB6 = 0;
		TRISBbits.TRISB7 = 0;	
  	}	

#ifndef _OMNI_CODE_	
_asm
movff TBLPTR_U, TBLPTRU
movff TBLPTR_L, TBLPTRL
_endasm	
#endif
}

#elif defined (PWM_V13)
void SetOutputPWM1(unsigned char outputconfig, unsigned char outputmode)
{

  /* set P1M1 and P1M0 */
  	outputconfig |= 0b00111111;
  	outputmode   |= 0b11111100;
	
  	CCP1CON = (CCP1CON | 0b11000000) & outputconfig;
  /* set CCP1M3, CCP1M2, CCP1M1, CCP1M0 */
    CCP1CON = (CCP1CON | 0b00001111) & outputmode;
	
}

#endif

