#include <p18cxxx.h>
#include <compare.h>

/********************************************************************
*    Function Name:  OpenECompare3                                  *
*    Return Value:   void                                           *
*    Parameters:     config: bit definitions to configure compare   *
*	 				 period: time period for the compare(match)		*	
*    Description:    This routine configures the compare for        *
*                    interrupt, output signal and compare period    *
*    Notes:          The bit definitions for config can be found    *
*                    in the compare.h file.  
********************************************************************/
#if defined (ECC_V8) || defined (ECC_V8_1) || defined (ECC_V8_3) || defined (ECC_V8_4)

void OpenECompare3(unsigned char config,unsigned int period)
{
	CCPR3L = period;       	// load ECAxL 
  	CCPR3H = (period >> 8);    // load ECAxH
  
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
  
#ifndef CC4_IO_V2    
if((CCP3CON & 0x0f) != 0x0a)
  #if defined (ECC_V8_3) || defined (ECC_V8_4)
  RPINR16_17=0x0B;
  CM3_TRIS = 1;
  #else
	CM3_TRIS = 0;	
#endif	
#endif	

}
#endif

#if  defined (ECC_V9)|| defined (ECC_V9_1)

void OpenECompare3(unsigned char config,unsigned int period)
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
	TRISBbits.TRISB5 = 0;	
  else if (((*(unsigned char far rom *)0x300005) & 0b00000100))
    if((ECCP2CON & 0x0f) != 0x0a)
	#if defined (ECC_V9)
	TRISEbits.TRISE0 = 0;
	#else
	TRISCbits.TRISC6 = 0;
	#endif
	
	CCPR3L = period;       	// load ECAxL 
  	CCPR3H = (period >> 8);    // load ECAxH
  
	CCP3CON = config&0x0F;  // Configure capture

  //configure timer source for CCP
  CCPTMRS0 &= 0b00111111;
  CCPTMRS0 |= ((config&0b00110000)<<2); 
	
  if(config&0x80)
  {
    PIR4bits.CCP3IF = 0;   // Clear the interrupt flag
    PIE4bits.CCP3IE = 1;   // Enable the interrupt
  }
 
#ifndef _OMNI_CODE_ 
_asm
movff TBLPTR_U, TBLPTRU
movff TBLPTR_L, TBLPTRL
_endasm
#endif
 
}
#endif


