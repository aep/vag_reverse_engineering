#include <p18cxxx.h>
#include <portb.h>

/* Enable RB0INT interrupt, falling edge/rising edge */

#if defined (PTB_V1) || defined (PTB_V2)
void OpenRB0INT(unsigned char config)
{
  INTCONbits.INT0IF=0;

  if(config&0x02)			//select edge	
    INTCON2bits.INTEDG0=1;
  else
    INTCON2bits.INTEDG0=0;

  if(config &0x01)		//disable pullups
		INTCON2bits.RBPU=1;
  else
		INTCON2bits.RBPU=0;
  	TRISBbits.TRISB0=1;
	
  if(config & 0x40)
      INTCON2bits.RBIP=1;
  else
      INTCON2bits.RBIP=0;
	
  if(config&0x80)			//enable interrupt
		INTCONbits.INT0IE=1;
  else
      INTCONbits.INT0IE=0;

}

#elif defined (PTB_V3)
void OpenRB0INT(unsigned char config)
{
	INTCONbits.INT0IF=0;

  if(config & 0x02)
	INTCON2bits.INTEDG0=1;
  else
	INTCON2bits.INTEDG0=0;

  TRISAbits.TRISA0 = 1;
  
   if(config & 0x40)
      INTCON2bits.RBIP=1;
  else
      INTCON2bits.RBIP=0;
	
  if(config&0x80)			//enable interrupt
	INTCONbits.INT0IE=1;
  else 
	INTCONbits.INT0IE=0;

}

#elif defined (PTB_V4)
void OpenRB0INT(unsigned char config)
{
  INTCONbits.INT0IF=0;

  if(config & 0x02)
    INTCON2bits.INTEDG0=1;
  else
    INTCON2bits.INTEDG0=0;

	TRISCbits.TRISC3 = 1;
	
  if(config & 0x40)
      INTCON2bits.RBIP=1;
  else
      INTCON2bits.RBIP=0;
	
  if(config&0x80)			//enable interrupt
	INTCONbits.INT0IE=1;
  else 
	INTCONbits.INT0IE=0;
	
}

#elif defined (PTB_V5)
void OpenRB0INT(unsigned char config)
{
  INTCONbits.INT0IF=0;

  if(config & 0x02)
    INTCON2bits.INTEDG0=1;
  else
    INTCON2bits.INTEDG0=0;

	TRISCbits.TRISC0 = 1;
	
  if(config&0x80)			//enable interrupt
	INTCONbits.INT0IE=1;
  else 
	INTCONbits.INT0IE=0;
	
}

#elif defined (PTB_V6)
void OpenRB0INT(unsigned char config)
{
  INTCONbits.INT0IF=0;

  if(config&0x02)			//select edge	
		INTCON2bits.INTEDG0=1;
  else
		INTCON2bits.INTEDG0=0;

  if(config &0x01)		//disable pullups
		INTCON2bits.RBPU=1;
  else
		INTCON2bits.RBPU=0;
		
  if(config & 0x40)
      INTCON2bits.RBIP=1;
  else
      INTCON2bits.RBIP=0;
		
  	
  if(config&0x80)			//enable interrupt
		INTCONbits.INT0IE=1;
  else
        INTCONbits.INT0IE=0;
}

#elif defined (PTB_V7) || defined (PTB_V7_1)
void OpenRB0INT(unsigned char config)
{
  INTCONbits.INT0IF=0;

  if(config&0x02)			//select edge	
		INTCON2bits.INTEDG0=1;
  else
		INTCON2bits.INTEDG0=0;

  if(config &0x01)		//disable pullups
		INTCON2bits.RBPU=1;
  else
		INTCON2bits.RBPU=0;
		
  if(config & 0x40)
      INTCON2bits.IOCIP=1;
  else
      INTCON2bits.IOCIP=0;
		
  	
  if(config&0x80)			//enable interrupt
		INTCONbits.INT0IE=1;
  else
        INTCONbits.INT0IE=0;
}

#endif
