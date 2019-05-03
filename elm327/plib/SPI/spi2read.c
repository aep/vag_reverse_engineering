#include <p18cxxx.h>
#include <spi.h>

/********************************************************************
*     Function Name:    ReadSPI2                                    *
*     Return Value:     contents of SSP2BUF register                *
*     Parameters:       void                                        *
*     Description:      Read single byte from SPI2 bus.             *
********************************************************************/
#if defined (SPI_V3) || defined (SPI_V5)

unsigned char ReadSPI2( void )
{
  unsigned char TempVar;
  TempVar = SSP2BUF;       //Clear BF
  PIR3bits.SSP2IF = 0;     //Clear interrupt flag
  SSP2BUF = 0x00;          // initiate bus cycle
  //while ( !SSP2STATbits.BF );                // wait until cycle complete
  while(!PIR3bits.SSP2IF); //wait until cycle complete
  return ( SSP2BUF );      // return with byte read 
}
#endif

#if defined (SPI_V5_1) || defined (SPI_V6)

unsigned char ReadSPI2( void )
{
  unsigned char TempVar;
  TempVar = SSP2BUF;       //Clear BF
  PIR2bits.SSP2IF = 0;     //Clear interrupt flag
  SSP2BUF = 0x00;          // initiate bus cycle
  //while ( !SSP2STATbits.BF );                // wait until cycle complete
  while(!PIR2bits.SSP2IF); //wait until cycle complete
  return ( SSP2BUF );      // return with byte read 
}


#endif
