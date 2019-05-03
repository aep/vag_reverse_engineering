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
;*      Function Name:  WriteUART                                       *
;*      Return Value:   void                                            *
;*      Parameters:     data: byte to send out the UART                 *
;*      Description:    This routine sends a byte out the TXD pin.      *
;*      Special Note:   The user must provide a routine:                * 
;*                      DelayTXBit():                                   *
;*                        DelayTXBit should have:                       *
;*                              8 Tcy for overhead                      *
;*                              2 Tcy call to DelayTXBit                *
;*                              ? Tcy                                   *
;*                              2 Tcy for return from DelayTXBit        *
;*                      = (((2*OSC_FREQ)/(4*BAUDRATE))+1)/2  Tcy        *
;************************************************************************
WriteUART
        banksel uartdata
        ; Retrieve character from stack.
        movlw   0xFF
        movff   PLUSW1,uartdata

        movlw   0x09                    ; Set bit counter for 9 bits
        movwf   BitCount
        bcf     STATUS,C        ; Send start bit (carry = 0)
        banksel SWTXD
        goto    SendStart
SendBit
        banksel uartdata
        rrcf    uartdata,F              ; Rotate next bit into carry
SendStart
        banksel SWTXD
        btfss   STATUS,C                ; Set or clear TXD pin according
        bcf     SWTXD,SWTXDpin  ; to what is in the carry
        btfsc   STATUS,C
        bsf     SWTXD,SWTXDpin
        call    DelayTXBitUART          ; Delay for 1 bit time
        banksel BitCount
        decfsz  BitCount,F              ; Count only 9 bits
        goto    SendBit
        banksel SWTXD
        bsf     SWTXD,SWTXDpin  ; Stop bit is high
        call    DelayTXBitUART          ; Delay for stop bit
        return

        GLOBAL  WriteUART

        END
