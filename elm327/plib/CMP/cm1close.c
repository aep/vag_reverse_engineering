#include <p18cxxx.h>
#include <compare.h>


/********************************************************************
*    Function Name:   CloseCompare1                                 *
*    Return Value:    void                                          *
*    Parameters:      void                                          *
*    Description:     This routine disables the compare interrupt.  *
********************************************************************/

#if defined (CC_V1) || defined (CC_V2) || defined (CC_V3) || defined (CC_V4) || defined (CC_V5) || defined (CC_V7)
void CloseCompare1(void)
{
   PIE1bits.CCP1IE = 0;    // Disable the interrupt
   CCP1CON=0x00;           // Reset the CCP module
}

#elif defined (CC_V6)
void CloseCompare1(void)
{
   PIE3bits.CCP1IE = 0;    // Disable the interrupt
   CCP1CON=0x00;           // Reset the CCP module
}

#endif
