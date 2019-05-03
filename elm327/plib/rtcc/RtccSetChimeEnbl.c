 
#include "rtcc.h"

#if defined (RTCC_V1) || defined (RTCC_V2)
/****************************************************************************************
 Function:        void RtccSetChimeEnable(BOOL enable, BOOL dsblAlrm)
 
 PreCondition:    None
 
 Input:           enable - boolean to enable/disable the RTCC chime
                  dsblAlrm - if TRUE, the API can temporarily disable
                             the alarm when changing the Chime status 
 Output:          None
 
 Side Effects:    None
 
 Overview:        The function enables/disables the chime alarm of the RTCC device.
 
 Note:            If alarm is enabled, changing the chime status can be safely made
                  when the sync pulse is unasserted. To avoid waiting for the sync
                  pulse, the user can choose to temporarily disable the alarm and then
                  re-enable it. This means that the user has knowledge that an alarm
                  event is not imminent.                  
 *****************************************************************************************/
void RtccSetChimeEnable(BOOL enable, BOOL dsblAlrm)
{
   BOOL    isAlrm=mRtccIsAlrmEnabled();

   if(isAlrm)
   {
       if(dsblAlrm)
       {
           mRtccAlrmDisable();
       }
       else
       {
           mRtccWaitSync();
       }
   }

   // update the chime status
   ALRMCFGbits.CHIME=enable;

   // restore previous status
   if(isAlrm && dsblAlrm)
   {
       mRtccAlrmEnable();
   }
}

//#else
//#warning "Selected device does not support this function"
#endif

