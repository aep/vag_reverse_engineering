#include <p18cxxx.h>
#include <adc.h>

#if defined (ADC_V1)
void OpenADC( unsigned char config, 
              unsigned char config2)
{
  ADCON0 = 0;

  ADCON1 = config;
  ADCON0 = ((config<<2) & 0xC0)|(config2 & 0b00111000);
  if( config2 & 0b10000000 )
  {
    PIR1bits.ADIF = 0;
    PIE1bits.ADIE = 1;
    INTCONbits.PEIE = 1;
  }
  ADCON0bits.ADON = 1;
}

#elif defined (ADC_V2)
void OpenADC( unsigned char config, 
              unsigned char config2)
{
  ADCON0 = 0;
  ADCON1 = 0;
  ADCON2 = 0;
  
  ADCON0 = (config2 >> 1) & 0b00111100;
  ADCON1 = ((config2 << 4) & 0b00110000) |
           (config & 0b00001111);
  ADCON2 = (config & 0b10000000) |
           ((config >> 4) & 0b00000111);

  if( config2 & 0b10000000 )
  {
    PIR1bits.ADIF = 0;
    PIE1bits.ADIE = 1;
    INTCONbits.PEIE = 1;
  }
  ADCON0bits.ADON = 1;
}

#elif defined (ADC_V3)
void OpenADC( unsigned char config,
              unsigned char config2,
              unsigned char portconfig)
{
    ADCON0 = 0;
    ADCON2 = 0;

    ADCON0 = ((config2 >> 1) & 0b00111100) |
	         ((config2 << 6) & 0b11000000);
	ADCON1 = portconfig;
    ADCON2 = ((config & 0b10000000)|((config >> 4) & 0b00000111)) |
	         ((config << 2) & 0b00111000);

    if( config2 & 0b10000000 )
    {
      PIR1bits.ADIF = 0;
      PIE1bits.ADIE = 1;
      INTCONbits.PEIE = 1;
    }
    ADCON0bits.ADON = 1;
}

#elif defined (ADC_V4) || defined (ADC_V5) || defined (ADC_V6)
void OpenADC( unsigned char config,
              unsigned char config2,
              unsigned char portconfig)
{
    ADCON0 = 0;
    ADCON2 = 0;

    ADCON0 = (config2 >> 1) & 0b00111100;	// GET CHANNELS 
    ADCON1 = (portconfig & 0b00001111) |                   // GET CONFIG
	         ((config2 << 4) & 0b00110000); //GET  Vref
    ADCON2 = (config & 0b10000000)	|	// RESULT
             ((config >> 4) & 0b00000111) |	// CONV CLK
             ((config << 2) & 0b00111000);	// ACQ TIME

    if( config2 & 0b10000000 )			// ADC INT.
    {
      PIR1bits.ADIF = 0;
      PIE1bits.ADIE = 1;
      INTCONbits.PEIE = 1;
    }
    ADCON0bits.ADON = 1;
}

#elif defined (ADC_V8)
void OpenADC( unsigned char config,
              unsigned char config2,
              unsigned int portconfig)
{
    ADCON0 = 0;
    ADCON1 = 0;
    ADCON2 = 0;

    ADCON0 = (config2 >> 1) & 0b00111100;
    ADCON1 |= (config2 << 4) & 0b00110000;
    ADCON2 = config & 0b10000000 |
             ((config >> 4) & 0b00000111) |
             ((config << 2) & 0b00111000);

    ANSEL = portconfig;
    ANSELH = (portconfig >> 8);
	if( config2 & 0b10000000 )
    {
      PIR1bits.ADIF = 0;
      PIE1bits.ADIE = 1;
      INTCONbits.PEIE = 1;
    }
    ADCON0bits.ADON = 1;
}

#elif defined (ADC_V7)
void OpenADC( unsigned char config1, 
              unsigned char config2, 
              unsigned char config3)
{	// Reset A/D Registers to POR state    
	ADCON0 = 0;
    ADCON1 = 0;
	ADCON3 = 0;	
	ANSEL0 = 0;
	ANSEL1 = 0;
	ADCHS  = 0;
	
	ADCON0 = (config1<<2) & 0b00111100;	//assign Conv type, conv mode and conv seq.
	ADCON1 = (config2 & 0b11000000) | ((config2 >>1) & 0b00010000);
	ADCON2 = config3;
	ADCON3 = (config2 & 0b00011111) | (config1 & 0b11000000);
    if(config1 & 0b00100000)	
	{
		PIR1bits.ADIF = 0;
      	PIE1bits.ADIE = 1;
      	INTCONbits.PEIE = 1;
	}
	ADCON0bits.ADON = 1;         // Enable the A/D module
}

