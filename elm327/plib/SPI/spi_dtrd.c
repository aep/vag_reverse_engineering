#include <p18cxxx.h>
#include <spi.h>

/********************************************************************
*     Function Name:    DataRdySPI                                  *
*     Return Value:     status byte to indicate if BF = 1           *
*     Parameters:       void                                        *
*     Description:      Determine if there is a byte to be read     *
*                       from the SSPBUF register.                   *
********************************************************************/

#undef DataRdySPI

#if defined (SPI_V1) || defined (SPI_V4)

unsigned char DataRdySPI( void )
{
  if ( SSPSTATbits.BF )
    return ( +1 );                // data in SSPBUF register
  else
    return ( 0 );                 // no data in SSPBUF register
}

#endif
