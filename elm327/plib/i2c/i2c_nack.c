#include <p18cxxx.h>
#include <i2c.h>


/********************************************************************
*     Function Name:    NotAckI2C                                   *
*     Return Value:     void                                        *
*     Parameters:       void                                        *
*     Description:      Initiate NOT ACK bus condition.             *
********************************************************************/
#if defined (I2C_V1)
#undef NotAckI2C
void NotAckI2C( void )
{
  SSPCON2bits.ACKDT = 1;          // set acknowledge bit for not ACK
  SSPCON2bits.ACKEN = 1;          // initiate bus acknowledge sequence
}

#endif
