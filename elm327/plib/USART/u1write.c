#include <p18cxxx.h>
#include <usart.h>

/********************************************************************
*    Function Name:  Write1USART                                     *
*    Return Value:   none                                           *
*    Parameters:     data: data to transmit                         *
*    Description:    This routine transmits a byte out the USART1.   *
********************************************************************/
#if defined (AUSART_V2) || defined (EAUSART_V6)|| defined (EAUSART_V7) ||\
    defined (EAUSART_V8) || defined (EAUSART_V9) || defined (EAUSART_V10) ||\
	defined (EAUSART_V11) || defined (EAUSART_V11_1) || defined (EAUSART_V12)

void Write1USART(char data)
{
  if(TXSTA1bits.TX9)  // 9-bit mode?
  {
    TXSTA1bits.TX9D = 0;       // Set the TX9D bit according to the
    if(USART1_Status.TX_NINE)  // USART1 Tx 9th bit in status reg
      TXSTA1bits.TX9D = 1;
  }

  TXREG1 = data;      // Write the data byte to the USART2
}
#endif
