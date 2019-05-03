#include <p18cxxx.h>
#include <portb.h>

/* Disable PORTB interrupts, resistors */
#if defined (PTB_V1) || defined (PTB_V2) || defined (PTB_V3) || defined (PTB_V4) || defined (PTB_V6)
#undef ClosePORTB
void ClosePORTB(void)
{
  INTCONbits.RBIE=0;  //Turn off PORTB interrupt on change
  DisablePullups();
}
#elif defined (PTB_V5)
#undef ClosePORTB
void ClosePORTB(void)
{
  INTCONbits.RABIE=0;
  DisablePullups();
}
#elif defined (PTB_V7) || defined (PTB_V7_1)
#undef ClosePORTB
void ClosePORTB(void)
{
  INTCONbits.IOCIE=0;
  DisablePullups();
}
#endif
