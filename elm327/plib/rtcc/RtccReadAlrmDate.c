 
#include "rtcc.h"

#if defined (RTCC_V1) || defined (RTCC_V2)
 /*********************************************************************
  Function:        void RtccReadAlrmDate(rtccDate* pDt)

  PreCondition:    pDt a valid pointer
 
  Input:           pDt - pointer to a rtccDate union to store the alarm Date
 
  Output:          None
 
  Side Effects:    None
 
  Overview:        The function updates the user supplied union/structure with
                   the current alarm Date of the RTCC device. 
 ********************************************************************/
void RtccReadAlrmDate(rtccDate* pDt)
{
   rtccTimeDate rTD;

   mRtccClearAlrmPtr();
   mRtccSetAlrmPtr(RTCCPTR_MASK_DAYMON);

   rTD.b[2]=ALRMVALL;
   rTD.b[3]=ALRMVALH;
   rTD.b[4]=ALRMVALL;
   rTD.b[5]=ALRMVALH;
   

   pDt->f.mday = rTD.f.mday;
   pDt->f.mon = rTD.f.mon;
   pDt->f.wday = rTD.f.wday;    // update user's data
}

//#else
//#warning "Selected device does not support this function"
#endif

