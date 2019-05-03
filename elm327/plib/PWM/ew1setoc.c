#include <p18cxxx.h>
#include <pwm.h>


/********************************************************************
*    Function Name:  SetOutputEPWM1                                 *
*    Return Value:   void                                           *
*    Parameters:     outputconfig: holds PWM output configuration.  *
*                    These configurations are defined in pwm.h.     *
*                    outputmode: holds PWM output mode.             *
*                    These modes are defined in pwm.h.              *
*    Description:    This routine sets the PWM output config bits   *
*                    and mode bits for ECCP and configures the      *
*                    appropriate TRIS bits for output.              *
********************************************************************/
#if defined (EPWM_V7)

void SetOutputEPWM1(unsigned char outputconfig, unsigned char outputmode)
{
  // #define __CONFIG3H 0x300005
  // #define __ECCPMX 1  /* bit 1 of __CONFIG3H */
  // static char eccpmx; /* will be set iff bit 1 of __CONFIG3H is set */

 // set P1M1 and P1M0
  ECCP1CON = (ECCP1CON | 0b11000000) & outputconfig;
  // set CCP1M3, CCP1M2, CCP1M1, CCP1M0
  ECCP1CON = (ECCP1CON | 0b00001111) & outputmode;

  if (SINGLE_OUT == outputconfig)
  {
      TRISDbits.TRISD4 = 0;
  }
  else if (IS_DUAL_PWM(outputconfig))
  {
      TRISDbits.TRISD4 = 0;
      TRISDbits.TRISD5 = 0;
  }
  else if (IS_QUAD_PWM(outputconfig))
  {
      TRISDbits.TRISD4 = 0;
      TRISDbits.TRISD5 = 0;
      TRISDbits.TRISD6 = 0;
      TRISDbits.TRISD7 = 0;
  }
}



#elif defined (EPWM_V14) || defined (EPWM_V14_1) ||defined (EPWM_V14_3) || defined (EPWM_V14_4)
void SetOutputEPWM1(unsigned char outputconfig, unsigned char outputmode)
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
   CCP1CON = (CCP1CON | 0b11000000) & outputconfig;
  /* set CCP1M3, CCP1M2, CCP1M1, CCP1M0 */
	CCP1CON = (CCP1CON | 0b00001111) & outputmode;
   #else
   ECCP1CON = (ECCP1CON | 0b11000000) & outputconfig;
  /* set CCP1M3, CCP1M2, CCP1M1, CCP1M0 */
  ECCP1CON = (ECCP1CON | 0b00001111) & outputmode;

   #endif

#if defined (PWM_V14_IO_V1) || defined (PWM_V15_IO_V1) || defined (PWM_V15_2_IO_V1) 	
  if (((*(unsigned char far rom *)__CONFIG3H) & 0b00000010))
     eccpmx=0xff;
  else
     eccpmx = 0;
