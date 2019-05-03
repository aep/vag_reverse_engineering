#include <p18cxxx.h>
#include <usart.h>

/********************************************************************
*    Function Name:  DataRdy3USART                                   *
*    Return Value:   char                                           *
*    Parameters:     void                                           *
*    Description:    This routine checks the RC3IF flag to see if    *
*                    any data has been received by the USART. It    *
*                    returns a 1 if data is available and a 0 if    *
*                    not.                                           *
********************************************************************/
#if defined (EAUSART_V12)
#undef DataRdy3USART
char DataRdy3USART(void)
{
  if(PIR6bits.RC3IF)  // If RC2IF is set
    return 1;  // Data is available, return TRUE
    return 0;  // Data not available, return FALSE
}

#endif
