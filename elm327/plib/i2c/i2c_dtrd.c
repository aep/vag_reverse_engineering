#include <p18cxxx.h>
#include <i2c.h>

/********************************************************************
*     Function Name:    DataRdyI2C                                  *
*     Return Value:     status byte to indicate if BF = 1           *
*     Parameters:       void                                        *
*     Description:      Determine if there is a byte to be read     *
*                       from the SSPBUF register.                   *
********************************************************************/
#if defined (I2C_V1) 
#undef DataRdyI2C
unsigned char DataRdyI2C( void )
{
  if ( SSPSTATbits.BF )           // test if buffer full bit is set     
    return ( +1 );                // data in SSPBUF register
  else
    return ( 0 );                 // no data in SSPBUF register
}
#endif
