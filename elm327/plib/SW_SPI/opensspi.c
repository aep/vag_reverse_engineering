#include <p18cxxx.h>
#include <sw_spi.h>

/********************************************************************
*       Function Name:  OpenSWSPI                                   *
*       Return Value:   void                                        *
*       Parameters:     void                                        *
*       Description:    This routine configures the I/O pins for SPI*
*                       operation.                                  *
********************************************************************/
void OpenSWSPI (void)
{
        SW_CS_PIN = 1;          // Make the CS pin high
        SW_DIN_PIN = 1;         // Make the DIN pin high

#if defined(MODE0)              // Mode 0
        SW_DOUT_PIN = 0;        // Make the Dout and SCK pin low
        SW_SCK_PIN = 0;
#endif

#if defined(MODE1)              // Mode 1
        SW_DOUT_PIN = 0;        // Make the Dout pin low
        SW_SCK_PIN = 1;         // Make the SCK pin high
#endif

#if defined(MODE2)              // Mode 2
        SW_DOUT_PIN = 0;        // Make the Dout and SCK pins low
        SW_SCK_PIN = 0;
#endif

#if defined(MODE3)              // Mode3
        SW_DOUT_PIN = 0;        // Make the Dout pin low
        SW_SCK_PIN = 1;         // Make the SCK pin high
#endif

        TRIS_SW_CS_PIN = 0;     // Make the CS pin an output
        TRIS_SW_DIN_PIN = 1;    // Make the DIN pin an input
        TRIS_SW_DOUT_PIN = 0;   // Make the DOUT pin an output
        TRIS_SW_SCK_PIN = 0;    // Make the SCK pin an output
}

