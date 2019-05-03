#include <p18cxxx.h>
#include <i2c.h>


/********************************************************************
*     Function Name:    EECurrentAddRead                            *
*     Return Value:     error condition status or data byte         *
*     Parameters:       EE memory control byte with R/W set to 1    *
*     Description:      Reads data at current address of EE memory  *
*                       device. This routine can be used for any I2C*
*                       EE memory device, which only uses 1 byte of *
*                       address data as in the 24LC01B/02B/04B/08B. *
*                                                                   *  
********************************************************************/
#if defined (I2C_V1) 

signed int EECurrentAddRead( unsigned char control )
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
    if ( WriteI2C( control ) )    // write byte - R/W bit should be 0
    {
	  StopI2C(); 
      return ( -3 );              // set error for write collision
    }

    //IdleI2C();                    // ensure module is idle
    if ( !SSPCON2bits.ACKSTAT )   // test for ACK condition received
    { 
      SSPCON2bits.RCEN = 1;       // enable master for 1 byte reception
      while ( SSPCON2bits.RCEN ); // check that receive sequence is over
      NotAckI2C();                // send NOT ACK condition
      while ( SSPCON2bits.ACKEN );// wait until ACK sequence is over                        
      StopI2C();                  // send STOP condition
      while ( SSPCON2bits.PEN );  // wait until stop condition is over 
      if ( PIR2bits.BCLIF )       // test for bus collision
      {
        return ( -1 );            // return with Bus Collision error 
      }
    }
    else
    {
	  StopI2C(); 
      return ( -2 );              // return with Not Ack error condition
    }
  }
  return ( (unsigned int) SSPBUF ); // return with contents of SSPBUF
}

#endif
