#include <p18cxxx.h>
#include <spi.h>

/*********************************************************************
*     Function Name:    putsSPI2                                     *
*     Return Value:     void                                         *
*     Parameters:       address of write string storage location     *
*     Description:      This routine writes a string to the SPI2 bus.*  
*********************************************************************/
#if defined (SPI_V3) || defined (SPI_V5) || defined (SPI_V5_1) || defined (SPI_V6)

void putsSPI2( unsigned char *wrptr )
{
  while ( *wrptr )                 // test for string null character
  {
     SSP2BUF = *wrptr++;           // initiate SPI2 bus cycle
     while( !SSP2STATbits.BF );    // wait until 'BF' bit is set
  }
}

#endif
