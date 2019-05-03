#include <p18cxxx.h>
#include <pcpwm.h>

/********************************************************************
*    Function Name:  pcpwm_OVD_CTRL                                   *
*    Return Value:   void                                           *
*    Parameters:     unsigned char 
*    Description:    This routine select Overide channel
*                    
*    Notes:          none
*                    
********************************************************************/
#if defined (PCPWM_V1) || defined (PCPWM_V2) || defined (PCPWM_V3)  

void pcpwm_OVD_CTRL(unsigned char config)
{
	OVDCOND  = config;
}

/********************************************************************
*    Function Name:  pcpwm_OVD_IO_STA                                   *
*    Return Value:   void                                           *
*    Parameters:     unsigned char 
*    Description:    This routine configures Idle state of PWM IO's
*                    
*    Notes:          none
*                    
********************************************************************/

void pcpwm_OVD_IO_STA(unsigned char config)
{
	OVDCONS  = config;
}

#endif