#endif
//--------------------------------------

	if (SINGLE_OUT == outputconfig)
  	{
   	 	 	TRISCbits.TRISC2 = 0;
	}
  	else if (IS_DUAL_PWM(outputconfig))
  	{				
			TRISCbits.TRISC2 = 0;
#if defined (PWM_V14_IO_V1)	|| defined (PWM_V15_IO_V1)		
		if(eccpmx)
			TRISEbits.TRISE6 = 0;
		else
			 TRISHbits.TRISH7 = 0;
#elif defined (PWM_V15_2_IO_V1)
		if(eccpmx)
			TRISEbits.TRISE6 = 0;
#elif defined (PWM_V14_IO_V2) 
			TRISEbits.TRISE6 = 0; 
#endif			
  	}
  	else if (IS_QUAD_PWM(outputconfig))
  	{
			TRISCbits.TRISC2 = 0;
#if defined (PWM_V14_IO_V1)	|| defined (PWM_V15_IO_V1)		
		if(eccpmx)	{TRISEbits.TRISE6 = 0;TRISEbits.TRISE5 = 0;}
		else		{TRISHbits.TRISH7 = 0;TRISHbits.TRISH6 = 0;}
		TRISGbits.TRISG4 = 0;
#elif defined (PWM_V15_2_IO_V1)
		if(eccpmx)
			TRISEbits.TRISE6 = 0;
			TRISEbits.TRISE5 = 0;
			TRISGbits.TRISG4 = 0;		
#elif defined (PWM_V14_IO_V2) 
			TRISEbits.TRISE6 = 0;
			TRISEbits.TRISE5 = 0;
			TRISGbits.TRISG4 = 0;
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

#elif defined (EPWM_V14_2)
void SetOutputEPWM1(unsigned char outputconfig, unsigned char outputmode)
{

  /* set P1M1 and P1M0 */
  	outputconfig |= 0b00111111;
  	outputmode |= 0b11111100;
  	ECCP1CON = (ECCP1CON | 0b11000000) & outputconfig;
  /* set CCP1M3, CCP1M2, CCP1M1, CCP1M0 */
  ECCP1CON = (ECCP1CON | 0b00001111) & outputmode;

//--------------------------------------
#if defined(PWM14_2_IO_V2)
  if (SINGLE_OUT == outputconfig)
  {
      TRISDbits.TRISD4 = 0;
  }
  else if (IS_DUAL_PWM(outputconfig))
  {
      TRISDbits.TRISD4 = 0;
      TRISDbits.TRISD5 = 0;
  }
  else if (IS_QUAD_PWM(outputconfig))
  {
      TRISDbits.TRISD4 = 0;
      TRISDbits.TRISD5 = 0;
      TRISDbits.TRISD6 = 0;
      TRISDbits.TRISD7 = 0;
  }
#elif defined(PWM14_2_IO_V1)
  if (SINGLE_OUT == outputconfig)
  {
      TRISBbits.TRISB4 = 0;
  }
  else if (IS_DUAL_PWM(outputconfig))
  {
      TRISBbits.TRISB4 = 0;
      TRISBbits.TRISB1 = 0;
  }
  else if (IS_QUAD_PWM(outputconfig))
  {
      TRISBbits.TRISB4 = 0;
      TRISBbits.TRISB1 = 0;
      TRISBbits.TRISB2 = 0;
      TRISBbits.TRISB3 = 0;
  }
#endif	
//---------------------------------------------
}

#elif defined (EPWM_V14_5)
void SetOutputEPWM1(unsigned char outputconfig, unsigned char outputmode)
{

  /* set P1M1 and P1M0 */
  	outputconfig |= 0b00111111;
  	outputmode |= 0b11111100;
  	CCP1CON = (CCP1CON | 0b11000000) & outputconfig;
  /* set CCP1M3, CCP1M2, CCP1M1, CCP1M0 */
  CCP1CON = (CCP1CON | 0b00001111) & outputmode;

//--------------------------------------
#if defined(PWM14_5_IO_V1) || defined(PWM14_5_IO_V2)
  if (SINGLE_OUT == outputconfig)
  {
      TRISCbits.TRISC2 = 0;
  }
  else if (IS_DUAL_PWM(outputconfig))
  {
      TRISCbits.TRISC2 = 0;
	  #if defined(PWM14_5_IO_V1)
      TRISDbits.TRISD5 = 0;
	  #elif defined(PWM14_5_IO_V2)
	  TRISBbits.TRISB2 = 0;
	  #endif
  }
  else if (IS_QUAD_PWM(outputconfig))
  {
      TRISCbits.TRISC2 = 0;
	  #if defined(PWM14_5_IO_V1)
      TRISDbits.TRISD5 = 0;
      TRISDbits.TRISD6 = 0;
      TRISDbits.TRISD7 = 0;
	  #elif defined(PWM14_5_IO_V2)
	  TRISBbits.TRISB2 = 0;
      TRISBbits.TRISB1 = 0;
      TRISBbits.TRISB4 = 0;
	  #endif
  }
#endif	
}
//---------------------------------------------

#elif defined (EPWM_V15) || defined (EPWM_V15_1)
void SetOutputEPWM1(unsigned char outputconfig, unsigned char outputmode)
{

  /* set P1M1 and P1M0 */
  	outputconfig |= 0b00111111;
  	outputmode |= 0b11111100;
  	ECCP1CON = (ECCP1CON | 0b11000000) & outputconfig;
  /* set CCP1M3, CCP1M2, CCP1M1, CCP1M0 */
  ECCP1CON = (ECCP1CON | 0b00001111) & outputmode;

//--------------------------------------

  if (SINGLE_OUT == outputconfig)
  {
      TRISCbits.TRISC2 = 0;
  }
  else if (IS_DUAL_PWM(outputconfig))
  {
      TRISCbits.TRISC2 = 0;
      TRISBbits.TRISB2 = 0;
  }
  else if (IS_QUAD_PWM(outputconfig))
  {
      TRISBbits.TRISB4 = 0;
      TRISBbits.TRISB1 = 0;
      TRISCbits.TRISC2 = 0;
      TRISBbits.TRISB2 = 0;
  }
	
//---------------------------------------------


}
#endif
