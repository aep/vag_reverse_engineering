#include <p18cxxx.h>
#include <mwire.h>

#if defined (MWIRE_V2) || defined (MWIRE_V4) || defined (MWIRE_V5) || defined (MWIRE_V6)
/********************************************************************
*     Function Name:    getsMwire1                                  *
*     Return Value:     void                                        *
*     Parameters:       address of read string storage location and *
*                       length of string bytes to read              *
*     Description:      This routine reads a string from the        *
*                       Microwire1 device. User must first issue    *
*                       start bit, opcode and address before reading*
*                       a string. Function WriteMWire1() or         *
*                       putcMWire1() can be called 2 times to       *
*                       accomplish the byte write sequence.         *
********************************************************************/
void getsMwire1( unsigned char *rdptr, unsigned char length )
{
  SSP1CON1bits.CKP = 0;           // ensure clock idle state is 0 for read
  while ( length )                // stay in loop until length = 0
  {
    SSP1BUF = 0x00;               // initiate bus cycle
    while( !SSP1STATbits.BF );    // wait until byte has been received
    *rdptr++ = SSP1BUF;           // save byte
    length--;                     // reduce string byte count by 1
  }  
  SSP1CON1bits.CKP = 1;           // ensure clock idle state is 1 for transmission
}
#endif
