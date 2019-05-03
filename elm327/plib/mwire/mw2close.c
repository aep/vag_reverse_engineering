#include <p18cxxx.h>
#include <mwire.h>

#if defined (MWIRE_V2) || defined (MWIRE_V4) || defined (MWIRE_V6)
/********************************************************************
*     Function Name:    CloseMwire2                                 *
*     Return Value:     void                                        *
*     Parameters:       void                                        *
*     Description:      This function disables the SSP2 module. Pin *
*                       I/O returns under the control of the port   *
*                       registers.                                  * 
********************************************************************/
#undef CloseMwire2
void CloseMwire2( void )
{
  SSP2CON1 &= 0xDF;     // disable synchronous serial port
}
#endif
