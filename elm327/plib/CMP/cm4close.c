#include <p18cxxx.h>
#include <compare.h>


/********************************************************************
*    Function Name:    CloseCapture4                                *
*    Return Value:     void                                         *
*    Parameters:       void                                         *
*    Description:      This routine disables the capture interrupt. *
********************************************************************/
#if defined (CC_V4)

void CloseCompare4(void)
{
   PIE3bits.CCP4IE = 0; // Disable the interrupt
   CCP4CON=0x00;        // Reset the CCP module
}

#elif defined (CC_V8) || defined (CC_V8_1) || defined (CC_V8_2) || defined (CC_V8_3) \
	|| defined (CC_V8_4) || defined (ECC_V9)|| defined (ECC_V9_1)
void CloseCompare4(void)
{
   PIE4bits.CCP4IE = 0; // Disable the interrupt
   CCP4CON=0x00;        // Reset the CCP module
}

#endif
