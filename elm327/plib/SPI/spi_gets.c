#include <p18cxxx.h>
#include <spi.h>

/********************************************************************
*     Function Name:    getsSPI                                     *
*     Return Value:     void                                        *
*     Parameters:       address of read string storage location and *
*                       length of string bytes to read              *
*     Description:      This routine reads a string from the SPI    *
*                       bus.  The number of bytes to read is deter- *
*                       mined by parameter 'length'.                *
********************************************************************/
#if defined (SPI_V1) || defined (SPI_V4)
void getsSPI( unsigned char *rdptr, unsigned char length )
{
  while ( length )                // stay in loop until length = 0
  {
    *rdptr++ = getcSPI();         // read a single byte
    length--;                     // reduce string length count by 1
  }
}
#endif
