#include <p18cxxx.h>
#include <compare.h>


/********************************************************************
*    Function Name:  OpenCompare5                                   *
*    Return Value:   void                                           *
*    Parameters:     config: bit definitions to configure compare   *
*	 				 period: time period for the compare(match)		*	
*    Description:    This routine configures the compare for        *
*                    interrupt, output signal and compare period    *
*    Notes:          The bit definitions for config can be found    *
*                    in the compare.h file.                         *
********************************************************************/

#if defined (CC_V4)

void OpenCompare5(unsigned char config,unsigned int period)
{
  	CCPR5L = period;       		// load CA5L 
    CCPR5H = (period >> 8);   	// load CA5H
	 
	CCP5CON = config&0x0F; 	// Configure capture
 
  if(config&0x80)
  {
    PIR3bits.CCP5IF = 0;  	// Clear the interrupt flag
    PIE3bits.CCP5IE = 1;  	// Enable the interrupt
  }
if((CCP5CON & 0x0f) != 0x0a)
	TRISGbits.TRISG4 = 0;

}

#elif defined (CC_V8) || defined (CC_V8_1) || defined (CC_V8_2)\
	|| defined (CC_V8_3) || defined (CC_V8_4) || defined (CC_V9)|| defined (CC_V9_1)
void OpenCompare5(unsigned char config,unsigned int period)
{
  	CCPR5L = period;       		// load CAxL 
    CCPR5H = (period >> 8);   	// load CAxH
	 
	CCP5CON = config&0x0F; 	// Configure capture

#if defined (CC_V8) || defined (CC_V8_1) || defined (CC_V8_3) || defined (CC_V8_4)
  //configure timer source for CCP
  CCPTMRS1 &= 0b11111011;
  CCPTMRS1 |= ((config&0b00010000)>>2); 
#elif  defined (CC_V9)|| defined (CC_V9_1)
  //configure timer source for CCP
  CCPTMRS1 &= 0b11110011;
  CCPTMRS1 |= ((config&0b00110000)>>2);   
#elif defined (CC_V8_2)
  //configure timer source for CCP
  CCPTMRS &= 0b11101111;
  CCPTMRS |= ((config&0b00010000)); 
#endif
  
  if(config&0x80)
  {
    PIR4bits.CCP5IF = 0;  	// Clear the interrupt flag
    PIE4bits.CCP5IE = 1;  	// Enable the interrupt
  }
if((CCP5CON & 0x0f) != 0x0a)
	#if defined (CC_V8_3) || defined (CC_V8_4)
	RPINR32_33=0x0B;
	CM5_TRIS = 1;
	#else
	CM5_TRIS = 1;
	#endif

}
#endif

