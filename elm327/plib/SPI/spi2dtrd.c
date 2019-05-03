#include <p18cxxx.h>
#include <spi.h>

/********************************************************************
*     Function Name:    DataRdySPI2                                 *
*     Return Value:     status byte to indicate if BF = 1           *
*     Parameters:       void                                        *
*     Description:      Determine if there is a byte to be read     *
*                       from the SSP2BUF register.                  *
********************************************************************/
#undef DataRdySPI2

#if defined (SPI_V3) || defined (SPI_V5) || defined (SPI_V5_1) || defined (SPI_V6)
unsigned char DataRdySPI2( void )
{
  if ( SSP2STATbits.BF )
    return ( +1 );                // data in SSP2BUF register
  else
    return ( 0 );                 // no data in SSP2BUF register
}

#endif
