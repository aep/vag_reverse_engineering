#include <p18cxxx.h>
#include <i2c.h>


/*********************************************************************
*     Function Name:    EERandomRead1                                *
*     Return Value:     error condition status and/or data byte      *
*     Parameters:       EE memory control byte with R/W set to 1     *
*     Description:      Reads 1 byte from passed address to EE memory*
*                       device. This routine can be used for any I2C *
*                       EE memory device, which only uses 1 byte of  *
*                       address data as in the 24LC01B/02B/04B/08B.  *
*                                                                    *  
*********************************************************************/
#if defined (I2C_V2) || defined (I2C_V3) || defined (I2C_V5) || defined (I2C_V6) || defined (I2C_V6_1) || defined (I2C_V6_2)
signed int EERandomRead1( unsigned char control, unsigned char address )
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
      return ( -3 );               // return with write collision error
    }

    //IdleI2C1();                    // ensure module is idle
    if ( !SSP1CON2bits.ACKSTAT )   // test for ACK condition, if received
    {
      if ( WriteI2C1( address ) )  // WRITE word address for EEPROM
      {
	    StopI2C1();  
        return ( -3 );             // return with write collision error
      }

      //IdleI2C1();                  // ensure module is idle
      if ( !SSP1CON2bits.ACKSTAT ) // test for ACK condition, if received
      {
        RestartI2C1();             // generate I2C1 bus restart condition
        while ( SSP1CON2bits.RSEN );// wait until re-start condition is over 
        if ( PIR2bits.BCL1IF )     // test for bus collision
        {
          return ( -1 );           // return with Bus Collision error 
        }
                          
        if ( WriteI2C1( control+1 ))// write 1 byte - R/W bit should be 1
        {
		  StopI2C1();  
          return ( -3 );           // return with write collision error
        }

        //IdleI2C1();                // ensure module is idle
        if ( !SSP1CON2bits.ACKSTAT )// test for ACK condition, if received
        {
          SSP1CON2bits.RCEN = 1;       // enable master for 1 byte reception
          while ( SSP1CON2bits.RCEN ); // check that receive sequence is over
          NotAckI2C1();              // send ACK condition
          while ( SSP1CON2bits.ACKEN ); // wait until ACK sequence is over 
          StopI2C1();              // send STOP condition
          while ( SSP1CON2bits.PEN ); // wait until stop condition is over 
          if ( PIR2bits.BCL1IF )   // test for bus collision
          {
           return ( -1 );          // return with Bus Collision error 
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
  return ( (unsigned int) SSP1BUF ); // return with data
}

#endif
