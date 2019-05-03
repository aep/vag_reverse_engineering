#include <p18cxxx.h>
#include <usart.h>

/**********************************************************************
*    Function Name:  puts3USART                                        *
*    Return Value:   void                                             *
*    Parameters:     data: pointer to string of data                  *
*    Description:    This routine transmits a string of characters    *
*                    to the USART3 including the null.                 *
**********************************************************************/
#if defined (EAUSART_V12)

void puts3USART( char *data)
{
  do
  {  // Transmit a byte
    while(Busy3USART());
    putc3USART(*data);
  } while( *data++ );
}

#endif
