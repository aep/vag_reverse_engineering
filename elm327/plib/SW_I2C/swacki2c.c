
#include <p18cxxx.h>
#include <delays.h>
#include "i2c_data.h"

/********************************************************************
*     Function Name:    signed char SWAckI2C(void)                  *
*     Return Value:     error condition status                      *
*     Parameters:       void                                        *
*     Description:      This function generates a bus acknowledge   *
*                       sequence.                                   *
********************************************************************/
signed char SWAckI2C( void )
{
  SCLK_LAT = 0;                   // set clock pin latch to 0  
  CLOCK_LOW;                      // set clock pin to output to drive low
  DATA_HI;                        // release data line to float high 
  Delay10TCY();                   // user may need to modify based on Fosc
  CLOCK_HI;                      // release clock line to float high
  Delay1TCY();                    // 1 cycle delay
  Delay1TCY();                    // 1 cycle delay

  if ( DATA_PIN )                 // error if ack = 1, slave did not ack
  {
    return ( -1 );                // return with acknowledge error
  }
  else
  {
    return ( 0 );                 // return with no error
  }
}

