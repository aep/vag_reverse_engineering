#include <p18cxxx.h>
#include <usart.h>


/********************************************************************
*    Function Name:  Write2USART                                     *
*    Return Value:   none                                           *
*    Parameters:     data: data to transmit                         *
*    Description:    This routine transmits a byte out the USART2.   *
********************************************************************/
#if defined (AUSART_V2) || defined (EAUSART_V6)|| defined (EAUSART_V7) ||\
    defined (EAUSART_V8) || defined (EAUSART_V9) || defined (EAUSART_V11)\
	|| defined (EAUSART_V12)

void Write2USART(char data)
{
  if(TXSTA2bits.TX9)  // 9-bit mode?
  {
    TXSTA2bits.TX9D = 0;       // Set the TX9D bit according to the
    if(USART2_Status.TX_NINE)  // USART2 Tx 9th bit in status reg
      TXSTA2bits.TX9D = 1;
  }

  TXREG2 = data;      // Write the data byte to the USART2
}

#endif
