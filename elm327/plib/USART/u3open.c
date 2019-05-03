#include <p18cxxx.h>
#include <usart.h>


/********************************************************************
*    Function Name:  Open3USART                                      *
*    Return Value:   void                                           *
*    Parameters:     config: bit definitions to configure USART3     *
*                    spbrg: baudrate value for register SPBRG3      *
*    Description:    This routine first resets the USART3 regs       *
*                    to the POR state. It then configures the       *
*                    USART3 for interrupts, synch/async, 8/9-bit,    *
*                    sync slave/master and single/cont. rx.         *
*    Notes:          The bit definitions for config can be found    *
*                    in the usart.h file.                           *
********************************************************************/
#if defined (EAUSART_V12)

void Open3USART( unsigned char config, unsigned int spbrg)
{
  TXSTA3 = 0;           // Reset USART registers to POR state
  RCSTA3 = 0;
 
  if(config&0x01)      // Sync or async operation
    TXSTA3bits.SYNC = 1;

  if(config&0x02)      // 8- or 9-bit mode
  {
    TXSTA3bits.TX9 = 1;
    RCSTA3bits.RX9 = 1;
  }

  if(config&0x04)      // Master or Slave (sync only)
    TXSTA3bits.CSRC = 1;

  if(config&0x08)      // Continuous or single reception
    RCSTA3bits.CREN = 1;
  else
    RCSTA3bits.SREN = 1;

  if(config&0x10)      // Baud rate select (asychronous mode only)
    TXSTA3bits.BRGH = 1;
  else
    TXSTA3bits.BRGH = 0;

  if(config&0x20)      // Address Detect Enable 
    RCSTA3bits.ADDEN = 1;
	
  // SENDB(asychronous mode only)  - need to be added
  
  if(config&0x40)      // Interrupt on receipt
    PIE6bits.RC3IE = 1;
  else
    PIE6bits.RC3IE = 0;

  if(config&0x80)      // Interrupt on transmission
    PIE6bits.TX3IE = 1;
  else
    PIE6bits.TX3IE = 0;

  SPBRG3 = spbrg;       // Write baudrate to SPBRG2
  SPBRGH3 = spbrg >> 8; // For 16-bit baud rate generation

  TXSTA3bits.TXEN = 1;  // Enable transmitter
  RCSTA3bits.SPEN = 1;  // Enable receiver
}


#endif
