#include <pconfig.h>

#include "spi_can.h"
#include <spi.h>
#include <can2510.h>

#if defined (SPI_V1) || defined (SPI_V2) || defined (SPI_V3)|| defined (SPI_V4) ||defined (SPI_V5)

void CAN2510Reset( void )
{
    CAN2510Enable(  );                        // Enable SPI Communication to MCP2510
    while( WriteSPI(CAN2510_CMD_RESET) );
    CAN2510Disable(  );                       // Disable SPI Communication to MCP2510
}

#endif
