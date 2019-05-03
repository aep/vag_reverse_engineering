#include <p18cxxx.h>
#include <i2c.h>


/********************************************************************
*     Function Name:    StartI2C                                    *
*     Return Value:     void                                        *
*     Parameters:       void                                        *
*     Description:      Send I2C bus start condition.               *
********************************************************************/
#if defined (I2C_V1)
#undef StartI2C
void StartI2C( void )
{
  SSPCON2bits.SEN = 1;            // initiate bus start condition
}

#endif
