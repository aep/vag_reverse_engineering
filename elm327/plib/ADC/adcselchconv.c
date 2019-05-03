#include <p18cxxx.h>
#include <adc.h>

#if defined (ADC_V1)
void SelChanConvADC(unsigned char channel)
{
  ADCON0 = (ADCON0 & 0b11000011)|
           (channel & 0b00111000);
  ADCON0bits.GO = 1;
}

#elif defined (ADC_V2) || defined (ADC_V3) || defined (ADC_V4) ||\
      defined (ADC_V5) || defined (ADC_V6) || defined (ADC_V8) ||\
	  defined (ADC_V10)|| defined (ADC_V11) || defined (ADC_V12) || defined (ADC_V11_1)
void SelChanConvADC(unsigned char channel)
{
  ADCON0 = (ADCON0 & 0b11000011)|
           ((channel >> 1) & 0b00111100);
  ADCON0bits.GO = 1;
}

#elif defined (ADC_V9) || defined (ADC_V9_1)
void SelChanConvADC(unsigned char channel)
{
    WDTCONbits.DEVCFG = 0;   
    ADCON0 = (ADCON0 & 0b11000011)|
	         ((channel >> 1) & 0b00111100);   
    ADCON0bits.GO = 1;
}

#elif defined (ADC_V7) 
void SelChanConvADC( unsigned char channel)
{	
   if(channel!=8)
      ANSEL0 = 0b00000001 << channel;
   else
      ANSEL1 = 0b00000001;
	  
   switch (channel)
    {
        case 0: 
		        ADCHS |=  0b00000011;
	            ADCHS &=  0b11111100;
			    break;			   
	    case 4: 
		        ADCHS |=  0b00000011;
				ADCHS &=  0b11111101;		
	            break;
	    case 8:
                ADCHS |=  0b00000011;
				ADCHS &=  0b11111110;		
	            break;
        case 1: 
		        ADCHS |=  0b00110000;
				ADCHS &=  0b11001111;
	            break;
		case 5: 
		        ADCHS |=  0b00110000;
				ADCHS &=  0b11011111;
	            break;
		case 2:
                ADCHS |=  0b00001100;
				ADCHS &=  0b11110011; 		
	            break;
		case 6: 
		        ADCHS |=  0b00001100;
				ADCHS &=  0b11110111;
	           break;
		case 3: 
		        ADCHS |=  0b11000000;
				ADCHS &=  0b00111111;
	            break;
		case 7: 
		        ADCHS |=  0b11000000;
			    ADCHS &=  0b01111111;
	            break;	
    }
  ADCON0bits.GO = 1;	
}

#elif defined (ADC_V7_1)
void SelChanConvADC( unsigned char channel)
{	
    ANSEL0 = 0b00000001 << channel;
    
   switch (channel)
    {
        case 0: 
		        ADCHS |=  0b00000011;
	            ADCHS &=  0b11111100;
			    break;			   
	    case 4: 
		        ADCHS |=  0b00000011;
				ADCHS &=  0b11111101;		
	            break;
	    case 1: 
		        ADCHS |=  0b00110000;
				ADCHS &=  0b11001111;
	            break;
		case 2:
                ADCHS |=  0b00001100;
				ADCHS &=  0b11110011; 		
	            break;
		case 3: 
		        ADCHS |=  0b11000000;
				ADCHS &=  0b00111111;
	            break;		
    }
  ADCON0bits.GO = 1;	
}

#elif defined (ADC_V13) || defined (ADC_V13_1) || defined (ADC_V13_2)\
	|| defined (ADC_V13_3) || defined (ADC_V14) || defined (ADC_V14_1) || defined (ADC_V14_2) || defined (ADC_V14_3)
void SelChanConvADC(unsigned char channel)
{
  ADCON0 = (ADCON0 & 0b10000011)|
           ((channel) & 0b01111100);
  ADCON0bits.GO = 1;
}

#elif defined (ADC_V15) || defined (ADC_V15_1) 
void SelChanConvADC(unsigned char channelA , unsigned char channelB )
{
  ADCHS0L = (ADCHS0L & 0b00000000)|
           ((channelA) & 0b11111111);
  ADCHS0H = (ADCHS0H & 0b00000000)|
           ((channelB) & 0b11111111); 
  ADCON1Lbits.SAMP = 0;		   
}
#endif
