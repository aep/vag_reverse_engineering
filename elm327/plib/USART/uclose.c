#include <p18cxxx.h>
#include <usart.h>

/*********************************************************************
*    Function Name:  CloseUSART                                      *
*    Return Value:   void                                            *
*    Parameters:     void                                            *
*    Description:    This routine disables the transmitter and       *
*                    receiver and disables the interrupts for both   *
*    Note:           There is a macro version of this function       *
*                    available in usart.h                            *
*********************************************************************/
#if defined (AUSART_V1) || defined (EAUSART_V3) || defined (EAUSART_V4) || defined (EAUSART_V5)
#undef CloseUSART
void CloseUSART(void)
{
  RCSTA &= 0b01001111;  // Disable the receiver
  TXSTAbits.TXEN = 0;   // and transmitter

  PIE1 &= 0b11001111;   // Disable both interrupts
}

#endif
