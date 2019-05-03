#include <p18cxxx.h>
#include <sw_spi.h>

/********************************************************************
*       Function Name:  SetCSSWSPI                                  *
*       Return Value:   void                                        *
*       Parameters:     void                                        *
*       Description:    This routine sets the CS pin high.          *
********************************************************************/
void SetCSSWSPI(void)
{
        SW_CS_PIN = 1;                  // Set the CS pin high
}
