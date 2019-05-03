#include <p18cxxx.h>
#include <timers.h>

/********************************************************************
*    Function Name:  WriteTimer12                                    *
*    Return Value:   void                                           *
*    Parameters:     char: value to write to Timer12                 *
*    Description:    This routine writes a 8-bit value to Timer12.   *
********************************************************************/

#if defined (TMR_V7)
#undef WriteTimer12
void WriteTimer12(unsigned char timer12)
{
  TMR12 = timer12;    // Write byte to Timer12
}

#endif