#elif defined (ADC_V7_1)
void OpenADC( unsigned char config1, 
              unsigned char config2, 
              unsigned char config3)
{	// Reset A/D Registers to POR state    
	ADCON0 = 0;
    ADCON1 = 0;
	ADCON3 = 0;	
	ANSEL0 = 0;
	ADCHS  = 0;
	
	ADCON0 = (config1<<2) & 0b00111100;	//assign Conv type, conv mode and conv seq.
	ADCON1 = (config2 & 0b11000000) | ((config2 >>1) & 0b00010000);
	ADCON2 = config3;
	ADCON3 = (config2 & 0b00011111) | (config1 & 0b11000000);
    if(config1 & 0b00100000)	
	{
		PIR1bits.ADIF = 0;
      	PIE1bits.ADIE = 1;
      	INTCONbits.PEIE = 1;
	}
	ADCON0bits.ADON = 1;         // Enable the A/D module
}

#elif defined (ADC_V9) || defined (ADC_V9_1)
void OpenADC( unsigned char config,
              unsigned char config2,
              unsigned int portconfig)
{
    WDTCONbits.ADSHR = 0;
    ADCON0 = 0;
    ADCON1 = 0;

    ADCON0 = ((config2 >> 1) & 0b00111100) | //channel
             ((config2 << 6) & 0b11000000);	//VREF
    ADCON1 = (config & 0b10000000) | //Result Format
             ((config >> 4) & 0b00000111) | //Conversion clock select
             ((config << 2) & 0b00111000); //acquisition time

    WDTCONbits.ADSHR= 1;
    ANCON0 = portconfig;
    ANCON1 = (portconfig >> 8);
    WDTCONbits.ADSHR= 0;	

	if( config2 & 0b10000000 )
    {
      PIR1bits.ADIF = 0;
      PIE1bits.ADIE = 1;
      INTCONbits.PEIE = 1;
    }
    ADCON0bits.ADON = 1;
}

#elif defined (ADC_V10)
void OpenADC( unsigned char config,
              unsigned char config2,
              unsigned char config3,
              unsigned int portconfig)
{
    ADCON0 = 0;
    ADCON1 = 0;
    ADCON2 = 0;

    ADCON0 = (config2 >> 1) & 0b00111100;  			//channel selection 
    ADCON1 = (config3 & 0b00001100) | //Positive Voltage Reference Configuration bits
             (config3 & 0b00000011);  //Negative Voltage Reference Configuration bits    
    ADCON2 = (config & 0b10000000) |
             ((config >> 4) & 0b00000111) |		//A/D Conversion Clock Select bits
             ((config << 2) & 0b00111000);		//A/D Acquisition Time Select bits 

    ANSEL = portconfig;							//Didn't Change
    ANSELH = (portconfig >> 8);					//Didn't Change
    
	if( config2 & 0b10000000 )					//interrupt enable check
    {
      PIR1bits.ADIF = 0;						//Clear the ADC Interrupt bit
      PIE1bits.ADIE = 1;						//Enable the ADC Interrupt
      INTCONbits.PEIE = 1;						//Peripheral Interrupt Enable
    }
    ADCON0bits.ADON = 1;						//A/D Conversion Status bit--A/D converter module is operating
}

#elif defined (ADC_V11)
void OpenADC( unsigned char config,
              unsigned char config2,
              unsigned int  config3)
{    
    ADCON0 = 0;
    ADCON1 = 0;

    ADCON0 = ((config2 >> 1) & 0b00111100) | //channel selection
             ((config2 << 6) & 0b11000000);	//VREF			 
    ADCON1 = (config & 0b10000000) | //Result Format 
             ((config >> 4) & 0b00000111) | //Conversion clock select
             ((config << 2) & 0b00111000); //acquisition time
			 
    ANCON0 = config3; // port configuration
    ANCON1 = config3 >> 8;  // VBG Selection and port configuration

	if( config2 & 0b10000000 )
    {
      PIR1bits.ADIF = 0;
      PIE1bits.ADIE = 1;
      INTCONbits.PEIE = 1;
    }
    ADCON0bits.ADON = 1;
}

