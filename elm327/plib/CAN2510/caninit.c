#include <pconfig.h>

#include <spi.h>
#include <can2510.h>
#include "spi_can.h"

#if defined (SPI_V1) || defined (SPI_V2) || defined (SPI_V3)|| defined (SPI_V4) ||defined (SPI_V5)
 
/*****************************************************************************************/
/* This shows the registers that are modified in the CAN2510 Initialization, and which   */
/* bits are modified (Y) and which are not modified (N). The bits that are not modified  */
/* are cleared. Some bits that are not modified may be Read Only bits                    */
/*                                      Bit                                              */
/*  Register       7        6        5        4        3        2        1        0      */
/*  CFG1 *        SJW1     SJW0     BRP5     BRP4     BRP3     BRP2     BRP1     BRP0    */
/*                 Y        Y        Y        Y        Y        Y        Y        Y      */
/*     por         0        0        0        0        0        0        0        0      */
/*     default     0        0        0        0        0        0        0        0      */
/*                                                                                       */
/*  CFG2 *      BTLMODE    SAM    PH1SEG2  PH1SEG1  PH1SEG0  PRSEG2   PRSEG1   PRSEG0    */
/*                 Y        Y        Y        Y        Y        Y        Y        Y      */
/*     por         0        0        0        0        0        0        0        0      */
/*     default     0        0        0        0        0        0        0        0      */
/*                                                                                       */
/*  CFG3 *         -     WAKFIL      -        -        -     PH2SEG2  PH2SEG1  PH2SEG0   */
/*                 -        Y        -        -        -        Y        Y        Y      */
/*     por         -        0        -        -        -        0        0        0      */
/*     default     -        0        -        -        -        0        0        0      */
/*                                                                                       */
/*  CANCTRL *   REQOP2   REQOP1   REQOP0    ABAT       -      CLKEN   CLKPRE1  CLKPRE0   */
/*                 Y        Y        Y        N        -        Y        Y        Y      */
/*     por         0        0        0        0        -        0        0        0      */
/*     default     0        0        0        0        -        1        1        1      */
/*                                                                                       */
/*  TXRTSCTRL *    -        -      B2RTS    B1RTS    B0RTS    B2RTSM   B1RTSM   B0RTSM   */
/*                 -        -        N        N        N        Y        Y        Y      */
/*     por         -        -        x        x        x        0        0        0      */
/*     default     -        -        x        x        x        0        0        0      */
/*                                                                                       */
/*  BFPCTRL *      -        -      B1BFS    B0BFS    B1BFE    B0BFE    B1BFM    B0BFM    */
/*                 -        -        Y        Y        Y        Y        Y        Y      */
/*     por         -        -        0        0        0        0        0        0      */
/*     default     -        -        x        x        0        0        x        x      */
/*                                                                                       */
/*  RXB0CTRL *     -      RXB0M1   RXB0M0     -      RXRTR     BUKT    BUKT1   FILHIT0   */
/*                 -        Y        Y        -        N        Y        N        N      */
/*     por         -        0        0        -        0        0        0        0      */
/*     default     -        1        1        -        0        1        1        0      */
/*                                                                                       */
/*  RXB1CTRL *     -      RXB1M1   RXB1M0     -      RXRTR   FILHIT2  FILHIT1  FILHIT0   */
/*                 -        Y        Y        -        N        N        N        N      */
/*     por         -        0        0        -        0        0        0        0      */
/*     default     -        1        1        -        0        0        0        0      */
/*                                                                                       */
/*  CANINTE *    MERRE    WAKIE    ERRIE    TX2IE    TX1IE    TX0IE    RX1IE    RX0IE    */
/*                 Y        Y        Y        Y        Y        Y        Y        Y      */
/*     por         0        0        0        0        0        0        0        0      */
/*     default     0        0        0        0        0        0        0        0      */
/*                                                                                       */
/*  CANINTF *    MERRF    WAKIF    ERRIF    TX2IF    TX1IF    TX0IF    RX1IF    RX0IF    */
/*                 N        N        N        N        N        N        N        N      */
/*     por         0        0        0        0        0        0        0        0      */
/*     default     0        0        0        0        0        0        0        0      */
/*                                                                                       */
/* This shows the registers that are modified in the PIC18CXXX for SPI Initialization,   */
/* and which bits are modified (Y) and which are not modified (N). The bits that are     */
/* not modified are cleared. Some bits that are not modified may be Read Only bits       */
/*     Default SPI mode = 0 0, Sample in middle, and SPI clock = Fosc/4                  */
/*                                      Bit                                              */
/*  Register       7        6        5        4        3        2        1        0      */
/*  SSPSTAT       SMP      CKE      D/A       P        S       R/W       UA       BF     */
/*                 Y        Y        N        N        N        N        N        N      */
/*     por         0        0        0        0        0        0        0        0      */
/*     default     0        1        0        0        0        0        0        0      */
/*                                                                                       */
/*  SSPCON1       WCOL    SSPOV    SSPEN     CKP     SSPM3    SSPM2    SSPM1    SSPM0    */
/*                 N        N        N        Y        Y        Y        Y        Y      */
/*     por         0        0        0        0        0        0        0        0      */
/*     default     0        0        0        0        0        0        0        0      */
/*                                                                                       */
/*  SSPCON2       GCEN   ACKSTAT   ACKDT    ACKEN     RCEN     PEN      RSEN     SEN     */
/*                 N        N        N        N        N        N        N        N      */
/*     por         0        0        0        0        0        0        0        0      */
/*     default     0        0        0        0        0        0        0        0      */
/*                                                                                       */
/*****************************************************************************************/

