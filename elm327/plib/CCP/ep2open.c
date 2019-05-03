#include <p18cxxx.h>
#include <capture.h>

#if defined (ECC_V8) || defined (ECC_V8_1) || defined (ECC_V8_3) || defined (ECC_V8_4)
/*******************************************************************************
Function Prototype : void OpenECapture2(unsigned char config)
 
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
				* ECCP_2_SEL_TMR12
				* ECCP_2_SEL_TMR34
				* ECCP_2_SEL_TMR36
				* ECCP_2_SEL_TMR38
				* ECCP_2_SEL_TMR310
				* ECCP_2_SEL_TMR_MASK			 
 
Return Value       : None
 
Remarks            : This function configures the input capture for idle mode, clock select,
                      capture per interrupt and mode select
********************************************************************************/
void OpenECapture2(unsigned char config)
{
  #if defined (ECC_V8_3) || defined (ECC_V8_4)
   CCP2CON = config&0x0F;  // Configure capture
   #else
   ECCP2CON = config&0x0F;  // Configure capture
   #endif
     
  //configure timer source for CCP

  CCPTMRS0 &= 0b11000111;
  CCPTMRS0 |= ((config&0b01110000)>>1);


#if defined(CC4_IO_V2)
  if(config&0x80)
  {
    PIR2bits.CCP2IF = 0;   // Clear the interrupt flag
    PIE2bits.CCP2IE = 1;   // Enable the interrupt

  }
#else  
  if(config&0x80)
  {
    PIR3bits.CCP2IF = 0;   // Clear the interrupt flag
    PIE3bits.CCP2IE = 1;   // Enable the interrupt

  }
#endif  

  CapStatus.ECap2OVF = 0;   // Clear the capture overflow status flag

#ifndef CC4_IO_V2 
  #if defined (ECC_V8_2) || defined (ECC_V8_3)
  RPINR16_17=0x07;
  CP2_TRIS = 1;
  #else
  CP2_TRIS = 1;	
  #endif
#endif
  
}

#elif defined (ECC_V9)|| defined (ECC_V9_1)
/*******************************************************************************
Function Prototype : void OpenECapture2(unsigned char config)
 
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
				* ECCP_2_SEL_TMR12
				* ECCP_2_SEL_TMR34
				* ECCP_2_SEL_TMR36
				* ECCP_2_SEL_TMR38
				* ECCP_2_SEL_TMR310
				* ECCP_2_SEL_TMR_MASK			 
 
Return Value       : None
 
Remarks            : This function configures the input capture for idle mode, clock select,
                      capture per interrupt and mode select
********************************************************************************/
void OpenECapture2(unsigned char config)
{
#ifndef _OMNI_CODE_
  unsigned char TBLPTR_U, TBLPTR_L;

_asm
movff TBLPTRU, TBLPTR_U
movff TBLPTRL, TBLPTR_L
_endasm
#endif

  if (((*(unsigned char far rom *)0x300005) & 0b00000001))

	TRISCbits.TRISC1 = 1;	
  else if (((*(unsigned char far rom *)0x300005) & 0b00000100))

	TRISBbits.TRISB3 = 1;	

	
  CCP2CON = config&0x0F;  // Configure capture
  
  //configure timer source for CCP

  CCPTMRS0 &= 0b11100111;
  CCPTMRS0 |= ((config&0b00110000)>>1);



  if(config&0x80)
  {
    PIR2bits.CCP2IF = 0;   // Clear the interrupt flag
    PIE2bits.CCP2IE = 1;   // Enable the interrupt

  }


  CapStatus.ECap2OVF = 0;   // Clear the capture overflow status flag



#ifndef _OMNI_CODE_
_asm
movff TBLPTR_U, TBLPTRU
movff TBLPTR_L, TBLPTRL
_endasm
#endif
  
}
#endif
