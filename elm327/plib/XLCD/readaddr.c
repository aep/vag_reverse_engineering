#include <p18cxxx.h>
#include <xlcd.h>

/*********************************************************************
*       Function Name:  ReadAddrXLCD                                 *
*       Return Value:   char: address from LCD controller            *
*       Parameters:     void                                         *
*       Description:    This routine reads an address byte from the  *
*                       Hitachi HD44780 LCD controller. The user     *
*                       must check to see if the LCD controller is   *
*                       busy before calling this routine. The address*
*                       is read from the character generator RAM or  *
*                       the display data RAM depending on what the   *
*                       previous SetxxRamAddr routine was called.    *
*********************************************************************/
unsigned char ReadAddrXLCD(void)
{
        char data;                      // Holds the data retrieved from the LCD

#ifdef BIT8                             // 8-bit interface
        RW_PIN = 1;                     // Set control bits for the read
        RS_PIN = 0;
        DelayFor18TCY();
        E_PIN = 1;                      // Clock data out of the LCD controller
        DelayFor18TCY();
        data = DATA_PORT;               // Save the data in the register
        E_PIN = 0;
        RW_PIN = 0;                     // Reset the control bits
#else                                   // 4-bit interface
        RW_PIN = 1;                     // Set control bits for the read
        RS_PIN = 0;
        DelayFor18TCY();
        E_PIN = 1;                      // Clock data out of the LCD controller
        DelayFor18TCY();
#ifdef UPPER                            // Upper nibble interface
        data = DATA_PORT&0xf0;          // Read the nibble into the upper nibble of data
#else                                   // Lower nibble interface
        data = (DATA_PORT<<4)&0xf0;     // Read the nibble into the upper nibble of data
#endif
        E_PIN = 0;                      // Reset the clock
        DelayFor18TCY();
        E_PIN = 1;                      // Clock out the lower nibble
        DelayFor18TCY();
#ifdef UPPER                            // Upper nibble interface
        data |= (DATA_PORT>>4)&0x0f;    // Read the nibble into the lower nibble of data
#else                                   // Lower nibble interface
        data |= DATA_PORT&0x0f;         // Read the nibble into the lower nibble of data
#endif
        E_PIN = 0;
        RW_PIN = 0;                     // Reset the control lines
#endif
        return (data&0x7f);             // Return the address, Mask off the busy bit
}

