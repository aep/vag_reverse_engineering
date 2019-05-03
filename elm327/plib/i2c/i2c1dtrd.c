#include <p18cxxx.h>
#include <i2c.h>

/********************************************************************
*     Function Name:    DataRdyI2C1                                 *
*     Return Value:     status byte to indicate if BF = 1           *
*     Parameters:       void                                        *
*     Description:      Determine if there is a byte to be read     *
*                       from the SSP1BUF register.                  *
********************************************************************/
#undef DataRdyI2C1

#if defined (I2C_V2) || defined (I2C_V3) || defined (I2C_V5) || defined (I2C_V6) || defined (I2C_V6_1) || defined (I2C_V6_2)
unsigned char DataRdyI2C1( void )
{
  if ( SSP1STATbits.BF )          // test if buffer full bit is set     
    return ( +1 );                // data in SSP1BUF register
  else
    return ( 0 );                 // no data in SSP1BUF register
}
#endif
