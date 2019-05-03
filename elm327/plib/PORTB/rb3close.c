#include <p18cxxx.h>
#include <portb.h>

/* Disable RB3INT interrupt */
#if defined (PTB_V2) || defined (PTB_V3) || defined (PTB_V6) || defined (PTB_V7)

#undef CloseRB3INT
void CloseRB3INT(void)
{
  INTCON3bits.INT3IE=0;
}
#endif
