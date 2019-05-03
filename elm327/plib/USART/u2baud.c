#include <p18cxxx.h>
#include "usart.h"

/* **********************************************
 * Function Name: baud2USART                    *
 * Parameters: baudconfig                       *
 *             Configuration setting for the    *
 *             BAUDCON2 register.               *
 * Description: sets the configuration for the  *
 *              BAUDCON2 register.              *
 * **********************************************/
#if defined (EAUSART_V7) || defined (EAUSART_V8) || defined (EAUSART_V9) || defined (EAUSART_V11) || defined (EAUSART_V12)

void baud2USART (unsigned char baudconfig)
{
    BAUDCON2 = baudconfig;
}

#endif
