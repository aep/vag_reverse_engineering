
#include <p18cxxx.h>
#include <delays.h>
#include <sw_i2c.h>

far unsigned char I2C_BUFFER;    // temp buffer for R/W operations
far unsigned char BIT_COUNTER;   // temp bufffer for bit counting

/********************************************************************
*     Function Name:    unsigned int SWReadI2C(void)                *
*     Return Value:     data byte or error condition                *
*     Parameters:       void                                        *
*     Description:      Read single byte from I2C bus.              *
********************************************************************/
signed int SWReadI2C( void )
{
  BIT_COUNTER = 8;                // set bit count for byte 
  SCLK_LAT = 0;                   // set clock pin latch to 0

  do
  {
    CLOCK_LOW;                    // set clock pin output to drive low
    DATA_HI;                      // release data line to float high
    Delay10TCY();                 // user may need to modify based on Fosc
    CLOCK_HI;                     // release clock line to float high
    Delay1TCY();                  // user may need to modify based on Fosc
    Delay1TCY();

    if ( !SCLK_PIN )              // test for clock low
    {
      if ( Clock_test( ) )        // clock wait routine
      {
        return ( -2 );            // return with error condition       
      }
    }

    I2C_BUFFER <<= 1;             // shift composed byte by 1
    I2C_BUFFER &= 0xFE;           // clear bit 0

    if ( DATA_PIN )               // is data line high
     I2C_BUFFER |= 0x01;          // set bit 0 to logic 1
   
  } while ( --BIT_COUNTER );      // stay until 8 bits have been acquired

  return ( (unsigned int) I2C_BUFFER ); // return with data
}

