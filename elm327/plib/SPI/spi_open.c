#include <p18cxxx.h>
#include <spi.h>

/********************************************************************
*   Function Name:  OpenSPI                                         *
*   Return Value:   void                                            *
*   Parameters:     SSP peripheral setup bytes                      *
*   Description:    This function sets up the SSP module on a       * 
*                   PIC18Cxxx device for use with a Microchip SPI   *
*                   EEPROM device or SPI bus device.                *
********************************************************************/
#if defined (SPI_V1)

void OpenSPI( unsigned char sync_mode, unsigned char bus_mode, unsigned char smp_phase)
{
  SSPSTAT &= 0x3F;                // power on state 
  SSPCON1 = 0x00;                 // power on state
  SSPCON1 |= sync_mode;           // select serial mode 
  SSPSTAT |= smp_phase;           // select data input sample phase

  switch( bus_mode )
  {
    case 0:                       // SPI bus mode 0,0
      SSPSTATbits.CKE = 1;        // data transmitted on falling edge
      break;    
    case 2:                       // SPI bus mode 1,0
      SSPSTATbits.CKE = 1;        // data transmitted on rising edge
      SSPCON1bits.CKP = 1;        // clock idle state high
      break;
    case 3:                       // SPI bus mode 1,1
      SSPCON1bits.CKP = 1;        // clock idle state high
      break;
    default:                      // default SPI bus mode 0,1
      break;
  }

  switch( sync_mode )
  {
    case 4:                       // slave mode w /SS enable
	#if defined SPI_IO_V1 
	 	TRISCbits.TRISC3 = 1;       // define clock pin as input	
      	TRISAbits.TRISA5 = 1;       // define /SS1 pin as input
    #elif defined SPI_IO_V2 || defined SPI_IO_V4 
		TRISFbits.TRISF7 = 1;       // define /SS pin as input
	 	TRISCbits.TRISC3 = 1;       // define clock pin as input
	#elif defined SPI_IO_V3
		TRISAbits.TRISA5 = 1;       // define /SS pin as input
	 	TRISBbits.TRISB1 = 1;       // define clock pin as input
	#elif defined SPI_IO_V5	
		TRISCbits.TRISC6 = 1;       // define /SS pin as input
	 	TRISCbits.TRISC5 = 1;       // define clock pin as input
	#elif defined SPI_IO_V6
	 	TRISCbits.TRISC3 = 1;       // define clock pin as input	
      	TRISAbits.TRISA5 = 1;       // define /SS1 pin as input
    	ANSEL &= 0b11101111;
	#elif defined SPI_IO_V9
		TRISBbits.TRISB6 = 1;		// define clock pin as input
		TRISCbits.TRISC6 = 1;		// define /SS pin as input
	#endif
		break;

case 5:                       // slave mode w/o /SS enable
	#if defined (SPI_IO_V1) || defined (SPI_IO_V6) || defined (SPI_IO_V2) || defined (SPI_IO_V4)
		TRISCbits.TRISC3 = 1;       // define clock pin as input	
    #elif defined SPI_IO_V3
	 	TRISBbits.TRISB1 = 1;       // define clock pin as input
	#elif defined SPI_IO_V5	
	 	TRISCbits.TRISC5 = 1;       // define clock pin as input
	#elif defined SPI_IO_V9
		TRISBbits.TRISB6 = 1;		// define clock pin as input		
	#endif
		break;
    
	default:                      // master mode, define clock pin as output
    #if defined (SPI_IO_V1) || defined (SPI_IO_V6) || defined (SPI_IO_V2) || defined (SPI_IO_V4)
		TRISCbits.TRISC3 = 0;       // define clock pin as output	
    #elif defined SPI_IO_V3
	 	TRISBbits.TRISB1 = 0;       // define clock pin as output
	#elif defined SPI_IO_V5	
	 	TRISCbits.TRISC5 = 0;       // define clock pin as output
	#elif defined SPI_IO_V9
		TRISBbits.TRISB6 = 0;		// define clock pin as output		
	#endif	 
	 
	 break;
  }
	#if defined SPI_IO_V3 
	 	TRISBbits.TRISB0 = 1;       // define SDI pin as input	
      	TRISCbits.TRISC7 = 0;       // define SDO pin as output
    #elif defined SPI_IO_V5
		TRISCbits.TRISC4 = 1;       // define SDI pin as input
	 	TRISCbits.TRISC7 = 0;       // define SDO pin as output
	#elif defined SPI_IO_V9
		TRISCbits.TRISC7 = 0;       // define SDO pin as output
		TRISBbits.TRISB4 = 1;       // define SDI pin as input			
	#else  
		TRISCbits.TRISC4 = 1;       // define SDI pin as input
	 	TRISCbits.TRISC5 = 0;       // define SDO pin as output
	#endif
  
	SSPCON1 |= SSPENB;              // enable synchronous serial port 
}
#endif

