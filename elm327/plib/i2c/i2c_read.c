#include <p18cxxx.h>
#include <i2c.h>

/********************************************************************
*     Function Name:    ReadI2C                                     *
*     Return Value:     contents of SSPBUF register                 *
*     Parameters:       void                                        *
*     Description:      Read single byte from I2C bus.              *
********************************************************************/
#if defined (I2C_V1)
unsigned char ReadI2C( void )
{
if( ((SSPCON1&0x0F)==0x08) || ((SSPCON1&0x0F)==0x0B) )	//master mode only
  SSPCON2bits.RCEN = 1;           // enable master for 1 byte reception
  while ( !SSPSTATbits.BF );      // wait until byte received  
  return ( SSPBUF );              // return with read byte 
}
#endif

#if defined (I2C_V4)
unsigned char ReadI2C( void )
{
  while ( !SSPSTATbits.BF );      // wait until byte received  
  return ( SSPBUF );              // return with read byte 
}
#endif
