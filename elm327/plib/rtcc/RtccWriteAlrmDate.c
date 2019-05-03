 
#include "rtcc.h"

#if defined (RTCC_V1) || defined (RTCC_V2)
/*********************************************************************
 Function:        void RtccWriteAlrmDate(const rtccDate* pDt)
 
 PreCondition:    pDt a valid rtccDate pointer having proper values:
                      wday: BCD codification, 00-06 
                      mday: BCD codification, 01-31
                      mon: BCD codification, 01-12
 
 Input:           pDt - pointer to a constant rtccDate union
 
 Output:          None
 
 Side Effects:    None
 
 Overview:        The function sets the alarm date in the RTCC device.
 
 Note:            The write is successful only if Wr Enable is set.
                  The function will enable the write itself, if needed.
                  Also, the Alarm will be temporarily disabled in order
                  to safely perform the update of the ALRMTIME register.
                  However, the device status will be restored. 
                  Note that the alarm date does not contain a year field.
 ********************************************************************/
BOOL RtccWriteAlrmDate(const rtccDate* pDt)
{
   WORD_VAL tempHourWDay ;
   WORD_VAL tempDayMonth ;

   BOOL    wasWrEn;
   BOOL    wasAlrm;

   if((MAX_MON < pDt->f.mon) || (MIN_MON > pDt->f.mon) || (MAX_MDAY < pDt->f.mday) || (MIN_MDAY > pDt->f.mday) || 
      (MAX_YEAR < pDt->f.year))
   {
       return FALSE;
   }

   tempDayMonth.byte.LB = pDt->f.mday;
   tempDayMonth.byte.HB = pDt->f.mon;

   if(!(wasWrEn=mRtccIsWrEn()))
   {
       RtccWrOn();            // have to allow the WRTEN in order to write the new value
   }
   if(wasAlrm=mRtccIsAlrmEnabled())
   {
       mRtccAlrmDisable();     // avoid spurious alarm interrupts
   }

   mRtccClearAlrmPtr();
   mRtccSetAlrmPtr(RTCCPTR_MASK_HRSWEEK);

   tempHourWDay.v[0] = ALRMVALL;
   tempHourWDay.v[1] = ALRMVALH;
   tempHourWDay.byte.LB = pDt->f.wday;

   mRtccClearRtcPtr();
   mRtccSetRtcPtr(RTCCPTR_MASK_DAYMON);

   ALRMVALL =tempDayMonth.v[0];
   ALRMVALH =tempDayMonth.v[1];
   ALRMVALL = tempHourWDay.v[0];
   ALRMVALH = tempHourWDay.v[1];

   if(wasAlrm)
   {
       mRtccAlrmEnable();
   }
   if(!wasWrEn)
   {
       mRtccWrOff();
   }

   return(TRUE);
}

//#else
//#warning "Selected device does not support this function"
#endif

