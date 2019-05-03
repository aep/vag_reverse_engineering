#include <p18cxxx.h>
#include <i2c.h>

/********************************************************************
*   Function Name:  OpenI2C1                                        *
*   Return Value:   void                                            *
*   Parameters:     SSP1 peripheral setup bytes                     *
*   Description:    This function sets up the SSP1 module on a      * 
*                   PIC18CXXX device for use with a Microchip I2C   *
*                   EEPROM device or I2C bus device.                *
********************************************************************/
#if defined (I2C_V2) || defined (I2C_V3) 
void OpenI2C1( unsigned char sync_mode, unsigned char slew )
{
  SSP1STAT &= 0x3F;                // power on state 
  SSP1CON1 = 0x00;                 // power on state
  SSP1CON2 = 0x00;                 // power on state
  SSP1CON1 |= sync_mode;           // select serial mode 
  SSP1STAT |= slew;                // slew rate on/off 

  I2C1_SCL = 1;               // Set SCL1 (PORTC,3) pin to input
  I2C1_SDA = 1;               // Set SDA1 (PORTC,4) pin to input

  SSP1CON1 |= SSPENB;              // enable synchronous serial port 
}
#endif

#if defined (I2C_V5) || defined (I2C_V6) || defined (I2C_V6_1) || defined (I2C_V6_2)
void OpenI2C1( unsigned char sync_mode, unsigned char slew )
{
  SSP1STAT &= 0x3F;                // power on state 
  SSP1CON1 = 0x00;                 // power on state
  SSP1CON2 = 0x00;                 // power on state
  SSP1CON1 |= sync_mode;           // select serial mode 
  SSP1STAT |= slew;                // slew rate on/off   

  SSP1CON1 |= SSPENB;              // enable synchronous serial port 
}
#endif
