#include <p18cxxx.h>
#include <i2c.h>


/********************************************************************
*     Function Name:    EEAckPolling                                *
*     Return Value:     error condition status                      *
*     Parameters:       EE memory control byte                      *
*     Description:      Acknowledge polling of I2C EE memory        *
*                       device. This routine can be used for most   *
*                       I2C EE memory device which uses acknowledge *
*                       polling.                                    *
********************************************************************/
#if defined (I2C_V1) 
signed char EEAckPolling( unsigned char control )
{
  IdleI2C();                      // ensure module is idle 
  StartI2C();                     // initiate START condition
  while ( SSPCON2bits.SEN );      // wait until start condition is over 
  if ( PIR2bits.BCLIF )           // test for bus collision
  {
    return ( -1 );                // return with Bus Collision error 
  }

  else
  {
    if ( WriteI2C( control ) == -1)    // write byte - R/W bit should be 0
    {
	  StopI2C(); 
      return ( -3 );              // set error for write collision
    }

    while ( SSPCON2bits.ACKSTAT ) // test for ACK condition received
    {
      RestartI2C();               // initiate Restart condition
      while ( SSPCON2bits.RSEN ); // wait until re-start condition is over 
      if ( PIR2bits.BCLIF )       // test for bus collision
      {
        return ( -1 );            // return with Bus Collision error 
      }

      if ( WriteI2C( control ) == -1)  // write byte - R/W bit should be 0
      {
	    StopI2C(); 
        return ( -3 );            // set error for write collision
      }
    }
  }
         
  StopI2C();                      // send STOP condition
  while ( SSPCON2bits.PEN );      // wait until stop condition is over         
  if ( PIR2bits.BCLIF )           // test for bus collision
  {
    return ( -1 );                // return with Bus Collision error 
  }
  return ( 0 );                   // return with no error     
}
#endif
