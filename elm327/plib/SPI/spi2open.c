#include <p18cxxx.h>
#include <spi.h>

/********************************************************************
*   Function Name:  OpenSPI2                                        *
*   Return Value:   void                                            *
*   Parameters:     SSP2 peripheral setup bytes                     *
*   Description:    This function sets up the SSP2 module on a      * 
*                   PIC18Cxxx device for use with a Microchip SPI   *
*                   EEPROM device or SPI bus device.                *
********************************************************************/
#if defined (SPI_V3)

void OpenSPI2( unsigned char sync_mode, unsigned char bus_mode, unsigned char smp_phase)
{
  SSP2STAT &= 0x3F;               // power on state 
  SSP2CON1 = 0x00;                // power on state
  SSP2CON1 |= sync_mode;          // select serial mode 
  SSP2STAT |= smp_phase;          // select data input sample phase

  switch( bus_mode )
  {
    case 0:                       // SPI2 bus mode 0,0
      SSP2STATbits.CKE = 1;       // data transmitted on rising edge
      break;    
    case 2:                       // SPI2 bus mode 1,0
      SSP2STATbits.CKE = 1;       // data transmitted on falling edge
      SSP2CON1bits.CKP = 1;       // clock idle state high
      break;
    case 3:                       // SPI2 bus mode 1,1
      SSP2CON1bits.CKP = 1;       // clock idle state high
      break;
    default:                      // default SPI2 bus mode 0,1
      break;
  }

  switch( sync_mode )
  {
    case 4:                       // slave mode w /SS enable
	#if defined SPI_IO_V8 
	 	TRISDbits.TRISD3 = 1;       // define /SS2 pin as input
		TRISDbits.TRISD0 = 1;       // define clock pin as input	
    #else
		TRISDbits.TRISD7 = 1;       // define /SS1 pin as input
	 	TRISDbits.TRISD6 = 1;       // define clock pin as input
	#endif
		break;

	case 5:                       // slave mode w/o /SS enable
	#if defined SPI_IO_V8 
	 	TRISDbits.TRISD0 = 1;       // define clock pin as input	
    #else
		TRISDbits.TRISD6 = 1;       // define clock pin as input
	#endif
		break;
	
	default:                      // master mode, define clock pin as output
    #if defined SPI_IO_V8 
	 	TRISDbits.TRISD0 = 0;       // define clock pin as output	
    #else
		TRISDbits.TRISD6 = 0;       // define clock pin as output
	#endif
	   	 break;
  }
	#if defined SPI_IO_V8 
		TRISDbits.TRISD1 = 1;       // define SDI pin as input
	 	TRISDbits.TRISD2 = 0;       // define SDO pin as output	
    #else
		TRISDbits.TRISD5 = 1;       // define SDI pin as input
	 	TRISDbits.TRISD4 = 0;       // define SDO pin as output
    #endif
 
  SSP2CON1 |= SSPENB;             // enable synchronous serial port 
}
#endif


#if defined (SPI_V5) || defined (SPI_V5_1) || defined (SPI_V6)

void OpenSPI2( unsigned char sync_mode, unsigned char bus_mode, unsigned char smp_phase)
{
  SSP2STAT &= 0x3F;               // power on state 
  SSP2CON1 = 0x00;                // power on state
  SSP2CON1 |= sync_mode;          // select serial mode 
  SSP2STAT |= smp_phase;          // select data input sample phase

  switch( bus_mode )
  {
    case 0:                       // SPI2 bus mode 0,0
      SSP2STATbits.CKE = 1;       // data transmitted on rising edge
      break;    
    case 2:                       // SPI2 bus mode 1,0
      SSP2STATbits.CKE = 1;       // data transmitted on falling edge
      SSP2CON1bits.CKP = 1;       // clock idle state high
      break;
    case 3:                       // SPI2 bus mode 1,1
      SSP2CON1bits.CKP = 1;       // clock idle state high
      break;
    default:                      // default SPI2 bus mode 0,1
      break;
  }
  
    switch( sync_mode )
  {
    case 4:                       // slave mode w /SS enable
	#if defined SPI_IO_V11 
	 	TRISBbits.TRISB0 = 1;       // define /SS2 pin as input
		TRISBbits.TRISB1 = 1;       // define clock pin as input	
    #elif defined SPI_IO_V12
		TRISDbits.TRISD3 = 1;       // define /SS pin as input
	 	TRISDbits.TRISD0 = 1;       // define clock pin as input
	#elif defined SPI_IO_V10
		TRISDbits.TRISD7 = 1;       // define /SS pin as input
	 	TRISDbits.TRISD6 = 1;       // define clock pin as input
	#endif
		break;

	case 5:                       // slave mode w/o /SS enable
	#if defined SPI_IO_V11 
	 	TRISBbits.TRISB1 = 1;       // define clock pin as input	
    #elif defined SPI_IO_V12
		TRISDbits.TRISD0 = 1;       // define clock pin as input
	#elif defined SPI_IO_V10
		TRISDbits.TRISD6 = 1;       // define clock pin as input
	#endif
		break;
	
	default:                      // master mode, define clock pin as output
    #if defined SPI_IO_V11 
	 	TRISBbits.TRISB1 = 0;       // define clock pin as output	
    #elif defined SPI_IO_V12
		TRISDbits.TRISD0 = 0;       // define clock pin as output
	#elif defined SPI_IO_V10
		TRISDbits.TRISD6 = 0;       // define clock pin as output
	#endif
	   	 break;
  }
	#if defined SPI_IO_V11 
		TRISBbits.TRISB2 = 1;       // define SDI pin as input
	 	TRISBbits.TRISB3 = 0;       // define SDO pin as output	
    #elif defined SPI_IO_V12
		TRISDbits.TRISD1 = 1;       // define SDI pin as input
	 	TRISDbits.TRISD4 = 0;       // define SDO pin as output
	#elif defined SPI_IO_V10
		TRISDbits.TRISD5 = 1;       // define SDI pin as input
	 	TRISDbits.TRISD4 = 0;       // define SDO pin as output
    #endif
  
  SSP2CON1 |= SSPENB;             // enable synchronous serial port 
}

#endif


