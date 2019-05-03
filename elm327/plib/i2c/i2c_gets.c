#include <p18cxxx.h>
#include <i2c.h>


/********************************************************************
*     Function Name:    getsI2C                                     *
*     Return Value:     error condition status                      *
*     Parameters:       address of read string storage location     *
*                       length of string bytes to read              *
*     Description:      This routine reads a predetemined string    *
*                       length in from the I2C bus. The routine is  *                       
*                       developed for the Master mode. The bus ACK  *
*                       condition is generated within this routine. *
********************************************************************/
#if defined (I2C_V1) 

signed char getsI2C( unsigned char *rdptr, unsigned char length )
{
    while ( length-- )           // perform getcI2C() for 'length' number of bytes
    {
      *rdptr++ = getcI2C();       // save byte received
      while ( SSPCON2bits.RCEN ); // check that receive sequence is over    

      if ( PIR2bits.BCLIF )       // test for bus collision
      {
        return ( -1 );            // return with Bus Collision error 
      }

	if( ((SSPCON1&0x0F)==0x08) || ((SSPCON1&0x0F)==0x0B) )	//master mode only
	{	
      if ( length )               // test if 'length' bytes have been read
      {
        SSPCON2bits.ACKDT = 0;    // set acknowledge bit state for ACK        
        SSPCON2bits.ACKEN = 1;    // initiate bus acknowledge sequence
        while ( SSPCON2bits.ACKEN ); // wait until ACK sequence is over 
      } 
	} 
	  
    }
    return ( 0 );                 // last byte received so don't send ACK      
}

#endif

