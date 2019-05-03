#include <pconfig.h>

#include "spi_can.h"
#include <can2510.h>

#if defined (SPI_V1) || defined (SPI_V2) || defined (SPI_V3)|| defined (SPI_V4) ||defined (SPI_V5)

unsigned char  CAN2510ReadMode( void )
{
    unsigned char mode;

    mode = CAN2510ByteRead( CAN2510_REG_CANSTAT );
    return ( mode & 0xE0 );                         // Mask off the OPMODE2:OPMODE0 bits and return this value
}                                                   // This indicates the MCP2510s current mode

#endif
