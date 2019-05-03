 
#include "rtcc.h"

#if defined (RTCC_V1) || defined (RTCC_V2)
 /*********************************************************************
 Function:        void RtccInitClock(void)

 PreCondition:    None
                  
 Input:           None
 
 Output:          None
 
 Side Effects:    Enables the secondary oscillator from Timer1
 
 Overview:        The function initializes the RTCC device. It starts the RTCC clock,
                  sets the RTCC Off and disables RTCC write. Disables the OE.
                   
 Note:            None
 ********************************************************************/
void RtccInitClock(void)
{
   // enable the Secondary Oscillator
#if defined (RTCC_SFR_V1)
	T1CONbits.SOSCEN = 1;
#else   
   T1CONbits.T1OSCEN = 1;
#endif

#if defined (RTCC_V1)
   RTCCFG = 0x0;
#else
    RTCCON1=0x0;
#endif
 	
   RTCCAL = 0x00;
   if(mRtccIsOn())
   {
      if(!mRtccIsWrEn())
      {
          RtccWrOn();
      }
       mRtccOff();
   }
   
   mRtccWrOff();
}

//#else
////#warning "Selected device does not support this function"
#endif

