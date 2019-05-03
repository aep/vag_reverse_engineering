#include <pconfig.h>

#include "spi_can.h"
#include<can2510.h>

#if defined (SPI_V1) || defined (SPI_V2) || defined (SPI_V3)|| defined (SPI_V4) ||defined (SPI_V5)

void CAN2510LoadRTRStd( unsigned char bufferNum,
                           unsigned int  msgId,
         	           unsigned char numBytes )
{
    static unsigned char bufferAddr;  // XMIT buffers are at 0x30,0x40,0x50

    if( numBytes > 8 )
        numBytes = 8;

    // convert input buffer of 0, 1, or 2 into buffer address of
    // 0x30,0x40,0x50
    bufferAddr = bufferNum;
    bufferAddr += 3;
    bufferAddr <<= 4;

    // Wait for buffer to become available (Test TXREQ bit for buffer)
    while( ( CAN2510ByteRead(bufferAddr) & 0x08 ) );

    // Write out header
    bufferAddr += 2;                  // Pointing to SIDL
    CAN2510ByteWrite( bufferAddr, ((unsigned char) msgId) << 5 );
    msgId >>= 3;
    bufferAddr--;                     // Pointing to SIDH
    CAN2510ByteWrite( bufferAddr, (unsigned char) msgId );

    bufferAddr+=4;                    // Pointing to DLC
    // Write 3 of bytes expected in returned message
    numBytes |= 0x40;
    CAN2510ByteWrite( bufferAddr, numBytes );

}
#endif