/*****************************************************************************************/
/*  This shows where the configuration bits are packed into the 2 24 bit variables       */
/*                                                                                       */
/*                                                                                       */
/*  BufferConfig (Short Long - 24 bits)                                                  */
/*      23        22        21        20       19       18        17         16          */
/*    REQOP2    REQOP1    REQOP0      -        -       CLKEN    CLKPRE1    CLKPRE0       */
/*                                                                                       */
/*      15        14        13        12       11       10        9          8           */
/*      -       B2RTSM    B1RTSM    B0RTSM    B1BFE    B0BFE     B1BFM      B0BFM        */
/*                                                                                       */
/*      7         6         5         4        3        2         1          0           */
/*   CANRESET   RXB0M1   RXB0M0     B1BFS    B0BFS     BUKT     RXB1M1     RXB1M0        */
/*                                                                                       */
/*                                                                                       */
/*  BitTimeConfig (Short Long - 24 bits)                                                 */
/*      23       22         21        20       19       18        17         16          */
/*      -      WAKFIL       -         -        -      PH2SEG2   PH2SEG1    PH2SEG0       */
/*                                                                                       */
/*      15       14         13        12       11       10        9          8           */
/*    BTLMODE    SAM      PH1SEG2   PH1SEG1  PH1SEG0  PRSEG2    PRSEG1     PRSEG0        */
/*                                                                                       */
/*      7        6          5         4        3        2         1          0           */
/*     SJW1     SJW0       BRP5      BRP4     BRP3     BRP2      BRP1       BRP0         */
/*                                                                                       */
/*****************************************************************************************/

static void CAN2510BitTimeInit( unsigned long BitTimeConfig );      // only used by this function

