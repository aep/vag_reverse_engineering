#include <p18cxxx.h>
#include <i2c.h>


/********************************************************************
*     Function Name:    EEPageWrite2                                *
*     Return Value:     error condition status                      *
*     Parameters:       EE memory control, address and pointer 1    *
*     Description:      Writes data string to I2C2 EE memory        *
*                       device. This routine can be used for any I2C*
*                       EE memory device, which only uses 1 byte of *
*                       address data as in the 24LC01B/02B/04B/08B. *
*                                                                   *  
********************************************************************/
#if defined (I2C_V3) || defined (I2C_V6) || defined (I2C_V6_1)
signed char EEPageWrite2( unsigned char control, unsigned char address, unsigned char *wrptr )
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
    if ( WriteI2C2( control ) )    // write 1 byte - R/W bit should be 0
    {
	  StopI2C2(); 
      return ( -3 );               // return with write collision error
    }

    //IdleI2C2();                    // ensure module is idle
    if ( !SSP2CON2bits.ACKSTAT )   // test for ACK condition, if received 
    { 
      if ( WriteI2C2( address ) )  // write address byte to EEPROM
      {
	    StopI2C2(); 
        return ( -3 );             // return with write collision error
      }

      //IdleI2C2();                  // ensure module is idle
      if ( !SSP2CON2bits.ACKSTAT ) // test for ACK condition, if received
      {
        if ( putsI2C2( wrptr ) )
        {
		  StopI2C2(); 
          return( -4 );            // bus device responded possible error
        }
      }
      else
      {
	    StopI2C2(); 
        return ( -2 );             // return with Not Ack error
      }
    }
    else
    {
	  StopI2C2(); 
      return ( -2 );               // return with Not Ack error
    }
  }

  //IdleI2C2();                      // ensure module is idle
  StopI2C2();                      // send STOP condition
  while ( SSP2CON2bits.PEN );      // wait until stop condition is over 
#if defined (I2C_V3) || defined (I2C_V6)
  if ( PIR3bits.BCL2IF )           // test for bus collision
#elif defined (I2C_V6_1)
  if ( PIR2bits.BCL2IF )           // test for bus collision
#endif  
  {
    return ( -1 );                 // return with Bus Collision error 
  }
  return ( 0 );                    // return with no error
}
#endif
