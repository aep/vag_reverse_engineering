#include "flash.h"

#if defined (FLASH_V2_1) 
/*********************************************************************
Function:        	void WriteWordFlash(unsigned long startaddr, unsigned int data)

PreCondition:    	None

Input:           	startaddr - Strating address from which flash has to be written
data - Data to be written into flash

Output:          	None

Side Effects:    	None

Overview:        	The function writes word to flash 

Note:            	1. Necessary to erase flash block (number of bytes specified in device data sheet) exclusively in application before writing 
if application had written data into to this block of flash(after erasing followed by programming).
2. Starting address has to be an even address else boundary mismatch will occur 
3. Writing can be done directly without erase if these bytes of flash is being written for the first time after programming
 ********************************************************************/
void WriteWordFlash(unsigned long startaddr, unsigned int data)
{

	unsigned char flag=0;
#ifndef _OMNI_CODE_
	DWORD_VAL flash_addr;
#else
	WORD_VAL flash_data;
	char *startptr;
	unsigned long saddress;
#if _ERRATA_TYPES & ERRATA_TBLWTINT
	unsigned char saved1,saved2,saved3,saved4;
#endif
#endif

#ifndef _OMNI_CODE_
	flash_addr.Val = startaddr;
#else
	saddress = startaddr;
#endif
	flash_data.Val = data;

#ifndef _OMNI_CODE_
	TBLPTRU = flash_addr.byte.UB; //Load the address to Address pointer registers
	TBLPTRH = flash_addr.byte.HB;
	TBLPTRL = flash_addr.byte.LB;
#else
	startptr = (const char *) saddress;
#if _ERRATA_TYPES & ERRATA_TBLWTINT
	/* Errata document (B3,B4,B5) advises that these devices need all *
	 * interrupt enable bits clear during TBLWT instruction.          *
	 * (That document mentions INTCON2 but it has no 'enable' bits.)  */
	saved1=INTCON; INTCON=0;	// Saving interrupt registers
	saved2=INTCON3; INTCON3=0;
	saved3=PIE1; PIE1=0;		
	saved4=PIE2; PIE2=0;		
#endif
#endif

#ifndef _OMNI_CODE_
	TABLAT = flash_data.byte.LB;
	_asm  TBLWTPOSTINC 	_endasm
	
	TABLAT =flash_data.byte.HB;
	_asm  TBLWT 	_endasm
#else
	*startptr = flash_data.byte.LB;	
	startptr++;
	*startptr = flash_data.byte.HB;	
#if _ERRATA_TYPES & ERRATA_TBLWTINT			       
	PIE1=saved3;		  // restore the interrupt registers
	PIE2=saved4; 	
	INTCON3=saved2;   
	INTCON=saved1;           
#endif
#endif

#ifndef _OMNI_CODE_
	TBLPTRU = flash_addr.byte.UB; //Load the address to Address pointer registers
	TBLPTRH = flash_addr.byte.HB;
	TBLPTRL = flash_addr.byte.LB;
#else
	startptr = (const char *) saddress;
#endif

	//*********** Flash write sequence ***********************************
#if defined (FLASH_V2_IO_V1)
	EECON1bits.WWPROG = 1;	
#else
	EECON1bits.WPROG = 1;	
#endif
			
	EECON1bits.WREN = 1;
	if(INTCONbits.GIE)
	{
		INTCONbits.GIE = 0;
		flag=1;
	}
	EECON2  = 0x55;
	EECON2  = 0xAA;
	EECON1bits.WR = 1;
	if(flag)
		INTCONbits.GIE = 1;

}


#endif

