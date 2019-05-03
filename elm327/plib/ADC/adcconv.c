#include <p18cxxx.h>
#include <adc.h>

#if defined (ADC_V1) || defined (ADC_V2) || defined (ADC_V3) ||\
 defined (ADC_V5) || defined (ADC_V8) ||defined (ADC_V4) || \
 defined (ADC_V6) || defined (ADC_V7) ||defined (ADC_V7_1)||\
 defined (ADC_V10) || defined (ADC_V11) || defined (ADC_V12) ||\
 defined (ADC_V13) || defined (ADC_V13_1) || defined (ADC_V11_1)\
 || defined (ADC_V13_2) || defined (ADC_V13_3)|| defined (ADC_V14) || defined (ADC_V14_1) || defined (ADC_V14_2) || defined (ADC_V14_3)
/************************************************************************************
Function       : void ConvertADC(void)
 
Overview     : This function starts the A/D conversion.
 
Parameters   : None

Returns         : None

Remarks        : This function sets the ADCON0<GO> bit and thus
		    starts conversion.
**************************************************************************************/ 
void ConvertADC(void)
{
  ADCON0bits.GO = 1;
}

#elif defined (ADC_V9) || defined (ADC_V9_1)
/************************************************************************************
Function       : void ConvertADC(void)
 
Overview     : This function starts the A/D conversion.
 
Parameters   : None

Returns         : None

Remarks        : This function sets the ADCON0<GO> bit and thus
		    starts conversion.
**************************************************************************************/ 
void ConvertADC(void)
{
  WDTCONbits.DEVCFG = 0;  
  ADCON0bits.GO = 1;
}

#elif defined (ADC_V15) || defined (ADC_V15_1)
/************************************************************************************
Function       : void ConvertADC(void)
 
Overview     : This function starts the A/D conversion.
 
Parameters   : None

Returns         : None

Remarks        : This function clears the ADCON1L<SAMP> bit and thus stops 
                 sampling and starts conversion.This happens only when 
                 trigger source for the A/D conversion is selected as Manual,
                 by clearing the ADCON1L <SSRC> bits.
**************************************************************************************/ 
void ConvertADC(void)
{
  ADCON1Lbits.SAMP = 0; /* clear SAMP to start conversion*/
}
#endif
