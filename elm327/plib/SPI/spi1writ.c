#include <p18cxxx.h>
#include <spi.h>

/********************************************************************
*     Function Name:    WriteSPI1                                   *
*     Return Value:     Status byte for WCOL detection.             *
*     Parameters:       Single data byte for SPI1 bus.              *
*     Description:      This routine writes a single byte to the    * 
*                       SPI1 bus.                                   *
********************************************************************/
#if defined (SPI_V2) || defined (SPI_V3) || defined (SPI_V5) || defined (SPI_V5_1) || defined (SPI_V5_2) || defined (SPI_V6)

signed char WriteSPI1( unsigned char data_out )
{
  unsigned char TempVar;  
  TempVar = SSP1BUF;           // Clears BF
  PIR1bits.SSP1IF = 0;         // Clear interrupt flag
  SSP1CON1bits.WCOL = 0;			//Clear any previous write collision
  SSP1BUF = data_out;          // write byte to SSP1BUF register
  if ( SSP1CON1 & 0x80 )       // test if write collision occurred
   return ( -1 );              // if WCOL bit is set return negative #
  else
   //while( !SSP1STATbits.BF ); // wait until bus cycle complete 
   while(!PIR1bits.SSP1IF); // wait until bus cycle complete
  return ( 0 );                // if WCOL bit is not set return non-negative#
}

#endif
