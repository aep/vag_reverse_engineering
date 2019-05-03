#include <p18cxxx.h>
#include <usart.h>

/* Only these devices have two USART modules: USART1 & USART2. */
#if defined (AUSART_V2 ) ||defined (EAUSART_V6 ) ||defined (EAUSART_V7 ) ||\
    defined (EAUSART_V8 ) ||defined (EAUSART_V9 ) || defined (EAUSART_V10) ||\
	defined (EAUSART_V11) || defined (EAUSART_V11_1) || defined (EAUSART_V12)
union USART1 USART1_Status;
#endif
