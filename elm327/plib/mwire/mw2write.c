#include <p18cxxx.h>
#include <mwire.h>

#if defined (MWIRE_V2) || defined (MWIRE_V4) || defined (MWIRE_V6)
/********************************************************************
*     Function Name:    WriteMwire2                                 *
*     Return Value:     Status byte for WCOL detection.             *
*     Parameters:       Single data byte for EEPROM device.         *
*     Description:      This routine writes a single byte to the    * 
*                       Microwire2 device.                          *
********************************************************************/
signed char WriteMwire2( unsigned char data_out )
{
  SSP2CON1bits.CKP = 1;        // ensure clock idle state is 1 for transmission
  SSP2BUF = data_out;          // write single byte to the Microwire2 device
  if ( SSP2CON1bits.WCOL )     // test if write collision occurred
   return ( -1 );              // if WCOL bit is set return negative #
  else
  {
   while ( !SSP2STATbits.BF ); // wait until bus cycle complete
   return ( 0 );               // if WCOL bit is not set return non negative #
  }
}
#endif
