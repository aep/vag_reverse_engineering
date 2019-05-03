#include <p18cxxx.h>
#include <spi.h>

/********************************************************************
*     Function Name:    ReadSPI1                                    *
*     Return Value:     contents of SSP1BUF register                *
*     Parameters:       void                                        *
*     Description:      Read single byte from SPI1 bus.             *
********************************************************************/
#if defined (SPI_V2) || defined (SPI_V3) || defined (SPI_V5) || defined (SPI_V5_1) || defined (SPI_V5_2) || defined (SPI_V6)

unsigned char ReadSPI1( void )
{
  unsigned char TempVar;
  TempVar = SSP1BUF;       //Clear BF
  PIR1bits.SSP1IF = 0;     //Clear interrupt flag
  SSP1BUF = 0x00;          // initiate bus cycle
  //while ( !SSP1STATbits.BF );                // wait until cycle complete
  while(!PIR1bits.SSP1IF); //wait until cycle complete
  return ( SSP1BUF );      // return with byte read 
}

#endif
