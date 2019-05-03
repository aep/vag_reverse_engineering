#include <p18cxxx.h>
#include <compare.h>


/********************************************************************
*    Function Name:   CloseECompare1                                *
*    Return Value:    void                                          *
*    Parameters:      void                                          *
*    Description:     This routine disables the capture interrupt.  *
********************************************************************/
#if defined (ECC_V5)

void CloseECompare1(void)
{
   #if defined ECCP1_IO_V5
    PIE1bits.CCP1IE = 1;   // Enable the interrupt
	#else 
	PIE2bits.ECCP1IE = 0;    // Disable the interrupt
	#endif
   ECCP1CON=0x00;           // Reset the CCP module
}

#elif defined (ECC_V8) || defined (ECC_V8_1) || defined (ECC_V8_2)\
|| defined (ECC_V8_3) || defined (ECC_V8_4) || defined (ECC_V8_5) || defined (ECC_V9)|| defined (ECC_V9_1)

void CloseECompare1(void)
{
#if defined(CC4_IO_V2) || defined (CC9_IO_V1)
   PIE1bits.CCP1IE = 0;    // Disable the interrupt
#else  
   PIE3bits.CCP1IE = 0;    // Disable the interrupt
#endif
   
   #if defined (ECC_V8_3) || defined (ECC_V8_4) || defined (ECC_V8_5)
   CCP1CON=0x00;           // Reset the CCP module
   #else
   ECCP1CON=0x00;           // Reset the CCP module
   #endif
}

#endif
