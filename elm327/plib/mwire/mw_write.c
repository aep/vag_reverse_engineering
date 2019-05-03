#include <p18cxxx.h>
#include <mwire.h>

#if defined (MWIRE_V1)
/********************************************************************
*     Function Name:    WriteMwire                                  *
*     Return Value:     Status byte for WCOL detection.             *
*     Parameters:       Single data byte for EEPROM device.         *
*     Description:      This routine writes a single byte to the    * 
*                       Microwire device.                           *
********************************************************************/
signed char WriteMwire( unsigned char data_out )
{
  SSPCON1bits.CKP = 1;         // ensure clock idle state is 1 for transmission
  SSPBUF = data_out;           // write single byte to the Microwire device
  if ( SSPCON1bits.WCOL )      // test if write collision occurred
   return ( -1 );              // if WCOL bit is set return negative #
  else
  {
   while ( !SSPSTATbits.BF );  // wait until bus cycle complete
   return ( 0 );               // if WCOL bit is not set return non negative #
  }
}
#endif

#if defined (MWIRE_V3)
/********************************************************************
*     Function Name:    WriteMwire                                  *
*     Return Value:     Status byte for WCOL detection.             *
*     Parameters:       Single data byte for EEPROM device.         *
*     Description:      This routine writes a single byte to the    * 
*                       Microwire device.                           *
********************************************************************/
signed char WriteMwire( unsigned char data_out )
{
  SSPCONbits.CKP = 1;         // ensure clock idle state is 1 for transmission
  SSPBUF = data_out;           // write single byte to the Microwire device
  if ( SSPCONbits.WCOL )      // test if write collision occurred
   return ( -1 );              // if WCOL bit is set return negative #
  else
  {
   while ( !SSPSTATbits.BF );  // wait until bus cycle complete
   return ( 0 );               // if WCOL bit is not set return non negative #
  }
}
#endif
