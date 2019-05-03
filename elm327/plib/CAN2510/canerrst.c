#include <pconfig.h>

#include "spi_can.h"
#include <can2510.h>

#if defined (SPI_V1) || defined (SPI_V2) || defined (SPI_V3)|| defined (SPI_V4) ||defined (SPI_V5)

unsigned char CAN2510ErrorState( void )
{

    /*************************************************************************/
    /* Determine the error state of the CAN Bus                              */
    /* - Error Active                                                        */
    /* - Error Active with EWARN set                                         */
    /* - Error Passive                                                       */
    /* - Bus Off                                                             */
    /*************************************************************************/

    CAN2510_REG_EFLGbits_type    BufferEFLG;      // BufferEFLG type so can access bits

    BufferEFLG.byte = CAN2510ByteRead( CAN2510_REG_EFLG );    // Read the EFLG register
                                                              //   so that status can
                                                              //   be determined
    if( BufferEFLG.TXBO == 1 )                                // TEC > 256?
       return( CAN2510_BUS_OFF );                             //   Yes, the transmitter
                                                              //   is Bus Off
    else if( (BufferEFLG.TXEP == 1) )                         // TEC > 127?
       return( CAN2510_ERROR_PASSIVE_TX );                    //   Yes, In Error Passive
                                                              //   mode
    else if( (BufferEFLG.RXEP == 1) )                         // REC > 127?
       return( CAN2510_ERROR_PASSIVE_RX );                    //   Yes, In Error Passive
                                                              //   mode
    else if( (BufferEFLG.TXWARN == 1) )                       // TEC > 95?
       return( CAN2510_ERROR_ACTIVE_WITH_TXWARN );            //   Yes, In Error Active mode
                                                              //   with an TX Error Warning
    else if( (BufferEFLG.RXWARN == 1) )                       // REC > 95?
       return( CAN2510_ERROR_ACTIVE_WITH_RXWARN );            //   Yes, In Error Active mode
                                                              //   with an RX Error Warning
    else                                                      //
       return( CAN2510_ERROR_ACTIVE );                        // In Error Active mode

}

#endif
