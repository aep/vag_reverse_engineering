#include <p18cxxx.h>
#include <timers.h>

/********************************************************************
*    Function Name:  OpenTimer4                                     *
*    Return Value:   void                                           *
*    Parameters:     config: bit definitions to configure Timer4    *
*    Description:    This routine first resets the Timer4 regs      *
*                    to the POR state and then configures the       *
*                    interrupt and clock source.                    *
*    Notes:          The bit definitions for config can be found    *
*                    in the timers.h file.                          *
********************************************************************/
#if defined (TMR_V4)  || defined (TMR_V6)

void OpenTimer4(unsigned char config)
{
  T4CON = (0xfb & config);  // Set all configuration values, but
                            // don't start timer yet					

  TMR4 = 0;                 // Clear Timer4
  PIR3bits.TMR4IF = 0;


  if(config & 0x80)         // Enable timer interrupts?
    PIE3bits.TMR4IE = 1;
  else
    PIE3bits.TMR4IE = 0;
	
  T4CONbits.TMR4ON = 1; // Turn on Timer4
}
#endif

#if defined (TMR_V7) || defined (TMR_V7_1) || defined (TMR_V7_2)\
 || defined (TMR_V7_3) || defined (TMR_V7_4)

void OpenTimer4(unsigned char config)
{
  T4CON = (0xfb & config);  // Set all configuration values, but
                            // don't start timer yet					

  TMR4 = 0;                 // Clear Timer4
  
#if defined(TMR_INT_V2) || defined (TMR_V7_1_INT_V1)
	PIR3bits.TMR4IF = 0;
#elif defined(TMR_V7_2)
	PIR4bits.TMR4IF = 0;	
#else  
  PIR5bits.TMR4IF = 0;
#endif  
  
#if defined(TMR_INT_V2) || defined (TMR_V7_1_INT_V1)
  if(config & 0x80)         // Enable timer interrupts?
    PIE3bits.TMR4IE = 1;
  else
    PIE3bits.TMR4IE = 0;
#elif defined(TMR_V7_2)
  if(config & 0x80)         // Enable timer interrupts?
    PIE4bits.TMR4IE = 1;
  else
    PIE4bits.TMR4IE = 0;	
#else  
  if(config & 0x80)         // Enable timer interrupts?
    PIE5bits.TMR4IE = 1;
  else
    PIE5bits.TMR4IE = 0;
#endif  	

	
  T4CONbits.TMR4ON = 1; // Turn on Timer4
}
#endif

