#include <pconfig.h>

#include "spi_can.h"
#include <can2510.h>

#if defined (SPI_V1) || defined (SPI_V2) || defined (SPI_V3)|| defined (SPI_V4) ||defined (SPI_V5)

/*****************************************************************************/
/***                                                                       ***/
/***   Function Name:   CAN2510SetSingleFilterStd                          ***/
/***                                                                       ***/
/***                                                                       ***/
/*****************************************************************************/


void CAN2510SetSingleFilterStd( unsigned char filterNum,
                                unsigned int  filter )
{
    unsigned char addr;
    unsigned char writeValue;

    // MUST already be in Configuration mode
    //
    /*************************************************************************/
    /* Determine address of least significant byte of filter                 */
    /* - Do boundry checking to ensure that a valid filter is selected       */
    /*************************************************************************/
    if( filterNum < 3 )                // For Receive Filters 0, 1, and 2
       addr = (filterNum * 4) + 1;     //   at locations 00h/01h, 04h/05h, and 08h/09h

    else
    {
        if( filterNum > 5 )    // There is a maximum of 5 filters ensure that
            filterNum = 5;     //   pointer can only point to one of these locations

        addr = (filterNum * 4) + 5;    // For Receive Filters 3, 4, and 5
    }                                  //   at locations 10h/11h, 14h/15h, and 18h/19h

    /*************************************************************************/
    /* Write RXFnSIDL                                                        */
    /*   filter<2:0> -> RXFnSIDL<7:5>                                        */
    /* - only upper three bits are significant (although bit 3 must be clear */
    /*   to indicate that we are using a standard message filter)            */
    /*************************************************************************/
    writeValue = ((unsigned char) filter) << 5;
    CAN2510ByteWrite( addr--, writeValue );

    /*************************************************************************/
    /* Write RXFnSIDH                                                        */
    /*   filter<10:3> -> RXFnSIDH<7:0>                                       */
    /* - contains bits 10:3 of the filter value                              */
    /*************************************************************************/
    writeValue = (unsigned char) ( filter >> 3 );
    CAN2510ByteWrite( addr, writeValue );
}

#endif
