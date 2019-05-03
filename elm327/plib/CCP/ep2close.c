#include <p18cxxx.h>
#include <capture.h>

#if defined (ECC_V8) || defined (ECC_V8_1) || defined (ECC_V8_3) || defined (ECC_V8_4)\
	|| defined (ECC_V9)|| defined (ECC_V9_1)
/********************************************************************
Function Prototype : void CloseECapture2(void)
 
Include            : capture.h
 
Description        : This function turns off the Input Capture module
 
Arguments          : None
 
Return Value       : None
 
Remarks            : This function disables the Input Capture interrupt 
                     and then turns off the module. The Interrupt                                  
********************************************************************/
void CloseECapture2(void)
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
