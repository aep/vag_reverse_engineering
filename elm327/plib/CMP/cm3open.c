#include <p18cxxx.h>
#include <compare.h>

/********************************************************************
*    Function Name:  OpenCompare3                                   *
*    Return Value:   void                                           *
*    Parameters:     config: bit definitions to configure compare   *
*	 				 period: time period for the compare(match)		*	
*    Description:    This routine configures the compare for        *
*                    interrupt, output signal and compare period    *
*    Notes:          The bit definitions for config can be found    *
*                    in the compare.h file.                         *
********************************************************************/

#if defined (CC_V3 ) || defined ( CC_V4)

void OpenCompare3(unsigned char config,unsigned int period)
{
  	CCPR3L = period;       		// load CA3L 
    CCPR3H = (period >> 8);   	// load CA3H
 
    CCP3CON = config&0x0F; //  Configure capture
	
  if(config&0x80)
  {
    PIR3bits.CCP3IF = 0;  // Clear the interrupt flag
    PIE3bits.CCP3IE = 1;  // Enable the interrupt
  }
  if((CCP3CON & 0x0f) !=0x0a)
    CM3_TRIS = 0;
}

#elif defined (CC_V8_2)

void OpenCompare3(unsigned char config,unsigned int period)
{
  	CCPR3L = period;       		// load CA3L 
    CCPR3H = (period >> 8);   	// load CA3H
 
    CCP3CON = config&0x0F; //  Configure capture
  //configure timer source for CCP
  CCPTMRS &= 0b11101111;
  CCPTMRS |= ((config&0b00010000)>>2); 
  
  if(config&0x80)
  {
    PIR4bits.CCP3IF = 0;  // Clear the interrupt flag
    PIE4bits.CCP3IE = 1;  // Enable the interrupt
  }
  if((CCP3CON & 0x0f) !=0x0a)
    CM3_TRIS = 0;
}

#endif



