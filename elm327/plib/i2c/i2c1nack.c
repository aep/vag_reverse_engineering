#include <p18cxxx.h>
#include <i2c.h>


/********************************************************************
*     Function Name:    NotAckI2C1                                  *
*     Return Value:     void                                        *
*     Parameters:       void                                        *
*     Description:      Initiate NOT ACK bus condition.             *
********************************************************************/
#undef NotAckI2C1
#if defined (I2C_V2) || defined (I2C_V3) || defined (I2C_V5) || defined (I2C_V6) || defined (I2C_V6_1) || defined (I2C_V6_2)
void NotAckI2C1( void )
{
  SSP1CON2bits.ACKDT = 1;          // set acknowledge bit for not ACK
  SSP1CON2bits.ACKEN = 1;          // initiate bus acknowledge sequence
}
#endif
