#include <p18cxxx.h>
#include <i2c.h>


/*********************************************************************
*     Function Name:    putsI2C2                                     *
*     Return Value:     error condition status                       *
*     Parameters:       address of write string storage location     *
*     Description:      This routine writes a string to the I2C2 bus,*
*                       until a null character is reached. If Master *
*                       function putcI2C is called. When trans-      *
*                       mission is complete then test for ack-       *
*                       nowledge bit. If Slave transmitter wait for  *
*                       null character or not ACK received from bus  *
*                       device.                                      *
*********************************************************************/
#if defined (I2C_V3) || defined (I2C_V6) || defined (I2C_V6_1)
signed char putsI2C2( unsigned char *wrptr )
{
   unsigned char temp;  
	while ( *wrptr )                 // transmit data until null character 
  {
    if ( SSP2CON1bits.SSPM3 )      // if Master transmitter then execute the following
    {  
	   temp = putcI2C2 ( *wrptr );
	   if (temp ) return ( temp );            // return with write collision error
      //if ( putcI2C2( *wrptr ) )    // write 1 byte
      //{
       // return ( -3 );             // return with write collision error
      //}
      //IdleI2C2();                  // test for idle condition
      //if ( SSP2CON2bits.ACKSTAT )  // test received ack bit state
      //{
       // return ( -2 );             // bus device responded with  NOT ACK
      //}                            // terminate putsI2C2() function
    }

    else                           // else Slave transmitter
    {
#if defined (I2C_V3) || defined (I2C_V6)
      PIR3bits.SSP2IF = 0;         // reset SSP2IF bit
#elif defined (I2C_V6_1)
	  PIR2bits.SSP2IF = 0;         // reset SSP2IF bit
#endif		
      SSP2BUF = *wrptr;            // load SSP2BUF with new data
      SSP2CON1bits.CKP = 1;        // release clock line 
#if defined (I2C_V3) || defined (I2C_V6)
      while ( !PIR3bits.SSP2IF );  // wait until ninth clock pulse received
#elif defined (I2C_V6_1)
	  while ( !PIR2bits.SSP2IF );  // wait until ninth clock pulse received
#endif	  
	 #if defined (I2C_SFR_V1) 
     if ( ( SSP2CON1bits.CKP ) && ( !SSP2STATbits.BF ) )
	 #else
      if ( ( SSP2CON1bits.CKP ) && ( !SSP2STATbits.BF ) )// if R/W=0 and BF=0, NOT ACK was received
	 #endif 
      {
        return ( -2 );             // terminate PutsI2C2() function
      }
    }

  wrptr ++;                        // increment pointer

  }                                // continue data writes until null character

  return ( 0 );
}
#endif
