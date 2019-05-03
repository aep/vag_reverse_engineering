#include <p18cxxx.h>
#include <usart.h>

/********************************************************************
*    Function Name:  DataRdy2USART                                   *
*    Return Value:   char                                           *
*    Parameters:     void                                           *
*    Description:    This routine checks the RC2IF flag to see if    *
*                    any data has been received by the USART. It    *
*                    returns a 1 if data is available and a 0 if    *
*                    not.                                           *
********************************************************************/
#if defined (AUSART_V2) || defined (EAUSART_V6)|| defined (EAUSART_V7) || \
    defined (EAUSART_V8) || defined (EAUSART_V9) || defined (EAUSART_V11) \
	|| defined (EAUSART_V12)
#undef DataRdy2USART
char DataRdy2USART(void)
{
  if(PIR3bits.RC2IF)  // If RC2IF is set
    return 1;  // Data is available, return TRUE
    return 0;  // Data not available, return FALSE
}

#endif
