#include <p18cxxx.h>
#include <pcpwm.h>

/********************************************************************
*    Function Name:  Openpcpwm                                      *
*    Return Value:   void                                           *
*    Parameters:     
*    Description:    This routine cofigures pwm module for the 		*
					 following parameters
*                    period,special event time, pwm mode,			*
*                    
*    Notes:          The bit definitions for config0,1,2,3 can be 	*
*					found in the pcpwm.h file.						*
********************************************************************/

#if defined (PCPWM_V1) 

void Openpcpwm(unsigned char config0,unsigned char config1,unsigned char config2,unsigned char config3,unsigned int period,unsigned int sptime)
{
	PTPERL = period;
	PTPERH = (period >> 8) & 0x0f;
	SEVTCMPL = sptime;
	SEVTCMPH = (sptime>>8) & 0x0f;
	PWMCON0 = config0 & 0x7f;
	PWMCON1 = config1 & 0xfb;
	PWMCON0 &= 0b11110111;
 	PTCON0 = config2;
	PTCON1 = config3 & 0xc0;

}
#endif 

#if defined (PCPWM_V2) || defined (PCPWM_V3) 
void Openpcpwm(unsigned char config0,unsigned char config1,unsigned char config2,unsigned char config3,unsigned int period,unsigned int sptime)
{
	PTPERL = period;
	PTPERH = (period >> 8) & 0x0f;
	SEVTCMPL = sptime;
	SEVTCMPH = (sptime>>8) & 0x0f;
	PWMCON0 = config0 & 0x7f;
	PWMCON1 = config1 & 0xfb;
 	PTCON0 = config2;
	PTCON1 = config3 & 0xc0;

}

#endif
