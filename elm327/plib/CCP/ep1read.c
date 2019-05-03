#include <p18cxxx.h>
#include <capture.h>

#if defined (CC_V5)
/*******************************************************************************
Function Prototype : unsigned int ReadECapture1(void)
 
Include            : capture.h
 
Description        : This function reads the pending Input Capture buffer.
 
Arguments          : None
 
Return Value       : This routine reads the CA1L and CA1H into the union Cap of type CapResult 
			that is defined in global data  space. The int result is then returned. 
 
Remarks            : This function reads the pending Input Capture buffer
*******************************************************************************/
unsigned int ReadECapture1(void)
{
  union CapResult Cap;

  CapStatus.ECap1OVF = 0;    // Clear the overflow flag in the
                             // status variable

  if(PIR2bits.ECCP1IF)       // If the overflow flag is set
    CapStatus.ECap1OVF = 1;  // Set the overflow flag

  Cap.bc[0] = ECCPR1L;       // Read CA1L into the lower byte
  Cap.bc[1] = ECCPR1H;       // Read CA1H into the high byte

  return (Cap.lc);          // Return the int
}

#elif defined (ECC_V8) || defined (ECC_V8_1) || defined (ECC_V8_2) || defined (ECC_V8_3) || defined (ECC_V8_4)\
	|| defined (ECC_V8_5) || defined (ECC_V9)|| defined (ECC_V9_1)
/*******************************************************************************
Function Prototype : unsigned int ReadECapture1(void)
 
Include            : capture.h
 
Description        : This function reads the pending Input Capture buffer.
 
Arguments          : None
 
Return Value       : This routine reads the CA1L and CA1H into the union Cap of type CapResult 
			that is defined in global data  space. The int result is then returned. 
 
Remarks            : This function reads the pending Input Capture buffer
*******************************************************************************/
unsigned int ReadECapture1(void)
{
  union CapResult Cap;

  CapStatus.ECap1OVF = 0;    // Clear the overflow flag in the
                             // status variable
#if defined(CC4_IO_V2) || defined (CC9_IO_V1)
   if(PIR1bits.CCP1IF)       // If the overflow flag is set
#else  
   if(PIR3bits.CCP1IF)       // If the overflow flag is set
#endif
    CapStatus.ECap1OVF = 1;  // Set the overflow flag

  Cap.bc[0] = CCPR1L;       // Read CA1L into the lower byte
  Cap.bc[1] = CCPR1H;       // Read CA1H into the high byte

  return (Cap.lc);          // Return the int
}

#endif
