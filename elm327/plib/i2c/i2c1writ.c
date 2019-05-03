#include <p18cxxx.h>
#include <i2c.h>

/********************************************************************
*     Function Name:    WriteI2C1                                   *
*     Return Value:     Status byte for WCOL detection.             *
*     Parameters:       Single data byte for I2C1 bus.              *
*     Description:      This routine writes a single byte to the    * 
*                       I2C1 bus.                                   *
********************************************************************/
#if defined (I2C_V2) || defined (I2C_V3) || defined (I2C_V5) || defined (I2C_V6) || defined (I2C_V6_1) || defined (I2C_V6_2) 
signed char WriteI2C1( unsigned char data_out )
{
  SSP1BUF = data_out;           // write single byte to SSP1BUF
  if ( SSP1CON1bits.WCOL )      // test if write collision occurred
    return ( -1 );              // if WCOL bit is set return negative #
  else
  {
    if( ((SSP1CON1&0x0F)!=0x08) && ((SSP1CON1&0x0F)!=0x0B) )	//slave mode only 
	{
      SSP1CON1bits.CKP = 1;        // release clock line 
      while ( !PIR1bits.SSP1IF );  // wait until ninth clock pulse received
      #if defined (I2C_V6_2)
	  {
	  if ( ( !SSP1STATbits.R_NOT_W ) && ( !SSP1STATbits.BF ) )// if R/W=0 and BF=0, NOT ACK was received
      {
        return ( -2 );             //Return NACK
      }	
	  else return(0);				//Return ACK
	  }
	  #else
	  {
      if ( ( !SSP1STATbits.R_W ) && ( !SSP1STATbits.BF ) )// if R/W=0 and BF=0, NOT ACK was received
      {
        return ( -2 );             //Return NACK
      }	
	  else return(0);				//Return ACK
	  }
	  #endif
    }
	else if( ((SSP1CON1&0x0F)==0x08) || ((SSP1CON1&0x0F)==0x0B) )	//master mode only	
	{
		while( SSP1STATbits.BF );   // wait until write cycle is complete      
		IdleI2C1();                  // ensure module is idle
	    if ( SSP1CON2bits.ACKSTAT ) // test for ACK condition received
	    	 return ( -2 );				//Return NACK	
		else return ( 0 );               //Return ACK
	}
  }
}

#endif
