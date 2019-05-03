#include <pconfig.h>

#include "spi_can.h"
#include <can2510.h>

#if defined (SPI_V1) || defined (SPI_V2) || defined (SPI_V3)|| defined (SPI_V4) ||defined (SPI_V5)

// MUST already be in configuration mode
void CAN2510SetSingleMaskXtd( unsigned char maskNum,
                              unsigned long mask )
{
    unsigned char TempSIDL;

    if( maskNum == 0 )
        maskNum = CAN2510_REG_RXM0EID0;          // maskNum is now the MCP2510 address of RXM0EID0
    else
        maskNum = CAN2510_REG_RXM1EID0;          // maskNum is now the MCP2510 address of RXM1EID0


    /*************************************************************************/
    /*  Format of Mask bits in "unsigned long" variable                      */
    /*    -   -   -  SID SID SID SID SID   SID SID SID SID SID SID EID EID   */
    /*    -   -   -   10  9   8   7   6     5   4   3   2   1   0   17  16   */
    /*                                                                       */
    /*   EID EID EID EID EID EID EID EID   EID EID EID EID EID EID EID EID   */
    /*    15  14  13  12  11  10  9   8     7   6   5   4   3   2   1   0    */
    /*************************************************************************/


    CAN2510ByteWrite( maskNum, (unsigned char) mask );            // Load RXMxEIDL

    mask >>= 8;
    maskNum--;
    CAN2510ByteWrite( maskNum, (unsigned char) mask );            // Load RXMxEIDH

    mask >>= 5;
    TempSIDL = ((unsigned char) mask) & 0xE0;                     // Load SID2:SID0 bits, clear all other bits
    mask >>= 3;
    maskNum--;
    TempSIDL |= ((unsigned char) mask) & 0x03;                    // OR in EID17:EID16 bits
    CAN2510ByteWrite( maskNum, TempSIDL );                        // Load RXMxSIDL

    mask >>= 5;
    maskNum--;
    CAN2510ByteWrite( maskNum, (unsigned char) mask );            // Load RXMxSIDH

}
#endif
