#include <p18cxxx.h>
#include <spi.h>

/********************************************************************
*     Function Name:    CloseSPI                                    *
*     Return Value:     void                                        *
*     Parameters:       void                                        *
*     Description:      This function disables the SSP module. Pin  *
*                       I/O returns under the control of the port   *
*                       registers.                                  *
********************************************************************/
#undef CloseSPI

#if defined (SPI_V1)

void CloseSPI( void )
{
  SSPCON1 &= 0xDF;                // disable synchronous serial port
}

#endif

#if defined (SPI_V4)

void CloseSPI( void )
{
  SSPCON &= 0xDF;                // disable synchronous serial port
}

#endif
