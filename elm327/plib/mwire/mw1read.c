#include <p18cxxx.h>
#include <mwire.h>

#if defined (MWIRE_V2) || defined (MWIRE_V4) || defined (MWIRE_V5) || defined (MWIRE_V6)
/********************************************************************
*     Function Name:    ReadMwire1                                  *
*     Return Value:     data byte                                   *
*     Parameters:       2 bytes which reflect startbit, opcode and  * 
*                       address.                                    *
*     Description:      Read single byte from Microwire1 device.    * 
*                       The start  bit, opcode and address compose  *
*                       the high and low bytes passed into this     *
*                       function.                                   *
********************************************************************/
unsigned char ReadMwire1( unsigned char high_byte, unsigned char low_byte )
{
  SSP1CON1bits.CKP = 1;            // ensure clock idle state is high for transmission
  SSP1BUF = high_byte;             // send start bit and opcode, initiate bus cycle
  while( !SSP1STATbits.BF );       // wait until reception is complete
  SSP1BUF = low_byte;              // send low byte, usually address, initiate bus cycle
  while( !SSP1STATbits.BF );       // wait until reception is complete

  SSP1CON1bits.CKP = 0;            // ensure clock idle state is low for read cycle
  SSP1BUF = 0x00;                  // initiate read cycle
  while( !SSP1STATbits.BF );       // wait until reception is complete
  SSP1CON1bits.CKP = 1;            // ensure clock idle state is high for transmission
  return ( SSP1BUF );              // return with one byte from Microwire1 device
}
#endif
