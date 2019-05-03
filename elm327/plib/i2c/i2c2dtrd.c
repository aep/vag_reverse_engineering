#include <p18cxxx.h>
#include <i2c.h>

/********************************************************************
*     Function Name:    DataRdyI2C2                                 *
*     Return Value:     status byte to indicate if BF = 1           *
*     Parameters:       void                                        *
*     Description:      Determine if there is a byte to be read     *
*                       from the SSP2BUF register.                  *
********************************************************************/
#if defined (I2C_V3) || defined (I2C_V6) || defined (I2C_V6_1)
#undef DataRdyI2C2
unsigned char DataRdyI2C2( void )
{
  if ( SSP2STATbits.BF )          // test if buffer full bit is set     
    return ( +1 );                // data in SSP2BUF register
  else
    return ( 0 );                 // no data in SSP2BUF register
}
#endif
