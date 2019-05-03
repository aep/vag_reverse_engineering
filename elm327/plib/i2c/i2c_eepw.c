#include <p18cxxx.h>
#include <i2c.h>


/********************************************************************
*     Function Name:    EEPageWrite                                 *
*     Return Value:     error condition status                      *
*     Parameters:       EE memory control, address and pointer 1    *
*     Description:      Writes data string to I2C EE memory         *
*                       device. This routine can be used for any I2C*
*                       EE memory device, which only uses 1 byte of *
*                       address data as in the 24LC01B/02B/04B/08B. *
*                                                                   *  
********************************************************************/
#if defined (I2C_V1) 

signed char EEPageWrite( unsigned char control, unsigned char address, unsigned char *wrptr )
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
    if ( WriteI2C( control ) )    // write 1 byte - R/W bit should be 0
    {
	  StopI2C(); 
      return ( -3 );              // return with write collision error
    }

    //IdleI2C();                    // ensure module is idle
    if ( !SSPCON2bits.ACKSTAT )   // test for ACK condition, if received 
    { 
      if ( WriteI2C( address ) )  // write address byte to EEPROM
      {
	    StopI2C(); 
        return ( -3 );            // return with write collision error
      }

      //IdleI2C();                  // ensure module is idle
      if ( !SSPCON2bits.ACKSTAT ) // test for ACK condition, if received
      {
        if ( putsI2C ( wrptr ) )
        {
		  StopI2C(); 
          return( -4 );           // bus device responded possible error
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

 //IdleI2C();                      // ensure module is idle
  StopI2C();                      // send STOP condition
  while ( SSPCON2bits.PEN );      // wait until stop condition is over 
  if ( PIR2bits.BCLIF )           // test for Bus collision
  {
    return ( -1 );                // return with Bus Collision error 
  }
  return ( 0 );                   // return with no error
}

#endif
