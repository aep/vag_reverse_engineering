#include <p18cxxx.h>
#include "usart.h"

/* **********************************************
 * Function Name: baud3USART                    *
 * Parameters: baudconfig                       *
 *             Configuration setting for the    *
 *             BAUDCON3 register.               *
 * Description: sets the configuration for the  *
 *              BAUDCON3 register.              *
 * **********************************************/
#if defined (EAUSART_V12)

void baud3USART (unsigned char baudconfig)
{
    BAUDCON3 = baudconfig;
}

#endif
