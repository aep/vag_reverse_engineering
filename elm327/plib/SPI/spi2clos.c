#include <p18cxxx.h>
#include <spi.h>

/********************************************************************
*     Function Name:    CloseSPI2                                   *
*     Return Value:     void                                        *
*     Parameters:       void                                        *
*     Description:      This function disables the SSP2 module. Pin *
*                       I/O returns under the control of the port   *
*                       registers.                                  *
********************************************************************/
#undef CloseSPI2

#if defined (SPI_V3) || defined (SPI_V5) || defined (SPI_V5_1) || defined (SPI_V6)

void CloseSPI2( void )
{
  SSP2CON1 &= 0xDF;                // disable synchronous serial port
}
#endif
