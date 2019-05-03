#include <p18cxxx.h>
#include <compare.h>


/********************************************************************
*    Function Name:    CloseCompare2                                *
*    Return Value:     void                                         *
*    Parameters:       void                                         *
*    Description:      This routine disables the compare interrupt. *
********************************************************************/
#if defined (CC_V2 ) || defined ( CC_V3 ) || defined ( CC_V4 ) || defined (CC_V7) || defined (CC_V8_5)

void CloseCompare2(void)
{
   PIE2bits.CCP2IE = 0; // Disable the interrupt
   CCP2CON=0x00;        // Reset the CCP module
}
#elif defined ( CC_V6 )  || defined (CC_V8_2)

void CloseCompare2(void)
{ 
   PIE3bits.CCP2IE = 0; // Disable the interrupt
   CCP2CON=0x00;        // Reset the CCP module
}
#endif
