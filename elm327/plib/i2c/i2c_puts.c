#include <p18cxxx.h>
#include <i2c.h>


/********************************************************************
*     Function Name:    putsI2C                                     *
*     Return Value:     error condition status                      *
*     Parameters:       address of write string storage location    *
*     Description:      This routine writes a string to the I2C bus,*
*                       until a null character is reached. If Master*
*                       function putcI2C is called. When trans-     *
*                       mission is complete then test for ack-      *
*                       nowledge bit. If Slave transmitter wait for *
*                       null character or not ACK received from bus *
*                       device.                                     *
********************************************************************/
#if defined (I2C_V1)

signed char putsI2C( unsigned char *wrptr )
{
	  unsigned char temp;
  while ( *wrptr )                // transmit data until null character 
  {
    if ( SSPCON1bits.SSPM3 )      // if Master transmitter then execute the following
    {
	  temp = putcI2C ( *wrptr );
	  if (temp ) return ( temp );            // return with write collision error
    
//      if ( putcI2C ( *wrptr ) )   // write 1 byte
//      {
//        return ( -3 );            // return with write collision error
//      }
//      IdleI2C();                  // test for idle condition
//      if ( SSPCON2bits.ACKSTAT )  // test received ack bit state
//      {
//        return ( -2 );            // bus device responded with  NOT ACK
//      }                           // terminate putsI2C() function
    }

    else                          // else Slave transmitter
    {
      PIR1bits.SSPIF = 0;         // reset SSPIF bit
      SSPBUF = *wrptr;            // load SSPBUF with new data
      SSPCON1bits.CKP = 1;        // release clock line 
      while ( !PIR1bits.SSPIF );  // wait until ninth clock pulse received

      if ( ( SSPCON1bits.CKP ) && ( !SSPSTATbits.BF ) )// if R/W=0 and BF=0, NOT ACK was received
      {
        return ( -2 );            // terminate PutsI2C() function
      }
    }

  wrptr ++;                       // increment pointer

  }                               // continue data writes until null character

  return ( 0 );
}

#endif

#if defined (I2C_V4)

signed char putsI2C( unsigned char *wrptr )
{
	  unsigned char temp;
  while ( *wrptr )                // transmit data until null character 
  {
    if ( (SSPCON&0x0F)==0x0B )      // if Master I2C in firmware,then execute the following
    {
	  temp = putcI2C ( *wrptr );
	  if (temp ) return ( temp );            // return with write collision error
    
//      if ( putcI2C ( *wrptr ) )   // write 1 byte
//      {
//        return ( -3 );            // return with write collision error
//      }
//      IdleI2C();                  // test for idle condition
//      if ( SSPCON2bits.ACKSTAT )  // test received ack bit state
//      {
//        return ( -2 );            // bus device responded with  NOT ACK
//      }                           // terminate putsI2C() function
    }

    else                          // else Slave transmitter
    {
      PIR1bits.SSPIF = 0;         // reset SSPIF bit
      SSPBUF = *wrptr;            // load SSPBUF with new data
      SSPCONbits.CKP = 1;        // release clock line 
      while ( !PIR1bits.SSPIF );  // wait until ninth clock pulse received

      if ( ( SSPCONbits.CKP ) && ( !SSPSTATbits.BF ) )// if R/W=0 and BF=0, NOT ACK was received
      {
        return ( -2 );            // terminate PutsI2C() function
      }
    }

  wrptr ++;                       // increment pointer

  }                               // continue data writes until null character

  return ( 0 );
}

#endif
