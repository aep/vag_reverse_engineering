#include <pconfig.h>

#include "spi_can.h"
#include <can2510.h>

#if defined (SPI_V1) || defined (SPI_V2) || defined (SPI_V3)|| defined (SPI_V4) ||defined (SPI_V5)

// MUST already be in configuration mode
void CAN2510SetSingleMaskStd( unsigned char maskNum,
                              unsigned int  mask )
{
    unsigned char writeValue;


    if( maskNum == 0 )
        maskNum = CAN2510_REG_RXM0SIDL;
    else
        maskNum = CAN2510_REG_RXM1SIDL;

    writeValue = ((unsigned char) mask) << 5;
    CAN2510ByteWrite( maskNum--, writeValue );
    writeValue = (unsigned char) (mask >> 3);
    CAN2510ByteWrite( maskNum,  writeValue );
}
#endif
