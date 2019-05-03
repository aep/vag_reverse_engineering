#include <p18cxxx.h>
#include <usart.h>


/********************************************************************
*    Function Name:  Write4USART                                     *
*    Return Value:   none                                           *
*    Parameters:     data: data to transmit                         *
*    Description:    This routine transmits a byte out the USART4.   *
********************************************************************/
#if defined (EAUSART_V12)

void Write4USART(char data)
{
  if(TXSTA4bits.TX9)  // 9-bit mode?
  {
    TXSTA4bits.TX9D = 0;       // Set the TX9D bit according to the
    if(USART4_Status.TX_NINE)  // USART2 Tx 9th bit in status reg
      TXSTA4bits.TX9D = 1;
  }

  TXREG4 = data;      // Write the data byte to the USART4
}

#endif
