#include <p18cxxx.h>
#include "usart.h"


/* **********************************************
 * Function Name: baudUSART                     *
 * Parameters: baudconfig                       *
 *             Configuration setting for the    *
 *             BAUDCTL register.                *
 * Description: sets the configuration for the  *
 *              BAUDCTL register.               *
 * **********************************************/

#if defined (EAUSART_V3) || defined (EAUSART_V4) || defined (EAUSART_V5)
void baudUSART (unsigned char baudconfig)
{
    BAUDCON = baudconfig;
}

#endif
