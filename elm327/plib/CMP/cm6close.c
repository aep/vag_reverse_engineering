#include <p18cxxx.h>
#include <compare.h>


/********************************************************************
*    Function Name:    CloseCapture6                                *
*    Return Value:     void                                         *
*    Parameters:       void                                         *
*    Description:      This routine disables the capture interrupt. *
********************************************************************/
#if defined (CC_V8) || defined (CC_V8_1) || defined (CC_V8_3) || defined (CC_V8_4)
void CloseCompare6(void)
{
   PIE4bits.CCP6IE = 0; // Disable the interrupt
   CCP6CON=0x00;        // Reset the CCP module
}

#endif
