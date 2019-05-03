#include <p18cxxx.h>
#include <timers.h>

/********************************************************************
*    Function Name:  WriteTimer10                                    *
*    Return Value:   void                                           *
*    Parameters:     char: value to write to Timer10                 *
*    Description:    This routine writes a 8-bit value to Timer10.   *
********************************************************************/

#if defined (TMR_V7)
#undef WriteTimer10
void WriteTimer10(unsigned char timer10)
{
  TMR10 = timer10;    // Write byte to Timer10
}

#endif
