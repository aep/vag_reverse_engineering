 
#include "rtcc.h"

#if defined (RTCC_V1) || defined (RTCC_V2)
/*********************************************************************
  Function:        void RtccSetAlarmRpt(rtccRepeat rpt, BOOL dsblAlrm)

  PreCondition:    rpt has to be a proper rtccRepeat enumeration value 
 
  Input:           rpt - value of the desired alarm repeat rate 
                   dsblAlrm - if TRUE, the API can temporarily disable
                              the alarm when changing the RPT value 
  Output:          None
  
  Side Effects:    None
  
  Overview:        The function sets the RTCC alarm repeat count.
  
  Note:            If alarm is enabled, changing the repeat count can be safely made
                   only when the sync pulse is unasserted. To avoid waiting for the sync
                   pulse, the user can choose to temporarily disable the alarm and then
                   re-enable it. This means that the user has the knowledge that an alarm
                   event is not imminent.
 ********************************************************************/
void RtccSetAlarmRpt(rtccRepeat rpt, BOOL dsblAlrm)
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

   // update the repeat rate
   ALRMCFGbits.AMASK=rpt;
       
   // restore previous status
   if(isAlrm && dsblAlrm)
   {
       mRtccAlrmEnable();
   }
}

//#else
//#warning "Selected device does not support this function"
#endif

