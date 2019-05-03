#include <p18cxxx.h>
#include <pwm.h>


/********************************************************************
*    Function Name:  SetOutputEPWM2                                 *
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
void SetOutputEPWM2(unsigned char outputconfig, unsigned char outputmode)
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
  
  #if defined (EPWM_V14_3) || defined (EPWM_V14_4)
  CCP2CON = (CCP2CON | 0b11000000) & outputconfig;
  /* set CCP1M3, CCP1M2, CCP1M1, CCP1M0 */
  CCP2CON = (CCP2CON | 0b00001111) & outputmode;
  #else
  	ECCP2CON = (ECCP2CON | 0b11000000) & outputconfig;
  /* set CCP1M3, CCP1M2, CCP1M1, CCP1M0 */
  ECCP2CON = (ECCP2CON | 0b00001111) & outputmode;
  #endif


#if defined (PWM_V14_IO_V1) || defined (PWM_V15_IO_V1) || defined (PWM_V15_2_IO_V1)
  if (((*(unsigned char far rom *)__CONFIG3H) & 0b00000001))
     eccpmx=0xff;
  else
     eccpmx = 0;
#endif
//--------------------------------------

	if (SINGLE_OUT == outputconfig)
  	{
#if defined (PWM_V14_IO_V1)	|| defined (PWM_V15_IO_V1) || defined (PWM_V15_2_IO_V1) 		
		if(eccpmx)
			TRISCbits.TRISC1 = 0;
		else
			 TRISEbits.TRISE7 = 0;
#elif defined (PWM_V14_IO_V2)
			TRISEbits.TRISE7 = 0; 
#endif		
	}
  	else if (IS_DUAL_PWM(outputconfig))
  	{				
#if defined (PWM_V14_IO_V1)	|| defined (PWM_V15_IO_V1) || defined (PWM_V15_2_IO_V1) 	 		
		if(eccpmx)
			TRISCbits.TRISC1 = 0;
		else
			 TRISEbits.TRISE7 = 0;
			 
			TRISEbits.TRISE2 = 0;
#elif defined (PWM_V14_IO_V2)
			TRISEbits.TRISE7 = 0; 
			TRISEbits.TRISE2 = 0;		
#endif		


  	}
  	else if (IS_QUAD_PWM(outputconfig))
  	{
#if defined (PWM_V14_IO_V1)	|| defined (PWM_V15_IO_V1) || defined (PWM_V15_2_IO_V1) 		
		if(eccpmx)
			TRISCbits.TRISC1 = 0;
		else
			 TRISEbits.TRISE7 = 0;
		TRISEbits.TRISE2 = 0;		
		TRISEbits.TRISE1 = 0;
		TRISEbits.TRISE0 = 0;			 
#elif defined (PWM_V14_IO_V2)
			TRISEbits.TRISE7 = 0;
		TRISEbits.TRISE2 = 0;		
		TRISEbits.TRISE1 = 0;
		TRISEbits.TRISE0 = 0;			
#endif		

  	}
//---------------------------------------------

#ifndef _OMNI_CODE_
_asm
movff TBLPTR_U, TBLPTRU
movff TBLPTR_L, TBLPTRL
_endasm
#endif
}

#elif defined (EPWM_V15) || defined (EPWM_V15_1)
void SetOutputEPWM2(unsigned char outputconfig, unsigned char outputmode)
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
  	ECCP2CON = (ECCP2CON | 0b11000000) & outputconfig;
  /* set CCP1M3, CCP1M2, CCP1M1, CCP1M0 */
  ECCP2CON = (ECCP2CON | 0b00001111) & outputmode;

//--------------------------------------

	if (SINGLE_OUT == outputconfig)
  	{
		if (((*(unsigned char far rom *)0x300005) & 0b00000001))
		{
			TRISCbits.TRISC1= 0;
		}
		else
		{
			TRISBbits.TRISB3 = 0;		
		}
	
	}
  	else if (IS_DUAL_PWM(outputconfig))
  	{				

		if (((*(unsigned char far rom *)0x300005) & 0b00000001))
		{
			TRISCbits.TRISC1= 0;
			TRISCbits.TRISC0 = 0;		
		}
		else
		{
			TRISBbits.TRISB5 = 0;
			TRISBbits.TRISB3 = 0;		
		}		
  	}
	
  	else if (IS_QUAD_PWM(outputconfig))
  	{
#if defined (EPWM_V15)	
		if (((*(unsigned char far rom *)0x300005) & 0b00000001))
		{
			TRISCbits.TRISC1= 0;
			TRISCbits.TRISC0 = 0;		
		}
		else
		{
			TRISBbits.TRISB5 = 0;
			TRISBbits.TRISB3 = 0;		
		}
		TRISDbits.TRISD3 = 0;
		TRISDbits.TRISD4 = 0;	
#endif		
  	}

#ifndef _OMNI_CODE_
_asm
movff TBLPTR_U, TBLPTRU
movff TBLPTR_L, TBLPTRL
_endasm	
#endif
}
#endif
