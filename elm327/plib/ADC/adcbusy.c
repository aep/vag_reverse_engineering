#include <p18cxxx.h>
#include <adc.h>

#if defined (ADC_V1) || defined (ADC_V2) || defined (ADC_V3) ||\
    defined (ADC_V4) || defined (ADC_V5) || defined (ADC_V6) ||\
	defined (ADC_V7) ||defined (ADC_V7_1) || defined (ADC_V8) ||\
	defined (ADC_V10) || defined (ADC_V11) || defined (ADC_V12) ||\
	defined (ADC_V13) || defined (ADC_V13_1) || defined (ADC_V11_1)\
	|| defined (ADC_V13_2) || defined (ADC_V13_3)|| defined (ADC_V14)\
	|| defined (ADC_V14_1) || defined (ADC_V14_2) || defined (ADC_V14_3)
/*************************************************************************************
Function:       char BusyADC(void)

Overview:    This function returns the ADC conversion status

Parameters:  None

Returns:        If the value of GO is ‘1’, then ‘1’ is returned,indicating that the
	           ADC is busy in conversion. If the value of GO is ‘0’, then ‘0’ is
                      returned, indicating that the ADC has completed conversion.

Remarks:     This function returns the complement of the ADCON0 <GO/~DONE> bit
                     status which indicates whether the ADC is busy in conversion.
            
***************************************************************************************/
char BusyADC(void)
{
  return(ADCON0bits.GO);
}

#elif defined (ADC_V9) || defined (ADC_V9_1)
/*************************************************************************************
Function:       char BusyADC(void)

Overview:    This function returns the ADC conversion status.  

Parameters:  None

Returns:        If the value of GO is ‘1’, then ‘1’ is returned,indicating that the
	           ADC is busy in conversion. If the value of GO is ‘0’, then ‘0’ is 
                      returned, indicating that the ADC has completed conversion. 

Remarks:     This function returns the complement of the ADCON0 <GO/~DONE> bit
                     status which indicates whether the ADC is busy in conversion.
            
***************************************************************************************/
char BusyADC(void)
{
  WDTCONbits.DEVCFG = 0;  
  return(ADCON0bits.GO);
}

#elif	defined (ADC_V15) || defined (ADC_V15_1)	
/*************************************************************************************
Function:    char BusyADC10(void)

Overview:    This function returns the ADC conversion status.  

Parameters:  None

Returns:     If the value of DONE is ‘0’, then ‘1’ is returned,indicating that the
             ADC is busy in conversion.If the value of DONE is ‘1’, then ‘0’ is 
             returned, indicating that the ADC has completed conversion. 

Remarks:     This function returns the complement of the ADCON1L <DONE> bit
             status which indicates whether the ADC is busy in conversion.
            
***************************************************************************************/  
char BusyADC(void)
{
  return(ADCON1Lbits.DONE);
}

#endif


