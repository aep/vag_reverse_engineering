 
#include "rtcc.h"

#if defined (RTCC_V1) || defined (RTCC_V2)
/*********************************************************************
  Function:        BOOL RtccWriteAlrmTimeDate(const rtccTimeDate* pTD)
 
  PreCondition:    rtccTimeDate structure fields have to have proper values:
                        sec:  BCD codification, 00-59 
                        min:  BCD codification, 00-59
                        hour: BCD codification, 00-24
                        wday: BCD codification, 00-06 
                        mday: BCD codification, 01-31
                        mon: BCD codification, 01-12
 
  Input:           pTD - pointer to a constant rtccTimeDate union
 
  Output:          TRUE '1' : If all the values are within range
                   FALSE '0' : If any value is out of above mentioned range.
 
  Side Effects:    None
 
  Overview:        The function sets the current alarm time and date in the RTCC device.
 
  Note:            Note that the alarm time does not contain a year field.
 ********************************************************************/
BOOL RtccWriteAlrmTimeDate(const rtccTimeDate* pTD)
{
    BOOL    wasWrEn;
    BOOL    wasAlrm;

   if((MAX_MIN < pTD->b[7]) || (MAX_SEC < pTD->b[6]) || (MAX_WDAY < pTD->b[5]) || (MAX_HOUR < pTD->b[4]) || 
      (MAX_MON < pTD->b[3]) || (MIN_MON > pTD->b[3]) || (MAX_MDAY < pTD->b[2]) || (MIN_MDAY > pTD->b[2]) )
   {
       return FALSE;
   }

   if(!(wasWrEn=mRtccIsWrEn()))
   {
       RtccWrOn();            // have to allow the WRTEN in order to write the new value
   }
   if(wasAlrm=mRtccIsAlrmEnabled())
   {
       mRtccAlrmDisable();     // avoid spurious alarm interrupts
   }


   mRtccClearAlrmPtr();
   mRtccSetAlrmPtr(RTCCPTR_MASK_DAYMON);

//   ALRMVAL=pTD->w[0];  // dummy write /* not required since alarm pointer is set to '0b10' */
   ALRMVALL=pTD->b[2];
   ALRMVALH=pTD->b[3];
   ALRMVALL=pTD->b[4];
   ALRMVALH=pTD->b[5];
   ALRMVALL=pTD->b[6];
   ALRMVALH=pTD->b[7];   

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

