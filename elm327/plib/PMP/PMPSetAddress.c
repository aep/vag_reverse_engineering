 
#include "pmp.h"

#if defined (pmp_v1_1) || defined (pmp_v1_2) || defined (pmp_v1_3)
/******************************************************************************
  Function:        void PMPSetAddress(WORD address)
 
  PreCondition:    None
 
  Side Effects:    None
  				
  Input:           address - This contains the parameters to be configured in the
                              PMADDR register as defined below
							  
                              Chip Select 
                                *	BIT_CS2_ON
                                *	BIT_CS2_OFF 
                                *	BIT_CS1_ON 
                                *	BIT_CS1_OFF
                            Destination Address
                                 *	BIT_A13
                                *	BIT_A12
                                *	BIT_A11
                                *	BIT_A10
                                *	BIT_A9
                                *	BIT_A8
                                *	BIT_A7
                                *	BIT_A6
                                *	BIT_A5
                                *	BIT_A4
                                *	BIT_A3
                                *	BIT_A2
                                *	BIT_A1
                                *	BIT_A0          
 
  Returns:          None
 
  Note:			Use in MASTER mode 1 or 2, MODE[1:0] = 10, 11 
 *****************************************************************************/

void PMPSetAddress(WORD address)
{
    PMADDRL = (BYTE) (0x00FF & address);
	PMADDRH = (BYTE) ((0xFF00 &address)>>8);
}

#endif
 
