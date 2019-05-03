 
#include "pmp.h"

#if defined (pmp_v1_1) || defined (pmp_v1_2) || defined (pmp_v1_3)
/******************************************************************************
 * Function:        BOOL PMPIsInputBufferNFull (BUFFER buf)
 *
 * PreCondition:    None
 *
 * Side Effects:    None
 *
 * Overview:        Returns state of PMSTAT.IBxF (input buffer(s) full bit)
 * 					
 * Input:           buf - buffer(0..3)
 *
 * Returns:          TRUE/FALSE
 *
 * Note:            Use in SLAVE BUFFERED mode, MODE[1:0] = 00
 *					or SLAVE ENHANCED mode, MODE[1:0] = 00  and INCM[1:0]=11
 *****************************************************************************/
BOOL PMPIsBufferNFull(BUFFER buf)
{
	BOOL status = FALSE;
	
	switch(buf)
	{
	case 0:
		status = PMSTATHbits.IB0F;
		break;
	case 1:
		status = PMSTATHbits.IB1F;
		break;
	case 2:
		status = PMSTATHbits.IB2F;
		break;
	case 3:
		status = PMSTATHbits.IB3F;
		break;	
	}	
	return(status);
}
#endif


