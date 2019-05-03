#include <pconfig.h>

#include "spi_can.h"
#include <can2510.h>

#if defined (SPI_V1) || defined (SPI_V2) || defined (SPI_V3)|| defined (SPI_V4)||defined (SPI_V5)

signed char CAN2510WriteBuffer( unsigned char bufferNum )
{


    if ( bufferNum == 0 )
        CAN2510BitModify( CAN2510_REG_TXB0CTRL, 0x08, 0x08 );   // set the TXREQ bit

    else if  ( bufferNum == 1 )
        CAN2510BitModify( CAN2510_REG_TXB1CTRL, 0x08, 0x08 );   // set the TXREQ bit

    else if  ( bufferNum == 2 )
        CAN2510BitModify( CAN2510_REG_TXB2CTRL, 0x08, 0x08 );   // set the TXREQ bit

    else 
        return (-1);                     // No buffer was 

    return (0);

}

#endif
