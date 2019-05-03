#include <p18cxxx.h>
#include <usart.h>


/********************************************************************
*    Function Name:  WriteUSART                                     *
*    Return Value:   none                                           *
*    Parameters:     data: data to transmit                         *
*    Description:    This routine transmits a byte out the USART.   *
********************************************************************/
#if defined (AUSART_V1) || defined (EAUSART_V3) || defined (EAUSART_V4) || defined (EAUSART_V5)

void WriteUSART(char data)
{
  if(TXSTAbits.TX9)  // 9-bit mode?
  {
    TXSTAbits.TX9D = 0;       // Set the TX9D bit according to the
    if(USART_Status.TX_NINE)  // USART Tx 9th bit in status reg
      TXSTAbits.TX9D = 1;
  }

  TXREG = data;      // Write the data byte to the USART
}

#endif
