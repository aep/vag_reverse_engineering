#include <p18cxxx.h>
#include <capture.h>

#if defined (CC_V8) || defined (CC_V8_1) || defined (CC_V8_3) || defined (CC_V8_4)
/*******************************************************************************
Function Prototype : void OpenCapture6(unsigned char config)
 
Include            : capture.h
 
Description        : This function configures the Input Capture module.
 
Arguments          : config - This contains the parameters to be configured in the
                              CCPxCON register as defined below
				Enable CCP Interrupts:
				    * CAPTURE_INT_ON        
				    * CAPTURE_INT_OFF  
				    * CAPTURE_INT_MASK
				Capture configuration
				     * CAP_EVERY_FALL_EDGE
				     * CAP_EVERY_RISE_EDGE 
				     * CAP_EVERY_4_RISE_EDGE  
				     * CAP_EVERY_16_RISE_EDGE
				     * CAP_MODE_MASK					
 
Return Value       : None
 
Remarks            : This function configures the input capture for idle mode, clock select,
                      capture per interrupt and mode select
********************************************************************************/
void OpenCapture6(unsigned char config)
{
  CCP6CON = config&0x0F; // Configure capture

  //configure timer source for CCP
  CCPTMRS1 &= 0b11101111;
  CCPTMRS1 |= (config&0b00010000);  
  
  if(config&0x80)
  {
    PIR4bits.CCP6IF = 0;  // Clear the interrupt flag
    PIE4bits.CCP6IE = 1;  // Enable the interrupt
  }

  	CapStatus.Cap6OVF = 0;  // Clear the capture overflow status flag
	
	#if defined (CC_V8_3) || defined (CC_V8_4)
	RPINR34_35=0x08;
	CP6_TRIS = 1;
	#else
	CP6_TRIS = 1;
	#endif
}
#endif
