#include <p18cxxx.h>
#include <i2c.h>


/********************************************************************
*     Function Name:    EERandomRead                                *
*     Return Value:     error condition status and/or data byte     *
*     Parameters:       EE memory control byte with R/W set to 1    *
*     Description:      Reads 1 byte from passed address to EE memory*
*                       device. This routine can be used for any I2C*
*                       EE memory device, which only uses 1 byte of *
*                       address data as in the 24LC01B/02B/04B/08B. *
*                                                                   *  
********************************************************************/
#if defined (I2C_V1) 

signed int EERandomRead( unsigned char control, unsigned char address )
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
    if ( WriteI2C( control ) )    // write 1 byte
    {
	  StopI2C(); 
      return ( -3 );              // return with write collision error
    }

    //IdleI2C();                    // ensure module is idle
    if ( !SSPCON2bits.ACKSTAT )   // test for ACK condition, if received
    {
      if ( WriteI2C( address ) )  // WRITE word address for EEPROM
      {
	    StopI2C(); 
        return ( -3 );            // return with write collision error
      }

      //IdleI2C();                  // ensure module is idle
      if ( !SSPCON2bits.ACKSTAT ) // test for ACK condition, if received
      {
        RestartI2C();             // generate I2C bus restart condition
        while ( SSPCON2bits.RSEN );// wait until re-start condition is over 
        if ( PIR2bits.BCLIF )     // test for bus collision
        {
          return ( -1 );          // return with Bus Collision error 
        }
                          
        if ( WriteI2C( control+1 ) )// write 1 byte - R/W bit should be 1
        {
		  StopI2C(); 
          return ( -3 );          // return with write collision error
        }

        //IdleI2C();                // ensure module is idle
        if ( !SSPCON2bits.ACKSTAT )// test for ACK condition, if received
        {
          SSPCON2bits.RCEN = 1;       // enable master for 1 byte reception
          while ( SSPCON2bits.RCEN ); // check that receive sequence is over
          NotAckI2C();              // send ACK condition
          while ( SSPCON2bits.ACKEN ); // wait until ACK sequence is over 
          StopI2C();              // send STOP condition
          while ( SSPCON2bits.PEN ); // wait until stop condition is over 
          if ( PIR2bits.BCLIF )   // test for bus collision
          {
           return ( -1 );         // return with Bus Collision error 
          }
        }
        else
        {
		  StopI2C(); 
          return ( -2 );          // return with Not Ack error
        }

      }
      else
      {
	    StopI2C(); 
        return ( -2 );            // return with Not Ack error
      }
    }
    else
    {
	  StopI2C(); 
      return ( -2 );              // return with Not Ack error
    }
  }
  return ( (unsigned int) SSPBUF );     // return with data
}

#endif
