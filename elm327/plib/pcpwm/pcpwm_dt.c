#include <p18cxxx.h>
#include <pcpwm.h>

/********************************************************************
*    Function Name:  pcpwm_dt_clk_source                                   *
*    Return Value:   void                                           *
*    Parameters:     unsigned char 
*    Description:    This routine selects the clock source for Dead time
*                    
*    Notes:          none
*                    
********************************************************************/
#if defined (PCPWM_V1) || defined (PCPWM_V2) || defined (PCPWM_V3) 

void pcpwm_dt_clk_source(unsigned char config)
{
	DTCON  |= (config & 0xc0);
}

/********************************************************************
*    Function Name:  pcpwm_dt_assignment                            *
*    Return Value:   void                                           *
*    Parameters:     unsigned char 
*    Description:    This routine updates the dead time
*                    
*    Notes:          none
*                    
********************************************************************/

void pcpwm_dt_assignment(unsigned char config)
{
	DTCON  |= (config & 0x3f);
}

#endif

