#include <pconfig.h>

#include "spi_can.h"
#include <can2510.h>

#if defined (SPI_V1) || defined (SPI_V2) || defined (SPI_V3)|| defined (SPI_V4) ||defined (SPI_V5)

void CAN2510SetBufferPriority( unsigned char bufferNum,
                               unsigned char msgPriority )
{
    // Convert from buffer number of 0, 1, and 2 into TXBnCTRL register address
    // (0x30, 0x40, and 0x50, respectively)
    bufferNum += 3;
    bufferNum <<= 4;

    // Set priority
    CAN2510BitModify( bufferNum, 0x03, msgPriority );
}
#endif
