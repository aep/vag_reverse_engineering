#include <pconfig.h>

#include <spi.h>
#include "spi_can.h"
#include <can2510.h>

#if defined (SPI_V1) || defined (SPI_V2) || defined (SPI_V3)|| defined (SPI_V4) ||defined (SPI_V5)

void InitSPI( unsigned char SPI_syncMode,
              unsigned char SPI_busMode,
              unsigned char SPI_smpPhase )
{
    static unsigned char setting;

    /* Initialize SPI with user selected settings */
    OpenSPI( SPI_syncMode, SPI_busMode, SPI_smpPhase );


}
#endif
