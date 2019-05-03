#include <p18cxxx.h>
#include <mwire.h>

#if defined (MWIRE_V1)
/********************************************************************
*     Function Name:    ReadMwire                                   *
*     Return Value:     data byte                                   *
*     Parameters:       2 bytes which reflect startbit, opcode and  * 
*                       address.                                    *
*     Description:      Read single byte from Microwire device. The * 
*                       start  bit, opcode and address compose the  *
*                       high and low bytes passed into this         *
*                       function.                                   *
********************************************************************/
unsigned char ReadMwire( unsigned char high_byte, unsigned char low_byte )
{
  SSPCON1bits.CKP = 1;            // ensure clock idle state is high for transmission
  SSPBUF = high_byte;             // send start bit and opcode, initiate bus cycle
  while( !SSPSTATbits.BF );       // wait until reception is complete
  SSPBUF = low_byte;              // send low byte, usually address, initiate bus cycle
  while( !SSPSTATbits.BF );       // wait until reception is complete

  SSPCON1bits.CKP = 0;            // ensure clock idle state is low for read cycle
  SSPBUF = 0x00;                  // initiate read cycle
  while( !SSPSTATbits.BF );       // wait until reception is complete
  SSPCON1bits.CKP = 1;            // ensure clock idle state is high for transmission
  return ( SSPBUF );              // return with one byte from Microwire device
}
#endif

#if defined (MWIRE_V3)
/********************************************************************
*     Function Name:    ReadMwire                                   *
*     Return Value:     data byte                                   *
*     Parameters:       2 bytes which reflect startbit, opcode and  * 
*                       address.                                    *
*     Description:      Read single byte from Microwire device. The * 
*                       start  bit, opcode and address compose the  *
*                       high and low bytes passed into this         *
*                       function.                                   *
********************************************************************/
unsigned char ReadMwire( unsigned char high_byte, unsigned char low_byte )
{
  SSPCONbits.CKP = 1;            // ensure clock idle state is high for transmission
  SSPBUF = high_byte;             // send start bit and opcode, initiate bus cycle
  while( !SSPSTATbits.BF );       // wait until reception is complete
  SSPBUF = low_byte;              // send low byte, usually address, initiate bus cycle
  while( !SSPSTATbits.BF );       // wait until reception is complete

  SSPCONbits.CKP = 0;            // ensure clock idle state is low for read cycle
  SSPBUF = 0x00;                  // initiate read cycle
  while( !SSPSTATbits.BF );       // wait until reception is complete
  SSPCONbits.CKP = 1;            // ensure clock idle state is high for transmission
  return ( SSPBUF );              // return with one byte from Microwire device
}

#endif

