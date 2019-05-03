#include <p18cxxx.h>
#include <portb.h>

/* Enable RB2 interrupts, falling edge/rising edge */
#if defined (PTB_V1) || defined (PTB_V2) || defined (PTB_V3)
void OpenRB2INT(unsigned char config)
{
  INTCON3bits.INT2IF=0;
  
  if(config & 0x02)            //Is rising edge used?
    INTCON2bits.INTEDG2=1;   //Yes, rising edge is used
  else
    INTCON2bits.INTEDG2=0;   //No, falling edge is used

  if(config & 0x01)
    INTCON2bits.RBPU=1;
  else
    INTCON2bits.RBPU=0;
  
  TRISBbits.TRISB2=1;
  
  if(config & 0x40)
      INTCON2bits.RBIP=1;
  else
      INTCON2bits.RBIP=0;

  if(config & 0x40)
      INTCON3bits.INT2IP=1;
  else
      INTCON3bits.INT2IP=0;	  	  
  
  if(config & 0x80)
      INTCON3bits.INT2IE=1;
  else
      INTCON3bits.INT2IE=0;  
}

#elif defined (PTB_V4)

void OpenRB2INT(unsigned char config)
{
  INTCON3bits.INT2IF=0;

  if(config & 0x02)
    INTCON2bits.INTEDG2=1;
  else
    INTCON2bits.INTEDG2=0;
 	
  TRISCbits.TRISC5=1;
  
    if(config & 0x40)
      INTCON2bits.RBIP=1;
  else
      INTCON2bits.RBIP=0;
	
  if(config & 0x40)
      INTCON3bits.INT2IP=1;
  else
      INTCON3bits.INT2IP=0;		
  
  if(config & 0x80)
      INTCON3bits.INT2IE=1;
  else
      INTCON3bits.INT2IE=0;

}
#elif defined (PTB_V5)
void OpenRB2INT(unsigned char config)
{
  INTCON3bits.INT2IF=0;

  if(config & 0x02)
    INTCON2bits.INTEDG2=1;
  else
    INTCON2bits.INTEDG2=0;

	TRISCbits.TRISC2 = 1;
	
  if(config & 0x40)
      INTCON3bits.INT2IP=1;
  else
      INTCON3bits.INT2IP=0;		
	
  if(config&0x80)			//enable interrupt
	INTCON3bits.INT2IE=1;
  else 
	INTCON3bits.INT2IE=0;	
}

#elif defined (PTB_V6)
void OpenRB2INT(unsigned char config)
{
  INTCON3bits.INT2IF=0;
  
  if(config&0x02)            //Is rising edge used?
    INTCON2bits.INTEDG2=1;   //Yes, rising edge is used
  else
    INTCON2bits.INTEDG2=0;   //No, falling edge is used

  if(config & 0x01)
    INTCON2bits.RBPU=1;
  else
    INTCON2bits.RBPU=0;
	
  if(config & 0x40)
      INTCON2bits.RBIP=1;
  else
      INTCON2bits.RBIP=0;
	
  if(config & 0x40)
      INTCON3bits.INT2IP=1;
  else
      INTCON3bits.INT2IP=0;		
  
  if(config & 0x80)
      INTCON3bits.INT2IE=1;
  else
      INTCON3bits.INT2IE=0;  
}

#elif defined (PTB_V7) || defined (PTB_V7_1)
void OpenRB2INT(unsigned char config)
{
  INTCON3bits.INT2IF=0;
  
  if(config&0x02)            //Is rising edge used?
    INTCON2bits.INTEDG2=1;   //Yes, rising edge is used
  else
    INTCON2bits.INTEDG2=0;   //No, falling edge is used

  if(config & 0x01)
    INTCON2bits.RBPU=1;
  else
    INTCON2bits.RBPU=0;
	
  if(config & 0x40)
      INTCON2bits.IOCIP=1;
  else
      INTCON2bits.IOCIP=0;
	
  if(config & 0x40)
      INTCON3bits.INT2IP=1;
  else
      INTCON3bits.INT2IP=0;		
  
  if(config & 0x80)
      INTCON3bits.INT2IE=1;
  else
      INTCON3bits.INT2IE=0;  
}

#endif

