#include <p18cxxx.h>
#include <timers.h>

/********************************************************************
*    Function Name:  ReadTimer6                                     *
*    Return Value:   char: Timer6 8-bit value                       *
*    Parameters:     void                                           *
*    Description:    This routine returns the 8-bit value of        *
*                    Timer6.                                        *
********************************************************************/

#if defined (TMR_V7) || defined (TMR_V7_1) || defined (TMR_V7_3) || defined (TMR_V7_4)
#undef ReadTimer6
unsigned char ReadTimer6(void)
{
  return (TMR6);    // Return 8-bits 
}

#endif
