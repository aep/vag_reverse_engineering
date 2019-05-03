#include <p18cxxx.h>
#include <i2c.h>


/********************************************************************
*     Function Name:    EECurrentAddRead1                           *
*     Return Value:     error condition status or data byte         *
*     Parameters:       EE memory control byte with R/W set to 1    *
*     Description:      Reads data at current address of EE memory  *
*                       device. This routine can be used for any I2C*
*                       EE memory device, which only uses 1 byte of *
*                       address data as in the 24LC01B/02B/04B/08B. *
*                                                                   *  
********************************************************************/
#if defined (I2C_V2) || defined (I2C_V3) || defined (I2C_V5) || defined (I2C_V6) || defined (I2C_V6_1) || defined (I2C_V6_2)
signed int EECurrentAddRead1( unsigned char control )
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
    if ( WriteI2C1( control ) )    // write byte - R/W bit should be 0
    {
	  StopI2C1();  
      return ( -3 );               // set error for write collision
    }

    //IdleI2C1();                    // ensure module is idle
    if ( !SSP1CON2bits.ACKSTAT )   // test for ACK condition received
    { 
      SSP1CON2bits.RCEN = 1;       // enable master for 1 byte reception
      while ( SSP1CON2bits.RCEN ); // check that receive sequence is over
      NotAckI2C1();                // send NOT ACK condition
      while ( SSP1CON2bits.ACKEN );// wait until ACK sequence is over                        
      StopI2C1();                  // send STOP condition
      while ( SSP1CON2bits.PEN );  // wait until stop condition is over 
      if ( PIR2bits.BCL1IF )       // test for bus collision
      {
        return ( -1 );             // return with Bus Collision error 
      }
    }
    else
    {
	  StopI2C1();  
      return ( -2 );               // return with Not Ack error condition
    }
  }
  return ( (unsigned int) SSP1BUF ); // return with contents of SSP1BUF
}

#endif
