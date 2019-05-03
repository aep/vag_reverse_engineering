#include <p18cxxx.h>
#include <usart.h>

/********************************************************************
*    Function Name:  DataRdyUSART                                   *
*    Return Value:   char                                           *
*    Parameters:     void                                           *
*    Description:    This routine checks the RCIF flag to see if    *
*                    any data has been received by the USART. It    *
*                    returns a 1 if data is available and a 0 if    *
*                    not.                                           *
********************************************************************/
#if defined (AUSART_V1) || defined (EAUSART_V3) || defined (EAUSART_V4) || defined (EAUSART_V5)
#undef DataRdyUSART
char DataRdyUSART(void)
{
  if(PIR1bits.RCIF)  // If RCIF is set
    return 1;  // Data is available, return TRUE
  return 0;  // Data not available, return FALSE
}

#endif
