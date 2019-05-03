#include <p18cxxx.h>
#include <i2c.h>

/********************************************************************
*     Function Name:    WriteI2C2                                   *
*     Return Value:     Status byte for WCOL detection.             *
*     Parameters:       Single data byte for I2C2 bus.              *
*     Description:      This routine writes a single byte to the    * 
*                       I2C2 bus.                                   *
********************************************************************/
#if defined (I2C_V3) || defined (I2C_V6) || defined (I2C_V6_1)
signed char WriteI2C2( unsigned char data_out )
{
  SSP2BUF = data_out;           // write single byte to SSP2BUF
  if ( SSP2CON1bits.WCOL )      // test if write collision occurred
    return ( -1 );              // if WCOL bit is set return negative #
  else
  {
	if( ((SSP2CON1&0x0F)!=0x08) && ((SSP2CON1&0x0F)!=0x0B) )	//slave mode only
	{
	 #if defined (I2C_SFR_V1) 
     if ( ( !SSP2STATbits.R_NOT_W ) && ( !SSP2STATbits.BF ) )
	 #else
      if ( ( !SSP2STATbits.R_W ) && ( !SSP2STATbits.BF ) )// if R/W=0 and BF=0, NOT ACK was received
	 #endif 
      {
        return ( -2 );             // return NACK
      }
	  else return(0);				// return ACK
	
	}  
    else if( ((SSP2CON1&0x0F)==0x08) || ((SSP2CON1&0x0F)==0x0B) )	//master mode only
	{
	    while( SSP2STATbits.BF );   // wait until write cycle is complete     
	    IdleI2C2();                  // ensure module is idle
	    if ( SSP2CON2bits.ACKSTAT ) // test for ACK condition received
	    	 return ( -2 );				//return NACK
		else return ( 0 );   			//return ACK
	}
	
  }
}
#endif
