 
#include "pmp.h"

#if defined (pmp_v1_1) || defined (pmp_v1_2) || defined (pmp_v1_3)
/******************************************************************************
 * Function:        WORD PMPMasterRead (void)
 *
 * PreCondition:    None
 *
 * Side Effects:    None
 *   
 * Input:           None
 *
 * Returns:          8-bit value read from external device
 * 					
 * Note:			Use in MASTER mode 1 or 2, MODE[1:0] = 10, 11 
 *****************************************************************************/
WORD PMPMasterRead(void)
{
WORD Temp_Read=0;

	while(!PMMODEHbits.BUSY)
	
	Temp_Read = PMDIN1H;
	Temp_Read = (WORD) ((Temp_Read<<8) | PMDIN1L);
	return(Temp_Read);
}

#endif


