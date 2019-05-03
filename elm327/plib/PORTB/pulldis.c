#include <p18cxxx.h>
#include <portb.h>

/* Disable PORTB resistors */
#if defined (PTB_V1) || defined (PTB_V2) || defined (PTB_V3) || defined (PTB_V4) || defined (PTB_V6) || defined (PTB_V7) || defined (PTB_V7_1)
#undef DisablePullups
void DisablePullups(void)
{
  INTCON2bits.RBPU=1;
}
#elif defined (PTB_V5)
#undef DisablePullups
void DisablePullups(void)
{
  INTCON2bits.RABPU=1;
}
#endif

