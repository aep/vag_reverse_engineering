#include <pconfig.h>

#include "spi_can.h"
#include <can2510.h>

#if defined (SPI_V1) || defined (SPI_V2) || defined (SPI_V3)|| defined (SPI_V4) ||defined (SPI_V5)

void CAN2510SetSingleFilterXtd( unsigned char filterNum,
                                unsigned long filter )
{
    unsigned char addr;
    unsigned char TempSIDL;

    // MUST already be in Configuration mode
    //
    /*************************************************************************/
    /* Determine address of least significant byte of filter                 */
    /* - Do boundry checking to ensure that a valid filter is selected       */
    /*************************************************************************/
    if( filterNum < 3 )                // For Receive Filters 0, 1, and 2
       addr = (filterNum * 4) + 3;     //   at locations 00h-03h, 04h-07h, and 08h-0Bh

    else
    {
        if( filterNum > 5 )    // There is a maximum of 5 filters ensure that
            filterNum = 5;     //   pointer can only point to one of these locations

        addr = (filterNum * 4) + 7;    // For Receive Filters 3, 4, and 5
    }                                  //   at locations 10h-13h, 14h-17h, and 18h-1Bh

    /*************************************************************************/
    /*  Format of Filter bits in "unsigned long" variable                    */
    /*    -   -   -  SID SID SID SID SID   SID SID SID SID SID SID EID EID   */
    /*    -   -   -   10  9   8   7   6     5   4   3   2   1   0   17  16   */
    /*                                                                       */
    /*   EID EID EID EID EID EID EID EID   EID EID EID EID EID EID EID EID   */
    /*    15  14  13  12  11  10  9   8     7   6   5   4   3   2   1   0    */
    /*************************************************************************/


    CAN2510ByteWrite( addr, (unsigned char) filter );               // Load RXFxEIDL

    filter >>= 8;
    addr--;
    CAN2510ByteWrite( addr, (unsigned char) filter );               // Load RXFxEIDH

    filter >>= 5;
    TempSIDL = ((unsigned char) filter) & 0xE0;                     // Load SID2:SID0 bits, clear all other bits
    filter >>= 3;
    addr--;
    TempSIDL |= ((unsigned char) filter) & 0x03;                    // OR in EID17:EID16 bits
    CAN2510ByteWrite( addr, TempSIDL );                             // Load RXFxSIDL

    filter >>= 5;
    addr--;
    CAN2510ByteWrite( addr, (unsigned char) filter );               // Load RXFxSIDH

}


#endif
