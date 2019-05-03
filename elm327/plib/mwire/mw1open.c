#include <p18cxxx.h>
#include <mwire.h>
#include "pps.h"

#if defined (MWIRE_V2) || defined (MWIRE_V4) || defined (MWIRE_V5) || defined (MWIRE_V6)
/********************************************************************
*   Function Name:  OpenMwire1                                      *
*   Return Value:   void                                            *
*   Parameters:     SSP1 peripheral setup byte                      *
*   Description:    This function sets up the SSP1 module on a      * 
*                   PIC18CXXX core device for use with a Microchip  *
*                   Microwire EEPROM device.                        *
********************************************************************/
void OpenMwire1( unsigned char sync_mode )
{
  SSP1STAT &= 0x3F;                // power on state 
  SSP1CON1 = 0x00;                 // power on state
  SSP1CON1 |= sync_mode;           // select serial mode 

#if defined (MWIRE_V6)
	PPSUnLock();	
    RPINR8_9=0x04;           //PPS assignment of SSP functins SDI1 to RP16
	RPOR16_17=0x04;          //PPS assignment of SSP functins SD01 to RP17                 
	RPOR14_15=0x03;         //PPS assignment of SSP functins SCK1 to RP15                 
	PPSLock();
#endif	
  
  MW1_DO_TRIS = 0;            // define SDO1 as output 
  MW1_CLK_TRIS = 0;            // define clock as output   
  MW1_DI_TRIS = 1;            // define SDI1 as input 
  
  SSP1CON1 |= SSPENB;              // enable synchronous serial port 
}
#endif
