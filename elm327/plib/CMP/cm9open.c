#include <p18cxxx.h>
#include <compare.h>


/********************************************************************
*    Function Name:  OpenCompare9                                   *
*    Return Value:   void                                           *
*    Parameters:     config: bit definitions to configure compare   *
*	 				 period: time period for the compare(match)		*	
*    Description:    This routine configures the compare for        *
*                    interrupt, output signal and compare period    *
*    Notes:          The bit definitions for config can be found    *
*                    in the compare.h file.                         *
********************************************************************/
#if defined (CC_V8) || defined (CC_V8_3) 
void OpenCompare9(unsigned char config,unsigned int period)
{
  	CCPR9L = period;       		// load CAxL 
    CCPR9H = (period >> 8);   	// load CAxH
	 
	CCP9CON = config&0x0F; 	// Configure capture

  //configure timer source for CCP
  CCPTMRS2 &= 0b11111011;
  CCPTMRS2 |= ((config&0b00010000)>>2);
	
  if(config&0x80)
  {
    PIR4bits.CCP9IF = 0;  	// Clear the interrupt flag
    PIE4bits.CCP9IE = 1;  	// Enable the interrupt
  }
if((CCP9CON & 0x0f) != 0x0a)
	#if defined (CC_V8_3) || defined (CC_V8_4)
	RPINR36_37=0x08;
	CM9_TRIS = 1;
	#else
	CM9_TRIS = 1;
	#endif

}
#endif

