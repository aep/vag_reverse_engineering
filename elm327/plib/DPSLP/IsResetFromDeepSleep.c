 
#include "dpslp.h"

#if defined (DPSLP_V1_1)
/*************************************************************************
 Function Prototype : signed char IsResetFromDeepSleep( void)

 Include            : dpslp.h

 Description        : This function returns the source of reset.
 
 Arguments          : None
                      
 Return Value       :Reset source
			* -1 : Reset source is Deep Sleep Wake up
			* 0 : Reset source is pure Power on Reset/BOR during sleep/some other source
 
 Remarks            : Clears Deeplseep bit in the respective register.
*************************************************************************/

signed char IsResetFromDeepSleep( void )
{

	if(WDTCONbits.DS)
	{	
		WDTCONbits.DS = 0;				//Manual clearing of bit
		return(-1);						//Reset source is Deep Sleep wake up
	}	
	else
	{	
		return(0);						//Reset Source is pure Power on Reset
	}	
	
}

#elif defined (DPSLP_V2_1)

signed char IsResetFromDeepSleep( void )
{

	if((RCON4bits.DPSLP) && (RCONbits.POR))
	{	
		RCON4bits.DPSLP = 0;				//Manual clearing of bit
		return(-1);						//Reset source is Deep Sleep wake up
	}	
	else
	{	
		return(0);						//Reset Source is pure Power on Reset
	}	
	
}

//#else
//#warning "Selected device does not support this function"
#endif
