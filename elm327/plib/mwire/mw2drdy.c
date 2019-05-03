#include <p18cxxx.h>
#include <mwire.h>

#if defined (MWIRE_V2) || defined (MWIRE_V4) || defined (MWIRE_V6)
/********************************************************************
*     Function Name:    DataRdyMwire2                               *
*     Return Value:     status byte to indicate ready/busy          *
*     Parameters:       void                                        *
*     Description:      Determine if Microwire2 device is ready,    *
*                       write cycle complete. If used after a       *
*                       write/erase cycle is complete a pull-up     *
*                       resistor on the DI line is required. If the *
*                       routine is called after a cycle has been    *
*                       initiated while CS is high then no pull-up  *
*                       resistor is required.                       *
********************************************************************/
#undef DataRdyMwire2
unsigned char DataRdyMwire2( void )
{
  if ( MW2_DI )            // test if DI line is high    
    return ( +1 );                // return ready = true
  else
    return ( 0 );                 // else ready = false
}
#endif
