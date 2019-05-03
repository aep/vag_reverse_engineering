#include <p18cxxx.h>
#include <capture.h>

#if defined (CC_V1) || defined (CC_V2) || defined (CC_V3) ||\
    defined (CC_V4) || defined (CC_V5)
/*******************************************************************************
Function Prototype : void OpenCapture1(unsigned char config)
 
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
void OpenCapture1(unsigned char config)
{
  CCP1CON = config & 0x0F;  // Configure capture
  if(config&0x80)
  {
    PIR1bits.CCP1IF = 0;   // Clear the interrupt flag
    PIE1bits.CCP1IE = 1;   // Enable the interrupt

  }
 CP1_TRIS = 1;		//TRIS direction as input
}

#elif defined (CC_V6)
/*******************************************************************************
Function Prototype : void OpenCapture1(unsigned char config)
 
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
void OpenCapture1(unsigned char config)
{
  CCP1CON = config & 0x0F;  // Configure capture
  if(config&0x80)
  {
    PIR3bits.CCP1IF = 0;   // Clear the interrupt flag
    PIE3bits.CCP1IE = 1;   // Enable the interrupt
  } 
 CP1_TRIS = 1;		//TRIS direction as input	
}

#elif defined (CC_V7)
/*******************************************************************************
Function Prototype : void OpenCapture1(unsigned char config)
 
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
void OpenCapture1(unsigned char config)
{
  CCP1CON = config & 0x0F;  // Configure capture
  if(config&0x80)
  {
    PIR1bits.CCP1IF = 0;   // Clear the interrupt flag
    PIE1bits.CCP1IE = 1;   // Enable the interrupt
  }
}

#endif
