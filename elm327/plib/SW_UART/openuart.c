#include <p18cxxx.h>

#define SWTXD         PORTBbits           // Transmit pin port and pin
#define SWTXDpin      RB4
#define TRIS_SWTXD    TRISBbits           // Transmit pin tris and pin
#define TRISbit_SWTXD TRISB4
#define SWRXD         PORTBbits           // Receive pin port and pin
#define SWRXDpin      RB5
#define TRIS_SWRXD    TRISBbits           // Receive pin tris and pin
#define TRISbit_SWRXD TRISB5

/* The following extern declared symbols needs to be defined by user prior 
 * to using UART functions.
 */

extern  void DelayRXHalfBitUART(void);
extern  void DelayRXBitUART(void);
extern  void DelayTXBitUART(void);
extern  char uartdata;
extern  char BitCount;

/********************************************************************
;*      Function Name:  OpenUART                                    *
;*      Return Value:   void                                        *
;*      Parameters:     void                                        *
;*      Description:    This routine configures the I/O pins for    *
;*                      software UART.                              *
;*******************************************************************/

void OpenUART(void)
{
    TRIS_SWTXD.TRISbit_SWTXD = 0x0;
    SWTXD.SWTXDpin           = 0x1;

    TRIS_SWRXD.TRISbit_SWRXD = 0x0;
    SWRXD.SWRXDpin           = 0x1;
}


