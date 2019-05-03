#include <p18cxxx.h>
#include <pwm.h>


/********************************************************************
*    Function Name:  SetOutputPWM3                                  *
*    Return Value:   void                                           *
*    Parameters:     outputconfig: holds PWM output configuration.  *
*                    These configurations are defined in pwm.h.     *
*                    outputmode: holds PWM output mode.             *
*                    These modes are defined in pwm.h.              *
*    Description:    This routine sets the PWM output config bits   *
*                    and mode bits for ECCP3 and configures the     *
*                    appropriate TRIS bits for output.              *
*                    Microcontroller mode is assumed.               *
********************************************************************/

#if defined (PWM_V4)

void SetOutputPWM3(unsigned char outputconfig, unsigned char outputmode)
{
  #define __CONFIG3H 0x300005
  char eccpmx; /* will be set iff bit 1 of __CONFIG3H is set */
#ifndef _OMNI_CODE_
  unsigned char TBLPTR_U, TBLPTR_L;

_asm
movff TBLPTRU, TBLPTR_U
movff TBLPTRL, TBLPTR_L
_endasm
#endif

  /* set P1M1 and P1M0 */
  CCP3CON = (CCP3CON | 0b11000000) & outputconfig;
  /* set CCP1M3, CCP1M2, CCP1M1, CCP1M0 */
  CCP3CON = (CCP3CON | 0b00001111) & outputmode;
     
#if defined (PWM1_IO_V4)
  if (((*(unsigned char far rom *)__CONFIG3H) & 0b00000010))
     eccpmx=0xff;
  else
     eccpmx = 0;
#endif

#if defined PWM3_IO_V1
	if (SINGLE_OUT == outputconfig)
  	{
   	 	 	TRISDbits.TRISD1 = 0;
	}
  	else if (IS_DUAL_PWM(outputconfig))
  	{				
			TRISDbits.TRISD1 = 0;
			TRISEbits.TRISE4 = 0;
  	}
  	else if (IS_QUAD_PWM(outputconfig))
  	{
			TRISDbits.TRISD1 = 0;
			TRISEbits.TRISE4 = 0;
			TRISEbits.TRISE3 = 0;
			TRISDbits.TRISD2 = 0;
  	}
#elif defined PWM3_IO_V2
	if (SINGLE_OUT == outputconfig)
  	{
   	 	 	TRISGbits.TRISG0 = 0;
	}
  	else if (IS_DUAL_PWM(outputconfig))
  	{				
			TRISGbits.TRISG0 = 0;
			TRISEbits.TRISE4 = 0;
  	}
  	else if (IS_QUAD_PWM(outputconfig))
  	{
			TRISGbits.TRISG0 = 0;
			TRISEbits.TRISE4 = 0;
			TRISEbits.TRISE3 = 0;
			TRISGbits.TRISG3 = 0;
  	}
#elif defined PWM3_IO_V3
	if (SINGLE_OUT == outputconfig)
  	{
   	 	 	TRISGbits.TRISG0 = 0;
	}
  	else if (IS_DUAL_PWM(outputconfig))
  	{				
			TRISGbits.TRISG0 = 0;
			if(eccpmx)	TRISEbits.TRISE4 = 0;
			else 		TRISHbits.TRISH5 = 0;
  	}
  	else if (IS_QUAD_PWM(outputconfig))
  	{
			TRISGbits.TRISG0 = 0;
			if(eccpmx)	{TRISEbits.TRISE4 = 0;TRISEbits.TRISE3 = 0;}
			else 		{TRISHbits.TRISH5 = 0;TRISHbits.TRISH4 = 0;}
			TRISGbits.TRISG3 = 0;
  	}
#endif

#ifndef _OMNI_CODE_
_asm
movff TBLPTR_U, TBLPTRU
movff TBLPTR_L, TBLPTRL
_endasm
#endif

}
#endif
