#include <p18cxxx.h>
#include <i2c.h>


/********************************************************************
*     Function Name:    EECurrentAddRead2                           *
*     Return Value:     error condition status or data byte         *
*     Parameters:       EE memory control byte with R/W set to 1    *
*     Description:      Reads data at current address of EE memory  *
*                       device. This routine can be used for any I2C*
*                       EE memory device, which only uses 1 byte of *
*                       address data as in the 24LC01B/02B/04B/08B. *
*                                                                   *  
********************************************************************/
#if defined (I2C_V3) || defined (I2C_V6) || defined (I2C_V6_1)
signed int EECurrentAddRead2( unsigned char control )
{
  IdleI2C2();                      // ensure module is idle
  StartI2C2();                     // initiate START condition
  while ( SSP2CON2bits.SEN );      // wait until start condition is over 
#if defined (I2C_V3) || defined (I2C_V6)
  if ( PIR3bits.BCL2IF )           // test for bus collision
#elif defined (I2C_V6_1)
  if ( PIR2bits.BCL2IF )           // test for bus collision
#endif  
  {
    return ( -1 );                 // return with Bus Collision error 
  }
  else
  {
    if ( WriteI2C2( control ) )    // write byte - R/W bit should be 0
    {
	  StopI2C2(); 
      return ( -3 );               // set error for write collision
    }

    //IdleI2C2();                    // ensure module is idle
    if ( !SSP2CON2bits.ACKSTAT )   // test for ACK condition received
    { 
      SSP2CON2bits.RCEN = 1;       // enable master for 1 byte reception
      while ( SSP2CON2bits.RCEN ); // check that receive sequence is over
      NotAckI2C2();                // send NOT ACK condition
      while ( SSP2CON2bits.ACKEN );// wait until ACK sequence is over                        
      StopI2C2();                  // send STOP condition
      while ( SSP2CON2bits.PEN );  // wait until stop condition is over 
#if defined (I2C_V3) || defined (I2C_V6)
  if ( PIR3bits.BCL2IF )           // test for bus collision
#elif defined (I2C_V6_1)
  if ( PIR2bits.BCL2IF )           // test for bus collision
#endif  
      {
        return ( -1 );             // return with Bus Collision error 
      }
    }
    else
    {
	  StopI2C2(); 
      return ( -2 );               // return with Not Ack error condition
    }
  }
  return ( (unsigned int) SSP2BUF ); // return with contents of SSP2BUF
}
#endif
