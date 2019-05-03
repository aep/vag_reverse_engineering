#include <p18cxxx.h>
#include <i2c.h>


/********************************************************************
*     Function Name:    RestartI2C2                                 *
*     Return Value:     void                                        *
*     Parameters:       void                                        *
*     Description:      Send I2C2 bus restart condition.            *
********************************************************************/
#undef RestartI2C2
#if defined (I2C_V3) || defined (I2C_V6) || defined (I2C_V6_1)
void RestartI2C2( void )
{
  SSP2CON2bits.RSEN = 1;           // initiate bus restart condition
}
#endif
