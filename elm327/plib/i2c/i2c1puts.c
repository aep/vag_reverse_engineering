#include <p18cxxx.h>
#include <i2c.h>


/*********************************************************************
*     Function Name:    putsI2C1                                     *
*     Return Value:     error condition status                       *
*     Parameters:       address of write string storage location     *
*     Description:      This routine writes a string to the I2C1 bus,*
*                       until a null character is reached. If Master *
*                       function putcI2C is called. When trans-      *
*                       mission is complete then test for ack-       *
*                       nowledge bit. If Slave transmitter wait for  *
*                       null character or not ACK received from bus  *
*                       device.                                      *
*********************************************************************/
#if defined (I2C_V2) || defined (I2C_V3) || defined (I2C_V5) || defined (I2C_V6) || defined (I2C_V6_1) || defined (I2C_V6_2)
signed char putsI2C1( unsigned char *wrptr )
{
   unsigned char temp;  
	while ( *wrptr )                 // transmit data until null character 
  {
    if ( SSP1CON1bits.SSPM3 )      // if Master transmitter then execute the following
    {
	  temp = putcI2C1 ( *wrptr );
	  if (temp ) return ( temp );   	
      //if ( putcI2C1( *wrptr ) )    // write 1 byte
      //{
      //  return ( -3 );             // return with write collision error
      //}
      //IdleI2C1();                  // test for idle condition
      //if ( SSP1CON2bits.ACKSTAT )  // test received ack bit state
      //{
      //  return ( -2 );             // bus device responded with  NOT ACK
      //}                            // terminate putsI2C1() function
    }

    else                           // else Slave transmitter
    {
      PIR1bits.SSP1IF = 0;         // reset SSP1IF bit
      SSP1BUF = *wrptr;            // load SSP1BUF with new data
      SSP1CON1bits.CKP = 1;        // release clock line 
      while ( !PIR1bits.SSP1IF );  // wait until ninth clock pulse received

      if ( ( SSP1CON1bits.CKP ) && ( !SSP1STATbits.BF ) )// if R/W=0 and BF=0, NOT ACK was received
      {
        return ( -2 );             // terminate PutsI2C1() function
      }
    }

  wrptr ++;                        // increment pointer

  }                                // continue data writes until null character

  return ( 0 );
}
#endif
