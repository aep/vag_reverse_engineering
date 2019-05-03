 
#include "rtcc.h"

#if defined (RTCC_V1) || defined (RTCC_V2)
 /*********************************************************************
  Function:        void RtccReadDate(rtccDate* pDt)

  PreCondition:    pDt a valid pointer
 
  Input:           pDt - pointer to a rtccTime union to store the current time
 
  Output:          None
 
  Side Effects:    None
 
  Overview:        The function updates the user supplied union/structure with
                   the current time of the RTCC device.
 
  Note:            The function makes sure that the read value is valid.
                   It avoids waiting for the RTCSYNC to be clear by 
                   performing successive reads.
 ********************************************************************/
void RtccReadDate(rtccDate* pDt)
{
   rtccTimeDate rTD0, rTD1;
   do
   {
      mRtccClearRtcPtr();
      mRtccSetRtcPtr(RTCCPTR_MASK_YEAR);

      rTD0.b[0]=RTCVALL;
	  rTD0.b[1]=RTCVALH;
	  rTD0.b[2]=RTCVALL;
	  rTD0.b[3]=RTCVALH;
	  rTD0.b[4]=RTCVALL;
	  rTD0.b[5]=RTCVALH;

   
      mRtccClearRtcPtr();
      mRtccSetRtcPtr(RTCCPTR_MASK_YEAR);

      rTD1.b[0]=RTCVALL;
	  rTD1.b[1]=RTCVALH;
	  rTD1.b[2]=RTCVALL;
	  rTD1.b[3]=RTCVALH;
	  rTD1.b[4]=RTCVALL;
	  rTD1.b[5]=RTCVALH;

   }while(rTD0.f.mday!=rTD1.f.mday); // make sure you have the month day

   pDt->f.mday=rTD0.f.mday;
   pDt->f.mon=rTD0.f.mon;
   pDt->f.wday=rTD0.f.wday;
   pDt->f.year=rTD0.f.year;
}

//#else
//#warning "Selected device does not support this function"
#endif

