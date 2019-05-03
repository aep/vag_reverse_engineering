#include <p18cxxx.h>
#include <mwire.h>

#if defined (MWIRE_V2) || defined (MWIRE_V4) || defined (MWIRE_V5) || defined (MWIRE_V6)
/********************************************************************
*     Function Name:    CloseMwire1                                 *
*     Return Value:     void                                        *
*     Parameters:       void                                        *
*     Description:      This function disables the SSP1 module. Pin *
*                       I/O returns under the control of the port   *
*                       registers.                                  * 
********************************************************************/
#undef CloseMwire1
void CloseMwire1( void )
{
  SSP1CON1 &= 0xDF;     // disable synchronous serial port
}
#endif
