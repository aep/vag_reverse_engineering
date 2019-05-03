#include <p18cxxx.h>
#include <capture.h>

#if defined (ECC_V5)
/*******************************************************************************
Function Prototype : void OpenECapture1(unsigned char config)
 
Include            : capture.h
 
Description        : This function configures the Input Capture module.
 
Arguments          : config - This contains the parameters to be configured in the
                              ECCPxCON register as defined below
				Enable ECCP Interrupts:
				    * ECAPTURE_INT_ON        
				    * CAPTURE_INT_OFF  
				    * CAPTURE_INT_MASK
				Capture configuration
				     * ECAP_EVERY_FALL_EDGE
				     * ECAP_EVERY_RISE_EDGE 
				     * ECAP_EVERY_4_RISE_EDGE  
				     * ECAP_EVERY_16_RISE_EDGE
				     * ECAP_MODE_MASK	
				configre CCP timer source
				 * ECCP_1_SEL_TMR12
				* ECCP_1_SEL_TMR34
				* ECCP_1_SEL_TMR36
				* ECCP_1_SEL_TMR38
				* ECCP_1_SEL_TMR310
				* ECCP_1_SEL_TMR312
				* ECCP_1_SEL_TMR_MASK						 
 
Return Value       : None
 
Remarks            : This function configures the input capture for idle mode, clock select,
                      capture per interrupt and mode select
********************************************************************************/
void OpenECapture1(unsigned char config)
{
  ECCP1CON = config&0x0F;  // Configure capture
  #if defined ECCP1_IO_V5
  if(config&0x80)
  {
    PIR1bits.CCP1IF = 0;   // Clear the interrupt flag
    PIE1bits.CCP1IE = 1;   // Enable the interrupt

  }
  TRISBbits.TRISB4 = 1;	
  #else 
  if(config&0x80)
  {
    PIR2bits.ECCP1IF = 0;   // Clear the interrupt flag
    PIE2bits.ECCP1IE = 1;   // Enable the interrupt

  }
  TRISDbits.TRISD4 = 1;	
  #endif
  CapStatus.ECap1OVF = 0;   // Clear the capture overflow status flag
		
}

#endif

#if defined (ECC_V8) || defined (ECC_V8_1) || defined (ECC_V8_2) || defined (ECC_V8_3) \
	|| defined (ECC_V8_4) || defined (ECC_V8_5) || defined (ECC_V9)|| defined (ECC_V9_1)

void OpenECapture1(unsigned char config)
{
  #if defined (ECC_V8_3) || defined (ECC_V8_4) || defined (ECC_V8_5)
   CCP1CON = config&0x0F;  // Configure capture
   #else
   ECCP1CON = config&0x0F;  // Configure capture
   #endif
   
 
#if defined (ECC_V8) || defined (ECC_V8_1) || defined (ECC_V8_3)
  //configure timer source for CCP
  CCPTMRS0 &= 0b11111000;
  CCPTMRS0 |= ((config&0b01110000)>>4); 
#elif defined (ECC_V9)|| defined (ECC_V9_1)  
  CCPTMRS0 &= 0b11111100;
  CCPTMRS0 |= ((config&0b00110000)>>4);  
#elif defined (ECC_V8_2) || defined (ECC_V8_5)
  //configure timer source for CCP
  CCPTMRS &= 0b11111110;
  CCPTMRS |= ((config&0b00010000)>>4); 
#endif

#if defined(CC4_IO_V2) || defined (CC9_IO_V1)
  if(config&0x80)
  {
    PIR1bits.CCP1IF = 0;   // Clear the interrupt flag
    PIE1bits.CCP1IE = 1;   // Enable the interrupt

  }
#else  
  if(config&0x80)
  {
    PIR3bits.CCP1IF = 0;   // Clear the interrupt flag
    PIE3bits.CCP1IE = 1;   // Enable the interrupt

  }
#endif
  
  CapStatus.ECap1OVF = 0;   // Clear the capture overflow status flag
	
#ifndef CC4_IO_V2  
  #if defined (ECC_V8_3)
  RPINR14_15=0x02;
  CP1_TRIS = 1;
  #else
  CP1_TRIS = 1;	
  #endif
#endif	
}
#endif
