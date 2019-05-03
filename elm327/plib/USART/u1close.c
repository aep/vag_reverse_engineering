#include <p18cxxx.h>
#include <usart.h>

/*********************************************************************
*    Function Name:  Close1USART                                      *
*    Return Value:   void                                            *
*    Parameters:     void                                            *
*    Description:    This routine disables the transmitter and       *
*                    receiver and disables the interrupts for both   *
*    Note:           There is a macro version of this function       *
*                    available in usart.h                            *
*********************************************************************/
#if defined (AUSART_V2) || defined (EAUSART_V6)|| defined (EAUSART_V7) ||\
    defined (EAUSART_V8) || defined (EAUSART_V9) || defined (EAUSART_V10) ||\
	defined (EAUSART_V11) || defined (EAUSART_V11_1) || defined (EAUSART_V12)
#undef Close1USART
void Close1USART(void)
{
  RCSTA1 &= 0b01001111;  // Disable the receiver
  TXSTA1bits.TXEN = 0;   // and transmitter

  PIE1 &= 0b11001111;   // Disable both interrupts
}

#endif
