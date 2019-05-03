#include <p18cxxx.h>
#include <i2c.h>


/********************************************************************
*     Function Name:    RestartI2C                                  *
*     Return Value:     void                                        *
*     Parameters:       void                                        *
*     Description:      Send I2C bus restart condition.             *
********************************************************************/
#if defined (I2C_V1)
#undef RestartI2C
void RestartI2C( void )
{
  SSPCON2bits.RSEN = 1;           // initiate bus restart condition
}

#endif
