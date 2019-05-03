#include <p18cxxx.h>
#include <i2c.h>

/********************************************************************
*     Function Name:    WriteI2C                                    *
*     Return Value:     Status byte for WCOL detection.             *
*     Parameters:       Single data byte for I2C bus.               *
*     Description:      This routine writes a single byte to the    * 
*                       I2C bus.                                    *
********************************************************************/
#if defined (I2C_V1)
signed char WriteI2C( unsigned char data_out )
{
  SSPBUF = data_out;           // write single byte to SSPBUF
  if ( SSPCON1bits.WCOL )      // test if write collision occurred
   return ( -1 );              // if WCOL bit is set return negative #
  else
  {
	if( ((SSPCON1&0x0F)!=0x08) && ((SSPCON1&0x0F)!=0x0B) )	//Slave mode only
	{
	      SSPCON1bits.CKP = 1;        // release clock line 
	      while ( !PIR1bits.SSPIF );  // wait until ninth clock pulse received

	      if ( ( !SSPSTATbits.R_W ) && ( !SSPSTATbits.BF ) )// if R/W=0 and BF=0, NOT ACK was received
	      {
	        return ( -2 );           //return NACK
	      }
		  else
		  {
			return ( 0 );				//return ACK
		  }	
	}
	else if( ((SSPCON1&0x0F)==0x08) || ((SSPCON1&0x0F)==0x0B) )	//master mode only
	{ 
	    while( SSPSTATbits.BF );   // wait until write cycle is complete   
	    IdleI2C();                 // ensure module is idle
	    if ( SSPCON2bits.ACKSTAT ) // test for ACK condition received
	    	 return ( -2 );			// return NACK
		else return ( 0 );              //return ACK
	}
	
  }
}

#endif

#if defined (I2C_V4)
signed char WriteI2C( unsigned char data_out )
{
  SSPBUF = data_out;           // write single byte to SSPBUF
  if ( SSPCONbits.WCOL )      // test if write collision occurred
   return ( -1 );              // if WCOL bit is set return negative #
  else
  {
    while( SSPSTATbits.BF );   // wait until write cycle is complete   
	
 //   if ( PIR1bits.SSPIF ) // test for ACK condition received
 //   	 return ( -2 );
//	else 
	return ( 0 );              // if WCOL bit is not set return non-negative #
  }
}

#endif


