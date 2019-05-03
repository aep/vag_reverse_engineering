#include <p18cxxx.h>
#include <usart.h>


/********************************************************************
*    Function Name:  Read2USART                                      *
*    Return Value:   char: received data                            *
*    Parameters:     void                                           *
*    Description:    This routine reads the data from the USART2     *
*                    and records the status flags for that byte     *
*                    in USART2_Status (Framing and Overrun).         *
********************************************************************/
#if defined (AUSART_V2) || defined (EAUSART_V6)|| defined (EAUSART_V7) ||\
    defined (EAUSART_V8) || defined (EAUSART_V9) || defined (EAUSART_V11)\
	|| defined (EAUSART_V12)

char Read2USART(void)
{
  char data;   // Holds received data

  USART2_Status.val &= 0xf2;          // Clear previous status flags

  if(RCSTA2bits.RX9)                  // If 9-bit mode
  {
    USART2_Status.RX_NINE = 0;        // Clear the recieve bit 9 for USART2
    if(RCSTA2bits.RX9D)               // according to the RX9D bit
      USART2_Status.RX_NINE = 1;
  }

  if(RCSTA2bits.FERR)                 // If a framing error occured
    USART2_Status.FRAME_ERROR = 1;    // Set the status bit

  if(RCSTA2bits.OERR)                 // If an overrun error occured
    USART2_Status.OVERRUN_ERROR = 1;  // Set the status bit

  data = RCREG2;                      // Read data

  return (data);                     // Return the received data
}

#endif
