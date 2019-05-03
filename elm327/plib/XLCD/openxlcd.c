#include <p18cxxx.h>
#include "delays.h"
#include <xlcd.h>

/********************************************************************
*       Function Name:  OpenXLCD                                    *
*       Return Value:   void                                        *
*       Parameters:     lcdtype: sets the type of LCD (lines)       *
*       Description:    This routine configures the LCD. Based on   *
*                       the Hitachi HD44780 LCD controller. The     *
*                       routine will configure the I/O pins of the  *
*                       microcontroller, setup the LCD for 4- or    *
*                       8-bit mode and clear the display. The user  *
*                       must provide three delay routines:          *
*                       DelayFor18TCY() provides a 18 Tcy delay     *
*                       DelayPORXLCD() provides at least 15ms delay *
*                       DelayXLCD() provides at least 5ms delay     *
********************************************************************/
void OpenXLCD(unsigned char lcdtype)
{
        // The data bits must be either a 8-bit port or the upper or
        // lower 4-bits of a port. These pins are made into inputs
#ifdef BIT8                             // 8-bit mode, use whole port
        DATA_PORT = 0;
        TRIS_DATA_PORT = 0x00;
#else                                   // 4-bit mode
#ifdef UPPER                            // Upper 4-bits of the port
        DATA_PORT &= 0x0f;
        TRIS_DATA_PORT &= 0x0F;
#else                                   // Lower 4-bits of the port
        DATA_PORT &= 0xf0;
        TRIS_DATA_PORT &= 0xF0;
#endif
#endif
        TRIS_RW = 0;                    // All control signals made outputs
        TRIS_RS = 0;
        TRIS_E = 0;
        RW_PIN = 0;                     // R/W pin made low
        RS_PIN = 0;                     // Register select pin made low
        E_PIN = 0;                      // Clock pin made low

        // Delay for 15ms to allow for LCD Power on reset
        DelayPORXLCD();
 //-------------------reset procedure through software----------------------       
		 WriteCmdXLCD(0x30);
			Delay10KTCYx(0x05);

		 WriteCmdXLCD(0x30);
			Delay10KTCYx(0x01);


		 WriteCmdXLCD(0x32);
		while( BusyXLCD() );
//------------------------------------------------------------------------------------------


        // Set data interface width, # lines, font
        while(BusyXLCD());              // Wait if LCD busy
        WriteCmdXLCD(lcdtype);          // Function set cmd

        // Turn the display on then off
        while(BusyXLCD());              // Wait if LCD busy
        WriteCmdXLCD(DOFF&CURSOR_OFF&BLINK_OFF);        // Display OFF/Blink OFF
        while(BusyXLCD());              // Wait if LCD busy
        WriteCmdXLCD(DON&CURSOR_ON&BLINK_ON);           // Display ON/Blink ON

        // Clear display
        while(BusyXLCD());              // Wait if LCD busy
        WriteCmdXLCD(0x01);             // Clear display

        // Set entry mode inc, no shift
        while(BusyXLCD());              // Wait if LCD busy
        WriteCmdXLCD(SHIFT_CUR_LEFT);   // Entry Mode

        // Set DD Ram address to 0
        while(BusyXLCD());              // Wait if LCD busy
        SetDDRamAddr(0x80);                // Set Display data ram address to 0

        return;
}

