 
#include "pmp.h"

#if defined (pmp_v1_1) || defined (pmp_v1_2) || defined (pmp_v1_3)
/******************************************************************************
 * Function     : void PMPClose(void)
 *
 * PreCondition : None
 *
 * Overview     : disables PMP module, disables interrupt
 *
 * Input        : None
 *
 * Returns      : None 
 *
 * Side Effects : PMCON.PMPEN, IEC2.PMPIE, IFS2.PMPIF are cleared.
 *****************************************************************************/
 void PMPClose(void)
 {
    PIE1bits.PMPIE = 0;
    PIR1bits.PMPIF = 0;
    IPR1bits.PMPIP = 0;
 }


#endif

