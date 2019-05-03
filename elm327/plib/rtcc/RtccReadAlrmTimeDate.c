 
#include "rtcc.h"

#if defined (RTCC_V1) || defined (RTCC_V2)
 /*********************************************************************
  Function:        void RtccReadAlrmTimeDate(rtccTimeDate* pTD)
 
  PreCondition:    None 
 
  Input:           pTD - pointer to a rtccTimeDate union to store the alarm time and date
 
  Output:          None
 
  Side Effects:    None
 
  Overview:        The function updates the user supplied union/structure with
                   the current alarm time and date of the RTCC device.
 
  Note:            None
 ********************************************************************/
void RtccReadAlrmTimeDate(rtccTimeDate* pTD)
{
   mRtccClearAlrmPtr();
   mRtccSetAlrmPtr(RTCCPTR_MASK_DAYMON);

//   pTD->w[0]=ALRMVAL;  // dummy read /* not required since alarm pointer is set to '0b10' */
   pTD->b[2]=ALRMVALL;
   pTD->b[3]=ALRMVALH;
   pTD->b[4]=ALRMVALL;
   pTD->b[5]=ALRMVALH;
   pTD->b[6]=ALRMVALL;
   pTD->b[7]=ALRMVALH;   
  // read the user value
}

// #else
// #warning "Selected device does not support this function"
#endif

