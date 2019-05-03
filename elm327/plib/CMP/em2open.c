#include <p18cxxx.h>
#include <compare.h>

/********************************************************************
*    Function Name:  OpenECompare2                                  *
*    Return Value:   void                                           *
*    Parameters:     config: bit definitions to configure compare   *
*	 				 period: time period for the compare(match)		*	
*    Description:    This routine configures the compare for        *
*                    interrupt, output signal and compare period    *
*    Notes:          The bit definitions for config can be found    *
*                    in the compare.h file.  
********************************************************************/
#if defined (ECC_V8) || defined (ECC_V8_1) || defined (ECC_V8_2) || defined (ECC_V8_3) || defined (ECC_V8_4)

void OpenECompare2(unsigned char config,unsigned int period)
{
	CCPR2L = period;       	// load ECAxL 
  	CCPR2H = (period >> 8);    // load ECAxH
  
   #if defined (ECC_V8_3) || defined (ECC_V8_4)
   CCP2CON = config&0x0F;  // Configure capture
   #else
	ECCP2CON = config&0x0F;  // Configure capture
   #endif

  #if defined (ECC_V8_2) 
  //configure timer source for CCP
  CCPTMRS &= 0b11000111;
  CCPTMRS |= ((config&0b01110000)>>1);
  #else
  //configure timer source for CCP
  CCPTMRS0 &= 0b11000111;
  CCPTMRS0 |= ((config&0b01110000)>>1);
  #endif

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

#ifndef CC4_IO_V2 
 #if defined (ECC_V8_3) || defined (ECC_V8_4)
  if((CCP2CON & 0x0f) != 0x0a)
  #else 
if((ECCP2CON & 0x0f) != 0x0a)
  #endif
  
  #if defined (ECC_V8_3)
  RPINR16_17=0x07;
  CM2_TRIS = 1;
  #else	
	CM2_TRIS = 0;	
#endif	
#endif	

}
#elif defined (ECC_V9)|| defined (ECC_V9_1)

void OpenECompare2(unsigned char config,unsigned int period)
{
#ifndef _OMNI_CODE_
  unsigned char TBLPTR_U, TBLPTR_L;

_asm
movff TBLPTRU, TBLPTR_U
movff TBLPTRL, TBLPTR_L
_endasm
#endif

  if (((*(unsigned char far rom *)0x300005) & 0b00000001))
     if((ECCP2CON & 0x0f) != 0x0a)
	TRISCbits.TRISC1 = 0;	
  else if (((*(unsigned char far rom *)0x300005) & 0b00000100))
    if((ECCP2CON & 0x0f) != 0x0a)
	TRISBbits.TRISB3 = 0;	
	 
	CCPR2L = period;       	// load ECAxL 
  	CCPR2H = (period >> 8);    // load ECAxH
  
	ECCP2CON = config&0x0F;  // Configure capture
 
  CCPTMRS0 &= 0b11100111;
  CCPTMRS0 |= ((config&0b00110000)>>1);

	

  if(config&0x80)
  {
    PIR2bits.CCP2IF = 0;   // Clear the interrupt flag
    PIE2bits.CCP2IE = 1;   // Enable the interrupt

  }

#ifndef _OMNI_CODE_  
_asm
movff TBLPTR_U, TBLPTRU
movff TBLPTR_L, TBLPTRL
_endasm
#endif

}


#endif


