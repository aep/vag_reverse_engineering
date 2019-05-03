 
#include "dpslp.h"

#if defined (DPSLP_V1_1) 
/*************************************************************************
 Function Prototype :void DeepSleepWakeUpSource( SRC* ptr)

 Include            : dpslp.h

 Description        : This function updates source of wake up of device from deep sleep.
 
 Arguments          : Pointer to union that reflects the status of deep sleep wake up source 
                      
 Return Value       :None
 
 Remarks            : This function updates union SRC reflects the wake up source of deep sleep.
*************************************************************************/

void DeepSleepWakeUpSource(SRC* ptr)
{

	ptr->WKSRC=0x00;				//Clear all source bit if set previously


		if(DSWAKELbits.DSPOR)
			ptr->WK_SRC.DS_POR=1;		//wake up source is Power on reset
		if(DSWAKELbits.DSMCLR)
			ptr->WK_SRC.DS_MCLR=1;		//wake up source is master reset pin set to low
		if(DSWAKELbits.DSRTC)
			ptr->WK_SRC.DS_RTC=1;		//wake up source is rtcc alarm
		if(DSWAKELbits.DSWDT)
			ptr->WK_SRC.DS_WDT=1;		//wake up source is deep sleep watch dog timer expiry
		if(DSWAKELbits.DSULP)
			ptr->WK_SRC.DS_ULP=1;		//wake up source is Ultra Low Power Wake Up Module
		if(DSWAKELbits.DSFLT)
			ptr->WK_SRC.DS_FLT=1;		//wake up due to fault in deep sleep configuration corruption
		if(DSWAKEHbits.DSINT0)
			ptr->WK_SRC.DS_INT0=1;		//wake up source is external interrupt
		if(DSCONLbits.DSBOR)
			ptr->WK_SRC.DS_BOR=1;		//Brown out occured during sleep
	
}

#elif defined (DPSLP_V2_1)

void DeepSleepWakeUpSource(SRC* ptr)
{

	ptr->WKSRC=0x00;				//Clear all source bit if set previously
	
		if(DSWAKELbits.DSPOR)
			ptr->WK_SRC.DS_POR=1;		//wake up source is Power on reset
		if(DSWAKELbits.DSICD)
			ptr->WK_SRC.DS_ICD=1;		//wake up source is ICD			
		if(DSWAKELbits.DSMCLR)
			ptr->WK_SRC.DS_MCLR=1;		//wake up source is master reset pin set to low
		if(DSWAKELbits.DSRTC)
			ptr->WK_SRC.DS_RTC=1;		//wake up source is rtcc alarm
		if(DSWAKELbits.DSWDT)
			ptr->WK_SRC.DS_WDT=1;		//wake up source is deep sleep watch dog timer expiry
		if(DSWAKELbits.DSULP)
			ptr->WK_SRC.DS_EXT=1;		//wake up source is external interrupt
		if(DSWAKELbits.BOR)
			ptr->WK_SRC.DS_BOR=1;		//Brown out occured during sleep
		if(DSWAKELbits.DSFLT)
			ptr->WK_SRC.DS_FLT=1;		//wake up due to fault in deep sleep configuration corruption
		if(DSWAKEHbits.DSINT0)
			ptr->WK_SRC.DS_INT0=1;		//wake up source is INT0	
}

//#else
//#warning "Selected device does not support this function"
#endif
