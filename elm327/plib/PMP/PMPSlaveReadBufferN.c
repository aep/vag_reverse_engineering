 
#include "pmp.h"

#if defined (pmp_v1_1) || defined (pmp_v1_2) || defined (pmp_v1_3)
/******************************************************************************
 * Function:        unsigned char PMPSlaveReadBufferN(BUFFER buf)
 *
 * PreCondition:    None
 *
 * Side Effects:    Reading PMDATA buffer clears status bit.
 *
 * Overview:        Reads the value in PMDATA register written by a master device.
 * 					
 * Input:           buf - buffer(0..3)
 *
 * Returns:          The value in selected buffer.
 *
 * Note:            Use in SLAVE BUFFERED mode, MODE[1:0] = 00 and INCM[1:0]=11              
 *					or SLAVE ENHANCED mode, MODE[1:0] = 01
 *****************************************************************************/
unsigned char PMPSlaveReadBufferN(BUFFER buf)
{

	WORD_VAL reg1, reg2;
	BYTE value;

	reg2.v[0] = PMDIN2L;					// copy contents of input buffers PMDIN2
	reg2.v[1] = PMDIN2H;					// copy contents of input buffers PMDIN2
	reg1.v[0] = PMDIN1L;					// copy contents of input buffers PMDIN1
	reg1.v[1] = PMDIN1H;					// copy contents of input buffers PMDIN1
	
	switch(buf)
	{
	case 0:
		value =reg1.v[0];				// get copy of PMDDIN1L
		break;
	case 1:
		value = reg1.v[1];				// get copy of PMDDIN1H
		break;
	case 2:
		value = reg2.v[0];				// get copy of PMDDIN2L
		break;
	case 3:	
		value = reg2.v[1];				// get copy of PMDIN2H
		break;
	}

	return(value);						// return to caller
}

#endif


