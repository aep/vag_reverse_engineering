 
#include "rtcc.h"

#if defined (RTCC_V1) || defined (RTCC_V2)
 /*********************************************************************
  Function:        void RtccReadAlrmTime(rtccTime* pTm)
 
  PreCondition:    pTm a valid pointer
 
  Input:           pTm - pointer to a rtccTime union to store the alarm time
 
  Output:          None
 
  Side Effects:    None
 
  Overview:        The function updates the user supplied union/structure with
                   the current alarm time of the RTCC device.
 ********************************************************************/
void RtccReadAlrmTime(rtccTime* pTm)
{
   rtccTimeDate rTD;

   mRtccClearAlrmPtr();
   mRtccSetAlrmPtr(RTCCPTR_MASK_HRSWEEK);

   rTD.b[4]=ALRMVALL;
   rTD.b[5]=ALRMVALH;
   rTD.b[6]=ALRMVALL;
   rTD.b[7]=ALRMVALH;  // read the user value

   pTm->f.hour=rTD.f.hour;
   pTm->f.min=rTD.f.min;
   pTm->f.sec=rTD.f.sec;    // update user's data
}

//#else
//#warning "Selected device does not support this function"
#endif

