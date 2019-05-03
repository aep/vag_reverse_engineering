#include <p18cxxx.h>
#include <usart.h>

/**********************************************************************
*    Function Name:  putrs1USART                                       *
*    Return Value:   void                                             *
*    Parameters:     data: pointer to string of data                  *
*    Description:    This routine transmits a string of characters    *
*                    in ROM to the USART1 including the null.          *
**********************************************************************/
#if defined (AUSART_V2) || defined (EAUSART_V6)|| defined (EAUSART_V7) ||\
    defined (EAUSART_V8) || defined (EAUSART_V9) || defined (EAUSART_V10) ||\
	defined (EAUSART_V11) || defined (EAUSART_V11_1) || defined (EAUSART_V12)

void putrs1USART(const char *data)
{
  do
  {  // Transmit a byte
    while(Busy1USART());
    putc1USART(*data);
  } while( *data++ );
}

#endif
