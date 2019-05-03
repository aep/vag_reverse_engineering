#include <p18cxxx.h>
#include <timers.h>

/********************************************************************
*    Function Name:  OpenTimer10                                *
*    Return Value:   void                                           *
*    Parameters:     config: bit definitions to configure Timer10    *
*    Description:    This routine first resets the Timer10 regs      *
*                    to the POR state and then configures the       *
*                    interrupt and clock source.                    *
*    Notes:          The bit definitions for config can be found    *
*                    in the timers.h file.                          *
********************************************************************/
#if defined (TMR_V7)

void OpenTimer10(unsigned char config)
{
  T10CON = (0xfb & config);  // Set all configuration values, but
                            // don't start timer yet					

  TMR10 = 0;                 // Clear Timer10
  PIR5bits.TMR10IF = 0;

  if(config & 0x80)         // Enable timer interrupts?
    PIE5bits.TMR10IE = 1;
  else
    PIE5bits.TMR10IE = 0;

  T10CONbits.TMR10ON = 1; // Turn on Timer10
}
#endif
