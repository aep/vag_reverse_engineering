#include <p18cxxx.h>
#include <compare.h>

/********************************************************************
*    Function Name:  OpenCompare4                                   *
*    Return Value:   void                                           *
*    Parameters:     config: bit definitions to configure compare   *
*	 				 period: time period for the compare(match)		*	
*    Description:    This routine configures the compare for        *
*                    interrupt, output signal and compare period    *
*    Notes:          The bit definitions for config can be found    *
*                    in the compare.h file.                         *
********************************************************************/

#if defined (CC_V4)

void OpenCompare4(unsigned char config,unsigned int period)
{
	CCPR4L = period;       		// load CA4L 
    CCPR4H = (period >> 8);   	// load CA4H
 
 	CCP4CON = config&0x0F; //  Configure capture
 
  if(config&0x80)
  {
    PIR3bits.CCP4IF = 0;  // Clear the interrupt flag
    PIE3bits.CCP4IE = 1;  // Enable the interrupt
  }
  if((CCP4CON & 0x0f) != 0x0a)
    CM4_TRIS = 0;

}

#elif defined (CC_V8) || defined (CC_V8_1) || defined (CC_V8_2)\
	|| defined (CC_V8_3) || defined (CC_V8_4) || defined (CC_V9)\
	|| defined (CC_V9_1)

void OpenCompare4(unsigned char config,unsigned int period)
{
	CCPR4L = period;       		// load CAxL 
    CCPR4H = (period >> 8);   	// load CAxH
 
 	CCP4CON = config&0x0F; //  Configure capture


#if defined (CC_V8) || defined (CC_V8_1) || defined (CC_V8_3) || defined (CC_V8_4)
  //configure timer source for CCP
  CCPTMRS1 &= 0b11111100;
  CCPTMRS1 |= ((config&0b00110000)>>4); 
#elif defined (CC_V9)|| defined (CC_V9_1)  
   //configure timer source for CCP
  CCPTMRS1 &= 0b11111100;
  CCPTMRS1 |= ((config&0b00110000)>>4);   
#elif defined (CC_V8_2)
  //configure timer source for CCP
  CCPTMRS &= 0b11101111;
  CCPTMRS |= ((config&0b00010000)>>1); 
#endif	
  if(config&0x80)
  {
    PIR4bits.CCP4IF = 0;  // Clear the interrupt flag
    PIE4bits.CCP4IE = 1;  // Enable the interrupt
  }
  if((CCP4CON & 0x0f) != 0x0a)
  #if defined (CC_V8_3) || defined (CC_V8_4)
  RPINR32_33=0x0B;
  CM4_TRIS = 1;		//TRIS direction as input
  #else
  CM4_TRIS = 1;		//TRIS direction as input
  #endif

}
#endif

