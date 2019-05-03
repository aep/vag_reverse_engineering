#include <p18cxxx.h>
#include <compare.h>


/********************************************************************
*    Function Name:  OpenCompare10                                   *
*    Return Value:   void                                           *
*    Parameters:     config: bit definitions to configure compare   *
*	 				 period: time period for the compare(match)		*	
*    Description:    This routine configures the compare for        *
*                    interrupt, output signal and compare period    *
*    Notes:          The bit definitions for config can be found    *
*                    in the compare.h file.                         *
********************************************************************/
#if defined (CC_V8) || defined (CC_V8_3) 
void OpenCompare10(unsigned char config,unsigned int period)
{
  	CCPR10L = period;       		// load CAxL 
    CCPR10H = (period >> 8);   	// load CAxH
	 
	CCP10CON = config&0x0F; 	// Configure capture

  //configure timer source for CCP
  CCPTMRS2 &= 0b11101111;
  CCPTMRS2 |= (config&0b00010000);  
	
  if(config&0x80)
  {
    PIR4bits.CCP10IF = 0;  	// Clear the interrupt flag
    PIE4bits.CCP10IE = 1;  	// Enable the interrupt
  }
if((CCP10CON & 0x0f) != 0x0a)
	#if defined (CC_V8_3) || defined (CC_V8_4)
	RPINR38_39=0x07;
	CM10_TRIS = 1;
	#else
	CM10_TRIS = 1;
	#endif

}
#endif

