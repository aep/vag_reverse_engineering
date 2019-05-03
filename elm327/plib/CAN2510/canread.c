#include <pconfig.h>

#include "spi_can.h"
#include <can2510.h>

#if defined (SPI_V1) || defined (SPI_V2) || defined (SPI_V3)|| defined (SPI_V4) ||defined (SPI_V5)

unsigned char CAN2510DataRead( unsigned char bufferNum,
                               unsigned long *msgId,
			       unsigned char *numBytes,
			       unsigned char *data )
{
    static unsigned char bufferAddr;
    static unsigned char readValue;
    static unsigned char DLCRegister;
    unsigned char result;
    unsigned char tempSIDL;


    bufferNum &= 0x01;                       // Only LSb is used to specify Buffer 0 or Buffer 1

    bufferAddr = bufferNum + 6;              // translate bufferNum of 0 or 1 into buffer address
    bufferAddr <<= 4;                        // of 0x60 or 0x70, respectively

    DLCRegister = CAN2510ByteRead( bufferAddr+5 );          // Read DLC register
    readValue = ( DLCRegister & 0x0f );                     // Remove all unwanted bits from DLCRegister
    if( readValue > 8 )
        readValue = 8;                                      // Ensure that DLC is NOT greater then 8
    *numBytes = readValue;                                  // Save Data length 

    tempSIDL = CAN2510ByteRead( bufferAddr+2 );             // Read SIDL register (for extended identifier)
    if( tempSIDL & 0x08 )                                   // Extended message?
    {                                                       // YES, Create Extended Message (SID10:SID0:EID17:EID0)
        readValue = CAN2510ByteRead( bufferAddr+1 );        // Read the high byte (SIDH - SID10:SID3)
        *msgId = readValue;

        *msgId <<= 3;                                       // Ready to load SID2:SID0 bits into msgId
        *msgId |= ( (tempSIDL >> 5) & 0x07 );               // Shift SID2:SID0 bits (SIDL) to bit2:bit0 of byte and load into msgId
        *msgId <<= 2;
        *msgId |= (tempSIDL & 0x03);                        // Load EID17:EID16 bits (SIDL - bit1:bit0) into msgId

        *msgId <<= 8;
        readValue = CAN2510ByteRead( bufferAddr+3 );        // Load EID15:EID8 bits (EIDH) into msgId
        *msgId |= readValue;

        *msgId <<= 8;
        readValue = CAN2510ByteRead( bufferAddr+4 );        // Load EID7:EID0 bits (EIDL) into msgId
        *msgId |= readValue;

        if( DLCRegister & 0x40 )                                       // Is Xtd Msgid an RTR?
        {                                                              // YES
            if( bufferNum )                                            // Clear Buffer 1 full flag
                CAN2510BitModify( CAN2510_REG_CANINTF, 0x02, 0x00 );
            else                                                       // Clear Buffer 0 full flag
                CAN2510BitModify( CAN2510_REG_CANINTF, 0x01, 0x00 );

            return CAN2510_XTDRTR;                                     // RTR on an XTD message
        }

        result = CAN2510_XTDMSG;                            // NOT an RTR Message (XTD)
    }
    else                                                    // NO (Standard message)
    {
        *msgId = CAN2510ByteRead( bufferAddr+1 );           // Read the high byte (SIDH - SID10:SID3)
        *msgId <<= 3;                                       // Ready to load SID2:SID0 bits into msgId
        *msgId |= (tempSIDL >> 5);                          // Shift SID2:SID0 bits (SIDL) to bit2:bit0 of byte and load into msgId

        if( tempSIDL & 0x10 )                                          // Is Std Msgid an RTR?
        {                                                              // YES
            if( bufferNum )                                            // Clear Buffer 1 full flag
                CAN2510BitModify( CAN2510_REG_CANINTF, 0x02, 0x00 );
            else                                                       // Clear Buffer 0 full flag
                CAN2510BitModify( CAN2510_REG_CANINTF, 0x01, 0x00 );

            return CAN2510_STDRTR;                                     // RTR on an STD message
        }
        result = CAN2510_STDMSG;                            // Standard message
    }

    bufferAddr += 6;                                        // Set buffer ptr to start of data

    readValue = *numBytes;                                  // Restore length of Data
    while( readValue-- )                                    // Copy specified number of bytes
    {
        *data++ = CAN2510ByteRead( bufferAddr++ );          // Copy the data into user locations
    }

    if( bufferNum )                                           // Clear Buffer 1 full flag
        CAN2510BitModify( CAN2510_REG_CANINTF, 0x02, 0x00 );
    else                                                      // Clear Buffer 0 full flag
        CAN2510BitModify( CAN2510_REG_CANINTF, 0x01, 0x00 );

    return result;                                            // Result is either STDMSG or XTDMSG
}
#endif
