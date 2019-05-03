#include <pconfig.h>

#include <spi.h>
#include <can2510.h>
#include "spi_can.h"

#if defined (SPI_V1) || defined (SPI_V2) || defined (SPI_V3)|| defined (SPI_V4) ||defined (SPI_V5)

void CAN2510Enable( void );
void CAN2510Disable( void );

/*****************************************************************************/
/*  Retrieves the Buffer status for the CAN module. Format of the bits is:   */
/*       bit7    bit6    bit5    bit4    bit3    bit2    bit1    bit0        */
/*      TX2IF  TXB2REQ  TX1IF  TXB1REQ  TX0IF  TXB0REQ  RXB1IF  RXB0IF       */
/*                                                                           */
/*****************************************************************************/

unsigned char CAN2510ReadStatus( void )
{
    unsigned char readValue;

    CAN2510Enable(  );                // Enable SPI Communication to MCP2510
    WriteSPI(CAN2510_CMD_STATUS);     // Send code for Read Status command
    readValue = ReadSPI();            // Read the status code, this is a Dummy read
    CAN2510Disable(  );               // Disable SPI Communication to MCP2510
    return ( readValue );             // Return the status code (same as previous read)
}
#endif
