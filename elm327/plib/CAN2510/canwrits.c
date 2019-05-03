#include <pconfig.h>

#include "spi_can.h"
#include <can2510.h>

#if defined (SPI_V1) || defined (SPI_V2) || defined (SPI_V3)|| defined (SPI_V4)||defined (SPI_V5)

// Writes a standard format message to the first available buffer
// Returns a value indicating which buffer was used
signed char CAN2510WriteStd( unsigned int  msgId,
                               unsigned char msgPriority,
         	               unsigned char numBytes,
                               unsigned char *data )
{
    unsigned char sentBuffer = 0;     // sentBuffer is initialized (=0)
    static unsigned char currBuffer;  // XMIT buffers are at 0x30,0x40,0x50
    static unsigned char dataptr;
    union CANReadStatusBits
    {
        unsigned char StatusByte;          // 
        struct ReadStatusBits 
        {
            unsigned RXB0IF:1;                // LSb of transmitted Byte
            unsigned RXB1IF:1;
            unsigned TXB0REQ:1;
            unsigned TXB0IF:1;
            unsigned TXB1REQ:1;
            unsigned TXB1IF:1;
            unsigned TXB2REQ:1;
            unsigned TXB2IF:1;                // MSb of transmitted Byte
        };
    } ReadStatus;



    if( numBytes > 8 )
    {
        numBytes = 8;
    }

    ReadStatus.StatusByte = CAN2510ReadStatus();  // Get the Status of all CAN buffers

    if (ReadStatus.TXB0REQ == 0)                  // Is TXB0 free and can be used for transmission
        currBuffer = 0x30;                        // point to correct registers (lower nibble is index)
    else if (ReadStatus.TXB1REQ == 0)             // Is TXB1 free and can be used for transmission
        currBuffer = 0x40;                        // point to correct registers (lower nibble is index)
    else if (ReadStatus.TXB2REQ == 0)             // Is TXB2 free and can be used for transmission
        currBuffer = 0x50;                        // point to correct registers (lower nibble is index)
    else                                          // NO, all buffers are full
        return -1;                                // -1 specifies that no TX buffer was available

    // Parse the msgId value into TXBxSIDH:TXBxSIDL
    currBuffer +=2;                                                    // Point to TXBxSIDL
    CAN2510ByteWrite( currBuffer, ((unsigned char) msgId) << 5 );      // Load TXBxSIDL
    currBuffer--;
    msgId >>= 3;
    CAN2510ByteWrite( currBuffer, (unsigned char) msgId );           // Load TXBxSIDH

    // Write out buffer length (in TXBxDLC)
    currBuffer += 4;
    CAN2510ByteWrite( currBuffer, numBytes );
    currBuffer ++;

    // Write out message
    while( numBytes-- )
    {
        CAN2510ByteWrite( currBuffer++, *data++ );
    }

    // Set priority and set request to send bit
    CAN2510ByteWrite( currBuffer & 0xF0, msgPriority | 0x08 );

    // Success!
    sentBuffer = (currBuffer >> 4);      // Remove index to point to buffers registers
    sentBuffer -= 3;                     // normalize return value to specify TX buffer
    return sentBuffer;

}


#endif
