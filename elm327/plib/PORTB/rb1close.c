#include <p18cxxx.h>
#include <portb.h>

/* Disable RB1INT interrupt */
#if defined (PTB_V1) || defined (PTB_V2) || defined (PTB_V3) ||\
    defined (PTB_V4) || defined (PTB_V5) || defined(PTB_V6) || defined (PTB_V7) || defined (PTB_V7_1)
#undef CloseRB1INT
void CloseRB1INT(void)
{
  INTCON3bits.INT1IE=0;     
}
#endif

