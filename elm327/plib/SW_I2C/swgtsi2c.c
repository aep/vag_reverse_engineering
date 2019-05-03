
#include <p18cxxx.h>
#include <delays.h>
#include "i2c_data.h"


/********************************************************************
*     Function Name:    signed char SWGetsI2C(unsigned char *rdptr, *
*                                             unsigned char length) *
*     Return Value:     return with error condition                 *
*     Parameters:       address of read string storage location and *
*                       length of string bytes to read              *
*     Description:      This routine reads a string from the I2C    *
*                       bus.                                        *
********************************************************************/
signed char SWGetsI2C( unsigned char *rdptr,  unsigned char length )
{
  unsigned int thold;             // define auto variable

  while ( length --)              // stay in loop until byte count is zero
  {
    thold = SWGetcI2C();          // read and save 1 byte
    if ( thold & 0xFF00 )
    {
      return ( -1 );              // return with error condition
    }
    else
    {
      *rdptr++ = thold;           // save off byte read
    }

    if ( !length )                // initiate NOT ACK
    {
      CLOCK_LOW;                  // make clock pin output to drive low
      DATA_HI;                    // release data line to float high 
      Delay10TCY();               // user may need to modify based on Fosc
      CLOCK_HI;                   // release clock line to float high 
      Delay10TCY();               // user may need to modify based on Fosc
    }
    else                          // else initiate ACK condition
    {
      CLOCK_LOW;                  // make clock pin output to drive low
      DATA_LAT = 0;               // set data pin latch to 0
      DATA_LOW;                   // make data pin output to drive low
      Delay10TCY();               // user may need to modify based on Fosc
      CLOCK_HI;                   // release clock line to float high 
      Delay10TCY();               // user may need to modify based on Fosc
    }
  }   
  return( 0 );                    // return with no error
}


