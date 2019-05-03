#include <p18cxxx.h>
#include <i2c.h>


/********************************************************************
*     Function Name:    StopI2C2                                    *
*     Return Value:     void                                        *
*     Parameters:       void                                        *
*     Description:      Send I2C2 bus stop condition.               *
********************************************************************/
#undef StopI2C2
#if defined (I2C_V3) || defined (I2C_V6) || defined (I2C_V6_1)
void StopI2C2( void )
{
  SSP2CON2bits.PEN = 1;            // initiate bus stop condition
}
#endif
