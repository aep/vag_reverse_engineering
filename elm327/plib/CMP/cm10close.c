#include <p18cxxx.h>
#include <compare.h>


/********************************************************************
*    Function Name:    CloseCapture10                                *
*    Return Value:     void                                         *
*    Parameters:       void                                         *
*    Description:      This routine disables the capture interrupt. *
********************************************************************/
#if defined (CC_V8) || defined (CC_V8_3) 
void CloseCompare10(void)
{
   PIE4bits.CCP10IE = 0; // Disable the interrupt
   CCP10CON=0x00;        // Reset the CCP module
}

#endif
