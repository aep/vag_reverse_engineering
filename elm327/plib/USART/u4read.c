#include <p18cxxx.h>
#include <usart.h>


/********************************************************************
*    Function Name:  Read4USART                                      *
*    Return Value:   char: received data                            *
*    Parameters:     void                                           *
*    Description:    This routine reads the data from the USART3     *
*                    and records the status flags for that byte     *
*                    in USART4_Status (Framing and Overrun).         *
********************************************************************/
#if defined (EAUSART_V12)

char Read4USART(void)
{
  char data;   // Holds received data

  USART4_Status.val &= 0xf2;          // Clear previous status flags

  if(RCSTA4bits.RX9)                  // If 9-bit mode
  {
    USART4_Status.RX_NINE = 0;        // Clear the recieve bit 9 for USART2
    if(RCSTA4bits.RX9D)               // according to the RX9D bit
      USART4_Status.RX_NINE = 1;
  }

  if(RCSTA4bits.FERR)                 // If a framing error occured
    USART4_Status.FRAME_ERROR = 1;    // Set the status bit

  if(RCSTA4bits.OERR)                 // If an overrun error occured
    USART4_Status.OVERRUN_ERROR = 1;  // Set the status bit

  data = RCREG4;                      // Read data

  return (data);                     // Return the received data
}

#endif
