 
#include "rtcc.h"

#if defined (RTCC_V1) || defined (RTCC_V2)
/*********************************************************************
  Function:        void RtccReadTimeDate(rtccTimeDate* pTD)
 
  PreCondition:    None
 
  Input:           pTD - pointer to a rtccTimeDate union to store the current 
                        time and date
  Output:          None
  
  Side Effects:    None
  
  Overview:        The function updates the user supplied union/structure with
                   the current time and date of the RTCC device.
 
  Note:            This firmware solution would consist of reading each       
                   register twice and then comparing the two values. If the   
                   two values match, then a rollover did not occur.
 ********************************************************************/
void RtccReadTimeDate(rtccTimeDate* pTD)
{
   rtccTimeDate	currTD;
   do
   {
      mRtccClearRtcPtr();
      mRtccSetRtcPtr(RTCCPTR_MASK_YEAR);

      pTD->b[0]=RTCVALL;
	  pTD->b[1]=RTCVALH;
      pTD->b[2]=RTCVALL;
	  pTD->b[3]=RTCVALH;
      pTD->b[4]=RTCVALL;
	  pTD->b[5]=RTCVALH;
      pTD->b[6]=RTCVALL;
	  pTD->b[7]=RTCVALH;
    // read the user value
   
      mRtccClearRtcPtr();
      mRtccSetRtcPtr(RTCCPTR_MASK_YEAR);
   
      currTD.b[0]=RTCVALL;
	  currTD.b[1]=RTCVALH;
      currTD.b[2]=RTCVALL;
	  currTD.b[3]=RTCVALH;
      currTD.b[4]=RTCVALL;
	  currTD.b[5]=RTCVALH;
      currTD.b[6]=RTCVALL;
	  currTD.b[7]=RTCVALH;	  
    // read the user value

   }while(pTD->f.sec!=currTD.f.sec);	// make sure you have the same sec
}

//#else
//#warning "Selected device does not support this function"
#endif

