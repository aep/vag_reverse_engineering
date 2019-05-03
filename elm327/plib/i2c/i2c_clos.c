#include <p18cxxx.h>
#include <i2c.h>

#if defined (I2C_V1)
/*********************************************************************
Function Prototype : void CloseI2C(void)

Include            : i2c.h 

Description        : This function turns off the I2C module 

Arguments          : None 

Return Value       : None 

Remarks            : This function disables the I2C module and clears the
			I2C Interrupt Enable and Flag bits.
*********************************************************************/
void CloseI2C( void )
{
  SSPCON1 &= 0xDF;                // disable synchronous serial port
}

#endif

#if defined (I2C_V4)
/*********************************************************************
Function Prototype : void CloseI2C(void)

Include            : i2c.h 

Description        : This function turns off the I2C module 

Arguments          : None 

Return Value       : None 

Remarks            : This function disables the I2C module and clears the
			I2C Interrupt Enable and Flag bits.
*********************************************************************/
void CloseI2C( void )
{
  SSPCON &= 0xDF;                // disable synchronous serial port
}

#endif
