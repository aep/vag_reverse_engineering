 
#include "rtcc.h"

#if defined (RTCC_V1) || defined (RTCC_V2)
/*********************************************************************
  Function:        void RtccWrOn(void)
 
  PreCondition:    None
 
  Input:           None
 
  Output:          None
 
  Side Effects:    None
 
  Overview:        Function to set the RTCCFG.RTCWREN
 
  Note:            The interrupts are disabled in order to have a proper 
                   device initialization
 ********************************************************************/
void RtccWrOn(void)
{
   unsigned int data;

/* Disable Interrupt */
   INTCONbits.PEIE = 0;

#ifdef _OMNI_CODE_
    EECON2 = 0x55;
    EECON2 = 0xAA;
#else
	_asm movlw 0x55 _endasm
	_asm movwf EECON2,0 _endasm
	_asm movlw 0xAA _endasm
	_asm movwf EECON2,0 _endasm
#endif

   #if defined (RTCC_V1)   
   RTCCFGbits.RTCWREN=1;  
   #else 
   RTCCON1bits.RTCWREN=1;
   #endif

/* Enable Interrupt */
   INTCONbits.PEIE = 1;
}

//#else
//#warning "Selected device does not support this function"
#endif

