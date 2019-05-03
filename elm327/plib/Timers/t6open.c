#include <p18cxxx.h>
#include <timers.h>

/********************************************************************
*    Function Name:  OpenTimer6                                     *
*    Return Value:   void                                           *
*    Parameters:     config: bit definitions to configure Timer6    *
*    Description:    This routine first resets the Timer6 regs      *
*                    to the POR state and then configures the       *
*                    interrupt and clock source.                    *
*    Notes:          The bit definitions for config can be found    *
*                    in the timers.h file.                          *
********************************************************************/

#if defined (TMR_V7) || defined (TMR_V7_1) || defined (TMR_V7_3) || defined (TMR_V7_4)

void OpenTimer6(unsigned char config)
{
  T6CON = (0xfb & config);  // Set all configuration values, but
                            // don't start timer yet					

  TMR6 = 0;                 // Clear Timer6
  PIR5bits.TMR6IF = 0;

  if(config & 0x80)         // Enable timer interrupts?
    PIE5bits.TMR6IE = 1;
  else
    PIE5bits.TMR6IE = 0;

  T6CONbits.TMR6ON = 1; // Turn on Timer6
}
#endif
