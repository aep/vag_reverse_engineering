//#include <p18cxxx.h>
#include <ctmu.h>

/*************************************************************************************
Function          : void CurrentControlCTMU(unsigned char config)

Overview          : This function selects the current source range and trims the
                         current source of CTMU.

Parameters        :  config - This contains the parameters to be configured in the
                           CTMU1CON register as defined below


		        Current Source Trim bits
			  *CTMU_POS_CURR_TRIM_62
			  *CTMU_POS_CURR_TRIM_60
			  *....
			  *CTMU_POS_CURR_TRIM_4
			  *CTMU_POS_CURR_TRIM_2
			  *CTMU_NOMINAL_CURRENT
			  *CTMU_NEG_CURR_TRIM_2
			  *CTMU_NEG_CURR_TRIM_4
			  *...
			  *CTMU_NEG_CURR_TRIM_60
			  *CTMU_NEG_CURR_TRIM_62

		       Current Source Range Select bits
			  *CTMU_CURR_RANGE_100_BASE_CURR
			  *CTMU_CURR_RANGE_10_BASE_CURR
			  *CTMU_CURR_RANGE_BASE_CURR
			  *CTUM_CURR_SOURCE_DISABLE


Returns           : None

Remarks           : The level of current is user-selectable across three ranges or a total of two
                         orders of magnitude, with the ability to trim the output in ±2% increments
************************************************************************************************/

#if	defined (CTMU_V1) || defined (CTMU_V1_1)
void CurrentControlCTMU(unsigned char config)
{
	CTMUICON = config;
}
#endif

#if	defined (CTMU_V2)  
void CurrentControlCTMU(unsigned char config)
{
	CTMUCON2 = config;
}

#endif