#elif defined (ADC_V11_1)
void OpenADC( unsigned char config,
              unsigned char config2,
			  unsigned char config3,
              unsigned int  portconfig)
{    
    ADCON0 = 0;
    ADCON1 = 0;

    ADCON0 = ((config2 >> 1) & 0b00111100) | //channel selection
             ((config2 << 6) & 0b11000000);	//VREF			 
    ADCON1 = (config & 0b10000000) | //Result Format 
             ((config >> 4) & 0b00000111) | //Conversion clock select
             ((config << 2) & 0b00111000); //acquisition time
			 
    ANCON0 = portconfig; // port configuration
    ANCON1 = portconfig >> 8;  // VBG Selection and port configuration
	
	ADCTRIG = (config3&0xC0)>>6;

	if( config2 & 0b10000000 )
    {
      PIR1bits.ADIF = 0;
      PIE1bits.ADIE = 1;
      INTCONbits.PEIE = 1;
    }
    ADCON0bits.ADON = 1;
}

#elif defined (ADC_V12)
void OpenADC( unsigned char config,
              unsigned char config2,
              unsigned char config3)
{
    ADCON0 = 0;
    ADCON2 = 0;

    ADCON0 = (config2 >> 1) & 0b00111100;	// GET CHANNELS 
    ADCON1 = (config3  & 0b10001111)|   
	         ((config2 << 4) & 0b00110000); //GET  Vref
    ADCON2 = (config & 0b10000000)	|	// RESULT
             ((config >> 4) & 0b00000111) |	// CONV CLK
             ((config << 2) & 0b00111000);	// ACQ TIME

    if( config2 & 0b10000000 )			// ADC INT.
    {
      PIR1bits.ADIF = 0;
      PIE1bits.ADIE = 1;
      INTCONbits.PEIE = 1;
    }
    ADCON0bits.ADON = 1;
}

#elif defined (ADC_V13) || defined (ADC_V13_1) || defined (ADC_V13_2)\
	|| defined (ADC_V13_3) || defined (ADC_V14) || defined (ADC_V14_1) || defined (ADC_V14_2) || defined (ADC_V14_3)
void OpenADC( unsigned char config,
              unsigned char config2,
              unsigned char config3)
{
    ADCON0 = 0;
	ADCON1 = 0;
    ADCON2 = 0;

    ADCON0 = (config2) & 0b01111100;	// GET CHANNELS 
	
    ADCON1 = config3; // Vref+/- & Trigger & Negetive channel select
			 
    ADCON2 = (config & 0b10000000)	|	// RESULT
             ((config >> 4) & 0b00000111) |	// CONV CLK
             ((config << 2) & 0b00111000);	// ACQ TIME
	
    if( config2 & 0b10000000 )			// ADC INT.
    {
      PIR1bits.ADIF = 0;
      PIE1bits.ADIE = 1;
      INTCONbits.PEIE = 1;
    }
    ADCON0bits.ADON = 1;
}


#elif defined (ADC_V15) || defined (ADC_V15_1)
void OpenADC( unsigned char config,
			  unsigned char config1,
              unsigned char config2,
              unsigned char config3,
			  unsigned char config4,
			  unsigned char config5,
              unsigned char config6,
              unsigned char config7
			  )
{
    ADCON1L = 0;
	ADCON1H = 0;
    ADCON2L = 0;
	ADCON2H = 0;
	ADCON3L = 0;
    ADCON3H = 0;
	ADCON5L = 0;
    ADCON5H = 0;

    ADCON1H = config;	// Mode and O/P format
	ADCON1L = (config1) | 0b00000010; //Trigger  & Sample enable bit 
			 
    ADCON2H = config2; // Vref+/- , OFFCAL mode & BUFREGEN
	ADCON2L = config3; // Interrupt sample ,Alt i/p mode
	
	ADCON3L = (config4) | 0b11111111;	//  CONV CLK
	ADCON3H = (config5) | 0b00001111;  // Auto Sample Time select bits
	
	ADCON5L = config6; // Write & Compare mode bits
    ADCON5H = config7; // Auto-Scan bits
	
    if( config & 0b10000000 )			// ADC INT. (ADON is the last bit and hence that is verified to set the interrupts)
    {
      PIR1bits.ADIF = 0;
      PIE1bits.ADIE = 1;
      INTCONbits.PEIE = 1;
    }
    ADCON1Hbits.ADON = 1;
}
#endif
