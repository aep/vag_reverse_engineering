#include <p18cxxx.h>
#include <timers.h>

/********************************************************************
    Function Name:  SetTmrCCPSrc     
                               
    Return Value:    void                                          

    Parameters:      config: bit definitions to configure Timer as a clock source to CCP module    

    Description:     This routine configures the timer to work as a clock source to CCP module.
                           Required timer has to be enabled by calling respective function.
  
    Notes:             The bit definitions for config can be found in the timers.h file.                         
********************************************************************/
#if defined (TMR_V2) || defined (TMR_V4) 
void SetTmrCCPSrc(unsigned char config)
{
  T3CON  = T3CON & 0xB7 ;
  T3CON  = T3CON | (config & 0x48); // Timer to CCPx enable  
}
#endif

#if defined (TMR_V6)
void SetTmrCCPSrc(unsigned char config)
{
 TCLKCON = TCLKCON & 0xFC;
 TCLKCON = TCLKCON | (config & 0x03);
}
#endif
