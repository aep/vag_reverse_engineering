#include <p18cxxx.h>
#include <pwm.h>


/********************************************************************
*    Function Name:  SetOutputEPWM3                                *
*    Return Value:   void                                           *
*    Parameters:     outputconfig: holds PWM output configuration.  *
*                    These configurations are defined in pwm.h.     *
*                    outputmode: holds PWM output mode.             *
*                    These modes are defined in pwm.h.              *
*    Description:    This routine sets the PWM output config bits   *
*                    and mode bits for ECCP and configures the      *
*                    appropriate TRIS bits for output.              *
********************************************************************/
#if defined (EPWM_V14) || defined (EPWM_V14_1) ||defined (EPWM_V14_3) || defined (EPWM_V14_4)
void SetOutputEPWM3(unsigned char outputconfig, unsigned char outputmode)
{
  char eccpmx=0; /* will be set iff bit 1 of __CONFIG3H is set */
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
  	CCP3CON = (CCP3CON | 0b11000000) & outputconfig;
  /* set CCP1M3, CCP1M2, CCP1M1, CCP1M0 */
  CCP3CON = (CCP3CON | 0b00001111) & outputmode;

#if defined (PWM_V14_IO_V1) || defined (PWM_V15_IO_V1) || defined (PWM_V15_2_IO_V1) 	
  if (((*(unsigned char far rom *)__CONFIG3H) & 0b00000010))
     eccpmx=0xff;
  else
     eccpmx = 0;
#endif
//--------------------------------------
#if defined (PWM_V14_IO_V1)	|| defined (PWM_V14_IO_V2) || defined (PWM_V15_IO_V1) || defined (PWM_V15_2_IO_V1) 	
	if (SINGLE_OUT == outputconfig)
  	{
   	 	 	TRISGbits.TRISG0 = 0;
	}
  	else if (IS_DUAL_PWM(outputconfig))
  	{				
			TRISGbits.TRISG0 = 0;
#if defined (PWM_V14_IO_V1)	|| defined (PWM_V15_IO_V1)  		
		if(eccpmx)
			TRISEbits.TRISE4 = 0;
		else
			 TRISHbits.TRISH5 = 0;
#elif defined (PWM_V15_2_IO_V1)
		if(eccpmx)
			TRISEbits.TRISE4 = 0;
#elif defined (PWM_V14_IO_V2)
			TRISEbits.TRISE4 = 0; 
#endif			
  	}
  	else if (IS_QUAD_PWM(outputconfig))
  	{
			TRISGbits.TRISG0 = 0;
#if defined (PWM_V14_IO_V1)	|| defined (PWM_V15_IO_V1)  		
		if(eccpmx)	{TRISEbits.TRISE4 = 0;TRISEbits.TRISE3 = 0;}
		else		{TRISHbits.TRISH5 = 0;TRISHbits.TRISH4 = 0;}
			TRISGbits.TRISG3 = 0;		
#elif defined (PWM_V15_2_IO_V1)
		if(eccpmx)
			TRISEbits.TRISE4 = 0;
			TRISEbits.TRISE3 = 0;
			TRISGbits.TRISG3 = 0;				
#elif defined (PWM_V14_IO_V2)
			TRISEbits.TRISE4 = 0;
			TRISEbits.TRISE3 = 0;
			TRISGbits.TRISG3 = 0;			
#endif			

  	}
#endif	
//---------------------------------------------

#ifndef _OMNI_CODE_
_asm
movff TBLPTR_U, TBLPTRU
movff TBLPTR_L, TBLPTRL
_endasm
#endif
}
#elif defined (EPWM_V15_1)
void SetOutputEPWM3(unsigned char outputconfig, unsigned char outputmode)
{
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
  	CCP3CON = (CCP3CON | 0b11000000) & outputconfig;
  /* set CCP1M3, CCP1M2, CCP1M1, CCP1M0 */
  CCP3CON = (CCP3CON | 0b00001111) & outputmode;



	if (SINGLE_OUT == outputconfig)
  	{
		  if (((*(unsigned char far rom *)0x300005) & 0b00000001))
   	 	 	TRISBbits.TRISB5 = 0;
		  else
			TRISCbits.TRISC6 = 0;
	}
  	else if (IS_DUAL_PWM(outputconfig))
  	{				
		  if (((*(unsigned char far rom *)0x300005) & 0b00000001))
   	 	 	TRISBbits.TRISB5 = 0;
		  else
			TRISCbits.TRISC6 = 0;
			TRISCbits.TRISC7 = 0; 
  	}
		
}

#elif defined (EPWM_V15) 
void SetOutputEPWM3(unsigned char outputconfig, unsigned char outputmode)
{
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
  	CCP3CON = (CCP3CON | 0b11000000) & outputconfig;
  /* set CCP1M3, CCP1M2, CCP1M1, CCP1M0 */
  CCP3CON = (CCP3CON | 0b00001111) & outputmode;



	if (SINGLE_OUT == outputconfig)
  	{
		  if (((*(unsigned char far rom *)0x300005) & 0b00000001))
   	 	 	TRISBbits.TRISB5 = 0;
		  else
			TRISEbits.TRISE0 = 0;
	}
  	else if (IS_DUAL_PWM(outputconfig))
  	{				
		  if (((*(unsigned char far rom *)0x300005) & 0b00000001))
   	 	 	TRISBbits.TRISB5 = 0;
		  else
			TRISEbits.TRISE0 = 0;
			TRISEbits.TRISE1 = 0; 
  	}
		
}
#endif
