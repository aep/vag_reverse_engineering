#include <pconfig.h>

#include <spi.h>
#include <can2510.h>
#include "spi_can.h"

#if defined (SPI_V1) || defined (SPI_V2) || defined (SPI_V3)|| defined (SPI_V4)||defined (SPI_V5)

unsigned char CAN2510InterruptStatus( void )
{
    return( CAN2510ByteRead( CAN2510_REG_CANSTAT ) & 0x0E );         // Return the source of the interrupt(s)
}
#endif
