#include <p18cxxx.h>
#include <capture.h>


/********************************************************************
*    Function Name:    CloseCapture2                                *
*    Return Value:     void                                         *
*    Parameters:       void                                         *
*    Description:      This routine disables the capture interrupt. *
********************************************************************/

#if defined (CC_V2) || defined (CC_V3) || defined (CC_V4) ||\
    defined (CC_V7) || defined (CC_V8_5)
/********************************************************************
Function Prototype : void CloseCapture2(void)
 
Include            : capture.h
 
Description        : This function turns off the Input Capture module
 
Arguments          : None
 
Return Value       : None
 
Remarks            : This function disables the Input Capture interrupt 
                     and then turns off the module. The Interrupt                                  
********************************************************************/
void CloseCapture2(void)
{
   PIE2bits.CCP2IE = 0; // Disable the interrupt
   CCP2CON=0x00;        // Reset the CCP module
}
#elif defined (CC_V6) || defined (CC_V8_2)
/********************************************************************
Function Prototype : void CloseCapture2(void)
 
Include            : capture.h
 
Description        : This function turns off the Input Capture module
 
Arguments          : None
 
Return Value       : None
 
Remarks            : This function disables the Input Capture interrupt 
                     and then turns off the module. The Interrupt                                  
********************************************************************/
void CloseCapture2(void)
{
   PIE3bits.CCP2IE = 0; // Disable the interrupt
   CCP2CON=0x00;        // Reset the CCP module
}
#endif
