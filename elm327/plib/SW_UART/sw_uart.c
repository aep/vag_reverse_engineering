#include <p18cxxx.h>
#include "sw_uart.h"

/********************************************************************
 *    Function Name:  getsUART                                       *
 *    Return Value:   void                                           *
 *    Parameters:     buffer: pointer to string                      *
 *                    len: length of characters to receive           *
 *    Description:    This routine receives a string of characters   *
 *                    from the SW UART of length specified by len.   *
 ********************************************************************/
void getsUART(char *buffer, unsigned char len)
{
	char i;    // Length counter

	for(i=0;i<len;i++)   // Only retrieve len characters
	{
		*buffer = getcUART(); // Get a character from the USART
		// and save in the string
		buffer++;          // Increment the string pointer
	}
}

/**********************************************************************
 *    Function Name:  putsUART                                         *
 *    Return Value:   void                                             *
 *    Parameters:     data: pointer to string of data                  *
 *    Description:    This routine transmits a string of characters    *
 *                    to the UART data byte including the null.        *
 **********************************************************************/
void putsUART( char *data)
{
	do
	{    // Transmit a byte
		putcUART(*data);
	} while( *data++ );
}

/* **********************************************************************
 *      Function Name:  ReadUART                                        *
 *      Return Value:   char: received data                             *
 *      Parameters:     void                                            *
 *      Description:    This routine waits for a start bit, and then    *
 *                      reads all 8-bits.                               *
 *      Special Note:   The user must provide two routines:             *
 *                      DelayRXHalfBit():                               *
 *                        DelayRXHalfBit should have:                   *
 *                              5 Tcy for overhead                      *
 *                              2 Tcy call to DelayRXHalfBit            *
 *                              ? Tcy                                   *
 *                              2 Tcy for return from DelayRXHalfBit    *
 *                              = (((2*OSC_FREQ)/(8*BAUDRATE))+1)/2 Tcy *
 *                      DelayRXBit():                                   *
 *                        DelayRXBit should have:                       *
 *                              10 Tcy for overhead                     *
 *                              2 Tcy call to DelayRXBit                *
 *                              ? Tcy                                   *
 *                              2 Tcy for return from DelayRXBit        *
 *                              = (((2*OSC_FREQ)/(4*BAUDRATE))+1)/2 Tcy *
 *********************************************************************** */

unsigned char ReadUART(void)
{
	unsigned char bitcount=8;
	unsigned char uartdata;

	while (PORTBbits.RB5){
		while (PORTBbits.RB5);
		DelayRXHalfBitUART();
	}

	while (bitcount--){
		DelayRXBitUART();
		STATUSbits.C = PORTBbits.RB5 ? 1:0;
		uartdata=uartdata>>1 | uartdata<<7;
	}
	return uartdata;
}

/* **********************************************************************
 *      Function Name:  WriteUART                                       *
 *      Return Value:   void                                            *
 *      Parameters:     data: byte to send out the UART                 *
 *      Description:    This routine sends a byte out the TXD pin.      *
 *      Special Note:   The user must provide a routine:                * 
 *                      DelayTXBit():                                   *
 *                        DelayTXBit should have:                       *
 *                              8 Tcy for overhead                      *
 *                              2 Tcy call to DelayTXBit                *
 *                              ? Tcy                                   *
 *                              2 Tcy for return from DelayTXBit        *
 *                      = (((2*OSC_FREQ)/(4*BAUDRATE))+1)/2  Tcy        *
 *********************************************************************** */


void WriteUART (unsigned char uartdata)
{
	unsigned char bitcount = 8;
	
	//start
    PORTBbits.RB4 = 0;
    DelayTXBitUART();

	while (bitcount--){
		PORTBbits.RB4 = uartdata& 0x01;
		DelayTXBitUART();
		uartdata >>= 1;
	}
	
	//stop
	PORTBbits.RB4 = 1;
	DelayTXBitUART();
}
