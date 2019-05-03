#include "Serial.h"
#include <xc.h>
#include <usart.h>
#include "main.h"

#define RX_BUFFER_SIZE 32
unsigned char RxBuffer[RX_BUFFER_SIZE];
int inIndex;
int outIndex;


/**********************************************************************
* Function:        void initEUSART (void)
* PreCondition:    None
* Input:		   None
* Output:		   None
* Side Effects:
* Overview:		  Initialization of USART
					1. Enable Transmitter and select High Baud Rate in TXSTA
					2. Select a value in SPGRB register to generate 9600 baud rate
					3. Enable Serial port in RCSTA register
					4. Enable continuous reception in RCSTA

***********************************************************************/
void initEUSART (void)
{
    TRISCbits.TRISC6 = 0;
    TRISCbits.TRISC7 = 1;

//    unsigned char config = USART_TX_INT_OFF & USART_RX_INT_OFF & USART_ASYNCH_MODE
// & USART_EIGHT_BIT
//& USART_CONT_RX
//& USART_BRGH_HIGH
//& USART_ADDEN_OFF;
//    unsigned int spbrg = 25;
//    unsigned char baud = BAUD_IDLE_RX_PIN_STATE_HIGH
// & BAUD_8_BIT_RATE & BAUD_WAKEUP_OFF
//            & BAUD_AUTO_OFF;
//
//
//    Open1USART(config, spbrg);
//    baud1USART(baud);
    TXSTA1 = 0b00100100;
    RCSTA1 = 0b10010000;
    BAUDCON1 = 0b00000000;
    SPBRG1 = 25;
    PIE1bits.RC1IE = 1;
}

/**********************************************************************
* Function:        void PutString(unsigned char *mess)
* PreCondition:    None
* Input:		   Pointer to display message
* Output:		   None
* Side Effects:
* Overview:		   Sends the string to terminal till it finds NULL character.
***********************************************************************/
void PutString(const char *mess)
{
	while(*mess != '\0')
	{
  		Putchar(*mess++);
	}
}

/**********************************************************************
* Function:        unsigned char Getchar(void)
* PreCondition:    None
* Input:		   None
* Output:		   Return a byte received from UART
* Side Effects:
* Overview:		  Wait till a byte received from termianl and then returns the received data
***********************************************************************/
unsigned char GetcharHW(void)
{
    return Read1USART();
}

unsigned char Getchar(void)
{
    unsigned char retVal = 0;
    if(HasData())
    {
        retVal = RxBuffer[outIndex];
        outIndex++;
        outIndex = outIndex & (RX_BUFFER_SIZE - 1);
    }
    return retVal;
}

int HasData(void)
{
    return inIndex != outIndex;
}
/**********************************************************************
* Function:        void Putchar (unsigned char send_data)
* PreCondition:    None
* Input:		   Byte to transmit
* Output:		   None
* Side Effects:
* Overview:		   Transmits a byte to terminal through UART.
***********************************************************************/
void Putchar (char send_data)
{
    while(Busy1USART());
    
    __delay_us(1);
    
    //TXREG1 = send_data;
    
    Write1USART(send_data);
}


/**********************************************************************
* Function:        void hex_ascii(unsigned char display_data)
* PreCondition:    None
* Input:		   HEX Value
* Output:		   None
* Side Effects:
* Overview:		 Convert Hex Value to ASCII and send to PC;
***********************************************************************/
void hex_ascii(unsigned char display_data)
{
    Putchar('0');
    Putchar('x');
	unsigned char temp;
	temp = ((display_data & 0xF0)>>4);
	if (temp <= 0x09)
		Putchar(temp+'0');
	else
		Putchar(temp+'0'+0x07);

	temp = display_data & 0x0F;
	if (temp <= 0x09)
		Putchar(temp+'0');
	else
		Putchar(temp+'0'+0x07);
        Putchar(' ');
//	Putchar('\r');
//	Putchar('\n');
}

void U1RXInterrupt(void)
{
    unsigned char inboundChar = GetcharHW();
    RxBuffer[inIndex] = inboundChar;
    inIndex++;
    inIndex = inIndex & (RX_BUFFER_SIZE - 1);
}
