#include <p18cxxx.h>
#include <adc.h>

#if defined (ADC_V1) || defined (ADC_V2) || defined (ADC_V3) ||\
    defined (ADC_V4) || defined (ADC_V5) || defined (ADC_V8) ||\
	defined (ADC_V6) || defined (ADC_V7) || defined (ADC_V7_1)||\
	defined (ADC_V10)|| defined (ADC_V11) || defined (ADC_V12) ||\
	defined (ADC_V13) || defined (ADC_V13_1) || defined (ADC_V11_1)\
	|| defined (ADC_V13_2) || defined (ADC_V13_3)|| defined (ADC_V14) || defined (ADC_V14_1) || defined (ADC_V14_2) || defined (ADC_V14_3)
/*************************************************************************************
Function :       void CloseADC(void)

Overview :    This function turns off the ADC module and disables the ADC interrupts

Parameters :  None

Returns :        None

Remarks :     This function first disables the ADC interrupt and then turns off the ADC
		module.The Interrupt Flag bit (ADIF) is also cleared.
            
***************************************************************************************/
void CloseADC(void)
{
  ADCON0bits.ADON = 0;
  PIE1bits.ADIE = 0;
}

#elif defined (ADC_V9) || defined (ADC_V9_1)
/*************************************************************************************
Function :       void CloseADC(void)

Overview :    This function turns of the ADC module and disables the ADC interrupts

Parameters :  None

Returns :        None

Remarks :     This function first disables the ADC interrupt and then turns off the ADC
		module.The Interrupt Flag bit (ADIF) is also cleared.
            
***************************************************************************************/
void CloseADC(void)
{
  WDTCONbits.DEVCFG = 0;  
  ADCON0bits.ADON = 0;
  PIE1bits.ADIE = 0;
}

#elif defined (ADC_V15) || defined (ADC_V15_1)
/*************************************************************************************
Function :       void CloseADC(void)

Overview :    This function turns of the ADC module and disables the ADC interrupts

Parameters :  None

Returns :        None

Remarks :     This function first disables the ADC interrupt and then turns off the ADC
		module.The Interrupt Flag bit (ADIF) is also cleared.
            
***************************************************************************************/
void CloseADC(void)
{
  ADCON1Hbits.ADON = 0;
  PIE1bits.ADIE = 0;
}
#endif
