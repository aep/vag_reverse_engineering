#include <p18cxxx.h>
#include <xlcd.h>

/********************************************************************
*       Function Name:  WriteCmdXLCD                                *
*       Return Value:   void                                        *
*       Parameters:     cmd: command to send to LCD                 *
*       Description:    This routine writes a command to the Hitachi*
*                       HD44780 LCD controller. The user must check *
*                       to see if the LCD controller is busy before *
*                       calling this routine.                       *
********************************************************************/
void WriteCmdXLCD(unsigned char cmd)
{
#ifdef BIT8                             // 8-bit interface
        TRIS_DATA_PORT = 0;             // Data port output
        DATA_PORT = cmd;                // Write command to data port
        RW_PIN = 0;                     // Set the control signals
        RS_PIN = 0;                     // for sending a command
        DelayFor18TCY();
        E_PIN = 1;                      // Clock the command in
        DelayFor18TCY();
        E_PIN = 0;
        DelayFor18TCY();
        TRIS_DATA_PORT = 0xff;          // Data port input
#else                                   // 4-bit interface
#ifdef UPPER                            // Upper nibble interface
        TRIS_DATA_PORT &= 0x0f;
        DATA_PORT &= 0x0f;
        DATA_PORT |= cmd&0xf0;
#else                                   // Lower nibble interface
        TRIS_DATA_PORT &= 0xf0;
        DATA_PORT &= 0xf0;
        DATA_PORT |= (cmd>>4)&0x0f;
#endif
        RW_PIN = 0;                     // Set control signals for command
        RS_PIN = 0;
        DelayFor18TCY();
        E_PIN = 1;                      // Clock command in
        DelayFor18TCY();
        E_PIN = 0;
#ifdef UPPER                            // Upper nibble interface
        DATA_PORT &= 0x0f;
        DATA_PORT |= (cmd<<4)&0xf0;
#else                                   // Lower nibble interface
        DATA_PORT &= 0xf0;
        DATA_PORT |= cmd&0x0f;
#endif
        DelayFor18TCY();
        E_PIN = 1;                      // Clock command in
        DelayFor18TCY();
        E_PIN = 0;
#ifdef UPPER                            // Make data nibble input
        TRIS_DATA_PORT |= 0xf0;
#else
        TRIS_DATA_PORT |= 0x0f;
#endif
#endif
        return;
}

