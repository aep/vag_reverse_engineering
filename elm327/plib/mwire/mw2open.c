#include <p18cxxx.h>
#include <mwire.h>
#include "pps.h"

#if defined (MWIRE_V2) || defined (MWIRE_V4) || defined (MWIRE_V6)
/********************************************************************
*   Function Name:  OpenMwire2                                      *
*   Return Value:   void                                            *
*   Parameters:     SSP2 peripheral setup byte                      *
*   Description:    This function sets up the SSP2 module on a      * 
*                   PIC18CXXX core device for use with a Microchip  *
*                   Microwire EEPROM device.                        *
********************************************************************/
void OpenMwire2( unsigned char sync_mode )
{

#if defined (MWIRE_V4)
	PPSUnLock();					            
	// PPSInput(IN_FN_PPS_SDI2,IN_PIN_PPS_RP4);		//PPS assignment of SSP functins on to PIN
	// PPSOutput(IN_FN_PPS_RP3,OUT_FN_PPS_SDO2);	//PPS assignment of SSP functins on to PIN	
	// PPSOutput(IN_FN_PPS_RP5,OUT_FN_PPS_SCK2);	//PPS assignment of SSP functins on to PIN
	RPINR21 = 4; //PPS assignment of SSP functins SDI2 to RP4
	RPOR3 = 9; //PPS assignment of SSP functins SD02 to RP3
	RPOR5 = 10; //PPS assignment of SSP functins SCK2 to RP5 	
	PPSLock();
#endif

#if defined (MWIRE_V6)
	PPSUnLock();					
	RPINR12_13=0x06;         //PPS assignment of SSP functins SDI2 to RP25
	RPOR24_25=0x04;         //PPS assignment of SSP functins SD02 to RP24                
	RPOR26_27=0x05;         //PPS assignment of SSP functins SCK2 to RP26                 
	PPSLock();
#endif	

  SSP2STAT &= 0x3F;                // power on state 
  SSP2CON1 = 0x00;                 // power on state
  SSP2CON1 |= sync_mode;           // select serial mode 

  MW2_DO_TRIS = 0;            // define SDO2 as output 
  MW2_CLK_TRIS = 0;            // define clock as output   
  MW2_DI_TRIS = 1;            // define SDI2 as input 
 
  SSP2CON1 |= SSPENB;              // enable synchronous serial port 
}
#endif
