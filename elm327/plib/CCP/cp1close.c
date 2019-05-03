#include <p18cxxx.h>
#include <capture.h>


#if defined (CC_V1) || defined (CC_V2) || defined (CC_V3) || \
    defined (CC_V4) || defined (CC_V5) || defined (CC_V7) 
/********************************************************************
Function Prototype : void CloseCapture1(void)
 
Include            : capture.h
 
Description        : This function turns off the Input Capture module
 
Arguments          : None
 
Return Value       : None
 
Remarks            : This function disables the Input Capture interrupt 
                     and then turns off the module.                        
********************************************************************/
void CloseCapture1(void)
{
   PIE1bits.CCP1IE = 0;    // Disable the interrupt
   CCP1CON=0x00;           // Reset the CCP module
}

#elif defined (CC_V6) 
/********************************************************************
Function Prototype : void CloseCapture1(void)
 
Include            : capture.h
 
Description        : This function turns off the Input Capture module
 
Arguments          : None
 
Return Value       : None
 
Remarks            : This function disables the Input Capture interrupt 
                     and then turns off the module.                          
********************************************************************/
void CloseCapture1(void)
{
   PIE3bits.CCP1IE = 0;    // Disable the interrupt
   CCP1CON=0x00;           // Reset the CCP module
}

#endif
