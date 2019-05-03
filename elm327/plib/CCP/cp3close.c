#include <p18cxxx.h>
#include <capture.h>

#if defined (CC_V3) || defined (CC_V4)
/********************************************************************
Function Prototype : void CloseCapture3(void)
 
Include            : capture.h
 
Description        : This function turns off the Input Capture module
 
Arguments          : None
 
Return Value       : None
 
Remarks            : This function disables the Input Capture interrupt 
                     and then turns off the module. The Interrupt                                  
********************************************************************/
void CloseCapture3(void)
{
   PIE3bits.CCP3IE = 0; // Disable the interrupt
   CCP3CON=0x00;        // Reset the CCP module
}
#elif defined (CC_V8_2)
void CloseCapture3(void)
{
   PIE4bits.CCP3IE = 0; // Disable the interrupt
   CCP3CON=0x00;        // Reset the CCP module
}

#endif
