  include <P18CXXX.INC>

SWTXD           equ     PORTB           ; Transmit pin port and pin
SWTXDpin        equ     4
TRIS_SWTXD      equ     TRISB           ; Transmit pin tris and pin
SWRXD           equ     PORTB           ; Receive pin port and pin
SWRXDpin        equ     5
TRIS_SWRXD      equ     TRISB           ; Receive pin tris and pin

        EXTERN  DelayRXHalfBitUART
        EXTERN  DelayRXBitUART
        EXTERN  DelayTXBitUART
        EXTERN  uartdata
        EXTERN  BitCount

UARTCODE        CODE
;********************************************************************
;*      Function Name:  OpenUART                                    *
;*      Return Value:   void                                        *
;*      Parameters:     void                                        *
;*      Description:    This routine configures the I/O pins for    *
;*                      software UART.                              *
;********************************************************************
OpenUART

        banksel SWTXD
        bcf             TRIS_SWTXD,SWTXDpin     ; Make TXD an output
        bsf             SWTXD,SWTXDpin          ; Make TXD high
        banksel SWRXD
        bsf             TRIS_SWRXD,SWRXDpin     ; Make RXD an input
        bsf             SWRXD,SWRXDpin          ; Make RXD high
        return

        GLOBAL  OpenUART
        
        END
