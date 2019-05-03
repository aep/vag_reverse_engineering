#include <p18cxxx.h>
#include <capture.h>

#if defined (ECC_V8) || defined (ECC_V8_1) || defined (ECC_V8_3) || defined (ECC_V8_4)
/*******************************************************************************
Function Prototype : void OpenECapture3(unsigned char config)
 
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
				condfigure CCP timer source				
					 * ECCP_3_SEL_TMR12
					* ECCP_3_SEL_TMR34
					* ECCP_3_SEL_TMR36
					* ECCP_3_SEL_TMR38
					* ECCP_3_SEL_TMR_MASK
Return Value       : None
 
Remarks            : This function configures the input capture for idle mode, clock select,
                      capture per interrupt and mode select
********************************************************************************/
void OpenECapture3(unsigned char config)
{
  CCP3CON = config&0x0F;  // Configure capture
  //configure timer source for CCP
  CCPTMRS0 &= 0b00111111;
  CCPTMRS0 |= ((config&0b00110000)<<2); 
  if(config&0x80)
  {
   #if defined (ECC_V8_3) || defined (ECC_V8_4)
   PIR4bits.ECCP3IF = 0;   // Clear the interrupt flag
   PIE4bits.ECCP3IE = 1;   // Enable the interrupt
   #else
   PIR4bits.CCP3IF = 0;   // Clear the interrupt flag
   PIE4bits.CCP3IE = 1;   // Enable the interrupt
   #endif
  }
  CapStatus.ECap3OVF = 0;   // Clear the capture overflow status flag
	
#ifndef CC4_IO_V2
  #if defined (ECC_V8_3) || defined (ECC_V8_4)
  RPINR16_17=0x0B;
  CP3_TRIS = 1;
  #else
  CP3_TRIS = 1;	
#endif	
#endif

}

#endif

#if defined (ECC_V9)|| defined (ECC_V9_1)
/*******************************************************************************
Function Prototype : void OpenECapture3(unsigned char config)
 
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
				condfigure CCP timer source				
					 * ECCP_3_SEL_TMR12
					* ECCP_3_SEL_TMR34
					* ECCP_3_SEL_TMR36
					* ECCP_3_SEL_TMR38
					* ECCP_3_SEL_TMR_MASK
Return Value       : None
 
Remarks            : This function configures the input capture for idle mode, clock select,
                      capture per interrupt and mode select
********************************************************************************/
void OpenECapture3(unsigned char config)
{
#ifndef _OMNI_CODE_
 unsigned char TBLPTR_U, TBLPTR_L;

_asm
movff TBLPTRU, TBLPTR_U
movff TBLPTRL, TBLPTR_L
_endasm
#endif

  if (((*(unsigned char far rom *)0x300005) & 0b00000001))
	TRISBbits.TRISB5 = 1;	
  else if (((*(unsigned char far rom *)0x300005) & 0b00000100))
	#if defined (ECC_V9)
	TRISEbits.TRISE0 = 1;
	#else
	TRISCbits.TRISC6 = 1;
	#endif
	
  CCP3CON = config&0x0F;  // Configure capture

  //configure timer source for CCP
  CCPTMRS0 &= 0b00111111;
  CCPTMRS0 |= ((config&0b00110000)<<2); 


  if(config&0x80)
  {
    PIR4bits.CCP3IF = 0;   // Clear the interrupt flag
    PIE4bits.CCP3IE = 1;   // Enable the interrupt

  }
  CapStatus.ECap3OVF = 0;   // Clear the capture overflow status flag
	
#ifndef _OMNI_CODE_  
_asm
movff TBLPTR_U, TBLPTRU
movff TBLPTR_L, TBLPTRL
_endasm
#endif

}

#endif
