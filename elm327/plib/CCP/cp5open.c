#include <p18cxxx.h>
#include <capture.h>

#if defined (CC_V4)

/*******************************************************************************
Function Prototype : void OpenCapture5(unsigned char config)
 
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
void OpenCapture5(unsigned char config)
{
  CCP5CON = config&0x0F; // Configure capture
 
  if(config&0x80)
  {
    PIR3bits.CCP5IF = 0;  // Clear the interrupt flag
    PIE3bits.CCP5IE = 1;  // Enable the interrupt
  }

  	CapStatus.Cap5OVF = 0;  // Clear the capture overflow status flag
	
	TRISGbits.TRISG4 = 1;
}

#elif defined (CC_V8) || defined (CC_V8_1)  || defined (CC_V8_2) || defined (CC_V8_3) ||\
	  defined (CC_V8_4) || defined (CC_V9)|| defined (CC_V9_1)
/*******************************************************************************
Function Prototype : void OpenCapture5(unsigned char config)
 
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
void OpenCapture5(unsigned char config)
{
  CCP5CON = config&0x0F; // Configure capture

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
    PIR4bits.CCP5IF = 0;  // Clear the interrupt flag
    PIE4bits.CCP5IE = 1;  // Enable the interrupt
  }

  	CapStatus.Cap5OVF = 0;  // Clear the capture overflow status flag
	
	#if defined (CC_V8_3) || defined (CC_V8_4)
	RPINR32_33=0x0B;
	CP5_TRIS = 1;
	#else
	CP5_TRIS = 1;
	#endif
}
#endif
