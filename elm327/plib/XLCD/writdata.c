#include <p18cxxx.h>
#include <xlcd.h>

/********************************************************************
*       Function Name:  WriteDataXLCD                               *
*       Return Value:   void                                        *
*       Parameters:     data: data byte to be written to LCD        *
*       Description:    This routine writes a data byte to the      *
*                       Hitachi HD44780 LCD controller. The user    *
*                       must check to see if the LCD controller is  *
*                       busy before calling this routine. The data  *
*                       is written to the character generator RAM or*
*                       the display data RAM depending on what the  *
*                       previous SetxxRamAddr routine was called.   *
********************************************************************/
void WriteDataXLCD(char data)
{
#ifdef BIT8                             // 8-bit interface
        TRIS_DATA_PORT = 0;             // Make port output
        DATA_PORT = data;               // Write data to port
        RS_PIN = 1;                     // Set control bits
        RW_PIN = 0;
        DelayFor18TCY();
        E_PIN = 1;                      // Clock data into LCD
        DelayFor18TCY();
        E_PIN = 0;
        RS_PIN = 0;                     // Reset control bits
        TRIS_DATA_PORT = 0xff;          // Make port input
#else                                   // 4-bit interface
#ifdef UPPER                            // Upper nibble interface
        TRIS_DATA_PORT &= 0x0f;
        DATA_PORT &= 0x0f;
        DATA_PORT |= data&0xf0;
#else                                   // Lower nibble interface
        TRIS_DATA_PORT &= 0xf0;
        DATA_PORT &= 0xf0;
        DATA_PORT |= ((data>>4)&0x0f);
#endif
        RS_PIN = 1;                     // Set control bits
        RW_PIN = 0;
        DelayFor18TCY();
        E_PIN = 1;                      // Clock nibble into LCD
        DelayFor18TCY();
        E_PIN = 0;
#ifdef UPPER                            // Upper nibble interface
        DATA_PORT &= 0x0f;
        DATA_PORT |= ((data<<4)&0xf0);
#else                                   // Lower nibble interface
        DATA_PORT &= 0xf0;
        DATA_PORT |= (data&0x0f);
#endif
        DelayFor18TCY();
        E_PIN = 1;                      // Clock nibble into LCD
        DelayFor18TCY();
        E_PIN = 0;
#ifdef UPPER                            // Upper nibble interface
        TRIS_DATA_PORT |= 0xf0;
#else                                   // Lower nibble interface
        TRIS_DATA_PORT |= 0x0f;
#endif
#endif
        return;
}

