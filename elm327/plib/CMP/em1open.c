#include <p18cxxx.h>
#include <compare.h>

/********************************************************************
*    Function Name:  OpenECompare1                                  *
*    Return Value:   void                                           *
*    Parameters:     config: bit definitions to configure compare   *
*	 				 period: time period for the compare(match)		*	
*    Description:    This routine configures the compare for        *
*                    interrupt, output signal and compare period    *
*    Notes:          The bit definitions for config can be found    *
*                    in the compare.h file.  
********************************************************************/
#if defined (ECC_V5)

void OpenECompare1(unsigned char config,unsigned int period)
{
	
	ECCP1CON = config&0x0F;  // Configure capture
	#if defined ECCP1_IO_V5
  if(config&0x80)
  {
    PIR1bits.CCP1IF = 0;   // Clear the interrupt flag
    PIE1bits.CCP1IE = 1;   // Enable the interrupt

  }
  if((ECCP1CON & 0x0f) != 0x0a)
	TRISBbits.TRISB4 = 0;	
  #else 
  if(config&0x80)
  {
    PIR2bits.ECCP1IF = 0;   // Clear the interrupt flag
    PIE2bits.ECCP1IE = 1;   // Enable the interrupt
  }
	if((ECCP1CON & 0x0f) != 0x0a)
	TRISDbits.TRISD4 = 0;	
	ECCPR1L = period;       	// load ECA1L 
  	ECCPR1H = (period >> 8);    // load ECA1H
	#endif
 
}

#elif defined (ECC_V8) || defined (ECC_V8_1) || defined (ECC_V8_2) || \
	defined (ECC_V8_3) || defined (ECC_V8_4) || defined (ECC_V8_5) || defined (ECC_V9)|| defined (ECC_V9_1)

void OpenECompare1(unsigned char config,unsigned int period)
{
	CCPR1L = period;       	// load ECA1L 
  	CCPR1H = (period >> 8);    // load ECA1H
  
   #if defined (ECC_V8_3) || defined (ECC_V8_4) || defined (ECC_V8_5)
   CCP1CON = config&0x0F;  // Configure capture
   #else
   ECCP1CON = config&0x0F;  // Configure capture
   #endif


#if defined (ECC_V8) || defined (ECC_V8_1) || defined (ECC_V8_3) || defined (ECC_V8_4)
  //configure timer source for CCP
  CCPTMRS0 &= 0b11111000;
  CCPTMRS0 |= ((config&0b01110000)>>4);
#elif defined (ECC_V9)|| defined (ECC_V9_1)  
  CCPTMRS0 &= 0b11111100;
  CCPTMRS0 |= ((config&0b00110000)>>4);    
#elif defined (ECC_V8_2) || defined (ECC_V8_5)
  //configure timer source for CCP
  CCPTMRS &= 0b11101111;
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

#ifndef CC4_IO_V2  
  #if defined (ECC_V8_3) || defined (ECC_V8_4)
  if((CCP1CON & 0x0f) != 0x0a)
  #else 
  if((ECCP1CON & 0x0f) != 0x0a)
  #endif
  
  #if defined (ECC_V8_3)
  RPINR14_15=0x02;
  CM1_TRIS = 1;
  #else
  CM1_TRIS = 0;	
  #endif
#endif	

 
}


#endif


