#include <p18cxxx.h>
#include <timers.h>

/********************************************************************
*    Function Name:  WriteTimer6                                    *
*    Return Value:   void                                           *
*    Parameters:     char: value to write to Timer6                 *
*    Description:    This routine writes a 8-bit value to Timer6.   *
********************************************************************/

#if defined (TMR_V7) || defined (TMR_V7_1) || defined (TMR_V7_3) || defined (TMR_V7_4)
#undef WriteTimer6
void WriteTimer6(unsigned char timer6)
{
  TMR6 = timer6;    // Write byte to Timer6
}

#endif
