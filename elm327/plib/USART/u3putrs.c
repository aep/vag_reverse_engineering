#include <p18cxxx.h>
#include <usart.h>

/**********************************************************************
*    Function Name:  putrs3USART                                       *
*    Return Value:   void                                             *
*    Parameters:     data: pointer to string of data                  *
*    Description:    This routine transmits a string of characters    *
*                    in ROM to the USART3 including the null.          *
**********************************************************************/
#if defined (EAUSART_V12)

#ifndef _OMNI_CODE_
void putrs3USART(const rom char *data)
#else
void putrs3USART(const char *data)
#endif
{
  do
  {  // Transmit a byte
    while(Busy3USART());
    putc3USART(*data);
  } while( *data++ );
}

#endif
