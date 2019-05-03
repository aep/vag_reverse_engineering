#include <p18cxxx.h>
#include "usart.h"



/* **********************************************
 * Function Name: baud1USART                    *
 * Parameters: baudconfig                       *
 *             Configuration setting for the    *
 *             BAUDCON1 register.               *
 * Description: sets the configuration for the  *
 *              BAUDCON1 register.              *
 * **********************************************/
#if defined (EAUSART_V6)|| defined (EAUSART_V7) || defined (EAUSART_V8) ||\
    defined (EAUSART_V9) || defined (EAUSART_V10) || defined (EAUSART_V11) || defined (EAUSART_V11_1) \
	|| defined (EAUSART_V12)

void baud1USART (unsigned char baudconfig)
{
    BAUDCON1 = baudconfig;
}

#endif
