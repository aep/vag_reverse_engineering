#include <p18cxxx.h>
#include <xlcd.h>

/********************************************************************
*       Function Name:  SetCGRamAddr                                *
*       Return Value:   void                                        *
*       Parameters:     CGaddr: character generator ram address     *
*       Description:    This routine sets the character generator   *
*                       address of the Hitachi HD44780 LCD          *
*                       controller. The user must check to see if   *
*                       the LCD controller is busy before calling   *
*                       this routine.                               *
********************************************************************/
void SetCGRamAddr(unsigned char CGaddr)
{
#ifdef BIT8                                     // 8-bit interface
        TRIS_DATA_PORT = 0;                     // Make data port ouput
        DATA_PORT = CGaddr | 0b01000000;        // Write cmd and address to port
        RW_PIN = 0;                             // Set control signals
        RS_PIN = 0;
        DelayFor18TCY();
        E_PIN = 1;                              // Clock cmd and address in
        DelayFor18TCY();
        E_PIN = 0;
        DelayFor18TCY();
        TRIS_DATA_PORT = 0xff;                  // Make data port inputs
#else                                           // 4-bit interface
#ifdef UPPER                                    // Upper nibble interface
        TRIS_DATA_PORT &= 0x0f;                 // Make nibble input
        DATA_PORT &= 0x0f;                      // and write upper nibble
        DATA_PORT |= ((CGaddr | 0b01000000) & 0xf0);
#else                                           // Lower nibble interface
        TRIS_DATA_PORT &= 0xf0;                 // Make nibble input
        DATA_PORT &= 0xf0;                      // and write upper nibble
        DATA_PORT |= (((CGaddr |0b01000000)>>4) & 0x0f);
#endif
        RW_PIN = 0;                             // Set control signals
        RS_PIN = 0;
        DelayFor18TCY();
        E_PIN = 1;                              // Clock cmd and address in
        DelayFor18TCY();
        E_PIN = 0;
#ifdef UPPER                                    // Upper nibble interface
        DATA_PORT &= 0x0f;                      // Write lower nibble
        DATA_PORT |= ((CGaddr<<4)&0xf0);
#else                                           // Lower nibble interface
        DATA_PORT &= 0xf0;                      // Write lower nibble
        DATA_PORT |= (CGaddr&0x0f);
#endif
        DelayFor18TCY();
        E_PIN = 1;                              // Clock cmd and address in
        DelayFor18TCY();
        E_PIN = 0;
#ifdef UPPER                                    // Upper nibble interface
        TRIS_DATA_PORT |= 0xf0;                 // Make inputs
#else                                           // Lower nibble interface
        TRIS_DATA_PORT |= 0x0f;                 // Make inputs
#endif
#endif
        return;
}

