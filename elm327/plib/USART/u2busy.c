#include <p18cxxx.h>
#include <usart.h>

/*********************************************************************
*    Function Name:  Busy2USART                                       *
*    Return Value:   char: transmit successful status                *
*    Parameters:     none                                            *
*    Description:    This routine checks to see if a byte can be     *
*                    written to the USART by checking the TRMT bit   *
*********************************************************************/
#if defined (AUSART_V2) || defined (EAUSART_V6)|| defined (EAUSART_V7) ||\
    defined (EAUSART_V8) || defined (EAUSART_V9) || defined (EAUSART_V11) || defined (EAUSART_V12)
#undef Busy2USART
char Busy2USART(void)
{
  if(!TXSTA2bits.TRMT)  // Is the transmit shift register empty
    return 1;          // No, return FALSE
    return 0;            // Return TRUE
}

#endif
