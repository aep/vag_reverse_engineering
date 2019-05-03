#include <pconfig.h>

#include "spi_can.h"
#include <can2510.h>
#include <spi.h>

#if defined (SPI_V1) || defined (SPI_V2) || defined (SPI_V3)|| defined (SPI_V4) ||defined (SPI_V5)

void CAN2510SendBuffer( unsigned char bufferNumber )
{
    CAN2510Enable(  );                        // Enable SPI Communication to MCP2510

    switch ( bufferNumber )
    {
        case CAN2510_TXB0:
            while( WriteSPI(0x81) );             // Request TXB0 to be sent
            break;
        case CAN2510_TXB1:
            while( WriteSPI(0x82) );             // Request TXB1 to be sent
            break;
        case CAN2510_TXB2:
            while( WriteSPI(0x84) );             // Request TXB2 to be sent
            break;
        case CAN2510_TXB0_B1:
            while( WriteSPI(0x83) );             // Request TXB0 and B1 to be sent
            break;
        case CAN2510_TXB0_B2:
            while( WriteSPI(0x85) );             // Request TXB0 and B2 to be sent
            break;
        case CAN2510_TXB1_B2:
            while( WriteSPI(0x86) );             // Request TXB1 and B2 to be sent
            break;
        case CAN2510_TXB0_B1_B2:
            while( WriteSPI(0x87) );             // Request TXB0, B1, and B2 to be sent
            break;
        default:
            break;                               // Do NOT request any Transmit buffers to be sent
    }

    CAN2510Disable(  );                       // Disable SPI Communication to MCP2510
}

#endif
