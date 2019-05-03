
#include <p18cxxx.h>
#include <delays.h>
#include "i2c_data.h"

/**********************************************************************
*     Function Name:    signed char SWWriteI2C(unsigned char data_out)*
*     Return Value:     error condition if bus error occurred         *
*     Parameters:       Single data byte for I2C bus.                 *
*     Description:      This routine writes a single byte to the      *
*                       I2C bus.                                      *
**********************************************************************/
signed char SWWriteI2C( unsigned char data_out )
{
  BIT_COUNTER = 8;                // initialize bit counter
  I2C_BUFFER = data_out;          // data to send out
  SCLK_LAT = 0;                   // set latch to 0
                                 
  do
  {
    if ( !SCLK_PIN )              // test if clock is low
    {                             // if it is then ..
      if ( Clock_test( ) )        // wait on clock for a short time
      {
        return ( -1 );            // return with error condition      
      }
    }

    else 
    {
#ifndef _OMNI_CODE_
     I2C_BUFFER &= 0xFF;          // generate movlb instruction
      _asm
      rlcf I2C_BUFFER,1,1         // rotate into carry and test  
      _endasm
#else
      if (STATUSbits.C == 1)
              I2C_BUFFER = (I2C_BUFFER << 1) | 0x1;
      else
              I2C_BUFFER = I2C_BUFFER << 1;
#endif

      if ( STATUS & 0x01 )        // if carry set, transmit out logic 1
      {
       CLOCK_LOW;                 // set clock pin output to drive low
       DATA_HI;                   // release data line to float high 
       Delay10TCY();              // user may need to modify based on Fosc
       CLOCK_HI;                  // release clock line to float high 
       Delay10TCY();              // user may need to modify based on Fosc
      }
      else                        // transmit out logic 0
      {
        CLOCK_LOW;                // set clock pin output to drive low
        DATA_LAT = 0;             // set data pin latch to 0
        DATA_LOW;                 // set data pin output to drive low 
        Delay10TCY();             // user may need to modify based on Fosc
        CLOCK_HI;                 // release clock line to float high 
        Delay10TCY();             // user may need to modify based on Fosc
      }

     BIT_COUNTER --;              // reduce bit counter by 1
    }
  } while ( BIT_COUNTER );        // stay in transmit loop until byte sent 

  return ( 0 );                   // return with no error
}

