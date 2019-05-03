 
#include "pmp.h"

#if defined (pmp_v1_1) || defined (pmp_v1_2) || defined (pmp_v1_3)
/******************************************************************************
 * Function:        BOOL PMPSlaveWriteBufferN(BUFFER buf, BYTE value)
 *
 * PreCondition:    None
 *
 * Side Effects:    None
 *
 * Overview:        writes the desired value into the selected output buffer
 * 					
 * Input:           buf - buffer(0..3)
 *                  value - value to be written
 *
 * Returns:          Returns the state of PMSTAT.OBE prior to the write operation.
 *
 * Note:            Use in SLAVE BUFFERED mode, MODE[1:0] = 00
 *					or SLAVE ENHANCED mode, MODE[1:0] = 00  and INCM[1:0]=11           
 *****************************************************************************/
BOOL PMPSlaveWriteBufferN(BUFFER buf, BYTE value)
{

	WORD_VAL reg;
	BOOL status;
	reg.Val = 0;
	
	if(PMSTATLbits.OBE)	
		status = TRUE;

	switch(buf)
	{
	case 0:
		PMADDRL = value;				// write it back to PMDATAOUT1
		break;

	case 1:
		PMADDRH = value;				// write it back to PMDATAOUT1
		break;

	case 2:
		PMDOUT2L = value;				// write it back to PMDATAOUT2
		break;
		
	case 3:
		PMDOUT2H = value;				// write it back to PMDATAOUT2
		break;
	}
	return(status);
}

#endif


