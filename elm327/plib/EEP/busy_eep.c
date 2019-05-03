#include <p18cxxx.h>
#include <EEP.h>

/********************************************************************
*     Function Name:    Busy_eep                                    *
*     Return Value:     None										*
*     Parameters:       None										*
*     Description:      Checks & waits the status of ER bit in 		*
						EECON1 register     						*
********************************************************************/
#if defined (EEP_V1) || defined (EEP_V2) || defined (EEP_V3)				
void Busy_eep ( void )
{
	while(EECON1bits.WR);
}
#endif
