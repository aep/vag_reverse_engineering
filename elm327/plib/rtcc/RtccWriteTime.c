 
#include "rtcc.h"

#if defined (RTCC_V1) || defined (RTCC_V2)
/***********************************************************************************
  Function:        BOOL RtccWriteTime(const rtccTime* pTm, BOOL di)
 
  PreCondition:    pTm pointing to a valid rtccTime structure having proper values:
                        sec:  BCD codification, 00-59 
                        min:  BCD codification, 00-59
                        hour: BCD codification, 00-24
                       
  Input:           pTm - pointer to a constant rtccTime union
                   di - if interrupts need to be disabled
                   
  Output:          TRUE '1' : If all the values are within range
                   FALSE '0' : If any value is out of above mentioned range.
                   
  Side Effects:    None
  
  Overview:        The function updates the user supplied union/structure with
                   the current time and date of the RTCC device.
                   
  Note:            The write is successful only if Wr Enable is set.
                   The function will enable the write itself, if needed.
                   Also, the Alarm will be temporarily disabled and the
                   device will be stopped (On set to 0) in order
                   to safely perform the update of the RTC time register.
                   However, the device status will be restored.
                   Usually the disabling of the interrupts is desired, if the 
                   user has to have more precise control over the actual moment
                   of the time setting.
 ***********************************************************************************/
BOOL RtccWriteTime(const rtccTime* pTm , BOOL di)
{
   WORD_VAL tempHourWDay ;
   WORD_VAL tempMinSec ;
   

   BOOL        wasWrEn;
   BOOL        wasOn;
   BOOL        wasAlrm=FALSE;

   if((MAX_MIN < pTm->f.min )|| (MAX_SEC < pTm->f.sec) || (MAX_HOUR < pTm->f.hour))
   {
       return(FALSE);
   }

   tempMinSec.byte.HB = pTm->f.min;
   tempMinSec.byte.LB =pTm->f.sec;        // update the desired fields

   if(di)
   {
      /* Disable Interrupt */
      INTCONbits.PEIE = 0;
   }
   
   if(!(wasWrEn= mRtccIsWrEn()))
   {
       RtccWrOn();            // have to allow the WRTEN in order to write the new value
   }
   if(wasOn= mRtccIsOn())
   {
       wasAlrm= mRtccIsAlrmEnabled();
       mRtccOff();         // turn module off before updating the time
   }

   mRtccClearRtcPtr();
   mRtccSetRtcPtr(RTCCPTR_MASK_HRSWEEK);

   tempHourWDay.byte.LB = RTCVALL;
   tempHourWDay.byte.HB = RTCVALH;
   tempHourWDay.byte.LB = pTm->f.hour;


   mRtccClearRtcPtr();
   mRtccSetRtcPtr(RTCCPTR_MASK_HRSWEEK);

   RTCVALL = tempHourWDay.v[0];
   RTCVALH = tempHourWDay.v[1];
   RTCVALL = tempMinSec.v[0];
   RTCVALH = tempMinSec.v[1];

   if(wasOn)
   {
       mRtccOn();
       if(wasAlrm)
       {
           mRtccAlrmEnable();
       }
   
       if(wasWrEn)
       {
           RtccWrOn();
       }
   }
   else
   {
       if(!wasWrEn)
       {
           mRtccWrOff();
       }
   }
   
   if(di)
   {
      /* Enable Interrupt */
      INTCONbits.PEIE = 1;
   }
   

   return(TRUE);
}

//#else
//#warning "Selected device does not support this function"
#endif

