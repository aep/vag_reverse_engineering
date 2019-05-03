#include <p18cxxx.h>
#include <capture.h>

#if defined (ECC_V8) || defined (ECC_V8_1)|| defined (ECC_V8_3) || defined (ECC_V8_4)\
	|| defined (ECC_V9)|| defined (ECC_V9_1)
/********************************************************************
Function Prototype : void CloseECapture3(void)
 
Include            : capture.h
 
Description        : This function turns off the Input Capture module
 
Arguments          : None
 
Return Value       : None
 
Remarks            : This function disables the Input Capture interrupt 
                     and then turns off the module. The Interrupt                                  
********************************************************************/
void CloseECapture3(void)
{
   #if defined (ECC_V8_3) || defined (ECC_V8_4)
   PIE4bits.ECCP3IE = 0;    // Disable the interrupt
   #else
   PIE4bits.CCP3IE = 0;    // Disable the interrupt
   #endif
   CCP3CON=0x00;           // Reset the CCP module
}

#endif
