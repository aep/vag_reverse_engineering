#include <p18cxxx.h>
#include <compare.h>


/********************************************************************
*    Function Name:   CloseECompare2                               *
*    Return Value:    void                                          *
*    Parameters:      void                                          *
*    Description:     This routine disables the capture interrupt.  *
********************************************************************/
#if defined (ECC_V8) || defined (ECC_V8_1) || defined (ECC_V8_3) || \
	defined (ECC_V8_4)|| defined (ECC_V9)|| defined (ECC_V9_1)

void CloseECompare2(void)
{
#if defined(CC4_IO_V2) || defined (CC9_IO_V1)
   PIE2bits.CCP2IE = 0;    // Disable the interrupt
#else  
   PIE3bits.CCP2IE = 0;    // Disable the interrupt
#endif
    
	#if defined (ECC_V8_3) || defined (ECC_V8_4)
   CCP2CON=0x00;           // Reset the CCP module
   #else
   ECCP2CON=0x00;           // Reset the CCP module
   #endif
}

#endif
