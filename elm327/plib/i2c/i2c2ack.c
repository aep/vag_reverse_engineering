#include <p18cxxx.h>
#include <i2c.h>


/********************************************************************
*     Function Name:    AckI2C2                                      *
*     Return Value:     void                                        *
*     Parameters:       void                                        *
*     Description:      Initiate ACK bus condition.                 *
********************************************************************/
#if defined (I2C_V3) || defined (I2C_V6) || defined (I2C_V6_1) 
#undef AckI2C2
void AckI2C2( void )
{
  SSP2CON2bits.ACKDT = 0;           // set acknowledge bit state for ACK
  SSP2CON2bits.ACKEN = 1;           // initiate bus acknowledge sequence
}
#endif
