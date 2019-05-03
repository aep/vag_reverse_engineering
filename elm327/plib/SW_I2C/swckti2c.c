
#include <p18cxxx.h>
#include <delays.h>
#include "i2c_data.h"

/********************************************************************
*   Function Name:      signed char Clock_test(void)                * 
*   Return Value:       error condition status                      *
*   Parameters:         void                                        *
*   Description:        This function allows for a slave I2C device *
*                       to stretch the clock low. The time period to*
*                       wait may need to be adjusted.               *
********************************************************************/
signed char Clock_test( void )
{
  Delay10TCYx(3);                 // user may need to adjust timeout period

  if ( !SCLK_PIN )                // if clock is still low after wait 
  {
    return ( -2 );                // return with clock error
  }
  else
  {
    return ( 0 );                 // return with no error
  } 
}

