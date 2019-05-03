 
#include "rtcc.h"

#if defined (RTCC_V1) || defined (RTCC_V2)
 /*********************************************************************
  Function:        void RtccReadTime(rtccTime *pTm)
 
  PreCondition:    pTm a valid pointer
 
  Input:           pTm - pointer to a rtccTime union to store the current time
  
  Output:          None
  
  Side Effects:    None
  
  Overview:        The function updates the user supplied union/structure with
                   the current time of the RTCC device.
  
  Note:            The function makes sure that the read value is valid.
                   It avoids waiting for the RTCSYNC to be clear by 
                   performing successive reads.
 ********************************************************************/
void RtccReadTime(rtccTime* pTm)
{
   rtccTimeDate rTD0, rTD1;

   do
   {
      mRtccClearRtcPtr();
      mRtccSetRtcPtr(RTCCPTR_MASK_HRSWEEK);

      rTD0.b[4]=RTCVALL;
	  rTD0.b[5]=RTCVALH;
	  rTD0.b[6]=RTCVALL;
	  rTD0.b[7]=RTCVALH;
         // read the user value
   
      mRtccClearRtcPtr();
      mRtccSetRtcPtr(RTCCPTR_MASK_HRSWEEK);
   
      rTD1.b[4]=RTCVALL;
	  rTD1.b[5]=RTCVALH;
	  rTD1.b[6]=RTCVALL;
	  rTD1.b[7]=RTCVALH;    // read the user value

   }while(rTD0.f.sec!=rTD1.f.sec); // make sure you have the same sec

   pTm->f.hour=rTD0.f.hour;
   pTm->f.min=rTD0.f.min;
   pTm->f.sec=rTD0.f.sec;    // update user's data

}

//#else
//#warning "Selected device does not support this function"
#endif