#if defined (SPI_V4)

void OpenSPI( unsigned char sync_mode, unsigned char bus_mode, unsigned char smp_phase)
{
  SSPSTAT &= 0x3F;                // power on state 
  SSPCON = 0x00;                 // power on state
  SSPCON |= sync_mode;           // select serial mode 
  SSPSTAT |= smp_phase;           // select data input sample phase

  switch( bus_mode )
  {
    case 0:                       // SPI bus mode 0,0
      SSPSTATbits.CKE = 1;        // data transmitted on falling edge
      break;    
    case 2:                       // SPI bus mode 1,0
      SSPSTATbits.CKE = 1;        // data transmitted on rising edge
      SSPCONbits.CKP = 1;        // clock idle state high
      break;
    case 3:                       // SPI bus mode 1,1
      SSPCONbits.CKP = 1;        // clock idle state high
      break;
    default:                      // default SPI bus mode 0,1
      break;
  }

  switch( sync_mode )
  {
    case 4:                       // slave mode w /SS enable
	#if defined SPI_IO_V1 
	 	TRISCbits.TRISC3 = 1;       // define clock pin as input	
      	TRISAbits.TRISA5 = 1;       // define /SS1 pin as input
    #elif defined SPI_IO_V2 || defined SPI_IO_V4 
		TRISFbits.TRISF7 = 1;       // define /SS pin as input
	 	TRISCbits.TRISC3 = 1;       // define clock pin as input
	#elif defined SPI_IO_V3
		TRISAbits.TRISA5 = 1;       // define /SS pin as input
	 	TRISBbits.TRISB1 = 1;       // define clock pin as input
	#elif defined SPI_IO_V5	
		TRISCbits.TRISC6 = 1;       // define /SS pin as input
	 	TRISCbits.TRISC5 = 1;       // define clock pin as input
	#elif defined SPI_IO_V6
	 	TRISCbits.TRISC3 = 1;       // define clock pin as input	
      	TRISAbits.TRISA5 = 1;       // define /SS1 pin as input
    	ANSEL &= 0b11101111;
	#endif
		break;

case 5:                       // slave mode w/o /SS enable
	#if defined (SPI_IO_V1) || defined (SPI_IO_V6) || defined (SPI_IO_V2) || defined (SPI_IO_V4)
		TRISCbits.TRISC3 = 1;       // define clock pin as input	
    #elif defined SPI_IO_V3
	 	TRISBbits.TRISB1 = 1;       // define clock pin as input
	#elif defined SPI_IO_V5	
	 	TRISCbits.TRISC5 = 1;       // define clock pin as input
	#endif
		break;
    
	default:                      // master mode, define clock pin as output
    #if defined (SPI_IO_V1) || defined (SPI_IO_V6) || defined (SPI_IO_V2) || defined (SPI_IO_V4)
		TRISCbits.TRISC3 = 0;       // define clock pin as output	
    #elif defined SPI_IO_V3
	 	TRISBbits.TRISB1 = 0;       // define clock pin as output
	#elif defined SPI_IO_V5	
	 	TRISCbits.TRISC5 = 0;       // define clock pin as output
	#endif
	 
	 break;
  }
	#if defined SPI_IO_V3 
	 	TRISBbits.TRISB0 = 1;       // define SDI pin as input	
      	TRISCbits.TRISC7 = 0;       // define SDO pin as output
    #elif defined SPI_IO_V5
		TRISCbits.TRISC4 = 1;       // define SDI pin as input
	 	TRISCbits.TRISC7 = 0;       // define SDO pin as output
	#else  
		TRISCbits.TRISC4 = 1;       // define SDI pin as input
	 	TRISCbits.TRISC5 = 0;       // define SDO pin as output
	#endif
  
	SSPCON |= SSPENB;              // enable synchronous serial port 
}
#endif
