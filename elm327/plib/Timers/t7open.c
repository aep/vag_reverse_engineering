#include <p18cxxx.h>
#include <timers.h>

/********************************************************************
*    Function Name:  OpenTimer7                                     *
*    Return Value:   void                                           *
*    Parameters:     config: bit definitions to configure Timer7    *
*    Description:    This routine first resets the Timer7 regs      *
*                    to the POR state and then configures the       *
*                    interrupt, clock source and 8/16-bit mode.     *
*    Notes:          The bit definitions for config can be found    *
*                    in the timers.h file.                          *
********************************************************************/
#if defined (TMR_V7)
	 
void OpenTimer7(unsigned char config, unsigned char config1)
{
  T7GCON = (0XF3 & config1);
  
  T7CON = (0x7F & config) << 1 ;    
    	
  TMR7H=0;             // Clear out timer registers
  TMR7L=0;
  
  PIR5bits.TMR7IF=0;
  PIR5bits.TMR7GIF=0;

  if(config&0x80)      // Enable interrupts if selected
    PIE5bits.TMR7IE=1;
  else
    PIE5bits.TMR7IE=0;
 
  if(config1 & 0x04)
    PIE5bits.TMR7GIE=1;
  else
    PIE5bits.TMR7GIE=0;
 
  if(T7GCONbits.TMR7GE)	
      T7GCONbits.T7GGO = 1;
  
  T7CONbits.TMR7ON = 1;  // Start Timer7
  
}
#endif 
	
	

