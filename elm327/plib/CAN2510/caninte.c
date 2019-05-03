#include <pconfig.h>

#include <spi.h>
#include <can2510.h>
#include "spi_can.h"

#if defined (SPI_V1) || defined (SPI_V2) || defined (SPI_V3)|| defined (SPI_V4) ||defined (SPI_V5)


    /********************************************************************/
    /*                                                                  */
    /* The CANINTE register can be modified by the bit modify command   */
    /*                                                                  */
    /********************************************************************/

void CAN2510InterruptEnable( unsigned char interruptFlags )
{
    static unsigned char setting;

    /* Select what interrupts are enabled */
    setting = ~interruptFlags;
    CAN2510ByteWrite( CAN2510_REG_CANINTE, setting );

}
#endif
