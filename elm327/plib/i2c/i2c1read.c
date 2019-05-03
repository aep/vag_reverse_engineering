#include <p18cxxx.h>
#include <i2c.h>

/********************************************************************
*     Function Name:    ReadI2C1                                    *
*     Return Value:     contents of SSP1BUF register                *
*     Parameters:       void                                        *
*     Description:      Read single byte from I2C1 bus.             *
********************************************************************/
#if defined (I2C_V2) || defined (I2C_V3) || defined (I2C_V5) || defined (I2C_V6) || defined (I2C_V6_1) || defined (I2C_V6_2)
unsigned char ReadI2C1( void )
{

if( ((SSP1CON1&0x0F)==0x08) || ((SSP1CON1&0x0F)==0x0B) )	//master mode only
  SSP1CON2bits.RCEN = 1;           // enable master for 1 byte reception
  while ( !SSP1STATbits.BF );      // wait until byte received  
  return ( SSP1BUF );              // return with read byte 
}
#endif
