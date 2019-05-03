 
#include "dpslp.h"

#if defined (DPSLP_V1_1) || defined (DPSLP_V1_2)
/*************************************************************************
 Function Prototype :void ULPWakeUpEnable( void)

 Include            : dpslp.h

 Description        : This function enables the Ultra Low power wake up module.
 
 Arguments          : None
                      
 Return Value       :None
 
 Remarks            : User must have charged the capacitor pior to enabling the deep sleep wake up from ultra low power wake up and must have called "EnableIntULPWU" function.
*************************************************************************/

void ULPWakeUpEnable( void )
{

		//**********************************
		//Stop Charging the capacitor on RA0
		//**********************************
		TRISAbits.TRISA0 = 1;
		//*****************************************
		//Enable the Ultra Low Power Wakeup module
		//and allow capacitor discharge
		//*****************************************
		WDTCONbits.ULPEN = 1;
		WDTCONbits.ULPSINK = 1;
	
}

//#else
//#warning "Selected device does not support this function"
#endif
