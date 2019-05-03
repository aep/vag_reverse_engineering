#include <p18cxxx.h>
#include <capture.h>




#if defined (CC_V1) || defined (CC_V2) || defined (CC_V3) ||\
    defined (CC_V4) || defined (CC_V5) || defined (CC_V7)
/*******************************************************************************
Function Prototype : unsigned int ReadCapture1(void)
 
Include            : capture.h
 
Description        : This function reads the pending Input Capture buffer.
 
Arguments          : None
 
Return Value       : This routine reads the CA1L and CA1H into the union Cap of type CapResult 
			that is defined in global data  space. The int result is then returned. 
 
Remarks            : This function reads the pending Input Capture buffer
*******************************************************************************/
unsigned int ReadCapture1(void)
{
  union CapResult Cap;

  CapStatus.Cap1OVF = 0;    // Clear the overflow flag in the
                            // status variable

  if(PIR1bits.CCP1IF)       // If the overflow flag is set
    CapStatus.Cap1OVF = 1;  // Set the overflow flag

  Cap.bc[0] = CCPR1L;       // Read CA1L into the lower byte
  Cap.bc[1] = CCPR1H;       // Read CA1H into the high byte

  return (Cap.lc);          // Return the int
}

#elif defined (CC_V6)
/*******************************************************************************
Function Prototype : unsigned int ReadCapture1(void)
 
Include            : capture.h
 
Description        : This function reads the pending Input Capture buffer.
 
Arguments          : None
 
Return Value       : This routine reads the CA1L and CA1H into the union Cap of type CapResult 
			that is defined in global data  space. The int result is then returned. 
 
Remarks            : This function reads the pending Input Capture buffer
*******************************************************************************/
unsigned int ReadCapture1(void)
{
  union CapResult Cap;

  CapStatus.Cap1OVF = 0;    // Clear the overflow flag in the
                            // status variable

  if(PIR3bits.CCP1IF)       // If the overflow flag is set
    CapStatus.Cap1OVF = 1;  // Set the overflow flag

  Cap.bc[0] = CCPR1L;       // Read CA1L into the lower byte
  Cap.bc[1] = CCPR1H;       // Read CA1H into the high byte

  return (Cap.lc);          // Return the int
}
#endif
