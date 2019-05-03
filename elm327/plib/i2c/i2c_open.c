#include <p18cxxx.h>
#include <i2c.h>

/********************************************************************
*   Function Name:  OpenI2C                                         *
*   Return Value:   void                                            *
*   Parameters:     SSP peripheral setup bytes                      *
*   Description:    This function sets up the SSP module on a       * 
*                   PIC18CXXX device for use with a Microchip I2C   *
*                   EEPROM device or I2C bus device.                *
********************************************************************/
#if defined (I2C_V1)

void OpenI2C( unsigned char sync_mode, unsigned char slew )
{
  SSPSTAT &= 0x3F;                // power on state 
  SSPCON1 = 0x00;                 // power on state
  SSPCON2 = 0x00;                 // power on state
  SSPCON1 |= sync_mode;           // select serial mode 
  SSPSTAT |= slew;                // slew rate on/off 

  I2C_SCL = 1;
  I2C_SDA = 1;
  SSPCON1 |= SSPENB;              // enable synchronous serial port 

}
#endif

#if defined (I2C_V4)

void OpenI2C( unsigned char sync_mode, unsigned char slew )
{
  SSPSTAT &= 0x3F;                // power on state 
  SSPCON = 0x00;                 // power on state
  SSPCON |= sync_mode;           // select serial mode 
  SSPSTAT |= slew;                // slew rate on/off 

  I2C_SCL = 1;
  I2C_SDA = 1;
  SSPCON |= SSPENB;              // enable synchronous serial port 

}
#endif
