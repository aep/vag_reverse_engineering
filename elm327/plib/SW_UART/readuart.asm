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
;************************************************************************
;*      Function Name:  ReadUART                                        *
;*      Return Value:   char: received data                             *
;*      Parameters:     void                                            *
;*      Description:    This routine waits for a start bit, and then    *
;*                      reads all 8-bits.                               *
;*      Special Note:   The user must provide two routines:             *
;*                      DelayRXHalfBit():                               *
;*                        DelayRXHalfBit should have:                   *
;*                              5 Tcy for overhead                      *
;*                              2 Tcy call to DelayRXHalfBit            *
;*                              ? Tcy                                   *
;*                              2 Tcy for return from DelayRXHalfBit    *
;*                              = (((2*OSC_FREQ)/(8*BAUDRATE))+1)/2 Tcy *
;*                      DelayRXBit():                                   *
;*                        DelayRXBit should have:                       *
;*                              10 Tcy for overhead                     *
;*                              2 Tcy call to DelayRXBit                *
;*                              ? Tcy                                   *
;*                              2 Tcy for return from DelayRXBit        *
;*                              = (((2*OSC_FREQ)/(4*BAUDRATE))+1)/2 Tcy *
;************************************************************************
ReadUART

        banksel BitCount
        movlw   0x08                    ; Count 8-bits
        movwf   BitCount
        banksel SWRXD
WaitChar
        btfsc   SWRXD,SWRXDpin          ; Detect a start bit (low)
        goto    WaitChar
        call    DelayRXHalfBitUART      ; Delay until middle of start bit
        banksel SWRXD
        btfsc   SWRXD,SWRXDpin          ; If not still low, then go back
        goto    WaitChar                ; and wait for start bit
GetChar                                 ; Loop to get all 8-bits
        call    DelayRXBitUART          ; Delay a full bit for middle of
        banksel SWRXD
        btfss   SWRXD,SWRXDpin          ; Set or clear the carry bit
        bcf             STATUS,C        ; according to the state of the
        btfsc   SWRXD,SWRXDpin          ; RXD I/O pin
        bsf             STATUS,C
        banksel uartdata
        rrcf    uartdata,F              ; Rotate the carry into data
        decfsz  BitCount,F              ; Loop for 8-bits
        goto    GetChar
        call    DelayRXBitUART          ; Delay a full bit time, middle of start bit
        call    DelayRXHalfBitUART      ; Delay half bit for end of start bit
        nop
        banksel uartdata
        movf   uartdata,W,BANKED
        return                          ; Return received character

        GLOBAL  ReadUART

        END
