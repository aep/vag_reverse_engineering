#include <p18cxxx.h>
#include <capture.h>

#if defined (CC_V4)
/*******************************************************************************
Function Prototype : unsigned int ReadCapture4(void)
 
Include            : capture.h
 
Description        : This function reads the pending Input Capture buffer.
 
Arguments          : None
 
Return Value       : This routine reads the CA1L and CA1H into the union Cap of type CapResult 
			that is defined in global data  space. The int result is then returned. 
 
Remarks            : This function reads the pending Input Capture buffer
*******************************************************************************/
unsigned int ReadCapture4(void)
{
  union CapResult Cap;

  CapStatus.Cap4OVF = 0;   // Clear the overflow flag in the
                           // status variable

  if(PIR3bits.CCP4IF)      // If the overflow flag is set
    CapStatus.Cap4OVF = 1; // Set the overflow flag

  Cap.bc[0] = CCPR4L;      // Read CA4L into the lower byte
  Cap.bc[1] = CCPR4H;      // Read CA4H into the high byte

  return (Cap.lc);         // Return the int
}


#elif defined (CC_V8) || defined (CC_V8_1) || defined (CC_V8_2)|| defined (CC_V8_3) || defined (CC_V8_4)\
	|| defined (CC_V9)|| defined (CC_V9_1)
/*******************************************************************************
Function Prototype : unsigned int ReadCapture4(void)
 
Include            : capture.h
 
Description        : This function reads the pending Input Capture buffer.
 
Arguments          : None
 
Return Value       : This routine reads the CA1L and CA1H into the union Cap of type CapResult 
			that is defined in global data  space. The int result is then returned. 
 
Remarks            : This function reads the pending Input Capture buffer
*******************************************************************************/
unsigned int ReadCapture4(void)
{
  union CapResult Cap;

  CapStatus.Cap4OVF = 0;   // Clear the overflow flag in the
                           // status variable

  if(PIR4bits.CCP4IF)      // If the overflow flag is set
    CapStatus.Cap4OVF = 1; // Set the overflow flag

  Cap.bc[0] = CCPR4L;      // Read CA4L into the lower byte
  Cap.bc[1] = CCPR4H;      // Read CA4H into the high byte

  return (Cap.lc);         // Return the int
}

#endif
