#include <p18cxxx.h>
#include <timers.h>

/********************************************************************
*    Function Name:  OpenTimer12                                *
*    Return Value:   void                                           *
*    Parameters:     config: bit definitions to configure Timer12    *
*    Description:    This routine first resets the Timer12 regs      *
*                    to the POR state and then configures the       *
*                    interrupt and clock source.                    *
*    Notes:          The bit definitions for config can be found    *
*                    in the timers.h file.                          *
********************************************************************/
#if defined (TMR_V7)

void OpenTimer12(unsigned char config)
{
  T12CON = (0xfb & config);  // Set all configuration values, but
                            // don't start timer yet					

  TMR12 = 0;                 // Clear Timer12
  PIR5bits.TMR12IF = 0;

  if(config & 0x80)         // Enable timer interrupts?
    PIE5bits.TMR12IE = 1;
  else
    PIE5bits.TMR12IE = 0;

  T12CONbits.TMR12ON = 1; // Turn on Timer12
}
#endif
