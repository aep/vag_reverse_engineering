#include <p18cxxx.h>
#include <pwm.h>


/********************************************************************
*    Function Name:  CloseEPWM3                                   *
*    Return Value:   void                                           *
*    Parameters:     void                                           *
*    Description:    This routine turns off PWM1.                   *
********************************************************************/

#if defined (EPWM_V14) || defined (EPWM_V14_1) ||defined (EPWM_V14_3) ||\
 defined (EPWM_V14_4)|| defined (EPWM_V15) ||defined (EPWM_V15_1)

void CloseEPWM3(void)
{
 
 	CCP3CON = 0x0;           // Turn off PWM
 
}
#endif
