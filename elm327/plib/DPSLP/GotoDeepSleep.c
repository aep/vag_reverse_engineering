 
#include "dpslp.h"

#if defined (DPSLP_V1_1) 
/*************************************************************************
 Function Prototype : void gotoDeepSleep( unsigned int config )

 Include            : dpslp.h

 Description        : This function saves content to DPGPRx registers, enables the sources of deep sleep wake up and puts the device to deep sleep.
 
 Arguments          : 	 -config -  contains parameters to configure the deep sleep wake up sources

			-Deep Sleep Ultra Low Power Wake Up
			*DPSLP_ULPWU_ENABLE
			*DPSLP_ULPWU_DISABLE
				
			-RTCC wake up source enable/disable
			*DPSLP_RTCC_WAKEUP_ENABLE
			*DPSLP_RTCC_WAKEUP_DISABLE
                      
 Return Value       :None 
 
 Remarks            : Affects Ultra Low Power wake up module configuration.
*************************************************************************/

void GotoDeepSleep( unsigned int config)
{
	
	//************* RTCC wake up cnfiguration *************
	if (config&0x0001)
	{
		DSCONHbits.RTCWDIS = 1;		//disable RTCC as source of wake up
	}

	//************* Ultra Low Power Wake UP **************
	if (config&0x0002)
	{
		DSCONHbits.DSULPEN = 1;		//enable ultra low power wake up module
		DSCONLbits.ULPWDIS = 0;		//Ultra low power wake up enabled
		ULPWakeUpEnable();
	}
	else
	{
		DSCONHbits.DSULPEN = 0;		//Disable ultra low power wake up module
		DSCONLbits.ULPWDIS = 1;		//Ultra low power wake up Disabled
	}
	OSCCONbits.IDLEN = 0;					// enable deep sleep
	DSCONHbits.DSEN = 1;					//set the deep sleep enable bit
	Sleep();
	
}

#elif defined (DPSLP_V2_1)

void GotoDeepSleep( unsigned int config)
{
	
	//************* RTCC wake up cnfiguration *************
	if (config&0x0001)
	{
		DSCONHbits.RTCWDIS = 1;		//disable RTCC as source of wake up
	}

	OSCCONbits.IDLEN = 0;					// enable deep sleep
	DSCONHbits.DSEN = 1;					//set the deep sleep enable bit
	Sleep();

}	
//#else
//#warning "Selected device does not support this function"
#endif
