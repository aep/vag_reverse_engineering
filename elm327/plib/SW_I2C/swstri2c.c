
#include <p18cxxx.h>
#include <delays.h>
#include "i2c_data.h"

/********************************************************************
*     Function Name:    void SWStartI2C(void)                       *
*     Return Value:     void                                        *
*     Parameters:       void                                        *
*     Description:      Send I2C bus start condition.               *
********************************************************************/
void SWStartI2C( void )
{
  DATA_LAT = 0;                   // set data pin latch to 0
  DATA_LOW;                       // set pin to output to drive low
  Delay10TCY();                   // user may need to modify based on Fosc
}
