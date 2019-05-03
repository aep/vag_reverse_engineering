#include <p18cxxx.h>
#include <xlcd.h>

/********************************************************************
*       Function Name:  ReadDataXLCD                                *
*       Return Value:   char: data byte from LCD controller         *
*       Parameters:     void                                        *
*       Description:    This routine reads a data byte from the     *
*                       Hitachi HD44780 LCD controller. The user    *
*                       must check to see if the LCD controller is  *
*                       busy before calling this routine. The data  *
*                       is read from the character generator RAM or *
*                       the display data RAM depending on what the  *
*                       previous SetxxRamAddr routine was called.   *
********************************************************************/
char ReadDataXLCD(void)
{
        char data;

#ifdef BIT8                             // 8-bit interface
        RS_PIN = 1;                     // Set the control bits
        RW_PIN = 1;
        DelayFor18TCY();
        E_PIN = 1;                      // Clock the data out of the LCD
        DelayFor18TCY();
        data = DATA_PORT;               // Read the data
        E_PIN = 0;
        RS_PIN = 0;                     // Reset the control bits
        RW_PIN = 0;
#else                                   // 4-bit interface
        RW_PIN = 1;
        RS_PIN = 1;
        DelayFor18TCY();
        E_PIN = 1;                      // Clock the data out of the LCD
        DelayFor18TCY();
#ifdef UPPER                            // Upper nibble interface
        data = DATA_PORT&0xf0;          // Read the upper nibble of data
#else                                   // Lower nibble interface
        data = (DATA_PORT<<4)&0xf0;     // read the upper nibble of data
#endif
        E_PIN = 0;                      // Reset the clock line
        DelayFor18TCY();
        E_PIN = 1;                      // Clock the next nibble out of the LCD
        DelayFor18TCY();
#ifdef UPPER                            // Upper nibble interface
        data |= (DATA_PORT>>4)&0x0f;    // Read the lower nibble of data
#else                                   // Lower nibble interface
        data |= DATA_PORT&0x0f;         // Read the lower nibble of data
#endif
        E_PIN = 0;                                      
        RS_PIN = 0;                     // Reset the control bits
        RW_PIN = 0;
#endif
        return(data);                   // Return the data byte
}

