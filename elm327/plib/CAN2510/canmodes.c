#include <pconfig.h>

#include "spi_can.h"
#include <can2510.h>

#if defined (SPI_V1) || defined (SPI_V2) || defined (SPI_V3)|| defined (SPI_V4) ||defined (SPI_V5)

void CAN2510SetMode( unsigned char mode )
{
    CAN2510BitModify( CAN2510_REG_CANCTRL, 0xE0, mode );
}


#endif
