#include <p18cxxx.h>
#include <portb.h>

/* Disable RB2INT interrupt */
#if defined (PTB_V1) || defined (PTB_V2) || defined (PTB_V3) ||\
    defined (PTB_V4) || defined (PTB_V5) ||defined (PTB_V6) || defined (PTB_V7) || defined (PTB_V7_1)
#undef CloseRB2INT
void CloseRB2INT(void)
{
  INTCON3bits.INT2IE=0;
}
#endif
