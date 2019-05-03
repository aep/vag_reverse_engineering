#include <p18cxxx.h>
#include <mwire.h>

#if defined (MWIRE_V2) || defined (MWIRE_V4) || defined (MWIRE_V5) || defined (MWIRE_V6)
/********************************************************************
*     Function Name:    WriteMwire1                                 *
*     Return Value:     Status byte for WCOL detection.             *
*     Parameters:       Single data byte for EEPROM device.         *
*     Description:      This routine writes a single byte to the    * 
*                       Microwire1 device.                          *
********************************************************************/
signed char WriteMwire1( unsigned char data_out )
{
  SSP1CON1bits.CKP = 1;        // ensure clock idle state is 1 for transmission
  SSP1BUF = data_out;          // write single byte to the Microwire1 device
  if ( SSP1CON1bits.WCOL )     // test if write collision occurred
   return ( -1 );              // if WCOL bit is set return negative #
  else
  {
   while ( !SSP1STATbits.BF ); // wait until bus cycle complete
   return ( 0 );               // if WCOL bit is not set return non negative #
  }
}
#endif
