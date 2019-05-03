 
#include "pmp.h"

#if defined (pmp_v1_1) || defined (pmp_v1_2) || defined (pmp_v1_3)
/******************************************************************************
 * Function:        void PMPMasterWrite(WORD value)
 *
 * PreCondition:    None
 *
 * Side Effects:    None
 *
 * Overview:        If 8-bit data mode is selected, the data appears on 8
 *					data lines.  If 16-bit data mode, the lower 8 bits of data
 *					are written first, followed by the upper 8 bits of data.
 * 					
 * Input:           value - to write to external device
 *
 * Returns:         None
 *
 * Note:			Use in MASTER mode 1 or 2, MODE[1:0] = 10, 11 
 *****************************************************************************/
void PMPMasterWrite(WORD value)
{
	while(PMMODEHbits.BUSY);
   	
	PMDIN1L = (BYTE) (0x00FF & value);
	PMDIN1H = (BYTE) ((0xFF00 & value)>>8);
}

#endif


