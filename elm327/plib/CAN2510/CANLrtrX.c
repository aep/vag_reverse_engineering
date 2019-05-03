#include <pconfig.h>

#include "spi_can.h"
#include<can2510.h>

#if defined (SPI_V1) || defined (SPI_V2) || defined (SPI_V3)|| defined (SPI_V4) ||defined (SPI_V5)

void CAN2510LoadRTRXtd( unsigned char bufferNum,
                           unsigned long msgId,
         	           unsigned char numBytes )
{
    static unsigned char currBuffer;  // XMIT buffers are at 0x30,0x40,0x50
    unsigned char TempSIDL;

    if( numBytes > 8 )
        numBytes = 8;

    // convert input buffer of 0, 1, or 2 into buffer address of
    // 0x30,0x40,0x50
    currBuffer = bufferNum;
    currBuffer += 3;
    currBuffer <<= 4;

    // Wait for buffer to become available (Test TXREQ bit for buffer)
    while( ( CAN2510ByteRead(currBuffer) & 0x08 ) );

    /**************************************************************************/
    /* Format of Extended Identifier Message bits in "unsigned long" variable */
    /*    -   -   -  SID SID SID SID SID   SID SID SID SID SID SID EID EID    */
    /*    -   -   -   10  9   8   7   6     5   4   3   2   1   0   17  16    */
    /*                                                                        */
    /*   EID EID EID EID EID EID EID EID   EID EID EID EID EID EID EID EID    */
    /*    15  14  13  12  11  10  9   8     7   6   5   4   3   2   1   0     */
    /**************************************************************************/
    //
    // Write out header
    // Parse the msgId value into TXBxSIDH:TXBxSIDL:TXBxEIDH:TXBxEIDL
    //

    currBuffer +=4;                                               // Point to TXBxEIDL
    CAN2510ByteWrite( currBuffer, (unsigned char) msgId );        // Load TXBxEIDL

    msgId >>= 8;
    currBuffer--;
    CAN2510ByteWrite( currBuffer, (unsigned char) msgId );        // Load TXBxEIDH

    msgId >>= 5;
    TempSIDL = ((unsigned char) msgId) & 0xE0;                    // Load SID2:SID0 bits, clear all other bits
    TempSIDL |= 0x08;                                             // Set extended transfer bit
    msgId >>= 3;
    currBuffer--;
    TempSIDL |= ((unsigned char) msgId) & 0x03;                   // OR in EID17:EID16 bits
    CAN2510ByteWrite( currBuffer, TempSIDL );                     // Load TXBxSIDL

    msgId >>= 5;
    currBuffer--;
    CAN2510ByteWrite( currBuffer, (unsigned char) msgId );        // Load TXBxSIDH

    // Write out buffer length (in TXBxDLC)
    currBuffer +=4;                    // Pointing to DLC
    numBytes |= 0x40;                  // Set RTR bit
    CAN2510ByteWrite( currBuffer, numBytes );

}

#endif
