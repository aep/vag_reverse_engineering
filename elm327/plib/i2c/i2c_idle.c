#include <p18cxxx.h>
#include <i2c.h>

#if defined (I2C_V1)
/**********************************************************************************************
Function Prototype : void IdleI2C(void) 

Include            : i2c.h 

Description        : This function generates Wait condition until I2C bus is Idle. 

Arguments          : None 

Return Value       : None 

Remarks            : This function will be in a wait state until Start Condition Enable bit,
                     Stop Condition Enable bit, Receive Enable bit, Acknowledge Sequence
                     Enable bit of I2C Control register and Transmit Status bit I2C Status
                     register are clear. The IdleI2C function is required since the hardware
                     I2C peripheral does not allow for spooling of bus sequence. The I2C
                     peripheral must be in Idle state before an I2C operation can be initiated
                     or write collision will be generated.
***********************************************************************************************/
void IdleI2C( void )
{
  while ( ( SSPCON2 & 0x1F ) || ( SSPSTATbits.R_W ) )
     continue;
}
#endif

#if defined (I2C_V4)
/**********************************************************************************************
Function Prototype : void IdleI2C(void) 

Include            : i2c.h 

Description        : This function generates Wait condition until I2C bus is Idle. 

Arguments          : None 

Return Value       : None 

Remarks            : This function will be in a wait state until Start Condition Enable bit,
                     Stop Condition Enable bit, Receive Enable bit, Acknowledge Sequence
                     Enable bit of I2C Control register and Transmit Status bit I2C Status
                     register are clear. The IdleI2C function is required since the hardware
                     I2C peripheral does not allow for spooling of bus sequence. The I2C
                     peripheral must be in Idle state before an I2C operation can be initiated
                     or write collision will be generated.
***********************************************************************************************/
void IdleI2C( void )
{
  while ( ( SSPCON & 0x1F ) || ( SSPSTATbits.R_W ) )
     continue;
}
#endif
