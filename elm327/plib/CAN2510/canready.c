#include <pconfig.h>

#include "spi_can.h"
#include <can2510.h>

#if defined (SPI_V1) || defined (SPI_V2) || defined (SPI_V3)|| defined (SPI_V4) ||defined (SPI_V5)

unsigned char CAN2510DataReady( unsigned char bufferNum )
{
    unsigned char int_flags;

    int_flags = CAN2510ByteRead( CAN2510_REG_CANINTF );


      if( bufferNum == CAN2510_RXB0 )         // RXB0 has Data waiting
      {
           return ( int_flags & 0x01 );
      }
      else if( bufferNum == CAN2510_RXB1 )    // RXB1 has Data waiting
      {
           return ( int_flags & 0x02 );
      }
      else if( bufferNum == CAN2510_RXBX )    // Either (or Both) RXB0 or RXB1 has Data waiting
      {
           return ( int_flags & 0x03 );
      }
      else
           return ( 0 );
}
#endif
