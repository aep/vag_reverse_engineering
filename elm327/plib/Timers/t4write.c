#include <p18cxxx.h>
#include <timers.h>

/********************************************************************
*    Function Name:  WriteTimer4                                    *
*    Return Value:   void                                           *
*    Parameters:     char: value to write to Timer4                 *
*    Description:    This routine writes a 8-bit value to Timer4.   *
********************************************************************/

#if defined (TMR_V4) || defined (TMR_V6) || defined (TMR_V7) || defined (TMR_V7_1) ||\
	defined (TMR_V7_2) || defined (TMR_V7_3) || defined (TMR_V7_4)
#undef WriteTimer4
void WriteTimer4(unsigned char timer4)
{
  TMR4 = timer4;    // Write byte to Timer4
}

#endif
