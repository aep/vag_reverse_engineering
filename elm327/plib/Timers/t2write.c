#include <p18cxxx.h>
#include <timers.h>

/********************************************************************
*    Function Name:  WriteTimer2                                    *
*    Return Value:   void                                           *
*    Parameters:     char: value to write to Timer2                 *
*    Description:    This routine writes a 8-bit value to Timer2.   *
********************************************************************/
#if defined (TMR_V2) || defined (TMR_V3) || defined (TMR_V4) || \
    defined (TMR_V5) || defined (TMR_V6)  || defined (TMR_V7) || defined (TMR_V7_1)\
	|| defined (TMR_V7_2) || defined (TMR_V7_3) || defined (TMR_V7_4) || defined (TMR_V7_5)
#undef WriteTimer2
void WriteTimer2(unsigned char timer2)
{
  TMR2 = timer2;    // Write byte to Timer2
}

#endif
