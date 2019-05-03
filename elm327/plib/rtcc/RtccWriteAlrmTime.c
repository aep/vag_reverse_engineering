 
#include "rtcc.h"

#if defined (RTCC_V1) || defined (RTCC_V2)
/*********************************************************************
  Function:        void RtccWriteAlrmTime(const rtccTime* pTm)
 
  PreCondition:    pTm a valid rtccTime pointer having proper values:
                       sec:  BCD codification, 00-59 
                       min:  BCD codification, 00-59
                       hour: BCD codification, 00-24
 
  Input:           pTm - pointer to a constant rtccTime union
 
  Output:          None
 
  Side Effects:    None
 
  Overview:        The function sets the current time in the RTCC device.
 
  Note:            The write is successful only if Wr Enable is set.
                   The function will enable the write itself, if needed.
                   Also, the Alarm will be temporarily disabled in order
                   to safely perform the update of the ALRMTIME register.
                   However, the device status will be restored.
 ********************************************************************/
BOOL RtccWriteAlrmTime(const rtccTime* pTm)
{
   WORD_VAL tempHourWDay ;
   WORD_VAL tempMinSec ;

   BOOL    wasWrEn;
   BOOL    wasAlrm;

   if((MAX_MIN < pTm->f.min)|| (MAX_SEC < pTm->f.sec) || (MAX_HOUR < pTm->f.hour))
   {
       return FALSE;
   }

   tempMinSec.byte.HB = pTm->f.min;
   tempMinSec.byte.LB =pTm->f.sec;        // update the desired fields

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
   tempHourWDay.byte.LB = pTm->f.hour;

   mRtccClearAlrmPtr();
   mRtccSetAlrmPtr(RTCCPTR_MASK_HRSWEEK);

   ALRMVALL = tempHourWDay.v[0];
   ALRMVALH = tempHourWDay.v[1];
   ALRMVALL = tempMinSec.v[0];
   ALRMVALH = tempMinSec.v[1];

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

