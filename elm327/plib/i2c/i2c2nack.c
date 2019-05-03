#include <p18cxxx.h>
#include <i2c.h>


/********************************************************************
*     Function Name:    NotAckI2C2                                  *
*     Return Value:     void                                        *
*     Parameters:       void                                        *
*     Description:      Initiate NOT ACK bus condition.             *
********************************************************************/
#undef NotAckI2C2
#if defined (I2C_V3) || defined (I2C_V6) || defined (I2C_V6_1)
void NotAckI2C2( void )
{
  SSP2CON2bits.ACKDT = 1;          // set acknowledge bit for not ACK
  SSP2CON2bits.ACKEN = 1;          // initiate bus acknowledge sequence
}
#endif
