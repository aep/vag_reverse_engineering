#include <p18cxxx.h>
#include <i2c.h>


/********************************************************************
*     Function Name:    EESequentialRead1                           *
*     Return Value:     error condition status                      *
*     Parameters:       EE memory control, address, pointer and     *
*                       length bytes.                               *
*     Description:      Reads data string from I2C EE memory        *
*                       device. This routine can be used for any I2C*
*                       EE memory device, which only uses 1 byte of *
*                       address data as in the 24LC01B/02B/04B/08B. *
*                                                                   *  
********************************************************************/
#if defined (I2C_V2) || defined (I2C_V3) || defined (I2C_V5) || defined (I2C_V6) || defined (I2C_V6_1) || defined (I2C_V6_2)
signed char EESequentialRead1( unsigned char control, unsigned char address, unsigned char *rdptr, unsigned char length )
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
    if ( WriteI2C1( control ) )    // write 1 byte 
    {
	  StopI2C1();  
      return ( -3 );               // set error for write collision
    }

    //IdleI2C1();                    // ensure module is idle
    if ( !SSP1CON2bits.ACKSTAT )   // test for ACK condition, if received
    {
      if ( WriteI2C1( address ) )  // WRITE word address to EEPROM
      {
	    StopI2C1();  
        return ( -3 );             // return with write collision error
      }
 
      //IdleI2C1();                  // ensure module is idle
      if ( !SSP1CON2bits.ACKSTAT ) // test for ACK condition received
      {
        RestartI2C1();             // generate I2C bus restart condition
        while ( SSP1CON2bits.RSEN );  // wait until re-start condition is over 
        if ( WriteI2C1( control +1 ) )// WRITE 1 byte - R/W bit should be 1 for read
        {
		  StopI2C1();  
          return ( -3 );           // set error for write collision
        }
      
        //IdleI2C1();                // ensure module is idle
        if ( !SSP1CON2bits.ACKSTAT )// test for ACK condition received
        {
          if ( getsI2C1( rdptr, length ) )// read in multiple bytes
          {
            return ( -1 );         // return with Bus Collision error
          }

          NotAckI2C1();            // send not ACK condition
          while ( SSP1CON2bits.ACKEN );// wait until ACK sequence is over 
          StopI2C1();              // send STOP condition
          while ( SSP1CON2bits.PEN );// wait until stop condition is over 
          if ( PIR2bits.BCL1IF )   // test for bus collision
          {
            return ( -1 );         // return with Bus Collision error 
          }
        }
        else
        {
		  StopI2C1();  
          return ( -2 );           // return with Not Ack error
        }
      }
      else
      {
	    StopI2C1();  
        return ( -2 );             // return with Not Ack error
      } 
    }
    else
    {
	  StopI2C1();  
      return ( -2 );               // return with Not Ack error
    }
  }
  return ( 0 );                    // return with no error
}
#endif
