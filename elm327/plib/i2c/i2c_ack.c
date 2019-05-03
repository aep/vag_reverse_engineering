#include <p18cxxx.h>
#include <i2c.h>


/********************************************************************
*     Function Name:    AckI2C                                      *
*     Return Value:     void                                        *
*     Parameters:       void                                        *
*     Description:      Initiate ACK bus condition.                 *
********************************************************************/
#if defined (I2C_V1) 
#undef AckI2C
void AckI2C( void )
{
  SSPCON2bits.ACKDT = 0;           // set acknowledge bit state for ACK
  SSPCON2bits.ACKEN = 1;           // initiate bus acknowledge sequence
}

#endif
