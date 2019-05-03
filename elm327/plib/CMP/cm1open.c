#include <p18cxxx.h>
#include <compare.h>

/********************************************************************
*    Function Name:  	OpenCompare1                                 

*    Return Value:   	void                                      

*    Parameters:       	config: bit definitions to configure compare   
*	 		 	period: time period for the compare(match)	
	
*    Description:    		This routine configures the compare for       
*                    		interrupt, output signal and compare period  

*    Notes:          		The bit definitions for config can be found   
*                    		in the compare.h file.                        
********************************************************************/
#if defined (CC_V1) || defined (CC_V2) || defined (CC_V3) || defined (CC_V4) || defined (CC_V5)

void OpenCompare1(unsigned char config,unsigned int period)
{
 	
  CCPR1L = period;       	// load CA1L 
  CCPR1H = (period >> 8);   // load CA1H

   CCP1CON = config & 0x0F;  // Configure compare
   if(config&0x80)
   {
	    PIR1bits.CCP1IF = 0;   // Clear the interrupt flag
	    PIE1bits.CCP1IE = 1;   // Enable the interrupt
   }
	if(((CCP1CON & 0x0f) != 0x0a) && ((CCP1CON & 0x0f) != 0x0b))
	{
		CM1_TRIS = 0;
	}

}

#elif defined (CC_V6)

void OpenCompare1(unsigned char config,unsigned int period)
{
 	
  CCPR1L = period;       	// load CA1L 
  CCPR1H = (period >> 8);   // load CA1H

   CCP1CON = config & 0x0F;  // Configure compare
   if(config&0x80)
   {
	    PIR3bits.CCP1IF = 0;   // Clear the interrupt flag
	    PIE3bits.CCP1IE = 1;   // Enable the interrupt
   }
	if(((CCP1CON & 0x0f) != 0x0a) && ((CCP1CON & 0x0f) != 0x0b))
	{
	  CM1_TRIS = 0;
	}
}

#elif defined (CC_V7)

void OpenCompare1(unsigned char config,unsigned int period)
{
 	
  CCPR1L = period;       	// load CA1L 
  CCPR1H = (period >> 8);   // load CA1H

   CCP1CON = config & 0x0F;  // Configure compare
   if(config&0x80)
   {
    PIR1bits.CCP1IF = 0;   // Clear the interrupt flag
    PIE1bits.CCP1IE = 1;   // Enable the interrupt
   }

}
#endif
