#include <p18cxxx.h>
#include <timers.h>

/********************************************************************
*    Function Name:  OpenTimer3                                     *
*    Return Value:   void                                           *
*    Parameters:     config: bit definitions to configure Timer3    *
*    Description:    This routine first resets the Timer3 regs      *
*                    to the POR state and then configures the       *
*                    interrupt, clock source.                       *
*    Notes:          The bit definitions for config can be found    *
*                    in the timers.h file.                          *
*                                                                   *
*                    The MPLAB CXX Reference Guide says that        *
*                    OpenTimer1(config) can select Timer 1 as the   *
*                    source for the CCPs.  However, this function   *
*                    does not write the necessary values to bits 6  *
*                    and 3 of T3CON.  Instead, the function         *
*                    incorrectly affects bit 3 of T1CON.            *
*                                                                   *
*                    Because the power-on default is timer1 source  *
*                    for both CCPs, we do not need to even have     *
*                    these values.  Should a user want to change    *
*                    this value, the user would need select the     *
*                    appropriate value when calling OpenTimer3.     *
*                                                                   *
********************************************************************/
#if defined (TMR_V2) || defined (TMR_V4)
void OpenTimer3(unsigned char config)
{
  T3CON = (0x36 & config);  // Set everything except 8/16 mode and Timer as CCP source
                            // don't start timer yet

  TMR3H=0;          //Clear timer3-related registers
  TMR3L=0;
  PIR2bits.TMR3IF = 0;

  if(config & 0x80)   // Interrupt on/off
    PIE2bits.TMR3IE = 1;
  else
    PIE2bits.TMR3IE = 0;



  if(config & ~T3_8BIT_RW) // Select between 8-bit and 16-bit modes
  {
    T3CONbits.RD16 = 1;
  }
  else
  {
    T3CONbits.RD16 = 0;
  }

  T3CONbits.TMR3ON = 1;   // Turn on Timer3
}

#endif

#if defined (TMR_V6)
void OpenTimer3(unsigned char config, unsigned char config1)
{
  T3GCON = (0XF3 & config1);

  T3CON = (0x7F & config) << 1;  // Set everything except 8/16 mode, and
                            // don't start timer yet
  if(config&0x04)
    T1CONbits.T1OSCEN=1;

  TMR3H=0;          //Clear timer3-related registers
  TMR3L=0;
  PIR2bits.TMR3IF = 0;
  PIR3bits.TMR3GIF =0;

  if(config & 0x80)   // Interrupt on/off
    PIE2bits.TMR3IE = 1;
  else
    PIE2bits.TMR3IE = 0;

  if(config1 & 0x04)
    PIE3bits.TMR3GIE=1;
  else
    PIE3bits.TMR3GIE=0;

  if(T3GCONbits.TMR3GE)
      T3GCONbits.T3GGO = 1;

  T3CONbits.TMR3ON = 1;   // Turn on Timer3
}

#endif


#if defined (TMR_V7) || defined (TMR_V7_1) || defined (TMR_V7_2) || defined (TMR_V7_3) || defined (TMR_V7_4) || defined (TMR_V7_5)
void OpenTimer3(unsigned char config, unsigned char config1)
{
  T3GCON = (0XF3 & config1);

  T3CON = (0x7F & config) << 1;  // Set everything except 8/16 mode, and
                            // don't start timer yet

  TMR3H=0;          //Clear timer3-related registers
  TMR3L=0;
  PIR2bits.TMR3IF = 0;
  
#if defined(TMR_INT_V2) || defined (TMR_INT_V7_3) || defined (TMR_INT_V7_5) || defined (TMR_V7_1_INT_V1)
	PIR3bits.TMR3GIF =0;
#else  
  PIR2bits.TMR3GIF =0;
#endif  

  if(config & 0x80)   // Interrupt on/off
    PIE2bits.TMR3IE = 1;
  else
    PIE2bits.TMR3IE = 0;

#if defined(TMR_INT_V2) || defined (TMR_INT_V7_3) || defined (TMR_INT_V7_5) || defined (TMR_V7_1_INT_V1)
  if(config1 & 0x04)
    PIE3bits.TMR3GIE=1;
  else
    PIE3bits.TMR3GIE=0;
#else  
  if(config1 & 0x04)
    PIE2bits.TMR3GIE=1;
  else
    PIE2bits.TMR3GIE=0;
#endif	


  if(T3GCONbits.TMR3GE)
      T3GCONbits.T3GGO = 1;

  T3CONbits.TMR3ON = 1;   // Turn on Timer3
}

#endif

