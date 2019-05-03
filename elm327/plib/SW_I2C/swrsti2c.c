
#include <p18cxxx.h>
#include <delays.h>
#include "i2c_data.h"

/********************************************************************
*     Function Name:    void SWRestartI2C(void)                     *
*     Return Value:     void                                        *
*     Parameters:       void                                        *
*     Description:      Send I2C bus restart condition.             *
********************************************************************/
void SWRestartI2C( void )
{
  SCLK_LAT = 0;                   // set clock pin latch to 0
  CLOCK_LOW;                      // set clock pin to output to drive low
  DATA_HI;                        // release data pin to float high
  Delay10TCY();                   // user may need to modify based on Fosc
  CLOCK_HI;                       // release clock pin to float high
  Delay10TCY();                   // user may need to modify based on Fosc
  DATA_LAT = 0;                   // set data pin latch to 0
  DATA_LOW;                       // set data pin output to drive low
  Delay10TCY();                   // user may need to modify based on Fosc
}
