#include <p18cxxx.h>
#include <i2c.h>


/********************************************************************
*     Function Name:    getsI2C1                                    *
*     Return Value:     error condition status                      *
*     Parameters:       address of read string storage location     *
*                       length of string bytes to read              *
*     Description:      This routine reads a predetemined string    *
*                       length in from the I2C1 bus. The routine is *
*                       developed for the Master mode. The bus ACK  *
*                       condition is generated within this routine. *
********************************************************************/
#if defined (I2C_V2) || defined (I2C_V3) || defined (I2C_V5) || defined (I2C_V6) || defined (I2C_V6_1) || defined (I2C_V6_2)
signed char getsI2C1( unsigned char *rdptr, unsigned char length )
{
    while ( length-- )            // perform getcI2C1() for 'length' number of bytes
    {
      *rdptr++ = getcI2C1();       // save byte received
      while ( SSP1CON2bits.RCEN ); // check that receive sequence is over    

      if ( PIR2bits.BCL1IF )       // test for bus collision
      {
        return ( -1 );             // return with Bus Collision error 
      }

	  
	if( ((SSP1CON1&0x0F)==0x08) || ((SSP1CON1&0x0F)==0x0B) )	//master mode only
	{	
      if ( length )               // test if 'length' bytes have been read
      {
        SSP1CON2bits.ACKDT = 0;    // set acknowledge bit state for ACK        
        SSP1CON2bits.ACKEN = 1;    // initiate bus acknowledge sequence
        while ( SSP1CON2bits.ACKEN ); // wait until ACK sequence is over 
      } 
	} 
	  
    }
    return ( 0 );                  // last byte received so don't send ACK      
}
#endif
