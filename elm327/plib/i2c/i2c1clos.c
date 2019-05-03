#include <p18cxxx.h>
#include <i2c.h>

/********************************************************************
*     Function Name:    CloseI2C1                                   *
*     Return Value:     void                                        *
*     Parameters:       void                                        *
*     Description:      This function disables the SSP1 module. Pin *
*                       I/O returns under the control of the port   *
*                       registers.                                  *
********************************************************************/
#undef CloseI2C1
#if defined (I2C_V2) || defined (I2C_V3) || defined (I2C_V5) || defined (I2C_V6) || defined (I2C_V6_1) || defined (I2C_V6_2)
void CloseI2C1( void )
{
  SSP1CON1 &= 0xDF;                // disable synchronous serial port
}
#endif
