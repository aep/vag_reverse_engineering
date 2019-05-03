#include <p18cxxx.h>
#include <pcpwm.h>

/********************************************************************
*    Function Name:  Closepcpwm                                     *
*    Return Value:   void                                           *
*    Parameters:     None 
*    Description:    This routine closes the pcpwm module
*                    
*    Notes:          none
*                    
********************************************************************/

#if defined (PCPWM_V1) || defined (PCPWM_V2) || defined (PCPWM_V3) 

void Closepcpwm(void)
{
	PIE3bits.PTIE = 0;
	PIR3bits.PTIF = 0;
	PWMCON0 = 0;
}

#endif
