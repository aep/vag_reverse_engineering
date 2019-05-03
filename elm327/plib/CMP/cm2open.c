#include <p18cxxx.h>
#include <compare.h>


/********************************************************************
*    Function Name:  OpenCompare2                                   *
*    Return Value:   void                                           *
*    Parameters:     config: bit definitions to configure compare   *
*	 				 period: time period for the compare(match)		*	
*    Description:    This routine configures the compare for        *
*                    interrupt, output signal and compare period    *
*    Notes:          The bit definitions for config can be found    *
*                    in the compare.h file.                         *
********************************************************************/

#if defined (CC_V2 ) || defined ( CC_V3 ) || defined ( CC_V4 )

void OpenCompare2(unsigned char config, unsigned int period)
{

#define __CONFIG3L 0x300004
#define __CONFIG3H 0x300005
char pmmode; /* will be set iff either bit 0 AND bit 1 or bit 5 AND bit 4 of __CONFIG3L are set */
char ccp2mx; /* will be set iff bit 0 of __CONFIG3H is set */

  	CCPR2L = period;       	// load CA2L 
    CCPR2H = (period >> 8);   // load CA2H

	CCP2CON = config&0x0F; //  Configure capture

   	if (((*(unsigned char far rom *)__CONFIG3H) & 0b00000001))
    	ccp2mx=0xff;
 	else
     	ccp2mx = 0;

#if defined CC_CONFIG3L_V1
  	if (((*(unsigned char far rom *)__CONFIG3L) & 0b00000011) == 0b00000011)
     	pmmode=0xff;
  	else
     	pmmode = 0;
#elif defined CC_CONFIG3L_V2
	if (((*(unsigned char far rom *)__CONFIG3L) & 0b00110000) == 0b00110000)
     	pmmode=0xff;
  	else
    	pmmode = 0;
#endif

	
  if(config&0x80)
  {
    PIR2bits.CCP2IF = 0;  // Clear the interrupt flag
    PIE2bits.CCP2IE = 1;  // Enable the interrupt
  }
if((CCP2CON & 0x0f) !=0x0a)
{
	#if defined CC2_IO_V0	
		TRISCbits.TRISC1 = 0;
	#elif defined CC2_IO_V1	
		TRISBbits.TRISB3 = 0;
	#elif defined CC2_IO_V2	
		TRISEbits.TRISE7 = 0;
	#elif defined CC2_IO_V3
		if(ccp2mx)	TRISCbits.TRISC1 = 0;
		else TRISBbits.TRISB3 = 0;
	#elif defined CC2_IO_V4
		if(ccp2mx)	TRISCbits.TRISC1 = 0;
		else TRISEbits.TRISE7 = 0;
	#elif defined CC2_IO_V5
		if(ccp2mx)	TRISCbits.TRISC1 = 0;
		else if(pmmode)TRISEbits.TRISE7 = 0;
		else TRISBbits.TRISB3 = 0;
	#endif	
}

}

#elif defined ( CC_V6 )

void OpenCompare2(unsigned char config, unsigned int period)
{

#define __CONFIG3L 0x300004
#define __CONFIG3H 0x300005
char pmmode; /* will be set iff either bit 0 AND bit 1 or bit 5 AND bit 4 of __CONFIG3L are set */
char ccp2mx; /* will be set iff bit 0 of __CONFIG3H is set */

  	CCPR2L = period;       	// load CA2L 
    CCPR2H = (period >> 8);   // load CA2H

	CCP2CON = config&0x0F; //  Configure capture

   	if (((*(unsigned char far rom *)__CONFIG3H) & 0b00000001))
    	ccp2mx=0xff;
 	else
     	ccp2mx = 0;

#if defined CC_CONFIG3L_V1
  	if (((*(unsigned char far rom *)__CONFIG3L) & 0b00000011) == 0b00000011)
     	pmmode=0xff;
  	else
     	pmmode = 0;
#elif defined CC_CONFIG3L_V2
	if (((*(unsigned char far rom *)__CONFIG3L) & 0b00110000) == 0b00110000)
     	pmmode=0xff;
  	else
    	pmmode = 0;
#endif

	
  if(config&0x80)
  {
    PIR3bits.CCP2IF = 0;  // Clear the interrupt flag
    PIE3bits.CCP2IE = 1;  // Enable the interrupt
  }
if((CCP2CON & 0x0f) !=0x0a)
{
	#if defined CC2_IO_V0	
		TRISCbits.TRISC1 = 0;
	#elif defined CC2_IO_V1	
		TRISBbits.TRISB3 = 0;
	#elif defined CC2_IO_V2	
		TRISEbits.TRISE7 = 0;
	#elif defined CC2_IO_V3
		if(ccp2mx)	TRISCbits.TRISC1 = 0;
		else TRISBbits.TRISB3 = 0;
	#elif defined CC2_IO_V4
		if(ccp2mx)	TRISCbits.TRISC1 = 0;
		else TRISEbits.TRISE7 = 0;
	#elif defined CC2_IO_V5
		if(ccp2mx)	TRISCbits.TRISC1 = 0;
		else if(pmmode)TRISEbits.TRISE7 = 0;
		else TRISBbits.TRISB3 = 0;
	#endif	
}

}

#elif defined (CC_V7)

void OpenCompare2(unsigned char config, unsigned int period)
{

  	CCPR2L = period;       	// load CA2L 
    CCPR2H = (period >> 8);   // load CA2H

	CCP2CON = config&0x0F; //  Configure capture
	
  if(config&0x80)
  {
    PIR2bits.CCP2IF = 0;  // Clear the interrupt flag
    PIE2bits.CCP2IE = 1;  // Enable the interrupt
  }

}

#elif defined ( CC_V8_2 )

void OpenCompare2(unsigned char config, unsigned int period)
{

  	CCPR2L = period;       	// load CA2L 
    CCPR2H = (period >> 8);   // load CA2H

	CCP2CON = config&0x0F; //  Configure capture
  //configure timer source for CCP
  CCPTMRS &= 0b11101111;
  CCPTMRS |= ((config&0b00010000)>>3); 
  if(config&0x80)
  {
    PIR3bits.CCP2IF = 0;  // Clear the interrupt flag
    PIE3bits.CCP2IE = 1;  // Enable the interrupt
  }
	if((CCP2CON & 0x0f) !=0x0a)
	{
		CM2_TRIS=0;
	}

}
#elif defined ( CC_V8_5 )

void OpenCompare2(unsigned char config, unsigned int period)
{

  	CCPR2L = period;       	// load CA2L 
    CCPR2H = (period >> 8);   // load CA2H

	CCP2CON = config&0x0F; //  Configure capture
  //configure timer source for CCP
  CCPTMRS &= 0b11101111;
  CCPTMRS |= ((config&0b00010000)>>1); 
  if(config&0x80)
  {
    PIR2bits.CCP2IF = 0;  // Clear the interrupt flag
    PIE2bits.CCP2IE = 1;  // Enable the interrupt
  }
	if((CCP2CON & 0x0f) !=0x0a)
	{
		CM2_TRIS=0;
	}

}

#endif

