#include <p18cxxx.h>
#include <usart.h>


/********************************************************************
*    Function Name:  Open4USART                                      *
*    Return Value:   void                                           *
*    Parameters:     config: bit definitions to configure USART4     *
*                    spbrg: baudrate value for register SPBRG3      *
*    Description:    This routine first resets the USART4 regs       *
*                    to the POR state. It then configures the       *
*                    USART3 for interrupts, synch/async, 8/9-bit,    *
*                    sync slave/master and single/cont. rx.         *
*    Notes:          The bit definitions for config can be found    *
*                    in the usart.h file.                           *
********************************************************************/
#if defined (EAUSART_V12)

void Open4USART( unsigned char config, unsigned int spbrg)
{
  TXSTA4 = 0;           // Reset USART registers to POR state
  RCSTA4 = 0;
 
  if(config&0x01)      // Sync or async operation
    TXSTA4bits.SYNC = 1;

  if(config&0x02)      // 8- or 9-bit mode
  {
    TXSTA4bits.TX9 = 1;
    RCSTA4bits.RX9 = 1;
  }

  if(config&0x04)      // Master or Slave (sync only)
    TXSTA4bits.CSRC = 1;

  if(config&0x08)      // Continuous or single reception
    RCSTA4bits.CREN = 1;
  else
    RCSTA4bits.SREN = 1;

  if(config&0x10)      // Baud rate select (asychronous mode only)
    TXSTA4bits.BRGH = 1;
  else
    TXSTA4bits.BRGH = 0;

  if(config&0x20)      // Address Detect Enable 
    RCSTA4bits.ADDEN = 1;
	
  // SENDB(asychronous mode only)  - need to be added
  
  if(config&0x40)      // Interrupt on receipt
    PIE6bits.RC4IE = 1;
  else
    PIE6bits.RC4IE = 0;

  if(config&0x80)      // Interrupt on transmission
    PIE6bits.TX4IE = 1;
  else
    PIE6bits.TX4IE = 0;

  SPBRG4 = spbrg;       // Write baudrate to SPBRG2
  SPBRGH4 = spbrg >> 8; // For 16-bit baud rate generation

  TXSTA4bits.TXEN = 1;  // Enable transmitter
  RCSTA4bits.SPEN = 1;  // Enable receiver
}


#endif
