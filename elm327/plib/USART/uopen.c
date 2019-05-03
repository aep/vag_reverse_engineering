#include <p18cxxx.h>
#include <usart.h>


/********************************************************************
*    Function Name:  OpenUSART                                      *
*    Return Value:   void                                           *
*    Parameters:     config: bit definitions to configure USART     *
*                    spbrg: baudrate value for register SPBRG1      *
*                    or for SPBRGH:SPBRG for 16-bit baud rate       *
*                    generation for applicable parts                *
*    Description:    This routine first resets the USART regs       *
*                    to the POR state. It then configures the       *
*                    USART for interrupts, synch/async, 8/9-bit,    *
*                    sync slave/master and single/cont. rx.         *
*    Notes:          The bit definitions for config can be found    *
*                    in the usart.h file.                           *
********************************************************************/
#if defined (AUSART_V1)

void OpenUSART( unsigned char config, unsigned int spbrg)
{
  TXSTA = 0;           // Reset USART registers to POR state
  RCSTA = 0;
 
  if(config&0x01)      // Sync or async operation
    TXSTAbits.SYNC = 1;

  if(config&0x02)      // 8- or 9-bit mode
  {
    TXSTAbits.TX9 = 1;
    RCSTAbits.RX9 = 1;
  }

  if(config&0x04)      // Master or Slave (sync only)
    TXSTAbits.CSRC = 1;

  if(config&0x08)      // Continuous or single reception
    RCSTAbits.CREN = 1;
  else
    RCSTAbits.SREN = 1;

  if(config&0x10)      // Baud rate select (asychronous mode only)
    TXSTAbits.BRGH = 1;
  else
    TXSTAbits.BRGH = 0;

  PIR1bits.TXIF = 0;

  if(config&0x40)      // Interrupt on receipt
    PIE1bits.RCIE = 1;
  else
    PIE1bits.RCIE = 0;

  PIR1bits.RCIF = 0;

  if(config&0x80)      // Interrupt on transmission
    PIE1bits.TXIE = 1;
  else
    PIE1bits.TXIE = 0;

  SPBRG = spbrg;       // Write baudrate to SPBRG1
  TXSTAbits.TXEN = 1;  // Enable transmitter
  RCSTAbits.SPEN = 1;  // Enable receiver
 
	TRISCbits.TRISC6 = 0;TRISCbits.TRISC7 = 1; 
	if(TXSTAbits.SYNC && !TXSTAbits.CSRC)	//synchronous  slave mode
		TRISCbits.TRISC6 = 1;
}

#elif defined (EAUSART_V3) || defined (EAUSART_V4) || defined (EAUSART_V5) 

void OpenUSART( unsigned char config, unsigned int spbrg)
{
  TXSTA = 0;           // Reset USART registers to POR state
  RCSTA = 0;
 
  if(config&0x01)      // Sync or async operation
    TXSTAbits.SYNC = 1;

  if(config&0x02)      // 8- or 9-bit mode
  {
    TXSTAbits.TX9 = 1;
    RCSTAbits.RX9 = 1;
  }

  if(config&0x04)      // Master or Slave (sync only)
    TXSTAbits.CSRC = 1;

  if(config&0x08)      // Continuous or single reception
    RCSTAbits.CREN = 1;
  else
    RCSTAbits.SREN = 1;

  if(config&0x10)      // Baud rate select (asychronous mode only)
    TXSTAbits.BRGH = 1;
  
    PIR1bits.TXIF = 0;
	
  if(config&0x20)  // Address Detect Enable
	 RCSTAbits.ADEN = 1;
	 
  if(config&0x40)      // Interrupt on receipt
    PIE1bits.RCIE = 1;
  else
    PIE1bits.RCIE = 0;

  PIR1bits.RCIF = 0;

  if(config&0x80)      // Interrupt on transmission
    PIE1bits.TXIE = 1;
  else
    PIE1bits.TXIE = 0;

  SPBRG = spbrg;       // Write baudrate to SPBRG1
  SPBRGH = spbrg >> 8; // For 16-bit baud rate generation

  TXSTAbits.TXEN = 1;  // Enable transmitter
  RCSTAbits.SPEN = 1;  // Enable receiver

#if defined (USART_IO_V1)
	TRISBbits.TRISB1 = 0;TRISBbits.TRISB4 = 1;
	if(TXSTAbits.SYNC && !TXSTAbits.CSRC)	//synchronous  slave mode
		TRISBbits.TRISB1 = 1;

#elif defined (USART_IO_V2)
	TRISAbits.TRISA2 = 0;TRISAbits.TRISA3 = 1;
	if(TXSTAbits.SYNC && !TXSTAbits.CSRC)	//synchronous  slave mode
		TRISAbits.TRISA2 = 1;
		
#elif defined (USART_IO_V3)
	TRISBbits.TRISB7 = 0;TRISBbits.TRISB5 = 1;
	if(TXSTAbits.SYNC && !TXSTAbits.CSRC)	//synchronous  slave mode
		TRISBbits.TRISB7 = 1;
		
#else
	TRISCbits.TRISC6 = 0;TRISCbits.TRISC7 = 1; 
	if(TXSTAbits.SYNC && !TXSTAbits.CSRC)	//synchronous  slave mode
		TRISCbits.TRISC6 = 1;

#endif
	
}

#endif
