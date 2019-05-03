#include <p18cxxx.h>
#include <portb.h>

/* Enable RB1INT interrupts, falling edge/rising edge */

#if defined (PTB_V1) || defined (PTB_V2)
void OpenRB1INT(unsigned char config)
{
  INTCON3bits.INT1IF=0;

  if(config&0x02)          //Is rising edge used
    INTCON2bits.INTEDG1=1; //Yes, rising edge is used
  else
    INTCON2bits.INTEDG1=0; //No, falling edge is used

  if(config & 0x01)			//disable pullups
      INTCON2bits.RBPU=1;
  else
      INTCON2bits.RBPU=0;
	  
  if(config & 0x40)
      INTCON2bits.RBIP=1;
  else
      INTCON2bits.RBIP=0;
	  
  if(config & 0x40)
      INTCON3bits.INT1IP=1;
  else
      INTCON3bits.INT1IP=0;	  
	  
  TRISBbits.TRISB1=1;

  if(config & 0x80)
      INTCON3bits.INT1IE=1;
  else
      INTCON3bits.INT1IE=0;  
  }

#elif defined (PTB_V3)
void OpenRB1INT(unsigned char config)
{
  INTCON3bits.INT1IF=0;

  if(config & 0x02)
    INTCON2bits.INTEDG1=1;
  else
    INTCON2bits.INTEDG1=0;
  
  TRISAbits.TRISA1=1;
  
   if(config & 0x40)
      INTCON2bits.RBIP=1;
  else
      INTCON2bits.RBIP=0;

  if(config & 0x40)
      INTCON3bits.INT1IP=1;
  else
      INTCON3bits.INT1IP=0;	  
	  
  if(config & 0x80) 
    INTCON3bits.INT1IE=1;
  else
	INTCON3bits.INT1IE=0;
	
}

#elif defined (PTB_V4)
void OpenRB1INT(unsigned char config)
{
  INTCON3bits.INT1IF=0;

  if(config & 0x02)
    INTCON2bits.INTEDG1=1;
  else
    INTCON2bits.INTEDG1=0;

  TRISCbits.TRISC4=1;
  
   if(config & 0x40)
      INTCON2bits.RBIP=1;
  else
      INTCON2bits.RBIP=0;
	  
  if(config & 0x40)
      INTCON3bits.INT1IP=1;
  else
      INTCON3bits.INT1IP=0;	  	  
  
  if(config & 0x80) 
    INTCON3bits.INT1IE=1;
  else
	INTCON3bits.INT1IE=0;
	
}
#elif defined (PTB_V5)
void OpenRB1INT(unsigned char config)
{
  INTCON3bits.INT1IF=0;

  if(config & 0x02)
    INTCON2bits.INTEDG1=1;
  else
    INTCON2bits.INTEDG1=0;

	TRISCbits.TRISC1 = 1;

  if(config & 0x40)
      INTCON3bits.INT1IP=1;
  else
      INTCON3bits.INT1IP=0;	  	
	
  if(config&0x80)			//enable interrupt
	INTCON3bits.INT1IE=1;
  else 
	INTCON3bits.INT1IE=0;	
}

#elif defined (PTB_V6)
void OpenRB1INT(unsigned char config)
{
  INTCON3bits.INT1IF=0;

  if(config&0x02)          //Is rising edge used
    INTCON2bits.INTEDG1=1; //Yes, rising edge is used
  else
    INTCON2bits.INTEDG1=0; //No, falling edge is used

  if(config & 0x01)			//disable pullups
      INTCON2bits.RBPU=1;
  else
      INTCON2bits.RBPU=0;
	  
  if(config & 0x40)
      INTCON2bits.RBIP=1;
  else
      INTCON2bits.RBIP=0;

  if(config & 0x40)
      INTCON3bits.INT1IP=1;
  else
      INTCON3bits.INT1IP=0;	  	  

  if(config & 0x80)
      INTCON3bits.INT1IE=1;
  else
      INTCON3bits.INT1IE=0;  
}

#elif defined (PTB_V7) || defined (PTB_V7_1)
void OpenRB1INT(unsigned char config)
{
  INTCON3bits.INT1IF=0;

  if(config&0x02)          //Is rising edge used
    INTCON2bits.INTEDG1=1; //Yes, rising edge is used
  else
    INTCON2bits.INTEDG1=0; //No, falling edge is used

  if(config & 0x01)			//disable pullups
      INTCON2bits.RBPU=1;
  else
      INTCON2bits.RBPU=0;
	  
  if(config & 0x40)
      INTCON2bits.IOCIP=1;
  else
      INTCON2bits.IOCIP=0;

  if(config & 0x40)
      INTCON3bits.INT1IP=1;
  else
      INTCON3bits.INT1IP=0;	  	  

  if(config & 0x80)
      INTCON3bits.INT1IE=1;
  else
      INTCON3bits.INT1IE=0;  
}

  
#endif
