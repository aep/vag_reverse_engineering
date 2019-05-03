 
#include "rtcc.h"

#if defined (RTCC_V1) || defined (RTCC_V2)
/****************************************************************************************
  Function:        void RtccSetAlarmRptCount(UINT8 rptCnt, BOOL dsblAlrm)
 
  PreCondition:    rptCnt has to be a value less then 255 
  
  Input:           rptCnt - value of the desired alarm repeat rate 
                   dsblAlrm - if TRUE, the API can temporarily disable
                              the alarm when changing the RPT value 
  Output:          None
  
  Side Effects:    None
  
  Overview:        The function sets the RTCC alarm repeat rate.
  
  Note:            rptCnt will be truncated to fit into 8 bit representation.
                   If alarm is enabled, changing the repeat count can be safely made
                   only when the sync pulse is unasserted. To avoid waiting for the sync
                   pulse, the user can choose to temporarily disable the alarm and then
                   re-enable it. This means that the user has the knowledge that an alarm
                   event is not imminent.
 ****************************************************************************************/
void RtccSetAlarmRptCount(unsigned char rptCnt, BOOL dsblAlrm)
{
   BOOL isAlrm= mRtccIsAlrmEnabled();

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
   
   // update the repeat count value
   ALRMRPTbits.ARPT=rptCnt;

   // restore previous status
   if(isAlrm && dsblAlrm)
   {
       mRtccAlrmEnable();
   }
   
}

//#else
//#warning "Selected device does not support this function"
#endif

