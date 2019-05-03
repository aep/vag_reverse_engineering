#include <p18cxxx.h>
#include <mwire.h>

#if defined (MWIRE_V1)
/********************************************************************
*   Function Name:  OpenMwire                                       *
*   Return Value:   void                                            *
*   Parameters:     SSP peripheral setup byte                       *
*   Description:    This function sets up the SSP module on a       * 
*                   PIC18CXXX core device for use with a Microchip  *
*                   Microwire EEPROM device.                        *
********************************************************************/
void OpenMwire( unsigned char sync_mode )
{
  SSPSTAT &= 0x3F;                // power on state 
  SSPCON1 = 0x00;                 // power on state
  SSPCON1 |= sync_mode;           // select serial mode 
  
  MW1_DO_TRIS = 0;           // define SDO as output 
  MW1_CLK_TRIS = 0;           // define clock as output   
  MW1_DI_TRIS = 1;           // define SDI as input 
  
  SSPCON1 |= SSPENB;              // enable synchronous serial port 
}
#endif

#if defined (MWIRE_V3)
/********************************************************************
*   Function Name:  OpenMwire                                       *
*   Return Value:   void                                            *
*   Parameters:     SSP peripheral setup byte                       *
*   Description:    This function sets up the SSP module on a       * 
*                   PIC18CXXX core device for use with a Microchip  *
*                   Microwire EEPROM device.                        *
********************************************************************/
void OpenMwire( unsigned char sync_mode )
{
  SSPSTAT &= 0x3F;                // power on state 
  SSPCON = 0x00;                 // power on state
  SSPCON |= sync_mode;           // select serial mode 

  MW1_DO_TRIS = 0;           // define SDO as output 
  MW1_CLK_TRIS = 0;           // define clock as output   
  MW1_DI_TRIS = 1;           // define SDI as input 
  
  SSPCON |= SSPENB;              // enable synchronous serial port 
}
#endif

