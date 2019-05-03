#include <p18cxxx.h>
#include <capture.h>

#if defined (CC_V3) || defined (CC_V4)
/*******************************************************************************
Function Prototype : unsigned int ReadCapture3(void)
 
Include            : capture.h
 
Description        : This function reads the pending Input Capture buffer.
 
Arguments          : None
 
Return Value       : This routine reads the CA1L and CA1H into the union Cap of type CapResult 
			that is defined in global data  space. The int result is then returned. 
 
Remarks            : This function reads the pending Input Capture buffer
*******************************************************************************/
unsigned int ReadCapture3(void)
{
  union CapResult Cap;

  CapStatus.Cap3OVF = 0;   // Clear the overflow flag in the
                           // status variable

  if(PIR3bits.CCP3IF)      // If the overflow flag is set
    CapStatus.Cap3OVF = 1; // Set the overflow flag

  Cap.bc[0] = CCPR3L;      // Read CA3L into the lower byte
  Cap.bc[1] = CCPR3H;      // Read CA3H into the high byte

  return (Cap.lc);         // Return the int
}

#elif defined (CC_V8_2)
unsigned int ReadCapture3(void)
{
  union CapResult Cap;

  CapStatus.Cap3OVF = 0;   // Clear the overflow flag in the
                           // status variable

  if(PIR4bits.CCP3IF)      // If the overflow flag is set
    CapStatus.Cap3OVF = 1; // Set the overflow flag

  Cap.bc[0] = CCPR3L;      // Read CA3L into the lower byte
  Cap.bc[1] = CCPR3H;      // Read CA3H into the high byte

  return (Cap.lc);         // Return the int
}
#endif
