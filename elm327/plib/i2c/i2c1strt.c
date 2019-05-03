#include <p18cxxx.h>
#include <i2c.h>


/********************************************************************
*     Function Name:    StartI2C1                                   *
*     Return Value:     void                                        *
*     Parameters:       void                                        *
*     Description:      Send I2C1 bus start condition.              *
********************************************************************/
#undef StartI2C1
#if defined (I2C_V2) || defined (I2C_V3) || defined (I2C_V5) || defined (I2C_V6) || defined (I2C_V6_1) || defined (I2C_V6_2)
void StartI2C1( void )
{
  SSP1CON2bits.SEN = 1;            // initiate bus start condition
}
#endif
