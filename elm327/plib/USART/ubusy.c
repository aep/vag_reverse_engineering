#include <p18cxxx.h>
#include <usart.h>

/*********************************************************************
*    Function Name:  BusyUSART                                       *
*    Return Value:   char: transmit successful status                *
*    Parameters:     none                                            *
*    Description:    This routine checks to see if a byte can be     *
*                    written to the USART by checking the TRMT bit   *
*********************************************************************/
#if defined (AUSART_V1) || defined (EAUSART_V3) || defined (EAUSART_V4) || defined (EAUSART_V5)
#undef BusyUSART
char BusyUSART(void)
{
  if(!TXSTAbits.TRMT)  // Is the transmit shift register empty
    return 1;          // No, return FALSE
  return 0;            // Return TRUE
}

#endif
