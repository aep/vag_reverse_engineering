 
#include "pmp.h"

#if defined (pmp_v1_1) || defined (pmp_v1_2) || defined (pmp_v1_3)
/******************************************************************************
 * Function:        BOOL PMPIsBufferNEmpty (BUFFER buf)
 *
 * PreCondition:    None
 *
 * Side Effects:    None
 *
 * Overview:        Returns state of PMSTAT.OBnE (output buffer(s) empty bit)
 *
 * Input:           buf - buffer(0..3)
 *
 * Returns:          TRUE/FALSE
 *
 * Note:            Use in SLAVE BUFFERED mode, MODE[1:0] = 00
 *					or SLAVE ENHANCED mode, MODE[1:0] = 00  and INCM[1:0]=11            
 *****************************************************************************/
BOOL PMPIsBufferNEmpty(BUFFER buf)
{
	BOOL status = FALSE;
	
	switch(buf)
	{
	case 0:
		status = PMSTATLbits.OB0E;
	break;
	case 1:
		status = PMSTATLbits.OB1E;
	break;
	case 2:
		status = PMSTATLbits.OB2E;
	break;
	case 3:
		status = PMSTATLbits.OB3E;
	break;	
	}	
	return(status);
}

#endif


