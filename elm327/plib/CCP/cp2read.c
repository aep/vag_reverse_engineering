
#include <p18cxxx.h>
#include <capture.h>

#if defined (CC_V2) || defined (CC_V3) || defined (CC_V4) ||\
    defined (CC_V7)
/*******************************************************************************
Function Prototype : unsigned int ReadCapture2(void)
 
Include            : capture.h
 
Description        : This function reads the pending Input Capture buffer.
 
Arguments          : None
 
Return Value       : This routine reads the CA1L and CA1H into the union Cap of type CapResult 
			that is defined in global data  space. The int result is then returned. 
 
Remarks            : This function reads the pending Input Capture buffer
*******************************************************************************/
unsigned int ReadCapture2(void)
{
  union CapResult Cap;

  CapStatus.Cap2OVF = 0;   // Clear the overflow flag in the
                           // status variable

  if(PIR2bits.CCP2IF)      // If the overflow flag is set
    CapStatus.Cap2OVF = 1; // Set the overflow flag

  Cap.bc[0] = CCPR2L;      // Read CA2L into the lower byte
  Cap.bc[1] = CCPR2H;      // Read CA2H into the high byte

  return (Cap.lc);         // Return the int
}

#elif defined (CC_V6) || defined (CC_V8_2) || defined (CC_V8_5)
/*******************************************************************************
Function Prototype : unsigned int ReadCapture2(void)
 
Include            : capture.h
 
Description        : This function reads the pending Input Capture buffer.
 
Arguments          : None
 
Return Value       : This routine reads the CA1L and CA1H into the union Cap of type CapResult 
			that is defined in global data  space. The int result is then returned. 
 
Remarks            : This function reads the pending Input Capture buffer
*******************************************************************************/
unsigned int ReadCapture2(void)
{
  union CapResult Cap;

  CapStatus.Cap2OVF = 0;   // Clear the overflow flag in the
                           // status variable
#if defined (CC_V6) || defined (CC_V8_2)
  if(PIR3bits.CCP2IF )      // If the overflow flag is set
    CapStatus.Cap2OVF = 1; // Set the overflow flag
#elif defined (CC_V8_5)
  if(PIR2bits.CCP2IF )      // If the overflow flag is set
    CapStatus.Cap2OVF = 1; // Set the overflow flag
#endif

  Cap.bc[0] = CCPR2L;      // Read CA2L into the lower byte
  Cap.bc[1] = CCPR2H;      // Read CA2H into the high byte

  return (Cap.lc);         // Return the int
}
#endif
