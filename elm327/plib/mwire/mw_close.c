#include <p18cxxx.h>
#include <mwire.h>

#if defined (MWIRE_V1)
/********************************************************************
*     Function Name:    CloseMwire                                  *
*     Return Value:     void                                        *
*     Parameters:       void                                        *
*     Description:      This function disables the SSP module. Pin  *
*                       I/O returns under the control of the port   *
*                       registers.                                  * 
********************************************************************/
#undef CloseMwire
void CloseMwire( void )
{
  SSPCON1 &= 0xDF;     // disable synchronous serial port
}
#endif
