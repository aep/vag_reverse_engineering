#include <p18cxxx.h>
#include <adc.h>

#if defined (ADC_V1) || defined (ADC_V2) || defined (ADC_V3) ||\
    defined (ADC_V4) || defined (ADC_V5) || defined (ADC_V6) ||\
    defined (ADC_V7) || defined (ADC_V7_1) || defined (ADC_V8) ||\
    defined (ADC_V9) || defined (ADC_V9_1) || defined (ADC_V10) || defined (ADC_V11) ||\
	defined (ADC_V12) || defined (ADC_V13) || defined (ADC_V13_1)\
	|| defined (ADC_V11_1) || defined (ADC_V13_2) || defined (ADC_V13_3)\
	|| defined (ADC_V14) || defined (ADC_V14_1) || defined (ADC_V14_2) || defined (ADC_V14_3)
/*************************************************************************************
Function:       int ReadADC(void)

Overview:    This function reads the ADC Buffer register which contains
                      the conversion value.

Parameters:  None

Returns:        Returns the ADC Buffer value

Remarks:     None
            
***************************************************************************************/	
int ReadADC(void)
{
  return (((unsigned int)ADRESH)<<8)|(ADRESL);
}

#elif	defined (ADC_V15) || defined (ADC_V15_1)
/************************************************************************
Function           : unsigned int ReadADC(unsigned char bufIndex) 

Overview           : This function reads the ADC Buffer register which contains 
                     the conversion value. 

Parameters         : bufIndex - This is the ADC buffer number which is to be read. 

Returns            : Returns the ADC Buffer value

Remarks            : This function returns the contents of the ADC Buffer register.
                     User should provide bufIndex value between ‘0’ to ‘15’ to 
                     ensure correct read of the ADCBUF0 to ADCBUFF.
 ************************************************************************/

unsigned int ReadADC(unsigned char bufIndex)
{
     return(*(&ADCBUF0+bufIndex));
}
#endif
