#include <p18cxxx.h>
#include <compare.h>


/********************************************************************
*    Function Name:    CloseCapture7                                *
*    Return Value:     void                                         *
*    Parameters:       void                                         *
*    Description:      This routine disables the capture interrupt. *
********************************************************************/
#if defined (CC_V8) || defined (CC_V8_1) || defined (CC_V8_3) || defined (CC_V8_4)
void CloseCompare7(void)
{
   PIE4bits.CCP7IE = 0; // Disable the interrupt
   CCP7CON=0x00;        // Reset the CCP module
}

#endif
