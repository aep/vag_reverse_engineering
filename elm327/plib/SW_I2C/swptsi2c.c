
#include <p18cxxx.h>
#include "i2c_data.h"

/********************************************************************
*     Function Name:    signed char SWPutsI2C(unsigned char *wrptr) *
*     Return Value:     end of string indicator or bus error        *
*     Parameters:       address of write string storage location    *
*     Description:      This routine writes a string to the I2C bus.*
********************************************************************/
signed char SWPutsI2C( unsigned char *wrptr )
{
  while ( *wrptr )
  {               
    if ( SWPutcI2C( *wrptr++) )   // write out data string to I2C receiver
    {
      return( -1 );               // return if there was an error in Putc()
    }
    else
    {
      if ( SWAckI2C( ) )          // go read bus ack status
      {
        return( -1 );             // return with possible error condition 
      }
    }
  }                              
  return ( 0 );                   // return with no error
}


