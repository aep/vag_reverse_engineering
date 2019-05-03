#include <p18cxxx.h>
#include <spi.h>

/********************************************************************
*     Function Name:    DataRdySPI1                                 *
*     Return Value:     status byte to indicate if BF = 1           *
*     Parameters:       void                                        *
*     Description:      Determine if there is a byte to be read     *
*                       from the SSP1BUF register.                  *
********************************************************************/
#undef DataRdySPI1

#if defined (SPI_V2) || defined (SPI_V3) || defined (SPI_V5) || defined (SPI_V5_1) || defined (SPI_V5_2) || defined (SPI_V6)
unsigned char DataRdySPI1( void )
{
  if ( SSP1STATbits.BF )
    return ( +1 );                // data in SSP1BUF register
  else
    return ( 0 );                 // no data in SSP1BUF register
}
#endif
