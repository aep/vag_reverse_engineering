#include <p18cxxx.h>
#include <i2c.h>


/********************************************************************
*     Function Name:    EEByteWrite                                 *
*     Return Value:     error condition status                      *
*     Parameters:       EE memory device control, address and data  *
*                       bytes.                                      *
*     Description:      Write single data byte to I2C EE memory     *
*                       device. This routine can be used for any I2C*
*                       EE memory device, which only uses 1 byte of *
*                       address data as in the 24LC01B/02B/04B/08B. *
*                                                                   *  
********************************************************************/
#if defined (I2C_V1) 
signed char EEByteWrite( unsigned char control, unsigned char address, unsigned char data )
{
  IdleI2C();                      // ensure module is idle
  StartI2C();                     // initiate START condition
  while ( SSPCON2bits.SEN );      // wait until start condition is over 
  if ( PIR2bits.BCLIF )           // test for bus collision
  {
    return ( -1 );                // return with Bus Collision error 
  }
  else                            // start condition successful
  {
    if ( WriteI2C( control ) )    // write byte - R/W bit should be 0
    {
	  StopI2C(); 
      return ( -3 );              // set error for write collision
    }

    //IdleI2C();                    // ensure module is idle
    if ( !SSPCON2bits.ACKSTAT )   // test for ACK condition received
    { 
      if ( WriteI2C( address ) )  // write word address for EEPROM
      {
	    StopI2C(); 
        return ( -3 );            // set error for write collision
      }

      //IdleI2C();                  // ensure module is idle
      if ( !SSPCON2bits.ACKSTAT ) // test for ACK condition received
      { 
        if ( WriteI2C( data ) )   // data byte for EEPROM
        {
		  StopI2C(); 
          return ( -3 );          // set error for write collision
        }
      }
      else
      {
	    StopI2C(); 
        return ( -2 );            // return with Not Ack error condition   
      }
    }
    else
    {
	  StopI2C(); 
      return ( -2 );              // return with Not Ack error condition   
    }
  }

  //IdleI2C();                      // ensure module is idle  
  StopI2C();                      // send STOP condition
  while ( SSPCON2bits.PEN );      // wait until stop condition is over 
  if ( PIR2bits.BCLIF )           // test for bus collision
  {
    return ( -1 );                // return with Bus Collision error 
  }
  return ( 0 );                   // return with no error
}

#endif
