#include <p18cxxx.h>
#include <usart.h>


/********************************************************************
*    Function Name:  Read3USART                                      *
*    Return Value:   char: received data                            *
*    Parameters:     void                                           *
*    Description:    This routine reads the data from the USART3     *
*                    and records the status flags for that byte     *
*                    in USART3_Status (Framing and Overrun).         *
********************************************************************/
#if defined (EAUSART_V12)

char Read3USART(void)
{
  char data;   // Holds received data

  USART3_Status.val &= 0xf2;          // Clear previous status flags

  if(RCSTA3bits.RX9)                  // If 9-bit mode
  {
    USART3_Status.RX_NINE = 0;        // Clear the recieve bit 9 for USART2
    if(RCSTA3bits.RX9D)               // according to the RX9D bit
      USART3_Status.RX_NINE = 1;
  }

  if(RCSTA3bits.FERR)                 // If a framing error occured
    USART3_Status.FRAME_ERROR = 1;    // Set the status bit

  if(RCSTA3bits.OERR)                 // If an overrun error occured
    USART3_Status.OVERRUN_ERROR = 1;  // Set the status bit

  data = RCREG3;                      // Read data

  return (data);                     // Return the received data
}

#endif
