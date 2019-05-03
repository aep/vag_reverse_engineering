#include <p18cxxx.h>
#include <adc.h>

#if defined (ADC_V1)
/*Description:
  void SetChanADC(unsigned char
  channel)
  
  This function Select the channel
  used as input to the A/D converter.
  Input:
  channel -  This contains the
             \parameters to be
             configured in the ADCON0
             register as defined below
  Return:
  None
  Remarks:
  Selects the pin that will be used as
  \input to the A/D converter.        */
void SetChanADC(unsigned char channel)
{
  ADCON0 = (channel & 0b00111000) |
           (ADCON0 & 0b11000111);
}

#elif defined (ADC_V2) || defined (ADC_V3) || defined (ADC_V4) ||\
      defined (ADC_V5) || defined (ADC_V6) || defined (ADC_V8)|| \
	  defined (ADC_V10)|| defined (ADC_V11) || defined (ADC_V12) || defined (ADC_V11_1)
void SetChanADC(unsigned char channel)
{

  ADCON0 = ((channel >> 1) & 0b00111100) |
           (ADCON0 & 0b11000011);

}
#elif defined (ADC_V9) || defined (ADC_V9_1)
void SetChanADC(unsigned char channel)
{

  WDTCONbits.DEVCFG = 0;  
  ADCON0 = ((channel >> 1) & 0b00111100) |
 	       (ADCON0 & 0b11000011);

}

#elif defined (ADC_V13) || defined (ADC_V13_1) || defined (ADC_V13_2)\
	|| defined (ADC_V13_3) || defined (ADC_V14) || defined (ADC_V14_1) || defined (ADC_V14_2) || defined (ADC_V14_3)
void SetChanADC(unsigned char channel)
{
  ADCON0 = (ADCON0 & 0b10000011)|
           ((channel) & 0b01111100);
}

#elif defined (ADC_V15) || defined (ADC_V15_1) 
void SetChanADC(unsigned char channelA , unsigned char channelB )
{
  ADCHS0L = (ADCHS0L & 0b00000000)|
           ((channelA) & 0b11111111);
  ADCHS0H = (ADCHS0H & 0b00000000)|
           ((channelB) & 0b11111111); 
} 		   
#endif




