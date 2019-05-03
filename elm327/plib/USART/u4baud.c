#include <p18cxxx.h>
#include "usart.h"

/* **********************************************
 * Function Name: baud4USART                    *
 * Parameters: baudconfig                       *
 *             Configuration setting for the    *
 *             BAUDCON4 register.               *
 * Description: sets the configuration for the  *
 *              BAUDCON4 register.              *
 * **********************************************/
#if defined (EAUSART_V12)

void baud4USART (unsigned char baudconfig)
{
    BAUDCON4 = baudconfig;
}

#endif
