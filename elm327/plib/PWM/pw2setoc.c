#include <p18cxxx.h>
#include <pwm.h>


/********************************************************************
*    Function Name:  SetOutputPWM2                                  *
*    Return Value:   void                                           *
*    Parameters:     outputconfig: holds PWM output configuration.  *
*                    These configurations are defined in pwm.h.     *
*                    outputmode: holds PWM output mode.             *
*                    These modes are defined in pwm.h.              *
*    Description:    This routine sets the PWM output config bits   *
*                    and mode bits for ECCP2 and configures the     *
*                    appropriate TRIS bits for output.              *
********************************************************************/

#if defined (PWM_V4)
void SetOutputPWM2(unsigned char outputconfig, unsigned char outputmode)
{
  char pmmode; /* will be set iff bit 0 AND bit 1 of __CONFIG3L are set */
  char ccp2mx; /* will be set iff bit 0 of __CONFIG3H is set */
#ifndef _OMNI_CODE_
  unsigned char TBLPTR_U, TBLPTR_L;

_asm
movff TBLPTRU, TBLPTR_U
movff TBLPTRL, TBLPTR_L
_endasm
#endif

  /* set P1M1 and P1M0 */
  CCP2CON = (CCP2CON | 0b11000000) & outputconfig;
  /* set CCP1M3, CCP1M2, CCP1M1, CCP1M0 */
  CCP2CON = (CCP2CON | 0b00001111) & outputmode;

#if defined (PWM_CONFIG3L_V1) || defined (PWM_CONFIG3L_V2)
 	if (((*(unsigned char far rom *)__CONFIG3H) & 0b00000001))
    	ccp2mx=0xff;
 	else
     	ccp2mx = 0;
#endif

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

#if defined PWM2_IO_V5
	
	if (SINGLE_OUT == outputconfig)
  	{
   	 	if(ccp2mx) 	TRISCbits.TRISC1 = 0;
		else 		TRISEbits.TRISE7 = 0; 
  	}
  	else if (IS_DUAL_PWM(outputconfig))
  	{
		if(ccp2mx) 	TRISCbits.TRISC1 = 0;
		else 		TRISEbits.TRISE7 = 0;
					TRISEbits.TRISE2 = 0;
  	}
  	else if (IS_QUAD_PWM(outputconfig))
  	{
		if(ccp2mx) 	TRISCbits.TRISC1 = 0;
		else 		TRISEbits.TRISE7 = 0;
					TRISEbits.TRISE2 = 0;
					TRISEbits.TRISE1 = 0;
					TRISEbits.TRISE0 = 0;
  	}	
#elif defined PWM2_IO_V3
	if (SINGLE_OUT == outputconfig)
  	{
   	 	 	TRISCbits.TRISC1 = 0;
	}
  	else if (IS_DUAL_PWM(outputconfig))
  	{				
			TRISCbits.TRISC1 = 0;
			TRISEbits.TRISE2 = 0;
  	}
  	else if (IS_QUAD_PWM(outputconfig))
  	{
			TRISCbits.TRISC1 = 0;
			TRISEbits.TRISE2 = 0;
			TRISEbits.TRISE1 = 0;
			TRISEbits.TRISE0 = 0;
  	}
#elif defined PWM2_IO_V6
	if (SINGLE_OUT == outputconfig)
  	{
		if(ccp2mx) 			TRISCbits.TRISC1 = 0;
		else if(pmmode)		TRISEbits.TRISE7 = 0; 
		else				TRISBbits.TRISB3 = 0;
  	}
  	else if (IS_DUAL_PWM(outputconfig))
  	{
		if(ccp2mx) 			TRISCbits.TRISC1 = 0;
		else if(pmmode)		TRISEbits.TRISE7 = 0; 
		else				TRISBbits.TRISB3 = 0;
							TRISEbits.TRISE2 = 0;
  	}
  	else if (IS_QUAD_PWM(outputconfig))
  	{
		if(ccp2mx) 			TRISCbits.TRISC1 = 0;
		else if(pmmode)		TRISEbits.TRISE7 = 0; 
		else				TRISBbits.TRISB3 = 0;
							TRISEbits.TRISE2 = 0;
							TRISEbits.TRISE1 = 0;
							TRISEbits.TRISE0 = 0;
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
