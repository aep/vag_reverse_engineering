#include <p18cxxx.h>
#include <capture.h>

#if defined (CC_V8) || defined (CC_V8_1) || defined (CC_V8_3) || defined (CC_V8_4)
/********************************************************************
Function Prototype : void CloseCapture7(void)
 
Include            : capture.h
 
Description        : This function turns off the Input Capture module
 
Arguments          : None
 
Return Value       : None
 
Remarks            : This function disables the Input Capture interrupt 
                     and then turns off the module. The Interrupt                                  
********************************************************************/
void CloseCapture7(void)
{
   PIE4bits.CCP7IE = 0; // Disable the interrupt
   CCP7CON=0x00;        // Reset the CCP module
}
#endif
