#include <p18cxxx.h>
#include <capture.h>

#if defined (CC_V4)
/*******************************************************************************
Function Prototype : unsigned int ReadCapture5(void)
 
Include            : capture.h
 
Description        : This function reads the pending Input Capture buffer.
 
Arguments          : None
 
Return Value       : This routine reads the CA1L and CA1H into the union Cap of type CapResult 
			that is defined in global data  space. The int result is then returned. 
 
Remarks            : This function reads the pending Input Capture buffer
*******************************************************************************/
unsigned int ReadCapture5(void)
{
  union CapResult Cap;

  CapStatus.Cap5OVF = 0;   // Clear the overflow flag in the
                           // status variable

  if(PIR3bits.CCP5IF)      // If the overflow flag is set
    CapStatus.Cap5OVF = 1; // Set the overflow flag

  Cap.bc[0] = CCPR5L;      // Read CA5L into the lower byte
  Cap.bc[1] = CCPR5H;      // Read CA5H into the high byte

  return (Cap.lc);         // Return the int
}

#elif defined (CC_V8) || defined (CC_V8_1) || defined (CC_V8_2) || defined (CC_V8_3) || defined (CC_V8_4) || defined (CC_V9)|| defined (CC_V9_1)
/*******************************************************************************
Function Prototype : unsigned int ReadCapture5(void)
 
Include            : capture.h
 
Description        : This function reads the pending Input Capture buffer.
 
Arguments          : None
 
Return Value       : This routine reads the CA1L and CA1H into the union Cap of type CapResult 
			that is defined in global data  space. The int result is then returned. 
 
Remarks            : This function reads the pending Input Capture buffer
*******************************************************************************/
unsigned int ReadCapture5(void)
{
  union CapResult Cap;

  CapStatus.Cap5OVF = 0;   // Clear the overflow flag in the
                           // status variable

  if(PIR4bits.CCP5IF)      // If the overflow flag is set
    CapStatus.Cap5OVF = 1; // Set the overflow flag

  Cap.bc[0] = CCPR5L;      // Read CA5L into the lower byte
  Cap.bc[1] = CCPR5H;      // Read CA5H into the high byte

  return (Cap.lc);         // Return the int
}
#endif
