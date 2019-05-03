#include <pconfig.h>

#include"CANenabl.h"

#if defined (SPI_V1) || defined (SPI_V2) || defined (SPI_V3)|| defined (SPI_V4)||defined (SPI_V5)
/*******************************************************************/
/*                                                                 */
/*  Function Name:  CAN2510Enable                                  */
/*  Return Value:   void                                           */
/*  Parameters:     none                                           */
/*  Description:    This function drives the MCP2510 CS pin Low    */
/*                                                                 */
/*******************************************************************/


void CAN2510Enable( void )
{

    LATname(C)  &= ~( 1 << 2 );        // Force selected pin output latch low, others unchanged
    TRISname(C) &= ~( 1 << 2 );        // Make selected pin an output

}


/*******************************************************************/
/*                                                                 */
/*  Function Name:  CAN2510Disable                                 */
/*  Return Value:   void                                           */
/*  Parameters:     none                                           */
/*  Description:    This function drives the MCP2510 CS pin High   */
/*                                                                 */
/*  NOTE:  The user MUST modify this file to specified the         */
/*         desired PIC18Cxxx I/O pin that will be used to          */
/*         interface to the MCP2510 CS pin                         */
/*                                                                 */
/*******************************************************************/

void CAN2510Disable( void )
{

    LATname(C)  |= ( 1 << 2 );         // Force selected pin output latch high, others unchanged
    TRISname(C) &= ~( 1 << 2 );        // Make selected pin an output

}
#endif
