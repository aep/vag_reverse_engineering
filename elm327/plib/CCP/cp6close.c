#include <p18cxxx.h>
#include <capture.h>

#if defined (CC_V8) || defined (CC_V8_1) || defined (CC_V8_3) || defined (CC_V8_4)
/********************************************************************
Function Prototype : void CloseCapture6(void)
 
Include            : capture.h
 
Description        : This function turns off the Input Capture module
 
Arguments          : None
 
Return Value       : None
 
Remarks            : This function disables the Input Capture interrupt 
                     and then turns off the module. The Interrupt                                  
********************************************************************/
void CloseCapture6(void)
{
   PIE4bits.CCP6IE = 0; // Disable the interrupt
   CCP6CON=0x00;        // Reset the CCP module
}
#endif
