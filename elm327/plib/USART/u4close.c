#include <p18cxxx.h>
#include <usart.h>

/*********************************************************************
*    Function Name:  Close4USART                                      *
*    Return Value:   void                                            *
*    Parameters:     void                                            *
*    Description:    This routine disables the transmitter and       *
*                    receiver and disables the interrupts for both   *
*    Note:           There is a macro version of this function       *
*                    available in usart.h                            *
*********************************************************************/
#if defined (EAUSART_V12)
#undef Close4USART
void Close4USART(void)
{
  RCSTA4 &= 0b01001111;  // Disable the receiver
  TXSTA4bits.TXEN = 0;   // and transmitter

  PIE6 &= 0b00111111;   // Disable both interrupts
}

#endif
