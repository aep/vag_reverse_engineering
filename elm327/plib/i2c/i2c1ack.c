#include <p18cxxx.h>
#include <i2c.h>


/********************************************************************
*     Function Name:    AckI2C1                                      *
*     Return Value:     void                                        *
*     Parameters:       void                                        *
*     Description:      Initiate ACK bus condition.                 *
********************************************************************/
#undef AckI2C1
#if defined (I2C_V2) || defined (I2C_V3) || defined (I2C_V5) || defined (I2C_V6) || defined (I2C_V6_1) || defined (I2C_V6_2)
void AckI2C1( void )
{
  SSP1CON2bits.ACKDT = 0;            // set acknowledge bit state for ACK
  SSP1CON2bits.ACKEN = 1;           // initiate bus acknowledge sequence
}
#endif
