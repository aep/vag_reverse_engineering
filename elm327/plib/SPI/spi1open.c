#include <p18cxxx.h>
#include <spi.h>

/********************************************************************
*   Function Name:  OpenSPI1                                        *
*   Return Value:   void                                            *
*   Parameters:     SSP1 peripheral setup bytes                     *
*   Description:    This function sets up the SSP1 module on a      * 
*                   PIC18Cxxx device for use with a Microchip SPI   *
*                   EEPROM device or SPI bus device.                *
********************************************************************/
#if defined (SPI_V2) || defined (SPI_V3)
void OpenSPI1( unsigned char sync_mode, unsigned char bus_mode, unsigned char smp_phase)
{
  SSP1STAT &= 0x3F;               // power on state 
  SSP1CON1 = 0x00;                // power on state
  SSP1CON1 |= sync_mode;          // select serial mode 
  SSP1STAT |= smp_phase;          // select data input sample phase

  switch( bus_mode )
  {
    case 0:                       // SPI1 bus mode 0,0
      SSP1STATbits.CKE = 1;       // data transmitted on rising edge
      break;    
    case 2:                       // SPI1 bus mode 1,0
      SSP1STATbits.CKE = 1;       // data transmitted on falling edge
      SSP1CON1bits.CKP = 1;       // clock idle state high
      break;
    case 3:                       // SPI1 bus mode 1,1
      SSP1CON1bits.CKP = 1;       // clock idle state high
      break;
    default:                      // default SPI1 bus mode 0,1
      break;
  }
 switch( sync_mode )
  {
    case 4:                       // slave mode w /SS enable
	#if defined SPI_IO_V1 
	 	TRISCbits.TRISC3 = 1;       // define clock pin as input	
      	TRISAbits.TRISA5 = 1;       // define /SS1 pin as input
    #elif defined SPI_IO_V2 
		TRISFbits.TRISF7 = 1;       // define /SS1 pin as input
	 	TRISCbits.TRISC3 = 1;       // define clock pin as input
	#endif
		break;

	case 5:                       // slave mode w/o /SS enable
		TRISCbits.TRISC3 = 1;       // define clock pin as input	
    	break;
    
	default:                      	// master mode, define clock pin as output
    	TRISCbits.TRISC3 = 0;       // define clock pin as output	
    	 break;
  }
		TRISCbits.TRISC4 = 1;       // define SDI pin as input
	 	TRISCbits.TRISC5 = 0;       // define SDO pin as output
     
  SSP1CON1 |= SSPENB;             	// enable synchronous serial port
 } 
 #endif 
 
#if defined (SPI_V5) || defined (SPI_V5_1) || defined (SPI_V5_2) || defined (SPI_V6)
void OpenSPI1( unsigned char sync_mode, unsigned char bus_mode, unsigned char smp_phase)
{
  SSP1STAT &= 0x3F;               // power on state 
  SSP1CON1 = 0x00;                // power on state
  SSP1CON1 |= sync_mode;          // select serial mode 
  SSP1STAT |= smp_phase;          // select data input sample phase

  switch( bus_mode )
  {
    case 0:                       // SPI1 bus mode 0,0
      SSP1STATbits.CKE = 1;       // data transmitted on rising edge
      break;    
    case 2:                       // SPI1 bus mode 1,0
      SSP1STATbits.CKE = 1;       // data transmitted on falling edge
      SSP1CON1bits.CKP = 1;       // clock idle state high
      break;
    case 3:                       // SPI1 bus mode 1,1
      SSP1CON1bits.CKP = 1;       // clock idle state high
      break;
    default:                      // default SPI1 bus mode 0,1
      break;
  }
  
   switch( sync_mode )
  {
    case 4:                       // slave mode w /SS enable
	#if defined SPI_IO_V15 
	 	TRISAbits.TRISA5 = 1;       // define /SS2 pin as input
		TRISBbits.TRISB2 = 1;       // define clock pin as input	
    #elif defined SPI_IO_V11 || defined (SPI_IO_V12) || defined (SPI_IO_V13)
		TRISAbits.TRISA5 = 1;       // define /SS1 pin as input
	 	TRISCbits.TRISC3 = 1;       // define clock pin as input
	#elif defined SPI_IO_V14
		TRISAbits.TRISA5 = 1;       // define /SS pin as input
	 	TRISBbits.TRISB4 = 1;       // define clock pin as input
	#elif defined SPI_IO_V10
		TRISFbits.TRISF7 = 1;       // define /SS pin as input
	 	TRISCbits.TRISC3 = 1;       // define clock pin as input
	#endif
		break;

	case 5:                       // slave mode w/o /SS enable
	#if defined SPI_IO_V15 
	 	TRISBbits.TRISB2 = 1;       // define clock pin as input	
    #elif defined SPI_IO_V11 || defined (SPI_IO_V12) || defined (SPI_IO_V13) || defined (SPI_IO_V10)
		TRISCbits.TRISC3 = 1;       // define clock pin as input
	#elif defined SPI_IO_V14
		TRISBbits.TRISB4 = 1;       // define clock pin as input
	#endif
		break;
	
	default:                      // master mode, define clock pin as output
    #if defined SPI_IO_V15 
	 	TRISBbits.TRISB2 = 0;       // define clock pin as output	
    #elif defined SPI_IO_V11 || defined (SPI_IO_V12) || defined (SPI_IO_V13) || defined (SPI_IO_V10)
		TRISCbits.TRISC3 = 0;       // define clock pin as output
	#elif defined SPI_IO_V14
		TRISBbits.TRISB4 = 0;       // define clock pin as output
	#endif
	   	 break;
  }
	#if defined SPI_IO_V15 
		TRISBbits.TRISB0 = 1;       // define SDI pin as input
	 	TRISBbits.TRISB3 = 0;       // define SDO pin as output	
    #elif defined SPI_IO_V11 || defined (SPI_IO_V12) || defined (SPI_IO_V13) || defined (SPI_IO_V10)
		TRISCbits.TRISC4 = 1;       // define SDI pin as input
	 	TRISCbits.TRISC5 = 0;       // define SDO pin as output
	#elif defined SPI_IO_V14
		TRISBbits.TRISB5 = 1;       // define SDI pin as input
	 	TRISCbits.TRISC7 = 0;       // define SDO pin as output
	#endif
  
  SSP1CON1 |= SSPENB;             	// enable synchronous serial port
 }
 
 #endif
