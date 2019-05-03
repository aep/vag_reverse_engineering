#include <p18cxxx.h>
#include <portb.h>

/* Configure PORTB interrupts,resistors */
#if defined (PTB_V1) || defined (PTB_V2) || defined (PTB_V3) || defined (PTB_V4) || defined (PTB_V6)
void OpenPORTB(unsigned char config)
{
  //read portb to remove mismatch
  char temp;
  temp=PORTB;            //Read PORTB to remove mismatch/clear RBIF

  if(config&0x01)
    DisablePullups();
  else
    EnablePullups();

 if(config&0x80)
    INTCONbits.RBIE=1;   //enable PORTB Interrupt on change
 else 
	INTCONbits.RBIE=0;   //disable PORTB Interrupt on change
}

#elif defined (PTB_V5)
void OpenPORTB(unsigned char config)
{
  //read portb to remove mismatch
  char temp;
  temp=PORTB;            //Read PORTB to remove mismatch/clear RBIF

  if(config&0x01)
    DisablePullups();
  else
    EnablePullups();

 if(config&0x80)
    INTCONbits.RABIE=1;   //enable PORTB Interrupt on change
 else 
	INTCONbits.RABIE=0;   //disable PORTB Interrupt on change
}

#elif defined (PTB_V7) || defined (PTB_V7_1)
void OpenPORTB(unsigned char config)
{
  //read portb to remove mismatch
  char temp;
  temp=PORTB;            //Read PORTB to remove mismatch/clear RBIF

  if(config&0x01)
    DisablePullups();
  else
    EnablePullups();

 if(config&0x80)
    INTCONbits.IOCIE=1;   //enable PORTB Interrupt on change
 else 
	INTCONbits.IOCIE=0;   //disable PORTB Interrupt on change
}

#endif
