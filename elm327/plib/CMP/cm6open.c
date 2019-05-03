#include <p18cxxx.h>
#include <compare.h>


/********************************************************************
*    Function Name:  OpenCompare6                                   *
*    Return Value:   void                                           *
*    Parameters:     config: bit definitions to configure compare   *
*	 				 period: time period for the compare(match)		*	
*    Description:    This routine configures the compare for        *
*                    interrupt, output signal and compare period    *
*    Notes:          The bit definitions for config can be found    *
*                    in the compare.h file.                         *
********************************************************************/
#if defined (CC_V8) || defined (CC_V8_1) || defined (CC_V8_3) || defined (CC_V8_4)
void OpenCompare6(unsigned char config,unsigned int period)
{
  	CCPR6L = period;       		// load CAxL 
    CCPR6H = (period >> 8);   	// load CAxH
	 
	CCP6CON = config&0x0F; 	// Configure capture

  //configure timer source for CCP
  CCPTMRS1 &= 0b11101111;
  CCPTMRS1 |= (config&0b00010000); 
	
  if(config&0x80)
  {
    PIR4bits.CCP6IF = 0;  	// Clear the interrupt flag
    PIE4bits.CCP6IE = 1;  	// Enable the interrupt
  }
if((CCP6CON & 0x0f) != 0x0a)
	#if defined (CC_V8_3) || defined (CC_V8_4)
	RPINR34_35=0x08;
	CM6_TRIS = 1;
	#else
	CM6_TRIS = 1;
	#endif

}
#endif

