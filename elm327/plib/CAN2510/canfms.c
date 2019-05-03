#include <pconfig.h>

#include "spi_can.h"
#include <can2510.h>

#if defined (SPI_V1) || defined (SPI_V2) || defined (SPI_V3)|| defined (SPI_V4) ||defined (SPI_V5)

signed char CAN2510SetMsgFilterStd( unsigned char bufferNum,
                                      unsigned int  mask,
			              unsigned int  *filters )
{
    static unsigned char currFilter;
    static unsigned char modebits;
    unsigned char counter1;           // 0 - FF
    unsigned char counter2;           // 0 - 4

    /* Go into configuration mode */
    modebits = ( CAN2510ReadMode() & 0xE0 );        // Save current mode (in OPMODE2:OPMODE0 bits)
    CAN2510SetMode( CAN2510_MODE_CONFIG );          // Initiate MCP2510 configuration mode
    counter1 = 0;                                   // Initialize loop counters (for time out)
    counter2 = 0;                                   //
    
    //
    // This while loop is to ensure that the device has entered into configuration mode.
    // If the operating mode does not enter configuration mode in a given time frame
    // and error code will be returened.
    //
    while( ( CAN2510ReadMode() & 0xE0 ) != CAN2510_MODE_CONFIG )          // Test to ensure that entered
    {                                                                     //      CAN Configuration mode
         counter1++;                                                      // Did Not enter Configuration Mode
                                                                          //   Loop Counter, Should do error
                                                                          //      if infinite loop 
         if (counter1 == 0)
         {
              CAN2510SetMode(CAN2510_MODE_CONFIG);                        // The MCP2510 can now be configured
              counter2++;                                                 // Loop Counter 2 incremented
              if (counter2 == 5)
              {
                   return( -1 );                                          // could NOT initialize, exit function
              }
         }
    }

    if( bufferNum == 0 )
    {
        CAN2510SetSingleMaskStd( 0, mask );
	CAN2510SetSingleFilterStd( 0, filters[0] );
	CAN2510SetSingleFilterStd( 1, filters[1] );
    }
    else
    {
        CAN2510SetSingleMaskStd( 1, mask );
	for( currFilter = 0; currFilter < 4; currFilter++ )
	    CAN2510SetSingleFilterStd( currFilter + 2, filters[currFilter] );
    }

    // Restore original mode
    CAN2510ByteWrite( CAN2510_REG_CANCTRL, modebits );
    CAN2510SetMode( modebits );                 // Restore MCP2510 mode

    //
    // This while loop is to ensure that the device has returned to the original mode.
    // If the operating mode does not enter this mode in a given time frame
    // and error code will be returened.
    //
    while( ( CAN2510ReadMode() & 0xE0 ) != modebits )                     // Test to ensure that returned
    {                                                                     //      to original mode
         counter1++;                                                      // Did Not enter original Mode
                                                                          //   Loop Counter, Should do error
                                                                          //      if infinite loop 
         if (counter1 == 0)
         {
              CAN2510SetMode( modebits );                                 // The MCP2510 can now be configured
              counter2++;                                                 // Loop Counter 2 incremented
              if (counter2 == 5)
              {
                   return( -1 );                                          // could NOT initialize, exit function
              }
         }
    }

    return( 0 );
}
#endif
