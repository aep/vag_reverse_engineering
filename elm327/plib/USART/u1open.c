#include <p18cxxx.h>
#include <usart.h>

#ifndef EAUSART_V12
#define RC1IE RCIE
#define TX1IE TXIE
#endif

/********************************************************************
*    Function Name:  Open1USART                                      *
*    Return Value:   void                                            *
*    Parameters:     config: bit definitions to configure USART1     *
*                    spbrg: baudrate value for register SPBRG1       *
*    Description:    This routine first resets the USART1 regs       *
*                    to the POR state. It then configures the        *
*                    USART1 for interrupts, synch/async, 8/9-bit,    *
*                    sync slave/master and single/cont. rx.          *
*    Notes:          The bit definitions for config can be found     * 
*                    in the usart.h file.                            *
********************************************************************/
#if defined (AUSART_V2) 

void Open1USART( unsigned char config, unsigned int spbrg)
{
  TXSTA1 = 0;          // Reset USART registers to POR state
  RCSTA1 = 0;
 
  if(config&0x01)      // Sync or async operation
    TXSTA1bits.SYNC = 1;

  if(config&0x02)      // 8- or 9-bit mode
  {
    TXSTA1bits.TX9 = 1;	
    RCSTA1bits.RX9 = 1;
  }

  if(config&0x04)      // Master or Slave (sync only)
    TXSTA1bits.CSRC = 1;

  if(config&0x08)      // Continuous or single reception
    RCSTA1bits.CREN = 1;
  else
    RCSTA1bits.SREN = 1;

  if(config&0x10)      // Baud rate select (asychronous mode only)
    TXSTA1bits.BRGH = 1;
  else
    TXSTA1bits.BRGH = 0;

  if(config&0x40)      // Interrupt on receipt
    PIE1bits.RC1IE = 1;
  else
    PIE1bits.RC1IE = 0;

  if(config&0x80)      // Interrupt on transmission
    PIE1bits.TX1IE = 1;
  else
    PIE1bits.TX1IE = 0;

  SPBRG1 = spbrg;       // Write baudrate to SPBRG
  
  TXSTA1bits.TXEN = 1;  // Enable transmitter
  RCSTA1bits.SPEN = 1;  // Enable receiver
	TRISCbits.TRISC6 = 0;TRISCbits.TRISC7 = 1; 
	if(TXSTA1bits.SYNC && !TXSTA1bits.CSRC)	//synchronous  slave mode
		TRISCbits.TRISC6 = 1;
}

#elif  defined (EAUSART_V6) || defined (EAUSART_V7) || defined (EAUSART_V8) ||\
       defined (EAUSART_V9) || defined (EAUSART_V10)

void Open1USART( unsigned char config, unsigned int spbrg)
{
  TXSTA1 = 0;          // Reset USART registers to POR state
  RCSTA1 = 0;
 
  if(config&0x01)      // Sync or async operation
    TXSTA1bits.SYNC = 1;

  if(config&0x02)      // 8- or 9-bit mode
  {
    TXSTA1bits.TX9 = 1;	
    RCSTA1bits.RX9 = 1;
  }

  if(config&0x04)      // Master or Slave (sync only)
    TXSTA1bits.CSRC = 1;

  if(config&0x08)      // Continuous or single reception
    RCSTA1bits.CREN = 1;
  else
    RCSTA1bits.SREN = 1;

  if(config&0x10)      // Baud rate select (asychronous mode only)
    TXSTA1bits.BRGH = 1;
  
  if(config&0x20)      // Address Detect Enable
    RCSTA1bits.ADDEN = 1;
   
  
  if(config&0x40)      // Interrupt on receipt
    PIE1bits.RC1IE = 1;
  else
    PIE1bits.RC1IE = 0;

  if(config&0x80)      // Interrupt on transmission
    PIE1bits.TX1IE = 1;
  else
    PIE1bits.TX1IE = 0;

  SPBRG1 = spbrg;       // Write baudrate to SPBRG1
  SPBRGH1 = spbrg >> 8; // For 16-bit baud rate generation

  TXSTA1bits.TXEN = 1;  // Enable transmitter
  RCSTA1bits.SPEN = 1;  // Enable receiver
  TRISCbits.TRISC6 = 0;
  TRISCbits.TRISC7 = 1; 
  if(TXSTA1bits.SYNC && !TXSTA1bits.CSRC)	//synchronous  slave mode
		TRISCbits.TRISC6 = 1;
}

#elif  defined (EAUSART_V11) || defined (EAUSART_V11_1) || defined (EAUSART_V12)

void Open1USART( unsigned char config, unsigned int spbrg)
{
  TXSTA1 = 0;          // Reset USART registers to POR state
  RCSTA1 = 0;
 
  if(config&0x01)      // Sync or async operation
    TXSTA1bits.SYNC = 1;

  if(config&0x02)      // 8- or 9-bit mode
  {
    TXSTA1bits.TX9 = 1;	
    RCSTA1bits.RX9 = 1;
  }

  if(config&0x04)      // Master or Slave (sync only)
    TXSTA1bits.CSRC = 1;

  if(config&0x08)      // Continuous or single reception
    RCSTA1bits.CREN = 1;
  else
    RCSTA1bits.SREN = 1;

  if(config&0x10)      // Baud rate select (asychronous mode only)
    TXSTA1bits.BRGH = 1;
  
  if(config&0x20)      // Address Detect Enable
    RCSTA1bits.ADDEN = 1;
	
  // SENDB (asychronous mode only)  - need to be added
  
  if(config&0x40)      // Interrupt on receipt
	PIE1bits.RC1IE = 1;
  else
    PIE1bits.RC1IE = 0;

  if(config&0x80)      // Interrupt on transmission
    PIE1bits.TX1IE = 1;
  else
    PIE1bits.TX1IE = 0;

  SPBRG1 = spbrg;       // Write baudrate to SPBRG1
  SPBRGH1 = spbrg >> 8; // For 16-bit baud rate generation

  TXSTA1bits.TXEN = 1;  // Enable transmitter
  RCSTA1bits.SPEN = 1;  // Enable receiver  
}
#endif
