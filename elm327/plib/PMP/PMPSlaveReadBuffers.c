 
#include "pmp.h"

#if defined (pmp_v1_1) || defined (pmp_v1_2) || defined (pmp_v1_3)
/******************************************************************************
 * Function:        void PMPSlaveReadBuffers(BYTE* ref)
 *
 * PreCondition:    None
 *
 * Side Effects:    Reading any of these buffers clears the IBF status bit as
 *					well as the individual IBnF status bits.
 *
 * Overview:        Copies 4 bytes from DATAIN buffers to a starting location
 *					pointed to by input parameter.
 * 					
 * Input:           ref - BYTE pointer
 *
 * Returns:          The contents of the 4 8-bit slave buffer registers.
 *
 * Note:            Use in SLAVE BUFFERED mode, MODE[1:0] = 00 and INCM[1:0]=11              
 *					or SLAVE ENHANCED mode, MODE[1:0] = 01
 *****************************************************************************/
void PMPSlaveReadBuffers(BYTE* ref)
{
	WORD_VAL reg1, reg2;
	
	reg2.v[0] = PMDIN2L;					// copy contents of input buffers PMDIN2
	reg2.v[1] = PMDIN2H;					// copy contents of input buffers PMDIN2
	reg1.v[0] = PMDIN1L;					// copy contents of input buffers PMDIN1
	reg1.v[1] = PMDIN1H;					// copy contents of input buffers PMDIN1
	
	*ref++ = reg1.v[0];
	*ref++ = reg1.v[1];
	*ref++ = reg2.v[0];
	*ref   = reg2.v[1];

}

#endif


