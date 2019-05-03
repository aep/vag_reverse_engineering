 
#include "pmp.h"

#if defined (pmp_v1_1) || defined (pmp_v1_2) || defined (pmp_v1_3)
/******************************************************************************
 * Function:        BOOL PMPSlaveWriteBuffers(BYTE* ref)
 *
 * PreCondition:    None
 *
 * Side Effects:    None
 *
 * Overview:        Copies 4 bytes, addressed by the pointer/ref argument, into
 *					the corresponding output registers. Byte[0] -> OUT1[7:0],
 *					byte[1] -> OUT1[15:8], ... etc. If entire buffer is empty,
 *					(IBF = 0) function returns TRUE, else the bytes are not
 *					copied and returns FALSE.
 *
 * Input:           ref - BYTE pointer
 *
 * Returns:          Returns the state of PMSTAT.OBE prior to the write operation.
 *
 * Note:            Use in SLAVE BUFFERED mode, MODE[1:0] = 00
 *					or SLAVE ENHANCED mode, MODE[1:0] = 00  and INCM[1:0]=11              
 *****************************************************************************/
BOOL PMPSlaveWriteBuffers(BYTE* ref)
{
	WORD_VAL reg1, reg2;
	BOOL status;
	
	if(PMSTATLbits.OBE)
		status = TRUE;

	PMDOUT1L = *ref++;
	PMDOUT1H = *ref++;
	PMDOUT2L = *ref++;
	PMDOUT2H = *ref;

	return(status);
}


#endif


