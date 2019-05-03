#include <p18cxxx.h>
#include <usart.h>


/********************************************************************
*    Function Name:  Write3USART                                     *
*    Return Value:   none                                           *
*    Parameters:     data: data to transmit                         *
*    Description:    This routine transmits a byte out the USART3.   *
********************************************************************/
#if defined (EAUSART_V12)

void Write3USART(char data)
{
  if(TXSTA3bits.TX9)  // 9-bit mode?
  {
    TXSTA3bits.TX9D = 0;       // Set the TX9D bit according to the
    if(USART3_Status.TX_NINE)  // USART2 Tx 9th bit in status reg
      TXSTA3bits.TX9D = 1;
  }

  TXREG3 = data;      // Write the data byte to the USART3
}

#endif
