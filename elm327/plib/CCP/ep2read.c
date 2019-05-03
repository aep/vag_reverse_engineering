#include <p18cxxx.h>
#include <capture.h>

#if defined (ECC_V8) || defined (ECC_V8_1)|| defined (ECC_V8_3) || defined (ECC_V8_4)\
	|| defined (ECC_V9)|| defined (ECC_V9_1)
/*******************************************************************************
Function Prototype : unsigned int ReadECapture2(void)
 
Include            : capture.h
 
Description        : This function reads the pending Input Capture buffer.
 
Arguments          : None
 
Return Value       : This routine reads the CAxL and CAxH into the union Cap of type CapResult 
			that is defined in global data  space. The int result is then returned. 
 
Remarks            : This function reads the pending Input Capture buffer
*******************************************************************************/
unsigned int ReadECapture2(void)
{
  union CapResult Cap;

  CapStatus.ECap2OVF = 0;    // Clear the overflow flag in the
                             // status variable
#if defined(CC4_IO_V2) || defined (CC9_IO_V1)
   if(PIR2bits.CCP2IF)       // If the overflow flag is set
#else  
   if(PIR3bits.CCP2IF)       // If the overflow flag is set
#endif
    CapStatus.ECap2OVF = 1;  // Set the overflow flag

  Cap.bc[0] = CCPR2L;       // Read CAxL into the lower byte
  Cap.bc[1] = CCPR2H;       // Read CAxH into the high byte

  return (Cap.lc);          // Return the int
}

#endif
