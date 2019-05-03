#include <p18cxxx.h>
#include <pcpwm.h>

/********************************************************************
*    Function Name:  SetDCpcpwm                                     *
*    Return Value:   void                                           *
*    Parameters:     unsigned int dutycycle 
*    Description:    This routine updates the duty cycle
*                    
*    Notes:          The bit definitions for config0,1,2,3 can be found    *
*                    in the pcpwm.h file.                          *
********************************************************************/

#if defined (PCPWM_V1) || defined (PCPWM_V2) || defined (PCPWM_V3) 

void Setdc0pcpwm(unsigned int dutycycle)
{
	PWMCON1bits.UDIS = 1;
	PDC0L = dutycycle;
	PDC0H = (dutycycle >>8) & 0x3f;

	PWMCON1bits.UDIS = 0;
}

void Setdc1pcpwm(unsigned int dutycycle)
{
	PWMCON1bits.UDIS = 1;
	PDC1L = dutycycle;
	PDC1H = (dutycycle >>8) & 0x3f;
	PWMCON1bits.UDIS = 0;
}
void Setdc2pcpwm(unsigned int dutycycle)
{
	PWMCON1bits.UDIS = 1;
	PDC2L = dutycycle;
	PDC2H = (dutycycle >>8) & 0x3f;
	PWMCON1bits.UDIS = 0;
}
#endif

#if defined (PCPWM_V2)
void Setdc3pcpwm(unsigned int dutycycle)
{
	PWMCON1bits.UDIS = 1;
	PDC3L = dutycycle;
	PDC3H = (dutycycle >>8) & 0x3f;
	PWMCON1bits.UDIS = 0;
}

#endif
