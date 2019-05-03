#include <p18cxxx.h>
#include <timers.h>

/********************************************************************
*    Function Name:  OpenTimer8                                *
*    Return Value:   void                                           *
*    Parameters:     config: bit definitions to configure Timer8    *
*    Description:    This routine first resets the Timer8 regs      *
*                    to the POR state and then configures the       *
*                    interrupt and clock source.                    *
*    Notes:          The bit definitions for config can be found    *
*                    in the timers.h file.                          *
********************************************************************/
#if defined (TMR_V7) || defined (TMR_V7_1) || defined (TMR_V7_4)

void OpenTimer8(unsigned char config)
{
  T8CON = (0xfb & config);  // Set all configuration values, but
                            // don't start timer yet					

  TMR8 = 0;                 // Clear Timer8
  PIR5bits.TMR8IF = 0;

  if(config & 0x80)         // Enable timer interrupts?
    PIE5bits.TMR8IE = 1;
  else
    PIE5bits.TMR8IE = 0;

  T8CONbits.TMR8ON = 1; // Turn on Timer8
}
#endif