signed char CAN2510Init( unsigned long BufferConfig,
                           unsigned long BitTimeConfig,
                           unsigned char interruptEnables,
                           unsigned char SPI_syncMode,
                           unsigned char SPI_busMode,
                           unsigned char SPI_smpPhase )
{
    static unsigned char setting;
    unsigned char counter1;           // 0 - FF
    unsigned char counter2;           // 0 - 4

    // Initialize SPI with user selected settings 
    //    SPI_syncMode - SSP mode
    //    SPI_busMode  - SPI mode (00, 01, 10, 11)
    //    SPI_smpPhase - Sample point
    //
    OpenSPI( SPI_syncMode, SPI_busMode, SPI_smpPhase );

    /* If processor reset was selected, do it. This is embedded in BufferConfig variable */
    if(! (BufferConfig & (~CAN2510_RESET)) )
        CAN2510Reset();

    /*************************************************************************/
    /* Set into configuration mode                                           */
    /*************************************************************************/

    CAN2510SetMode(CAN2510_MODE_CONFIG);               // The MCP2510 can now be configured
    counter1 = 0;                                      // Initialize counters
    counter2 = 0;                                      //
    
    //
    // This while loop is to ensure that the device has entered into configuration mode.
    // If the operating mode does not enter configuration mode in a given time frame
    // and error code will be returened.
    //
    while( CAN2510ReadMode() != CAN2510_MODE_CONFIG )          // Test to ensure that entered
    {                                                          //      CAN Configuration mode
         counter1++;                                           // Did Not enter Configuration Mode
                                                               //   Loop Counter, Should do error
                                                               //      if infinite loop 
         if (counter1 == 0)
         {
              CAN2510SetMode(CAN2510_MODE_CONFIG);             // The MCP2510 can now be configured
              counter2++;                                      // Loop Counter 2 incremented
              if (counter2 == 5)
              {
                   return( -1 );                              // could NOT initialize, exit function
              }
         }
    }
    
    /*************************************************************************/
    /* Now Configure the MCP2510. Configure CLKOUT (in CANCTRL register).    */
    /* We need to be in configuration mode to set the configuration          */
    /* registers                                                             */
    /*************************************************************************/
    setting = (unsigned char) (BufferConfig >> 16) & 0x07;
    setting |= 0x80;                                          // Maintain the Configuration mode
    CAN2510ByteWrite( CAN2510_REG_CANCTRL, setting );

    /*************************************************************************/
    /* Load the 3 registers (CNF1, CNF2, CNF3) to configure the Bit Time     */
    /*************************************************************************/
    CAN2510BitTimeInit( BitTimeConfig );


    /*************************************************************************/
    /* Select if RTS/TXn pins are:                                           */
    /*                 Request to send or general purpose digital inputs     */
    /*************************************************************************/
    setting = (unsigned char) (BufferConfig >> 12) & 0x07;
    CAN2510ByteWrite( CAN2510_REG_TXRTSCTRL, setting );

    /*************************************************************************/
    /* Select if RxBF pins are:                                              */
    /*                 Receive buffer interrupt,                             */
    /*                 general purpose digital outputs, or                   */
    /*                 hi-impedance input                                    */
    /*************************************************************************/
    setting =  (unsigned char) (BufferConfig >>8) & 0x0F;
    setting |= (unsigned char) (BufferConfig <<1) & 0x30;
    CAN2510ByteWrite( CAN2510_REG_BFPCTRL, setting );

    /*************************************************************************/
    /* Specify Receive Buffer 0 Operating mode and if RXB0 will roll over    */
    /* to RXB1                                                               */
    /*************************************************************************/
    setting =  (unsigned char) ( ~ ((BufferConfig) & 0x60) | ((BufferConfig) & 0x04) );
    CAN2510ByteWrite( CAN2510_REG_RXB0CTRL, setting );

    /*************************************************************************/
    /* Specify Receive Buffer 1 Operating mode                               */
    /*************************************************************************/
    setting = (unsigned char) ( ~ (BufferConfig << 5) & 0x60 );
    CAN2510ByteWrite( CAN2510_REG_RXB1CTRL, setting );

    /*************************************************************************/
    /* Clear the interrupt flags                                             */
    /* Select what interrupts are enabled                                    */
    /*************************************************************************/
    setting = ~interruptEnables;
    CAN2510ByteWrite( CAN2510_REG_CANINTF, 0x00 );
    CAN2510ByteWrite( CAN2510_REG_CANINTE, setting );

    return( 0 );                                         // Initialized MCP2510
}



static void CAN2510BitTimeInit( unsigned long BitTimeConfig )
{
    static unsigned char databyte;
    static unsigned char WriteData;

    /********************************************************************/
    /*                                                                  */
    /* Set synchronization jump width and baud rate prescaler           */
    /* Set Propagation Segment and Phase 1 Segment widths               */
    /* Specify the number of times to sample and the source             */
    /* of the Phase 2 Segment time                                      */
    /* Set synchronization jump width and baud rate prescaler           */
    /*                                                                  */
    /* The CNF1, CNF2, and CNF3 registers can only be modified by the   */
    /* bit modify command                                               */
    /*                                                                  */
    /********************************************************************/

    databyte = (unsigned char) (BitTimeConfig);              // All bits used
    WriteData = ~databyte;                                   // Complement the value
    CAN2510ByteWrite( CAN2510_REG_CNF1, WriteData );

    databyte = (unsigned char) (BitTimeConfig >> 8 );        // All bits used
    WriteData = ( (databyte & 0xC0) | (~databyte & 0x3F) );
    CAN2510ByteWrite( CAN2510_REG_CNF2, WriteData );

    databyte = (unsigned char) (BitTimeConfig >> 16 );       // 4 bits used
    databyte &= 0x47;                                        // Zero unused 4 bits
    WriteData = ( (databyte & 0x41) | (~databyte & 0x06) );
    CAN2510ByteWrite( CAN2510_REG_CNF3, WriteData );

}
#endif
