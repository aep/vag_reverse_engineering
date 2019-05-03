#include <p18cxxx.h>
#include <i2c.h>


/*********************************************************************
*     Function Name:    EEAckPolling1                                *
*     Return Value:     error condition status                       *
*     Parameters:       EE memory control byte                       *
*     Description:      Acknowledge polling of I2C1 EE memory        *
*                       device. This routine can be used for most    *
*                       I2C EE memory devices which uses acknowledge *
*                       polling.                                     *
*********************************************************************/
#if defined (I2C_V2) || defined (I2C_V3)  || defined (I2C_V5) || defined (I2C_V6) || defined (I2C_V6_1) || defined (I2C_V6_2)
signed char EEAckPolling1( unsigned char control )
{   
  IdleI2C1();                      // ensure module is idle 
  StartI2C1();                     // initiate START condition
  while ( SSP1CON2bits.SEN );      // wait until start condition is over 
  if ( PIR2bits.BCL1IF )           // test for bus collision
  {
    return ( -1 );                 // return with Bus Collision error 
  }

  else
  {
    if ( WriteI2C1( control ) == -1)    // write byte - R/W bit should be 0
    {
	  StopI2C1();  
      return ( -3 );               // set error for write collision
    }

    while ( SSP1CON2bits.ACKSTAT ) // test for ACK condition received
    {
      RestartI2C1();               // initiate Restart condition
      while ( SSP1CON2bits.RSEN ); // wait until re-start condition is over 
      if ( PIR2bits.BCL1IF )       // test for bus collision
      {
        return ( -1 );             // return with Bus Collision error 
      }
	  if ( WriteI2C1( control ) == -1)  // write byte - R/W bit should be 0
      {
	   StopI2C1();  
       return ( -3 );             // set error for write collision
      }
    }
  }
       
  StopI2C1();                      // send STOP condition
  while ( SSP1CON2bits.PEN );      // wait until stop condition is over         
  if ( PIR2bits.BCL1IF )           // test for bus collision
  {
    return ( -1 );                 // return with Bus Collision error 
  }
  return ( 0 );                    // return with no error     
}
#endif


