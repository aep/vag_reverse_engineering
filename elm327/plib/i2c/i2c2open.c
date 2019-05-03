#include <p18cxxx.h>
#include <i2c.h>

/********************************************************************
*   Function Name:  OpenI2C2                                        *
*   Return Value:   void                                            *
*   Parameters:     SSP2 peripheral setup bytes                     *
*   Description:    This function sets up the SSP2 module on a      * 
*                   PIC18CXXX device for use with a Microchip I2C   *
*                   EEPROM device or I2C bus device.                *
********************************************************************/
#if defined (I2C_V3)
void OpenI2C2( unsigned char sync_mode, unsigned char slew )
{
  SSP2STAT &= 0x3F;                // power on state 
  SSP2CON1 = 0x00;                 // power on state
  SSP2CON2 = 0x00;                 // power on state
  SSP2CON1 |= sync_mode;           // select serial mode 
  SSP2STAT |= slew;                // slew rate on/off 

  I2C2_SCL = 1;
  I2C2_SDA = 1;
  SSP2CON1 |= SSPENB;              // enable synchronous serial port 
}
#endif

#if defined (I2C_V6) || defined (I2C_V6_1)
void OpenI2C2( unsigned char sync_mode, unsigned char slew )
{
  SSP2STAT &= 0x3F;                // power on state 
  SSP2CON1 = 0x00;                 // power on state
  SSP2CON2 = 0x00;                 // power on state
  SSP2CON1 |= sync_mode;           // select serial mode 
  SSP2STAT |= slew;                // slew rate on/off 
 
  SSP2CON1 |= SSPENB;              // enable synchronous serial port 
}
#endif
