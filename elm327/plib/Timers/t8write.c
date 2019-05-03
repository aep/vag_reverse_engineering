#include <p18cxxx.h>
#include <timers.h>

/********************************************************************
*    Function Name:  WriteTimer8                                    *
*    Return Value:   void                                           *
*    Parameters:     char: value to write to Timer8                 *
*    Description:    This routine writes a 8-bit value to Timer8.   *
********************************************************************/

#if defined (TMR_V7) || defined (TMR_V7_1) || defined (TMR_V7_4)
#undef WriteTimer8
void WriteTimer8(unsigned char timer8)
{
  TMR8 = timer8;    // Write byte to Timer8
}

#endif
