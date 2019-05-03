#include <pconfig.h>

#include <spi.h>
#include <can2510.h>
#include "spi_can.h"

#if defined (SPI_V1) || defined (SPI_V2) || defined (SPI_V3)|| defined (SPI_V4) ||defined (SPI_V5)

/*****************************************************************************/
/*                                                                           */
/*  Modifies the specifed bits in a register to the new values               */
/*                                                                           */
/*****************************************************************************/


void CAN2510BitModify( unsigned char addr,
                       unsigned char mask,
		       unsigned char value )
{
    CAN2510Enable(  );                        // Enable SPI Communication to MCP2510
    while( WriteSPI(CAN2510_CMD_BITMOD) );    // Send code for bit modify command
    while( WriteSPI(addr) );                  // Send address of register to modify
    while( WriteSPI(mask) );                  // Send mask of bits to modify in the register
    while( WriteSPI(value) );                 // Send new data to be loaded into specified bits
    CAN2510Disable(  );                       // Disable SPI Communication to MCP2510
}


#endif
