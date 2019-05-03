#include <p18cxxx.h>
#include <usart.h>

/**********************************************************************
*    Function Name:  puts4USART                                        *
*    Return Value:   void                                             *
*    Parameters:     data: pointer to string of data                  *
*    Description:    This routine transmits a string of characters    *
*                    to the USART4 including the null.                 *
**********************************************************************/
#if defined (EAUSART_V12)

void puts4USART( char *data)
{
  do
  {  // Transmit a byte
    while(Busy4USART());
    putc4USART(*data);
  } while( *data++ );
}

#endif
