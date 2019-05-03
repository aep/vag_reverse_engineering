#include <p18cxxx.h>
#include <capture.h>

#if defined (CC_V3) || defined (CC_V4)
/*******************************************************************************
Function Prototype : void OpenCapture3(unsigned char config)
 
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
void OpenCapture3(unsigned char config)
{
  CCP3CON = config&0x0F; //  Configure capture

 
  if(config&0x80)
  {
    PIR3bits.CCP3IF = 0;  // Clear the interrupt flag
    PIE3bits.CCP3IE = 1;  // Enable the interrupt
  }

  CapStatus.Cap3OVF = 0;  // Clear the capture overflow status flag
 
  CP3_TRIS = 1;		//TRIS direction as input  
}

#elif defined (CC_V8_2)
void OpenCapture3(unsigned char config)
{
  CCP3CON = config&0x0F; //  Configure capture

  //configure timer source for CCP
  CCPTMRS &= 0b11111011;
  CCPTMRS |= ((config&0b00010000)>>2); 
  
  if(config&0x80)
  {
    PIR4bits.CCP3IF = 0;  // Clear the interrupt flag
    PIE4bits.CCP3IE = 1;  // Enable the interrupt
  }

  CapStatus.Cap3OVF = 0;  // Clear the capture overflow status flag
 
  CP3_TRIS = 1;		//TRIS direction as input  
}
#endif
