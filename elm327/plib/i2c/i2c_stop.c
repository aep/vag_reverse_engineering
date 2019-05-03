#include <p18cxxx.h>
#include <i2c.h>


/********************************************************************
*     Function Name:    StopI2C                                     *
*     Return Value:     void                                        *
*     Parameters:       void                                        *
*     Description:      Send I2C bus stop condition.                *
********************************************************************/
#if defined (I2C_V1)
#undef StopI2C
void StopI2C( void )
{
  SSPCON2bits.PEN = 1;            // initiate bus stop condition
}

#endif
