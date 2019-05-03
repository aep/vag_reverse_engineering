#include <p18cxxx.h>
#include <xlcd.h>

/********************************************************************
*       Function Name:  putrsXLCD
*       Return Value:   void
*       Parameters:     buffer: pointer to string
*       Description:    This routine writes a string of bytes to the
*                       Hitachi HD44780 LCD controller. The user
*                       must check to see if the LCD controller is
*                       busy before calling this routine. The data
*                       is written to the character generator RAM or
*                       the display data RAM depending on what the
*                       previous SetxxRamAddr routine was called.
********************************************************************/
void putrsXLCD(const char *buffer)
{
        while(*buffer)                  // Write data to LCD up to null
        {
                while(BusyXLCD());      // Wait while LCD is busy
                WriteDataXLCD(*buffer); // Write character to LCD
                buffer++;               // Increment buffer
        }
        return;
}

