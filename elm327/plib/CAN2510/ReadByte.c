#include <pconfig.h>

#include "spi_can.h"
#include <spi.h>
#include <can2510.h>

#if defined (SPI_V1) || defined (SPI_V2) || defined (SPI_V3)|| defined (SPI_V4) ||defined (SPI_V5)

unsigned char CAN2510ByteRead( unsigned char addr )
{
    unsigned char ReturnValue;

    CAN2510Enable(  );                        // Enable SPI Communication to MCP2510
    while( WriteSPI(CAN2510_CMD_READ) );
    while( WriteSPI(addr) );
    ReturnValue = ReadSPI();
    CAN2510Disable(  );                       // Disable SPI Communication to MCP2510
    return( ReturnValue );
}

#endif
