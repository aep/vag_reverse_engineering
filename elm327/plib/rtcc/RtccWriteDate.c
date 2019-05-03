 
#include "rtcc.h"

#if defined (RTCC_V1) || defined (RTCC_V2)
/***********************************************************************************
  Function:        BOOL RtccWriteDate(const rtccDate* pDt, BOOL di)
 
  PreCondition:    pDt is a valid rtccDate pointer having proper values:
                        wday: BCD codification, 00-06 
                        mday: BCD codification, 01-31
                        mon: BCD codification, 01-12
                        year: BCD codification, 00-99
 
  Input:           pDt - pointer to a constant rtccDate union
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
 *************************************************************************************/
BOOL RtccWriteDate(const rtccDate* pDt , BOOL di)
{
   WORD_VAL tempHourWDay ;
   WORD_VAL tempDayMonth ;
   WORD_VAL tempYear ;

   BOOL        wasWrEn;
   BOOL        wasOn;
   BOOL        wasAlrm=FALSE;

   if((MAX_MON < pDt->f.mon) || (MIN_MON > pDt->f.mon) || (MAX_MDAY < pDt->f.mday) || (MIN_MDAY > pDt->f.mday) || 
      (MAX_YEAR < pDt->f.year))
   {
       return(FALSE);
   }

   tempYear.byte.LB = pDt->f.year;
   tempDayMonth.byte.LB = pDt->f.mday;
   tempDayMonth.byte.HB = pDt->f.mon;

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

   tempHourWDay.v[0] = RTCVALL;
   tempHourWDay.v[1] = RTCVALH;
   tempHourWDay.byte.HB = pDt->f.wday;

   mRtccClearRtcPtr();
   mRtccSetRtcPtr(RTCCPTR_MASK_YEAR);


   RTCVALL=tempYear.v[0];
   RTCVALH=tempYear.v[1];
   RTCVALL=tempDayMonth.v[0];
   RTCVALH=tempDayMonth.v[1];
   RTCVALL=tempHourWDay.v[0];
   RTCVALH=tempHourWDay.v[1];

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
     INTCONbits.PEIE = 0;
   }
   

   return(TRUE);
}

//#else
//#warning "Selected device does not support this function"
#endif


