#include <p18cxxx.h>
#include <portb.h>

/* Enable RB3 interrupts, falling edge/rising edge */

#if defined (PTB_V2) || defined (PTB_V3)
void OpenRB3INT(unsigned char config)
{
  	INTCON3bits.INT3IF=0;

  if(config & 0x02)
    INTCON2bits.INTEDG3=1;
  else
    INTCON2bits.INTEDG3=0;
  
  if(config & 0x01)
    INTCON2bits.RBPU=1;
  else
    INTCON2bits.RBPU=0;

  TRISBbits.TRISB3=1;
  
    if(config & 0x40)
      INTCON2bits.RBIP=1;
  else
      INTCON2bits.RBIP=0;
	  
  if(config & 0x40)
      INTCON2bits.INT3IP=1;
  else
      INTCON2bits.INT3IP=0;		  
  
  if(config & 0x80)
      INTCON3bits.INT3IE=1;
  else
      INTCON3bits.INT3IE=0;
  
}

#elif defined (PTB_V6)
void OpenRB3INT(unsigned char config)
{
  	INTCON3bits.INT3IF=0;

  if(config & 0x02)
    INTCON2bits.INTEDG3=1;
  else
    INTCON2bits.INTEDG3=0;
  
  if(config & 0x01)
    INTCON2bits.RBPU=1;
  else
    INTCON2bits.RBPU=0;

  if(config & 0x40)
      INTCON2bits.INT3IP=1;
  else
      INTCON2bits.INT3IP=0;		
	
  if(config & 0x40)
      INTCON2bits.RBIP=1;
  else
      INTCON2bits.RBIP=0;
  
  if(config & 0x80)
      INTCON3bits.INT3IE=1;
  else
      INTCON3bits.INT3IE=0;

}

#elif defined (PTB_V7)
void OpenRB3INT(unsigned char config)
{
  	INTCON3bits.INT3IF=0;

  if(config & 0x02)
    INTCON2bits.INTEDG3=1;
  else
    INTCON2bits.INTEDG3=0;
  
  if(config & 0x01)
    INTCON2bits.RBPU=1;
  else
    INTCON2bits.RBPU=0;

  if(config & 0x40)
      INTCON2bits.INT3IP=1;
  else
      INTCON2bits.INT3IP=0;		
	
  if(config & 0x40)
      INTCON2bits.IOCIP=1;
  else
      INTCON2bits.IOCIP=0;
  
  if(config & 0x80)
      INTCON3bits.INT3IE=1;
  else
      INTCON3bits.INT3IE=0;

}
#endif

