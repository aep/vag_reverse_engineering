#include <p18cxxx.h>
#include <usart.h>

/**********************************************************************
*    Function Name:  putsUSART                                        *
*    Return Value:   void                                             *
*    Parameters:     data: pointer to string of data                  *
*    Description:    This routine transmits a string of characters    *
*                    to the USART including the null.                 *
**********************************************************************/

#if defined (AUSART_V1) || defined (EAUSART_V3) || defined (EAUSART_V4) || defined (EAUSART_V5)

void putsUSART( char *data)
{
  do
  {  // Transmit a byte
    while(BusyUSART());
    putcUSART(*data);
  } while( *data++ );
}

#endif
