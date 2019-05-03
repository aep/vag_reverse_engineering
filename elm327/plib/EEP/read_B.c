#include <p18cxxx.h>
#include <EEP.h>

/********************************************************************
*     Function Name:    Read_b_eep                                 *
*     Return Value:     contents of EEDATA register                *
*     Parameters:       unsigned int add                           *
*     Description:      Read single byte from Internal EEP         *
********************************************************************/
#if defined (EEP_V1)		//	128 byte EEP
unsigned char Read_b_eep( unsigned int badd )
{
	EEADR = (badd & 0x07f);
	EECON1bits.CFGS = 0;
	EECON1bits.EEPGD = 0;
	EECON1bits.RD = 1;
	Nop();							//Nop may be required for latency at high frequencies
	Nop();							//Nop may be required for latency at high frequencies
	return ( EEDATA );              // return with read byte 
}

#elif defined (EEP_V2)	//	256 byte EEP
unsigned char Read_b_eep( unsigned int badd )
{
	EEADR = (badd & 0x0ff);
  	EECON1bits.CFGS = 0;
	EECON1bits.EEPGD = 0;
	EECON1bits.RD = 1;
	Nop();							//Nop may be required for latency at high frequencies
	Nop();							//Nop may be required for latency at high frequencies
	return ( EEDATA );              // return with read byte
}

#elif defined (EEP_V3)				// 1024 byte EEP	
unsigned char Read_b_eep( unsigned int badd )
{
	EEADRH = (badd >> 8) & 0x03;
	EEADR = (badd & 0x0ff);
  	EECON1bits.CFGS = 0;
	EECON1bits.EEPGD = 0;
	EECON1bits.RD = 1;
	Nop();							//Nop may be required for latency at high frequencies
	Nop();							//Nop may be required for latency at high frequencies
	return ( EEDATA );              // return with read byte 
}
#endif
