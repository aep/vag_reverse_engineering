#include <p18cxxx.h>
#include <spi.h>

/*********************************************************************
*     Function Name:    putsSPI1                                     *
*     Return Value:     void                                         *
*     Parameters:       address of write string storage location     *
*     Description:      This routine writes a string to the SPI1 bus.*  
*********************************************************************/
#if defined (SPI_V2) || defined (SPI_V3) || defined (SPI_V5) || defined (SPI_V5_1) || defined (SPI_V5_2) || defined (SPI_V6)

void putsSPI1( unsigned char *wrptr )
{
  while ( *wrptr )                 // test for string null character
  {
     SSP1BUF = *wrptr++;           // initiate SPI1 bus cycle
     while( !SSP1STATbits.BF );    // wait until 'BF' bit is set
  }
}
#endif
