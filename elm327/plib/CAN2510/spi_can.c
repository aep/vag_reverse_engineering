#include <pconfig.h>

#include "spi_can.h"
#include <spi.h>

#if defined (SPI_V1) || defined (SPI_V2) || defined (SPI_V3)|| defined (SPI_V4) ||defined (SPI_V5)

void CAN2510SPIReset( void )
{
    while( WriteSPI(CAN2510_CMD_RESET) );
}

unsigned char CAN2510SPIRead( unsigned char addr )
{
    while( WriteSPI(CAN2510_CMD_READ) );
    while( WriteSPI(addr) );
    return ReadSPI();
}

void CAN2510SPIWrite( unsigned char addr, unsigned char value )
{
    while( WriteSPI(CAN2510_CMD_WRITE) );
    while( WriteSPI(addr) );
    while( WriteSPI(value) );
}

void CAN2510SPISend( unsigned char bufferNumber )
{
    static unsigned char sendCommand;

    sendCommand = CAN2510_CMD_RTS & 0xf8;
    sendCommand |= (bufferNumber & 0x07);
    while( WriteSPI(sendCommand) );
}

void CAN2510SPIBitMod( unsigned char addr,
                       unsigned char mask,
		       unsigned char value )
{
    while( WriteSPI(CAN2510_CMD_BITMOD) );
    while( WriteSPI(addr) );
    while( WriteSPI(mask) );
    while( WriteSPI(value) );
}
#endif
