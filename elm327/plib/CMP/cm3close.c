#include <p18cxxx.h>
#include <compare.h>


/********************************************************************
*    Function Name:    CloseCapture3                                *
*    Return Value:     void                                         *
*    Parameters:       void                                         *
*    Description:      This routine disables the capture interrupt. *
********************************************************************/
#if defined (CC_V3 ) || defined ( CC_V4)
void CloseCompare3(void)
{
   PIE3bits.CCP3IE = 0; // Disable the interrupt
   CCP3CON=0x00;        // Reset the CCP module
}
#elif defined (CC_V8_2)
void CloseCompare3(void)
{
   PIE4bits.CCP3IE = 0; // Disable the interrupt
   CCP3CON=0x00;        // Reset the CCP module
}

#endif
