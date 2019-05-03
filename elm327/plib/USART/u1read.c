#include <p18cxxx.h>
#include <usart.h>


/********************************************************************
*    Function Name:  Read1USART                                      *
*    Return Value:   char: received data                            *
*    Parameters:     void                                           *
*    Description:    This routine reads the data from the USART1     *
*                    and records the status flags for that byte     *
*                    in USART1_Status (Framing and Overrun).         *
********************************************************************/
#if defined (AUSART_V2) || defined (EAUSART_V6)|| defined (EAUSART_V7) ||\
    defined (EAUSART_V8) || defined (EAUSART_V9) || defined (EAUSART_V10) ||\
	defined (EAUSART_V11) || defined (EAUSART_V11_1) || defined (EAUSART_V12)

char Read1USART(void)
{
  char data;   // Holds received data

  USART1_Status.val &= 0xf2;          // Clear previous status flags

  if(RCSTA1bits.RX9)                  // If 9-bit mode
  {
    USART1_Status.RX_NINE = 0;        // Clear the recieve bit 9 for USART1
    if(RCSTA1bits.RX9D)               // according to the RX9D bit
      USART1_Status.RX_NINE = 1;
  }

  if(RCSTA1bits.FERR)                 // If a framing error occured
    USART1_Status.FRAME_ERROR = 1;    // Set the status bit

  if(RCSTA1bits.OERR)                 // If an overrun error occured
    USART1_Status.OVERRUN_ERROR = 1;  // Set the status bit

  data = RCREG1;                      // Read data

  return (data);                     // Return the received data
}

#endif
