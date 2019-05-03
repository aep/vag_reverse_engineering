#include <p18cxxx.h>
#include <spi.h>

/********************************************************************
*     Function Name:    WriteSPI2                                   *
*     Return Value:     Status byte for WCOL detection.             *
*     Parameters:       Single data byte for SPI2 bus.              *
*     Description:      This routine writes a single byte to the    * 
*                       SPI2 bus.                                   *
********************************************************************/
#if defined (SPI_V3) || defined (SPI_V5)

signed char WriteSPI2( unsigned char data_out )
{
  unsigned char TempVar;  
  
  TempVar = SSP2BUF;           // Clears BF
  PIR3bits.SSP2IF = 0;         // Clear interrupt flag
  SSP2CON1bits.WCOL = 0;			//Clear any previous write collision
  SSP2BUF = data_out;          // write byte to SSP2BUF register
  if ( SSP2CON1 & 0x80 )       // test if write collision occurred
   return ( -1 );              // if WCOL bit is set return negative #
  else
   // while( !SSP2STATbits.BF ); // wait until bus cycle complete 
   while(!PIR3bits.SSP2IF); //wait until bus cycle complete
  return ( 0 );                // if WCOL bit is not set return non-negative#
}

#elif defined (SPI_V5_1) || defined (SPI_V6)

signed char WriteSPI2( unsigned char data_out )
{
  unsigned char TempVar;  
  
  TempVar = SSP2BUF;           // Clears BF
  PIR2bits.SSP2IF = 0;         // Clear interrupt flag
  SSP2BUF = data_out;          // write byte to SSP2BUF register
  if ( SSP2CON1 & 0x80 )       // test if write collision occurred
   return ( -1 );              // if WCOL bit is set return negative #
  else
   // while( !SSP2STATbits.BF ); // wait until bus cycle complete 
   while(!PIR2bits.SSP2IF); //wait until bus cycle complete
  return ( 0 );                // if WCOL bit is not set return non-negative#
}

#endif
