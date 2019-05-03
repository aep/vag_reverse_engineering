#include <p18cxxx.h>
#include <spi.h>

/********************************************************************
*     Function Name:    CloseSPI1                                   *
*     Return Value:     void                                        *
*     Parameters:       void                                        *
*     Description:      This function disables the SSPa module. Pin *
*                       I/O returns under the control of the port   *
*                       registers.                                  *
********************************************************************/
#undef CloseSPI1

#if defined (SPI_V2) || defined (SPI_V3) || defined (SPI_V5) || defined (SPI_V5_1) || defined (SPI_V5_2) || defined (SPI_V6)

void CloseSPI1( void )
{
  SSP1CON1 &= 0xDF;               // disable synchronous serial port
}
#endif
