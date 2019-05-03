#include <p18cxxx.h>
#include <capture.h>

#if defined (ECC_V8) || defined (ECC_V8_1) || defined (ECC_V8_3) || defined (ECC_V8_4)\
	|| defined (ECC_V9)|| defined (ECC_V9_1)
/*******************************************************************************
Function Prototype : unsigned int ReadECapture3(void)
 
Include            : capture.h
 
Description        : This function reads the pending Input Capture buffer.
 
Arguments          : None
 
Return Value       : This routine reads the CAxL and CAxH into the union Cap of type CapResult 
			that is defined in global data  space. The int result is then returned. 
 
Remarks            : This function reads the pending Input Capture buffer
*******************************************************************************/
unsigned int ReadECapture3(void)
{
  union CapResult Cap;

  CapStatus.ECap3OVF = 0;    // Clear the overflow flag in the
                             // status variable

  #if defined (ECC_V8_3) || defined (ECC_V8_4)
   if(PIR4bits.ECCP3IF)       // If the overflow flag is set
   #else
   if(PIR4bits.CCP3IF)       // If the overflow flag is set
   #endif
   
   CapStatus.ECap3OVF = 1;  // Set the overflow flag

  Cap.bc[0] = CCPR3L;       // Read CAxL into the lower byte
  Cap.bc[1] = CCPR3H;       // Read CAxH into the high byte

  return (Cap.lc);          // Return the int
}

#endif
