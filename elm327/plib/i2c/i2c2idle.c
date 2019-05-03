#include <p18cxxx.h>
#include <i2c.h>


/********************************************************************
*     Function Name:    IdleI2C2                                    *
*     Return Value:     void                                        *
*     Parameters:       void                                        *
*     Description:      Test and wait until I2C2 module is idle.    *
********************************************************************/

#if defined (I2C_V3) || defined (I2C_V6) || defined (I2C_V6_1)
#undef IdleI2C2
void IdleI2C2( void )
{
  #if defined (I2C_SFR_V1)
    while ((SSP2CON2 & 0x1F) | (SSP2STATbits.R_NOT_W))
  #else
    while ((SSP2CON2 & 0x1F) | (SSP2STATbits.R_W))
  #endif
     continue;
}
#endif
