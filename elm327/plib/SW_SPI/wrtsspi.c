#include <p18cxxx.h>
#include <sw_spi.h>

/********************************************************************
*       Function Name:  WriteSWSPI                                  *
*       Return Value:   char: received data                         *
*       Parameters:     data: data to transmit                      *
*       Description:    This routine sets the CS pin high.          *
********************************************************************/
char WriteSWSPI( char output)
{
        char BitCount;                  // Bit counter
        static char input;

        BitCount = 8;                   // Do 8-bits
        input = output;

#if defined(MODE0)                      // Mode 0
// SCK idles low
// Data output after falling edge of SCK
// Data sampled before rising edge of SCK
        SW_DOUT_PIN = 0;                // Set Dout to MSB of data
        if(input&0x80)
                SW_DOUT_PIN = 1;
        Nop();                          // Adjust for jitter
        Nop();
        do                              // Loop 8 times
        {
#ifndef _OMNI_CODE_
                STATUSbits.C = 0;       // Set the carry bit according
                if(SW_DIN_PIN)          // to the Din pin
                STATUSbits.C = 1;
                SW_SCK_PIN = 1;         // Set the SCK pin
                _asm
                rlcf  input,1,1
                _endasm
#else
                // If SW_DIN_PIN is set, then Carry bit will also be set as
                // above code. Carry bit will be reset before the left rotate
                // operation. Hence the below if condition takes care of the 
                // correctly setting the value of input after rotation as per 
                // the carry bit value which was before the operation.
                // (See the instructions generated for the rotate operation).
                if (SW_DIN_PIN)
                        input = (input << 1) | 0x1;
                else
                        input = input << 1;

                SW_SCK_PIN = 1;         // Set the SCK pin
#endif

//              Rlcf(input);            // Rotate the carry into the data byte
                Nop();                  // Produces a 50% duty cycle clock
                Nop();
                Nop();
                Nop();
                Nop();
                Nop();
                Nop();
                Nop();
                Nop();
                Nop();
                Nop();
                SW_SCK_PIN = 0;         // Clear the SCK pin
                SW_DOUT_PIN = 0;        // Set Dout to the next bit according to
                if(input&0x80)          // the MSB of data
                        SW_DOUT_PIN = 1;
                BitCount--;             // Count iterations through loop
        } while(BitCount);
#endif

#if defined(MODE1)                      // Mode1
// SCK idles high
// Data output after rising edge of SCK
// Data sampled before falling edge of SCK
        SW_DOUT_PIN = 0;                // Set the Dout pin according to
        if(input&0x80)                  // the MSB of data
                SW_DOUT_PIN = 1;
        Nop();                          // Adjust for jitter
        Nop();
        do                              // Loop 8 times
        {
#ifndef _OMNI_CODE_
                STATUSbits.C = 0;       // Set the carry bit according to
                if(SW_DIN_PIN)          // the Din pin
                        STATUSbits.C = 1;
                SW_SCK_PIN = 0;         // Clear the SCK pin
                _asm
                rlcf  input,1,1
                _endasm   		        // Rotate the carry into the data byte
#else
                // If SW_DIN_PIN is set, then Carry bit will also be set as
                // above code. Carry bit will be reset before the left rotate
                // operation. Hence the below if condition takes care of the
                // correctly setting the value of input after rotation as per
                // the carry bit value which was before the operation.
                // (See the instructions generated for the rotate operation).
                if (SW_DIN_PIN)
                        input = (input << 1) | 0x1;
                else
                        input = input << 1;

                SW_SCK_PIN = 1;         // Set the SCK pin


#endif
                Nop();                  // Produces a 50% duty cycle clock
                Nop();
                Nop();
                Nop();
                Nop();
                Nop();
                Nop();
                Nop();
                Nop();
                Nop();
                Nop();
                SW_SCK_PIN = 1;         // Set the SCK pin
                SW_DOUT_PIN = 0;        // Set the Dout pin according to the
                if(input&0x80)          // MSB of data
                        SW_DOUT_PIN = 1;
                BitCount--;             // Count iterations through loop
        } while(BitCount);
#endif

#if defined(MODE2)                      // Mode2
// SCK idles low
// Data output after rising edge of SCK
// Data sampled after falling edge of SCK
        do                              // Loop 8 times
        {
                SW_SCK_PIN = 1;         // Set the SCK pin
                SW_DOUT_PIN = 0;        // Set the Dout pin according to
                if(input&0x80)          // the MSB of data
                        SW_DOUT_PIN = 1;
#ifndef _OMNI_CODE_
                STATUSbits.C = 0;       // Set the carry bit according to
                if(SW_DIN_PIN)          // the Din pin
                        STATUSbits.C = 1;
                SW_SCK_PIN = 0;         // Clear the SCK pin
                _asm
                rlcf  input,1,1
                _endasm		            // Rotate the carry into the data byte
#else
                // If SW_DIN_PIN is set, then Carry bit will also be set as
                // above code. Carry bit will be reset before the left rotate
                // operation. Hence the below if condition takes care of the
                // correctly setting the value of input after rotation as per
                // the carry bit value which was before the operation.
                // (See the instructions generated for the rotate operation).
                if (SW_DIN_PIN)
                        input = (input << 1) | 0x1;
                else
                        input = input << 1;

                SW_SCK_PIN = 1;         // Set the SCK pin
#endif
                Nop();                  // Produces a 50% duty cycle clock
                Nop();
                Nop();
                Nop();
                Nop();
                BitCount--;             // Count loop iterations
        } while(BitCount);
#endif

#if defined(MODE3)                      // Mode 3
// SCK idles high
// Data output after falling edge of SCK
// Data sampled before rising edge of SCK
        do                              // Loop 8 times
        {
                SW_SCK_PIN = 0;         // Clear the SCK pin
                SW_DOUT_PIN = 0;        // Set the Dout pin according to 
                if(input&0x80)          // the MSB of data
                        SW_DOUT_PIN = 1;
#ifndef _OMNI_CODE_
                STATUSbits.C = 0;       // Set the carry bit according to
                if(SW_DIN_PIN)          // the state of the Din pin
                        STATUSbits.C = 1;
                SW_SCK_PIN = 1;         // Set the SCK pin
                _asm
                rlcf  input,1,1
                _endasm		            // Rotate the carry into the data byte
#else
                // If SW_DIN_PIN is set, then Carry bit will also be set as
                // above code. Carry bit will be reset before the left rotate
                // operation. Hence the below if condition takes care of the
                // correctly setting the value of input after rotation as per
                // the carry bit value which was before the operation.
                // (See the instructions generated for the rotate operation).
                if (SW_DIN_PIN)
                        input = (input << 1) | 0x1;
                else
                        input = input << 1;

                SW_SCK_PIN = 1;         // Set the SCK pin
#endif
                Nop();                  // Produces a 50% duty cycle clock
                Nop();
                Nop();
                Nop();
                Nop();
                BitCount--;             // Count loop iterations
        } while(BitCount);
#endif

        return(input);                  // Return the received data
}

