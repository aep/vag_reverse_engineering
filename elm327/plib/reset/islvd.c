#include <p18cxxx.h>
#include <reset.h>

#if defined (LVD_V1)
/********************************************************************
*       Function Name:  isLVD                                       *
*       Return Value:   char                                        *
*       Parameters:     void                                        *
*       Description:    This routine determines if a low voltage    *
*                       condition occurred.                         *
*********************************************************************/
char isLVD()
{
   if(PIR2bits.LVDIF)
      return 1;
   else
      return 0;
}
#endif
