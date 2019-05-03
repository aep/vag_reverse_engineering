#include <p18cxxx.h>
#include <timers.h>

/********************************************************************
*    Function Name:  ReadTimer4                                     *
*    Return Value:   char: Timer4 8-bit value                       *
*    Parameters:     void                                           *
*    Description:    This routine returns the 8-bit value of        *
*                    Timer4.                                        *
********************************************************************/

#if defined (TMR_V4) || defined (TMR_V6) || defined (TMR_V7) || defined (TMR_V7_1)\
 || defined (TMR_V7_2) || defined (TMR_V7_3) || defined (TMR_V7_4)
#undef ReadTimer4
unsigned char ReadTimer4(void)
{
  return (TMR4);    // Return 8-bits 
}

#endif
