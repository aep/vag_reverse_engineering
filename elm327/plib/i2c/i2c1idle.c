#include <p18cxxx.h>
#include <i2c.h>


/********************************************************************
*     Function Name:    IdleI2C1                                    *
*     Return Value:     void                                        *
*     Parameters:       void                                        *
*     Description:      Test and wait until I2C1 module is idle.    *
********************************************************************/
#undef IdleI2C1

#if defined (I2C_V2) || defined (I2C_V3) || defined (I2C_V5) || defined (I2C_V6) || defined (I2C_V6_1)
void IdleI2C1( void ) 
{
		while ( ( SSP1CON2 & 0x1F ) | ( SSP1STATbits.R_W ) )
	continue;
}
#endif

#if defined (I2C_V6_2)
void IdleI2C1( void ) 
{
	while ( ( SSP1CON2 & 0x1F ) | ( SSP1STATbits.R_NOT_W ) )
	continue;
}
#endif
